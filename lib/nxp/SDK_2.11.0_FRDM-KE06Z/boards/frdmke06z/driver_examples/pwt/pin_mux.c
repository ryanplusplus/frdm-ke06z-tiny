/*
 * Copyright 2017 ,2021 NXP
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
product: Pins v9.0
processor: MKE06Z128xxx4
package_id: MKE06Z128VLK4
mcu_data: ksdk2_0
processor_version: 9.0.0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
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
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '64', peripheral: UART1, signal: RX, pin_signal: PTC6/KBI0_P22/UART1_RX/CAN0_RX}
  - {pin_num: '63', peripheral: UART1, signal: TX, pin_signal: PTC7/KBI0_P23/UART1_TX/CAN0_TX}
  - {pin_num: '28', peripheral: PWT, signal: 'PWTIN, 0', pin_signal: PTD5/KBI0_P29/PWT_IN0}
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
    /* pin 64,63 is configured as UART1_RX, UART1_TX */
    PORT_SetPinSelect(kPORT_UART1, kPORT_UART1_RXPTC7_TXPTC6);
    /* pin 28 is configured as PWT_IN0 */
    PORT_SetPinSelect(kPORT_PWTIN0, kPORT_PWTIN0_PTD5);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
