/**************************************************************************//**
 * @file     IAP.c
 * @brief    This file provides IAP process functions.
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
#include <string.h>


/* Array stored download command data */
uint8_t au8CmdData[2];

/* Array stored frame code data */
uint8_t au8CodeData[256];

/* Array stored sub-command data */
uint8_t au8SubCmdData[12];

/* Array stored data length */
uint8_t au8LenData[2];

/* Frame Checksum byte */
uint8_t u8ChecksumData;

/**
 *  @brief Function pointer for jump branch
 */
typedef void (*PTRJUMP)(void);

/* Entry Point */
uint32_t *u32Entry;

/****************************************************************************//**
 * @brief      UART auto-baudrate init
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void Drv_UartInit(void)
{
    volatile uint32_t u32Timeout = 0xffffffff;
    
    /* Enable UART Clock */
    CLOCK_EnableModule(UART0_MODULE);

    /* PINMUX Function setting */
    PIN_SetChannel(PIN_GPIO10, PIN_GPIO10_UART0_TXD);
    PIN_SetChannel(PIN_GPIO11, PIN_GPIO11_UART0_RXD);

    /* Disable UART Unit */
    UART_Disable(UART0);

    /* Auto-baud control setting */
    UART_SetBaudCountUpdateMethod(UART0, UART_BAUD_COUNT_UPDATE_BY_HARDWARE);

    UART_EnableAutoBaud(UART0);

    /* Word length select = 8-bit character, 1 stop bit */
    UART_SetDataBit(UART0, UART_8_DATA_BIT);

    /* UART unit enable */
    UART_Enable(UART0);

    /* Wait for auto-baud lock */
    while(UART_GetIntRawFlag(UART0, UART_INT_AUTOBAUD_LOCK) == 0)
    {
        if (u32Timeout-- == 0)
        {
            return;
        }
    }

    /* Close auto-baud detection */
    UART_DisableAutoBaud(UART0);
}




/****************************************************************************//**
 * @brief      Read data from UART
 *
 * @param[in]  pu8Buf   : Pointer to the buffer stores the data readed
 *             u32Count : The size of data to be readed
 *
 * @return     none
 *
 *******************************************************************************/
void Drv_UartRead(uint8_t* pu8Buf, uint32_t u32Count)
{
    volatile uint32_t i = 0;
    volatile uint32_t u32Timeout = 0xffffffff;

    for(i = 0; i < u32Count; i++)
    {
        u32Timeout = 0xffffffff;
        
        /* Wait until data is available in RBR or the FIFO */
        while (UART_GetStatus(UART0, UART_STS_RX_NOT_EMPTY) == 0U) 
        {
            if (u32Timeout-- == 0)
            {
                return;
            }
        }

        /* Read one byte data from UART peripheral */
        pu8Buf[i] = UART_ReadByte(UART0);
    }
}




/****************************************************************************//**
 * @brief      Write a byte data to the UART
 *
 * @param[in]  u8Data : Byte data to be written
 *
 * @return     none
 *
 *******************************************************************************/
void Drv_UartWriteByte(uint8_t u8Data)
{
    volatile uint32_t u32Timeout = 0xffffffff;
    
    /* Send byte data */
    UART_WriteByte(UART0, u8Data);

    /* Wait until transmitter empty */
    while (UART_GetStatus(UART0, UART_STS_TX_EMPTY) == 0U)
    {
        if (u32Timeout-- == 0)
        {
            return;
        }
    }
}




/****************************************************************************//**
 * @brief      Write data to UART
 *
 * @param[in]  pu8Buf   : Pointer to the buffer stores the data to be written
 *             u32Count : The size of data to be written
 *
 * @return     none
 *
 *******************************************************************************/
