/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : GMAC
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

#ifndef ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_H
#define ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_H

/**
*   @file
*
*   @addtogroup ETH_43_GMAC_DRIVER Ethernet Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Platform_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_VENDOR_ID                    43
#define ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION     4
#define ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION     7
#define ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION  0
#define ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION             3
#define ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_SW_MINOR_VERSION             0
#define ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Checks against Platform_Types.h */
#if ((ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION    != PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION    != PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AUTOSAR Version Numbers of Eth_43_GMAC_Ipw_TrustedFunctions.h and Platform_Types.h are different"
#endif

#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"

extern void Eth_43_GMAC_Ipw_SelectPhyInterface(Gmac_Ip_MiiModeType ModeSelect);

#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ETH_43_GMAC_IPW_TRUSTEDFUNCTIONS_H */
