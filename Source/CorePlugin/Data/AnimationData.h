#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimationData.Generated.h"

USTRUCT(BlueprintType)
struct FAnimationData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumping;
	
};
