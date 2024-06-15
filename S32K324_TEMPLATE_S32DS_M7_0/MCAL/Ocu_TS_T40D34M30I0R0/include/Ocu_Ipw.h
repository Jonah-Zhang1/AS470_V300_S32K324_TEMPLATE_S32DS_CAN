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
=====================================================================================================*/

#ifndef OCU_IPW_H
#define OCU_IPW_H

/**
*   @file           Ocu_Ipw.h
*
*   @internal
*   @addtogroup     ocu_ipw Ocu IPW
*   @brief          Ocu IPW API.
*   @details        Ocu IPW header file, containing variables, functions prototypes, data types and/or
*                   defines and macros that are Autosar specific and are not exported by the OCU driver.
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*===============================================================================================
*         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/

#include "Ocu_Ipw_Types.h"
#include "Ocu_Ipw_Cfg.h"
#include "Emios_Ocu_Ip.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_IPW_VENDOR_ID                       43
#define OCU_IPW_AR_RELEASE_MAJOR_VERSION        4
#define OCU_IPW_AR_RELEASE_MINOR_VERSION        7
#define OCU_IPW_AR_RELEASE_REVISION_VERSION     0
#define OCU_IPW_SW_MAJOR_VERSION                3
#define OCU_IPW_SW_MINOR_VERSION                0
#define OCU_IPW_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (OCU_IPW_VENDOR_ID != OCU_IPW_CFG_VENDOR_ID)
    #error "Ocu_Ipw.h and Ocu_Ipw_Cfg.h have different vendor ids"
#endif

/* Check if  header file and Ocu_Ipw_Cfg.h file are of the same Autosar version */
#if ((OCU_IPW_AR_RELEASE_MAJOR_VERSION != OCU_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_MINOR_VERSION != OCU_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_REVISION_VERSION != OCU_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw.h and Ocu_Ipw_Cfg.h are different"
#endif

