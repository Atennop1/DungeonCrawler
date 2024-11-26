// Copyright Atennop. All Rights Reserved.

#include "DungeonCrawler/Public/Character/Movement/CharacterMovingComponent.h"
#include "DungeonCrawler/Public/Character/DungeonCharacter.h"

UCharacterMovingComponent::UCharacterMovingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCharacterMovingComponent::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<ADungeonCharacter>(GetOwner());
	check (Character != nullptr)
}

void UCharacterMovingComponent::Move(const FVector2D Value) const
{
	 Character->AddMovementInput(Character->GetActorRightVector(), Value.X);
	 Character->AddMovementInput(Character->GetActorForwardVector(), Value.Y);
}
