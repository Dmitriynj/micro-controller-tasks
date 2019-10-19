#include <timer-3-handler.h>
#include <state.h>
#include <on-button-pressed-logic.h>
#include <stm32f4xx_tim.h>
#include <stm32f4xx_gpio.h>

void TIM3_IRQHandler(void) {
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) {
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		int sum = getStateSum();
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)) {
			setStateSum(++sum);
			if (sum == 8) {
				onPressButton();
			}
			else if (sum > 8) {
				GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
				setStateSum(9);
			}
		}else {
			setStateSum(0);
		}
	}
}
