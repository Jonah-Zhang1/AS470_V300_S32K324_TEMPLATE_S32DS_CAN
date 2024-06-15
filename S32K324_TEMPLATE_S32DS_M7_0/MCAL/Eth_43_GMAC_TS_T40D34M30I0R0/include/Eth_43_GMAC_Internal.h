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


#ifndef ETH_43_GMAC_INTERNAL_H
#define ETH_43_GMAC_INTERNAL_H

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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ETH_43_GMAC_INTERNAL_VENDOR_ID                    43
#define ETH_43_GMAC_INTERNAL_AR_RELEASE_MAJOR_VERSION     4
#define ETH_43_GMAC_INTERNAL_AR_RELEASE_MINOR_VERSION     7
#define ETH_43_GMAC_INTERNAL_AR_RELEASE_REVISION_VERSION  0
#define ETH_43_GMAC_INTERNAL_SW_MAJOR_VERSION             3
#define ETH_43_GMAC_INTERNAL_SW_MINOR_VERSION             0
#define ETH_43_GMAC_INTERNAL_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ETH_43_GMAC_START_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


void Eth_43_GMAC_ReportTransmission(
                                const uint8 CtrlIdx, \
                                const uint8 FifoIdx \
                           );

 
#define ETH_43_GMAC_STOP_SEC_CODE
#include "Eth_43_GMAC_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* ETH_43_GMAC_INTERNAL_H */
