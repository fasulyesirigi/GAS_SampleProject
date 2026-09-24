// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "CustomAbilitySystemComponent.generated.h"

/**
 *
 */
UCLASS()
class GAS_SAMPLEPROJECT_API UCustomAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

protected:
	TArray<FGameplayAbilitySpec> LastActivatedAbilities;

public:
	UCustomAbilitySystemComponent();

protected:
	virtual void BeginPlay() override;

	void OnRep_ActivateAbilities() override;

public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
