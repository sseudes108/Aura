#include "StateMachine/StateBase.h"

void UStateBase::Enter() {}
void UStateBase::Exit() {}
void UStateBase::Tick(float DeltaTime) {}
FString UStateBase::GetName() { return "Base"; }