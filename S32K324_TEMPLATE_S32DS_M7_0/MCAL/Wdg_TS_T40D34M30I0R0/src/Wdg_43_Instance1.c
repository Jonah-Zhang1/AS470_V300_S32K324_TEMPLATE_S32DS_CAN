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
#include "Wdg_43_Instance1.h"
#include "Wdg_ChannelTypes.h"
#include "Wdg_Channel.h"

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_43_INSTANCE1_VENDOR_ID_C                    43
#define WDG_43_INSTANCE1_AR_RELEASE_MAJOR_VERSION_C     4
#define WDG_43_INSTANCE1_AR_RELEASE_MINOR_VERSION_C     7
#define WDG_43_INSTANCE1_AR_RELEASE_REVISION_VERSION_C  0
#define WDG_43_INSTANCE1_SW_MAJOR_VERSION_C             3
#define WDG_43_INSTANCE1_SW_MINOR_VERSION_C             0
#define WDG_43_INSTANCE1_SW_PATCH_VERSION_C             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_Channel.h header file are of the same vendor */
#if (WDG_43_INSTANCE1_VENDOR_ID_C != WDG_CHANNEL_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg_Channel.h have different vendor ids"
#endif

#if ((WDG_43_INSTANCE1_AR_RELEASE_MAJOR_VERSION_C    != WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_INSTANCE1_AR_RELEASE_MINOR_VERSION_C    != WDG_CHANNEL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_INSTANCE1_AR_RELEASE_REVISION_VERSION_C != WDG_CHANNEL_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg.c and Wdg_Channel.h are different"
#endif

