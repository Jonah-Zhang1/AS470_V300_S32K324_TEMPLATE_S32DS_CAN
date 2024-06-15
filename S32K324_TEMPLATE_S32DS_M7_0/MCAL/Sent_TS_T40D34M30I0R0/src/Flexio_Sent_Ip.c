/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO_SENT_IP
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
*   Copyright 2020 - 2023 NXP Semiconductors NXP.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Flexio_Sent_Ip.h"
#include "Flexio_Sent_Ip_Irq.h"

#ifdef FEATURE_FLEXIO_DEV_ERROR_DETECT
    #if (STD_ON == FEATURE_FLEXIO_DEV_ERROR_DETECT)
        #include "Devassert.h"
    #endif
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_SENT_IP_VENDOR_ID_C                      43
#define FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_SENT_IP_SW_MAJOR_VERSION_C               3
#define FLEXIO_SENT_IP_SW_MINOR_VERSION_C               0
#define FLEXIO_SENT_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Flexio_Sent_Ip header file are of the same vendor */
#if (FLEXIO_SENT_IP_VENDOR_ID_C != FLEXIO_SENT_IP_VENDOR_ID)
    #error "Flexio_Sent_Ip.c and Flexio_Sent_Ip.h have different vendor IDs"
#endif
/* Check if current file and Flexio_Sent_Ip header file are of the same Autosar version */
#if ((FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION_C     != FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION) || \
       (FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION_C     != FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION) || \
       (FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION_C  != FLEXIO_SENT_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "Flexio_Sent_Ip.c and Flexio_Sent_Ip.h have different vendor IDs"
#endif
/* Check if current file and Flexio_Sent_Ip header file are of the same Software version */
#if ((FLEXIO_SENT_IP_SW_MAJOR_VERSION_C != FLEXIO_SENT_IP_SW_MAJOR_VERSION) || \
      (FLEXIO_SENT_IP_SW_MINOR_VERSION_C != FLEXIO_SENT_IP_SW_MINOR_VERSION) || \
      (FLEXIO_SENT_IP_SW_PATCH_VERSION_C != FLEXIO_SENT_IP_SW_PATCH_VERSION)    \
    )
    #error "Flexio_Sent_Ip.c and Flexio_Sent_Ip.h have different vendor IDs"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef FEATURE_FLEXIO_DEV_ERROR_DETECT
        #if (STD_ON == FEATURE_FLEXIO_DEV_ERROR_DETECT)    
        
            /* Check if current file and Devassert.h header file are of the same Autosar version */
            #if ((FLEXIO_SENT_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
                (FLEXIO_SENT_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION) \
                )
                #error "AutoSar Version Numbers of Flexio_Sent_Ip.h and Devassert.h are different"
            #endif
        #endif /* (STD_ON == FEATURE_FLEXIO_DEV_ERROR_DETECT) */
    #endif
#endif
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#define FLEXIO_SENT_IP_TIMER_QUEUE_SIZE   ((uint16)100U)
/*==================================================================================================
                                  VARIABLE DECLARATIONS
==================================================================================================*/
#define SENT_START_SEC_CONST_UNSPECIFIED
#include "Sent_MemMap.h"
/* Table of base addresses for FLEXIO instances. */
static FLEXIO_Type * const Flexio_Sent_Ip_apxBase[FEATURE_FLEXIO_INSTANCE_COUNT] = IP_FLEXIO_BASE_PTRS;

#define SENT_STOP_SEC_CONST_UNSPECIFIED
#include "Sent_MemMap.h"

#define SENT_START_SEC_VAR_INIT_UNSPECIFIED
#include "Sent_MemMap.h"

/* Pointer to runtime state structure.*/
Flexio_Sent_Ip_StateType *Flexio_Sent_Ip_apxStatePtr[FEATURE_FLEXIO_INSTANCE_COUNT] = {NULL_PTR};

#define SENT_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Sent_MemMap.h"

#define SENT_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Sent_MemMap.h"

/* Pointer to Nibble data for Fast message */
static Flexio_DataProcessType   Flexio_Sent_Ip_axFastData[FEATURE_FLEXIO_INSTANCE_COUNT][FEATURE_FLEXIO_CHANNEL_COUNT];

static uint16 Flexio_Sent_Ip_au16TimerBuffer[FEATURE_FLEXIO_CHANNEL_COUNT][256];

#ifdef FXIO_ISR_PROCESS_TIMER_CTRL0
static uint8  Flexio_Sent_Ip_au8TimerIdx[FEATURE_FLEXIO_CHANNEL_COUNT];
static uint16  Flexio_Sent_Ip_u16TimerQueueIndex;
#endif


static uint8  Flexio_Sent_Ip_au8TimerQueue[FLEXIO_SENT_IP_TIMER_QUEUE_SIZE];




#define SENT_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
#include "Sent_MemMap.h"


#define SENT_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sent_MemMap.h"

Flexio_Sent_Ip_StateType Flexio_Sent_Ip_axStateStructure[FEATURE_FLEXIO_INSTANCE_COUNT];

#define SENT_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Sent_MemMap.h"

#define SENT_START_SEC_VAR_CLEARED_32
#include "Sent_MemMap.h"

static uint32 Flexio_Sent_Ip_au32CalibrationPulseWith[FEATURE_FLEXIO_CHANNEL_COUNT];

#define SENT_STOP_SEC_VAR_CLEARED_32
#include "Sent_MemMap.h"

#define SENT_START_SEC_VAR_CLEARED_8
#include "Sent_MemMap.h"

static uint8 Flexio_Sent_Ip_u32CalibrationPulseWithErrorCount[FEATURE_FLEXIO_CHANNEL_COUNT];

#define SENT_STOP_SEC_VAR_CLEARED_8
#include "Sent_MemMap.h"

#if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
#define SENT_START_SEC_VAR_CLEARED_BOOLEAN
#include "Sent_MemMap.h"

static boolean Flexio_Sent_Ip_abFirstHalfDmaBuffer[FEATURE_FLEXIO_INSTANCE_COUNT][FEATURE_FLEXIO_CHANNEL_COUNT];

#define SENT_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Sent_MemMap.h"
#endif
/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/
#define SENT_START_SEC_CODE
#include "Sent_MemMap.h"

static void Flexio_Drv_InitDevice(uint32 Instance, uint8 ResourceConfig);

static void Flexio_Drv_ResourcesInit(uint32 Instance, const Flexio_CtrlConfigType * Config);

static void Flexio_Sent_Ip_Configure(uint8 Instance, uint8 ResourceConfig, const Flexio_Sent_Ip_StateType *Receiver);

static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetFastMsgFromRaw(uint32 RawMsg, uint16 Tick, uint8 *NibbleVal);

static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_CrcEnhanced64Check(uint32 bit2Val, uint32 bit3Val, uint8 Crc);

static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_ProcessSerialMsg(Flexio_DataProcessType *Data);

static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_StartTransfer(uint8 NibbleNum,
                                                              uint32 TickLengthUs,
                                                              Flexio_DataProcessType *Data,
                                                              Flexio_Sent_FastMsgType *SentFastFrame);

static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetSerialMsgFromRaw(Sent_StatusCRCImplementType CrcType,
                                                                    Flexio_DataProcessType    *Data, 
                                                                    Flexio_Sent_SerialMsgType *SentSerialFrame);
                                                                    
static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_FastShortCrcCheck(boolean StatusNibbleCrcCal, 
                                                                  Sent_StatusCRCImplementType CrcType,
                                                                  uint8 NumberOfNibbles,
                                                                  const uint8 *SentRxFrame);

static Flexio_Sent_Ip_StatusType Flexio_Drv_Allocate(uint32 Instance,
                                                     uint8 ResourceConfig,
                                                     Flexio_Sent_Ip_StateType * State);



#if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_InitDma(uint8 Instance,
                                                        uint8 ResourceConfig,
                                                        const Flexio_Sent_Ip_StateType *Receiver);
static void Flexio_Sent_Ip_DmaDataProcessing(const uint8 Instance,
                                             const uint8 ChannelId, 
                                             const uint32 DmaTimerVal);
#endif
static void Flexio_Sent_Ip_InitSerialBuffer(void);
static void Flexio_Sent_Ip_SerialNotiHandler(const uint8 Instance,
                                             const uint8 ChannelId,
                                             Flexio_Sent_Ip_StatusType CrcStatus,
                                             Flexio_Sent_SerialMsgType *SentSerialFrame);
static void Flexio_Sent_Ip_TimerQueueIndexHandler(uint16* TimerQueueIndex);
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/*
 * Function Name : Flexio_Drv_InitDevice
 * Description   : Initializes the FlexIO device
 * Implements    : Flexio_Drv_InitDevice_Activity
 */
static void Flexio_Drv_InitDevice(uint32 Instance, uint8 ResourceConfig)
{
    uint8 i = 0;
    uint8 j = 0;
    uint8 k = 0;
    
    /* Clear state structures array */
    for (i = (uint8)0U; i < ResourceConfig; i++)
    {
        /* Copy the value of the increment in another variable to prevent compiler warnings*/
        k = i;

        /* Clear Fast Data */
        Flexio_Sent_Ip_axFastData[Instance][i].DataIndx        = 0U;
        Flexio_Sent_Ip_axFastData[Instance][i].TimerVal       = 0U;
        Flexio_Sent_Ip_axFastData[Instance][i].FastState        = STATUS_SENT_FAST_IDLE;
        Flexio_Sent_Ip_axFastData[Instance][i].SerialState      = STATUS_SENT_SERIAL_IDLE;
        Flexio_Sent_Ip_axFastData[Instance][i].FastMsgCount    = 0U;
        Flexio_Sent_Ip_axFastData[Instance][i].TimerbufferIndx = 0U;

        for (j = 0U; (j < (SENT_MAX_NIBBLE_DATA + 2U)); j++)
        {   
            Flexio_Sent_Ip_axFastData[Instance][k].NibbleVal[j] = 0U;
        }
        for (j = 0U; (j < 18U); j++)
        {
            Flexio_Sent_Ip_axFastData[Instance][k].SerialData[j] = 0U;
        }
        for (j = 0U; (j < 255U); j++)
        {
            Flexio_Sent_Ip_au16TimerBuffer[k][j] = 0U;
        }
#ifdef FXIO_ISR_PROCESS_TIMER_CTRL0
        Flexio_Sent_Ip_au8TimerIdx[i] = 0U;
#endif
    }
}

/*
 * Function Name : Flexio_Drv_Allocate
 * Description   : Allocate timers and shifters for a new driver instance
*/
static Flexio_Sent_Ip_StatusType Flexio_Drv_Allocate(uint32 Instance, uint8 ResourceConfig, Flexio_Sent_Ip_StateType * State)
{
    uint8 ResourceAvailable;                   /* total number of resources */
    const FLEXIO_Type *BaseAddr;    /* base address of the FlexIO module */
    Flexio_Sent_Ip_StatusType Result;
    /* Find free resources for a new driver. Drivers may need one or two adjacent timers */
    BaseAddr = Flexio_Sent_Ip_apxBase[Instance];

    /* In the first time of driver initialization: size = 8 (Read PARAM & TIME mask register)*/
    ResourceAvailable = Flexio_Sent_Ip_GetTimerNum(BaseAddr);

    if(ResourceConfig <= ResourceAvailable)
    {
        State->ResourceAllocation = ResourceConfig;
        Result = STATUS_FLEXIO_SENT_IP_SUCCESS;
    }else
    {
        /* Flexio does not enough timer resource for required resource from SENT */
        Result = STATUS_FLEXIO_SENT_IP_ERROR;
    }
    return Result;
}



/*
 * Function Name : Flexio_Drv_ResourcesInit
 * Description   : Initializes the resources for the current driver
*/
static void Flexio_Drv_ResourcesInit(uint32 Instance, const Flexio_CtrlConfigType * Config)
{
    uint8 Resource;
    uint8 ChnlIdx;
    FLEXIO_Type *BaseAddr;

    BaseAddr = Flexio_Sent_Ip_apxBase[Instance];

    for(ChnlIdx = 0; ChnlIdx < Config->ChnlConfigured; ChnlIdx++)
    {
        Resource = Config->ChnlConfig[ChnlIdx]->ChannelHwOffset;
        /* Ensure all timers are disabled */
        Flexio_Sent_Ip_SetTimerMode(BaseAddr, Resource, FLEXIO_TIMER_MODE_DISABLED);
        /* Ensure all interrupts and DMA requests are disabled */
        Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, (uint8)(1U << Resource), FALSE);
#if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
        Flexio_Mcl_Ip_SetTimerDMARequest(BaseAddr, (uint8)(1U << Resource), FALSE);
#endif
        /* Clear any leftover flags */
        Flexio_Mcl_Ip_ClearTimerStatus(BaseAddr, Resource);
    }
}

/*
 * Function Name : FLEXIO_DRV_InitDriver
 * Description   : Initializes an instance of FlexIO driver
*/
static Flexio_Sent_Ip_StatusType FLEXIO_DRV_InitDriver(uint32 Instance,
                                                       const Flexio_CtrlConfigType * Config)
{
    Flexio_Sent_Ip_StatusType RetCode;

    /* allocate times for the driver */
    RetCode = Flexio_Drv_Allocate(Instance, Config->ChnlConfigured, Config->CtrlState);
    if (RetCode == STATUS_FLEXIO_SENT_IP_SUCCESS)
    {
        /* initialize the allocated resources */
        Flexio_Drv_ResourcesInit(Instance, Config);
    }

    return RetCode;
}


