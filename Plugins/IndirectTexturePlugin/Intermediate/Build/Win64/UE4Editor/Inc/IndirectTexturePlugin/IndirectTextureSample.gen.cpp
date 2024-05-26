// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IndirectTexturePlugin/Public/IndirectTextureSample.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIndirectTextureSample() {}
// Cross Module References
	INDIRECTTEXTUREPLUGIN_API UClass* Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_NoRegister();
	INDIRECTTEXTUREPLUGIN_API UClass* Z_Construct_UClass_UMaterialExpressionIndirectTextureSample();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialExpression();
	UPackage* Z_Construct_UPackage__Script_IndirectTexturePlugin();
	INDIRECTTEXTUREPLUGIN_API UClass* Z_Construct_UClass_UIndirectTexture_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UMaterialExpressionIndirectTextureSample::execSetIndirectTexture)
	{
		P_GET_OBJECT(UIndirectTexture,Z_Param_NewIndirectTexture);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIndirectTexture(Z_Param_NewIndirectTexture);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMaterialExpressionIndirectTextureSample::execGetIndirectTexture)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UIndirectTexture**)Z_Param__Result=P_THIS->GetIndirectTexture();
		P_NATIVE_END;
	}
	void UMaterialExpressionIndirectTextureSample::StaticRegisterNativesUMaterialExpressionIndirectTextureSample()
	{
		UClass* Class = UMaterialExpressionIndirectTextureSample::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetIndirectTexture", &UMaterialExpressionIndirectTextureSample::execGetIndirectTexture },
			{ "SetIndirectTexture", &UMaterialExpressionIndirectTextureSample::execSetIndirectTexture },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics
	{
		struct MaterialExpressionIndirectTextureSample_eventGetIndirectTexture_Parms
		{
			UIndirectTexture* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MaterialExpressionIndirectTextureSample_eventGetIndirectTexture_Parms, ReturnValue), Z_Construct_UClass_UIndirectTexture_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "UIndirectTextureSample" },
		{ "ModuleRelativePath", "Public/IndirectTextureSample.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMaterialExpressionIndirectTextureSample, nullptr, "GetIndirectTexture", nullptr, nullptr, sizeof(MaterialExpressionIndirectTextureSample_eventGetIndirectTexture_Parms), Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics
	{
		struct MaterialExpressionIndirectTextureSample_eventSetIndirectTexture_Parms
		{
			UIndirectTexture* NewIndirectTexture;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NewIndirectTexture;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics::NewProp_NewIndirectTexture = { "NewIndirectTexture", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MaterialExpressionIndirectTextureSample_eventSetIndirectTexture_Parms, NewIndirectTexture), Z_Construct_UClass_UIndirectTexture_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics::NewProp_NewIndirectTexture,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "UIndirectTextureSample" },
		{ "ModuleRelativePath", "Public/IndirectTextureSample.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMaterialExpressionIndirectTextureSample, nullptr, "SetIndirectTexture", nullptr, nullptr, sizeof(MaterialExpressionIndirectTextureSample_eventSetIndirectTexture_Parms), Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_NoRegister()
	{
		return UMaterialExpressionIndirectTextureSample::StaticClass();
	}
	struct Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IndirectTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_IndirectTexture;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMaterialExpression,
		(UObject* (*)())Z_Construct_UPackage__Script_IndirectTexturePlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_GetIndirectTexture, "GetIndirectTexture" }, // 414668488
		{ &Z_Construct_UFunction_UMaterialExpressionIndirectTextureSample_SetIndirectTexture, "SetIndirectTexture" }, // 2664644494
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "IndirectTextureSample.h" },
		{ "ModuleRelativePath", "Public/IndirectTextureSample.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::NewProp_IndirectTexture_MetaData[] = {
		{ "BlueprintGetter", "GetIndirectTexture" },
		{ "BlueprintSetter", "SetIndirectTexture" },
		{ "Category", "UIndirectTexture" },
		{ "Comment", "// Indirect texture to sample\n" },
		{ "ModuleRelativePath", "Public/IndirectTextureSample.h" },
		{ "ToolTip", "Indirect texture to sample" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::NewProp_IndirectTexture = { "IndirectTexture", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMaterialExpressionIndirectTextureSample, IndirectTexture), Z_Construct_UClass_UIndirectTexture_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::NewProp_IndirectTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::NewProp_IndirectTexture_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::NewProp_IndirectTexture,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMaterialExpressionIndirectTextureSample>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::ClassParams = {
		&UMaterialExpressionIndirectTextureSample::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMaterialExpressionIndirectTextureSample()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMaterialExpressionIndirectTextureSample_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMaterialExpressionIndirectTextureSample, 2858687687);
	template<> INDIRECTTEXTUREPLUGIN_API UClass* StaticClass<UMaterialExpressionIndirectTextureSample>()
	{
		return UMaterialExpressionIndirectTextureSample::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMaterialExpressionIndirectTextureSample(Z_Construct_UClass_UMaterialExpressionIndirectTextureSample, &UMaterialExpressionIndirectTextureSample::StaticClass, TEXT("/Script/IndirectTexturePlugin"), TEXT("UMaterialExpressionIndirectTextureSample"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMaterialExpressionIndirectTextureSample);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
