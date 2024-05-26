// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class IAssetTypeActions;
class FIndirectTexturePluginEditorModule final : public IModuleInterface
{
private:
	TSharedPtr<IAssetTypeActions> IndirectionAssetTypeActions;
public:
	/** IModuleInterface implementation */
	void StartupModule() final;
	void ShutdownModule() final;
public:
	void RegisterAssetTypeAction(IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> Action);
};
