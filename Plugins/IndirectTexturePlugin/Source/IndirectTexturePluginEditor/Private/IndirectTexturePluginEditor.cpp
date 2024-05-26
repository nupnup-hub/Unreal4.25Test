// Copyright Epic Games, Inc. All Rights Reserved.


#include "IndirectTexturePluginEditor.h"
#include "IndirectTextureAssetTypeAction.h" 
#include "IndirectTexture.h"
#include "IndirectTextureThumbnailRenderer.h"
#include "Engine/Texture.h"
#include "CanvasItem.h"
#include "CanvasTypes.h" 

#define LOCTEXT_NAMESPACE "FIndirectTexturePluginEditorModule"
 
void FIndirectTexturePluginEditorModule::StartupModule()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	FName CategoriesKey = TEXT("GenerateIndirectTextureEditorCategory");
	FText CategoriesDisplayName = LOCTEXT("CustomAssetCategory", "UserDefine");
	FText AssetName = NSLOCTEXT("AssetTypeActions", "AssetTypeActions_GenerateIndirectTexture", "IndirectTextureAsset");

	EAssetTypeCategories::Type bit = AssetTools.RegisterAdvancedAssetCategory(CategoriesKey, CategoriesDisplayName);
	RegisterAssetTypeAction(AssetTools, MakeShareable(new FIndirectTextureAssetTypeAction(bit, AssetName)));
 
	///UThumbnailManager::Get().RegisterCustomRenderer(UIndirectTexture::StaticClass(), UIndirectTextureThumbnailRenderer::StaticClass());
}
void FIndirectTexturePluginEditorModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		AssetTools.UnregisterAssetTypeActions(IndirectionAssetTypeActions.ToSharedRef());
	}
	IndirectionAssetTypeActions.Reset();

	//UThumbnailManager::Get().UnregisterCustomRenderer(UIndirectTexture::StaticClass());
}
void FIndirectTexturePluginEditorModule::RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action)
{
	AssetTools.RegisterAssetTypeActions(Action);
	IndirectionAssetTypeActions = Action;
	//UE_LOG(LogTemp, Log, TEXT("IsSupported %s"), *FString::FromInt(IndirectionAssetTypeActions->IsSupported()))
}
#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FIndirectTexturePluginEditorModule, IndirectTexturePluginEditor)