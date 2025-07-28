/******************************************************************************
 * @file     iap.h
 * @brief    In-Application Programming process header file.
 * @version  V8.1.3
 * @date     5-September-2024
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


#if defined(SPD1179)
    #include "spd1179.h"
#else
    #include "spc1169.h"
#endif




/**
 *  @brief Function pointer for jump branch
 */
typedef void (*PTRJUMP)(void);




/**
 *  @brief Mailbox ID define
 */
#define WRITE_MAILBOX_ID        (0)   /*!< Write mailbox id */
#define READ_MAILBOX_ID         (2)   /*!< Read mailbox id */




/**
 *  @brief UART bootloader commands
 */
#define CMD_WRITE_MEMORY          (0x36U)   /*!< Writes up to 256 bytes to the RAM or Flash memory starting from an address specified by the application */
#define CMD_EXT_ERASE             (0x34U)   /*!< Erases one to all Flash memory sectors using two byte addressing mode */
#define CMD_GO                    (0x21U)   /*!< Jumps to user application code located in the internal Flash memory */




/**
 *  @brief Constants define
 */
#define FLASH_START_ADDR        (0x10000000U)   /*!< FLASH memory start address                      */
#define FLASH_END_ADDR          (0x1000FFFFU)   /*!< FLASH memory end address for user application   */



#define ACK                     (0x79U)         /*!< Acknowledge byte           */
#define NACK                    (0x1FU)         /*!< Non-Acknowledge byte       */


/**
 *  @brief Boot Public Function Declaration
 */
ErrorStatus CAN_Read_Mailbox_Init(CAN_REGS *CANx, uint32_t u8MailboxId);
ErrorStatus CAN_Write_Mailbox_Init(CAN_REGS *CANx, uint8_t u8MailboxId);

void IAP_Write(CAN_REGS *CANx, uint8_t *au8Buf, uint32_t u32WriteLen);
uint8_t IAP_Read(CAN_REGS *CANx, uint8_t *au8Buf);

void IAP_LoadFromCAN(CAN_REGS *CANx);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* IAP_H */


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/

