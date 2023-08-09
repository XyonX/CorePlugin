#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimationData.Generated.h"

UENUM(BlueprintType)
enum class ECharacterEquipmentStatus: uint8
{
	
	Unarmed = 0		UMETA(DisplayName = "Unamed"),
	Armed =1		UMETA(DisplayName = "Armed"),
	Melee = 2		UMETA(DisplayName = "Melee"),
	Throwable = 0	UMETA(DisplayName = "Throwable"),
};

UENUM(BlueprintType)
enum class EMovementDirection : uint8
{
	Forward = 0		UMETA(DisplayName = "Forward"),
	Backward =1		UMETA(DisplayName = "Backward"),
	Left = 2		UMETA(DisplayName = "Left"),
	Right =3		UMETA(DisplayName = "Right")
};


UENUM(BlueprintType)
enum class EMovementStatus : uint8
{
	Idle = 0		UMETA(DisplayName = "Idle"),
	Walking =1		UMETA(DisplayName = "Walk"),
	Jogging = 2		UMETA(DisplayName = "Jog"),
	Sprinting = 3	UMETA(DisplayName = "SPrinting"),
	Pivoting =4		UMETA(DisplayName = "Pivoting"),
	Jumping =5		UMETA(DisplayName = "Jumping")
};

USTRUCT(BlueprintType)
struct FMovementSpeed
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WalkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JogSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SprintSpeed;
};


/** Store primitive data needed for animation calculation or other data derivation */

USTRUCT(BlueprintType)
struct FRawAnimationData
{
	GENERATED_BODY()
	/** General Information */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Velocity ;

	/** bool Status */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumping;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bIsCrouching;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bIsInAir;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bHasWeaponEquipped;

	/** Location Status */
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	FVector CharacterLocation ;
	
	/** Rotation Status */
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	FRotator CharacterRotation ;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	FRotator ControllerRotation ;
	
};

USTRUCT(BlueprintType)
struct FCalculatedAnimationData
{
	GENERATED_BODY()

	/** General Information */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Velocity ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator VelocityRotation ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator DeltaR_MovCtlr ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator DeltaR_CharCtlr ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMovementStatus MovementStatus;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EMovementDirection MovementDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECharacterEquipmentStatus CharacterEquipmentStatus;


	
	
};

UCLASS()
class COREPLUGIN_API UAnimationData : public UObject
{
	GENERATED_BODY()
};


	/*
	//virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


public:
	UFUNCTION(BlueprintCallable)
	void UpdateAnimationProperties(float DeltaTime);
	UFUNCTION(BlueprintCallable)
	void TurnInPlace();
	//void FindMovementDirection();
	UFUNCTION(BlueprintCallable)
	void FindLocomotionState();
	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	void UpdateLocationData(float DeltaTime);
	UFUNCTION(BlueprintCallable, meta = (BlueprintThreadSafe))
	void UpdateRotationData(float DeltaTime);
/*
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	ACoreCharacterEXTENDED*CoreCharacter ;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	ACorePlayerController*CoreController;
	ACorePlayerController*GetPlayerController ();
	ACoreCharacter*GetPlayerCharacter ();*/
/*	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	FVector CharacterWorldLocationLoc ;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	FRotator CharacterWorldRotationCharacterWorldRotation ;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float Velocity ;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bIsInAir;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bHasWeaponEquipped;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bIsCrouching;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bIsAccelerating ;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float MovementOffset;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float MovementOffsetAccel ;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float Character_Yaw;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float Character_Yaw_LastFrame;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float Root_Yaw_Offset_PerFrame;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float Root_Yaw_Offset;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	float PivotTime;
	float NormalTolerance ;*/
/*	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	ELocomotionState LocomotionState ;
	
//	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	EVelocityDirection VelocityDirection ; */
	