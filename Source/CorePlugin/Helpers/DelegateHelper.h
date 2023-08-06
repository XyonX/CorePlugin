/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "CorePlugin/Spawnables/Spawnable.h"
#include "GameFramework/Actor.h"
#include "CorePlugin/Data/AnimationData.h"
#include "DelegateHelper.generated.h"

//DECLARE Delegates Here
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMouseMovementDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDragDelegate_Down,USpawnable*,Spawnable);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDragDelegate , FVector2D ,ScreenPostion , USpawnable*,Spawnable);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDragDelegate , FVector2D ,ScreenPostion);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDragDelegate_Up);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMouseMovementDelegate, FVector, CursorHitLocation );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterMovementDelegate, FVector, CharacterLocation );


//Animation Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateAnimationData , FCalculatedAnimationData , AnimationData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateAnimationData_float , float , value );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateAnimationData_int , int , value );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateAnimationData_bool , bool , value );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateAnimationData_FVector , FVector , value );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateAnimationData_FRotator , FRotator , value );


//UI Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonClicked);

//Begin play
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGlobalBeginPlayDelegate);

UCLASS()
class COREPLUGIN_API ADelegateHelper : public AActor
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;

public:

	
	
	static FOnDragDelegate_Down DragDelegate_Down;
	static FOnDragDelegate	OnDragDelegate;
	static FOnDragDelegate_Up	DragDelegate_Up;
	static FOnMouseMovementDelegate OnMouseMovementDelegate ;
	static FOnCharacterMovementDelegate OnCharacterMovementDelegate;

	
	static FOnUpdateAnimationData Transmitter_AnimationData;
	
	static FOnUpdateAnimationData_FVector Transmitter_CharacterWorldLocation;
	static FOnUpdateAnimationData_FVector Transmitter_Velocity;
	static FOnUpdateAnimationData_FRotator Transmitter_ControlRotation;
	static FOnUpdateAnimationData_FRotator Transmitter_CharacterRotation;

	static FOnUpdateAnimationData_bool Transmitter_JumpingStatus;
	static FOnUpdateAnimationData_bool Transmitter_CrouchStatus;
	static FOnUpdateAnimationData_bool Transmitter_InAirStatus;

	static FGlobalBeginPlayDelegate Transmitter_GlobalBeginPlay;
	

	// Game Manger

	static FOnButtonClicked OnStartButtonClicked; 

};