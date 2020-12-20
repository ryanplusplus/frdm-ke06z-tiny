/*!
 * @file
 * @brief
 */

#include "MKE06Z4.h"
#include "systick.h"

static i_tiny_time_source_t interface;
static volatile tiny_time_source_ticks_t ticks;

void SysTick_Handler(void)
{
  ticks++;
}

static tiny_time_source_ticks_t _ticks(i_tiny_time_source_t* _self)
{
  (void)_self;

  // ticks has less than integer size so is atomic
  return ticks;
}

static const i_tiny_time_source_api_t api = { _ticks };

i_tiny_time_source_t* systick_init(void)
{
  if(SysTick_Config(SystemCoreClock / 1000)) {
    NVIC_SystemReset();
  }

  NVIC_SetPriority(SysTick_IRQn, 7);

  interface.api = &api;

  return &interface;
}
