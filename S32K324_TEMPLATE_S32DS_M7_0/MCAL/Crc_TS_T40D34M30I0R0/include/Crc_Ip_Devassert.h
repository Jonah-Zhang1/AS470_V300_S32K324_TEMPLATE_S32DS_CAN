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
#ifndef CRC_IP_DEVASSERT_H
#define CRC_IP_DEVASSERT_H

/**
*   @file    Crc_Ip_Devassert.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Crc - Crc Ip driver header file.
*   @details
*
*   @addtogroup CRC_IP_DRIVER
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
#include "Mcal.h"
#include "Crc_Ip_Types.h"

#ifdef CRC_IP_DEV_ERROR_DETECT
#if (STD_ON == CRC_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == CRC_IP_DEV_ERROR_DETECT) */
#endif /* #ifdef CRC_IP_DEV_ERROR_DETECT */
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the standard types header file and also in the
*        module's description file
*/
#define CRC_IP_DEVASSERT_VENDOR_ID                     43
#define CRC_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION      4
#define CRC_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION      7
#define CRC_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION   0
#define CRC_IP_DEVASSERT_SW_MAJOR_VERSION              3
#define CRC_IP_DEVASSERT_SW_MINOR_VERSION              0
#define CRC_IP_DEVASSERT_SW_PATCH_VERSION              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Mcal header file are of the same Autosar version */
#if ((CRC_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
    (CRC_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION  != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Crc_Ip_DevAssert.h and Mcal header are different"
#endif
#endif

/* Check if source file and Crc header file are of the same vendor */
#if (CRC_IP_DEVASSERT_VENDOR_ID != CRC_IP_TYPES_VENDOR_ID)
    #error "Crc_Ip_DevAssert.h and Crc_Ip_Types have different vendor ids"
#endif

/* Check if source file and Crc header file are of the same Autosar version */
#if ((CRC_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION    != CRC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION    != CRC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION != CRC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_DevAssert.h and Crc_Ip_Types are different"
#endif

/* Check if source file and Crc header file are of the same Software version */
#if ((CRC_IP_DEVASSERT_SW_MAJOR_VERSION != CRC_IP_TYPES_SW_MAJOR_VERSION) || \
     (CRC_IP_DEVASSERT_SW_MINOR_VERSION != CRC_IP_TYPES_SW_MINOR_VERSION) || \
     (CRC_IP_DEVASSERT_SW_PATCH_VERSION != CRC_IP_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_DevAssert.h and Crc_Ip_Types are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#ifdef CRC_IP_DEV_ERROR_DETECT
#if (STD_ON == CRC_IP_DEV_ERROR_DETECT)
/* Check if Crc_Ip_DevAssert.h file and Devassert.h file are of the same Autosar version */
#if ((CRC_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION    != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION    != DEVASSERT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Crc_Ip_DevAssert.h and Devassert.h are different"
#endif
#endif /* (STD_ON == CRC_IP_DEV_ERROR_DETECT) */
#endif /* #ifdef CRC_IP_DEV_ERROR_DETECT */
#endif /* #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
                                           TYPEDEF
==================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

#if (STD_ON == CRC_IP_DEV_ERROR_DETECT)
    #define CRC_IP_DEV_ASSERT(x) DevAssert(x)
#else
    /* Assert macro does nothing */
    #define CRC_IP_DEV_ASSERT(x) ((void)0)
#endif /* #if (STD_ON == CRC_IP_DEV_ERROR_DETECT) */

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef CRC_IP_DEVASSERT_H */
