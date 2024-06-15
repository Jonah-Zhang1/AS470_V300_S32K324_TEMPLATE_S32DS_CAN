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

#ifndef WDG_CHANNEL_TYPES_H
#define WDG_CHANNEL_TYPES_H

/**
*   @file
*
*   @addtogroup Wdg
*   @{
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
#include "StandardTypes.h"
#include "Wdg_Cfg_Defines.h"
#include "WdgIf_Types.h"
#include "Wdg_Ipw_Types.h"

#if (WDG_DIRECT_SERVICE == STD_OFF)
    #include "Gpt.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_CHANNEL_TYPES_VENDOR_ID                    43
#define WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION     7
#define WDG_CHANNEL_TYPES_AR_RELEASE_REVISION_VERSION  0
#define WDG_CHANNEL_TYPES_SW_MAJOR_VERSION             3
#define WDG_CHANNEL_TYPES_SW_MINOR_VERSION             0
#define WDG_CHANNEL_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WDG configuration header file are of the same vendor */
#if (WDG_CHANNEL_TYPES_VENDOR_ID != WDG_VENDOR_ID_CFG)
#error "Wdg_ChannelType.h and Wdg_Cfg_Defines.h have different vendor ids"
#endif

/* Check if current file and Wdg_Cfg_Defines header file are of the same Autosar version */
#if ((WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION     != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION     != WDG_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_CHANNEL_TYPES_AR_RELEASE_REVISION_VERSION  != WDG_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Wdg_ChannelType.h and Wdg_Cfg_Defines.h are different"
#endif

/* Check if current file and Wdg_Cfg_Defines header file are of the same software version */
#if ((WDG_CHANNEL_TYPES_SW_MAJOR_VERSION != WDG_SW_MAJOR_VERSION_CFG) || \
     (WDG_CHANNEL_TYPES_SW_MINOR_VERSION != WDG_SW_MINOR_VERSION_CFG) || \
     (WDG_CHANNEL_TYPES_SW_PATCH_VERSION != WDG_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Wdg_ChannelType.h and Wdg_Cfg_Defines.h are different"
#endif

/* Check if current file and Wdg_Ipw_Types header file are of the same vendor */
#if (WDG_CHANNEL_TYPES_VENDOR_ID != WDG_IPW_TYPES_VENDOR_ID)
    #error "Wdg_ChannelType.h and Wdg_Ipw_Types.h have different vendor ids"
#endif

#if ((WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION     != WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION     != WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_TYPES_AR_RELEASE_REVISION_VERSION  != WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_ChannelType.h and Wdg_Ipw_Types.h are different"
#endif

#if ((WDG_CHANNEL_TYPES_SW_MAJOR_VERSION != WDG_IPW_TYPES_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_TYPES_SW_MINOR_VERSION != WDG_IPW_TYPES_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_TYPES_SW_PATCH_VERSION != WDG_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_ChannelType.h and Wdg_Ipw_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and WdgIf_Types header file are of the same Autosar version */
    #if ((WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION    != WDGIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION     != WDGIF_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_ChannelType.h and WdgIf_Types.h are different"
    #endif

    /* Check if source file and Gpt header file are of the same Autosar version */
    #if (WDG_DIRECT_SERVICE == STD_OFF)
        #if (( WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) || \
            ( WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION  != GPT_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Wdg_ChannelType.h and Gpt.h are different"
        #endif
    #endif

    /* Check if source file and Gpt header file are of the same Autosar version */
    #if (WDG_DIRECT_SERVICE == STD_OFF)
        #if (( WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
            ( WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Wdg_ChannelType.h and StandardTypes.h are different"
        #endif
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief  This enumerated type will contain the service ids for the watchodg functions
*
* @pre To define WDG_GETVERSION_ID, WDG_VERSION_INFO_API has to be equal to STD_ON
*
*/
typedef enum
{
#if (WDG_VERSION_INFO_API == STD_ON)
    WDG_GETVERSION_ID   = 0x04, /*< @brief The service id for the Wdg_GetVersion function,
                                            used when using DET */
#endif
#if (WDG_DIRECT_SERVICE == STD_ON)
    WDG_SERVICE_ID              = 0x05, /*< @brief The service id for the Wdg_Service function, used
                                            when using DET */
#endif
#if (WDG_DISABLE_ALLOWED == STD_ON)
#if (WDG_CLEAR_RESET_REQUEST == STD_ON)
    WDG_CLEARRESETREQUEST_ID    = 0x06, /*< @brief The service id for the Wdg_ClearResetRequest function, used
                                            when using DET */
#endif
#endif
    WDG_INIT_ID                 = 0x00, /*< @brief The service id for the Wdg_Init function, used
                                            when using DET */
    WDG_SETMODE_ID              = 0x01, /*< @brief The service id for the Wdg_SetMode function, used
                                            when using DET */
    WDG_TRIGGER_ID              = 0x02, /*< @brief The service id for the Wdg_Cbk_GptNotification function, used
                                            when using DET */
    WDG_SETTRIGGERCONDITION_ID  = 0x03  /*< @brief The service id for the Wdg_SetTriggerCondition function, used
                                            when using DET */
} Wdg_ServiceIdType;

/**
* @brief  Indicates the aditional det errors used by the watchdog driver
* @implements     Wdg_ErrorIdType_enum
*/
typedef enum
{
    WDG_E_DRIVER_STATE  = 0x10, /*< @brief API service used in wrong context (e.g. driver not
                                            initialized) */
    WDG_E_PARAM_MODE,           /*< @brief = 0x11 API service called with wrong/inconsistent
                                                   parameter(s) */
    WDG_E_PARAM_CONFIG,         /*< @brief = 0x12 API service called with wrong/inconsistent
                                                   parameter(s) */
    WDG_E_PARAM_TIMEOUT,        /*< @brief = 0x13 API service called with wrong/inconsistent
                                                   parameter(s) */
    WDG_E_PARAM_POINTER,        /*< @brief = 0x14 Wdg_GetVersionInfo service called with
                                                   NULL_PTR */
    WDG_E_INIT_FAILED,           /*< @brief = 0x15 Invalid configuration set selection */
#if (WDG_DISABLE_ALLOWED == STD_ON)
#if (WDG_CLEAR_RESET_REQUEST == STD_ON)
    WDG_E_STATUS_TIMEOUT,        /*< @brief = 0x16 API operation did not complete in time */
#endif /* WDG_CLEAR_RESET_REQUEST == STD_ON */
#endif /* WDG_DISABLE_ALLOWED == STD_ON */
} Wdg_ErrorIdType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct
{
    uint32 Wdg_u32TimerTriggeringPeriod;

    const Wdg_Ipw_ConfigType *Wdg_Ipw_pConfig;
} Wdg_ModeType;

/**
* @brief  Defines the configuration structure
* @implements     Wdg_ConfigType_struct
*/
typedef struct
{
    /**
    @brief The number of configured channels
    */
    const WdgIf_ModeType Wdg_DefaultMode;
    /**
    @brief The instance id
    */
    const Wdg_Ipw_InstanceType Wdg_Instance;

#if (WDG_DIRECT_SERVICE == STD_OFF)
    /**
    @brief Gpt Channel configured
    */
    const Gpt_ChannelType Wdg_TimerChannel;

    /**
    @brief The frequency of the configured timer channel
    */
    const uint32 Wdg_u32TriggerSourceClock;
#endif

    /**
    @brief Pointer to Watchdog Specific implementation details
    */
    const Wdg_ModeType *const Wdg_ModeSettings[3];

} Wdg_ConfigType;
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

#endif /*WDG_CHANNEL_TYPES_H*/
