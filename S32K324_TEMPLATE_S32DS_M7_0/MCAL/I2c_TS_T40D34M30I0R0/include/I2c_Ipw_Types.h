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

#ifndef I2C_IPW_TYPES_H
#define I2C_IPW_TYPES_H

/**
*     @file
*
*     @addtogroup I2C_DRIVER I2c Driver
*     @{
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
#include "Lpi2c_Ip.h"
#include "CDD_I2c_Cfg.h"
#if (STD_ON == I2C_FLEXIO_USED)
#include "Flexio_I2c_Ip.h"
#endif

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_IPW_TYPES_VENDOR_ID                      43
#define I2C_IPW_TYPES_MODULE_ID                      255   
#define I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION       7
#define I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION    0
#define I2C_IPW_TYPES_SW_MAJOR_VERSION               3
#define I2C_IPW_TYPES_SW_MINOR_VERSION               0
#define I2C_IPW_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lpi2c_Ip header file are of the same vendor */
#if (I2C_IPW_TYPES_VENDOR_ID != LPI2C_IP_VENDOR_ID)
    #error "Lpi2c_Ip.h and I2c_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Lpi2c_Ip header file are of the same Autosar version */
#if ((I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != LPI2C_IP_AR_RELEASE_MAJOR_VERSION) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION != LPI2C_IP_AR_RELEASE_MINOR_VERSION) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION != LPI2C_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lpi2c_Ip.h and I2c_Ipw_Types.h are different"
#endif
/* Check if current file and Lpi2c_Ip header file are of the same Software version */
#if ((I2C_IPW_TYPES_SW_MAJOR_VERSION != LPI2C_IP_SW_MAJOR_VERSION) || \
     (I2C_IPW_TYPES_SW_MINOR_VERSION != LPI2C_IP_SW_MINOR_VERSION) || \
     (I2C_IPW_TYPES_SW_PATCH_VERSION != LPI2C_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lpi2c_Ip.h and I2c_Ipw_Types.h are different"
#endif

/* Check if current file and CDD_I2c_Cfg header file are of the same vendor */
#if (I2C_IPW_TYPES_VENDOR_ID != I2C_VENDOR_ID_CFG)
    #error "CDD_I2c_Cfg.h and I2c_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and CDD_I2c_Cfg header file are of the same Autosar version */
#if ((I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != I2C_AR_RELEASE_MAJOR_VERSION_CFG) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION != I2C_AR_RELEASE_MINOR_VERSION_CFG) ||    \
     (I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION != I2C_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of CDD_I2c_Cfg.h and I2c_Ipw_Types.h are different"
#endif
/* Check if current file and CDD_I2c_Cfg header file are of the same Software version */
#if ((I2C_IPW_TYPES_SW_MAJOR_VERSION != I2C_SW_MAJOR_VERSION_CFG) || \
     (I2C_IPW_TYPES_SW_MINOR_VERSION != I2C_SW_MINOR_VERSION_CFG) || \
     (I2C_IPW_TYPES_SW_PATCH_VERSION != I2C_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of CDD_I2c_Cfg.h and I2c_Ipw_Types.h are different"
#endif

#if (STD_ON == I2C_FLEXIO_USED)
    /* Check if current file and CDD_I2c_Cfg header file are of the same vendor */
    #if (I2C_IPW_TYPES_VENDOR_ID != FLEXIO_I2C_IP_VENDOR_ID)
        #error "CDD_I2c_Cfg.h and I2c_Ipw_Types.h have different vendor ids"
    #endif
    /* Check if current file and CDD_I2c_Cfg header file are of the same Autosar version */
    #if ((I2C_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != FLEXIO_I2C_IP_AR_RELEASE_MAJOR_VERSION) ||    \
        (I2C_IPW_TYPES_AR_RELEASE_MINOR_VERSION != FLEXIO_I2C_IP_AR_RELEASE_MINOR_VERSION) ||    \
        (I2C_IPW_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_I2C_IP_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of CDD_I2c_Cfg.h and I2c_Ipw_Types.h are different"
    #endif
    /* Check if current file and CDD_I2c_Cfg header file are of the same Software version */
    #if ((I2C_IPW_TYPES_SW_MAJOR_VERSION != FLEXIO_I2C_IP_SW_MAJOR_VERSION) || \
        (I2C_IPW_TYPES_SW_MINOR_VERSION != FLEXIO_I2C_IP_SW_MINOR_VERSION) || \
        (I2C_IPW_TYPES_SW_PATCH_VERSION != FLEXIO_I2C_IP_SW_PATCH_VERSION) \
        )
        #error "Software Version Numbers of CDD_I2c_Cfg.h and I2c_Ipw_Types.h are different"
    #endif
#endif /* I2C_FLEXIO_USED */

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
/**
* @brief   The structure contains the hardware configuration for lpi2c module.
*/
typedef struct
{
    const Lpi2c_Ip_MasterConfigType * Master;
    const Lpi2c_Ip_SlaveConfigType  * Slave;

}Lpi2c_Ipw_HwChannelConfigType;

/**
* @brief   The structure contains the hardware channel configuration type.
*/
typedef struct
{
    const Lpi2c_Ipw_HwChannelConfigType * I2c_Ipw_Lpi2cHwConfig;

#if (STD_ON == I2C_FLEXIO_USED)
    const Flexio_I2c_Ip_MasterConfigType * I2c_Ipw_FlexioHwConfig;
#endif

} I2c_Ipw_HwChannelConfigType;

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

#endif /*I2C_IPW_TYPES_H*/

