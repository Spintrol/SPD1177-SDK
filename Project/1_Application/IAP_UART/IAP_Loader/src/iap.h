/**************************************************************************//**
 * @file     iap.h
 * @brief    IAP header file.
 * @version  V12.0.5
 * @date     5-June-2025
 *
 * @note
 * Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd.. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/

#ifndef IAP_H
#define IAP_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1169.h"




/**
 *  @brief UART IAP commands
 */
#define CMD_WRITE_MEMORY          0x36      /*!< Writes up to 256 bytes to the Flash memory starting from an address specified by the application */
#define CMD_ERASE                 0x34      /*!< Erases the specified Flash memory area */
#define CMD_GO                    0x21      /*!< Jumps to user application code located in the internal Flash memory */



/**
 *  @brief Constants definition
 */
#define FLASH_START_ADDR          0x10000000        /*!< FLASH memory start address */
#define FLASH_END_ADDR            0x1000FFFF        /*!< FLASH memory end address   */




/**
 *  @brief IAP Public Function Declaration
 */
void Drv_UartWriteByte(uint8_t u8Data);
void IAP_LoadFromUart(void);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* IAP_H */


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
