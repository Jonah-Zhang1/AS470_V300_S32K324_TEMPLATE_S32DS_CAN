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

#ifndef CDD_I2S_TYPES_H
#define CDD_I2S_TYPES_H

/**
*   @file
*
*   @addtogroup I2S_DRIVER I2s Driver
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_I2s_CfgDefines.h"
#include "I2s_Ipw_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2S_TYPES_VENDOR_ID                         43
#define I2S_TYPES_MODULE_ID                         255
#define I2S_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define I2S_TYPES_AR_RELEASE_MINOR_VERSION          7
#define I2S_TYPES_AR_RELEASE_REVISION_VERSION       0
#define I2S_TYPES_SW_MAJOR_VERSION                  3
#define I2S_TYPES_SW_MINOR_VERSION                  0
#define I2S_TYPES_SW_PATCH_VERSION                  0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_I2s_CfgDefines header file are of the same vendor */
#if (I2S_TYPES_VENDOR_ID != I2S_CFGDEFINES_VENDOR_ID)
#error "CDD_I2s_Types.h and CDD_I2s_CfgDefines.h have different vendor ids"
#endif

/* Check if current file and CDD_I2s_CfgDefines header file are of the same Autosar version */
#if ((I2S_TYPES_AR_RELEASE_MAJOR_VERSION     != I2S_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_TYPES_AR_RELEASE_MINOR_VERSION     != I2S_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (I2S_TYPES_AR_RELEASE_REVISION_VERSION  != I2S_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_I2s_Types.h and CDD_I2s_CfgDefines.h are different"
#endif

/* Check if current file and CDD_I2s_CfgDefines header file are of the same software version */
#if ((I2S_TYPES_SW_MAJOR_VERSION != I2S_CFGDEFINES_SW_MAJOR_VERSION) || \
     (I2S_TYPES_SW_MINOR_VERSION != I2S_CFGDEFINES_SW_MINOR_VERSION) || \
     (I2S_TYPES_SW_PATCH_VERSION != I2S_CFGDEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_I2s_Types.h and CDD_I2s_CfgDefines.h are different"
#endif

/* Check if current file and I2s_Ipw_Types header file are of the same vendor */
#if (I2S_TYPES_VENDOR_ID != I2S_IPW_TYPES_VENDOR_ID)
#error "CDD_I2s_Types.h and I2s_Ipw_Types.h have different vendor ids"
#endif

/* Check if current file and I2s_Ipw_Types header file are of the same Autosar version */
#if ((I2S_TYPES_AR_RELEASE_MAJOR_VERSION     != I2S_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_TYPES_AR_RELEASE_MINOR_VERSION     != I2S_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2S_TYPES_AR_RELEASE_REVISION_VERSION  != I2S_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_I2s_Types.h and I2s_Ipw_Types.h are different"
#endif

/* Check if current file and I2s_Ipw_Types header file are of the same software version */
#if ((I2S_TYPES_SW_MAJOR_VERSION != I2S_IPW_TYPES_SW_MAJOR_VERSION) || \
     (I2S_TYPES_SW_MINOR_VERSION != I2S_IPW_TYPES_SW_MINOR_VERSION) || \
     (I2S_TYPES_SW_PATCH_VERSION != I2S_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_I2s_Types.h and I2s_Ipw_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
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
 * @brief          This gives the number of I2S configuration
 */
typedef uint8                          I2s_HwUnitCount;

/**
 * @brief          This gives the transfer data type
 */
typedef uint8                          I2s_DataType;

/**
 * @brief          I2s Word Mask for transmitted data
 */
typedef uint16                         I2s_WordMaskType;

/**
 * @brief          This gives the logical channel
 */
typedef uint8                          I2s_LogicalChannel;

/**
 * @brief Definition of the type of transfer status
 */
typedef struct
{
    I2s_StatusType status;
    uint32 byteRemainCount;
} I2s_StatusStructType;

/**
 * @brief Definition of the type of transfer direction
 */
typedef enum
{
    I2S_SEND_DATA       = 0x0U, /**< @brief Used to send data */
    I2S_RECEIVE_DATA    = 0x1U  /**< @brief Used to receive data */
} I2s_DataDirectionType;

/**
 * @brief This type contains initialization data.
 * @details This contains initialization data for the I2S driver. It shall contain:
 *         - The number of I2S modules to be configured
 *         - I2S dependent properties for used HW units
 */
typedef struct
{
    /**< @brief Number of I2S configurations */
    const I2s_HwUnitCount cfgCount;

    /**< @brief Pointer to I2s hardware unit configuration array */
    const I2s_HwConfigType * const * pHwConfig;
} I2s_ConfigType;

/**
 * @brief Definition for Request Buffer. This is the structure which is passed to I2s_SyncTransmit or I2s_AsyncTransmit
 * function. This holds the necessary information required for the communication of I2S Hw with the Slave
 * device
 */
typedef struct
{
    /**< @brief Buffer Size : The number of words for reading or writing of each channel. The size of each buffer word element is "I2s Buffer Element Size" selected in configurator. */
    uint32                   bufferSize;

    /**< @brief Direction of the data. Can be either Send or Receive. */
    I2s_DataDirectionType  dataDirection;

#if (I2S_IPW_USING_SAI == STD_ON)
#if (I2S_SAI_ENABLE_DATA_MASKING == STD_ON)
    /**< @brief
     * Configures whether the transmit word is masked for the corresponding word in the frame. (If hardware supports)
     * 0000000000000000b - Word N is enabled.
     * 0000000000000001b - Word N is masked.
     */
    I2s_WordMaskType wordMask;
#endif /* (I2S_SAI_ENABLE_DATA_MASKING == STD_ON) */

#if (I2S_SAI_AUTO_DISABLE_CLOCK == STD_ON)
    /**< @brief Auto disable clock when the request is completed (If hardware supports)
     * (Saving power if there is no request immediately after)
     * The clock generation will be started again at next transmission
     */
    boolean autoDisableClock;
#endif /* (I2S_SAI_AUTO_DISABLE_CLOCK == STD_ON) */
#endif /* (I2S_IPW_USING_SAI == STD_ON) */

    /**< @brief Buffer to Store or to transmit Serial data */
    I2s_DataType ** pDataBuffer;
} I2s_RequestType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*CDD_I2S_TYPES_H*/

/** @} */
