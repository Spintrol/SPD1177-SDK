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


uint32_t              u32PWMPeriod;         /* PWM Period*/
uint16_t              u16PREDRIID;          /* PRE-DRIVER mode ID */
uint16_t              u16Data;              /* Data */
ErrorStatus           eErrorState;
#define               Wake_Up_Mode          0
#define               ValueToTemperature(x)     ((4096 * (x) - 305657)/1081)

/*************************************************************************************************************************
 *
 * @brief      In this case, we use signal to wakeup the system from stop state.
 * @note       1, VDD5EXT over-current shut down protection must be enabled after VDD5EXT enabled, this operation has been
 *             showed in the code.
 * @note       2, If MCU over temperature 105 degrees Celsius, can not enter SYSTEM_Stop(), this operation has been showed 
 *             in the code.
 *
 *************************************************************************************************************************/
int main(void)
{
    int32_t * pi32TrimValue;
    int32_t i32Temperature;
    
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

    /* Enable VDD5EXT */
    eErrorState = EPWR_WriteRegisterField(HV_REG_PMUCTL, PMUCTL_VDD5EXTEN_Msk, 
    PMUCTL_VDD5EXTEN_ENABLE);
    if (eErrorState == ERROR)
    {
        printf("Write PMUCTL register FAIL\n");
        return 0;
    }
    
    Delay_Ms(5);
    
    /* Enable VDD5EXT over-current shut down protection */
    eErrorState = EPWR_WriteRegisterField(HV_REG_PMUCTL, PMUCTL_VDD5EXTPROTEN_Msk, 
    PMUCTL_VDD5EXTPROTEN_ENABLE);
    if (eErrorState == ERROR)
    {
        printf("Write PMUCTL register FAIL\n");
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
    /* Config pin as GPIO input */
    PIN_SetPinAsGPIO((PIN_NameEnum)PIN_GPIO9);
    GPIO_SetPinDir((PIN_NameEnum)PIN_GPIO9, GPIO_INPUT);

    /* Set GPIO number and active level */
    SYSTEM->GPIOWKUPCTL = (LOW << GPIOWKUPCTL_STOPWKUPPOL_Pos) |
                          (PIN_GPIO9  << GPIOWKUPCTL_STOPWKUPIO_Pos) |
                          GPIOWKUPCTL_STOPWKUPWE_ENABLE;
    
    printf("LIN or MON must be enabled, otherwise cyclic wake up can not be disabled\n");
    eErrorState = EPWR_WriteRegisterField(HV_REG_PMUCTL, 
                                         PMUCTL_LINWKUPEN_Msk | PMUCTL_MONWKUPEN_Msk , 
                                         PMUCTL_LINWKUPEN_DISABLE | PMUCTL_MONWKUPEN_ENABLE );
    if (eErrorState == ERROR)
    {
        printf("Write PMUCTL register FAIL\n");
        return 0;
    }
    
    printf("Enable cyclic sense wake up and disable cyclic wake up\n");
    eErrorState = EPWR_WriteRegisterField(HV_REG_PMUCTL, 
                                         PMUCTL_CYCSENWKUPEN_Msk | PMUCTL_CYCWKUPEN_Msk, 
                                         PMUCTL_CYCSENWKUPEN_ENABLE | PMUCTL_CYCWKUPEN_DISABLE);
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

    /* Disable VDD5EXT over-current shut down protection */
    eErrorState = EPWR_WriteRegisterField(HV_REG_PMUCTL, PMUCTL_VDD5EXTPROTEN_Msk, 
    PMUCTL_VDD5EXTPROTEN_DISABLE);
    if (eErrorState == ERROR)
    {
        printf("Write PMUCTL register FAIL\n");
        return 0;
    }

    /* Enable sleep/stop command */
    eErrorState = EPWR_WriteRegister(HV_REG_CTLKEY, KEY_PMU_CMD);
    if (eErrorState == ERROR)
    {
        printf("Write CTLKEY register FAIL\n");
        return 0;
    }

    /* Enable monitor MCU */
    SYSTEM_EnableMonitorItem(MONITOR_MCU_TEMPERATURE);
    ADC_EnableTSensor(ADC);
    /* Wait for sampling to end */
    Delay_Ms(500);
    
    /* TPMUOFFSET
     * TPMUGAIN
     * TLINOFFSET
     * TLINGAIN
     * TMCUOFFSET
     * TMCUGAIN   
     */
    pi32TrimValue = (int32_t *)0x11001168;
    
    /* The if branch is equivalent to the else branch, and the if branch is more accurate */
    if (pi32TrimValue[4] != 0xffffffff)
    {
        i32Temperature = ((pi32TrimValue[4] + pi32TrimValue[5] * SYSTEM->TMCUCODE )/65536);
    }
    else
    {
        i32Temperature = ((4096 * SYSTEM->TMCUCODE - 305657)/1081);    
    }
    
    /* If MCU over temperature 105 degrees Celsius, can not enter SYSTEM_Stop() */
    if (i32Temperature > 105)
    {
        printf("the MCU temperature is %d\n", i32Temperature);  
        return 0;
    }
    
    pHWLIB->SYSTEM_Stop();

    printf("total test passed\n");
    
    /* Read PMUCTL */
    eErrorState = EPWR_ReadRegister(HV_REG_PMUCTL, &u16Data);
    if (eErrorState == ERROR)
    {
        printf("Read PMUCTL register FAIL\n");
        return 0;
    }
    
    /* If VDD5EXT enabled */
    if (u16Data & PMUCTL_VDD5EXTEN_ENABLE)
    {
        /* HV parameter write enable */
        eErrorState = EPWR_WriteRegister(HV_REG_CTLKEY, KEY_USER_REG);
        if (eErrorState == ERROR)
        {
            printf("Write CTLKEY register FAIL\n");
            return 0;
        }
        
        Delay_Ms(5);
        
        /* Enable VDD5EXT over-current shut down protection */
        eErrorState = EPWR_WriteRegisterField(HV_REG_PMUCTL, PMUCTL_VDD5EXTPROTEN_Msk, 
        PMUCTL_VDD5EXTPROTEN_ENABLE);
        if (eErrorState == ERROR)
        {
            printf("Write PMUCTL register FAIL\n");
            return 0;
        }
    }

    while (1)
    {

    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/



