/*================================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : eMios
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
++++++++++++++++++++++
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
==================================================================================================================*/

/**
*   @file          Emios_Ocu_Ip.c
*
*   @addtogroup    ocu_ip Ocu IPL
*   @brief         Ocu eMIOS source file for OCU driver.
*   @details       eMIOS driver interface.
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*================================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================================*/

#include "Emios_Ocu_Ip.h"
#include "Emios_Ocu_Ip_HwAccess.h"
#include "SchM_Ocu.h"

#if (STD_ON == OCU_DEV_ERROR_DETECT)
#include "Devassert.h"
#endif

#if (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT)
#define USER_MODE_REG_PROT_ENABLED  STD_ON
#include "RegLockMacros.h"
#else
#define USER_MODE_REG_PROT_ENABLED  STD_OFF
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_OCU_IP_VENDOR_ID_C                       43
#define EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION_C        4
#define EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION_C        7
#define EMIOS_OCU_IP_AR_RELEASE_REVISION_VERSION_C     0
#define EMIOS_OCU_IP_SW_MAJOR_VERSION_C                3
#define EMIOS_OCU_IP_SW_MINOR_VERSION_C                0
#define EMIOS_OCU_IP_SW_PATCH_VERSION_C                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_OCU_IP_VENDOR_ID_C != EMIOS_OCU_IP_VENDOR_ID)
    #error "Emios_Ocu_Ip.c and Emios_Ocu_Ip.h have different vendor ids"
#endif

/* Check if  source file and Emios_Ocu_Ip.h file are of the same Autosar version */
#if ((EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION_C != EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION_C != EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_OCU_IP_AR_RELEASE_REVISION_VERSION_C != EMIOS_OCU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Ocu_Ip.c and Emios_Ocu_Ip.h are different"
#endif

