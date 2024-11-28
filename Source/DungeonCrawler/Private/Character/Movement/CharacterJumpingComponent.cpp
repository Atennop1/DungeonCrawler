// Copyright Atennop. All Rights Reserved.

#include "Character/Movement/CharacterJumpingComponent.h"
#include "Character/DungeonCharacter.h"

UCharacterJumpingComponent::UCharacterJumpingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCharacterJumpingComponent::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<ADungeonCharacter>(GetOwner());
	check(Character != nullptr);
}

void UCharacterJumpingComponent::StartJumping() const
{
	Character->Jump();
}

void UCharacterJumpingComponent::StopJumping() const
{
	Character->StopJumping();
}

