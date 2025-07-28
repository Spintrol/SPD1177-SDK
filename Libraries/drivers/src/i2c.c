/******************************************************************************
 * @file     i2c.c
 * @brief    I2C firmware functions.
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

#include "i2c.h"




/******************************************************************************
 * @brief      Initializes I2C Speed
 *
 * @param[in]  I2Cx    :  Select the I2C module
 * @param[in]  u32Speed:  Operation speed (bps)
 *
 * @return     ErrorStatus:
 *                  ERROR if I2C clock is not fast enough to support the speed
 *
 ******************************************************************************/
ErrorStatus I2C_InitSpeed(I2C_REGS *I2Cx, uint32_t u32Speed)
{
    uint32_t u32PCnt;
    uint32_t u32HCnt;
    uint32_t u32LCnt;
    uint32_t u32LCntMin;
    uint32_t u32SpikeLen;
    uint32_t u32ClkFreq;

    u32ClkFreq = CLOCK_GetModuleClock(AHB_MODULE);
    u32PCnt    = u32ClkFreq / u32Speed;

    /* Standard mode (100 kbps) */
    if(u32Speed <= 100000)
    {
        u32SpikeLen = u32ClkFreq / 20000000;
        if((u32SpikeLen * 20000000) != u32ClkFreq)
        {
            u32SpikeLen = u32SpikeLen + 1;
        }

        u32LCntMin  = 47 * u32ClkFreq / 10000000;
        if((u32LCntMin * 10000000) == (47 * u32ClkFreq))
        {
            u32LCntMin = u32LCntMin + 1;
        }
        else
        {
            u32LCntMin = u32LCntMin + 2;
        }

        if(u32LCntMin > (u32PCnt / 2))
        {
            u32LCnt = u32LCntMin;
        }
        else
        {
            u32LCnt = u32PCnt / 2;
        }

        u32HCnt = u32PCnt - u32LCnt;

        /* Check whether I2C clock is fast enough to support the speed */
        if((u32LCnt < 9) || (u32HCnt < (u32SpikeLen + 13)))
        {
            return ERROR;
        }

        /* Set I2C operating speed mode */
        MODIFY_REG(I2Cx->I2CCTL, I2CCTL_SPEED_Msk, I2CCTL_SPEED_STANDARD);

        /* Spike suppression */
        I2Cx->I2CFSSPKLEN = u32SpikeLen;

        /* Standard mode SCL hold low time counter */
        I2Cx->I2CSSLCNT = u32LCnt - 1;

        /* Standard mode SCL hold high time counter */
        I2Cx->I2CSSHCNT = u32HCnt - 7 - u32SpikeLen;
    }

    /* Fast mode (400 kbps) */
    else if(u32Speed <= 400000)
    {
        u32SpikeLen = u32ClkFreq / 20000000;
        if((u32SpikeLen * 20000000) != u32ClkFreq)
        {
            u32SpikeLen = u32SpikeLen + 1;
        }

        u32LCntMin = 13 * u32ClkFreq / 10000000;
        if((u32LCntMin * 10000000) == (13 * u32ClkFreq))
        {
            u32LCntMin = u32LCntMin + 1;
        }
        else
        {
            u32LCntMin = u32LCntMin + 2;
        }

        if(u32LCntMin > (u32PCnt / 2))
        {
            u32LCnt = u32LCntMin;
        }
        else
        {
            u32LCnt = u32PCnt / 2;
        }

        u32HCnt = u32PCnt - u32LCnt;

        /* Check whether I2C clock is fast enough to support the speed */
        if((u32LCnt < 9) || (u32HCnt < (u32SpikeLen + 13)))
        {
            return ERROR;
        }

        /* Set I2C operating speed mode */
        MODIFY_REG(I2Cx->I2CCTL, I2CCTL_SPEED_Msk, I2CCTL_SPEED_FAST);

        /* Spike suppresion */
        I2Cx->I2CFSSPKLEN = u32SpikeLen;

        /* Fast mode SCL hold low time counter */
        I2Cx->I2CFSLCNT = u32LCnt - 1;

        /* Fast mode SCL hold high time counter */
        I2Cx->I2CFSHCNT = u32HCnt - 7 - u32SpikeLen;
    }

    /* High speed mode (3.4 Mbps) */
    else
    {
        u32SpikeLen = u32ClkFreq / 100000000;
        if((u32SpikeLen * 100000000) != u32ClkFreq)
        {
            u32SpikeLen = u32SpikeLen + 1;
        }

        u32HCnt = u32PCnt / 3;
        u32LCnt = u32HCnt * 2;
        /* Check whether I2C clock is fast enough to support the speed */
        if((u32LCnt < 9) || (u32HCnt < (u32SpikeLen + 13)))
        {
            return ERROR;
        }

        /* Set I2C operating speed mode */
        MODIFY_REG(I2Cx->I2CCTL, I2CCTL_SPEED_Msk, I2CCTL_SPEED_HIGH);

        /* High mode SCL hold low time counter */
        I2Cx->I2CHSLCNT = u32LCnt - 1;

        /* High mode SCL hold high time counter */
        I2Cx->I2CHSHCNT = u32HCnt - 7 - u32SpikeLen;
    }

    return SUCCESS;
}




