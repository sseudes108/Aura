#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/WidgetControllers/AuraOverlayWidgetController.h"
#include "UI/Widgets/AuraUserWidget.h"

UAuraOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(
	const FWidgetControllerParams& WidgetControllerParams){
	if(OverlayWidgetController == nullptr){
		OverlayWidgetController = NewObject<UAuraOverlayWidgetController>(this, OverlayWidgetClass);
		OverlayWidgetController->SetWidgetParams(WidgetControllerParams);
	}

	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* Pc, APlayerState* Ps, UAbilitySystemComponent* Asc, UAttributeSet* As){
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass is not set on BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass is not set on BP_AuraHUD"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(Pc, Ps, Asc, As);
	UAuraOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);

	Widget->AddToViewport();
}