/* Check if header file and Ocu_Ipw_Cfg.h file are of the same Software version */
#if ((OCU_IPW_SW_MAJOR_VERSION != OCU_IPW_CFG_SW_MAJOR_VERSION) || \
     (OCU_IPW_SW_MINOR_VERSION != OCU_IPW_CFG_SW_MINOR_VERSION) || \
     (OCU_IPW_SW_PATCH_VERSION != OCU_IPW_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw.h and Ocu_Ipw_Cfg.h are different"
#endif

#if (OCU_IPW_VENDOR_ID != EMIOS_OCU_IP_VENDOR_ID)
    #error "Ocu_Ipw.h and Emios_Ocu_Ip.h have different vendor ids"
#endif

/* Check if  header file and Emios_Ocu_Ip.h file are of the same Autosar version */
#if ((OCU_IPW_AR_RELEASE_MAJOR_VERSION != EMIOS_OCU_IP_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_MINOR_VERSION != EMIOS_OCU_IP_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_REVISION_VERSION != EMIOS_OCU_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw.h and Emios_Ocu_Ip.h are different"
#endif

/* Check if header file and Emios_Ocu_Ip.h file are of the same Software version */
#if ((OCU_IPW_SW_MAJOR_VERSION != EMIOS_OCU_IP_SW_MAJOR_VERSION) || \
     (OCU_IPW_SW_MINOR_VERSION != EMIOS_OCU_IP_SW_MINOR_VERSION) || \
     (OCU_IPW_SW_PATCH_VERSION != EMIOS_OCU_IP_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw.h and Emios_Ocu_Ip.h are different"
#endif

#if (OCU_IPW_VENDOR_ID != OCU_IPW_TYPES_VENDOR_ID)
    #error "Ocu_Ipw.h and Ocu_Ipw_Types.h have different vendor ids"
#endif

/* Check if  header file and Ocu_Ipw_Types.h file are of the same Autosar version */
#if ((OCU_IPW_AR_RELEASE_MAJOR_VERSION != OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_MINOR_VERSION != OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_AR_RELEASE_REVISION_VERSION != OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw.h and Ocu_Ipw_Types.h are different"
#endif

/* Check if header file and Ocu_Ipw_Types.h file are of the same Software version */
#if ((OCU_IPW_SW_MAJOR_VERSION != OCU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (OCU_IPW_SW_MINOR_VERSION != OCU_IPW_TYPES_SW_MINOR_VERSION) || \
     (OCU_IPW_SW_PATCH_VERSION != OCU_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw.h and Ocu_Ipw_Types.h are different"
#endif

/*===============================================================================================
*                                         CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                    DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                          ENUMS
===============================================================================================*/

/*===============================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/


/*===============================================================================================
*                               GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/


/*===============================================================================================
*                                   FUNCTION PROTOTYPES
===============================================================================================*/
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

/**
 * @brief       Ocu_Ipw_Init
 * @details     This function call the supported IP initialization functions.
 *
 * @param[in]   pIpConfig - Pointer to OCU top configuration structure
 *
 * @return      void
 *
 */
void Ocu_Ipw_Init(const Ocu_Ipw_IpConfigType * const pIpConfig);

/*===============================================================================================*/

#if (STD_ON == OCU_DEINIT_API)
/**
 * @brief       Ocu_Ipw_DeInit
 * @details     This function call the supported IP de-initialization functions.
 *
 * @param[in]   pIpConfig - Pointer to OCU top configuration structure
 *
 * @return      void
 */
void Ocu_Ipw_DeInit(const Ocu_Ipw_IpConfigType * const pIpConfig);
#endif /* OCU_DEINIT_API */

/*===============================================================================================*/
/**
 * @brief       Ocu_Ipw_StartChannel
 * @details     Call StartChannel() function for the eMIOS Ocu channel
 *
 * @param[in]   NumChannel - Ocu channel Id in top configuration structure
 *
 * @return      void
 */
void Ocu_Ipw_StartChannel(uint16 NumChannel);

/*===============================================================================================*/
/**
 * @brief       Ocu_Ipw_StopChannel
 * @details     Call StopChannel() function for the eMIOS Ocu channel
 *
 * @param[in]   NumChannel - Ocu channel Id in top configuration structure
 *
 * @return      void
 */
void Ocu_Ipw_StopChannel(uint16 NumChannel);

/*===============================================================================================*/

#if (STD_ON == OCU_SET_PIN_STATE_API)
/**
 * @brief       Ocu_Ipw_SetPinState
 * @details     Call SetPinState() function for the eMIOS Ocu channel
 *
 * @param[in]   NumChannel - Ocu channel Id in top configuration structure
 * @param[in]   PinState - Expected Pin State for the given channel
 *
 * @return      void
 */
void Ocu_Ipw_SetPinState(uint16 NumChannel, OCU_PIN_STATE_TYPE PinState);
#endif

/*===============================================================================================*/

#if (STD_ON == OCU_SET_PIN_ACTION_API)
/**
* @brief    Ocu_Ipw_SetPinAction
* @details  Call SetPinAction() function for the eMIOS Ocu channel
*
* @param[in]    NumChannel - Ocu channel Id in top configuration structure
* @param[in]    PinAction - Expected Pin Action for the given channel
*
*/
void Ocu_Ipw_SetPinAction(uint16 NumChannel, OCU_PIN_ACTION_TYPE PinAction);
#endif

/*===============================================================================================*/

#if (STD_ON == OCU_GET_COUNTER_API)
/**
* @brief        Ocu_Ipw_GetCounter
* @details      Call GetCounter() function for the eMIOS Ocu channel
*
* @param[in]    NumChannel - Ocu channel Id in top configuration structure
*
* @return       Ocu_Ipw_ValueType
*/
Ocu_Ipw_ValueType Ocu_Ipw_GetCounter(uint16 NumChannel);
#endif /* OCU_GET_COUNTER_API */

/*===============================================================================================*/

#if (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API)
/**
 * @brief       Ocu_Ipw_SetAbsoluteThreshold
 * @details     This function will change the compare match interval for the given timer channel
 *
 * @param[in]   NumChannel - Ocu channel Id in top configuration structure
 *              ReferenceValue - Reference value for the counting interval
 *              AbsoluteValue - Absolute value for the counting interval
 *
 * @return  OCU_RETURN_TYPE - Tells the caller whether the compare match will occur (or has already occurred)
 *                            during the current Reference Interval, as a result of setting the new threshold value.
 */
OCU_RETURN_TYPE Ocu_Ipw_SetAbsoluteThreshold(uint16 NumChannel, Ocu_Ipw_ValueType ReferenceValue, Ocu_Ipw_ValueType AbsoluteValue);
#endif /* OCU_SET_ABSOLUTE_THRESHOLD_API */

/*===============================================================================================*/

#if (STD_ON == OCU_SET_RELATIVE_THRESHOLD_API)
/**
 * @brief       Ocu_Ipw_SetRelativeThreshold
 * @details     This function will change the compare match interval for the given timer channel
 *
 * @param[in]   NumChannel - Ocu channel Id in top configuration structure
 * @param[in]   RelativeValue - Reference value for the counting interval
 *
 * @return  OCU_RETURN_TYPE - Tells the caller whether the compare match will occur (or has already occurred)
 *                            during the current Reference Interval, as a result of setting the new threshold value.
 */
OCU_RETURN_TYPE Ocu_Ipw_SetRelativeThreshold(uint16 NumChannel, Ocu_Ipw_ValueType RelativeValue);
#endif /* OCU_SET_RELATIVE_THRESHOLD_API */

/*===============================================================================================*/

#if (STD_ON == OCU_SET_CLOCK_MODE_API)
/**
 * @brief       Ocu_Ipw_SetClockMode
 * @details     Call SetClockMode() function of all configured Hw IPs
 *
 * @param[in]   Prescaler   OCU_PRIMARY_PRESCALER for normal clock mode or
 *                          OCU_ALTERNATIVE_PRESCALER for a different prescaler for the driver
 */
void Ocu_Ipw_SetClockMode(OCU_PIN_SELECT_PRESCALER_TYPE Prescaler);
#endif

/*===============================================================================================*/
#if ((STD_ON == OCU_SET_RELATIVE_THRESHOLD_API) || (STD_ON == OCU_SET_ABSOLUTE_THRESHOLD_API))
/**
 * @brief       Ocu_Ipw_GetMaxCounterValue
 * @details     This function will return max counter value for given channel
 *
 * @param[in]   NumChannel - Logic channel
 *
 * @return      uint32 - Max counter value for given channel
 */
uint32 Ocu_Ipw_GetMaxCounterValue(uint16 NumChannel);
#endif

#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)

/**
 * @brief   This function is used to disable the OCU compare match notification.
 *
 * @param[in]   NumChannel - Ocu channel Id in top configuration structure
 *
 * @return none
 *
 *
 */
void Ocu_Ipw_DisableNotification(uint16 NumChannel);

/**
 * @brief   This function is used to enable the OCU compare match notification.
 *
 * @param[in]   NumChannel - Ocu channel Id in top configuration structure
 *
 * @return none
 *
 *
 */
void Ocu_Ipw_EnableNotification(uint16 NumChannel);

#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* OCU_IPW_H */
