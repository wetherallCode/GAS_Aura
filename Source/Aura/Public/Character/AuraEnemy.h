// Copyright Lone Moose Interactive

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	//~ Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//~ End Enemy Interface

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;
	/** End Combat Interface */
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Class Defaults")
	int32 Level;

	virtual void InitAbilityActorInfo() override;
};