/*
 * Function Name: Flexio_Sent_Ip_Configure
 * Description  : Configure registers for functionality of SENT base on FLEXIO
*/
static void Flexio_Sent_Ip_Configure(uint8 Instance, uint8 ResourceConfig, const Flexio_Sent_Ip_StateType *Receiver)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource instance (timer) */
    uint8 FlexioPin;  
    uint8 ChnlIdx = 0;  
    Flexio_Sent_Ip_TimerConfig TempTimerConfig;
    Flexio_Sent_Ip_TimerControl TempTimerControl;
    
    BaseAddr = Flexio_Sent_Ip_apxBase[Instance];
    
    for(ChnlIdx = 0; ChnlIdx < ResourceConfig; ChnlIdx++)
    {
        /* Calculation of the base address and the resource Instance of the flexio */
        ResourceIndex = Receiver->ChnlCfg[ChnlIdx].Timer;
        FlexioPin = Receiver->ChnlCfg[ChnlIdx].Pin;

        TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_DISABLED;                         
        TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
        TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_TRG_EDGE;
        TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_TRG;
        TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
        TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_CLK_SHIFT_TMR;
        TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;
        
        /* Timer configuration for Input Capture Mode - needed for SENT */
        Flexio_Sent_Ip_SetTimerConfig(BaseAddr,
                                      SENT_TIMER(ResourceIndex),
                                      &TempTimerConfig);

        TempTimerControl.Trigger = (uint8)(FlexioPin << 1); /* to be modified to be changed by user config */
        TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_HIGH;
        TempTimerControl.TriggerSource =FLEXIO_TRIGGER_SOURCE_INTERNAL;
        TempTimerControl.Pin = FlexioPin;
        TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
        TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
        TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;
        
        Flexio_Sent_Ip_SetTimerControl(BaseAddr,
                                       SENT_TIMER(ResourceIndex),
                                       &TempTimerControl);
    }
    /* Enable interrupt for timer  */
    if(FLEXIO_DRIVER_TYPE_INTERRUPTS == Receiver->DriverType)
    {
        for(ChnlIdx = 0; ChnlIdx < ResourceConfig; ChnlIdx++)
        {
            ResourceIndex = Receiver->ChnlCfg[ChnlIdx].Timer;
            Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, (uint8)1 << ResourceIndex , TRUE);
        }
    }
    /* Enable DMA for timer  */
    else if(FLEXIO_DRIVER_TYPE_DMA == Receiver->DriverType)
    {
        for(ChnlIdx = 0; ChnlIdx < ResourceConfig; ChnlIdx++)
        {
            ResourceIndex = Receiver->ChnlCfg[ChnlIdx].Timer;
#if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
            Flexio_Mcl_Ip_SetTimerDMARequest(BaseAddr, (uint8)1 << ResourceIndex , TRUE);
#endif
        }
    }
    else
    {
        /* Do nothing */
    }
    
}

/*
 * Function Name : Flexio_Sent_Ip_GetSerialMsgFromRaw
 * Description   : extract the serial message data from the raw data
 * Implements : Flexio_Sent_Ip_GetSerialMsgFromRaw
*/
static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetSerialMsgFromRaw(Sent_StatusCRCImplementType CrcType,
                                                                    Flexio_DataProcessType    *Data, 
                                                                    Flexio_Sent_SerialMsgType *SentSerialFrame)
{
    uint32 Bit2Val  = 0U;
    uint32 Bit3Val  = 0U;
    uint8 MsgId = 0U;
    uint8 Crc = 0U;
    uint16 MsgData = 0U;
    uint8 i = 0U;
    Flexio_Sent_Ip_StatusType Result = STATUS_FLEXIO_SENT_IP_ERROR;

    switch(Data->SerialState)
    {
        case STATUS_SENT_SERIAL_SHORT:
            /* Short message */
            for(i = 0U; i < 16U; i++)
            {
                Bit2Val = (SENT_GET_BIT2(Data->SerialData[i], Bit2Val));
            }
            SentSerialFrame->MsgType = SENT_SHORT_SERIAL;
            MsgId = (uint8)SENT_SHORT_MSGID(Bit2Val);
            MsgData = (uint16)SENT_SHORT_DATA(Bit2Val);
            Crc = (uint8)SENT_SHORT_CRC(Bit2Val);

            /* Create Nibble data for CRC checking */
            Data->NibbleVal[0] = 0;
            /* The CRC checksum is derived for the Message ID and Data Byte */
            Data->NibbleVal[1] = MsgId;
            Data->NibbleVal[2] = (uint8)((uint16)(MsgData & (uint16)0xF0) >> (uint16)4U);
            Data->NibbleVal[3] = (uint8)(MsgData & (uint16)0x0F);
            Data->NibbleVal[4] = Crc;
            /* CRC 4 bit checking */
            Result = Flexio_Sent_Ip_FastShortCrcCheck(FALSE, CrcType, (uint8)3U, Data->NibbleVal);
            (void)Bit3Val;
            break;
        case STATUS_SENT_SERIAL_ENHANCED:
            /* Get all #BIT2 and #BIT3 from status bit - aSerialData */
            for(i = 0U; i < 18U; i++)
            {
                Bit2Val = (SENT_GET_BIT2(Data->SerialData[i], Bit2Val));
                Bit3Val = (SENT_GET_BIT3(Data->SerialData[i], Bit3Val));
            }
            /* Check configuration bit */
            if(1U == SENT_ENHANCED_BIT_CONF(Bit3Val))
            {
                 /* BIT_CONF=1: Enhanced 16 bit data + 4 bit ID */
                SentSerialFrame->MsgType = SENT_ENHANCED_SERIAL_4_ID;
                MsgId = (uint8)SENT_ENHANCED4_MSGID(Bit3Val);
                MsgData = (uint16)SENT_ENHANCED4_DATA(Bit3Val, Bit2Val);
                Crc = (uint8)SENT_ENHANCED4_CRC(Bit2Val);
            }else
            {
                /* BIT_CONF=0: Enhanced 12 bit data + 8 bit ID */
                SentSerialFrame->MsgType = SENT_ENHANCED_SERIAL_8_ID;
                MsgId = (uint8)(SENT_ENHANCED8_MSGID(Bit3Val));
                MsgData = (uint16)SENT_ENHANCED8_DATA(Bit2Val);
                Crc = (uint8)SENT_ENHANCED8_CRC(Bit2Val);
            }
            /* CRC 6 bit checking */
            Result = Flexio_Sent_Ip_CrcEnhanced64Check(Bit2Val, Bit3Val, Crc);
            (void)CrcType;
            break;
        case STATUS_SENT_SERIAL_IDLE:
            /* do nothing */
            break;
        default :
#if (FEATURE_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
            /* Should not get here */
#endif
            break;
    }
    SentSerialFrame->MessageId = MsgId;
    SentSerialFrame->MessageData = MsgData;
    SentSerialFrame->SerialCrc = Crc;
    
    return Result;
}

/*
 * Function Name : Flexio_Sent_Ip_GetFastMsgFromRaw
 * Description   : extract the fast message data from the pulse width of the signal
 * Implements : Flexio_Sent_Ip_GetFastMsgFromRaw
*/
static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetFastMsgFromRaw(uint32 RawMsg, uint16 Tick, uint8 *NibbleVal)
{
    uint16  Val;
    uint16  Val_Int;
    uint16  Val_Surplus;
    uint8   i;
    Flexio_Sent_Ip_StatusType Result; 

    /* This value need to multiply with 10 in oder to prevent float value */
    Val = (uint16)(RawMsg*10U/Tick);
    /**
    * val value need to be rounded
    * For example, we get the value 11,8 and the expected value is 12.
    * About the algorithm:
    * with x<y.5, x equals y.
    * with x>=y.5, x equals y+1.
    */
    for(i = 11U; i<28U; i++)
    {
        Val_Int = (uint16)(Val / ((uint16)i*10U));
        Val_Surplus = (uint16)(Val % ((uint16)i*10U));
        if((Val_Int == 1U) && (Val_Surplus < 10U))
        {
            if(Val_Surplus < 5U)
            {
                Val = i;
            }
            else
            {
                Val = ((uint16)i+1U);
            }
            break;
        }
        else
        {
            /* Do nothing */
        }
        
    }
    /* Minimum nibble pulse period (transmission value of 0) = 12 clock ticks  */
    /* Maximum nibble pulse period (transmission value of 15) = 12 + 15 = 27 clock ticks  */
    
#ifdef MCAL_ENABLE_FAULT_INJECTION
    /* Error injection point to check in case the measured nibble data value is <0 or >15 */
    MCAL_FAULT_INJECTION_POINT(SENT_FIP_1_CHANGE_NIBBLE_DATA_VALUE);
#endif

    if((Val >= 12U) && (Val <= 27U))
    {
        *NibbleVal = (uint8)(Val-12U);
        Result = STATUS_FLEXIO_SENT_IP_SUCCESS;
    }else
    {
        Result = STATUS_FLEXIO_SENT_IP_ERROR;
    }
    return Result;
}

/* FUNCTION ********************************************************************
 * Function Name : Flexio_Sent_Ip_CrcEnhanced64Check
 * Description   : Implementation Example for Enhanced Serial Message Format CRC
 * END ************************************************************************/

static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_CrcEnhanced64Check(uint32 bit2Val, uint32 bit3Val, uint8 Crc)
{
    static const uint8 CRC_6bit[64] = {0,  25, 50, 43, 61, 36, 15, 22, 35, 58, 17, 8,  30, 7,  44, 53, 
                                 31, 6,  45, 52, 34, 59, 16, 9,  60, 37, 14, 23, 1,  24, 51, 42, 
                                 62, 39, 12, 21, 3,  26, 49, 40, 29, 4,  47, 54, 32, 57, 18, 11, 
                                 33, 56, 19, 10, 28, 5,  46, 55, 2,  27, 48, 41, 63, 38, 13, 20};
    uint8 Crc64;
    uint8 i;
    Flexio_Sent_Ip_StatusType Result;
    /* 6-bit groups */
    uint8 Data[4] = {0, 0, 0, 0};
    /* The CRC checksum can be implemented via a bit-wise exclusive OR with a 64 array lookup. The checksum is determined */
    /* by reading-in 6-bit groups (in decimal representation) of the 24-bit message data in sequence, and then checksumming the */
    /* result with an extra zero value (augmentation by six 0-bits).) */
    /* CRC table for poly = 0x59 (x^6+x^4+x^3+1) */
    Crc64 = 21;

    /* Create 6-bit group from bit2Val and bit3Val */
    for(i = 0; i< 12U; i++)
    {
        Data[i/3U] = (Data[i/3U] << 1) | (uint8)(SET_GET_BIT24(bit2Val, i));
        Data[i/3U] = (Data[i/3U] << 1) | (uint8)(SET_GET_BIT24(bit3Val, i)); 
    }
    /* Initialize checksum */
    for(i=0; i< 4U; i++)  /* Repeat for end of Data Nibbles */
    {
        Crc64 = SENT_BITXOR(Data[i], CRC_6bit[Crc64]);
    }
    Crc64 = SENT_BITXOR(0, CRC_6bit[Crc64]);

    if(Crc == Crc64)
    {
        Result = STATUS_FLEXIO_SENT_IP_CRCPASSED;
    }
    else
    {
        Result = STATUS_FLEXIO_SENT_IP_CRCFAILED;
    }
    return Result;
}

/* FUNCTION ********************************************************************
 * Function Name : Flexio_Sent_Ip_FastShortCrcCheck
 * Description   : The CRC is calculated using polynomial x^4 + x^3 + x^2 + 1 with seed value of 0101
 *                 To calculate CRC for SENT frame following by 3 types of Implementation:
 *                 - Implementation using 16 Element Array.
 *                 - Implementation using 256 Element Array.
 *                 - Legacy Implementation.
 *                 The Checksum nibble is a 4 bit CRC of the Data nibbles only.
 *                 The Status and Communication Nibble is not included in the CRC calculation
 * END ************************************************************************/
static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_FastShortCrcCheck(boolean StatusNibbleCrcCal, Sent_StatusCRCImplementType CrcType, uint8 NumberOfNibbles, const uint8 *SentRxFrame)
{
#if(STD_ON == FLEXIO_SENT_IP_CRC_256_ELEMENT_ARRAY_SUPPORTING)
    /* 256 Element Array */
    static const uint8 CRC256_4bit[256] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                                    13, 12, 15, 14, 9, 8, 11, 10, 5, 4, 7, 6, 1, 0, 3, 2,
                                    7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8,
                                    10, 11, 8, 9, 14, 15, 12, 13, 2, 3, 0, 1, 6, 7, 4, 5,
                                    14, 15, 12, 13, 10, 11, 8, 9, 6, 7, 4, 5, 2, 3, 0, 1,
                                    3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12,
                                    9, 8, 11, 10, 13, 12, 15, 14, 1, 0, 3, 2, 5, 4, 7, 6,
                                    4, 5, 6, 7, 0, 1, 2, 3, 12, 13, 14, 15, 8, 9, 10, 11,
                                    1, 0, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 13, 12, 15, 14,
                                    12, 13, 14, 15, 8, 9, 10, 11, 4, 5, 6, 7, 0, 1, 2, 3,
                                    6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9,
                                    11, 10, 9, 8, 15, 14, 13, 12, 3, 2, 1, 0, 7, 6, 5, 4,
                                    15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0,
                                    2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9, 14, 15, 12, 13,
                                    8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7,
                                    5, 4, 7, 6, 1, 0, 3, 2, 13, 12, 15, 14, 9, 8, 11, 10};
