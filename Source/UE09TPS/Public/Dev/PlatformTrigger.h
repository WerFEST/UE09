// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "PlatformTrigger.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTriggerActivated, bool, bIsActivated);


UCLASS()
class UE09TPS_API APlatformTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	APlatformTrigger();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* TriggerBox;

	UFUNCTION()
	void OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(BlueprintAssignable)
	FOnTriggerActivated OnTriggerActivated;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SetIsActivated(bool bIsActivated_In);

	UFUNCTION(Server, Reliable)
	void Server_SetIsActivated(bool bIsActivated_In);

	UFUNCTION()
	void SetIsActivated(bool bIsActivated_In);



protected:
	virtual void BeginPlay() override;

	//UPROPERTY(ReplicatedUsing=OnRep_IsActivated)
	bool bIsActivated = false;

	UFUNCTION()
	void OnRep_IsActivated(bool bIsActivated_Old);


private:

	TArray<APawn*> OverlappedPawns;

};
