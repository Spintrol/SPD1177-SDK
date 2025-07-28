/******************************************************************************
 * @file     main.c
 * @brief    Main program body
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
#include <stdio.h>

#if defined(SPD1179)
    #include "spd1179.h"
#else
    #include "spc1169.h"
#endif

#define                 DEBUG_INFO                 1                            /* The controlling flag of printf info*/
#define                 SLAVE_TRANSMIT             0                            /* 1: slave transmit 0: slave receive */
#define                 T_BUFFER_SIZE              128
#define                 I2C_Slave_ADDR             0x9                          /* IIC Slave ADDR */
#define                 I2C_SPEED                  400000

uint32_t                gu32BuffSize                = T_BUFFER_SIZE;
uint8_t                 gau8TxBuf[T_BUFFER_SIZE];
uint8_t                 gau8RxBuf[T_BUFFER_SIZE];
uint32_t                gu32_cnt_i2c_stop_isr;
ErrorStatus             estatus;

static void Check_Receive_Data(void)
{
    int i;
    uint8_t u8Data = 0;

    /*To check the datum sent and recieved are the same*/
    for(i = 0; i < gu32BuffSize; i++)
    {
        if (gau8RxBuf[i] != u8Data)
        {
            printf("[Error]@%4d: TX(0x%02X) != RX(0x%02X)\n", __LINE__, u8Data, gau8RxBuf[i] );
        }
        else
        {
            #if DEBUG_INFO
            printf("%3d: TX(0x%02X) == RX(0x%02X)\n", i, u8Data, gau8RxBuf[i] );
            #endif
        }

        u8Data++;
    }
}

void Slave_Bulk_TxRX_data(I2C_REGS* I2Cx)
{
    int i;
    uint8_t u8Data = 0;
    uint32_t u32IsrCnt = 0;                                        /*Interrupt Check variable*/

    if (SLAVE_TRANSMIT)
    {
        /* Generate random datum to transmit */
        for(i=0; i < gu32BuffSize; i++)
        {
            gau8TxBuf[i] = u8Data++;
            printf("gau8TxBuf[%d] = 0x%x\n", i, gau8TxBuf[i]);
        }

        printf("Slave Tx data...\n");
        I2C_SlaveBulkWrite(I2Cx, gau8TxBuf, gu32BuffSize);
    }
    else
    {
        printf("Slave Rx data...\n");
        I2C_SlaveBulkRead(I2Cx, gau8RxBuf, gu32BuffSize);

        /*To check the datum sent and recieved are the same*/
        Check_Receive_Data();
    }

    /*
    * The master will sent a 'STOP' CMD to the IIC, and then sent a 'RESTART' at the
    * next bulk. we can count the bulk we has sent to get the INT count had entered.
    */
    u32IsrCnt += 1;

    /* Wait for I2C INT done */
    Delay_Us(300);

    /*
    * Check interrupt counter, if the INT count is not equal the bulk we has sent, there
    * must be something wrong had happened.
    */
    if( gu32_cnt_i2c_stop_isr != u32IsrCnt )
    {
        printf("[Error]@%4d: I2C ISR counter not right. expect %d, but is %d", __LINE__,
                              u32IsrCnt, gu32_cnt_i2c_stop_isr);
    }
    else
    {
        printf("Success\n");
    }
}


/*************************************************************************************************************************
 *
 * @brief      In this case, the IIC controller is used as salve opened the 'STOP' INT, and master sent datum to slave with
 *             a 'STOP' CMD after every bulk, in other words, IIC will stop after every bulk, so the number of INT equal the
 *             number of bulks had sent.
 *
 *             This demo code is couple with the master demo code named "I2C_Master_Bulk_Polling_TxRx".
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

    #if defined(SPD1179)
    /* Initial the I2C PIN */
    PIN_SetChannel(PIN_GPIO14, PIN_GPIO14_I2C_SCL);
    PIN_SetChannel(PIN_GPIO15, PIN_GPIO15_I2C_SDA);

    /*
    * Set Output Strength as 20mA, in case of many more
    * slaves are linking to the master.
    */
    PIN_SetOutStrength(PIN_GPIO14, PIN_OUT_STRENGTH_20MA);
    PIN_SetOutStrength(PIN_GPIO15, PIN_OUT_STRENGTH_20MA);
    #else
    /* Initial the I2C PIN */
    PIN_SetChannel(PIN_GPIO32, PIN_GPIO32_I2C_SCL);
    PIN_SetChannel(PIN_GPIO33, PIN_GPIO33_I2C_SDA);

    /*
    * Set Output Strength as 20mA, in case of many more
    * slaves are linking to the master.
    */
    PIN_SetOutStrength(PIN_GPIO32, PIN_OUT_STRENGTH_20MA);
    PIN_SetOutStrength(PIN_GPIO33, PIN_OUT_STRENGTH_20MA);
    #endif

    /* Disable All INT */
    I2C_DisableInt(I2C,I2C_INT_ALL);

    /* Enable the INT of detecting the STOP of I2C */
    I2C_EnableInt(I2C,I2C_INT_STOP_DETECT);

    /* Clear All INT */
    I2C_ClearInt(I2C, I2C_INT_ALL);

    /* Initial I2C as Slave and set the speed as 400K */
    estatus = I2C_SlaveInit(I2C, I2C_ADDR_7BIT, I2C_Slave_ADDR, I2C_SPEED);
    if(estatus == ERROR)
    {
        printf("[IIC slave initial FAIL] I2C clock is not fast enough to support the speed\n");
        return 0;
    }

    /* Enable MCU INT Request */
    NVIC_EnableIRQ(I2C_IRQn);
    
    /* Enable MCU INT Request */
    I2C_Enable(I2C);

    /* Enable I2C */
    I2C_Enable(I2C);

    /* Slave start to transmit and receive data */
    Slave_Bulk_TxRX_data(I2C);

    while(1)
    {

    }
}


void I2C_IRQHandler(void)
{
    if(I2C_GetIntFlag(I2C,I2C_INT_STOP_DETECT))
    {
        gu32_cnt_i2c_stop_isr ++ ;
        
        I2C_ClearInt(I2C, I2C_INT_STOP_DETECT|I2C_INT_GLOBAL);
    }
    else
    {
        printf("[%s Error] Stop detect interrupt error\n", __func__);
    }
}


/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