#endif
    /* 16 Element Array */
    static const uint8 CRC16_4bit[16]  = {0, 13, 7, 10, 14, 3, 9, 4, 1, 12, 6, 11, 15, 2, 8, 5};
    Flexio_Sent_Ip_StatusType Result;
    uint8 Crc;
    uint8 i;
    uint8 StartIndex = StatusNibbleCrcCal ? (uint8)0U : (uint8)1U;

    Crc = 5;   /* SEED_4BIT */
    switch(CrcType)
    {
#if(STD_ON == FLEXIO_SENT_IP_CRC_256_ELEMENT_ARRAY_SUPPORTING)
        /** 
        * SENT_Rx_Frame[DataIndx = 0]=Status & Communication
        * SENT_Rx_Frame[DataIndx = 1]=1st nibble, ... 
        * SENT_Rx_Frame[DataIndx = NIBBLE]=NIBBLEth nibble
        * SENT_Rx_Frame[DataIndx = NIBBLE+1]=CRC 
        * The Checksum nibble is a 4 bit CRC of the Data nibbles only.
        * The Status and Communication Nibble is not included in the CRC calculation.
        */
        case SENT_RECOMMENDED_IMPLEMENTATION_256_ELEMENT:
            /** 
             *  The CRC checksum can be implemented as a series of shift left by 4 (multiply by 16) 
             *  followed by a 256 element array lookup. The checksum is determined by using all
             *  data nibbles in sequence and then checksumming the result with an extra zero value.
             */
            /* Initialize checksum */
            for(i = StartIndex; i<(NumberOfNibbles+1U); i++)  /* Repeat for end of Data Nibbles */
            {
                Crc = CRC256_4bit[(Crc << 4) + SentRxFrame[i]];
            }
            Crc = CRC256_4bit[(Crc << 4)];
            break;

        case SENT_LEGACY_IMPLEMENTATION_256_ELEMENT:
            /**
            *  The CRC checksum can be implemented as a series of shift left by 4 (multiply by 16)
            *  followed by a 256 array lookup
            */   
            /* Initialize checksum */
            for(i = StartIndex; i < (NumberOfNibbles + 1U); i++)  /* Repeat for end of Data Nibbles */
            {
                Crc = CRC256_4bit[(Crc << 4) + SentRxFrame[i]];
            }
            break;
            
#endif
        case SENT_RECOMMENDED_IMPLEMENTATION_16_ELEMENT:
            /** 
             *  The CRC checksum can be implemented as a series of shift left by 4 (multiply by 16) 
             *  followed by a 16 element array lookup. The checksum is determined by using all
             *  data nibbles in sequence and then checksumming the result with an extra zero value.
             */
            /* Initialize checksum */
            for(i = StartIndex; i<(NumberOfNibbles+1U); i++)  /* Repeat for end of Data Nibbles */
            {
                Crc = SENT_BITXOR(SentRxFrame[i], CRC16_4bit[Crc]);
            }
            Crc = SENT_BITXOR(0, CRC16_4bit[Crc]);
            break;
            
        case SENT_LEGACY_IMPLEMENTATION_16_ELEMENT:
            /** 
             *  The CRC checksum can be implemented as a series of shift left by 4 (multiply by 16) 
             *  followed by a 16 element array lookup. The checksum is determined by using all
             *  data nibbles in sequence.
             */
            /* Initialize checksum */
            for(i = StartIndex; i<(NumberOfNibbles+1U); i++)  /* Repeat for end of Data Nibbles */
            {
                Crc = SENT_BITXOR(SentRxFrame[i], CRC16_4bit[Crc]);
            }
            break;

        default:
#if (FEATURE_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
            /* Should not get here */
#endif
        break;
    }

    if(SentRxFrame[NumberOfNibbles+1U] == Crc)
    {
        Result = STATUS_FLEXIO_SENT_IP_CRCPASSED;
    }
    else
    {
        Result = STATUS_FLEXIO_SENT_IP_CRCFAILED;
    }
    return Result;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Sent_Ip_StartTransfer
 * Description   : Measure the PulseWidth of the signal received by the FLEXIO_SENT driver
 * Implements : Flexio_Sent_Ip_StartTransfer
 *
 *END**************************************************************************/

static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_StartTransfer(uint8 NibbleNum,
                                                              uint32 TickLengthUs,
                                                              Flexio_DataProcessType *Data,
                                                              Flexio_Sent_FastMsgType *SentFastFrame)
{
    static uint16 AdjustedTick[FEATURE_FLEXIO_CHANNEL_COUNT];
    static uint8 Nibble_Val[FEATURE_FLEXIO_CHANNEL_COUNT];
    uint8 DataIndx;
    uint32 PulseWidthTick;
    uint32 pulseWidthCnt;
    Flexio_Sent_Ip_StatusType Result = STATUS_FLEXIO_SENT_IP_ERROR;
    Flexio_Sent_Ip_StateType *Receiver;

    /** 
    * aNibbleVal[DataIndx = 0]=Status & Communication
    * aNibbleVal[DataIndx = 1]=1st nibble, ... 
    * aNibbleVal[DataIndx = NIBBLE]=NIBBLEth nibble
    * aNibbleVal[DataIndx = NIBBLE+1]=CRC 
    */
    DataIndx = Data->DataIndx;
    pulseWidthCnt = (Data->TimerVal*100U)/(uint8)FLEXIO_TIMER_FREQ_MHZ;
    Receiver = Flexio_Sent_Ip_apxStatePtr[SentFastFrame->Instance];
    
    switch(Data->FastState)
    {
        case STATUS_SENT_FAST_IDLE: /* Throw-out captured value until Calibration Pulse was found */
#if(STD_ON == FLEXIO_SENT_IP_EXPANDING_RANGE_MODE)
            PulseWidthTick = (pulseWidthCnt*10/(((uint32)TickLengthUs)));
#else
            PulseWidthTick = (pulseWidthCnt/(((uint32)TickLengthUs)*100U));
#endif
            /* Check tolerance pulse in accepted range = +-25% */
            if((PulseWidthTick >= SYNC_CAL_TICK_MIN) && (PulseWidthTick <=  SYNC_CAL_TICK_MAX ))
            {
                if(0U == Flexio_Sent_Ip_au32CalibrationPulseWith[SentFastFrame->ChannelId])
                {
                    /* Use calibration pulse length of first frame as validation value */
                    Flexio_Sent_Ip_au32CalibrationPulseWith[SentFastFrame->ChannelId] = Data->TimerVal;
                    /* Initial calibration successive error counter */
                    Flexio_Sent_Ip_u32CalibrationPulseWithErrorCount[SentFastFrame->ChannelId] = (uint8)0U;
                    AdjustedTick[SentFastFrame->ChannelId] = (uint16)((pulseWidthCnt)/(uint8)SYNC_CAL_TICK);
                    Data->FastState = STATUS_SENT_FAST_SYNC_CALIB; /* Checking done with Synchronization + Calibration */
                    Data->DataIndx = 0;    /* Ready for processing Status & Communication Data */
                    Receiver->TransferErrorDetect[SentFastFrame->ChannelId] = FALSE;
                    Result = STATUS_FLEXIO_SENT_IP_BUSY;
                }
                else
                {
                    /* Check calibration pulse with is defferent more than 1.5625% with validation value or not */
                    if(((Data->TimerVal * 200U) >= (197U* Flexio_Sent_Ip_au32CalibrationPulseWith[SentFastFrame->ChannelId])) &&
                    ((Data->TimerVal * 200U) <= (203U * Flexio_Sent_Ip_au32CalibrationPulseWith[SentFastFrame->ChannelId])))
                    {
                        AdjustedTick[SentFastFrame->ChannelId] = (uint16)((pulseWidthCnt)/(uint8)SYNC_CAL_TICK);
                        Data->FastState = STATUS_SENT_FAST_SYNC_CALIB; /* Checking done with Synchronization + Calibration */
                        Data->DataIndx = 0;    /* Ready for processing Status & Communication Data */
                        Receiver->TransferErrorDetect[SentFastFrame->ChannelId] = FALSE;
                        Flexio_Sent_Ip_u32CalibrationPulseWithErrorCount[SentFastFrame->ChannelId] = (uint8)0U;
                        Result = STATUS_FLEXIO_SENT_IP_BUSY;
                    }
                    else
                    {
                        Flexio_Sent_Ip_u32CalibrationPulseWithErrorCount[SentFastFrame->ChannelId]++;
                        /* Successive error notification */
                        if(NULL_PTR != Receiver->SentFastErrorNotif[SentFastFrame->ChannelId])
                        {
                            Receiver->SentFastErrorNotif[SentFastFrame->ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_SUCCESSIVE_CALIBRATION);
                        }
                        Receiver->TransferErrorDetect[SentFastFrame->ChannelId] = TRUE;
                        
                        if((uint8)3U <= Flexio_Sent_Ip_u32CalibrationPulseWithErrorCount[SentFastFrame->ChannelId])
                        {
                            
                            /* Resynchronization CalibrationPulseWith validation value if number of consecutive error is more than 3 */
                            Flexio_Sent_Ip_au32CalibrationPulseWith[SentFastFrame->ChannelId] = Data->TimerVal;
                            Flexio_Sent_Ip_u32CalibrationPulseWithErrorCount[SentFastFrame->ChannelId] = (uint8)0U;
                        }
                    }
                }
            }
            else if(FALSE == Receiver->TransferErrorDetect[SentFastFrame->ChannelId])
            {
                /* Nibble value error notification */
                if(NULL_PTR != Receiver->SentFastErrorNotif[SentFastFrame->ChannelId])
                {
                    Receiver->SentFastErrorNotif[SentFastFrame->ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_CALIBRATION_LENGTH);
                }
                Receiver->TransferErrorDetect[SentFastFrame->ChannelId] = TRUE;
            }
            else
            {
                /* Do nothing */
            }
            break;
        case STATUS_SENT_FAST_SYNC_CALIB: /* Calibration Pulse was found and calculate nibble value */
            /* nibble processing here */
            if(STATUS_FLEXIO_SENT_IP_SUCCESS == Flexio_Sent_Ip_GetFastMsgFromRaw(pulseWidthCnt, AdjustedTick[SentFastFrame->ChannelId], &Nibble_Val[SentFastFrame->ChannelId]))
            {
                Data->NibbleVal[DataIndx] = Nibble_Val[SentFastFrame->ChannelId];
                /* Check whether this nibble value is CRC: dataIndx = NUMBER_OF_NIBBLES + 2 */
                if(DataIndx == (uint8)(NibbleNum + 1U))
                {
                    /* Get Fast message data after check CRC successful */
                    /* 1. Status and Communication Nibble */
                    SentFastFrame->StatusCommunication = Data->NibbleVal[0];
                    /* 2. CRC and Checksum */
                    SentFastFrame->FastCrc = Data->NibbleVal[NibbleNum + 1U];
                    /* 3. Fast message Data */
                    for(DataIndx = 0; DataIndx < NibbleNum; DataIndx++)
                    {
                        SentFastFrame->DataNibble[DataIndx] = Data->NibbleVal[DataIndx+1U];
                    }
                    if(SENT_PAUSE_PULSE_DISABLED == Receiver->ChnlCfg[SentFastFrame->ChannelId].PausePulse)
                    {
                        Result = STATUS_FLEXIO_SENT_IP_SUCCESS;
                        Data->FastState = STATUS_SENT_FAST_CHECKED; /* CRC receiving is done */
                    }
                    else
                    {
                        Result = STATUS_FLEXIO_SENT_IP_BUSY;
                        Data->FastState = STATUS_SENT_FAST_PAUSE_PULSE; /* CRC receiving is done and next is pause pulse */
                    }
                }
                else
                {
                    Result = STATUS_FLEXIO_SENT_IP_BUSY;
                }
                Data->DataIndx++;
            }
            else
            {
                /* Nibble checking get error and jump out of the while loop */
                Result = STATUS_FLEXIO_SENT_IP_ERROR;
                /* Nibble value error notification */
                if(NULL_PTR != Receiver->SentFastErrorNotif[SentFastFrame->ChannelId])
                {
                    Receiver->SentFastErrorNotif[SentFastFrame->ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_NIBBLE_VALUE);
                }
                /* Jump out of the while loop */
                Data->FastState = STATUS_SENT_FAST_IDLE;
            }
            break;
        case STATUS_SENT_FAST_PAUSE_PULSE:
            {
                Result = STATUS_FLEXIO_SENT_IP_SUCCESS;
                /* Jump out of the while loop */
                Data->FastState = STATUS_SENT_FAST_CHECKED;
            }
            break;
        default:
            #if (FEATURE_FLEXIO_DEV_ERROR_DETECT == STD_ON)
                DevAssert(FALSE);
                /* Should not get here */
            #endif
            break;
    }
    
    return Result;
}

/*! @endcond*/


#if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
/**
*   @brief          This function initializes DMA
*/

