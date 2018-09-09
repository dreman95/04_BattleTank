// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("Player controller begin play"));
	
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player controller not possessing tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player controller possessing: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const {
	
	//Get pawn from the tanks player controller perspective 
	//Returns the pawn the playercontroller class is currently possesing 
	return Cast<ATank>(GetPawn());

}


