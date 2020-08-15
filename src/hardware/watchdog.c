/*!
 * @file
 * @brief
 */

#include "watchdog.h"
#include "micro.h"

void watchdog_init(void) {
  LL_IWDG_EnableWriteAccess(IWDG);
  {
    // Watchdog tick rate = 32 KHz / 32 = 1 msec
    LL_IWDG_SetPrescaler(IWDG, LL_IWDG_PRESCALER_32);

    // 1000 * tick rate = 1000 * 1 = 1 second timeout
    LL_IWDG_SetReloadCounter(IWDG, 1000);
  }
  LL_IWDG_DisableWriteAccess(IWDG);

  LL_IWDG_ReloadCounter(IWDG);
  LL_IWDG_Enable(IWDG);
}

void watchdog_kick(void) {
  LL_IWDG_ReloadCounter(IWDG);
}
