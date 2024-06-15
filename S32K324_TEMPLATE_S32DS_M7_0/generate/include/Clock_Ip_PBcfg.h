/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P07_D2306_ASR_REL_4_7_REV_0000_20230629
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

#ifndef CLOCK_IP_PBCFG_H
#define CLOCK_IP_PBCFG_H

/**
*   @file       Clock_Ip_PBcfg.h
*   @version    3.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup CLOCK_DRIVER_CONFIGURATION Clock Ip Driver
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
#include "Clock_Ip_Types.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_PBCFG_VENDOR_ID                      43
#define CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION       4
#define CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION       7
#define CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION    0
#define CLOCK_IP_PBCFG_SW_MAJOR_VERSION               3
#define CLOCK_IP_PBCFG_SW_MINOR_VERSION               0
#define CLOCK_IP_PBCFG_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Clock_Ip_Types.h file are of the same vendor */
#if (CLOCK_IP_PBCFG_VENDOR_ID != CLOCK_IP_TYPES_VENDOR_ID)
    #error "Clock_Ip_PBcfg.h and Clock_Ip_Types.h have different vendor ids"
#endif

/* Check if header file and Clock_Ip_Types.h file are of the same Autosar version */
#if ((CLOCK_IP_PBCFG_AR_RELEASE_MAJOR_VERSION != CLOCK_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_MINOR_VERSION != CLOCK_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_AR_RELEASE_REVISION_VERSION != CLOCK_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_PBcfg.h and Clock_Ip_Types.h are different"
#endif

/* Check if header file and Clock_Ip_Types.h file are of the same Software version */
#if ((CLOCK_IP_PBCFG_SW_MAJOR_VERSION != CLOCK_IP_TYPES_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_MINOR_VERSION != CLOCK_IP_TYPES_SW_MINOR_VERSION) || \
     (CLOCK_IP_PBCFG_SW_PATCH_VERSION != CLOCK_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_PBcfg.h and Clock_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief            Number of configured internal oscillators
*/
#define CLOCK_IP_CONFIGURED_IRCOSCS_0_NO       (3U)

/**
* @brief            Number of configured external oscillators
*/
#define CLOCK_IP_CONFIGURED_XOSCS_0_NO       (2U)

/**
* @brief            Number of configured pll devices
*/
#define CLOCK_IP_CONFIGURED_PLLS_0_NO       (1U)

/**
* @brief            Number of configured selectors
*/
#define CLOCK_IP_CONFIGURED_SELECTORS_0_NO       (12U)

/**
* @brief            Number of configured dividers
*/
#define CLOCK_IP_CONFIGURED_DIVIDERS_0_NO       (21U)

/**
* @brief            Number of configured divider triggers
*/
#define CLOCK_IP_CONFIGURED_DIVIDER_TRIGGERS_0_NO       (1U)

/**
* @brief            Number of configured fractional dividers
*/

/**
* @brief            Number of configured external signals
*/
#define CLOCK_IP_CONFIGURED_EXT_CLKS_0_NO       (2U)

/**
* @brief            Number of configured pcfs
*/

/**
* @brief            Number of configured gates
*/

/**
* @brief            Number of configured clock monitoring units
*/

/**
* @brief            Number of configured frequencies
*/
#define CLOCK_IP_CONFIGURED_FREQUENCIES_0_NO       (6U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"


extern const Clock_Ip_ClockConfigType Mcu_aClockConfigPB[];

#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* CLOCK_IP_PBCFG_H */

