#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase(){
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraCharacterBase::BeginPlay(){
	Super::BeginPlay();
}