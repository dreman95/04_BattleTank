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


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	
	//Get pawn from the tanks player controller perspective 
	//Returns the pawn the playercontroller class is currently possesing 
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector OutHitLocation; //Out parameter
	if (GetSightRayHitLocation(OutHitLocation)) //has "side effect", is going to line trace
	{


		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *OutHitLocation.ToString());
		
			//TODO Tell controlled tank to aim at this point 
	}

}
//Get World location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find the crosshair position
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
	
	//"De-project" screen the screen position of the crosshaiur to a world direction
	//Line-trace along that look direction, and see what we hit (up to max range)
	return true;
}


