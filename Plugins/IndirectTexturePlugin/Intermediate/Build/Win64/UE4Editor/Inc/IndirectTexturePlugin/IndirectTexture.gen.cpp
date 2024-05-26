// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IndirectTexturePlugin/Public/IndirectTexture.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIndirectTexture() {}
// Cross Module References
	INDIRECTTEXTUREPLUGIN_API UClass* Z_Construct_UClass_UIndirectTexture_NoRegister();
	INDIRECTTEXTUREPLUGIN_API UClass* Z_Construct_UClass_UIndirectTexture();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_IndirectTexturePlugin();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UIndirectTexture::execSetIndirectResolution)
	{
		P_GET_STRUCT(FIntPoint,Z_Param_NewIndirectResolution);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIndirectResolution(Z_Param_NewIndirectResolution);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UIndirectTexture::execSetTileSetCount)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_NewTileSetCount);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTileSetCount(Z_Param_NewTileSetCount);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UIndirectTexture::execSetSource)
	{
		P_GET_OBJECT(UTexture2D,Z_Param_NewSource);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSource(Z_Param_NewSource);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UIndirectTexture::execGetIndirectResolution)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FIntPoint*)Z_Param__Result=P_THIS->GetIndirectResolution();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UIndirectTexture::execGetTileSetCount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetTileSetCount();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UIndirectTexture::execGetSource)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=P_THIS->GetSource();
		P_NATIVE_END;
	}
	void UIndirectTexture::StaticRegisterNativesUIndirectTexture()
	{
		UClass* Class = UIndirectTexture::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetIndirectResolution", &UIndirectTexture::execGetIndirectResolution },
			{ "GetSource", &UIndirectTexture::execGetSource },
			{ "GetTileSetCount", &UIndirectTexture::execGetTileSetCount },
			{ "SetIndirectResolution", &UIndirectTexture::execSetIndirectResolution },
			{ "SetSource", &UIndirectTexture::execSetSource },
			{ "SetTileSetCount", &UIndirectTexture::execSetTileSetCount },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics
	{
		struct IndirectTexture_eventGetIndirectResolution_Parms
		{
			FIntPoint ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(IndirectTexture_eventGetIndirectResolution_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "CallInEditor", "true" },
		{ "Category", "UIndirectTexture" },
		{ "ModuleRelativePath", "Public/IndirectTexture.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UIndirectTexture, nullptr, "GetIndirectResolution", nullptr, nullptr, sizeof(IndirectTexture_eventGetIndirectResolution_Parms), Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UIndirectTexture_GetSource_Statics
	{
		struct IndirectTexture_eventGetSource_Parms
		{
			UTexture2D* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UIndirectTexture_GetSource_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(IndirectTexture_eventGetSource_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UIndirectTexture_GetSource_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIndirectTexture_GetSource_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndirectTexture_GetSource_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "CallInEditor", "true" },
		{ "Category", "UIndirectTexture" },
		{ "ModuleRelativePath", "Public/IndirectTexture.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UIndirectTexture_GetSource_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UIndirectTexture, nullptr, "GetSource", nullptr, nullptr, sizeof(IndirectTexture_eventGetSource_Parms), Z_Construct_UFunction_UIndirectTexture_GetSource_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_GetSource_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UIndirectTexture_GetSource_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_GetSource_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UIndirectTexture_GetSource()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UIndirectTexture_GetSource_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics
	{
		struct IndirectTexture_eventGetTileSetCount_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(IndirectTexture_eventGetTileSetCount_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics::Function_MetaDataParams[] = {
		{ "BlueprintGetter", "" },
		{ "CallInEditor", "true" },
		{ "Category", "UIndirectTexture" },
		{ "ModuleRelativePath", "Public/IndirectTexture.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UIndirectTexture, nullptr, "GetTileSetCount", nullptr, nullptr, sizeof(IndirectTexture_eventGetTileSetCount_Parms), Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UIndirectTexture_GetTileSetCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UIndirectTexture_GetTileSetCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics
	{
		struct IndirectTexture_eventSetIndirectResolution_Parms
		{
			FIntPoint NewIndirectResolution;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewIndirectResolution_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NewIndirectResolution;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::NewProp_NewIndirectResolution_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::NewProp_NewIndirectResolution = { "NewIndirectResolution", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(IndirectTexture_eventSetIndirectResolution_Parms, NewIndirectResolution), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::NewProp_NewIndirectResolution_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::NewProp_NewIndirectResolution_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::NewProp_NewIndirectResolution,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "CallInEditor", "true" },
		{ "Category", "UIndirectTexture" },
		{ "ModuleRelativePath", "Public/IndirectTexture.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UIndirectTexture, nullptr, "SetIndirectResolution", nullptr, nullptr, sizeof(IndirectTexture_eventSetIndirectResolution_Parms), Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UIndirectTexture_SetSource_Statics
	{
		struct IndirectTexture_eventSetSource_Parms
		{
			UTexture2D* NewSource;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NewSource;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UIndirectTexture_SetSource_Statics::NewProp_NewSource = { "NewSource", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(IndirectTexture_eventSetSource_Parms, NewSource), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UIndirectTexture_SetSource_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIndirectTexture_SetSource_Statics::NewProp_NewSource,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndirectTexture_SetSource_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "CallInEditor", "true" },
		{ "Category", "UIndirectTexture" },
		{ "ModuleRelativePath", "Public/IndirectTexture.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UIndirectTexture_SetSource_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UIndirectTexture, nullptr, "SetSource", nullptr, nullptr, sizeof(IndirectTexture_eventSetSource_Parms), Z_Construct_UFunction_UIndirectTexture_SetSource_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_SetSource_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UIndirectTexture_SetSource_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_SetSource_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UIndirectTexture_SetSource()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UIndirectTexture_SetSource_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics
	{
		struct IndirectTexture_eventSetTileSetCount_Parms
		{
			int32 NewTileSetCount;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewTileSetCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NewTileSetCount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::NewProp_NewTileSetCount_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::NewProp_NewTileSetCount = { "NewTileSetCount", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(IndirectTexture_eventSetTileSetCount_Parms, NewTileSetCount), METADATA_PARAMS(Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::NewProp_NewTileSetCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::NewProp_NewTileSetCount_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::NewProp_NewTileSetCount,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "CallInEditor", "true" },
		{ "Category", "UIndirectTexture" },
		{ "ModuleRelativePath", "Public/IndirectTexture.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UIndirectTexture, nullptr, "SetTileSetCount", nullptr, nullptr, sizeof(IndirectTexture_eventSetTileSetCount_Parms), Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UIndirectTexture_SetTileSetCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UIndirectTexture_SetTileSetCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UIndirectTexture_NoRegister()
	{
		return UIndirectTexture::StaticClass();
	}
	struct Z_Construct_UClass_UIndirectTexture_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IndirectResolution_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_IndirectResolution;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TileSetCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_TileSetCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Source_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Source;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIndirectTexture_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_IndirectTexturePlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UIndirectTexture_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UIndirectTexture_GetIndirectResolution, "GetIndirectResolution" }, // 2584699682
		{ &Z_Construct_UFunction_UIndirectTexture_GetSource, "GetSource" }, // 2302750928
		{ &Z_Construct_UFunction_UIndirectTexture_GetTileSetCount, "GetTileSetCount" }, // 823419705
		{ &Z_Construct_UFunction_UIndirectTexture_SetIndirectResolution, "SetIndirectResolution" }, // 1604412886
		{ &Z_Construct_UFunction_UIndirectTexture_SetSource, "SetSource" }, // 2158625405
		{ &Z_Construct_UFunction_UIndirectTexture_SetTileSetCount, "SetTileSetCount" }, // 1847147425
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIndirectTexture_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "IndirectTexture.h" },
		{ "ModuleRelativePath", "Public/IndirectTexture.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIndirectTexture_Statics::NewProp_IndirectResolution_MetaData[] = {
		{ "BlueprintGetter", "GetIndirectResolution" },
		{ "BlueprintSetter", "SetIndirectResolution" },
		{ "Category", "UIndirectTexture" },
		{ "ModuleRelativePath", "Public/IndirectTexture.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UIndirectTexture_Statics::NewProp_IndirectResolution = { "IndirectResolution", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIndirectTexture, IndirectResolution), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UClass_UIndirectTexture_Statics::NewProp_IndirectResolution_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UIndirectTexture_Statics::NewProp_IndirectResolution_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIndirectTexture_Statics::NewProp_TileSetCount_MetaData[] = {
		{ "BlueprintGetter", "GetTileSetCount" },
		{ "BlueprintSetter", "SetTileSetCount" },
		{ "Category", "UIndirectTexture" },
		{ "ModuleRelativePath", "Public/IndirectTexture.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UIndirectTexture_Statics::NewProp_TileSetCount = { "TileSetCount", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIndirectTexture, TileSetCount), METADATA_PARAMS(Z_Construct_UClass_UIndirectTexture_Statics::NewProp_TileSetCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UIndirectTexture_Statics::NewProp_TileSetCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIndirectTexture_Statics::NewProp_Source_MetaData[] = {
		{ "BlueprintGetter", "GetSource" },
		{ "BlueprintSetter", "SetSource" },
		{ "CallInEditor", "true" },
		{ "Category", "UIndirectTexture" },
		{ "ModuleRelativePath", "Public/IndirectTexture.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UIndirectTexture_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIndirectTexture, Source), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UIndirectTexture_Statics::NewProp_Source_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UIndirectTexture_Statics::NewProp_Source_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UIndirectTexture_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIndirectTexture_Statics::NewProp_IndirectResolution,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIndirectTexture_Statics::NewProp_TileSetCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UIndirectTexture_Statics::NewProp_Source,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIndirectTexture_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UIndirectTexture>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UIndirectTexture_Statics::ClassParams = {
		&UIndirectTexture::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UIndirectTexture_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UIndirectTexture_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UIndirectTexture_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UIndirectTexture_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UIndirectTexture()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UIndirectTexture_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIndirectTexture, 1064932495);
	template<> INDIRECTTEXTUREPLUGIN_API UClass* StaticClass<UIndirectTexture>()
	{
		return UIndirectTexture::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIndirectTexture(Z_Construct_UClass_UIndirectTexture, &UIndirectTexture::StaticClass, TEXT("/Script/IndirectTexturePlugin"), TEXT("UIndirectTexture"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIndirectTexture);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
