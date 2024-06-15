/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : eMios
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

#ifndef OCU_TYPES_H
#define OCU_TYPES_H

/**
*   @file          Ocu_Types.h
*
*   @addtogroup    ocu_driver Ocu Driver
*   @brief         Ocu HLD generic types file.
*   @details       OCU header file containing generic Ocu types and structures.
*
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

#include "Std_Types.h"
#include "Ocu_CfgDefines.h"
#include "Ocu_Ipw_Types.h"

/*==================================================================================================
*                               HEADER FILE VERSION INFORMATION
==================================================================================================*/
#define OCU_TYPES_VENDOR_ID                       43
#define OCU_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define OCU_TYPES_AR_RELEASE_MINOR_VERSION        7
#define OCU_TYPES_AR_RELEASE_REVISION_VERSION     0
#define OCU_TYPES_SW_MAJOR_VERSION                3
#define OCU_TYPES_SW_MINOR_VERSION                0
#define OCU_TYPES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((OCU_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (OCU_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ocu_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if source file and OCU header file are of the same vendor */
#if (OCU_TYPES_VENDOR_ID != OCU_CFGDEFINES_VENDOR_ID)
    #error "Ocu_Types.h and Ocu_CfgDefines.h have different vendor IDs"
#endif
/* Check if source file and OCU header file are of the same AutoSar version */
#if ((OCU_TYPES_AR_RELEASE_MAJOR_VERSION != OCU_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_TYPES_AR_RELEASE_MINOR_VERSION != OCU_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_TYPES_AR_RELEASE_REVISION_VERSION != OCU_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ocu_Types.h and Ocu_CfgDefines.h are different"
#endif
/* Check if source file and OCU header file are of the same Software version */
#if ((OCU_TYPES_SW_MAJOR_VERSION != OCU_CFGDEFINES_SW_MAJOR_VERSION) || \
     (OCU_TYPES_SW_MINOR_VERSION != OCU_CFGDEFINES_SW_MINOR_VERSION) || \
     (OCU_TYPES_SW_PATCH_VERSION != OCU_CFGDEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Ocu_Types.h and Ocu_CfgDefines.h are different"
#endif

/* Check if source file and OCU types header file are of the same vendor */
#if (OCU_TYPES_VENDOR_ID != OCU_IPW_TYPES_VENDOR_ID)
    #error "Ocu_Types.h and Ocu_Ipw_Types.h have different vendor IDs"
#endif
    /* Check if header file and OCU types header file are the same as Autosar version */
#if ((OCU_TYPES_AR_RELEASE_MAJOR_VERSION != OCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (OCU_TYPES_AR_RELEASE_MINOR_VERSION != OCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (OCU_TYPES_AR_RELEASE_REVISION_VERSION != OCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Ocu_Types.h and Ocu_Ipw_Types.h are different"
#endif
/* Check if header file and OCU types header file are the same software version */
#if ((OCU_TYPES_SW_MAJOR_VERSION != OCU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (OCU_TYPES_SW_MINOR_VERSION != OCU_IPW_TYPES_SW_MINOR_VERSION) || \
     (OCU_TYPES_SW_PATCH_VERSION != OCU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Ocu_Types.h and Ocu_Ipw_Types.h are different"
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

/** @brief Valid channel number */
#define OCU_VALID_CHANNEL_NUM     0U

/** @brief Invalid channel number */
#define OCU_INVALID_CHANNEL_NUM     255U

/** @brief Instance ID of this OCU driver. */
#define OCU_INSTANCE_INDEX              (0U)

/**
* @brief            API service used without module initialization
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*
*/
#define OCU_E_UNINIT                    (0x02U)

/**
* @brief            API service used with an invalid channel Identifier
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_PARAM_INVALID_CHANNEL     (0x03U)

/**
* @brief            API Ocu_SetPinState() called with an invalid pin state or when the channel is in the RUNNING state..
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_PARAM_INVALID_STATE      (0x04U)

/**
* @brief            API Ocu_SetPinAction() called with an invalid pin action.
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_PARAM_INVALID_ACTION     (0x05U)

/**
* @brief            Usage of Ocu_DisableNotification() or Ocu_EnableNotification() on a channel where a NULL pointer
*                   is configured as the notification function.
* @details          Errors and exceptions that will be detected by the OCU driver.
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_NO_VALID_NOTIF           (0x06U)

/**
* @brief            API Ocu_Init() called while the OCU driver has already been initialized
* @details          Errors and exceptions that will be detected by the OCU driver.
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_ALREADY_INITIALIZED      (0x07U)

/**
* @brief            API Ocu_GetVersionInfo() is called with a NULL parameter.
* @details          Errors and exceptions that will be detected by the OCU driver.
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_PARAM_POINTER            (0x08U)

/**
* @brief            API Ocu_StartChannel() called on a channel that is in state RUNNING.
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_BUSY                      (0x09U)

/**
* @brief            Ocu_SetPinState() or Ocu_SetPinAction() called for a channel that doesn't
*                   have an associated output pin.
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_PARAM_NO_PIN              (0x0AU)


/**
* @brief            API Ocu_Init service called with wrong parameter
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define AUTOSAR
*/
#define OCU_E_INIT_FAILED               (0x0BU)

/**
* @brief            Ocu_SetAbsoluteThreshold() or Ocu_SetRelativeThreshold() called for with a compare
*                   match parameter greater than maximum supported counter value for a given channel
* @details          Errors and exceptions that will be detected by the OCU driver
* @implements       Ocu_ErrorIds_define Non-AUTOSAR
*/
#define OCU_E_PARAM_INVALID_VALUE       (0x1BU)

/**
* @brief            API Ocu_Init service called with wrong Core number
* @details          Errors and exceptions that will be detected by the OCU driver when
* @implements       Ocu_ErrorIds_define Non-AUTOSAR
*/
#define OCU_E_PARAM_CONFIG               (0x2BU)

/**
* @brief            API service ID of Ocu_Init() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_INIT_ID                (0x00U)

/**
* @brief            API service ID of Ocu_DeInit() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_DEINIT_ID              (0x01U)

/**
* @brief            API service ID of Ocu_StartChannel() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_STARTCHANNEL_ID        (0x02U)

/**
* @brief            API service ID of Ocu_StopChannel() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_STOPCHANNEL_ID         (0x03U)
/**
* @brief            API service ID of Ocu_SetPinState() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_SETPINSTATE_ID          (0x04U)

/**
* @brief            API service ID of Ocu_SetPinAction() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_SETPINACTION_ID         (0x05U)

/**
* @brief            API service ID of Ocu_GetCounter() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_GETCOUNTER_ID           (0x06U)

/**
* @brief            API service ID of Ocu_SetAbsoluteThreshold() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_SETABSOLUTETHRESHOLD_ID  (0x07U)

/**
* @brief            API service ID of Ocu_SetRelativeThreshold() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_SETRELATIVETHRESHOLD_ID  (0x08U)

/**
* @brief            API service ID of Ocu_GetVersionInfo() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_GETVERSIONINFO_ID        (0x09U)

/**
* @brief            API service ID of Ocu_DisableNotification() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_DISABLENOTIFICATION_ID   (0x0AU)

/**
* @brief            API service ID of Ocu_EnableNotification() function
* @details          Parameters used when raising an error/exception
*/
#define OCU_ENABLENOTIFICATION_ID    (0x0BU)

/**
* @brief            API Ocu_SetClockMode service called with wrong parameter
* @details          Parameters used when raising an error/exception
*/
#define OCU_SETCLOCKMODE_ID          (0x7AU)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief    Ocu channel notification typedef.
* @details  The callback notifications shall be configurable
*           as pointers to user defined functions within the configuration structure.
*/
typedef void (*Ocu_NotificationType)(void);

/**
* @brief        Ocu Value type (the value of the period is platform dependent and thus configurable)
* @details      Type for reading the counter and writing the threshold values (in number of ticks)
* @implements   Ocu_ValueType_typedef
*/
typedef uint32 Ocu_ValueType;
/**
* @brief      Ocu channel type
* @details    Numeric identifier of an OCU channel.
* @implements Ocu_ChannelType_typedef
*/
typedef uint16 Ocu_ChannelType;


/**
* @brief      Ocu Return Type
* @details    Return information after setting a new threshold value.
*
* @implements Ocu_ReturnType_enumeration
*/
typedef enum
{
    /** @brief The compare match will occur inside the current Reference Interval. */
    OCU_CM_IN_REF_INTERVAL = 0x00U,
    /** @brief The compare match will not occur inside the current Reference Interval. */
    OCU_CM_OUT_REF_INTERVAL = 0x01U
} Ocu_ReturnType;

/**
* @brief      Edge Pin Action type
* @details    Automatic action (by hardware) to be performed on a pin attached to an OCU channel.
* @implements Ocu_PinActionType_enumeration
*/
typedef enum
{
    /** @brief The channel pin will be set HIGH upon compare match. */
    OCU_SET_HIGH = 0x00U,
    /** @brief The channel pin will be set LOW upon compare match. */
    OCU_SET_LOW = 0x01U,
    /** @brief The channel pin will be set to the opposite of its current level HIGH upon compare match. */
    OCU_TOGGLE = 0x02U,
    /** @brief The channel pin will remain at its current level upon compare match. */
    OCU_DISABLE = 0x03U
} Ocu_PinActionType;


/**
* @brief      Pin State level
* @details    Output state of the pin linked to an OCU channel.
*
* @implements Ocu_PinStateType_enumeration
*/
typedef enum
{
    /** @brief The pin associated to an OCU channel is in high state. */
    OCU_HIGH = 0x00U,
    /** @brief The pin associated to an OCU channel is in low state. */
    OCU_LOW = 0x01U
} Ocu_PinStateType;

/**
* @brief      Prescaler type
* @details    This enum specifies the possible types of prescallers used to configure base-clock timers
*
*/
typedef enum
{
    /** @brief Selected value is the default/primary prescaler */
    OCU_PRIMARY_PRESCALER = 0,
    /** @brief Selected value is the alternative configured prescaler */
    OCU_ALTERNATIVE_PRESCALER
} Ocu_SelectPrescalerType;

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** @brief  Ocu high level channel configuration structure */
typedef struct
{
    /** @brief Channel output pin enable */
    boolean  OutputPinEnable;
#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
    /** @brief Pointer to channel notification function */
    const Ocu_NotificationType pfChNotification;
#endif
} Ocu_ChannelConfigType;

/**
* @brief      Ocu high level configuration structure
* @implements Ocu_ConfigType_struct
*/
typedef struct
{
    /** @brief Number of OCU channels (configured in tresos plugin builder) */
    const Ocu_ChannelType NumChannels;
    /** @brief Pointer to the OCU channel configuration */
    const Ocu_ChannelConfigType (*pOcuChannelsConfig)[];
    /** @brief Combined IP specific configuration structure */
    const Ocu_Ipw_IpConfigType *pcxIpConfig;
#if (STD_ON == OCU_NOTIFICATION_SUPPORTED)
    /** @brief  Index table to translate HW channels to logical used to process interrupts for notifications */
    const Ocu_ChannelType (*HwToLogicChannelMap)[];
#endif
    const Ocu_ChannelType (*Ocu_Channel_UseMap)[];
    /** @brief Index Core */
    uint8 CoreId;
} Ocu_ConfigType;

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

#endif    /*OCU_TYPES_H*/
