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

#ifndef WDG_CHANNEL_H
#define WDG_CHANNEL_H

/**
*   @file
*
*   @addtogroup  Wdg
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
#include "Mcal.h"
#include "Wdg_ChannelTypes.h"
#include "Wdg_Cfg.h"

#if (WDG_DIRECT_SERVICE == STD_OFF)
    #include "Gpt.h"
#endif

#include "Wdg_Ipw_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_CHANNEL_VENDOR_ID                    43
#define WDG_CHANNEL_MODULE_ID                    102
#define WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION     4
#define WDG_CHANNEL_AR_RELEASE_MINOR_VERSION     7

#define WDG_CHANNEL_AR_RELEASE_REVISION_VERSION  0
#define WDG_CHANNEL_SW_MAJOR_VERSION             3
#define WDG_CHANNEL_SW_MINOR_VERSION             0
#define WDG_CHANNEL_SW_PATCH_VERSION             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and WDG configuration header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID != WDG_VENDOR_ID_CFG)
#error "Wdg_Channel.h and Wdg_Cfg.h have different vendor ids"
#endif

/* Check if current file and Wdg_Cfg header file are of the same Autosar version */
#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION     != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION     != WDG_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION  != WDG_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Wdg_Channel.h and Wdg_Cfg.h are different"
#endif

