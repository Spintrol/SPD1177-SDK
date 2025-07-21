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

/*************************************************************************************************************************
 *
 * @brief      In this case, print VDD33 over-voltage and VDD33 under-voltage event.
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

    /* Set the BOD of VDD33UV */
    POWER_SetVDD33UVThreshold(BOD_VDD33UV_3dot03_V, BOD_VDD33UV_3dot12_V);

    /* Set the BOD of VDD33OV */
    POWER_SetVDD33OVThreshold(BOD_VDD33OV_3dot66_V, BOD_VDD33OV_3dot53_V);

    /* Enable VDD33 over-voltage and VDD33 under-voltage Int */
    SYSTEM_EnableNonMaskableInt(NMI_EVENT_VDD33UV | NMI_EVENT_VDD33OV);

    while (1)
    {

    }
}


void NMI_Handler(void)
{
    printf("NMI_Handler\n");

    /* Get VDD33OV flag */
    if (SYSTEM_GetNonMaskableIntFlag(NMI_EVENT_VDD33OV) != 0)
    {
        printf("VDD33 over-voltage interrupt\n");
    }
    /* Get VDD33UV flag */
    else if (SYSTEM_GetNonMaskableIntFlag(NMI_EVENT_VDD33UV) != 0)
    {
        printf("VDD33 under-voltage interrupt\n");
    }

    /* To avoid printf too fast */
    Delay_Ms(500);

    /* Clear VDD33 over-voltage and VDD33 under-voltage Int flag */
    SYSTEM_ClearNonMaskableInt(NMI_EVENT_VDD33UV | NMI_EVENT_VDD33OV);

    /* Clear NMI Int */
    SYSTEM_ClearNonMaskableInt(NMI_EVENT_GLOBAL);
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
