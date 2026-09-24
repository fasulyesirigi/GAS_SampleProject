// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CustomGameplayAbility.generated.h"

/**
 *
 */
UCLASS()
class GAS_SAMPLEPROJECT_API UCustomGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()


public:

	UCustomGameplayAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	bool ShouldShowInWidget = false;
};
