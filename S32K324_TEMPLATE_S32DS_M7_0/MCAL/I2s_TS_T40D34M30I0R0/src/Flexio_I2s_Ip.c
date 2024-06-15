/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : I2S
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
*   Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup flexio_i2s_ip FLEXIO_I2S IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Flexio_I2s_Ip.h"
#include "Flexio_I2s_Ip_HwAccess.h"
#include "OsIf.h"
#include "Devassert.h"
#if (STD_ON == FLEXIO_I2S_IP_ENABLE)
#if(STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
    #include "Dma_Ip.h"
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
#endif /* (STD_ON == FLEXIO_I2S_IP_ENABLE) */


/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2S_IP_VENDOR_ID_C                    43
#define FLEXIO_I2S_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define FLEXIO_I2S_IP_AR_RELEASE_MINOR_VERSION_C     7
#define FLEXIO_I2S_IP_AR_RELEASE_REVISION_VERSION_C  0
#define FLEXIO_I2S_IP_SW_MAJOR_VERSION_C             3
#define FLEXIO_I2S_IP_SW_MINOR_VERSION_C             0
#define FLEXIO_I2S_IP_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if (STD_ON == FLEXIO_I2S_IP_ENABLE)

/* Size of 32 bit register in byte */
#define SIZE_OF_32BIT_REG       (4U)

/* Shifters/Timers used for I2S simulation The parameter x represents the
   ResourceIndex value for the current driver Instance */
#define TX_SHIFTER(x)           (x)
#define RX_SHIFTER(x)           (uint8)((x) + 1U)
#define SCK_TIMER(x)            (x)
#define WS_TIMER(x)             (uint8)((x) + 1U)
#define WS_TIMER_RISING_BLK(x)  (uint8)((x) + 2U)

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#define I2S_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2s_MemMap.h"

#if (FLEXIO_I2S_IP_NUMBER_OF_CHANNEL != 0U)
Flexio_I2s_Ip_StateType Flexio_I2s_Ip_MasterSlaveState[FLEXIO_I2S_IP_NUMBER_OF_CHANNEL];
#endif

/* Pointer to runtime Master/Slave state structures.*/
Flexio_I2s_Ip_StateType * Flexio_I2s_Ip_pxState[FLEXIO_I2S_IP_INSTANCE_COUNT][FLEXIO_I2S_IP_NUMBER_OF_CHANNEL];

#define I2S_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2s_MemMap.h"

#define I2S_START_SEC_CONST_UNSPECIFIED
#include "I2s_MemMap.h"
static FLEXIO_Type * const Flexio_I2s_Ip_pBaseAddr[FLEXIO_I2S_IP_INSTANCE_COUNT] = IP_FLEXIO_BASE_PTRS;

#define I2S_STOP_SEC_CONST_UNSPECIFIED
#include "I2s_MemMap.h"

#define I2S_START_SEC_VAR_CLEARED_8
#include "I2s_MemMap.h"
/* I2s channel init status*/
static uint8 Flexio_I2s_Ip_ChannelStatus[FLEXIO_I2S_IP_MAX_CHANNEL_COUNT];
static uint8 Flexio_I2s_Ip_ChannelMapping[FLEXIO_I2S_IP_MAX_CHANNEL_COUNT];

#define I2S_STOP_SEC_VAR_CLEARED_8
#include "I2s_MemMap.h"


