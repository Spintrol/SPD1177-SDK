/******************************************************************************
 * @file     iap.c
 * @brief    This file provides In-Application Programming process functions.
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


#include "iap.h"




/* Array stored frame code data */
static __align(4) uint8_t au8CodeData[264];

/* Array stored sub-command data */
static uint8_t au8SubCmdData[12];

/**
 *  @brief Function pointer for jump branch
 */
typedef void (*PTRJUMP)(void);

/* Entry Point */
uint32_t *u32Entry;

/* Function prototype declarations */
static uint8_t IAP_CalculateChecksum(const uint8_t au8Buf[], uint32_t u32Size, uint8_t u8OptionData);
static uint32_t IAP_ConvertToInt(const uint8_t au8Buf[], uint8_t u8Size);




/*******************************************************************************
 * @brief      Wait LIN RX Frame
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
void IAP_WaitRXFrame()
{
    volatile uint32_t u32Timeout = 0xffffffff;
    
    /* Wait id match event */
    while(UART_GetIntRawFlag(UART1, UART_INT_LIN_ID_MATCH) == 0)
    {
        if (u32Timeout-- == 0)
        {
            return;
        }
    }
    
    /* Clear id match flag */
    UART_ClearInt(UART1, UART_INT_LIN_ID_MATCH);  
        
    /* Set the check mode */
    LIN_SetCheckSumMode(UART1, LIN_ENHANCED_CHECKSUM);

    /* Set the respond mode */
    LIN_SetResponse(UART1, LIN_RESPONSE_RX);

    /* Set the respond lenth */
    LIN_SetResponseLen(UART1, LIN_RESPONSE_8_BYTE);
    
    u32Timeout = 0xffffffff;
    
    while(UART_GetRxFIFOLevel(UART1) != 8)
    {
        if (u32Timeout-- == 0)
        {
            return;
        }
    }
}




/*******************************************************************************
 * @brief      Read single frame from LIN
 *
 * @param[in]  au8Buf      : Pointer to the buffer stores the data readed
 *             u32Location : The specific location of au8Buf to save data
 *
 * @return     none
 *
 ******************************************************************************/
void IAP_ReadSingleFrame(uint8_t au8Buf[], uint32_t u32Location)
{
    uint32_t i;
    
    IAP_WaitRXFrame();
    
    for (i = 0; i < LIN_RESPONSE_8_BYTE; i++)
    {
        au8Buf[u32Location] = UART_ReadByte(UART1);
        u32Location++;
    }
}




/*******************************************************************************
 * @brief      Write frame to LIN
 *
 * @param[in]  au8Buf              : Pointer to the buffer stores the data 
 *                                   to be written
 *             u32TotalFrameNumber : The total number of frames
 *
 * @return     none
 *
 ******************************************************************************/
void IAP_WriteFrame(uint8_t au8Buf[], uint32_t u32TotalFrameNumber)
{
    uint32_t i, j;
    volatile uint32_t u32Timeout = 0xffffffff;
    
    /* Discard old id match flag */
    UART_ClearInt(UART1, UART_INT_LIN_ID_MATCH);  
    
    for (i = 0; i < u32TotalFrameNumber; i++)
    {
        u32Timeout = 0xffffffff;
        
        /* Wait id match event */
        while(UART_GetIntRawFlag(UART1, UART_INT_LIN_ID_MATCH) == 0)
        {
            if (u32Timeout-- == 0)
            {
                return;
            }
        }
        
        /* Clear id match flag */
        UART_ClearInt(UART1, UART_INT_LIN_ID_MATCH);  
            
        /* Set the check mode */
        LIN_SetCheckSumMode(UART1, LIN_ENHANCED_CHECKSUM);

        /* Set the respond mode */
        LIN_SetResponse(UART1, LIN_RESPONSE_TX);

        /* Set the respond lenth */
        LIN_SetResponseLen(UART1, LIN_RESPONSE_8_BYTE);
        
        for (j = 0; j < LIN_RESPONSE_8_BYTE; j++)
        {
            UART_WriteByte(UART1, au8Buf[(8 * i + j)]);
        }
        
        /* Send frame */
        SET_BITS(UART1->LINCTL, LINCTL_TXCHKSUM_TRANSMIT);
    }
}




