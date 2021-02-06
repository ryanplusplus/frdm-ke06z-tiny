/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
 
/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v6.0
processor: MKE06Z128xxx4
package_id: MKE06Z128VLK4
mcu_data: ksdk2_0
processor_version: 6.0.1
board: FRDM-KE06Z
pin_labels:
- {pin_num: '79', pin_signal: PTA5/KBI0_P5/IRQ/TCLK0/RESET_b, label: 'J4[6]/J7[10]/RST_TGTMCU/SW1', identifier: USER_LED}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '52', peripheral: GPIOB, signal: 'GPIO, 21', pin_signal: PTG5/KBI1_P21/FTM2_CH3/SPI1_MOSI, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{

    gpio_pin_config_t LED_RED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB21 (pin 52) */
    GPIO_PinInit(BOARD_LED_RED_GPIO_PORT, BOARD_LED_RED_PIN, &LED_RED_config);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
