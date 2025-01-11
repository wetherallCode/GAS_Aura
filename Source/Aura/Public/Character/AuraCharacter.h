// Copyright Lone Moose Interactive

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class AAuraPlayerState;
class UAttributeSet;
class UAbilitySystemComponent;
class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();

	virtual void OnRep_PlayerState() override;
	virtual void PossessedBy(AController* NewController) override;

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface */
protected:
	UPROPERTY(EditDefaultsOnly, Category="Components")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category="Components")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

private:
	virtual void InitAbilityActorInfo() override;
};
