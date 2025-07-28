/******************************************************************************
 * @file     spi.c
 * @brief    SPI firmware functions.
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

#include "spi.h"




/******************************************************************************
 * @brief      SPI clock initial
 *
 * @param[in]  SPIx       :  Select the SPI module
 * @param[in]  u32BaudRate:  Baud rate (bps)
 *
 * @return     none
 *
 * @detail     FIXME Add your detailed description here !
 *
 ******************************************************************************/
ErrorStatus SPI_InitSpeed(SPI_REGS *SPIx, uint32_t u32BaudRate)
{
    ErrorStatus Status = SUCCESS;
    uint32_t u32BaudCnt ;
    
    if (SPIx == SPI0)
    {
        CLOCK_EnableModule(SPI0_MODULE);
    }
    else
    {
        CLOCK_EnableModule(SPI1_MODULE);
    }

    u32BaudCnt = (uint32_t)(CLOCK_GetModuleClock(SPI0_MODULE) / u32BaudRate) ;

    if(u32BaudCnt < 65536U)
    {
        SPI_SetBaudCount(SPIx, u32BaudCnt) ;
    }
    else
    {
        Status = ERROR;
    }
    
    return Status;
}




/******************************************************************************
 * @brief      Initializes the SPI operating in SPI mode
 *
 * @param[in]  SPIx       :  Select the SPI port
 * @param[in]  eMode      :  SPI mode defined by SPI_ModeEnum
 *                           Following values are valid:
 *                             - \ref SPI_MASTER
 *                             - \ref SPI_SLAVE
 * @param[in]  eSPIMode   :  SPI mode defined by SPI_SPIModeEnum
 *                           Following values are valid:
 *                             - \ref SPI_MODE_PHS_POL_00
 *                             - \ref SPI_MODE_PHS_POL_01
 *                             - \ref SPI_MODE_PHS_POL_10
 *                             - \ref SPI_MODE_PHS_POL_11
 * @param[in]  u8DataSize :  Define SPI data size in one frame
 * @param[in]  u32Baudrate:  Define SPI baud rate
 *
 * @return     none
 *
 ******************************************************************************/
void SPI_Init(SPI_REGS          *SPIx,
              SPI_ModeEnum      eMode,
              SPI_SPIModeEnum   eSPIMode,
              uint8_t           u8DataSize,
              uint32_t          u32Baudrate
             )
{
    /* Enable SPI clock and set baud rate */
    SPI_InitSpeed(SPIx, u32Baudrate);

    /* Disable SPI */
    SPI_Disable(SPIx);

    /* Configure SPI function mode: Master or Slave */
    SPI_SetMode(SPIx, eMode);

    if(SPI_SLAVE == eMode)
    {
        /* Enable slave clock free running */
        SPI_EnableSlaveClockFreeRun(SPIx);
    }

    /* Set frame format as SPI mode */
    SPI_SetProtocol(SPIx, SPI_SPI);

    /* Configure SPI mode */
    SPI_SetSPIMode(SPIx, eSPIMode);

    /* Disable SFRM invert, SFRM active low */
    SPI_DisableSFRMInvert(SPIx);

    /* Configure SPI data size */
    SPI_SetDataSize(SPIx, u8DataSize);

    //  /* Enable SPI */
    //  SPI_Enable(SPIx);
}




/******************************************************************************
 * @brief      Initializes the SPI with pre-define settings
 *
 * @param[in]  SPIx       :  Select the SPI port
 * @param[in]  eMode      :  SPI mode defined by SPI_ModeEnum
 *                           Following values are valid:
 *                             - \ref SPI_MASTER
 *                             - \ref SPI_SLAVE
 * @param[in]  u8DataSize :  Define SPI data size in one frame
 * @param[in]  u32Baudrate:  Define SPI baud rate
 *
 * @return     none
 *
 * @detail     As in a lot of SPI application scenario,
 *             Frame is active Low
 *             Clock idle      Low
 *             Data send on    Rising edge
 *             In these cases, user can use this function as a simple method to configure SPI
 *
 ******************************************************************************/
