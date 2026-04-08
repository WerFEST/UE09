// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev/PlatformTrigger.h"
#include "Net/UnrealNetwork.h"
#include "Player/UE09BaseCharacter.h"


//
APlatformTrigger::APlatformTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;
	SetNetUpdateFrequency(2.f);
	SetMinNetUpdateFrequency(2.f);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));

}


//
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnTriggerOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnTriggerOverlapEnd);

}


//
void APlatformTrigger::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME(APlatformTrigger, bIsActivated);
	
}


//
void APlatformTrigger::Server_SetIsActivated_Implementation(bool bIsActivated_In)
{
	SetIsActivated(bIsActivated_In);

}


//
void APlatformTrigger::Multicast_SetIsActivated_Implementation(bool bIsActivated_In)
{
	bIsActivated = bIsActivated_In;
	if (OnTriggerActivated.IsBound())
	{
		OnTriggerActivated.Broadcast(bIsActivated);

	}

}


//
void APlatformTrigger::OnRep_IsActivated(bool bIsActivated_Old)
{
	SetIsActivated(bIsActivated);
}


//
void APlatformTrigger::SetIsActivated(bool bIsActivated_In)
{
	bIsActivated = bIsActivated_In;
	if (OnTriggerActivated.IsBound())
	{
		OnTriggerActivated.Broadcast(bIsActivated);
	}

}


//
void APlatformTrigger::OnTriggerOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AUE09BaseCharacter* lOtherPawn = Cast<AUE09BaseCharacter>(OtherActor); //APawn* lOtherPawn = Cast<APawn>(OtherActor);
	if (!IsValid(lOtherPawn)) return;


	if (GetLocalRole() == ROLE_Authority) // lOtherPawn->IsLocallyControlled()
	{
		OverlappedPawns.AddUnique(lOtherPawn);

		if (!bIsActivated && OverlappedPawns.Num() > 0)
		{
			//bIsActivated = true;
			//lOtherPawn->Server_ActivatePlatformTrigger(this, true);
			lOtherPawn->Client_ActivatePlatformTrigger(this, true);
		}
	}
}


//
void APlatformTrigger::OnTriggerOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AUE09BaseCharacter* lOtherPawn = Cast<AUE09BaseCharacter>(OtherActor); //APawn* lOtherPawn = Cast<APawn>(OtherActor);
	if (!IsValid(lOtherPawn)) return;

	OverlappedPawns.RemoveSingleSwap(lOtherPawn);

	if (GetLocalRole() == ROLE_Authority) // lOtherPawn->IsLocallyControlled()
	{
		if (bIsActivated && OverlappedPawns.Num() == 0)
		{
			//bIsActivated = false;
			//lOtherPawn->Server_ActivatePlatformTrigger(this, false);
			lOtherPawn->Client_ActivatePlatformTrigger(this, false);
		}
	}
}
