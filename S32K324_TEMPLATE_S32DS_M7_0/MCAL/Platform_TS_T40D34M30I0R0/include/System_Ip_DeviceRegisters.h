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
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SYSTEM_IP_DEVICE_REGISTERS_H_
#define SYSTEM_IP_DEVICE_REGISTERS_H_

/**
*   @file
*
*   @addtogroup System_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_TYPES_VENDOR_ID                    43
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION                   3
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_MINOR_VERSION                   0
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_SW_PATCH_VERSION                   0
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION           4
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION           7
#define CDD_PLATFORM_SYSTEM_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION        0


#if defined(S32G2XX)
    #include "S32G274A.h"
#elif defined(S32K3XX)
#ifdef S32K344
    #include "S32K344.h"
#endif
#ifdef S32K342
    #include "S32K342.h"
#endif
#ifdef S32K341
    #include "S32K341.h"
#endif
#ifdef S32K324
    #include "S32K324.h"
#endif 
#ifdef S32K314
    #include "S32K314.h"
#endif
#ifdef S32K312
    #include "S32K312.h"
#endif
#ifdef S32K322
    #include "S32K322.h"
#endif
#ifdef S32K396
    #include "S32K39.h"
#endif
#if defined(S32K328) || defined(S32K338) || defined(S32K348) || defined(S32K358)
    #include "S32K358.h"
#endif
#ifdef S32K388
    #include "S32K388.h"
#endif
#if defined(S32K311) || defined(S32K310)
    #include "S32K311.h"
#endif
#if defined(S32M276) || defined(S32M274)
    #include "S32M27x.h"
#endif

    #define MCM_ISCR_FIDCE_SHIFT          MCM_CM7_ISCR_FIDCE_SHIFT
    #define MCM_ISCR_FIXCE_SHIFT          MCM_CM7_ISCR_FIXCE_SHIFT
    #define MCM_ISCR_FUFCE_SHIFT          MCM_CM7_ISCR_FUFCE_SHIFT
    #define MCM_ISCR_FOFCE_SHIFT          MCM_CM7_ISCR_FOFCE_SHIFT
    #define MCM_ISCR_FDZCE_SHIFT          MCM_CM7_ISCR_FDZCE_SHIFT
    #define MCM_ISCR_FIOCE_SHIFT          MCM_CM7_ISCR_FIOCE_SHIFT
    #define MCM_ISCR_WABE_SHIFT           MCM_CM7_ISCR_WABE_SHIFT 
    #define MCM_CPCR_CM7_AHBSPRI_MASK     MCM_CM7_CPCR_CM7_AHBSPRI_MASK
    #define MCM_ISCR_WABS_MASK            MCM_CM7_ISCR_WABS_MASK
    
/*     #define MCM MCM_0_CM7 */
    
    #define FPU_INPUT_DENORMAL_IRQ_SUPPORTED
    #define FPU_INEXACT_IRQ_SUPPORTED
    #define FPU_UNDERFLOW_IRQ_SUPPORTED
    #define FPU_OVERFLOW_IRQ_SUPPORTED
    #define FPU_DIVIDE_BY_ZERO_IRQ_SUPPORTED
    #define FPU_INVALID_OPERATION_IRQ_SUPPORTED
    #define TCM_WRITE_ABORT_IRQ_SUPPORTED
    
    #define MCM_HAS_WABS_SUPPORTED
    
    #define MCM_HAS_PLATFORM_REVISION
#else
    #error "Unknown platform!"
#endif


#endif /* SYSTEM_IP_DEVICE_REGISTERS_H_ */

/** @} */