void SPI_InitEasy(SPI_REGS      *SPIx,
                  SPI_ModeEnum  eMode,
                  uint8_t       u8DataSize,
                  uint32_t      u32Baudrate
                 )
{
    SPI_Init(SPIx, eMode, SPI_MODE_PHS_POL_00, u8DataSize, u32Baudrate);
}




/******************************************************************************
 * @brief      Exit network mode
 *
 * @param[in]  SPIx:  Select the SPI module
 *
 * @return     none
 *
 * @detail     When operating in Slave mode, the external code must provide
 *             the correct number of bits as determined by the frame width (SPISP.FRMWIDTH)
 *             and number of time slots (SPICLT0.FRMSLOT). When the number of
 *             bits read in during a Frame cycle do not match the number expected,
 *             a Bit Count Error will occur (SPIIF.BITCNTERR) and the contents in
 *             the FIFO cannot be guaranteed. Software must be used to handle
 *             any error conditions when they occur.
 *
 ******************************************************************************/
void SPI_ExitNetMode(SPI_REGS *SPIx)
{
    /* Wait TXFIFO empty, if not empty, will send none net mode frame */
    while(SPI_GetStatus(SPIx, SPI_STS_TX_EMPTY) == 0U)
    {}

    /* De-activate DMA service */

    /* Set SPI normal mode */
    SPI_SetMode(SPIx, SPI_SPI);

    /* Wait until Net mode idle */
    while(SPI_GetStatus(SPIx, SPI_STS_NET_BUSY) != 0U)
    {}

    /* Disable SPI module */
    SPI_Disable(SPIx);
}




/******************************************************************************
 * @brief      Send data to SPI peripheral (Single Frame mode, Send only)
 *
 * @param[in]  SPIx   :  Select the SPI module
 * @param[in]  pu32Buf:  Pointer to the array that stored data to be sent
 * @param[in]  u32Size:  Number of data to be sent
 *
 * @return     none
 *
 * @detail     FIXME add your detailed description here !
 *
 ******************************************************************************/
void SPI_Send(SPI_REGS *SPIx, uint32_t *pu32Buf, uint32_t u32Size)
{
    uint32_t i;

    for(i = 0; i < u32Size; i++)
    {
        /* Wait until TXFIFO empty */
        while(SPI_GetStatus(SPIx, SPI_STS_TX_EMPTY) == 0U)
        {}

        /* Send one data */
        SPI_SendData(SPIx, pu32Buf[i]);
    }
}




/******************************************************************************
 * @brief      Receive data from SPI peripheral (Single Frame mode, Receive only)
 *
 * @param[in]  SPIx       :  Select the SPI module
 * @param[in]  pu32Buf    :  Pointer to the buffer that stored the received data
 * @param[in]  u32Size    :  Number of data to be received
 *
 * @return     none
 *
 * @detail     FIXME add your detailed description here !
 *
 ******************************************************************************/
void SPI_Receive(SPI_REGS *SPIx, uint32_t *pu32Buf, uint32_t u32Size)
{
    uint32_t i;
    uint32_t u32ReadFlag  =   SPI_STS_RX_NOT_EMPTY
                              | ((0 != SPI_IsEnableFIFOPack(SPIx))
                                 ? SPI_STS_RX_EVEN_SAMPLE : 0U
                                ) ;

    for(i = 0; i < u32Size ; i++)
    {
        /* Wait until RXFIFO not empty and has even samples (Pack mode) */
        while(SPI_GetStatus(SPIx, u32ReadFlag) != u32ReadFlag)
        {}

        /* Receive one data */
        pu32Buf[i] = SPI_ReceiveData(SPIx);
    }
}




