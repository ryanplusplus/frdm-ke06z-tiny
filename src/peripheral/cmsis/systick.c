/*!
 * @file
 * @brief
 */

#include "systick.h"
#include "micro.h"

static struct {
  i_tiny_time_source_t interface;
  volatile tiny_time_source_ticks_t ticks;
} self;

void SysTick_Handler(void) {
  self.ticks++;
}

static tiny_time_source_ticks_t ticks(i_tiny_time_source_t* _self) {
  (void)_self;

  tiny_time_source_ticks_t ticks1;
  tiny_time_source_ticks_t ticks2;

  do {
    ticks1 = self.ticks;
    ticks2 = self.ticks;
  } while(ticks1 != ticks2);

  return ticks1;
}

static const i_tiny_time_source_api_t api = { ticks };

i_tiny_time_source_t* systick_init(void) {
  if(SysTick_Config(SystemCoreClock / 1000)) {
    NVIC_SystemReset();
  }

  NVIC_SetPriority(SysTick_IRQn, 7);

  self.interface.api = &api;

  return &self.interface;
}
