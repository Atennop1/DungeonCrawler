// Copyright Atennop. All Rights Reserved.

#include "Character/DungeonPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void ADungeonPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (const auto Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}

	const auto EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADungeonPlayerController::CallMove);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADungeonPlayerController::CallRotate);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ADungeonPlayerController::CallStartJumping);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ADungeonPlayerController::CallStopJumping);
}

void ADungeonPlayerController::AcknowledgePossession(APawn* InPawn)
{
	Super::AcknowledgePossession(InPawn);
	PossessedCharacter = Cast<ADungeonCharacter>(InPawn);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void ADungeonPlayerController::CallMove(const FInputActionValue& Value) { if (IsValid(PossessedCharacter)) PossessedCharacter->GetMovingComponent()->Move(Value.Get<FVector2D>()); }

// ReSharper disable once CppMemberFunctionMayBeConst
void ADungeonPlayerController::CallRotate(const FInputActionValue& Value) { if (IsValid(PossessedCharacter)) PossessedCharacter->GetRotatingComponent()->Rotate(Value.Get<FVector2D>()); }

// ReSharper disable once CppMemberFunctionMayBeConst
void ADungeonPlayerController::CallStartJumping(const FInputActionValue& Value) { if (IsValid(PossessedCharacter)) PossessedCharacter->GetJumpingComponent()->StartJumping(); }

// ReSharper disable once CppMemberFunctionMayBeConst
void ADungeonPlayerController::CallStopJumping(const FInputActionValue& Value) { if (IsValid(PossessedCharacter)) PossessedCharacter->GetJumpingComponent()->StopJumping(); }
