#include <stm32f4xx_syscfg.h>
#include <system_stm32f4xx.h>
#include <config.h>
#include <state.h>

int main()
{
	SystemInit();

	int periods[] = {1, 2, 3, 4};
	int pins[] = {0x1000, 0x2000, 0x4000, 0x8000};
	setStateCounter(0);
	setStateMode(1);
	setStatePeriods(periods);
	setStatePins(pins);
	setStateSum(0);

	setGpioPortD();
	setGpioPortA();
	setTim3();
	setTim4();
	setNvicTim3();
	setNvicTim4();

	while(1){};
}

