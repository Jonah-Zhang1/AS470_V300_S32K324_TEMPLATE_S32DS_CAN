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
/* Prevention from multiple including the same header */
#ifndef CRC_H
#define CRC_H

/**
*   @file    Crc.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Crc - Crc driver source file.
*   @details
*
*   @defgroup CRC_HLD_DRIVER CRC HLD Driver
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
#include "CDD_Crc.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRC_VENDOR_ID                       43
#define CRC_AR_RELEASE_MAJOR_VERSION        4
#define CRC_AR_RELEASE_MINOR_VERSION        7
#define CRC_AR_RELEASE_REVISION_VERSION     0
#define CRC_SW_MAJOR_VERSION                3
#define CRC_SW_MINOR_VERSION                0
#define CRC_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and CDD_Crc.h file are of the same vendor */
#if (CRC_VENDOR_ID != CDD_CRC_VENDOR_ID)
    #error "Crc.h and CDD_Crc.h have different vendor ids"
#endif

/* Check if header file and CDD_Crc.h file are of the same Autosar version */
#if ((CRC_AR_RELEASE_MAJOR_VERSION != CDD_CRC_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_AR_RELEASE_MINOR_VERSION != CDD_CRC_AR_RELEASE_MINOR_VERSION) || \
     (CRC_AR_RELEASE_REVISION_VERSION != CDD_CRC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc.h and CDD_Crc.h are different"
#endif

/* Check if header file and CDD_Crc.h file are of the same Software version */
#if ((CRC_SW_MAJOR_VERSION != CDD_CRC_SW_MAJOR_VERSION) || \
     (CRC_SW_MINOR_VERSION != CDD_CRC_SW_MINOR_VERSION) || \
     (CRC_SW_PATCH_VERSION != CDD_CRC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Crc.h and CDD_Crc.h are different"
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

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_H */
