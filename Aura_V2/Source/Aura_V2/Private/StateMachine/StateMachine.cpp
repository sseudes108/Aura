#include "StateMachine/StateMachine.h"

#include "StateMachine/StateBase.h"
#include "Character/CharacterBase.h"

UStateMachine::UStateMachine(){
	PrimaryComponentTick.bCanEverTick = true;
}

void UStateMachine::BeginPlay(){
	Super::BeginPlay();
	StateController = Cast<ACharacterBase>(GetOwner());
}

void UStateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// if(CurrentStatePtr == nullptr){
	// 	CurrentStatePtr = Cast<UStateBase>(CurrentState.Get());
	// }
	// CurrentStatePtr->Tick(DeltaTime);
	
	if(CurrentStatePtr != nullptr){
		CurrentStatePtr->Tick(DeltaTime);
	}
}

void UStateMachine::ChangeState(const TStrongObjectPtr<UObject>& NewState){
	if(CurrentState.IsValid()){
		CurrentStatePtr = Cast<UStateBase>(CurrentState.Get());

		if(CurrentStatePtr != nullptr){
			CurrentStatePtr->Exit();
		}
	}

	CurrentState = NewState;
	CurrentStatePtr = Cast<UStateBase>(CurrentState.Get());

	if(CurrentStatePtr){
		StateController->UpdateStateHistory(CurrentStatePtr->GetName());

		CurrentStatePtr->Enter();
	}
}