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

/**
*   @file    Crc_Ip_TrustedFunctions.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Crc - Crc Ip driver source file.
*   @details
*
*   @addtogroup CRC_IP_DRIVER
*   @{
*/

/* Prevention from multiple including the same header */
#ifndef CRC_IP_TRUSTEDFUNCTIONS_H
#define CRC_IP_TRUSTEDFUNCTIONS_H

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

#include "Mcal.h"
#include "Crc_Ip_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_TRUSTEDFUNCTIONS_VENDOR_ID                      43
#define CRC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION       4
#define CRC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION       7
#define CRC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION    0
#define CRC_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION               3
#define CRC_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION               0
#define CRC_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Crc_Ip_TrustedFunctions.h file and Mcal.h header file are of the same Autosar version */
#if ((CRC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Crc_Ip_TrustedFunctions.h and Mcal.h are different"
#endif
#endif


/* Check if the files Crc_Ip_TrustedFunctions.h and Crc_Ip_CfgDefines.h are of the same version */
#if (CRC_IP_TRUSTEDFUNCTIONS_VENDOR_ID != CRC_IP_CFG_DEFINES_VENDOR_ID)
    #error "Crc_Ip_TrustedFunctions.h and Crc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if Crc_Ip_TrustedFunctions.h and Crc_Ip_CfgDefines.h are of the same Autosar version */
#if ((CRC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION != CRC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION != CRC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION != CRC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_TrustedFunctions.h and Crc_Ip_CfgDefines.h are different"
#endif

/* Check if Crc_Ip_TrustedFunctions.h and Crc_Ip_CfgDefines.h are of the same Software version */
#if ((CRC_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION != CRC_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CRC_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION != CRC_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CRC_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION != CRC_IP_CFG_DEFINES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_TrustedFunctions.h and Crc_Ip_CfgDefines.h are different"
#endif

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
*                               STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

#if (defined(CRC_ENABLE_USER_MODE_SUPPORT) && (CRC_ENABLE_USER_MODE_SUPPORT == STD_ON))

/**
 * @brief This function configure Set User Access Allowed
 */
extern void Crc_Ip_SetUserAccessAllowed(uint32 const pxCrcBaseAddr);

#endif

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_IP_TRUSTEDFUNCTIONS_H */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
