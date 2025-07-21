/**************************************************************************//**
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

#include <stdio.h>
#include "iap.h"

#if (defined(SPD1177) || defined(SPD1179B))
    #include "spd1177.h"
#elif defined(SPD1179)
    #include "spd1179.h"
#else
    #include "spc1169.h"
#endif

/**
 *  @brief Function pointer for jump branch
 */
typedef void (*PTRJUMP)(void);


/* Entry Point */
uint32_t *pu32Entry;




int main(void)
{
    uint32_t u32TimeOut;

    CLOCK_InitWithRCO(100000000);

    /* Delay Init */
    Delay_Init();


    /* UART Init */
    PIN_SetChannel(PIN_GPIO10, PIN_GPIO10_UART0_TXD);
    PIN_SetChannel(PIN_GPIO11, PIN_GPIO11_UART0_RXD);

    UART_Init(UART0, 38400);

    /* Wait for handshake byte with timeout 50ms */
    u32TimeOut = 50000;
    while(u32TimeOut--)
    {
        /* Check the received handshake byte (0x7F) */
        if(UART_GetStatus(UART0, UART_STS_RX_NOT_EMPTY))
        {

            if(UART0->UARTDAT == 0x7F)
            {
                /* Received correct handshake byte, return ACK */
                Drv_UartWriteByte(0x79);

                /* Enter application loading process */
                IAP_LoadFromUart();
            }
            else
            {
                /* Received wrong handshake byte, return NACK */
                Drv_UartWriteByte(0x1F);
            }
        }

        /* Delay 1us */
        Delay_Us(1);
    }


    printf("IAP Loader Jump to application ...\n");

    /* Entry point */
    pu32Entry = (uint32_t *)(0x1000F000 + 4);

    /* Jump to the application */
    ((PTRJUMP)(*pu32Entry))();


    while(1)
    {
    }
}

/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
