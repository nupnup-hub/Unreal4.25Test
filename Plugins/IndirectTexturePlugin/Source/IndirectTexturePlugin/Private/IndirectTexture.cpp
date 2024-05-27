// Fill out your copyright notice in the Description page of Project Settings.


#include "IndirectTexture.h" 
#include "Engine/Texture.h"
#include "Engine/TextureRenderTarget2D.h" 

UIndirectTexture::UIndirectTexture()
{
	InitializeDelHandle = FCoreDelegates::OnBeginFrame.AddUObject(this, &UIndirectTexture::Initialize); 
}
UIndirectTexture::~UIndirectTexture()
{ 
}
void UIndirectTexture::Initialize()
{
	if (Source == nullptr)
		return;

	AllowOverlapValue = true;
	SetIndirectResolution(FIntPoint(Source->Resource->GetSizeX(), Source->Resource->GetSizeY()));
	AllowOverlapValue = false;

	FCoreDelegates::OnBeginFrame.Remove(InitializeDelHandle);
	InitializeDelHandle.Reset(); 
}
UTexture2D* UIndirectTexture::GetSource()const
{
	return Source;
}
UTexture2D* UIndirectTexture::GetIndirectTexture()const
{
	return IndirectTexture != nullptr && CanUseIndirectTexture ? IndirectTexture : Source;
}
int32 UIndirectTexture::GetTileSetCount()const
{
	return TileSetCount;
}
FIntPoint UIndirectTexture::GetIndirectResolution()const
{
	return IndirectResolution;
}
void UIndirectTexture::SetSource(UTexture2D* NewSource)
{
	if (Source == NewSource && !AllowOverlapValue)
		return;

	Source = NewSource;
	if (Source != nullptr)
	{
		//Cover only the cases related to the texture formats used in examples(PUBG_Test_Tileset_01) 
		DeActivateShader();
		ActivateShdaer();
	}
}
void UIndirectTexture::SetTileSetCount(int32 NewTileSetCount)
{
	TileSetCount = NewTileSetCount;
	NotifyEvent(INDIRECT_TEXTURE_EVENT::OPTION_CHAGED);
}
void UIndirectTexture::SetIndirectResolution(const FIntPoint NewIndirectResolution)
{
	if (IndirectResolution == NewIndirectResolution && !AllowOverlapValue)
		return;

	DeActivateShader(); 
	IndirectResolution.X = pow(2, ceil(log2(NewIndirectResolution.X)));
	IndirectResolution.Y = pow(2, ceil(log2(NewIndirectResolution.Y)));
	ActivateShdaer();
}
bool UIndirectTexture::HasValidSource()const
{
	return Source != nullptr;
}
bool UIndirectTexture::IsActivatedShader()const
{
	return CSHandler.IsRegistered();
}
int32 UIndirectTexture::RegisterIndirectTextureEvent(const INDIRECT_TEXTURE_EVENT EvType, FIndirectTextureEventDelegate* Handle)
{
	return EventListener.Add(Handle);
}
int32 UIndirectTexture::DeRegisterIndirectTextureEvent(const INDIRECT_TEXTURE_EVENT EvType, FIndirectTextureEventDelegate* Handle)
{
	return EventListener.Remove(Handle);
}
void UIndirectTexture::NotifyEvent(const INDIRECT_TEXTURE_EVENT EvType)
{
	for (const auto& data : EventListener)
		data->Execute(EvType);
}
void UIndirectTexture::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	//UE_LOG(LogTemp, Log, TEXT("UIndirectTexture PostEditChangeProperty"));
	Super::PostEditChangeProperty(PropertyChangedEvent);
	FName PropertyName = (PropertyChangedEvent.MemberProperty != nullptr) ? PropertyChangedEvent.MemberProperty->GetFName() : NAME_None;

	AllowOverlapValue = true;
	if (PropertyName == GET_MEMBER_NAME_CHECKED(UIndirectTexture, Source))
	{
		SetSource(Source);
	}
	else if (PropertyName == GET_MEMBER_NAME_CHECKED(UIndirectTexture, TileSetCount))
	{
		SetTileSetCount(TileSetCount);
	}
	else if (PropertyName == GET_MEMBER_NAME_CHECKED(UIndirectTexture, IndirectResolution))
	{
		SetIndirectResolution(IndirectResolution);
	}
	AllowOverlapValue = false;
}
void UIndirectTexture::ActivateShdaer()
{
	FlushRenderingCommands();

	FIndirectCSDelegate Del;
	Del.BindUObject(this, &UIndirectTexture::RegisterUpdateIndirectTextureDelHandle);

	IndirectRt = NewObject<UTextureRenderTarget2D>();
	IndirectRt->InitCustomFormat(IndirectResolution.X, IndirectResolution.Y, PF_B8G8R8A8, true);
 
	CSHandler.UpdateParameters(FIndirectCSParameters(Source, IndirectTexture, IndirectRt));
	CSHandler.Begin(Del);

	if (DestroyRtDelHandle.IsValid())
	{
		FCoreDelegates::OnBeginFrame.Remove(DestroyRtDelHandle);
		DestroyRtDelHandle.Reset();
	} 
	FlushRenderingCommands();
	CanUseIndirectTexture = false;
}
void UIndirectTexture::DeActivateShader()
{
	FlushRenderingCommands();

	CSHandler.End();
	CSHandler.UpdateParameters(FIndirectCSParameters(nullptr, nullptr, nullptr));

	FlushRenderingCommands();
}
void UIndirectTexture::UpdateIndirectTexture()
{
	if (IndirectRt == nullptr || !IndirectRt->IsValidLowLevel())
		return; 

	FlushRenderingCommands(); 
	IndirectTexture = IndirectRt->ConstructTexture2D(this, Source->GetName() + TEXT("IndirectTexture"), EObjectFlags::RF_Public);
	FCoreDelegates::OnBeginFrame.Remove(UpdateIndirectTextureDelHandle);
	UpdateIndirectTextureDelHandle.Reset();
	DeActivateShader();
	CanUseIndirectTexture = true;

	NotifyEvent(INDIRECT_TEXTURE_EVENT::INDIRECT_TEXTURE_CREATION);
}
void UIndirectTexture::RegisterUpdateIndirectTextureDelHandle()
{ 
	if (!UpdateIndirectTextureDelHandle.IsValid())
		UpdateIndirectTextureDelHandle = FCoreDelegates::OnBeginFrame.AddUObject(this, &UIndirectTexture::UpdateIndirectTexture);
} 
