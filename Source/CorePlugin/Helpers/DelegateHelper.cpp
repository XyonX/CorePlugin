/******************************************************************************
* Project Core - Generic UE Project
* Copyright (c) [2023] [ Joydip chakraborty ]
* This class is part of the ProjectCore open-source project. 
* ******************************************************************************/


#include "DelegateHelper.h"

// Define the static variable ADelegateHelper::DragStartedDelegate
FOnDragDelegate_Down ADelegateHelper::DragDelegate_Down;
FOnDragDelegate ADelegateHelper::OnDragDelegate;
FOnDragDelegate_Up ADelegateHelper::DragDelegate_Up;

FOnMouseMovementDelegate ADelegateHelper::OnMouseMovementDelegate;
FOnCharacterMovementDelegate ADelegateHelper::OnCharacterMovementDelegate;
FOnButtonClicked ADelegateHelper::OnStartButtonClicked;

//animation data def

FOnUpdateAnimationData ADelegateHelper::Transmitter_AnimationData;

FOnUpdateAnimationData_FVector ADelegateHelper::Transmitter_Velocity;
FOnUpdateAnimationData_FVector ADelegateHelper::Transmitter_CharacterWorldLocation;
FOnUpdateAnimationData_FVector ADelegateHelper::Transmitter_MovementDirection;
FOnUpdateAnimationData_FRotator ADelegateHelper::Transmitter_ControlRotation;
FOnUpdateAnimationData_FRotator ADelegateHelper::Transmitter_CharacterRotation;

FOnUpdateAnimationData_bool ADelegateHelper::Transmitter_JumpingStatus;
FOnUpdateAnimationData_bool ADelegateHelper::Transmitter_CrouchStatus;
FOnUpdateAnimationData_bool ADelegateHelper::Transmitter_InAirStatus;

FGlobalBeginPlayDelegate ADelegateHelper::Transmitter_GlobalBeginPlay;

void ADelegateHelper::BeginPlay()
{
	Super::BeginPlay();
}
