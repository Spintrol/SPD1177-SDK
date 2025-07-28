/******************************************************************************
 * @file     iap.c
 * @brief    This file provides In-Application Programming process functions.
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


#include "iap.h"
#include <string.h>
#include <stdio.h>


/* Array stored frame code data (4 data_len + 256 data + 1 checksum ) 
 * Because the data address needs to be 4 bytes aligned, the data_len 
 * takes up 4 bytes
 **/
#if defined ( __CC_ARM )
static __align(4) uint8_t au8CodeData[261];
#else
#pragma data_alignment=4
static uint8_t au8CodeData[261];
#endif

/* Array stored sub-command data */
static uint8_t au8CmdData[64];

CAN_MessageTypeDef message_rx;
CAN_MessageTypeDef message_tx;

uint8_t u8NACK[1] = {NACK};
uint8_t u8ACK[1]  = { ACK};

uint8_t u8Buff[64];

/* Entry Point */
uint32_t *u32Entry;

/* Function prototype declarations */
static uint8_t IAP_CalculateChecksum(const uint8_t au8Buf[], uint32_t u32Size);
static uint32_t IAP_ConvertToInt(const uint8_t au8Buf[], uint8_t u8Size);


/*******************************************************************************
 * @brief      Read Mailbox Init
 *
 * @param[in]  CANx         : Select the CAN module
 *             u8MailboxId  : Mailbox id
 *             u32Count     : The number of data to be readed
 *
 * @return     ErrorStatus type
 *
 ******************************************************************************/
ErrorStatus CAN_Read_Mailbox_Init(CAN_REGS *CANx, uint32_t u8MailboxId)
{
    ErrorStatus status;
    uint32_t u8CanfdFlag;

    /* Get CAN Type */
    u8CanfdFlag = CAN_IsEnableFDFormat(CANx);

    /* Init mailbox for receive message */
    message_rx.eDataDir    = CAN_MSG_DATA_RX;
    message_rx.eRmtRspEn   = DISABLE;
    message_rx.eIntEn      = DISABLE;
    message_rx.eEobEn      = DISABLE;
    message_rx.eOverwriteEn= DISABLE;
    message_rx.eMaskRtrEn  = DISABLE;
    message_rx.eMaskIdeEn  = DISABLE;
    message_rx.u32Id       = 0x0;
    message_rx.u32IdMask   = 0x0;
    message_rx.u8MBoxId    = u8MailboxId;
    message_rx.eType       = CAN_FRAME_DATA;

    /* Set CAN frame format */
    if (u8CanfdFlag)
    {
        message_rx.eFormat      = CAN_FORMAT_FD_STD;
        message_rx.u8DataLen    = 64;
    }
    else
    {
        message_rx.eFormat      = CAN_FORMAT_STD;
        message_rx.u8DataLen    = 8;
    }

    /* Set mailbox */
    status = CAN_SetMessage(CANx, &message_rx);
    if (status != SUCCESS)
    {
        return ERROR;
    }

    message_rx.pu8Data = (uint8_t *)(long)(& CAN->CANMBOX[message_rx.u8MBoxId].CANMBOXFDW[0]);
    
    /* Enable mailbox */
    CAN_EnableMailbox(CANx, message_rx.u8MBoxId);

    return SUCCESS;
}


/*******************************************************************************
 * @brief      Write Mailbox Init
 *
 * @param[in]  CANx         : Select the CAN module
 *             u8MailboxId  : Mailbox id
 *             u32Count     : The number of data to be readed
 *
 * @return     ErrorStatus type
 *
 ******************************************************************************/
ErrorStatus CAN_Write_Mailbox_Init(CAN_REGS *CANx, uint8_t u8MailboxId)
{
    ErrorStatus status;
    /* !0:canfd, 0:can */
    uint32_t u8CanfdFlag;

    /* Get CAN Type */
    u8CanfdFlag = CAN_IsEnableFDFormat(CANx);

    /* Init mailbox for transmit message */
    message_tx.eDataDir    = CAN_MSG_DATA_TX;
    message_tx.eRmtRspEn   = DISABLE;
    message_tx.eIntEn      = DISABLE;
    message_tx.eEobEn      = DISABLE;
    message_tx.eBrs        = DISABLE;
    message_tx.eEsiCtlEn   = DISABLE;
    message_tx.eEsi        = DISABLE;
    message_tx.u32Id       = 0x1;
    message_tx.u8MBoxId    = u8MailboxId;
    message_tx.eType       = CAN_FRAME_DATA;
    message_tx.pu8Data     = u8Buff;

    /* Set CAN frame format */
    if (u8CanfdFlag)
    {
        message_tx.eFormat      = CAN_FORMAT_FD_STD;
        message_tx.u8DataLen    = 64;
    }
    else
    {
        message_tx.eFormat      = CAN_FORMAT_STD;
        message_tx.u8DataLen    = 8;
    }

    /* Set mailbox */
    status = CAN_SetMessage(CANx, &message_tx);
    if (status != SUCCESS)
    {
        return ERROR;
    }

    CAN_DisableMessageNew(CANx, message_tx.u8MBoxId);
    CAN_DisableMailboxTransmitRequest(CANx, message_tx.u8MBoxId);

    /* Enable mailbox */
    CAN_EnableMailbox(CANx, message_tx.u8MBoxId);
    
    return SUCCESS;
}


