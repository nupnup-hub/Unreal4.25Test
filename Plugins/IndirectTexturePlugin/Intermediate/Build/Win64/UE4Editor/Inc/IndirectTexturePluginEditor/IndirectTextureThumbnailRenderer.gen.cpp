// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IndirectTexturePluginEditor/Public/IndirectTextureThumbnailRenderer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIndirectTextureThumbnailRenderer() {}
// Cross Module References
	INDIRECTTEXTUREPLUGINEDITOR_API UClass* Z_Construct_UClass_UIndirectTextureThumbnailRenderer_NoRegister();
	INDIRECTTEXTUREPLUGINEDITOR_API UClass* Z_Construct_UClass_UIndirectTextureThumbnailRenderer();
	UNREALED_API UClass* Z_Construct_UClass_UThumbnailRenderer();
	UPackage* Z_Construct_UPackage__Script_IndirectTexturePluginEditor();
// End Cross Module References
	void UIndirectTextureThumbnailRenderer::StaticRegisterNativesUIndirectTextureThumbnailRenderer()
	{
	}
	UClass* Z_Construct_UClass_UIndirectTextureThumbnailRenderer_NoRegister()
	{
		return UIndirectTextureThumbnailRenderer::StaticClass();
	}
	struct Z_Construct_UClass_UIndirectTextureThumbnailRenderer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIndirectTextureThumbnailRenderer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UThumbnailRenderer,
		(UObject* (*)())Z_Construct_UPackage__Script_IndirectTexturePluginEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIndirectTextureThumbnailRenderer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "IndirectTextureThumbnailRenderer.h" },
		{ "ModuleRelativePath", "Public/IndirectTextureThumbnailRenderer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIndirectTextureThumbnailRenderer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UIndirectTextureThumbnailRenderer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UIndirectTextureThumbnailRenderer_Statics::ClassParams = {
		&UIndirectTextureThumbnailRenderer::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UIndirectTextureThumbnailRenderer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UIndirectTextureThumbnailRenderer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UIndirectTextureThumbnailRenderer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UIndirectTextureThumbnailRenderer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIndirectTextureThumbnailRenderer, 3986496225);
	template<> INDIRECTTEXTUREPLUGINEDITOR_API UClass* StaticClass<UIndirectTextureThumbnailRenderer>()
	{
		return UIndirectTextureThumbnailRenderer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIndirectTextureThumbnailRenderer(Z_Construct_UClass_UIndirectTextureThumbnailRenderer, &UIndirectTextureThumbnailRenderer::StaticClass, TEXT("/Script/IndirectTexturePluginEditor"), TEXT("UIndirectTextureThumbnailRenderer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIndirectTextureThumbnailRenderer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
