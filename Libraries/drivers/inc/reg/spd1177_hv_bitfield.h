/*************************************************************************
 * @file     hv_bitfield.h
 * @brief    High voltage module register bit-field definition
 * @version  V12.0.5
 * @date     5-June-2025
 *
 * @note
 * Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd.. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION
 * REGARDING THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM.
 * SPINTROL SHALL NOT BE LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL
 * DOES NOT GUARANTEE THE CORRECTNESS OF THIS SOFTWARE AND RESERVES THE
 * RIGHT TO MODIFY THE SOFTWARE WITHOUT NOTIFICATION.
 *
 ************************************************************************/


#ifndef HV_BITFIELD_H
#define HV_BITFIELD_H

#ifdef __cplusplus
extern "C" {
#endif



/********************************************************************************
*
* Module Name     HV
*
*
********************************************************************************/



/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       PINPMURST
  *  @access     HV->SYSEVTFLG
  *  @brief      XRSTn pin triggered PMU reset event flag
  */
#define SYSEVTFLG_PINPMURST_Pos  (0)
#define SYSEVTFLG_PINPMURST_Msk  (0x1U << SYSEVTFLG_PINPMURST_Pos)

#define SYSEVTFLG_PINPMURST_NOT_OCCUR  ((0x0U) << SYSEVTFLG_PINPMURST_Pos)
#define SYSEVTFLG_PINPMURST_OCCUR      ((0x1U) << SYSEVTFLG_PINPMURST_Pos)

#define SYSEVTFLG_PINPMURST_(x)  (((x) << SYSEVTFLG_PINPMURST_Pos) & SYSEVTFLG_PINPMURST_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       PINFUNCRST
  *  @access     HV->SYSEVTFLG
  *  @brief      XRSTn pin triggered function reset event flag
  */
#define SYSEVTFLG_PINFUNCRST_Pos  (1)
#define SYSEVTFLG_PINFUNCRST_Msk  (0x1U << SYSEVTFLG_PINFUNCRST_Pos)

#define SYSEVTFLG_PINFUNCRST_NOT_OCCUR  ((0x0U) << SYSEVTFLG_PINFUNCRST_Pos)
#define SYSEVTFLG_PINFUNCRST_OCCUR      ((0x1U) << SYSEVTFLG_PINFUNCRST_Pos)

#define SYSEVTFLG_PINFUNCRST_(x)  (((x) << SYSEVTFLG_PINFUNCRST_Pos) & SYSEVTFLG_PINFUNCRST_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       PMUWDTRST
  *  @access     HV->SYSEVTFLG
  *  @brief      PMU watchdog reset event flag
  */
#define SYSEVTFLG_PMUWDTRST_Pos  (2)
#define SYSEVTFLG_PMUWDTRST_Msk  (0x1U << SYSEVTFLG_PMUWDTRST_Pos)

#define SYSEVTFLG_PMUWDTRST_NOT_OCCUR  ((0x0U) << SYSEVTFLG_PMUWDTRST_Pos)
#define SYSEVTFLG_PMUWDTRST_OCCUR      ((0x1U) << SYSEVTFLG_PMUWDTRST_Pos)

#define SYSEVTFLG_PMUWDTRST_(x)  (((x) << SYSEVTFLG_PMUWDTRST_Pos) & SYSEVTFLG_PMUWDTRST_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       PMUTIMEOUT
  *  @access     HV->SYSEVTFLG
  *  @brief      PMU timeout evet flag
  *              It is asserted if the VDD5/VDD3 failed to be fully established within the
  *              predefined time  (typical 2ms)
  */
#define SYSEVTFLG_PMUTIMEOUT_Pos  (3)
#define SYSEVTFLG_PMUTIMEOUT_Msk  (0x1U << SYSEVTFLG_PMUTIMEOUT_Pos)

#define SYSEVTFLG_PMUTIMEOUT_NOT_OCCUR  ((0x0U) << SYSEVTFLG_PMUTIMEOUT_Pos)
#define SYSEVTFLG_PMUTIMEOUT_OCCUR      ((0x1U) << SYSEVTFLG_PMUTIMEOUT_Pos)

#define SYSEVTFLG_PMUTIMEOUT_(x)  (((x) << SYSEVTFLG_PMUTIMEOUT_Pos) & SYSEVTFLG_PMUTIMEOUT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       VDD5EXTOCFAIL
  *  @access     HV->SYSEVTFLG
  *  @brief      VDD5EXT over-current failure event flag
  *              It is asserted if the condition is detected during power-up or last for more
  *              than 320us and make the VDD5EXT self-shutdown
  */
#define SYSEVTFLG_VDD5EXTOCFAIL_Pos  (4)
#define SYSEVTFLG_VDD5EXTOCFAIL_Msk  (0x1U << SYSEVTFLG_VDD5EXTOCFAIL_Pos)

#define SYSEVTFLG_VDD5EXTOCFAIL_NOT_OCCUR  ((0x0U) << SYSEVTFLG_VDD5EXTOCFAIL_Pos)
#define SYSEVTFLG_VDD5EXTOCFAIL_OCCUR      ((0x1U) << SYSEVTFLG_VDD5EXTOCFAIL_Pos)

#define SYSEVTFLG_VDD5EXTOCFAIL_(x)  (((x) << SYSEVTFLG_VDD5EXTOCFAIL_Pos) & SYSEVTFLG_VDD5EXTOCFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       VDD5OCFAIL
  *  @access     HV->SYSEVTFLG
  *  @brief      VDD5 over-current failure event flag
  *              It is asserted if the condition is detected during power-up or last for more
  *              than 320us in active state and make the system go to sleep
  */
#define SYSEVTFLG_VDD5OCFAIL_Pos  (5)
#define SYSEVTFLG_VDD5OCFAIL_Msk  (0x1U << SYSEVTFLG_VDD5OCFAIL_Pos)

#define SYSEVTFLG_VDD5OCFAIL_NOT_OCCUR  ((0x0U) << SYSEVTFLG_VDD5OCFAIL_Pos)
#define SYSEVTFLG_VDD5OCFAIL_OCCUR      ((0x1U) << SYSEVTFLG_VDD5OCFAIL_Pos)

#define SYSEVTFLG_VDD5OCFAIL_(x)  (((x) << SYSEVTFLG_VDD5OCFAIL_Pos) & SYSEVTFLG_VDD5OCFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       VDD3OCFAIL
  *  @access     HV->SYSEVTFLG
  *  @brief      VDD3 over-current failure event flag
  *              It is asserted if the condition last for more than 320us and make the system go
  *              to sleep
  */
#define SYSEVTFLG_VDD3OCFAIL_Pos  (6)
#define SYSEVTFLG_VDD3OCFAIL_Msk  (0x1U << SYSEVTFLG_VDD3OCFAIL_Pos)

#define SYSEVTFLG_VDD3OCFAIL_NOT_OCCUR  ((0x0U) << SYSEVTFLG_VDD3OCFAIL_Pos)
#define SYSEVTFLG_VDD3OCFAIL_OCCUR      ((0x1U) << SYSEVTFLG_VDD3OCFAIL_Pos)

#define SYSEVTFLG_VDD3OCFAIL_(x)  (((x) << SYSEVTFLG_VDD3OCFAIL_Pos) & SYSEVTFLG_VDD3OCFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       PMUONFAIL
  *  @access     HV->SYSEVTFLG
  *  @brief      PMU power on failure event flag
  *              It is asserted if VDD5/VDD3 over-current or timeout for 5 times and make the
  *              system go to sleep
  */
#define SYSEVTFLG_PMUONFAIL_Pos  (7)
#define SYSEVTFLG_PMUONFAIL_Msk  (0x1U << SYSEVTFLG_PMUONFAIL_Pos)

#define SYSEVTFLG_PMUONFAIL_NOT_OCCUR  ((0x0U) << SYSEVTFLG_PMUONFAIL_Pos)
#define SYSEVTFLG_PMUONFAIL_OCCUR      ((0x1U) << SYSEVTFLG_PMUONFAIL_Pos)

#define SYSEVTFLG_PMUONFAIL_(x)  (((x) << SYSEVTFLG_PMUONFAIL_Pos) & SYSEVTFLG_PMUONFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       PMUWDTFAIL
  *  @access     HV->SYSEVTFLG
  *  @brief      PMU WDT failure event flag
  *              It is asserted if PMU watchdog reset happnes for 5 times and make the system go
  *              to sleep
  */
#define SYSEVTFLG_PMUWDTFAIL_Pos  (8)
#define SYSEVTFLG_PMUWDTFAIL_Msk  (0x1U << SYSEVTFLG_PMUWDTFAIL_Pos)

#define SYSEVTFLG_PMUWDTFAIL_NOT_OCCUR  ((0x0U) << SYSEVTFLG_PMUWDTFAIL_Pos)
#define SYSEVTFLG_PMUWDTFAIL_OCCUR      ((0x1U) << SYSEVTFLG_PMUWDTFAIL_Pos)

#define SYSEVTFLG_PMUWDTFAIL_(x)  (((x) << SYSEVTFLG_PMUWDTFAIL_Pos) & SYSEVTFLG_PMUWDTFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       PMUOTFAIL
  *  @access     HV->SYSEVTFLG
  *  @brief      PMU over-temperature fatal failure event flag
  */
#define SYSEVTFLG_PMUOTFAIL_Pos  (9)
#define SYSEVTFLG_PMUOTFAIL_Msk  (0x1U << SYSEVTFLG_PMUOTFAIL_Pos)

#define SYSEVTFLG_PMUOTFAIL_NOT_OCCUR  ((0x0U) << SYSEVTFLG_PMUOTFAIL_Pos)
#define SYSEVTFLG_PMUOTFAIL_OCCUR      ((0x1U) << SYSEVTFLG_PMUOTFAIL_Pos)

#define SYSEVTFLG_PMUOTFAIL_(x)  (((x) << SYSEVTFLG_PMUOTFAIL_Pos) & SYSEVTFLG_PMUOTFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       SLEEPCMD
  *  @access     HV->SYSEVTFLG
  *  @brief      Sleep command received event flag
  */
#define SYSEVTFLG_SLEEPCMD_Pos  (10)
#define SYSEVTFLG_SLEEPCMD_Msk  (0x1U << SYSEVTFLG_SLEEPCMD_Pos)

#define SYSEVTFLG_SLEEPCMD_NOT_OCCUR  ((0x0U) << SYSEVTFLG_SLEEPCMD_Pos)
#define SYSEVTFLG_SLEEPCMD_OCCUR      ((0x1U) << SYSEVTFLG_SLEEPCMD_Pos)

#define SYSEVTFLG_SLEEPCMD_(x)  (((x) << SYSEVTFLG_SLEEPCMD_Pos) & SYSEVTFLG_SLEEPCMD_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       STOPCMD
  *  @access     HV->SYSEVTFLG
  *  @brief      Stop command received event flag
  */
#define SYSEVTFLG_STOPCMD_Pos  (11)
#define SYSEVTFLG_STOPCMD_Msk  (0x1U << SYSEVTFLG_STOPCMD_Pos)

#define SYSEVTFLG_STOPCMD_NOT_OCCUR  ((0x0U) << SYSEVTFLG_STOPCMD_Pos)
#define SYSEVTFLG_STOPCMD_OCCUR      ((0x1U) << SYSEVTFLG_STOPCMD_Pos)

#define SYSEVTFLG_STOPCMD_(x)  (((x) << SYSEVTFLG_STOPCMD_Pos) & SYSEVTFLG_STOPCMD_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       CYCSENWKUP
  *  @access     HV->SYSEVTFLG
  *  @brief      Cyclic sense IO wakeup event flag
  */
#define SYSEVTFLG_CYCSENWKUP_Pos  (12)
#define SYSEVTFLG_CYCSENWKUP_Msk  (0x1U << SYSEVTFLG_CYCSENWKUP_Pos)

#define SYSEVTFLG_CYCSENWKUP_NOT_OCCUR  ((0x0U) << SYSEVTFLG_CYCSENWKUP_Pos)
#define SYSEVTFLG_CYCSENWKUP_OCCUR      ((0x1U) << SYSEVTFLG_CYCSENWKUP_Pos)

#define SYSEVTFLG_CYCSENWKUP_(x)  (((x) << SYSEVTFLG_CYCSENWKUP_Pos) & SYSEVTFLG_CYCSENWKUP_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       CYCWKUP
  *  @access     HV->SYSEVTFLG
  *  @brief      Cyclic wakeup event flag
  */
#define SYSEVTFLG_CYCWKUP_Pos  (13)
#define SYSEVTFLG_CYCWKUP_Msk  (0x1U << SYSEVTFLG_CYCWKUP_Pos)

#define SYSEVTFLG_CYCWKUP_NOT_OCCUR  ((0x0U) << SYSEVTFLG_CYCWKUP_Pos)
#define SYSEVTFLG_CYCWKUP_OCCUR      ((0x1U) << SYSEVTFLG_CYCWKUP_Pos)

#define SYSEVTFLG_CYCWKUP_(x)  (((x) << SYSEVTFLG_CYCWKUP_Pos) & SYSEVTFLG_CYCWKUP_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       MONWKUP
  *  @access     HV->SYSEVTFLG
  *  @brief      MON wakeup event flag
  */
#define SYSEVTFLG_MONWKUP_Pos  (14)
#define SYSEVTFLG_MONWKUP_Msk  (0x1U << SYSEVTFLG_MONWKUP_Pos)

#define SYSEVTFLG_MONWKUP_NOT_OCCUR  ((0x0U) << SYSEVTFLG_MONWKUP_Pos)
#define SYSEVTFLG_MONWKUP_OCCUR      ((0x1U) << SYSEVTFLG_MONWKUP_Pos)

#define SYSEVTFLG_MONWKUP_(x)  (((x) << SYSEVTFLG_MONWKUP_Pos) & SYSEVTFLG_MONWKUP_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLG       LINWKUP
  *  @access     HV->SYSEVTFLG
  *  @brief      LIN wakeup event flag
  */
#define SYSEVTFLG_LINWKUP_Pos  (15)
#define SYSEVTFLG_LINWKUP_Msk  (0x1U << SYSEVTFLG_LINWKUP_Pos)

#define SYSEVTFLG_LINWKUP_NOT_OCCUR  ((0x0U) << SYSEVTFLG_LINWKUP_Pos)
#define SYSEVTFLG_LINWKUP_OCCUR      ((0x1U) << SYSEVTFLG_LINWKUP_Pos)

#define SYSEVTFLG_LINWKUP_(x)  (((x) << SYSEVTFLG_LINWKUP_Pos) & SYSEVTFLG_LINWKUP_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    PINPMURST
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      XRSTn pin triggered PMU reset event flag clear
  */
#define SYSEVTFLGCLR_PINPMURST_Pos  (0)
#define SYSEVTFLGCLR_PINPMURST_Msk  (0x1U << SYSEVTFLGCLR_PINPMURST_Pos)

#define SYSEVTFLGCLR_PINPMURST_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_PINPMURST_Pos)
#define SYSEVTFLGCLR_PINPMURST_CLEAR      ((0x1U) << SYSEVTFLGCLR_PINPMURST_Pos)

#define SYSEVTFLGCLR_PINPMURST_(x)  (((x) << SYSEVTFLGCLR_PINPMURST_Pos) & SYSEVTFLGCLR_PINPMURST_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    PINFUNCRST
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      XRSTn pin triggered function reset event flag clear
  */
#define SYSEVTFLGCLR_PINFUNCRST_Pos  (1)
#define SYSEVTFLGCLR_PINFUNCRST_Msk  (0x1U << SYSEVTFLGCLR_PINFUNCRST_Pos)

#define SYSEVTFLGCLR_PINFUNCRST_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_PINFUNCRST_Pos)
#define SYSEVTFLGCLR_PINFUNCRST_CLEAR      ((0x1U) << SYSEVTFLGCLR_PINFUNCRST_Pos)

#define SYSEVTFLGCLR_PINFUNCRST_(x)  (((x) << SYSEVTFLGCLR_PINFUNCRST_Pos) & SYSEVTFLGCLR_PINFUNCRST_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    PMUWDTRST
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      PMU watchdog reset event flag clear
  */
#define SYSEVTFLGCLR_PMUWDTRST_Pos  (2)
#define SYSEVTFLGCLR_PMUWDTRST_Msk  (0x1U << SYSEVTFLGCLR_PMUWDTRST_Pos)

#define SYSEVTFLGCLR_PMUWDTRST_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_PMUWDTRST_Pos)
#define SYSEVTFLGCLR_PMUWDTRST_CLEAR      ((0x1U) << SYSEVTFLGCLR_PMUWDTRST_Pos)

#define SYSEVTFLGCLR_PMUWDTRST_(x)  (((x) << SYSEVTFLGCLR_PMUWDTRST_Pos) & SYSEVTFLGCLR_PMUWDTRST_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    PMUTIMEOUT
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      PMU timeout evet flag clear
  */
#define SYSEVTFLGCLR_PMUTIMEOUT_Pos  (3)
#define SYSEVTFLGCLR_PMUTIMEOUT_Msk  (0x1U << SYSEVTFLGCLR_PMUTIMEOUT_Pos)

#define SYSEVTFLGCLR_PMUTIMEOUT_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_PMUTIMEOUT_Pos)
#define SYSEVTFLGCLR_PMUTIMEOUT_CLEAR      ((0x1U) << SYSEVTFLGCLR_PMUTIMEOUT_Pos)

#define SYSEVTFLGCLR_PMUTIMEOUT_(x)  (((x) << SYSEVTFLGCLR_PMUTIMEOUT_Pos) & SYSEVTFLGCLR_PMUTIMEOUT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    VDD5EXTOCFAIL
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      VDD5EXT over-current event flag clear
  */
#define SYSEVTFLGCLR_VDD5EXTOCFAIL_Pos  (4)
#define SYSEVTFLGCLR_VDD5EXTOCFAIL_Msk  (0x1U << SYSEVTFLGCLR_VDD5EXTOCFAIL_Pos)

#define SYSEVTFLGCLR_VDD5EXTOCFAIL_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_VDD5EXTOCFAIL_Pos)
#define SYSEVTFLGCLR_VDD5EXTOCFAIL_CLEAR      ((0x1U) << SYSEVTFLGCLR_VDD5EXTOCFAIL_Pos)

#define SYSEVTFLGCLR_VDD5EXTOCFAIL_(x)  (((x) << SYSEVTFLGCLR_VDD5EXTOCFAIL_Pos) & SYSEVTFLGCLR_VDD5EXTOCFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    VDD5OCFAIL
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      VDD5 over-current event flag clear
  */
#define SYSEVTFLGCLR_VDD5OCFAIL_Pos  (5)
#define SYSEVTFLGCLR_VDD5OCFAIL_Msk  (0x1U << SYSEVTFLGCLR_VDD5OCFAIL_Pos)

#define SYSEVTFLGCLR_VDD5OCFAIL_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_VDD5OCFAIL_Pos)
#define SYSEVTFLGCLR_VDD5OCFAIL_CLEAR      ((0x1U) << SYSEVTFLGCLR_VDD5OCFAIL_Pos)

#define SYSEVTFLGCLR_VDD5OCFAIL_(x)  (((x) << SYSEVTFLGCLR_VDD5OCFAIL_Pos) & SYSEVTFLGCLR_VDD5OCFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    VDD3OCFAIL
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      VDD3 over-current event flag clear
  */
#define SYSEVTFLGCLR_VDD3OCFAIL_Pos  (6)
#define SYSEVTFLGCLR_VDD3OCFAIL_Msk  (0x1U << SYSEVTFLGCLR_VDD3OCFAIL_Pos)

#define SYSEVTFLGCLR_VDD3OCFAIL_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_VDD3OCFAIL_Pos)
#define SYSEVTFLGCLR_VDD3OCFAIL_CLEAR      ((0x1U) << SYSEVTFLGCLR_VDD3OCFAIL_Pos)

#define SYSEVTFLGCLR_VDD3OCFAIL_(x)  (((x) << SYSEVTFLGCLR_VDD3OCFAIL_Pos) & SYSEVTFLGCLR_VDD3OCFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    PMULDOFAIL
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      PMU LDO failure event flag clear
  */
#define SYSEVTFLGCLR_PMULDOFAIL_Pos  (7)
#define SYSEVTFLGCLR_PMULDOFAIL_Msk  (0x1U << SYSEVTFLGCLR_PMULDOFAIL_Pos)

#define SYSEVTFLGCLR_PMULDOFAIL_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_PMULDOFAIL_Pos)
#define SYSEVTFLGCLR_PMULDOFAIL_CLEAR      ((0x1U) << SYSEVTFLGCLR_PMULDOFAIL_Pos)

#define SYSEVTFLGCLR_PMULDOFAIL_(x)  (((x) << SYSEVTFLGCLR_PMULDOFAIL_Pos) & SYSEVTFLGCLR_PMULDOFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    PMUWDTFAIL
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      PMU WDT failure event flag clear
  */
#define SYSEVTFLGCLR_PMUWDTFAIL_Pos  (8)
#define SYSEVTFLGCLR_PMUWDTFAIL_Msk  (0x1U << SYSEVTFLGCLR_PMUWDTFAIL_Pos)

#define SYSEVTFLGCLR_PMUWDTFAIL_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_PMUWDTFAIL_Pos)
#define SYSEVTFLGCLR_PMUWDTFAIL_CLEAR      ((0x1U) << SYSEVTFLGCLR_PMUWDTFAIL_Pos)

#define SYSEVTFLGCLR_PMUWDTFAIL_(x)  (((x) << SYSEVTFLGCLR_PMUWDTFAIL_Pos) & SYSEVTFLGCLR_PMUWDTFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    PMUOTFAIL
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      PMU over-temperature fatal failure event flag clear
  */
#define SYSEVTFLGCLR_PMUOTFAIL_Pos  (9)
#define SYSEVTFLGCLR_PMUOTFAIL_Msk  (0x1U << SYSEVTFLGCLR_PMUOTFAIL_Pos)

#define SYSEVTFLGCLR_PMUOTFAIL_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_PMUOTFAIL_Pos)
#define SYSEVTFLGCLR_PMUOTFAIL_CLEAR      ((0x1U) << SYSEVTFLGCLR_PMUOTFAIL_Pos)

#define SYSEVTFLGCLR_PMUOTFAIL_(x)  (((x) << SYSEVTFLGCLR_PMUOTFAIL_Pos) & SYSEVTFLGCLR_PMUOTFAIL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    SLEEPCMD
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      Sleep command received event flag clear
  */
#define SYSEVTFLGCLR_SLEEPCMD_Pos  (10)
#define SYSEVTFLGCLR_SLEEPCMD_Msk  (0x1U << SYSEVTFLGCLR_SLEEPCMD_Pos)

#define SYSEVTFLGCLR_SLEEPCMD_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_SLEEPCMD_Pos)
#define SYSEVTFLGCLR_SLEEPCMD_CLEAR      ((0x1U) << SYSEVTFLGCLR_SLEEPCMD_Pos)

#define SYSEVTFLGCLR_SLEEPCMD_(x)  (((x) << SYSEVTFLGCLR_SLEEPCMD_Pos) & SYSEVTFLGCLR_SLEEPCMD_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    STOPCMD
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      Stop command received event flag clear
  */
#define SYSEVTFLGCLR_STOPCMD_Pos  (11)
#define SYSEVTFLGCLR_STOPCMD_Msk  (0x1U << SYSEVTFLGCLR_STOPCMD_Pos)

#define SYSEVTFLGCLR_STOPCMD_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_STOPCMD_Pos)
#define SYSEVTFLGCLR_STOPCMD_CLEAR      ((0x1U) << SYSEVTFLGCLR_STOPCMD_Pos)

#define SYSEVTFLGCLR_STOPCMD_(x)  (((x) << SYSEVTFLGCLR_STOPCMD_Pos) & SYSEVTFLGCLR_STOPCMD_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    CYCSENWKUP
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      Cyclic sense GPIO wakeup event flag clear
  */
#define SYSEVTFLGCLR_CYCSENWKUP_Pos  (12)
#define SYSEVTFLGCLR_CYCSENWKUP_Msk  (0x1U << SYSEVTFLGCLR_CYCSENWKUP_Pos)

#define SYSEVTFLGCLR_CYCSENWKUP_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_CYCSENWKUP_Pos)
#define SYSEVTFLGCLR_CYCSENWKUP_CLEAR      ((0x1U) << SYSEVTFLGCLR_CYCSENWKUP_Pos)

#define SYSEVTFLGCLR_CYCSENWKUP_(x)  (((x) << SYSEVTFLGCLR_CYCSENWKUP_Pos) & SYSEVTFLGCLR_CYCSENWKUP_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    CYCWKUP
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      Cyclic wakeup event flag clear
  */
#define SYSEVTFLGCLR_CYCWKUP_Pos  (13)
#define SYSEVTFLGCLR_CYCWKUP_Msk  (0x1U << SYSEVTFLGCLR_CYCWKUP_Pos)

#define SYSEVTFLGCLR_CYCWKUP_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_CYCWKUP_Pos)
#define SYSEVTFLGCLR_CYCWKUP_CLEAR      ((0x1U) << SYSEVTFLGCLR_CYCWKUP_Pos)

#define SYSEVTFLGCLR_CYCWKUP_(x)  (((x) << SYSEVTFLGCLR_CYCWKUP_Pos) & SYSEVTFLGCLR_CYCWKUP_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    MONWKUP
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      MON wake up event flag clear
  */
#define SYSEVTFLGCLR_MONWKUP_Pos  (14)
#define SYSEVTFLGCLR_MONWKUP_Msk  (0x1U << SYSEVTFLGCLR_MONWKUP_Pos)

#define SYSEVTFLGCLR_MONWKUP_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_MONWKUP_Pos)
#define SYSEVTFLGCLR_MONWKUP_CLEAR      ((0x1U) << SYSEVTFLGCLR_MONWKUP_Pos)

#define SYSEVTFLGCLR_MONWKUP_(x)  (((x) << SYSEVTFLGCLR_MONWKUP_Pos) & SYSEVTFLGCLR_MONWKUP_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           SYSEVTFLGCLR    LINWKUP
  *  @access     HV->SYSEVTFLGCLR
  *  @brief      Lin wake up event flag clear
  */
#define SYSEVTFLGCLR_LINWKUP_Pos  (15)
#define SYSEVTFLGCLR_LINWKUP_Msk  (0x1U << SYSEVTFLGCLR_LINWKUP_Pos)

#define SYSEVTFLGCLR_LINWKUP_NO_EFFECT  ((0x0U) << SYSEVTFLGCLR_LINWKUP_Pos)
#define SYSEVTFLGCLR_LINWKUP_CLEAR      ((0x1U) << SYSEVTFLGCLR_LINWKUP_Pos)

#define SYSEVTFLGCLR_LINWKUP_(x)  (((x) << SYSEVTFLGCLR_LINWKUP_Pos) & SYSEVTFLGCLR_LINWKUP_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          VDD5LPLVL
  *  @access     HV->PMUCTL
  *  @brief      VDD5 level in low-power stop mode
  */
#define PMUCTL_VDD5LPLVL_Pos  (0)
#define PMUCTL_VDD5LPLVL_Msk  (0x3U << PMUCTL_VDD5LPLVL_Pos)

#define PMUCTL_VDD5LPLVL_4P24V  ((0x00U) << PMUCTL_VDD5LPLVL_Pos)
#define PMUCTL_VDD5LPLVL_4P45V  ((0x01U) << PMUCTL_VDD5LPLVL_Pos)
#define PMUCTL_VDD5LPLVL_4P70V  ((0x02U) << PMUCTL_VDD5LPLVL_Pos)
#define PMUCTL_VDD5LPLVL_5P00V  ((0x03U) << PMUCTL_VDD5LPLVL_Pos)

#define PMUCTL_VDD5LPLVL_(x)  (((x) << PMUCTL_VDD5LPLVL_Pos) & PMUCTL_VDD5LPLVL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          VDD3LPLVL
  *  @access     HV->PMUCTL
  *  @brief      VDD3 level in low-power stop mode
  */
#define PMUCTL_VDD3LPLVL_Pos  (2)
#define PMUCTL_VDD3LPLVL_Msk  (0x3U << PMUCTL_VDD3LPLVL_Pos)

#define PMUCTL_VDD3LPLVL_2P77V  ((0x00U) << PMUCTL_VDD3LPLVL_Pos)
#define PMUCTL_VDD3LPLVL_2P88V  ((0x01U) << PMUCTL_VDD3LPLVL_Pos)
#define PMUCTL_VDD3LPLVL_3P00V  ((0x02U) << PMUCTL_VDD3LPLVL_Pos)
#define PMUCTL_VDD3LPLVL_3P30V  ((0x03U) << PMUCTL_VDD3LPLVL_Pos)

#define PMUCTL_VDD3LPLVL_(x)  (((x) << PMUCTL_VDD3LPLVL_Pos) & PMUCTL_VDD3LPLVL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          XRSTDGWIN
  *  @access     HV->PMUCTL
  *  @brief      XRSTn pin deglitch filtering window
  */
#define PMUCTL_XRSTDGWIN_Pos  (4)
#define PMUCTL_XRSTDGWIN_Msk  (0x7U << PMUCTL_XRSTDGWIN_Pos)

#define PMUCTL_XRSTDGWIN_4P2US    ((0x000U) << PMUCTL_XRSTDGWIN_Pos)
#define PMUCTL_XRSTDGWIN_97US     ((0x001U) << PMUCTL_XRSTDGWIN_Pos)
#define PMUCTL_XRSTDGWIN_394US    ((0x002U) << PMUCTL_XRSTDGWIN_Pos)
#define PMUCTL_XRSTDGWIN_1P58MS   ((0x003U) << PMUCTL_XRSTDGWIN_Pos)
#define PMUCTL_XRSTDGWIN_3P17MS   ((0x004U) << PMUCTL_XRSTDGWIN_Pos)
#define PMUCTL_XRSTDGWIN_6P34MS   ((0x005U) << PMUCTL_XRSTDGWIN_Pos)
#define PMUCTL_XRSTDGWIN_25P68MS  ((0x006U) << PMUCTL_XRSTDGWIN_Pos)
#define PMUCTL_XRSTDGWIN_102P7MS  ((0x007U) << PMUCTL_XRSTDGWIN_Pos)

#define PMUCTL_XRSTDGWIN_(x)  (((x) << PMUCTL_XRSTDGWIN_Pos) & PMUCTL_XRSTDGWIN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          LPRCOAON
  *  @access     HV->PMUCTL
  *  @brief      Force LPRCO to be always-on even in stop and sleep mode
  */
#define PMUCTL_LPRCOAON_Pos  (7)
#define PMUCTL_LPRCOAON_Msk  (0x1U << PMUCTL_LPRCOAON_Pos)

#define PMUCTL_LPRCOAON_DISABLE  ((0x0U) << PMUCTL_LPRCOAON_Pos)
#define PMUCTL_LPRCOAON_ENABLE   ((0x1U) << PMUCTL_LPRCOAON_Pos)

#define PMUCTL_LPRCOAON_(x)  (((x) << PMUCTL_LPRCOAON_Pos) & PMUCTL_LPRCOAON_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          VDD5EXTEN
  *  @access     HV->PMUCTL
  *  @brief      VDD5EXT enable
  *              Upon sleep mode entry, this bit will be cleared if VDD5EXTPROTEN=1, and user
  *              needs to manually re-enable VDD5EXT after the system wakes up from sleep mode.
  *              Otherwise, it keeps unchanged although the VDD5EXT is shut down by sleep mode
  *              logic. In this case, if VDD5EXTEN=1 before sleep mode entry, VDD5EXT will be
  *              turned on again when it wakes up from sleep mode.
  */
#define PMUCTL_VDD5EXTEN_Pos  (8)
#define PMUCTL_VDD5EXTEN_Msk  (0x1U << PMUCTL_VDD5EXTEN_Pos)

#define PMUCTL_VDD5EXTEN_DISABLE  ((0x0U) << PMUCTL_VDD5EXTEN_Pos)
#define PMUCTL_VDD5EXTEN_ENABLE   ((0x1U) << PMUCTL_VDD5EXTEN_Pos)

#define PMUCTL_VDD5EXTEN_(x)  (((x) << PMUCTL_VDD5EXTEN_Pos) & PMUCTL_VDD5EXTEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          VDD5EXTPROTEN
  *  @access     HV->PMUCTL
  *  @brief      VDD5EXT protect enable to shut down VDD5EXT upon over-current for more than
  *              320us or under-voltage (regarded as short).
  *              It also enable clearance of VDD5EXTEN upon sleep mode entry.
  */
#define PMUCTL_VDD5EXTPROTEN_Pos  (9)
#define PMUCTL_VDD5EXTPROTEN_Msk  (0x1U << PMUCTL_VDD5EXTPROTEN_Pos)

#define PMUCTL_VDD5EXTPROTEN_DISABLE  ((0x0U) << PMUCTL_VDD5EXTPROTEN_Pos)
#define PMUCTL_VDD5EXTPROTEN_ENABLE   ((0x1U) << PMUCTL_VDD5EXTPROTEN_Pos)

#define PMUCTL_VDD5EXTPROTEN_(x)  (((x) << PMUCTL_VDD5EXTPROTEN_Pos) & PMUCTL_VDD5EXTPROTEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          PMUWDTEN
  *  @access     HV->PMUCTL
  *  @brief      PMU watchdog enable
  */
#define PMUCTL_PMUWDTEN_Pos  (10)
#define PMUCTL_PMUWDTEN_Msk  (0x1U << PMUCTL_PMUWDTEN_Pos)

#define PMUCTL_PMUWDTEN_DISABLE  ((0x0U) << PMUCTL_PMUWDTEN_Pos)
#define PMUCTL_PMUWDTEN_ENABLE   ((0x1U) << PMUCTL_PMUWDTEN_Pos)

#define PMUCTL_PMUWDTEN_(x)  (((x) << PMUCTL_PMUWDTEN_Pos) & PMUCTL_PMUWDTEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          CYCSENWKUPEN
  *  @access     HV->PMUCTL
  *  @brief      Cyclic sense GPIO (including MON) wakeup enable
  *              Note: Once MONWKUPEN=1, MON pin cannot be used for cyclic sense wakeup, but only
  *              for asynchronous MON wakeup
  */
#define PMUCTL_CYCSENWKUPEN_Pos  (12)
#define PMUCTL_CYCSENWKUPEN_Msk  (0x1U << PMUCTL_CYCSENWKUPEN_Pos)

#define PMUCTL_CYCSENWKUPEN_DISABLE  ((0x0U) << PMUCTL_CYCSENWKUPEN_Pos)
#define PMUCTL_CYCSENWKUPEN_ENABLE   ((0x1U) << PMUCTL_CYCSENWKUPEN_Pos)

#define PMUCTL_CYCSENWKUPEN_(x)  (((x) << PMUCTL_CYCSENWKUPEN_Pos) & PMUCTL_CYCSENWKUPEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          CYCWKUPEN
  *  @access     HV->PMUCTL
  *  @brief      Cyclic wakeup enable
  *              This bit is automatically set to 1 if both LINWKUPEN & MONWKUPEN bits are 0
  */
#define PMUCTL_CYCWKUPEN_Pos  (13)
#define PMUCTL_CYCWKUPEN_Msk  (0x1U << PMUCTL_CYCWKUPEN_Pos)

#define PMUCTL_CYCWKUPEN_DISABLE  ((0x0U) << PMUCTL_CYCWKUPEN_Pos)
#define PMUCTL_CYCWKUPEN_ENABLE   ((0x1U) << PMUCTL_CYCWKUPEN_Pos)

#define PMUCTL_CYCWKUPEN_(x)  (((x) << PMUCTL_CYCWKUPEN_Pos) & PMUCTL_CYCWKUPEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          MONWKUPEN
  *  @access     HV->PMUCTL
  *  @brief      MON wakeup enable
  *              Note: Write 1 to this bit will also write 1 to EN bit in MONCTL
  */
#define PMUCTL_MONWKUPEN_Pos  (14)
#define PMUCTL_MONWKUPEN_Msk  (0x1U << PMUCTL_MONWKUPEN_Pos)

#define PMUCTL_MONWKUPEN_DISABLE  ((0x0U) << PMUCTL_MONWKUPEN_Pos)
#define PMUCTL_MONWKUPEN_ENABLE   ((0x1U) << PMUCTL_MONWKUPEN_Pos)

#define PMUCTL_MONWKUPEN_(x)  (((x) << PMUCTL_MONWKUPEN_Pos) & PMUCTL_MONWKUPEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUCTL          LINWKUPEN
  *  @access     HV->PMUCTL
  *  @brief      LIN wakeup enable
  */
#define PMUCTL_LINWKUPEN_Pos  (15)
#define PMUCTL_LINWKUPEN_Msk  (0x1U << PMUCTL_LINWKUPEN_Pos)

#define PMUCTL_LINWKUPEN_DISABLE  ((0x0U) << PMUCTL_LINWKUPEN_Pos)
#define PMUCTL_LINWKUPEN_ENABLE   ((0x1U) << PMUCTL_LINWKUPEN_Pos)

#define PMUCTL_LINWKUPEN_(x)  (((x) << PMUCTL_LINWKUPEN_Pos) & PMUCTL_LINWKUPEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUSTS          CURSTATE
  *  @access     HV->PMUSTS
  *  @brief      Current state
  */
#define PMUSTS_CURSTATE_Pos  (0)
#define PMUSTS_CURSTATE_Msk  (0x3U << PMUSTS_CURSTATE_Pos)

#define PMUSTS_CURSTATE_STARTUP  ((0x00U) << PMUSTS_CURSTATE_Pos)
#define PMUSTS_CURSTATE_SLEEP    ((0x01U) << PMUSTS_CURSTATE_Pos)
#define PMUSTS_CURSTATE_STOP     ((0x02U) << PMUSTS_CURSTATE_Pos)
#define PMUSTS_CURSTATE_ACTIVE   ((0x03U) << PMUSTS_CURSTATE_Pos)

#define PMUSTS_CURSTATE_(x)  (((x) << PMUSTS_CURSTATE_Pos) & PMUSTS_CURSTATE_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUSTS          PRESTATE1
  *  @access     HV->PMUSTS
  *  @brief      Last state
  */
#define PMUSTS_PRESTATE1_Pos  (2)
#define PMUSTS_PRESTATE1_Msk  (0x3U << PMUSTS_PRESTATE1_Pos)

#define PMUSTS_PRESTATE1_STARTUP  ((0x00U) << PMUSTS_PRESTATE1_Pos)
#define PMUSTS_PRESTATE1_SLEEP    ((0x01U) << PMUSTS_PRESTATE1_Pos)
#define PMUSTS_PRESTATE1_STOP     ((0x02U) << PMUSTS_PRESTATE1_Pos)
#define PMUSTS_PRESTATE1_ACTIVE   ((0x03U) << PMUSTS_PRESTATE1_Pos)

#define PMUSTS_PRESTATE1_(x)  (((x) << PMUSTS_PRESTATE1_Pos) & PMUSTS_PRESTATE1_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUSTS          PRESTATE2
  *  @access     HV->PMUSTS
  *  @brief      The state before the last
  */
#define PMUSTS_PRESTATE2_Pos  (4)
#define PMUSTS_PRESTATE2_Msk  (0x3U << PMUSTS_PRESTATE2_Pos)

#define PMUSTS_PRESTATE2_STARTUP  ((0x00U) << PMUSTS_PRESTATE2_Pos)
#define PMUSTS_PRESTATE2_SLEEP    ((0x01U) << PMUSTS_PRESTATE2_Pos)
#define PMUSTS_PRESTATE2_STOP     ((0x02U) << PMUSTS_PRESTATE2_Pos)
#define PMUSTS_PRESTATE2_ACTIVE   ((0x03U) << PMUSTS_PRESTATE2_Pos)

#define PMUSTS_PRESTATE2_(x)  (((x) << PMUSTS_PRESTATE2_Pos) & PMUSTS_PRESTATE2_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUSTS          LPPMURDY
  *  @access     HV->PMUSTS
  *  @brief      Low-power PMU ready
  */
#define PMUSTS_LPPMURDY_Pos  (6)
#define PMUSTS_LPPMURDY_Msk  (0x1U << PMUSTS_LPPMURDY_Pos)

#define PMUSTS_LPPMURDY_NOT_READY  ((0x0U) << PMUSTS_LPPMURDY_Pos)
#define PMUSTS_LPPMURDY_READY      ((0x1U) << PMUSTS_LPPMURDY_Pos)

#define PMUSTS_LPPMURDY_(x)  (((x) << PMUSTS_LPPMURDY_Pos) & PMUSTS_LPPMURDY_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUSTS          HPPMURDY
  *  @access     HV->PMUSTS
  *  @brief      High-power PMU ready
  */
#define PMUSTS_HPPMURDY_Pos  (7)
#define PMUSTS_HPPMURDY_Msk  (0x1U << PMUSTS_HPPMURDY_Pos)

#define PMUSTS_HPPMURDY_NOT_READY  ((0x0U) << PMUSTS_HPPMURDY_Pos)
#define PMUSTS_HPPMURDY_READY      ((0x1U) << PMUSTS_HPPMURDY_Pos)

#define PMUSTS_HPPMURDY_(x)  (((x) << PMUSTS_HPPMURDY_Pos) & PMUSTS_HPPMURDY_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUSTS          VDD5EXTRDY
  *  @access     HV->PMUSTS
  *  @brief      VDD5EXT ready
  */
#define PMUSTS_VDD5EXTRDY_Pos  (8)
#define PMUSTS_VDD5EXTRDY_Msk  (0x1U << PMUSTS_VDD5EXTRDY_Pos)

#define PMUSTS_VDD5EXTRDY_NOT_READY  ((0x0U) << PMUSTS_VDD5EXTRDY_Pos)
#define PMUSTS_VDD5EXTRDY_READY      ((0x1U) << PMUSTS_VDD5EXTRDY_Pos)

#define PMUSTS_VDD5EXTRDY_(x)  (((x) << PMUSTS_VDD5EXTRDY_Pos) & PMUSTS_VDD5EXTRDY_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PMUSTS          CPRDY
  *  @access     HV->PMUSTS
  *  @brief      Pre-driver charge-pump ready
  */
#define PMUSTS_CPRDY_Pos  (9)
#define PMUSTS_CPRDY_Msk  (0x1U << PMUSTS_CPRDY_Pos)

#define PMUSTS_CPRDY_NOT_READY  ((0x0U) << PMUSTS_CPRDY_Pos)
#define PMUSTS_CPRDY_READY      ((0x1U) << PMUSTS_CPRDY_Pos)

#define PMUSTS_CPRDY_(x)  (((x) << PMUSTS_CPRDY_Pos) & PMUSTS_CPRDY_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           CYCSENSECTL     DEADCNT
  *  @access     HV->CYCSENSECTL
  *  @brief      Dead time is (DEADCNT+1) * 2ms
  */
#define CYCSENSECTL_DEADCNT_Pos  (0)
#define CYCSENSECTL_DEADCNT_Msk  (0x3FFU << CYCSENSECTL_DEADCNT_Pos)

#define CYCSENSECTL_DEADCNT_(x)  (((x) << CYCSENSECTL_DEADCNT_Pos) & CYCSENSECTL_DEADCNT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           CYCSENSECTL     RAMPCNT
  *  @access     HV->CYCSENSECTL
  *  @brief      VDD5EXT power on time after the dead time and before the sense window,  which is
  *              (RAMPCNT+1) * 2ms
  *              This feature is enabled only when the VDD5EXTEN bit in PMUCTL is set as 1 during
  *              stop entry
  */
#define CYCSENSECTL_RAMPCNT_Pos  (10)
#define CYCSENSECTL_RAMPCNT_Msk  (0x3U << CYCSENSECTL_RAMPCNT_Pos)

#define CYCSENSECTL_RAMPCNT_(x)  (((x) << CYCSENSECTL_RAMPCNT_Pos) & CYCSENSECTL_RAMPCNT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           CYCSENSECTL     SENSECNT
  *  @access     HV->CYCSENSECTL
  *  @brief      Sense window is (SENSECNT+1) * 10us
  */
#define CYCSENSECTL_SENSECNT_Pos  (12)
#define CYCSENSECTL_SENSECNT_Msk  (0xFU << CYCSENSECTL_SENSECNT_Pos)

#define CYCSENSECTL_SENSECNT_(x)  (((x) << CYCSENSECTL_SENSECNT_Pos) & CYCSENSECTL_SENSECNT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           CYCWKUPCTL      DEADCNT
  *  @access     HV->CYCWKUPCTL
  *  @brief      Dead time is (DEADCNT+1) * 2ms
  */
#define CYCWKUPCTL_DEADCNT_Pos  (0)
#define CYCWKUPCTL_DEADCNT_Msk  (0x3FFU << CYCWKUPCTL_DEADCNT_Pos)

#define CYCWKUPCTL_DEADCNT_(x)  (((x) << CYCWKUPCTL_DEADCNT_Pos) & CYCWKUPCTL_DEADCNT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           MONCTL          EN
  *  @access     HV->MONCTL
  *  @brief      MON enable
  *              This bit will be also written as 1 when write 1 to PMUCTL.MONWKUPEN.
  *              In sleep mode, this bit is masked as 0 if MON wakeup is disabled.
  *              In stop mode, this bit is masked as 0 if both MON wakeup and cyclic sense wakeup
  *              are disabled.
  */
#define MONCTL_EN_Pos  (0)
#define MONCTL_EN_Msk  (0x1U << MONCTL_EN_Pos)

#define MONCTL_EN_DISABLE  ((0x0U) << MONCTL_EN_Pos)
#define MONCTL_EN_ENABLE   ((0x1U) << MONCTL_EN_Pos)

#define MONCTL_EN_(x)  (((x) << MONCTL_EN_Pos) & MONCTL_EN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           MONCTL          PULLMODE
  *  @access     HV->MONCTL
  *  @brief      MON pin pull mode
  */
#define MONCTL_PULLMODE_Pos  (1)
#define MONCTL_PULLMODE_Msk  (0x3U << MONCTL_PULLMODE_Pos)

#define MONCTL_PULLMODE_PULL_DISABLE   ((0x00U) << MONCTL_PULLMODE_Pos)
#define MONCTL_PULLMODE_PULL_DOWN      ((0x01U) << MONCTL_PULLMODE_Pos)
#define MONCTL_PULLMODE_PULL_UP        ((0x02U) << MONCTL_PULLMODE_Pos)
#define MONCTL_PULLMODE_PULL_ADAPTIVE  ((0x03U) << MONCTL_PULLMODE_Pos)

#define MONCTL_PULLMODE_(x)  (((x) << MONCTL_PULLMODE_Pos) & MONCTL_PULLMODE_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           MONCTL          WKUPPOL
  *  @access     HV->MONCTL
  *  @brief      MON pin polarity to trigger the asynchronous MON wakeup
  *              It does not affect the polarity when MON is used for cyclic sense wakeup
  */
#define MONCTL_WKUPPOL_Pos  (3)
#define MONCTL_WKUPPOL_Msk  (0x1U << MONCTL_WKUPPOL_Pos)

#define MONCTL_WKUPPOL_ACTIVE_LOW   ((0x0U) << MONCTL_WKUPPOL_Pos)
#define MONCTL_WKUPPOL_ACTIVE_HIGH  ((0x1U) << MONCTL_WKUPPOL_Pos)

#define MONCTL_WKUPPOL_(x)  (((x) << MONCTL_WKUPPOL_Pos) & MONCTL_WKUPPOL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VBATUV
  *  @access     HV->TZEVTSTS0
  *  @brief      VBAT under-voltage event status (without latch)
  */
#define TZEVTSTS0_VBATUV_Pos  (0)
#define TZEVTSTS0_VBATUV_Msk  (0x1U << TZEVTSTS0_VBATUV_Pos)

#define TZEVTSTS0_VBATUV_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VBATUV_Pos)
#define TZEVTSTS0_VBATUV_OCCUR      ((0x1U) << TZEVTSTS0_VBATUV_Pos)

#define TZEVTSTS0_VBATUV_(x)  (((x) << TZEVTSTS0_VBATUV_Pos) & TZEVTSTS0_VBATUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VBATOV
  *  @access     HV->TZEVTSTS0
  *  @brief      VBAT over-voltage event status (without latch)
  */
#define TZEVTSTS0_VBATOV_Pos  (1)
#define TZEVTSTS0_VBATOV_Msk  (0x1U << TZEVTSTS0_VBATOV_Pos)

#define TZEVTSTS0_VBATOV_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VBATOV_Pos)
#define TZEVTSTS0_VBATOV_OCCUR      ((0x1U) << TZEVTSTS0_VBATOV_Pos)

#define TZEVTSTS0_VBATOV_(x)  (((x) << TZEVTSTS0_VBATOV_Pos) & TZEVTSTS0_VBATOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VDD5UV
  *  @access     HV->TZEVTSTS0
  *  @brief      VDD5 under-voltage event status (without latch)
  */
#define TZEVTSTS0_VDD5UV_Pos  (2)
#define TZEVTSTS0_VDD5UV_Msk  (0x1U << TZEVTSTS0_VDD5UV_Pos)

#define TZEVTSTS0_VDD5UV_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VDD5UV_Pos)
#define TZEVTSTS0_VDD5UV_OCCUR      ((0x1U) << TZEVTSTS0_VDD5UV_Pos)

#define TZEVTSTS0_VDD5UV_(x)  (((x) << TZEVTSTS0_VDD5UV_Pos) & TZEVTSTS0_VDD5UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VDD5OV
  *  @access     HV->TZEVTSTS0
  *  @brief      VDD5 over-voltage event status (without latch)
  */
#define TZEVTSTS0_VDD5OV_Pos  (3)
#define TZEVTSTS0_VDD5OV_Msk  (0x1U << TZEVTSTS0_VDD5OV_Pos)

#define TZEVTSTS0_VDD5OV_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VDD5OV_Pos)
#define TZEVTSTS0_VDD5OV_OCCUR      ((0x1U) << TZEVTSTS0_VDD5OV_Pos)

#define TZEVTSTS0_VDD5OV_(x)  (((x) << TZEVTSTS0_VDD5OV_Pos) & TZEVTSTS0_VDD5OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VDD5EXTUV
  *  @access     HV->TZEVTSTS0
  *  @brief      VDD5EXT under-voltage event status (without latch)
  */
#define TZEVTSTS0_VDD5EXTUV_Pos  (4)
#define TZEVTSTS0_VDD5EXTUV_Msk  (0x1U << TZEVTSTS0_VDD5EXTUV_Pos)

#define TZEVTSTS0_VDD5EXTUV_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VDD5EXTUV_Pos)
#define TZEVTSTS0_VDD5EXTUV_OCCUR      ((0x1U) << TZEVTSTS0_VDD5EXTUV_Pos)

#define TZEVTSTS0_VDD5EXTUV_(x)  (((x) << TZEVTSTS0_VDD5EXTUV_Pos) & TZEVTSTS0_VDD5EXTUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VDD5EXTOV
  *  @access     HV->TZEVTSTS0
  *  @brief      VDD5EXT over-voltage event status (without latch)
  */
#define TZEVTSTS0_VDD5EXTOV_Pos  (5)
#define TZEVTSTS0_VDD5EXTOV_Msk  (0x1U << TZEVTSTS0_VDD5EXTOV_Pos)

#define TZEVTSTS0_VDD5EXTOV_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VDD5EXTOV_Pos)
#define TZEVTSTS0_VDD5EXTOV_OCCUR      ((0x1U) << TZEVTSTS0_VDD5EXTOV_Pos)

#define TZEVTSTS0_VDD5EXTOV_(x)  (((x) << TZEVTSTS0_VDD5EXTOV_Pos) & TZEVTSTS0_VDD5EXTOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VDD3UV
  *  @access     HV->TZEVTSTS0
  *  @brief      VDD3 under-voltage event status (without latch)
  */
#define TZEVTSTS0_VDD3UV_Pos  (6)
#define TZEVTSTS0_VDD3UV_Msk  (0x1U << TZEVTSTS0_VDD3UV_Pos)

#define TZEVTSTS0_VDD3UV_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VDD3UV_Pos)
#define TZEVTSTS0_VDD3UV_OCCUR      ((0x1U) << TZEVTSTS0_VDD3UV_Pos)

#define TZEVTSTS0_VDD3UV_(x)  (((x) << TZEVTSTS0_VDD3UV_Pos) & TZEVTSTS0_VDD3UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VDD3OV
  *  @access     HV->TZEVTSTS0
  *  @brief      VDD3 over-voltage event status (without latch)
  */
#define TZEVTSTS0_VDD3OV_Pos  (7)
#define TZEVTSTS0_VDD3OV_Msk  (0x1U << TZEVTSTS0_VDD3OV_Pos)

#define TZEVTSTS0_VDD3OV_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VDD3OV_Pos)
#define TZEVTSTS0_VDD3OV_OCCUR      ((0x1U) << TZEVTSTS0_VDD3OV_Pos)

#define TZEVTSTS0_VDD3OV_(x)  (((x) << TZEVTSTS0_VDD3OV_Pos) & TZEVTSTS0_VDD3OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       PMUOTWARN
  *  @access     HV->TZEVTSTS0
  *  @brief      PMU over-temperature warning event status (without latch)
  */
#define TZEVTSTS0_PMUOTWARN_Pos  (8)
#define TZEVTSTS0_PMUOTWARN_Msk  (0x1U << TZEVTSTS0_PMUOTWARN_Pos)

#define TZEVTSTS0_PMUOTWARN_NOT_OCCUR  ((0x0U) << TZEVTSTS0_PMUOTWARN_Pos)
#define TZEVTSTS0_PMUOTWARN_OCCUR      ((0x1U) << TZEVTSTS0_PMUOTWARN_Pos)

#define TZEVTSTS0_PMUOTWARN_(x)  (((x) << TZEVTSTS0_PMUOTWARN_Pos) & TZEVTSTS0_PMUOTWARN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VDD5EXTOC
  *  @access     HV->TZEVTSTS0
  *  @brief      VDD5EXT over-current event status (without latch)
  */
#define TZEVTSTS0_VDD5EXTOC_Pos  (9)
#define TZEVTSTS0_VDD5EXTOC_Msk  (0x1U << TZEVTSTS0_VDD5EXTOC_Pos)

#define TZEVTSTS0_VDD5EXTOC_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VDD5EXTOC_Pos)
#define TZEVTSTS0_VDD5EXTOC_OCCUR      ((0x1U) << TZEVTSTS0_VDD5EXTOC_Pos)

#define TZEVTSTS0_VDD5EXTOC_(x)  (((x) << TZEVTSTS0_VDD5EXTOC_Pos) & TZEVTSTS0_VDD5EXTOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VDD5OC
  *  @access     HV->TZEVTSTS0
  *  @brief      VDD5 over-current event status (without latch)
  */
#define TZEVTSTS0_VDD5OC_Pos  (10)
#define TZEVTSTS0_VDD5OC_Msk  (0x1U << TZEVTSTS0_VDD5OC_Pos)

#define TZEVTSTS0_VDD5OC_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VDD5OC_Pos)
#define TZEVTSTS0_VDD5OC_OCCUR      ((0x1U) << TZEVTSTS0_VDD5OC_Pos)

#define TZEVTSTS0_VDD5OC_(x)  (((x) << TZEVTSTS0_VDD5OC_Pos) & TZEVTSTS0_VDD5OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       VDD3OC
  *  @access     HV->TZEVTSTS0
  *  @brief      VDD3 over-current event status (without latch)
  */
#define TZEVTSTS0_VDD3OC_Pos  (11)
#define TZEVTSTS0_VDD3OC_Msk  (0x1U << TZEVTSTS0_VDD3OC_Pos)

#define TZEVTSTS0_VDD3OC_NOT_OCCUR  ((0x0U) << TZEVTSTS0_VDD3OC_Pos)
#define TZEVTSTS0_VDD3OC_OCCUR      ((0x1U) << TZEVTSTS0_VDD3OC_Pos)

#define TZEVTSTS0_VDD3OC_(x)  (((x) << TZEVTSTS0_VDD3OC_Pos) & TZEVTSTS0_VDD3OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       CLKERR
  *  @access     HV->TZEVTSTS0
  *  @brief      Clock error event status (without latch)
  *              This bit is the logic OR of LPRCOERR and RCOERR bits in TZEVTSTS1
  */
#define TZEVTSTS0_CLKERR_Pos  (12)
#define TZEVTSTS0_CLKERR_Msk  (0x1U << TZEVTSTS0_CLKERR_Pos)

#define TZEVTSTS0_CLKERR_NOT_OCCUR  ((0x0U) << TZEVTSTS0_CLKERR_Pos)
#define TZEVTSTS0_CLKERR_OCCUR      ((0x1U) << TZEVTSTS0_CLKERR_Pos)

#define TZEVTSTS0_CLKERR_(x)  (((x) << TZEVTSTS0_CLKERR_Pos) & TZEVTSTS0_CLKERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       LINTXDTIMEOUT
  *  @access     HV->TZEVTSTS0
  *  @brief      LIN TXD timeout event status (without latch)
  *              It is asserted when TXD holds dominant state for over 12ms
  */
#define TZEVTSTS0_LINTXDTIMEOUT_Pos  (13)
#define TZEVTSTS0_LINTXDTIMEOUT_Msk  (0x1U << TZEVTSTS0_LINTXDTIMEOUT_Pos)

#define TZEVTSTS0_LINTXDTIMEOUT_NOT_OCCUR  ((0x0U) << TZEVTSTS0_LINTXDTIMEOUT_Pos)
#define TZEVTSTS0_LINTXDTIMEOUT_OCCUR      ((0x1U) << TZEVTSTS0_LINTXDTIMEOUT_Pos)

#define TZEVTSTS0_LINTXDTIMEOUT_(x)  (((x) << TZEVTSTS0_LINTXDTIMEOUT_Pos) & TZEVTSTS0_LINTXDTIMEOUT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       LINOC
  *  @access     HV->TZEVTSTS0
  *  @brief      LIN transceiver over-current event status (without latch)
  */
#define TZEVTSTS0_LINOC_Pos  (14)
#define TZEVTSTS0_LINOC_Msk  (0x1U << TZEVTSTS0_LINOC_Pos)

#define TZEVTSTS0_LINOC_NOT_OCCUR  ((0x0U) << TZEVTSTS0_LINOC_Pos)
#define TZEVTSTS0_LINOC_OCCUR      ((0x1U) << TZEVTSTS0_LINOC_Pos)

#define TZEVTSTS0_LINOC_(x)  (((x) << TZEVTSTS0_LINOC_Pos) & TZEVTSTS0_LINOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS0       LINOT
  *  @access     HV->TZEVTSTS0
  *  @brief      LIN transceiver over-temperature event status (without latch)
  */
#define TZEVTSTS0_LINOT_Pos  (15)
#define TZEVTSTS0_LINOT_Msk  (0x1U << TZEVTSTS0_LINOT_Pos)

#define TZEVTSTS0_LINOT_NOT_OCCUR  ((0x0U) << TZEVTSTS0_LINOT_Pos)
#define TZEVTSTS0_LINOT_OCCUR      ((0x1U) << TZEVTSTS0_LINOT_Pos)

#define TZEVTSTS0_LINOT_(x)  (((x) << TZEVTSTS0_LINOT_Pos) & TZEVTSTS0_LINOT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       PDRVOCLU
  *  @access     HV->TZEVTSTS1
  *  @brief      Pre-driver U-phase low-side over-current event status (without latch)
  *              It is detected by Vds over-voltage of the external FET
  */
#define TZEVTSTS1_PDRVOCLU_Pos  (0)
#define TZEVTSTS1_PDRVOCLU_Msk  (0x1U << TZEVTSTS1_PDRVOCLU_Pos)

#define TZEVTSTS1_PDRVOCLU_NOT_OCCUR  ((0x0U) << TZEVTSTS1_PDRVOCLU_Pos)
#define TZEVTSTS1_PDRVOCLU_OCCUR      ((0x1U) << TZEVTSTS1_PDRVOCLU_Pos)

#define TZEVTSTS1_PDRVOCLU_(x)  (((x) << TZEVTSTS1_PDRVOCLU_Pos) & TZEVTSTS1_PDRVOCLU_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       PDRVOCLV
  *  @access     HV->TZEVTSTS1
  *  @brief      Pre-driver V-phase low-side over-current event status (without latch)
  *              It is detected by Vds over-voltage of the external FET
  */
#define TZEVTSTS1_PDRVOCLV_Pos  (1)
#define TZEVTSTS1_PDRVOCLV_Msk  (0x1U << TZEVTSTS1_PDRVOCLV_Pos)

#define TZEVTSTS1_PDRVOCLV_NOT_OCCUR  ((0x0U) << TZEVTSTS1_PDRVOCLV_Pos)
#define TZEVTSTS1_PDRVOCLV_OCCUR      ((0x1U) << TZEVTSTS1_PDRVOCLV_Pos)

#define TZEVTSTS1_PDRVOCLV_(x)  (((x) << TZEVTSTS1_PDRVOCLV_Pos) & TZEVTSTS1_PDRVOCLV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       PDRVOCLW
  *  @access     HV->TZEVTSTS1
  *  @brief      Pre-driver W-phase low-side over-current event status (without latch)
  *              It is detected by Vds over-voltage of the external FET
  */
#define TZEVTSTS1_PDRVOCLW_Pos  (2)
#define TZEVTSTS1_PDRVOCLW_Msk  (0x1U << TZEVTSTS1_PDRVOCLW_Pos)

#define TZEVTSTS1_PDRVOCLW_NOT_OCCUR  ((0x0U) << TZEVTSTS1_PDRVOCLW_Pos)
#define TZEVTSTS1_PDRVOCLW_OCCUR      ((0x1U) << TZEVTSTS1_PDRVOCLW_Pos)

#define TZEVTSTS1_PDRVOCLW_(x)  (((x) << TZEVTSTS1_PDRVOCLW_Pos) & TZEVTSTS1_PDRVOCLW_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       PDRVOCHU
  *  @access     HV->TZEVTSTS1
  *  @brief      Pre-driver U-phase high-side over-current event status (without latch)
  *              It is detected by Vds over-voltage of the external FET
  */
#define TZEVTSTS1_PDRVOCHU_Pos  (3)
#define TZEVTSTS1_PDRVOCHU_Msk  (0x1U << TZEVTSTS1_PDRVOCHU_Pos)

#define TZEVTSTS1_PDRVOCHU_NOT_OCCUR  ((0x0U) << TZEVTSTS1_PDRVOCHU_Pos)
#define TZEVTSTS1_PDRVOCHU_OCCUR      ((0x1U) << TZEVTSTS1_PDRVOCHU_Pos)

#define TZEVTSTS1_PDRVOCHU_(x)  (((x) << TZEVTSTS1_PDRVOCHU_Pos) & TZEVTSTS1_PDRVOCHU_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       PDRVOCHV
  *  @access     HV->TZEVTSTS1
  *  @brief      Pre-driver V-phase high-side over-current event status (without latch)
  *              It is detected by Vds over-voltage of the external FET
  */
#define TZEVTSTS1_PDRVOCHV_Pos  (4)
#define TZEVTSTS1_PDRVOCHV_Msk  (0x1U << TZEVTSTS1_PDRVOCHV_Pos)

#define TZEVTSTS1_PDRVOCHV_NOT_OCCUR  ((0x0U) << TZEVTSTS1_PDRVOCHV_Pos)
#define TZEVTSTS1_PDRVOCHV_OCCUR      ((0x1U) << TZEVTSTS1_PDRVOCHV_Pos)

#define TZEVTSTS1_PDRVOCHV_(x)  (((x) << TZEVTSTS1_PDRVOCHV_Pos) & TZEVTSTS1_PDRVOCHV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       PDRVOCHW
  *  @access     HV->TZEVTSTS1
  *  @brief      Pre-driver W-phase high-side over-current event status (without latch)
  *              It is detected by Vds over-voltage of the external FET
  */
#define TZEVTSTS1_PDRVOCHW_Pos  (5)
#define TZEVTSTS1_PDRVOCHW_Msk  (0x1U << TZEVTSTS1_PDRVOCHW_Pos)

#define TZEVTSTS1_PDRVOCHW_NOT_OCCUR  ((0x0U) << TZEVTSTS1_PDRVOCHW_Pos)
#define TZEVTSTS1_PDRVOCHW_OCCUR      ((0x1U) << TZEVTSTS1_PDRVOCHW_Pos)

#define TZEVTSTS1_PDRVOCHW_(x)  (((x) << TZEVTSTS1_PDRVOCHW_Pos) & TZEVTSTS1_PDRVOCHW_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       VCPUV
  *  @access     HV->TZEVTSTS1
  *  @brief      Pre-driver VCP under-voltage event status (without latch)
  */
#define TZEVTSTS1_VCPUV_Pos  (6)
#define TZEVTSTS1_VCPUV_Msk  (0x1U << TZEVTSTS1_VCPUV_Pos)

#define TZEVTSTS1_VCPUV_NOT_OCCUR  ((0x0U) << TZEVTSTS1_VCPUV_Pos)
#define TZEVTSTS1_VCPUV_OCCUR      ((0x1U) << TZEVTSTS1_VCPUV_Pos)

#define TZEVTSTS1_VCPUV_(x)  (((x) << TZEVTSTS1_VCPUV_Pos) & TZEVTSTS1_VCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       VCPOV
  *  @access     HV->TZEVTSTS1
  *  @brief      Pre-driver VCP over-voltage event status (without latch)
  */
#define TZEVTSTS1_VCPOV_Pos  (7)
#define TZEVTSTS1_VCPOV_Msk  (0x1U << TZEVTSTS1_VCPOV_Pos)

#define TZEVTSTS1_VCPOV_NOT_OCCUR  ((0x0U) << TZEVTSTS1_VCPOV_Pos)
#define TZEVTSTS1_VCPOV_OCCUR      ((0x1U) << TZEVTSTS1_VCPOV_Pos)

#define TZEVTSTS1_VCPOV_(x)  (((x) << TZEVTSTS1_VCPOV_Pos) & TZEVTSTS1_VCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       LPRCOERR
  *  @access     HV->TZEVTSTS1
  *  @brief      100kHz LPRCO error event status (without latch)
  */
#define TZEVTSTS1_LPRCOERR_Pos  (8)
#define TZEVTSTS1_LPRCOERR_Msk  (0x1U << TZEVTSTS1_LPRCOERR_Pos)

#define TZEVTSTS1_LPRCOERR_NOT_OCCUR  ((0x0U) << TZEVTSTS1_LPRCOERR_Pos)
#define TZEVTSTS1_LPRCOERR_OCCUR      ((0x1U) << TZEVTSTS1_LPRCOERR_Pos)

#define TZEVTSTS1_LPRCOERR_(x)  (((x) << TZEVTSTS1_LPRCOERR_Pos) & TZEVTSTS1_LPRCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       RCOERR
  *  @access     HV->TZEVTSTS1
  *  @brief      40MHz RCO error event status (without latch)
  */
#define TZEVTSTS1_RCOERR_Pos  (9)
#define TZEVTSTS1_RCOERR_Msk  (0x1U << TZEVTSTS1_RCOERR_Pos)

#define TZEVTSTS1_RCOERR_NOT_OCCUR  ((0x0U) << TZEVTSTS1_RCOERR_Pos)
#define TZEVTSTS1_RCOERR_OCCUR      ((0x1U) << TZEVTSTS1_RCOERR_Pos)

#define TZEVTSTS1_RCOERR_(x)  (((x) << TZEVTSTS1_RCOERR_Pos) & TZEVTSTS1_RCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       VBATCPUV
  *  @access     HV->TZEVTSTS1
  *  @brief      Pre-driver VBATCP under-voltage event status (without latch)
  */
#define TZEVTSTS1_VBATCPUV_Pos  (10)
#define TZEVTSTS1_VBATCPUV_Msk  (0x1U << TZEVTSTS1_VBATCPUV_Pos)

#define TZEVTSTS1_VBATCPUV_NOT_OCCUR  ((0x0U) << TZEVTSTS1_VBATCPUV_Pos)
#define TZEVTSTS1_VBATCPUV_OCCUR      ((0x1U) << TZEVTSTS1_VBATCPUV_Pos)

#define TZEVTSTS1_VBATCPUV_(x)  (((x) << TZEVTSTS1_VBATCPUV_Pos) & TZEVTSTS1_VBATCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTSTS1       VBATCPOV
  *  @access     HV->TZEVTSTS1
  *  @brief      Pre-driver VBATCP over-voltage event status (without latch)
  */
#define TZEVTSTS1_VBATCPOV_Pos  (11)
#define TZEVTSTS1_VBATCPOV_Msk  (0x1U << TZEVTSTS1_VBATCPOV_Pos)

#define TZEVTSTS1_VBATCPOV_NOT_OCCUR  ((0x0U) << TZEVTSTS1_VBATCPOV_Pos)
#define TZEVTSTS1_VBATCPOV_OCCUR      ((0x1U) << TZEVTSTS1_VBATCPOV_Pos)

#define TZEVTSTS1_VBATCPOV_(x)  (((x) << TZEVTSTS1_VBATCPOV_Pos) & TZEVTSTS1_VBATCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VBATUV
  *  @access     HV->TZIE0
  *  @brief      VBAT under-voltage event interrupt enable
  */
#define TZIE0_VBATUV_Pos  (0)
#define TZIE0_VBATUV_Msk  (0x1U << TZIE0_VBATUV_Pos)

#define TZIE0_VBATUV_DISABLE  ((0x0U) << TZIE0_VBATUV_Pos)
#define TZIE0_VBATUV_ENABLE   ((0x1U) << TZIE0_VBATUV_Pos)

#define TZIE0_VBATUV_(x)  (((x) << TZIE0_VBATUV_Pos) & TZIE0_VBATUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VBATOV
  *  @access     HV->TZIE0
  *  @brief      VBAT over-voltage event interrupt enable
  */
#define TZIE0_VBATOV_Pos  (1)
#define TZIE0_VBATOV_Msk  (0x1U << TZIE0_VBATOV_Pos)

#define TZIE0_VBATOV_DISABLE  ((0x0U) << TZIE0_VBATOV_Pos)
#define TZIE0_VBATOV_ENABLE   ((0x1U) << TZIE0_VBATOV_Pos)

#define TZIE0_VBATOV_(x)  (((x) << TZIE0_VBATOV_Pos) & TZIE0_VBATOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VDD5UV
  *  @access     HV->TZIE0
  *  @brief      VDD5 under-voltage event interrupt enable
  */
#define TZIE0_VDD5UV_Pos  (2)
#define TZIE0_VDD5UV_Msk  (0x1U << TZIE0_VDD5UV_Pos)

#define TZIE0_VDD5UV_DISABLE  ((0x0U) << TZIE0_VDD5UV_Pos)
#define TZIE0_VDD5UV_ENABLE   ((0x1U) << TZIE0_VDD5UV_Pos)

#define TZIE0_VDD5UV_(x)  (((x) << TZIE0_VDD5UV_Pos) & TZIE0_VDD5UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VDD5OV
  *  @access     HV->TZIE0
  *  @brief      VDD5 over-voltage event interrupt enable
  */
#define TZIE0_VDD5OV_Pos  (3)
#define TZIE0_VDD5OV_Msk  (0x1U << TZIE0_VDD5OV_Pos)

#define TZIE0_VDD5OV_DISABLE  ((0x0U) << TZIE0_VDD5OV_Pos)
#define TZIE0_VDD5OV_ENABLE   ((0x1U) << TZIE0_VDD5OV_Pos)

#define TZIE0_VDD5OV_(x)  (((x) << TZIE0_VDD5OV_Pos) & TZIE0_VDD5OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VDD5EXTUV
  *  @access     HV->TZIE0
  *  @brief      VDD5EXT under-voltage event interrupt enable
  */
#define TZIE0_VDD5EXTUV_Pos  (4)
#define TZIE0_VDD5EXTUV_Msk  (0x1U << TZIE0_VDD5EXTUV_Pos)

#define TZIE0_VDD5EXTUV_DISABLE  ((0x0U) << TZIE0_VDD5EXTUV_Pos)
#define TZIE0_VDD5EXTUV_ENABLE   ((0x1U) << TZIE0_VDD5EXTUV_Pos)

#define TZIE0_VDD5EXTUV_(x)  (((x) << TZIE0_VDD5EXTUV_Pos) & TZIE0_VDD5EXTUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VDD5EXTOV
  *  @access     HV->TZIE0
  *  @brief      VDD5EXT over-voltage event interrupt enable
  */
#define TZIE0_VDD5EXTOV_Pos  (5)
#define TZIE0_VDD5EXTOV_Msk  (0x1U << TZIE0_VDD5EXTOV_Pos)

#define TZIE0_VDD5EXTOV_DISABLE  ((0x0U) << TZIE0_VDD5EXTOV_Pos)
#define TZIE0_VDD5EXTOV_ENABLE   ((0x1U) << TZIE0_VDD5EXTOV_Pos)

#define TZIE0_VDD5EXTOV_(x)  (((x) << TZIE0_VDD5EXTOV_Pos) & TZIE0_VDD5EXTOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VDD3UV
  *  @access     HV->TZIE0
  *  @brief      VDD3 under-voltage event interrupt enable
  */
#define TZIE0_VDD3UV_Pos  (6)
#define TZIE0_VDD3UV_Msk  (0x1U << TZIE0_VDD3UV_Pos)

#define TZIE0_VDD3UV_DISABLE  ((0x0U) << TZIE0_VDD3UV_Pos)
#define TZIE0_VDD3UV_ENABLE   ((0x1U) << TZIE0_VDD3UV_Pos)

#define TZIE0_VDD3UV_(x)  (((x) << TZIE0_VDD3UV_Pos) & TZIE0_VDD3UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VDD3OV
  *  @access     HV->TZIE0
  *  @brief      VDD3 over-voltage event interrupt enable
  */
#define TZIE0_VDD3OV_Pos  (7)
#define TZIE0_VDD3OV_Msk  (0x1U << TZIE0_VDD3OV_Pos)

#define TZIE0_VDD3OV_DISABLE  ((0x0U) << TZIE0_VDD3OV_Pos)
#define TZIE0_VDD3OV_ENABLE   ((0x1U) << TZIE0_VDD3OV_Pos)

#define TZIE0_VDD3OV_(x)  (((x) << TZIE0_VDD3OV_Pos) & TZIE0_VDD3OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           PMUOTWARN
  *  @access     HV->TZIE0
  *  @brief      PMU over-temperature warning event interrupt enable
  */
#define TZIE0_PMUOTWARN_Pos  (8)
#define TZIE0_PMUOTWARN_Msk  (0x1U << TZIE0_PMUOTWARN_Pos)

#define TZIE0_PMUOTWARN_DISABLE  ((0x0U) << TZIE0_PMUOTWARN_Pos)
#define TZIE0_PMUOTWARN_ENABLE   ((0x1U) << TZIE0_PMUOTWARN_Pos)

#define TZIE0_PMUOTWARN_(x)  (((x) << TZIE0_PMUOTWARN_Pos) & TZIE0_PMUOTWARN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VDD5EXTOC
  *  @access     HV->TZIE0
  *  @brief      VDD5EXT over-current event flag
  */
#define TZIE0_VDD5EXTOC_Pos  (9)
#define TZIE0_VDD5EXTOC_Msk  (0x1U << TZIE0_VDD5EXTOC_Pos)

#define TZIE0_VDD5EXTOC_DISABLE  ((0x0U) << TZIE0_VDD5EXTOC_Pos)
#define TZIE0_VDD5EXTOC_ENABLE   ((0x1U) << TZIE0_VDD5EXTOC_Pos)

#define TZIE0_VDD5EXTOC_(x)  (((x) << TZIE0_VDD5EXTOC_Pos) & TZIE0_VDD5EXTOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VDD5OC
  *  @access     HV->TZIE0
  *  @brief      VDD5 over-current event interrupt enable
  */
#define TZIE0_VDD5OC_Pos  (10)
#define TZIE0_VDD5OC_Msk  (0x1U << TZIE0_VDD5OC_Pos)

#define TZIE0_VDD5OC_DISABLE  ((0x0U) << TZIE0_VDD5OC_Pos)
#define TZIE0_VDD5OC_ENABLE   ((0x1U) << TZIE0_VDD5OC_Pos)

#define TZIE0_VDD5OC_(x)  (((x) << TZIE0_VDD5OC_Pos) & TZIE0_VDD5OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           VDD3OC
  *  @access     HV->TZIE0
  *  @brief      VDD3 over-current event interrupt enable
  */
#define TZIE0_VDD3OC_Pos  (11)
#define TZIE0_VDD3OC_Msk  (0x1U << TZIE0_VDD3OC_Pos)

#define TZIE0_VDD3OC_DISABLE  ((0x0U) << TZIE0_VDD3OC_Pos)
#define TZIE0_VDD3OC_ENABLE   ((0x1U) << TZIE0_VDD3OC_Pos)

#define TZIE0_VDD3OC_(x)  (((x) << TZIE0_VDD3OC_Pos) & TZIE0_VDD3OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           CLKERR
  *  @access     HV->TZIE0
  *  @brief      Clock error event interrupt enable
  */
#define TZIE0_CLKERR_Pos  (12)
#define TZIE0_CLKERR_Msk  (0x1U << TZIE0_CLKERR_Pos)

#define TZIE0_CLKERR_DISABLE  ((0x0U) << TZIE0_CLKERR_Pos)
#define TZIE0_CLKERR_ENABLE   ((0x1U) << TZIE0_CLKERR_Pos)

#define TZIE0_CLKERR_(x)  (((x) << TZIE0_CLKERR_Pos) & TZIE0_CLKERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           LINTXDTIMEOUT
  *  @access     HV->TZIE0
  *  @brief      LIN TXD timeout event interrupt enable
  */
#define TZIE0_LINTXDTIMEOUT_Pos  (13)
#define TZIE0_LINTXDTIMEOUT_Msk  (0x1U << TZIE0_LINTXDTIMEOUT_Pos)

#define TZIE0_LINTXDTIMEOUT_DISABLE  ((0x0U) << TZIE0_LINTXDTIMEOUT_Pos)
#define TZIE0_LINTXDTIMEOUT_ENABLE   ((0x1U) << TZIE0_LINTXDTIMEOUT_Pos)

#define TZIE0_LINTXDTIMEOUT_(x)  (((x) << TZIE0_LINTXDTIMEOUT_Pos) & TZIE0_LINTXDTIMEOUT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           LINOC
  *  @access     HV->TZIE0
  *  @brief      LIN transceiver over-current event interrupt enable
  */
#define TZIE0_LINOC_Pos  (14)
#define TZIE0_LINOC_Msk  (0x1U << TZIE0_LINOC_Pos)

#define TZIE0_LINOC_DISABLE  ((0x0U) << TZIE0_LINOC_Pos)
#define TZIE0_LINOC_ENABLE   ((0x1U) << TZIE0_LINOC_Pos)

#define TZIE0_LINOC_(x)  (((x) << TZIE0_LINOC_Pos) & TZIE0_LINOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE0           LINOT
  *  @access     HV->TZIE0
  *  @brief      LIN transceiver over-temperature event interrupt enable
  */
#define TZIE0_LINOT_Pos  (15)
#define TZIE0_LINOT_Msk  (0x1U << TZIE0_LINOT_Pos)

#define TZIE0_LINOT_DISABLE  ((0x0U) << TZIE0_LINOT_Pos)
#define TZIE0_LINOT_ENABLE   ((0x1U) << TZIE0_LINOT_Pos)

#define TZIE0_LINOT_(x)  (((x) << TZIE0_LINOT_Pos) & TZIE0_LINOT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VBATUV
  *  @access     HV->TZIC0
  *  @brief      VBAT under-voltage event interrupt clear
  */
#define TZIC0_VBATUV_Pos  (0)
#define TZIC0_VBATUV_Msk  (0x1U << TZIC0_VBATUV_Pos)

#define TZIC0_VBATUV_NO_EFFECT  ((0x0U) << TZIC0_VBATUV_Pos)
#define TZIC0_VBATUV_CLEAR      ((0x1U) << TZIC0_VBATUV_Pos)

#define TZIC0_VBATUV_(x)  (((x) << TZIC0_VBATUV_Pos) & TZIC0_VBATUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VBATOV
  *  @access     HV->TZIC0
  *  @brief      VBAT over-voltage event interrupt clear
  */
#define TZIC0_VBATOV_Pos  (1)
#define TZIC0_VBATOV_Msk  (0x1U << TZIC0_VBATOV_Pos)

#define TZIC0_VBATOV_NO_EFFECT  ((0x0U) << TZIC0_VBATOV_Pos)
#define TZIC0_VBATOV_CLEAR      ((0x1U) << TZIC0_VBATOV_Pos)

#define TZIC0_VBATOV_(x)  (((x) << TZIC0_VBATOV_Pos) & TZIC0_VBATOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VDD5UV
  *  @access     HV->TZIC0
  *  @brief      VDD5 under-voltage event interrupt clear
  */
#define TZIC0_VDD5UV_Pos  (2)
#define TZIC0_VDD5UV_Msk  (0x1U << TZIC0_VDD5UV_Pos)

#define TZIC0_VDD5UV_NO_EFFECT  ((0x0U) << TZIC0_VDD5UV_Pos)
#define TZIC0_VDD5UV_CLEAR      ((0x1U) << TZIC0_VDD5UV_Pos)

#define TZIC0_VDD5UV_(x)  (((x) << TZIC0_VDD5UV_Pos) & TZIC0_VDD5UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VDD5OV
  *  @access     HV->TZIC0
  *  @brief      VDD5 over-voltage event interrupt clear
  */
#define TZIC0_VDD5OV_Pos  (3)
#define TZIC0_VDD5OV_Msk  (0x1U << TZIC0_VDD5OV_Pos)

#define TZIC0_VDD5OV_NO_EFFECT  ((0x0U) << TZIC0_VDD5OV_Pos)
#define TZIC0_VDD5OV_CLEAR      ((0x1U) << TZIC0_VDD5OV_Pos)

#define TZIC0_VDD5OV_(x)  (((x) << TZIC0_VDD5OV_Pos) & TZIC0_VDD5OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VDD5EXTUV
  *  @access     HV->TZIC0
  *  @brief      VDD5EXT under-voltage event interrupt clear
  */
#define TZIC0_VDD5EXTUV_Pos  (4)
#define TZIC0_VDD5EXTUV_Msk  (0x1U << TZIC0_VDD5EXTUV_Pos)

#define TZIC0_VDD5EXTUV_NO_EFFECT  ((0x0U) << TZIC0_VDD5EXTUV_Pos)
#define TZIC0_VDD5EXTUV_CLEAR      ((0x1U) << TZIC0_VDD5EXTUV_Pos)

#define TZIC0_VDD5EXTUV_(x)  (((x) << TZIC0_VDD5EXTUV_Pos) & TZIC0_VDD5EXTUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VDD5EXTOV
  *  @access     HV->TZIC0
  *  @brief      VDD5EXT over-voltage event interrupt clear
  */
#define TZIC0_VDD5EXTOV_Pos  (5)
#define TZIC0_VDD5EXTOV_Msk  (0x1U << TZIC0_VDD5EXTOV_Pos)

#define TZIC0_VDD5EXTOV_NO_EFFECT  ((0x0U) << TZIC0_VDD5EXTOV_Pos)
#define TZIC0_VDD5EXTOV_CLEAR      ((0x1U) << TZIC0_VDD5EXTOV_Pos)

#define TZIC0_VDD5EXTOV_(x)  (((x) << TZIC0_VDD5EXTOV_Pos) & TZIC0_VDD5EXTOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VDD3UV
  *  @access     HV->TZIC0
  *  @brief      VDD3 under-voltage event interrupt clear
  */
#define TZIC0_VDD3UV_Pos  (6)
#define TZIC0_VDD3UV_Msk  (0x1U << TZIC0_VDD3UV_Pos)

#define TZIC0_VDD3UV_NO_EFFECT  ((0x0U) << TZIC0_VDD3UV_Pos)
#define TZIC0_VDD3UV_CLEAR      ((0x1U) << TZIC0_VDD3UV_Pos)

#define TZIC0_VDD3UV_(x)  (((x) << TZIC0_VDD3UV_Pos) & TZIC0_VDD3UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VDD3OV
  *  @access     HV->TZIC0
  *  @brief      VDD3 over-voltage event interrupt clear
  */
#define TZIC0_VDD3OV_Pos  (7)
#define TZIC0_VDD3OV_Msk  (0x1U << TZIC0_VDD3OV_Pos)

#define TZIC0_VDD3OV_NO_EFFECT  ((0x0U) << TZIC0_VDD3OV_Pos)
#define TZIC0_VDD3OV_CLEAR      ((0x1U) << TZIC0_VDD3OV_Pos)

#define TZIC0_VDD3OV_(x)  (((x) << TZIC0_VDD3OV_Pos) & TZIC0_VDD3OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           PMUOTWARN
  *  @access     HV->TZIC0
  *  @brief      Over-temperature warning event interrupt clear
  */
#define TZIC0_PMUOTWARN_Pos  (8)
#define TZIC0_PMUOTWARN_Msk  (0x1U << TZIC0_PMUOTWARN_Pos)

#define TZIC0_PMUOTWARN_NO_EFFECT  ((0x0U) << TZIC0_PMUOTWARN_Pos)
#define TZIC0_PMUOTWARN_CLEAR      ((0x1U) << TZIC0_PMUOTWARN_Pos)

#define TZIC0_PMUOTWARN_(x)  (((x) << TZIC0_PMUOTWARN_Pos) & TZIC0_PMUOTWARN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VDD5EXTOC
  *  @access     HV->TZIC0
  *  @brief      VDD5EXT over-current event interrupt clear
  */
#define TZIC0_VDD5EXTOC_Pos  (9)
#define TZIC0_VDD5EXTOC_Msk  (0x1U << TZIC0_VDD5EXTOC_Pos)

#define TZIC0_VDD5EXTOC_NO_EFFECT  ((0x0U) << TZIC0_VDD5EXTOC_Pos)
#define TZIC0_VDD5EXTOC_CLEAR      ((0x1U) << TZIC0_VDD5EXTOC_Pos)

#define TZIC0_VDD5EXTOC_(x)  (((x) << TZIC0_VDD5EXTOC_Pos) & TZIC0_VDD5EXTOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VDD5OC
  *  @access     HV->TZIC0
  *  @brief      VDD5 over-current event interrupt clear
  */
#define TZIC0_VDD5OC_Pos  (10)
#define TZIC0_VDD5OC_Msk  (0x1U << TZIC0_VDD5OC_Pos)

#define TZIC0_VDD5OC_NO_EFFECT  ((0x0U) << TZIC0_VDD5OC_Pos)
#define TZIC0_VDD5OC_CLEAR      ((0x1U) << TZIC0_VDD5OC_Pos)

#define TZIC0_VDD5OC_(x)  (((x) << TZIC0_VDD5OC_Pos) & TZIC0_VDD5OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           VDD3OC
  *  @access     HV->TZIC0
  *  @brief      VDD3 over-current event interrupt clear
  */
#define TZIC0_VDD3OC_Pos  (11)
#define TZIC0_VDD3OC_Msk  (0x1U << TZIC0_VDD3OC_Pos)

#define TZIC0_VDD3OC_NO_EFFECT  ((0x0U) << TZIC0_VDD3OC_Pos)
#define TZIC0_VDD3OC_CLEAR      ((0x1U) << TZIC0_VDD3OC_Pos)

#define TZIC0_VDD3OC_(x)  (((x) << TZIC0_VDD3OC_Pos) & TZIC0_VDD3OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           CLKERR
  *  @access     HV->TZIC0
  *  @brief      Clock error event interrupt clear
  */
#define TZIC0_CLKERR_Pos  (12)
#define TZIC0_CLKERR_Msk  (0x1U << TZIC0_CLKERR_Pos)

#define TZIC0_CLKERR_NO_EFFECT  ((0x0U) << TZIC0_CLKERR_Pos)
#define TZIC0_CLKERR_CLEAR      ((0x1U) << TZIC0_CLKERR_Pos)

#define TZIC0_CLKERR_(x)  (((x) << TZIC0_CLKERR_Pos) & TZIC0_CLKERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           LINTXDTIMEOUT
  *  @access     HV->TZIC0
  *  @brief      LIN TXD timeout event interrupt clear
  */
#define TZIC0_LINTXDTIMEOUT_Pos  (13)
#define TZIC0_LINTXDTIMEOUT_Msk  (0x1U << TZIC0_LINTXDTIMEOUT_Pos)

#define TZIC0_LINTXDTIMEOUT_NO_EFFECT  ((0x0U) << TZIC0_LINTXDTIMEOUT_Pos)
#define TZIC0_LINTXDTIMEOUT_CLEAR      ((0x1U) << TZIC0_LINTXDTIMEOUT_Pos)

#define TZIC0_LINTXDTIMEOUT_(x)  (((x) << TZIC0_LINTXDTIMEOUT_Pos) & TZIC0_LINTXDTIMEOUT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           LINOC
  *  @access     HV->TZIC0
  *  @brief      LIN transceiver over-current event interrupt clear
  */
#define TZIC0_LINOC_Pos  (14)
#define TZIC0_LINOC_Msk  (0x1U << TZIC0_LINOC_Pos)

#define TZIC0_LINOC_NO_EFFECT  ((0x0U) << TZIC0_LINOC_Pos)
#define TZIC0_LINOC_CLEAR      ((0x1U) << TZIC0_LINOC_Pos)

#define TZIC0_LINOC_(x)  (((x) << TZIC0_LINOC_Pos) & TZIC0_LINOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC0           LINOT
  *  @access     HV->TZIC0
  *  @brief      LIN transceiver over-temperature event interrupt clear
  */
#define TZIC0_LINOT_Pos  (15)
#define TZIC0_LINOT_Msk  (0x1U << TZIC0_LINOT_Pos)

#define TZIC0_LINOT_NO_EFFECT  ((0x0U) << TZIC0_LINOT_Pos)
#define TZIC0_LINOT_CLEAR      ((0x1U) << TZIC0_LINOT_Pos)

#define TZIC0_LINOT_(x)  (((x) << TZIC0_LINOT_Pos) & TZIC0_LINOT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VBATUV
  *  @access     HV->TZIF0
  *  @brief      Latched VBAT under-voltage event interrupt flag
  */
#define TZIF0_VBATUV_Pos  (0)
#define TZIF0_VBATUV_Msk  (0x1U << TZIF0_VBATUV_Pos)

#define TZIF0_VBATUV_NOT_OCCUR  ((0x0U) << TZIF0_VBATUV_Pos)
#define TZIF0_VBATUV_OCCUR      ((0x1U) << TZIF0_VBATUV_Pos)

#define TZIF0_VBATUV_(x)  (((x) << TZIF0_VBATUV_Pos) & TZIF0_VBATUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VBATOV
  *  @access     HV->TZIF0
  *  @brief      Latched VBAT over-voltage event interrupt flag
  */
#define TZIF0_VBATOV_Pos  (1)
#define TZIF0_VBATOV_Msk  (0x1U << TZIF0_VBATOV_Pos)

#define TZIF0_VBATOV_NOT_OCCUR  ((0x0U) << TZIF0_VBATOV_Pos)
#define TZIF0_VBATOV_OCCUR      ((0x1U) << TZIF0_VBATOV_Pos)

#define TZIF0_VBATOV_(x)  (((x) << TZIF0_VBATOV_Pos) & TZIF0_VBATOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VDD5UV
  *  @access     HV->TZIF0
  *  @brief      Latched VDD5 under-voltage event interrupt flag
  */
#define TZIF0_VDD5UV_Pos  (2)
#define TZIF0_VDD5UV_Msk  (0x1U << TZIF0_VDD5UV_Pos)

#define TZIF0_VDD5UV_NOT_OCCUR  ((0x0U) << TZIF0_VDD5UV_Pos)
#define TZIF0_VDD5UV_OCCUR      ((0x1U) << TZIF0_VDD5UV_Pos)

#define TZIF0_VDD5UV_(x)  (((x) << TZIF0_VDD5UV_Pos) & TZIF0_VDD5UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VDD5OV
  *  @access     HV->TZIF0
  *  @brief      Latched VDD5 over-voltage event interrupt flag
  */
#define TZIF0_VDD5OV_Pos  (3)
#define TZIF0_VDD5OV_Msk  (0x1U << TZIF0_VDD5OV_Pos)

#define TZIF0_VDD5OV_NOT_OCCUR  ((0x0U) << TZIF0_VDD5OV_Pos)
#define TZIF0_VDD5OV_OCCUR      ((0x1U) << TZIF0_VDD5OV_Pos)

#define TZIF0_VDD5OV_(x)  (((x) << TZIF0_VDD5OV_Pos) & TZIF0_VDD5OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VDD5EXTUV
  *  @access     HV->TZIF0
  *  @brief      Latched VDD5EXT under-voltage event interrupt flag
  */
#define TZIF0_VDD5EXTUV_Pos  (4)
#define TZIF0_VDD5EXTUV_Msk  (0x1U << TZIF0_VDD5EXTUV_Pos)

#define TZIF0_VDD5EXTUV_NOT_OCCUR  ((0x0U) << TZIF0_VDD5EXTUV_Pos)
#define TZIF0_VDD5EXTUV_OCCUR      ((0x1U) << TZIF0_VDD5EXTUV_Pos)

#define TZIF0_VDD5EXTUV_(x)  (((x) << TZIF0_VDD5EXTUV_Pos) & TZIF0_VDD5EXTUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VDD5EXTOV
  *  @access     HV->TZIF0
  *  @brief      Latched VDD5EXT over-voltage event interrupt flag
  */
#define TZIF0_VDD5EXTOV_Pos  (5)
#define TZIF0_VDD5EXTOV_Msk  (0x1U << TZIF0_VDD5EXTOV_Pos)

#define TZIF0_VDD5EXTOV_NOT_OCCUR  ((0x0U) << TZIF0_VDD5EXTOV_Pos)
#define TZIF0_VDD5EXTOV_OCCUR      ((0x1U) << TZIF0_VDD5EXTOV_Pos)

#define TZIF0_VDD5EXTOV_(x)  (((x) << TZIF0_VDD5EXTOV_Pos) & TZIF0_VDD5EXTOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VDD3UV
  *  @access     HV->TZIF0
  *  @brief      Latched VDD3 under-voltage event interrupt flag
  */
#define TZIF0_VDD3UV_Pos  (6)
#define TZIF0_VDD3UV_Msk  (0x1U << TZIF0_VDD3UV_Pos)

#define TZIF0_VDD3UV_NOT_OCCUR  ((0x0U) << TZIF0_VDD3UV_Pos)
#define TZIF0_VDD3UV_OCCUR      ((0x1U) << TZIF0_VDD3UV_Pos)

#define TZIF0_VDD3UV_(x)  (((x) << TZIF0_VDD3UV_Pos) & TZIF0_VDD3UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VDD3OV
  *  @access     HV->TZIF0
  *  @brief      Latched VDD3 over-voltage event interrupt flag
  */
#define TZIF0_VDD3OV_Pos  (7)
#define TZIF0_VDD3OV_Msk  (0x1U << TZIF0_VDD3OV_Pos)

#define TZIF0_VDD3OV_NOT_OCCUR  ((0x0U) << TZIF0_VDD3OV_Pos)
#define TZIF0_VDD3OV_OCCUR      ((0x1U) << TZIF0_VDD3OV_Pos)

#define TZIF0_VDD3OV_(x)  (((x) << TZIF0_VDD3OV_Pos) & TZIF0_VDD3OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           PMUOTWARN
  *  @access     HV->TZIF0
  *  @brief      Latched PMU over-temperature warning event interrupt flag
  */
#define TZIF0_PMUOTWARN_Pos  (8)
#define TZIF0_PMUOTWARN_Msk  (0x1U << TZIF0_PMUOTWARN_Pos)

#define TZIF0_PMUOTWARN_NOT_OCCUR  ((0x0U) << TZIF0_PMUOTWARN_Pos)
#define TZIF0_PMUOTWARN_OCCUR      ((0x1U) << TZIF0_PMUOTWARN_Pos)

#define TZIF0_PMUOTWARN_(x)  (((x) << TZIF0_PMUOTWARN_Pos) & TZIF0_PMUOTWARN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VDD5EXTOC
  *  @access     HV->TZIF0
  *  @brief      Latched VDD5EXT over-current event interrupt flag
  */
#define TZIF0_VDD5EXTOC_Pos  (9)
#define TZIF0_VDD5EXTOC_Msk  (0x1U << TZIF0_VDD5EXTOC_Pos)

#define TZIF0_VDD5EXTOC_NOT_OCCUR  ((0x0U) << TZIF0_VDD5EXTOC_Pos)
#define TZIF0_VDD5EXTOC_OCCUR      ((0x1U) << TZIF0_VDD5EXTOC_Pos)

#define TZIF0_VDD5EXTOC_(x)  (((x) << TZIF0_VDD5EXTOC_Pos) & TZIF0_VDD5EXTOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VDD5OC
  *  @access     HV->TZIF0
  *  @brief      Latched VDD5 over-current event interrupt flag
  */
#define TZIF0_VDD5OC_Pos  (10)
#define TZIF0_VDD5OC_Msk  (0x1U << TZIF0_VDD5OC_Pos)

#define TZIF0_VDD5OC_NOT_OCCUR  ((0x0U) << TZIF0_VDD5OC_Pos)
#define TZIF0_VDD5OC_OCCUR      ((0x1U) << TZIF0_VDD5OC_Pos)

#define TZIF0_VDD5OC_(x)  (((x) << TZIF0_VDD5OC_Pos) & TZIF0_VDD5OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           VDD3OC
  *  @access     HV->TZIF0
  *  @brief      Latched VDD3 over-current event interrupt flag
  */
#define TZIF0_VDD3OC_Pos  (11)
#define TZIF0_VDD3OC_Msk  (0x1U << TZIF0_VDD3OC_Pos)

#define TZIF0_VDD3OC_NOT_OCCUR  ((0x0U) << TZIF0_VDD3OC_Pos)
#define TZIF0_VDD3OC_OCCUR      ((0x1U) << TZIF0_VDD3OC_Pos)

#define TZIF0_VDD3OC_(x)  (((x) << TZIF0_VDD3OC_Pos) & TZIF0_VDD3OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           CLKERR
  *  @access     HV->TZIF0
  *  @brief      Latched clock error event interrupt flag
  */
#define TZIF0_CLKERR_Pos  (12)
#define TZIF0_CLKERR_Msk  (0x1U << TZIF0_CLKERR_Pos)

#define TZIF0_CLKERR_NOT_OCCUR  ((0x0U) << TZIF0_CLKERR_Pos)
#define TZIF0_CLKERR_OCCUR      ((0x1U) << TZIF0_CLKERR_Pos)

#define TZIF0_CLKERR_(x)  (((x) << TZIF0_CLKERR_Pos) & TZIF0_CLKERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           LINTXTIMEOUT
  *  @access     HV->TZIF0
  *  @brief      Latched LIN TXD timeout event interrupt flag
  */
#define TZIF0_LINTXTIMEOUT_Pos  (13)
#define TZIF0_LINTXTIMEOUT_Msk  (0x1U << TZIF0_LINTXTIMEOUT_Pos)

#define TZIF0_LINTXTIMEOUT_NOT_OCCUR  ((0x0U) << TZIF0_LINTXTIMEOUT_Pos)
#define TZIF0_LINTXTIMEOUT_OCCUR      ((0x1U) << TZIF0_LINTXTIMEOUT_Pos)

#define TZIF0_LINTXTIMEOUT_(x)  (((x) << TZIF0_LINTXTIMEOUT_Pos) & TZIF0_LINTXTIMEOUT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           LINOC
  *  @access     HV->TZIF0
  *  @brief      Latched LIN transceiver over-current event interrupt flag
  */
#define TZIF0_LINOC_Pos  (14)
#define TZIF0_LINOC_Msk  (0x1U << TZIF0_LINOC_Pos)

#define TZIF0_LINOC_NOT_OCCUR  ((0x0U) << TZIF0_LINOC_Pos)
#define TZIF0_LINOC_OCCUR      ((0x1U) << TZIF0_LINOC_Pos)

#define TZIF0_LINOC_(x)  (((x) << TZIF0_LINOC_Pos) & TZIF0_LINOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF0           LINOT
  *  @access     HV->TZIF0
  *  @brief      Latched LIN transceiver over-temperature event interrupt flag
  */
#define TZIF0_LINOT_Pos  (15)
#define TZIF0_LINOT_Msk  (0x1U << TZIF0_LINOT_Pos)

#define TZIF0_LINOT_NOT_OCCUR  ((0x0U) << TZIF0_LINOT_Pos)
#define TZIF0_LINOT_OCCUR      ((0x1U) << TZIF0_LINOT_Pos)

#define TZIF0_LINOT_(x)  (((x) << TZIF0_LINOT_Pos) & TZIF0_LINOT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           PDRVOCLU
  *  @access     HV->TZIE1
  *  @brief      Pre-driver U-phase low-side over-current event interrupt enable
  */
#define TZIE1_PDRVOCLU_Pos  (0)
#define TZIE1_PDRVOCLU_Msk  (0x1U << TZIE1_PDRVOCLU_Pos)

#define TZIE1_PDRVOCLU_DISABLE  ((0x0U) << TZIE1_PDRVOCLU_Pos)
#define TZIE1_PDRVOCLU_ENABLE   ((0x1U) << TZIE1_PDRVOCLU_Pos)

#define TZIE1_PDRVOCLU_(x)  (((x) << TZIE1_PDRVOCLU_Pos) & TZIE1_PDRVOCLU_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           PDRVOCLV
  *  @access     HV->TZIE1
  *  @brief      Pre-driver V-phase low-side over-current event interrupt enable
  */
#define TZIE1_PDRVOCLV_Pos  (1)
#define TZIE1_PDRVOCLV_Msk  (0x1U << TZIE1_PDRVOCLV_Pos)

#define TZIE1_PDRVOCLV_DISABLE  ((0x0U) << TZIE1_PDRVOCLV_Pos)
#define TZIE1_PDRVOCLV_ENABLE   ((0x1U) << TZIE1_PDRVOCLV_Pos)

#define TZIE1_PDRVOCLV_(x)  (((x) << TZIE1_PDRVOCLV_Pos) & TZIE1_PDRVOCLV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           PDRVOCLW
  *  @access     HV->TZIE1
  *  @brief      Pre-driver W-phase low-side over-current event interrupt enable
  */
#define TZIE1_PDRVOCLW_Pos  (2)
#define TZIE1_PDRVOCLW_Msk  (0x1U << TZIE1_PDRVOCLW_Pos)

#define TZIE1_PDRVOCLW_DISABLE  ((0x0U) << TZIE1_PDRVOCLW_Pos)
#define TZIE1_PDRVOCLW_ENABLE   ((0x1U) << TZIE1_PDRVOCLW_Pos)

#define TZIE1_PDRVOCLW_(x)  (((x) << TZIE1_PDRVOCLW_Pos) & TZIE1_PDRVOCLW_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           PDRVOCHU
  *  @access     HV->TZIE1
  *  @brief      Pre-driver U-phase high-side over-current event interrupt enable
  */
#define TZIE1_PDRVOCHU_Pos  (3)
#define TZIE1_PDRVOCHU_Msk  (0x1U << TZIE1_PDRVOCHU_Pos)

#define TZIE1_PDRVOCHU_DISABLE  ((0x0U) << TZIE1_PDRVOCHU_Pos)
#define TZIE1_PDRVOCHU_ENABLE   ((0x1U) << TZIE1_PDRVOCHU_Pos)

#define TZIE1_PDRVOCHU_(x)  (((x) << TZIE1_PDRVOCHU_Pos) & TZIE1_PDRVOCHU_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           PDRVOCHV
  *  @access     HV->TZIE1
  *  @brief      Pre-driver V-phase high-side over-current event interrupt enable
  */
#define TZIE1_PDRVOCHV_Pos  (4)
#define TZIE1_PDRVOCHV_Msk  (0x1U << TZIE1_PDRVOCHV_Pos)

#define TZIE1_PDRVOCHV_DISABLE  ((0x0U) << TZIE1_PDRVOCHV_Pos)
#define TZIE1_PDRVOCHV_ENABLE   ((0x1U) << TZIE1_PDRVOCHV_Pos)

#define TZIE1_PDRVOCHV_(x)  (((x) << TZIE1_PDRVOCHV_Pos) & TZIE1_PDRVOCHV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           PDRVOCHW
  *  @access     HV->TZIE1
  *  @brief      Pre-driver W-phase high-side over-current event interrupt enable
  */
#define TZIE1_PDRVOCHW_Pos  (5)
#define TZIE1_PDRVOCHW_Msk  (0x1U << TZIE1_PDRVOCHW_Pos)

#define TZIE1_PDRVOCHW_DISABLE  ((0x0U) << TZIE1_PDRVOCHW_Pos)
#define TZIE1_PDRVOCHW_ENABLE   ((0x1U) << TZIE1_PDRVOCHW_Pos)

#define TZIE1_PDRVOCHW_(x)  (((x) << TZIE1_PDRVOCHW_Pos) & TZIE1_PDRVOCHW_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           VCPUV
  *  @access     HV->TZIE1
  *  @brief      Pre-driver VCP over-voltage event interrupt enable
  */
#define TZIE1_VCPUV_Pos  (6)
#define TZIE1_VCPUV_Msk  (0x1U << TZIE1_VCPUV_Pos)

#define TZIE1_VCPUV_DISABLE  ((0x0U) << TZIE1_VCPUV_Pos)
#define TZIE1_VCPUV_ENABLE   ((0x1U) << TZIE1_VCPUV_Pos)

#define TZIE1_VCPUV_(x)  (((x) << TZIE1_VCPUV_Pos) & TZIE1_VCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           VCPOV
  *  @access     HV->TZIE1
  *  @brief      Pre-driver VCP over-voltage event interrupt enable
  */
#define TZIE1_VCPOV_Pos  (7)
#define TZIE1_VCPOV_Msk  (0x1U << TZIE1_VCPOV_Pos)

#define TZIE1_VCPOV_DISABLE  ((0x0U) << TZIE1_VCPOV_Pos)
#define TZIE1_VCPOV_ENABLE   ((0x1U) << TZIE1_VCPOV_Pos)

#define TZIE1_VCPOV_(x)  (((x) << TZIE1_VCPOV_Pos) & TZIE1_VCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           VBATUV
  *  @access     HV->TZIE1
  *  @brief      VBAT under-voltage event interrupt enable
  */
#define TZIE1_VBATUV_Pos  (8)
#define TZIE1_VBATUV_Msk  (0x1U << TZIE1_VBATUV_Pos)

#define TZIE1_VBATUV_DISABLE  ((0x0U) << TZIE1_VBATUV_Pos)
#define TZIE1_VBATUV_ENABLE   ((0x1U) << TZIE1_VBATUV_Pos)

#define TZIE1_VBATUV_(x)  (((x) << TZIE1_VBATUV_Pos) & TZIE1_VBATUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           VDD5UV
  *  @access     HV->TZIE1
  *  @brief      VDD5 under-voltage event interrupt enable
  */
#define TZIE1_VDD5UV_Pos  (9)
#define TZIE1_VDD5UV_Msk  (0x1U << TZIE1_VDD5UV_Pos)

#define TZIE1_VDD5UV_DISABLE  ((0x0U) << TZIE1_VDD5UV_Pos)
#define TZIE1_VDD5UV_ENABLE   ((0x1U) << TZIE1_VDD5UV_Pos)

#define TZIE1_VDD5UV_(x)  (((x) << TZIE1_VDD5UV_Pos) & TZIE1_VDD5UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           VDD3UV
  *  @access     HV->TZIE1
  *  @brief      VDD3 under-voltage event interrupt enable
  */
#define TZIE1_VDD3UV_Pos  (10)
#define TZIE1_VDD3UV_Msk  (0x1U << TZIE1_VDD3UV_Pos)

#define TZIE1_VDD3UV_DISABLE  ((0x0U) << TZIE1_VDD3UV_Pos)
#define TZIE1_VDD3UV_ENABLE   ((0x1U) << TZIE1_VDD3UV_Pos)

#define TZIE1_VDD3UV_(x)  (((x) << TZIE1_VDD3UV_Pos) & TZIE1_VDD3UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           PMUOTWARN
  *  @access     HV->TZIE1
  *  @brief      Over-temperature warning event interrupt enable
  */
#define TZIE1_PMUOTWARN_Pos  (11)
#define TZIE1_PMUOTWARN_Msk  (0x1U << TZIE1_PMUOTWARN_Pos)

#define TZIE1_PMUOTWARN_DISABLE  ((0x0U) << TZIE1_PMUOTWARN_Pos)
#define TZIE1_PMUOTWARN_ENABLE   ((0x1U) << TZIE1_PMUOTWARN_Pos)

#define TZIE1_PMUOTWARN_(x)  (((x) << TZIE1_PMUOTWARN_Pos) & TZIE1_PMUOTWARN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           VBATCPUV
  *  @access     HV->TZIE1
  *  @brief      VBATCP under-voltage event interrupt enable
  */
#define TZIE1_VBATCPUV_Pos  (12)
#define TZIE1_VBATCPUV_Msk  (0x1U << TZIE1_VBATCPUV_Pos)

#define TZIE1_VBATCPUV_DISABLE  ((0x0U) << TZIE1_VBATCPUV_Pos)
#define TZIE1_VBATCPUV_ENABLE   ((0x1U) << TZIE1_VBATCPUV_Pos)

#define TZIE1_VBATCPUV_(x)  (((x) << TZIE1_VBATCPUV_Pos) & TZIE1_VBATCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           VBATCPOV
  *  @access     HV->TZIE1
  *  @brief      VBATCP over-voltage event interrupt enable
  */
#define TZIE1_VBATCPOV_Pos  (13)
#define TZIE1_VBATCPOV_Msk  (0x1U << TZIE1_VBATCPOV_Pos)

#define TZIE1_VBATCPOV_DISABLE  ((0x0U) << TZIE1_VBATCPOV_Pos)
#define TZIE1_VBATCPOV_ENABLE   ((0x1U) << TZIE1_VBATCPOV_Pos)

#define TZIE1_VBATCPOV_(x)  (((x) << TZIE1_VBATCPOV_Pos) & TZIE1_VBATCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           LPRCOERR
  *  @access     HV->TZIE1
  *  @brief      LPRCO error event interrupt enable
  */
#define TZIE1_LPRCOERR_Pos  (14)
#define TZIE1_LPRCOERR_Msk  (0x1U << TZIE1_LPRCOERR_Pos)

#define TZIE1_LPRCOERR_DISABLE  ((0x0U) << TZIE1_LPRCOERR_Pos)
#define TZIE1_LPRCOERR_ENABLE   ((0x1U) << TZIE1_LPRCOERR_Pos)

#define TZIE1_LPRCOERR_(x)  (((x) << TZIE1_LPRCOERR_Pos) & TZIE1_LPRCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIE1           RCOERR
  *  @access     HV->TZIE1
  *  @brief      RCO error event interrupt enable
  */
#define TZIE1_RCOERR_Pos  (15)
#define TZIE1_RCOERR_Msk  (0x1U << TZIE1_RCOERR_Pos)

#define TZIE1_RCOERR_DISABLE  ((0x0U) << TZIE1_RCOERR_Pos)
#define TZIE1_RCOERR_ENABLE   ((0x1U) << TZIE1_RCOERR_Pos)

#define TZIE1_RCOERR_(x)  (((x) << TZIE1_RCOERR_Pos) & TZIE1_RCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           PDRVOCLU
  *  @access     HV->TZIC1
  *  @brief      Pre-driver U-phase low-side over-current event interrupt clear
  */
#define TZIC1_PDRVOCLU_Pos  (0)
#define TZIC1_PDRVOCLU_Msk  (0x1U << TZIC1_PDRVOCLU_Pos)

#define TZIC1_PDRVOCLU_NO_EFFECT  ((0x0U) << TZIC1_PDRVOCLU_Pos)
#define TZIC1_PDRVOCLU_CLEAR      ((0x1U) << TZIC1_PDRVOCLU_Pos)

#define TZIC1_PDRVOCLU_(x)  (((x) << TZIC1_PDRVOCLU_Pos) & TZIC1_PDRVOCLU_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           PDRVOCLV
  *  @access     HV->TZIC1
  *  @brief      Pre-driver V-phase low-side over-current event interrupt clear
  */
#define TZIC1_PDRVOCLV_Pos  (1)
#define TZIC1_PDRVOCLV_Msk  (0x1U << TZIC1_PDRVOCLV_Pos)

#define TZIC1_PDRVOCLV_NO_EFFECT  ((0x0U) << TZIC1_PDRVOCLV_Pos)
#define TZIC1_PDRVOCLV_CLEAR      ((0x1U) << TZIC1_PDRVOCLV_Pos)

#define TZIC1_PDRVOCLV_(x)  (((x) << TZIC1_PDRVOCLV_Pos) & TZIC1_PDRVOCLV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           PDRVOCLW
  *  @access     HV->TZIC1
  *  @brief      Pre-driver W-phase low-side over-current event interrupt clear
  */
#define TZIC1_PDRVOCLW_Pos  (2)
#define TZIC1_PDRVOCLW_Msk  (0x1U << TZIC1_PDRVOCLW_Pos)

#define TZIC1_PDRVOCLW_NO_EFFECT  ((0x0U) << TZIC1_PDRVOCLW_Pos)
#define TZIC1_PDRVOCLW_CLEAR      ((0x1U) << TZIC1_PDRVOCLW_Pos)

#define TZIC1_PDRVOCLW_(x)  (((x) << TZIC1_PDRVOCLW_Pos) & TZIC1_PDRVOCLW_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           PDRVOCHU
  *  @access     HV->TZIC1
  *  @brief      Pre-driver U-phase high-side over-current event interrupt clear
  */
#define TZIC1_PDRVOCHU_Pos  (3)
#define TZIC1_PDRVOCHU_Msk  (0x1U << TZIC1_PDRVOCHU_Pos)

#define TZIC1_PDRVOCHU_NO_EFFECT  ((0x0U) << TZIC1_PDRVOCHU_Pos)
#define TZIC1_PDRVOCHU_CLEAR      ((0x1U) << TZIC1_PDRVOCHU_Pos)

#define TZIC1_PDRVOCHU_(x)  (((x) << TZIC1_PDRVOCHU_Pos) & TZIC1_PDRVOCHU_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           PDRVOCHV
  *  @access     HV->TZIC1
  *  @brief      Pre-driver V-phase high-side over-current event interrupt clear
  */
#define TZIC1_PDRVOCHV_Pos  (4)
#define TZIC1_PDRVOCHV_Msk  (0x1U << TZIC1_PDRVOCHV_Pos)

#define TZIC1_PDRVOCHV_NO_EFFECT  ((0x0U) << TZIC1_PDRVOCHV_Pos)
#define TZIC1_PDRVOCHV_CLEAR      ((0x1U) << TZIC1_PDRVOCHV_Pos)

#define TZIC1_PDRVOCHV_(x)  (((x) << TZIC1_PDRVOCHV_Pos) & TZIC1_PDRVOCHV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           PDRVOCHW
  *  @access     HV->TZIC1
  *  @brief      Pre-driver W-phase high-side over-current event interrupt clear
  */
#define TZIC1_PDRVOCHW_Pos  (5)
#define TZIC1_PDRVOCHW_Msk  (0x1U << TZIC1_PDRVOCHW_Pos)

#define TZIC1_PDRVOCHW_NO_EFFECT  ((0x0U) << TZIC1_PDRVOCHW_Pos)
#define TZIC1_PDRVOCHW_CLEAR      ((0x1U) << TZIC1_PDRVOCHW_Pos)

#define TZIC1_PDRVOCHW_(x)  (((x) << TZIC1_PDRVOCHW_Pos) & TZIC1_PDRVOCHW_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           VCPUV
  *  @access     HV->TZIC1
  *  @brief      Pre-driver VCP over-voltage event interrupt clear
  */
#define TZIC1_VCPUV_Pos  (6)
#define TZIC1_VCPUV_Msk  (0x1U << TZIC1_VCPUV_Pos)

#define TZIC1_VCPUV_NO_EFFECT  ((0x0U) << TZIC1_VCPUV_Pos)
#define TZIC1_VCPUV_CLEAR      ((0x1U) << TZIC1_VCPUV_Pos)

#define TZIC1_VCPUV_(x)  (((x) << TZIC1_VCPUV_Pos) & TZIC1_VCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           VCPOV
  *  @access     HV->TZIC1
  *  @brief      Pre-driver VCP over-voltage event interrupt clear
  */
#define TZIC1_VCPOV_Pos  (7)
#define TZIC1_VCPOV_Msk  (0x1U << TZIC1_VCPOV_Pos)

#define TZIC1_VCPOV_NO_EFFECT  ((0x0U) << TZIC1_VCPOV_Pos)
#define TZIC1_VCPOV_CLEAR      ((0x1U) << TZIC1_VCPOV_Pos)

#define TZIC1_VCPOV_(x)  (((x) << TZIC1_VCPOV_Pos) & TZIC1_VCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           VBATUV
  *  @access     HV->TZIC1
  *  @brief      VBAT under-voltage event interrupt clear
  */
#define TZIC1_VBATUV_Pos  (8)
#define TZIC1_VBATUV_Msk  (0x1U << TZIC1_VBATUV_Pos)

#define TZIC1_VBATUV_NO_EFFECT  ((0x0U) << TZIC1_VBATUV_Pos)
#define TZIC1_VBATUV_CLEAR      ((0x1U) << TZIC1_VBATUV_Pos)

#define TZIC1_VBATUV_(x)  (((x) << TZIC1_VBATUV_Pos) & TZIC1_VBATUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           VDD5UV
  *  @access     HV->TZIC1
  *  @brief      VDD5 under-voltage event interrupt clear
  */
#define TZIC1_VDD5UV_Pos  (9)
#define TZIC1_VDD5UV_Msk  (0x1U << TZIC1_VDD5UV_Pos)

#define TZIC1_VDD5UV_NO_EFFECT  ((0x0U) << TZIC1_VDD5UV_Pos)
#define TZIC1_VDD5UV_CLEAR      ((0x1U) << TZIC1_VDD5UV_Pos)

#define TZIC1_VDD5UV_(x)  (((x) << TZIC1_VDD5UV_Pos) & TZIC1_VDD5UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           VDD3UV
  *  @access     HV->TZIC1
  *  @brief      VDD3 under-voltage event interrupt clear
  */
#define TZIC1_VDD3UV_Pos  (10)
#define TZIC1_VDD3UV_Msk  (0x1U << TZIC1_VDD3UV_Pos)

#define TZIC1_VDD3UV_NO_EFFECT  ((0x0U) << TZIC1_VDD3UV_Pos)
#define TZIC1_VDD3UV_CLEAR      ((0x1U) << TZIC1_VDD3UV_Pos)

#define TZIC1_VDD3UV_(x)  (((x) << TZIC1_VDD3UV_Pos) & TZIC1_VDD3UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           PMUOTWARN
  *  @access     HV->TZIC1
  *  @brief      Over-temperature warning event interrupt clear
  */
#define TZIC1_PMUOTWARN_Pos  (11)
#define TZIC1_PMUOTWARN_Msk  (0x1U << TZIC1_PMUOTWARN_Pos)

#define TZIC1_PMUOTWARN_NO_EFFECT  ((0x0U) << TZIC1_PMUOTWARN_Pos)
#define TZIC1_PMUOTWARN_CLEAR      ((0x1U) << TZIC1_PMUOTWARN_Pos)

#define TZIC1_PMUOTWARN_(x)  (((x) << TZIC1_PMUOTWARN_Pos) & TZIC1_PMUOTWARN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           VBATCPUV
  *  @access     HV->TZIC1
  *  @brief      VBATCP under-voltage event interrupt clear
  */
#define TZIC1_VBATCPUV_Pos  (12)
#define TZIC1_VBATCPUV_Msk  (0x1U << TZIC1_VBATCPUV_Pos)

#define TZIC1_VBATCPUV_NO_EFFECT  ((0x0U) << TZIC1_VBATCPUV_Pos)
#define TZIC1_VBATCPUV_CLEAR      ((0x1U) << TZIC1_VBATCPUV_Pos)

#define TZIC1_VBATCPUV_(x)  (((x) << TZIC1_VBATCPUV_Pos) & TZIC1_VBATCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           VBATCPOV
  *  @access     HV->TZIC1
  *  @brief      VBATCP over-voltage event interrupt clear
  */
#define TZIC1_VBATCPOV_Pos  (13)
#define TZIC1_VBATCPOV_Msk  (0x1U << TZIC1_VBATCPOV_Pos)

#define TZIC1_VBATCPOV_NO_EFFECT  ((0x0U) << TZIC1_VBATCPOV_Pos)
#define TZIC1_VBATCPOV_CLEAR      ((0x1U) << TZIC1_VBATCPOV_Pos)

#define TZIC1_VBATCPOV_(x)  (((x) << TZIC1_VBATCPOV_Pos) & TZIC1_VBATCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           LPRCOERR
  *  @access     HV->TZIC1
  *  @brief      LPRCO error event interrupt clear
  */
#define TZIC1_LPRCOERR_Pos  (14)
#define TZIC1_LPRCOERR_Msk  (0x1U << TZIC1_LPRCOERR_Pos)

#define TZIC1_LPRCOERR_NO_EFFECT  ((0x0U) << TZIC1_LPRCOERR_Pos)
#define TZIC1_LPRCOERR_CLEAR      ((0x1U) << TZIC1_LPRCOERR_Pos)

#define TZIC1_LPRCOERR_(x)  (((x) << TZIC1_LPRCOERR_Pos) & TZIC1_LPRCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIC1           RCOERR
  *  @access     HV->TZIC1
  *  @brief      RCO error event interrupt clear
  */
#define TZIC1_RCOERR_Pos  (15)
#define TZIC1_RCOERR_Msk  (0x1U << TZIC1_RCOERR_Pos)

#define TZIC1_RCOERR_NO_EFFECT  ((0x0U) << TZIC1_RCOERR_Pos)
#define TZIC1_RCOERR_CLEAR      ((0x1U) << TZIC1_RCOERR_Pos)

#define TZIC1_RCOERR_(x)  (((x) << TZIC1_RCOERR_Pos) & TZIC1_RCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           PDRVOCLU
  *  @access     HV->TZIF1
  *  @brief      Latched pre-driver U-phase low-side over-current event interrupt flag
  */
#define TZIF1_PDRVOCLU_Pos  (0)
#define TZIF1_PDRVOCLU_Msk  (0x1U << TZIF1_PDRVOCLU_Pos)

#define TZIF1_PDRVOCLU_NOT_OCCUR  ((0x0U) << TZIF1_PDRVOCLU_Pos)
#define TZIF1_PDRVOCLU_OCCUR      ((0x1U) << TZIF1_PDRVOCLU_Pos)

#define TZIF1_PDRVOCLU_(x)  (((x) << TZIF1_PDRVOCLU_Pos) & TZIF1_PDRVOCLU_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           PDRVOCLV
  *  @access     HV->TZIF1
  *  @brief      Latched pre-driver V-phase low-side over-current event interrupt flag
  */
#define TZIF1_PDRVOCLV_Pos  (1)
#define TZIF1_PDRVOCLV_Msk  (0x1U << TZIF1_PDRVOCLV_Pos)

#define TZIF1_PDRVOCLV_NOT_OCCUR  ((0x0U) << TZIF1_PDRVOCLV_Pos)
#define TZIF1_PDRVOCLV_OCCUR      ((0x1U) << TZIF1_PDRVOCLV_Pos)

#define TZIF1_PDRVOCLV_(x)  (((x) << TZIF1_PDRVOCLV_Pos) & TZIF1_PDRVOCLV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           PDRVOCLW
  *  @access     HV->TZIF1
  *  @brief      Latched pre-driver W-phase low-side over-current event interrupt flag
  */
#define TZIF1_PDRVOCLW_Pos  (2)
#define TZIF1_PDRVOCLW_Msk  (0x1U << TZIF1_PDRVOCLW_Pos)

#define TZIF1_PDRVOCLW_NOT_OCCUR  ((0x0U) << TZIF1_PDRVOCLW_Pos)
#define TZIF1_PDRVOCLW_OCCUR      ((0x1U) << TZIF1_PDRVOCLW_Pos)

#define TZIF1_PDRVOCLW_(x)  (((x) << TZIF1_PDRVOCLW_Pos) & TZIF1_PDRVOCLW_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           PDRVOCHU
  *  @access     HV->TZIF1
  *  @brief      Latched pre-driver U-phase high-side over-current event interrupt flag
  */
#define TZIF1_PDRVOCHU_Pos  (3)
#define TZIF1_PDRVOCHU_Msk  (0x1U << TZIF1_PDRVOCHU_Pos)

#define TZIF1_PDRVOCHU_NOT_OCCUR  ((0x0U) << TZIF1_PDRVOCHU_Pos)
#define TZIF1_PDRVOCHU_OCCUR      ((0x1U) << TZIF1_PDRVOCHU_Pos)

#define TZIF1_PDRVOCHU_(x)  (((x) << TZIF1_PDRVOCHU_Pos) & TZIF1_PDRVOCHU_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           PDRVOCHV
  *  @access     HV->TZIF1
  *  @brief      Latched pre-driver V-phase high-side over-current event interrupt flag
  */
#define TZIF1_PDRVOCHV_Pos  (4)
#define TZIF1_PDRVOCHV_Msk  (0x1U << TZIF1_PDRVOCHV_Pos)

#define TZIF1_PDRVOCHV_NOT_OCCUR  ((0x0U) << TZIF1_PDRVOCHV_Pos)
#define TZIF1_PDRVOCHV_OCCUR      ((0x1U) << TZIF1_PDRVOCHV_Pos)

#define TZIF1_PDRVOCHV_(x)  (((x) << TZIF1_PDRVOCHV_Pos) & TZIF1_PDRVOCHV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           PDRVOCHW
  *  @access     HV->TZIF1
  *  @brief      Latched pre-driver W-phase high-side over-current event interrupt flag
  */
#define TZIF1_PDRVOCHW_Pos  (5)
#define TZIF1_PDRVOCHW_Msk  (0x1U << TZIF1_PDRVOCHW_Pos)

#define TZIF1_PDRVOCHW_NOT_OCCUR  ((0x0U) << TZIF1_PDRVOCHW_Pos)
#define TZIF1_PDRVOCHW_OCCUR      ((0x1U) << TZIF1_PDRVOCHW_Pos)

#define TZIF1_PDRVOCHW_(x)  (((x) << TZIF1_PDRVOCHW_Pos) & TZIF1_PDRVOCHW_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           VCPUV
  *  @access     HV->TZIF1
  *  @brief      Latched pre-driver VCP over-voltage event interrupt flag
  */
#define TZIF1_VCPUV_Pos  (6)
#define TZIF1_VCPUV_Msk  (0x1U << TZIF1_VCPUV_Pos)

#define TZIF1_VCPUV_NOT_OCCUR  ((0x0U) << TZIF1_VCPUV_Pos)
#define TZIF1_VCPUV_OCCUR      ((0x1U) << TZIF1_VCPUV_Pos)

#define TZIF1_VCPUV_(x)  (((x) << TZIF1_VCPUV_Pos) & TZIF1_VCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           VCPOV
  *  @access     HV->TZIF1
  *  @brief      Latched pre-driver VCP over-voltage event interrupt flag
  */
#define TZIF1_VCPOV_Pos  (7)
#define TZIF1_VCPOV_Msk  (0x1U << TZIF1_VCPOV_Pos)

#define TZIF1_VCPOV_NOT_OCCUR  ((0x0U) << TZIF1_VCPOV_Pos)
#define TZIF1_VCPOV_OCCUR      ((0x1U) << TZIF1_VCPOV_Pos)

#define TZIF1_VCPOV_(x)  (((x) << TZIF1_VCPOV_Pos) & TZIF1_VCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           VBATUV
  *  @access     HV->TZIF1
  *  @brief      Latched VBAT under-voltage event interrupt flag
  */
#define TZIF1_VBATUV_Pos  (8)
#define TZIF1_VBATUV_Msk  (0x1U << TZIF1_VBATUV_Pos)

#define TZIF1_VBATUV_NOT_OCCUR  ((0x0U) << TZIF1_VBATUV_Pos)
#define TZIF1_VBATUV_OCCUR      ((0x1U) << TZIF1_VBATUV_Pos)

#define TZIF1_VBATUV_(x)  (((x) << TZIF1_VBATUV_Pos) & TZIF1_VBATUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           VDD5UV
  *  @access     HV->TZIF1
  *  @brief      Latched VDD5 under-voltage event interrupt flag
  */
#define TZIF1_VDD5UV_Pos  (9)
#define TZIF1_VDD5UV_Msk  (0x1U << TZIF1_VDD5UV_Pos)

#define TZIF1_VDD5UV_NOT_OCCUR  ((0x0U) << TZIF1_VDD5UV_Pos)
#define TZIF1_VDD5UV_OCCUR      ((0x1U) << TZIF1_VDD5UV_Pos)

#define TZIF1_VDD5UV_(x)  (((x) << TZIF1_VDD5UV_Pos) & TZIF1_VDD5UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           VDD3UV
  *  @access     HV->TZIF1
  *  @brief      Latched VDD3 under-voltage event interrupt flag
  */
#define TZIF1_VDD3UV_Pos  (10)
#define TZIF1_VDD3UV_Msk  (0x1U << TZIF1_VDD3UV_Pos)

#define TZIF1_VDD3UV_NOT_OCCUR  ((0x0U) << TZIF1_VDD3UV_Pos)
#define TZIF1_VDD3UV_OCCUR      ((0x1U) << TZIF1_VDD3UV_Pos)

#define TZIF1_VDD3UV_(x)  (((x) << TZIF1_VDD3UV_Pos) & TZIF1_VDD3UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           PMUOTWARN
  *  @access     HV->TZIF1
  *  @brief      Latched over-temperature warning event interrupt flag
  */
#define TZIF1_PMUOTWARN_Pos  (11)
#define TZIF1_PMUOTWARN_Msk  (0x1U << TZIF1_PMUOTWARN_Pos)

#define TZIF1_PMUOTWARN_NOT_OCCUR  ((0x0U) << TZIF1_PMUOTWARN_Pos)
#define TZIF1_PMUOTWARN_OCCUR      ((0x1U) << TZIF1_PMUOTWARN_Pos)

#define TZIF1_PMUOTWARN_(x)  (((x) << TZIF1_PMUOTWARN_Pos) & TZIF1_PMUOTWARN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           VBATCPUV
  *  @access     HV->TZIF1
  *  @brief      Latched VBATCP under-voltage event interrupt flag
  */
#define TZIF1_VBATCPUV_Pos  (12)
#define TZIF1_VBATCPUV_Msk  (0x1U << TZIF1_VBATCPUV_Pos)

#define TZIF1_VBATCPUV_NOT_OCCUR  ((0x0U) << TZIF1_VBATCPUV_Pos)
#define TZIF1_VBATCPUV_OCCUR      ((0x1U) << TZIF1_VBATCPUV_Pos)

#define TZIF1_VBATCPUV_(x)  (((x) << TZIF1_VBATCPUV_Pos) & TZIF1_VBATCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           VBATCPOV
  *  @access     HV->TZIF1
  *  @brief      Latched VBATCP over-voltage event interrupt flag
  */
#define TZIF1_VBATCPOV_Pos  (13)
#define TZIF1_VBATCPOV_Msk  (0x1U << TZIF1_VBATCPOV_Pos)

#define TZIF1_VBATCPOV_NOT_OCCUR  ((0x0U) << TZIF1_VBATCPOV_Pos)
#define TZIF1_VBATCPOV_OCCUR      ((0x1U) << TZIF1_VBATCPOV_Pos)

#define TZIF1_VBATCPOV_(x)  (((x) << TZIF1_VBATCPOV_Pos) & TZIF1_VBATCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           LPRCOERR
  *  @access     HV->TZIF1
  *  @brief      Latched LPRCO error event interrupt flag
  */
#define TZIF1_LPRCOERR_Pos  (14)
#define TZIF1_LPRCOERR_Msk  (0x1U << TZIF1_LPRCOERR_Pos)

#define TZIF1_LPRCOERR_NOT_OCCUR  ((0x0U) << TZIF1_LPRCOERR_Pos)
#define TZIF1_LPRCOERR_OCCUR      ((0x1U) << TZIF1_LPRCOERR_Pos)

#define TZIF1_LPRCOERR_(x)  (((x) << TZIF1_LPRCOERR_Pos) & TZIF1_LPRCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZIF1           RCOERR
  *  @access     HV->TZIF1
  *  @brief      Latched RCO error event interrupt flag
  */
#define TZIF1_RCOERR_Pos  (15)
#define TZIF1_RCOERR_Msk  (0x1U << TZIF1_RCOERR_Pos)

#define TZIF1_RCOERR_NOT_OCCUR  ((0x0U) << TZIF1_RCOERR_Pos)
#define TZIF1_RCOERR_OCCUR      ((0x1U) << TZIF1_RCOERR_Pos)

#define TZIF1_RCOERR_(x)  (((x) << TZIF1_RCOERR_Pos) & TZIF1_RCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL0       PMUOTFATAL
  *  @access     HV->EVTTHCTL0
  *  @brief      PMU over-temperature fatal event threshold
  */
#define EVTTHCTL0_PMUOTFATAL_Pos  (0)
#define EVTTHCTL0_PMUOTFATAL_Msk  (0x7U << EVTTHCTL0_PMUOTFATAL_Pos)

#define EVTTHCTL0_PMUOTFATAL_129C  ((0x000U) << EVTTHCTL0_PMUOTFATAL_Pos)
#define EVTTHCTL0_PMUOTFATAL_137C  ((0x001U) << EVTTHCTL0_PMUOTFATAL_Pos)
#define EVTTHCTL0_PMUOTFATAL_146C  ((0x002U) << EVTTHCTL0_PMUOTFATAL_Pos)
#define EVTTHCTL0_PMUOTFATAL_154C  ((0x003U) << EVTTHCTL0_PMUOTFATAL_Pos)
#define EVTTHCTL0_PMUOTFATAL_163C  ((0x004U) << EVTTHCTL0_PMUOTFATAL_Pos)
#define EVTTHCTL0_PMUOTFATAL_171C  ((0x005U) << EVTTHCTL0_PMUOTFATAL_Pos)
#define EVTTHCTL0_PMUOTFATAL_180C  ((0x006U) << EVTTHCTL0_PMUOTFATAL_Pos)
#define EVTTHCTL0_PMUOTFATAL_189C  ((0x007U) << EVTTHCTL0_PMUOTFATAL_Pos)

#define EVTTHCTL0_PMUOTFATAL_(x)  (((x) << EVTTHCTL0_PMUOTFATAL_Pos) & EVTTHCTL0_PMUOTFATAL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL0       PMUOTWARN
  *  @access     HV->EVTTHCTL0
  *  @brief      PMU over-temperature warning event threshold
  */
#define EVTTHCTL0_PMUOTWARN_Pos  (3)
#define EVTTHCTL0_PMUOTWARN_Msk  (0x7U << EVTTHCTL0_PMUOTWARN_Pos)

#define EVTTHCTL0_PMUOTWARN_129C  ((0x000U) << EVTTHCTL0_PMUOTWARN_Pos)
#define EVTTHCTL0_PMUOTWARN_137C  ((0x001U) << EVTTHCTL0_PMUOTWARN_Pos)
#define EVTTHCTL0_PMUOTWARN_146C  ((0x002U) << EVTTHCTL0_PMUOTWARN_Pos)
#define EVTTHCTL0_PMUOTWARN_154C  ((0x003U) << EVTTHCTL0_PMUOTWARN_Pos)
#define EVTTHCTL0_PMUOTWARN_163C  ((0x004U) << EVTTHCTL0_PMUOTWARN_Pos)
#define EVTTHCTL0_PMUOTWARN_171C  ((0x005U) << EVTTHCTL0_PMUOTWARN_Pos)
#define EVTTHCTL0_PMUOTWARN_180C  ((0x006U) << EVTTHCTL0_PMUOTWARN_Pos)
#define EVTTHCTL0_PMUOTWARN_189C  ((0x007U) << EVTTHCTL0_PMUOTWARN_Pos)

#define EVTTHCTL0_PMUOTWARN_(x)  (((x) << EVTTHCTL0_PMUOTWARN_Pos) & EVTTHCTL0_PMUOTWARN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL0       VBATUV
  *  @access     HV->EVTTHCTL0
  *  @brief      VBAT under-voltage event threshold
  */
#define EVTTHCTL0_VBATUV_Pos  (6)
#define EVTTHCTL0_VBATUV_Msk  (0x7U << EVTTHCTL0_VBATUV_Pos)

#define EVTTHCTL0_VBATUV_5P0V   ((0x000U) << EVTTHCTL0_VBATUV_Pos)
#define EVTTHCTL0_VBATUV_5P5V   ((0x001U) << EVTTHCTL0_VBATUV_Pos)
#define EVTTHCTL0_VBATUV_6P0V   ((0x002U) << EVTTHCTL0_VBATUV_Pos)
#define EVTTHCTL0_VBATUV_7P4V   ((0x003U) << EVTTHCTL0_VBATUV_Pos)
#define EVTTHCTL0_VBATUV_9P4V   ((0x004U) << EVTTHCTL0_VBATUV_Pos)
#define EVTTHCTL0_VBATUV_12P9V  ((0x005U) << EVTTHCTL0_VBATUV_Pos)
#define EVTTHCTL0_VBATUV_16P6V  ((0x006U) << EVTTHCTL0_VBATUV_Pos)
#define EVTTHCTL0_VBATUV_17P6V  ((0x007U) << EVTTHCTL0_VBATUV_Pos)

#define EVTTHCTL0_VBATUV_(x)  (((x) << EVTTHCTL0_VBATUV_Pos) & EVTTHCTL0_VBATUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL0       VBATOV
  *  @access     HV->EVTTHCTL0
  *  @brief      VBAT over-voltage event threshold
  */
#define EVTTHCTL0_VBATOV_Pos  (9)
#define EVTTHCTL0_VBATOV_Msk  (0x7U << EVTTHCTL0_VBATOV_Pos)

#define EVTTHCTL0_VBATOV_14P2V  ((0x000U) << EVTTHCTL0_VBATOV_Pos)
#define EVTTHCTL0_VBATOV_16P6V  ((0x001U) << EVTTHCTL0_VBATOV_Pos)
#define EVTTHCTL0_VBATOV_20P0V  ((0x002U) << EVTTHCTL0_VBATOV_Pos)
#define EVTTHCTL0_VBATOV_23P2V  ((0x003U) << EVTTHCTL0_VBATOV_Pos)
#define EVTTHCTL0_VBATOV_27P5V  ((0x004U) << EVTTHCTL0_VBATOV_Pos)
#define EVTTHCTL0_VBATOV_30P4V  ((0x005U) << EVTTHCTL0_VBATOV_Pos)
#define EVTTHCTL0_VBATOV_33P9V  ((0x006U) << EVTTHCTL0_VBATOV_Pos)
#define EVTTHCTL0_VBATOV_44P0V  ((0x007U) << EVTTHCTL0_VBATOV_Pos)

#define EVTTHCTL0_VBATOV_(x)  (((x) << EVTTHCTL0_VBATOV_Pos) & EVTTHCTL0_VBATOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL0       VDD5UV
  *  @access     HV->EVTTHCTL0
  *  @brief      VDD5 under-voltage event threshold
  */
#define EVTTHCTL0_VDD5UV_Pos  (12)
#define EVTTHCTL0_VDD5UV_Msk  (0x3U << EVTTHCTL0_VDD5UV_Pos)

#define EVTTHCTL0_VDD5UV_4P4V  ((0x00U) << EVTTHCTL0_VDD5UV_Pos)
#define EVTTHCTL0_VDD5UV_4P5V  ((0x01U) << EVTTHCTL0_VDD5UV_Pos)
#define EVTTHCTL0_VDD5UV_4P6V  ((0x02U) << EVTTHCTL0_VDD5UV_Pos)
#define EVTTHCTL0_VDD5UV_4P7V  ((0x03U) << EVTTHCTL0_VDD5UV_Pos)

#define EVTTHCTL0_VDD5UV_(x)  (((x) << EVTTHCTL0_VDD5UV_Pos) & EVTTHCTL0_VDD5UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL0       VDD5OV
  *  @access     HV->EVTTHCTL0
  *  @brief      VDD5 over-voltage event threshold
  */
#define EVTTHCTL0_VDD5OV_Pos  (14)
#define EVTTHCTL0_VDD5OV_Msk  (0x3U << EVTTHCTL0_VDD5OV_Pos)

#define EVTTHCTL0_VDD5OV_5P26V  ((0x00U) << EVTTHCTL0_VDD5OV_Pos)
#define EVTTHCTL0_VDD5OV_5P46V  ((0x01U) << EVTTHCTL0_VDD5OV_Pos)
#define EVTTHCTL0_VDD5OV_5P68V  ((0x02U) << EVTTHCTL0_VDD5OV_Pos)
#define EVTTHCTL0_VDD5OV_5P90V  ((0x03U) << EVTTHCTL0_VDD5OV_Pos)

#define EVTTHCTL0_VDD5OV_(x)  (((x) << EVTTHCTL0_VDD5OV_Pos) & EVTTHCTL0_VDD5OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL1       VDD5EXTUV
  *  @access     HV->EVTTHCTL1
  *  @brief      VDD5EXT under-voltage threshold
  */
#define EVTTHCTL1_VDD5EXTUV_Pos  (0)
#define EVTTHCTL1_VDD5EXTUV_Msk  (0x3U << EVTTHCTL1_VDD5EXTUV_Pos)

#define EVTTHCTL1_VDD5EXTUV_3P8V  ((0x00U) << EVTTHCTL1_VDD5EXTUV_Pos)
#define EVTTHCTL1_VDD5EXTUV_4P0V  ((0x01U) << EVTTHCTL1_VDD5EXTUV_Pos)
#define EVTTHCTL1_VDD5EXTUV_4P2V  ((0x02U) << EVTTHCTL1_VDD5EXTUV_Pos)
#define EVTTHCTL1_VDD5EXTUV_4P4V  ((0x03U) << EVTTHCTL1_VDD5EXTUV_Pos)

#define EVTTHCTL1_VDD5EXTUV_(x)  (((x) << EVTTHCTL1_VDD5EXTUV_Pos) & EVTTHCTL1_VDD5EXTUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL1       VDD5EXTOV
  *  @access     HV->EVTTHCTL1
  *  @brief      VDD5EXT over-voltage threshold
  */
#define EVTTHCTL1_VDD5EXTOV_Pos  (2)
#define EVTTHCTL1_VDD5EXTOV_Msk  (0x3U << EVTTHCTL1_VDD5EXTOV_Pos)

#define EVTTHCTL1_VDD5EXTOV_5P26V  ((0x00U) << EVTTHCTL1_VDD5EXTOV_Pos)
#define EVTTHCTL1_VDD5EXTOV_5P46V  ((0x01U) << EVTTHCTL1_VDD5EXTOV_Pos)
#define EVTTHCTL1_VDD5EXTOV_5P68V  ((0x02U) << EVTTHCTL1_VDD5EXTOV_Pos)
#define EVTTHCTL1_VDD5EXTOV_5P90V  ((0x03U) << EVTTHCTL1_VDD5EXTOV_Pos)

#define EVTTHCTL1_VDD5EXTOV_(x)  (((x) << EVTTHCTL1_VDD5EXTOV_Pos) & EVTTHCTL1_VDD5EXTOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL1       VDD3UV
  *  @access     HV->EVTTHCTL1
  *  @brief      VDD3 under-voltage threshold
  */
#define EVTTHCTL1_VDD3UV_Pos  (4)
#define EVTTHCTL1_VDD3UV_Msk  (0x3U << EVTTHCTL1_VDD3UV_Pos)

#define EVTTHCTL1_VDD3UV_2P57V  ((0x00U) << EVTTHCTL1_VDD3UV_Pos)
#define EVTTHCTL1_VDD3UV_2P70V  ((0x01U) << EVTTHCTL1_VDD3UV_Pos)
#define EVTTHCTL1_VDD3UV_2P85V  ((0x02U) << EVTTHCTL1_VDD3UV_Pos)
#define EVTTHCTL1_VDD3UV_3P00V  ((0x03U) << EVTTHCTL1_VDD3UV_Pos)

#define EVTTHCTL1_VDD3UV_(x)  (((x) << EVTTHCTL1_VDD3UV_Pos) & EVTTHCTL1_VDD3UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL1       VDD3OV
  *  @access     HV->EVTTHCTL1
  *  @brief      VDD3 over-voltage threshold
  */
#define EVTTHCTL1_VDD3OV_Pos  (6)
#define EVTTHCTL1_VDD3OV_Msk  (0x3U << EVTTHCTL1_VDD3OV_Pos)

#define EVTTHCTL1_VDD3OV_3P40V  ((0x00U) << EVTTHCTL1_VDD3OV_Pos)
#define EVTTHCTL1_VDD3OV_3P64V  ((0x01U) << EVTTHCTL1_VDD3OV_Pos)
#define EVTTHCTL1_VDD3OV_3P90V  ((0x02U) << EVTTHCTL1_VDD3OV_Pos)
#define EVTTHCTL1_VDD3OV_4P22V  ((0x03U) << EVTTHCTL1_VDD3OV_Pos)

#define EVTTHCTL1_VDD3OV_(x)  (((x) << EVTTHCTL1_VDD3OV_Pos) & EVTTHCTL1_VDD3OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL1       VCPUV
  *  @access     HV->EVTTHCTL1
  *  @brief      VCP under-voltage event threshold
  */
#define EVTTHCTL1_VCPUV_Pos  (8)
#define EVTTHCTL1_VCPUV_Msk  (0xFU << EVTTHCTL1_VCPUV_Pos)

#define EVTTHCTL1_VCPUV_VBAT_ADD_6dot097_V  ((0x0000U) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_6dot333_V  ((0x0001U) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_6dot568_V  ((0x0002U) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_6dot802_V  ((0x0003U) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_7dot039_V  ((0x0004U) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_7dot295_V  ((0x0005U) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_7dot509_V  ((0x0006U) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_7dot745_V  ((0x0007U) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_7dot982_V  ((0x0008U) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_8dot217_V  ((0x0009U) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_8dot452_V  ((0x000AU) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_8dot687_V  ((0x000BU) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_8dot922_V  ((0x000CU) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_9dot158_V  ((0x000DU) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_9dot393_V  ((0x000EU) << EVTTHCTL1_VCPUV_Pos)
#define EVTTHCTL1_VCPUV_VBAT_ADD_9dot629_V  ((0x000FU) << EVTTHCTL1_VCPUV_Pos)

#define EVTTHCTL1_VCPUV_(x)  (((x) << EVTTHCTL1_VCPUV_Pos) & EVTTHCTL1_VCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           EVTTHCTL1       VCPOV
  *  @access     HV->EVTTHCTL1
  *  @brief      VCP over-voltage event threshold
  */
#define EVTTHCTL1_VCPOV_Pos  (12)
#define EVTTHCTL1_VCPOV_Msk  (0xFU << EVTTHCTL1_VCPOV_Pos)

#define EVTTHCTL1_VCPOV_VBAT_ADD_11dot22_V  ((0x0000U) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_11dot43_V  ((0x0001U) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_11dot7_V   ((0x0002U) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_11dot94_V  ((0x0003U) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_12dot18_V  ((0x0004U) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_12dot42_V  ((0x0005U) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_12dot66_V  ((0x0006U) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_12dot9_V   ((0x0007U) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_13dot09_V  ((0x0008U) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_13dot38_V  ((0x0009U) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_13dot61_V  ((0x000AU) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_13dot85_V  ((0x000BU) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_14dot09_V  ((0x000CU) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_14dot33_V  ((0x000DU) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_14dot57_V  ((0x000EU) << EVTTHCTL1_VCPOV_Pos)
#define EVTTHCTL1_VCPOV_VBAT_ADD_14dot81_V  ((0x000FU) << EVTTHCTL1_VCPOV_Pos)

#define EVTTHCTL1_VCPOV_(x)  (((x) << EVTTHCTL1_VCPOV_Pos) & EVTTHCTL1_VCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL0        EN
  *  @access     HV->PDRVCTL0
  *  @brief      Pre-driver enable
  */
#define PDRVCTL0_EN_Pos  (0)
#define PDRVCTL0_EN_Msk  (0x1U << PDRVCTL0_EN_Pos)

#define PDRVCTL0_EN_DISABLE  ((0x0U) << PDRVCTL0_EN_Pos)
#define PDRVCTL0_EN_ENABLE   ((0x1U) << PDRVCTL0_EN_Pos)

#define PDRVCTL0_EN_(x)  (((x) << PDRVCTL0_EN_Pos) & PDRVCTL0_EN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL0        MAXHOLDEN
  *  @access     HV->PDRVCTL0
  *  @brief      Enable maximum hold during pre-driver switch
  */
#define PDRVCTL0_MAXHOLDEN_Pos  (1)
#define PDRVCTL0_MAXHOLDEN_Msk  (0x1U << PDRVCTL0_MAXHOLDEN_Pos)

#define PDRVCTL0_MAXHOLDEN_DISABLE  ((0x0U) << PDRVCTL0_MAXHOLDEN_Pos)
#define PDRVCTL0_MAXHOLDEN_ENABLE   ((0x1U) << PDRVCTL0_MAXHOLDEN_Pos)

#define PDRVCTL0_MAXHOLDEN_(x)  (((x) << PDRVCTL0_MAXHOLDEN_Pos) & PDRVCTL0_MAXHOLDEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL0        MINNOV
  *  @access     HV->PDRVCTL0
  *  @brief      Minimal non-overlap timing window
  */
#define PDRVCTL0_MINNOV_Pos  (2)
#define PDRVCTL0_MINNOV_Msk  (0x3U << PDRVCTL0_MINNOV_Pos)

#define PDRVCTL0_MINNOV_350NS   ((0x00U) << PDRVCTL0_MINNOV_Pos)
#define PDRVCTL0_MINNOV_750NS   ((0x01U) << PDRVCTL0_MINNOV_Pos)
#define PDRVCTL0_MINNOV_1550NS  ((0x02U) << PDRVCTL0_MINNOV_Pos)
#define PDRVCTL0_MINNOV_3150NS  ((0x03U) << PDRVCTL0_MINNOV_Pos)

#define PDRVCTL0_MINNOV_(x)  (((x) << PDRVCTL0_MINNOV_Pos) & PDRVCTL0_MINNOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL0        LSOCTH
  *  @access     HV->PDRVCTL0
  *  @brief      Low side over current detection threshold.
  *              It is via monitoring the Vds of external FET, and the threshold is Vds/Rdson,
  *              where Rdson is the on resistance of the external FET.
  */
#define PDRVCTL0_LSOCTH_Pos  (4)
#define PDRVCTL0_LSOCTH_Msk  (0xFU << PDRVCTL0_LSOCTH_Pos)

#define PDRVCTL0_LSOCTH_0P15V_DIV_RDSON  ((0x0000U) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_0P30V_DIV_RDSON  ((0x0001U) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_0P45V_DIV_RDSON  ((0x0002U) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_0P60V_DIV_RDSON  ((0x0003U) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_0P75V_DIV_RDSON  ((0x0004U) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_0P90V_DIV_RDSON  ((0x0005U) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_1P05V_DIV_RDSON  ((0x0006U) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_1P20V_DIV_RDSON  ((0x0007U) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_1P35V_DIV_RDSON  ((0x0008U) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_1P50V_DIV_RDSON  ((0x0009U) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_1P65V_DIV_RDSON  ((0x000AU) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_1P80V_DIV_RDSON  ((0x000BU) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_1P95V_DIV_RDSON  ((0x000CU) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_2P10V_DIV_RDSON  ((0x000DU) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_2P25V_DIV_RDSON  ((0x000EU) << PDRVCTL0_LSOCTH_Pos)
#define PDRVCTL0_LSOCTH_2P40V_DIV_RDSON  ((0x000FU) << PDRVCTL0_LSOCTH_Pos)

#define PDRVCTL0_LSOCTH_(x)  (((x) << PDRVCTL0_LSOCTH_Pos) & PDRVCTL0_LSOCTH_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL0        DGCLKDIV
  *  @access     HV->PDRVCTL0
  *  @brief      Vds monitor deglitch clock dividing ratio.
  *              The blanking and filtering windows are scaled up accordingly
  */
#define PDRVCTL0_DGCLKDIV_Pos  (8)
#define PDRVCTL0_DGCLKDIV_Msk  (0x3U << PDRVCTL0_DGCLKDIV_Pos)

#define PDRVCTL0_DGCLKDIV_1  ((0x00U) << PDRVCTL0_DGCLKDIV_Pos)
#define PDRVCTL0_DGCLKDIV_2  ((0x01U) << PDRVCTL0_DGCLKDIV_Pos)
#define PDRVCTL0_DGCLKDIV_4  ((0x02U) << PDRVCTL0_DGCLKDIV_Pos)
#define PDRVCTL0_DGCLKDIV_8  ((0x03U) << PDRVCTL0_DGCLKDIV_Pos)

#define PDRVCTL0_DGCLKDIV_(x)  (((x) << PDRVCTL0_DGCLKDIV_Pos) & PDRVCTL0_DGCLKDIV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL0        BLANKWIN
  *  @access     HV->PDRVCTL0
  *  @brief      Vds monitor blanking window size
  */
#define PDRVCTL0_BLANKWIN_Pos  (10)
#define PDRVCTL0_BLANKWIN_Msk  (0x3U << PDRVCTL0_BLANKWIN_Pos)

#define PDRVCTL0_BLANKWIN_350NS   ((0x00U) << PDRVCTL0_BLANKWIN_Pos)
#define PDRVCTL0_BLANKWIN_750NS   ((0x01U) << PDRVCTL0_BLANKWIN_Pos)
#define PDRVCTL0_BLANKWIN_1550NS  ((0x02U) << PDRVCTL0_BLANKWIN_Pos)
#define PDRVCTL0_BLANKWIN_3150NS  ((0x03U) << PDRVCTL0_BLANKWIN_Pos)

#define PDRVCTL0_BLANKWIN_(x)  (((x) << PDRVCTL0_BLANKWIN_Pos) & PDRVCTL0_BLANKWIN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL0        FILTERWIN
  *  @access     HV->PDRVCTL0
  *  @brief      Vds monitor deglitch filter window size
  */
#define PDRVCTL0_FILTERWIN_Pos  (12)
#define PDRVCTL0_FILTERWIN_Msk  (0x3U << PDRVCTL0_FILTERWIN_Pos)

#define PDRVCTL0_FILTERWIN_350NS   ((0x00U) << PDRVCTL0_FILTERWIN_Pos)
#define PDRVCTL0_FILTERWIN_750NS   ((0x01U) << PDRVCTL0_FILTERWIN_Pos)
#define PDRVCTL0_FILTERWIN_1550NS  ((0x02U) << PDRVCTL0_FILTERWIN_Pos)
#define PDRVCTL0_FILTERWIN_3150NS  ((0x03U) << PDRVCTL0_FILTERWIN_Pos)

#define PDRVCTL0_FILTERWIN_(x)  (((x) << PDRVCTL0_FILTERWIN_Pos) & PDRVCTL0_FILTERWIN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL1        VCPLVL
  *  @access     HV->PDRVCTL1
  *  @brief      VCP level above VBAT
  */
#define PDRVCTL1_VCPLVL_Pos  (0)
#define PDRVCTL1_VCPLVL_Msk  (0x7U << PDRVCTL1_VCPLVL_Pos)

#define PDRVCTL1_VCPLVL_9P7V   ((0x000U) << PDRVCTL1_VCPLVL_Pos)
#define PDRVCTL1_VCPLVL_10P1V  ((0x001U) << PDRVCTL1_VCPLVL_Pos)
#define PDRVCTL1_VCPLVL_10P7V  ((0x002U) << PDRVCTL1_VCPLVL_Pos)
#define PDRVCTL1_VCPLVL_11P4V  ((0x003U) << PDRVCTL1_VCPLVL_Pos)
#define PDRVCTL1_VCPLVL_12P0V  ((0x004U) << PDRVCTL1_VCPLVL_Pos)
#define PDRVCTL1_VCPLVL_12P8V  ((0x005U) << PDRVCTL1_VCPLVL_Pos)
#define PDRVCTL1_VCPLVL_13P5V  ((0x006U) << PDRVCTL1_VCPLVL_Pos)
#define PDRVCTL1_VCPLVL_14P4V  ((0x007U) << PDRVCTL1_VCPLVL_Pos)

#define PDRVCTL1_VCPLVL_(x)  (((x) << PDRVCTL1_VCPLVL_Pos) & PDRVCTL1_VCPLVL_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL1        LSVGS
  *  @access     HV->PDRVCTL1
  *  @brief      Pre-driver low-side Vgs select
  */
#define PDRVCTL1_LSVGS_Pos  (3)
#define PDRVCTL1_LSVGS_Msk  (0x7U << PDRVCTL1_LSVGS_Pos)

#define PDRVCTL1_LSVGS_8P15V  ((0x000U) << PDRVCTL1_LSVGS_Pos)
#define PDRVCTL1_LSVGS_8P5V   ((0x001U) << PDRVCTL1_LSVGS_Pos)
#define PDRVCTL1_LSVGS_8P9V   ((0x002U) << PDRVCTL1_LSVGS_Pos)
#define PDRVCTL1_LSVGS_9P3V   ((0x003U) << PDRVCTL1_LSVGS_Pos)
#define PDRVCTL1_LSVGS_9P6V   ((0x004U) << PDRVCTL1_LSVGS_Pos)
#define PDRVCTL1_LSVGS_10P0V  ((0x005U) << PDRVCTL1_LSVGS_Pos)
#define PDRVCTL1_LSVGS_10P4V  ((0x006U) << PDRVCTL1_LSVGS_Pos)
#define PDRVCTL1_LSVGS_11P4V  ((0x007U) << PDRVCTL1_LSVGS_Pos)

#define PDRVCTL1_LSVGS_(x)  (((x) << PDRVCTL1_LSVGS_Pos) & PDRVCTL1_LSVGS_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL1        STATICSTR
  *  @access     HV->PDRVCTL1
  *  @brief      Static pull-up and pull-down strength when not switch
  */
#define PDRVCTL1_STATICSTR_Pos  (6)
#define PDRVCTL1_STATICSTR_Msk  (0x1FU << PDRVCTL1_STATICSTR_Pos)

#define PDRVCTL1_STATICSTR_(x)  (((x) << PDRVCTL1_STATICSTR_Pos) & PDRVCTL1_STATICSTR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL1        SSMODE
  *  @access     HV->PDRVCTL1
  *  @brief      Dithering mode on charge-pump clock for spread spectrum
  */
#define PDRVCTL1_SSMODE_Pos  (11)
#define PDRVCTL1_SSMODE_Msk  (0x3U << PDRVCTL1_SSMODE_Pos)

#define PDRVCTL1_SSMODE_FIXED_DIV       ((0x00U) << PDRVCTL1_SSMODE_Pos)
#define PDRVCTL1_SSMODE_DIV8_OR_DIV16   ((0x01U) << PDRVCTL1_SSMODE_Pos)
#define PDRVCTL1_SSMODE_DIV16_OR_DIV32  ((0x02U) << PDRVCTL1_SSMODE_Pos)
#define PDRVCTL1_SSMODE_DIV32_OR_DIV64  ((0x03U) << PDRVCTL1_SSMODE_Pos)

#define PDRVCTL1_SSMODE_(x)  (((x) << PDRVCTL1_SSMODE_Pos) & PDRVCTL1_SSMODE_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL1        SSPRD
  *  @access     HV->PDRVCTL1
  *  @brief      Dithering period on charge-pump clock for spread spectrum
  */
#define PDRVCTL1_SSPRD_Pos  (13)
#define PDRVCTL1_SSPRD_Msk  (0x1U << PDRVCTL1_SSPRD_Pos)

#define PDRVCTL1_SSPRD_256X  ((0x0U) << PDRVCTL1_SSPRD_Pos)
#define PDRVCTL1_SSPRD_512X  ((0x1U) << PDRVCTL1_SSPRD_Pos)

#define PDRVCTL1_SSPRD_(x)  (((x) << PDRVCTL1_SSPRD_Pos) & PDRVCTL1_SSPRD_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL1        MEADLYMODE
  *  @access     HV->PDRVCTL1
  *  @brief      Pre-driver path delay measurement end point mode
  */
#define PDRVCTL1_MEADLYMODE_Pos  (14)
#define PDRVCTL1_MEADLYMODE_Msk  (0x1U << PDRVCTL1_MEADLYMODE_Pos)

#define PDRVCTL1_MEADLYMODE_OTHER_SIDE_OC_RISE  ((0x0U) << PDRVCTL1_MEADLYMODE_Pos)
#define PDRVCTL1_MEADLYMODE_SAME_SIDE_OC_FALL   ((0x1U) << PDRVCTL1_MEADLYMODE_Pos)

#define PDRVCTL1_MEADLYMODE_(x)  (((x) << PDRVCTL1_MEADLYMODE_Pos) & PDRVCTL1_MEADLYMODE_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL1        MEADLYEN
  *  @access     HV->PDRVCTL1
  *  @brief      Pre-driver path delay measurement enable
  */
#define PDRVCTL1_MEADLYEN_Pos  (15)
#define PDRVCTL1_MEADLYEN_Msk  (0x1U << PDRVCTL1_MEADLYEN_Pos)

#define PDRVCTL1_MEADLYEN_DISABLE  ((0x0U) << PDRVCTL1_MEADLYEN_Pos)
#define PDRVCTL1_MEADLYEN_ENABLE   ((0x1U) << PDRVCTL1_MEADLYEN_Pos)

#define PDRVCTL1_MEADLYEN_(x)  (((x) << PDRVCTL1_MEADLYEN_Pos) & PDRVCTL1_MEADLYEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPDSTR0    STRENTH0
  *  @access     HV->PDRVLSPDSTR0
  *  @brief      Pull-down strength for time segment 0, which is 10mA*(code+1)
  */
#define PDRVLSPDSTR0_STRENTH0_Pos  (0)
#define PDRVLSPDSTR0_STRENTH0_Msk  (0x1FU << PDRVLSPDSTR0_STRENTH0_Pos)

#define PDRVLSPDSTR0_STRENTH0_(x)  (((x) << PDRVLSPDSTR0_STRENTH0_Pos) & PDRVLSPDSTR0_STRENTH0_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPDSTR0    STRENTH1
  *  @access     HV->PDRVLSPDSTR0
  *  @brief      Pull-down strength for time segment 1, which is 10mA*(code+1)
  */
#define PDRVLSPDSTR0_STRENTH1_Pos  (8)
#define PDRVLSPDSTR0_STRENTH1_Msk  (0x1FU << PDRVLSPDSTR0_STRENTH1_Pos)

#define PDRVLSPDSTR0_STRENTH1_(x)  (((x) << PDRVLSPDSTR0_STRENTH1_Pos) & PDRVLSPDSTR0_STRENTH1_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPDSTR1    STRENTH2
  *  @access     HV->PDRVLSPDSTR1
  *  @brief      Pull-down strength for time segment 2, which is 10mA*(code+1)
  */
#define PDRVLSPDSTR1_STRENTH2_Pos  (0)
#define PDRVLSPDSTR1_STRENTH2_Msk  (0x1FU << PDRVLSPDSTR1_STRENTH2_Pos)

#define PDRVLSPDSTR1_STRENTH2_(x)  (((x) << PDRVLSPDSTR1_STRENTH2_Pos) & PDRVLSPDSTR1_STRENTH2_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPDSTR1    STRENTH3
  *  @access     HV->PDRVLSPDSTR1
  *  @brief      Pull-down strength for time segment 3, which is 10mA*(code+1)
  */
#define PDRVLSPDSTR1_STRENTH3_Pos  (8)
#define PDRVLSPDSTR1_STRENTH3_Msk  (0x1FU << PDRVLSPDSTR1_STRENTH3_Pos)

#define PDRVLSPDSTR1_STRENTH3_(x)  (((x) << PDRVLSPDSTR1_STRENTH3_Pos) & PDRVLSPDSTR1_STRENTH3_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPUSTR0    STRENTH0
  *  @access     HV->PDRVLSPUSTR0
  *  @brief      Pull-up strength for time segment 0, which is 10mA*(code+1)
  */
#define PDRVLSPUSTR0_STRENTH0_Pos  (0)
#define PDRVLSPUSTR0_STRENTH0_Msk  (0x1FU << PDRVLSPUSTR0_STRENTH0_Pos)

#define PDRVLSPUSTR0_STRENTH0_(x)  (((x) << PDRVLSPUSTR0_STRENTH0_Pos) & PDRVLSPUSTR0_STRENTH0_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPUSTR0    STRENTH1
  *  @access     HV->PDRVLSPUSTR0
  *  @brief      Pull-up strength for time segment 1, which is 10mA*(code+1)
  */
#define PDRVLSPUSTR0_STRENTH1_Pos  (8)
#define PDRVLSPUSTR0_STRENTH1_Msk  (0x1FU << PDRVLSPUSTR0_STRENTH1_Pos)

#define PDRVLSPUSTR0_STRENTH1_(x)  (((x) << PDRVLSPUSTR0_STRENTH1_Pos) & PDRVLSPUSTR0_STRENTH1_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPUSTR1    STRENTH2
  *  @access     HV->PDRVLSPUSTR1
  *  @brief      Pull-up strength for time segment 2, which is 10mA*(code+1)
  */
#define PDRVLSPUSTR1_STRENTH2_Pos  (0)
#define PDRVLSPUSTR1_STRENTH2_Msk  (0x1FU << PDRVLSPUSTR1_STRENTH2_Pos)

#define PDRVLSPUSTR1_STRENTH2_(x)  (((x) << PDRVLSPUSTR1_STRENTH2_Pos) & PDRVLSPUSTR1_STRENTH2_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPUSTR1    STRENTH3
  *  @access     HV->PDRVLSPUSTR1
  *  @brief      Pull-up strength for time segment 3, which is 10mA*(code+1)
  */
#define PDRVLSPUSTR1_STRENTH3_Pos  (8)
#define PDRVLSPUSTR1_STRENTH3_Msk  (0x1FU << PDRVLSPUSTR1_STRENTH3_Pos)

#define PDRVLSPUSTR1_STRENTH3_(x)  (((x) << PDRVLSPUSTR1_STRENTH3_Pos) & PDRVLSPUSTR1_STRENTH3_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPDSTR0    STRENTH0
  *  @access     HV->PDRVHSPDSTR0
  *  @brief      Pull-down strength for time segment 0, which is 10mA*(code+1)
  */
#define PDRVHSPDSTR0_STRENTH0_Pos  (0)
#define PDRVHSPDSTR0_STRENTH0_Msk  (0x1FU << PDRVHSPDSTR0_STRENTH0_Pos)

#define PDRVHSPDSTR0_STRENTH0_(x)  (((x) << PDRVHSPDSTR0_STRENTH0_Pos) & PDRVHSPDSTR0_STRENTH0_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPDSTR0    STRENTH1
  *  @access     HV->PDRVHSPDSTR0
  *  @brief      Pull-down strength for time segment 1, which is 10mA*(code+1)
  */
#define PDRVHSPDSTR0_STRENTH1_Pos  (8)
#define PDRVHSPDSTR0_STRENTH1_Msk  (0x1FU << PDRVHSPDSTR0_STRENTH1_Pos)

#define PDRVHSPDSTR0_STRENTH1_(x)  (((x) << PDRVHSPDSTR0_STRENTH1_Pos) & PDRVHSPDSTR0_STRENTH1_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPDSTR1    STRENTH2
  *  @access     HV->PDRVHSPDSTR1
  *  @brief      Pull-down strength for time segment 2, which is 10mA*(code+1)
  */
#define PDRVHSPDSTR1_STRENTH2_Pos  (0)
#define PDRVHSPDSTR1_STRENTH2_Msk  (0x1FU << PDRVHSPDSTR1_STRENTH2_Pos)

#define PDRVHSPDSTR1_STRENTH2_(x)  (((x) << PDRVHSPDSTR1_STRENTH2_Pos) & PDRVHSPDSTR1_STRENTH2_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPDSTR1    STRENTH3
  *  @access     HV->PDRVHSPDSTR1
  *  @brief      Pull-down strength for time segment 3, which is 10mA*(code+1)
  */
#define PDRVHSPDSTR1_STRENTH3_Pos  (8)
#define PDRVHSPDSTR1_STRENTH3_Msk  (0x1FU << PDRVHSPDSTR1_STRENTH3_Pos)

#define PDRVHSPDSTR1_STRENTH3_(x)  (((x) << PDRVHSPDSTR1_STRENTH3_Pos) & PDRVHSPDSTR1_STRENTH3_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPUSTR0    STRENTH0
  *  @access     HV->PDRVHSPUSTR0
  *  @brief      Pull-up strength for time segment 0, which is 10mA*(code+1)
  */
#define PDRVHSPUSTR0_STRENTH0_Pos  (0)
#define PDRVHSPUSTR0_STRENTH0_Msk  (0x1FU << PDRVHSPUSTR0_STRENTH0_Pos)

#define PDRVHSPUSTR0_STRENTH0_(x)  (((x) << PDRVHSPUSTR0_STRENTH0_Pos) & PDRVHSPUSTR0_STRENTH0_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPUSTR0    STRENTH1
  *  @access     HV->PDRVHSPUSTR0
  *  @brief      Pull-up strength for time segment 1, which is 10mA*(code+1)
  */
#define PDRVHSPUSTR0_STRENTH1_Pos  (8)
#define PDRVHSPUSTR0_STRENTH1_Msk  (0x1FU << PDRVHSPUSTR0_STRENTH1_Pos)

#define PDRVHSPUSTR0_STRENTH1_(x)  (((x) << PDRVHSPUSTR0_STRENTH1_Pos) & PDRVHSPUSTR0_STRENTH1_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPUSTR1    STRENTH2
  *  @access     HV->PDRVHSPUSTR1
  *  @brief      Pull-up strength for time segment 2, which is 10mA*(code+1)
  */
#define PDRVHSPUSTR1_STRENTH2_Pos  (0)
#define PDRVHSPUSTR1_STRENTH2_Msk  (0x1FU << PDRVHSPUSTR1_STRENTH2_Pos)

#define PDRVHSPUSTR1_STRENTH2_(x)  (((x) << PDRVHSPUSTR1_STRENTH2_Pos) & PDRVHSPUSTR1_STRENTH2_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPUSTR1    STRENTH3
  *  @access     HV->PDRVHSPUSTR1
  *  @brief      Pull-up strength for time segment 3, which is 10mA*(code+1)
  */
#define PDRVHSPUSTR1_STRENTH3_Pos  (8)
#define PDRVHSPUSTR1_STRENTH3_Msk  (0x1FU << PDRVHSPUSTR1_STRENTH3_Pos)

#define PDRVHSPUSTR1_STRENTH3_(x)  (((x) << PDRVHSPUSTR1_STRENTH3_Pos) & PDRVHSPUSTR1_STRENTH3_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPDLEN     LEN0
  *  @access     HV->PDRVLSPDLEN
  *  @brief      Pull-down time segment 0 length, which is 25ns*code
  */
#define PDRVLSPDLEN_LEN0_Pos  (0)
#define PDRVLSPDLEN_LEN0_Msk  (0xFU << PDRVLSPDLEN_LEN0_Pos)

#define PDRVLSPDLEN_LEN0_(x)  (((x) << PDRVLSPDLEN_LEN0_Pos) & PDRVLSPDLEN_LEN0_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPDLEN     LEN1
  *  @access     HV->PDRVLSPDLEN
  *  @brief      Pull-down time segment 1 length, which is 25ns*code
  */
#define PDRVLSPDLEN_LEN1_Pos  (4)
#define PDRVLSPDLEN_LEN1_Msk  (0xFU << PDRVLSPDLEN_LEN1_Pos)

#define PDRVLSPDLEN_LEN1_(x)  (((x) << PDRVLSPDLEN_LEN1_Pos) & PDRVLSPDLEN_LEN1_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPDLEN     LEN2
  *  @access     HV->PDRVLSPDLEN
  *  @brief      Pull-down time segment 2 length, which is 25ns*code
  */
#define PDRVLSPDLEN_LEN2_Pos  (8)
#define PDRVLSPDLEN_LEN2_Msk  (0xFU << PDRVLSPDLEN_LEN2_Pos)

#define PDRVLSPDLEN_LEN2_(x)  (((x) << PDRVLSPDLEN_LEN2_Pos) & PDRVLSPDLEN_LEN2_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPDLEN     LEN3
  *  @access     HV->PDRVLSPDLEN
  *  @brief      Pull-down time segment 3 length, which is 25ns*code
  */
#define PDRVLSPDLEN_LEN3_Pos  (12)
#define PDRVLSPDLEN_LEN3_Msk  (0xFU << PDRVLSPDLEN_LEN3_Pos)

#define PDRVLSPDLEN_LEN3_(x)  (((x) << PDRVLSPDLEN_LEN3_Pos) & PDRVLSPDLEN_LEN3_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPULEN     LEN0
  *  @access     HV->PDRVLSPULEN
  *  @brief      Pull-up time segment 0 length, which is 25ns*code
  */
#define PDRVLSPULEN_LEN0_Pos  (0)
#define PDRVLSPULEN_LEN0_Msk  (0xFU << PDRVLSPULEN_LEN0_Pos)

#define PDRVLSPULEN_LEN0_(x)  (((x) << PDRVLSPULEN_LEN0_Pos) & PDRVLSPULEN_LEN0_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPULEN     LEN1
  *  @access     HV->PDRVLSPULEN
  *  @brief      Pull-up time segment 1 length, which is 25ns*code
  */
#define PDRVLSPULEN_LEN1_Pos  (4)
#define PDRVLSPULEN_LEN1_Msk  (0xFU << PDRVLSPULEN_LEN1_Pos)

#define PDRVLSPULEN_LEN1_(x)  (((x) << PDRVLSPULEN_LEN1_Pos) & PDRVLSPULEN_LEN1_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPULEN     LEN2
  *  @access     HV->PDRVLSPULEN
  *  @brief      Pull-up time segment 2 length, which is 25ns*code
  */
#define PDRVLSPULEN_LEN2_Pos  (8)
#define PDRVLSPULEN_LEN2_Msk  (0xFU << PDRVLSPULEN_LEN2_Pos)

#define PDRVLSPULEN_LEN2_(x)  (((x) << PDRVLSPULEN_LEN2_Pos) & PDRVLSPULEN_LEN2_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVLSPULEN     LEN3
  *  @access     HV->PDRVLSPULEN
  *  @brief      Pull-up time segment 3 length, which is 25ns*code
  */
#define PDRVLSPULEN_LEN3_Pos  (12)
#define PDRVLSPULEN_LEN3_Msk  (0xFU << PDRVLSPULEN_LEN3_Pos)

#define PDRVLSPULEN_LEN3_(x)  (((x) << PDRVLSPULEN_LEN3_Pos) & PDRVLSPULEN_LEN3_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPDLEN     LEN0
  *  @access     HV->PDRVHSPDLEN
  *  @brief      Pull-down time segment 0 length, which is 25ns*code
  */
#define PDRVHSPDLEN_LEN0_Pos  (0)
#define PDRVHSPDLEN_LEN0_Msk  (0xFU << PDRVHSPDLEN_LEN0_Pos)

#define PDRVHSPDLEN_LEN0_(x)  (((x) << PDRVHSPDLEN_LEN0_Pos) & PDRVHSPDLEN_LEN0_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPDLEN     LEN1
  *  @access     HV->PDRVHSPDLEN
  *  @brief      Pull-down time segment 1 length, which is 25ns*code
  */
#define PDRVHSPDLEN_LEN1_Pos  (4)
#define PDRVHSPDLEN_LEN1_Msk  (0xFU << PDRVHSPDLEN_LEN1_Pos)

#define PDRVHSPDLEN_LEN1_(x)  (((x) << PDRVHSPDLEN_LEN1_Pos) & PDRVHSPDLEN_LEN1_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPDLEN     LEN2
  *  @access     HV->PDRVHSPDLEN
  *  @brief      Pull-down time segment 2 length, which is 25ns*code
  */
#define PDRVHSPDLEN_LEN2_Pos  (8)
#define PDRVHSPDLEN_LEN2_Msk  (0xFU << PDRVHSPDLEN_LEN2_Pos)

#define PDRVHSPDLEN_LEN2_(x)  (((x) << PDRVHSPDLEN_LEN2_Pos) & PDRVHSPDLEN_LEN2_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPDLEN     LEN3
  *  @access     HV->PDRVHSPDLEN
  *  @brief      Pull-down time segment 3 length, which is 25ns*code
  */
#define PDRVHSPDLEN_LEN3_Pos  (12)
#define PDRVHSPDLEN_LEN3_Msk  (0xFU << PDRVHSPDLEN_LEN3_Pos)

#define PDRVHSPDLEN_LEN3_(x)  (((x) << PDRVHSPDLEN_LEN3_Pos) & PDRVHSPDLEN_LEN3_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPULEN     LEN0
  *  @access     HV->PDRVHSPULEN
  *  @brief      Pull-up time segment 0 length, which is 25ns*code
  */
#define PDRVHSPULEN_LEN0_Pos  (0)
#define PDRVHSPULEN_LEN0_Msk  (0xFU << PDRVHSPULEN_LEN0_Pos)

#define PDRVHSPULEN_LEN0_(x)  (((x) << PDRVHSPULEN_LEN0_Pos) & PDRVHSPULEN_LEN0_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPULEN     LEN1
  *  @access     HV->PDRVHSPULEN
  *  @brief      Pull-up time segment 1 length, which is 25ns*code
  */
#define PDRVHSPULEN_LEN1_Pos  (4)
#define PDRVHSPULEN_LEN1_Msk  (0xFU << PDRVHSPULEN_LEN1_Pos)

#define PDRVHSPULEN_LEN1_(x)  (((x) << PDRVHSPULEN_LEN1_Pos) & PDRVHSPULEN_LEN1_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPULEN     LEN2
  *  @access     HV->PDRVHSPULEN
  *  @brief      Pull-up time segment 2 length, which is 25ns*code
  */
#define PDRVHSPULEN_LEN2_Pos  (8)
#define PDRVHSPULEN_LEN2_Msk  (0xFU << PDRVHSPULEN_LEN2_Pos)

#define PDRVHSPULEN_LEN2_(x)  (((x) << PDRVHSPULEN_LEN2_Pos) & PDRVHSPULEN_LEN2_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVHSPULEN     LEN3
  *  @access     HV->PDRVHSPULEN
  *  @brief      Pull-up time segment 3 length, which is 25ns*code
  */
#define PDRVHSPULEN_LEN3_Pos  (12)
#define PDRVHSPULEN_LEN3_Msk  (0xFU << PDRVHSPULEN_LEN3_Pos)

#define PDRVHSPULEN_LEN3_(x)  (((x) << PDRVHSPULEN_LEN3_Pos) & PDRVHSPULEN_LEN3_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVDLYU        LSDLY
  *  @access     HV->PDRVDLYU
  *  @brief      Low-side measured turn-on delay, which is LSDLY*25ns
  */
#define PDRVDLYU_LSDLY_Pos  (0)
#define PDRVDLYU_LSDLY_Msk  (0xFFU << PDRVDLYU_LSDLY_Pos)

#define PDRVDLYU_LSDLY_(x)  (((x) << PDRVDLYU_LSDLY_Pos) & PDRVDLYU_LSDLY_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVDLYU        HSDLY
  *  @access     HV->PDRVDLYU
  *  @brief      High-side measured turn-on delay, which is HSDLY*25ns
  */
#define PDRVDLYU_HSDLY_Pos  (8)
#define PDRVDLYU_HSDLY_Msk  (0xFFU << PDRVDLYU_HSDLY_Pos)

#define PDRVDLYU_HSDLY_(x)  (((x) << PDRVDLYU_HSDLY_Pos) & PDRVDLYU_HSDLY_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVDLYV        LSDLY
  *  @access     HV->PDRVDLYV
  *  @brief      Low-side measured turn-on delay, which is LSDLY*25ns
  */
#define PDRVDLYV_LSDLY_Pos  (0)
#define PDRVDLYV_LSDLY_Msk  (0xFFU << PDRVDLYV_LSDLY_Pos)

#define PDRVDLYV_LSDLY_(x)  (((x) << PDRVDLYV_LSDLY_Pos) & PDRVDLYV_LSDLY_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVDLYV        HSDLY
  *  @access     HV->PDRVDLYV
  *  @brief      High-side measured turn-on delay, which is HSDLY*25ns
  */
#define PDRVDLYV_HSDLY_Pos  (8)
#define PDRVDLYV_HSDLY_Msk  (0xFFU << PDRVDLYV_HSDLY_Pos)

#define PDRVDLYV_HSDLY_(x)  (((x) << PDRVDLYV_HSDLY_Pos) & PDRVDLYV_HSDLY_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVDLYW        LSDLY
  *  @access     HV->PDRVDLYW
  *  @brief      Low-side measured turn-on delay, which is LSDLY*25ns
  */
#define PDRVDLYW_LSDLY_Pos  (0)
#define PDRVDLYW_LSDLY_Msk  (0xFFU << PDRVDLYW_LSDLY_Pos)

#define PDRVDLYW_LSDLY_(x)  (((x) << PDRVDLYW_LSDLY_Pos) & PDRVDLYW_LSDLY_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVDLYW        HSDLY
  *  @access     HV->PDRVDLYW
  *  @brief      High-side measured turn-on delay, which is HSDLY*25ns
  */
#define PDRVDLYW_HSDLY_Pos  (8)
#define PDRVDLYW_HSDLY_Msk  (0xFFU << PDRVDLYW_HSDLY_Pos)

#define PDRVDLYW_HSDLY_(x)  (((x) << PDRVDLYW_HSDLY_Pos) & PDRVDLYW_HSDLY_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINCTL          EN
  *  @access     HV->LINCTL
  *  @brief      LIN enable
  *              This bit should be written as 1 when enable transmitter and over-temperature
  *              detect function
  */
#define LINCTL_EN_Pos  (0)
#define LINCTL_EN_Msk  (0x1U << LINCTL_EN_Pos)

#define LINCTL_EN_DISABLE  ((0x0U) << LINCTL_EN_Pos)
#define LINCTL_EN_ENABLE   ((0x1U) << LINCTL_EN_Pos)

#define LINCTL_EN_(x)  (((x) << LINCTL_EN_Pos) & LINCTL_EN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINCTL          TXEN
  *  @access     HV->LINCTL
  *  @brief      LIN transmmiter enable
  *              This bit will be automatically cleared as 0 if EN bit is written as 0 or the
  *              events as selected in LINTXPDEVTEN register happens
  */
#define LINCTL_TXEN_Pos  (1)
#define LINCTL_TXEN_Msk  (0x1U << LINCTL_TXEN_Pos)

#define LINCTL_TXEN_DISABLE  ((0x0U) << LINCTL_TXEN_Pos)
#define LINCTL_TXEN_ENABLE   ((0x1U) << LINCTL_TXEN_Pos)

#define LINCTL_TXEN_(x)  (((x) << LINCTL_TXEN_Pos) & LINCTL_TXEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINCTL          OTEN
  *  @access     HV->LINCTL
  *  @brief      LIN over-temperature detect enable
  *              This bit will be automatically cleared as 0 if EN bit is written as 0
  */
#define LINCTL_OTEN_Pos  (2)
#define LINCTL_OTEN_Msk  (0x1U << LINCTL_OTEN_Pos)

#define LINCTL_OTEN_DISABLE  ((0x0U) << LINCTL_OTEN_Pos)
#define LINCTL_OTEN_ENABLE   ((0x1U) << LINCTL_OTEN_Pos)

#define LINCTL_OTEN_(x)  (((x) << LINCTL_OTEN_Pos) & LINCTL_OTEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINCTL          OTTH
  *  @access     HV->LINCTL
  *  @brief      LIN over-temperature threshold
  */
#define LINCTL_OTTH_Pos  (3)
#define LINCTL_OTTH_Msk  (0x7U << LINCTL_OTTH_Pos)

#define LINCTL_OTTH_129C  ((0x000U) << LINCTL_OTTH_Pos)
#define LINCTL_OTTH_137C  ((0x001U) << LINCTL_OTTH_Pos)
#define LINCTL_OTTH_145C  ((0x002U) << LINCTL_OTTH_Pos)
#define LINCTL_OTTH_153C  ((0x003U) << LINCTL_OTTH_Pos)
#define LINCTL_OTTH_161C  ((0x004U) << LINCTL_OTTH_Pos)
#define LINCTL_OTTH_170C  ((0x005U) << LINCTL_OTTH_Pos)
#define LINCTL_OTTH_178C  ((0x006U) << LINCTL_OTTH_Pos)
#define LINCTL_OTTH_186C  ((0x007U) << LINCTL_OTTH_Pos)

#define LINCTL_OTTH_(x)  (((x) << LINCTL_OTTH_Pos) & LINCTL_OTTH_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINCTL          RLOAD
  *  @access     HV->LINCTL
  *  @brief      LIN transmitter loading resistance
  */
#define LINCTL_RLOAD_Pos  (10)
#define LINCTL_RLOAD_Msk  (0x7U << LINCTL_RLOAD_Pos)

#define LINCTL_RLOAD_938_OHM  ((0x000U) << LINCTL_RLOAD_Pos)
#define LINCTL_RLOAD_857_OHM  ((0x001U) << LINCTL_RLOAD_Pos)
#define LINCTL_RLOAD_770_OHM  ((0x002U) << LINCTL_RLOAD_Pos)
#define LINCTL_RLOAD_698_OHM  ((0x003U) << LINCTL_RLOAD_Pos)
#define LINCTL_RLOAD_650_OHM  ((0x004U) << LINCTL_RLOAD_Pos)
#define LINCTL_RLOAD_580_OHM  ((0x005U) << LINCTL_RLOAD_Pos)
#define LINCTL_RLOAD_500_OHM  ((0x006U) << LINCTL_RLOAD_Pos)
#define LINCTL_RLOAD_440_OHM  ((0x007U) << LINCTL_RLOAD_Pos)

#define LINCTL_RLOAD_(x)  (((x) << LINCTL_RLOAD_Pos) & LINCTL_RLOAD_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXPDEVTEN    VBATUV
  *  @access     HV->LINTXPDEVTEN
  *  @brief      Shut down LIN transmitter upon VBAT under-voltage event
  */
#define LINTXPDEVTEN_VBATUV_Pos  (0)
#define LINTXPDEVTEN_VBATUV_Msk  (0x1U << LINTXPDEVTEN_VBATUV_Pos)

#define LINTXPDEVTEN_VBATUV_DISABLE  ((0x0U) << LINTXPDEVTEN_VBATUV_Pos)
#define LINTXPDEVTEN_VBATUV_ENABLE   ((0x1U) << LINTXPDEVTEN_VBATUV_Pos)

#define LINTXPDEVTEN_VBATUV_(x)  (((x) << LINTXPDEVTEN_VBATUV_Pos) & LINTXPDEVTEN_VBATUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXPDEVTEN    VDD5UV
  *  @access     HV->LINTXPDEVTEN
  *  @brief      Shut down LIN transmitter upon VDD5 under-voltage event
  */
#define LINTXPDEVTEN_VDD5UV_Pos  (1)
#define LINTXPDEVTEN_VDD5UV_Msk  (0x1U << LINTXPDEVTEN_VDD5UV_Pos)

#define LINTXPDEVTEN_VDD5UV_DISABLE  ((0x0U) << LINTXPDEVTEN_VDD5UV_Pos)
#define LINTXPDEVTEN_VDD5UV_ENABLE   ((0x1U) << LINTXPDEVTEN_VDD5UV_Pos)

#define LINTXPDEVTEN_VDD5UV_(x)  (((x) << LINTXPDEVTEN_VDD5UV_Pos) & LINTXPDEVTEN_VDD5UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXPDEVTEN    VDD3UV
  *  @access     HV->LINTXPDEVTEN
  *  @brief      Shut down LIN transmitter upon VDD3 under-voltage event
  */
#define LINTXPDEVTEN_VDD3UV_Pos  (2)
#define LINTXPDEVTEN_VDD3UV_Msk  (0x1U << LINTXPDEVTEN_VDD3UV_Pos)

#define LINTXPDEVTEN_VDD3UV_DISABLE  ((0x0U) << LINTXPDEVTEN_VDD3UV_Pos)
#define LINTXPDEVTEN_VDD3UV_ENABLE   ((0x1U) << LINTXPDEVTEN_VDD3UV_Pos)

#define LINTXPDEVTEN_VDD3UV_(x)  (((x) << LINTXPDEVTEN_VDD3UV_Pos) & LINTXPDEVTEN_VDD3UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXPDEVTEN    VDD5OC
  *  @access     HV->LINTXPDEVTEN
  *  @brief      Shut down LIN transmitter upon VDD5 over-current event
  */
#define LINTXPDEVTEN_VDD5OC_Pos  (3)
#define LINTXPDEVTEN_VDD5OC_Msk  (0x1U << LINTXPDEVTEN_VDD5OC_Pos)

#define LINTXPDEVTEN_VDD5OC_DISABLE  ((0x0U) << LINTXPDEVTEN_VDD5OC_Pos)
#define LINTXPDEVTEN_VDD5OC_ENABLE   ((0x1U) << LINTXPDEVTEN_VDD5OC_Pos)

#define LINTXPDEVTEN_VDD5OC_(x)  (((x) << LINTXPDEVTEN_VDD5OC_Pos) & LINTXPDEVTEN_VDD5OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXPDEVTEN    VDD3OC
  *  @access     HV->LINTXPDEVTEN
  *  @brief      Shut down LIN transmitter upon VDD3 over-current event
  */
#define LINTXPDEVTEN_VDD3OC_Pos  (4)
#define LINTXPDEVTEN_VDD3OC_Msk  (0x1U << LINTXPDEVTEN_VDD3OC_Pos)

#define LINTXPDEVTEN_VDD3OC_DISABLE  ((0x0U) << LINTXPDEVTEN_VDD3OC_Pos)
#define LINTXPDEVTEN_VDD3OC_ENABLE   ((0x1U) << LINTXPDEVTEN_VDD3OC_Pos)

#define LINTXPDEVTEN_VDD3OC_(x)  (((x) << LINTXPDEVTEN_VDD3OC_Pos) & LINTXPDEVTEN_VDD3OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXPDEVTEN    LPRCOERR
  *  @access     HV->LINTXPDEVTEN
  *  @brief      Shut down LIN transmitter upon LPRCO error event
  */
#define LINTXPDEVTEN_LPRCOERR_Pos  (5)
#define LINTXPDEVTEN_LPRCOERR_Msk  (0x1U << LINTXPDEVTEN_LPRCOERR_Pos)

#define LINTXPDEVTEN_LPRCOERR_DISABLE  ((0x0U) << LINTXPDEVTEN_LPRCOERR_Pos)
#define LINTXPDEVTEN_LPRCOERR_ENABLE   ((0x1U) << LINTXPDEVTEN_LPRCOERR_Pos)

#define LINTXPDEVTEN_LPRCOERR_(x)  (((x) << LINTXPDEVTEN_LPRCOERR_Pos) & LINTXPDEVTEN_LPRCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXPDEVTEN    RCOERR
  *  @access     HV->LINTXPDEVTEN
  *  @brief      Shut down LIN transmitter upon RCO error event
  */
#define LINTXPDEVTEN_RCOERR_Pos  (6)
#define LINTXPDEVTEN_RCOERR_Msk  (0x1U << LINTXPDEVTEN_RCOERR_Pos)

#define LINTXPDEVTEN_RCOERR_DISABLE  ((0x0U) << LINTXPDEVTEN_RCOERR_Pos)
#define LINTXPDEVTEN_RCOERR_ENABLE   ((0x1U) << LINTXPDEVTEN_RCOERR_Pos)

#define LINTXPDEVTEN_RCOERR_(x)  (((x) << LINTXPDEVTEN_RCOERR_Pos) & LINTXPDEVTEN_RCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXPDEVTEN    LINTXDTIMEOUT
  *  @access     HV->LINTXPDEVTEN
  *  @brief      Shut down LIN transmitter upon LIN TXD timeout event
  */
#define LINTXPDEVTEN_LINTXDTIMEOUT_Pos  (7)
#define LINTXPDEVTEN_LINTXDTIMEOUT_Msk  (0x1U << LINTXPDEVTEN_LINTXDTIMEOUT_Pos)

#define LINTXPDEVTEN_LINTXDTIMEOUT_DISABLE  ((0x0U) << LINTXPDEVTEN_LINTXDTIMEOUT_Pos)
#define LINTXPDEVTEN_LINTXDTIMEOUT_ENABLE   ((0x1U) << LINTXPDEVTEN_LINTXDTIMEOUT_Pos)

#define LINTXPDEVTEN_LINTXDTIMEOUT_(x)  (((x) << LINTXPDEVTEN_LINTXDTIMEOUT_Pos) & LINTXPDEVTEN_LINTXDTIMEOUT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXPDEVTEN    LINOC
  *  @access     HV->LINTXPDEVTEN
  *  @brief      Shut down LIN transmitter upon LIN over-current event
  */
#define LINTXPDEVTEN_LINOC_Pos  (8)
#define LINTXPDEVTEN_LINOC_Msk  (0x1U << LINTXPDEVTEN_LINOC_Pos)

#define LINTXPDEVTEN_LINOC_DISABLE  ((0x0U) << LINTXPDEVTEN_LINOC_Pos)
#define LINTXPDEVTEN_LINOC_ENABLE   ((0x1U) << LINTXPDEVTEN_LINOC_Pos)

#define LINTXPDEVTEN_LINOC_(x)  (((x) << LINTXPDEVTEN_LINOC_Pos) & LINTXPDEVTEN_LINOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXPDEVTEN    LINOT
  *  @access     HV->LINTXPDEVTEN
  *  @brief      Shut down LIN transmitter upon LIN over-temperature event
  */
#define LINTXPDEVTEN_LINOT_Pos  (9)
#define LINTXPDEVTEN_LINOT_Msk  (0x1U << LINTXPDEVTEN_LINOT_Pos)

#define LINTXPDEVTEN_LINOT_DISABLE  ((0x0U) << LINTXPDEVTEN_LINOT_Pos)
#define LINTXPDEVTEN_LINOT_ENABLE   ((0x1U) << LINTXPDEVTEN_LINOT_Pos)

#define LINTXPDEVTEN_LINOT_(x)  (((x) << LINTXPDEVTEN_LINOT_Pos) & LINTXPDEVTEN_LINOT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXSCTL       ISTEP
  *  @access     HV->LINTXSCTL
  *  @brief      Current DAC step size for the slope control.
  *              The slew time is roughly 200/ISTEP us.
  *              It is recommended to set as twice the baud rate in Kbps. (i.e. Set to 40 if the
  *              baud rate is 20Kbps)
  *              Write 0 to this field will be ignored
  */
#define LINTXSCTL_ISTEP_Pos  (0)
#define LINTXSCTL_ISTEP_Msk  (0xFFU << LINTXSCTL_ISTEP_Pos)

#define LINTXSCTL_ISTEP_DISABLE  ((0x00000000U) << LINTXSCTL_ISTEP_Pos)

#define LINTXSCTL_ISTEP_(x)  (((x) << LINTXSCTL_ISTEP_Pos) & LINTXSCTL_ISTEP_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXSCTL       DEN
  *  @access     HV->LINTXSCTL
  *  @brief      Current DAC code LSB dithering enable
  */
#define LINTXSCTL_DEN_Pos  (8)
#define LINTXSCTL_DEN_Msk  (0x1U << LINTXSCTL_DEN_Pos)

#define LINTXSCTL_DEN_DISABLE  ((0x0U) << LINTXSCTL_DEN_Pos)
#define LINTXSCTL_DEN_ENABLE   ((0x1U) << LINTXSCTL_DEN_Pos)

#define LINTXSCTL_DEN_(x)  (((x) << LINTXSCTL_DEN_Pos) & LINTXSCTL_DEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXSCTL       PUEN
  *  @access     HV->LINTXSCTL
  *  @brief      Enable strong hold when recessive state is settled
  */
#define LINTXSCTL_PUEN_Pos  (9)
#define LINTXSCTL_PUEN_Msk  (0x1U << LINTXSCTL_PUEN_Pos)

#define LINTXSCTL_PUEN_DISABLE  ((0x0U) << LINTXSCTL_PUEN_Pos)
#define LINTXSCTL_PUEN_ENABLE   ((0x1U) << LINTXSCTL_PUEN_Pos)

#define LINTXSCTL_PUEN_(x)  (((x) << LINTXSCTL_PUEN_Pos) & LINTXSCTL_PUEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           LINTXSCTL       PDEN
  *  @access     HV->LINTXSCTL
  *  @brief      Enable strong pull-down when dominant state is settled
  */
#define LINTXSCTL_PDEN_Pos  (10)
#define LINTXSCTL_PDEN_Msk  (0x1U << LINTXSCTL_PDEN_Pos)

#define LINTXSCTL_PDEN_DISABLE  ((0x0U) << LINTXSCTL_PDEN_Pos)
#define LINTXSCTL_PDEN_ENABLE   ((0x1U) << LINTXSCTL_PDEN_Pos)

#define LINTXSCTL_PDEN_(x)  (((x) << LINTXSCTL_PDEN_Pos) & LINTXSCTL_PDEN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           PDRVCTL2        HSOCTH
  *  @access     HV->PDRVCTL2
  *  @brief      High side over current detection threshold.
  *              It is via monitoring the Vds of external FET, and the threshold is Vds/Rdson,
  *              where Rdson is the on resistance of the external FET.
  */
#define PDRVCTL2_HSOCTH_Pos  (0)
#define PDRVCTL2_HSOCTH_Msk  (0xFU << PDRVCTL2_HSOCTH_Pos)

#define PDRVCTL2_HSOCTH_0P15V_DIV_RDSON  ((0x0000U) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_0P30V_DIV_RDSON  ((0x0001U) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_0P45V_DIV_RDSON  ((0x0002U) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_0P60V_DIV_RDSON  ((0x0003U) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_0P75V_DIV_RDSON  ((0x0004U) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_0P90V_DIV_RDSON  ((0x0005U) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_1P05V_DIV_RDSON  ((0x0006U) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_1P20V_DIV_RDSON  ((0x0007U) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_1P35V_DIV_RDSON  ((0x0008U) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_1P50V_DIV_RDSON  ((0x0009U) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_1P65V_DIV_RDSON  ((0x000AU) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_1P80V_DIV_RDSON  ((0x000BU) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_1P95V_DIV_RDSON  ((0x000CU) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_2P10V_DIV_RDSON  ((0x000DU) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_2P25V_DIV_RDSON  ((0x000EU) << PDRVCTL2_HSOCTH_Pos)
#define PDRVCTL2_HSOCTH_2P40V_DIV_RDSON  ((0x000FU) << PDRVCTL2_HSOCTH_Pos)

#define PDRVCTL2_HSOCTH_(x)  (((x) << PDRVCTL2_HSOCTH_Pos) & PDRVCTL2_HSOCTH_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VBATUV
  *  @access     HV->TZEVTFRC0
  *  @brief      VBAT under-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VBATUV_Pos  (0)
#define TZEVTFRC0_VBATUV_Msk  (0x1U << TZEVTFRC0_VBATUV_Pos)

#define TZEVTFRC0_VBATUV_DISABLE  ((0x0U) << TZEVTFRC0_VBATUV_Pos)
#define TZEVTFRC0_VBATUV_ENABLE   ((0x1U) << TZEVTFRC0_VBATUV_Pos)

#define TZEVTFRC0_VBATUV_(x)  (((x) << TZEVTFRC0_VBATUV_Pos) & TZEVTFRC0_VBATUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VBATOV
  *  @access     HV->TZEVTFRC0
  *  @brief      VBAT over-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VBATOV_Pos  (1)
#define TZEVTFRC0_VBATOV_Msk  (0x1U << TZEVTFRC0_VBATOV_Pos)

#define TZEVTFRC0_VBATOV_DISABLE  ((0x0U) << TZEVTFRC0_VBATOV_Pos)
#define TZEVTFRC0_VBATOV_ENABLE   ((0x1U) << TZEVTFRC0_VBATOV_Pos)

#define TZEVTFRC0_VBATOV_(x)  (((x) << TZEVTFRC0_VBATOV_Pos) & TZEVTFRC0_VBATOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VDD5UV
  *  @access     HV->TZEVTFRC0
  *  @brief      VDD5 under-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VDD5UV_Pos  (2)
#define TZEVTFRC0_VDD5UV_Msk  (0x1U << TZEVTFRC0_VDD5UV_Pos)

#define TZEVTFRC0_VDD5UV_DISABLE  ((0x0U) << TZEVTFRC0_VDD5UV_Pos)
#define TZEVTFRC0_VDD5UV_ENABLE   ((0x1U) << TZEVTFRC0_VDD5UV_Pos)

#define TZEVTFRC0_VDD5UV_(x)  (((x) << TZEVTFRC0_VDD5UV_Pos) & TZEVTFRC0_VDD5UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VDD5OV
  *  @access     HV->TZEVTFRC0
  *  @brief      VDD5 over-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VDD5OV_Pos  (3)
#define TZEVTFRC0_VDD5OV_Msk  (0x1U << TZEVTFRC0_VDD5OV_Pos)

#define TZEVTFRC0_VDD5OV_DISABLE  ((0x0U) << TZEVTFRC0_VDD5OV_Pos)
#define TZEVTFRC0_VDD5OV_ENABLE   ((0x1U) << TZEVTFRC0_VDD5OV_Pos)

#define TZEVTFRC0_VDD5OV_(x)  (((x) << TZEVTFRC0_VDD5OV_Pos) & TZEVTFRC0_VDD5OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VDD5EXTUV
  *  @access     HV->TZEVTFRC0
  *  @brief      VDD5EXT under-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VDD5EXTUV_Pos  (4)
#define TZEVTFRC0_VDD5EXTUV_Msk  (0x1U << TZEVTFRC0_VDD5EXTUV_Pos)

#define TZEVTFRC0_VDD5EXTUV_DISABLE  ((0x0U) << TZEVTFRC0_VDD5EXTUV_Pos)
#define TZEVTFRC0_VDD5EXTUV_ENABLE   ((0x1U) << TZEVTFRC0_VDD5EXTUV_Pos)

#define TZEVTFRC0_VDD5EXTUV_(x)  (((x) << TZEVTFRC0_VDD5EXTUV_Pos) & TZEVTFRC0_VDD5EXTUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VDD5EXTOV
  *  @access     HV->TZEVTFRC0
  *  @brief      VDD5EXT over-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VDD5EXTOV_Pos  (5)
#define TZEVTFRC0_VDD5EXTOV_Msk  (0x1U << TZEVTFRC0_VDD5EXTOV_Pos)

#define TZEVTFRC0_VDD5EXTOV_DISABLE  ((0x0U) << TZEVTFRC0_VDD5EXTOV_Pos)
#define TZEVTFRC0_VDD5EXTOV_ENABLE   ((0x1U) << TZEVTFRC0_VDD5EXTOV_Pos)

#define TZEVTFRC0_VDD5EXTOV_(x)  (((x) << TZEVTFRC0_VDD5EXTOV_Pos) & TZEVTFRC0_VDD5EXTOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VDD3UV
  *  @access     HV->TZEVTFRC0
  *  @brief      VDD3 under-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VDD3UV_Pos  (6)
#define TZEVTFRC0_VDD3UV_Msk  (0x1U << TZEVTFRC0_VDD3UV_Pos)

#define TZEVTFRC0_VDD3UV_DISABLE  ((0x0U) << TZEVTFRC0_VDD3UV_Pos)
#define TZEVTFRC0_VDD3UV_ENABLE   ((0x1U) << TZEVTFRC0_VDD3UV_Pos)

#define TZEVTFRC0_VDD3UV_(x)  (((x) << TZEVTFRC0_VDD3UV_Pos) & TZEVTFRC0_VDD3UV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VDD3OV
  *  @access     HV->TZEVTFRC0
  *  @brief      VDD3 over-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VDD3OV_Pos  (7)
#define TZEVTFRC0_VDD3OV_Msk  (0x1U << TZEVTFRC0_VDD3OV_Pos)

#define TZEVTFRC0_VDD3OV_DISABLE  ((0x0U) << TZEVTFRC0_VDD3OV_Pos)
#define TZEVTFRC0_VDD3OV_ENABLE   ((0x1U) << TZEVTFRC0_VDD3OV_Pos)

#define TZEVTFRC0_VDD3OV_(x)  (((x) << TZEVTFRC0_VDD3OV_Pos) & TZEVTFRC0_VDD3OV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       PMUOTWARN
  *  @access     HV->TZEVTFRC0
  *  @brief      PMU over-temperature warning event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_PMUOTWARN_Pos  (8)
#define TZEVTFRC0_PMUOTWARN_Msk  (0x1U << TZEVTFRC0_PMUOTWARN_Pos)

#define TZEVTFRC0_PMUOTWARN_DISABLE  ((0x0U) << TZEVTFRC0_PMUOTWARN_Pos)
#define TZEVTFRC0_PMUOTWARN_ENABLE   ((0x1U) << TZEVTFRC0_PMUOTWARN_Pos)

#define TZEVTFRC0_PMUOTWARN_(x)  (((x) << TZEVTFRC0_PMUOTWARN_Pos) & TZEVTFRC0_PMUOTWARN_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VDD5EXTOC
  *  @access     HV->TZEVTFRC0
  *  @brief      VDD5EXT over-current event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VDD5EXTOC_Pos  (9)
#define TZEVTFRC0_VDD5EXTOC_Msk  (0x1U << TZEVTFRC0_VDD5EXTOC_Pos)

#define TZEVTFRC0_VDD5EXTOC_DISABLE  ((0x0U) << TZEVTFRC0_VDD5EXTOC_Pos)
#define TZEVTFRC0_VDD5EXTOC_ENABLE   ((0x1U) << TZEVTFRC0_VDD5EXTOC_Pos)

#define TZEVTFRC0_VDD5EXTOC_(x)  (((x) << TZEVTFRC0_VDD5EXTOC_Pos) & TZEVTFRC0_VDD5EXTOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VDD5OC
  *  @access     HV->TZEVTFRC0
  *  @brief      VDD5 over-current event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VDD5OC_Pos  (10)
#define TZEVTFRC0_VDD5OC_Msk  (0x1U << TZEVTFRC0_VDD5OC_Pos)

#define TZEVTFRC0_VDD5OC_DISABLE  ((0x0U) << TZEVTFRC0_VDD5OC_Pos)
#define TZEVTFRC0_VDD5OC_ENABLE   ((0x1U) << TZEVTFRC0_VDD5OC_Pos)

#define TZEVTFRC0_VDD5OC_(x)  (((x) << TZEVTFRC0_VDD5OC_Pos) & TZEVTFRC0_VDD5OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       VDD3OC
  *  @access     HV->TZEVTFRC0
  *  @brief      VDD3 over-current event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_VDD3OC_Pos  (11)
#define TZEVTFRC0_VDD3OC_Msk  (0x1U << TZEVTFRC0_VDD3OC_Pos)

#define TZEVTFRC0_VDD3OC_DISABLE  ((0x0U) << TZEVTFRC0_VDD3OC_Pos)
#define TZEVTFRC0_VDD3OC_ENABLE   ((0x1U) << TZEVTFRC0_VDD3OC_Pos)

#define TZEVTFRC0_VDD3OC_(x)  (((x) << TZEVTFRC0_VDD3OC_Pos) & TZEVTFRC0_VDD3OC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       LINTXDTIMEOUT
  *  @access     HV->TZEVTFRC0
  *  @brief      LIN TXD timeout event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_LINTXDTIMEOUT_Pos  (13)
#define TZEVTFRC0_LINTXDTIMEOUT_Msk  (0x1U << TZEVTFRC0_LINTXDTIMEOUT_Pos)

#define TZEVTFRC0_LINTXDTIMEOUT_DISABLE  ((0x0U) << TZEVTFRC0_LINTXDTIMEOUT_Pos)
#define TZEVTFRC0_LINTXDTIMEOUT_ENABLE   ((0x1U) << TZEVTFRC0_LINTXDTIMEOUT_Pos)

#define TZEVTFRC0_LINTXDTIMEOUT_(x)  (((x) << TZEVTFRC0_LINTXDTIMEOUT_Pos) & TZEVTFRC0_LINTXDTIMEOUT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       LINOC
  *  @access     HV->TZEVTFRC0
  *  @brief      LIN transceiver over-current event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_LINOC_Pos  (14)
#define TZEVTFRC0_LINOC_Msk  (0x1U << TZEVTFRC0_LINOC_Pos)

#define TZEVTFRC0_LINOC_DISABLE  ((0x0U) << TZEVTFRC0_LINOC_Pos)
#define TZEVTFRC0_LINOC_ENABLE   ((0x1U) << TZEVTFRC0_LINOC_Pos)

#define TZEVTFRC0_LINOC_(x)  (((x) << TZEVTFRC0_LINOC_Pos) & TZEVTFRC0_LINOC_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC0       LINOT
  *  @access     HV->TZEVTFRC0
  *  @brief      LIN transceiver over-temperature event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC0_LINOT_Pos  (15)
#define TZEVTFRC0_LINOT_Msk  (0x1U << TZEVTFRC0_LINOT_Pos)

#define TZEVTFRC0_LINOT_DISABLE  ((0x0U) << TZEVTFRC0_LINOT_Pos)
#define TZEVTFRC0_LINOT_ENABLE   ((0x1U) << TZEVTFRC0_LINOT_Pos)

#define TZEVTFRC0_LINOT_(x)  (((x) << TZEVTFRC0_LINOT_Pos) & TZEVTFRC0_LINOT_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       PDRVOCLU
  *  @access     HV->TZEVTFRC1
  *  @brief      Pre-driver U-phase low-side over-current event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_PDRVOCLU_Pos  (0)
#define TZEVTFRC1_PDRVOCLU_Msk  (0x1U << TZEVTFRC1_PDRVOCLU_Pos)

#define TZEVTFRC1_PDRVOCLU_DISABLE  ((0x0U) << TZEVTFRC1_PDRVOCLU_Pos)
#define TZEVTFRC1_PDRVOCLU_ENABLE   ((0x1U) << TZEVTFRC1_PDRVOCLU_Pos)

#define TZEVTFRC1_PDRVOCLU_(x)  (((x) << TZEVTFRC1_PDRVOCLU_Pos) & TZEVTFRC1_PDRVOCLU_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       PDRVOCLV
  *  @access     HV->TZEVTFRC1
  *  @brief      Pre-driver V-phase low-side over-current event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_PDRVOCLV_Pos  (1)
#define TZEVTFRC1_PDRVOCLV_Msk  (0x1U << TZEVTFRC1_PDRVOCLV_Pos)

#define TZEVTFRC1_PDRVOCLV_DISABLE  ((0x0U) << TZEVTFRC1_PDRVOCLV_Pos)
#define TZEVTFRC1_PDRVOCLV_ENABLE   ((0x1U) << TZEVTFRC1_PDRVOCLV_Pos)

#define TZEVTFRC1_PDRVOCLV_(x)  (((x) << TZEVTFRC1_PDRVOCLV_Pos) & TZEVTFRC1_PDRVOCLV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       PDRVOCLW
  *  @access     HV->TZEVTFRC1
  *  @brief      Pre-driver W-phase low-side over-current event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_PDRVOCLW_Pos  (2)
#define TZEVTFRC1_PDRVOCLW_Msk  (0x1U << TZEVTFRC1_PDRVOCLW_Pos)

#define TZEVTFRC1_PDRVOCLW_DISABLE  ((0x0U) << TZEVTFRC1_PDRVOCLW_Pos)
#define TZEVTFRC1_PDRVOCLW_ENABLE   ((0x1U) << TZEVTFRC1_PDRVOCLW_Pos)

#define TZEVTFRC1_PDRVOCLW_(x)  (((x) << TZEVTFRC1_PDRVOCLW_Pos) & TZEVTFRC1_PDRVOCLW_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       PDRVOCHU
  *  @access     HV->TZEVTFRC1
  *  @brief      Pre-driver U-phase high-side over-current event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_PDRVOCHU_Pos  (3)
#define TZEVTFRC1_PDRVOCHU_Msk  (0x1U << TZEVTFRC1_PDRVOCHU_Pos)

#define TZEVTFRC1_PDRVOCHU_DISABLE  ((0x0U) << TZEVTFRC1_PDRVOCHU_Pos)
#define TZEVTFRC1_PDRVOCHU_ENABLE   ((0x1U) << TZEVTFRC1_PDRVOCHU_Pos)

#define TZEVTFRC1_PDRVOCHU_(x)  (((x) << TZEVTFRC1_PDRVOCHU_Pos) & TZEVTFRC1_PDRVOCHU_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       PDRVOCHV
  *  @access     HV->TZEVTFRC1
  *  @brief      Pre-driver V-phase high-side over-current event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_PDRVOCHV_Pos  (4)
#define TZEVTFRC1_PDRVOCHV_Msk  (0x1U << TZEVTFRC1_PDRVOCHV_Pos)

#define TZEVTFRC1_PDRVOCHV_DISABLE  ((0x0U) << TZEVTFRC1_PDRVOCHV_Pos)
#define TZEVTFRC1_PDRVOCHV_ENABLE   ((0x1U) << TZEVTFRC1_PDRVOCHV_Pos)

#define TZEVTFRC1_PDRVOCHV_(x)  (((x) << TZEVTFRC1_PDRVOCHV_Pos) & TZEVTFRC1_PDRVOCHV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       PDRVOCHW
  *  @access     HV->TZEVTFRC1
  *  @brief      Pre-driver W-phase high-side over-current event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_PDRVOCHW_Pos  (5)
#define TZEVTFRC1_PDRVOCHW_Msk  (0x1U << TZEVTFRC1_PDRVOCHW_Pos)

#define TZEVTFRC1_PDRVOCHW_DISABLE  ((0x0U) << TZEVTFRC1_PDRVOCHW_Pos)
#define TZEVTFRC1_PDRVOCHW_ENABLE   ((0x1U) << TZEVTFRC1_PDRVOCHW_Pos)

#define TZEVTFRC1_PDRVOCHW_(x)  (((x) << TZEVTFRC1_PDRVOCHW_Pos) & TZEVTFRC1_PDRVOCHW_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       VCPUV
  *  @access     HV->TZEVTFRC1
  *  @brief      Pre-driver VCP under-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_VCPUV_Pos  (6)
#define TZEVTFRC1_VCPUV_Msk  (0x1U << TZEVTFRC1_VCPUV_Pos)

#define TZEVTFRC1_VCPUV_DISABLE  ((0x0U) << TZEVTFRC1_VCPUV_Pos)
#define TZEVTFRC1_VCPUV_ENABLE   ((0x1U) << TZEVTFRC1_VCPUV_Pos)

#define TZEVTFRC1_VCPUV_(x)  (((x) << TZEVTFRC1_VCPUV_Pos) & TZEVTFRC1_VCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       VCPOV
  *  @access     HV->TZEVTFRC1
  *  @brief      Pre-driver VCP over-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_VCPOV_Pos  (7)
#define TZEVTFRC1_VCPOV_Msk  (0x1U << TZEVTFRC1_VCPOV_Pos)

#define TZEVTFRC1_VCPOV_DISABLE  ((0x0U) << TZEVTFRC1_VCPOV_Pos)
#define TZEVTFRC1_VCPOV_ENABLE   ((0x1U) << TZEVTFRC1_VCPOV_Pos)

#define TZEVTFRC1_VCPOV_(x)  (((x) << TZEVTFRC1_VCPOV_Pos) & TZEVTFRC1_VCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       LPRCOERR
  *  @access     HV->TZEVTFRC1
  *  @brief      100kHz LPRCO error event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_LPRCOERR_Pos  (8)
#define TZEVTFRC1_LPRCOERR_Msk  (0x1U << TZEVTFRC1_LPRCOERR_Pos)

#define TZEVTFRC1_LPRCOERR_DISABLE  ((0x0U) << TZEVTFRC1_LPRCOERR_Pos)
#define TZEVTFRC1_LPRCOERR_ENABLE   ((0x1U) << TZEVTFRC1_LPRCOERR_Pos)

#define TZEVTFRC1_LPRCOERR_(x)  (((x) << TZEVTFRC1_LPRCOERR_Pos) & TZEVTFRC1_LPRCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       RCOERR
  *  @access     HV->TZEVTFRC1
  *  @brief      40MHz RCO error event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_RCOERR_Pos  (9)
#define TZEVTFRC1_RCOERR_Msk  (0x1U << TZEVTFRC1_RCOERR_Pos)

#define TZEVTFRC1_RCOERR_DISABLE  ((0x0U) << TZEVTFRC1_RCOERR_Pos)
#define TZEVTFRC1_RCOERR_ENABLE   ((0x1U) << TZEVTFRC1_RCOERR_Pos)

#define TZEVTFRC1_RCOERR_(x)  (((x) << TZEVTFRC1_RCOERR_Pos) & TZEVTFRC1_RCOERR_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       VBATCPUV
  *  @access     HV->TZEVTFRC1
  *  @brief      VBATCP under-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_VBATCPUV_Pos  (10)
#define TZEVTFRC1_VBATCPUV_Msk  (0x1U << TZEVTFRC1_VBATCPUV_Pos)

#define TZEVTFRC1_VBATCPUV_DISABLE  ((0x0U) << TZEVTFRC1_VBATCPUV_Pos)
#define TZEVTFRC1_VBATCPUV_ENABLE   ((0x1U) << TZEVTFRC1_VBATCPUV_Pos)

#define TZEVTFRC1_VBATCPUV_(x)  (((x) << TZEVTFRC1_VBATCPUV_Pos) & TZEVTFRC1_VBATCPUV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           TZEVTFRC1       VBATCPOV
  *  @access     HV->TZEVTFRC1
  *  @brief      VBATCP over-voltage event force
  *              This bit is writable only when CTLKEY=0x8888, and cleared to 0 if CTLKEY is
  *              neither 0x8888 nor 0x7777.
  */
#define TZEVTFRC1_VBATCPOV_Pos  (11)
#define TZEVTFRC1_VBATCPOV_Msk  (0x1U << TZEVTFRC1_VBATCPOV_Pos)

#define TZEVTFRC1_VBATCPOV_DISABLE  ((0x0U) << TZEVTFRC1_VBATCPOV_Pos)
#define TZEVTFRC1_VBATCPOV_ENABLE   ((0x1U) << TZEVTFRC1_VBATCPOV_Pos)

#define TZEVTFRC1_VBATCPOV_(x)  (((x) << TZEVTFRC1_VBATCPOV_Pos) & TZEVTFRC1_VBATCPOV_Msk)


/**
  *  @hierarchy  Module          Register        Bitfield
  *              HV           CTLKEY          KEY
  *  @access     HV->CTLKEY
  *  @brief      Control Key
  *              Write as 0x6666 to enable sotware reset command
  *              Write as 0x7777 to enable write on registers highlighted in red
  *              Write as 0x8888 to enable write on registers highlighted in blue
  *              Write as 0x9999 to enable sleep/stop command
  */
#define CTLKEY_KEY_Pos  (0)
#define CTLKEY_KEY_Msk  (0xFFFFU << CTLKEY_KEY_Pos)

#define CTLKEY_KEY_(x)  (((x) << CTLKEY_KEY_Pos) & CTLKEY_KEY_Msk)



#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* HV_BITFIELD_H */


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
