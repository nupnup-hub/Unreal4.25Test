// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
	
/**
 * 
 */
class INDIRECTTEXTUREPLUGINEDITOR_API FIndirectTextureAssetTypeAction final: public FAssetTypeActions_Base
{
private:
	EAssetTypeCategories::Type Categories;
	FText Name;
public:
	FIndirectTextureAssetTypeAction(EAssetTypeCategories::Type Categories, FText Name);
	~FIndirectTextureAssetTypeAction();
public:
	UClass* GetSupportedClass() const final;
	FText GetName() const final;
	FColor GetTypeColor() const final;
	uint32 GetCategories() final;
};
