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
#define                  PWMPeriod(u32PWMFreqHz)           ((CLOCK_GetModuleClock(PWM_MODULE))/u32PWMFreqHz)/2;
#define                  PWM_FREQ                           20000                               /* 20kHz PWM */


uint32_t                u32PWMPeriod;


/*************************************************************************************************************************
 *
 * @brief      In this case, 40kHz waveform with 25% duty will be output through PWM1 A channel, bringing out by PWM up
 *             counting mode. We can measure this waveform with PIN_GPIO12.
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

    /* Init PWM1,PWM freq will be set as 20kHz in this function */
    PWM_InitSingleChannel(PWM1, PWM_CHA, PWM_FREQ);

    /* Configure PWM counter as up counting mode */
    PWM_SetCounterMode(PWM1, COUNT_UP);

    /*
    * The PWM counting mode is set to be up-down by default, as a result, we need
    * to re-config the AQCTLA register, which is used for controlling the PWM output
    * action when ZRO/CAU/PRD/CAD (for more information, please read the PWM application
    * note) event had happened.
    *
    * Key Point: the PWM freq will be double because of the ZRO/CAU/PRD/CAD event.
    */
    PWM_ActionQualifierCHA(PWM1, AQCTLAA_ZRO_SET_HIGH
                           | AQCTLAA_CAU_SET_LOW
                           | AQCTLAA_PRD_DO_NOTHING
                           | AQCTLAA_CAD_DO_NOTHING);

    /* Set PWM1A output 25% duty waveform */
    u32PWMPeriod = PWMPeriod(PWM_FREQ);
    PWM_SetCMPA(PWM1, (u32PWMPeriod * 1) / 4);

    /* Select PIN_GPIO12 as the channel A output of PWM1 */
    PIN_SetChannel(PIN_GPIO12, PIN_GPIO12_PWM1A);

    /* Start PWM1 */
    PWM_RunCounter(PWM1);

    while (1)
    {

    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
