/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/

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