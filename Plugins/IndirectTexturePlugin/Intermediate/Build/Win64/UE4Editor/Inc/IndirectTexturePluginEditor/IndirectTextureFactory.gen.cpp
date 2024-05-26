// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IndirectTexturePluginEditor/Public/IndirectTextureFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIndirectTextureFactory() {}
// Cross Module References
	INDIRECTTEXTUREPLUGINEDITOR_API UClass* Z_Construct_UClass_UIndirectTextureFactory_NoRegister();
	INDIRECTTEXTUREPLUGINEDITOR_API UClass* Z_Construct_UClass_UIndirectTextureFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_IndirectTexturePluginEditor();
// End Cross Module References
	void UIndirectTextureFactory::StaticRegisterNativesUIndirectTextureFactory()
	{
	}
	UClass* Z_Construct_UClass_UIndirectTextureFactory_NoRegister()
	{
		return UIndirectTextureFactory::StaticClass();
	}
	struct Z_Construct_UClass_UIndirectTextureFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIndirectTextureFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_IndirectTexturePluginEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIndirectTextureFactory_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "IndirectTextureFactory.h" },
		{ "ModuleRelativePath", "Public/IndirectTextureFactory.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIndirectTextureFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UIndirectTextureFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UIndirectTextureFactory_Statics::ClassParams = {
		&UIndirectTextureFactory::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UIndirectTextureFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UIndirectTextureFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UIndirectTextureFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UIndirectTextureFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIndirectTextureFactory, 1438457171);
	template<> INDIRECTTEXTUREPLUGINEDITOR_API UClass* StaticClass<UIndirectTextureFactory>()
	{
		return UIndirectTextureFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIndirectTextureFactory(Z_Construct_UClass_UIndirectTextureFactory, &UIndirectTextureFactory::StaticClass, TEXT("/Script/IndirectTexturePluginEditor"), TEXT("UIndirectTextureFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIndirectTextureFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
