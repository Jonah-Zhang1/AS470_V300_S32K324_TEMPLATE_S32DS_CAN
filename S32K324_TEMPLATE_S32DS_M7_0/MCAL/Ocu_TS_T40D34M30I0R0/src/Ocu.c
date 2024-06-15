/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : eMios
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
*   @file           Ocu.c
*   @implements     Ocu.c_Artifact
*   @addtogroup     ocu_driver Ocu Driver
*   @brief          Ocu HLD interface implementation.
*   @details        Ocu high level interface implementation.
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Ocu.h"
#include "Ocu_Irq.h"

#if (STD_ON == OCU_DEV_ERROR_DETECT)
#include "Det.h"
#endif

/*==================================================================================================
*                                  SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_VENDOR_ID_C                     43
#define OCU_AR_RELEASE_MAJOR_VERSION_C      4
#define OCU_AR_RELEASE_MINOR_VERSION_C      7
#define OCU_AR_RELEASE_REVISION_VERSION_C   0
#define OCU_SW_MAJOR_VERSION_C              3
#define OCU_SW_MINOR_VERSION_C              0
#define OCU_SW_PATCH_VERSION_C              0
/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and OCU header file are of the same vendor */
#if (OCU_VENDOR_ID_C != OCU_VENDOR_ID)
    #error "Ocu.c and Ocu.h have different vendor IDs"
#endif

/* Check if source file and OCU header file are of the same AutoSar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION_C != OCU_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION_C != OCU_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION_C != OCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu.c and Ocu.h are different"
#endif
/* Check if source file and OCU header file are of the same Software version */
#if ((OCU_SW_MAJOR_VERSION_C != OCU_SW_MAJOR_VERSION) || \
     (OCU_SW_MINOR_VERSION_C != OCU_SW_MINOR_VERSION) || \
     (OCU_SW_PATCH_VERSION_C != OCU_SW_PATCH_VERSION))
#error "Software Version Numbers of Ocu.c and Ocu.h are different"
#endif

/* Check if source file and DET header file are of the same version */
#if (STD_ON == OCU_DEV_ERROR_DETECT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        #if ((OCU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (OCU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Ocu.c and Det.h are different"
        #endif
    #endif
#endif /* OCU_DEV_ERROR_DETECT */

/* Check if source file and OCU IRQ header file are of the same vendor */
#if (OCU_VENDOR_ID_C != OCU_IRQ_VENDOR_ID)
    #error "Ocu.c and Ocu_Irq.h have different vendor IDs"
#endif
/* Check if source file and OCU IRQ header file are of the same version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION_C != OCU_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION_C != OCU_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION_C != OCU_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu.c and Ocu_Irq.h are different"
#endif
/* Check if source file and OCU IRQ header are of the same Software version */
#if ((OCU_SW_MAJOR_VERSION_C != OCU_IRQ_SW_MAJOR_VERSION) || \
     (OCU_SW_MINOR_VERSION_C != OCU_IRQ_SW_MINOR_VERSION) || \
     (OCU_SW_PATCH_VERSION_C != OCU_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Ocu.c and Ocu_Irq.h are different"
#endif

/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/
/**
@brief Enum containing the possible states of the Ocu driver
*/
#if ((STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL) || \
     (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL))
typedef enum
{
    OCU_STATE_UNINIT = 0x00,                /**< @brief OCU driver status - uninitialized*/
    OCU_STATE_IDLE                          /**< @brief OCU driver status - Idle*/
} Ocu_GlobalStateType;
#endif

/**
* @brief This enumerated type allows the selection of channel status type.
*
*/
#if ((STD_ON == OCU_SET_PIN_ACTION_API) || (STD_ON == OCU_PARAM_CHECK))
typedef enum
{
    OCU_STATUS_UNINITIALIZED = 0,           /**< @brief OCU channel status - uninitialized */
    OCU_STATUS_INITIALIZED,                 /**< @brief OCU channel status - initialized */
    OCU_STATUS_STOPPED,                     /**< @brief OCU channel status - stopped */
    OCU_STATUS_RUNNING                      /**< @brief OCU channel status - expired */
} Ocu_ChannelStatusType;  /* PRQA S 3448*/
#endif
/*===============================================================================================
*                                       LOCAL MACROS
===============================================================================================*/


/*===============================================================================================
*                                       LOCAL CONSTANTS
===============================================================================================*/


/*===============================================================================================
*                                       LOCAL VARIABLES
===============================================================================================*/

#define OCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"

/**
* @brief    Array of pointers to Ocu high level configuration structure - the pointer is valid only when the driver is in initialized state for a given partition
*/
static const Ocu_ConfigType * Ocu_spcxConfig[OCU_MAX_PARTITIONS];

#define OCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Ocu_MemMap.h"


#define OCU_START_SEC_VAR_CLEARED_8
#include "Ocu_MemMap.h"

#if ((STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL) || \
     (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL))
/**
* @brief Variable storing the current state of the Ocu driver
*/
static Ocu_GlobalStateType Ocu_seGlobalState[OCU_MAX_PARTITIONS] = {OCU_STATE_UNINIT};
#endif

#if (STD_ON == OCU_PARAM_CHECK)
/**
* @brief    This arrays shall be used to store the internal running state of each OCU channel.
* @details  This array shall be initialized by Ocu_Init() function and shall be used by all APIs' which
            require a certain mode to function.
            Possible values for each channel: OCU_STATUS_UNINITIALIZED, OCU_STATUS_INITIALIZED,
            OCU_STATUS_STOPPED, OCU_STATUS_RUNNING
*/
static Ocu_ChannelStatusType Ocu_saxChannelState[OCU_NUM_HW_CHANNELS] = {OCU_STATUS_UNINITIALIZED};
#endif

