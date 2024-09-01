#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateMachine.generated.h"

class UStateBase;
class ACharacterBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AURA_V2_API UStateMachine : public UActorComponent{
	GENERATED_BODY()

public:	
	UStateMachine();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ChangeState(const TStrongObjectPtr<UObject>& NewState);

private:
	TStrongObjectPtr<UObject> CurrentState;
	UStateBase* CurrentStatePtr;
	ACharacterBase* StateController;
};