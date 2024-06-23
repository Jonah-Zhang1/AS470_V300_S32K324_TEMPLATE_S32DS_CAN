/*
*   (c) Copyright 2020 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"
#include "Platform.h"
#include "Can_43_FLEXCAN.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "CanIf.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "CDD_Uart.h"
#include "ARP_Transmit.h"
#include "Queue.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define LENGTH_CAN_SDU   (8U)

uint8 Can0_au8Sdu8bytes[LENGTH_CAN_SDU] = {0x01U, 0x02U, 0x03U, 0x04U, 0x05U, 0x06U, 0x07U, 0x08};
uint8 Can1_au8Sdu8bytes[LENGTH_CAN_SDU] = {0x11U, 0x22U, 0x33U, 0x44U, 0x55U, 0x66U, 0x7U, 0x88};
uint8 Uart_au8Sdu8bytes[LENGTH_CAN_SDU] = {0xaaU, 0xbbU, 0xccU, 0xddU, 0x55U, 0x66U, 0x7U, 0x88};
uint8 Uart_au8ReceiveData[LENGTH_CAN_SDU] = {0};

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
uint8 CanIf_u8TxConfirmCnt = 0U;
boolean CanIf_bTxFlag = FALSE;
uint8 CanIf_u8RxIndicationCnt = 0U;
boolean CanIf_bRxFlag = FALSE;
uint32 t1ms_clk = 0;

/************canIf_Transmit case hard fault**********************/
// PduInfoType TxPdu_Can0 ={
//    .SduDataPtr = Can0_au8Sdu8bytes,
//    .SduLength = sizeof(Can0_au8Sdu8bytes)
//};
//
// PduInfoType TxPdu_Can1 ={
//    .SduDataPtr = Can1_au8Sdu8bytes,
//    .SduLength = sizeof(Can1_au8Sdu8bytes)
//};
/*********************************************************************/
void Can_DummyDelay(uint32 loops);

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/



void Task_1ms(void)
{
    t1ms_clk++;
}

/*1ms Interrupt*/    
void Gpt_Stm0_Notification(void)
{
//    Task_1ms();
}

void Gpt_Pit0_Notification(void)
{
	Task_1ms();
}

void Task_100ms(void)
{
    PduInfoType TxPdu_Can0 ={
        Can0_au8Sdu8bytes,
    	sizeof(Can0_au8Sdu8bytes)
    };

    PduInfoType TxPdu_Can1 ={
        Can1_au8Sdu8bytes,
        sizeof(Can1_au8Sdu8bytes)
    };
		Dio_FlipChannel(DioConf_DioChannel_DioChannel_PTA30_LED2_GREEN);

		//Can_DummyDelay(0xfff);
//		Dio_WriteChannel(DioConf_DioChannel_DioChannel_PTA29_LED1_BLUE, STD_LOW);
//		Dio_WriteChannel(DioConf_DioChannel_DioChannel_PTA30_LED2_GREEN, STD_LOW);
		//Can_DummyDelay(0xfff);

		/*the code below cause: hardfault*/
       CanIf_Transmit(CanIfTxPduCfg_0, &TxPdu_Can0);
       CanIf_Transmit(CanIfTxPduCfg_1, &TxPdu_Can1);
}

void Task_10ms(void)
{
    User_UartTask();
    Eth_43_GMAC_MainFunction();
}

void Task_1000ms(void)
{
	Dio_FlipChannel(DioConf_DioChannel_DioChannel_PTA29_LED1_BLUE);
	Dio_FlipChannel(DioConf_DioChannel_DioChannel_PTA30_LED2_GREEN);
}


void TaskSchedule(void)
{

    if(t1ms_clk % 1000 == 0)
    {
    	Task_1000ms();
    }

//    if(t1ms_clk % 100 == 0 )
//    {
//        Task_100ms();
//    }
//
//    if(t1ms_clk % 10 == 0)
//    {
//    	 Task_10ms();
//    }
//    else
//    {
//
//    }
}

boolean CanLPduReceiveCallout(uint8 Hrh, Can_IdType CanId, uint8 CanDataLegth, const uint8* CanSduPtr)
{

    static unsigned int high = 0;
    //User_UartPrintString("CanLPduReceive_Callout!\r\n");
    if(high <= 10)
    {
    	high ++;
    	Dio_WriteChannel(DioConf_DioChannel_DioChannel_PTB18_LED4_YELLOW, STD_HIGH);
    }
    else if((high > 10) && (high <= 20))
    {
    	high ++;
    	Dio_WriteChannel(DioConf_DioChannel_DioChannel_PTB18_LED4_YELLOW, STD_LOW);
    }
    else
    {

    	high = 0;
    }
    return true;
}