#define OCU_STOP_SEC_VAR_CLEARED_8
#include "Ocu_MemMap.h"


#define OCU_START_SEC_VAR_CLEARED_BOOLEAN
#include "Ocu_MemMap.h"

/**
* @brief    This arrays shall be used to store the Notification enabled information of all channels
* @details  This array shall be initialized by Ocu_Init() function and shall be set / reset
*           by Ocu_EnableNotification and Ocu_DisableNotification functions.
*           Possible values for each channel: TRUE, FALSE
*/
#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
static boolean Ocu_sabNotificationEnabled[OCU_NUM_HW_CHANNELS];
#endif
#define OCU_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Ocu_MemMap.h"

/*===============================================================================================
*                                       GLOBAL CONSTANTS
===============================================================================================*/
#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

#if (STD_ON == OCU_PRECOMPILE_SUPPORT)
/** @brief   Array of pointers to Ocu high level config structures */
extern const Ocu_ConfigType * const Ocu_gapcxConfig[OCU_MAX_PARTITIONS];
#endif

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/

/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL)

static inline Std_ReturnType Ocu_ValidateGlobalConfigCall(uint8 ServiceId);

static inline void Ocu_EndValidateGlobalConfigCall(Std_ReturnType ValidCall, uint8 ServiceId);

#endif

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
/**
* @brief          Validate the call of a function impacting the configuration of one of the driver's
* @details        channels. Before executing, a function which changes the configuration of a
*                 channel shall check if:
*                 1. It is not preempting itself
*                 2. It is not preempting a function that changes the configuration of the
*                    entire driver
*                 In any of the above cases, the function will report an error to Det,
*                 depending on the environment the driver is run in.
*
* @param[in]      ServiceId       Id of the service calling this function
*
* @return         Std_ReturnType  Call is valid or not
* @retval         E_OK            Caller of the function can continue its execution
* @retval         E_NOT_OK        Caller of the function should drop execution
*          .
*/
static inline Std_ReturnType Ocu_ValidateChannelConfigCall(Ocu_ChannelType ChannelNumber, uint8 ServiceId);
#endif

#if (STD_ON  == OCU_PARAM_CHECK)

static inline Std_ReturnType Ocu_ValidateParamPtrInit(const Ocu_ConfigType * ConfigPtr);

#if (STD_ON == OCU_SET_PIN_STATE_API)
static inline Std_ReturnType Ocu_ValidatePinState(Ocu_PinStateType PinState);
#endif

#if (STD_ON  == OCU_PARAM_CHECK)
/**
* @brief          Validate the running state for the given channel and API.
* @details        For example: Ocu_StartChannel() can only be called if a channel
*                 is not in  RUNNING mode, while Ocu_StopChannel() can only be called if
*                 the channel is not STOPPED.
*
* @param[in]      ChannelNumber - Ocu channel Id
* @param[in]      ServiceId - Ocu service/API ID
*
* @return         Std_ReturnType  Validity of the parameter
* @retval         E_OK            Parameter is valid
* @retval         E_NOT_OK        Parameter is invalid
*/
static inline Std_ReturnType Ocu_ValidateRunningState(Ocu_ChannelType ChannelNumber, uint8 ServiceId);
#endif  /* OCU_PARAM_CHECK */

#if (STD_ON == OCU_SET_PIN_ACTION_API)
static inline Std_ReturnType Ocu_ValidatePinAction(Ocu_PinActionType PinAction);
#endif

#if ((STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
/**
* @brief          Validate the Compare match Value parameter against the maximum counter value.*
*                 In case an error is detected, the function will report an error to Det
*
* @param[in]      CompareValue    Value of the compare match
* @param[in]      ServiceId     Id of the service calling this function
*
* @return         Std_ReturnType  Validity of the parameter
* @retval         E_OK            Parameter is valid
* @retval         E_NOT_OK        Parameter is invalid
*/
static inline Std_ReturnType Ocu_ValidateCompareValue(Ocu_ChannelType ChannelNumber, Ocu_ValueType CompareValue, uint8 ServiceId);
#endif

#if ((STD_ON == OCU_SET_PIN_ACTION_API) || (STD_ON == OCU_SET_PIN_STATE_API))
/**
* @brief          Validate if Output Pin is enabled for a certain channel.
*                 In case an error is detected, the function will report an error to Det
*
* @param[in]      ServiceId     Id of the service calling this function
*
* @return         Std_ReturnType  Validity of the parameter
* @retval         E_OK            Parameter is valid
* @retval         E_NOT_OK        Parameter is invalid
*/
static inline Std_ReturnType Ocu_ValidatePinSetup(Ocu_ChannelType ChannelNumber, uint8 ServiceId);
#endif

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
static inline Std_ReturnType Ocu_ValidateParamNotification(Ocu_ChannelType ChannelNumber, uint8 ServiceId);
#endif

#endif

