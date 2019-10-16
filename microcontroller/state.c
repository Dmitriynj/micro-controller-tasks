#include <state.h>
#include <stm32f4xx_gpio.h>
#include <blink.h>

void executeState(struct StateDef state) {
	if(state.value == 1) {
		blink(100000, GPIO_Pin_15);
	}
	if(state.value == 2) {
		blink(10000, GPIO_Pin_15);
	}
}

void toggleStateMode(struct StateDef state) {
	if(state.value == 2) {
		state.value = 1;
	} else {
		state.value = 2;
	}
}