/*******************************************************************************
 * @brief      Read data from CAN
 *
 * @param[in]  CANx    : Select the CAN module
 *             au8Buf   : Pointer to the buffer stores the data readed
 *
 * @return     Read data len
 *
 ******************************************************************************/
uint8_t IAP_Read(CAN_REGS *CANx, uint8_t *au8Buf)
{
    int i;
    volatile uint32_t u32Timeout = 0xffffffff;

    /* Wait receive message Done */
    while (!CAN_GetMailboxControlInfo(CANx, message_rx.u8MBoxId, CAN_MBOX_SET_MSG_NEW))
    {
        if (u32Timeout-- == 0)
        {
            return 0;
        }
    }

    /* Get mailbox Data */
    CAN_GetMessage(CANx, &message_rx);
    
    for (i = 0; i < message_rx.u8DataLen; i++ )
    {
        au8Buf[i] = message_rx.pu8Data[i];
    }

    /* Clear Mailbox NEW */
    CAN_DisableMessageNew(CANx, message_rx.u8MBoxId);
    CAN_DisableMailboxTransmitRequest(CANx, message_rx.u8MBoxId);
    
    return message_rx.u8DataLen;
}


/*******************************************************************************
 * @brief      Write data to CAN
 *
 * @param[in]  CANx    : Select the CAN module
 *             au8Buf   : Pointer to the buffer stores the data to be written
 *             u32Count : The number of data to be written
 *
 * @return     write data len
 *
 ******************************************************************************/
uint8_t CAN_Write(CAN_REGS *CANx, uint8_t *au8Buf, uint8_t u8WriteLen)
{
    int i;
    volatile uint32_t u32Timeout = 0xffffffff;
    
    /* Set mailbox data len */
    CAN_SetMessageDataLength(CANx, message_tx.u8MBoxId, u8WriteLen);

    for (i = 0; i < u8WriteLen; i++ )
    {
        message_tx.pu8Data[i] = au8Buf[i];
    }

    /* Set mailbox data */
    CAN_SetMessageData(CANx, message_tx.u8MBoxId, message_tx.pu8Data, u8WriteLen);
    
    /* Enable Mailbox NEW and TXREQ */
    CAN_EnableMessageNew(CANx, message_tx.u8MBoxId);
    CAN_EnableMailboxTransmitRequest(CANx, message_tx.u8MBoxId);

    /* Wait transmit message Done */
    while (CAN_GetMailboxControlInfo(CANx, message_tx.u8MBoxId, CAN_MBOX_SET_MSG_NEW | CAN_MBOX_REQUEST_TX))
    {
        if (u32Timeout-- == 0)
        {
            return 0;
        }
    }
    
    return u8WriteLen;
}

/*******************************************************************************
 * @brief      Write data to CAN
 *
 * @param[in]  CANx    : Select the CAN module
 *             au8Buf   : Pointer to the buffer stores the data to be written
 *             u32Count : The number of data to be written
 *
 * @return     none
 *
 ******************************************************************************/
void IAP_Write(CAN_REGS *CANx, uint8_t *au8Buf, uint32_t u32WriteLen)
{
    uint8_t len = 0;
    uint32_t u32TotalLen = 0;
    uint32_t u8CanfdFlag;
    
    /* Get CAN Type */
    u8CanfdFlag = CAN_IsEnableFDFormat(CANx);

    while (u32TotalLen < u32WriteLen)
    {
        if (u8CanfdFlag)
        {
            /* CANFD format */
            if (u32WriteLen - u32TotalLen > 64)
            {
                len = CAN_Write(CANx, au8Buf + u32TotalLen, 64);
            }
            else
            {
                len = CAN_Write(CANx, au8Buf + u32TotalLen, u32WriteLen - u32TotalLen);
            }
        }
        else
        {
            /* CAN format */
            if (u32WriteLen - u32TotalLen > 8)
            {
                len = CAN_Write(CANx, au8Buf + u32TotalLen, 8);
            }
            else
            {
                len = CAN_Write(CANx, au8Buf + u32TotalLen, u32WriteLen - u32TotalLen);
            }
        }

        u32TotalLen = u32TotalLen + len;
    }
}



