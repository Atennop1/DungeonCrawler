﻿// Copyright Atennop. All Rights Reserved.

#include "Character/DungeonCharacter.h"

ADungeonCharacter::ADungeonCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ADungeonCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(MovingComponent != nullptr)
	check(RotatingComponent != nullptr)
	check(JumpingComponent != nullptr)
}
