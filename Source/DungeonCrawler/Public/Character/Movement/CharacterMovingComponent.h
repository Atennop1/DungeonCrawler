﻿// Copyright Atennop. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterMovingComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DUNGEONCRAWLER_API UCharacterMovingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class ADungeonCharacter *Character = nullptr;

protected:
	virtual void BeginPlay() override;
	
public:
	UCharacterMovingComponent();
	void Move(const FVector2D Input) const;
};