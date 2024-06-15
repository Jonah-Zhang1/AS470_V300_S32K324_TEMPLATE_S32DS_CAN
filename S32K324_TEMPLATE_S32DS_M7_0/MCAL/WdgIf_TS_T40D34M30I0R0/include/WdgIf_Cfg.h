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

#ifndef WDGIF_CFG_H
#define WDGIF_CFG_H

/**
*   @file WdgIf_Cfg.h
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

#include "modules.h"

#if ((USE_WDG_MODULE == STD_ON) || (USE_WDG_INSTANCE1 == STD_ON) || (USE_WDG_INSTANCE2 == STD_ON) || \
     (USE_WDG_INSTANCE3 == STD_ON) || (USE_WDG_INSTANCE4 == STD_ON) \
    )
#include "Wdg_Cfg.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDGIF_VENDOR_ID_CFG                   43
#define WDGIF_MODULE_ID_CFG                   43
#define WDGIF_AR_RELEASE_MAJOR_VERSION_CFG    4
#define WDGIF_AR_RELEASE_MINOR_VERSION_CFG    7
#define WDGIF_AR_RELEASE_REVISION_VERSION_CFG 0
#define WDGIF_SW_MAJOR_VERSION_CFG            3
#define WDGIF_SW_MINOR_VERSION_CFG            0
#define WDGIF_SW_PATCH_VERSION_CFG            0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if ((USE_WDG_MODULE == STD_ON) || (USE_WDG_INSTANCE1 == STD_ON) || (USE_WDG_INSTANCE2 == STD_ON) || \
     (USE_WDG_INSTANCE3 == STD_ON) || (USE_WDG_INSTANCE4 == STD_ON) \
    )
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance4 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_CFG != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_CFG != WDG_AR_RELEASE_MINOR_VERSION_CFG))
         #error "AutoSar Version Numbers of WdgIf_Cfg.h and Wdg_Cfg.h are different"
     #endif
#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
*   @brief  Compile switch to enable/disable development error detection for this module
*/
#define WDGIF_DEV_ERROR_DETECT   (STD_ON)

#if ((USE_WDG_MODULE == STD_ON) || (USE_WDG_INSTANCE1 == STD_ON) || (USE_WDG_INSTANCE2 == STD_ON) || \
     (USE_WDG_INSTANCE3 == STD_ON) || (USE_WDG_INSTANCE4 == STD_ON) \
    )
/**
*   @brief  Constant specifying the number of controlled watchdog drivers
*/
#define WDGIF_NUMBER_OF_DEVICES   WDG_NO_OF_INSTANCES
#endif

/**
*   @brief  Compile switch to enable/disable the version information
*/
#define WDGIF_VERSION_INFO_API   (STD_ON)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

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

#endif /*WDGIF_CFG_H*/
