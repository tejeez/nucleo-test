#include "stm32h745xx.h"

void SysTick_Handler()
{
	GPIOB->ODR ^= 1 | (1<<14);
}

void main(void)
{
	// Configure PB0 and PB14 as outputs
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOBEN;
	GPIOB->MODER = GPIO_MODER_MODE0_0 | GPIO_MODER_MODE14_0;

	// Turn one LED on already
	GPIOB->ODR = 1<<14;

	// Use SysTick for periodic interrupts
	SysTick_Config(10000000);
	NVIC_EnableIRQ(SysTick_IRQn);

	// Sleep outside of interrupts
	for(;;)
		__WFI();
}
