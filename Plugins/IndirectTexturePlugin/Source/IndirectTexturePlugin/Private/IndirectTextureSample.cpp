// Fill out your copyright notice in the Description page of Project Settings.


#include "IndirectTextureSample.h"
#include "IndirectTexture.h" 
#include "Materials/Material.h"
#include "MaterialCompiler.h"    
#include "Materials/MaterialExpressionScreenPosition.h"
#include "Materials/MaterialExpressionNoise.h"
#include "Materials/MaterialExpressionMultiply.h"
#include "Materials/MaterialExpressionFloor.h"
#include "Materials/MaterialExpressionDivide.h"
#include "Materials/MaterialExpressionCustom.h"
#include "Materials/MaterialExpressionComponentMask.h" 
#include "Materials/MaterialExpressionTextureCoordinate.h"
#include "Materials/MaterialExpressionTextureSample.h"
#include "Materials/MaterialExpressionConstant.h"
#include "Materials/MaterialExpressionAdd.h"
#include "Materials/MaterialExpressionSceneTexture.h"
#include "Engine/TextureRenderTarget2D.h"

#define DESTROY_EXPRESSION(e) if(e != nullptr){ e->BeginDestroy(); e = nullptr;};         

void UMaterialExpressionIndirectTextureSample::ExpressionSet::Initialize()
{
    Custom = NewObject<UMaterialExpressionCustom>();
    Custom->Inputs.Add(FCustomInput());
    Custom->Inputs[0].InputName = FName(TEXT("Uv"));
    Custom->Inputs[1].InputName = FName(TEXT("TileSize"));

    Custom->OutputType = ECustomMaterialOutputType::CMOT_Float4;
    Custom->Code = TEXT(R"(
        struct RandomNumberGenerator
        {
            uint state;

            uint2 BlockCipherTEA(uint v0, uint v1, uint iterations = 16)
            {
                uint sum = 0;
                const uint delta = 0x9e3779b9;
                const uint k[4] = { 0xa341316c, 0xc8013ea4, 0xad90777d, 0x7e95761e };
                for (uint i = 0; i < iterations; i++)
                {
                    sum += delta;
                    v0 += ((v1 << 4) + k[0]) ^ (v1 + sum) ^ ((v1 >> 5) + k[1]);
                    v1 += ((v0 << 4) + k[2]) ^ (v0 + sum) ^ ((v0 >> 5) + k[3]);
                }
                return uint2(v0, v1);
            }

            uint Interleave32bit(uint2 v)
            {
                uint x = v.x & 0x0000ffff;
                x = (x | (x << 8)) & 0x00FF00FF;
                x = (x | (x << 4)) & 0x0F0F0F0F;
                x = (x | (x << 2)) & 0x33333333;
                x = (x | (x << 1)) & 0x55555555;

                uint y = v.y & 0x0000ffff;
                y = (y | (y << 8)) & 0x00FF00FF;
                y = (y | (y << 4)) & 0x0F0F0F0F;
                y = (y | (y << 2)) & 0x33333333;
                y = (y | (y << 1)) & 0x55555555;

                return x | (y << 1);
            }

            void Initialize(uint seed)
            {
                seed = (seed ^ 61) ^ (seed >> 16);
                seed *= 9;
                seed = seed ^ (seed >> 4);
                seed *= 0x27d4eb2d;
                seed = seed ^ (seed >> 15);
                state = seed;
            }

            void Initialize(uint2 pixel, uint sampleNumber)
            {
                state = BlockCipherTEA(Interleave32bit(pixel), sampleNumber).x;
            }

            uint Random()
            {
                state ^= (state << 13);
                state ^= (state >> 17);
                state ^= (state << 5);
                return state;
            }

            float Random01()
            {
                return asfloat(0x3f800000 | Random() >> 9) - 1.0;
            }
        };

        RandomNumberGenerator Rng;
        Rng.Initialize(uint2(Uv.x * TileSize, Uv.y * TileSize), Uv.x * TileSize + Uv.y * TileSize * TileSize);
        float2 randomUv = float2(Rng.Random01(), Rng.Random01());
        int randomDirX = Rng.Random01() > 0.5f ? 1 : -1;
        int randomDirY = Rng.Random01() < 0.5f ? 1 : -1;
        return float4(randomUv, randomDirX, randomDirY);
        )");

    TextureCoord = NewObject<UMaterialExpressionTextureCoordinate>();
    TileSizeConstant = NewObject<UMaterialExpressionConstant>();
    MulTextureCoordAndTileSize = NewObject<UMaterialExpressionMultiply>();
    MulAfterAppedAndTileSize = NewObject<UMaterialExpressionMultiply>();
    MulAfterAppedAndTextureCoord = NewObject<UMaterialExpressionMultiply>();
    MulScaleTextureCoord = NewObject<UMaterialExpressionMultiply>();

    FloorScaledOffset = NewObject<UMaterialExpressionFloor>();
    FloorRandomizedOffset = NewObject<UMaterialExpressionFloor>();
    Divide = NewObject<UMaterialExpressionDivide>();
    ComponentMaskRG = NewObject<UMaterialExpressionComponentMask>();
    ComponentMaskBA = NewObject<UMaterialExpressionComponentMask>();

    AddTileSize = NewObject<UMaterialExpressionAdd>();
    AddTextureCoord = NewObject<UMaterialExpressionAdd>();
    Sample = NewObject<UMaterialExpressionTextureSample>();
}
void UMaterialExpressionIndirectTextureSample::ExpressionSet::Clear()
{
    /*
     //DESTROY_EXPRESSION(Custom)
    //DESTROY_EXPRESSION(TextureCoord)
    //DESTROY_EXPRESSION(TileSizeConstant)
    //DESTROY_EXPRESSION(MulTextureCoordAndTileSize)
   // DESTROY_EXPRESSION(MulAfterAppedAndTileSize)
   // DESTROY_EXPRESSION(MulAfterAppedAndTextureCoord)
   // DESTROY_EXPRESSION(MulScaleTextureCoord)

   // DESTROY_EXPRESSION(FloorScaledOffset)
   // DESTROY_EXPRESSION(FloorRandomizedOffset)
    //DESTROY_EXPRESSION(Divide)
    //DESTROY_EXPRESSION(ComponentMaskRG)
    //DESTROY_EXPRESSION(ComponentMaskBA)
    //DESTROY_EXPRESSION(AddTileSize)
    //DESTROY_EXPRESSION(AddTextureCoord)
    //DESTROY_EXPRESSION(Sample)  
    */
}

