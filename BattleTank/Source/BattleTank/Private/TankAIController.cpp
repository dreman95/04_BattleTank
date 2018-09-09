// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	auto AITank = GetAITank();

	if (!AITank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank is not possessed"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank %s is possessed by TankAIController"), *(AITank->GetName()));
	}
	
}

ATank * ATankAIController::GetAITank()
{
	return Cast<ATank>(GetPawn());
}
