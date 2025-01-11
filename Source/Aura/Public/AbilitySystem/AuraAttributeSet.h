// Copyright Lone Moose Interactive

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT(BlueprintType)
struct FEffectProperties
{
	GENERATED_BODY()
	FEffectProperties()
	{
	}

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	FGameplayEffectContextHandle EffectContextHandle;

	/* Source */
	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<UAbilitySystemComponent> SourceAbilitySystemComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<AActor> SourceAvatarActor = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<AController> SourceController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<ACharacter> SourceCharacter = nullptr;


	/* Target */
	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<AActor> TargetAvatarActor = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<AController> TargetController = nullptr;

	UPROPERTY(BlueprintReadOnly, Category="Effects")
	TObjectPtr<ACharacter> TargetCharacter = nullptr;
};

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	/**
	 *  Primary Attributes
	 */

	/* Strength */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength);

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	/* End Strength */

	/* Intelligence */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Primary Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence);

	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	/* End Intelligence */

	/* Resilience */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Primary Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Resilience);

	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;
	/* End Resilience */

	/* Vigor */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Primary Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vigor);

	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;
	/* End Vigor */

	/**
	 *  Secondary Attributes
	 */

	/* Armor */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Armor);

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;
	/* End Armor */

	/* ArmorPenetration */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Secondary Attributes")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ArmorPenetration);

	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;
	/* End ArmorPenetration */

	/* BlockChance */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Secondary Attributes")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, BlockChance);

	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;
	/* End BlockChance */

	/* CriticalHitChance */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Secondary Attributes")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitChance);

	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;
	/* End CriticalHitChance */

	/* CriticalHitDamage */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Secondary Attributes")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitDamage);

	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;
	/* End CriticalHitDamage */

	/* CriticalHitResistance */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Secondary Attributes")
	FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, CriticalHitResistance);

	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;
	/* End CriticalHitResistance */

	/* HealthRegeneration */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Secondary Attributes")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HealthRegeneration);

	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;
	/* End HealthRegeneration */

	/* ManaRegeneration */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Mana, Category="Secondary Attributes")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, ManaRegeneration);

	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;
	/* End ManaRegeneration */

	/* Max Health */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxHealth, Category="Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	/* End Max Health */

	/* Max MaxMana */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxMana, Category="Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	/* End MaxMana */

	/**
	 * Vital Attributes
	 **/

	/** Health */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Health, Category="Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	/* End Health */


	/* Max Mana */
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Mana, Category="Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	/* End Mana */


private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