/******************************************************************************
 * @brief      Initializes the I2C master
 *
 * @param[in]  I2Cx    :  Select the I2C module
 * @param[in]  u32Speed:  Operation speed (bps)
 *
 * @return     ErrorStatus:
 *                  ERROR if I2C clock is not fast enough to support the speed
 *
 ******************************************************************************/
ErrorStatus I2C_MasterInit(I2C_REGS *I2Cx, uint32_t u32Speed)
{
    /* Enable I2C Module Clock */
    CLOCK_EnableModule(I2C_MODULE);

    /* Disable I2C */
    I2C_Disable(I2Cx);

    /* Master mode */
    I2C_SetMode(I2Cx, I2C_MASTER);

    /* Restart enable */
    I2C_EnableRestart(I2Cx);

    /* Initial I2C Speed */
    if(u32Speed > 400000) /* For high-speed mode, set fast-speed as 400k */
    {
        I2C_InitSpeed(I2Cx, 400000);
    }

    if(I2C_InitSpeed(I2Cx, u32Speed) == SUCCESS)
    {
        /* Enable I2C */
        //    I2C_Enable(I2Cx);

        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}




/******************************************************************************
 * @brief      Initializes the I2C slave
 *
 * @param[in]  I2Cx      :  Select the I2C module
 * @param[in]  eAddrMode :  Address mode
 *                          Please refer to I2C_AddrModeEnum
 *                           - \ref I2C_ADDR_7BIT
 *                           - \ref I2C_ADDR_10BIT
 * @param[in]  u16SlvAddr:  Slave address
 * @param[in]  u32Speed  :  Operation speed (bps)
 *
 * @return     ErrorStatus:
 *                  ERROR if I2C clock is not fast enough to support the speed
 *
 ******************************************************************************/
ErrorStatus I2C_SlaveInit(I2C_REGS *I2Cx, I2C_AddrModeEnum eAddrMode, uint16_t u16SlvAddr, uint32_t u32Speed)
{
    uint32_t u32SDASetup;

    CLOCK_EnableModule(I2C_MODULE);

    /* Disable I2C */
    I2C_Disable(I2Cx);

    /* Slave mode */
    I2C_SetMode(I2Cx, I2C_SLAVE);

    /* Restart enable */
    I2C_EnableRestart(I2Cx);

    /* Set address mode */
    I2C_SetAddressMode(I2Cx, eAddrMode);

    /* Slave address */
    I2C_SetSlaveAddress(I2Cx, u16SlvAddr);

    if(u32Speed <= 100000)
    {
        /* SDA Minimum Set Up Delay 250ns */
        u32SDASetup = CLOCK_GetModuleClock(AHB_MODULE) / 4000000 + 1;
    }
    else if(u32Speed <= 400000)
    {
        /* SDA Minimum Set Up Delay 100ns */
        u32SDASetup = CLOCK_GetModuleClock(AHB_MODULE) / 10000000 + 1;
    }
    else
    {
        /* SDA Minimum Set Up Delay 30ns */
        u32SDASetup = CLOCK_GetModuleClock(AHB_MODULE) * 3 / 100000000 + 1;
    }

    /* Check whether I2C clock is fast enough to support the speed */
    if(u32SDASetup < 2)
    {
        return ERROR;
    }
    else
    {
        I2Cx->I2CSDASETUP = u32SDASetup;
    }

    /* Enable I2C */
    //  I2C_Enable(I2Cx);

    return SUCCESS;
}




/******************************************************************************
 * @brief      Enable I2C
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_Enable(I2C_REGS *I2Cx)
{
    /* Enable I2C */
    SET_BITS(I2Cx->I2CCTL, I2CCTL_EN_Msk);

    /* Wait I2C enabled */
    while(I2C_GetStatus(I2Cx, I2C_STS_ENABLE) == 0U)
    {
    }
}




