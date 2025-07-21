/******************************************************************************
 * @file     pga.c
 * @brief    PGA firmware functions.
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

#include "pga.h"




/******************************************************************************
 * @brief      Initialized DPGA
 *
 * @param[in]  eGain:  Select the gain, defined by PGA_GainEnum
 *                     \ref - DPGA_GAIN_2X ~ DPGA_GAIN_64X
 *
 * @return     none
 *
 * @exmaple    PGA_InitDPGA(DPGA_GAIN_2X)
 *
 ******************************************************************************/
void PGA_InitDPGA(PGA_GainEnum eGain)
{
    /* Enable PGA Clock */
    CLOCK_EnableModule(PGA_MODULE);
    
    /* Set DPGA gain */
    PGA_SetDPGAGain(eGain);

    /* Enable DPGA */
    PGA_EnableDPGA();
}




/******************************************************************************
 * @brief      Initialized SPGA
 *
 * @param[in]  eInput:  Select the input, defined by PGA_InputSelEnum
 *                      \ref - SPGA_FROM_ANA_IN0 ~ SPGA_FROM_ANA_IN3
 * @param[in]  eGain :  Select the gain, defined by PGA_GainEnum
 *                      \ref - SPGA_GAIN_1X ~ SPGA_GAIN_64X
 *
 * @return     none
 *
 * @exmaple    PGA_InitSPGA(SPGA_FROM_ANA_IN0, DPGA_GAIN_2X)
 *
 ******************************************************************************/
void PGA_InitSPGA(PGA_InputSelEnum eInput, PGA_GainEnum eGain)
{
    /* Enable PGA Clock */
    CLOCK_EnableModule(PGA_MODULE);
    
    /* Set input */
    PGA_SetSPGAInput(eInput);

    /* Set SPGA gain */
    PGA_SetSPGAGain(eGain);

    /* Enable SPGA */
    PGA_EnableSPGA();
}




/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
