//Led yanmasi icin kullanici(mavi) butonuna basili tutunuz.


#include "main.h"



void LED_GPIO_Init(void);
void BUTTON_GPIO_Init(void);


int main(void)
{

  HAL_Init();

  BUTTON_GPIO_Init();
  LED_GPIO_Init();

  int kontrol = 0;

  while (1)
  {
	  kontrol = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

	  if(kontrol == 1){
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);
	  }
    else{
	    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);
	  }
  }
}


void LED_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct_Led;

  __HAL_RCC_GPIOD_CLK_ENABLE();

  GPIO_InitStruct_Led.Pin 	= GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  GPIO_InitStruct_Led.Mode 	= GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct_Led.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct_Led.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct_Led);
}


void BUTTON_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct_Button;

  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct_Button.Pin 	= GPIO_PIN_0;
  GPIO_InitStruct_Button.Mode 	= GPIO_MODE_INPUT;
  GPIO_InitStruct_Button.Pull 	= GPIO_NOPULL;
  GPIO_InitStruct_Button.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct_Button);
}
