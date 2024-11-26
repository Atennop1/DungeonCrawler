// Copyright Atennop. All Rights Reserved.

#include "DungeonCrawler/Public/Character/Movement/CharacterJumpingComponent.h"
#include "DungeonCrawler/Public/Character/DungeonCharacter.h"

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

