/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXIO_SENT_IP
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
*   Copyright 2020 - 2023 NXP Semiconductors NXP.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef SENT_TYPES_H
#define SENT_TYPES_H

/**
*   @file       Sent_Types.h
*
*   @version    3.0.0
*
*   @brief      AUTOSAR Sent - Sent generic types file.
*   @details    Contains generic Sent types and structures.
*
*   @addtogroup SENT_DRIVER
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
#include "StandardTypes.h"
#include "Sent_Ipw_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Sent_Types.h
*/
#define SENT_TYPES_VENDOR_ID                      43
#define SENT_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define SENT_TYPES_AR_RELEASE_MINOR_VERSION       7
#define SENT_TYPES_AR_RELEASE_REVISION_VERSION    0
#define SENT_TYPES_SW_MAJOR_VERSION               3
#define SENT_TYPES_SW_MINOR_VERSION               0
#define SENT_TYPES_SW_PATCH_VERSION               0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sent_Ipw_Types header file are of the same vendor */
#if (SENT_TYPES_VENDOR_ID != SENT_IPW_TYPES_VENDOR_ID)
    #error "Sent_Types.h and Sent_Ipw_Types.h have different vendor ids" 
#endif
/* Check if current file and Sent_Ipw_Types header file are of the same Autosar version */
#if ((SENT_TYPES_AR_RELEASE_MAJOR_VERSION    != SENT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) ||    \
     (SENT_TYPES_AR_RELEASE_MINOR_VERSION    != SENT_IPW_TYPES_AR_RELEASE_MINOR_VERSION) ||    \
     (SENT_TYPES_AR_RELEASE_REVISION_VERSION != SENT_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Sent_Types.h and Sent_Ipw_Types.h are different" 
#endif
/* Check if current file and Sent_Ipw_Types header file are of the same Software version */
#if ((SENT_TYPES_SW_MAJOR_VERSION != SENT_IPW_TYPES_SW_MAJOR_VERSION) || \
     (SENT_TYPES_SW_MINOR_VERSION != SENT_IPW_TYPES_SW_MINOR_VERSION) || \
     (SENT_TYPES_SW_PATCH_VERSION != SENT_IPW_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Sent_Types.h and Sent_Ipw_Types.h are different" 
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes.h header file are of the same Autosar version */
    #if ((SENT_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
            (SENT_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of SentTypes.h and StandardTypes.h are different"
    #endif
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

/**
* @brief          Sent_DriverStatusType
* @details        Sent Driver status used for checking and preventing double driver intialization.
*                 SENT_UNINIT = The state SENT_UNINIT means that the Sent module has not 
*                              been initialized yet and cannot be used.
*                 SENT_INIT = The SENT_INIT state indicates that the Sent driver has been 
*                             initialized, making each available channel ready for service.
*
*/
typedef enum
{
    SENT_UNINIT = 0U,   /**< @brief Driver not initialized */
    SENT_INIT           /**< @brief Driver ready */
}Sent_DriverStatusType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief    Structure that contains Sent Hw configuration.
 * @details  It contains the information specific to one Sent Hw unit
 */
typedef struct
{
    /**< @brief HWoffet of configured controller */
    const uint8     CtrHwOffset;
    
    /**< @brief HWoffet of configured controller */
    const uint8     CtrHwID;
    
    /**< @brief Summary of all the channel in a controller. */
    const uint8     ChnlConfigured;

    /**< @brief Structure containing the hardware specific configuration for the channel. */
    const Sent_Ipw_CtrlConfigType       *CtrlConfig;
    
} Sent_ControllerConfigType;

/**
 * @brief This type contains initialization data.
 * @details This contains initialization data for the Sent driver. It shall contain:
 *         - The number of Sent modules to be configured
 *         - Dem error reporting configuration 
 *         - Sent dependent properties for used HW units
*/
/* @implements     Sent_ConfigType_structure */
typedef struct
{
    /**< @brief CodeID for configured controller */
    const uint32                CoreIDConfigured;
    
    /**< @brief Summary of all the configured controller. */
    const uint8                 CtrConfigured;

    /**< @brief Pointer to Sent hardware unit configuration */
    const Sent_ControllerConfigType * const * const ControllerConfig;
} Sent_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif    /*SENT_TYPES_H*/