/* Check if current file and Wdg_Cfg header file are of the same software version */
#if ((WDG_CHANNEL_SW_MAJOR_VERSION != WDG_SW_MAJOR_VERSION_CFG) || \
     (WDG_CHANNEL_SW_MINOR_VERSION != WDG_SW_MINOR_VERSION_CFG) || \
     (WDG_CHANNEL_SW_PATCH_VERSION != WDG_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Wdg_Channel.h and Wdg_Cfg.h are different"
#endif

/* Check if current file and Wdg_ChannelTypes header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID != WDG_CHANNEL_TYPES_VENDOR_ID)
#error "Wdg_Channel.h and Wdg_ChannelTypes.h have different vendor ids"
#endif

#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION     != WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION     != WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION  != WDG_CHANNEL_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Channel.h and Wdg_ChannelTypes.h are different"
#endif

#if ((WDG_CHANNEL_SW_MAJOR_VERSION != WDG_CHANNEL_TYPES_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION != WDG_CHANNEL_TYPES_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION != WDG_CHANNEL_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Channel.h and Wdg_ChannelTypes.h are different"
#endif


/* Check if current file and Wdg_Ipw_Types header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID != WDG_IPW_TYPES_VENDOR_ID)
#error "Wdg_Channel.h and Wdg_Ipw_Types.h have different vendor ids"
#endif

#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION     != WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION     != WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION  != WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_Channel.h and Wdg_Ipw_Types.h are different"
#endif

#if ((WDG_CHANNEL_SW_MAJOR_VERSION != WDG_IPW_TYPES_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION != WDG_IPW_TYPES_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION != WDG_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Channel.h and Wdg_Ipw_Types.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same version */
    #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_Channel.h and Mcal.h are different"
    #endif

    /* Check if source file and Gpt header file are of the same Autosar version */
    #if (WDG_DIRECT_SERVICE == STD_OFF)
        #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION) || \
            (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Wdg_Channel.h and Gpt.h are different"
        #endif
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#if (WDG_MULTICORE_ENABLED == STD_ON)
    #define Wdg_GetCoreID() OsIf_GetCoreID()
#endif /* (WDG_MULTICORE_ENABLED == STD_ON) */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define WDG_START_SEC_CONFIG_DATA_UNSPECIFIED

#include "Wdg_MemMap.h"

#define WDG_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Wdg_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_START_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_START_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

/**
* @brief   This function initializes the WDG module.
* @details The @p Wdg_Init function shall initialize the Wdg module and the
*          watchdog hardware, i.e. it shall set the default watchdog mode and
*          timeout period as provided in the configuration set.
*
* @param[in]   ConfigPtr     Pointer to configuration set.
* @param[in]   Instance  Harwdware instance.
*
* @return         void
*
* @implements      Wdg_ChannelInit_Activity
*/
void Wdg_ChannelInit(const Wdg_Ipw_InstanceType Instance,
                     const Wdg_ConfigType *ConfigPtr);

/**
* @brief   Switches the watchdog into the mode Mode.
* @details By choosing one of a limited number of statically configured
*          settings (e.g. toggle or window watchdog, different timeout periods)
*          the Wdg module and the watchdog hardware can be switched between the
*          following three different watchdog modes using the @p Wdg_SetMode
*          function:<br>
*          - WDGIF_OFF_MODE,
*          - WDGIF_SLOW_MODE,
*          - WDGIF_FAST_MODE.
*          .
*
* @param[in] Mode      One of the following statically configured modes:<br>
*                      -# WDGIF_OFF_MODE,
*                      -# WDGIF_SLOW_MODE,
*                      -# WDGIF_FAST_MODE.
*
* @param[in]   Instance  Harwdware instance.
*
* @return              Std_ReturnType.
* @retval  E_OK        Mode switch executed completely and successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
*
* @implements      Wdg_ChannelSetMode_Activity
*/
Std_ReturnType Wdg_ChannelSetMode(const Wdg_Ipw_InstanceType Instance,
                                  WdgIf_ModeType Mode);

#if (WDG_DIRECT_SERVICE == STD_OFF)
/**
* @brief   Reset the watchdog timeout counter according to the timeout value passed.
* @details
*
* @param[in]   Timeout value (milliseconds) for setting the trigger counter.
* @param[in]   Instance  Harwdware instance.
*
* @implements      Wdg_ChannelSetTriggerCondition_Activity
*/
void Wdg_ChannelSetTriggerCondition(const Wdg_Ipw_InstanceType Instance,
                                    uint16 Timeout);
#endif

/*Returns the version information of the module.*/
#if (WDG_VERSION_INFO_API == STD_ON)
/**
* @brief   Returns the version information of the module.
* @details The  Wdg_ChannelGetVersionInfo function shall return the version
*          information of this module. The version information includes:
*          - Module Id,
*          - Vendor Id,
*          - Vendor specific version numbers.
*          .
*
* @pre    This function is available if the WDG_VERSION_INFO_API must be
*         equal STD_ON.
*
* @param[in,out] VersionInfo   Pointer to where to store the version
*                              information of this module.
* @param[in]     Instance  Harwdware instance.
*
*
*
* @implements      Wdg_ChannelGetVersionInfo_Activity
*/
void Wdg_ChannelGetVersionInfo(const Wdg_Ipw_InstanceType Instance,
                                Std_VersionInfoType *VersionInfo);

#endif /* WDG_VERSION_INFO_API == STD_ON */

#if (WDG_DIRECT_SERVICE == STD_ON)
    /**
    * @brief   Perform a wdg channel service.
    * @details 
    *
    * @pre    This this function is availble if the WDG_DIRECT_SERVICE must be
    *         equal STD_ON.
    * @param[in]   Instance  Harwdware instance.
    * 
    * @implements      Wdg_ChannelService_Activity
    *
    * @return void
    */
    void Wdg_ChannelService(const Wdg_Ipw_InstanceType Instance);
#endif /* WDG_DIRECT_SERVICE == STD_ON */

#if (WDG_DISABLE_ALLOWED == STD_ON)
#if (WDG_CLEAR_RESET_REQUEST == STD_ON)
    /**
    * @brief   Clear a reset request occurring after Watchdog timeout is reached.
    * @details 
    *
    * @pre    This this function is availble if the WDG_DISABLE_ALLOWED and WDG_CLEAR_RESET_REQUEST must be
    *         equal STD_ON.
    * @param[in]   Instance  Harwdware instance.
    * 
    * @implements      Wdg_ChannelClearResetRequest_Activity
    *
    * @return void
    * @retval  E_OK        Clear reset request successfully.
    * @retval  E_NOT_OK    returned if watchdog instance unlocks sequence failed
    *                      or it has not requested a reset.
    *
    */
void Wdg_ChannelClearResetRequest(const Wdg_Ipw_InstanceType Instance);
#endif /* WDG_CLEAR_RESET_REQUEST == STD_ON */
#endif /* WDG_DISABLE_ALLOWED == STD_ON */


#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_STOP_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_STOP_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* WDG_CHANNEL_H */
