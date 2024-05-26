// Fill out your copyright notice in the Description page of Project Settings.


#include "IndirectTextureAssetTypeAction.h"
#include "IndirectTexture.h"

FIndirectTextureAssetTypeAction::FIndirectTextureAssetTypeAction(EAssetTypeCategories::Type Categories, FText Name)
    :Categories(Categories), Name(Name)
{
}
FIndirectTextureAssetTypeAction::~FIndirectTextureAssetTypeAction()
{
}
UClass* FIndirectTextureAssetTypeAction::GetSupportedClass() const
{
    return UIndirectTexture::StaticClass();
}
FText FIndirectTextureAssetTypeAction::GetName() const
{
    return Name;
}
FColor FIndirectTextureAssetTypeAction::GetTypeColor() const
{
    return FColor::Cyan;
}
uint32 FIndirectTextureAssetTypeAction::GetCategories()
{
    return Categories;  
}