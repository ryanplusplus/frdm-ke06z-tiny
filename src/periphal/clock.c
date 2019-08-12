/*!
 * @file
 * @brief
 */

#include "stm32f30x.h"
#include "stm32f30x_rcc.h"
#include "stm32f30x_flash.h"
#include "clock.h"

void clock_init(void) {
  // 48-72 MHz requires 2 wait states
  FLASH_SetLatency(FLASH_Latency_2);

  RCC_DeInit();

  RCC_HSEConfig(RCC_HSE_ON);

  if(!RCC_WaitForHSEStartUp()) {
    NVIC_SystemReset();
  }

  RCC_ClockSecuritySystemCmd(ENABLE);

  // SYSCLK = HSE * 9 = 8 * 9 = 72 MHz
  RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_9);

  // HCLK (AHB) = SYSCLK / 1 = 72 / 1 = 72 MHz
  RCC_HCLKConfig(RCC_SYSCLK_Div1);

  // PCLK (APB1) = SYSCLK / 1 = 72 / 1 = 72 MHz
  RCC_PCLK1Config(RCC_HCLK_Div1);

  // PCLK2 (APB2) = SYSCLK / 2 = 72 / 2 = 36 MHz
  RCC_PCLK2Config(RCC_HCLK_Div1);

  // ADCCLK = PCLK2 / 1 = 72 / 1 = 72 MHz
  RCC_ADCCLKConfig(RCC_ADC12PLLCLK_Div1);

  RCC_PLLCmd(ENABLE);

  while(!RCC_GetFlagStatus(RCC_FLAG_PLLRDY)) {
  }

  RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);

  while(RCC_GetSYSCLKSource() != 0x08) {
  }

  SystemCoreClockUpdate();
}
