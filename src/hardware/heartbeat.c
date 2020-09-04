/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include <stdbool.h>
#include "MKE06Z4.h"
#include "heartbeat.h"

#define port GPIOB
#define pin 21

enum {
  half_period_in_msec = 500,
};

static struct {
  tiny_timer_t timer;
  bool state;
} self;

static void blink(tiny_timer_group_t* group, void* context)
{
  (void)context;

  if(self.state) {
    port->PCOR = (1 << pin);
  }
  else {
    port->PSOR = (1 << pin);
  }

  self.state = !self.state;

  tiny_timer_start(group, &self.timer, half_period_in_msec, blink, NULL);
}

void heartbeat_init(tiny_timer_group_t* timer_group)
{
  port->PDDR |= (1 << pin);
  port->PIDR |= (1 << pin);

  tiny_timer_start(timer_group, &self.timer, half_period_in_msec, blink, NULL);
}
