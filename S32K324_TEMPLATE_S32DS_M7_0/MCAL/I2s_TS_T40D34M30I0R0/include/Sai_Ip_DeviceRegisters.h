/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : I2S
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

#ifndef SAI_IP_DEVICEREGISTERS_H
#define SAI_IP_DEVICEREGISTERS_H

/**
*   @file
*
*   @addtogroup sai_ip SAI IPL
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
#include "Sai_Ip_CfgDefines.h"
#include "Sai_Ip_FeatureDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAI_IP_DEVICEREGISTERS_VENDOR_ID                      43
#define SAI_IP_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION       4
#define SAI_IP_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION       7
#define SAI_IP_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION    0
#define SAI_IP_DEVICEREGISTERS_SW_MAJOR_VERSION               3
#define SAI_IP_DEVICEREGISTERS_SW_MINOR_VERSION               0
#define SAI_IP_DEVICEREGISTERS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sai_Ip_CfgDefines header file are of the same vendor */
#if (SAI_IP_DEVICEREGISTERS_VENDOR_ID != SAI_IP_CFGDEFINES_VENDOR_ID)
#error "Sai_Ip_DeviceRegisters.h and Sai_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip_CfgDefines header file are of the same Autosar version */
#if ((SAI_IP_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION     != SAI_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION     != SAI_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SAI_IP_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION  != SAI_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_DeviceRegisters.h and Sai_Ip_CfgDefines.h are different"
#endif

/* Check if current file and Sai_Ip_CfgDefines header file are of the same software version */
#if ((SAI_IP_DEVICEREGISTERS_SW_MAJOR_VERSION != SAI_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (SAI_IP_DEVICEREGISTERS_SW_MINOR_VERSION != SAI_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (SAI_IP_DEVICEREGISTERS_SW_PATCH_VERSION != SAI_IP_CFGDEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Sai_Ip_DeviceRegisters.h and Sai_Ip_CfgDefines.h are different"
#endif

/* Check if current file and Sai_Ip_FeatureDefines header file are of the same vendor */
#if (SAI_IP_DEVICEREGISTERS_VENDOR_ID != SAI_IP_FEATUREDEFINES_VENDOR_ID)
#error "Sai_Ip_DeviceRegisters.h and Sai_Ip_FeatureDefines.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip_FeatureDefines header file are of the same Autosar version */
#if ((SAI_IP_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION     != SAI_IP_FEATUREDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION     != SAI_IP_FEATUREDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (SAI_IP_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION  != SAI_IP_FEATUREDEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_DeviceRegisters.h and Sai_Ip_FeatureDefines.h are different"
#endif

/* Check if current file and Sai_Ip_FeatureDefines header file are of the same software version */
#if ((SAI_IP_DEVICEREGISTERS_SW_MAJOR_VERSION != SAI_IP_FEATUREDEFINES_SW_MAJOR_VERSION) || \
     (SAI_IP_DEVICEREGISTERS_SW_MINOR_VERSION != SAI_IP_FEATUREDEFINES_SW_MINOR_VERSION) || \
     (SAI_IP_DEVICEREGISTERS_SW_PATCH_VERSION != SAI_IP_FEATUREDEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Sai_Ip_DeviceRegisters.h and Sai_Ip_FeatureDefines.h are different"
#endif

#if (STD_ON == SAI_IP_ENABLE)
/* Declare Dev Assert */
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
#include "Devassert.h"

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Devassert.h header file are of the same Autosar version */
#if ((SAI_IP_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Sai_Ip_FeatureDefines.h and Devassert.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
#endif /* (SAI_IP_DEV_ERROR_DETECT == STD_ON) */
#endif /* (STD_ON == SAI_IP_ENABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SAI_IP_DEVICEREGISTERS_H */
