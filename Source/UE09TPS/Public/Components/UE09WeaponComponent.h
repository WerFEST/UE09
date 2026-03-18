// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UE09WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE09TPS_API UUE09WeaponComponent : public UActorComponent
{
	GENERATED_BODY()


	/** METHODS **/

public:
	UUE09WeaponComponent();

protected:
	virtual void BeginPlay() override;

private:


	/** PROPERTIES **/

public:

protected:

private:

};
