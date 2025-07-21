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


ErrorStatus Status;


/*************************************************************************************************************************
 *
 * @brief      In this case, we suppose the PLL clock is 100MHz, but set the PLL clock at 75MHz. Then use the RCO0 to detect
 *              if PLL clock is around 100MHz.
 *
 *************************************************************************************************************************/


int main(void)
{
    CLOCK_InitWithRCO(CLOCK_CPU_32MHZ);

    Delay_Init();

    /*
     * Init the UART
     */
    PIN_SetChannel(PIN_GPIO10, PIN_GPIO10_UART0_TXD);
    PIN_SetChannel(PIN_GPIO11, PIN_GPIO11_UART0_RXD);
    UART_Init(UART0, 38400);

    printf("Enter the test\n");

    /* Configure PLL clock */
    Status = CLOCK_ConfigurePLL(0, __RCO_CLOCK, CLOCK_CPU_75MHZ);
    if (Status == SUCCESS)
    {
        printf("the PLL initial success\n");
    }
    else
    {
        printf("the PLL initial failed\n");
    }

    /* Enable clock error Int */
    SYSTEM_EnableNonMaskableInt(NMI_EVENT_CLK_DETECT_ERROR);

    /* Initialize the clock detection */
    Status = CLOCK_DetectionInit(CLOCK_FROM_RCO, CLOCK_CPU_32MHZ, CLOCK_FROM_PLL, 100000000, 1);
    if (Status == SUCCESS)
    {
        printf("the PLL detect set success\n");
    }
    else
    {
        printf("the PLL detect set failed\n");
    }

    while (1)
    {

    }
}


void NMI_Handler(void)
{
    printf("NMI_Handler\n");
    if (SYSTEM_GetNonMaskableIntFlag(NMI_EVENT_CLK_DETECT_ERROR) != 0)
    {
        printf("CLKDETERR interrupt\n");
    }

    /* Clear PLL UNLOCK Int */
    SYSTEM_ClearNonMaskableInt(NMI_EVENT_CLK_DETECT_ERROR);

    /* Clear NMI Int */
    SYSTEM_ClearNonMaskableInt(NMI_EVENT_GLOBAL);
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
