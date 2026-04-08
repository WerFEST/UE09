// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dev/PlatformTrigger.h"
#include "BasePlatform.generated.h"


class UStaticMeshComponent;


UCLASS()
class UE09TPS_API ABasePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ABasePlatform();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* PlatformMesh;

	UFUNCTION(BlueprintNativeEvent)
	void OnPlatformTriggerActivated(bool bIsActivated);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class APlatformTrigger* PlatformTrigger;

protected:
	virtual void BeginPlay() override;



};
