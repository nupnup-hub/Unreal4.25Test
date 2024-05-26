// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "IndirectTextureFactory.generated.h"

/**
 * 
 */
UCLASS()
class INDIRECTTEXTUREPLUGINEDITOR_API UIndirectTextureFactory final: public UFactory
{
	GENERATED_BODY()
public:
	UIndirectTextureFactory(const FObjectInitializer& ObjectInitializer);
public:
	UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) final;
	bool ShouldShowInNewMenu() const final;
};