/******************************************************************************
 * @brief      Disable I2C
 *
 * @param[in]  I2Cx:  Select the I2C module
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_Disable(I2C_REGS *I2Cx)
{
    /* Disable I2C */
    CLEAR_BITS(I2Cx->I2CCTL, I2CCTL_EN_Msk);

    /* Wait I2C disabled */
    while(I2C_GetStatus(I2Cx, I2C_STS_ENABLE) != 0U)
    {
    }
}




/******************************************************************************
 * @brief      I2C Master Mode Send Data function
 *
 * @param[in]  I2Cx         :  Select the I2C module
 * @param[in]  eAddrMode    :  Address mode
 *                             Please refer to I2C_AddrModeEnum
 *                               - \ref I2C_ADDR_7BIT
 *                               - \ref I2C_ADDR_10BIT
 * @param[in]  u16TargetAddr:  Target Slave address
 * @param[in]  pu8WriteBuf  :  Pointer to the buffer that stored the data to be sent
 * @param[in]  u32Count     :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_MasterWrite( I2C_REGS *I2Cx , I2C_AddrModeEnum eAddrMode
    , uint16_t u16TargetAddr , uint8_t *pu8WriteBuf , uint32_t u32Count)
{
    uint32_t i;

    /* Set Address Mode */
    I2C_SetAddressMode(I2Cx, eAddrMode);

    /* Set Target Slave Address*/
    I2C_SetTargetAddress(I2Cx, u16TargetAddr);

    for(i = 0; i < u32Count; i++)
    {
        /* Write TxFIFO, Send Address and Send Data If Master Get ACK */
        I2C_WriteByte(I2Cx, pu8WriteBuf[i]);

        /* Wait Slave Receive Data And Send ACK Again,
         * Then Master Stop Bus Because of TxFIFO Empty
         */

        /* Wait Until TxFIFO Empty */
        while(!I2C_GetStatus(I2Cx, I2C_STS_TX_EMPTY)) { }

        /* Wait I2C Bus Idle */
        while(I2C_GetStatus(I2Cx, I2C_STS_ACTIVITY)) { }

        /* Do Not Get ACK, Master Abort Send Data, Flush TxFIFO, Send Stop Signal */
        if(I2C_GetIntRawFlag(I2Cx, I2C_INT_TX_ABORT))
        {
            return;
        }
    }
}




