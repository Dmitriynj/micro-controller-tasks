#include <stm32f4xx_exti.h>
#include <stm32f4xx_gpio.h>
#include <config.h>
#include <delay.h>
#include <state.h>

void EXTI0_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line0) != RESET){
	    delay(10000);
	    if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1){
	        toggleStateMode();
	    }
	    EXTI_ClearITPendingBit(EXTI_Line0);
	}
}
