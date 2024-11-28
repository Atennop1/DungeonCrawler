// Copyright Atennop. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Movement/CharacterJumpingComponent.h"
#include "Movement/CharacterMovingComponent.h"
#include "Movement/CharacterRotatingComponent.h"
#include "DungeonCharacter.generated.h"

UCLASS()
class DUNGEONCRAWLER_API ADungeonCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:
	ADungeonCharacter();

	UCharacterMovingComponent *GetMovingComponent() const { return MovingComponent; }
	UCharacterRotatingComponent *GetRotatingComponent() const { return RotatingComponent; }
	UCharacterJumpingComponent *GetJumpingComponent() const { return JumpingComponent; }
	
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UCharacterMovingComponent *MovingComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UCharacterRotatingComponent *RotatingComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UCharacterJumpingComponent *JumpingComponent = nullptr;
};