extern UartTransmitEventState uartTxEvent;
extern UartReceiveEventState uartRxEvent;


void LPUART_CallBack(uint8 Channel, Uart_EventType Event)
{
    if(UART_EVENT_RX_FULL == Event)
    {        
        uartRxEvent = UART_RECEIVE_EVENT_COMPLETED;
    }
    else if(UART_EVENT_TX_EMPTY == Event)
    {
    	//uartTxEvent = UART_TRANSMIT_EVENT_COMPLETED;
    }
    else if(UART_EVENT_END_TRANSFER == Event)
	{
          uartTxEvent = UART_TRANSMIT_EVENT_COMPLETED;
	}
    else if(UART_EVENT_ERROR == Event)
	{

	}
    else
    {

    }
}
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void CanIf_ControllerBusOff(uint8 ControllerId)
{
    (void)ControllerId;
}

void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode )
{
    (void)ControllerId;
    (void)ControllerMode;
}


void Can_DummyDelay(uint32 loops)
{
    VAR( volatile uint32, CAN_VAR) data = 0xAA55AA55;
    VAR( volatile uint32, CAN_VAR) contor1 = 0;
    VAR( volatile uint32, CAN_VAR) contor2 = loops;

    do
    {
        for (contor1 = 0; contor1 < 0x2FF; contor1++)
        {
            data ^= (1 << contor1) | (0xAAAAAA | contor2);
        }
        contor2--;
    } while( contor2 > 0);
}

Can_PduType Can_CreatePduInfo(Can_IdType id, PduIdType swPduHandle, uint8 length, uint8* sdu)
{
    Can_PduType PduInfo;

    PduInfo.id = id;
    PduInfo.swPduHandle = swPduHandle;
    PduInfo.length = length;
    PduInfo.sdu = sdu;

    return PduInfo;
}

int main(void)
{
    uint8 u8TimeOut = 100U;
    CanIf_bTxFlag = FALSE;
    CanIf_bRxFlag = FALSE;
    volatile uint8 Eth_ModeChg = 0;
    
    /***Port_Init() need before Mcu_Init(), otherwise Ethernet cannot run normally****/
    Port_Init(NULL_PTR);

    /* Initialize the Mcu driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config_VS_0);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */
    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuConf_McuModeSettingConf_McuModeSettingConf_0);

#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();
#endif

    Mcu_SetMode(McuModeSettingConf_0);

    //Port_Init(NULL_PTR);

    /*platform need to to be initialed after MCU Module     20240527*/

    /* Initialize Platform driver */
    Platform_Init(NULL_PTR);/*platform need to to be initialed after MCU Module*/

    /* Initilize Can driver */
#if (CAN_43_FLEXCAN_PRECOMPILE_SUPPORT == STD_ON)
    Can_43_FLEXCAN_Init(NULL_PTR);
#else
    Can_43_FLEXCAN_Init(&Can_43_FLEXCAN_Config);
    
#endif
    /*The API to be called for this is Gpt_Init()
    MCU module shall be initialized before GPT is initialized.*/

    Gpt_Init(NULL_PTR);
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0, 40000);//the last pram is how many ticks before timeout
    //Frequence is 40MHz, so One tick is 0.025us, 40000~1ms    400000~10ms     40000000~1s
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_PIT0);

    /**STM0 can not run normally*/
    Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_STM0, 1000);
    Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_STM0);

    CanIf_Init(NULL_PTR);

    Uart_Init(NULL_PTR);
    User_UartInit();

    Ethernet_Init();


    Can_43_FLEXCAN_SetControllerMode(CanController_0, CAN_CS_STARTED);
    Can_43_FLEXCAN_SetControllerMode(CanController_1, CAN_CS_STARTED);

    /* Can_CreatePduInfo(id, swPduHandle,length, sdu) */
//    static Can_PduType Can0_PduInfo, Can1_PduInfo;
//    Can0_PduInfo = Can_CreatePduInfo(0U, 0U, 8U, Can0_au8Sdu8bytes);
//    Can1_PduInfo = Can_CreatePduInfo(0U, 0U, 8U, Can1_au8Sdu8bytes);
//    Can_43_FLEXCAN_Write(CanHardwareObject_3, &Can1_PduInfo);//CAN1 Transmit
//    Can_43_FLEXCAN_Write(CanHardwareObject_2, &Can0_PduInfo);//CAN0 Transmit

	while(true)
	{
       TaskSchedule();
       //User_UartPrintString("Hello World!\r\n");//success to User_UartPrintString Hello world!
	}

    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
