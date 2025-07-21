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
#include <stdlib.h>

#if (defined(SPD1177) || defined(SPD1179B))
    #include "spd1177.h"
#elif defined(SPD1179)
    #include "spd1179.h"
#else
    #include "spc1169.h"
#endif

#include "iap.h"


uint8_t u8nack = 0x1F; //NACK
uint8_t u8ack  = 0x79;  // ACK

#define DEBUG_INFO      1



/*
*  0: USE CAN
*  1: USE CANFD
*/
#define USE_CANFD_IAP           0

#define NOMINAL_SAMPLE_POINT    80  // 80%
#define NOMINAL_BAUDRATE        500000

#define DATA_SAMPLE_POINT       80  // 80%
#define DATA_BAUDRATE           2000000

/* CAN Baudrate */
double f64Baudrate;
double f64SamplePoints;
static uint8_t au8Data[64];


void ConfigCANParameters(CAN_REGS *CANx, uint32_t u32Baudrate, uint32_t u32SamplePoint)
{
    uint32_t u32Data ;
    uint32_t u32CanFreq;
    uint32_t u32Nbs1Nbs2;
    uint32_t u32Nbs1;
    uint32_t u32Nbs2;
    uint32_t u32Nbrp1;
    uint32_t u32Nbrp2;
    uint32_t u32Nbrp;
    uint32_t u32Numerator;
    uint32_t u32Denominator;

    /* Calculate Nbs1+Nbs2 */
    u32CanFreq = CLOCK_GetModuleClock(CAN_MODULE);
    if (u32Baudrate > 0)
    {
        u32Nbs1Nbs2 = u32CanFreq / u32Baudrate;
    }
    
    /* Calculate Nbrp */
    u32Nbs1 = u32Nbs1Nbs2 * u32SamplePoint / 100;
    u32Nbs2 = u32Nbs1Nbs2 - u32Nbs1;
    u32Nbrp1 = u32Nbs1 / 256 + 1;
    u32Nbrp2 = u32Nbs2 / 128 + 1;
    if (u32Nbrp1 > u32Nbrp2)
    {
        u32Nbrp = u32Nbrp1;
    }
    else
    {
        u32Nbrp = u32Nbrp2;
    }
    
    if (u32Nbrp > 256)
    {
        u32Nbrp = 256;
    }
    
    /* Calculate Nbs1 Nbs2 */
    u32Nbs1 = u32Nbs1 / u32Nbrp;
    u32Nbs2 = u32Nbs2 / u32Nbrp;
    
    if (u32Nbs1 > 256)
    {
        u32Nbs1 = 256;
    }
    if (u32Nbs1 < 1)
    {
        u32Nbs1 = 1;
    }
    
    if (u32Nbs2 > 128)
    {
        u32Nbs2 = 128;
    }

    /* Set Nbrp Nbs1 Nbs2 */
    u32Nbs1 = u32Nbs1 - 1;
    CAN_SetNominalBitRatePrescaler(CANx, u32Nbrp);
    CAN_SetNominalBitPhaseBufferSegment1(CANx, u32Nbs1);
    CAN_SetNominalBitPhaseBufferSegment2(CANx, u32Nbs2);
    CAN_SetNominalBitResyncJumpWidth(CANx, 8);
    printf("u32Nbrp :%d u32Nbs1 :%d u32Nbs2 :%d\n", u32Nbrp, u32Nbs1, u32Nbs2);
    
    /* Get actual baudrate Sample point */
    u32Data = CAN_GetNominalBitPhaseBufferSegment1(CANx) + 1;
    u32Data += CAN_GetNominalBitPhaseBufferSegment2(CANx);
    u32Data *= CAN_GetNominalBitRatePrescaler(CANx);
    f64Baudrate = CLOCK_GetModuleClock(CAN_MODULE) / u32Data;
    
    u32Numerator = CAN_GetNominalBitPhaseBufferSegment1(CANx) + 1;
    u32Denominator = u32Numerator + CAN_GetNominalBitPhaseBufferSegment2(CANx);
    f64SamplePoints = ((double)u32Numerator) / u32Denominator;
    printf("CAN actual Nominal Sample points : %f%%\n", f64SamplePoints * 100);
    printf("CAN actual Nominal Baudrate: %f\n", f64Baudrate );

}


