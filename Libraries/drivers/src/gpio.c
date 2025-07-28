/******************************************************************************
 * @file     gpio.c
 * @brief    GPIO firmware functions.
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

#include "gpio.h"




/******************************************************************************
 * @brief      Configure GPIO edge detection type
 *
 * @param[in]  ePinName :  Select the pin, should be PIN_NameEnum
 * @param[in]  eEdgeType:  Edge detection type, should be GPIO_EdgeIntEnum
 *                         - \ref GPIO_EDGE_RISING  -> Rising edge
 *                         - \ref GPIO_EDGE_FALLING -> Falling edge
 *                         - \ref GPIO_EDGE_BOTH    -> Rising and Falling edge
 *                         - \ref GPIO_EDGE_NONE    -> Disable edge detection
 *
 * @return     none
 *
 ******************************************************************************/
void GPIO_SetEdgeIntMode(PIN_NameEnum ePinName, GPIO_EdgeEnum eEdgeType)
{
    /* Enable/Disabe GPIO Rising/Falling interrupt function */
    switch (eEdgeType)
    {
        case GPIO_EDGE_RISING:
            GPIO_EnableRisingEdgeDetect(ePinName);
            GPIO_EnableRisingEdgeInt(ePinName);

            GPIO_DisableFallingEdgeDetect(ePinName);
            GPIO_DisableFallingEdgeInt(ePinName);
            break;

        case GPIO_EDGE_FALLING:
            GPIO_DisableRisingEdgeDetect(ePinName);
            GPIO_DisableRisingEdgeInt(ePinName);

            GPIO_EnableFallingEdgeDetect(ePinName);
            GPIO_EnableFallingEdgeInt(ePinName);
            break;

        case GPIO_EDGE_BOTH:
            GPIO_EnableRisingEdgeDetect(ePinName);
            GPIO_EnableRisingEdgeInt(ePinName);

            GPIO_EnableFallingEdgeDetect(ePinName);
            GPIO_EnableFallingEdgeInt(ePinName);
            break;

        case GPIO_EDGE_NONE:
            GPIO_DisableRisingEdgeDetect(ePinName);
            GPIO_DisableRisingEdgeInt(ePinName);

            GPIO_DisableFallingEdgeDetect(ePinName);
            GPIO_DisableFallingEdgeInt(ePinName);
            break;

        default:
            break;
    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
