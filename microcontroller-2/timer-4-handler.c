#include <timer-4-handler.h>
#include <blink-logic.h>
#include <state.h>
#include <stm32f4xx_tim.h>

void TIM4_IRQHandler(void){
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) {
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
		blink();
		int counter = getStateCounter();
		int *periods = getStatePeriods();
		if (counter == periods[3]) {
			counter = -1;
		}
		setStateCounter(++counter);
	}
}