/******************************************************************************
 * @brief      SPI Master Transmit and Receive data (Single Frame mode, Full Duplex)
 *
 * @param[in]  SPIx           :  Select the SPI module
 * @param[in]  pu32WriteBuffer:  Pointer to the array that stored data to be sent
 * @param[in]  pu32ReadBuffer :  Pointer to the buffer that stored the received data
 * @param[in]  u32Size        :  Number of data to be transceived
 *
 * @return     none
 *
 * @detail     FIXME add your detailed description here !
 *
 ******************************************************************************/
void SPI_MasterTransceive(SPI_REGS *SPIx,
                          uint32_t *pu32WriteBuffer,
                          uint32_t *pu32ReadBuffer,
                          uint32_t u32Size
                         )
{
    uint32_t i;
    uint32_t u32ReadFlag  =   SPI_STS_RX_NOT_EMPTY
                              | ((0 != SPI_IsEnableFIFOPack(SPIx))
                                 ? SPI_STS_RX_EVEN_SAMPLE : 0U
                                ) ;

    for(i = 0; i < u32Size ; i++)
    {
        /* Wait until TXFIFO empty */
        while(SPI_GetStatus(SPIx, SPI_STS_TX_EMPTY) == 0U)
        {}

        /* Send one data */
        SPI_SendData(SPIx, pu32WriteBuffer[i]);

        /* Wait until RXFIFO not empty and has even samples (pack mode) */
        while(SPI_GetStatus(SPIx, u32ReadFlag) != u32ReadFlag)
        {}

        /* Receive one data */
        pu32ReadBuffer[i] = SPI_ReceiveData(SPIx);
    }
}




/******************************************************************************
 * @brief      SPI Master Transmit and Receive Multi-Frame data (For SPI mode only)
 *
 * @param[in]  SPIx           :  Select the SPI module
 * @param[in]  pu32WriteBuffer:  Pointer to the array that stored data to be sent
 * @param[in]  pu32ReadBuffer :  Pointer to the buffer that stored the received data
 * @param[in]  u32Size        :  Number of data to be transceived
 *
 * @return     none
 *
 * @detail     No access limitation when CPU write SPI FIFO
 *
 ******************************************************************************/
void SPI_MasterB2BTransceive(SPI_REGS *SPIx,
                             uint32_t *pu32WriteBuffer,
                             uint32_t *pu32ReadBuffer,
                             uint32_t u32Size
                            )
{
    SPI_EnableTestSFRMLock(SPIx);

    /* Wait until not busy */
    while(SPI_GetStatus(SPIx, SPI_STS_BUSY) != 0U)
    {}

    SPI_EnableSFRMLock(SPIx);

    SPI_MasterTransceive(SPIx, pu32WriteBuffer, pu32ReadBuffer, u32Size);

    SPI_DisableSFRMLock(SPIx);

    /* Wait until lock released */
    while(SPI_GetStatus(SPIx, SPI_STS_SFRM_LOCKED) != 0U)
    {}

    SPI_DisableTestSFRMLock(SPIx);
}




/******************************************************************************
 * @brief      SSP Master Transmit and Receive Multi-Frame data
 *
 * @param[in]  SPIx           :  Select the SPI module
 * @param[in]  pu32WriteBuffer:  Pointer to the array that stored data to be sent
 * @param[in]  pu32ReadBuffer :  Pointer to the buffer that stored the received data
 * @param[in]  u32Size        :  Number of data to be transceived
 *
 * @return     none
 *
 * @detail     SPI module bus clock must faster than module clock and
 *             CPU write FIFO should be faster enough to keep FIFO not empty until
 *             all data transfer finished.
 *
 ******************************************************************************/
//void SSP_MasterB2BTransceive(SPI_REGS *SPIx,
//                             uint32_t *pu32WriteBuffer,
//                             uint32_t *pu32ReadBuffer,
//                             uint32_t u32Size
//                            )
//{
//    uint32_t u32TxCount = 0U;
//    uint32_t u32RxCount = 0U;

//    uint32_t u32WriteFlag =   SPI_STS_TX_NOT_FULL
//                              | ((0 != SPI_IsEnableFIFOPack(SPIx))
//                                 ? SPI_STS_TX_EVEN_SAMPLE : 0U
//                                ) ;

