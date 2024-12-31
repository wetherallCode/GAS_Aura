// Copyright Lone Moose Interactive


#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}


// Called when the game starts or when spawned
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GamePlayEffectClass)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent
		(TargetActor);

	// Check to see if the actor has a AbilitySystemComp
	if (TargetAbilitySystemComponent == nullptr)
	{
		return;
	}
	// If the actor has a AbilitySystemComp, check if the GamePlayEffectClass is set before going on
	check(GamePlayEffectClass)
	// Create the Effect Context
	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	// Make the EffectSpecHandle 
	FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(
		GamePlayEffectClass, ActorLevel,
		EffectContextHandle);

	// You need to dereference the TSharedPtr<GameplayEffectSpec> from the SpecHandle in order to Apply a GameplayEffectSpec (like to Self or Target)
	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(
		*EffectSpecHandle.Data.Get());

	if (const bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy ==
		EGameplayEffectDurationType::Infinite && InfiniteEffectRemovalPolicy ==
		EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		// Store EffectHandle is the duration policy is infinite
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetAbilitySystemComponent);
	}
}

void AAuraEffectActor::OnOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		for (const TSubclassOf<UGameplayEffect> InstantGameplayEffect : MultipleInstantGameplayEffectClass)
		{
			ApplyEffectToTarget(TargetActor, InstantGameplayEffect);
		}
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		for (const TSubclassOf<UGameplayEffect> DurationEffect : MultipleDurationGameplayEffectClass)
		{
			ApplyEffectToTarget(TargetActor, DurationEffect);
		}
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
}

void AAuraEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		for (const TSubclassOf<UGameplayEffect> InstantGameplayEffect : MultipleInstantGameplayEffectClass)
		{
			ApplyEffectToTarget(TargetActor, InstantGameplayEffect);
		}
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		for (const TSubclassOf<UGameplayEffect> DurationEffect : MultipleDurationGameplayEffectClass)
		{
			ApplyEffectToTarget(TargetActor, DurationEffect);
		}
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		for (const TSubclassOf<UGameplayEffect> DurationEffect : MultipleDurationGameplayEffectClass)
		{
			ApplyEffectToTarget(TargetActor, DurationEffect);
		}
	}
	if (InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* TargetAbilitySystemComponent =
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent
			(TargetActor);
		if (!IsValid(TargetAbilitySystemComponent))
		{
			return;
		}
		TArray<FActiveGameplayEffectHandle> HandlesToRemove;

		for (TTuple<FActiveGameplayEffectHandle, UAbilitySystemComponent*> HandlePair : ActiveEffectHandles)
		{
			if (HandlePair.Value == TargetAbilitySystemComponent)
			{
				TargetAbilitySystemComponent->RemoveActiveGameplayEffect(HandlePair.Key, 1);
				HandlesToRemove.Add(HandlePair.Key);
			}
		}
		for (FActiveGameplayEffectHandle& EffectHandle : HandlesToRemove)
		{
			ActiveEffectHandles.FindAndRemoveChecked(EffectHandle);
		}
	}
}
