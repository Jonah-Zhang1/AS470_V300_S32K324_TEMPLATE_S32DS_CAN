/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Swt
*   Dependencies         : none
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

#ifndef AEWDOG_IP_TYPES_H
#define AEWDOG_IP_TYPES_H

/**
*   @file
*
*   @addtogroup AeWdog_Ip
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "StandardTypes.h"
#include "AeWdog_Ip_Cfg_Defines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEWDOG_IP_TYPES_VENDOR_ID                    43
#define AEWDOG_IP_TYPES_MODULE_ID                    102
#define AEWDOG_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define AEWDOG_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define AEWDOG_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define AEWDOG_IP_TYPES_SW_MAJOR_VERSION             3
#define AEWDOG_IP_TYPES_SW_MINOR_VERSION             0
#define AEWDOG_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and AeWdog_Ip_Cfg_Defines configuration header file are of the same vendor */
#if (AEWDOG_IP_TYPES_VENDOR_ID != AEWDOG_IP_CFG_DEFINES_VENDOR_ID)
#error "AeWdog_Ip_Types.h and AeWdog_Ip_Cfg_Defines.h have different vendor ids"
#endif

#if ((AEWDOG_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_TYPES_AR_RELEASE_MINOR_VERSION    != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_TYPES_AR_RELEASE_REVISION_VERSION != AEWDOG_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of AeWdog_Ip_Types.h and AeWdog_Ip_Cfg_Defines.h are different"
#endif

#if ((AEWDOG_IP_TYPES_SW_MAJOR_VERSION != AEWDOG_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_TYPES_SW_MINOR_VERSION != AEWDOG_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (AEWDOG_IP_TYPES_SW_PATCH_VERSION != AEWDOG_IP_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of AeWdog_Ip_Types.h and AeWdog_Ip_Cfg_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((AEWDOG_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != STD_AR_RELEASE_MAJOR_VERSION) || \
        (AEWDOG_IP_TYPES_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of AeWdog_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/
/** @brief       Enum defining the possible type values for AEWDOG API
* @Implements    AeWdog_Ip_StatusType_enumeration
*/
typedef enum
{
    AEWDOG_IP_STATUS_SUCCESS      = 0x000U,
    AEWDOG_IP_STATUS_ERROR        = 0x001U,
    AEWDOG_IP_STATUS_TIMEOUT      = 0x002U
} AeWdog_Ip_StatusType;

/** @brief       Enum defining the watchdog mode for AEWDOG API
* @Implements    AeWdog_Ip_ModeType_enumeration
*/
typedef enum
{
    AEWDOG_IP_SIMPLE_WATCHDOG      = 0x00,
    AEWDOG_IP_CHALLENGER_WATCHDOG  = 0x01
} AeWdog_Ip_ModeType;

/** @brief       Enum defining the fault response configuration for AEWDOG API
* @Implements    AeWdog_Ip_FaultRespType_enumeration
*/
typedef enum
{
    AEWDOG_IP_NOTIFICATION   = 0x00,
    AEWDOG_IP_RESET          = 0x01
} AeWdog_Ip_FaultRespType;

/** @brief       Enum defining the max number of bad responses for AEWDOG API
* @Implements    AeWdog_Ip_BadRespType_enumeration
*/
typedef enum
{
    AEWDOG_IP_BADRESP_MAX_0   = 0x00,
    AEWDOG_IP_BADRESP_MAX_1   = 0x01,
    AEWDOG_IP_BADRESP_MAX_2   = 0x02,
    AEWDOG_IP_BADRESP_MAX_3   = 0x03
} AeWdog_Ip_BadRespType;

/** @brief       Enum defining the window duty cycle for AEWDOG API
* @Implements    AeWdog_Ip_WindowDutyCycleType_enumeration
*/
typedef enum
{
    AEWDOG_IP_DUTY_DISABLED   = 0x00,
    AEWDOG_IP_DUTY_31_25      = 0x01,
    AEWDOG_IP_DUTY_50_0       = 0x02,
    AEWDOG_IP_DUTY_68_75      = 0x03
} AeWdog_Ip_WindowDutyCycleType;

/** @brief       Enum defining the watchdog window duration for AEWDOG API
* @Implements    AeWdog_Ip_WindowPeriodType_enumeration
*/
typedef enum
{
    AEWDOG_IP_WD_PERIOD_DISABLED        = 0x00,
    AEWDOG_IP_WD_PERIOD_TIME_1_2_512    = 0x01,
    AEWDOG_IP_WD_PERIOD_TIME_2_2_512    = 0x02,
    AEWDOG_IP_WD_PERIOD_TIME_3_2_512    = 0x03,
    AEWDOG_IP_WD_PERIOD_TIME_4_2_512    = 0x04,
    AEWDOG_IP_WD_PERIOD_TIME_6_2_512    = 0x05,
    AEWDOG_IP_WD_PERIOD_TIME_8_2_512    = 0x06,
    AEWDOG_IP_WD_PERIOD_TIME_23_512     = 0x07,
    AEWDOG_IP_WD_PERIOD_TIME_31_512     = 0x08,
    AEWDOG_IP_WD_PERIOD_TIME_47_512     = 0x09,
    AEWDOG_IP_WD_PERIOD_TIME_62_512     = 0x0A,
    AEWDOG_IP_WD_PERIOD_TIME_125_512    = 0x0B,
    AEWDOG_IP_WD_PERIOD_TIME_250_512    = 0x0C,
    AEWDOG_IP_WD_PERIOD_TIME_500_512    = 0x0D,
    AEWDOG_IP_WD_PERIOD_TIME_1000_512   = 0x0E,
    AEWDOG_IP_WD_PERIOD_TIME_2000_512   = 0x0F
} AeWdog_Ip_WindowPeriodType;


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief AEWDOG configuration structure
 * This structure is used to configure the AEWDOG fault response, watchdog mode, Max number of bad responses,
 * window duty cycle and watchdog window duration
 *
 * Implements : aewdog_init_config_t_Class
 */
typedef struct
{
    AeWdog_Ip_ModeType              eAeWdogMode;      /*!< Watchdog mode for AEWDOG */
    AeWdog_Ip_FaultRespType         eFaultRespType;   /*!< Fault response configuration */
    AeWdog_Ip_BadRespType           eMaxBadResp;      /*!< Max number of bad responses */
    AeWdog_Ip_WindowDutyCycleType   eWindowDutyCycle; /*!< Window duty cycle */
    AeWdog_Ip_WindowPeriodType      eWindowPeriod;    /*!< Watchdog Window Duration */
} AeWdog_Ip_ConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEWDOG_IP_TYPES_H */
