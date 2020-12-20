/*!
 * @file
 * @brief
 */

#include "uart.h"
#include "tiny_single_subscriber_event.h"
#include "fsl_port.h"
#include "fsl_uart.h"
#include "tiny_utils.h"

#define UART UART1

static tiny_single_subscriber_event_t send_complete;
static tiny_single_subscriber_event_t receive;
static i_tiny_uart_t self;

void UART1_IRQHandler(void)
{
  if(kUART_RxDataRegFullFlag & UART_GetStatusFlags(UART)) {
    tiny_uart_on_receive_args_t args = { .byte = UART_ReadByte(UART) };
    tiny_single_subscriber_event_publish(&receive, &args);
  }

  if(kUART_TxDataRegEmptyFlag & UART_GetStatusFlags(UART)) {
    UART_DisableInterrupts(UART, kUART_TxDataRegEmptyInterruptEnable);
    tiny_single_subscriber_event_publish(&send_complete, NULL);
  }
}

static void send(i_tiny_uart_t* self, uint8_t byte)
{
  UART_WriteByte(UART, byte);
  UART_EnableInterrupts(UART, kUART_TxDataRegEmptyInterruptEnable);
}

static i_tiny_event_t* on_send_complete(i_tiny_uart_t* self)
{
  return &send_complete.interface;
}

static i_tiny_event_t* on_receive(i_tiny_uart_t* self)
{
  return &receive.interface;
}

static const i_tiny_uart_api_t api = { send, on_send_complete, on_receive };

static void initialize_peripheral(void)
{
  // Pins 63, 64 = TX, RX */
  PORT_SetPinSelect(kPORT_UART1, kPORT_UART1_RXPTC7_TXPTC6);

  uart_config_t config = {
    .baudRate_Bps = 115200,
    .parityMode = kUART_ParityDisabled,
    .stopBitCount = kUART_OneStopBit,
    .enableTx = true,
    .enableRx = true,
  };
  UART_Init(UART, &config, CLOCK_GetFreq(kCLOCK_BusClk));

  UART_EnableInterrupts(UART, kUART_RxDataRegFullInterruptEnable);
  EnableIRQ(UART1_IRQn);

  // Without this, the first byte doesn't seem to be sent
  // Maybe it implicitly clears some flag necessary for TX to work?
  (void)UART_GetStatusFlags(UART);
}

i_tiny_uart_t* uart_init(void)
{
  initialize_peripheral();

  tiny_single_subscriber_event_init(&send_complete);
  tiny_single_subscriber_event_init(&receive);

  self.api = &api;
  return &self;
}
