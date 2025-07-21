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
#include <stdio.h>

#if (defined(SPD1177) || defined(SPD1179B))
    #include "spd1177.h"
#elif defined(SPD1179)
    #include "spd1179.h"
#else
    #include "spc1169.h"
#endif


#define            OffsetADDRInFlash                  0xF000
#define            FlashBaseADDR                      0x10000000
#define            OperationADDR                      (FlashBaseADDR + OffsetADDRInFlash)
#define            OperationLEN                       0x400


FlashOperationStatus        status;
uint32_t                    au32Buf[OperationLEN];
uint32_t                    i;


void Flash_Operation(void)
{
    /* Erase flash sector */
    pHWLIB->FLASHC_EraseSector(OperationADDR);

    /* Read from the flash, to check if the flash erased success or not */
    pHWLIB->FLASHC_VerifyRead(au32Buf, OperationADDR, OperationLEN);

    for (i = 0; i < OperationLEN; i++)
    {
        if (au32Buf[i] == 0xFFFFFFFF)
        {
            ;
        }
        else
        {
            printf("Erase flash fail\n");
            return;
        }
    }
    printf("Erase flash success\n");

    /* Generate the data need to be write to flash */
    for (i = 0; i < OperationLEN; i++)
    {
        au32Buf[i] = (i % 55);
    }
    /* Write data to flash */
    status = pHWLIB->FLASHC_Program(au32Buf, OperationADDR, OperationLEN);

    if (status != FLASH_OP_SUCCESS)
    {
        printf("Write to flash ERROR\n");
        return;
    }
    else
    {
        printf("Write flash success\n");
    }
}


/*************************************************************************************************************************
 *
 * @brief      In this case, show the flash operation
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
    
    pHWLIB->FLASHC_Init();
    
    pHWLIB->FLASHC_SetTiming(100000000);
    
    printf("Flash is working at 100MHz, and Start to do something with flash...\n");
    Flash_Operation();
    
    /* Wait printf in Flash_Operation finish */
    Delay_Ms(10);

    /* Change the HCLK to 50MHz */
    CLOCK_InitWithRCO(CLOCK_CPU_50MHZ);
    
    Delay_Init();
    
    UART_Init(UART0, 38400);
    
    pHWLIB->FLASHC_SetTiming(CLOCK_CPU_50MHZ);

    printf("Flash is working at 50MHz, and Start to do something with flash...\n");
    Flash_Operation();

    while (1)
    {

    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
