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
	FGameplayEffectSpecHandle SpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GamePlayEffectClass, 1.f,
		EffectContextHandle);

	// You need to dereference the TSharedPtr<GameplayEffectSpec> from the SpecHandle in order to Apply a GameplayEffectSpec (like to Self or Target)
	TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}




