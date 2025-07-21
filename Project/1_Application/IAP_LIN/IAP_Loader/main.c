/******************************************************************************
 * @file     main.c
 * @brief    Main body
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
#include "iap.h"
#include "stdio.h"

#define              LIN_BAUD_RATE         50000             /*For slave           */
#define              REFID                 0x32              /* REFID State        */
#define              IDMASK                0x3f              /* IDMASK State       */




/*********************************************************************************************************************
 *
 * @brief      In this case, use LIN to update IAP_App in MCU
 *
 *                                VBAT                                  VBAT--Switch
 *                                 |                        __ __ __ __ __ __ __ |_ __ __ __ __ __
 *                                 |                       |                     |                |
 *                                 |                       |                     |                |
 *             _____         ______|_____                  |            _________|_______         |
 *            |     |       |            |-------------LIN-|--------x--|     |       |   |        |
 *            | PC  |       |            |                 |        |  | LIN | MCU   |   |        |
 *            |     |<----->| USB-TO-LIN |                 |220pF  --- | PHY |       |   |        |
 *            |     |       |            |                 |       --- |     |       |   |        |
 *            |     |       |            |                 |        |  |_____|_______|   |        |
 *            |_____|       |____________|-------------GND-|--------x--|_________________|        |
 *                                                         |                                      |
 *                                                         |__ __ __ __ __ __ __ __ __ __ __ __ __|
 *
 * @KeyPoint   :   1, In master side, the tool equipped with a 1k built-in pull-up resistor, so do not need to add any
 *                 pull-up resistor;
 *                 2, In slave side, the MCU equipped with a 30k built-in pull-up resistor, so do not need to add any
 *                 pull-up resistor in circuit;
 *                 3, In slave side, the circuit already add 220pF capacitance between LIN and GND;
 *                 4, In slave side, makesure no extra resistors and capacitances are connected to LIN;
 *                 5, Add switch in the side of slave, so master can keep power on state forever.
 *
 * @TestMethod :   1, Use ISP to download IAP_Loader;
 *                 2, Use IAP to download IAP_App.
 * 
 * @TestResult :   IAP_App run success
 *
 **********************************************************************************************************************/
int32_t main(void)
{
    /* PRE-DRIVER mode ID */
    uint16_t u16PREDRIID;

    /* Function State */    
    ErrorStatus eErrorState;

    /* TX Data */    
    uint8_t au8Txd[8];    
    
    /* Application Entry address */
    uint32_t u32Entry = 0U;

    /* Timeout */
    uint32_t u32TimeOut = 0U;
    
    uint32_t i;

    /* Clock Init */
    CLOCK_InitWithRCO(100000000);

    /* Delay Init */
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
        printf("Init HV mode FAIL\n");
        return 0;
    }
    else
    {
        printf("Init HV mode SUCCESS[ID:%d]\n", u16PREDRIID);
    }

    /* HV parameter write enable */
    eErrorState = EPWR_WriteRegister(HV_REG_CTLKEY, KEY_USER_REG);
    if (eErrorState == ERROR)
    {
        printf("Write CTLKEY register FAIL\n");
        return 0;
    }

    /*
    Init LIN parameter
    */
    eErrorState = EPWR_WriteRegisterField(HV_REG_LINCTL, LINCTL_RLOAD_Msk | LINCTL_TXEN_Msk | LINCTL_EN_Msk, LINCTL_RLOAD_938_OHM | LINCTL_TXEN_ENABLE | LINCTL_EN_ENABLE);
    if (eErrorState == ERROR)
    {
        printf("EPWR_WriteRegisterField FAIL\n");
        return 0;
    }
    
    eErrorState = EPWR_WriteRegisterField(HV_REG_LINTXSCTL, LINTXSCTL_ISTEP_Msk , ((LIN_BAUD_RATE << 1) / 1000) << LINTXSCTL_ISTEP_Pos);
    if (eErrorState == ERROR)
    {
        printf("EPWR_WriteRegisterField FAIL\n");
        return 0;
    }
    
    /* LIN configuration */
    PIN_SetChannel(PIN_GPIO25, PIN_GPIO25_UART1_TXD);
    PIN_SetChannel(PIN_GPIO26, PIN_GPIO26_UART1_RXD);
    LIN_Init(UART1, LIN_SLAVE, LIN_BAUD_RATE);
    LIN_SetRxFIFOMode(UART1, LIN_SAVE_CORRECT_DATA);
    
    /* Set the id filter */
    LIN_SetIDFilter(UART1, REFID, IDMASK);

    /* Enable UART1_IRQn trigger INT in MCU side */
    NVIC_EnableIRQ(UART1_IRQn);
    
    /* Wait for handshake byte with timeout 50ms, or the bootloader will jump to the application running */
    u32TimeOut = 50000;
    while (u32TimeOut--)
    {
        /* Check id match event */
        if (UART_GetIntRawFlag(UART1, UART_INT_LIN_ID_MATCH) != 0)
        {
            /* Clear id match flag */
            UART_ClearInt(UART1, UART_INT_LIN_ID_MATCH);  
                
            /* Set the check mode */
            LIN_SetCheckSumMode(UART1, LIN_ENHANCED_CHECKSUM);

            /* Set the respond mode */
            LIN_SetResponse(UART1, LIN_RESPONSE_TX);

            /* Set the respond lenth */
            LIN_SetResponseLen(UART1, LIN_RESPONSE_8_BYTE);
            
            /* Set the respond data */
            for (i = 0; i < LIN_RESPONSE_8_BYTE; i++)
            {
                au8Txd[i] = 0x79;
            }
            
            for (i = 0; i < LIN_RESPONSE_8_BYTE; i++)
            {
                UART_WriteByte(UART1, au8Txd[i]);
            }
            
            /* Send frame */
            SET_BITS(UART1->LINCTL, LINCTL_TXCHKSUM_TRANSMIT);
            
            /* Enter bootloader process */
            IAP_LoadFromLIN();
        }

        /* Delay 1us */
        Delay_Us(1);
    }

    /* Revert LIN configuration to original */
    WRITE_REG(UART1->UARTCTL, 0);
    WRITE_REG(UART1->LINCTL, 0);
    WRITE_REG(UART1->LINIDFILT, 0); 

    /* Entry address */
    u32Entry = *(__IO uint32_t *)(0x1000F000U + 4);

    /* Jump to the application */
    ((PTRJUMP)(u32Entry))();

    while (1)
    {
    }
}

/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/