/*==================================================================================================
*                                  GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/
#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL)

/**
* @brief          Validate the call of a function impacting the configuration of the entire driver.
* @details        Before executing, a function which changes the configuration of the entire driver
*                 shall check if:
*                 1. It is not preempting itself
*                 2. It is not preempting another function that changes the configuration of the
*                    entire driver
*                 3. It is not preempting a function that changes the configuration of one of the
*                    driver's channels
*                 In any of the above cases, the function will report an error to Det,
*                 depending on the environment the driver is run in.
*
*
* @param[in]      ServiceId       Id of the service calling this function
*
* @return         Std_ReturnType  Call is valid or not
* @retval         E_OK            Caller of the function can continue its execution
* @retval         E_NOT_OK        Caller of the function should drop execution
*
*
*          .
*/
static inline Std_ReturnType Ocu_ValidateGlobalConfigCall(uint8 ServiceId)
{
    /* Variable to store the value returned by the function */
    Std_ReturnType RetVal;
    uint8 CoreId = (uint8)Ocu_GetCoreId();

    if (OCU_STATE_UNINIT == Ocu_seGlobalState[CoreId])
    {
        RetVal = (OCU_INIT_ID != ServiceId) ? (Std_ReturnType)OCU_E_UNINIT : (Std_ReturnType)E_OK;
        if ((Std_ReturnType)E_OK != RetVal)
        {
            (void)Det_ReportError(  OCU_MODULE_ID,
                                    OCU_INSTANCE_INDEX,
                                    ServiceId,
                                    RetVal
                                 );
        }
    }
    else
    {
        RetVal = (OCU_INIT_ID == ServiceId) ? (Std_ReturnType)OCU_E_ALREADY_INITIALIZED : (Std_ReturnType)E_OK;
        if ((Std_ReturnType)E_OK != RetVal)
        {
            (void)Det_ReportError(  OCU_MODULE_ID,
                                    OCU_INSTANCE_INDEX,
                                    ServiceId,
                                    RetVal
                                 );
        }
    }
    return RetVal;
}


/**
* @brief          Completes the execution of a function impacting the configuration of the entire driver.
* @details        Performs actions in order to ensure that after it's caller has completed the execution
*                 the driver will remain in a state allowing execution of other functions updating the
*                 configuration of the entire driver or of a single channel
*
* @param[in]      ServiceId  The service id of the caller function
* @param[in]      ValidCall    The function call was previously validated
* @return void
*
*
*          .
*/
static inline void Ocu_EndValidateGlobalConfigCall(Std_ReturnType ValidCall, uint8 ServiceId)
{
    uint8 CoreId = (uint8)Ocu_GetCoreId();
    /* Change the state of the driver only if the previous call to Ocu_ValidateGlobalConfigCall()
    stated that the API call is valid, */
    if ((Std_ReturnType)E_OK == ValidCall)
    {
        if (OCU_DEINIT_ID == ServiceId)
        {
            Ocu_seGlobalState[CoreId] = OCU_STATE_UNINIT;
        }
        else
        {
            Ocu_seGlobalState[CoreId] = OCU_STATE_IDLE;
        }
    }
}
#endif

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
static inline Std_ReturnType Ocu_ValidateChannelConfigCall(Ocu_ChannelType ChannelNumber, uint8 ServiceId)
{
    uint8 CoreId = (uint8)Ocu_GetCoreId();

    /* Check if the driver is initialized */
    Std_ReturnType RetVal = (OCU_STATE_UNINIT == Ocu_seGlobalState[CoreId]) ? (Std_ReturnType)OCU_E_UNINIT : (Std_ReturnType)E_OK;

    if ((Std_ReturnType)E_OK == RetVal)
    {
        /* Check if the channel number is in valid range */
        RetVal = (ChannelNumber < OCU_NUM_HW_CHANNELS) ? (Std_ReturnType)E_OK : (Std_ReturnType)OCU_E_PARAM_INVALID_CHANNEL;
        if ((Std_ReturnType)E_OK == RetVal)
        {
            if (NULL_PTR != Ocu_spcxConfig[CoreId])
            {
                RetVal = (255U == (uint8)((*Ocu_spcxConfig[CoreId]->Ocu_Channel_UseMap)[ChannelNumber])) ? (Std_ReturnType)OCU_E_PARAM_CONFIG : (Std_ReturnType)E_OK;
            }
            else
            {
                /* Driver not yet initialized */
                RetVal = (Std_ReturnType)OCU_E_UNINIT;
            }
        }
    }

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError(OCU_MODULE_ID, OCU_INSTANCE_INDEX, ServiceId, RetVal);
    }
    return RetVal;
}

#endif

#if (STD_ON  == OCU_PARAM_CHECK)

/**
* @brief          Validate the configuration parameter of the Ocu_Init API. The check is required
*                 only in variant Post-Build, where the pointer should not be NULL.In case an
*                 error is detected, the function will report an error to Det,
*                 depending on the environment the driver is run in.
*
*
* @param[in]      ConfigPtr       Pointer to the configuration the driver is to be init with
*
* @return         Std_ReturnType  Validity of the pointer
* @retval         E_OK            Pointer is valid
* @retval         E_NOT_OK        Pointer is invalid
*
*
*          .
*/
static inline Std_ReturnType Ocu_ValidateParamPtrInit(const Ocu_ConfigType * ConfigPtr)
{
    /* Variable to store the value returned by the function */
    Std_ReturnType RetVal;
    uint8 CoreId = (uint8)Ocu_GetCoreId();

#if (STD_ON == OCU_PRECOMPILE_SUPPORT)
    /* Ignore compiler warning for pre-compile configurations */
    (void)ConfigPtr;
#endif

#if (STD_ON == OCU_PRECOMPILE_SUPPORT)
    /* For pre-compile, check DET error if the received config pointer is not NULL */
    RetVal = (NULL_PTR != ConfigPtr) ? (Std_ReturnType)OCU_E_INIT_FAILED : (Std_ReturnType)E_OK;
#else
    /* For post build, check DET error if the received config pointer is NULL */
    RetVal = (NULL_PTR == ConfigPtr) ? (Std_ReturnType)OCU_E_INIT_FAILED : (Std_ReturnType)E_OK;
#endif
    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError(  OCU_MODULE_ID,
                                OCU_INSTANCE_INDEX,
                                OCU_INIT_ID,
                                RetVal
                             );
    }
