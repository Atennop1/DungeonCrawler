// Copyright Atennop. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/ActorComponent.h"
#include "CharacterRotatingComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DUNGEONCRAWLER_API UCharacterRotatingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class ADungeonCharacter *Character = nullptr;
	
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess))
	UCameraComponent *CharacterCamera = nullptr;

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UCharacterRotatingComponent();

	void Rotate(const FVector2D Input) const;
};
