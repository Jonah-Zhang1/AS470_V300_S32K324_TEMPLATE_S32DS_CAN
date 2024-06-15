/*===================================================================================================
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
*  Copyright 2020 - 2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
=====================================================================================================*/

#ifndef OCU_IPW_TYPES_H
#define OCU_IPW_TYPES_H

/**
*   @file           Ocu_Ipw_Types.h
*
*   @internal
*   @addtogroup     ocu_ipw Ocu IPW
*   @brief          Ocu IPW header file.
*   @details        Ipw defines, types used by OCU driver.
*
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Std_Types.h"
#include "Ocu_Ipw_CfgDefines.h"
#include "Emios_Ocu_Ip_Types.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_IPW_TYPES_VENDOR_ID                       43
#define OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION        7
#define OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION     0
#define OCU_IPW_TYPES_SW_MAJOR_VERSION                3
#define OCU_IPW_TYPES_SW_MINOR_VERSION                0
#define OCU_IPW_TYPES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (OCU_IPW_TYPES_VENDOR_ID != EMIOS_OCU_IP_TYPES_VENDOR_ID)
    #error "Ocu_Ipw_Types.h and Emios_Ocu_Ip_Types.h have different vendor ids"
#endif

/* Check if  header file and Emios_Ocu_Ip_Types.h file are of the same Autosar version */
#if ((OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw_Types.h and Emios_Ocu_Ip_Types.h are different"
#endif

/* Check if header file and Emios_Ocu_Ip_Types.h file are of the same Software version */
#if ((OCU_IPW_TYPES_SW_MAJOR_VERSION != EMIOS_OCU_IP_TYPES_SW_MAJOR_VERSION) || \
     (OCU_IPW_TYPES_SW_MINOR_VERSION != EMIOS_OCU_IP_TYPES_SW_MINOR_VERSION) || \
     (OCU_IPW_TYPES_SW_PATCH_VERSION != EMIOS_OCU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw_Types.h and Emios_Ocu_Ip_Types.h are different"
#endif

#if (OCU_IPW_TYPES_VENDOR_ID != OCU_IPW_CFGDEFINES_VENDOR_ID)
    #error "Ocu_Ipw_Types.h and Ocu_Ipw_CfgDefines.h have different vendor ids"
#endif

/* Check if  header file and Ocu_Ipw_CfgDefines.h file are of the same Autosar version */
#if ((OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != OCU_IPW_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != OCU_IPW_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != OCU_IPW_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Ipw_Types.h and Ocu_Ipw_CfgDefines.h are different"
#endif

/* Check if header file and Ocu_Ipw_CfgDefines.h file are of the same Software version */
#if ((OCU_IPW_TYPES_SW_MAJOR_VERSION != OCU_IPW_CFGDEFINES_SW_MAJOR_VERSION) || \
     (OCU_IPW_TYPES_SW_MINOR_VERSION != OCU_IPW_CFGDEFINES_SW_MINOR_VERSION) || \
     (OCU_IPW_TYPES_SW_PATCH_VERSION != OCU_IPW_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ocu_Ipw_Types.h and Ocu_Ipw_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if this header file and Std_Types.h file are of the same Autosar version */
    #if ((OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ocu_Ipw_Types.h and Std_Types.h are different"
    #endif

#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/** @brief Symbolic name for eMios channels */
#define OCU_EMIOS_CHANNEL       (2U)

#ifndef OCU_PIN_STATE_TYPE
#define OCU_PIN_STATE_TYPE              Emios_Ocu_Ip_PinStateType
#endif

#ifndef OCU_PIN_ACTION_TYPE
#define OCU_PIN_ACTION_TYPE             Emios_Ocu_Ip_PinActionType
#endif

#ifndef OCU_PIN_SELECT_PRESCALER_TYPE
#define OCU_PIN_SELECT_PRESCALER_TYPE   Emios_Ocu_Ip_SelectPrescalerType
#endif

#ifndef OCU_RETURN_TYPE
#define OCU_RETURN_TYPE                 Emios_Ocu_Ip_ReturnType
#endif

/** @brief The compare match will occur inside the current Reference Interval. */
#define OCU_IPW_CM_IN_REF_INTERVAL  0U
/** @brief The compare match will not occur inside the current Reference Interval. */
#define OCU_IPW_CM_OUT_REF_INTERVAL 1U

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*===============================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

typedef struct
{
    /** @brief IP used for the OCU channel */
    const uint8 mChannelIpType;
    /** @brief IP instance used for this OCU channel */
    const uint8 mInstanceNo;
    /** @brief Index in the IP specific configuration table */
    const uint8 mIdxChannelConfig;
} Ocu_Ipw_IpChannelConfigType;


/**
* @internal
* @brief   IP specific configuration structure
*/
typedef struct
{
    /* @brief Pointer to the array containing IPL channel configuration for eMios instances */
    const Emios_Ocu_Ip_ConfigType * const (*pEmiosIpConfig)[];
    /* @brief Pointer to Array containing IP type and index in the IP configuration table for each Ocu channel */
    const Ocu_Ipw_IpChannelConfigType (*pIpChannelsConfig)[];
} Ocu_Ipw_IpConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif    /* OCU_IPW_TYPES_H */