#if (STD_OFF == OCU_PRECOMPILE_SUPPORT)
    else
    {
        RetVal = (CoreId != ConfigPtr->CoreId) ? (Std_ReturnType)OCU_E_PARAM_CONFIG : (Std_ReturnType)E_OK;
        if ((Std_ReturnType)E_OK != RetVal)
        {
            (void)Det_ReportError(  OCU_MODULE_ID,
                                    OCU_INSTANCE_INDEX,
                                    OCU_INIT_ID,
                                    RetVal
                                 );
        }
    }
#else
    else
    {
        RetVal = (NULL_PTR == Ocu_gapcxConfig[CoreId]) ? (Std_ReturnType)OCU_E_INIT_FAILED : (Std_ReturnType)E_OK;
        if ((Std_ReturnType)E_OK != RetVal)
        {
            (void)Det_ReportError(  OCU_MODULE_ID,
                                    OCU_INSTANCE_INDEX,
                                    OCU_INIT_ID,
                                    RetVal
                                 );
        }
        else
        {
            RetVal = (CoreId != Ocu_gapcxConfig[CoreId]->CoreId) ? (Std_ReturnType)OCU_E_PARAM_CONFIG : (Std_ReturnType)E_OK;
            if ((Std_ReturnType)E_OK != RetVal)
            {
                (void)Det_ReportError(  OCU_MODULE_ID,
                                        OCU_INSTANCE_INDEX,
                                        OCU_INIT_ID,
                                        RetVal
                                     );
            }
        }
    }
#endif

    return RetVal;
}

#if (STD_ON  == OCU_PARAM_CHECK)
/**
* @brief    Validate the running state for the given channel and API.
*
*/
static inline Std_ReturnType Ocu_ValidateRunningState(Ocu_ChannelType ChannelNumber, uint8 ServiceId)
{
    /* Variable to store the value returned by the function */
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;

    /* Check if the dutyCycle param is in valid range */
    if (OCU_STATUS_RUNNING == Ocu_saxChannelState[ChannelNumber])
    {
        if (OCU_STARTCHANNEL_ID == ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16)OCU_MODULE_ID,
                (uint8)OCU_INSTANCE_INDEX,
                (uint8)OCU_STARTCHANNEL_ID,
                (uint8)OCU_E_BUSY
            );

            RetVal = (Std_ReturnType)E_NOT_OK;
        }
#if (STD_ON == OCU_SET_PIN_STATE_API)
        else if (OCU_SETPINSTATE_ID == ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16)OCU_MODULE_ID,
                (uint8)OCU_INSTANCE_INDEX,
                (uint8)OCU_SETPINSTATE_ID,
                (uint8)OCU_E_PARAM_INVALID_STATE
            );
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
#endif

#if (STD_ON == OCU_DEINIT_API)
        else if (OCU_DEINIT_ID == ServiceId)
        {
            (void)Det_ReportError
            (
                (uint16)OCU_MODULE_ID,
                (uint8)OCU_INSTANCE_INDEX,
                (uint8)OCU_DEINIT_ID,
                (uint8)OCU_E_PARAM_INVALID_STATE
            );
            RetVal = (Std_ReturnType)E_NOT_OK;
        }
#endif
        else
        {
            /*do nothing*/
        }
    }

    if ((OCU_STOPCHANNEL_ID == ServiceId) && (OCU_STATUS_STOPPED == Ocu_saxChannelState[ChannelNumber]))
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
    }

    return RetVal;
}
#endif  /* OCU_PARAM_CHECK */

#if (STD_ON == OCU_SET_PIN_STATE_API)
/**
* @brief          Validate the PinState parameter (only OCU_LOW and OCU_HIGH are allowed) . In case an
*                 error is detected, the function will report an error to Det,
*                 depending on the environment the driver is run in.
*
*
* @param[in]      PinState        Pin State level
*
* @return         Std_ReturnType  Validity of the parameter
* @retval         E_OK            Parameter is valid
* @retval         E_NOT_OK        Parameter is invalid
*/
static inline Std_ReturnType Ocu_ValidatePinState(Ocu_PinStateType PinState)
{
    /* Variable to store the value returned by the function */
    Std_ReturnType RetVal = ((PinState != OCU_LOW) && (PinState != OCU_HIGH)) ? (Std_ReturnType)OCU_E_PARAM_INVALID_STATE : (Std_ReturnType)E_OK;

    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError(  OCU_MODULE_ID,
                                OCU_INSTANCE_INDEX,
                                OCU_SETPINSTATE_ID,
                                RetVal
                             );
    }
    return RetVal;
}
#endif

#if ((STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
static inline Std_ReturnType Ocu_ValidateCompareValue(Ocu_ChannelType ChannelNumber, Ocu_ValueType CompareValue, uint8 ServiceId)
{
    Ocu_ValueType lMaxCntVal;

    /* Check if the channel number is in valid range */
    Std_ReturnType RetVal = (ChannelNumber < OCU_NUM_HW_CHANNELS) ? (Std_ReturnType)E_OK : (Std_ReturnType)OCU_E_PARAM_INVALID_CHANNEL;
    if ((Std_ReturnType)E_OK == RetVal)
    {
        lMaxCntVal = Ocu_Ipw_GetMaxCounterValue(ChannelNumber);

        /* Check if the dutyCycle param is in valid range */
        RetVal = ((uint32)lMaxCntVal < (uint32)CompareValue) ? (Std_ReturnType)OCU_E_PARAM_INVALID_VALUE : (Std_ReturnType)E_OK;
        if ((Std_ReturnType)E_OK != RetVal)
        {
            (void)Det_ReportError(OCU_MODULE_ID, OCU_INSTANCE_INDEX, ServiceId, RetVal);
        }
    }
    else
    {
        (void)Det_ReportError(OCU_MODULE_ID, OCU_INSTANCE_INDEX, ServiceId, RetVal);
    }
    return RetVal;
}
#endif

