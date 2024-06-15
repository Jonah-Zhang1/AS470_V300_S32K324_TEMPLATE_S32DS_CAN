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

#ifndef MSCM_IP_H
#define MSCM_IP_H

/**
*   @file Mscm_Ip.h
*
*   @addtogroup Mscm_Ip Mscm IPV Driver
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#include "Mscm_Ip_Types.h"
#include "Mscm_Ip_Cfg.h"
#include "Mcal.h"

#ifdef MSCM_IP_ENABLE_USER_MODE_SUPPORT
    #include "OsIf.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_MSCM_IP_VENDOR_ID                          43
#define RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION           4
#define RM_MSCM_IP_AR_RELEASE_MINOR_VERSION           7
#define RM_MSCM_IP_AR_RELEASE_REVISION_VERSION        0
#define RM_MSCM_IP_SW_MAJOR_VERSION                   3
#define RM_MSCM_IP_SW_MINOR_VERSION                   0
#define RM_MSCM_IP_SW_PATCH_VERSION                   0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Mscm_Ip_Types.h */
#if (RM_MSCM_IP_VENDOR_ID != RM_MSCM_IP_TYPES_VENDOR_ID)
    #error "Mscm_Ip.h and Mscm_Ip_Types.h have different vendor ids"
#endif

#if ((RM_MSCM_IP_SW_MAJOR_VERSION != RM_MSCM_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_SW_MINOR_VERSION != RM_MSCM_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_SW_PATCH_VERSION != RM_MSCM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mscm_Ip.h and Mscm_Ip_Types.h are different"
#endif

/* Check if current file and Mscm_Ip_Cfg header file are of the same vendor */
#if (RM_MSCM_IP_VENDOR_ID != RM_MSCM_IP_CFG_VENDOR_ID)
    #error "Mscm_Ip.h and Mscm_Ip_Cfg.h have different vendor ids"
#endif

/* Check if current file and Mscm_Ip_Cfg header file are of the same Software version */
#if ((RM_MSCM_IP_SW_MAJOR_VERSION != RM_MSCM_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_MSCM_IP_SW_MINOR_VERSION != RM_MSCM_IP_CFG_SW_MINOR_VERSION) || \
     (RM_MSCM_IP_SW_PATCH_VERSION != RM_MSCM_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mscm_Ip.h and Mscm_Ip_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef MSCM_IP_ENABLE_USER_MODE_SUPPORT
        /* Checks against OsIf.h */
        #if ((RM_MSCM_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
            (RM_MSCM_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
            #error "AUTOSAR Version Numbers of Mscm_Ip.h and OsIf.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#if defined(__cplusplus)
extern "C" {
#endif


#ifdef RM_IP_ENABLE_MSCM
#if (RM_IP_ENABLE_MSCM == STD_ON)

#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
/**
* @brief   Export Mscm configurations.
*/
MSCM_CONFIG_EXT

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
 * @brief         Initializes the configured Mscm.
 */
void Mscm_Ip_Init(const Mscm_Ip_ConfigType *pMscmConfig);
#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"
#endif
#endif

#if defined(__cplusplus)
}
#endif

#endif /* MSCM_IP_H */

/** @} */
