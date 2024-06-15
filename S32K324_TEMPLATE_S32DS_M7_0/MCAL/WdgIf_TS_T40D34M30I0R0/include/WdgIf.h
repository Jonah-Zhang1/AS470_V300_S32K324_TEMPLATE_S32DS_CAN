/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : generic
*   Dependencies         : 
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

#ifndef WDGIF_H
#define WDGIF_H

/**
*   @file WdgIf.h
*
*   @addtogroup  WdgIf
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

#include "StandardTypes.h"
#include "WdgIf_Cfg.h"
#include "WdgIf_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDGIF_VENDOR_ID                    43
#define WDGIF_MODULE_ID                    43
#define WDGIF_AR_RELEASE_MAJOR_VERSION     4
#define WDGIF_AR_RELEASE_MINOR_VERSION     7
#define WDGIF_AR_RELEASE_REVISION_VERSION  0
#define WDGIF_SW_MAJOR_VERSION             3
#define WDGIF_SW_MINOR_VERSION             0
#define WDGIF_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WdgIf_Cfg header file are of the same vendor */
#if ((WDGIF_VENDOR_ID != WDGIF_VENDOR_ID_CFG) \
    )
    #error "WdgIf.h and WdgIf_Cfg.h have different vendor ids"
#endif
/* Check if current file and WDGIF configuration header file are of the same Autosar version */
#if ((WDGIF_AR_RELEASE_MAJOR_VERSION    != WDGIF_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDGIF_AR_RELEASE_MINOR_VERSION    != WDGIF_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDGIF_AR_RELEASE_REVISION_VERSION != WDGIF_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of WdgIf.h and WdgIf_Cfg.h are different"
#endif
/* Check if current file and WDGIF configuration header file are of the same software version */
#if ((WDGIF_SW_MAJOR_VERSION != WDGIF_SW_MAJOR_VERSION_CFG) || \
     (WDGIF_SW_MINOR_VERSION != WDGIF_SW_MINOR_VERSION_CFG) || \
     (WDGIF_SW_PATCH_VERSION != WDGIF_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of WdgIf.h and WdgIf_Cfg.h are different"
#endif
/* Check if current file and StandardTypes header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDGIF_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WDGIF_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of WdgIf.h and StandardTypes.h are different"
    #endif
#endif

/* Check if current file and WdgIf_Types header file are of the same vendor.*/
#if (WDGIF_VENDOR_ID != WDGIF_TYPES_VENDOR_ID)
    #error "WdgIf.h and WdgIf_Types.h have different vendor ids"
#endif
/* Check if current file and WDGIF configuration header file are of the same Autosar version */
#if ((WDGIF_AR_RELEASE_MAJOR_VERSION    != WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDGIF_AR_RELEASE_MINOR_VERSION    != WDGIF_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDGIF_AR_RELEASE_REVISION_VERSION != WDGIF_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of WdgIf.h and WdgIf_Types.h are different"
#endif
/* Check if current file and WDGIF configuration header file are of the same software version */
#if ((WDGIF_SW_MAJOR_VERSION != WDGIF_TYPES_SW_MAJOR_VERSION) || \
     (WDGIF_SW_MINOR_VERSION != WDGIF_TYPES_SW_MINOR_VERSION) || \
     (WDGIF_SW_PATCH_VERSION != WDGIF_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of WdgIf.h and WdgIf_Types.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

extern const WdgIf_SetModeFctPtrType WdgIf_SetModeFctPtr[];

#if (WDG_DIRECT_SERVICE == STD_OFF)
extern const WdgIf_SetTriggerFctPtrType WdgIf_SetTriggerConditionFctPtr[];
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
*   @brief  This define indicates the error detectable by the Watchdog Driver Interface
*/
#define WDGIF_E_PARAM_DEVICE    (uint8)0x01

/**
*    @brief  Service id for the setmode function
*/
#define WDGIF_SETMODE_ID   (uint8)0x01

/**
*   @brief  Service id for the trigger function
*/
#define WDGIF_TRIGGER_ID   (uint8)0x02

/**
*   @brief  Define the setmode function
*/
#define WdgIf_SetMode(DeviceIndex, WdgMode)    WdgIf_SetModeFctPtr[DeviceIndex](WdgMode)

/**
*   @brief  Define the setmode function
*/
#define WdgIf_SetTriggerCondition(DeviceIndex, Timeout) WdgIf_SetTriggerConditionFctPtr[DeviceIndex](Timeout)

#if (WDGIF_VERSION_INFO_API==STD_ON)

/**
*   @brief  Service id for the trigger function
*/
#define WDGIF_VERSION_ID   (uint8)0x03

/**
*   @brief  WdgIf_GetVersionInfo function
*/
#define WdgIf_GetVersionInfo(versioninfo) { (versioninfo)->vendorID = WDGIF_VENDOR_ID; \
                                            (versioninfo)->moduleID = WDGIF_MODULE_ID; \
                                            (versioninfo)->sw_major_version = WDGIF_SW_MAJOR_VERSION; \
                                            (versioninfo)->sw_minor_version = WDGIF_SW_MINOR_VERSION; \
                                            (versioninfo)->sw_patch_version = WDGIF_SW_PATCH_VERSION; \
                                          }
#endif /* WDGIF_VERSION_INFO_API==STD_ON */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDGIF_H */