#if ((STD_ON == OCU_SET_PIN_ACTION_API) || (STD_ON == OCU_SET_PIN_STATE_API))
static inline Std_ReturnType Ocu_ValidatePinSetup(Ocu_ChannelType ChannelNumber, uint8 ServiceId)
{
    boolean PinConfigStatus;
    uint8 CoreId = (uint8)Ocu_GetCoreId();

    /* Check if the channel number is in valid range */
    Std_ReturnType RetVal = (ChannelNumber < OCU_CONF_CHANNELS_PB) ? (Std_ReturnType)E_OK : (Std_ReturnType)OCU_E_PARAM_INVALID_CHANNEL;

    if ((Std_ReturnType)E_OK == RetVal)
    {
        if (NULL_PTR != Ocu_spcxConfig[CoreId])
        {
            if (NULL_PTR != Ocu_spcxConfig[CoreId]->pOcuChannelsConfig)
            {
                PinConfigStatus = (*Ocu_spcxConfig[CoreId]->pOcuChannelsConfig)[ChannelNumber].OutputPinEnable;
                RetVal = (TRUE != PinConfigStatus) ? (Std_ReturnType)OCU_E_PARAM_NO_PIN : (Std_ReturnType)E_OK;
            }
            else
            {
                RetVal = (Std_ReturnType)OCU_E_PARAM_POINTER;
            }
        }
        else
        {
            /* Driver not yet initialized */
            RetVal = (Std_ReturnType)OCU_E_UNINIT;
        }
    }
    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError(OCU_MODULE_ID, OCU_INSTANCE_INDEX, ServiceId, RetVal);
    }
    return RetVal;
}
#endif  /* ((STD_ON == OCU_SET_PIN_ACTION_API) || (STD_ON == OCU_SET_PIN_STATE_API)) */

#if (STD_ON == OCU_SET_PIN_ACTION_API)
/**
* @brief          Validate the PinAction parameter (only OCU_SET_LOW, OCU_SET_HIGH, OCU_TOGGLE and
*                 OCU_DISABLE are allowed). In case an error is detected, the function will report
*                 an error to Det, depending on the environment the driver is run in.
*
* @param[in]      PinAction        Pin Action type
*
* @return         Std_ReturnType  Validity of the parameter
* @retval         E_OK            Parameter is valid
* @retval         E_NOT_OK        Parameter is invalid
*/
static inline Std_ReturnType Ocu_ValidatePinAction(Ocu_PinActionType PinAction)
{

    /* Variable to store the value returned by the function */
    Std_ReturnType RetVal = (   (PinAction != OCU_SET_LOW)  &&
                                (PinAction != OCU_SET_HIGH) &&
                                (PinAction != OCU_TOGGLE)   &&
                                (PinAction != OCU_DISABLE) )    ? (Std_ReturnType)OCU_E_PARAM_INVALID_ACTION : (Std_ReturnType)E_OK;
    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError(  OCU_MODULE_ID,
                                OCU_INSTANCE_INDEX,
                                OCU_SETPINACTION_ID,
                                RetVal
                             );
    }
    return RetVal;

}
#endif

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)

/**
* @brief          Validate the notification handler of a Ocu channel.
*                 In order to be valid, the notification handler should not be
*                 NULL. In case it is NULL, the function will report an error to
*                 Det or Serr,depending on the environment the driver is run in.
*
*
* @param[in]      ChannelNumber   The Id of the given channel
* @param[in]      Notification    The notification edge type
*
* @return   Std_ReturnType  Validity of notification handler
* @RetVal       (Std_ReturnType)E_OK        Notification handler is valid
* @RetVal       (Std_ReturnType)E_NOT_OK    Notification handler is not valid
*
*
*          .
*/
static inline Std_ReturnType Ocu_ValidateParamNotification(Ocu_ChannelType ChannelNumber, uint8 ServiceId)
{
    Ocu_NotificationType lpfChNotification;
    uint8 CoreId = (uint8)Ocu_GetCoreId();

    /* Check if the channel number is in valid range */
    Std_ReturnType RetVal = (ChannelNumber < OCU_CONF_CHANNELS_PB) ? (Std_ReturnType)E_OK : (Std_ReturnType)OCU_E_PARAM_INVALID_CHANNEL;

    if ((Std_ReturnType)E_OK == RetVal)
    {
        if (NULL_PTR != Ocu_spcxConfig[CoreId])
        {
            if (NULL_PTR != Ocu_spcxConfig[CoreId]->pOcuChannelsConfig)
            {
                lpfChNotification = (*Ocu_spcxConfig[CoreId]->pOcuChannelsConfig)[ChannelNumber].pfChNotification;
                /* store the value to be returned according to the Notification param */
                RetVal = (NULL_PTR == lpfChNotification) ? (Std_ReturnType)OCU_E_NO_VALID_NOTIF : (Std_ReturnType)E_OK;
            }
            else
            {
                RetVal = (Std_ReturnType)OCU_E_PARAM_POINTER;
            }
        }
        else
        {
            /* Driver not yet initialized */
            RetVal = (Std_ReturnType)OCU_E_UNINIT;
        }
    }
    if ((Std_ReturnType)E_OK != RetVal)
    {
        (void)Det_ReportError(OCU_MODULE_ID, OCU_INSTANCE_INDEX, ServiceId, RetVal);
    }

    return RetVal;
}
#endif

#endif

/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)

/**
 * @brief Generic function used by all interrupt service routines to call notification
 *
 */
