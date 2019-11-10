/*!
 * @file
 * @brief
 */

#include "watchdog.h"
#include "stm32f30x_iwdg.h"

void watchdog_init(void) {
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
  {
    // Watchdog tick rate = 32 KHz / 32 = 1 msec
    IWDG_SetPrescaler(IWDG_Prescaler_32);

    // 1000 * tick rate = 1000 * 1 = 1 second timeout
    IWDG_SetReload(1000);
  }
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Disable);

  IWDG_ReloadCounter();
  IWDG_Enable();
}

void watchdog_kick(void) {
  IWDG_ReloadCounter();
}
