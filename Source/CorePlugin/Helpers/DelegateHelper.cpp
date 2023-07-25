// Fill out your copyright notice in the Description page of Project Settings.


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