void Ocu_ProcessChannelNotification(uint16 Channel)
{
    Ocu_NotificationType lpfChNotification;
    uint8 CoreId = (uint8)Ocu_GetCoreId();

    if ((Channel < OCU_CONF_CHANNELS_PB) && (NULL_PTR != Ocu_spcxConfig[CoreId]->pOcuChannelsConfig))
    {
        lpfChNotification = (*Ocu_spcxConfig[CoreId]->pOcuChannelsConfig)[Channel].pfChNotification;

        if ((NULL_PTR != lpfChNotification) && (TRUE == Ocu_sabNotificationEnabled[Channel]))
        {
            lpfChNotification();
        }
    }
}

#endif

/*================================================================================================*/
/**
* @brief        This function initializes the Ocu driver.
* @implements   Ocu_Init_Activity
*
*/
void Ocu_Init(const Ocu_ConfigType * ConfigPtr)
{
    uint8 ChIdx;   /* Channel index used in the loop */
    uint8 CoreId = (uint8)Ocu_GetCoreId();
#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL) || (STD_ON  == OCU_PARAM_CHECK)
    Std_ReturnType IsValidCall;
#endif

#if (STD_ON == OCU_PRECOMPILE_SUPPORT)
    (void)ConfigPtr;
#endif

#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL)
    IsValidCall = Ocu_ValidateGlobalConfigCall(OCU_INIT_ID);
    if ((Std_ReturnType)E_OK == IsValidCall)
#endif
    {
#if (STD_ON  == OCU_PARAM_CHECK)
        IsValidCall = Ocu_ValidateParamPtrInit(ConfigPtr);
        if ((Std_ReturnType)E_OK == IsValidCall)
#endif
        {
            /* All validations passed. Here starts the actual
               functional code of the function */

            /* Save configuration pointer in global variable */
#if (STD_ON == OCU_PRECOMPILE_SUPPORT)
            Ocu_spcxConfig[CoreId] = Ocu_gapcxConfig[CoreId];
#else
            Ocu_spcxConfig[CoreId] = ConfigPtr;
#endif
            if (NULL_PTR != Ocu_spcxConfig[CoreId])
            {
                for (ChIdx = 0U; ChIdx < OCU_NUM_HW_CHANNELS; ++ChIdx)
                {
                    if (255U != (uint8)((*Ocu_spcxConfig[CoreId]->Ocu_Channel_UseMap)[ChIdx]))
                    {
#if (STD_ON  == OCU_PARAM_CHECK)
                        /* Initialize global data */
                        Ocu_saxChannelState[ChIdx] = OCU_STATUS_INITIALIZED;
#endif

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
                        /* Disable notifications */
                        Ocu_sabNotificationEnabled[ChIdx] = FALSE;
#endif
                    }
                }

                Ocu_Ipw_Init(Ocu_spcxConfig[CoreId]->pcxIpConfig);
            }
#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL) || (STD_ON  == OCU_PARAM_CHECK)
            else
            {
                IsValidCall = (Std_ReturnType)OCU_E_INIT_FAILED;
            }
#endif
        }
    }

#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL)
    Ocu_EndValidateGlobalConfigCall(IsValidCall, OCU_INIT_ID);
#endif
}


/*===============================================================================================*/
#if (STD_ON == OCU_DEINIT_API)
/**
* @brief        This function deinitializes the Ocu driver.
* @implements   Ocu_DeInit_Activity
*
*/
void Ocu_DeInit(void)
{
    uint8 ChIdx;   /* Channel index used in the loop */
    uint8 CoreId;

#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL) || (STD_ON  == OCU_PARAM_CHECK)
    Std_ReturnType IsValidCall;
#endif

#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL)
    IsValidCall = Ocu_ValidateGlobalConfigCall(OCU_DEINIT_ID);
    if ((Std_ReturnType)E_OK == IsValidCall)
#endif
    {
        CoreId = (uint8)Ocu_GetCoreId();

        if (NULL_PTR != Ocu_spcxConfig[CoreId])
        {

#if (STD_ON  == OCU_PARAM_CHECK)
            for (ChIdx = 0U; ChIdx < OCU_NUM_HW_CHANNELS; ++ChIdx)
            {
                if (255U != (uint8)(*Ocu_spcxConfig[CoreId]->Ocu_Channel_UseMap)[ChIdx])
                {
                    if ((Std_ReturnType)E_NOT_OK == Ocu_ValidateRunningState(ChIdx, OCU_DEINIT_ID))
                    {
                        IsValidCall = (Std_ReturnType)E_NOT_OK;
                    }
                }
            }
            if ((Std_ReturnType)E_OK == IsValidCall)
#endif
            {
                /* All validations passed. Here starts the actual
                functional code of the function */
                Ocu_Ipw_DeInit(Ocu_spcxConfig[CoreId]->pcxIpConfig);

                for (ChIdx = 0U; ChIdx < OCU_NUM_HW_CHANNELS; ++ChIdx)
                {
                    if (255U != (uint8)(*Ocu_spcxConfig[CoreId]->Ocu_Channel_UseMap)[ChIdx])
                    {
#if (STD_ON  == OCU_PARAM_CHECK)
                        /* initialize global data */
                        Ocu_saxChannelState[ChIdx] = OCU_STATUS_UNINITIALIZED;
#endif

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
                        /* Disable notifications */
                        Ocu_sabNotificationEnabled[ChIdx] = FALSE;
#endif
                    }
                }

                /* Set global configuration pointer back to NULL, flagging that the driver is deinitialized */
                Ocu_spcxConfig[CoreId] = NULL_PTR;
            }
        }
#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL) || (STD_ON  == OCU_PARAM_CHECK)
        else
        {
            /* Driver not yet initialized */
            IsValidCall = (Std_ReturnType)OCU_E_UNINIT;
        }
#endif
    }

#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL)
    Ocu_EndValidateGlobalConfigCall(IsValidCall, OCU_DEINIT_ID);
#endif
}
#endif