/******************************************************************************
 * @brief      I2C Slave Mode Receive Data function
 *
 * @param[in]  I2Cx      :  Select the I2C module
 * @param[in]  pu8ReadBuf:  Pointer to the buffer that stored the received data
 * @param[in]  u32Count  :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_SlaveRead(I2C_REGS *I2Cx, uint8_t *pu8ReadBuf, uint32_t u32Count)
{
    uint32_t i;

    for(i = 0; i < u32Count; i++)
    {
        /* Slave Receive Data, And Send ACK */

        /* Wait Until RxFIFO Not Empty */
        while(!I2C_GetStatus(I2Cx, I2C_STS_RX_NOT_EMPTY)) { }

        /* Read RxFIFO, Read Data */
        pu8ReadBuf[i] = I2C_ReadByte(I2Cx);
    }
}




/******************************************************************************
 * @brief      I2C Master Mode Receive Data function
 *
 * @param[in]  I2Cx         :  Select the I2C module
 * @param[in]  eAddrMode    :  Address mode
 *                             Please refer to I2C_AddrModeEnum
 *                              - \ref I2C_ADDR_7BIT
 *                              - \ref I2C_ADDR_10BIT
 * @param[in]  u16TargetAddr:  Target Slave address
 * @param[in]  pu8ReadBuf   :  Pointer to the buffer that stored the received data
 * @param[in]  u32Count     :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_MasterRead(I2C_REGS *I2Cx, I2C_AddrModeEnum eAddrMode,
                    uint16_t u16TargetAddr, uint8_t *pu8ReadBuf, uint32_t u32Count)
{
    uint32_t i;

    /* Set Address Mode */
    I2C_SetAddressMode(I2Cx, eAddrMode);

    /* Set Target Slave Address*/
    I2C_SetTargetAddress(I2Cx, u16TargetAddr);

    for(i = 0; i < u32Count; i++)
    {
        /* Write TxFIFO, Send Read Command */
        I2C_MasterReadCmd(I2Cx);

        /* Wait Slave Send Data If Master Get ACK,
        * Then Master Receive One Data,
        * Send NACK and Stop Bus Because of TxFIFO Empty;
        */

        /* Wait Until RxFIFO Not Empty */
        while(!I2C_GetStatus(I2Cx, I2C_STS_RX_NOT_EMPTY))
        {
            /* Do Not Get ACK, Master Abort Send Data, Flush TxFIFO, Send Stop Signal */
            if(I2C_GetIntRawFlag(I2Cx, I2C_INT_TX_ABORT))
            {
                return;
            }
        }

        /* Read RxFIFO, Read Data */
        pu8ReadBuf[i] = I2C_ReadByte(I2Cx);

        /* Wait I2C Bus Idle */
        while(I2C_GetStatus(I2Cx, I2C_STS_ACTIVITY)) { }
    }
}




/******************************************************************************
 * @brief      I2C Slave Mode Send Data function
 *
 * @param[in]  I2Cx       :  Select the I2C module
 * @param[in]  pu8WriteBuf:  Pointer to the buffer that stored the data to be sent
 * @param[in]  u32Count   :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_SlaveWrite(I2C_REGS *I2Cx, uint8_t *pu8WriteBuf, uint32_t u32Count)
{
    uint32_t i;

    for(i = 0; i < u32Count; i++)
    {
        /* Slave Send ACK If Master Request Address Matched
        */

        /* Wait Until Detect Read Request */
        while(!I2C_GetIntRawFlag(I2Cx, I2C_INT_READ_REQ)) { }

        /* Clear Event Flag */
        I2C_ClearInt(I2Cx, I2C_INT_READ_REQ);

        /* Write TxFIFO, Send Data */
        I2C_WriteByte(I2Cx, pu8WriteBuf[i]);

        /* Wait Master Send ACK/NACK
        */

        /* Wait Until Master Receiver Done, Slave Get NACK */
        while(!I2C_GetIntRawFlag(I2Cx, I2C_INT_RX_DONE)) { }

        /* Clear Event Flag */
        I2C_ClearInt(I2Cx, I2C_INT_RX_DONE);
    }
}




