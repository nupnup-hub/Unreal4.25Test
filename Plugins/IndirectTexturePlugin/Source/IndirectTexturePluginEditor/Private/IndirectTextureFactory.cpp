// Fill out your copyright notice in the Description page of Project Settings.


#include "IndirectTextureFactory.h"
#include "IndirectTexture.h"

UIndirectTextureFactory::UIndirectTextureFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UIndirectTexture::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}
UObject* UIndirectTextureFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	check(InClass->IsChildOf(UIndirectTexture::StaticClass()));
	return NewObject<UIndirectTexture>(InParent, InClass, InName, Flags | RF_Transactional, Context);
	//return NewObject<UIndirectTextureG>(InParent, InClass, InName, Flags);
}
bool UIndirectTextureFactory::ShouldShowInNewMenu() const
{
	return true;
}