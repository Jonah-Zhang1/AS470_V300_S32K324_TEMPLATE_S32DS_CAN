/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : LPI2C
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K3_RTD_3_0_0_P07_D2306_ASR_REL_4_7_REV_0000_20230629
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

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
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Flexio_I2c_Ip_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2C_IP_PBCFG_VENDOR_ID_C                     43
#define FLEXIO_I2C_IP_PBCFG_MODULE_ID_C                     255
#define FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define FLEXIO_I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define FLEXIO_I2C_IP_PBCFG_SW_MAJOR_VERSION_C              3
#define FLEXIO_I2C_IP_PBCFG_SW_MINOR_VERSION_C              0
#define FLEXIO_I2C_IP_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/



/* Check if current file and Flexio_I2c_Ip_PBcfg.h header file are of the same vendor */
#if (FLEXIO_I2C_IP_PBCFG_VENDOR_ID_C != FLEXIO_I2C_IP_PBCFG_VENDOR_ID )
    #error "Flexio_I2c_Ip_PBcfg.c and Flexio_I2c_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if current file and Flexio_I2c_Ip_PBcfg.h header file are of the same Autosar version */
#if ((FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION_C != FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION_C != FLEXIO_I2C_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION_C != FLEXIO_I2C_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Flexio_I2c_Ip_PBcfg.c and Flexio_I2c_Ip_PBcfg.h are different"
#endif

/* Check if current file and Flexio_I2c_Ip_PBcfg.h header file are of the same Software version */
#if ((FLEXIO_I2C_IP_PBCFG_SW_MAJOR_VERSION_C != FLEXIO_I2C_IP_PBCFG_SW_MAJOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_SW_MINOR_VERSION_C != FLEXIO_I2C_IP_PBCFG_SW_MINOR_VERSION) || \
     (FLEXIO_I2C_IP_PBCFG_SW_PATCH_VERSION_C != FLEXIO_I2C_IP_PBCFG_SW_PATCH_VERSION ) \
    )
    #error "Software Version Numbers of Flexio_I2c_Ip_PBcfg.c and Flexio_I2c_Ip_PBcfg.h are different"
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

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"



/* Channel configuration for channel FLEXIO_0_CH_0_1 - configured as master */
Flexio_I2c_Ip_MasterConfigType Flexio_I2cMasterChannel0 =
{

    /* Slave address */
    0U,
    /* Transfer Type */
    FLEXIO_I2C_USING_INTERRUPTS,
    /* Baud rate in hertz */
    (uint32)59523.80952380953,
    /* I2c flexio compare value */
    41,
    /* I2cFlexIOChannelPrescaler */

    FLEXIO_TMR_DECREMENT_ON_FLEXIO_CLK_DIV_16,

    /* I2c flexio sda pin */
    11U,
    /* I2c flexio scl pin */
    10U,
    /* Master Callback */
    NULL_PTR,
    /* I2c Master Callback Parameter */
    0U,
    /* FlexIO device instance number */
    0U,
    /* Index of first used internal resource instance (shifter and timer) */
    0U,
    
    /* DMA rx channel */
    0U,
    /* DMA tx channel */
    0U,
    
    /* Master state index */
    0U
};
    

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

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

