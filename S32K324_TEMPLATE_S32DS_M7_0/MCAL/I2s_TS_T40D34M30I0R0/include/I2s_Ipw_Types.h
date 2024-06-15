/**
*   @file    I2s_Ipw_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR I2s - I2s middle level driver header file.
*   @details This file is the header containing all the necessary information for SAI
*            LLD.
*   @addtogroup SAI_DRIVER I2s Driver
*   @{
*/
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

#ifndef I2S_IPW_TYPES_H
#define I2S_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "I2s_Ipw_CfgDefines.h"
#if (I2S_IPW_USING_SAI == STD_ON)
#include "Sai_Ip_Types.h"
#endif /* (I2S_IPW_USING_SAI == STD_ON) */
#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
#include "Flexio_I2s_Ip_Types.h"
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2S_IPW_TYPES_VENDOR_ID                       43
#define I2S_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define I2S_IPW_TYPES_AR_RELEASE_MINOR_VERSION        7
#define I2S_IPW_TYPES_AR_RELEASE_REVISION_VERSION     0
#define I2S_IPW_TYPES_SW_MAJOR_VERSION                3
#define I2S_IPW_TYPES_SW_MINOR_VERSION                0
#define I2S_IPW_TYPES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2s_Ipw_CfgDefines header file are of the same vendor */
#if (I2S_IPW_TYPES_VENDOR_ID != I2S_IPW_CFGDEFINES_VENDOR_ID)
#error "I2s_Ipw_Types.h and I2s_Ipw_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and I2s_Ipw_CfgDefines header file are of the same Autosar version */
#if ((I2S_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     != I2S_IPW_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_TYPES_AR_RELEASE_MINOR_VERSION     != I2S_IPW_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != I2S_IPW_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw_Types.h and I2s_Ipw_CfgDefines.h are different"
#endif

