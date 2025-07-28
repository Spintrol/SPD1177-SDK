/******************************************************************************
 * @file     main.c
 * @brief    Main program body
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
#include <stdio.h>

#if defined(SPD1179)
    #include "spd1179.h"
#else
    #include "spc1169.h"
#endif


uint8_t             u8Data;                            /* Receive data */


/*************************************************************************************************************************
 *
 * @brief      In this case, UART read data using INT model, when there is one byte in the receive FIFO, the RX INT will be
 *             triggered, then, the data will be receive in the INT function.
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

    /* Set the receive fifo INT triger level at least 2 byte */
    UART_SetRxFIFOThreshold(UART0, 1);

    /* Enable data reaching INT */
    UART_EnableInt(UART0, UART_INT_RX_REQ);

    /* Enable the Gloable INT of UART */
    NVIC_EnableIRQ(UART0_IRQn);

    while (1)
    {

    }
}


void UART0_IRQHandler(void)
{
    printf("Enter the int\n");
    /* Read data until the receive FIFO is empty */
    while (UART_GetRxFIFOLevel(UART0))
    {
        u8Data = UART_ReadByte(UART0) - '0';
        printf("Rece data(0~10): %d\n", u8Data);
    }

    UART_ClearInt(UART0, UART_INT_ALL);
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
