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

#ifndef WDGIF_TYPES_H
#define WDGIF_TYPES_H

/**
*   @file WdgIf_Types.h
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

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDGIF_TYPES_VENDOR_ID                    43
#define WDGIF_TYPES_MODULE_ID                    43
#define WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define WDGIF_TYPES_AR_RELEASE_MINOR_VERSION     7
#define WDGIF_TYPES_AR_RELEASE_REVISION_VERSION  0
#define WDGIF_TYPES_SW_MAJOR_VERSION             3
#define WDGIF_TYPES_SW_MINOR_VERSION             0
#define WDGIF_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and WDGIF_TYPES configuration header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WDGIF_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of WdgIf.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
*   @brief  This enumerated type will contain the watchdog driver's possible states
*/
typedef enum
{
    WDGIF_UNINIT         = 0x01U,  /**< @brief = 0x01 The watchdog driver is not uninitialized.  This shall be the default value after reset */
    WDGIF_IDLE           = 0x02U,  /**< @brief = 0x02 The watchdog driver is currently idle, i.e not beeing triggered or mode changed */
    WDGIF_BUSY           = 0x03U   /**< @brief = 0x03 The watchdog driver is currently busy, i.e triggered or switchd between modes */
}WdgIf_StatusType;

/**
*   @brief  This enumerated type will contain the watchdog driver's possible modes
*/
typedef enum {
    WDGIF_OFF_MODE      = 0x00U,  /**< @brief  = 0x00 In this mode, the watchdog driver is disabled (switched off). */
    WDGIF_SLOW_MODE     = 0x01U,  /**< @brief  = 0x01 In this mode, the watchdog driver is set up for a long timeout period (slow triggering).*/
    WDGIF_FAST_MODE     = 0x02U   /**< @brief  = 0x02 In this mode, the watchdog driver is set up for a short timeout period (fast triggering).*/
} WdgIf_ModeType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef Std_ReturnType (*WdgIf_SetModeFctPtrType)(WdgIf_ModeType);
typedef void (*WdgIf_SetTriggerFctPtrType)(uint16);
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /*WDGIF_TYPES_H*/
