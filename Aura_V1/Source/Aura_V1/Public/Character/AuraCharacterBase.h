#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS()
class AURA_V1_API AAuraCharacterBase : public ACharacter{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};