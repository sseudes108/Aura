#include "UI/Widgets/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UAuraWidgetController* InWidgetController){
	WidgetController = InWidgetController;
	WidgetControllerSet();
}