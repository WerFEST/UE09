// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "UE09TPS.generated.h"


/** Main log category used across the project */
DECLARE_LOG_CATEGORY_EXTERN( LogUE09TPS, Log, All );


/** Health Delegates **/
DECLARE_DYNAMIC_MULTICAST_DELEGATE( FOnDeathSignature );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams( FOnHealthChangedSignature, float, Health, float, HealthDelta );


USTRUCT( BlueprintType )
struct FTestStats
{
	GENERATED_BODY()

public:

};