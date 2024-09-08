#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableActor.generated.h"

UINTERFACE(MinimalAPI)
class UInteractableActor : public UInterface{
	GENERATED_BODY()
};

class AURA_V2_API IInteractableActor{
	GENERATED_BODY()
public:
	USkeletalMeshComponent* BodyMesh;
	virtual void SetUpMeshHighLight() = 0;
	virtual void HighLightActor() = 0;
	virtual void UnHighLightActor() = 0;
};