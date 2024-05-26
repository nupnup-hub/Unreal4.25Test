// Copyright Epic Games, Inc. All Rights Reserved.


#include "IndirectTexturePlugin.h"
#define LOCTEXT_NAMESPACE "FIndirectTexturePluginModule"
 
void FIndirectTexturePluginModule::StartupModule()
{
	FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Plugins/IndirectTexturePlugin/Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/CustomShaders"), ShaderDirectory);
} 
void FIndirectTexturePluginModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
IMPLEMENT_MODULE(FIndirectTexturePluginModule, IndirectTexturePlugin)