/*===============================================================================================*/
/**
* @brief            This function starts a specified Ocu channel.
* @implements       Ocu_StartChannel_Activity
*
*/
Std_ReturnType Ocu_StartChannel(Ocu_ChannelType ChannelNumber)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    
#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    if ((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_STARTCHANNEL_ID))
    {

#endif

#if (STD_ON  == OCU_PARAM_CHECK)
        if ((Std_ReturnType)E_OK == Ocu_ValidateRunningState(ChannelNumber, OCU_STARTCHANNEL_ID))
        {
#endif  /* OCU_PARAM_CHECK */

#if (STD_ON  == OCU_PARAM_CHECK)
            /*set channel status to RUNNING*/
            Ocu_saxChannelState[ChannelNumber] = OCU_STATUS_RUNNING;
#endif

            /* All validations passed. Here starts the actual
            functional code of the function */
            Ocu_Ipw_StartChannel(ChannelNumber);
            RetVal = (Std_ReturnType)E_OK;

#if (STD_ON  == OCU_PARAM_CHECK)
        }
#endif  /* OCU_PARAM_CHECK */

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    }
#endif

    return RetVal;
}

/*===============================================================================================*/
/**
* @brief            This function stops a specified Ocu channel.
* @implements       Ocu_StopChannel_Activity
*
*/
void Ocu_StopChannel(Ocu_ChannelType ChannelNumber)
{
#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    if ((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_STOPCHANNEL_ID))
    {
#endif

#if (STD_ON  == OCU_PARAM_CHECK)
        if ((Std_ReturnType)E_OK == Ocu_ValidateRunningState(ChannelNumber, OCU_STOPCHANNEL_ID))
        {
#endif  /* OCU_PARAM_CHECK */

#if (STD_ON  == OCU_PARAM_CHECK)
            /*set channel status to STOPPED*/
            Ocu_saxChannelState[ChannelNumber] = OCU_STATUS_STOPPED;
#endif

            /* All validations passed. Here starts the actual
            functional code of the function */
            Ocu_Ipw_StopChannel(ChannelNumber);
#if (STD_ON  == OCU_PARAM_CHECK)
        }
#endif  /* OCU_PARAM_CHECK */

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    }

#endif
}