static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_InitDma(uint8 Instance,
                                                        uint8 ResourceConfig,
                                                        const Flexio_Sent_Ip_StateType *Receiver)
{
    const FLEXIO_Type *BaseAddr;
    Dma_Ip_ReturnType EdmaStatus;
    uint8 ChnlIdx;
    Flexio_Sent_Ip_StatusType ReturnStatus = STATUS_FLEXIO_SENT_IP_SUCCESS;
    BaseAddr = Flexio_Sent_Ip_apxBase[Instance];

    for(ChnlIdx = 0; ChnlIdx < ResourceConfig; ChnlIdx++)
    {
        const Dma_Ip_LogicChannelTransferListType dmaChannelTransferListReceive[SENT_DMA_CHANNEL_CONFIG_LIST_SIZE] =
        {
            /* Source  configuration */ 
            {
                .Param = DMA_IP_CH_SET_SOURCE_ADDRESS, /* Dma_Ip_Set_Source_Address */
                .Value = (uint32) &(BaseAddr->TIMCMP[SENT_TIMER(Receiver->ChnlCfg[ChnlIdx].Timer)]), /* Address */
            },
            {
                .Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET, /* Dma_Ip_Set_Source_SignedOffset */
                .Value = 0,
            },
            {
                .Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE, /* Dma_Ip_Set_Source_TransferSize */
                .Value = DMA_IP_TRANSFER_SIZE_4_BYTE,
            },
            /* Destination configuration  */
            {
                .Param = DMA_IP_CH_SET_DESTINATION_ADDRESS, /* Dma_Ip_Set_Destination_Address */
                .Value = (uint32)Receiver->ChnlCfg[ChnlIdx].DmaTimerBuffer,
            }, /* ADRESA */
            {
                .Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET, /* Dma_Ip_Set_Destination_SignedOffset */
                .Value = 4U,
            },
            {
                .Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE, /* Dma_Ip_Set_Destination_TransferSize */
                .Value = DMA_IP_TRANSFER_SIZE_4_BYTE,
            },
            {
                .Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ,
                .Value = (uint32)(1U+(~(4U * ((uint32)Receiver->ChnlCfg[ChnlIdx].DmaBufferDepth * ((uint32)Receiver->ChnlCfg[ChnlIdx].NibbleCnt + (uint32)3U + (uint32)((Receiver->ChnlCfg[ChnlIdx].PausePulse == SENT_PAUSE_PULSE_DISABLED) ? 0U : 1U))* 2U) ))),
            },
            /* Minor/Major Loop config */
            {
                .Param = DMA_IP_CH_SET_MINORLOOP_SIZE,
                .Value = 4U,
            },
            {
                .Param = DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT,
                .Value = 1,
            },
            {
                .Param = DMA_IP_CH_SET_MAJORLOOP_COUNT, /* Dma_Ip_Set_MajorLoop_Count */
                .Value = (uint32)((uint32)Receiver->ChnlCfg[ChnlIdx].DmaBufferDepth*((uint32)Receiver->ChnlCfg[ChnlIdx].NibbleCnt + (uint32)3U + (uint32)((Receiver->ChnlCfg[ChnlIdx].PausePulse == SENT_PAUSE_PULSE_DISABLED)?0U:1U)) * 2U),
            },
            {
                .Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT, /* Dma_Ip_Set_Control_EnIntMajor */
                .Value = 1,
            },
            {
                .Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST,
                .Value = 0,
            },
        };

        EdmaStatus = Dma_Ip_SetLogicChannelTransferList(Receiver->ChnlCfg[ChnlIdx].SentDmaChannel, &dmaChannelTransferListReceive[0], SENT_DMA_CHANNEL_CONFIG_LIST_SIZE);
        if (EdmaStatus != DMA_IP_STATUS_SUCCESS)
        {
            ReturnStatus = STATUS_FLEXIO_SENT_IP_ERROR;
        }
        else
        {
            Flexio_Sent_Ip_abFirstHalfDmaBuffer[Instance][ChnlIdx] = TRUE;
        }
    }

    return ReturnStatus;
}
#endif /* (FEATURE_FLEXIO_DMA_ENABLE == STD_ON) */

/*******************************************************************************
 * API implementation
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Sent_Ip_Init
 * Description   : Initialize the FLEXIO_SENT master mode driver
 * Implements : Flexio_Sent_Ip_Init_Activity
 *
 *END**************************************************************************/
/* @implements      Flexio_Sent_Ip_Init_Activity */
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_Init(uint8 Instance, const Flexio_CtrlConfigType *Config)
{
    uint8 ChnlIdx = 0;
    Flexio_Sent_Ip_StatusType   Result;

    /* Initialize Flexio device */
    Flexio_Drv_InitDevice(Instance, Config->ChnlConfigured);
    /* Initialize the flexio driver */
    Result = FLEXIO_DRV_InitDriver(Instance, Config);
    /* Check if initialization failed, not enough resources*/
    if(STATUS_FLEXIO_SENT_IP_ERROR != Result)
    {
        /* Initialize the driver specific context strcture */
        Config->CtrlState->DriverType = Config->DriverType;
        for(ChnlIdx = 0; ChnlIdx < Config->ChnlConfigured; ChnlIdx++)
        {
            
            Config->CtrlState->TransferErrorDetect[ChnlIdx] = FALSE;
            Config->CtrlState->SentFastNotif[ChnlIdx]             = Config->ChnlConfig[ChnlIdx]->SentFastNotif;
            Config->CtrlState->SentSerialNotif[ChnlIdx]           = Config->ChnlConfig[ChnlIdx]->SentSerialNotif;
            Config->CtrlState->SentFastErrorNotif[ChnlIdx]          = Config->ChnlConfig[ChnlIdx]->SentFastErrorNotif;
            Config->CtrlState->SentSerialErrorNotif[ChnlIdx]        = Config->ChnlConfig[ChnlIdx]->SentSerialErrorNotif;
            Config->CtrlState->ChnlCfg[ChnlIdx].Timer             = Config->ChnlConfig[ChnlIdx]->ChannelHwOffset;
            Config->CtrlState->ChnlCfg[ChnlIdx].Pin               = Config->ChnlConfig[ChnlIdx]->SentPin;
            Config->CtrlState->ChnlCfg[ChnlIdx].NibbleCnt         = Config->ChnlConfig[ChnlIdx]->NumberOfNibbles;
            Config->CtrlState->ChnlCfg[ChnlIdx].TickLengthUs      = Config->ChnlConfig[ChnlIdx]->TickTime;
            Config->CtrlState->ChnlCfg[ChnlIdx].StatusNibbleCrcCalIncluding               = Config->ChnlConfig[ChnlIdx]->StatusNibbleCrcCalIncluding;
            Config->CtrlState->ChnlCfg[ChnlIdx].FastCrc               = Config->ChnlConfig[ChnlIdx]->SentFastCrcImpelement;
            Config->CtrlState->ChnlCfg[ChnlIdx].SlowCrc               = Config->ChnlConfig[ChnlIdx]->SentSlowCrcImpelement;
            Config->CtrlState->ChnlCfg[ChnlIdx].PausePulse        = Config->ChnlConfig[ChnlIdx]->PausePulse;
    #if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
            Config->CtrlState->ChnlCfg[ChnlIdx].SentDmaChannel    = Config->ChnlConfig[ChnlIdx]->SentDmaChannel;
            Config->CtrlState->ChnlCfg[ChnlIdx].DmaBufferDepth    = Config->ChnlConfig[ChnlIdx]->DmaBufferDepth;
            Config->CtrlState->ChnlCfg[ChnlIdx].DmaTimerBuffer    = Config->ChnlConfig[ChnlIdx]->DmaTimerBuffer;
    #endif
            Flexio_Sent_Ip_au32CalibrationPulseWith[ChnlIdx]      = 0U;
            Flexio_Sent_Ip_u32CalibrationPulseWithErrorCount[ChnlIdx]      = 0U;
        }

        /* Configure the device for SENT mode */
        Flexio_Sent_Ip_Configure(Instance, Config->ChnlConfigured, Config->CtrlState);
        
    #if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
        /* Configure DMA for SENT */
        Result = Flexio_Sent_Ip_InitDma(Instance, Config->ChnlConfigured, Config->CtrlState);
        
        /* Check if initialize DMA fail */
        if(STATUS_FLEXIO_SENT_IP_ERROR != Result)
        {
            /* Allocate controller state to the global variable state */
            Flexio_Sent_Ip_apxStatePtr[Instance] = Config->CtrlState;
        }
    #else
        /* Allocate controller state to the global variable state */
        Flexio_Sent_Ip_apxStatePtr[Instance] = Config->CtrlState;
    #endif
    }
    
    return Result;
}

/*FUNCTION**********************************************************************
 *
 * Function Name :  Flexio_Sent_Ip_Deinit
 * Description   :  De-initialize the FLEXIO_SENT driver
 * Implements :     Flexio_Sent_Ip_Deinit
 *
 *END**************************************************************************/
/* @implements      Flexio_Sent_Ip_DeInit_Activity */
void Flexio_Sent_Ip_DeInit(uint8 Instance)
{
    uint8 ChnlIdx;
    uint8 DataIdx;

#if (STD_ON == FEATURE_FLEXIO_DEV_ERROR_DETECT) /* to be implemented in the CDD_sent */ 
    DevAssert(Flexio_Sent_Ip_apxStatePtr[Instance] != NULL_PTR);
#endif 

    /* Clear state structures array */
    for (ChnlIdx = 0U; ChnlIdx < Flexio_Sent_Ip_apxStatePtr[Instance]->ResourceAllocation; ChnlIdx++)
    {
        /* Clear Fast data */
        Flexio_Sent_Ip_axFastData[Instance][ChnlIdx].DataIndx        = 0;
        Flexio_Sent_Ip_axFastData[Instance][ChnlIdx].TimerVal       = 0;
        Flexio_Sent_Ip_axFastData[Instance][ChnlIdx].FastState        = STATUS_SENT_FAST_IDLE;
        Flexio_Sent_Ip_axFastData[Instance][ChnlIdx].SerialState      = STATUS_SENT_SERIAL_IDLE;
        Flexio_Sent_Ip_axFastData[Instance][ChnlIdx].FastMsgCount    = 0;
        Flexio_Sent_Ip_axFastData[Instance][ChnlIdx].TimerbufferIndx = 0;

        for (DataIdx = 0U; DataIdx < (uint8)(SENT_MAX_NIBBLE_DATA + 2U); DataIdx++)
        {
            Flexio_Sent_Ip_axFastData[Instance][ChnlIdx].NibbleVal[DataIdx] = 0;
        }
        for (DataIdx = 0U; DataIdx < 18U; DataIdx++)
        {
            Flexio_Sent_Ip_axFastData[Instance][ChnlIdx].SerialData[DataIdx] = 0;
        }
        for (DataIdx = 0U; DataIdx < 255U; DataIdx++)
        {
            Flexio_Sent_Ip_au16TimerBuffer[ChnlIdx][DataIdx] = 0;
        }
        
        Flexio_Sent_Ip_apxStatePtr[Instance]->TransferErrorDetect[ChnlIdx] = FALSE;
#ifdef FXIO_ISR_PROCESS_TIMER_CTRL0
        Flexio_Sent_Ip_au8TimerIdx[ChnlIdx] = 0;
#endif
    }
    /* Reset state variables */
    Flexio_Sent_Ip_apxStatePtr[Instance] = NULL_PTR;
}
/* @implements      Flexio_Sent_Ip_StartChannelReceiving_Activity */
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_StartChannelReceiving
(
    const uint8  Instance,
    const uint8  ChannelId
)
{
    FLEXIO_Type *BaseAddr;
    const Flexio_Sent_Ip_StateType *Receiver;
    Flexio_Sent_Ip_StatusType       ReturnValue = STATUS_FLEXIO_SENT_IP_ERROR;

    #if (FEATURE_FLEXIO_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FEATURE_FLEXIO_INSTANCE_COUNT);
    #endif
    BaseAddr = Flexio_Sent_Ip_apxBase[Instance];
    Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];

    #if (FEATURE_FLEXIO_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ChannelId < Receiver->ResourceAllocation);
    #endif
    /*Checks if the channel received as parameter is disabled */
    if(FLEXIO_TIMER_MODE_DISABLED == Flexio_Sent_Ip_GetTimerMode(BaseAddr, Receiver->ChnlCfg[ChannelId].Timer))
    {   
        /*Enable channel in order to receive data on it*/
        Flexio_Sent_Ip_SetTimerMode(BaseAddr, Receiver->ChnlCfg[ChannelId].Timer, FLEXIO_TIMER_16BIT_INPUT_CAPTURE_MODE);
        ReturnValue = STATUS_FLEXIO_SENT_IP_SUCCESS;
    }

    return ReturnValue;
}
/* @implements      Flexio_Sent_Ip_StopChannelReceiving_Activity */
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_StopChannelReceiving
(
    const uint8  Instance,
    const uint8  ChannelId
)
{
    FLEXIO_Type *BaseAddr;
    const Flexio_Sent_Ip_StateType *Receiver;
    Flexio_Sent_Ip_StatusType       ReturnValue = STATUS_FLEXIO_SENT_IP_ERROR;

    #if (FEATURE_FLEXIO_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FEATURE_FLEXIO_INSTANCE_COUNT);
    #endif
    BaseAddr = Flexio_Sent_Ip_apxBase[Instance];
    Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];

    #if (FEATURE_FLEXIO_DEV_ERROR_DETECT == STD_ON)
    DevAssert(ChannelId < Receiver->ResourceAllocation);
    #endif
    /*Checks if the channel received as parameter is enabled */
    if(FLEXIO_TIMER_MODE_DISABLED != Flexio_Sent_Ip_GetTimerMode(BaseAddr, Receiver->ChnlCfg[ChannelId].Timer))
    {   
        /*Disable channel in order to stop receiving data on it*/
        Flexio_Sent_Ip_SetTimerMode(BaseAddr, Receiver->ChnlCfg[ChannelId].Timer, FLEXIO_TIMER_MODE_DISABLED);
        ReturnValue = STATUS_FLEXIO_SENT_IP_SUCCESS;
    }

    return ReturnValue;
}


