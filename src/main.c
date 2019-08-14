/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include "stm32f30x.h"
#include "clock.h"
#include "systick.h"
#include "tiny_timer.h"
#include "watchdog.h"
#include "heartbeat.h"
#include "i2c1.h"
#include "lsm303dlhc.h"

static tiny_timer_group_t timer_group;
static tiny_timer_t timer;
static lsm303dlhc_t lsm;

static void kick_watchdog(tiny_timer_group_t* _timer_group, void* context) {
  (void)context;
  (void)_timer_group;
  watchdog_kick();
  tiny_timer_start(&timer_group, &timer, 1, kick_watchdog, NULL);
}

void main(void) {
  __disable_irq();
  {
    watchdog_init();
    clock_init();
    tiny_timer_group_init(&timer_group, systick_init());
    heartbeat_init(&timer_group);
    lsm303dlhc_init(&lsm, i2c1_init());
  }
  __enable_irq();

  tiny_timer_start(&timer_group, &timer, 1, kick_watchdog, NULL);

  while(1) {
    tiny_timer_group_run(&timer_group);
  }
}
