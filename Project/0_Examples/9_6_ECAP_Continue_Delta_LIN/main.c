/******************************************************************************
 * @file     main.c
 * @brief    Main program body
 * @version  V1.0.0
 * @date     30-Apr-2020
 *
 * @note
 * Copyright (C) [2014-2020] Spintrol Limited Corporation. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING 
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE 
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE 
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/

#if defined(SPD1179)
    #include "spd1179.h"
#else
    #include "spc1169.h"
#endif

#include <stdio.h>



uint32_t TStamp0, TStamp1, TStamp2, TStamp3;

/*usd the count to calculate the period*/
#define CNTTOFREQ(x) (CLOCK_GetModuleClock(ECAP_MODULE) / (x))


uint16_t    u16PREDRIID;                    /* PRE-DRIVER mode ID */
ErrorStatus eErrorState;                    /* Function State     */




/*************************************************************************************************************************
 *
 * @brief      In this case, In this case, GPIO26 used as UART1_RXD and ECAP input, and ECAP work in countinue delta 
 *             operation mode. The ECAP is used to capture PWM command from LIN interface.
 *
 *                                                 GPIO25                     ---------------
 *                                                  ---        UART1_TXD     |               |
 *                                                 |   |-------------------->|               |   --    --    --
 *                                                  ---                      |               |  |  |  |  |  |  |       LIN interface
 *                                                                           |               |      --    --            --- 
 *                                                                           |    LIN PHY    |-------------------------| X |
 *            -------                              GPIO26                    |               |                          ---
 *           |       |                              ---       UART1_RXD      |               |
 *           | ECAP  |<----------------------------|   |<--------------------|               |
 *           |       |  ECAP captured pin           ---                      |               |
 *            -------                                                         ---------------
 *                                       
 *             Please keep in mind that don't do too much in the Int function, which can cause captured value over-write.
 *             Key Point:
 *                     <1>:For Continue mode, user do not care about exactly each incoming event, so we do not add extra 4
 *                         event cycle to initialize the divider.
 *                      
 *                     <2>:As showed below:
 *                           -------          --------          --------
 *                          |       |        |        |        |        |        |
 *                          |       |        |        |        |        |        |
 *                                   --------          --------          --------
 *                         / \     / \      / \      / \      / \      / \      / \
 *                          |       |        |        |        |        |        |
 *                          1       2        3        4        5        6        7
 *             
 *             If there are 7 Int had happended, there will be 7 count value need to store into ECAP->CAP0~3. 
 *             
 *             Take a scenarios into acount, 3 INT had happened, then ECAP->CAP0/ECAP->CAP1/ECAP->CAP2 stroe the value
 *             captured, but you do too much work in INT of 3 before reading ECAP->CAP0~2, then there are other 2 INT 
 *             happened, then the 2 new value will store in ECAP->CAPA3 and ECAP->CAP0,which cause ECAP->CAP0 over written,
 *             as a result, ECAP->CAP0 is bigger than ECAP->CAP1~3, this is fatal in a sys.
 *
 *************************************************************************************************************************/


int main(void)
{
    CLOCK_InitWithRCO(100000000);

    Delay_Init();

    /*
    * Init the UART
    *
    * 1.Set the GPIO10/11 as UART FUNC
    *
    * 2.Enable the UART CLK
    *
    * 3.Set the rest para
    */  
    PIN_SetChannel(PIN_GPIO10,PIN_GPIO10_UART0_TXD);
    PIN_SetChannel(PIN_GPIO11,PIN_GPIO11_UART0_RXD);
    UART_Init(UART0, 38400);

    PIN_SetChannel(PIN_GPIO26, PIN_GPIO26_GPIO26);

    PIN_EnableInputChannel(PIN_GPIO26, PIN_GPIO26_GPIO26);

    /* Init High-Voltage module */
    eErrorState = HV_Init(&u16PREDRIID);
    if(eErrorState == ERROR)
    {
        printf("HV Init FAIL\n");
        return 0;
    }

    printf("Init HV SUCCESS[ID:%d]\n", u16PREDRIID);

    eErrorState = EPWR_WriteRegister(HV_REG_CTLKEY, KEY_USER_REG);
    if(eErrorState == ERROR)
    {
        printf("Write CTLKEY FAIL\n");
        return 0;
    }

    eErrorState = EPWR_WriteRegisterField(HV_REG_LINCTL, LINCTL_TXSLOPE_Msk|LINCTL_STRENGTH_Msk|LINCTL_TXEN_Msk|LINCTL_EN_Msk, LINCTL_TXSLOPE_2P5US|LINCTL_STRENGTH_47P2MA|LINCTL_TXEN_ENABLE|LINCTL_EN_ENABLE);
    if(eErrorState == ERROR)
    {
        printf("Write LINCTL FAIL\n");
        return 0;
    }

    /* ECAP Init */
    ECAP_CaptureModeInit(ECAP, PIN_GPIO26);

    /* Set the count reset back to zero when event happened */
    ECAP_EnableEventResetCounter(ECAP, ECAP_CEVT0);
    ECAP_EnableEventResetCounter(ECAP, ECAP_CEVT1);
    ECAP_EnableEventResetCounter(ECAP, ECAP_CEVT2);
    ECAP_EnableEventResetCounter(ECAP, ECAP_CEVT3);

    /* Enable EVT3 Interrupt */
    ECAP_EnableInt(ECAP, ECAP_INT_CEVT3);

    /* Enable global interrupt of EACP */
    NVIC_EnableIRQ(ECAP_IRQn);

    /* Start ECAP */
    ECAP_RunCounter(ECAP);

    while(1)
    {
      
    }
}




void ECAP_IRQHandler(void)
{
    uint32_t cnt;

    TStamp0 = ECAP->CAP0;
    TStamp1 = ECAP->CAP1;
    TStamp2 = ECAP->CAP2;
    TStamp3 = ECAP->CAP3;

    cnt = TStamp2 + TStamp1;
    printf("Fre  = %d Hz\n", CNTTOFREQ(cnt));
    printf("Duty = %d%%\n",  TStamp1 * 100 / cnt);

    /* Clear CEVT3 */
    ECAP_ClearInt(ECAP, ECAP_INT_CEVT3);
    ECAP_ClearInt(ECAP, ECAP_INT_GLOBAL);
}


/******************* (C) COPYRIGHT 2020 SPINTROL LIMITED ***** END OF FILE ****/
