/******************************************************************************
 * @file     uart.c
 * @brief    UART firmware functions.
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

#include "uart.h"




/******************************************************************************
 * @brief      Initializes the UART speed
 *
 * @param[in]  UARTx      :  Select the UART module
 * @param[in]  u32BaudRate:  Baud rate
 *
 * @return     none
 *
 ******************************************************************************/
void UART_InitSpeed(UART_REGS *UARTx, uint32_t u32BaudRate)
{
    uint32_t u32BaudCnt;

    /* Enable UART Clock */
    if (UARTx == UART0)
    {
        CLOCK_EnableModule(UART0_MODULE);
    }
    else
    {
        CLOCK_EnableModule(UART1_MODULE);
    }

    /* Calculate UART clock divisor */
    u32BaudCnt = (uint32_t)(CLOCK_GetModuleClock(UART0_MODULE) / u32BaudRate);

    /* Configure the baud count register */
    UART_SetBaudCount(UARTx, u32BaudCnt);
}




/******************************************************************************
 * @brief      Initializes the UART
 *
 * @param[in]  UARTx      :  Select the UART module
 * @param[in]  u32BaudRate:  Baud rate
 *
 * @return     none
 *
 ******************************************************************************/
void UART_Init(UART_REGS *UARTx, uint32_t u32BaudRate)
{
    UART_InitSpeed(UARTx, u32BaudRate);

    /* Configure UART control register (UARTCTL) */
    UARTx->UARTCTL = UARTCTL_RXEN_ENABLE              |
                     UARTCTL_TXEN_ENABLE              |
                     UARTCTL_RXDMAEN_DISABLE          |
                     UARTCTL_TXDMAEN_DISABLE          |
                     UARTCTL_LPBK_NORMAL_MODE         |
                     UARTCTL_BUS32_8BIT               |
                     UARTCTL_ABEN_DISABLE             |
                     UARTCTL_ABUP_UPDATE_BY_HW        |
                     UARTCTL_NRZMODE_NRZ_LEVEL        |
                     UARTCTL_DATABIT_8_DATA_BIT       |
                     UARTCTL_PRTYEN_PARITY_DISABLE    |
                     UARTCTL_STOPBIT_1_STOP_BIT;
}




/******************************************************************************
 * @brief      Wait UART auto baud ready
 *
 * @param[in]  UARTx      :  Select the UART module
 *
 * @return     ERROR or SUCCESS
 *
 ******************************************************************************/
ErrorStatus UART_WaitAutoBaudReady(UART_REGS *UARTx)
{
    // Wait auto baud locked
    while (UART_GetIntRawFlag(UARTx, UART_INT_AUTOBAUD_LOCK) == 0U)
    {}

    // Clear flag
    UART_ClearInt(UARTx, UART_INT_AUTOBAUD_LOCK);

    // Update baud counter for software update mode
    if (UART_BAUD_COUNT_UPDATE_BY_SOFTWARE
            == UART_GetBaudCountUpdateMethod(UARTx)
       )
    {
        UART_SetBaudCount(UARTx, UART_GetBaudCount(UARTx));
    }

    return SUCCESS;
}




/******************************************************************************
 * @brief      Initializes the LIN mode of UART
 *
 * @param[in]  UARTx      :  Select the UART module
 * @param[in]  eMode      :  LIN mode
 *                           Please refer to LIN_ModeEnum
 * @param[in]  u32BaudRate:  Baud rate
 *
 * @return     none
 *
 ******************************************************************************/
