// Fill out your copyright notice in the Description page of Project Settings.

#pragma once 
#include "CoreMinimal.h" 
#include "MaterialExpressionIO.h"
#include "Materials/MaterialExpression.h"  
#include "IndirectTexture.h"
#include "IndirectTextureSample.generated.h" 

/**
 *
 */ 
class UTexture;
class UMaterial;
class UMaterialExpressionCustom;
class UMaterialExpressionTextureCoordinate;
class UMaterialExpressionConstant;
class UMaterialExpressionMultiply;
class UMaterialExpressionFloor;
class UMaterialExpressionDivide;
class UMaterialExpressionComponentMask;
class UMaterialExpressionAdd;
class UMaterialExpressionTextureSample;
class FMaterialCompiler;

UCLASS()
class INDIRECTTEXTUREPLUGIN_API UMaterialExpressionIndirectTextureSample final: public UMaterialExpression
{
    GENERATED_UCLASS_BODY()
private:
    struct ExpressionSet
    {
    public:
        UMaterialExpressionCustom* Custom = nullptr;
        UMaterialExpressionTextureCoordinate* TextureCoord = nullptr;
        UMaterialExpressionConstant* TileSizeConstant = nullptr;
        UMaterialExpressionMultiply* MulTextureCoordAndTileSize = nullptr;
        UMaterialExpressionMultiply* MulAfterAppedAndTileSize = nullptr;
        UMaterialExpressionMultiply* MulAfterAppedAndTextureCoord = nullptr;
        UMaterialExpressionMultiply* MulScaleTextureCoord = nullptr;

        UMaterialExpressionFloor* FloorScaledOffset = nullptr;
        UMaterialExpressionFloor* FloorRandomizedOffset = nullptr;
        UMaterialExpressionDivide* Divide = nullptr;
        UMaterialExpressionComponentMask* ComponentMaskRG = nullptr;
        UMaterialExpressionComponentMask* ComponentMaskBA = nullptr;

        UMaterialExpressionAdd* AddTileSize = nullptr;
        UMaterialExpressionAdd* AddTextureCoord = nullptr;
        UMaterialExpressionTextureSample* Sample = nullptr;
    public:
        void Initialize();
        void Clear();
    };
public:
    // Indirect texture to sample
    UPROPERTY(EditAnywhere, BlueprintGetter = GetIndirectTexture, BlueprintSetter = SetIndirectTexture, Category = "UIndirectTexture")
    UIndirectTexture* IndirectTexture = nullptr;
private:
    FIndirectTextureEventDelegate  IndirectEventDel;
private:
    ExpressionSet Set;
public:
    ~UMaterialExpressionIndirectTextureSample();
public:
    UFUNCTION(BlueprintCallable, Category = "UIndirectTextureSample")
    UIndirectTexture* GetIndirectTexture() const;
    UObject* GetReferencedTexture()const final;
public:
    UFUNCTION(BlueprintCallable, Category = "UIndirectTextureSample")
    void SetIndirectTexture(UIndirectTexture* NewIndirectTexture);
public:
    bool CanReferenceTexture() const final;
private:
    bool IsValidTexture(UTexture* Texture)const;
private:
    void BeginDestroy() final;
    void PostLoad() final;
private:
    void NotifyIndirectTextureEvent(const INDIRECT_TEXTURE_EVENT EventType);
public:
#if WITH_EDITOR 
    int32 Compile(FMaterialCompiler* Compiler, int32 OutputIndex) final; 
#endif 
};

