// Copyright Lone Moose Interactive


#include "AbilitySystem/AuraAbilitySystemComponent.h"

#include "Aura/Aura.h"


void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                const FGameplayEffectSpec& EffectSpec,
                                                FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	// Create a Tag container first then append all the asset tags associated with the effect to the container
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	for (const FGameplayTag& Tag : TagContainer)
	{
		// TODO: Broadcast the tag to the Widget Controller
		const FString Msg = FString::Printf(TEXT("GE Tag: %s: "), *Tag.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 2.f, GB_ORANGE, Msg);
	}
}