/* Check if source file and Emios_Ocu_Ip.h file are of the same Software version */
#if ((EMIOS_OCU_IP_SW_MAJOR_VERSION_C != EMIOS_OCU_IP_SW_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_SW_MINOR_VERSION_C != EMIOS_OCU_IP_SW_MINOR_VERSION) || \
     (EMIOS_OCU_IP_SW_PATCH_VERSION_C != EMIOS_OCU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Ocu_Ip.c and Emios_Ocu_Ip.h are different"
#endif

#if (EMIOS_OCU_IP_VENDOR_ID_C != EMIOS_OCU_IP_HWACCESS_VENDOR_ID)
    #error "Emios_Ocu_Ip.c and Emios_Ocu_Ip_HwAccess.h have different vendor ids"
#endif

/* Check if  source file and Emios_Ocu_Ip_HwAccess.h file are of the same Autosar version */
#if ((EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION_C != EMIOS_OCU_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION_C != EMIOS_OCU_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_OCU_IP_AR_RELEASE_REVISION_VERSION_C != EMIOS_OCU_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Ocu_Ip.c and Emios_Ocu_Ip_HwAccess.h are different"
#endif

/* Check if source file and Emios_Ocu_Ip_HwAccess.h file are of the same Software version */
#if ((EMIOS_OCU_IP_SW_MAJOR_VERSION_C != EMIOS_OCU_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_SW_MINOR_VERSION_C != EMIOS_OCU_IP_HWACCESS_SW_MINOR_VERSION) || \
     (EMIOS_OCU_IP_SW_PATCH_VERSION_C != EMIOS_OCU_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Ocu_Ip.c and Emios_Ocu_Ip_HwAccess.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT)
        /* Check if this source file and RegLockMacros.h file are of the same Autosar version */
        #if ((EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
            (EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION_C != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Emios_Ocu_Ip.c and RegLockMacros.h are different"
        #endif
    #endif
    #if (STD_ON == OCU_DEV_ERROR_DETECT)
        /* Check if this source file and Devassert.h file are of the same Autosar version */
        #if ((EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Emios_Ocu_Ip.c and Devassert.h are different"
        #endif
    #endif

    /* Check if this source file and SchM_Ocu.h file are of the same Autosar version */
    #if ((EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_OCU_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_OCU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Emios_Ocu_Ip.c and SchM_Ocu.h are different"
    #endif
#endif

#if (STD_ON == OCU_EMIOS_USED)

/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/
/**
@brief Enum containing the possible states of the Ocu driver
*/
typedef enum
{
    EMIOS_OCU_IP_DRV_STATE_UNINIT = 0,  /**< @brief Ocu driverl state - uninitialized */
    EMIOS_OCU_IP_DRV_STATE_IDLE         /**< @brief Ocu driverl state - Idle */
} Emios_Ocu_Ip_GlobalDrvStateType;

/**
* @brief This enumerated type allows the selection of channel status type.
*
*/
typedef enum
{
    EMIOS_OCU_IP_CH_STATE_UNINITIALIZED = 0,    /**< @brief Ocu channel state - uninitialized */
    EMIOS_OCU_IP_CH_STATE_INITIALIZED,          /**< @brief Ocu channel state - initialized */
    EMIOS_OCU_IP_CH_STATE_STOPPED,              /**< @brief Ocu channel state - stopped */
    EMIOS_OCU_IP_CH_STATE_RUNNING               /**< @brief Ocu channel state - running */
} Emios_Ocu_Ip_ChannelStateType;   /* PRQA S 3448*/

/*================================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*================================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================================*/

#define OCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"

/**
* @brief Pointer to eMIOS IP configuration structure - the pointer is valid only when the driver is in initialized state
*/
static const Emios_Ocu_Ip_ConfigType * Emios_Ocu_Ip_aspxIpConfig[OCU_EMIOS_INSTANCE_COUNT];

/**
* @brief    This arrays shall be used to store the action information for each eMIOS channel
* @details  This array shall be initialized by Ocu_Init() and Ocu_SetPinAction().
*           This data shall be used by Emios_Ocu_Ip_StartChannel to replace the information erased when
*           Emios_Ocu_Ip_StopChannel was called.
*/
static Emios_Ocu_Ip_PinActionType Emios_Ocu_Ip_axPinAction[OCU_EMIOS_INSTANCE_COUNT][OCU_EMIOS_CHANNEL_COUNT];

#define OCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"


#define OCU_START_SEC_VAR_CLEARED_8
#include "Ocu_MemMap.h"

#if ((STD_ON == OCU_GET_COUNTER_API) || (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
/**
* @brief    This arrays shall be used to store the Counter Bus Id information for each eMIOS channel
* @details  This array shall be initialized by Ocu_Init() and Ocu_SetPinAction().
*           This data shall be used by  StartChannel() to replace the information erased when
*           StopChannel() was called.
*/
static uint8 Emios_Ocu_Ip_au8CounterBusIdx[OCU_EMIOS_INSTANCE_COUNT][OCU_EMIOS_CHANNEL_COUNT];
#endif

/**
* @brief    Variable storing the current state of the Ocu driver
*/
static Emios_Ocu_Ip_GlobalDrvStateType Emios_Ocu_Ip_aesGlobalDrvState[OCU_EMIOS_INSTANCE_COUNT] = {EMIOS_OCU_IP_DRV_STATE_UNINIT};

/**
* @brief    This arrays shall be used to store the internal running state of each OCU channel.
* @details  This array shall be initialized by Ocu_Init() function and shall be used by all APIs' which
            require a certain mode to function.
            Possible values for each channel: EMIOS_OCU_IP_CH_STATE_UNINITIALIZED, EMIOS_OCU_IP_CH_STATE_INITIALIZED,
            EMIOS_OCU_IP_CH_STATE_STOPPED, EMIOS_OCU_IP_CH_STATE_RUNNING
*/
static Emios_Ocu_Ip_ChannelStateType Emios_Ocu_Ip_saxChannelState[OCU_EMIOS_INSTANCE_COUNT][OCU_EMIOS_CHANNEL_COUNT] = {{EMIOS_OCU_IP_CH_STATE_UNINITIALIZED}};

#define OCU_STOP_SEC_VAR_CLEARED_8
#include "Ocu_MemMap.h"


#if ((STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
#define OCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"

/**
* @brief    This arrays shall be used to store the max counter value for each eMIOS channel
* @details  This array shall be initialized by Ocu_Init().
*           This data shall be used by Ocu_GetMaxCounterValue() and Ocu_SetRelativeThreshold()
*/
static Emios_Ocu_Ip_ValueType Emios_Ocu_Ip_sauMaxCounterVals[OCU_EMIOS_INSTANCE_COUNT][OCU_EMIOS_CHANNEL_COUNT];

#define OCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"
#endif /* (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API) */


#define OCU_START_SEC_VAR_CLEARED_32
#include "Ocu_MemMap.h"

#if (defined(MCAL_EMIOS_REG_PROT_AVAILABLE) && (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief  Array of eMIOS peripheral base addresses
 */
static const uint32 EMIOS_BASE_ADDR32[] = eMIOS_BASE_ADDRS;
#endif /* defined(MCAL_EMIOS_REG_PROT_AVAILABLE) && (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT) */

#define OCU_STOP_SEC_VAR_CLEARED_32
#include "Ocu_MemMap.h"

/*================================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================================*/

/*================================================================================================================
*                                      GLOBAL MACROS
==================================================================================================================*/

#define MASTER_BUS_NOT_INSTALL      (0xFFU)

/*================================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================================*/
#define OCU_START_SEC_CONST_UNSPECIFIED
#include "Ocu_MemMap.h"

/** @brief  Array of eMIOS peripheral base pointers */
Emios_Ocu_Ip_xRegLayoutType * const Emios_Ocu_Ip_gapcxBase[OCU_EMIOS_INSTANCE_COUNT] = IP_eMIOS_BASE_PTRS;

#define OCU_STOP_SEC_CONST_UNSPECIFIED
#include "Ocu_MemMap.h"

#define OCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Ocu_MemMap.h"

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/** @brief Global array variable used to channel state for process common interrupt */
Emios_Ocu_Ip_ChStateType Emios_Ocu_Ip_gaxChState[OCU_EMIOS_INSTANCE_COUNT][OCU_EMIOS_CHANNEL_COUNT] = {{{(boolean)FALSE, (boolean)FALSE, NULL_PTR, (uint16)OCU_EMIOS_INVALID_CHANNEL_NUM}}};
#endif

#define OCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Ocu_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#if (defined(MCAL_EMIOS_REG_PROT_AVAILABLE) && (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief        Enables eMIOS registers writing in User Mode by configuring REG_PROT
 * @details      Sets the UAA (User Access Allowed) bit of the eMIOS IP allowing eMIOS registers writing in User Mode
 *
 * @param[in]    none
 *
 * @return       none
 *
 * @pre          Should be executed in supervisor mode
 * @post         none
 *
 */
void Emios_Ocu_Ip_SetUserAccessAllowed(uint32 EmiosBaseAddr);
#endif


#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if ((STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
/**
* @brief        This internal function determines status of the compare match after the new threshold was written.
* @details      This function compare systematic the input parameter values to determine if the
*               compare-match will occur in the given interval or has already occurred.
*               The reference interval if composed of all integer value between the StartIntervalVal and
*               EndIntervalVal, considering also the possibility of counter over-run.
*               I.e. considering a 8bit counter if StartIntervalVal = 253 and  EndIntervalVal = 5 than
*               the values inside the interval are {253, 254, 255, 0, 1, 2, 3, 4} and all other values are
*               outside reference interval.
*
* @param[in]    PostCmWriteValue    Value of the counter after Compare match was written
* @param[in]    StartIntervalVal    Start value of the reference interval
* @param[in]    EndIntervalVal      End value of the reference interval
*
* @return   Emios_Ocu_Ip_ValueType  Compare match was written in or outside the given interval
* @retval       OCU_EMIOS_CM_IN_REF_INTERVAL  Compare match was written inside the reference interval
* @retval       OCU_EMIOS_CM_OUT_REF_INTERVAL Compare match was written outside the reference interval
*
*/
static Emios_Ocu_Ip_ReturnType Emios_Ocu_Ip_DetermineNextCmStatus(Emios_Ocu_Ip_ValueType PostCmWriteValue, Emios_Ocu_Ip_ValueType StartIntervalVal, Emios_Ocu_Ip_ValueType EndIntervalVal);
#endif

/**
 * @brief Clear FLAG bit from eMIOS UC Status register n (eMIOS_Sn).
 * @details: The FLAG bit is set when a match event in the comparators occurred.
 *            The FLAG bit must be cleared by writing a 1 to it.
 *              0 FLAG cleared
 *              1 FLAG set event has occurred
 *
 * @param[in]   InstNum - eMIOS Instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 * @return none
 */
void Emios_Ocu_Ip_ClearPendingInterrupts(uint8 InstNum, uint8 ChNum);
/*==================================================================================================
*                                  GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == OCU_DEV_ERROR_DETECT)
/**
 * @brief
 * @param[in]   InstNum - eMIOS Instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 * @return none
 */
static void Emios_Ocu_Ip_AssertChannelAndInstanceNumber(uint8 InstNum, uint8 ChNum);
#endif

/*================================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================================*/
#if (STD_ON == OCU_DEV_ERROR_DETECT)
static void Emios_Ocu_Ip_AssertChannelAndInstanceNumber(uint8 InstNum, uint8 ChNum)
{
#if (STD_ON == OCU_EMIOS_IP_ON_S32ZE_PLATFORM)
    DevAssert(  (InstNum < OCU_EMIOS_INSTANCE_COUNT) &&
                (   (ChNum < 8U) ||
                    ((ChNum >= 16U) && (ChNum < OCU_EMIOS_CHANNEL_COUNT))));
#else
    DevAssert((InstNum < OCU_EMIOS_INSTANCE_COUNT) && (ChNum < OCU_EMIOS_CHANNEL_COUNT));
#endif
}
#endif

#if (defined(MCAL_EMIOS_REG_PROT_AVAILABLE) && (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT))
void Emios_Ocu_Ip_SetUserAccessAllowed(uint32 EmiosBaseAddr)
{
    SET_USER_ACCESS_ALLOWED(EmiosBaseAddr, EMIOS_PROT_MEM_U32);
}
#endif

#if ((STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
/**
* @brief    This internal function determines status of the compare match after the new threshold was written.
*
*/
static Emios_Ocu_Ip_ReturnType Emios_Ocu_Ip_DetermineNextCmStatus(Emios_Ocu_Ip_ValueType PostCmWriteValue, Emios_Ocu_Ip_ValueType StartIntervalVal, Emios_Ocu_Ip_ValueType EndIntervalVal)
{
    /* Variable to store the value to be returned by the function */
    Emios_Ocu_Ip_ReturnType RetVal = OCU_EMIOS_CM_OUT_REF_INTERVAL;

    /* check if compare match will happen before counter roll-over */
    if (StartIntervalVal <= EndIntervalVal)
    {
        /* counter is not expected to roll-over */
        /* check if post-update value is inside the compare match interval */
        if ((StartIntervalVal <= PostCmWriteValue) && (PostCmWriteValue < EndIntervalVal))
        {
            RetVal = OCU_EMIOS_CM_IN_REF_INTERVAL;
        }
        else
        {
            RetVal = OCU_EMIOS_CM_OUT_REF_INTERVAL;
        }
    }
    else    /*counter has rolled-over*/
    {
        /* check if post-update value is outside the compare match interval */
        if ((PostCmWriteValue < StartIntervalVal) && (PostCmWriteValue > EndIntervalVal))
        {
            RetVal = OCU_EMIOS_CM_OUT_REF_INTERVAL;
        }
        else
        {
            RetVal = OCU_EMIOS_CM_IN_REF_INTERVAL;
        }
    }
    return RetVal;
}
#endif

/*================================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================================*/

/**
 * @brief Clear FLAG bit from eMIOS UC Status register n (eMIOS_Sn).
 * @details: The FLAG bit is set when a match event in the comparators occurred.
 *            The FLAG bit must be cleared by writing a 1 to it.
 *              0 FLAG cleared
 *              1 FLAG set event has occurred
 *
 * @param[in]   InstNum - eMIOS Instance number
 * @param[in]   ChNum - Channel number in the eMIOS instance
 * @return none
 */
void Emios_Ocu_Ip_ClearPendingInterrupts(uint8 InstNum, uint8 ChNum)
{
#if (STD_ON == OCU_DEV_ERROR_DETECT)
    Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif
#if (STD_ON == OCU_EMIOS_IP_ON_S32ZE_PLATFORM)
        if (    (InstNum < OCU_EMIOS_INSTANCE_COUNT) &&
                (   (ChNum < 8U) ||
                    ((ChNum >= 16U) && (ChNum < OCU_EMIOS_CHANNEL_COUNT))))
#else
    if ((InstNum < OCU_EMIOS_INSTANCE_COUNT) && (ChNum < OCU_EMIOS_CHANNEL_COUNT))
#endif
    {
        Emios_Ocu_Ip_ClearInterruptFlags(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum);
    }
}

/**
* @brief   Ocu driver initialization function for eMIOS module.
*
*/
void Emios_Ocu_Ip_Init(const Emios_Ocu_Ip_ConfigType * const pEmiosIpConfig)
{
    uint8   InstNum;    /* assigned eMIOS HW module index */
    uint8   ChNum;      /* assigned eMIOS HW channel index */
    uint8   ChLoopIdx;  /* Channel index used in the loop */
    uint8   lu8BusSelect    = 0U;
    uint32  lu32CtrVal      = 0U;

#if (defined(MCAL_EMIOS_REG_PROT_AVAILABLE) && (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT))
    uint8 u8ModuleIdxUserMode = 0xFFU;    /* assigned eMIOS HW module index */
#endif
    /** @brief Pointer to eMIOS channel specific configuration */
    const Emios_Ocu_Ip_ChannelConfigType * pEmiosChannelCfg;

#if (STD_ON == OCU_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != pEmiosIpConfig);
#endif

    /* Get eMIOS instance number for this IPL configuration structure */
    InstNum = pEmiosIpConfig->InstanceNo;

    if (NULL_PTR == Emios_Ocu_Ip_aspxIpConfig[InstNum])
    {
        /* Save configuration pointer in a local variable */
        Emios_Ocu_Ip_aspxIpConfig[InstNum] = pEmiosIpConfig;
#if (STD_ON == OCU_DEV_ERROR_DETECT)
        DevAssert((0U < Emios_Ocu_Ip_aspxIpConfig[InstNum]->NumChannels) &&
            (Emios_Ocu_Ip_aspxIpConfig[InstNum]->NumChannels <= OCU_EMIOS_NUM_HW_CHANNELS));
#endif
        /* Initialize each eMIOS configured channel */
        for (ChLoopIdx = 0U; ChLoopIdx < Emios_Ocu_Ip_aspxIpConfig[InstNum]->NumChannels; ++ChLoopIdx)
        {
            pEmiosChannelCfg = &(*Emios_Ocu_Ip_aspxIpConfig[InstNum]->pcxChannelsConfig)[ChLoopIdx];

            lu32CtrVal  = pEmiosChannelCfg->ControlValue;

            /* Get eMIOS channel number */
            ChNum = pEmiosChannelCfg->HwChannel;

#if (STD_ON == OCU_DEV_ERROR_DETECT)
            Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif
            /* Initialize global data */
            Emios_Ocu_Ip_saxChannelState[InstNum][ChNum] = EMIOS_OCU_IP_CH_STATE_INITIALIZED;

#if (defined(MCAL_EMIOS_REG_PROT_AVAILABLE) && (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT))
            if ((InstNum != u8ModuleIdxUserMode) || (0x0U == ChLoopIdx))
            {
                /* Register Protection - Set UAA bit in GCR - allow USER MODE access */
                OsIf_Trusted_Call1param(Emios_Ocu_Ip_SetUserAccessAllowed, EMIOS_BASE_ADDR32[InstNum]);
                u8ModuleIdxUserMode = InstNum;
            }
#endif

#if ((STD_ON == OCU_GET_COUNTER_API) || (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
            Emios_Ocu_Ip_au8CounterBusIdx[InstNum][ChNum] = MASTER_BUS_NOT_INSTALL;
#endif

#if ((STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
            /* Store the Max Counter Value */
            Emios_Ocu_Ip_sauMaxCounterVals[InstNum][ChNum] = pEmiosChannelCfg->MaxCounterValue;
#endif /* (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API) */

            /* Disable interrupts */
            Emios_Ocu_Ip_SetFlagEnableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);

            /* Reset Channel to be configured */
            Emios_Ocu_Ip_SetOperationMode(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, EMIOS_MODE_GPIO_IN);
            Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
            Emios_Ocu_Ip_SetOutputFlipFlop(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
            Emios_Ocu_Ip_SetPrescalerEnableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
            Emios_Ocu_Ip_SetBusSelectBits(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, 0U);

            /* Configure Bus Select for eMIOS */
            lu8BusSelect = (uint8)((lu32CtrVal & EMIOS_OCU_BUS_SELECT_PARAM_MASK) >> EMIOS_OCU_BUS_SELECT_PARAM_SHIFT);
            Emios_Ocu_Ip_SetBusSelectBits(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, lu8BusSelect);

            /* configure DEBUG bits */
            Emios_Ocu_Ip_SetFreezeEnableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, (1U == ((lu32CtrVal & OCU_EMIOS_DBG_INFO_MASK) >> OCU_EMIOS_DBG_INFO_SHIFT)) ? TRUE : FALSE);

            /* Select the clock divider value for the internal prescaler of Unified Channel*/
            Emios_Ocu_Ip_SetPrescalerBits(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, (uint8)((lu32CtrVal & OCU_EMIOS_CLOCK_DIV_MASK) >> OCU_EMIOS_CLOCK_DIV_SHIFT));

            /* Configure default PIN Action behavior */
            Emios_Ocu_Ip_axPinAction[InstNum][ChNum] = (uint8)((lu32CtrVal & OCU_EMIOS_PIN_ACTION_MASK) >> OCU_EMIOS_PIN_ACTION_SHIFT);

            /* Set Compare A Value = default threshold */
            Emios_Ocu_Ip_SetMatchLeadingEdge(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, pEmiosChannelCfg->DefaultThreshold);

            /* The EDPOL value is transferred to the output flip-flop */
            Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, (0U == ((lu32CtrVal & OCU_EMIOS_PIN_STATE_MASK) >> OCU_EMIOS_PIN_STATE_SHIFT)) ? TRUE : FALSE);

            if (OCU_EMIOS_OUTPUT_ENABLE == ((lu32CtrVal & OCU_EMIOS_OUTPIN_USED_MASK) >> OCU_EMIOS_OUTPIN_USED_SHIFT))
            {
                /* Set bit EDSEL to 0 */
                Emios_Ocu_Ip_SetOutputFlipFlop(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
                /* The output pin operates normally */
                Emios_Ocu_Ip_SetOutputDisableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
            }

            /* Set Single Action Output Compare (SAOC) Mode */
            Emios_Ocu_Ip_SetOperationMode(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, EMIOS_MODE_SAOC);

            /* Store counter Bus channel and configure for channel using internal bus */
            if (lu8BusSelect != (uint8)EMIOS_OCU_BUS_INTERNAL_COUNTER)
            {
#if ((STD_ON == OCU_GET_COUNTER_API) || (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
                /* Store CounterBus Id */
                Emios_Ocu_Ip_au8CounterBusIdx[InstNum][ChNum] = pEmiosChannelCfg->HwChannelCounterBus;
#endif
            }
            else
            {
#if ((STD_ON == OCU_GET_COUNTER_API) || (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
                /* Store CounterBus Id */
                Emios_Ocu_Ip_au8CounterBusIdx[InstNum][ChNum] = ChNum;
#endif
                /* The UCPREN bit enables the prescaler counter */
                Emios_Ocu_Ip_SetPrescalerEnableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, TRUE);
            }

            /* Clear pending interrupt serviced */
            Emios_Ocu_Ip_ClearPendingInterrupts(InstNum, ChNum);

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
            Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mChannelInit    = TRUE;
            Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mNotifEnabled   = FALSE;
            Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mCallbackFunc   = pEmiosChannelCfg->mCallbackFunc;
            Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mCallbackParam  = pEmiosChannelCfg->mCallbackParam;
#endif

        }
        
        /* Update driver's state for this instance */
        Emios_Ocu_Ip_aesGlobalDrvState[InstNum] = EMIOS_OCU_IP_DRV_STATE_IDLE;
    }
}

