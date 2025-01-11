// Copyright Lone Moose Interactive

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "ModMagCalc_MaxMana.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UModMagCalc_MaxMana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UModMagCalc_MaxMana();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
	FGameplayEffectAttributeCaptureDefinition IntelligenceDef;
};
