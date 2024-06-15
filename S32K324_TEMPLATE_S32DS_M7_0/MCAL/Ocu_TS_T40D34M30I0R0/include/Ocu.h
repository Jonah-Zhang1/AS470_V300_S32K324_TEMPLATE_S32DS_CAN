/*==================================================================================================
*     Project             : RTD AUTOSAR 4.7
*     Platform            : CORTEXM
*     Peripheral          : eMios
*     Dependencies        : none
*
*     Autosar Version     : 4.7.0
*     Autosar Revision    : ASR_REL_4_7_REV_0000
*     Autosar ConfVariant :
*     SWVersion           : 3.0.0
*     BuildVersion        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
*     Copyright 2020 - 2023 NXP Semiconductors
*
*     NXP Confidential. This software is owned or controlled by NXP and may only be
*     used strictly in accordance with the applicable license terms. By expressly
*     accepting such terms or by downloading, installing, activating and/or otherwise
*     using the software, you are agreeing that you have read, and that you agree to
*     comply with and are bound by, such license terms. If you do not agree to be
*     bound by the applicable license terms, then you may not retain, install,
*     activate or otherwise use the software.
==================================================================================================*/

#ifndef OCU_H
#define OCU_H

/**
*   @file           Ocu.h
*   @implements     Ocu.h_Artifact
*   @addtogroup     ocu_driver Ocu Driver
*   @brief          Ocu HLD module API header.
*   @details        Ocu module API header, containing Autosar API and function that are exported by OCU driver
*
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Ocu_Types.h"
#include "Ocu_Cfg.h"
#include "Ocu_EnvCfg.h"
#include "Ocu_Ipw.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_VENDOR_ID                       43
#define OCU_MODULE_ID                       125
#define OCU_AR_RELEASE_MAJOR_VERSION        4
#define OCU_AR_RELEASE_MINOR_VERSION        7
#define OCU_AR_RELEASE_REVISION_VERSION     0
#define OCU_SW_MAJOR_VERSION                3
#define OCU_SW_MINOR_VERSION                0
#define OCU_SW_PATCH_VERSION                0
/*==================================================================================================
 *                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and OCU configuration header file are of the same vendor */
#if (OCU_VENDOR_ID != OCU_CFG_VENDOR_ID)
    #error "Ocu.h and Ocu_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and OCU configuration header file are the same as Autosar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION != OCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION != OCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION != OCU_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Ocu.h and Ocu_Cfg.h are different"
