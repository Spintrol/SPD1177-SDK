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

#include "spd1179.h"
#include <stdio.h>


uint32_t              u32PWMPeriod;         /* PWM Period*/
uint16_t              u16PREDRIID;          /* PRE-DRIVER mode ID */
uint32_t              u32TemVale;           /* Temperature Code */
uint32_t              u32Temperature;       /* MCU Temperature */
ErrorStatus           eErrorState;
#define               Wake_Up_Mode          0
#define               ValueToTemperature(x)     ((4096 * (x) - 305657)/1081)

/*************************************************************************************************************************
 *
 * @brief      In this case, we use signal to wakeup the system from stop state.
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

    /* HV init */
    eErrorState = HV_Init(&u16PREDRIID);
    if (eErrorState == ERROR)
    {
        printf("Init PRE-DRIVER mode FAIL\n");
        return 0;
    }
    else
    {
        printf("Init PRE-DRIVER mode SUCCESS[ID:%d]\n", u16PREDRIID);
    }

    /* HV parameter write enable */
    eErrorState = EPWR_WriteRegister(HV_REG_CTLKEY, KEY_USER_REG);
    if (eErrorState == ERROR)
    {
        printf("Write CTLKEY register FAIL\n");
        return 0;
    }

    /* LIN wake up setting */
    #if(Wake_Up_Mode == 0)
    eErrorState = EPWR_WriteRegisterField(HV_REG_PMUCTL, PMUCTL_LINWKUPEN_Msk | 
      PMUCTL_CYCWKUPEN_Msk, PMUCTL_LINWKUPEN_ENABLE | PMUCTL_CYCWKUPEN_DISABLE);
    if (eErrorState == ERROR)
    {
        printf("Write PMUCTL register FAIL\n");
        return 0;
    }
    
    /* MON asynchronous wake up setting */
    #elif(Wake_Up_Mode == 1)
    eErrorState = EPWR_WriteRegisterField(HV_REG_PMUCTL, PMUCTL_MONWKUPEN_Msk |
                                    PMUCTL_LINWKUPEN_Msk | PMUCTL_CYCWKUPEN_Msk,
                                    PMUCTL_MONWKUPEN_ENABLE | PMUCTL_LINWKUPEN_DISABLE |
                                    PMUCTL_CYCWKUPEN_DISABLE);
    if (eErrorState == ERROR)
    {
        printf("Write PMUCTL register FAIL\n");
        return 0;
    }

    /* Wakeup level is high, MON pin need pull down */
    eErrorState = EPWR_WriteRegisterField(HV_REG_MONCTL, MONCTL_WKUPPOL_Msk |
                               MONCTL_EN_Msk | MONCTL_PULLMODE_Msk,
                               MONCTL_WKUPPOL_ACTIVE_HIGH | MONCTL_EN_ENABLE |
                               MONCTL_PULLMODE_PULL_DOWN);
    if (eErrorState == ERROR)
    {
        printf("Write MONCTL register FAIL\n");
        return 0;
    }

    /* Cyclic wake up setting */
    #elif(Wake_Up_Mode == 2)
    eErrorState = EPWR_WriteRegisterField(HV_REG_PMUCTL, PMUCTL_CYCWKUPEN_Msk |
                                          PMUCTL_LINWKUPEN_Msk, PMUCTL_CYCWKUPEN_ENABLE |
                                          PMUCTL_LINWKUPEN_DISABLE);
    if (eErrorState == ERROR)
    {
        printf("Write PMUCTL register FAIL\n");
        return 0;
    }
    
    /* Dead time is (DEADCNT+1) * 2ms */
    eErrorState = EPWR_WriteRegisterField(HV_REG_CYCWKUPCTL, CYCWKUPCTL_DEADCNT_Msk, CYCWKUPCTL_DEADCNT_(5));
    if (eErrorState == ERROR)
    {
        printf("Write CYCWKUPCTL register FAIL\n");
        return 0;
    }
    
    /* Cyclic sense wake up setting */
    #elif(Wake_Up_Mode == 3)
    /* Use GPIO9 as the wake up source */
    SYSTEM_SetStopWakeUpByGPIO(PIN_GPIO9, LOW);
    
    eErrorState = EPWR_WriteRegisterField(HV_REG_PMUCTL, PMUCTL_CYCSENWKUPEN_Msk |
                        PMUCTL_LINWKUPEN_Msk | PMUCTL_CYCWKUPEN_Msk, 
                        PMUCTL_CYCSENWKUPEN_ENABLE | PMUCTL_LINWKUPEN_DISABLE |
                        PMUCTL_CYCWKUPEN_DISABLE);
    if (eErrorState == ERROR)
    {
        printf("Write PMUCTL register FAIL\n");
        return 0;
    }
    /* Dead time is (DEADCNT+1) * 2ms, sense window is (SENSECNT+1) * 10us */
    eErrorState = EPWR_WriteRegisterField(HV_REG_CYCSENSECTL, CYCSENSECTL_DEADCNT_Msk | \
            CYCSENSECTL_SENSECNT_Msk, CYCSENSECTL_DEADCNT_(10) | CYCSENSECTL_SENSECNT_(15));
    if (eErrorState == ERROR)
    {
        printf("Write CYCSENSECTL register FAIL\n");
        return 0;
    }
    #endif

    /* Enable sleep/stop command */
    eErrorState = EPWR_WriteRegister(HV_REG_CTLKEY, KEY_PMU_CMD);
    if (eErrorState == ERROR)
    {
        printf("Write CTLKEY register FAIL\n");
        return 0;
    }

    /* Before test VCP temperature, power up PRE-DRIVER mode*/
    eErrorState = EPWR_WriteRegisterField(HV_REG_PDRVCTL0, PDRVCTL0_EN_Msk, PDRVCTL0_EN_ENABLE);
    if (eErrorState == ERROR)
    {
        printf("Write PDRVCTL0 register FAIL\n");
        return 0;
    }

    /* Enable Monitor LV MCU temperature */
    SYSTEM_EnableMonitorItem(MONITOR_MCU_TEMPERATURE);

    /* Before test ADCREF13 temperature, Power up ADC */
    ADC_PowerUp(ADC);

    /* Before test MCU temperature, enable TSensor */
    ADC_EnableTSensor(ADC);

    /* Wait for ADC sample temperature data */
    Delay_Ms(1000);

    /* Get MCU temperature */
    u32TemVale = SYSTEM_GetTMCUMonitorValue();
    u32Temperature = ValueToTemperature(u32TemVale);

    /* STOP mode work temperature range is -40 Celsius to 105 Celsius*/
    if (u32Temperature > 100)
    {
        printf("Work temperature greater than 100 Celsius\n");
        return 0;
    }

    pHWLIB->SYSTEM_Stop();

    printf("total test passed\n");
    
    while (1)
    {

    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/