/*******************************************************************************
 * @brief      Calculate the checksum of the specified array data
 *
 * @param[in]  au8Buf       : Byte array
 *             u32Size      : The byte array size
 *
 * @return     Checksum of the byte array
 *
 ******************************************************************************/
static uint8_t IAP_CalculateChecksum(const uint8_t au8Buf[], uint32_t u32Size)
{
    /* Variable for loop */
    uint32_t i;

    /* Variable for checksum */
    uint8_t chkByte = 0xFFU;

    for (i = 0U; i < u32Size; i++)
    {
        chkByte ^= au8Buf[i];
    }

    return chkByte;
}




/*******************************************************************************
 * @brief      Convert byte array data to integer value
 *
 * @param[in]  au8Buf : Byte array
 *             u8Size : Byte array length
 *
 * @return     none
 *
 ******************************************************************************/
static uint32_t IAP_ConvertToInt(const uint8_t au8Buf[], uint8_t u8Size)
{
    /* Loop variable */
    int32_t i = 0;

    /* Store result value */
    uint32_t u32Data = 0U;


    for (i = ((int32_t)u8Size - 1); i >= 0; i--)
    {
        u32Data <<= 8;
        u32Data |= au8Buf[i];
    }

    return u32Data;
}


/****************************************************************************//**
 * @brief      Convert byte array data to int value
 *
 * @param[in]  pu8Buf: Pointer to byte array
 *             u8Size: Byte array length
 *
 * @return     none
 *
 *******************************************************************************/
uint32_t Drv_ConvertToInt(uint8_t *pu8Buf, uint8_t u8Size)
{
    /* Loop variable */
    int32_t i = 0;

    /* Store result value */
    uint32_t u32Data = 0;

    for(i = (u8Size - 1); i >= 0; i--)
    {
        u32Data <<= 8;
        u32Data |= pu8Buf[i];
    }

    return u32Data;
}



