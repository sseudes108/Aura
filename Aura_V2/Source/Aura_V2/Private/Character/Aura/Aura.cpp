#include "Character/Aura/Aura.h"

#include "Character/Aura/States/AuraStateIdle.h"

void AAura::BeginPlay(){
	Super::BeginPlay();
    
    CreateStates();
    IniStateMachine(IdleState);
}

void AAura::CreateStates(){
    Super::CreateStates();

    IdleState = TStrongObjectPtr<UObject>(NewObject<UAuraStateIdle>());
}

void AAura::IniStateMachine(const TStrongObjectPtr<UObject>& InitialState){
    Super::IniStateMachine(InitialState);
}

void AAura::UpdateStateHistory(FString NewState){
    Super::UpdateStateHistory(NewState);
}
