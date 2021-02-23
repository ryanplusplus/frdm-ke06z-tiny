/*!
 * @file
 * @brief
 */

#include "interrupts.h"
#include "clock.h"
#include "watchdog.h"
#include "systick.h"
#include "tiny_timer.h"
#include "heartbeat.h"
#include "uart.h"
#include "hello_world.h"

#include "fsl_gpio.h"

static tiny_timer_group_t timer_group;

int main(void)
{
  interrupts_disable();
  {
    watchdog_init();
    clock_init();
    tiny_timer_group_init(&timer_group, systick_init());
    watchdog_enable_kicker(&timer_group);
    heartbeat_init(&timer_group);
    hello_world_init(uart_init());
  }
  interrupts_enable();

  while(1) {
    tiny_timer_group_run(&timer_group);
  }
}

void exit(int status)
{
  (void)status;

  while(1) {
  }
}