/********************************************************************************
 * @brief      Load user application code from CAN
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void IAP_LoadFromCAN(CAN_REGS *CANx)
{
    /* Variable for loop */
    uint32_t i = 0U;

    /* Temporary variable for checksum byte */
    uint8_t  u8TempChkByte = 0xFFU;

    /* Temporary variable for address data */
    uint32_t u32TempAddr = 0U;

    /* Temporary variable for size data */
    uint32_t u32TempSize = 0U;

    /* CAN Type */
    uint32_t u8CanfdFlag;
    
    /* Receiven data len */
    uint32_t u32Len;
    
    FlashOperationStatus Status;
    
    volatile uint32_t u32Timeout = 0xffffffff;
    
    /* 1:CANFD 0:CAN */
    u8CanfdFlag = CAN_IsEnableFDFormat(CANx);
    
    /******************************************************/
    /******************  Command Routine  *****************/
    /******************************************************/
    while (u32Timeout != 0)
    {
        IAP_Read(CANx, au8CmdData);

        /* Command routine */
        switch (au8CmdData[0])
        {
            case CMD_WRITE_MEMORY:
                u32Timeout = 0xffffffff;
            
                /* Calculate checksum */
                u8TempChkByte = IAP_CalculateChecksum(au8CmdData, 5);
                
                /* Validate checksum */
                if (u8TempChkByte != au8CmdData[5])
                {
                    /* Invalid checksum, Send NACK */
                    IAP_Write(CANx, u8NACK, 1);
                    break;
                }

                /* Get the start address */
                u32TempAddr = IAP_ConvertToInt(au8CmdData + 1, 4U);

                /* Send ACK */
                IAP_Write(CANx, u8ACK, 1);
                
                /* Receive number of bytes to be written */
                u32Len = IAP_Read(CANx, au8CodeData + 3);

                /* Frame size data_len occupies 4 bytes,
                 * the first three bytes are invalid for
                 * the subsequent data to be aligned with 4 bytes
                 */
                u32TempSize = au8CodeData[3] + 3U;
                
                /* Receive code data */
                while (u32Len < u32TempSize)
                {
                    u32Len = u32Len + IAP_Read(CANx, au8CodeData + 3 + u32Len);
                }

                /* Calculate checksum */
                u8TempChkByte = IAP_CalculateChecksum(au8CodeData + 3, u32TempSize - 1);

                /* Validate frame checksum */
                if (u8TempChkByte != au8CodeData[u32TempSize + 3 - 1])
                {
                    IAP_Write(CANx, u8NACK, 1);
                    break;
                }
                
                /* Validate address */
                if ((u32TempAddr & 0x7) != 0)
                {
                    IAP_Write(CANx, u8NACK, 1);
                    break;
                }
                
                /* Validate size */
                if (((u32TempSize - 2) & 0x7) != 0)
                {
                    IAP_Write(CANx, u8NACK, 1);
                    break;
                }

                /* Check address and Write data to the target memory */
                if ((u32TempAddr >= FLASH_START_ADDR) && (u32TempAddr < FLASH_END_ADDR))
                {
                    /* Program data to Flash */
                    Status = pHWLIB->FLASHC_Program((uint32_t *)(au8CodeData + 4), u32TempAddr, (u32TempSize - 2) / 4U);
                    if (Status != FLASH_OP_SUCCESS)
                    {
                        IAP_Write(CANx, u8NACK, 1);
                        break;
                    }
                }
                else
                {
                    /* Invalid memory address, send NACK */
                    IAP_Write(CANx, u8NACK, 1);
                    break;
                }

                /* Send ACK */
                IAP_Write(CANx, u8ACK, 1);

                break;

            case CMD_GO:
                u32Timeout = 0xffffffff;
            
                /* Calculate checksum */
                u8TempChkByte = IAP_CalculateChecksum(au8CmdData, 5);
            
                /* Validate checksum */
                if(u8TempChkByte != au8CmdData[5])
                {
                    /* Invalid checksum, Send NACK */
                    IAP_Write(CANx, u8NACK, 1);
                    break;
                }

                /* Get the jump address */
                u32TempAddr = Drv_ConvertToInt(au8CmdData + 1, 4U);

                /* Check the jump address */
                if(((u32TempAddr >= FLASH_START_ADDR) && (u32TempAddr < FLASH_END_ADDR)))
                {
                    /* Set Entry Point */
                    u32TempAddr += 4U;  /* Address of Reset Handler */
                    u32Entry = (uint32_t *)(u32TempAddr);

                    /* Send ACK */
                    IAP_Write(CANx, u8ACK, 1);

                    /* Jump to the address */
                    ((PTRJUMP)(*u32Entry))();
                }

                /* Send NACK */
                IAP_Write(CANx, u8NACK, 1);
                
                break;

            case CMD_EXT_ERASE:
                u32Timeout = 0xffffffff;
            
                /* CAN protocol, which needs to be used to receive data again */
                if (u8CanfdFlag == 0)
                {
                    IAP_Read(CANx, au8CmdData + 8);
                }

                /* Calculate checksum */
                u8TempChkByte = IAP_CalculateChecksum(au8CmdData, 9);

                /* Validate checksum */
                if (u8TempChkByte != au8CmdData[9])
                {
                    IAP_Write(CANx, u8NACK, 1);
                    break;
                }

                /* Get the start address for erase */
                u32TempAddr = Drv_ConvertToInt(au8CmdData + 1, 4);

                /* Get the erase area size */
                u32TempSize = Drv_ConvertToInt(au8CmdData + 5, 4);
                
                /* Validate address */
                if ((u32TempAddr & 0xfff) != 0)
                {
                    IAP_Write(CANx, u8NACK, 1);
                    break;
                }

                /* Erase */
                for(i = u32TempAddr; i < (u32TempAddr + u32TempSize); i += FLASH_SECTOR_SIZE)
                {
                    /* Erase sector, address Sector aligned */
                    Status = pHWLIB->FLASHC_EraseSector(i);
                    if (Status != FLASH_OP_SUCCESS)
                    {
                        IAP_Write(CANx, u8NACK, 1);
                        break;
                    }
                }
                if (Status == FLASH_OP_SUCCESS)
                {
                    /* Send ACK */
                    IAP_Write(CANx, u8ACK, 1);
                }
                break;

            default :
                break;
        } /* For switch-case   */
        
        u32Timeout--;
    } /* For while loop */
    
    /* Entry point */
    u32Entry = (uint32_t *)(0x1000F000 + 4);

    /* Jump to the application */
    ((PTRJUMP)(*u32Entry))();
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
