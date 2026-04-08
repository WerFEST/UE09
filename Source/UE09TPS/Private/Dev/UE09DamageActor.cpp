// Fill out your copyright notice in the Description page of Project Settings.


#include "Dev/UE09DamageActor.h"
#include "Kismet/GameplayStatics.h"


//
AUE09DamageActor::AUE09DamageActor()
{
	PrimaryActorTick.bCanEverTick = true;
}


//
void AUE09DamageActor::BeginPlay()
{
	Super::BeginPlay();
}


//
void AUE09DamageActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	DrawDebugSphere( GetWorld(), GetActorLocation(), Radius, Segments, FColor::Red );
	UGameplayStatics::ApplyRadialDamage( GetWorld(), Damage, GetActorLocation(), Radius, DamageType, {}, this, nullptr,
										 bDoFullDamage, ECollisionChannel::ECC_Visibility );
}