/*******************************************************************************
 * @brief      Calculate the checksum of the specified array data
 *
 * @param[in]  au8Buf       : Byte array
 *             u32Size      : The byte array size
 *             u8OptionData : Optional byte data, if no, set 0x00
 *
 * @return     Checksum of the byte array
 *
 ******************************************************************************/
static uint8_t IAP_CalculateChecksum(const uint8_t au8Buf[], uint32_t u32Size, uint8_t u8OptionData)
{
    /* Variable for loop */
    uint32_t i;

    /* Variable for checksum */
    uint8_t chkByte = 0xFFU;

    /* Calculate checksum */
    chkByte ^= u8OptionData;

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
 * @brief      Load user application code from LIN
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void IAP_LoadFromLIN(void)
{
    /* Variable for loop */
    uint32_t i = 0U;

    /* Temporary variable for checksum byte */
    uint8_t  u8TempChkByte = 0xFFU;

    /* Temporary variable for address data */
    uint32_t u32TempAddr = 0U;

    /* Temporary variable for size data */
    uint32_t u32TempSize = 0U;
    
    FlashOperationStatus Status;
    
    volatile uint32_t u32Timeout = 0xffffffff;

    /* Enable Flash register write access */
    FLASHC_WALLOW();

    /******************************************************/
    /******************  Command Routine  *****************/
    /******************************************************/
    while (u32Timeout != 0)
    {
        IAP_ReadSingleFrame(au8CodeData, 0);
        
        if (au8CodeData[0] == CMD_EXT_ERASE)
        {
            IAP_ReadSingleFrame(au8CodeData, 8);
        }
        
        /* Command routine */
        switch (au8CodeData[0])
        {
            case CMD_WRITE_MEMORY:
                u32Timeout = 0xffffffff;

                /* Calculate checksum */
                u8TempChkByte = IAP_CalculateChecksum(&au8CodeData[1], 4U, au8CodeData[0]);

                /* Validate checksum */
                if (u8TempChkByte != au8CodeData[5])
                {
                    /* Invalid checksum, Send NACK */
                    au8SubCmdData[0] = NACK;
                    IAP_WriteFrame(au8SubCmdData, 1);
                    break;
                }

                /* Get the start address */
                u32TempAddr = IAP_ConvertToInt(&au8CodeData[1], 4U);

                /* Send ACK */
                au8SubCmdData[0] = ACK;
                IAP_WriteFrame(au8SubCmdData, 1);
                
                /* Read first Frame */
                IAP_ReadSingleFrame(au8CodeData, 0);
                
                /* Remaining length is au8CodeData[0] + 1 + 1 + 1 - 8 */
                u32TempSize = au8CodeData[0] - 5;
                
                if ((u32TempSize & 0x7) == 0)
                {
                    u32TempSize = u32TempSize / 8;
                }
                else
                {
                    u32TempSize = u32TempSize / 8;
                    u32TempSize++;
                }

                /* Read remaining data */
                for (i = 0; i < u32TempSize; i++)
                {
                    IAP_ReadSingleFrame(au8CodeData, (8 + 8 * i));
                }
                
                /* Frame size */
                u32TempSize = (uint32_t)au8CodeData[0] + 1U;

                /* Calculate checksum */
                u8TempChkByte = IAP_CalculateChecksum(&au8CodeData[1], u32TempSize, au8CodeData[0]);

                /* Validate frame checksum */
                if (u8TempChkByte != au8CodeData[(au8CodeData[0] + 2)])
                {
                    au8SubCmdData[0] = NACK;
                    IAP_WriteFrame(au8SubCmdData, 1);
                    break;
                }
                
                /* Validate address */
                if ((u32TempAddr & 0x7) != 0)
                {
                    au8SubCmdData[0] = NACK;
                    IAP_WriteFrame(au8SubCmdData, 1);
                    break;
                }
                
                /* Validate size */
                if ((u32TempSize & 0x7) != 0)
                {
                    au8SubCmdData[0] = NACK;
                    IAP_WriteFrame(au8SubCmdData, 1);
                    break;
                }

                /* Check address and Write data to the target memory */
                if ((u32TempAddr >= FLASH_START_ADDR) && (u32TempAddr < FLASH_END_ADDR))
                {
                    /* Program data to Flash */
                    Status = pHWLIB->FLASHC_Program((uint32_t *)(&au8CodeData[1]), u32TempAddr, u32TempSize / 4U);
                    if (Status != FLASH_OP_SUCCESS)
                    {
                        au8SubCmdData[0] = NACK;
                        IAP_WriteFrame(au8SubCmdData, 1);
                        break;
                    }
                }
                else
                {
                    /* Invalid memory address, send NACK */
                    au8SubCmdData[0] = NACK;
                    IAP_WriteFrame(au8SubCmdData, 1);
                    break;
                }

                /* Send ACK */
                au8SubCmdData[0] = ACK;
                IAP_WriteFrame(au8SubCmdData, 1);
                break;

            case CMD_GO:
                u32Timeout = 0xffffffff;
            
                /* Calculate checksum */
                u8TempChkByte = IAP_CalculateChecksum(&au8CodeData[1], 4U, au8CodeData[0]);
            
                /* Validate checksum */
                if(u8TempChkByte != au8CodeData[5])
                {
                    au8SubCmdData[0] = NACK;
                    IAP_WriteFrame(au8SubCmdData, 1);
                    break;
                }

                /* Get the jump address */
                u32TempAddr = Drv_ConvertToInt(&au8CodeData[1], 4U);

                /* Check the jump address */
                if(((u32TempAddr >= FLASH_START_ADDR) && (u32TempAddr < FLASH_END_ADDR)))
                {
                    /* Set Entry Point */
                    u32TempAddr += 4U;
                    u32Entry = (uint32_t *)(u32TempAddr);

                    /* Send ACK */
                    au8SubCmdData[0] = ACK;
                    IAP_WriteFrame(au8SubCmdData, 1);

                    /* Wait TXD pin finishing data transfer */
                    while(UART_GetTxFIFOLevel(UART1) != 0)
                    {
                    }
                    Delay_Ms(10);
                    
                    /* Revert LIN configuration to original */
                    WRITE_REG(UART1->UARTCTL, 0);
                    WRITE_REG(UART1->LINCTL, 0);
                    WRITE_REG(UART1->LINIDFILT, 0);
                    
                    /* Jump to the address */
                    ((PTRJUMP)(*u32Entry))();
                }

                /* Send NACK */
                au8SubCmdData[0] = NACK;
                IAP_WriteFrame(au8SubCmdData, 1);
                break;

            case CMD_EXT_ERASE:
                u32Timeout = 0xffffffff;
            
                /* Calculate checksum */
                u8TempChkByte = IAP_CalculateChecksum(&au8CodeData[1], 8, au8CodeData[0]);

                /* Validate checksum */
                if (u8TempChkByte != au8CodeData[9])
                {
                    au8SubCmdData[0] = NACK;
                    IAP_WriteFrame(au8SubCmdData, 1);
                    break;
                }
                /* Get the start address for erase */
                u32TempAddr = Drv_ConvertToInt(&au8CodeData[1], 4);

                /* Get the erase area size */
                u32TempSize = Drv_ConvertToInt(&au8CodeData[1] + 4, 4);

                /* Validate address and size */
                if((u32TempAddr < FLASH_START_ADDR) || (u32TempAddr > FLASH_END_ADDR))
                {
                    au8SubCmdData[0] = NACK;
                    IAP_WriteFrame(au8SubCmdData, 1);
                    break;
                }
                
                /* Validate address */
                if ((u32TempAddr & 0xfff) != 0)
                {
                    au8SubCmdData[0] = NACK;
                    IAP_WriteFrame(au8SubCmdData, 1);
                    break;
                }

                /* Erase */
                for(i = u32TempAddr; i < (u32TempAddr + u32TempSize); i += FLASH_SECTOR_SIZE)
                {
                    /* Erase sector, address Sector aligned */
                    Status = pHWLIB->FLASHC_EraseSector(i);
                    if (Status != FLASH_OP_SUCCESS)
                    {
                        au8SubCmdData[0] = NACK;
                        IAP_WriteFrame(au8SubCmdData, 1);
                        break;
                    }
                }
                if (Status == FLASH_OP_SUCCESS)
                {
                    /* Send ACK */
                    au8SubCmdData[0] = ACK;
                    IAP_WriteFrame(au8SubCmdData, 1);
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
