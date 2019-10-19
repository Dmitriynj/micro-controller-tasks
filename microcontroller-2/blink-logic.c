#include <blink-logic.h>
#include <state.h>
#include <stm32f4xx_gpio.h>

void blink() {
	int counter = getStateCounter();
	int *periods = getStatePeriods();
	int *pins = getStatePins();

	if (!counter) {
		GPIO_SetBits(GPIOD, pins[0]);
	}
	if (counter == periods[0]) {
		GPIO_ResetBits(GPIOD, pins[0]);
		GPIO_SetBits(GPIOD, pins[1]);
	}
	if (counter == periods[1]) {
		GPIO_ResetBits(GPIOD, pins[1]);
		GPIO_SetBits(GPIOD, pins[2]);
	}
	if (counter == periods[2]) {
		GPIO_ResetBits(GPIOD, pins[2]);
		GPIO_SetBits(GPIOD, pins[3]);
	}
	if (counter == periods[3]) {
		GPIO_ResetBits(GPIOD, pins[3]);
	}
}
