/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef EMIOS_MCL_IP_PBCFG_H
#define EMIOS_MCL_IP_PBCFG_H
/**
*   @file Emios_Mcl_Ip_PBcfg.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - MCL driver header file.
*   @details 
*
*   @addtogroup MCL_DRIVER MCL Driver
*   @{
*/
#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Emios_Mcl_Ip_Types.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_MCL_IP_PBCFG_VENDOR_ID                       43
#define EMIOS_MCL_IP_PBCFG_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_MCL_IP_PBCFG_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_MCL_IP_PBCFG_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_MCL_IP_PBCFG_SW_MAJOR_VERSION                3
#define EMIOS_MCL_IP_PBCFG_SW_MINOR_VERSION                0
#define EMIOS_MCL_IP_PBCFG_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_MCL_IP_PBCFG_VENDOR_ID != EMIOS_MCL_IP_TYPES_VENDOR_ID)
    #error "Emios_Mcl_Ip_PBcfg.h and Emios_Mcl_Ip_Types.h have different vendor ids"
#endif

/* Check if  header file and Emios_Mcl_Ip_Types.h file are of the same Autosar version */
#if ((EMIOS_MCL_IP_PBCFG_AR_RELEASE_MAJOR_VERSION != EMIOS_MCL_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_PBCFG_AR_RELEASE_MINOR_VERSION != EMIOS_MCL_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_MCL_IP_PBCFG_AR_RELEASE_REVISION_VERSION != EMIOS_MCL_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Mcl_Ip_PBcfg.h and Emios_Mcl_Ip_Types.h are different"
#endif

/* Check if header file and Emios_Mcl_Ip_Types.h file are of the same Software version */
#if ((EMIOS_MCL_IP_PBCFG_SW_MAJOR_VERSION != EMIOS_MCL_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_MCL_IP_PBCFG_SW_MINOR_VERSION != EMIOS_MCL_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_MCL_IP_PBCFG_SW_PATCH_VERSION != EMIOS_MCL_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Mcl_Ip_PBcfg.h and Emios_Mcl_Ip_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"


#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* EMIOS_MCL_IP_PBCFG_H */