#endif
/* Check if header file and OCU configuration header file are the same software version */
#if ((OCU_SW_MAJOR_VERSION != OCU_CFG_SW_MAJOR_VERSION) || \
     (OCU_SW_MINOR_VERSION != OCU_CFG_SW_MINOR_VERSION) || \
     (OCU_SW_PATCH_VERSION != OCU_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Ocu.h and Ocu_Cfg.h are different"
#endif

/* Check if source file and OCU types header file are of the same vendor */
#if (OCU_VENDOR_ID != OCU_TYPES_VENDOR_ID)
    #error "Ocu.h and Ocu_Types.h have different vendor IDs"
#endif
    /* Check if header file and OCU types header file are the same as Autosar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION != OCU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION != OCU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION != OCU_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Ocu.h and Ocu_Types.h are different"
#endif
/* Check if header file and OCU types header file are the same software version */
#if ((OCU_SW_MAJOR_VERSION != OCU_TYPES_SW_MAJOR_VERSION) || \
     (OCU_SW_MINOR_VERSION != OCU_TYPES_SW_MINOR_VERSION) || \
     (OCU_SW_PATCH_VERSION != OCU_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Ocu.h and Ocu_Types.h are different"
#endif

/* Check if source file and Ocu_EnvCfg header file are of the same vendor */
#if (OCU_VENDOR_ID != OCU_ENVCFG_VENDOR_ID)
    #error "Ocu.h and Ocu_EnvCfg.h have different vendor IDs"
#endif
/* Check if source file and Ocu_EnvCfg header file are of the same AutoSar version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION != OCU_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION != OCU_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION != OCU_ENVCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu.h and Ocu_EnvCfg.h are different"
#endif
/* Check if source file and Ocu_EnvCfg header file are of the same Software version */
#if ((OCU_SW_MAJOR_VERSION != OCU_ENVCFG_SW_MAJOR_VERSION) || \
     (OCU_SW_MINOR_VERSION != OCU_ENVCFG_SW_MINOR_VERSION) || \
     (OCU_SW_PATCH_VERSION != OCU_ENVCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Ocu.h and Ocu_EnvCfg.h are different"
#endif

/* Check if source file and OCU IPW header file are of the same vendor */
#if (OCU_VENDOR_ID != OCU_IPW_VENDOR_ID)
#error "Ocu.h and Ocu_Ipw.h have different vendor IDs"
#endif
/* Check if source file and Ocu_Ipw header file are of the same version */
#if ((OCU_AR_RELEASE_MAJOR_VERSION != OCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_AR_RELEASE_MINOR_VERSION != OCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (OCU_AR_RELEASE_REVISION_VERSION != OCU_IPW_AR_RELEASE_REVISION_VERSION))
#error "Autosar Version Numbers of Ocu.h and Ocu_Ipw.h are different"
#endif
/* Check if source file and Ocu_Ipw header file are of the same Software Version */
#if ((OCU_SW_MAJOR_VERSION != OCU_IPW_SW_MAJOR_VERSION) || \
     (OCU_SW_MINOR_VERSION != OCU_IPW_SW_MINOR_VERSION) || \
     (OCU_SW_PATCH_VERSION != OCU_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Ocu.h and Ocu_Ipw.h are different"
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

#if (STD_ON != OCU_PRECOMPILE_SUPPORT)

#define OCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"
/**
* @brief   Export Post-Build Ocu configurations.
*/
OCU_CONFIG_EXT

#define OCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Ocu_MemMap.h"

#endif

/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/

#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

/*===============================================================================================*/
/**
* @brief        This function initializes the Ocu driver.
* @details      The function Ocu_Init shall initialize all internals variables and the used
*               OCU structure of the microcontroller according to the parameters
*               specified in ConfigPtr.
*               Ocu shall initialize the free-running timers that are used by the driver.
*
*               If development error detection is enabled, calling the routine with a NULL ConfigPtr,
*               Ocu_Init shall raise the development error OCU_E_INIT_FAILED and return without any
*               action.
*
*               If development error detection is enabled, calling the routine Ocu_Init
*               while the OCU driver and hardware are already initialized will cause a
*               development error OCU_E_ALREADY_INITIALIZED.
*               The desired functionality shall be left without any action.
*
*               For pre-compile and link time configuration variants, a NULL pointer shall be passed
*               to the initialization routine. In this case the check for this NULL pointer
*               has to be omitted.
*
*               If development error detection for the Ocu module is enabled, if any function
*               (except Ocu_Init) is called before Ocu_Init has been called, the called function
*               shall raise development error OCU_E_UNINIT.
*
* @param[in]    ConfigPtr       pointer to OCU top configuration structure
*
* @return       void
*
* @implements   Ocu_Init_Activity
*
*/
void Ocu_Init(const Ocu_ConfigType * ConfigPtr);

/*===============================================================================================*/
#if (STD_ON == OCU_DEINIT_API)
/**
* @brief        This function deinitializes the Ocu driver.
* @details      The function Ocu_DeInit shall deinitialize the OCU module.
*
*               The function Ocu_DeInit shall deinitialize the OCU variables and registers that were
*               initialized by Ocu_Init to a state comparable to their power on reset state.
*               The function Ocu_DeInit shall disable OCU interrupts and OCU signal edge notifications.
*               The function Ocu_DeInit shall stop all free-running counters, which are exclusively
*               used by this driver.
*               If development error detection for the Ocu module is enabled,
*               when a development error occurs, the corresponding OCU function shall:
*                    Report the error to the Development Error Tracer.
*                    Skip the desired functionality in order to avoid any corruptions
*                       of data or hardware registers (this means leave the function without any actions).
*               If development error detection is enabled for the OCU driver: if a channel is still in
*               the RUNNING state when the function Ocu_DeInit is called, then the function shall raise
*               the development error OCU_E_PARAM_INVALID_STATE and return without any action.
*               If development error detection for the Ocu module is enabled, if any function
*               (except Ocu_Init) is called before Ocu_Init has been called, the called function
*               shall raise development error OCU_E_UNINIT.
*
* @return       void
*
* @pre          Ocu_Init
* @implements   Ocu_DeInit_Activity
*
*/
void Ocu_DeInit(void);
#endif

/*===============================================================================================*/
/**
* @brief            This function starts a specified Ocu channel.
* @details          The function Ocu_StartChannel shall start an OCU channel by allowing all
*                   compare match configured actions to be performed.
*
*                   The state of the selected channel shall be set to RUNNING If the function
*                   Ocu_StartChannel has been successfully performed.
*
*                   If development error detection is enabled for the OCU driver: If the function
*                   Ocu_StartChannel is called on a channel in the state RUNNING, then the function
*                   shall raise the error OCU_E_BUSY and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   ChannelNumber is invalid (not within the range specified by the configuration),
*                   the function Ocu_StartChannel shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the driver is
*                   not initialized, the function Ocu_StartChannel shall raise the error OCU_E_UNINIT
*                   and return without any action.
*
* @param[in]        ChannelNumber       Ocu channel Id
*
* @return           E_NOT_OK if call to Ocu_ValidateChannelConfigCall() or Ocu_ValidateRunningState()
                    has failed, E_OK otherwise.
* @pre              Ocu_Init
* @implements       Ocu_StartChannel_Activity
*/
Std_ReturnType Ocu_StartChannel(Ocu_ChannelType ChannelNumber);

/*===============================================================================================*/
/**
* @brief            This function stops a specified Ocu channel.
* @details          The function Ocu_StopChannel shall stop an OCU channel by halting compare
*                   match configured actions for this channel.
*
*                   The state of the selected channel shall be set to STOPPED if the function
*                   Ocu_StopChannel is successfully performed. If the function Ocu_StopChannel is
*                   called on a channel in the state STOPPED, then the function shall leave
*                   without any action (no change of the channel state), and shall not raise
*                   a development error.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   ChannelNumber is invalid (not within the range specified by the configuration),
*                   the function Ocu_StopChannel shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the driver
*                   is not initialized, the function Ocu_StopChannel shall raise the error
*                   OCU_E_UNINIT and return without any action.
*
* @param[in]        ChannelNumber - Ocu channel Id
*
* @return           void
*
* @pre              Ocu_Init
*
* @implements       Ocu_StopChannel_Activity
*
*/
void Ocu_StopChannel(Ocu_ChannelType ChannelNumber);

/*===============================================================================================*/
#if (STD_ON == OCU_SET_PIN_STATE_API)
/**
* @brief            Service to set immediately the level of the pin associated to an OCU channel.
* @details          The function Ocu_SetPinState shall set the pin associated with the channel
*                   to the level indicated by PinState.
*
*                   The function Ocu_SetPinState shall be used only if the channel is not in the
*                   RUNNING state.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   ChannelNumber is invalid (not within the range specified by the configuration),
*                   the function Ocu_SetPinState shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action
*
*                   If development error detection is enabled for the OCU driver: If a pin is not
*                   associated with the channel (not defined in the configuration of the channel),
*                   the function Ocu_SetPinState shall raise the error OCU_E_PARAM_NO_PIN and
*                   return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   PinState is invalid (not within the range specified by the configuration),
*                   the function Ocu_SetPinState shall raise the error OCU_E_PARAM_INVALID_STATE
*                   and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the driver
*                   is not initialized, the function Ocu_SetPinState shall raise the error
*                   OCU_E_UNINIT and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the channel
*                   is in the RUNNING state, the function Ocu_SetPinState shall raise the error
*                   OCU_E_PARAM_INVALID_STATE and return without any action.
*
* @param[in]        ChannelNumber - Ocu channel Id
* @param[in]        PinState      - Output Pin State
*
* @return           void
* @pre              Ocu_Init
*
* @implements       Ocu_SetPinState_Activity
*
*/
void Ocu_SetPinState(Ocu_ChannelType ChannelNumber, Ocu_PinStateType PinState);
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_SET_PIN_ACTION_API)
/**
* @brief            Service to indicate the driver what shall be done automatically by hardware
*                   (if supported) upon compare match.
* @details          The function Ocu_SetPinAction shall set the action to be performed by hardware
*                   automatically, at the next compare match in the corresponding OCU channel.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   ChannelNumber is invalid (not within the range specified by the configuration),
*                   the function Ocu_SetPinAction shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If a pin is not
*                   associated with the channel (not defined in the configuration of the channel),
*                   the function Ocu_SetPinAction shall raise the error OCU_E_PARAM_NO_PIN and
*                   return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   PinAction is invalid (not within the range specified by the type), the function
*                   Ocu_SetPinAction shall raise the error OCU_E_PARAM_INVALID_ACTION and return
*                   without any action.
*
*                   If development error detection is enabled for the OCU driver: If the driver
*                   is not initialized, the function Ocu_SetPinAction shall raise the error
*                   OCU_E_UNINIT and return without any action.
*
*                   If a pin is associated with a channel; the relevant action with this pin shall
*                   be performed upon compare match.
*
* @param[in]        ChannelNumber - Ocu channel Id
* @param[in]        PinAction     - Pin Action (OCU_SET_LOW, OCU_SET_HIGH, OCU_TOGGLE, OCU_DISABLE)
*
* @return           void
* @pre              Ocu_Init
*
* @implements       Ocu_SetPinAction_Activity
*
*/
void Ocu_SetPinAction(Ocu_ChannelType ChannelNumber, Ocu_PinActionType PinAction);
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_GET_COUNTER_API)
/**
* @brief            Service to read the current value of the counter.
* @details          The function Ocu_GetCounter shall read and return the value of the counter of
*                   the channel indicated by ChannelNumber.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   ChannelNumber is invalid (not within the range specified by the configuration),
*                   the function Ocu_GetCounter shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and shall return the value 0.
*
*                   If development error detection is enabled for the OCU driver: if the driver is
*                   not initialized, then the function Ocu_GetCounterValue shall raise the error
*                   OCU_E_UNINIT and shall return the value 0.
*
* @param[in]        ChannelNumber  Ocu channel Id
*
* @return           Ocu_ValueType  the value of the hardware counter.
*
* @pre              Ocu_Init
*
* @implements       Ocu_GetCounter_Activity
*
*/
Ocu_ValueType Ocu_GetCounter(Ocu_ChannelType ChannelNumber);
#endif


/*===============================================================================================*/
#if (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API)
/**
* @brief            Service to set the value of the channel threshold using an absolute input data.
* @details          The function Ocu_SetAbsoluteThreshold shall set the channel threshold
*                   (the compare value) to the value given by AbsoluteValue.
*
*                   If development error detection is enabled for the OCU driver: If the driver is
*                   not initialized, the function Ocu_SetAbsoluteThreshold shall raise the error
*                   OCU_E_UNINIT and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   ChannelNumber is invalid (not within the range specified by the configuration),
*                   the function Ocu_SetAbsoluteThreshold shall raise the error
*                   OCU_E_PARAM_INVALID_CHANNEL and return without any action.
*
*                   After setting a new threshold value, the API Ocu_SetAbsoluteThreshold shall
*                   return a status to inform the caller whether the compare match will occur
*                   (or has already occurred) during the current Reference Interval, as a result
*                   of setting the new threshold value. (see OCU_SWS for details)
*
* @param[in]        ChannelNumber  - Ocu channel Id
* @param[in]        ReferenceValue - Value given by the upper layer and used as a base to determine
*                                    whether to call the notification before the function exits
*                                     or not.
* @param[in]        AbsoluteValue  - Value to compare with the content of the counter.
*                                    This value is in ticks.
*
* @return           Ocu_ReturnType - Tells the caller whether the compare match will occur
*                                    (or has already occurred) during the current Reference Interval,
*                                    as a result of setting the new threshold value.
* @pre              Ocu_Init
*
* @implements       Ocu_SetAbsoluteThreshold_Activity
*/
Ocu_ReturnType Ocu_SetAbsoluteThreshold(Ocu_ChannelType ChannelNumber, Ocu_ValueType ReferenceValue, Ocu_ValueType AbsoluteValue);
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API)
/**
* @brief            Service to set the value of the channel threshold relative to the current
*                   value of the counter.
* @details          The function Ocu_SetAbsoluteThreshold shall set the channel threshold
*                   (the compare value) to the value given by RelativeValue plus the current
*                   counter value read from hw.
*
*                   After setting a new threshold value, the API Ocu_SetRelativeThreshold shall
*                   return a status to inform the caller whether the compare match will occur
*                   (or has already occurred) during the current Reference Interval, as a result
*                   of setting the new threshold value.
*
*                   If development error detection is enabled for the OCU driver: If the driver
*                   is not initialized, the function Ocu_SetRelativeThreshold shall raise the
*                   error OCU_E_UNINIT and return without any action.
*
*                   After setting a new threshold value, the API Ocu_SetRelativeThreshold shall
*                   return a status to inform the caller whether the compare match will occur
*                   (or has already occurred) during the current Reference Interval, as a result
*                   of setting the new threshold value.
*
* @param[in]        ChannelNumber - Ocu channel Id
* @param[in]        RelativeValue - Value to use for computing the new threshold.
*
* @return          Ocu_ReturnType - Tells the caller whether the compare match will occur
*                                   (or has already occurred) during the current Reference
*                                   Interval, as a result of setting the new threshold value.
* @pre              Ocu_Init
*
* @implements       Ocu_SetRelativeThreshold_Activity
*/
Ocu_ReturnType Ocu_SetRelativeThreshold(Ocu_ChannelType ChannelNumber, Ocu_ValueType RelativeValue);
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/**
* @brief            This service is used to disable notifications from an OCU channel.
* @details          The function Ocu_DisableNotification shall disable the OCU compare match
*                   notification.
*
*                   If development error detection is enabled for the OCU driver: If the driver
*                   is not initialized, the function Ocu_DisableNotification shall raise the error
*                   OCU_E_UNINIT and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   Channel is invalid (not within the range specified by configuration), the
*                   function Ocu_DisableNotification shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the
*                   notification function is the NULL pointer, the function Ocu_DisableNotification
*                   shall raise the error OCU_E_NO_VALID_NOTIF and return without any action.
*
* @param[in]        ChannelNumber - Ocu channel Id
*
* @return           void
*
* @pre              Ocu_Init
*
* @implements       Ocu_DisableNotification_Activity
*
*/
void Ocu_DisableNotification(Ocu_ChannelType ChannelNumber);
#endif


/*===============================================================================================*/
#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
/**
* @brief            This service is used to enable notifications from an OCU channel.
* @details          The function Ocu_EnableNotification shall enable the OCU compare match
*                   notification of the indexed channel.
*
*                   If development error detection is enabled for the OCU driver: If the driver is
*                   not initialized, the function Ocu_EnableNotification shall raise the error
*                   OCU_E_UNINIT and return without any action.
*
*                   If development error detection is enabled for the OCU driver: If the parameter
*                   Channel is invalid (not within the range specified by configuration), then the
*                   function Ocu_EnableNotification shall raise the error OCU_E_PARAM_INVALID_CHANNEL
*                   and return without any action.
*
*                  If development error detection is enabled for the OCU driver: If the notification
*                  function is the NULL pointer, the function Ocu_EnableNotification shall raise the
*                  error OCU_E_NO_VALID_NOTIF and return without any action.
*
* @param[in]        ChannelNumber - Ocu channel Id
* @param[in]        Notification  - notification type to be enabled
*
* @return           void
*
* @pre              Ocu_Init
*
* @implements       Ocu_EnableNotification_Activity
*
*/
void Ocu_EnableNotification(Ocu_ChannelType ChannelNumber);
#endif

/*===============================================================================================*/
#if (STD_ON == OCU_VERSION_INFO_API)
/**
* @brief            This function returns Ocu driver version details
* @details          The function Ocu_GetVersionInfo shall return the version information of this module.
*                   The version information includes: Module Id, Vendor Id, Vendor specific version number.
*
* @param[in,out]    versioninfo - pointer to Std_VersionInfoType output variable
*
* @return           void
*
* @implements       Ocu_GetVersionInfo_Activity
*
*/
void Ocu_GetVersionInfo(Std_VersionInfoType * versioninfo);
#endif

/*===============================================================================================*/

#if (STD_ON == OCU_SET_CLOCK_MODE_API)
/**
* @brief    Implementation specific function to change the peripheral clock frequency.
* @details  This function is useful to set the prescalers that divide the OCU channels clock frequency.
*
* @param[in]    Prescaler - prescaler type
*               Possible values:
*                   - OCU_PRIMARY_PRESCALER for normal clock mode or
*                   - OCU_ALTERNATIVE_PRESCALER for a different prescaler for the driver
*
* @implements   Ocu_SetClockMode_Activity
*
*/
void Ocu_SetClockMode(Ocu_SelectPrescalerType Prescaler);
#endif

/*===============================================================================================*/

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OCU_H */
