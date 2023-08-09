// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerHandlerHelper.generated.h"




UCLASS()
class COREPLUGIN_API ATimerHandlerHelper : public AActor
{
	GENERATED_BODY()

public:

	ATimerHandlerHelper();
	~ATimerHandlerHelper();

	static void ClearTimer ();


	// timer Handler
	
	static FTimerHandle OnMovementTimer;
};
