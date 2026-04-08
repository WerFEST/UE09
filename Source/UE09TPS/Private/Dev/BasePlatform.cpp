// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev/BasePlatform.h"


//
ABasePlatform::ABasePlatform()
{
	PrimaryActorTick.bCanEverTick = false;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));

}


//
void ABasePlatform::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(PlatformTrigger))
	{
		PlatformTrigger->OnTriggerActivated.AddDynamic(this, &ABasePlatform::OnPlatformTriggerActivated);
	}
}


void ABasePlatform::OnPlatformTriggerActivated_Implementation(bool bIsActivated)
{
	// some things...
}