/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include "fsl_gpio.h"
#include "heartbeat.h"

#define port GPIOB
#define pin 21

enum {
  half_period_in_msec = 500,
};

static tiny_timer_t timer;

static void blink(tiny_timer_group_t* group, void* context)
{
  (void)context;
  port->PTOR = (1 << pin);
}

void heartbeat_init(tiny_timer_group_t* timer_group)
{
  port->PDDR |= (1 << pin);
  port->PIDR |= (1 << pin);

  tiny_timer_start_periodic(timer_group, &timer, half_period_in_msec, blink, NULL);
}
