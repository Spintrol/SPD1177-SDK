/******************************************************************************
 * @file     main.c
 * @brief    Main program body
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
#include "spd1177.h"
#include <stdio.h>


#define              BAUDRATE              19200              /* LIN Rate */
#define              REFID                 0x01              /* REFID State */
#define              IDMASK                0x01              /* IDMASK State */
uint8_t              u8Id;                                   /* Receive Id */
uint16_t             u16PREDRIID;                            /* PRE-DRIVER mode ID */
ErrorStatus          eErrorState;                            /* Function State */
uint16_t             i;                                      /* Print Num */
volatile uint8_t     u8Rxd[9];                               /* RX Data */
volatile uint8_t     state                 = 0;

/*************************************************************************************************************************
 *
 * @brief      In this case, the LIN slave receive the data from master.
 *
 *        Key_points:
 *                  (1)First start the slave code to wait the master code to send data.
 *
 *************************************************************************************************************************/


int main(void)
{
    CLOCK_InitWithRCO(100000000);

    Delay_Init();

    /*
     * Init the UART
     */
    PIN_SetChannel(PIN_GPIO10, PIN_GPIO10_UART0_TXD);
    PIN_SetChannel(PIN_GPIO11, PIN_GPIO11_UART0_RXD);
    UART_Init(UART0, 38400);

    printf("Enter the test\n");

    /* HV reset */
    eErrorState = HV_Reset();
    if (eErrorState == ERROR)
    {
        printf("HV_Reset FAIL\n");
        return 0;
    }
    else
    {
        printf("HV_Reset SUCCESS\n");
    }

    /* HV init */
    eErrorState = HV_Init(&u16PREDRIID);
    if (eErrorState == ERROR)
    {
        printf("Init HV mode FAIL\n");
        return 0;
    }
    else
    {
        printf("Init HV mode SUCCESS[ID:%d]\n", u16PREDRIID);
    }

    /* HV parameter write enable */
    eErrorState = EPWR_WriteRegister(HV_REG_CTLKEY, KEY_USER_REG);
    if (eErrorState == ERROR)
    {
        printf("Write CTLKEY register FAIL\n");
        return 0;
    }

    /*
    Init LIN parameter
    */
    eErrorState = EPWR_WriteRegisterField(HV_REG_LINCTL, LINCTL_RLOAD_Msk | LINCTL_TXEN_Msk | LINCTL_EN_Msk, LINCTL_RLOAD_938_OHM | LINCTL_TXEN_ENABLE | LINCTL_EN_ENABLE);
    if (eErrorState == ERROR)
    {
        printf("EPWR_WriteRegisterField FAIL\n");
        return 0;
    }
    
    eErrorState = EPWR_WriteRegisterField(HV_REG_LINTXSCTL, LINTXSCTL_ISTEP_Msk , ((BAUDRATE << 1) / 1000) << LINTXSCTL_ISTEP_Pos);
    if (eErrorState == ERROR)
    {
        printf("EPWR_WriteRegisterField FAIL\n");
        return 0;
    }
    
    /* LIN_Init */
    PIN_SetChannel(PIN_GPIO25, PIN_GPIO25_UART1_TXD);
    PIN_SetChannel(PIN_GPIO26, PIN_GPIO26_UART1_RXD);
    LIN_Init(UART1, LIN_SLAVE, BAUDRATE);
    
    UART_SetRxFIFOThreshold(UART1, LIN_RESPONSE_8_BYTE);

    /* Enable the RX time out INT */
    UART_EnableInt(UART1, UART_INT_LIN_ID_MATCH | UART_INT_RX_REQ | UART_INT_RX_TIMEOUT | UART_INT_RX_FRAME_ERROR | UART_INT_LIN_BIT_ERROR | UART_INT_AUTOBAUD_LOCK);

    /* Enable UART1_IRQn trigger INT in MCU side */
    NVIC_EnableIRQ(UART1_IRQn);

    /* Set the id filter */
    LIN_SetIDFilter(UART1, REFID, IDMASK);

    while (1)
    {
        /* Init state */
        state = 0;
        
        /* Wait until leave RX_REQ */
        while (state == 0)
        {
        }
        
        for (i = 0; i < LIN_RESPONSE_8_BYTE + 1; i++)
        {
            printf("u8Rxd[%d] is %x\n", i, u8Rxd[i]);
        }
    }
}


void UART1_IRQHandler(void)
{
    if (UART_GetIntFlag(UART1, UART_INT_LIN_ID_MATCH) != 0)
    {
        /* Get the id */
        u8Id = LIN_GetRxID(UART1);

        u8Id = u8Id & 0x3F;
        
        /* Set the check mode */
        LIN_SetCheckSumMode(UART1, LIN_ENHANCED_CHECKSUM);

        /* Set the respond mode */
        LIN_SetResponse(UART1, LIN_RESPONSE_RX);

        /* Set the respond lenth */
        LIN_SetResponseLen(UART1, LIN_RESPONSE_8_BYTE);

        /* Clear the start signal flag */
        UART_ClearInt(UART1, UART_INT_LIN_ID_MATCH);
    }
    else if (UART_GetIntFlag(UART1, UART_INT_RX_REQ) != 0)
    {
        for (i = 0; i < LIN_RESPONSE_8_BYTE + 1; i++)
        {
            u8Rxd[i] = UART_ReadByte(UART1);
        }
        
        /* When communication finished, should revert LIN to none response */
        LIN_SetResponse(UART1, LIN_RESPONSE_NONE);
        
        state = 1;
        
        /* Clear the start signal flag */
        UART_ClearInt(UART1, UART_INT_RX_REQ);
    }
    /* GetRxTimeoutIntFlag */
    else if (UART_GetIntFlag(UART1, UART_INT_RX_TIMEOUT) != 0)
    {
        printf("LIN Rx Time out\n");
        UART_ClearInt(UART1, UART_INT_RX_TIMEOUT);
    }
    /* GetRxStopbitErrorIntFlag */
    else if (UART_GetIntFlag(UART1, UART_INT_RX_FRAME_ERROR) != 0)
    {
        printf("LIN Rx Stop bit error\n");
        UART_ClearInt(UART1, UART_INT_RX_FRAME_ERROR);
    }
    /* GetTxBitErrorIntFlag */
    else if (UART_GetIntFlag(UART1, UART_INT_LIN_BIT_ERROR) != 0)
    {
        printf("LIN Tx bit error\n");
        UART_ClearInt(UART1, UART_INT_LIN_BIT_ERROR);
    }
    /* GetAutobaudlockFlag */
    if (UART_GetIntFlag(UART1, UART_INT_AUTOBAUD_LOCK) != 0)
    {
        /* The BaudCount must be set once again */
        UART_SetBaudCount(UART1, UART_GetBaudCount(UART1));
        
        UART_ClearInt(UART1, UART_INT_AUTOBAUD_LOCK);
    }
    UART_ClearInt(UART1, UART_INT_ALL);
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
