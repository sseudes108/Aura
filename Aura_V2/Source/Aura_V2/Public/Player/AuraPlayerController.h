#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

struct FInputActionValue;

UCLASS()
class AURA_V2_API AAuraPlayerController : public APlayerController{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	void CanMove(bool CanMove);

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void SetInputMappingContext();

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	bool bCanMove = true;
	void Move(const FInputActionValue& InputActionValue);
};