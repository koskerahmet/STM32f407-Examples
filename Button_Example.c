
#include "main.h"

static void LED_GPIO_Init(void);
static void BUTTON_GPIO_Init(void);

int main(void)
{
  HAL_Init();
	
  BUTTON_GPIO_Init();
  LED_GPIO_Init();

  while (1)
  {
    GPIO_PinState PinState = GPIO_PIN_RESET;

    PinState = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

    if(PinState == GPIO_PIN_SET)
    {
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_SET);
    }
    else
    {
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);
    }
  }
}


void LED_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct_Led;

  __HAL_RCC_GPIOD_CLK_ENABLE();

  GPIO_InitStruct_Led.Pin   = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  GPIO_InitStruct_Led.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct_Led.Pull  = GPIO_NOPULL;
  GPIO_InitStruct_Led.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct_Led);
}


void BUTTON_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct_Button;

  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitStruct_Button.Pin   = GPIO_PIN_0;
  GPIO_InitStruct_Button.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct_Button.Pull  = GPIO_NOPULL;
  GPIO_InitStruct_Button.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct_Button);
}
