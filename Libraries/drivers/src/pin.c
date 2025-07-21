/******************************************************************************
 * @file     pin.c
 * @brief    PINMUX firmware functions.
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

#include "pin.h"




/******************************************************************************
 * @brief      Set all pin to default function
 *
 * @param[in]  none
 *
 * @return     none
 *
 ******************************************************************************/
void PIN_ResetAllPin(void)
{
    PIN_NameEnum ePinName;

    /* Set all pin as GPIO input */
#if (defined(SPD1177) || defined(SPD1179) || defined(SPD1179B))
    GPIO->GCDR[0] = 0xF807FFFFU;  /* Do not modify internal IOs (PIN_GPIO19 ~ PIN_GPIO26) */
#else
    GPIO->GCDR[0] = 0xFFFFFFFFU;
#endif

    /* Set all pin channel as default */
    ePinName = PIN_GPIO_LAST;
    while (ePinName--)
    {
        if ((ePinName <= PIN_GPIO4) || (ePinName >= PIN_GPIO36))
        {
            PIN_SetChannel(ePinName, PIN_CH1);
        }
        else
        {
#if (defined(SPD1177) || defined(SPD1179) || defined(SPD1179B))
            /* Do not modify internal IOs (PIN_GPIO19 ~ PIN_GPIO26) */
            if ((ePinName <= PIN_GPIO18) || (ePinName == PIN_GPIO27))
            {
                PIN_SetChannel(ePinName, PIN_CH0);
            }
#else
            PIN_SetChannel(ePinName, PIN_CH0);
#endif
        }
    }
}




/******************************************************************************
 * @brief      Set the specified pin as GPIO function
 *
 * @param[in]  ePinName:  Select the pin, should be PIN_NameEnum
 *
 * @return     none
 *
 ******************************************************************************/
void PIN_SetPinAsGPIO(PIN_NameEnum ePinName)
{
    PIN_SetChannel(ePinName, PIN_CH0);
}




/******************************************************************************
 * @brief      Set the specified pin as ECAPO function
 *
 * @param[in]  ePinName:  Select the pin, should be PIN_NameEnum
 *
 * @return     none
 *
 ******************************************************************************/
void PIN_SetPinAsECAPO(PIN_NameEnum ePinName)
{
    if (     ((ePinName >= PIN_GPIO18) && (ePinName <= PIN_GPIO24))

          ||  (ePinName == PIN_GPIO5 )
          ||  (ePinName == PIN_GPIO1 )
       )
    {
        PIN_SetChannel(ePinName, PIN_CH3);
    }
}




/******************************************************************************
 * @brief      Set the specified pin as Analog function
 *
 * @param[in]  ePinName:  Select the pin, should be PIN_NameEnum
 *
 * @return     none
 *
 ******************************************************************************/
void PIN_SetPinAsAnalog(PIN_NameEnum ePinName)
{
    if (ePinName <= PIN_GPIO40)
    {
        if ((ePinName <= PIN_GPIO4) || (ePinName >= PIN_GPIO36))
        {
            PIN_SetChannel(ePinName, PIN_CH1);
        }
        if ((ePinName >= PIN_GPIO28) && (ePinName <= PIN_GPIO31))
        {
            PIN_SetChannel(ePinName, PIN_CH1);
        }
    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
