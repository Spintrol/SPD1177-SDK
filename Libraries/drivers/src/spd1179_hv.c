/******************************************************************************
 * @file     epwr.c
 * @brief    ePower firmware functions.
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

#include "spd1179_hv.h"




/****************************************************************************//**
 * @brief      Initialize High Voltage Module Pin Interface
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void HV_PinInit(void)
{
    /* Pin for High Voltage Module */
    PIN_SetChannel(GPIO_HV_PWM_W_L, PIN_GPIO19_PWM2B);
    PIN_SetChannel(GPIO_HV_PWM_W_H, PIN_GPIO20_PWM2A);

    PIN_SetChannel(GPIO_HV_PWM_V_L, PIN_GPIO21_PWM1B);
    PIN_SetChannel(GPIO_HV_PWM_V_H, PIN_GPIO22_PWM1A);

    PIN_SetChannel(GPIO_HV_PWM_U_L, PIN_GPIO23_PWM0B);
    PIN_SetChannel(GPIO_HV_PWM_U_H, PIN_GPIO24_PWM0A);
}




/********************************************************************************
 * @brief      Initialize High Voltage Module
 *
 * @param[in]  u32Baudrate:  Communication Speed (bps)
 * @param[in]  pu16ID     :  Pointer to the data stored High Voltage Module ID
 *
 * @return     ERROR or SUCCESS
 *
 *******************************************************************************/
ErrorStatus HV_Init(uint16_t *pu16ID)
{
    ErrorStatus Status;

    /* Init Pin Interface */
    HV_PinInit();

    /* Init Communication */
    Status = EPWR_ComSpeedInit(EPWR_COM_SPEED);

    if (Status == SUCCESS)
    {
        /* Handshake with High Voltage Module */
        Status = EPWR_GetID(pu16ID);

        if (Status == SUCCESS)
        {
            /* Init High Voltage Module registers */
            Status = HV_InitRegister();
        }
    }

    return Status;
}




/********************************************************************************
 * @brief      Init High Voltage Module Registers (Trim)
 *
 * @param[in]  none
 *
 * @return     ERROR or SUCCESS
 *
 *******************************************************************************/
ErrorStatus HV_InitRegister(void)
{
    ErrorStatus Status = SUCCESS;
    uint32_t u32Temp;

    /* Get Trim Flag */
    u32Temp = *(__IO uint32_t *)(0x11001000U + 0x180);

    /* Valid Trim Flag */
    if (u32Temp == 0x1ACCE551U)
    {
        /* Enable Write Access */
        Status = EPWR_WriteRegister(HV_REG_CTLKEY, KEY_ENGR_REG);


        /* Write PMUTRIM0 value */
        if (Status == SUCCESS)
        {
            u32Temp = *(__IO uint32_t *)(0x11001000U + 0x188);

            Status = EPWR_WriteRegister(0x30, u32Temp);
        }

        /* Write PMUTRIM1 value */
        if (Status == SUCCESS)
        {
            u32Temp = *(__IO uint32_t *)(0x11001000U + 0x18C);

            Status = EPWR_WriteRegister(0x31, u32Temp);
        }

        /* Write PMUTRIM2 value */
        if (Status == SUCCESS)
        {
            u32Temp = *(__IO uint32_t *)(0x11001000U + 0x190);

            Status = EPWR_WriteRegister(0x32, u32Temp);
        }

        /* Write PMUTRIM3 value */
        if (Status == SUCCESS)
        {
            u32Temp = *(__IO uint32_t *)(0x11001000U + 0x194);

            Status = EPWR_WriteRegister(0x33, u32Temp);
        }

        /* Write BODTRIM value */
        if (Status == SUCCESS)
        {
            u32Temp = *(__IO uint32_t *)(0x11001000U + 0x198);

            Status = EPWR_WriteRegister(0x34, u32Temp);
        }

        /* Write LINTRIM value */
        if (Status == SUCCESS)
        {
            u32Temp = *(__IO uint32_t *)(0x11001000U + 0x19C);

            Status = EPWR_WriteRegister(0x35, u32Temp);
        }
        
        /* Enable Write Access */
        Status = EPWR_WriteRegister(HV_REG_CTLKEY, KEY_USER_REG);
        
        if (Status == SUCCESS)
        {
            /* Write PMUCTL vaule */
            Status = EPWR_WriteRegister(HV_REG_PMUCTL, 0xA2B5);
        }
        
        if (Status == SUCCESS)
        {
            /* Write PDRVCTL1 vaule */
            Status = EPWR_WriteRegister(HV_REG_PDRVCTL1, 0x1A7C);
        }

        /* Disable Write Access */
        Status = EPWR_WriteRegister(HV_REG_CTLKEY, KEY_LOCK_ALL);
    }

    return Status;
}




/********************************************************************************
 * @brief      Connect the PMU T-Sensor to the ATEST channel,
               so the TPMU signal can be measured by ADC
 *
 * @param[in]  none
 *
 * @return     None
 *
 *******************************************************************************/
//void HV_ConnectTPMUToAnalogTest(void)
//{
//    uint32_t u32Temp;
//    __IO uint32_t *pREG = (__IO uint32_t *)(0x40000754);
//    *pREG =  0x1ACCE551;

//    /* Stop system monitor */
//    pREG = (__IO uint32_t *)(0x40000734);
//    *pREG = 0x1acce551U;

//    /* Enable ePower analog test */
//    pREG = (__IO uint32_t *)(0x40000730);
//    u32Temp = (*pREG) & 0xf000001fU;
//    u32Temp |= 1U << 27;
//    *pREG = u32Temp;

//    /* Analog test point select 0 */
//    pREG = (__IO uint32_t *)(0x40000730);
//    u32Temp = (*pREG) & (~0xfU);
//    *pREG = u32Temp;

//    /* Enable ATEST pin output */
//    pREG = (__IO uint32_t *)(0x40000730);
//    u32Temp = (*pREG);
//    u32Temp |= 1U << 4;
//    *pREG = u32Temp;

//    /* Select TPMU as PMONSEL input */
//    pREG = (__IO uint32_t *)(0x40000730);
//    u32Temp = *pREG & (~((0x7U) << 28));
//    u32Temp |= 0x5U << 28;
//    *pREG = u32Temp;


//    pREG = (__IO uint32_t *)(0x40000754);
//    *pREG =  0x0U;
//}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
