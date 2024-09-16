#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Interfaces/InteractableActor.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class AURA_V2_API AEnemyCharacter : public ACharacterBase, public IInteractableActor{	
	GENERATED_BODY()
public:
	AEnemyCharacter();
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
protected:
	virtual void BeginPlay() override;
};