/*FUNCTION**********************************************************************
 *
 * Function Name: Flexio_Sent_Ip_ProcessSerialMsg
 * Description  : Measure the PulseWidth of the signal received by the FLEXIO_SENT driver
 * Implements   : Flexio_Sent_Ip_ProcessSerialMsg
 *
 *END**************************************************************************/
 
static Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_ProcessSerialMsg(Flexio_DataProcessType *Data)
{
    Flexio_Sent_Ip_StatusType Status = STATUS_FLEXIO_SENT_IP_SUCCESS;
    uint8 FastMsgCount;
    uint8 Startbit;
    
    FastMsgCount = Data->FastMsgCount;
    /* Check Status and Communication Nibble from Fast message in-oder to determine serial message */
    Data->SerialData[FastMsgCount] = Data->NibbleVal[0];
    /* Extract start bit */
    Startbit = ((uint8)(Data->NibbleVal[0] & (uint8)0x08) >> (uint8)3);

    switch(Data->SerialState)
    {
        case STATUS_SENT_SERIAL_IDLE:
            /* Step 1: Check Status and Communication Nibble from Fast message in-oder to determine serial message */
            if(Startbit == 1U)
            {
                /* Short Serial data recording flag is raised */
                Data->SerialState = STATUS_SENT_SERIAL_SHORT;
                Data->SerialData[0] = Data->NibbleVal[0];
                FastMsgCount = 1;
            }
            break;
        case STATUS_SENT_SERIAL_SHORT:
            /* Step 2: Ready for record SHORT SERIAL data when eSerialState=STATUS_SENT_SERIAL_SHORT,  */
            if(Startbit == 1U)
            {
                if(FastMsgCount == 1U)
                {
                    /* Enhanced Serial data recording flag is raised */
                    Data->SerialState = STATUS_SENT_SERIAL_ENHANCED;
                }else
                {
                    /* Wrong start bit for short serial data format */
                    Status = STATUS_FLEXIO_SENT_IP_ERROR;
                }
            }
            FastMsgCount++;
            break;
        case STATUS_SENT_SERIAL_ENHANCED:
            /* Step 3: Ready for record ENHANCED SERIAL data when eSerialState=STATUS_SENT_SERIAL_ENHANCED,  */
            if(((FastMsgCount < 6U)  && (Startbit == 0U)) || ((FastMsgCount == 6U) && (Startbit == 1U)))
            {
                /* Wrong start bit for enhanced serial data format */
                Status = STATUS_FLEXIO_SENT_IP_ERROR;
            }
            FastMsgCount++;
            break;
        default:
#if (FEATURE_FLEXIO_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
            /* Should not get here */
#endif
            break;
    }
    
    Data->FastMsgCount = FastMsgCount;
    return Status;
}

static boolean Flexio_Sent_Ip_IsAllChannelDisabled(const uint8 Instance)
{
    boolean RetVal;
    const FLEXIO_Type * BaseAddr = Flexio_Sent_Ip_apxBase[Instance];
    const Flexio_Sent_Ip_StateType * Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];
    uint8 ChannelId;
    uint8 ActiveChannelCount = 0;
    /*Counts the channels that are enabled*/
    for(ChannelId = 0U; ChannelId < Receiver->ResourceAllocation; ChannelId++)
    {   
        /*Check if a channel is enabled*/
        if(FLEXIO_TIMER_16BIT_INPUT_CAPTURE_MODE == Flexio_Sent_Ip_GetTimerMode(BaseAddr, Receiver->ChnlCfg[ChannelId].Timer))
        {
            ActiveChannelCount++;
        }
    }

    /*Cheack if there are active channels*/
    if(ActiveChannelCount > 0U)
    {
        RetVal = FALSE;
    }
    else
    {
        RetVal = TRUE;
    }
    
    return RetVal;
}

static boolean Flexio_Sent_Ip_IsChannelDisabled(const uint8 Instance, const uint8 ChannelId)
{
    boolean RetVal;
    const FLEXIO_Type * BaseAddr = Flexio_Sent_Ip_apxBase[Instance];
    const Flexio_Sent_Ip_StateType * Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];
    
    /*Check if channel is enabled*/
    if(FLEXIO_TIMER_16BIT_INPUT_CAPTURE_MODE == Flexio_Sent_Ip_GetTimerMode(BaseAddr, Receiver->ChnlCfg[ChannelId].Timer))
    {
        RetVal = FALSE;
    }
    else
    {
        RetVal = TRUE;
    }
    
    return RetVal;
}


/*FUNCTION**********************************************************************
 *
 * Function Name:   Flexio_Sent_Ip_GetFastChannelMsgData
 * Description:     Receive fast message on a sent channel
 * Implements:      Flexio_Sent_Ip_GetFastChannelMsgData_Activity
 *
 *END**************************************************************************/
/* @implements      Flexio_Sent_Ip_GetFastChannelMsgData_Activity */
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetFastChannelMsgData(const uint8 Instance, const uint8 ChannelId)
{
    
    FLEXIO_Type *BaseAddr;
    static const Flexio_Sent_Ip_StateType *Receiver;
    static Flexio_Sent_FastMsgType  SentFastFrame;
    static Flexio_DataProcessType   Data;
    Flexio_Sent_Ip_StatusType       Status = STATUS_FLEXIO_SENT_IP_ERROR;
    Flexio_Sent_Ip_StatusType       RetStatus = STATUS_FLEXIO_SENT_IP_ERROR;
    
    uint32 TimeoutTicks = OsIf_MicrosToTicks(SENT_TIMEOUT, SENT_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(SENT_TIMEOUT_TYPE); /* initialize current counter */
    uint32 ElapsedTicks = 0; /* elapsed will give timeout */

    BaseAddr = Flexio_Sent_Ip_apxBase[Instance];
    Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];
    
    Data = Flexio_Sent_Ip_axFastData[Instance][ChannelId];
    Data.FastState = STATUS_SENT_FAST_IDLE;
    Data.DataIndx = 0;
    SentFastFrame.Instance = Instance;
    SentFastFrame.ChannelId = ChannelId;
    
    if((FLEXIO_DRIVER_TYPE_POLLING == Receiver->DriverType) && (NULL_PTR != Receiver->SentFastNotif[ChannelId]) && (!Flexio_Sent_Ip_IsChannelDisabled(Instance, ChannelId)))
    {
        /* Wait for getting all Fast Message Data, sentRxState = 2 means that CRC is checked done */
        while((ElapsedTicks < TimeoutTicks) && (!Flexio_Sent_Ip_IsChannelDisabled(Instance, ChannelId)))
        {
            /* Check flag on TIMSTAT_resourceIndex register  */
            if(Flexio_Mcl_Ip_GetTimerStatus(BaseAddr, SENT_TIMER(Receiver->ChnlCfg[ChannelId].Timer)) != FALSE)
            {
                /* Get Timer value */
                Data.TimerVal = Flexio_Sent_Ip_GetTimerCompare(BaseAddr,SENT_TIMER(Receiver->ChnlCfg[ChannelId].Timer));
                /* Start converting from time value to nibble Data */
                Status = Flexio_Sent_Ip_StartTransfer(Receiver->ChnlCfg[ChannelId].NibbleCnt, Receiver->ChnlCfg[ChannelId].TickLengthUs, &Data, &SentFastFrame);
                /* TIMSTAT will be cleared only when this flag was raised */
                /*FLEXIO.TIMSTAT.B.TSF = 0x01u --> Write 1 to clear TIMER #0 TSF flag */
                Flexio_Mcl_Ip_ClearTimerStatus(BaseAddr, SENT_TIMER(Receiver->ChnlCfg[ChannelId].Timer));
            }
            if((STATUS_FLEXIO_SENT_IP_SUCCESS == Status) && (STATUS_SENT_FAST_CHECKED == Data.FastState))
            {
                /* Checking CRC for processed nibble */
                Status = Flexio_Sent_Ip_FastShortCrcCheck(Receiver->ChnlCfg[ChannelId].StatusNibbleCrcCalIncluding, Receiver->ChnlCfg[ChannelId].FastCrc, Receiver->ChnlCfg[ChannelId].NibbleCnt, Data.NibbleVal);
                /* Sent Data to callback function */
                SentFastFrame.Instance = Receiver->Instance;
                SentFastFrame.ChannelId = ChannelId;
                SentFastFrame.Length = Receiver->ChnlCfg[ChannelId].NibbleCnt;
                if(STATUS_FLEXIO_SENT_IP_CRCPASSED == Status)
                {
                    (Receiver->SentFastNotif[ChannelId])(Status, &SentFastFrame);
                }
                /* CRC notification */
                if((NULL_PTR != Receiver->SentFastErrorNotif[ChannelId]) && (STATUS_FLEXIO_SENT_IP_CRCFAILED == Status))
                {
                    /* Callback function for serial message */
                    Receiver->SentFastErrorNotif[ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_CRC);
                }
                Status = STATUS_FLEXIO_SENT_IP_ERROR;
                Data.FastState = STATUS_SENT_FAST_IDLE;
                Data.DataIndx = 0;
            }
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SENT_TIMEOUT_TYPE);
        }
        if ((ElapsedTicks >= TimeoutTicks) && (Status != STATUS_FLEXIO_SENT_IP_SUCCESS))
        {
            RetStatus = STATUS_FLEXIO_SENT_IP_TIMEOUT;
            /* Timeout notification */
            if(NULL_PTR != Receiver->SentFastErrorNotif[ChannelId])
            {
                /* Callback function for fast message */
                Receiver->SentFastErrorNotif[ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_TIMEOUT);
            }
        }
        else
        {
            RetStatus = STATUS_FLEXIO_SENT_IP_SUCCESS;
        }
    } 
    else
    {
        RetStatus = STATUS_FLEXIO_SENT_IP_ERROR;
    }

    return RetStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name:   Flexio_Sent_Ip_GetFastMsgData
 * Description:     Receive fast message on a sent channel
 * Implements:      Flexio_Sent_Ip_GetFastMsgData_Activity
 *
 *END**************************************************************************/