void LIN_Init(UART_REGS *UARTx, LIN_ModeEnum eMode, uint32_t u32BaudRate)
{
    UART_InitSpeed(UARTx, u32BaudRate);

    /* Configure UART control register (UARTCTL) */
    UARTx->UARTCTL = UARTCTL_RXDMAEN_DISABLE         |
                     UARTCTL_TXDMAEN_DISABLE         |
                     UARTCTL_LPBK_NORMAL_MODE        |
                     UARTCTL_BUS32_8BIT              |
                     UARTCTL_ABEN_ENABLE             |
                     UARTCTL_ABUP_UPDATE_BY_HW       |
                     UARTCTL_NRZMODE_NRZ_LEVEL       |
                     UARTCTL_DATABIT_8_DATA_BIT      |
                     UARTCTL_PRTYEN_PARITY_ENABLE    |
                     UARTCTL_STOPBIT_1_STOP_BIT;


    /* Configure LIN control register (LINCTL) */
    UARTx->LINCTL = LINCTL_LINEN_LIN_MODE         |
                    (eMode << LINCTL_MASTER_Pos)  |
                    LINCTL_SBRKLEN_13_BIT         |
                    LINCTL_SBRKDEL_1_BIT          |
                    LINCTL_RESP_RESPONSE_NONE     |
                    LINCTL_RESPLEN_X_BYTE         |
                    LINCTL_CHKSUM_ENHANCED_MODE   |
                    LINCTL_ATOTH_AUTO_THRESHOLD   |
                    LINCTL_ATXCHKSUM_MANUAL_TX;
                    
    SET_BITS(UARTx->UARTCTL, UARTCTL_RXEN_ENABLE | UARTCTL_TXEN_ENABLE);
}




/******************************************************************************
 * @brief      Writes the specified string to the UART peripheral
 *
 * @param[in]  UARTx  :  Select the UART module
 * @param[in]  pu8Text:  String message to be sent
 *
 * @return     none
 *
 ******************************************************************************/
void UART_WriteText(UART_REGS *UARTx, const uint8_t *pu8Text)
{
    while (*pu8Text)
    {
        /* Send one byte when transmiter fifo not full */
        if (UART_GetStatus(UARTx, UART_STS_TX_NOT_FULL) != 0U)
        {
            UART_WriteByte(UARTx, *(pu8Text++));
        }
    }

    /* Wait until transmiter empty */
    while (UART_GetStatus(UARTx, UART_STS_TX_EMPTY) == 0U)
    {
    }
}




/******************************************************************************
 * @brief      Writes a specified number of bytes to the UART peripheral
 *
 * @param[in]  UARTx    :  Select the UART module
 * @param[in]  pu8Buffer:  Byte array that contains the data to send
 * @param[in]  u32Offset:  Zero-based byte offset in the buffer parameter
                           at which to begin copying bytes to UART peripheral
 * @param[in]  u32Count :  Number of byte data to be sent
 *
 * @return     none
 *
 ******************************************************************************/
void UART_Write(UART_REGS *UARTx, uint8_t *pu8Buffer, uint32_t u32Offset,
                uint32_t u32Count
               )
{
    int32_t i;

    for (i = 0; i < u32Count;)
    {
        /* Send one byte when transmiter fifo not full */
        if (UART_GetStatus(UARTx, UART_STS_TX_NOT_FULL) != 0U)
        {
            UART_WriteByte(UARTx, (uint8_t)pu8Buffer[u32Offset + i]);
            ++i;
        }
    }

    /* Wait until transmiter empty */
    while (UART_GetStatus(UARTx, UART_STS_TX_EMPTY) == 0U)
    {
    }
}




/******************************************************************************
 * @brief      Reads a specified number of bytes from the UART peripheral
 *
 * @param[in]  UARTx    :  Select the UART module
 * @param[in]  pu8Buffer:  Byte array that contains the data to be read
 * @param[in]  u32Offset:  Offset in the buffer array to begin reading from
 * @param[in]  u32Count :  Number of byte data to be read
 *
 * @return     none
 *
 ******************************************************************************/
void UART_Read(UART_REGS *UARTx, uint8_t *pu8Buffer, uint32_t u32Offset,
               uint32_t u32Count
              )
{
    int32_t i;

    for (i = 0; i < u32Count;)
    {
        /* Read one byte when receiver fifo not empty */
        if (UART_GetStatus(UARTx, UART_STS_RX_NOT_EMPTY) != 0U)
        {
            pu8Buffer[u32Offset + i] = UART_ReadByte(UARTx);
            ++i;
        }
    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
