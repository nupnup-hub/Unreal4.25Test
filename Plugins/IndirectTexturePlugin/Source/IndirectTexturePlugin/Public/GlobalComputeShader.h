// Fill out your copyright notice in the Description page of Project Settings.


#pragma once
#include "CoreMinimal.h"
#include "GlobalShader.h" 
#include "ShaderCore.h"
#include "Runtime/Engine/Classes/Engine/TextureRenderTarget2D.h"

/**
 *
 */
class UTexture;
struct FIndirectCSParameters
{
public:
	UTexture2D* Source;
	UTexture2D* Indirect;
	UTextureRenderTarget2D* RenderTarget;
public:
	FIndirectCSParameters() = default;
	FIndirectCSParameters(UTexture2D* Source, UTexture2D* Indirect, UTextureRenderTarget2D* RenderTarget);
public:
	FIntPoint GetSourceSize()const;
	FIntPoint GetRenderTargetSize() const; 
public:
	void Update(UTexture2D* NewSource, UTexture2D* NewIndirect, UTextureRenderTarget2D* NewRenderTarget);
public:
	bool IsValid()const; 
};

DECLARE_DELEGATE(FIndirectCSDelegate);
class INDIRECTTEXTUREPLUGIN_API FIndirectCSHandler
{
private:
	FIndirectCSParameters Params;
	FRHISamplerState* SamLinearClamp; 
	FDelegateHandle OnPostResolvedSceneColorHandle; 
	FDelegateHandle EndRenderFrameHandle;
	TArray<TRefCountPtr<IPooledRenderTarget>> CsOutput;
private:
	FIndirectCSDelegate ExecuteEndDel;
public:
	bool IsRegistered()const;
private:
	bool CanExecute()const;
public:
	// Call this whenever you have new parameters to share.
	void UpdateParameters(const FIndirectCSParameters& NewParameters);
public:
	bool Begin(FIndirectCSDelegate NewExecuteEndDel);
	void Execute(FRHICommandListImmediate& RHICmdList, FSceneRenderTargets& SceneContext);
	void End();
public:
	void ClearAllocatedRt();
};
