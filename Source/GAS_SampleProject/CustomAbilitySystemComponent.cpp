// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAbilitySystemComponent.h"
#include "BaseCharacter.h"

UCustomAbilitySystemComponent::UCustomAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCustomAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCustomAbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();

	ABaseCharacter* Character = Cast<ABaseCharacter>(GetOwner());
	if (!Character) return;

	Character->SendAbilitiesChangedEvent();
	bool bAbilitiesChanged = false;

	if (LastActivatedAbilities.Num() != ActivatableAbilities.Items.Num())
	{
		bAbilitiesChanged = true;
	}
	else
	{
		for (int32 i = 0; i < LastActivatedAbilities.Num(); ++i)
		{
			if (LastActivatedAbilities[i].Ability != ActivatableAbilities.Items[i].Ability)
			{
				bAbilitiesChanged = true;
				break;
			}
		}
	}
	if (bAbilitiesChanged)
	{
		Character->SendAbilitiesChangedEvent();
		LastActivatedAbilities = ActivatableAbilities.Items;
	}

}

void UCustomAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