#if ((WDG_43_INSTANCE1_SW_MAJOR_VERSION_C != WDG_CHANNEL_SW_MAJOR_VERSION) || \
     (WDG_43_INSTANCE1_SW_MINOR_VERSION_C != WDG_CHANNEL_SW_MINOR_VERSION) || \
     (WDG_43_INSTANCE1_SW_PATCH_VERSION_C != WDG_CHANNEL_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg.c and Wdg_Channel.h are different"
#endif

/* Check if current file and Wdg header file are of the same vendor */
#if (WDG_43_INSTANCE1_VENDOR_ID_C != WDG_43_INSTANCE1_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg.h have different vendor ids"
#endif

#if ((WDG_43_INSTANCE1_AR_RELEASE_MAJOR_VERSION_C    != WDG_43_INSTANCE1_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_INSTANCE1_AR_RELEASE_MINOR_VERSION_C    != WDG_43_INSTANCE1_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_INSTANCE1_AR_RELEASE_REVISION_VERSION_C != WDG_43_INSTANCE1_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg.c and Wdg.h are different"
#endif

#if ((WDG_43_INSTANCE1_SW_MAJOR_VERSION_C != WDG_43_INSTANCE1_SW_MAJOR_VERSION) || \
     (WDG_43_INSTANCE1_SW_MINOR_VERSION_C != WDG_43_INSTANCE1_SW_MINOR_VERSION) || \
     (WDG_43_INSTANCE1_SW_PATCH_VERSION_C != WDG_43_INSTANCE1_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg.c and Wdg.h are different"
#endif

/* Check if current file and Wdg_ChannelTypes.h header file are of the same vendor */
#if (WDG_43_INSTANCE1_VENDOR_ID_C != WDG_CHANNEL_TYPES_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg_ChannelTypes.h have different vendor ids"
#endif

#if ((WDG_43_INSTANCE1_AR_RELEASE_MAJOR_VERSION_C    != WDG_CHANNEL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_43_INSTANCE1_AR_RELEASE_MINOR_VERSION_C    != WDG_CHANNEL_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_43_INSTANCE1_AR_RELEASE_REVISION_VERSION_C != WDG_CHANNEL_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg.c and Wdg_ChannelTypes.h are different"
#endif

#if ((WDG_43_INSTANCE1_SW_MAJOR_VERSION_C != WDG_CHANNEL_TYPES_SW_MAJOR_VERSION) || \
     (WDG_43_INSTANCE1_SW_MINOR_VERSION_C != WDG_CHANNEL_TYPES_SW_MINOR_VERSION) || \
     (WDG_43_INSTANCE1_SW_PATCH_VERSION_C != WDG_CHANNEL_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg.c and Wdg_ChannelTypes.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
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
* @details The @p Wdg_43_Instance1_Init function shall initialize the Wdg module and the
*          watchdog hardware, i.e. it shall set the default watchdog mode and
*          timeout period as provided in the configuration set.
*
* @param[in] ConfigPtr     Pointer to configuration set.
*
* 
*
**/
void Wdg_43_Instance1_Init(const Wdg_ConfigType *ConfigPtr)
{
    Wdg_ChannelInit(WDG_IPW_INSTANCE1, ConfigPtr);
}


/**
* @brief   Switches the watchdog into the mode Mode.
* @details By choosing one of a limited number of statically configured
*          settings (e.g. toggle or window watchdog, different timeout periods)
*          the Wdg module and the watchdog hardware can be switched between the
*          following three different watchdog modes using the @p  Wdg_43_Instance1_SetMode
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
*                      .
*
* @return              Std_ReturnType.
* @retval  E_OK        Mode switch executed completely and successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
*
* 
*
**/
Std_ReturnType Wdg_43_Instance1_SetMode(WdgIf_ModeType Mode)
{
    return Wdg_ChannelSetMode(WDG_IPW_INSTANCE1, Mode);
}

#if (WDG_DIRECT_SERVICE_INSTANCE1 == STD_OFF)
    /**
    * @brief   Reset the watchdog timeout counter according to the timeout value passed.
    * @details 
    *
    * @param[in] Timeout    Timeout value (milliseconds) for setting the trigger counter.
    *  
    *
    **/
    void Wdg_43_Instance1_SetTriggerCondition(uint16 Timeout)
    {
        Wdg_ChannelSetTriggerCondition(WDG_IPW_INSTANCE1, Timeout);
    }
#endif

#if (WDG_DIRECT_SERVICE_INSTANCE1 == STD_ON)
    /**
    * @brief   Service the Watchdog directly without using an external trigger.
    * @details 
    *
    * @param 
    * 
    * 
    *
    **/
    void Wdg_43_Instance1_Service(void)
    {
        Wdg_ChannelService(WDG_IPW_INSTANCE1);
    }
#endif

#if (WDG_DISABLE_ALLOWED == STD_ON)
#if (WDG_CLEAR_RESET_REQUEST_INSTANCE1 == STD_ON)
    /**
    * @brief   Clear a reset request occurring after Watchdog timeout is reached.
    * @details 
    *
    * 
    * @return 
    * @retval  E_OK        Clear reset request successfully.
    * @retval  E_NOT_OK    returned if watchdog instance unlocks sequence failed
    *                      or it has not requested a reset.
    **/
    void Wdg_43_Instance1_ClearResetRequest(void)
    {
        Wdg_ChannelClearResetRequest(WDG_IPW_INSTANCE1);
    }
#endif
#endif


#if (WDG_43_INSTANCE1_VERSION_INFO_API == STD_ON)
/**
* @brief   Returns the version information of the module.
* @details The Wdg_43_Instance1_ChannelGetVersionInfo function shall return the version
*          information of this module. The version information includes:
*          - Module Id,
*          - Vendor Id,
*          - Vendor specific version numbers.
*          .
*
* @pre    This function is only required if the WDG_VERSION_INFO_API has to be
*         equal STD_ON.
*
* @param[in,out] Versioninfo   Pointer to where to store the version
*                              information of this module.
*
*
* @implements     Wdg_InstanceNo_GetVersionInfo_Activity
*
*
**/


void Wdg_43_Instance1_GetVersionInfo(Std_VersionInfoType *Versioninfo)
{
    Wdg_ChannelGetVersionInfo(WDG_IPW_INSTANCE1, Versioninfo);
}
#endif /* WDG_VERSION_INFO_API == STD_ON */


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

#endif /*#if (WDG_INSTANCE1 == STD_ON)*/
#ifdef __cplusplus
}
#endif
#endif

/** @} */