UMaterialExpressionIndirectTextureSample::UMaterialExpressionIndirectTextureSample(const FObjectInitializer& ObjectInitializer)
    :UMaterialExpression(ObjectInitializer)
{
    Set.Initialize();
}

UMaterialExpressionIndirectTextureSample::~UMaterialExpressionIndirectTextureSample()
{
    Set.Clear();
}
UIndirectTexture* UMaterialExpressionIndirectTextureSample::GetIndirectTexture()const
{
    return IndirectTexture;
}
UObject* UMaterialExpressionIndirectTextureSample::GetReferencedTexture()const
{
    return CanReferenceTexture() ? IndirectTexture->GetIndirectTexture() : nullptr;
}
void UMaterialExpressionIndirectTextureSample::SetIndirectTexture(UIndirectTexture* NewIndirectTexture)
{
    IndirectTexture = NewIndirectTexture;
}
bool UMaterialExpressionIndirectTextureSample::CanReferenceTexture() const
{
    return IndirectTexture != nullptr && IndirectTexture->HasValidSource();
}
bool UMaterialExpressionIndirectTextureSample::IsValidTexture(UTexture* Texture)const
{
    return Texture != nullptr && Texture->Resource != nullptr && Texture->GetMaterialType() == MCT_Texture2D;
}
#if WITH_EDITOR 
int32 UMaterialExpressionIndirectTextureSample::Compile(FMaterialCompiler* Compiler, int32 OutputIndex)
{
    if (IndirectTexture == nullptr)
        return Super::Compile(Compiler, OutputIndex);
     
    UTexture* Texture = IndirectTexture->GetIndirectTexture();
    if (!IsValidTexture(Texture))
        return Super::Compile(Compiler, OutputIndex);
     
    Set.Initialize(); 
    const uint32 TileSetCount = IndirectTexture->GetTileSetCount();
    const FVector2D IndirectResolution = IndirectTexture->GetIndirectResolution();

    Set.TileSizeConstant->R = TileSetCount;
    Set.MulTextureCoordAndTileSize->A.Connect(OutputIndex, Set.TextureCoord);
    Set.MulTextureCoordAndTileSize->B.Connect(OutputIndex, Set.TileSizeConstant);

    Set.FloorScaledOffset->Input.Connect(OutputIndex, Set.MulTextureCoordAndTileSize);
    Set.Divide->A.Connect(OutputIndex, Set.FloorScaledOffset);
    Set.Divide->B.Connect(OutputIndex, Set.TileSizeConstant);

    Set.Custom->Inputs[0].Input.Connect(OutputIndex, Set.Divide);
    Set.Custom->Inputs[1].Input.Connect(OutputIndex, Set.TileSizeConstant);

    Set.ComponentMaskRG->Input.Connect(OutputIndex, Set.Custom);
    Set.ComponentMaskRG->R = Set.ComponentMaskRG->G = true;
    Set.ComponentMaskRG->B = Set.ComponentMaskRG->A = false;

    Set.MulAfterAppedAndTileSize->A.Connect(OutputIndex, Set.ComponentMaskRG);
    Set.MulAfterAppedAndTileSize->B.Connect(OutputIndex, Set.TileSizeConstant);
    Set.FloorRandomizedOffset->Input.Connect(OutputIndex, Set.MulAfterAppedAndTileSize);

    Set.ComponentMaskBA->Input.Connect(OutputIndex, Set.Custom);
    Set.ComponentMaskBA->R = Set.ComponentMaskBA->G = false;
    Set.ComponentMaskBA->B = Set.ComponentMaskBA->A = true;

    Set.MulAfterAppedAndTextureCoord->A.Connect(OutputIndex, Set.ComponentMaskBA);
    Set.MulAfterAppedAndTextureCoord->B.Connect(OutputIndex, Set.TextureCoord);

    Set.AddTileSize->A.Connect(OutputIndex, Set.TileSizeConstant);
    Set.AddTileSize->ConstB = 0;

    Set.MulScaleTextureCoord->A.Connect(OutputIndex, Set.MulAfterAppedAndTextureCoord);
    Set.MulScaleTextureCoord->B.Connect(OutputIndex, Set.AddTileSize);

    Set.AddTextureCoord->A.Connect(OutputIndex, Set.FloorRandomizedOffset);
    Set.AddTextureCoord->B.Connect(OutputIndex, Set.MulScaleTextureCoord);

    Set.Sample->Coordinates.Connect(OutputIndex, Set.AddTextureCoord);
    Set.Sample->Texture = Texture; 
    //Set.Sample->SamplerType = EMaterialSamplerType::SAMPLERTYPE_Color;
    Set.Sample->SamplerType = EMaterialSamplerType::SAMPLERTYPE_LinearColor;
    return Set.Sample->Compile(Compiler, OutputIndex);
}  
/*
void UMaterialExpressionIndirectTextureSample ::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    FName PropertyName = (PropertyChangedEvent.MemberProperty != nullptr) ? PropertyChangedEvent.MemberProperty->GetFName() : NAME_None;

    UClass* OwnerClass = PropertyChangedEvent.MemberProperty->GetOwnerClass();
    if (OwnerClass->IsChildOf<UIndirectTexture>())
    {
        Material->MarkPackageDirty();
        Material->PreEditChange(nullptr);
        Material->PostEditChange();
    }
}
*/
#endif 