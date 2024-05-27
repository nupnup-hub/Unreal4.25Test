// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalComputeShader.h"
#include "ShaderParameterStruct.h"
#include "RenderGraphUtils.h"
#include "RenderTargetPool.h"
#include "Engine/Texture.h"

#define THREAD_DIMX 16
#define THREAD_DIMY 16

class FScalingTextureCS final : public FGlobalShader
{
public:
	DECLARE_GLOBAL_SHADER(FScalingTextureCS);
	SHADER_USE_PARAMETER_STRUCT(FScalingTextureCS, FGlobalShader);
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(FVector2D, InputDimention)
		SHADER_PARAMETER(FVector2D, OutputDimention)
		SHADER_PARAMETER(FVector2D, InvOutputDimention)
		SHADER_PARAMETER_TEXTURE(Texture2D, InputTexture)
		SHADER_PARAMETER_UAV(RWTexture2D<float4>, OutputTexture)
		SHADER_PARAMETER_SAMPLER(SamplerState, SamLinearClamp)
		END_SHADER_PARAMETER_STRUCT()
public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}
	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), THREAD_DIMX);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), THREAD_DIMY);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), 1);
	}
}; 
IMPLEMENT_GLOBAL_SHADER(FScalingTextureCS, "/CustomShaders/ScalingTexture.usf", "Main", SF_Compute);

static FIntVector CalDispatchGroupDim(const FIntPoint dimXY)
{
	return FIntVector(FMath::DivideAndRoundUp(dimXY.X, THREAD_DIMX), FMath::DivideAndRoundUp(dimXY.Y, THREAD_DIMY), 1);
}

FIndirectCSParameters::FIndirectCSParameters(UTexture2D* Source, UTexture2D* Indirect, UTextureRenderTarget2D* RenderTarget)
{
	Update(Source, Indirect, RenderTarget);
}
FIntPoint FIndirectCSParameters::GetSourceSize()const
{
	return Source ? FIntPoint(Source->Resource->GetSizeX(), Source->Resource->GetSizeY()) : FIntPoint::ZeroValue;
}
FIntPoint FIndirectCSParameters::GetRenderTargetSize() const
{
	return RenderTarget ? FIntPoint(RenderTarget->SizeX, RenderTarget->SizeY) : FIntPoint::ZeroValue;
}
void FIndirectCSParameters::Update(UTexture2D* NewSource, UTexture2D* NewIndirect, UTextureRenderTarget2D* NewRenderTarget)
{
	Source = NewSource;
	Indirect = NewIndirect;
	RenderTarget = NewRenderTarget;
}
bool FIndirectCSParameters::IsValid()const
{
	return Source != nullptr && RenderTarget != nullptr && Source->Resource != nullptr && RenderTarget->GetRenderTargetResource();
}

