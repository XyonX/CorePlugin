// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "InputModifiers.h"
#include "UObject/Object.h"
#include "InputHandlerHelper.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class COREPLUGIN_API UInputHandlerHelper : public UObject
{
	GENERATED_BODY()

public:
	
	static UInputAction* CreateInputAction (AActor*Outer, EInputActionValueType ValueType);
	static UInputMappingContext* CreateInputMappingContext (AActor*Outer);
	static void MapKeyWithInputAction (UInputMappingContext* InputMappingContext, UInputAction* InputAction,
	FKey Key, bool bNegate = false, bool bSwizzle = false, EInputAxisSwizzle SwizzleOrder = EInputAxisSwizzle::YXZ);
};
