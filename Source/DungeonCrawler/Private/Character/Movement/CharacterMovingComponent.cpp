// Copyright Atennop. All Rights Reserved.

#include "Character/Movement/CharacterMovingComponent.h"
#include "Character/DungeonCharacter.h"
#include "Kismet/KismetMathLibrary.h"

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
	Character->AddMovementInput(UKismetMathLibrary::GetRightVector(Character->GetControlRotation()), Value.X);
	Character->AddMovementInput(UKismetMathLibrary::GetForwardVector(Character->GetControlRotation()), Value.Y);
}
