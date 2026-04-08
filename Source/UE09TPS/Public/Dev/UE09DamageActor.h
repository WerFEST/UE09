// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "UE09DamageActor.generated.h"


UCLASS()
class UE09TPS_API AUE09DamageActor : public AActor
{
	GENERATED_BODY()

public:

	AUE09DamageActor();

	virtual void Tick( float DeltaTime ) override;


protected:

	virtual void BeginPlay() override;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	float Radius = 500.0f;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	float Segments = 16.0f;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	float Damage = 10.0f;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	bool bDoFullDamage = false;

};
