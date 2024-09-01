#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StateBase.generated.h"

UCLASS(Abstract)
class AURA_V2_API UStateBase : public UObject{
	GENERATED_BODY()

public:
	virtual void Enter();
	virtual void Tick(float DeltaTime);
	virtual void Exit();
	virtual FString GetName();
};