/*=================================================================================================================*/
#if (STD_ON == OCU_DEINIT_API)
/**
* @brief   Ocu driver de-initialization function for eMIOS module.
*
*/
void Emios_Ocu_Ip_DeInit(uint8 InstNum)
{
    /** @brief Pointer to eMIOS channel specific configuration */
    const Emios_Ocu_Ip_ChannelConfigType * pEmiosChannelCfg;

    uint8 ChNum;        /* assigned eMIOS HW channel index */
    uint8 ChLoopIdx;    /* Channel index used in the loop */

#if (STD_ON == OCU_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != Emios_Ocu_Ip_aspxIpConfig[InstNum]);
#endif

    if (NULL_PTR != Emios_Ocu_Ip_aspxIpConfig[InstNum])
    {
#if (STD_ON == OCU_DEV_ERROR_DETECT)
        DevAssert((0U < Emios_Ocu_Ip_aspxIpConfig[InstNum]->NumChannels) && (Emios_Ocu_Ip_aspxIpConfig[InstNum]->NumChannels <= OCU_EMIOS_NUM_HW_CHANNELS));
#endif
        for (ChLoopIdx = 0U; ChLoopIdx < Emios_Ocu_Ip_aspxIpConfig[InstNum]->NumChannels; ++ChLoopIdx)
        {
            /* only handle eMIOS channels */
            pEmiosChannelCfg = &(*Emios_Ocu_Ip_aspxIpConfig[InstNum]->pcxChannelsConfig)[ChLoopIdx];

            /* Get eMIOS channel number */
            ChNum = pEmiosChannelCfg->HwChannel;
#if (STD_ON == OCU_DEV_ERROR_DETECT)
            Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif
            /* Disable interrupts */
            Emios_Ocu_Ip_SetFlagEnableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);

            /* Clear pending interrupt serviced */
            Emios_Ocu_Ip_ClearPendingInterrupts(InstNum, ChNum);

            /* Reset Timer control register, internal Counter is also cleared when entering GPIO Mode */
            Emios_Ocu_Ip_gapcxBase[InstNum]->CH.UC[ChNum].C = 0U;

            /* clear An register */
            Emios_Ocu_Ip_SetMatchLeadingEdge(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, 0U);

            /* Clear Interrupt Flag */
            Emios_Ocu_Ip_ClearPendingInterrupts(InstNum, ChNum);

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
            Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mChannelInit    = FALSE;
            Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mNotifEnabled   = FALSE;
            Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mCallbackFunc   = NULL_PTR;
            Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mCallbackParam  = (uint16)OCU_EMIOS_INVALID_CHANNEL_NUM;
#endif
            /* initialize global data */
            Emios_Ocu_Ip_saxChannelState[InstNum][ChNum] = EMIOS_OCU_IP_CH_STATE_UNINITIALIZED;

            /* Flag that the selected instance is deinitialized */
            Emios_Ocu_Ip_aesGlobalDrvState[InstNum] = EMIOS_OCU_IP_DRV_STATE_UNINIT;
        }

        /* Set local configuration pointer back to NULL */
        Emios_Ocu_Ip_aspxIpConfig[InstNum] = NULL_PTR;
    }
}
#endif /* OCU_DEINIT_API */

