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
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateAnimationData , FAnimationData , AnimationData);


//UI Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnButtonClicked);

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
	static FOnUpdateAnimationData Delegate_UpdateAnimationDataDelegate;

	// Game Manger

	static FOnButtonClicked OnStartButtonClicked; 

};