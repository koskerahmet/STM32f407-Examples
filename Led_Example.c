
#include "main.h"

static void LED_GPIO_Init(void);


int main(void)
{
  HAL_Init();
	
  LED_GPIO_Init();

  while (1)
  {
        // PD12, PD13, PD14, PD15 Pins HIGH
   	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);  //
     	HAL_Delay(1000); // 1 Second Delay
	
	// PD12, PD13, PD14, PD15 Pins LOW
     	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET); //Ledlerin Pinlerini LOW Yapmak
     	HAL_Delay(2000); // 1 Second Delay
  }
}

void LED_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct_Led;

  __HAL_RCC_GPIOD_CLK_ENABLE(); // GPIOD Port Clock Enabled

  GPIO_InitStruct_Led.Pin 	= GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15; // Selected GPIO pins : PD12, PD13, PD14, PD15
  GPIO_InitStruct_Led.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct_Led.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct_Led.Speed     = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct_Led);
}
