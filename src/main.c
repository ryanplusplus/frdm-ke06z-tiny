/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include "stm32f0xx.h"
#include "clock.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_gpio.h"
#include "tiny_utils.h"

#ifdef USE_SYSTEM_VIEW
#include "SEGGER_SYSVIEW.h"
#endif

static StaticTask_t on_task;
static StackType_t on_task_stack[512 / sizeof(StackType_t)];
static void on_task_function(void* context) {
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);

  LL_GPIO_SetPinSpeed(GPIOC, LL_GPIO_PIN_13, LL_GPIO_SPEED_FREQ_LOW);
  LL_GPIO_SetPinOutputType(GPIOC, LL_GPIO_PIN_13, LL_GPIO_OUTPUT_PUSHPULL);
  LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_13, LL_GPIO_MODE_OUTPUT);
  LL_GPIO_SetPinPull(GPIOC, LL_GPIO_PIN_13, LL_GPIO_PULL_UP);

  while(1) {
    LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_13);
    vTaskDelay(57);
  }

  vTaskDelete(NULL);
}

static StaticTask_t off_task;
static StackType_t off_task_stack[512 / sizeof(StackType_t)];
static void off_task_function(void* context) {
  while(1) {
    LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_13);
    vTaskDelay(73);
  }

  vTaskDelete(NULL);
}

void main(void) {
  __disable_irq();
  {
    clock_init();

    xTaskCreateStatic(
      on_task_function,
      "on_task",
      element_count(on_task_stack),
      NULL,
      1,
      on_task_stack,
      &on_task);

    xTaskCreateStatic(
      off_task_function,
      "off_task",
      element_count(off_task_stack),
      NULL,
      1,
      off_task_stack,
      &off_task);
  }
  __enable_irq();

#ifdef USE_SYSTEM_VIEW
  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();
#endif

  vTaskStartScheduler();
}

static StaticTask_t idle_task;
static StackType_t idle_task_stack[configMINIMAL_STACK_SIZE];
void vApplicationGetIdleTaskMemory(StaticTask_t** task, StackType_t** stack, uint32_t* stack_size) {
  *task = &idle_task;
  *stack = idle_task_stack;
  *stack_size = element_count(idle_task_stack);
}

static StaticTask_t timer_task;
static StackType_t timer_task_stack[configMINIMAL_STACK_SIZE];
void vApplicationGetTimerTaskMemory(StaticTask_t** task, StackType_t** stack, uint32_t* stack_size) {
  *task = &timer_task;
  *stack = timer_task_stack;
  *stack_size = element_count(timer_task_stack);
}
