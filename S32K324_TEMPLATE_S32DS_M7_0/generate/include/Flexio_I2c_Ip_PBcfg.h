/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : LPI2C
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
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXIO_I2C_IP_PBCFG_H
#define FLEXIO_I2C_IP_PBCFG_H

/**
*   @file
*
*   @addtogroup FLEXIO_I2C_DRIVER_CONFIGURATION Flexio_I2c Driver Configurations
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Flexio_I2c_Ip_Types.h"
#include "Flexio_I2c_Ip_Callbacks.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2C_IP_PBCFG_VENDOR_ID                     43
#define FLEXIO_I2C_IP_PBCFG_MODULE_ID                     255
#define FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION      4
#define FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION      7
#define FLEXIO_I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION   0
#define FLEXIO_I2C_IP_PBCFG_SW_MAJOR_VERSION              3
#define FLEXIO_I2C_IP_PBCFG_SW_MINOR_VERSION              0
#define FLEXIO_I2C_IP_PBCFG_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Flexio_I2c_Ip_Types.h header file are of the same vendor */
#if (FLEXIO_I2C_IP_PBCFG_VENDOR_ID != FLEXIO_I2C_IP_TYPES_VENDOR_ID)
    #error "Flexio_I2c_Ip_PBcfg.h and Flexio_I2c_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and Flexio_I2c_Ip_Types.h header file are of the same Autosar version */
#if ((FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION != FLEXIO_I2C_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION != FLEXIO_I2C_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_I2c_Ip_PBcfg.h and Flexio_I2c_Ip.h are different"
#endif
/* Check if current file and Flexio_I2c_Ip_Types.h header file are of the same Software version */
#if ((FLEXIO_I2C_IP_PBCFG_SW_MAJOR_VERSION != FLEXIO_I2C_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_SW_MINOR_VERSION != FLEXIO_I2C_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_SW_PATCH_VERSION != FLEXIO_I2C_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_I2c_Ip_PBcfg.h and Flexio_I2c_Ip_Types.h are different"
#endif


/* Check if current file and Flexio_I2c_Ip_Callbacks.h header file are of the same vendor */
#if (FLEXIO_I2C_IP_PBCFG_VENDOR_ID != FLEXIO_I2C_IP_CALLBACKS_VENDOR_ID)
    #error "Flexio_I2c_Ip_PBcfg.h and Flexio_I2c_Ip_Callbacks.h have different vendor ids"
#endif
/* Check if current file and Flexio_I2c_Ip_Callbacks.h header file are of the same Autosar version */
#if ((FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION != FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION != FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_CALLBACKS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_I2c_Ip_PBcfg.h and Flexio_I2c_Ip_Callbacks.h are different"
#endif
/* Check if current file and Flexio_I2c_Ip_Callbacks.h header file are of the same Software version */
#if ((FLEXIO_I2C_IP_PBCFG_SW_MAJOR_VERSION != FLEXIO_I2C_IP_CALLBACKS_SW_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_SW_MINOR_VERSION != FLEXIO_I2C_IP_CALLBACKS_SW_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_SW_PATCH_VERSION != FLEXIO_I2C_IP_CALLBACKS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Flexio_I2c_Ip_PBcfg.h and Flexio_I2c_Ip_Callbacks.h are different"
#endif

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define FLEXIO_I2C_IP_NUM_MASTER_USED 0U
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_I2C_IP_PBCFG_H */

