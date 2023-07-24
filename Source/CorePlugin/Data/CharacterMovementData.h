// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CharacterMovementData.generated.h"

USTRUCT(BlueprintType)
struct FCharacterMovementData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Defaults")
	float TurnRate;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Defaults")
	float LookUpRate;
	
};