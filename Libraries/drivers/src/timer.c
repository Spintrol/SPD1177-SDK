/******************************************************************************
 * @file     timer.c
 * @brief    TIMER firmware functions.
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

#include "timer.h"




/******************************************************************************
 * @brief      Initialize the timer
 *
 * @param[in]  TIMERx          :  Select the timer module
 * @param[in]  u32TimerPeriodMs:  Timer interrupt period (ms)
 *
 * @return     none
 *
 ******************************************************************************/
void TIMER_Init(TIMER_REGS *TIMERx, uint32_t u32TimerPeriodMs)
{
    uint32_t u32TimerClk;

    /* Enable and Get Timer module clock */
    if (TIMERx == TIMER0)
    {
        CLOCK_EnableModule(TIMER0_MODULE);

        u32TimerClk = CLOCK_GetModuleClock(TIMER0_MODULE);
    }
    else if (TIMERx == TIMER1)
    {
        CLOCK_EnableModule(TIMER1_MODULE);

        u32TimerClk = CLOCK_GetModuleClock(TIMER1_MODULE);
    }
    else
    {
        CLOCK_EnableModule(TIMER2_MODULE);

        u32TimerClk = CLOCK_GetModuleClock(TIMER2_MODULE);
    }

    /* Set timer mode */
    TIMER_SetMode(TIMERx, TIMER_GENERAL_TIMER);

    /* Set reload timer while timer reaches 0 */
    TIMER_SetReloadValue(TIMERx, CLOCK_MsToCounter(u32TimerPeriodMs, u32TimerClk));

    /* Enable Timer interrupt */
    TIMER_EnableInt(TIMERx);

    /* Enable Timer */
//  TIMER_Enable(TIMERx);
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
