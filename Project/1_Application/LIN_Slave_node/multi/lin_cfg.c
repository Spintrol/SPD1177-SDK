/******************************************************************************
 * @file     lin_cfg.c
 * @brief    Common LIN configuration, data structure
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


#include "lin_cfg.h"
#include "lin.h"
/* Mapping interface with hardware */
l_u8 lin_lld_response_buffer[10];
l_u8 lin_successful_transfer;
l_u8 lin_error_in_response;
l_u8 lin_goto_sleep_flg;
/* Save configuration flag */
l_u8 lin_save_configuration_flg = 0;
lin_word_status_str lin_word_status;
l_u8 lin_current_pid;

const l_signal_handle LI0_response_error_signal = LI0_FrontLeftDoorErrSig;

volatile l_u8 buffer_backup_data[8];

/* definition and initialization of signal array */
l_u8    lin_pFrameBuf[LIN_FRAME_BUF_SIZE] =
{


  0xf0 /* 0 : 11110000 */ /* start of frame LI0_FrontLeftDoorMessage */



  ,0x00 /* 1 : 00000000 */ /* start of frame LI0_MasterToFrontControl */

  ,0xff /* 2 : 11111111 */
  

  ,0xfe /* 3 : 11111110 */ /* start of frame LI0_FrontLeftDoorErrEvent */


  ,0xf0 /* 4 : 11110000 */ /* start of frame LI0_FrontToMasterMessage */


  ,0xc4 /* 5 : 11000100 */ /* start of frame LI0_FrontToMasterEventMessage */

  ,0xf0 /* 6 : 11110000 */
  
};

/* definition and initialization of signal array */
l_u8    lin_flag_handle_tbl[LIN_FLAG_BUF_SIZE] =
{


  0xFF /* 0: start of flag frame LI0_FrontLeftDoorMessage */



  ,0xFF /* 1: start of flag frame LI0_MasterToFrontControl */


  ,0xFF /* 2: start of flag frame LI0_FrontLeftDoorErrEvent */


  ,0xFF /* 3: start of flag frame LI0_FrontToMasterMessage */


  ,0xFF /* 4: start of flag frame LI0_FrontToMasterEventMessage */

};

/*************************** Flag set when signal is updated ******************/
/* Diagnostic signal */
l_u8 lin_diag_signal_tbl[16];
/*****************************event trigger frame*****************************/

const l_u8 LI0_ETF_MotorStates_info_data = LI0_FrontToMasterEventMessage ;  /* frame data */


/**********************************  Frame table **********************************/
const lin_frame_struct lin_frame_tbl[LIN_NUM_OF_FRMS] ={

    { LIN_FRM_UNCD, 1, LIN_RES_PUB, 0, 0, 1   , (l_u8*)0 }

   ,{ LIN_FRM_UNCD, 2, LIN_RES_SUB, 1, 1, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 1, LIN_RES_PUB, 3, 2, 1 , (l_u8*)&LI0_response_error_signal }
  
   ,{ LIN_FRM_UNCD, 1, LIN_RES_PUB, 4, 3, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_UNCD, 2, LIN_RES_PUB, 5, 4, 1 , (l_u8*)0 }
  
   ,{ LIN_FRM_EVNT, 2, LIN_RES_PUB, 0, 0, 0 , (l_u8*)&LI0_ETF_MotorStates_info_data }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_SUB, 0, 0, 0 , (l_u8*)0 }
  
   ,{ LIN_FRM_DIAG, 8, LIN_RES_PUB, 0, 0, 0 , (l_u8*)0 }
  
};

/*********************************** Frame flag Initialization **********************/
/*************************** Frame flag for send/receive successfully ***************/
l_bool lin_frame_flag_tbl[LIN_NUM_OF_FRMS] = {0, 0, 0, 0, 0, 0, 0, 0};
/*************************** Frame flag for updating signal in frame ****************/
volatile l_u8 lin_frame_updating_flag_tbl[LIN_NUM_OF_FRMS] = {0, 0, 0, 0, 0, 0, 0, 0};


/**************************** Lin configuration Initialization ***********************/

l_u8 lin_configuration_RAM[LIN_SIZE_OF_CFG]= {0x00, 0x01, 0x06, 0x03, 0x08, 0x04, 0x0B, 0x3C, 0x3D ,0xFF};

const l_u16  lin_configuration_ROM[LIN_SIZE_OF_CFG]= {0x00, 0x01, 0x06, 0x03, 0x08, 0x04, 0x0B, 0x3C, 0x3D ,0xFFFF};

/***************************************** Node Attribute*****************************************/

l_u8 lin_configured_NAD = 0x11;    /*<configured_NAD>*/
const l_u8 lin_initial_NAD    =0x11;    /*<initial_NAD>*/
const lin_product_id product_id = {0x0021, 0x0001, 0x0000 };  /* {<supplier_id>,<function_id>,<variant>} */
const l_signal_handle response_error =  LI0_FrontLeftDoorErrSig;
const l_u8 num_frame_have_esignal = 1;                                 /*number of frame contain error signal*/
const l_u16 lin_response_error_byte_offset[1] = {LIN_BYTE_OFFSET_LI0_FrontLeftDoorErrSig};                  /*<interface_name>_< response_error>*/
const l_u8 lin_response_error_bit_offset[1] = {LIN_BIT_OFFSET_LI0_FrontLeftDoorErrSig};                  /*<interface_name>_< response_error>*/


