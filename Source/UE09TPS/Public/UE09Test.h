// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UE09TPS/UE09TPS.h"

#include "UE09Test.generated.h"


UCLASS()
class UE09TPS_API AUE09Test : public AActor
{
	GENERATED_BODY()
	

public:	
	AUE09Test();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UE09|CharStats")
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UE09|CharStats")
	float Stamina;

	UPROPERTY(EditInstanceOnly, Category = "UE09|AdditionalStats")
	int32 Level;

	UFUNCTION(BlueprintPure)
	inline float GetHealth() 
	{ 
		return Health; 
	};

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "UE09")
	float Foo();




protected:
	virtual void BeginPlay() override;

private:

};