#define I2S_START_SEC_CODE
#include "I2s_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
static Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_WaitTimeout(const Flexio_I2s_Ip_StateType * pState, uint32 u32Timeout)
{
    Flexio_I2s_Ip_StatusType eRet = FLEXIO_I2S_IP_STATUS_SUCCESS;

    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(u32Timeout, FLEXIO_I2S_IP_TIMEOUT_TYPE);
    uint32 u32CurrentTicks = OsIf_GetCounter(FLEXIO_I2S_IP_TIMEOUT_TYPE);
    uint32 u32ElapsedTicks = 0U;

    while ((FLEXIO_I2S_IP_STATUS_BUSY == pState->status) && (u32ElapsedTicks < u32TimeoutTicks))
    {
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, FLEXIO_I2S_IP_TIMEOUT_TYPE);
    }

    if (u32ElapsedTicks >= u32TimeoutTicks)
    {
        eRet = FLEXIO_I2S_IP_STATUS_TIMEOUT;
    }

    return eRet;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterConfigure
 * Description   : configures the FLEXIO module as I2S Master
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterConfigure(Flexio_I2s_Ip_StateType * Master,
                                          const Flexio_I2s_Ip_MasterConfigType * ConfigPtr)
{
    FLEXIO_Type *baseAddr;
    uint16 divider;
    uint16 bits;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    Flexio_I2s_Ip_TimerConfig TempTimerConfig;
    Flexio_I2s_Ip_TimerControl TempTimerControl;
    Flexio_I2s_Ip_ShifterControl ShifterControl;

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    /* Convert bytes to bits */
    bits = (uint16)(8U*((uint16)ConfigPtr->byteWidth));
    divider = ConfigPtr->DividerValue;

    /* Configure tx shifter */
    Flexio_I2s_Ip_SetShifterConfig(baseAddr,
                                TX_SHIFTER(ResourceIndex),
                                FLEXIO_SHIFTER_START_BIT_DISABLED_SH,
                                FLEXIO_SHIFTER_STOP_BIT_DISABLED,
                                FLEXIO_SHIFTER_SOURCE_PIN);
                                
    ShifterControl.Mode = FLEXIO_SHIFTER_MODE_DISABLED;
    ShifterControl.Pin = ConfigPtr->txPin;
    ShifterControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
    ShifterControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    ShifterControl.Timer = SCK_TIMER(ResourceIndex);
    ShifterControl.TimerPolarity = FLEXIO_TIMER_POLARITY_POSEDGE;
    
    Flexio_I2s_Ip_SetShifterControl(baseAddr,
                                 TX_SHIFTER(ResourceIndex),
                                 &ShifterControl);

    /* Configure rx shifter */
    Flexio_I2s_Ip_SetShifterConfig(baseAddr,
                                RX_SHIFTER(ResourceIndex),
                                FLEXIO_SHIFTER_START_BIT_DISABLED,
                                FLEXIO_SHIFTER_STOP_BIT_DISABLED,
                                FLEXIO_SHIFTER_SOURCE_PIN);
    
    ShifterControl.Mode = FLEXIO_SHIFTER_MODE_DISABLED;
    ShifterControl.Pin = ConfigPtr->rxPin;
    ShifterControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
    ShifterControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    ShifterControl.Timer = SCK_TIMER(ResourceIndex);
    ShifterControl.TimerPolarity = FLEXIO_TIMER_POLARITY_NEGEDGE;
    
    Flexio_I2s_Ip_SetShifterControl(baseAddr,
                                 RX_SHIFTER(ResourceIndex),
                                 &ShifterControl);

    /* Configure SCK timer */
    Flexio_I2s_Ip_SetTimerCompare(baseAddr, SCK_TIMER(ResourceIndex), (uint16)((uint16)(((uint16)(bits << 1U) - 1U) << 8U) + divider));
    
    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_ENABLED;                         
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_TRG_HIGH;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_NEVER;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_CLK_SHIFT_TMR;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;
    
    Flexio_I2s_Ip_SetTimerConfig(baseAddr,
                              SCK_TIMER(ResourceIndex),
                              &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)((uint8)(TX_SHIFTER(ResourceIndex) << 2U) + 1U); /* to be modified to be changed by user config */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_LOW;
    TempTimerControl.TriggerSource =FLEXIO_TRIGGER_SOURCE_INTERNAL;
    TempTimerControl.Pin = ConfigPtr->sckPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_LOW;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_OUTPUT;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;
        
    Flexio_I2s_Ip_SetTimerControl(baseAddr,
                                SCK_TIMER(ResourceIndex),
                                &TempTimerControl);

    /* Configure WS timer */

    Flexio_I2s_Ip_SetTimerCompare(baseAddr, WS_TIMER(ResourceIndex), (uint16)((bits * ((divider + 1U) * 2U)) - 1U));
    
    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_DISABLED;                         
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_TIM_ENABLE;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_NEVER;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_CLK_SHIFT_TMR;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;
    
    Flexio_I2s_Ip_SetTimerConfig(baseAddr,
                              WS_TIMER(ResourceIndex),
                              &TempTimerConfig);
    
    TempTimerControl.Trigger = (uint8)0U; /* to be modified to be changed by user config */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_HIGH;
    TempTimerControl.TriggerSource =FLEXIO_TRIGGER_SOURCE_EXTERNAL;
    TempTimerControl.Pin = ConfigPtr->wsPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_LOW;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_OUTPUT;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;
    
    Flexio_I2s_Ip_SetTimerControl(baseAddr,
                               WS_TIMER(ResourceIndex),
                               &TempTimerControl);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_SlaveConfigure
 * Description   : configures the FLEXIO module as I2S Slave
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_SlaveConfigure(const Flexio_I2s_Ip_StateType * Slave,
                                         const Flexio_I2s_Ip_SlaveConfigType * ConfigPtr)
{
    FLEXIO_Type *baseAddr;
    uint16 bits;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    Flexio_I2s_Ip_TimerConfig TempTimerConfig;
    Flexio_I2s_Ip_TimerControl TempTimerControl;
    Flexio_I2s_Ip_ShifterControl ShifterControl;

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Slave->FlexioCommon.Instance];
    ResourceIndex = Slave->FlexioCommon.ResourceIndex;
    /* Convert bytes to bits */
    bits = (uint16)(8U*((uint16)ConfigPtr->byteWidth));

    /* Configure tx shifter */
    Flexio_I2s_Ip_SetShifterConfig(baseAddr,
                                TX_SHIFTER(ResourceIndex),
                                FLEXIO_SHIFTER_START_BIT_DISABLED,
                                FLEXIO_SHIFTER_STOP_BIT_DISABLED,
                                FLEXIO_SHIFTER_SOURCE_PIN);                                
    
    ShifterControl.Mode = FLEXIO_SHIFTER_MODE_DISABLED;
    ShifterControl.Pin = ConfigPtr->txPin;
    ShifterControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
    ShifterControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    ShifterControl.Timer = WS_TIMER(ResourceIndex);
    ShifterControl.TimerPolarity = FLEXIO_TIMER_POLARITY_POSEDGE;
   
    Flexio_I2s_Ip_SetShifterControl(baseAddr,
                                 TX_SHIFTER(ResourceIndex),
                                 &ShifterControl);

    /* Configure rx shifter */
    Flexio_I2s_Ip_SetShifterConfig(baseAddr,
                                RX_SHIFTER(ResourceIndex),
                                FLEXIO_SHIFTER_START_BIT_DISABLED,
                                FLEXIO_SHIFTER_STOP_BIT_DISABLED,
                                FLEXIO_SHIFTER_SOURCE_PIN);
                                
    ShifterControl.Mode = FLEXIO_SHIFTER_MODE_DISABLED;
    ShifterControl.Pin = ConfigPtr->rxPin;
    ShifterControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
    ShifterControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    ShifterControl.Timer = WS_TIMER(ResourceIndex);
    ShifterControl.TimerPolarity = FLEXIO_TIMER_POLARITY_NEGEDGE;
    
    Flexio_I2s_Ip_SetShifterControl(baseAddr,
                                 RX_SHIFTER(ResourceIndex),
                                 &ShifterControl);

    /* Configure SCK timer */
    Flexio_I2s_Ip_SetTimerCompare(baseAddr, SCK_TIMER(ResourceIndex), (uint16)((uint16)(bits << 2U) - 3U));
    
    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_DISABLED;                         
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_PIN_POSEDGE;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_TIM_CMP;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_TRG_SHIFT_TRG;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;
    
    Flexio_I2s_Ip_SetTimerConfig(baseAddr,
                              SCK_TIMER(ResourceIndex),
                              &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)(ConfigPtr->sckPin << 1U); /* to be modified to be changed by user config */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_LOW;
    TempTimerControl.TriggerSource =FLEXIO_TRIGGER_SOURCE_INTERNAL;
    TempTimerControl.Pin = ConfigPtr->wsPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_LOW;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;
    
    Flexio_I2s_Ip_SetTimerControl(baseAddr,
                                  SCK_TIMER(ResourceIndex),
                                  &TempTimerControl);

    /* Configure WS_TIMER_RISING_BLK timer */
    Flexio_I2s_Ip_SetTimerCompare(baseAddr, WS_TIMER_RISING_BLK(ResourceIndex), (uint16)((uint16)(bits << 2U) - 4U));
    
    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_DISABLED;                         
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_PIN_POSEDGE_TRG_HIGH;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_TRG;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_PIN_SHIFT_PIN;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;
    
    Flexio_I2s_Ip_SetTimerConfig(baseAddr,
                              WS_TIMER_RISING_BLK(ResourceIndex),
                              &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)((uint8)(SCK_TIMER(ResourceIndex) << 2U) + 3U); /* to be modified to be changed by user config */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_HIGH;
    TempTimerControl.TriggerSource =FLEXIO_TRIGGER_SOURCE_INTERNAL;
    TempTimerControl.Pin = ConfigPtr->sckPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_HIGH;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;
    
    Flexio_I2s_Ip_SetTimerControl(baseAddr,
                                  WS_TIMER_RISING_BLK(ResourceIndex),
                                  &TempTimerControl);

    /* Configure WS timer */
    Flexio_I2s_Ip_SetTimerCompare(baseAddr, WS_TIMER(ResourceIndex), (uint16)((uint16)(bits << 1U) - 1U));
    
    TempTimerConfig.Start = FLEXIO_TIMER_START_BIT_DISABLED;                         
    TempTimerConfig.Stop = FLEXIO_TIMER_STOP_BIT_DISABLED;
    TempTimerConfig.Enable = FLEXIO_TIMER_ENABLE_PIN_POSEDGE_TRG_HIGH;
    TempTimerConfig.Disable = FLEXIO_TIMER_DISABLE_TIM_CMP_TRG_LOW;
    TempTimerConfig.Reset = FLEXIO_TIMER_RESET_NEVER;
    TempTimerConfig.Decrement = FLEXIO_TIMER_DECREMENT_PIN_SHIFT_PIN;
    TempTimerConfig.Output = FLEXIO_TIMER_INITOUT_ONE;
    
    Flexio_I2s_Ip_SetTimerConfig(baseAddr,
                              WS_TIMER(ResourceIndex),
                              &TempTimerConfig);

    TempTimerControl.Trigger = (uint8)((uint8)(WS_TIMER_RISING_BLK(ResourceIndex) << 2U) + 3U); /* to be modified to be changed by user config */
    TempTimerControl.TriggerPolarity = FLEXIO_TRIGGER_POLARITY_HIGH;
    TempTimerControl.TriggerSource =FLEXIO_TRIGGER_SOURCE_INTERNAL;
    TempTimerControl.Pin = ConfigPtr->sckPin;
    TempTimerControl.PinPolarity = FLEXIO_PIN_POLARITY_LOW;
    TempTimerControl.PinConfig = FLEXIO_PIN_CONFIG_DISABLED;
    TempTimerControl.Mode = FLEXIO_TIMER_MODE_DISABLED;
    
    Flexio_I2s_Ip_SetTimerControl(baseAddr,
                                  WS_TIMER(ResourceIndex),
                                  &TempTimerControl);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterEndTransfer
 * Description   : End the current transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterEndTransfer(Flexio_I2s_Ip_StateType *Master)
{
    FLEXIO_Type *baseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Disable transfer engine */
    switch (Master->driverType)
    {
        case FLEXIO_I2S_IP_DRIVER_TYPE_INTERRUPT:
            /* Disable interrupts for Rx and Tx shifters */
            Flexio_Mcl_Ip_SetShifterInterrupt(baseAddr,
                                 (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))),
                                 FALSE);
            Flexio_Mcl_Ip_SetShifterErrorInterrupt(baseAddr,
                                 (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))),
                                 FALSE);
            break;
        case FLEXIO_I2S_IP_DRIVER_TYPE_POLLING:
            /* Nothing to do here */
            break;
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
        case FLEXIO_I2S_IP_DRIVER_TYPE_DMA:
            /* Stop DMA channels */
            Flexio_Mcl_Ip_SetShifterDMARequest(baseAddr, (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))), FALSE);
            break;
