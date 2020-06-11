#include "stm32f412zx.h"

void SysTick_Handler()
{
	GPIOB->ODR ^= 1 | (1<<14);
}

void main(void)
{
	// Configure PB0 and PB14 as outputs
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
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
