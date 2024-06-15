/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Flexio FlexPwm
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

#ifndef FLEXPWM_IP_TRUSTEDFUNCTIONS_H
#define FLEXPWM_IP_TRUSTEDFUNCTIONS_H

/**
 *     @file       FlexPwm_Ip_TrustedFunctions.h 
 *     @brief      Header file of FlexPwm module.
 *     @details    This file contains some functions so that OS Application can call them  
 *     @addtogroup flexpwm_ip FlexPwm IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "FlexPwm_Ip_Cfg.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXPWM_IP_TRUSTEDFUNCTIONS_VENDOR_ID                    43
#define FLEXPWM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION     4
#define FLEXPWM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION     7
#define FLEXPWM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION  0
#define FLEXPWM_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION             3
#define FLEXPWM_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION             0
#define FLEXPWM_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and FlexPwm_Ip_Cfg.h header file are of the same vendor */
#if (FLEXPWM_IP_TRUSTEDFUNCTIONS_VENDOR_ID != FLEXPWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of FlexPwm_Ip_TrustedFunctions.h and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((FLEXPWM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != FLEXPWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXPWM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != FLEXPWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXPWM_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != FLEXPWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of FlexPwm_Ip_TrustedFunctions.h and FlexPwm_Ip_Cfg.h are different."
#endif

/* Check if header file and FlexPwm_Ip_Cfg.h header file are of the same software version */
#if ((FLEXPWM_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != FLEXPWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXPWM_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != FLEXPWM_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXPWM_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != FLEXPWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of FlexPwm_Ip_TrustedFunctions.h and FlexPwm_Ip_Cfg.h are different."
#endif

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == FLEXPWM_IP_USER_ACCESS_ALLOWED_AVAILABLE)
extern void FlexPwm_Ip_SetUserAccessAllowed(uint8 Instance);
extern void FlexPwm_Ip_ClrUserAccessAllowed(uint8 Instance);
    #endif
#endif

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* FLEXPWM_IP_TRUSTEDFUNCTIONS_H */

