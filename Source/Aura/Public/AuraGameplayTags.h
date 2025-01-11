// Copyright Lone Moose Interactive

#pragma once

#include "CoreMinimal.h"

/**
 * Aura Gameplay Tags
 *
 * Singleton containing native Gameplay Tags
 */

struct FAuraGameplayTags
{
	static const FAuraGameplayTags Get() { return GameplayTags; }
	static void InitializeStaticGameplayTags();

private:
	static FAuraGameplayTags GameplayTags;
};
