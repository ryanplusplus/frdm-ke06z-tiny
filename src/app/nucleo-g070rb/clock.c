/*!
 * @file
 * @brief
 */

#include "stm32g0xx_ll_rcc.h"
#include "stm32g0xx_ll_system.h"
#include "clock.h"

void clock_init(void) {
  LL_RCC_HSI_Enable();
  while(!LL_RCC_HSI_IsReady()) {
  };

  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);

  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI) {
  };

  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);

  SystemCoreClockUpdate();
}