/*=================================================================================================================*/
/**
 * @brief   Ocu driver function for starting the eMIOS timer channel.
 *
 */
void Emios_Ocu_Ip_StartChannel(uint8 InstNum, uint8 ChNum)
{
    boolean lOutputPinState;

#if (STD_ON == OCU_DEV_ERROR_DETECT)
    Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif

    if (    (EMIOS_OCU_IP_DRV_STATE_IDLE == Emios_Ocu_Ip_aesGlobalDrvState[InstNum]) &&
            (   (EMIOS_OCU_IP_CH_STATE_INITIALIZED == Emios_Ocu_Ip_saxChannelState[InstNum][ChNum]) ||
                (EMIOS_OCU_IP_CH_STATE_STOPPED == Emios_Ocu_Ip_saxChannelState[InstNum][ChNum]) ) )
    {
        /* enter critical section TODO check */
        SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_00();

        /* clear EDSEL, EDPOL, ODIS bits */
        Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
        Emios_Ocu_Ip_SetOutputFlipFlop(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
        Emios_Ocu_Ip_SetOutputDisableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);

        switch (Emios_Ocu_Ip_axPinAction[InstNum][ChNum])
        {
            case OCU_EMIOS_SET_HIGH:
            {
                Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, TRUE);
            }
            break;

            case OCU_EMIOS_SET_DISABLE:
            {
                Emios_Ocu_Ip_SetOutputDisableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, TRUE);
            }
            break;

            case OCU_EMIOS_SET_TOGGLE:
            {
                Emios_Ocu_Ip_SetOutputFlipFlop(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, TRUE);
            }
            break;

            default:
            {
                lOutputPinState = Emios_Ocu_Ip_GetOutputPinState(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum);
                Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, lOutputPinState);
            }
            break;
        }

        /* Set Single Action Output Compare (SAOC) Mode */
        Emios_Ocu_Ip_SetOperationMode(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, EMIOS_MODE_SAOC);

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
        /* Clear interrupt flags */
        Emios_Ocu_Ip_ClearPendingInterrupts(InstNum, ChNum);

        /* enable interrupt for given channel */
        Emios_Ocu_Ip_SetFlagEnableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, TRUE);