void ConfigCANFDParameters(CAN_REGS *CANx, uint32_t u32Baudrate, uint32_t u32SamplePoint)
{
    uint32_t u32Data ;
    uint32_t u32CanFreq;
    uint32_t u32Dbs1Dbs2;
    uint32_t u32Dbs1;
    uint32_t u32Dbs2;
    uint32_t u32Dbrp1;
    uint32_t u32Dbrp2;
    uint32_t u32Dbrp;
    uint32_t u32Numerator;
    uint32_t u32Denominator;
 
    /* Calculate Dbs1+Dbs2 */
    u32CanFreq = CLOCK_GetModuleClock(CAN_MODULE);
    if (u32Baudrate > 0)
    {
        u32Dbs1Dbs2 = u32CanFreq / u32Baudrate;
    }
    
    /* Calculate Dbrp */
    u32Dbs1 = u32Dbs1Dbs2 * u32SamplePoint / 100;
    u32Dbs2 = u32Dbs1Dbs2 - u32Dbs1;
    u32Dbrp1 = u32Dbs1 / 32 + 1;
    u32Dbrp2 = u32Dbs2 / 16 + 1;
    if (u32Dbrp1 > u32Dbrp2)
    {
        u32Dbrp = u32Dbrp1;
    }
    else
    {
        u32Dbrp = u32Dbrp2;
    }
    
    if (u32Dbrp > 32)
    {
        u32Dbrp = 32;
    }
    
    /* Calculate Dbs1 Dbs2 */
    u32Dbs1 = u32Dbs1 / u32Dbrp;
    u32Dbs2 = u32Dbs2 / u32Dbrp;
    if (u32Dbs1 > 32)
    {
        u32Dbs1 = 32;
    }
    if (u32Dbs1 < 1)
    {
        u32Dbs1 = 1;
    }

    if (u32Dbs2 > 16)
    {
        u32Dbs2 = 16;
    }

    /* Set Dbrp Dbs1 Dbs2 */
    u32Dbs1 = u32Dbs1 - 1;
    CAN_SetDataBitRatePrescaler(CANx, u32Dbrp);
    CAN_SetDataBitPhaseBufferSegment1(CANx, u32Dbs1 );
    CAN_SetDataBitPhaseBufferSegment2(CANx, u32Dbs2 ); /* sample point: 80% */
    CAN_SetDataBitResyncJumpWidth    (CANx, 2 );
    
    printf("u32Dbrp :%d u32Dbs1 :%d u32Dbs2 :%d\n", u32Dbrp, u32Dbs1, u32Dbs2);

    /* Get actual baudrate Sample point */
    u32Data = CAN_GetDataBitPhaseBufferSegment1(CANx) + 1;
    u32Data += CAN_GetDataBitPhaseBufferSegment2(CANx);
    u32Data *= CAN_GetDataBitRatePrescaler(CANx);
    f64Baudrate = CLOCK_GetModuleClock(CAN_MODULE) / u32Data;
    
    u32Numerator = CAN_GetDataBitPhaseBufferSegment1(CANx) + 1;
    u32Denominator = u32Numerator + CAN_GetDataBitPhaseBufferSegment2(CANx);
    f64SamplePoints = ((double)u32Numerator) / u32Denominator;
    
    printf("CAN actual Data Sample points : %f%%\n", f64SamplePoints * 100);
    printf("CAN actual Data Baudrate: %f\n", f64Baudrate );
}

/*********************************************************************************************************************
 *
 * @brief      In this case, the Demo IAP upgrades via CAN protocol or CANFD protocol
 *              
 *             _____         ____________                              _________          ________
 *            |     |       |            |                            |         |        |        |
 *            | PC  |-VCC---|            |---------GND----------------|         |--GND---|        |
 *            |     |-D+----|            |----x---CANH-----x----------| CAN PHY |--RX----|  MCU   |
 *            |     |-D-----| USB-TO-CAN |----|-CANL-x-----|------x---|         |--TX----|        |
 *            |     |-GND---|            |    |  __  |     |  __  |   |         |---5V---|        |
 *            |_____|       |____________|    |_|__|_|     |_|__|_|   |_________|        |________|
 *                                              120          120
 *                                                
 * @KeyPoint   :   1. Add 120 ohm termination resistor
 *                 2. Modify the defination USE_CANFD_IAP
 *
 * @TestMethod :   The example and host computer sample point and baud rate configuration are the same
 * 
 * @TestResult :   
 *                  CAN protocol:
 *                              1. sample point 80%,baudrate500K, IAP upgrade is successful
 *                              2. sample point 80%,baudrate1M, IAP upgrade is successful
 *
 *                  CANFD protocol:
 *                              1. arbitration field sample point 80%,baudrate500K, data field sample point 80%,
 *                                 baudrate 2M IAP upgrade is successful
 *                              2. arbitration field sample point 80%,baudrate1M, data field sample point 80%,
 *                                 baudrate 5M IAP upgrade is successful
 *
 *************************************************************************************************************************/

