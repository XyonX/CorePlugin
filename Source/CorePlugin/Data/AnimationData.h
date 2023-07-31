#pragma once
#include "CoreMinimal.h"
#include "PlayerData.h"
#include "UObject/Object.h"
#include "AnimationData.Generated.h"


USTRUCT(BlueprintType)
struct FAnimationData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Velocity ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumping;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bIsCrouching;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bIsInAir;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	FVector WorldLocation ;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	FRotator WorldRotation ;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	bool bHasWeaponEquipped;
	
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
	
	float NormalTolerance ;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	ELocomotionState LocomotionState ;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	EVelocityDirection VelocityDirection ;
	
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
	FVector WorldLocation ;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AnimInstance")
	FRotator WorldRotation ;

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
	