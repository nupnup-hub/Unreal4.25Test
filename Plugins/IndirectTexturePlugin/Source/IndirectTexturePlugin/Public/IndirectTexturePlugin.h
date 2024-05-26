// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FIndirectTexturePluginModule final : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	void StartupModule() final;
	void ShutdownModule() final;
};