#endif

        /* exit critical section */
        SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_00();

        /* set channel status to 'RUNNING' */
        Emios_Ocu_Ip_saxChannelState[InstNum][ChNum] = EMIOS_OCU_IP_CH_STATE_RUNNING;
    }
}

/*=================================================================================================================*/
/**
 * @brief   Ocu driver function for stopping the eMIOS timer channel.
 *
 */
void Emios_Ocu_Ip_StopChannel(uint8 InstNum, uint8 ChNum)
{
#if (STD_ON == OCU_DEV_ERROR_DETECT)
    Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif

    if (    (EMIOS_OCU_IP_DRV_STATE_IDLE == Emios_Ocu_Ip_aesGlobalDrvState[InstNum]) &&
            (   (EMIOS_OCU_IP_CH_STATE_INITIALIZED == Emios_Ocu_Ip_saxChannelState[InstNum][ChNum]) ||
                (EMIOS_OCU_IP_CH_STATE_RUNNING == Emios_Ocu_Ip_saxChannelState[InstNum][ChNum]) ) )
    {
        /* enter critical section */
        SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_01();

        /* Clear output mode bits */
        Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
        Emios_Ocu_Ip_SetOutputFlipFlop(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
        Emios_Ocu_Ip_SetOutputDisableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
        /* Clear interrupt flags */
        Emios_Ocu_Ip_ClearPendingInterrupts(InstNum, ChNum);
        /* disable interrupt */
        Emios_Ocu_Ip_SetFlagEnableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
#endif
        /* exit critical section */
        SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_01();

        /* set channel status to 'STOPPED' */
        Emios_Ocu_Ip_saxChannelState[InstNum][ChNum] = EMIOS_OCU_IP_CH_STATE_STOPPED;
    }
}

/*=================================================================================================================*/
#if (STD_ON == OCU_GET_COUNTER_API)
/**
 * @brief   Ocu driver function for getting the current counter value for an eMIOS timer channel.
 *
 */
Emios_Ocu_Ip_ValueType Emios_Ocu_Ip_GetCounter(uint8 InstNum, uint8 ChNum)
{
    Emios_Ocu_Ip_ValueType RetCntVal = 0U;

#if (STD_ON == OCU_DEV_ERROR_DETECT)
    Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif
    if (EMIOS_OCU_IP_DRV_STATE_IDLE == Emios_Ocu_Ip_aesGlobalDrvState[InstNum])
    {
        /* Read the elapsed time */
        RetCntVal = Emios_Ocu_Ip_GetCntVal(Emios_Ocu_Ip_gapcxBase[InstNum], Emios_Ocu_Ip_au8CounterBusIdx[InstNum][ChNum]);
        /* TODO - check if master bus should be read for channels that have master bus */
    }

    return RetCntVal;
}
#endif /* OCU_GET_COUNTER_API */

/*=================================================================================================================*/
#if (STD_ON == OCU_SET_PIN_STATE_API)
/**
 * @brief   Ocu driver function for setting the Pin State for the current eMIOS channel
 *
 */
void Emios_Ocu_Ip_SetPinState(uint8 InstNum, uint8 ChNum, Emios_Ocu_Ip_PinStateType PinState)
{
#if (STD_ON == OCU_DEV_ERROR_DETECT)
    Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif

    if (    (EMIOS_OCU_IP_DRV_STATE_IDLE == Emios_Ocu_Ip_aesGlobalDrvState[InstNum]) &&
            (EMIOS_OCU_IP_CH_STATE_RUNNING != Emios_Ocu_Ip_saxChannelState[InstNum][ChNum]) )
    {
        /* enter critical section */
        SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_03();

        if (OCU_EMIOS_HIGH == PinState)
        {
            /* clear EDSEL */
            Emios_Ocu_Ip_SetOutputFlipFlop(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
            /* set EDPOL up 1 */
            Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, TRUE);
        }
        else
        {
            /* clear EDPOL and EDSEL */
            Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
            Emios_Ocu_Ip_SetOutputFlipFlop(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
        }

        /* bit FORCMA set comparator A */
        Emios_Ocu_Ip_SetForceMatchA(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, TRUE);

        /* exit critical section */
        SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_03();
    }
}
#endif

/*=================================================================================================================*/
#if (STD_ON == OCU_SET_PIN_ACTION_API)
/**
 * @brief   Ocu driver function for setting the Pin Action for the current eMIOS channel
 *
 */
void Emios_Ocu_Ip_SetPinAction(uint8 InstNum, uint8 ChNum, Emios_Ocu_Ip_PinActionType PinAction)
{
    boolean lOutputPinState;

#if (STD_ON == OCU_DEV_ERROR_DETECT)
    Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif

    if (    (EMIOS_OCU_IP_DRV_STATE_IDLE == Emios_Ocu_Ip_aesGlobalDrvState[InstNum]) &&
            (EMIOS_OCU_IP_CH_STATE_RUNNING == Emios_Ocu_Ip_saxChannelState[InstNum][ChNum]) )
    {
        /* enter critical section */
        SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_02();

        /* clear EDSEL EDPOL ODIS */
        Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
        Emios_Ocu_Ip_SetOutputFlipFlop(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);
        Emios_Ocu_Ip_SetOutputDisableBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, FALSE);

        Emios_Ocu_Ip_axPinAction[InstNum][ChNum] = PinAction;

        switch (Emios_Ocu_Ip_axPinAction[InstNum][ChNum])
        {
            case OCU_EMIOS_SET_DISABLE:
            {
                /* Read level output of channel before Disable output */
                lOutputPinState = Emios_Ocu_Ip_GetOutputPinState(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum);
                Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, lOutputPinState);
            }
            break;

            case OCU_EMIOS_SET_HIGH:
            {
                Emios_Ocu_Ip_SetEdgePolarityBit(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, TRUE);
            }
            break;

            case OCU_EMIOS_SET_TOGGLE:
            {
                Emios_Ocu_Ip_SetOutputFlipFlop(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, TRUE);
            }
            break;

            default:
            {
                /* Do nothing */
            }
            break;
        }

        if (EMIOS_OCU_IP_CH_STATE_RUNNING == Emios_Ocu_Ip_saxChannelState[InstNum][ChNum])
        {
#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
            /* Clear interrupt flags */
            Emios_Ocu_Ip_ClearPendingInterrupts(InstNum, ChNum);
#endif
        }

        /* exit critical section */
        SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_02();
    }
}
#endif

