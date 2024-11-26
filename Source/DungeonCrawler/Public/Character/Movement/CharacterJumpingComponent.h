// Copyright Atennop. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterJumpingComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DUNGEONCRAWLER_API UCharacterJumpingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class ADungeonCharacter *Character = nullptr;
	
protected:
	virtual void BeginPlay() override;

public:
	UCharacterJumpingComponent();

	void StartJumping() const;
	void StopJumping() const;
};
