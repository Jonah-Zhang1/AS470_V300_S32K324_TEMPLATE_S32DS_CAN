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

#ifndef EMIOS_OCU_IP_TRUSTEDFUNCTIONS_H
#define EMIOS_OCU_IP_TRUSTEDFUNCTIONS_H

/**
*   @file         Emios_Ocu_Ip_TrustedFunctions.h
*
*   @addtogroup   ocu_ip Ocu IPL
*   @brief        Ocu eMIOS driver header file.
*   @details      eMios driver interface.
*
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
#include "Emios_Ocu_Ip_CfgDefines.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_OCU_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define EMIOS_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_OCU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                3
#define EMIOS_OCU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define EMIOS_OCU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_OCU_IP_TRUSTEDFUNCTIONS_VENDOR_ID != EMIOS_OCU_IP_CFGDEFINES_VENDOR_ID)
    #error "Emios_Ocu_Ip_TrustedFunctions.h and Emios_Ocu_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if  header file and Emios_Ocu_Ip_CfgDefines.h file are of the same Autosar version */
#if ((EMIOS_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != EMIOS_OCU_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != EMIOS_OCU_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_OCU_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != EMIOS_OCU_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Ocu_Ip_TrustedFunctions.h and Emios_Ocu_Ip_CfgDefines.h are different"
#endif

/* Check if header file and Emios_Ocu_Ip_CfgDefines.h file are of the same Software version */
#if ((EMIOS_OCU_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != EMIOS_OCU_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != EMIOS_OCU_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (EMIOS_OCU_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != EMIOS_OCU_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Ocu_Ip_TrustedFunctions.h and Emios_Ocu_Ip_CfgDefines.h are different"
#endif

#if (STD_ON == OCU_EMIOS_USED)

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"


#if (defined(MCAL_EMIOS_REG_PROT_AVAILABLE) && (STD_ON == OCU_ENABLE_USER_MODE_SUPPORT))
/**
 * @brief        Enables eMIOS registers writing in User Mode by configuring REG_PROT
 * @details      Sets the UAA (User Access Allowed) bit of the eMIOS IP allowing eMIOS registers writing in User Mode
 *
 * @param[in]    none
 *
 * @return       none
 *
 * @pre          Should be executed in supervisor mode
 * @post         none
 *
 */
extern void Emios_Ocu_Ip_SetUserAccessAllowed(uint32 EmiosBaseAddr);
#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#endif /* OCU_EMIOS_USED */


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_OCU_IP_TRUSTEDFUNCTIONS_H */