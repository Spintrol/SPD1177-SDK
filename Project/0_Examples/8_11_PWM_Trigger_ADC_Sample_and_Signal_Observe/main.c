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


/* This macro is used to get the PWM period with a specified frequency */
#define              PWMPeriod(u32PWMFreqHz)              ((CLOCK_GetModuleClock(PWM_MODULE))/u32PWMFreqHz)/2;
#define              PWM_FREQ                             2000                                /* 2kHz PWM */
#define              PWM_DB_NS                            100                                /* 100ns */


uint32_t             u32PWMPeriod;
int32_t              i32Result;
uint32_t             u32Count                             = 0;


/*************************************************************************************************************************
 *
 * @brief      In this case, PWM0SOCA trigger the ADC0 event
 *
 *        Key_points:
 *                  (1)if you want to observe the trigger signal, do not use the J-LINK download the code, because the
 *        observe PIN_GPIO18 will be occupied by J-LINK SWCK/TCLK
 *
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

    /* Select the channel A/B output of PWM0 respectively */
    PIN_SetChannel(PIN_GPIO19, PIN_GPIO19_PWM0A);
    PIN_SetChannel(PIN_GPIO22, PIN_GPIO22_PWM0B);

    /* set the GPIO to observe the SYNC signal*/
    PIN_SetChannel(PIN_GPIO18, PIN_GPIO18_PWMSOCO);

    /* Initial Basic Complementary PWM */
    PWM_InitComplementaryPairChannel(PWM0, PWM_FREQ, PWM_DB_NS);

    /* Enable PWM0SOCA output to the pin */
    PWMCFG->SOCAOCTL = (PWMCFG->SOCAOCTL & (~SOCAOCTL_SOCA0EN_Msk)) | SOCAOCTL_SOCA0EN_ENABLE;

    /* Set pulse duration of PWMSOCA output to the pin */
    PWMCFG->SOCAOCTL = (PWMCFG->SOCAOCTL & (~SOCAOCTL_DURATION_Msk)) | SOCAOCTL_DURATION_32_PWM_CLK;


    /* Set PWM0A output 25% duty waveform */
    u32PWMPeriod = PWMPeriod(PWM_FREQ);
    PWM_SetCMPA(PWM0, (u32PWMPeriod * 3) / 4);

    /* Start counting */
    PWM_RunCounter(PWM0);

    /* PWM trigger timing selecting */
    PWM_SetSOCATiming(PWM0, EQU_ZERO);

    /* PWM trigger period selecting */
    PWM_SetSOCAPeriod(PWM0, ON_1ST_EVENT);

    /* Enable PWM SOCA trigger */
    PWM_EnableSOCA(PWM0);

    /* ADC initial */
    ADC_EasyInit1(ADC, ADC_CH0, PIN_GPIO0, ADC_SOC_TRIGGER_FROM_PWM0SOCA);
    ADC_EasyInit1(ADC, ADC_CH1, PIN_GPIO2, ADC_SOC_TRIGGER_FROM_PWM0SOCA);
    ADC_EasyInit1(ADC, ADC_CH2, PIN_GPIO4, ADC_SOC_TRIGGER_FROM_PWM0SOCA);

    /* SOC0 averaging 4 times */
    ADC_SetChannelResultAverageCount(ADC, ADC_CH0, ADC_AVERAGE_COUNT_4);
    ADC_SetChannelResultAverageCount(ADC, ADC_CH1, ADC_AVERAGE_COUNT_4);
    ADC_SetChannelResultAverageCount(ADC, ADC_CH2, ADC_AVERAGE_COUNT_4);

    /* INT service routine configuration */
    NVIC_SetPriority(ADCCH0_IRQn, 1);
    NVIC_EnableIRQ(ADCCH0_IRQn);

    while (1)
    {

    }
}


void ADCCH0_IRQHandler(void)
{
    /* The result */
    if (u32Count >= 15)
    {
        printf("CH0 %d\n", ADC_GetChannelResult(ADC, ADC_CH0));
        printf("CH1 %d\n", ADC_GetChannelResult(ADC, ADC_CH1));
        printf("CH2 %d\n", ADC_GetChannelResult(ADC, ADC_CH2));
        u32Count = 0;
    }

    u32Count++;

    /* Clear ADC SOC0 INT flag */
    ADC_ClearChannelInt(ADC, ADC_CH0);
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
