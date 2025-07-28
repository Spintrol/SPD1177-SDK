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

uint16_t              u16PREDRIID;                                                                /* PRE-DRIVER mode ID */
int32_t               a[128];
uint32_t              i;
/*************************************************************************************************************************
 *
 * @brief      In this case, print system voltage.
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

    #if defined(SPD1179)
    /* HV init */
    HV_Init(&u16PREDRIID);

    /* HV parameter write enable */
    EPWR_WriteRegister(HV_REG_CTLKEY, KEY_USER_REG);

    /* Before test VCP temperature, power up PRE-DRIVER mode*/
    EPWR_WriteRegisterField(HV_REG_PDRVCTL0, PDRVCTL0_EN_Msk, PDRVCTL0_EN_ENABLE);

    /* Enable all items */
    SYSTEM_EnableMonitorItem(MONITOR_ALL);
    
    SYSTEM_SetMonitorThreshold(MONITOR_HV_VBAT, 10000, 14000);
    SYSTEM_SetMonitorThreshold(MONITOR_HV_LIN_TEMPERATURE, 30, 70);
    SYSTEM_SetMonitorThreshold(MONITOR_HV_PMU_TEMPERATURE, 30, 70);
 
    SYSTEM_EnableNonMaskableInt(NMI_EVENT_HV_VBAT_ERROR
                                |NMI_EVENT_HV_LIN_TEMPERATURE_ERROR
                                |NMI_EVENT_HV_PMU_TEMPERATURE_ERROR);
    #else
    /* Enable VDD12, VDD33, MCU items */
    SYSTEM_EnableMonitorItem(MONITOR_VDD12 | MONITOR_VDD33 | MONITOR_MCU_TEMPERATURE);
    
    SYSTEM_SetMonitorThreshold(MONITOR_MCU_TEMPERATURE, 30, 50);
    SYSTEM_EnableNonMaskableInt(NMI_EVENT_LV_TEMPERATURE_ERROR);
    #endif

    /* Before test ADCREF13 temperature, Power up ADC */
    ADC_PowerUp(ADC);

    /* Before test MCU temperature, enable TSensor */
    ADC_EnableTSensor(ADC);
    
    pHWLIB->FLASHC_Read((uint32_t *)a, 0x11001168, 6);
    
    /* TPMUOFFSET
       TPMUGAIN
       TLINOFFSET
       TLINGAIN
       TMCUOFFSET
       TMCUGAIN   */
    for (i = 0; i < 6; i++)
    {
        printf("%x, %d\n", a[i], i);
    }
 
    while (1)
    {
        Delay_Ms(500);

        printf("the VDD12 voltage is %2.3f\n", ((float)(SYSTEM->VDD12CODE)) / 1120);

        printf("the VDD33 voltage is %2.3f\n", ((float)(SYSTEM->VDD33CODE)) / 1120);
        
        if (a[4] != 0xffffffff)
        {
            printf("the MCU temperature is %d\n", ((a[4] + a[5] * SYSTEM->TMCUCODE )/65536));  
        }
        else
        {
            printf("the MCU temperature is %d\n", ((4096 * SYSTEM->TMCUCODE - 305657)/1081));            
        }

        
        #if defined(SPD1179)
        if (a[2] != 0xffffffff)
        {
            printf("the HV block LIN PHY temperature is %d\n", ((a[2] + a[3] * SYSTEM->TLINCODE)/65536));
        }
        else
        {
            printf("the HV block LIN PHY temperature is %d\n", ((26549-32* SYSTEM->TLINCODE)/69));
        }

        if (a[0] != 0xffffffff)
        {
            printf("the HV block PMU temperature is %d\n", ((a[0] + a[1] * SYSTEM->TPMUCODE)/65536));
        }
        else
        {
            printf("the HV block PMU temperature is %d\n", ((13125-16*SYSTEM->TPMUCODE)/33));
        }

        
        printf("the VBAT voltage is %2.3f\n", ((float)(SYSTEM->VBATCODE)) / 1120 * 13);
        
        #endif
    }
}

void NMI_Handler()
{
    if (SYSTEM_GetNonMaskableIntFlag(NMI_EVENT_HV_VBAT_ERROR) != 0)
    {
        printf("NMI_EVENT_HV_VBAT_ERROR\n");
        SYSTEM_ClearNonMaskableInt(NMI_EVENT_HV_VBAT_ERROR);
    }
    if (SYSTEM_GetNonMaskableIntFlag(NMI_EVENT_HV_LIN_TEMPERATURE_ERROR) != 0)
    {
        printf("NMI_EVENT_HV_LIN_TEMPERATURE_ERROR\n");
        SYSTEM_ClearNonMaskableInt(NMI_EVENT_HV_LIN_TEMPERATURE_ERROR);
    }
    if (SYSTEM_GetNonMaskableIntFlag(NMI_EVENT_HV_PMU_TEMPERATURE_ERROR) != 0)
    {
        printf("NMI_EVENT_HV_PMU_TEMPERATURE_ERROR\n");
        SYSTEM_ClearNonMaskableInt(NMI_EVENT_HV_PMU_TEMPERATURE_ERROR);
    }
    if (SYSTEM_GetNonMaskableIntFlag(NMI_EVENT_LV_TEMPERATURE_ERROR) != 0)
    {
        printf("NMI_EVENT_LV_TEMPERATURE_ERROR\n");
        SYSTEM_ClearNonMaskableInt(NMI_EVENT_LV_TEMPERATURE_ERROR);
    }
    
    /* Clear INT */
    SYSTEM_ClearNonMaskableInt(NMI_EVENT_GLOBAL);
}

/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
