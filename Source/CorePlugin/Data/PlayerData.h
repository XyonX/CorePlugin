/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/Object.h"
#include "PlayerData.generated.h"

UENUM(BlueprintType)
enum class ELocomotionType: uint8
{
	
	Strafing = 0					UMETA(DisplayName = "Strafing"),
	OrientRotaionToMovement =1		UMETA(DisplayName = "Orient Rotation To Movement"),
	FourWayMovement = 2				UMETA(DisplayName = "Four Way (LU =RU = F)"),
};

UENUM(BlueprintType)
enum class ECharacterEquipmentState: uint8
{
	
	Unarmed = 0					UMETA(DisplayName = "Unamed"),
	Armed =1		UMETA(DisplayName = "Armed"),
	Melee = 2				UMETA(DisplayName = "Melee"),
	Throwable = 0					UMETA(DisplayName = "Strafing"),
};

UENUM(BlueprintType)
enum class EAnimationSet: uint8
{
	LyraAnimation = 0					UMETA(DisplayName = "Default Lyra Animation "),
	MovementAnimSetPro =1		UMETA(DisplayName = "Movement AnimSet Pro"),
	MobilityPro = 2				UMETA(DisplayName = "MobilityPro"),
	RiflePro = 3				UMETA(DisplayName = "RiflePro"),
};

USTRUCT(BlueprintType)
struct FLocomotionModes
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite ,EditAnywhere,Category="Locomotion Modes")
	ELocomotionType UnarmedLocomotionType ;
	UPROPERTY(BlueprintReadWrite ,EditAnywhere,Category="Locomotion Modes")
	ELocomotionType ArmedLocomotionType;
	UPROPERTY(BlueprintReadWrite ,EditAnywhere,Category="Locomotion Modes")
	EAnimationSet UnarmedAnimationSet;
	UPROPERTY(BlueprintReadWrite ,EditAnywhere,Category="Locomotion Modes")
	EAnimationSet ArmedAnimationSet;
	
};

USTRUCT(BlueprintType)
struct FMaxMovementSpeed  : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Locomotion")
	float Walk;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Locomotion")
	float Jog;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Locomotion")
	float Sprint;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Locomotion")
	float ADS;
	
};
UENUM(BlueprintType)
enum class EVelocityDirection : uint8
{
	Forward = 0		UMETA(DisplayName = "Forward"),
	Backward =1		UMETA(DisplayName = "Backward"),
	Left = 2		UMETA(DisplayName = "Left"),
	Right =3		UMETA(DisplayName = "Right")
};
UENUM(BlueprintType)
enum class ELocomotionState : uint8
{
	Idle = 0		UMETA(DisplayName = "Idle"),
	Walking =1		UMETA(DisplayName = "Walk"),
	Joging = 2		UMETA(DisplayName = "Jog"),
	Sprinting = 3		UMETA(DisplayName = "SPrinting"),
	Pivoting =4		UMETA(DisplayName = "Pivoting"),
	Jumping =5		UMETA(DisplayName = "Jumping")
};


UCLASS()
class COREPLUGIN_API UPlayerData : public UObject
{
	GENERATED_BODY()
};
