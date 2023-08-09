// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerHandlerHelper.h"
#include "Engine/World.h"

FTimerHandle ATimerHandlerHelper::OnMovementTimer;

ATimerHandlerHelper::ATimerHandlerHelper()
{
}

ATimerHandlerHelper::~ATimerHandlerHelper()
{
	ClearTimer();
}

// Clear the timer handle
void ATimerHandlerHelper::ClearTimer()
{
	if (GEngine && GEngine->GetWorld())
	{
		GEngine->GetWorld()->GetTimerManager().ClearTimer(OnMovementTimer);
	}
}