/*=================================================================================================================*/
#if (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API)
/**
 * @brief   The function changes the eMIOS compare register value.
 *
 */
Emios_Ocu_Ip_ReturnType Emios_Ocu_Ip_SetRelativeThreshold(uint8 InstNum, uint8 ChNum, Emios_Ocu_Ip_ValueType RelativeValue)
{
    Emios_Ocu_Ip_ValueType CntValuePreUpdate    = 0U;   /* CNT register value before computing the update */
    Emios_Ocu_Ip_ValueType CntValPostUpdate     = 0U;   /* CNT register value after computing the update TODO */
    Emios_Ocu_Ip_ValueType CmpMatchValue        = 0U;   /* New CNT register value */
    Emios_Ocu_Ip_ReturnType RetVal; /* Return value to see if the current counter has overrunned the postupdate CNT */

#if (STD_ON == OCU_DEV_ERROR_DETECT)
    Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif

    if (EMIOS_OCU_IP_DRV_STATE_IDLE == Emios_Ocu_Ip_aesGlobalDrvState[InstNum])
    {
        SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_04();

        /* Calculate CmpMatchValue, matching can occur at current cycle or next cycle */
        CntValuePreUpdate = Emios_Ocu_Ip_GetCntVal(Emios_Ocu_Ip_gapcxBase[InstNum], Emios_Ocu_Ip_au8CounterBusIdx[InstNum][ChNum]);

        /* new threshold value = current counter read value + relative value */
        CmpMatchValue = (CntValuePreUpdate + RelativeValue);

        /* Set timeout value to UC A register */
        Emios_Ocu_Ip_SetMatchLeadingEdge(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, CmpMatchValue);

        /* re-Read Counter register */
        CntValPostUpdate = Emios_Ocu_Ip_GetCntVal(Emios_Ocu_Ip_gapcxBase[InstNum], Emios_Ocu_Ip_au8CounterBusIdx[InstNum][ChNum]);

        /* exit critical section */
        SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_04();

        /* check if compare match will happen before counter roll-over */
        RetVal = Emios_Ocu_Ip_DetermineNextCmStatus(CntValPostUpdate, CntValuePreUpdate, CmpMatchValue);
    }
    else
    {
        RetVal = OCU_EMIOS_CM_OUT_REF_INTERVAL;
    }
    return RetVal;
}

