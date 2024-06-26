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

/**
*   @file
*
*   @addtogroup I2C_DRIVER_CONFIGURATION I2c Driver Configurations
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
#include "Lpi2c_Ip_PBcfg.h"
#include "I2c_Ipw_PBcfg.h"
#include "I2c_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IPW_PBCFG_VENDOR_ID_C                     43
#define I2C_IPW_PBCFG_MODULE_ID_C                     255
#define I2C_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define I2C_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define I2C_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define I2C_IPW_PBCFG_SW_MAJOR_VERSION_C              3
#define I2C_IPW_PBCFG_SW_MINOR_VERSION_C              0
#define I2C_IPW_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2c header file are of the same vendor */
#if (I2C_IPW_PBCFG_VENDOR_ID_C != I2C_IPW_TYPES_VENDOR_ID)
    #error "I2c_Ipw_PBcfg.c and I2c_Ipw_Types.h have different vendor ids"
#endif

/* Check if current file and I2c header file are of the same vendor */
#if (I2C_IPW_PBCFG_MODULE_ID_C   != I2C_IPW_TYPES_MODULE_ID)
    #error "I2c_Ipw_PBcfg.c and I2c_Ipw_Types.h have different module ids"
#endif
/* Check if current file and I2c header file are of the same Autosar version */
#if ((I2C_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C != I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C != I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of I2c_Ipw_PBcfg.c and I2c_Ipw_Types.h are different"
#endif
/* Check if current file and I2c header file are of the same Software version */
#if ((I2C_IPW_PBCFG_SW_MAJOR_VERSION_C  != I2C_IPW_TYPES_SW_MAJOR_VERSION) || \
     (I2C_IPW_PBCFG_SW_MINOR_VERSION_C  != I2C_IPW_TYPES_SW_MINOR_VERSION) || \
     (I2C_IPW_PBCFG_SW_PATCH_VERSION_C  != I2C_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of I2c_Ipw_PBcfg.c and I2c_Ipw_Types.h are different"
#endif

/* Check if current file and I2c header file are of the same vendor */
#if (I2C_IPW_PBCFG_VENDOR_ID_C != I2C_IPW_PBCFG_VENDOR_ID)
    #error "I2c_Ipw_PBcfg.c and I2c_Ipw_PBcfg.h have different vendor ids"
#endif
/* Check if current file and I2c header file are of the same Autosar version */
#if ((I2C_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C != I2C_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C != I2C_IPW_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (I2C_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != I2C_IPW_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of I2c_Ipw_PBcfg.c and I2c_Ipw_PBcfg.h are different"
#endif
/* Check if current file and I2c header file are of the same Software version */
#if ((I2C_IPW_PBCFG_SW_MAJOR_VERSION_C != I2C_IPW_PBCFG_SW_MAJOR_VERSION) || \
     (I2C_IPW_PBCFG_SW_MINOR_VERSION_C != I2C_IPW_PBCFG_SW_MINOR_VERSION) || \
     (I2C_IPW_PBCFG_SW_PATCH_VERSION_C != I2C_IPW_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of I2c_Ipw_PBcfg.c and I2c_Ipw_PBcfg.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"


/* Config structure for channel LPI2C_0 */
const Lpi2c_Ipw_HwChannelConfigType I2c_Ipw_ChannelConfig0 =
{
    &I2c_Lpi2cMasterChannel0,   
    NULL_PTR
};


#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