/* Check if current file and I2s_Ipw_CfgDefines header file are of the same software version */
#if ((I2S_IPW_TYPES_SW_MAJOR_VERSION != I2S_IPW_CFGDEFINES_SW_MAJOR_VERSION) || \
     (I2S_IPW_TYPES_SW_MINOR_VERSION != I2S_IPW_CFGDEFINES_SW_MINOR_VERSION) || \
     (I2S_IPW_TYPES_SW_PATCH_VERSION != I2S_IPW_CFGDEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw_Types.h and I2s_Ipw_CfgDefines.h are different"
#endif

#if (I2S_IPW_USING_SAI == STD_ON)
/* Check if current file and I2s_Ipw_Types header file are of the same vendor */
#if (I2S_IPW_TYPES_VENDOR_ID != SAI_IP_TYPES_VENDOR_ID)
#error "I2s_Ipw_Types.h and Sai_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip_Types header file are of the same Autosar version */
#if ((I2S_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     != SAI_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_TYPES_AR_RELEASE_MINOR_VERSION     != SAI_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != SAI_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw_Types.h and Sai_Ip_Types.h are different"
#endif

/* Check if current file and Sai_Ip_Types header file are of the same software version */
#if ((I2S_IPW_TYPES_SW_MAJOR_VERSION != SAI_IP_TYPES_SW_MAJOR_VERSION) || \
     (I2S_IPW_TYPES_SW_MINOR_VERSION != SAI_IP_TYPES_SW_MINOR_VERSION) || \
     (I2S_IPW_TYPES_SW_PATCH_VERSION != SAI_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw_Types.h and Sai_Ip_Types.h are different"
#endif
#endif /* (I2S_IPW_USING_SAI == STD_ON) */

#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
/* Check if current file and I2s_Ipw_Types header file are of the same vendor */
#if (I2S_IPW_TYPES_VENDOR_ID != FLEXIO_I2S_IP_TYPES_VENDOR_ID)
#error "I2s_Ipw_Types.h and Flexio_I2s_Ip_Types.h have different vendor ids"
#endif

/* Check if current file and Flexio_I2s_Ip_Types header file are of the same Autosar version */
#if ((I2S_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     != FLEXIO_I2S_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_TYPES_AR_RELEASE_MINOR_VERSION     != FLEXIO_I2S_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != FLEXIO_I2S_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw_Types.h and Flexio_I2s_Ip_Types.h are different"
#endif

/* Check if current file and Flexio_I2s_Ip_Types header file are of the same software version */
#if ((I2S_IPW_TYPES_SW_MAJOR_VERSION != FLEXIO_I2S_IP_TYPES_SW_MAJOR_VERSION) || \
     (I2S_IPW_TYPES_SW_MINOR_VERSION != FLEXIO_I2S_IP_TYPES_SW_MINOR_VERSION) || \
     (I2S_IPW_TYPES_SW_PATCH_VERSION != FLEXIO_I2S_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw_Types.h and Flexio_I2s_Ip_Types.h are different"
#endif
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief Definition for different state and errors of Operation Status
 */
typedef enum
{
    I2S_STATUS_UNINITIALIZED = 0x00U,  /*!< Function unsupported */
    I2S_STATUS_COMPLETED     = 0x01U,  /*!< Function completed successfully */
    I2S_STATUS_ERROR         = 0x02U,  /*!< Function didn't complete successfully */
    I2S_STATUS_TIMEOUT       = 0x03U,  /*!< Function timed out */
    I2S_STATUS_BUSY          = 0x04U,  /*!< Function busy */
    I2S_STATUS_ABORTED       = 0x05U   /*!< Function aborted */
} I2s_StatusType;

/**
 * @brief Definition of the transmitter/recevier of a SAI hw unit
 */
typedef enum
{
    I2S_TRANSMITTER          = 0x0U,      /**< @brief Transmitter */
    I2S_RECEIVER             = 0x1U       /**< @brief Receiver */
} I2s_TransmitReceiveType;

/**
 * @brief Definition of the master/slave mode
 */
typedef enum
{
    I2S_MASTER            = 0x0U,      /**< @brief Master */
    I2S_SLAVE             = 0x1U       /**< @brief Slave */
} I2s_ModeType;

/**
 * @brief This enum contains all IPs which can integrate SAI functionalities
 */
typedef enum
{
#if (I2S_IPW_USING_SAI == STD_ON)
    I2S_OVER_SAI        = 0x0U,
#endif /* (I2S_IPW_USING_SAI == STD_ON) */
#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
    I2S_OVER_FLEXIO_I2S = 0x1U
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */
} I2s_SupportedIPsType;

/**
 * @brief This structure contains config structures for all IPs available.
 */
typedef struct
{
#if (I2S_IPW_USING_SAI == STD_ON)
    const Sai_Ip_ConfigType * SaiIpConfig;
#endif /* (I2S_IPW_USING_SAI == STD_ON) */
#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
    const Flexio_I2s_Ip_MasterConfigType * FlexioMasterIpConfig;
    const Flexio_I2s_Ip_SlaveConfigType * FlexioSlaveIpConfig;
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */
} I2s_Ipw_ConfigType;


/**
 * @brief   This structure holds the HWUnit configuration parameters.
 */
typedef struct
{
    uint32 CoreId;
    uint8 LogicChn;
    uint8 HwInstance;
    I2s_SupportedIPsType IpType;
    I2s_ModeType IpMode;
    I2s_TransmitReceiveType IpTransmitReceiveMode;
    I2s_Ipw_ConfigType IpConfig;
} I2s_HwConfigType;


/**
 * @brief   This structure holds the Logical configuration parameters.
 */
typedef struct
{
    I2s_SupportedIPsType IpType;
    uint8 HwInstance;
    I2s_ModeType Mode;
    I2s_TransmitReceiveType TransmitDirection;
} I2s_LogicalConfigState;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*I2S_IPW_TYPES_H*/

/** @} */