/* @implements      Flexio_Sent_Ip_GetFastMsgData_Activity */
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetFastMsgData(const uint8 Instance)
{
    FLEXIO_Type *BaseAddr;
    static const Flexio_Sent_Ip_StateType   *Receiver;
    static Flexio_Sent_FastMsgType     SentFastFrame[FEATURE_FLEXIO_INSTANCE_COUNT][FEATURE_FLEXIO_CHANNEL_COUNT];
    static Flexio_DataProcessType      Data[FEATURE_FLEXIO_INSTANCE_COUNT][FEATURE_FLEXIO_CHANNEL_COUNT];
    uint8 ResourceIndex = 0u;
    uint8 ChannelId;
    uint8 TimerIdx;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(SENT_TIMEOUT, SENT_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(SENT_TIMEOUT_TYPE); /* initialize current counter */
    uint32 ElapsedTicks = 0; /* elapsed will give timeout */

#if (FEATURE_FLEXIO_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FEATURE_FLEXIO_INSTANCE_COUNT);
#endif

    /* To allocate status for frame processing */
    Flexio_Sent_Ip_StatusType   Status[FEATURE_FLEXIO_INSTANCE_COUNT][FEATURE_FLEXIO_CHANNEL_COUNT];
    Flexio_Sent_Ip_StatusType   TempStatus;
    
    /* To allocate status for channel processing: successful and timeout */
    Flexio_Sent_Ip_StatusType   Result = STATUS_FLEXIO_SENT_IP_TIMEOUT;
    
    uint16 TimerQueueIndex = 0U;
    
    BaseAddr = Flexio_Sent_Ip_apxBase[Instance];
    Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];

    Flexio_Sent_Ip_InitSerialBuffer();
    /* Enable interrupt for all configured channels */
    for(ChannelId = 0U; ChannelId < Flexio_Sent_Ip_apxStatePtr[Instance]->ResourceAllocation; ChannelId++)
    {
        ResourceIndex |= (1U << Receiver->ChnlCfg[ChannelId].Timer);
        /* Reset fast message state before handling a new fast message */
        Data[Instance][ChannelId].FastState = STATUS_SENT_FAST_IDLE;
        Data[Instance][ChannelId].DataIndx = 0U;
        /* get information of that channel */
        Data[Instance][ChannelId] = Flexio_Sent_Ip_axFastData[Instance][ChannelId];
        Data[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
        Data[Instance][ChannelId].FastMsgCount = 0U;
        SentFastFrame[Instance][ChannelId].Instance = Instance;
        SentFastFrame[Instance][ChannelId].ChannelId = ChannelId;
		Data[Instance][ChannelId].TimerbufferIndx = 0U;
    }
    Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, ResourceIndex , TRUE);

    while(ElapsedTicks < TimeoutTicks)
    {
        /* if(queue not empty) else wait, not increase queue index */
        if(Flexio_Sent_Ip_au8TimerQueue[TimerQueueIndex] != 0xFFU)
        {
            /* get value of channel index */
            ChannelId = Flexio_Sent_Ip_au8TimerQueue[TimerQueueIndex];
            Status[Instance][ChannelId] = STATUS_FLEXIO_SENT_IP_ERROR;
            
            /* check if polling and sent serial callback, else skip, increate index */
            if((FLEXIO_DRIVER_TYPE_POLLING == Receiver->DriverType) && (NULL_PTR != Receiver->SentFastNotif[ChannelId]))
            {
                /* Get timer buffer index from previous time */
                TimerIdx = Data[Instance][ChannelId].TimerbufferIndx;
                /* Get timer value */
                Data[Instance][ChannelId].TimerVal = Flexio_Sent_Ip_au16TimerBuffer[ChannelId][TimerIdx];
                /* Start converting from time value to nibble data */
                Status[Instance][ChannelId] = Flexio_Sent_Ip_StartTransfer(Receiver->ChnlCfg[ChannelId].NibbleCnt, Receiver->ChnlCfg[ChannelId].TickLengthUs, &Data[Instance][ChannelId], &SentFastFrame[Instance][ChannelId]);
                /* reset timer buffer after processed */
                Flexio_Sent_Ip_au16TimerBuffer[ChannelId][TimerIdx] = 0U;
                /* Increase index for the next timer value */
                TimerIdx++;
                Data[Instance][ChannelId].TimerbufferIndx = (uint8)TimerIdx;
                
                if((STATUS_FLEXIO_SENT_IP_SUCCESS == Status[Instance][ChannelId]) && (STATUS_SENT_FAST_CHECKED == Data[Instance][ChannelId].FastState))
                {
                    /* Checking CRC for processed nibble */
                    TempStatus = Flexio_Sent_Ip_FastShortCrcCheck(Receiver->ChnlCfg[ChannelId].StatusNibbleCrcCalIncluding, Receiver->ChnlCfg[ChannelId].FastCrc, Receiver->ChnlCfg[ChannelId].NibbleCnt, Data[Instance][ChannelId].NibbleVal);
                    /* Sent data to callback function */
                    SentFastFrame[Instance][ChannelId].Instance = Receiver->Instance;
                    SentFastFrame[Instance][ChannelId].ChannelId = ChannelId;
                    SentFastFrame[Instance][ChannelId].Length = Receiver->ChnlCfg[ChannelId].NibbleCnt;
                    
                    if(STATUS_FLEXIO_SENT_IP_CRCPASSED == TempStatus)
                    {
                        (Receiver->SentFastNotif[ChannelId])(TempStatus, &SentFastFrame[Instance][ChannelId]);
                        Result = STATUS_FLEXIO_SENT_IP_SUCCESS;
                    }
                    /* CRC notification */
                    if((NULL_PTR != Receiver->SentFastErrorNotif[ChannelId]) && (STATUS_FLEXIO_SENT_IP_CRCFAILED == TempStatus))
                    {
                        /* Callback function for serial message */
                        Receiver->SentFastErrorNotif[ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_CRC);
                    }
					/* Reset FastState after processing a completed Fast Frame */
					Data[Instance][ChannelId].FastState = STATUS_SENT_FAST_IDLE;
					Data[Instance][ChannelId].DataIndx = 0U;
                }
                Flexio_Sent_Ip_au8TimerQueue[TimerQueueIndex] = 0xFFU;
                
                /* increase index */
                if(TimerQueueIndex == (FLEXIO_SENT_IP_TIMER_QUEUE_SIZE-1U))
                {
                    TimerQueueIndex = 0U;
                }
                else
                {
                    TimerQueueIndex++;
                }
            }
            else
            {
                Flexio_Sent_Ip_au8TimerQueue[TimerQueueIndex] = 0xFFU;  
                /* increase index */
                if(TimerQueueIndex == (FLEXIO_SENT_IP_TIMER_QUEUE_SIZE-1U))
                {
                    TimerQueueIndex = 0U;
                }
                else
                {
                    TimerQueueIndex++;
                }
            } 
        }
        if(Flexio_Sent_Ip_IsAllChannelDisabled(Instance))
        {
            break;
        }
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SENT_TIMEOUT_TYPE);
    }
    
    /* Disable interrupt for all configured channels */
    Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, ResourceIndex , FALSE);
    Flexio_Sent_Ip_InitSerialBuffer();
    
    return Result;
}

/*FUNCTION**********************************************************************
 *
 * Function Name:   Flexio_Sent_Ip_GetSerialChannelMsgData
 * Description:     Receive Serial message on a sent channel
 * Implements:      Flexio_Sent_Ip_GetSerialChannelMsgData_Activity
 *
 *END**************************************************************************/
/* @implements      Flexio_Sent_Ip_GetSerialChannelMsgData_Activity */
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetSerialChannelMsgData(const uint8 Instance, const uint8 ChannelId)
{
    FLEXIO_Type * BaseAddr;
    const Flexio_Sent_Ip_StateType    * Receiver;
    Flexio_Sent_FastMsgType     SentFastFrame;
    Flexio_Sent_SerialMsgType   SentSerialFrame;
    Flexio_DataProcessType      Data;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(SENT_TIMEOUT, SENT_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(SENT_TIMEOUT_TYPE); /* initialize current counter */
    uint32 ElapsedTicks = 0; /* elapsed will give timeout */

    /* To allocate status for frame processing */
    Flexio_Sent_Ip_StatusType Status  = STATUS_FLEXIO_SENT_IP_ERROR;
    /* To allocate status for fast message when check CRC */
    Flexio_Sent_Ip_StatusType StatusCrc;
    /* To allocate status for channel processing: successful and timeout */
    Flexio_Sent_Ip_StatusType Result = STATUS_FLEXIO_SENT_IP_TIMEOUT;
    uint8 FastMsgCount = 0U;
    BaseAddr = Flexio_Sent_Ip_apxBase[Instance];
    Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];
    
    Data = Flexio_Sent_Ip_axFastData[Instance][ChannelId];
    Data.SerialState = STATUS_SENT_SERIAL_IDLE;
    Data.FastMsgCount = 0;
    
    SentFastFrame.Instance = Instance;
    SentFastFrame.ChannelId = ChannelId;
    
    if((FLEXIO_DRIVER_TYPE_POLLING == Receiver->DriverType) && (NULL_PTR != Receiver->SentSerialNotif[ChannelId]) && (!Flexio_Sent_Ip_IsChannelDisabled(Instance, ChannelId)))
    {
        FastMsgCount = 0;
        Data.FastState = STATUS_SENT_FAST_IDLE;
        Data.DataIndx = 0;
        while((ElapsedTicks < TimeoutTicks) && (!Flexio_Sent_Ip_IsChannelDisabled(Instance, ChannelId)))
        {
            /* Check flag on TIMSTAT_resourceIndex register  */
            if(Flexio_Mcl_Ip_GetTimerStatus(BaseAddr, SENT_TIMER(Receiver->ChnlCfg[ChannelId].Timer)) != FALSE)
            {
                /* Get timer value */
                Data.TimerVal = Flexio_Sent_Ip_GetTimerCompare(BaseAddr,SENT_TIMER(Receiver->ChnlCfg[ChannelId].Timer));
                /* Start converting from time value to nibble data */
                Status = Flexio_Sent_Ip_StartTransfer(Receiver->ChnlCfg[ChannelId].NibbleCnt, Receiver->ChnlCfg[ChannelId].TickLengthUs, &Data, &SentFastFrame);
                /* TIMSTAT will be cleared only when this flag was raised */
                /*FLEXIO.TIMSTAT.B.TSF = 0x01u --> Write 1 to clear TIMER #0 TSF flag */
                Flexio_Mcl_Ip_ClearTimerStatus(BaseAddr, SENT_TIMER(Receiver->ChnlCfg[ChannelId].Timer));
                
                /* Incase there is any error on fast frame diagnostic */
                if(STATUS_FLEXIO_SENT_IP_ERROR == Status)
                {
                    /* Reset Data after processing a completed Serial Frame or having any error*/
                    Data.SerialState = STATUS_SENT_SERIAL_IDLE;
                    Data.FastMsgCount = 0U;
                }
            }
            
            /* Slow message processing will be started when fast message was passed in CRC checking */
            if((STATUS_FLEXIO_SENT_IP_SUCCESS == Status) && (STATUS_SENT_FAST_CHECKED == Data.FastState))
            {
                /* Checking CRC for processed nibble */
                StatusCrc = Flexio_Sent_Ip_FastShortCrcCheck(Receiver->ChnlCfg[ChannelId].StatusNibbleCrcCalIncluding, Receiver->ChnlCfg[ChannelId].FastCrc, Receiver->ChnlCfg[ChannelId].NibbleCnt, Data.NibbleVal);
                /* Sent data to callback function */
                SentFastFrame.Instance = Receiver->Instance;
                SentFastFrame.ChannelId = ChannelId;
                SentFastFrame.Length = Receiver->ChnlCfg[ChannelId].NibbleCnt;
                if(STATUS_FLEXIO_SENT_IP_CRCPASSED == StatusCrc)
                {                
                    if(NULL_PTR != Receiver->SentFastNotif[ChannelId])
                    {
                        (Receiver->SentFastNotif[ChannelId])(StatusCrc, &SentFastFrame);
                    }
                    /* Serial message is a sequence of fast message.
                    If a fast message get error Serial message need to start again: fastcount will be reset to 0 */
                    if(STATUS_FLEXIO_SENT_IP_ERROR == Flexio_Sent_Ip_ProcessSerialMsg(&Data))
                    {
                        /* Reset Data after processing a completed Serial Frame or having any error */
                        Data.SerialState = STATUS_SENT_SERIAL_IDLE;
                        Data.FastMsgCount = 0U;
                    }
                }
                if(STATUS_FLEXIO_SENT_IP_CRCFAILED == StatusCrc)
                {
          			/* Reset Data after processing a completed Serial Frame or having any error*/
          			Data.SerialState = STATUS_SENT_SERIAL_IDLE;
          			Data.FastMsgCount = 0U;
                    if(NULL_PTR != Receiver->SentFastErrorNotif[ChannelId])
                    {
                        Receiver->SentFastErrorNotif[ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_CRC);;
                    }
                }
                FastMsgCount = Data.FastMsgCount;
                
                /** Slow message processing done only when:
                * 1. fastMsgCount = 16 and data->eSerialState = STATUS_SENT_SERIAL_SHORT (Short message)
                * 2. fastMsgCount = 18 and data->eSerialState = STATUS_SENT_SERIAL_ENHANCED (Enhanced message) 
                */
                if(((Data.SerialState == STATUS_SENT_SERIAL_SHORT) && (FastMsgCount == 16U)) || 
                  ((Data.SerialState == STATUS_SENT_SERIAL_ENHANCED) && (FastMsgCount == 18U)))
                {
                    /* Start to extract serial data */
                    Status = Flexio_Sent_Ip_GetSerialMsgFromRaw(Receiver->ChnlCfg[ChannelId].SlowCrc, &Data, &SentSerialFrame);
                    SentSerialFrame.ChannelId = ChannelId;
                    SentSerialFrame.Instance = Receiver->Instance;
                    Flexio_Sent_Ip_SerialNotiHandler(Instance, ChannelId, Status, &SentSerialFrame);
                    FastMsgCount = 0U;
                    Data.FastMsgCount = 0U;
                    Data.SerialState = STATUS_SENT_SERIAL_IDLE;
                    Result = STATUS_FLEXIO_SENT_IP_SUCCESS;
                }
                Data.FastState = STATUS_SENT_FAST_IDLE;
                Data.DataIndx = 0;
            }
            ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SENT_TIMEOUT_TYPE);
        }
    }
    
    return Result;
}

/*FUNCTION**********************************************************************
 *
 * Function Name:   Flexio_Sent_Ip_GetSerialMsgData
 * Description:     Receive Serial message on all sent channel
 * Implements:      Flexio_Sent_Ip_GetSerialMsgData_Activity
 *
 *END**************************************************************************/
