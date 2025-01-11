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

	// Broadcast all Asset Tags
	EffectAssetTags.Broadcast(TagContainer);
}