/******************************************************************************
 * @brief      I2C Master Mode Bulk Send Data function
 *
 * @param[in]  I2Cx          :  Select the I2C module
 * @param[in]  eAddrMode     :  Address mode
 *                              Please refer to I2C_AddrModeEnum
 *                               - \ref I2C_ADDR_7BIT
 *                               - \ref I2C_ADDR_10BIT
 * @param[in]  u16TargetAddr :  Target Slave address
 * @param[in]  pu8WriteBuf   :  Pointer to the buffer that stored the data to be sent
 * @param[in]  u32Count      :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_MasterBulkWrite(I2C_REGS *I2Cx, I2C_AddrModeEnum eAddrMode,
                         uint16_t u16TargetAddr, uint8_t *pu8WriteBuf, uint32_t u32Count)
{
    uint32_t i;

    /* Set Address Mode */
    I2C_SetAddressMode(I2Cx, eAddrMode);

    /* Set Target Slave Address*/
    I2C_SetTargetAddress(I2Cx, u16TargetAddr);

    /* TxFIFO Can Not Empty During Bulk Transmit */
    for(i = 0; i < u32Count; i++)
    {
        /* Wait Until TxFIFO not Full */
        while(!I2C_GetStatus(I2Cx, I2C_STS_TX_NOT_FULL))
        {
            /* Do Not Get ACK, Master Abort Send Data, Flush TxFIFO, Send Stop Signal */
            if(I2C_GetIntRawFlag(I2Cx, I2C_INT_TX_ABORT))
            {
                return ;
            }
        }

        /* Write TxFIFO, Send Data If Master Get ACK */
        I2C_WriteByte(I2Cx, pu8WriteBuf[i]);
    }

    /* Wait Slave Receive Data And Send ACK Again,
    * Until Master Stop Bus Because of TxFIFO Empty
    */

    /* Wait Until TxFIFO Empty */
    while(!I2C_GetStatus(I2Cx, I2C_STS_TX_EMPTY)) { }

    /* Wait I2C Bus Idle */
    while(I2C_GetStatus(I2Cx, I2C_STS_ACTIVITY)) { }

    /* Do Not Get ACK, Master Abort Send Data, Flush TxFIFO, Send Stop Signal */
    if(I2C_GetIntRawFlag(I2Cx, I2C_INT_TX_ABORT))
    {
        return ;
    }
}




/******************************************************************************
 * @brief      I2C Slave Mode Bulk Receive Data function
 *
 * @param[in]  I2Cx      :  Select the I2C module
 * @param[in]  pu8ReadBuf:  Pointer to the buffer that stored the received data
 * @param[in]  u32Count  :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_SlaveBulkRead(I2C_REGS *I2Cx, uint8_t *pu8ReadBuf, uint32_t u32Count)
{
    uint32_t i;

    for(i = 0; i < u32Count; i++)
    {
        /* Slave Receive Data, And Send ACK
         */

        /* Wait Until RxFIFO Not Empty */
        while(!I2C_GetStatus(I2Cx, I2C_STS_RX_NOT_EMPTY)) { }

        /* Read RxFIFO, Read Data */
        pu8ReadBuf[i] = I2C_ReadByte(I2Cx);
    }
}