/* @implements      Flexio_Sent_Ip_GetSerialMsgData_Activity */
Flexio_Sent_Ip_StatusType Flexio_Sent_Ip_GetSerialMsgData(const uint8 Instance)
{
    FLEXIO_Type *BaseAddr;
    static const Flexio_Sent_Ip_StateType   *Receiver;
    static Flexio_Sent_FastMsgType     SentFastFrame[FEATURE_FLEXIO_INSTANCE_COUNT][FEATURE_FLEXIO_CHANNEL_COUNT];
    static Flexio_Sent_SerialMsgType   SentSerialFrame[FEATURE_FLEXIO_INSTANCE_COUNT][FEATURE_FLEXIO_CHANNEL_COUNT];
    static Flexio_DataProcessType      Data[FEATURE_FLEXIO_INSTANCE_COUNT][FEATURE_FLEXIO_CHANNEL_COUNT];
    uint8 ResourceIndex = 0u;
    uint8 ChannelId;
    uint8 TimerIdx;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(SENT_TIMEOUT, SENT_TIMEOUT_TYPE);
    uint32 CurrentTicks = OsIf_GetCounter(SENT_TIMEOUT_TYPE); /* initialize current counter */
    uint32 ElapsedTicks = 0; /* elapsed will give timeout */

#if (FEATURE_FLEXIO_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < FEATURE_FLEXIO_INSTANCE_COUNT);
#endif
    /* To allocate status for frame processing */
    Flexio_Sent_Ip_StatusType   Status[FEATURE_FLEXIO_INSTANCE_COUNT][FEATURE_FLEXIO_CHANNEL_COUNT];
    Flexio_Sent_Ip_StatusType   TempStatus;
    
    /* To allocate status for channel processing: successful and timeout */
    Flexio_Sent_Ip_StatusType   Result = STATUS_FLEXIO_SENT_IP_TIMEOUT;
    
    uint16 TimerQueueIndex = 0U;
    
    BaseAddr = Flexio_Sent_Ip_apxBase[Instance];
    Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];

    Flexio_Sent_Ip_InitSerialBuffer();
    /* Enable interrupt for all configured channels */
    for(ChannelId = 0U; ChannelId < Flexio_Sent_Ip_apxStatePtr[Instance]->ResourceAllocation; ChannelId++)
    {
        ResourceIndex |= (1U << Receiver->ChnlCfg[ChannelId].Timer);
        /* Reset fast message state before handling a new fast message */
        Data[Instance][ChannelId].FastState = STATUS_SENT_FAST_IDLE;
        Data[Instance][ChannelId].DataIndx = 0U;
        /* get information of that channel */
        Data[Instance][ChannelId] = Flexio_Sent_Ip_axFastData[Instance][ChannelId];
        Data[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
        Data[Instance][ChannelId].FastMsgCount = 0U;
        SentFastFrame[Instance][ChannelId].Instance = Instance;
        SentFastFrame[Instance][ChannelId].ChannelId = ChannelId;
		Data[Instance][ChannelId].TimerbufferIndx = 0U;
    }
    Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, ResourceIndex , TRUE);

    while((ElapsedTicks < TimeoutTicks))
    {
        /* if(queue not empty) else wait, not increase queue index */
        if(Flexio_Sent_Ip_au8TimerQueue[TimerQueueIndex] != 0xFFU)
        {
            /* get value of channel index */
            ChannelId = Flexio_Sent_Ip_au8TimerQueue[TimerQueueIndex];
            Status[Instance][ChannelId] = STATUS_FLEXIO_SENT_IP_ERROR;
            
            /* check if polling and sent serial callback, else skip, increate index */
            if((FLEXIO_DRIVER_TYPE_POLLING == Receiver->DriverType) && (NULL_PTR != Receiver->SentSerialNotif[ChannelId]))
            {
                /* Get timer buffer index from previous time */
                TimerIdx = Data[Instance][ChannelId].TimerbufferIndx;
                /* Get timer value */
                Data[Instance][ChannelId].TimerVal = Flexio_Sent_Ip_au16TimerBuffer[ChannelId][TimerIdx];
                /* Start converting from time value to nibble data */
                Status[Instance][ChannelId] = Flexio_Sent_Ip_StartTransfer(Receiver->ChnlCfg[ChannelId].NibbleCnt, Receiver->ChnlCfg[ChannelId].TickLengthUs, &Data[Instance][ChannelId], &SentFastFrame[Instance][ChannelId]);
                /* reset timer buffer after processed */
                Flexio_Sent_Ip_au16TimerBuffer[ChannelId][TimerIdx] = 0U;
                /* Increase index for the next timer value */
                TimerIdx++;
                Data[Instance][ChannelId].TimerbufferIndx = (uint8)TimerIdx;
                
                if(STATUS_FLEXIO_SENT_IP_ERROR == Status[Instance][ChannelId])
                {
                    /* Reset Data after processing a completed Serial Frame or having any error*/
                    Data[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
                    Data[Instance][ChannelId].FastMsgCount = 0U;
                    
                }
                if((STATUS_FLEXIO_SENT_IP_SUCCESS == Status[Instance][ChannelId]) && (STATUS_SENT_FAST_CHECKED == Data[Instance][ChannelId].FastState))
                {
                    /* Checking CRC for processed nibble */
                    TempStatus = Flexio_Sent_Ip_FastShortCrcCheck(Receiver->ChnlCfg[ChannelId].StatusNibbleCrcCalIncluding, Receiver->ChnlCfg[ChannelId].FastCrc, Receiver->ChnlCfg[ChannelId].NibbleCnt, Data[Instance][ChannelId].NibbleVal);
                    /* Sent data to callback function */
                    SentFastFrame[Instance][ChannelId].Instance = Receiver->Instance;
                    SentFastFrame[Instance][ChannelId].ChannelId = ChannelId;
                    SentFastFrame[Instance][ChannelId].Length = Receiver->ChnlCfg[ChannelId].NibbleCnt;
                    if(STATUS_FLEXIO_SENT_IP_CRCPASSED == TempStatus)
                    {
                        if(NULL_PTR != Receiver->SentFastNotif[ChannelId])
                        {
                            (Receiver->SentFastNotif[ChannelId])(TempStatus, &SentFastFrame[Instance][ChannelId]);
                        }
                        /* Serial message is a sequence of fast message.
                        If a fast message get error Serial message need to start again: fast-count will be reset to 0 */
                        if(STATUS_FLEXIO_SENT_IP_ERROR == Flexio_Sent_Ip_ProcessSerialMsg(&Data[Instance][ChannelId]))
                        {
                            /* Reset Data after processing a completed Serial Frame or having any error*/
                            Data[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
                            Data[Instance][ChannelId].FastMsgCount = 0U;
                        }
                    }
                    if(STATUS_FLEXIO_SENT_IP_CRCFAILED == TempStatus)
                    {
                        if(NULL_PTR != Receiver->SentFastErrorNotif[ChannelId])
                        {
                            Receiver->SentFastErrorNotif[ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_CRC);
                        }
                        /* Reset Data after processing a completed Serial Frame or having any error*/
                        Data[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
                        Data[Instance][ChannelId].FastMsgCount = 0U;
                    }
					/* Reset FastState after processing a completed Fast Frame */
					Data[Instance][ChannelId].FastState = STATUS_SENT_FAST_IDLE;
					Data[Instance][ChannelId].DataIndx = 0U;
                    
                    /* check if msg count, process serial data before processing new */
                    if(((Data[Instance][ChannelId].SerialState == STATUS_SENT_SERIAL_SHORT) && (Data[Instance][ChannelId].FastMsgCount == 16U)) || 
                      ((Data[Instance][ChannelId].SerialState == STATUS_SENT_SERIAL_ENHANCED) && (Data[Instance][ChannelId].FastMsgCount == 18U)))
                    {
                        /* the next position of timer buffer is saved for the next frame processing */
                        Flexio_Sent_Ip_axFastData[Instance][ChannelId].TimerbufferIndx = (uint8)Data[Instance][ChannelId].TimerbufferIndx;
                        /* Start to extract serial data */
                        TempStatus = Flexio_Sent_Ip_GetSerialMsgFromRaw(Receiver->ChnlCfg[ChannelId].SlowCrc, &Data[Instance][ChannelId], &SentSerialFrame[Instance][ChannelId]);
                        SentSerialFrame[Instance][ChannelId].ChannelId = ChannelId;
                        SentSerialFrame[Instance][ChannelId].Instance = Receiver->Instance;
                        if(STATUS_FLEXIO_SENT_IP_CRCPASSED == TempStatus)
                        {
                            Result = STATUS_FLEXIO_SENT_IP_SUCCESS;
                        }
                        Flexio_Sent_Ip_SerialNotiHandler(Receiver->Instance, ChannelId, TempStatus, &SentSerialFrame[Instance][ChannelId]);
                        /* Reset Data after processing a completed Serial Frame */
                        Data[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
                        Data[Instance][ChannelId].FastMsgCount = 0U;
                    }
                }
                Flexio_Sent_Ip_au8TimerQueue[TimerQueueIndex] = 0xFFU;
                
                /* increase index */
                Flexio_Sent_Ip_TimerQueueIndexHandler(&TimerQueueIndex);
            }
            else
            {
                Flexio_Sent_Ip_au8TimerQueue[TimerQueueIndex] = 0xFFU;  
                
                /* increase index */
                Flexio_Sent_Ip_TimerQueueIndexHandler(&TimerQueueIndex);
            } 
        }
        if(Flexio_Sent_Ip_IsAllChannelDisabled(Instance))
        {
            break;
        }
        ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, SENT_TIMEOUT_TYPE);
    }
    
    /* Disable interrupt for all configured channels */
    Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, ResourceIndex , FALSE);
    Flexio_Sent_Ip_InitSerialBuffer();
    
    return Result;
}

#if (FEATURE_FLEXIO_DMA_ENABLE == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Sent_Ip_IRQHandler
 * Description   : Implementation of FLEXIO interrupt handler for all fast and serial messages
 *
 *END**************************************************************************/

static void Flexio_Sent_Ip_DmaDataProcessing(const uint8 Instance, const uint8 ChannelId, const uint32 DmaTimerVal)
{
    const  Flexio_Sent_Ip_StateType     *Receiver;
    static Flexio_Sent_FastMsgType      SentFastFrame[FEATURE_FLEXIO_CHANNEL_COUNT];
    static Flexio_Sent_SerialMsgType    SentSerialFrame[FEATURE_FLEXIO_CHANNEL_COUNT];
    uint8  NibbleCnt;
    uint32  TickLengthUs;
    Flexio_Sent_Ip_StatusType Status;

    Flexio_Sent_Ip_axFastData[Instance][ChannelId].TimerVal = DmaTimerVal;
    
    SentFastFrame[ChannelId].Instance = Instance;
    SentFastFrame[ChannelId].ChannelId = ChannelId;
    Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];
    NibbleCnt = Receiver->ChnlCfg[ChannelId].NibbleCnt;
    TickLengthUs = Receiver->ChnlCfg[ChannelId].TickLengthUs;
    /* Start converting from time value to nibble data */
    Status = Flexio_Sent_Ip_StartTransfer(NibbleCnt, TickLengthUs, &Flexio_Sent_Ip_axFastData[Instance][ChannelId], &SentFastFrame[ChannelId]);
    
    /* ignore all previous fast message and restart fast message count if there is any error on message diagnostic */
    if(STATUS_FLEXIO_SENT_IP_ERROR == Status)
    {
        Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount = 0;
        Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
    }
    
    /* Slow message processing will be started when fast message was passed in CRC checking */
    if((STATUS_FLEXIO_SENT_IP_SUCCESS == Status) && (STATUS_SENT_FAST_CHECKED == Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastState))
    {
        /* Checking CRC for processed nibble */
        Status = Flexio_Sent_Ip_FastShortCrcCheck(Receiver->ChnlCfg[ChannelId].StatusNibbleCrcCalIncluding, Receiver->ChnlCfg[ChannelId].FastCrc, NibbleCnt, Flexio_Sent_Ip_axFastData[Instance][ChannelId].NibbleVal);

        if(NULL_PTR != Receiver->SentFastNotif[ChannelId])
        {
            SentFastFrame[ChannelId].ChannelId = ChannelId;
            SentFastFrame[ChannelId].Length = NibbleCnt;
			if(STATUS_FLEXIO_SENT_IP_CRCPASSED == Status)
			{
				Receiver->SentFastNotif[ChannelId](Status, &SentFastFrame[ChannelId]);
			}
        }
        if(STATUS_FLEXIO_SENT_IP_CRCFAILED == Status)
        {
            if(NULL_PTR != Receiver->SentFastErrorNotif[ChannelId])
            {
                Receiver->SentFastErrorNotif[ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_CRC);
            }
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount = 0;
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
        }
        if(STATUS_FLEXIO_SENT_IP_ERROR == Flexio_Sent_Ip_ProcessSerialMsg(&Flexio_Sent_Ip_axFastData[Instance][ChannelId]))
        {
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount = 0;
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
        }
        
        /* Clear Fast data when Fast data processing done */
        Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastState = STATUS_SENT_FAST_IDLE;
        Flexio_Sent_Ip_axFastData[Instance][ChannelId].DataIndx = 0;
        Flexio_Sent_Ip_axFastData[Instance][ChannelId].TimerVal = 0;
    }

    if(((Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState == STATUS_SENT_SERIAL_SHORT) && (Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount == 16U)) || 
       ((Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState == STATUS_SENT_SERIAL_ENHANCED) && (Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount == 18U)))
    {
        /* Start to extract serial data */
        Status = Flexio_Sent_Ip_GetSerialMsgFromRaw(Receiver->ChnlCfg[ChannelId].SlowCrc, &Flexio_Sent_Ip_axFastData[Instance][ChannelId], &SentSerialFrame[ChannelId]);
        if(NULL_PTR != Receiver->SentSerialNotif[ChannelId])
        {
            SentSerialFrame[ChannelId].ChannelId = ChannelId;
            if(STATUS_FLEXIO_SENT_IP_CRCPASSED == Status)
            {
                /* Callback function for serial message */
                Receiver->SentSerialNotif[ChannelId](Status, &SentSerialFrame[ChannelId]);
            }
        }
        /* CRC notification */
        if((NULL_PTR != Receiver->SentSerialErrorNotif[ChannelId]) && (STATUS_FLEXIO_SENT_IP_CRCFAILED == Status))
        {
            /* Callback function for serial message */
            Receiver->SentSerialErrorNotif[ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_CRC);
        }
        /* Clear Fast data when Fast data processing done */
        Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
        Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount = 0;
    }
}

