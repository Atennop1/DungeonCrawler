// Copyright Atennop. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterJumpingComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DUNGEONCRAWLER_API UCharacterJumpingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCharacterJumpingComponent();

	void StartJumping() const;
	void StopJumping() const;

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY()
	class ADungeonCharacter *Character = nullptr;
};
