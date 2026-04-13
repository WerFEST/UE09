// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/UE09BaseCharacter.h"
#include "InputActionValue.h"
#include "InputAction.h"

#include "UE09PlayerCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
//class UInputAction;
//struct FInputActionValue;


DECLARE_LOG_CATEGORY_EXTERN(LogPlayerCharacter, Log, All);


/**
 * 
 */
UCLASS()
class UE09TPS_API AUE09PlayerCharacter : public AUE09BaseCharacter
{
	GENERATED_BODY()
	

	/** METHODS **/

public: 
	AUE09PlayerCharacter();


protected:
	virtual void BeginPlay() override;

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Zoom( bool bIsZooming );


private:


	/** PROPERTIES **/

public:


protected:
	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category = "UE09|Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category = "UE09|Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category = "UE09|Input")
	UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category = "UE09|Input")
	UInputAction* MouseLookAction;

	/** Mouse Look Input Action */
	UPROPERTY( EditAnywhere, Category = "UE09|Input" )
	UInputAction* ZoomAction;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;


private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UE09|Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UE09|Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

};
