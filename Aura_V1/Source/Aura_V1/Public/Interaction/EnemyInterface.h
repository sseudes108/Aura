#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface{
	GENERATED_BODY()
};

class AURA_V1_API IEnemyInterface{
	GENERATED_BODY()
public:
	virtual void HighLightActor() = 0;
	virtual void UnhighLightActor() = 0;
};