//    uint32_t u32ReadFlag  =   SPI_STS_RX_NOT_EMPTY
//                              | ((0 != SPI_IsEnableFIFOPack(SPIx))
//                                 ? SPI_STS_RX_EVEN_SAMPLE : 0U
//                                ) ;

//    uint32_t u32Dummy     = (u32Size < SPI_FIFO_DEPTH) ? u32Size :
//                            SPI_FIFO_DEPTH;

//    /* Wait until TXFIFO empty */
//    while(SPI_GetStatus(SPIx, SPI_STS_TX_EMPTY) == 0U)
//    {}

//    do
//    {
//        /* Send one data */
//        SPI_SendData(SPIx, pu32WriteBuffer[u32TxCount]);
//        u32TxCount++;
//    }
//    while(u32TxCount < u32Dummy);

//    while(u32TxCount < u32Size)
//    {
//        /* Try receive one data */
//        if(SPI_GetStatus(SPIx, u32ReadFlag) == u32ReadFlag)
//        {
//            pu32ReadBuffer[u32RxCount] = SPI_ReceiveData(SPIx);
//            u32RxCount++;
//        }

//        /* Try send one data */
//        if(SPI_GetStatus(SPIx, u32WriteFlag) == u32WriteFlag)
//        {
//            SPI_SendData(SPIx, pu32WriteBuffer[u32TxCount]);
//            u32TxCount++;
//        }
//    }

//    while(u32RxCount < u32Size)
//    {
//        if(SPI_GetStatus(SPIx, u32ReadFlag) == u32ReadFlag)
//        {
//            pu32ReadBuffer[u32RxCount] = SPI_ReceiveData(SPIx);
//            u32RxCount++;
//        }
//    }
//}




/******************************************************************************
 * @brief      SPI Slave Transmit and Receive Multi-Frame data (Full Duplex)
 *
 * @param[in]  SPIx           :  Select the SPI module
 * @param[in]  pu32WriteBuffer:  Pointer to the array that stored data to be sent
 * @param[in]  pu32ReadBuffer :  Pointer to the buffer that stored the received data
 * @param[in]  u32Size        :  Number of data to be transceived
 *
 * @return     none
 *
 * @detail     Time interval between SFRM active level should be long enough.
 *
 ******************************************************************************/
void SPI_SlaveTransceive(SPI_REGS *SPIx,
                         uint32_t *pu32WriteBuffer,
                         uint32_t *pu32ReadBuffer,
                         uint32_t u32Size
                        )
{
    uint32_t u32TxCount = 0U;
    uint32_t u32RxCount = 0U;

    uint32_t u32WriteFlag =   SPI_STS_TX_NOT_FULL
                              | ((0 != SPI_IsEnableFIFOPack(SPIx))
                                 ? SPI_STS_TX_EVEN_SAMPLE : 0U
                                ) ;

    uint32_t u32ReadFlag  =   SPI_STS_RX_NOT_EMPTY
                              | ((0 != SPI_IsEnableFIFOPack(SPIx))
                                 ? SPI_STS_RX_EVEN_SAMPLE : 0U
                                ) ;

    while(u32TxCount < u32Size)
    {
        /* Try receive one data */
        if(SPI_GetStatus(SPIx, u32ReadFlag) == u32ReadFlag)
        {
            pu32ReadBuffer[u32RxCount] = SPI_ReceiveData(SPIx);
            u32RxCount++;
        }

        /* Try send one data */
        if(SPI_GetStatus(SPIx, u32WriteFlag) == u32WriteFlag)
        {
            SPI_SendData(SPIx, pu32WriteBuffer[u32TxCount]);
            u32TxCount++;
        }
    }

    while(u32RxCount < u32Size)
    {
        if(SPI_GetStatus(SPIx, u32ReadFlag) == u32ReadFlag)
        {
            pu32ReadBuffer[u32RxCount] = SPI_ReceiveData(SPIx);
            u32RxCount++;
        }
    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/

