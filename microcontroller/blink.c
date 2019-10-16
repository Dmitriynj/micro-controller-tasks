#include <blink.h>
#include <stm32f4xx_gpio.h>
#include <delay.h>

void blink(long unsigned int number, int GPIO_Pin){
	GPIO_SetBits(GPIOD, GPIO_Pin);
	delay(number);
	GPIO_ResetBits(GPIOD, GPIO_Pin);
	delay(number);
}