/*===============================================================================================*/
#if (STD_ON == OCU_SET_PIN_STATE_API)
/**
* @brief            Service to set immediately the level of the pin associated to an OCU channel.
* @implements       Ocu_SetPinState_Activity
*
*/
void Ocu_SetPinState(Ocu_ChannelType ChannelNumber, Ocu_PinStateType PinState)
{
#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    if ((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_SETPINSTATE_ID))
    {
#endif

#if (STD_ON  == OCU_PARAM_CHECK)
        if ((Std_ReturnType)E_OK == Ocu_ValidatePinState(PinState))
        {
            if ((Std_ReturnType)E_OK == Ocu_ValidateRunningState(ChannelNumber, OCU_SETPINSTATE_ID))
            {
                if ((Std_ReturnType)E_OK == Ocu_ValidatePinSetup(ChannelNumber, OCU_SETPINSTATE_ID))
                {
#endif
                    /* All validations passed. Here starts the actual
                    functional code of the function */
                    Ocu_Ipw_SetPinState((uint16)ChannelNumber, (OCU_PIN_STATE_TYPE)PinState);
#if (STD_ON  == OCU_PARAM_CHECK)
                }
            }
        }
#endif

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    }

#endif
}
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_SET_PIN_ACTION_API)
/**
* @brief            Service to indicate the driver what shall be done automatically by hardware
*                   (if supported) upon compare match.
* @implements       Ocu_SetPinAction_Activity
*
*/
void Ocu_SetPinAction(Ocu_ChannelType ChannelNumber, Ocu_PinActionType PinAction)
{
#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    if ((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_SETPINACTION_ID))
    {
#endif

#if (STD_ON  == OCU_PARAM_CHECK)
        if ((Std_ReturnType)E_OK == Ocu_ValidatePinAction(PinAction))
        {
            if ((Std_ReturnType)E_OK == Ocu_ValidatePinSetup(ChannelNumber, OCU_SETPINACTION_ID))
            {
#endif
                /* Call the Ipw function to set pin action */
                Ocu_Ipw_SetPinAction((uint16)ChannelNumber, (OCU_PIN_ACTION_TYPE)PinAction);
#if (STD_ON  == OCU_PARAM_CHECK)
            }
        }
#endif

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    }

#endif
}
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_GET_COUNTER_API)
/**
* @brief            Service to read the current value of the counter.
* @implements       Ocu_GetCounter_Activity
*
*/
Ocu_ValueType Ocu_GetCounter(Ocu_ChannelType ChannelNumber)
{
    Ocu_ValueType RetVal = 0U;

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    if ((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_GETCOUNTER_ID))
#endif
    {
        /* All validations passed. Here starts the actual
         *  functional code of the function */
        RetVal = Ocu_Ipw_GetCounter(ChannelNumber);
    }
    return RetVal;
}
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/**
* @brief            This service is used to disable notifications from an OCU channel.
* @implements       Ocu_DisableNotification_Activity
*
*/
void Ocu_DisableNotification(Ocu_ChannelType ChannelNumber)
{
#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    if ((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_DISABLENOTIFICATION_ID))
    {
#endif

#if (STD_ON  == OCU_PARAM_CHECK)
        if ((Std_ReturnType)E_OK == Ocu_ValidateParamNotification(ChannelNumber, OCU_DISABLENOTIFICATION_ID))
        {
#endif
            /* Disable upper layer notifications */
            Ocu_Ipw_DisableNotification((uint16)ChannelNumber);
            Ocu_sabNotificationEnabled[ChannelNumber] = FALSE;
#if (STD_ON  == OCU_PARAM_CHECK)
        }
#endif

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    }

#endif
}
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/**
* @brief            This service is used to enable notifications from an OCU channel.
* @implements       Ocu_EnableNotification_Activity
*
*/
void Ocu_EnableNotification(Ocu_ChannelType ChannelNumber)
{
#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    if ((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_ENABLENOTIFICATION_ID))
    {
#endif
#if (STD_ON  == OCU_PARAM_CHECK)
        if ((Std_ReturnType)E_OK == Ocu_ValidateParamNotification(ChannelNumber, OCU_ENABLENOTIFICATION_ID))
        {
#endif
            /* Enable upper layer notifications */
            Ocu_Ipw_EnableNotification((uint16)ChannelNumber);
            Ocu_sabNotificationEnabled[ChannelNumber] = TRUE;
#if (STD_ON  == OCU_PARAM_CHECK)
        }
#endif
#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    }

#endif
}
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_VERSION_INFO_API)
/**
* @brief            This function returns Ocu driver version details
* @implements       Ocu_GetVersionInfo_Activity
*
*/
void Ocu_GetVersionInfo(Std_VersionInfoType * versioninfo)
{
#if (STD_ON == OCU_DEV_ERROR_DETECT)
    if (NULL_PTR != versioninfo)
    {
#endif

        (versioninfo)->vendorID         = (uint16)OCU_VENDOR_ID;
        (versioninfo)->moduleID         = OCU_MODULE_ID;

        (versioninfo)->sw_major_version = (uint8)OCU_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = (uint8)OCU_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = (uint8)OCU_SW_PATCH_VERSION;

#if (STD_ON == OCU_DEV_ERROR_DETECT)
    }
    else
    {
        (void)Det_ReportError(  OCU_MODULE_ID,
                                OCU_INSTANCE_INDEX,
                                OCU_GETVERSIONINFO_ID,
                                OCU_E_PARAM_POINTER
                             );
    }
#endif
}
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API)
/**
* @brief            Service to set the value of the channel threshold using an absolute input data.
* @implements       Ocu_SetAbsoluteThreshold_Activity
*
*/
Ocu_ReturnType Ocu_SetAbsoluteThreshold(Ocu_ChannelType ChannelNumber, Ocu_ValueType ReferenceValue, Ocu_ValueType AbsoluteValue)
{
    Ocu_ReturnType RetVal = OCU_CM_OUT_REF_INTERVAL;

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    if ((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_SETABSOLUTETHRESHOLD_ID))
    {
#endif

#if (STD_ON  == OCU_PARAM_CHECK)
        if ((Std_ReturnType)E_OK == Ocu_ValidateCompareValue(ChannelNumber, ReferenceValue, OCU_SETABSOLUTETHRESHOLD_ID))
        {
            if ((Std_ReturnType)E_OK == Ocu_ValidateCompareValue(ChannelNumber, AbsoluteValue, OCU_SETABSOLUTETHRESHOLD_ID))
            {
#endif
                RetVal = (OCU_IPW_CM_IN_REF_INTERVAL == Ocu_Ipw_SetAbsoluteThreshold((uint16)ChannelNumber, (Ocu_Ipw_ValueType)ReferenceValue, (Ocu_Ipw_ValueType)AbsoluteValue)) ? OCU_CM_IN_REF_INTERVAL : OCU_CM_OUT_REF_INTERVAL;
#if (STD_ON  == OCU_PARAM_CHECK)
            }
        }
#endif

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    }
#endif

    return RetVal;
}
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API)
/**
* @brief            Service to set the value of the channel threshold relative to the current
*                   value of the counter.
* @implements       Ocu_SetRelativeThreshold_Activity
*
*/
Ocu_ReturnType Ocu_SetRelativeThreshold(Ocu_ChannelType ChannelNumber, Ocu_ValueType RelativeValue)
{
    Ocu_ReturnType RetVal = OCU_CM_OUT_REF_INTERVAL;

#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    if ((Std_ReturnType)E_OK == Ocu_ValidateChannelConfigCall(ChannelNumber, OCU_SETRELATIVETHRESHOLD_ID))
    {
#endif
#if (STD_ON  == OCU_PARAM_CHECK)
        if ((Std_ReturnType)E_OK == Ocu_ValidateCompareValue(ChannelNumber, RelativeValue, OCU_SETRELATIVETHRESHOLD_ID))
        {
#endif
            RetVal = (OCU_IPW_CM_IN_REF_INTERVAL == Ocu_Ipw_SetRelativeThreshold((uint16)ChannelNumber, (Ocu_Ipw_ValueType)RelativeValue)) ? OCU_CM_IN_REF_INTERVAL : OCU_CM_OUT_REF_INTERVAL;
#if (STD_ON  == OCU_PARAM_CHECK)
        }
#endif
#if (STD_ON == OCU_VALIDATE_CHANNEL_CONFIG_CALL)
    }
#endif

    return RetVal;
}
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_SET_CLOCK_MODE_API)
/**
* @brief    Implementation specific function to change the peripheral clock frequency.
* @implements   Ocu_SetClockMode_Activity
*
*/
void Ocu_SetClockMode(Ocu_SelectPrescalerType Prescaler)
{
#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL)
    Std_ReturnType IsValidCall = Ocu_ValidateGlobalConfigCall(OCU_SETCLOCKMODE_ID);
    if ((Std_ReturnType)E_OK == IsValidCall)
#endif
    {
        Ocu_Ipw_SetClockMode((OCU_PIN_SELECT_PRESCALER_TYPE)Prescaler);
    }
#if (STD_ON == OCU_VALIDATE_GLOBAL_CONFIG_CALL)
    Ocu_EndValidateGlobalConfigCall(IsValidCall, OCU_SETCLOCKMODE_ID);
#endif
}
#endif


#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
