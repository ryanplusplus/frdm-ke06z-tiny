/*!
 * @file
 * @brief
 */

#include "watchdog.h"
#include "fsl_wdog8.h"

enum {
  kick_period = 100
};

static tiny_timer_t timer;

static void kick_watchdog(tiny_timer_group_t* group, void* context)
{
  (void)group;
  (void)context;
  WDOG8_Refresh(WDOG);
}

void watchdog_init(void)
{
  wdog8_config_t config = {
    .enableWdog8 = false,
    .clockSource = kWDOG8_ClockSource1,
    .prescaler = kWDOG8_ClockPrescalerDivide1,
    .workMode.enableWait = true,
    .workMode.enableStop = false,
    .workMode.enableDebug = false,
    .testMode = kWDOG8_TestModeDisabled,
    .enableUpdate = true,
    .enableInterrupt = false,
    .enableWindowMode = false,
    .windowValue = 0U,
    .timeoutValue = 0xFFU,
  };
  WDOG8_Init(WDOG, &config);
}

void watchdog_enable_kicker(tiny_timer_group_t* timer_group)
{
  tiny_timer_start_periodic(
    timer_group,
    &timer,
    kick_period,
    NULL,
    kick_watchdog);
}
