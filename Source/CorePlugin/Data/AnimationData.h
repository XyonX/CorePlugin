#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimationData.Generated.h"


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

	/** Character State */
	
	//UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	//ELocomotionState LocomotionState ;
};

USTRUCT(BlueprintType)
struct FCalculatedAnimationData
{
	GENERATED_BODY()

	/** General Information */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Velocity ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator MovementRotation ;
	
	//UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	//EVelocityDirection VelocityDirection ;
	
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
	