#pragma once

#include "StateMachine/StateBase.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraStateIdle.generated.h"

UCLASS()
class AURA_V2_API UAuraStateIdle : public UStateBase{
	GENERATED_BODY()

public:
	virtual void Enter() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Exit() override;
	virtual FString GetName() override;
};