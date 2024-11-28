// Copyright Atennop. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterMovingComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DUNGEONCRAWLER_API UCharacterMovingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCharacterMovingComponent();
	void Move(const FVector2D Input) const;
	
protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY()
	class ADungeonCharacter *Character = nullptr;
};
