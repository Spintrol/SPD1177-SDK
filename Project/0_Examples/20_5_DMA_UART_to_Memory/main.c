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


#define              RESULT_ADDRESS              0x1ffffb00


uint32_t             *pu32Result                  = (uint32_t *)RESULT_ADDRESS;
uint32_t             au32Src[4];                                                    /* Source data */
uint32_t             i;                                                             /* Print Num */


void DMA_UART_Init(UART_REGS *UARTx)
{
    /* Unlock Key Protect */
    UART_WALLOW(UARTx);

    /* Stop UART */
    UART_Disable(UARTx);
    UART_DisableSIR(UARTx);
    LIN_Disable(UARTx);

    /* UART_Init */
    UART_Init(UARTx, 38400);
    UART_ClearTxFIFO(UARTx);
    UART_ClearRxFIFO(UARTx);

    /* Set UART BusWidth */
    UART_Set32BitBusWidth(UARTx);

    /* Enable UART loop */
    UART_EnableLoopback(UARTx);

    /* Set the Rx FIFO Threshold, the DMA will start next transfer when the Rx current deep > Rx FIFO Threshold*/
    UART_SetRxFIFOThreshold(UARTx, 15);

    /* Enable the Rx DMA */
    UART_SetTxDMA(UARTx, DISABLE);
    UART_SetRxDMA(UARTx, ENABLE);
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
 * @brief       This example use DMA channel 0 to transfer the data from UART to RAM.
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

    /* DMA relevant UART parameter set */
    DMA_UART_Init(UART1);

    /* Enable UART */
    UART_Enable(UART1);

    /* DMA enable interrupt */
    DMA_Int_Init(DMA_CH0);

    /* Transfer type */
    DMA_SetTransferType(DMACH0, DMA_PERIPHERAL_TO_MEMORY);

    /* Set source transfer parameters */
    DMA_SetSourceTransferWidth(DMACH0, DMA_TRANSFER_IN_WORD);
    DMA_SetSourceBurstLen(DMACH0, DMA_BURST_LENGTH_4_WORDS);

    /* Set destination transfer parameters */
    DMA_SetDestinationTransferWidth(DMACH0, DMA_TRANSFER_IN_WORD);
    DMA_SetDestinationBurstLen(DMACH0, DMA_BURST_LENGTH_4_WORDS);

    /* Block transfer num */
    DMA_SetBlockTransferSize(DMACH0, 4);

    /* Init source data */
    au32Src[0] = 0x82131415;
    au32Src[1] = 0x86171819;
    au32Src[2] = 0x80212223;
    au32Src[3] = 0x84252627;

    for (i = 0; i < 4; i++)
    {
        printf("The Send word is %x\n", au32Src[i]);
    }

    /* Source address */
    DMA_SetSourceAddr(DMACH0, (uint32_t)(&UART1->UARTDAT));
    /* Source address increment */
    DMA_SetSourceAddrMode(DMACH0, DMA_ADDRESS_NO_CHANGE);
    DMA_SetSourceHandShake(DMACH0, DMA_HANDSHAKE_BY_HARDWARE, DMA_HANDSHAKE_POL_ACTIVE_HIGH);
    /* Source peripheral */
    DMA_SetSourcePeripheral(DMACH0, DMA_SPER_UART1_RX);

    /* Destination address */
    DMA_SetDestinationAddr(DMACH0, RESULT_ADDRESS);
    /* Destination address increment */
    DMA_SetDestinationAddrMode(DMACH0, DMA_ADDRESS_MODE_INCREASE);
    DMA_SetDestinationHandShake(DMACH0, DMA_HANDSHAKE_BY_SOFTWARE, DMA_HANDSHAKE_POL_ACTIVE_HIGH);

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

        for (i = 0; i < 4; i++)
        {
            UART_WriteWord(UART1, au32Src[i]);
        }
        
        Delay_Ms(100);
        
        /* Reset the destination addr, because dectination addr is increased after previous loop */
        DMA_Disable();
        DMA_SetDestinationAddr(DMACH0, RESULT_ADDRESS);
        DMA_Enable();
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
        for (i = 0; i < 4; i++)
        {
            printf("%d:Rx 0x%08X\n", i, *((uint32_t *)pu32Result + i));
        }
        /* Clear DMA_CH0 TRANSFER COMPLETE flag */
        DMA_ClearTransferCompleteInt(DMA_CH0);
    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
