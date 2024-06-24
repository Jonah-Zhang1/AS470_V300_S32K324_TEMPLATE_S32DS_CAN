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

/* Prevention from multiple including the same header */
#ifndef LCU_IP_CFG_DEFINES_H_
#define LCU_IP_CFG_DEFINES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "StandardTypes.h"
#include "PlatformTypes.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LCU_IP_CFG_DEFINES_VENDOR_ID                       43
#define LCU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION        4
#define LCU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION        7
#define LCU_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION     0
#define LCU_IP_CFG_DEFINES_SW_MAJOR_VERSION                3
#define LCU_IP_CFG_DEFINES_SW_MINOR_VERSION                0
#define LCU_IP_CFG_DEFINES_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and StandardTypes header file are of the same Autosar version */
#if ((LCU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lcu_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif

/* Check if header file and PlatformTypes header file are of the same Autosar version */
#if ((LCU_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (LCU_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Lcu_Ip_Cfg_Defines.h and PlatformTypes.h are different"
#endif
#endif

/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/
/* LCU Available */
#define LCU_IP_IS_AVAILABLE                      STD_OFF

/* Not Support DEV ERRPR DETECT */
#define LCU_IP_DEV_ERROR_DETECT                  STD_OFF

/* SYNC Functions Available */
#define LCU_IP_SYNC_FUNC_IS_AVAILABLE            STD_OFF

/* ASYNC Functions Available */
#define LCU_IP_ASYNC_FUNC_IS_AVAILABLE           STD_OFF

#define LCU_IP_MULTICORE_IS_AVAILABLE            STD_OFF



#ifdef __cplusplus
}
#endif

#endif  /* #ifndef LCU_IP_CFG_DEFINES_H_ */

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
