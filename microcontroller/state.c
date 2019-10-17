#include <state.h>
#include <stm32f4xx_gpio.h>
#include <blink.h>

struct StateDef thisState;

void initState() {
	thisState.value = 1;
}

void setState(struct StateDef state) {
	thisState = state;
}
struct StateDef getState() {
	return thisState;
}

void executeState() {
	if(thisState.value == 1) {
		blink(1000000, GPIO_Pin_15);
	}
	if(thisState.value == 2) {
		blink(225000, GPIO_Pin_15);
	}
}

void toggleStateMode() {
	if(thisState.value == 2) {
		thisState.value = 1;
	} else {
		thisState.value = 2;
	}
}
