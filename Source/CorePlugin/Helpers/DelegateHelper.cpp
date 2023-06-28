// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateHelper.h"

// Define the static variable ADelegateHelper::DragStartedDelegate
FDragStartedDelegate ADelegateHelper::DragDownDelegate;
FDragStartedDelegate ADelegateHelper::DragUpDelegate;
FOnDragDelegate ADelegateHelper::OnDragDelegate;
FOnMouseMovementDelegate ADelegateHelper::OnMouseMovementDelegate;

void ADelegateHelper::BeginPlay()
{
	Super::BeginPlay();
}
