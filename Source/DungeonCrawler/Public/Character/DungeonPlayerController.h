// Copyright Atennop. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DungeonCharacter.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"
#include "DungeonPlayerController.generated.h"

UCLASS()
class DUNGEONCRAWLER_API ADungeonPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	UPROPERTY()
	ADungeonCharacter *PossessedCharacter;

	UPROPERTY(EditDefaultsOnly)
	UInputMappingContext *InputMappingContext;
	
	UPROPERTY(EditDefaultsOnly)
	UInputAction *MoveAction;
	
	UPROPERTY(EditDefaultsOnly)
	UInputAction *LookAction;

	UPROPERTY(EditDefaultsOnly)
	UInputAction *JumpAction;

	void CallMove(const FInputActionValue &Value);
	void CallRotate(const FInputActionValue &Value);
	void CallStartJumping(const FInputActionValue &Value);
	void CallStopJumping(const FInputActionValue &Value);

protected:
	virtual void OnPossess(APawn *PossessingPawn) override;
};