/************************** TL Layer and Diagnostic: SINGLE interface **************************/
/* QUEUE information */
lin_tl_pdu_data tl_tx_queue_data[MAX_QUEUE_SIZE];    /*transmit queue data */
lin_tl_pdu_data tl_rx_queue_data[MAX_QUEUE_SIZE];    /*receive queue data */

lin_transport_layer_queue lin_tl_tx_queue = {
0,                                                /* the first element of queue */
0,                                                /* the last element of queue */
LD_QUEUE_EMPTY,                                   /* status of queue */
0,                                                /* curernt size of queue */
MAX_QUEUE_SIZE,                                   /* size of queue */
tl_tx_queue_data,                                 /* data of queue */
};

lin_transport_layer_queue lin_tl_rx_queue = {
0,                                                /* the first element of queue */
0,                                                /* the last element of queue */
LD_QUEUE_EMPTY,                                   /* status of queue */
0,                                                /* curernt size of queue */
MAX_QUEUE_SIZE,                                   /* size of queue */
tl_rx_queue_data,                                 /* data of queue */
};
/* message information in transmit queue */
l_u16 tl_rx_msg_index;                                /* index of message in queue */
l_u16 tl_rx_msg_size;                                 /* Size of message in queue */
/* message information in receive queue */
l_u16 tl_tx_msg_index;                                /* index of message in queue */
l_u16 tl_tx_msg_size;                                 /* Size of message in queue */
lin_last_cfg_result tl_last_cfg_result;               /* Status of the last configuration service in LIN 2.0, J2602 */
l_u8 tl_last_RSID;                                    /* RSID of the last node configuration service */
l_u8 tl_ld_error_code;                                /* Error code in case of positive response */
l_u8 tl_no_of_pdu;                                    /* number of received pdu */
l_u8 tl_frame_counter;                                /* frame counter in received message */
lin_message_timeout_type tl_check_timeout_type;       /* timeout type */
l_u16 tl_check_timeout;                               /* timeout counter*/
l_u8 *tl_ident_data;                                  /* To store address of RAM area contain response */
lin_diagnostic_state tl_diag_state   =  LD_DIAG_IDLE;
lin_service_status tl_service_status =  LD_SERVICE_IDLE ; /* service status */
lin_message_status tl_receive_msg_status;             /* receive message status */
lin_message_status tl_rx_msg_status;                  /* cooked rx status */
lin_message_status tl_tx_msg_status;                  /* cooked tx status */










/****************************Support SID Initialization ***********************/

const l_u8 lin_diag_services_supported[_DIAG_NUMBER_OF_SERVICES_] = {0xB2,0x2E,0xB7,0xB0,0xB3,0xB6,0xB1,0x22};
l_u8 lin_diag_services_flag[_DIAG_NUMBER_OF_SERVICES_] = {0,0,0,0,0,0,0,0};

l_u8 tl_slaveresp_cnt = 0;
/*This ld_read_by_id_callout() function is used when the master node transmits a read by
 identifier request with an identifier in the user defined area (id from 32 to 63).
 The driver will call this function when such request is received.
 * id: the identifier in the user defined area (32 to 63)
 * data: pointer points to a data area with 5 bytes, used to give the positive response.
  Driver uses 0xFF "do not care value" for unassigned data values.
  Data length in PCI is (1 + number of assigned meaningful data values).
  Driver will take as data for all data before and including the last value in the frame that is different from 0xFF.
  PCI is 0x02-0x06, so data should have at least one value different from 0xFF.
  For example, a response frame, (NAD) (PCI) (0xF2) (0xFF) (0x00) (0xFF) (0xFF) (0xFF),
  PCI will be 0x03, since in this case driver takes all data before 0x00 and 0x00 as meaningful data,
  and values after 0x00 are do not care value.
 * return: LD_NEGATIVE_RESPONSE Respond with a negative response.
           LD_POSTIVE_RESPONSE Respond with a positive response.
           LD_ID_NO_RESPONSE The slave node will not answer.
 */
l_u8 ld_read_by_id_callout(l_u8 id, l_u8 *data)
{
    l_u8 retval = LD_NEGATIVE_RESPONSE;
    /* Following code is an example - Real implementation is application-dependent */
    /* This example implement with ID = 32 - LIN_READ_USR_DEF_MIN */
    if (id == LIN_READ_USR_DEF_MIN)
    {
      /* id received is user defined 32 */
      data[0] = (l_u8) (id + 1);    /* Data user define */
      data[1] = (l_u8) (id + 2);    /* Data user define */
      data[2] = (l_u8) (id + 3);    /* Data user define */
      data[3] = (l_u8) (id + 4);    /* Data user define */
      data[4] = (l_u8) (id + 5);    /* Data user define */
      retval = LD_POSITIVE_RESPONSE;
    }
    else
    {
      /* other identifiers, respond with negative response by default*/
    }
    return retval;
}

/******************* Copyright (C) 2022 Spintrol Electronic Technology (Shanghai) Co., Ltd. ***** END OF FILE ****/