int main(void)
{
    uint32_t u32TimeOut;
    
    /* Entry Point */
    uint32_t *pu32Entry;

    CLOCK_InitWithRCO(100000000U);

    Delay_Init();

    /*
     * Init the UART
     */
    PIN_SetChannel(PIN_GPIO10, PIN_GPIO10_UART0_TXD);
    PIN_SetChannel(PIN_GPIO11, PIN_GPIO11_UART0_RXD);
    UART_Init(UART0, 38400);

    /* Step1: Init CAN gpio  */
    #if (defined(SPD1179) || defined(SPD1177))
    PIN_SetChannel(PIN_GPIO8, PIN_GPIO8_CAN_TXD);
    PIN_SetChannel(PIN_GPIO9, PIN_GPIO9_CAN_RXD);
    #else
    PIN_SetChannel(PIN_GPIO8, PIN_GPIO8_CAN_TXD);
    PIN_SetChannel(PIN_GPIO9, PIN_GPIO9_CAN_RXD);
    #endif

    /* Step2: Enable CAN Clk */
    CLOCK_EnableModule(CAN_MODULE);

    /* Step3: Enable ISO-CAN protocol */
    if (USE_CANFD_IAP)
    {
        CAN_EnableFDFormat(CAN);
    }
    else
    {
        CAN_DisableFDFormat(CAN);
    }
    CAN_DisableNonIsoMode(CAN);

    /* Step4: Set nominal bit baud rate
     */
    ConfigCANParameters(CAN, NOMINAL_BAUDRATE, NOMINAL_SAMPLE_POINT);

    /* Step5: Set Data bit baud rate
     */
    if (USE_CANFD_IAP)
    {
        ConfigCANFDParameters(CAN, DATA_BAUDRATE, DATA_SAMPLE_POINT);
    }

    /* Set protocol exception mode */
    CAN_EnableProtocolException(CAN);

    /* Set transmission pause function */
    CAN_EnableTransmissionPause(CAN);

    /* Set RXD edge filter during integration status */
    CAN_EnableEdgeFilter(CAN);

    /* Enable re-tran message afte lost arbitration or error */
    CAN_EnableAutoRetransmission(CAN);
    
    /* Set timestamp */
    CAN_EnableTimestamp(CAN);

    /* Step6: Init message RAM */
    CAN_InitMessageRAM(CAN);

    /* Enable message RAM ECC */
    CAN_EnableParityCheck(CAN);

    /* Step7: Enable CAN */
    CAN_Enable(CAN);

    CAN_Read_Mailbox_Init(CAN, READ_MAILBOX_ID);
    CAN_Write_Mailbox_Init(CAN, WRITE_MAILBOX_ID);

    /* Wait for handshake byte with timeout 50ms, or the bootloader will jump to the application running */
    u32TimeOut = 50000;
    while (u32TimeOut--)
    {
        /* Check the received handshake byte (0x7F) */
        if ((CAN_IsMessageNew(CAN, READ_MAILBOX_ID)))
        {
            IAP_Read(CAN, au8Data);

            if (au8Data[0] == 0x7FU)
            {
                /* Received correct handshake byte, return ACK */
                IAP_Write(CAN, &u8ack, 1);
                /* Enter bootloader process */
                IAP_LoadFromCAN(CAN);
            }
            else
            {
                /* Received wrong handshake byte, return NACK */
                IAP_Write(CAN, &u8nack, 1);
            }
        }
        
        Delay_Us(1);
    }

    /* Entry point */
    pu32Entry = (uint32_t *)(0x1000F000 + 4);

    /* Jump to the application */
    ((PTRJUMP)(*pu32Entry))();

    while (1)
    {
    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
