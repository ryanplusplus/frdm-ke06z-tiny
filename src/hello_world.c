/*!
 * @file
 * @brief
 */

#include "hello_world.h"
#include "tiny_utils.h"

static tiny_event_subscription_t send_complete_subscription;

static const uint8_t message[] = "hello, world!\r\n";
static uint8_t offset;

static void send_next_byte(void* context, const void* args)
{
  reinterpret(uart, context, i_tiny_uart_t*);
  (void)args;

  if(offset < sizeof(message)) {
    tiny_uart_send(uart, message[offset++]);
  }
}

void hello_world_init(i_tiny_uart_t* uart)
{
  tiny_event_subscription_init(&send_complete_subscription, uart, send_next_byte);
  tiny_event_subscribe(tiny_uart_on_send_complete(uart), &send_complete_subscription);

  tiny_uart_send(uart, message[offset++]);
}
