// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
 

#include "CoreMinimal.h"
#include "ThumbnailRendering/ThumbnailRenderer.h"
#include "IndirectTextureThumbnailRenderer.generated.h"
 

UCLASS()
class INDIRECTTEXTUREPLUGINEDITOR_API UIndirectTextureThumbnailRenderer : public UThumbnailRenderer
{
GENERATED_BODY()
	public:
	virtual void Draw(UObject* Object, int32 X, int32 Y, uint32 Width, uint32 Height, FRenderTarget* RenderTarget, FCanvas* Canvas, bool bAdditionalViewFamily) override;
	virtual bool CanVisualizeAsset(UObject* Object) override;
};
 