void Flexio_Sent_Ip_DmaHandler(const uint8 Instance, const uint8 ChannelId)
{
    uint16 DataIndex;
    const Flexio_Sent_Ip_StateType *Receiver;
    uint8 NumberOfData;
    
    Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];
    
    if(NULL_PTR != Flexio_Sent_Ip_apxStatePtr[Instance])
    {
        if(SENT_PAUSE_PULSE_DISABLED == Receiver->ChnlCfg[ChannelId].PausePulse)
        {  
            NumberOfData = Receiver->ChnlCfg[ChannelId].DmaBufferDepth * (Receiver->ChnlCfg[ChannelId].NibbleCnt + 3U);
        }
        else
        {
            NumberOfData = Receiver->ChnlCfg[ChannelId].DmaBufferDepth * (Receiver->ChnlCfg[ChannelId].NibbleCnt + 4U);
        }

        if (Flexio_Sent_Ip_abFirstHalfDmaBuffer[Instance][ChannelId])
        {
            for(DataIndex = 0U; DataIndex < (uint16)NumberOfData; DataIndex++)
            {
                /* Process all data for first half of dma buffer */
                Flexio_Sent_Ip_DmaDataProcessing(Instance, ChannelId, Receiver->ChnlCfg[ChannelId].DmaTimerBuffer[DataIndex]);
                Receiver->ChnlCfg[ChannelId].DmaTimerBuffer[DataIndex] = 0U;
            };
            Flexio_Sent_Ip_abFirstHalfDmaBuffer[Instance][ChannelId] = FALSE;
        }
        else
        {           
            for(DataIndex = (uint16)NumberOfData; DataIndex <(uint16) (2U * (uint16)NumberOfData); DataIndex++)
            {
                /* Process all data for second half of dma buffer */
                Flexio_Sent_Ip_DmaDataProcessing(Instance, ChannelId, Receiver->ChnlCfg[ChannelId].DmaTimerBuffer[DataIndex]);
                Receiver->ChnlCfg[ChannelId].DmaTimerBuffer[DataIndex] = 0U;
            };
            Flexio_Sent_Ip_abFirstHalfDmaBuffer[Instance][ChannelId] = TRUE;
        }

    }
}

#endif /* (FEATURE_FLEXIO_DMA_ENABLE == STD_ON) */


/* @implements      Flexio_Sent_Ip_IRQHandler_Activity */
#ifdef FXIO_ISR_PROCESS_MESSAGE_HANDLER_CTRL0_COMBINED

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Sent_Ip_IRQMsgDataHandler
 * Description   : Implementation of FLEXIO interrupt handler for all fast and serial messages
 *
 *END**************************************************************************/

void Flexio_Sent_Ip_IRQMsgDataHandler(const uint8 Instance, const uint8 HwChannel, uint32 TimerVal)
{
    static Flexio_Sent_Ip_StateType     *Receiver;
    static Flexio_Sent_FastMsgType      SentFastFrame;
    static Flexio_Sent_SerialMsgType    SentSerialFrame;
    uint8  NibbleCnt;
    uint32  TickLengthUs;
    uint8  ChannelId;
    Flexio_Sent_Ip_StatusType Status = STATUS_FLEXIO_SENT_IP_ERROR;
    
#if (STD_ON == FEATURE_FLEXIO_DEV_ERROR_DETECT)
    DevAssert(FEATURE_FLEXIO_INSTANCE_COUNT > Instance);
#endif
    
    if(NULL_PTR != Flexio_Sent_Ip_apxStatePtr[Instance])
    {
        Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];
        
        /* Get ChannelID from HwChannel */
        for(ChannelId = 0; ChannelId < FEATURE_FLEXIO_CHANNEL_COUNT; ChannelId++)
        {
            if(HwChannel == Receiver->ChnlCfg[ChannelId].Timer)
            {
                /* get channelID and break for loop */
                break;
            }
        }
        SentFastFrame.Instance = Instance;
        SentFastFrame.ChannelId = ChannelId;
        /* Get timer value */
        Flexio_Sent_Ip_axFastData[Instance][ChannelId].TimerVal = TimerVal;

        NibbleCnt = Receiver->ChnlCfg[ChannelId].NibbleCnt;
        TickLengthUs = Receiver->ChnlCfg[ChannelId].TickLengthUs;
        
        /* Start converting from time value to nibble data */
        Status = Flexio_Sent_Ip_StartTransfer(NibbleCnt, TickLengthUs, &Flexio_Sent_Ip_axFastData[Instance][ChannelId], &SentFastFrame);

        if(STATUS_FLEXIO_SENT_IP_ERROR == Status)
        {
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount = 0;
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
        }
        /* Slow message processing will be started when fast message was passed in CRC checking */
        if((STATUS_FLEXIO_SENT_IP_SUCCESS == Status) && (STATUS_SENT_FAST_CHECKED == Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastState))
        {
            /* Checking CRC for processed nibble */
            Status = Flexio_Sent_Ip_FastShortCrcCheck(Receiver->ChnlCfg[ChannelId].StatusNibbleCrcCalIncluding, Receiver->ChnlCfg[ChannelId].FastCrc, NibbleCnt, Flexio_Sent_Ip_axFastData[Instance][ChannelId].NibbleVal);

            SentFastFrame.Instance = Receiver->Instance;
            SentFastFrame.ChannelId = ChannelId;
            SentFastFrame.Length = NibbleCnt;
            if(STATUS_FLEXIO_SENT_IP_CRCPASSED == Status)
            {            
                if(NULL_PTR != Receiver->SentFastNotif[ChannelId])
                {
                    Receiver->SentFastNotif[ChannelId](Status, &SentFastFrame);
                }
            }
            if(STATUS_FLEXIO_SENT_IP_CRCFAILED == Status)
            {
                Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount = 0;
                Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
                if(NULL_PTR != Receiver->SentFastErrorNotif[ChannelId])
                {
                    Receiver->SentFastErrorNotif[ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_CRC);   
                }
            }
            if(STATUS_FLEXIO_SENT_IP_ERROR == Flexio_Sent_Ip_ProcessSerialMsg(&Flexio_Sent_Ip_axFastData[Instance][ChannelId]))
            {
                Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount = 0;
                Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
            }
            
            /* Clear Fast data when Fast data processing done */
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastState = STATUS_SENT_FAST_IDLE;
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].DataIndx = 0;
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].TimerVal = 0;

        }

        if(((Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState == STATUS_SENT_SERIAL_SHORT) && (Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount == 16)) || 
           ((Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState == STATUS_SENT_SERIAL_ENHANCED) && (Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount == 18)))
        {
            /* Start to extract serial data */
            Status = Flexio_Sent_Ip_GetSerialMsgFromRaw(Receiver->ChnlCfg[ChannelId].SlowCrc, &Flexio_Sent_Ip_axFastData[Instance][ChannelId], &SentSerialFrame);

            SentSerialFrame.ChannelId = ChannelId;
            SentSerialFrame.Instance = Receiver->Instance;
            if(STATUS_FLEXIO_SENT_IP_CRCPASSED == Status)
            {            
                if(NULL_PTR != Receiver->SentSerialNotif[ChannelId])
                {
                    /* Callback function for serial message */
                    Receiver->SentSerialNotif[ChannelId](Status, &SentSerialFrame);
                }
            }
            /* Clear Fast data when Fast data processing done */
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].SerialState = STATUS_SENT_SERIAL_IDLE;
            Flexio_Sent_Ip_axFastData[Instance][ChannelId].FastMsgCount = 0;
            if((NULL_PTR != Receiver->SentSerialErrorNotif[ChannelId]) && (STATUS_FLEXIO_SENT_IP_CRCFAILED == Status))
            {
                /* Callback function for serial message */
                Receiver->SentSerialErrorNotif[ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_CRC);
            }
        }
    }
}

#endif /* FXIO_ISR_PROCESS_MESSAGE_HANDLER_CTRL0_COMBINED */

#ifdef FXIO_ISR_PROCESS_TIMER_CTRL0

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Sent_Ip_IRQTimerHandler
 * Description   : Collect timer values and allocate to Flexio_Sent_Ip_au16TimerBuffer
 *
 *END**************************************************************************/
void Flexio_Sent_Ip_IRQTimerHandler(const uint8 Instance, const uint8 HwChannel, uint32 TimerVal)
{
    uint8       ChannelId = 0U;
    static const Flexio_Sent_Ip_StateType *Receiver;

#if (STD_ON == FEATURE_FLEXIO_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != Flexio_Sent_Ip_apxStatePtr[Instance]);
    DevAssert(FEATURE_FLEXIO_INSTANCE_COUNT > Instance);
#endif

    Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];
    
    /* Get ChannelID from HwChannel */
    for(ChannelId = 0; ChannelId < FEATURE_FLEXIO_CHANNEL_COUNT; ChannelId++)
    {
        if(HwChannel == Receiver->ChnlCfg[ChannelId].Timer)
        {
            /* get channelID and break for loop */
            break;
        }
    }
    /* Flexio_Sent_Ip_au16TimerBuffer was used to provide data for Flexio_Sent_Ip_GetSerialMsgData function */
    Flexio_Sent_Ip_au16TimerBuffer[ChannelId][Flexio_Sent_Ip_au8TimerIdx[ChannelId]] = TimerVal;
    Flexio_Sent_Ip_au8TimerQueue[Flexio_Sent_Ip_u16TimerQueueIndex] = ChannelId;
    Flexio_Sent_Ip_au8TimerIdx[ChannelId]++;
    
    /* increase index */
    if(Flexio_Sent_Ip_u16TimerQueueIndex == FLEXIO_SENT_IP_TIMER_QUEUE_SIZE-1)
    {
        Flexio_Sent_Ip_u16TimerQueueIndex = 0U;
    }
    else
    {
        Flexio_Sent_Ip_u16TimerQueueIndex++;
    }
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_Sent_Ip_IrqHandler
 * Description   : Implementation of Flexio interrupt handler
 *
 ******************************************************************************/

void Flexio_Sent_Ip_IrqHandler(uint8 HwChannel, uint8 TimerMaskFlag)
{
    const FLEXIO_Type *BaseAddr;
    uint8 EnabledInterrupts;
    uint8 TimerEvents;
    uint32 TimerVal;
    
    BaseAddr = Flexio_Sent_Ip_apxBase[0];
    /* read enabled interrupts in a separate instruction to avoid MISRA violation */
    EnabledInterrupts = (uint8)Flexio_Mcl_Ip_GetAllTimerInterrupt(BaseAddr);
    TimerEvents  = TimerMaskFlag & EnabledInterrupts;
    TimerVal = Flexio_Sent_Ip_GetTimerCompare(BaseAddr,SENT_TIMER(HwChannel));

    if(0U != (TimerEvents & ((uint8)(1U << HwChannel))))
    {
    #ifdef FXIO_ISR_PROCESS_MESSAGE_HANDLER_CTRL0_COMBINED
        Flexio_Sent_Ip_IRQMsgDataHandler(0, HwChannel, TimerVal);
    #endif
    #ifdef FXIO_ISR_PROCESS_TIMER_CTRL0
        Flexio_Sent_Ip_IRQTimerHandler(0, HwChannel, TimerVal);
    #endif
    }
    
    (void) TimerVal;
}

/* Reset buffer for polling transfer with all channel */
static void Flexio_Sent_Ip_InitSerialBuffer(void)
{
    uint16 t;
    

    for (t = (uint16)0U; t < FLEXIO_SENT_IP_TIMER_QUEUE_SIZE; t++)
    {
        Flexio_Sent_Ip_au8TimerQueue[t] = 0xffU;
    }
#ifdef FXIO_ISR_PROCESS_TIMER_CTRL0
    for (t = (uint16)0U; t < FEATURE_FLEXIO_CHANNEL_COUNT; t++)
    {
        Flexio_Sent_Ip_au8TimerIdx[t] = 0x0U;
    }
    Flexio_Sent_Ip_u16TimerQueueIndex = 0U;
#endif   
}

static void Flexio_Sent_Ip_TimerQueueIndexHandler(uint16* TimerQueueIndex)
{
    /* increase index */
    if(*TimerQueueIndex == (FLEXIO_SENT_IP_TIMER_QUEUE_SIZE-1U))
    {
        *TimerQueueIndex = 0U;
    }
    else
    {
        (*TimerQueueIndex)++;
    }
}

static void Flexio_Sent_Ip_SerialNotiHandler(const uint8 Instance,
                                             const uint8 ChannelId,
                                             Flexio_Sent_Ip_StatusType CrcStatus,
                                             Flexio_Sent_SerialMsgType *SentSerialFrame)
{
    const  Flexio_Sent_Ip_StateType     *Receiver;
    
    Receiver = Flexio_Sent_Ip_apxStatePtr[Instance];
    if((NULL_PTR != Receiver->SentSerialNotif[ChannelId]) && (STATUS_FLEXIO_SENT_IP_CRCPASSED == CrcStatus))
    {
        /* Callback function for serial message */
        Receiver->SentSerialNotif[ChannelId](CrcStatus, SentSerialFrame);
    }
    /* CRC notification */
    if((NULL_PTR != Receiver->SentSerialErrorNotif[ChannelId]) && (STATUS_FLEXIO_SENT_IP_CRCFAILED == CrcStatus))
    {
        /* Callback function for serial message */
        Receiver->SentSerialErrorNotif[ChannelId](STATUS_FLEXIO_SENT_IP_ERROR_CRC);
    }
}
#define SENT_STOP_SEC_CODE
#include "Sent_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