#endif /* OCU_SET_RELATIVE_THRESHOLD_API */

/*=================================================================================================================*/
#if (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API)
/**
 * @brief   The function changes the eMIOS compare register value.
 *
 */
Emios_Ocu_Ip_ReturnType Emios_Ocu_Ip_SetAbsoluteThreshold(uint8 InstNum, uint8 ChNum, Emios_Ocu_Ip_ValueType ReferenceVal, Emios_Ocu_Ip_ValueType AbsoluteVal)
{
    Emios_Ocu_Ip_ValueType CntValPostUpdate = 0U;   /* CNT register value after computing the update TODO - remove = 0*/
    Emios_Ocu_Ip_ReturnType RetVal; /* Return value to see if the current counter has overrunned the postupdate CNT */

#if (STD_ON == OCU_DEV_ERROR_DETECT)
    Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif

    if (EMIOS_OCU_IP_DRV_STATE_IDLE == Emios_Ocu_Ip_aesGlobalDrvState[InstNum])
    {
        SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_05();
        /* write value of AbsoluteVal to UC A register use for compare */
        Emios_Ocu_Ip_SetMatchLeadingEdge(Emios_Ocu_Ip_gapcxBase[InstNum], ChNum, AbsoluteVal);

        /* Read counter register */
        CntValPostUpdate = Emios_Ocu_Ip_GetCntVal(Emios_Ocu_Ip_gapcxBase[InstNum], Emios_Ocu_Ip_au8CounterBusIdx[InstNum][ChNum]);

        SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_05();
        RetVal = Emios_Ocu_Ip_DetermineNextCmStatus(CntValPostUpdate, ReferenceVal, AbsoluteVal);
    }
    else
    {
        RetVal = OCU_EMIOS_CM_OUT_REF_INTERVAL;
    }
    return RetVal;
}
#endif /* OCU_SET_ABSOLUTE_THRESHOLD_API */

