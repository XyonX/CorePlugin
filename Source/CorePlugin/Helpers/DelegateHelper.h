// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DelegateHelper.generated.h"

//DECLARE Delegates Here
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMouseMovementDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMouseMovementDelegate, FVector, CursorHitLocation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDragStartedDelegate);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnDragDelegate , FVector2D ,ScreenPostion);


UCLASS()
class COREPLUGIN_API ADelegateHelper : public AActor
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;

public:

	
	
	static FDragStartedDelegate DragDownDelegate;
	static FOnDragDelegate	OnDragDelegate;
	static FDragStartedDelegate	DragUpDelegate;
	static FOnMouseMovementDelegate OnMouseMovementDelegate ;

};
