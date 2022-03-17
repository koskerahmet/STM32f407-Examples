
#include "main.h"

void LED_GPIO_Init(void);
void BUTTON_GPIO_Init(void);

int main(void)
{
  HAL_Init();
  LED_GPIO_Init();

  while (1)
  {
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);
	   HAL_Delay(2000);
	   
     HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET); 
     HAL_Delay(2000);
  }
}

void LED_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct_Led;

  __HAL_RCC_GPIOD_CLK_ENABLE(); //Clock aktif etme

  GPIO_InitStruct_Led.Pin 	= GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15; 
  GPIO_InitStruct_Led.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct_Led.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct_Led.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct_Led);
}
