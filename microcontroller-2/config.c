#include <config.h>
#include <stm32f4xx.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_syscfg.h>
#include <system_stm32f4xx.h>
#include <stm32f4xx_tim.h>
#include <misc.h>

GPIO_InitTypeDef GPIO_InitStruct;
int time = 480;
int prescaler = 10000;
int tWriting = 5;

void setTime(int t) {
	time = t;
}

void setGpioPortD() {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitTypeDef GPIO_StructPortD;

	GPIO_StructPortD.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_StructPortD.GPIO_Mode = GPIO_Mode_OUT;

	GPIO_Init(GPIOD, &GPIO_StructPortD);
	GPIO_StructInit(&GPIO_StructPortD);
}

void setGpioPortA() {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_StructPortA;
	GPIO_StructPortA.GPIO_Pin = GPIO_Pin_0;
	GPIO_StructPortA.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOA, &GPIO_StructPortA);
}

void setNvicTim3() {
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

void setNvicTim4() {
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x02;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

void setTim3() {
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	TIM_TimeBaseStructInit(&TIM_InitStruct);

	TIM_InitStruct.TIM_Period = tWriting-1;
	TIM_InitStruct.TIM_Prescaler = 6000-1;
	TIM_InitStruct.TIM_ClockDivision = 0;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_InitStruct);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
}

void setTim4() {
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	TIM_TimeBaseStructInit(&TIM_InitStruct);

	TIM_InitStruct.TIM_Period = time-1;
	TIM_InitStruct.TIM_Prescaler = prescaler-1;
	TIM_InitStruct.TIM_ClockDivision = 0;
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_InitStruct);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM4, ENABLE);
}
