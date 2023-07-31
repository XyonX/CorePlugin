// Fill out your copyright notice in the Description page of Project Settings.


#include "InputHandlerHelper.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include"InputModifiers.h"

UInputAction* UInputHandlerHelper::CreateInputAction(AActor*Outer , EInputActionValueType ValueType)
{
	UInputAction*InputAction= NewObject<UInputAction>(Outer);
	InputAction->ValueType = ValueType;
	
	return InputAction;
}

UInputMappingContext* UInputHandlerHelper::CreateInputMappingContext(AActor*Outer)
{
	return NewObject <UInputMappingContext>(Outer);
}

void UInputHandlerHelper::MapKeyWithInputAction(UInputMappingContext* InputMappingContext, UInputAction* InputAction,
	FKey Key, bool bNegate , bool bSwizzle , EInputAxisSwizzle SwizzleOrder )
{
	FEnhancedActionKeyMapping& Mapping = InputMappingContext->MapKey(InputAction, Key);
	UObject* Outer = InputMappingContext->GetOuter();

	if (bNegate)
	{
		UInputModifierNegate* Negate = NewObject<UInputModifierNegate>(Outer);
		Mapping.Modifiers.Add(Negate);
	}

	if (bSwizzle)
	{
		UInputModifierSwizzleAxis* Swizzle = NewObject<UInputModifierSwizzleAxis>(Outer);
		Swizzle->Order = SwizzleOrder;
		Mapping.Modifiers.Add(Swizzle);
	}
}
