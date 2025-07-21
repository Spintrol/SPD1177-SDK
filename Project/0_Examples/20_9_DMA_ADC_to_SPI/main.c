/******************************************************************************
 * @file     main.c
 * @brief    Main program body
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
#include <stdio.h>

#if (defined(SPD1177) || defined(SPD1179B))
    #include "spd1177.h"
#elif defined(SPD1179)
    #include "spd1179.h"
#else
    #include "spc1169.h"
#endif


#define             ValueToVoltage(x)           ((x * 3657) / 4096) /1000


int32_t            ai32Result[1];                                          /* Result data */


void DMA_SPI_Init(SPI_REGS *SPIx)
{
    /* Unlock Key Protect */
    SPI_WALLOW(SPIx);

    /* Stop SPI */
    SPI_Disable(SPIx);

    /* SPI_Init */
    SPI_Init(SPIx, SPI_MASTER, SPI_MODE_PHS_POL_00, 32, 1000000);

    /* Enable SPI loop */
    SPI_EnableLoopback(SPIx);

    /* Enable the Tx DMA */
    SPI_SetTxDMA(SPIx, ENABLE);
    SPI_SetRxDMA(SPIx, DISABLE);
}


void DMA_Int_Init(DMA_ChannelEnum DMA_CHx)
{
    /* Enable the DMA interrupt */
    DMA_EnableTransferCompleteInt(DMA_CHx);
    DMA_EnableTransferErrorInt(DMA_CHx);

    /* Clear all interrupt flag */
    DMA_ClearTransferCompleteInt(DMA_CHx);
    DMA_ClearTransferErrorInt(DMA_CHx);

    /* Disable the DMA transfer */
    DMA_DisableChannelTransfer(DMA_CHx);
}


/*************************************************************************************************************************
 *
 * @brief       This example use DMA channel 0 to transfer the data from ADC to SPI.
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

    /* Enable global INT for DMA */
    NVIC_EnableIRQ(DMAC_IRQn);

    /* Stop DMA */
    DMA_Disable();

    /* Wait until DMA is disable */
    while (DMA_IsEnable() == 1)
    {}

    /* DMA relevant SPI parameter set */
    DMA_SPI_Init(SPI0);

    /* Run SPI */
    SPI_Enable(SPI0);

    /*ADC Init*/
    ADC_EasyInit1(ADC, ADC_CH0, PIN_GPIO0, ADC_SOC_TRIGGER_FROM_SOFTWARE);

    ADC_SetChannelResultAverageCount(ADC, ADC_CH0, ADC_AVERAGE_COUNT_16);

    /* ADC ADC_SOC_0 DMA enable */
    ADC->ADCCTL = ADC->ADCCTL | ADCCTL_DMAEN0_ENABLE;

    /* DMA enable interrupt */
    DMA_Int_Init(DMA_CH0);

    /* Transfer type */
    DMA_SetTransferType(DMACH0, DMA_PERIPHERAL_TO_PERIPHERAL);

    /* Set source transfer parameters */
    DMA_SetSourceTransferWidth(DMACH0, DMA_TRANSFER_IN_WORD);
    DMA_SetSourceBurstLen(DMACH0, DMA_BURST_LENGTH_1_WORD);

    /* Set destination transfer parameters */
    DMA_SetDestinationTransferWidth(DMACH0, DMA_TRANSFER_IN_WORD);
    DMA_SetDestinationBurstLen(DMACH0, DMA_BURST_LENGTH_1_WORD);

    /* Block transfer num */
    DMA_SetBlockTransferSize(DMACH0, 1);

    /* Source address */
    DMA_SetSourceAddr(DMACH0, (uint32_t)(&ADC->ADCRESULT[0]));
    /* Source address increment */
    DMA_SetSourceAddrMode(DMACH0, DMA_ADDRESS_NO_CHANGE);
    DMA_SetSourceHandShake(DMACH0, DMA_HANDSHAKE_BY_HARDWARE, DMA_HANDSHAKE_POL_ACTIVE_HIGH);
    /* Source peripheral */
    DMA_SetSourcePeripheral(DMACH0, DMA_SPER_ADCRESULT0);

    /* Destination address */
    DMA_SetDestinationAddr(DMACH0, (uint32_t)(&SPI0->SPIDATA));
    /* Destination address increment */
    DMA_SetDestinationAddrMode(DMACH0, DMA_ADDRESS_NO_CHANGE);
    DMA_SetDestinationHandShake(DMACH0, DMA_HANDSHAKE_BY_HARDWARE, DMA_HANDSHAKE_POL_ACTIVE_HIGH);
    /* Destination peripheral */
    DMA_SetDestinationPeripheral(DMACH0, DMA_DPER_SPI0_TX);

    /* DMA disable suspend */
    DMA_DisableSuspend(DMACH0);

    /* Enable channel 0 interrupt */
    DMA_EnableChannelInt(DMACH0);
    
    /* Enable DMA */
    DMA_Enable();
    
    while (1)
    {
        /* Enable Channel 0 transfer*/
        DMA_EnableChannelTransfer(DMA_CH0);

        /* Use software to trigger ADC SOC0 start to work */
        ADC_ForceChannelSOC(ADC, ADC_CH0);

        while ((SPI_GetRxFIFOLevel(SPI0) != 1))
        {
        }

        ai32Result[0] = SPI_ReceiveData(SPI0);
        printf("Rx %d\n", ai32Result[0]);
        printf("The voltage is %2.1f\n", (double)ValueToVoltage(ai32Result[0]));
        
        Delay_Ms(100);
    }
}


void DMAC_IRQHandler(void)
{
    /* Get TRANSFER ERROR flag */
    if (DMA_GetGlobalIntFlag(DMA_INT_TRANSFER_ERROR) != 0)
    {
        printf("DMA Channel Error!\n");
    }

    /* Get TRANSFER COMPLETE flag */
    if (DMA_GetGlobalIntFlag(DMA_INT_TRANSFER_COMPLETE) != 0)
    {
        printf("Channel transfer complete!\n");
    }

    /* Get DMA_CH0 TRANSFER COMPLETE flag */
    if (DMA_GetTransferCompleteIntFlag(DMA_CH0) != 0)
    {
        printf("Channel 0 transfer complete!\n");
        /* Clear DMA_CH0 TRANSFER COMPLETE flag */
        DMA_ClearTransferCompleteInt(DMA_CH0);
    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