bool FIndirectCSHandler::IsRegistered()const
{
	return OnPostResolvedSceneColorHandle.IsValid();
}
bool FIndirectCSHandler::CanExecute()const
{
	return Params.IsValid();
}
//Update the parameters by a providing an instance of the Parameters structure used by the shader manager
void FIndirectCSHandler::UpdateParameters(const FIndirectCSParameters& NewParameters)
{
	Params = NewParameters;
} 
bool FIndirectCSHandler::Begin(FIndirectCSDelegate NewExecuteEndDel)
{ 
	if (OnPostResolvedSceneColorHandle.IsValid())
		return false;
	  
	const FName RendererModuleName("Renderer");
	IRendererModule* RendererModule = FModuleManager::GetModulePtr<IRendererModule>(RendererModuleName);
	if (RendererModule)
		OnPostResolvedSceneColorHandle = RendererModule->GetResolvedSceneColorCallbacks().AddRaw(this, &FIndirectCSHandler::Execute);
	
	EndRenderFrameHandle = FCoreDelegates::OnEndFrameRT.AddRaw(this, &FIndirectCSHandler::ClearAllocatedRt);
	FSamplerStateInitializerRHI SamplerStateInitializer
	(
		SF_Bilinear,
		AM_Clamp,
		AM_Clamp,
		AM_Clamp
	);
	SamLinearClamp = RHICreateSamplerState(SamplerStateInitializer);
	ExecuteEndDel = NewExecuteEndDel;
	return true;
}
void FIndirectCSHandler::Execute(FRHICommandListImmediate& RHICmdList, class FSceneRenderTargets& SceneContext)
{
	if (!CanExecute())
		return;
	check(IsInRenderingThread());

	const FIntPoint SourceSize = Params.GetSourceSize();
	const FIntPoint RenderTargetSize = Params.GetRenderTargetSize();

	//Texture Size is definitely a power of 2
	const bool IsSameResolution = SourceSize == RenderTargetSize;
	const uint32 ComputeCount = !IsSameResolution ? FMath::Max(abs(log2(SourceSize.X) - log2(RenderTargetSize.X)), abs(log2(SourceSize.Y) - log2(RenderTargetSize.Y))) : 1;
	 
	TArray<FIntPoint> RtResolution;
	FIntPoint AllocateRenderTargetSize = SourceSize;
	EPixelFormat Format = Params.RenderTarget->GetRenderTargetResource()->TextureRHI->GetFormat();

	const uint32 RtOffset = CsOutput.Num(); 
	for (uint32 i = 0; i < ComputeCount; ++i)
	{
		if (!IsSameResolution)
		{  
			if (RenderTargetSize.X > SourceSize.X)
				AllocateRenderTargetSize.X = FMath::Min(AllocateRenderTargetSize.X * 2, RenderTargetSize.X);
			else if (RenderTargetSize.X < SourceSize.X)
				AllocateRenderTargetSize.X = FMath::Max(AllocateRenderTargetSize.X / 2, RenderTargetSize.X);
			if (RenderTargetSize.Y > SourceSize.Y)
				AllocateRenderTargetSize.Y = FMath::Min(AllocateRenderTargetSize.Y * 2, RenderTargetSize.Y);
			else if (RenderTargetSize.Y < SourceSize.Y)
				AllocateRenderTargetSize.Y = FMath::Max(AllocateRenderTargetSize.Y / 2, RenderTargetSize.Y); 
		}

		TRefCountPtr<IPooledRenderTarget> AllocatedRt;
		FPooledRenderTargetDesc ComputeShaderOutputDesc(FPooledRenderTargetDesc::Create2DDesc(AllocateRenderTargetSize, Format, FClearValueBinding::None, TexCreate_None, TexCreate_ShaderResource | TexCreate_UAV, false));
		ComputeShaderOutputDesc.DebugName = TEXT("IndirectCS_Output_RenderTarget");
		GRenderTargetPool.FindFreeElement(RHICmdList, ComputeShaderOutputDesc, AllocatedRt, TEXT("IndirectCS_Output_RenderTarget"));
		CsOutput.Add(MoveTemp(AllocatedRt));	
		RtResolution.Add(AllocateRenderTargetSize);	 
	}
 
	TShaderMapRef<FScalingTextureCS> IndirectCS(GetGlobalShaderMap(GMaxRHIFeatureLevel));
	for (uint32 i = 0; i < ComputeCount; ++i)
	{
		int32 OutputIndex = i + RtOffset;
		int32 PreOutputIndex = OutputIndex - 1;

		FScalingTextureCS::FParameters PassParameters;
		PassParameters.InputDimention = i == 0 ? SourceSize : RtResolution[i - 1];
		PassParameters.OutputDimention = RtResolution[i];
		PassParameters.InvOutputDimention = FVector2D(1.0f / PassParameters.OutputDimention.X, 1.0f / PassParameters.OutputDimention.Y);
		PassParameters.InputTexture = i == 0 ? Params.Source->Resource->TextureRHI : CsOutput[PreOutputIndex]->GetRenderTargetItem().ShaderResourceTexture;
		PassParameters.OutputTexture = CsOutput[OutputIndex]->GetRenderTargetItem().UAV;
		PassParameters.SamLinearClamp = SamLinearClamp;
 
		//Dispatch the compute shader
		if (i > 0)
			RHICmdList.TransitionResource(EResourceTransitionAccess::EReadable, EResourceTransitionPipeline::EComputeToCompute, CsOutput[PreOutputIndex]->GetRenderTargetItem().ShaderResourceTexture);
		RHICmdList.TransitionResource(EResourceTransitionAccess::ERWBarrier, EResourceTransitionPipeline::EGfxToCompute, CsOutput[OutputIndex]->GetRenderTargetItem().UAV);
		FComputeShaderUtils::Dispatch(RHICmdList, IndirectCS, PassParameters, CalDispatchGroupDim(RtResolution[i]));
	}
	  
	RHICmdList.CopyTexture(CsOutput[ComputeCount - 1 + RtOffset]->GetRenderTargetItem().ShaderResourceTexture, Params.RenderTarget->GetRenderTargetResource()->TextureRHI, FRHICopyTextureInfo());
	ExecuteEndDel.Execute();
} 
void FIndirectCSHandler::End()
{ 
	if (!OnPostResolvedSceneColorHandle.IsValid())
		return;
	 
	const FName RendererModuleName("Renderer");
	IRendererModule* RendererModule = FModuleManager::GetModulePtr<IRendererModule>(RendererModuleName);
	if (RendererModule)
		RendererModule->GetResolvedSceneColorCallbacks().Remove(OnPostResolvedSceneColorHandle);
	OnPostResolvedSceneColorHandle.Reset();

	FCoreDelegates::OnEndFrameRT.Remove(EndRenderFrameHandle);
	EndRenderFrameHandle.Reset();
	SamLinearClamp = nullptr;
	ExecuteEndDel.Unbind();
}
void FIndirectCSHandler::ClearAllocatedRt()
{
	for (int32 i = 0; i < CsOutput.Num(); ++i)
		GRenderTargetPool.FreeUnusedResource(CsOutput[i]);
	CsOutput.Reset();
}
