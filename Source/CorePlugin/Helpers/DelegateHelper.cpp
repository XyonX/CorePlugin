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
FOnUpdateAnimationData ADelegateHelper::Delegate_UpdateAnimationDataDelegate;
FOnButtonClicked ADelegateHelper::OnStartButtonClicked;

void ADelegateHelper::BeginPlay()
{
	Super::BeginPlay();
}