void Drv_UartWrite(uint8_t* pu8Buf, uint32_t u32Count)
{
    volatile uint32_t i = 0;
    volatile uint32_t u32Timeout = 0xffffffff;

    for(i = 0; i < u32Count; i++)
    {
        /* Send byte data */
        UART_WriteByte(UART0, pu8Buf[i]);
        
        u32Timeout = 0xffffffff;

        /* Wait until transmitter empty */
        while (UART_GetStatus(UART0, UART_STS_TX_EMPTY) == 0U)
        {
            if (u32Timeout-- == 0)
            {
                return;
            }
        }
    }
}




/****************************************************************************//**
 * @brief      Calculate the checksum of the specified array data
 *
 * @param[in]  pu8Buf       : Pointer to the byte array
 *             u32Size      : The byte array size
 *             u8OptionData : Optional byte data, if no, set 0x00
 *
 * @return     none
 *
 *******************************************************************************/
uint8_t Drv_CalculateChecksum(uint8_t *pu8Buf, uint32_t u32Size, uint8_t u8OptionData)
{
    /* Variable for loop */
    uint32_t i;

    /* Variable for checksum */
    uint8_t chkByte = 0xFF;

    /* Calculate checksum */
    chkByte ^= u8OptionData;

    for(i = 0; i < u32Size; i++)
    {
        chkByte ^= pu8Buf[i];
    }

    return chkByte;
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




/****************************************************************************//**
 * @brief      Load user application code from UART
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void IAP_LoadFromUart(void)
{
    /* Variable for loop */
    uint32_t i = 0;

    /* Temporary variable for checksum byte */
    uint8_t  u8TempChkByte = 0xFF;

    /* Temporary variable for address data */
    uint32_t u32TempAddr = 0;

    /* Temporary variable for size data */
    uint32_t u32TempSize = 0;
    
    FlashOperationStatus Status;
    
    volatile uint32_t u32Timeout = 0xffffffff;

    /* Enable Flash register write access */
    FLASHC_WALLOW();


    /******************************************************/
    /******************  Command Rountine  ****************/
    /******************************************************/
    while(u32Timeout != 0)
    {
        /* Receive command */
        Drv_UartRead(au8CmdData, 1);

        /* Command routine */
        switch(au8CmdData[0])
        {
        case CMD_WRITE_MEMORY:
            u32Timeout = 0xffffffff;
        
            /* Receive the start address and checksum */
            Drv_UartRead(au8SubCmdData, 5);

            /* Calculate checksum */
            u8TempChkByte = Drv_CalculateChecksum(au8SubCmdData, 4, au8CmdData[0]);

            /* Validate checksum */
            if(u8TempChkByte != au8SubCmdData[4])
            {
                /* Invalid checksum, Send NACK */
                Drv_UartWriteByte(0x1F);
                break;
            }

            /* Get the start address */
            u32TempAddr = Drv_ConvertToInt(au8SubCmdData, 4);

            /* Send ACK */
            Drv_UartWriteByte(0x79);


            /* Receive number of bytes to be written */
            Drv_UartRead(au8LenData, 1);

            /* Frame size */
            u32TempSize = au8LenData[0] + 1;

            /* Receive code data */
            Drv_UartRead(au8CodeData, u32TempSize);

            /* Receive checksum */
            Drv_UartRead(&u8ChecksumData, 1);

            /* Calculate checksum */
            u8TempChkByte = Drv_CalculateChecksum(au8CodeData, u32TempSize, au8LenData[0]);

            /* Validate frame checksum */
            if(u8TempChkByte != u8ChecksumData)
            {
                Drv_UartWriteByte(0x1F);
                break;
            }

            /* Validate address */
            if ((u32TempAddr & 0x7) != 0)
            {
                Drv_UartWriteByte(0x1F);
                break;
            }
            
            /* Validate size */
            if ((u32TempSize & 0x7) != 0)
            {
                Drv_UartWriteByte(0x1F);
                break;
            }
            
            /* Check address and Write data to the target memory */
            if((u32TempAddr >= FLASH_START_ADDR) && (u32TempAddr < FLASH_END_ADDR))
            {
                /* Program data to Flash */
                Status = pHWLIB->FLASHC_Program((uint32_t *)au8CodeData, u32TempAddr, u32TempSize / 4);
                if (Status != FLASH_OP_SUCCESS)
                {
                    Drv_UartWriteByte(0x1F);
                    break;
                }
            }
            else
            {
                /* Invalid memory address, send NACK */
                Drv_UartWriteByte(0x1F);
                break;
            }

            /* Send ACK */
            Drv_UartWriteByte(0x79);

            break;

        case CMD_ERASE:
            u32Timeout = 0xffffffff;
        
            /* Receive sub-command */
            Drv_UartRead(au8SubCmdData, 9);

            /* Calculate checksum */
            u8TempChkByte = Drv_CalculateChecksum(au8SubCmdData, 8, au8CmdData[0]);

            /* Validate checksum */
            if(u8TempChkByte != au8SubCmdData[8])
            {
                /* Invalid checksum, Send NACK */
                Drv_UartWriteByte(0x99);
                break;
            }

            /* Get the start address for erase */
            u32TempAddr = Drv_ConvertToInt(au8SubCmdData, 4);

            /* Get the erase area size */
            u32TempSize = Drv_ConvertToInt(au8SubCmdData + 4, 4);

            /* Validate address and size */
            if((u32TempAddr < FLASH_START_ADDR) || (u32TempAddr > FLASH_END_ADDR))
            {
                Drv_UartWriteByte(0x1F);
                break;
            }
            
            /* Validate address */
            if ((u32TempAddr & 0xfff) != 0)
            {
                Drv_UartWriteByte(0x1F);
                break;
            }

            /* Erase */
            for(i = u32TempAddr; i < (u32TempAddr + u32TempSize); i += FLASH_SECTOR_SIZE)
            {
                /* Erase sector, address Sector aligned */
                Status = pHWLIB->FLASHC_EraseSector(i);
                if (Status != FLASH_OP_SUCCESS)
                {
                    Drv_UartWriteByte(0x1F);
                    break;
                }
            }
            if (Status == FLASH_OP_SUCCESS)
            {
                /* Send ACK */
                Drv_UartWriteByte(0x79);
            }

            break;
            
        case CMD_GO:
            u32Timeout = 0xffffffff;
        
            /* Receive the jump address and checksum */
            Drv_UartRead( au8SubCmdData, 5U);

            /* Calculate checksum */
            u8TempChkByte = Drv_CalculateChecksum(au8SubCmdData, 4U, au8CmdData[0]);
        
            /* Validate checksum */
            if(u8TempChkByte != au8SubCmdData[4])
            {
                /* Invalid checksum, Send NACK */
                Drv_UartWriteByte( 0x1F);
                break;
            }

            /* Get the jump address */
            u32TempAddr = Drv_ConvertToInt(au8SubCmdData, 4U);

            /* Check the jump address */
            if(((u32TempAddr >= FLASH_START_ADDR) && (u32TempAddr < FLASH_END_ADDR)))
            {
                /* Set Entry Point */
                u32TempAddr += 4U;  /* Address of Reset Handler */
                u32Entry = (uint32_t *)(u32TempAddr);

                /* Send ACK */
                Drv_UartWriteByte( 0x79);

                /* Wait TXD pin finishing data transfer */
                while ((UART0->UARTSTS & UARTSTS_TXEMPTY_Msk) == UARTSTS_TXEMPTY_NOT_EMPTY)
                {
                }
                
                Delay_Ms(10);
                
                /* Jump to the address */
                ((PTRJUMP)(*u32Entry))();
            }

            /* Send NACK */
            Drv_UartWriteByte( 0x1F);
            
            break;

        default :
            break;
        }
        
        u32Timeout--;
    }
    
    /* Entry point */
    u32Entry = (uint32_t *)(0x1000F000 + 4);

    /* Jump to the application */
    ((PTRJUMP)(*u32Entry))();
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
