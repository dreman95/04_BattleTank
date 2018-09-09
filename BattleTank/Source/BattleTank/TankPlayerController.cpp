// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const {

	//Get pawn from the tanks player controller perspective 
	//Returns the pawn the playercontroller class is currently possesing 
	return Cast<ATank>(GetPawn());

	

}

