// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "UE09TPS.generated.h"


/** Main log category used across the project */
DECLARE_LOG_CATEGORY_EXTERN(LogUE09TPS, Log, All);


USTRUCT(BlueprintType)
struct FTestStats
{
	GENERATED_BODY()

public:

	FTestStats() : Health(100.0f), Stamina(100.0f), Level(1)
	{
	}

	UPROPERTY()
	float Health;

	UPROPERTY()
	float Stamina;

	UPROPERTY()
	int32 Level;





};