/******************************************************************************
 * @brief      I2C Master Mode Bulk Receive Data function
 *
 * @param[in]  I2Cx         :  Select the I2C module
 * @param[in]  eAddrMode    :  Address mode
 *                             Please refer to I2C_AddrModeEnum
 *                              - \ref I2C_ADDR_7BIT
 *                              - \ref I2C_ADDR_10BIT
 * @param[in]  u16TargetAddr:  Target Slave address
 * @param[in]  pu8ReadBuf   :  Pointer to the buffer that stored the received data
 * @param[in]  u32Count     :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_MasterBulkRead(I2C_REGS *I2Cx, I2C_AddrModeEnum eAddrMode,
                        uint16_t u16TargetAddr, uint8_t *pu8ReadBuf, uint32_t u32Count)
{
    uint32_t u32RxCnt = 0;
    uint32_t u32TxCnt = 0;

    /* Set Address Mode */
    I2C_SetAddressMode(I2Cx, eAddrMode);

    /* Set Target Slave Address*/
    I2C_SetTargetAddress(I2Cx, u16TargetAddr);

    /* Master Send Address, Wait Slave Send Data If Master Get ACK;
    * Then Master Receive Data and Send ACK;
    * Send NACK and Stop Bus When TxFIFO Empty;
    */

    /* TxFIFO Can Not Empty During Bulk Transmit */
    while(u32TxCnt < u32Count)
    {
        /* TxFIFO not Full */
        if(I2C_GetStatus(I2Cx, I2C_STS_TX_NOT_FULL))
        {
            /* Write TxFIFO, Send Read Command */
            I2C_MasterReadCmd(I2Cx);
            u32TxCnt++;
        }

        /* RxFIFO Not Empty */
        if(I2C_GetStatus(I2Cx, I2C_STS_RX_NOT_EMPTY))
        {
            /* Read RxFIFO, Read Data */
            *pu8ReadBuf++ = I2C_ReadByte(I2Cx);
            u32RxCnt++;
        }

        /* Do Not Get ACK, Master Abort Send Data, Flush TxFIFO, Send Stop Signal */
        if(I2C_GetIntRawFlag(I2Cx, I2C_INT_TX_ABORT))
        {
            return;
        }
    }

    /* Read the Rest of Data */
    while(u32RxCnt < u32Count)
    {
        /* RxFIFO Not Empty */
        if(I2C_GetStatus(I2Cx, I2C_STS_RX_NOT_EMPTY))
        {
            /* Read RxFIFO, Read Data */
            *pu8ReadBuf++ = I2C_ReadByte(I2Cx);
            u32RxCnt++;
        }
    }

    /* Wait Until TxFIFO Empty */
    while(!I2C_GetStatus(I2Cx, I2C_STS_TX_EMPTY)) { }

    /* Wait I2C Bus Idle */
    while(I2C_GetStatus(I2Cx, I2C_STS_ACTIVITY)) { }
}




/******************************************************************************
 * @brief      I2C Slave Mode Bulk Send Data function
 *
 * @param[in]  I2Cx       :  Select the I2C module
 * @param[in]  pu8WriteBuf:  Pointer to the buffer that stored the data to be sent
 * @param[in]  u32Count   :  Number of data to be sent or received
 *
 * @return     none
 *
 ******************************************************************************/
void I2C_SlaveBulkWrite(I2C_REGS *I2Cx, uint8_t *pu8WriteBuf, uint32_t u32Count)
{
    uint32_t i = 0;

    /* Slave Send ACK If Master Request Address Matched
    */

    /* Wait Until Detect Read Request */
    while(!I2C_GetIntRawFlag(I2Cx, I2C_INT_READ_REQ)) { }

    /* Clear Event Flag */
    I2C_ClearInt(I2Cx, I2C_INT_READ_REQ);

    while(i < u32Count)
    {
        /* I2C Bus Idle */
        if(!I2C_GetStatus(I2Cx, I2C_STS_ACTIVITY))
        {
            return;
        }

        /* TxFIFO not Full */
        if(I2C_GetStatus(I2Cx, I2C_STS_TX_NOT_FULL))
        {
            /* Write TxFIFO, Send Data */
            I2C_WriteByte(I2Cx, pu8WriteBuf[i]);
            i++;
        }
    }

    /* Wait Until Master Receiver Done, Slave Get NACK */
    while(!I2C_GetIntRawFlag(I2Cx, I2C_INT_RX_DONE)) { }

    /* Clear Event Flag */
    I2C_ClearInt(I2Cx, I2C_INT_RX_DONE);

    /* Clear Event Flag */
    I2C_ClearInt(I2Cx, I2C_INT_READ_REQ);
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/