#endif
        default:
            /* Impossible type - do nothing */
            break;
    }

    Master->driverIdle = TRUE;
    Master->txData = NULL_PTR;
    Master->rxData = NULL_PTR;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterEnableTransfer
 * Description   : Enables timers and shifters to start a transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterEnableTransfer(Flexio_I2s_Ip_StateType *Master)
{
    FLEXIO_Type *baseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    /* enable timers and shifters */
    Flexio_I2s_Ip_SetShifterMode(baseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_MODE_TRANSMIT);
    Flexio_I2s_Ip_SetShifterMode(baseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_MODE_RECEIVE);
    if (Master->Master)
    {
        Flexio_I2s_Ip_SetTimerMode(baseAddr, SCK_TIMER(ResourceIndex), FLEXIO_TIMER_MODE_8BIT_BAUD);
    }
    else
    {
        Flexio_I2s_Ip_SetTimerMode(baseAddr, SCK_TIMER(ResourceIndex), FLEXIO_TIMER_MODE_16BIT);
        Flexio_I2s_Ip_SetTimerMode(baseAddr, WS_TIMER_RISING_BLK(ResourceIndex), FLEXIO_TIMER_MODE_16BIT);
    }
    Flexio_I2s_Ip_SetTimerMode(baseAddr, WS_TIMER(ResourceIndex), FLEXIO_TIMER_MODE_16BIT);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterStopTransfer
 * Description   : Stops the current transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterStopTransfer(Flexio_I2s_Ip_StateType *Master)
{
    FLEXIO_Type *baseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    ResourceIndex = Master->FlexioCommon.ResourceIndex;
    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];

    /* disable timers and shifters */
    Flexio_I2s_Ip_SetShifterMode(baseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_MODE_DISABLED);
    Flexio_I2s_Ip_SetShifterMode(baseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_MODE_DISABLED);
    Flexio_I2s_Ip_SetTimerMode(baseAddr, SCK_TIMER(ResourceIndex), FLEXIO_TIMER_MODE_DISABLED);
    if (!Master->Master)
    {
        Flexio_I2s_Ip_SetTimerMode(baseAddr, WS_TIMER_RISING_BLK(ResourceIndex), FLEXIO_TIMER_MODE_DISABLED);
    }
    Flexio_I2s_Ip_SetTimerMode(baseAddr, WS_TIMER(ResourceIndex), FLEXIO_TIMER_MODE_DISABLED);
    /* Disable pin output */
    Flexio_I2s_Ip_SetShifterPinConfig(baseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_PIN_CONFIG_DISABLED);

    /* clear any leftover error flags */
    Flexio_Mcl_Ip_ClearShifterErrorStatus(baseAddr, TX_SHIFTER(ResourceIndex));
    Flexio_Mcl_Ip_ClearShifterErrorStatus(baseAddr, RX_SHIFTER(ResourceIndex));
    /* discard any leftover rx. data */
    Flexio_Mcl_Ip_ClearShifterStatus(baseAddr, RX_SHIFTER(ResourceIndex));

    /* end the transfer */
    Flexio_I2s_Ip_MasterEndTransfer(Master);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterWaitTransferEnd
 * Description   : waits for the end of a blocking transfer
 *
 *END**************************************************************************/
static Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterWaitTransferEnd(Flexio_I2s_Ip_StateType * Master, uint32 Timeout)
{
    uint32 CurrentTicks = 0u;
    uint32 ElapsedTicks = 0u;
    uint32 TimeoutTicks = OsIf_MicrosToTicks(Timeout, FLEXIO_I2S_IP_TIMEOUT_TYPE);
    Flexio_I2s_Ip_StatusType osifError = FLEXIO_I2S_IP_STATUS_SUCCESS;

    switch (Master->driverType)
    {
        case FLEXIO_I2S_IP_DRIVER_TYPE_INTERRUPT:
            /* Wait for transfer to be completed by the IRQ */
            (void)Flexio_I2s_Ip_WaitTimeout(Master, Timeout);
            break;
        case FLEXIO_I2S_IP_DRIVER_TYPE_POLLING:
            CurrentTicks = OsIf_GetCounter(FLEXIO_I2S_IP_TIMEOUT_TYPE);
            /* Call Flexio_I2s_Ip_MasterGetStatus() to do the transfer */
            do
            {
                ElapsedTicks += OsIf_GetElapsed(&CurrentTicks, FLEXIO_I2S_IP_TIMEOUT_TYPE);
            } while ((Flexio_I2s_Ip_MasterGetStatus(Master->FlexioCommon.Instance, (uint8)Master->FlexioCommon.ResourceIndex/2U, NULL_PTR) == FLEXIO_I2S_IP_STATUS_BUSY) && (ElapsedTicks < TimeoutTicks));

            if(ElapsedTicks >= TimeoutTicks)
            {
                osifError = FLEXIO_I2S_IP_STATUS_TIMEOUT;
            }
            break;
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
        case FLEXIO_I2S_IP_DRIVER_TYPE_DMA:
           /* Wait for transfer to be completed by the DMA */
            (void)Flexio_I2s_Ip_WaitTimeout(Master, Timeout);
            break;
#endif
        default:
            /* Impossible type - do nothing */
            break;
    }

    /* blocking transfer is over */
    Master->blocking = FALSE;
    if (osifError == FLEXIO_I2S_IP_STATUS_TIMEOUT)
    {
        /* abort current transfer */
        Master->status = FLEXIO_I2S_IP_STATUS_TIMEOUT;
        Flexio_I2s_Ip_MasterStopTransfer(Master);
    }

    return Master->status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_ReadData
 * Description   : reads data received by the module
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_ReadData(Flexio_I2s_Ip_StateType *Master)
{
    const FLEXIO_Type *baseAddr;
    uint32 data;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Read data from shifter buffer */
    data = Flexio_I2s_Ip_ReadShifterBuffer(baseAddr, RX_SHIFTER(ResourceIndex), FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);

    if (Master->rxRemainingWords > 0U)
    {
        if (Master->rxData != NULL_PTR)
        {
            switch (Master->byteWidth)
            {
            case 1U:
                *(uint8 *)Master->rxData = (uint8)data;
                break;
            case 2U:
                *(uint16 *)Master->rxData = (uint16)data;
                break;
            default:
                *(uint32 *)Master->rxData = (uint32)data;
                break;
            }
            /* Update rx buffer pointer */
            Master->rxData = &Master->rxData[Master->byteWidth];
        }
        /* Update remaining bytes count even if buffer is null */
        Master->rxRemainingWords -= 1U;
    }
    else
    {
        /* No data to receive, just ignore the read data */
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_WriteData
 * Description   : writes data to be transmitted by the module
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_WriteData(Flexio_I2s_Ip_StateType * Master)
{
    FLEXIO_Type *baseAddr;
    uint32 data;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* If having more data to be transferred */
    if (Master->txRemainingWords != 0U)
    {
        /* Read data from user buffer and update tx buffer pointer and remaining bytes count */
        switch (Master->byteWidth)
        {
            case 1U:
                data = (uint32)(*(const uint8 *)Master->txData);
                break;
            case 2U:
                data = (uint32)(*(const uint16 *)Master->txData);
                break;
            default:
                data = (uint32)(*(const uint32 *)Master->txData);
                break;
        }
        Master->txData = &Master->txData[Master->byteWidth];
        Master->txRemainingWords -= 1U;
        /* Write data to shifter buffer */
        /* Shift data before bit-swapping it to get the relevant bits in the lower part of the shifter */
        data <<= 32U - (uint32)(8U*((uint32)Master->byteWidth));
        Flexio_I2s_Ip_WriteShifterBuffer(baseAddr, TX_SHIFTER(ResourceIndex), data, FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterCheckStatus
 * Description   : Check status of the I2S transfer. This function can be
 *                 called either in an interrupt routine or directly in polling
 *                 mode to advance the I2S transfer.
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterCheckStatus(uint8 Instance, uint8 Channel)
{
    Flexio_I2s_Ip_StateType * Master = Flexio_I2s_Ip_pxState[Instance][Channel];
    FLEXIO_Type *baseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Check for errors */
    if (Master->txData != NULL_PTR)
    {
        if(Flexio_Mcl_Ip_GetShifterErrorStatus(baseAddr, TX_SHIFTER(ResourceIndex)))
        {
            Master->status = FLEXIO_I2S_IP_STATUS_TX_UNDERRUN;
            Flexio_Mcl_Ip_ClearShifterErrorStatus(baseAddr, TX_SHIFTER(ResourceIndex));
            /* Continue processing events */
        }
    }
    if (Master->rxData != NULL_PTR)
    {
        if (Flexio_Mcl_Ip_GetShifterErrorStatus(baseAddr, RX_SHIFTER(ResourceIndex)))
        {
            Master->status = FLEXIO_I2S_IP_STATUS_RX_OVERRUN;
            Flexio_Mcl_Ip_ClearShifterErrorStatus(baseAddr, RX_SHIFTER(ResourceIndex));
            /* Continue processing events */
        }
    }
    /* Check if data was received */
    if (Flexio_Mcl_Ip_GetShifterStatus(baseAddr, RX_SHIFTER(ResourceIndex)))
    {
        Flexio_I2s_Ip_ReadData(Master);
        if ((Master->rxData != NULL_PTR) && (Master->rxRemainingWords == 0U))
        {
            /* Out of rx space, call callback to allow user to provide a new buffer */
            if (Master->callback != NULL_PTR)
            {
                Master->callback(FLEXIO_I2S_IP_EVENT_RX_FULL, Master->callbackParam);
            }
        }
    }
    /* Check if transmitter needs more data */
    if (Master->txData != NULL_PTR)
    {
        if (Flexio_Mcl_Ip_GetShifterStatus(baseAddr, TX_SHIFTER(ResourceIndex)))
        {
            Flexio_I2s_Ip_WriteData(Master);
            if (Master->txRemainingWords == 0U)
            {
                Master->txData = NULL_PTR;
                /* Out of data, call callback to allow user to provide a new buffer */
                if (Master->callback != NULL_PTR)
                {
                    Master->callback(FLEXIO_I2S_IP_EVENT_TX_EMPTY, Master->callbackParam);
                }
                if ((Master->txRemainingWords == 0U) && (Master->driverType == FLEXIO_I2S_IP_DRIVER_TYPE_INTERRUPT))
                {
                    /* Still no more data to transmit, transmission will stop */
                    /* disable tx interrupts */
                    Flexio_Mcl_Ip_SetShifterInterrupt(baseAddr, (uint8)(1U << TX_SHIFTER(ResourceIndex)), FALSE);
                    Flexio_Mcl_Ip_SetShifterErrorInterrupt(baseAddr, (uint8)(1U << TX_SHIFTER(ResourceIndex)), FALSE);
                    /* Enable rx interrupt to signal end of transfer */
                    Flexio_Mcl_Ip_SetShifterInterrupt(baseAddr, (uint8)(1U << RX_SHIFTER(ResourceIndex)), TRUE);
                }
            }
        }
    }

    /* Check if transfer is over */
    if (Master->rxRemainingWords == 0U)
    {
        /* End transfer */
        Flexio_I2s_Ip_MasterStopTransfer(Master);
        /* Record success if there was no error */
        if (Master->status == FLEXIO_I2S_IP_STATUS_BUSY)
        {
            Master->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
        }
        /* Call callback to announce the event to the user */
        if (Master->callback != NULL_PTR)
        {
            Master->callback(FLEXIO_I2S_IP_EVENT_END_TRANSFER, Master->callbackParam);
        }
    }
}

#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterEndDmaTxTransfer
 * Description   : function called at the end of a DMA Tx transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterEndDmaTxTransfer(uint8 Instance,
                                                 const uint8 FlexIOChannel)
{
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    Flexio_I2s_Ip_StateType *State = NULL_PTR;
    uint8 ChannelIndex;

    if (0U != Flexio_I2s_Ip_ChannelStatus[FlexIOChannel])
    {
        ChannelIndex = Flexio_I2s_Ip_ChannelMapping[FlexIOChannel];
        State = Flexio_I2s_Ip_pxState[Instance][ChannelIndex];
        ResourceIndex = State->FlexioCommon.ResourceIndex;
        if (FlexIOChannel == TX_SHIFTER(ResourceIndex))
        {
            if (State->callback != NULL_PTR)
            {
                State->callback(FLEXIO_I2S_IP_EVENT_TX_EMPTY, State->callbackParam);
            }

            if (State->txRemainingWords == 0U)
            {
                /* No more data to transmit, transmission will stop */
                State->txData = NULL_PTR;
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterEndDmaRxTransfer
 * Description   : function called at the end of a DMA Tx transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterEndDmaRxTransfer(uint8 Instance,
                                                 const uint8 FlexIOChannel)
{
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    Flexio_I2s_Ip_StateType *State = NULL_PTR;
    uint8 ChannelIndex;

    if (0U != Flexio_I2s_Ip_ChannelStatus[FlexIOChannel])
    {
        ChannelIndex = Flexio_I2s_Ip_ChannelMapping[FlexIOChannel];
        State = Flexio_I2s_Ip_pxState[Instance][ChannelIndex];
        ResourceIndex = State->FlexioCommon.ResourceIndex;
        if (FlexIOChannel == RX_SHIFTER(ResourceIndex))
        {
            if (State->rxData != NULL_PTR)
            {
                if (State->callback != NULL_PTR)
                {
                    State->callback(FLEXIO_I2S_IP_EVENT_RX_FULL, State->callbackParam);
                }
            }

            if (State->rxRemainingWords == 0U)
            {
                /* End transfer */
                Flexio_I2s_Ip_MasterStopTransfer(State);
                /* No more data, end transfer */
                if (State->status == FLEXIO_I2S_IP_STATUS_BUSY)
                {
                    State->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
                }
                /* Call callback to announce the event to the user */
                if (State->callback != NULL_PTR)
                {
                    State->callback(FLEXIO_I2S_IP_EVENT_END_TRANSFER, State->callbackParam);
                }
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterStartDmaTransfer
 * Description   : Starts a DMA transfer
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_MasterStartDmaTransfer(Flexio_I2s_Ip_StateType * Master)
{
    uint8 ShifterMask = 0u;
    FLEXIO_Type * baseAddr;
    Dma_Ip_LogicChannelTransferListType DmaTransferList[10u];
    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    const uint8 DmaTransferSize[SIZE_OF_32BIT_REG] = { DMA_IP_TRANSFER_SIZE_1_BYTE, DMA_IP_TRANSFER_SIZE_2_BYTE, DMA_IP_TRANSFER_SIZE_4_BYTE, DMA_IP_TRANSFER_SIZE_4_BYTE };
    const uint8 ResourceIndex = Master->FlexioCommon.ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    DmaTransferList[0u].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    DmaTransferList[1u].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    DmaTransferList[2u].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    DmaTransferList[3u].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    DmaTransferList[4u].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    DmaTransferList[5u].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    DmaTransferList[6u].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    DmaTransferList[7u].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
    DmaTransferList[8u].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    DmaTransferList[9u].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;

    DmaTransferList[2u].Value = DmaTransferSize[Master->byteWidth - 1u];
    DmaTransferList[5u].Value = DmaTransferSize[Master->byteWidth - 1u];
    DmaTransferList[6u].Value = Master->byteWidth; /* Size of buffer */
    DmaTransferList[8u].Value = 1U;
    DmaTransferList[9u].Value = 1U;

    if (Master->txData != NULL_PTR)
    {
        /* Configure DMA channel for send transfers */
        /* Source/Destination configuration values */
        DmaTransferList[0u].Value = (uint32)(&(Master->txData[0U]));
        DmaTransferList[1u].Value = Master->byteWidth; /* Size of buffer */
        /* The bytes to be transferred are actually in SHIFBUF but data is written in SHIFTBUFBIS with bits are swapped
        So the offset for DMA to copy to SHIFTBUFBIS is swapped also
        Therefore, the correct offset = size of register (4bytes) - byteWidth */
        DmaTransferList[3u].Value = (uint32)(&(baseAddr->SHIFTBUFBIS[TX_SHIFTER(ResourceIndex)])) + (SIZE_OF_32BIT_REG - (uint32)Master->byteWidth);
        DmaTransferList[4u].Value = 0U;
        DmaTransferList[7u].Value = Master->txRemainingWords;

        /* Now that this tx is set up, clear remaining bytes count */
        Master->txRemainingWords = 0U;
        (void)Dma_Ip_SetLogicChannelTransferList(Master->txDMAChannel, DmaTransferList, 10u);
        /* Start DMA channel */
        (void)Dma_Ip_SetLogicChannelCommand(Master->txDMAChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);
        ShifterMask = (1U << TX_SHIFTER(ResourceIndex));
    }

    /* Configure DMA channel for receive transfers*/
    /* Source/Destination configuration values */
    DmaTransferList[0u].Value = (uint32) (&(baseAddr->SHIFTBUFBIS[RX_SHIFTER(ResourceIndex)]));
    DmaTransferList[1u].Value = 0U;
    if (Master->rxData != NULL_PTR)
    {
        DmaTransferList[3u].Value = (uint32)(&(Master->rxData[0]));
        DmaTransferList[4u].Value = Master->byteWidth; /* Size of buffer */
    }
    else
    {
        DmaTransferList[3u].Value = (uint32)(&(Master->dummyDmaData));
        DmaTransferList[4u].Value = 0U;
    }
    DmaTransferList[7u].Value = Master->rxRemainingWords;

    /* Now that this rx is set up, clear remaining bytes count */
    Master->rxRemainingWords = 0U;
    (void)Dma_Ip_SetLogicChannelTransferList(Master->rxDMAChannel, DmaTransferList, 10u);
    /* Start DMA channel */
    (void)Dma_Ip_SetLogicChannelCommand(Master->rxDMAChannel, DMA_IP_CH_SET_HARDWARE_REQUEST);

    ShifterMask |= (1U << RX_SHIFTER(ResourceIndex));

    Flexio_Mcl_Ip_SetShifterDMARequest(baseAddr, ShifterMask, TRUE);

}
#endif /* #if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_ResourcesInit
 * Description   : Initializes the resources for the current driver
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_ResourcesInit(uint8 Instance,
                                        const Flexio_I2s_Ip_CommonStateType *Driver)
{
    uint8 Resource;
    uint8 ResourceCount;
    uint8 ResourceIndex;
    FLEXIO_Type *BaseAddr;

    BaseAddr = Flexio_I2s_Ip_pBaseAddr[Instance];
    ResourceCount = Driver->ResourceCount;
    ResourceIndex = Driver->ResourceIndex;
    for (Resource = ResourceIndex; Resource < (ResourceIndex + ResourceCount); Resource++)
    {
        /* Ensure all shifters/timers are disabled */
        Flexio_I2s_Ip_SetShifterMode(BaseAddr, Resource, FLEXIO_SHIFTER_MODE_DISABLED);
        Flexio_I2s_Ip_SetTimerMode(BaseAddr, Resource, FLEXIO_TIMER_MODE_DISABLED);
        /* Ensure all interrupts and DMA requests are disabled */
        Flexio_Mcl_Ip_SetShifterInterrupt(BaseAddr, (uint8)(1U << Resource), FALSE);
        Flexio_Mcl_Ip_SetShifterErrorInterrupt(BaseAddr, (uint8)(1U << Resource), FALSE);
        Flexio_Mcl_Ip_SetTimerInterrupt(BaseAddr, (uint8)(1U << Resource), FALSE);
        Flexio_Mcl_Ip_SetShifterDMARequest(BaseAddr, (uint8)(1U << Resource), FALSE);
        /* Clear any leftover flags */
        Flexio_Mcl_Ip_ClearShifterStatus(BaseAddr, Resource);
        Flexio_Mcl_Ip_ClearShifterErrorStatus(BaseAddr, Resource);
        Flexio_Mcl_Ip_ClearTimerStatus(BaseAddr, Resource);
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_InitDriver
 * Description   : Initializes an Instance of FlexIO driver
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_InitDriver(uint8 Instance,
                                     uint8 Channel,
                                     const Flexio_I2s_Ip_CommonStateType * Driver)
{
    uint8 Index;
    const uint8 ResourceIndex = (uint8)(Driver->ResourceIndex);
    const uint8 ResourceCount = 2U; /* Only TX and RX Channel create event */

    for (Index = 0U; Index < ResourceCount; Index++)
    {
        /* Shifter/Timer Channel is being used */
        Flexio_I2s_Ip_ChannelStatus[ResourceIndex + Index] = 1U;
        /* Mapping Shifter/Timer Channel with Hardware Channel */
        Flexio_I2s_Ip_ChannelMapping[ResourceIndex + Index] = Channel;
    }

    /* initialize the allocated resources */
    Flexio_I2s_Ip_ResourcesInit(Instance, Driver);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_DeinitDriver
 * Description   : De-initializes an Instance of FlexIO driver
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_DeinitDriver(const Flexio_I2s_Ip_CommonStateType * Driver)
{
    uint8 Index;
    const uint8 ResourceIndex = (uint8)(Driver->ResourceIndex);
    const uint8 ResourceCount = 2U; /* Only TX and RX Channel create event */

    for (Index = 0U; Index < ResourceCount; Index++)
    {
        Flexio_I2s_Ip_ChannelStatus[ResourceIndex + Index] = 0U;
        Flexio_I2s_Ip_ChannelMapping[ResourceIndex + Index] = 0U;
    }
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterInit
 * Description   : Initialize the FLEXIO_I2S Master mode driver
 * @implements Flexio_I2s_Ip_MasterInit_Activity
 *
 *END**************************************************************************/
void Flexio_I2s_Ip_MasterInit(uint8 Instance,
                              uint8 Channel,
                              const Flexio_I2s_Ip_MasterConfigType * ConfigPtr)
{
    Flexio_I2s_Ip_StateType * Master;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(ConfigPtr != NULL_PTR);
    DevAssert(Flexio_I2s_Ip_pxState[Instance][Channel] == NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
#endif

    Flexio_I2s_Ip_pxState[Instance][Channel] = ConfigPtr->MasterState;
    Master = Flexio_I2s_Ip_pxState[Instance][Channel];

    /* Instruct the resource allocator that we need two shifters/timers */
    Master->FlexioCommon.ResourceCount = 2U;
    Master->FlexioCommon.ResourceIndex = ConfigPtr->ResourceIndex;

    /* Common FlexIO driver initialization */
    Flexio_I2s_Ip_InitDriver(Instance, Channel, &(Master->FlexioCommon));

    /* Initialize driver-specific context structure */
    Master->driverType = ConfigPtr->driverType;
    Master->byteWidth = ConfigPtr->byteWidth;
    Master->driverIdle = TRUE;
    Master->callback = ConfigPtr->callback;
    Master->callbackParam = ConfigPtr->callbackParam;
    Master->blocking = FALSE;
    Master->txData = NULL_PTR;
    Master->txRemainingWords = 0U;
    Master->rxData = NULL_PTR;
    Master->rxRemainingWords = 0U;
    Master->Master = TRUE;
    Master->status = FLEXIO_I2S_IP_STATUS_SUCCESS;

    /* Configure device for I2S mode */
    Flexio_I2s_Ip_MasterConfigure(Master, ConfigPtr);

    /* Set up transfer engine */
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
    if (FLEXIO_I2S_IP_DRIVER_TYPE_DMA == Master->driverType)
    {
        Master->txDMAChannel = ConfigPtr->txDMAChannel;
        Master->rxDMAChannel = ConfigPtr->rxDMAChannel;
    }
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterDeinit
 * Description   : De-initialize the FLEXIO_I2S Master mode driver
 * @implements Flexio_I2s_Ip_MasterDeinit_Activity
 *
 *END**************************************************************************/
void Flexio_I2s_Ip_MasterDeinit(uint8 Instance, uint8 Channel)
{
    const Flexio_I2s_Ip_StateType * Master = Flexio_I2s_Ip_pxState[Instance][Channel];

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
#endif

    /* Check if Driver is busy */
    if (Master->driverIdle)
    {
        Flexio_I2s_Ip_DeinitDriver(&(Master->FlexioCommon));
        Flexio_I2s_Ip_pxState[Instance][Channel] = NULL_PTR;
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterSendData
 * Description   : Perform a non-blocking send transaction on the I2S bus
 * @implements Flexio_I2s_Ip_MasterSendData_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterSendData(uint8 Instance, uint8 Channel,
                                                      const uint8 * TxBuff,
                                                      uint32 TxSize)
{
    Flexio_I2s_Ip_StateType * Master = Flexio_I2s_Ip_pxState[Instance][Channel];

    FLEXIO_Type *baseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    Flexio_I2s_Ip_StatusType RetStatus = FLEXIO_I2S_IP_STATUS_SUCCESS;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
    DevAssert(TxBuff != NULL_PTR);
    DevAssert(TxSize > 0U);
#endif

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Check if driver is busy */
    if (Master->driverIdle == FALSE)
    {
        RetStatus = FLEXIO_I2S_IP_STATUS_BUSY;
    }
    else
    {
        Master->txData = TxBuff;
        Master->txRemainingWords = TxSize;
        /* also count received data, it tells us when tx is actually completed */
        Master->rxRemainingWords = TxSize;
        Master->rxData = NULL_PTR;
        Master->status = FLEXIO_I2S_IP_STATUS_BUSY;
        Master->driverIdle = FALSE;

        /* Enable pin output */
        Flexio_I2s_Ip_SetShifterPinConfig(baseAddr, TX_SHIFTER(ResourceIndex), FLEXIO_PIN_CONFIG_OUTPUT);
        /* Enable timers and shifters */
        Flexio_I2s_Ip_MasterEnableTransfer(Master);
        /* Enable transfer engine */
        switch (Master->driverType)
        {
            case FLEXIO_I2S_IP_DRIVER_TYPE_INTERRUPT:
                /* Enable interrupts for Tx shifter */
                Flexio_Mcl_Ip_SetShifterInterrupt(baseAddr,
                                     (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))),
                                     TRUE);
                Flexio_Mcl_Ip_SetShifterErrorInterrupt(baseAddr,
                                     (uint8)((1U << TX_SHIFTER(ResourceIndex)) | (1U << RX_SHIFTER(ResourceIndex))),
                                     TRUE);
                break;
            case FLEXIO_I2S_IP_DRIVER_TYPE_POLLING:
                /* Call Flexio_I2s_Ip_MasterCheckStatus once to send the first byte */
                Flexio_I2s_Ip_MasterCheckStatus(Instance, Channel);
                break;
    #if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
            case FLEXIO_I2S_IP_DRIVER_TYPE_DMA:
                Flexio_I2s_Ip_MasterStartDmaTransfer(Master);
                break;
    #endif
            default:
                /* Impossible type - do nothing */
                break;
        }
    }

    return RetStatus;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterSendDataBlocking
 * Description   : Perform a blocking send transaction on the I2S bus
 * @implements Flexio_I2s_Ip_MasterSendDataBlocking_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterSendDataBlocking(uint8 Instance, uint8 Channel,
                                                              const uint8 * TxBuff,
                                                              uint32 TxSize,
                                                              uint32 Timeout)
{
    Flexio_I2s_Ip_StateType * Master = Flexio_I2s_Ip_pxState[Instance][Channel];
    Flexio_I2s_Ip_StatusType RetStatus;

    /* Check if driver is busy */
    if (Master->driverIdle == FALSE)
    {
        RetStatus = FLEXIO_I2S_IP_STATUS_BUSY;
    }
    else
    {
        /* mark transfer as blocking */
        if (Master->driverType != FLEXIO_I2S_IP_DRIVER_TYPE_POLLING)
        {
            Master->blocking = TRUE;
        }
        /* Call Flexio_I2s_Ip_MasterSendData to start transfer */
        (void)Flexio_I2s_Ip_MasterSendData(Instance, Channel, TxBuff, TxSize);
        /* Wait for transfer to end */
        RetStatus = Flexio_I2s_Ip_MasterWaitTransferEnd(Master, Timeout);
    }

    return RetStatus;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterReceiveData
 * Description   : Perform a non-blocking receive transaction on the I2S bus
 * @implements Flexio_I2s_Ip_MasterReceiveData_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterReceiveData(uint8 Instance, uint8 Channel,
                                                         uint8 * RxBuff,
                                                         uint32 RxSize)
{
    Flexio_I2s_Ip_StateType * Master = Flexio_I2s_Ip_pxState[Instance][Channel];

    FLEXIO_Type *baseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    Flexio_I2s_Ip_StatusType RetStatus = FLEXIO_I2S_IP_STATUS_SUCCESS;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
    DevAssert(RxBuff != NULL_PTR);
    DevAssert(RxSize > 0U);
#endif

    baseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Check if driver is busy */
    if (Master->driverIdle == FALSE)
    {
        RetStatus = FLEXIO_I2S_IP_STATUS_BUSY;
    }
    else
    {
        Master->rxData = RxBuff;
        Master->rxRemainingWords = RxSize;
        Master->txData = NULL_PTR;
        Master->txRemainingWords = 0U;
        Master->status = FLEXIO_I2S_IP_STATUS_BUSY;
        Master->driverIdle = FALSE;

        /* Enable timers and shifters */
        Flexio_I2s_Ip_MasterEnableTransfer(Master);

        /* Enable transfer engine */
        switch (Master->driverType)
        {
            case FLEXIO_I2S_IP_DRIVER_TYPE_INTERRUPT:
                /* Enable interrupts for Rx shifter */
                Flexio_Mcl_Ip_SetShifterInterrupt(baseAddr,
                                     (uint8)(1U << RX_SHIFTER(ResourceIndex)),
                                     TRUE);
                Flexio_Mcl_Ip_SetShifterErrorInterrupt(baseAddr,
                                     (uint8)(1U << RX_SHIFTER(ResourceIndex)),
                                     TRUE);
                break;
            case FLEXIO_I2S_IP_DRIVER_TYPE_POLLING:
                /* Call Flexio_I2s_Ip_MasterCheckStatus once to send the first byte */
                Flexio_I2s_Ip_MasterCheckStatus(Instance, Channel);
                break;
    #if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
            case FLEXIO_I2S_IP_DRIVER_TYPE_DMA:
                Flexio_I2s_Ip_MasterStartDmaTransfer(Master);
                break;
    #endif
            default:
                /* Impossible type - do nothing */
                break;
        }

        /* For Master we need to send a dummy char to start the clock.
           For Slave just put a 0 in the buffer to keep the tx line clear while receiving. */
        Flexio_I2s_Ip_WriteShifterBuffer(baseAddr, TX_SHIFTER(ResourceIndex), 0x0, FLEXIO_SHIFTER_RW_MODE_BIT_SWAP);
    }

    return RetStatus;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterReceiveDataBlocking
 * Description   : Perform a blocking receive transaction on the I2S bus
 * @implements Flexio_I2s_Ip_MasterReceiveDataBlocking_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterReceiveDataBlocking(uint8 Instance, uint8 Channel,
                                                                 uint8 * RxBuff,
                                                                 uint32 RxSize,
                                                                 uint32 Timeout)
{
    Flexio_I2s_Ip_StateType * Master = Flexio_I2s_Ip_pxState[Instance][Channel];
    Flexio_I2s_Ip_StatusType RetStatus;

    /* Check if driver is busy */
    if (Master->driverIdle == FALSE)
    {
        RetStatus = FLEXIO_I2S_IP_STATUS_BUSY;
    }
    else
    {
        /* mark transfer as blocking */
        if (Master->driverType != FLEXIO_I2S_IP_DRIVER_TYPE_POLLING)
        {
            Master->blocking = TRUE;
        }
        /* Call Flexio_I2s_Ip_MasterReceiveData to start transfer */
        (void)Flexio_I2s_Ip_MasterReceiveData(Instance, Channel, RxBuff, RxSize);
        
        /* Wait for transfer to end */
        RetStatus = Flexio_I2s_Ip_MasterWaitTransferEnd(Master, Timeout);
    }

    return RetStatus;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterTransferAbort
 * Description   : Aborts a non-blocking I2S Master transaction
 * @implements Flexio_I2s_Ip_MasterTransferAbort_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterTransferAbort(uint8 Instance, uint8 Channel)
{
    Flexio_I2s_Ip_StateType * Master = Flexio_I2s_Ip_pxState[Instance][Channel];
    Flexio_I2s_Ip_StatusType t_Return = FLEXIO_I2S_IP_STATUS_SUCCESS;
    
#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
#endif
    if (FLEXIO_I2S_IP_STATUS_UNINIT != Master->status)
    {
#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
        DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
        DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
#endif
        /* Check if driver is busy */
        if (Master->driverIdle)
        {
            t_Return = FLEXIO_I2S_IP_STATUS_SUCCESS;
        }

        Master->status = FLEXIO_I2S_IP_STATUS_ABORTED;
        Flexio_I2s_Ip_MasterStopTransfer(Master);
    }
    else
    {
        t_Return = FLEXIO_I2S_IP_STATUS_UNINIT;
    }
    return t_Return;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterGetStatus
 * Description   : Get the status of the current non-blocking I2S Master transaction
 * @implements Flexio_I2s_Ip_MasterGetStatus_Activity
 *
 *END**************************************************************************/
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_MasterGetStatus(uint8 Instance, uint8 Channel, uint32 *BytesRemaining)
{
    const Flexio_I2s_Ip_StateType * Master = Flexio_I2s_Ip_pxState[Instance][Channel];
    uint32 RemainingWords = 0u;
    Flexio_I2s_Ip_StatusType RetStatus;
    boolean IsChannelIdle;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(Master != NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
#endif

    RetStatus = Master->status;
    if(RetStatus != FLEXIO_I2S_IP_STATUS_UNINIT)
    {
        IsChannelIdle = Master->driverIdle;
        if (IsChannelIdle == FALSE)
        {
            switch(Master->driverType)
            {
            case FLEXIO_I2S_IP_DRIVER_TYPE_POLLING:
                /* In polling mode advance the I2S transfer here */
                Flexio_I2s_Ip_MasterCheckStatus(Instance, Channel);
                RemainingWords = Master->rxRemainingWords;
                break;
#if(STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
            case FLEXIO_I2S_IP_DRIVER_TYPE_DMA:
                /* In DMA mode just update the remaining count.
                DO NOT write Master->rxRemainingWords directly !!! */
                (void)Dma_Ip_GetLogicChannelParam(Master->rxDMAChannel, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &RemainingWords);
                break;
#endif
            default: /* Interrupt */
                RemainingWords = Master->rxRemainingWords;
                break;
            }
        }

        if (RetStatus == FLEXIO_I2S_IP_STATUS_ABORTED)
        {
#if(STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
            if(Master->driverType == FLEXIO_I2S_IP_DRIVER_TYPE_DMA)
            {
            /* DO NOT write Master->rxRemainingWords directly !!! */
            (void)Dma_Ip_GetLogicChannelParam(Master->rxDMAChannel, DMA_IP_CH_GET_CURRENT_ITER_COUNT, &RemainingWords);            
            }
            else
#endif
            {
                RemainingWords = Master->rxRemainingWords;
            }
        }
        
        /* Use rxRemainingWords even for transmit; byte is not transmitted
        until rx shifter reports a receive event */
        if (BytesRemaining != NULL_PTR)
        {
            *BytesRemaining = RemainingWords;
        }

        if (IsChannelIdle == FALSE)
        {
            RetStatus = FLEXIO_I2S_IP_STATUS_BUSY;
        }
    }
    else
    {
        /* Driver uninitialized, do nothing. */
    }
    return RetStatus;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_SlaveInit
 * Description   : Initialize the FLEXIO_I2S Slave mode driver
 * @implements Flexio_I2s_Ip_SlaveInit_Activity
 *
 *END**************************************************************************/
void Flexio_I2s_Ip_SlaveInit(uint8 Instance,
                             uint8 Channel,
                             const Flexio_I2s_Ip_SlaveConfigType * ConfigPtr)
{
    Flexio_I2s_Ip_StateType * Slave;

#if (STD_ON == FLEXIO_I2S_IP_DEV_ERROR_DETECT)
    DevAssert(ConfigPtr != NULL_PTR);
    DevAssert(Flexio_I2s_Ip_pxState[Instance][Channel] == NULL_PTR);
    DevAssert(Instance < FLEXIO_INSTANCE_COUNT);
    DevAssert(Channel < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL);
#endif

    Flexio_I2s_Ip_pxState[Instance][Channel] = ConfigPtr->SlaveState;
    Slave =  Flexio_I2s_Ip_pxState[Instance][Channel];

    /* Instruct the resource allocator that we need three shifters/timers */
    Slave->FlexioCommon.ResourceCount = 3U;
    Slave->FlexioCommon.ResourceIndex = ConfigPtr->ResourceIndex;

    /* Common FlexIO driver initialization */
    Flexio_I2s_Ip_InitDriver(Instance, Channel, &(Slave->FlexioCommon));

    /* Initialize driver-specific context structure */
    Slave->driverType = ConfigPtr->driverType;
    Slave->byteWidth = ConfigPtr->byteWidth;
    Slave->driverIdle = TRUE;
    Slave->callback = ConfigPtr->callback;
    Slave->callbackParam = ConfigPtr->callbackParam;
    Slave->blocking = FALSE;
    Slave->txData = NULL_PTR;
    Slave->txRemainingWords = 0U;
    Slave->rxData = NULL_PTR;
    Slave->rxRemainingWords = 0U;
    Slave->Master = FALSE;
    Slave->status = FLEXIO_I2S_IP_STATUS_SUCCESS;

    /* Configure device for I2S mode */
    Flexio_I2s_Ip_SlaveConfigure(Slave, ConfigPtr);

    /* Set up transfer engine */
#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
    if (FLEXIO_I2S_IP_DRIVER_TYPE_DMA == Slave->driverType)
    {
        Slave->txDMAChannel = ConfigPtr->txDMAChannel;
        Slave->rxDMAChannel = ConfigPtr->rxDMAChannel;
    }
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */
}


/*!
 * @brief De-initialize the FLEXIO_I2S Slave mode driver
 *
 * This function de-initializes the FLEXIO_I2S driver in Slave mode. The driver can't be used
 * again until reinitialized. The context structure is no longer needed by the driver and
 * can be freed after calling this function.
 *
 * @param Slave    Pointer to the FLEXIO_I2S Slave driver context structure.
 * @return    Error or success status returned by API
 * @implements Flexio_I2s_Ip_SlaveDeinit_Activity
 */
void Flexio_I2s_Ip_SlaveDeinit(uint8 Instance, uint8 Channel)
{
    Flexio_I2s_Ip_MasterDeinit(Instance, Channel);
}


/*!
 * @brief Perform a non-blocking send transaction on the I2S bus
 *
 * This function starts the transmission of a block of data and returns immediately.
 * The rest of the transmission is handled by the interrupt service routine (if the driver
 * is initialized in interrupt mode) or by the Flexio_I2s_Ip_SlaveGetStatus function (if
 * the driver is initialized in polling mode).
 * Use Flexio_I2s_Ip_SlaveGetStatus() to check the progress of the transmission.
 *
 * @param Slave    Pointer to the FLEXIO_I2S Slave driver context structure.
 * @param TxBuff    pointer to the data to be transferred
 * @param TxSize    length in bytes of the data to be transferred
 * @return    Error or success status returned by API
 * @implements Flexio_I2s_Ip_SlaveSendData_Activity
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveSendData(uint8 Instance, uint8 Channel,
                                                     const uint8 * TxBuff,
                                                     uint32 TxSize)
{
    return Flexio_I2s_Ip_MasterSendData(Instance, Channel, TxBuff, TxSize);
}


/*!
 * @brief Perform a blocking send transaction on the I2S bus
 *
 * This function sends a block of data, and
 * only returns when the transmission is complete.
 *
 * @param Slave    Pointer to the FLEXIO_I2S Slave driver context structure.
 * @param TxBuff    pointer to the data to be transferred
 * @param TxSize    length in bytes of the data to be transferred
 * @param Timeout  Timeout for the transfer in milliseconds
 * @return    Error or success status returned by API
 * @implements Flexio_I2s_Ip_SlaveSendDataBlocking_Activity
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveSendDataBlocking(uint8 Instance, uint8 Channel,
                                                             const uint8 * TxBuff,
                                                             uint32 TxSize,
                                                             uint32 Timeout)
{
    return Flexio_I2s_Ip_MasterSendDataBlocking(Instance, Channel, TxBuff, TxSize, Timeout);
}


/*!
 * @brief Perform a non-blocking receive transaction on the I2S bus
 *
 * This function starts the reception of a block of data and returns immediately.
 * The rest of the reception is handled by the interrupt service routine (if the driver
 * is initialized in interrupt mode) or by the Flexio_I2s_Ip_SlaveGetStatus function (if
 * the driver is initialized in polling mode).
 * Use Flexio_I2s_Ip_SlaveGetStatus() to check the progress of the reception.
 *
 * @param Slave    Pointer to the FLEXIO_I2S Slave driver context structure.
 * @param RxBuff    pointer to the buffer where to store received data
 * @param RxSize    length in bytes of the data to be transferred
 * @return    Error or success status returned by API
 * @implements Flexio_I2s_Ip_SlaveReceiveData_Activity
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveReceiveData(uint8 Instance, uint8 Channel,
                                                        uint8 * RxBuff,
                                                        uint32 RxSize)
{
    return Flexio_I2s_Ip_MasterReceiveData(Instance, Channel, RxBuff, RxSize);
}


/*!
 * @brief Perform a blocking receive transaction on the I2S bus
 *
 * This function receives a block of data and only returns when the reception is complete.
 *
 * @param Slave    Pointer to the FLEXIO_I2S Slave driver context structure.
 * @param RxBuff    pointer to the buffer where to store received data
 * @param RxSize    length in bytes of the data to be transferred
 * @param Timeout  Timeout for the transfer in milliseconds
 * @return    Error or success status returned by API
 * @implements Flexio_I2s_Ip_SlaveReceiveDataBlocking_Activity
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveReceiveDataBlocking(uint8 Instance, uint8 Channel,
                                                                uint8 * RxBuff,
                                                                uint32 RxSize,
                                                                uint32 Timeout)
{
    return Flexio_I2s_Ip_MasterReceiveDataBlocking(Instance, Channel, RxBuff, RxSize, Timeout);
}


/*!
 * @brief Aborts a non-blocking I2S Slave transaction
 *
 * This function aborts a non-blocking I2S transfer.
 *
 * @param Slave    Pointer to the FLEXIO_I2S Slave driver context structure.
 * @return    Error or success status returned by API
 * @implements Flexio_I2s_Ip_SlaveTransferAbort_Activity
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveTransferAbort(uint8 Instance, uint8 Channel)
{
    return Flexio_I2s_Ip_MasterTransferAbort(Instance, Channel);
}


/*!
 * @brief Get the status of the current non-blocking I2S Slave transaction
 *
 * This function returns the current status of a non-blocking I2S Slave transaction.
 * A return code of FLEXIO_I2S_IP_STATUS_BUSY means the transfer is still in progress.
 * Otherwise the function returns a status reflecting the outcome of the last transfer.
 * When the driver is initialized in polling mode this function also advances the transfer
 * by checking and handling the transmit and receive events, so it must be called
 * frequently to avoid overflows or underflows.
 *
 * @param Slave    Pointer to the FLEXIO_I2S Slave driver context structure.
 * @param BytesRemaining  the remaining number of bytes to be transferred
 * @return    Error or success status returned by API
 * @implements Flexio_I2s_Ip_SlaveGetStatus_Activity
 */
Flexio_I2s_Ip_StatusType Flexio_I2s_Ip_SlaveGetStatus(uint8 Instance, uint8 Channel, uint32 *BytesRemaining)
{
    return Flexio_I2s_Ip_MasterGetStatus(Instance, Channel, BytesRemaining);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_MasterCheckEvent
 * Description   : Check if event had occurred for selected FlexIO channel
 *
 *END**************************************************************************/
static boolean Flexio_I2s_Ip_MasterCheckEvent(uint8 StatusMask,
                                              uint8 Channel)
{
    return ((((((uint32)StatusMask) >> Channel) & 1U) == 1U) ? TRUE : FALSE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_TransmitEventHandler
 * Description   : handler for transmit event
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_TransmitEventHandler(Flexio_I2s_Ip_StateType *Master,
                                               uint8 ShifterMaskFlag,
                                               uint8 ShifterErrMaskFlag,
                                               uint8 TimerMaskFlag)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    BaseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    /* Handle events for TX shifter or SCK timer */
    if(Flexio_I2s_Ip_MasterCheckEvent(ShifterErrMaskFlag, TX_SHIFTER(ResourceIndex)))
    {
        if (TRUE == Flexio_I2s_Ip_GetShifterErrorInterrupt(BaseAddr, TX_SHIFTER(ResourceIndex)))
        {
            Master->status = FLEXIO_I2S_IP_STATUS_TX_UNDERRUN;
            /* don't stop the transfer, continue processing events */
        }
    }

    /* Check if transmitter needs more data */
    if (Flexio_I2s_Ip_MasterCheckEvent(ShifterMaskFlag, TX_SHIFTER(ResourceIndex)))
    {
        if (TRUE == Flexio_I2s_Ip_GetShifterInterrupt(BaseAddr, TX_SHIFTER(ResourceIndex)))
        {
            Flexio_I2s_Ip_WriteData(Master);
            if (0U == Master->txRemainingWords)
            {
                /* Done transmitting, disable Tx interrupt */
                Flexio_Mcl_Ip_SetShifterInterrupt(BaseAddr, (uint8)(1U << TX_SHIFTER(ResourceIndex)), FALSE);
                Flexio_Mcl_Ip_SetShifterErrorInterrupt(BaseAddr, (uint8)(1U << TX_SHIFTER(ResourceIndex)), FALSE);
            }
        }
    }

    /* Check if the transfer is over */
    if (Flexio_I2s_Ip_MasterCheckEvent(TimerMaskFlag, SCK_TIMER(ResourceIndex)))
    {
        if (TRUE == Flexio_Mcl_Ip_GetTimerInterruptEnable(BaseAddr,SCK_TIMER(ResourceIndex)))
        {
            if (Master->callback != NULL_PTR)
            {
                Master->callback(FLEXIO_I2S_IP_EVENT_END_TRANSFER, Master->callbackParam);
            }
        }
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Flexio_I2s_Ip_ReceiveEventHandler
 * Description   : handler for receive event
 *
 *END**************************************************************************/
static void Flexio_I2s_Ip_ReceiveEventHandler(Flexio_I2s_Ip_StateType *Master,
                                              uint8 ShifterMaskFlag,
                                              uint8 ShifterErrMaskFlag)
{
    FLEXIO_Type *BaseAddr;
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */

    BaseAddr = Flexio_I2s_Ip_pBaseAddr[Master->FlexioCommon.Instance];
    ResourceIndex = Master->FlexioCommon.ResourceIndex;

    if (Flexio_I2s_Ip_MasterCheckEvent(ShifterErrMaskFlag, RX_SHIFTER(ResourceIndex)))
    {
        if (TRUE == Flexio_I2s_Ip_GetShifterErrorInterrupt(BaseAddr, RX_SHIFTER(ResourceIndex)))
        {
            Master->status = FLEXIO_I2S_IP_STATUS_RX_OVERRUN;
            /* don't stop the transfer, continue processing events */
        }
    }

    /* Check if data was received */
    if (TRUE == Flexio_I2s_Ip_MasterCheckEvent(ShifterMaskFlag, RX_SHIFTER(ResourceIndex)))
    {
        if (TRUE == Flexio_I2s_Ip_GetShifterInterrupt(BaseAddr, RX_SHIFTER(ResourceIndex)))
        {
            Flexio_I2s_Ip_ReadData(Master);
        }
    }

    /* Check if transfer is over */
    if (Master->rxRemainingWords == 0U)
    {
        /* Record success if there was no error */
        if (Master->status == FLEXIO_I2S_IP_STATUS_BUSY)
        {
            Master->status = FLEXIO_I2S_IP_STATUS_SUCCESS;
        }
        /* End transfer */
        Flexio_I2s_Ip_MasterStopTransfer(Master);
        /* Call callback to announce the event to the user */
        if (Master->callback != NULL_PTR)
        {
            Master->callback(FLEXIO_I2S_IP_EVENT_END_TRANSFER, Master->callbackParam);
        }
    }
}

/*!
 * @brief Handler for FlexIO I2s channels
 *
 * @param FlexIOChannel    FlexIO channel
 * @param ShifterMaskFlag  Status mask of Flexio channel
 * @param ShifterErrMaskFlag  Status error mask of Flexio channel
 * @param TimerMaskFlag  Timer mask of Flexio channel
 * @return
 * @implements Flexio_I2s_Ip_IrqHandler_Activity
 */
void Flexio_I2s_Ip_IrqHandler(uint8 FlexIOChannel,
                              uint8 ShifterMaskFlag,
                              uint8 ShifterErrMaskFlag,
                              uint8 TimerMaskFlag)
{
    uint8 ResourceIndex;    /* Index of first used internal resource Instance (shifter and timer) */
    Flexio_I2s_Ip_StateType *State = NULL_PTR;
    const uint8 Instance = 0U;
    uint8 ChannelIndex;

    if (0U != Flexio_I2s_Ip_ChannelStatus[FlexIOChannel])
    {
        ChannelIndex = Flexio_I2s_Ip_ChannelMapping[FlexIOChannel];
        State = Flexio_I2s_Ip_pxState[Instance][ChannelIndex];
        ResourceIndex = State->FlexioCommon.ResourceIndex;
        if (FlexIOChannel == TX_SHIFTER(ResourceIndex))
        {
            Flexio_I2s_Ip_TransmitEventHandler(State, ShifterMaskFlag, ShifterErrMaskFlag, TimerMaskFlag);
        }
        else /* FlexIOChannel equal ResourceIndex RX_SHIFTER */
        {
            Flexio_I2s_Ip_ReceiveEventHandler(State, ShifterMaskFlag, ShifterErrMaskFlag);
        }
    }
}

#if (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE)
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter0(void);
/* Dma complete transmit notification for flexio channel 0 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter0(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 0U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter1(void);
/* Dma complete receive notification for flexio channel 1 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter1(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 1U);
}

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter1(void);
/* Dma complete transmit notification for flexio channel 1 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter1(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 1U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter2(void);
/* Dma complete receive notification for flexio channel 2 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter2(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 2U);
}

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter2(void);
/* Dma complete transmit notification for flexio channel 2 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter2(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 2U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter3(void);
/* Dma complete receive notification for flexio channel 3 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter3(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 3U);
}

#if (FLEXIO_I2S_IP_MAX_CHANNEL_COUNT > 4U)
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter3(void);
/* Dma complete transmit notification for flexio channel 3 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter3(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 3U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter4(void);
/* Dma complete receive notification for flexio channel 4 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter4(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 4U);
}

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter4(void);
/* Dma complete transmit notification for flexio channel 4 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter4(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 4U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter5(void);
/* Dma complete receive notification for flexio channel 5 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter5(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 5U);
}

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter5(void);
/* Dma complete transmit notification for flexio channel 5 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter5(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 5U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter6(void);
/* Dma complete receive notification for flexio channel 6 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter6(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 6U);
}

void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter6(void);
/* Dma complete transmit notification for flexio channel 6 */
void FlexIO_I2s_Ip_DmaTxTransferCompleteShifter6(void)
{
    Flexio_I2s_Ip_MasterEndDmaTxTransfer(0U, 6U);
}

void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter7(void);
/* Dma complete receive notification for flexio channel 7 */
void FlexIO_I2s_Ip_DmaRxTransferCompleteShifter7(void)
{
    Flexio_I2s_Ip_MasterEndDmaRxTransfer(0U, 7U);
}
#endif /* (FLEXIO_I2S_IP_MAX_CHANNEL_COUNT > 4U) */
#endif /* (STD_ON == FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE) */

#define I2S_STOP_SEC_CODE
#include "I2s_MemMap.h"

#endif /* (STD_ON == FLEXIO_I2S_IP_ENABLE) */

#ifdef __cplusplus
}
#endif

/** @} */
