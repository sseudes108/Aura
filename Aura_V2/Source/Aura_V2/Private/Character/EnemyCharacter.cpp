#include "Character/EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter(){
    SetUpMeshHighLight();
}

void AEnemyCharacter::SetUpMeshHighLight(){
    BodyMesh = GetMesh();
    BodyMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
    BodyMesh->SetCustomDepthStencilValue(250);
    Weapon->SetCustomDepthStencilValue(250);
}

void AEnemyCharacter::HighLightActor(){
    BodyMesh->SetRenderCustomDepth(true);
    Weapon->SetRenderCustomDepth(true);
}

void AEnemyCharacter::UnHighLightActor(){
    BodyMesh->SetRenderCustomDepth(false);
    Weapon->SetRenderCustomDepth(false);
}