/*=================================================================================================================*/
#if (STD_ON == OCU_SET_CLOCK_MODE_API)
/**
 * @brief   The function changes the prescaler of eMIOS channel.
 *
 */
void Emios_Ocu_Ip_SetClockMode(uint8 InstNum, Emios_Ocu_Ip_SelectPrescalerType Prescaler)
{
    uint8 ChNum;
    uint8 ChLoopIdx;    /* Channel index used in the loop */

    const Emios_Ocu_Ip_ChannelConfigType * pEmiosChannelCfg;
#if (STD_ON == OCU_DEV_ERROR_DETECT)
    DevAssert(NULL_PTR != Emios_Ocu_Ip_aspxIpConfig[InstNum]);
#endif

    if (NULL_PTR != Emios_Ocu_Ip_aspxIpConfig[InstNum])
    {
#if (STD_ON == OCU_DEV_ERROR_DETECT)
        DevAssert((0U < Emios_Ocu_Ip_aspxIpConfig[InstNum]->NumChannels) && (Emios_Ocu_Ip_aspxIpConfig[InstNum]->NumChannels <= OCU_EMIOS_NUM_HW_CHANNELS));
#endif
        /* enter critical section */
        SchM_Enter_Ocu_OCU_EXCLUSIVE_AREA_06();

        for (ChLoopIdx = 0U; ChLoopIdx < Emios_Ocu_Ip_aspxIpConfig[InstNum]->NumChannels; ++ChLoopIdx)
        {
            /* only handle eMIOS channels */
            pEmiosChannelCfg = &(*Emios_Ocu_Ip_aspxIpConfig[InstNum]->pcxChannelsConfig)[ChLoopIdx];

            ChNum = pEmiosChannelCfg->HwChannel;
#if (STD_ON == OCU_DEV_ERROR_DETECT)
            Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif
            if (OCU_EMIOS_ALTERNATIVE_PRESCALER == Prescaler)
            {
                Emios_Ocu_Ip_SetPrescalerBits(  Emios_Ocu_Ip_gapcxBase[InstNum], ChNum,
                                                (uint8)((pEmiosChannelCfg->AltControlValue & OCU_EMIOS_CLOCK_DIV_MASK) >> OCU_EMIOS_CLOCK_DIV_SHIFT) );
            }
            else
            {
                Emios_Ocu_Ip_SetPrescalerBits(  Emios_Ocu_Ip_gapcxBase[InstNum], ChNum,
                                                (uint8)((pEmiosChannelCfg->ControlValue & OCU_EMIOS_CLOCK_DIV_MASK) >> OCU_EMIOS_CLOCK_DIV_SHIFT) );
            }
        }

        /* exit critical section */
        SchM_Exit_Ocu_OCU_EXCLUSIVE_AREA_06();
    }
}
#endif

/*===============================================================================================*/
#if ((STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
/**
 * @brief   This function will return max counter value for given channel
 *
 */
uint32 Emios_Ocu_Ip_GetMaxCounterValue(uint8 InstNum, uint8 ChNum)
{
    uint32 RetMaxCntVal = 0U;

#if (STD_ON == OCU_DEV_ERROR_DETECT)
    Emios_Ocu_Ip_AssertChannelAndInstanceNumber(InstNum, ChNum);
#endif /* STD_ON == OCU_DEV_ERROR_DETECT */

    if (EMIOS_OCU_IP_DRV_STATE_IDLE == Emios_Ocu_Ip_aesGlobalDrvState[InstNum])
    {
        RetMaxCntVal = Emios_Ocu_Ip_sauMaxCounterVals[InstNum][ChNum];
    }

    return RetMaxCntVal;
}
#endif /* (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API) */


#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/**
 * @brief   This function is used to disable the OCU compare match notification.
 *
 */
void  Emios_Ocu_Ip_DisableNotification(uint8 InstNum, uint8 ChNum)
{
    if (EMIOS_OCU_IP_DRV_STATE_IDLE == Emios_Ocu_Ip_aesGlobalDrvState[InstNum])
    {
        /* disable user notification switch inside the channels status variable */
        Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mNotifEnabled = FALSE;
    }
}

/**
 * @brief   This function is used to enable the OCU compare match notification of the indexed channel.
 *
 */
void Emios_Ocu_Ip_EnableNotification(uint8 InstNum, uint8 ChNum)
{
    if (EMIOS_OCU_IP_DRV_STATE_IDLE == Emios_Ocu_Ip_aesGlobalDrvState[InstNum])
    {
        if (NULL_PTR != Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mCallbackFunc)
        {
            /* enable user notification switch inside the channels status variable */
            Emios_Ocu_Ip_gaxChState[InstNum][ChNum].mNotifEnabled = TRUE;
        }
    }
}
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#endif /* OCU_EMIOS_USED */


#ifdef __cplusplus
}
#endif

/** @} */
