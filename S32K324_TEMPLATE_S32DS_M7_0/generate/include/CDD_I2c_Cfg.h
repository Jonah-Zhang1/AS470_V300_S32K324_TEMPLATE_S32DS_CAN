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
*   @addtogroup I2C_DRIVER_CONFIGURATION I2c Driver Configurations
*   @{
*/

#ifndef CDD_I2C_CFG_H
#define CDD_I2C_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Mcal.h"
#include "CDD_I2c_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2C_VENDOR_ID_CFG                    43
#define I2C_MODULE_ID_CFG                    255
#define I2C_AR_RELEASE_MAJOR_VERSION_CFG     4
#define I2C_AR_RELEASE_MINOR_VERSION_CFG     7
#define I2C_AR_RELEASE_REVISION_VERSION_CFG  0
#define I2C_SW_MAJOR_VERSION_CFG             3
#define I2C_SW_MINOR_VERSION_CFG             0
#define I2C_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and CDD_I2c_PBcfg header file are of the same vendor */
#if (I2C_VENDOR_ID_CFG != I2C_PBCFG_VENDOR_ID)
    #error "CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h have different vendor IDs"
#endif

/* Check if current file and CDD_I2c_PBcfg header file are of the same Autosar version */
#if ((I2C_AR_RELEASE_MAJOR_VERSION_CFG    != I2C_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2C_AR_RELEASE_MINOR_VERSION_CFG    != I2C_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (I2C_AR_RELEASE_REVISION_VERSION_CFG != I2C_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h are different"
#endif

/* Check if current file and CDD_I2c_PBcfg header file are of the same software version */
#if ((I2C_SW_MAJOR_VERSION_CFG != I2C_PBCFG_SW_MAJOR_VERSION) || \
     (I2C_SW_MINOR_VERSION_CFG != I2C_PBCFG_SW_MINOR_VERSION) || \
     (I2C_SW_PATCH_VERSION_CFG != I2C_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of CDD_I2c_Cfg.h and CDD_I2c_PBcfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if ((I2C_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (I2C_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "CDD_I2c_Cfg.h and Mcal.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
 /**
* @brief   macro contains all PB configuration macros.
*/
#define I2C_CONFIG_EXT \
 I2C_CONFIG_PB



/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Precompile Support On.
* @details        VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*                 configuration are allowed in this variant.
*/
#define I2C_PRECOMPILE_SUPPORT (STD_OFF)

/**
* @brief   Total number of I2c channel configured.
*/
#define I2C_HW_MAX_CONFIG           (1U)


/**
* @brief   Total number of available hardware I2C channels.
*/
#define I2C_HW_MAX_MODULES          (6U)

/**
* @brief   Total number of available hardware LPI2C channels.
*/
#define I2C_LPI2C_MAX_MODULES       (2U)

/**
* @brief            This is the ID of the first FLEXIO channel.
*/
#define I2C_FLEXIO_FIRST_CHANNEL_U8   (I2C_LPI2C_MAX_MODULES)

/**
* @brief   Switches the Development Error Detection and Notification ON or OFF.
*/
#define I2C_DEV_ERROR_DETECT      (STD_ON)  /* Enable Development Error Detection */

/**
* @brief          Support for version info API.
*/
#define I2C_VERSION_INFO_API      (STD_ON)  /* Enable API I2c_GetVersionInfo      */


/**
* @brief          Link I2c channels symbolic names with I2c channel IDs.
*/

#define I2C_LPI2C_0     0U
                


/**
* @brief          spurious coreid.
*/
#define I2C_SPURIOUS_CORE_ID        (0U)

/**
* @brief          Symbolic names for configured channels.
*/
#define I2cConf_I2cChannel_I2cChannel_1         0

/**
* @brief          FLEXIO Channel Used
*/
#define I2C_FLEXIO_USED   (STD_OFF)


/**
* @brief            Enable/Disable the API for reporting the Dem Error.
*/
#define I2C_DISABLE_DEM_REPORT_ERROR_STATUS    (STD_ON)

/**
* @brief            Enable/Disable Multi Core Support.
*/
#define I2C_MULTICORE_SUPPORT   (STD_OFF)

/**
* @brief            DMA is used for at least one channel (STD_ON/STD_OFF)
*/
#define I2C_DMA_USED   (STD_OFF)

#if (I2C_MULTICORE_SUPPORT == STD_ON)
    #define I2c_GetCoreID()            OsIf_GetCoreID()
#else
    #define I2c_GetCoreID()            ((uint32)0UL)
#endif /* (I2C_MULTICORE_SUPPORT == STD_ON) */

/**
* @brief            TIMEOUT for sync transmissions
*/
#define I2C_TIMEOUT               65535U



/**
* @brief            I2c slave rx buffer full
*/
#define  I2C_EVENT_RX_FULL_SLAVE  0x03U

/**
* @brief            I2c slave tx buffer empty
*/
#define  I2C_EVENT_TX_EMPTY_SLAVE  0x04U

/**
* @brief            I2c slave tx request 
*/
#define  I2C_EVENT_TX_REQ_SLAVE 0x05U

/**
* @brief            I2c slave rx request
*/
#define  I2C_EVENT_RX_REQ_SLAVE 0x06U

/**
* @brief            I2c slave stop transfer 
*/
#define  I2C_EVENT_STOP_SLAVE 0x07U

/**
* @brief            I2c master end transfer 
*/
#define I2C_EVENT_END_TRANSFER_MASTER  0x0BU

/**
* @brief            I2c master pin low timeout
*/
#define I2C_EVENT_PIN_LOW_TIMEOUT_MASTER  0x0CU

/**
* @brief            I2c master dma transfer error event
*/
#define I2C_EVENT_DMA_TRANSFER_ERROR_MASTER 0x0DU

/**
* @brief            I2c slave dma transfer error event
*/
#define I2C_EVENT_DMA_TRANSFER_ERROR_SLAVE 0x0EU


/**
* @brief            The callback configured by the user for i2c events.
*/

#define I2C_MODULE_CALLBACK(Event, Channel) (I2c_Callback(Event, Channel))

#define I2C_START_SEC_CODE
#include "I2c_MemMap.h"

/**
* @brief            The callback configured by the user for i2c events.
*/
extern void I2C_MODULE_CALLBACK(uint8 Event, uint8 Channel);

#define I2C_STOP_SEC_CODE
#include "I2c_MemMap.h"





    

/**
* @brief            Pre-Compile structure from CDD_I2c_Cfg.c file.
*/
#define I2C_CONF_PB \
 extern const I2c_ConfigType I2cGlobalConfig;



/**
* @brief        Variable storing number of maximum partitions using in configuration.
*/

#define I2C_MAX_CORE_ID     ((uint8)1U)

/**
* @brief    the value initialization un init for each core.
*/
#define I2C_UNINIT_CORE \
{ I2C_UNINIT}

/**
* @brief    the value initialization null pointer for each core.
*/
#define I2C_NULL_PTR \
{ NULL_PTR}

/**
* @brief        the value initialization Hardware Map.
*/
#define I2C_HW_MAP_INIT \
{ -1, -1, -1, -1, -1, -1}

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
 * @brief Definition of the type of activation or procession mechanism of an I2C hw unit
 * @implements I2c_DataDirectionType_enum
 */
typedef enum
{
    I2C_SEND_DATA       = 0x0U, /**< @brief Used to send data to a slave */
    I2C_RECEIVE_DATA    = 0x1U  /**< @brief Used to receive data from a slave */
} I2c_DataDirectionType;

/**
 * @brief Definition of the hardware channel type
 * 
 */
typedef enum
{
    I2C_LPI2C_CHANNEL       = 0x0U, /**< @brief This is used for LPI2C channels */
    I2C_FLEXIO_CHANNEL      = 0x1U  /**< @brief This is used for FlexIO channels */
} I2c_HwChannelType;

/*==================================================================================================
*                                   STRUCTURES AND OTHERS
==================================================================================================*/
/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting
*/
typedef struct
{
    Mcal_DemErrorType I2c_E_TimeoutFailureCfg;

} I2c_DemConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define I2C_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

extern const I2c_DemConfigType I2c_DemConfig;

#define I2C_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "I2c_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* CDD_I2C_CFG_H */

