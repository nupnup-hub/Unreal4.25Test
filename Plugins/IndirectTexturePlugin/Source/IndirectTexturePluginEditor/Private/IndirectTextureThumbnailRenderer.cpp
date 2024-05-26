// Fill out your copyright notice in the Description page of Project Settings.


/*
#include "IndirectTextureThumbnailRenderer.h"
#include "Engine/Texture.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "IndirectTexture.h"

void UIndirectTextureThumbnailRenderer::Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas, bool bAdditionalViewFamily)
{
	UIndirectTexture* IndirectTextureHandler = Cast<UIndirectTexture>(Object);
	if (IndirectTextureHandler && IndirectTextureHandler->GetIndirectTexture())
	{
		UTexture* Source = IndirectTextureHandler->GetSource();
		UTexture* IndirectTexture = IndirectTextureHandler->GetIndirectTexture();
		if (IndirectTexture == nullptr || IndirectTexture->Resource == nullptr)
		{
			FCanvasTileItem TileItem(FVector2D(X, Y), Source->Resource, FVector2D(Width, Height), FLinearColor::White);
			TileItem.BlendMode = SE_BLEND_Opaque;
			Canvas->DrawItem(TileItem);
		}
		else
		{
			FCanvasTileItem TileItem(FVector2D(X, Y), IndirectTexture->Resource, FVector2D(Width, Height), FLinearColor::White);
			TileItem.BlendMode = SE_BLEND_Opaque;
			Canvas->DrawItem(TileItem);
		}
	}
}

bool UIndirectTextureThumbnailRenderer::CanVisualizeAsset(UObject* Object)
{
	UIndirectTexture* IndirectTexture = Cast<UIndirectTexture>(Object);
	return IndirectTexture && IndirectTexture->GetIndirectTexture() != nullptr;
}
*/