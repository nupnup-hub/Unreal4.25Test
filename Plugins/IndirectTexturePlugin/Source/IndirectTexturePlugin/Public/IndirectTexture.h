// Fill out your copyright notice in the Description page of Project Settings.


#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GlobalComputeShader.h"
#include "IndirectTexture.generated.h"

/**
 *
 */
class UTexture;
class UTextureRenderTarget2D;
UCLASS()
class INDIRECTTEXTUREPLUGIN_API UIndirectTexture final: public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintGetter = GetSource, BlueprintSetter = SetSource, CallInEditor, Category = "UIndirectTexture")
	UTexture2D* Source = nullptr;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetTileSetCount, BlueprintSetter = SetTileSetCount, Category = "UIndirectTexture")
	int32 TileSetCount = 1;
	 
	UPROPERTY(EditAnywhere, BlueprintGetter = GetIndirectResolution, BlueprintSetter = SetIndirectResolution, Category = "UIndirectTexture")
	FIntPoint IndirectResolution = FIntPoint(1, 1);
private:
	UTexture2D* IndirectTexture = nullptr;
	UTextureRenderTarget2D* IndirectRt = nullptr;
	FIndirectCSHandler CSHandler;
private:
	FDelegateHandle InitializeDelHandle;
	FDelegateHandle UpdateIndirectTextureDelHandle;
	FDelegateHandle DestroyRtDelHandle;
private:
	bool AllowOverlapValue = false;
	bool CanUseIndirectTexture = false;
public:
	UIndirectTexture();
	~UIndirectTexture();
private:
	void Initialize();
public:
	UFUNCTION(BlueprintGetter, CallInEditor, Category = "UIndirectTexture")
	UTexture2D* GetSource()const;

	UTexture2D* GetIndirectTexture()const;

	UFUNCTION(BlueprintGetter, CallInEditor, Category = "UIndirectTexture")
	int32 GetTileSetCount()const;

	UFUNCTION(BlueprintGetter, CallInEditor, Category = "UIndirectTexture")
	FIntPoint GetIndirectResolution()const;
public:
	UFUNCTION(BlueprintSetter, CallInEditor, Category = "UIndirectTexture")
	void SetSource(UTexture2D* NewSource);

	UFUNCTION(BlueprintSetter, CallInEditor, Category = "UIndirectTexture")
	void SetTileSetCount(const int32 NewTileSetCount);

	UFUNCTION(BlueprintSetter, CallInEditor, Category = "UIndirectTexture")
	void SetIndirectResolution(const FIntPoint NewIndirectResolution);
public:
	bool HasValidSource()const;
	bool IsActivatedShader()const;
public:
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) final;
private:
	void ActivateShdaer();
	void DeActivateShader();
	void UpdateIndirectTexture();
	void RegisterUpdateIndirectTextureDelHandle();
private:
	//void TryDestoryRt(); 
};
