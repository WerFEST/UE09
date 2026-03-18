// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UE09PlayerController.generated.h"


class UInputMappingContext;


/**
 * 
 */
UCLASS()
class UE09TPS_API AUE09PlayerController : public APlayerController
{
	GENERATED_BODY()

	/** METHODS **/

public:

protected:
	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

private:


	/** PROPERTIES **/

public:

protected:
	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

private:


	
};
