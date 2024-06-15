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
* @{
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

#include "Wdg_Channel.h"
#include "Wdg_EnvCfg.h"
#include "Wdg_Ipw.h"
#include "SchM_Wdg.h"
#include "Det.h"
#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #include "Dem.h"
#endif
#include "Wdg_CfgExt.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_CHANNEL_VENDOR_ID_C                      43
#define WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C       4
#define WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C       7
#define WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C    0
#define WDG_CHANNEL_SW_MAJOR_VERSION_C               3
#define WDG_CHANNEL_SW_MINOR_VERSION_C               0
#define WDG_CHANNEL_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and WDG configuration header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID_C != WDG_CHANNEL_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg_Channel.h have different vendor ids"
#endif

/* Check if current file and Wdg_Channel header file are of the same Autosar version */
#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C     != WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C     != WDG_CHANNEL_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C != WDG_CHANNEL_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_Channel.h are different"
#endif

/* Check if current file and Wdg_Channel header file are of the same software version */
#if ((WDG_CHANNEL_SW_MAJOR_VERSION_C != WDG_CHANNEL_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION_C != WDG_CHANNEL_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION_C != WDG_CHANNEL_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Channel.c and Wdg_Channel.h are different"
#endif

/* Check if current file and Wdg_EnvCfg header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID_C != WDG_ENVCFG_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg_EnvCfg.h have different vendor ids"
#endif

#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C     != WDG_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C     != WDG_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C  != WDG_ENVCFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_EnvCfg.h are different"
#endif

#if ((WDG_CHANNEL_SW_MAJOR_VERSION_C != WDG_ENVCFG_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION_C != WDG_ENVCFG_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION_C != WDG_ENVCFG_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Channel.c and Wdg_EnvCfg.h are different"
#endif

/* Check if current file and Wdg_Ipw header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID_C != WDG_IPW_VENDOR_ID)
    #error "Wdg_Channel.c and Wdg_Ipw.h have different vendor ids"
#endif

#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C     != WDG_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C     != WDG_IPW_AR_RELEASE_MINOR_VERSION) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C  != WDG_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_Ipw.h are different"
#endif

#if ((WDG_CHANNEL_SW_MAJOR_VERSION_C != WDG_IPW_SW_MAJOR_VERSION) || \
     (WDG_CHANNEL_SW_MINOR_VERSION_C != WDG_IPW_SW_MINOR_VERSION) || \
     (WDG_CHANNEL_SW_PATCH_VERSION_C != WDG_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Channel.c and Wdg_Ipw.h are different"
#endif

/* Check if current file and Wdg_CfgExt header file are of the same vendor */
#if (WDG_CHANNEL_VENDOR_ID_C != WDG_VENDOR_ID_CFG_EXT)
    #error "Wdg_Channel.c and Wdg_CfgExt.h have different vendor ids"
#endif

#if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C     != WDG_AR_RELEASE_MAJOR_VERSION_CFG_EXT) || \
     (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C     != WDG_AR_RELEASE_MINOR_VERSION_CFG_EXT) || \
     (WDG_CHANNEL_AR_RELEASE_REVISION_VERSION_C  != WDG_AR_RELEASE_REVISION_VERSION_CFG_EXT))
#error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_CfgExt.h are different"
#endif

#if ((WDG_CHANNEL_SW_MAJOR_VERSION_C != WDG_SW_MAJOR_VERSION_CFG_EXT) || \
     (WDG_CHANNEL_SW_MINOR_VERSION_C != WDG_SW_MINOR_VERSION_CFG_EXT) || \
     (WDG_CHANNEL_SW_PATCH_VERSION_C != WDG_SW_PATCH_VERSION_CFG_EXT))
#error "Software Version Numbers of Wdg_Channel.c and Wdg_CfgExt.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and SchM_Wdg header file are of the same Autosar version */
    #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C     != SCHM_WDG_AR_RELEASE_MAJOR_VERSION) || \
        (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C     != SCHM_WDG_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wdg_Channel.c and SchM_Wdg.h are different"
    #endif

    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C     != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C     != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wdg_Channel.c and Mcal.h are different"
    #endif

    /* Check if current file and Det header file are of the same Autosar version */
    #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C     != DET_AR_RELEASE_MAJOR_VERSION) || \
        (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C     != DET_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Wdg_Channel.c and Det.h are different"
    #endif

    #if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Check if current file and Dem header file are of the same Autosar version */
        #if ((WDG_CHANNEL_AR_RELEASE_MAJOR_VERSION_C     != DEM_AR_RELEASE_MAJOR_VERSION) || \
            (WDG_CHANNEL_AR_RELEASE_MINOR_VERSION_C     != DEM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Wdg_Channel.c and Dem.h are different"
        #endif
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief  This enumerated type will contain the watchdog driver's possible states
*/
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
typedef enum
{
    WDG_UNINIT         = 0x01,  /**< @brief = 0x01 The watchdog driver is not uninitialized */
    WDG_IDLE           = 0x02,  /**< @brief = 0x02 The watchdog driver is currently idle,
                                                   i.e not being triggered or mode changed */
    WDG_BUSY           = 0x03,  /**< @brief = 0x03 The watchdog driver is currently busy,
                                                   i.e triggered or switched between modes */
    WDG_INITIALIZING   = 0x04   /**< @brief = 0x04 The watchdog driver is currently initializing */

} Wdg_StatusType;
#endif

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

#define WDG_START_SEC_VAR_CLEARED_UNSPECIFIED

#include "Wdg_MemMap.h"

/**
*  @brief Variable that indicate the current configuration set
*/
static const Wdg_ConfigType* Wdg_apConfigPtr[WDG_NO_OF_INSTANCES];

#define WDG_STOP_SEC_VAR_CLEARED_UNSPECIFIED

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
    #define WDG_START_SEC_VAR_INIT_UNSPECIFIED

    #include "Wdg_MemMap.h"

    /**
    *  @brief Variable that indicated the state of the driver
    */
    static Wdg_StatusType Wdg_aeStatus[WDG_NO_OF_INSTANCES] = WDG_INIT_STATUS_ARRAY;

    #define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED

    #include "Wdg_MemMap.h"
#endif

#if (WDG_DIRECT_SERVICE == STD_OFF)
    #define WDG_START_SEC_VAR_CLEARED_32

    #include "Wdg_MemMap.h"

    /**
    *  @brief Variable that indicate the watchdog timeout
    */
    static uint32 Wdg_au32Timeout[WDG_NO_OF_INSTANCES]; /* implicit zero initialization*/

    /**
    *  @brief Variable that indicated the timer value in ms
    */
    static uint32 Wdg_au32GptPeriod[WDG_NO_OF_INSTANCES]; /* implicit zero initialization*/

    #define WDG_STOP_SEC_VAR_CLEARED_32

    #include "Wdg_MemMap.h"
#endif

#define WDG_START_SEC_VAR_CLEARED_UNSPECIFIED

#include "Wdg_MemMap.h"

/**
*  @brief Variable that indicates the last Wdg Mode
*/
static WdgIf_ModeType Wdg_aePreviousMode[WDG_NO_OF_INSTANCES] = WDG_INIT_PREVIOUS_MODE_ARRAY; /* implicit zero initialization*/

#if (WDG_DIRECT_SERVICE == STD_OFF)
#if (WDG_VALIDATE_PARAMS == STD_ON)
    static WdgIf_ModeType Wdg_aeCurrentMode[WDG_NO_OF_INSTANCES] = WDG_INIT_PREVIOUS_MODE_ARRAY; /* implicit zero initialization*/
#endif /*(WDG_VALIDATE_PARAMS == STD_ON)*/
#endif /*(WDG_DIRECT_SERVICE == STD_OFF)*/

#define WDG_STOP_SEC_VAR_CLEARED_UNSPECIFIED

#include "Wdg_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
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

#if (WDG_DIRECT_SERVICE == STD_OFF)
    /* Gpt Callback functionality is only active if the Service Mode requires an external timer */
    static inline void  Wdg_ChannelTrigger(const Wdg_Ipw_InstanceType Instance);

        #ifdef WDG_INSTANCE0
    #if (WDG_INSTANCE0 == STD_ON)
    void Wdg_Cbk_GptNotification0(void);
    #endif
    #endif

            #ifdef WDG_INSTANCE1
    #if (WDG_INSTANCE1 == STD_ON)
    void Wdg_Cbk_GptNotification1(void);
    #endif
    #endif

            #ifdef WDG_INSTANCE2
    #if (WDG_INSTANCE2 == STD_ON)
    void Wdg_Cbk_GptNotification2(void);
    #endif
    #endif

            #ifdef WDG_INSTANCE3
    #if (WDG_INSTANCE3 == STD_ON)
    void Wdg_Cbk_GptNotification3(void);
    #endif
    #endif

            #ifdef WDG_INSTANCE4
    #if (WDG_INSTANCE4 == STD_ON)
    void Wdg_Cbk_GptNotification4(void);
    #endif
    #endif

                                
    
#endif /* WDG_DIRECT_SERVICE */

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
static inline Std_ReturnType Wdg_ChannelValidateGlobalCall(CONST(Wdg_ServiceIdType, AUTOMATIC)ServiceId,
                                                                          const Wdg_Ipw_InstanceType Instance
                                                                         );
#endif

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
static inline void Wdg_ChannelEndValidateGlobalCall(Std_ReturnType Validation,
                                                                   const Wdg_Ipw_InstanceType Instance
                                                                  );
#endif

#if (WDG_VALIDATE_PARAMS == STD_ON)
static inline Std_ReturnType Wdg_ValidatePtrInit
                                            (const Wdg_ConfigType* const ConfigPtr,
                                             const Wdg_Ipw_InstanceType Instance
                                            );
#endif

#if (WDG_DIRECT_SERVICE == STD_OFF)
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
static inline Std_ReturnType Wdg_ChannelValidateTrigerCondition(const Wdg_Ipw_InstanceType Instance);
#endif /* WDG_VALIDATE_GLOBAL_CALL == STD_ON */
#endif /* WDG_DIRECT_SERVICE == OFF */

#if ((WDG_VALIDATE_PARAMS == STD_ON) && (WDG_VERSION_INFO_API == STD_ON))
static inline Std_ReturnType Wdg_ValidatePtrVersion
                                           (const Std_VersionInfoType* VersionInfo,
                                            const Wdg_Ipw_InstanceType Instance
                                           );
#endif


static inline Std_ReturnType Wdg_ChannelValidateMode(WdgIf_ModeType Wdg_Mode,
                                                                    Wdg_ServiceIdType ServiceId,
                                                                    Wdg_ErrorIdType ErrorId,
                                                                    const Wdg_Ipw_InstanceType Instance
                                                                   );

#if (WDG_DIRECT_SERVICE == STD_OFF)
#if (WDG_VALIDATE_PARAMS == STD_ON)
static inline Std_ReturnType Wdg_ValidateTimeout(uint16 Timeout,
                                                                const Wdg_Ipw_InstanceType Instance
                                                               );
#endif /* WDG_VALIDATE_GLOBAL_CALL == STD_ON */
#endif /* WDG_DIRECT_SERVICE == OFF */

#if (WDG_MULTICORE_ENABLED == STD_ON)
static inline Std_ReturnType Wdg_ChannelValidateCoreUsed(uint32 CoreID,
                                                                        const Wdg_Ipw_InstanceType Instance,
                                                                        Wdg_ServiceIdType ServiceId,
                                                                        Wdg_ErrorIdType ErrorId
                                                                       );
#endif

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
/*==================================================================================================
*                                       LOCAL FUNCTIONS
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

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function validates the global call
 * @details    This service is a non reentrant function used for validating the calls for functions
 *             that uses all the channels - Wdg_Init, Wdg_SetTriggerCondition, Wdg_SetMode.
 *
 * @param[in]   ServiceId      The service id of the caller function
 * @param[in]   Instance    Harwdware WDG instance
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Wdg_ChannelValidateGlobalCall_Activity
 *
 * */
static inline Std_ReturnType Wdg_ChannelValidateGlobalCall(const Wdg_ServiceIdType ServiceId,
                                                                          const Wdg_Ipw_InstanceType Instance
                                                                         )
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;

    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_06();
    if (((WDG_UNINIT == Wdg_aeStatus[Instance]) && (WDG_INIT_ID != ServiceId)) ||\
       (WDG_INITIALIZING == Wdg_aeStatus[Instance]) || (WDG_BUSY == Wdg_aeStatus[Instance])
      )
    {
        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_06();
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)ServiceId, (uint8)WDG_E_DRIVER_STATE);
        Valid = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if (WDG_INIT_ID == ServiceId)
        {
            Wdg_aeStatus[Instance] = WDG_INITIALIZING;
        }
        else
        {
            Wdg_aeStatus[Instance] = WDG_BUSY;
        }
        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_06();
    }
    return Valid;
}
#endif /* WDG_VALIDATE_GLOBAL_CALL == STD_ON */

#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function ends the validation of the global call.
 * @details    This service is a non reentrant function used for end the validation the calls for
 *             functions that uses all the channels - Wdg_Init, Wdg_SetTriggerCondition, Wdg_SetMode.
 *
 * @param[in]   Validation      The function call was previously validated
 * @param[in]   Instance    Harwdware WDG instance.
 * @return void
 *
 * @implements  Wdg_ChannelEndValidateGlobalCall_Activity
 * */
static inline void Wdg_ChannelEndValidateGlobalCall(Std_ReturnType Validation,
                                                                   const Wdg_Ipw_InstanceType Instance
                                                                  )
{
    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_07();
    if ((Std_ReturnType)E_OK == Validation)
    {
        Wdg_aeStatus[Instance] = WDG_IDLE;
    }
    else
    {
        if (WDG_BUSY == Wdg_aeStatus[Instance])
        {
            Wdg_aeStatus[Instance] = WDG_IDLE;
        }
        else
        {
            if (NULL_PTR == Wdg_apConfigPtr[Instance])
            {
                Wdg_aeStatus[Instance] = WDG_UNINIT;
            }
            else
            {
                Wdg_aeStatus[Instance] = WDG_IDLE;
            }
        }
    }
    SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_07();
}
#endif /* WDG_VALIDATE_GLOBAL_CALL == STD_ON*/

#if (WDG_MULTICORE_ENABLED == STD_ON)
 /**
 * @brief      This function uses to check if the Core is validate
 *
 * @param[in]   The Wdg_ChannelValidateCoreUsed will check invalidate CoreID.
 * @param[in]   ServiceId    The service id of the caller function
 * @param[in]   ErrorId      The function call was previously validated
 * @param[in]   Instance  Harwdware WDG instance.
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 *
 * */
static inline Std_ReturnType Wdg_ChannelValidateCoreUsed(uint32 CoreID,
                                                                        const Wdg_Ipw_InstanceType Instance,
                                                                        Wdg_ServiceIdType ServiceId,
                                                                        Wdg_ErrorIdType ErrorId
                                                                       )
{
    Std_ReturnType Valid = (Std_ReturnType)E_NOT_OK;

    if (CoreID == Wdg_au32InstanceCoreUsed[Instance])
    {
        Valid = (Std_ReturnType)E_OK;
    }
#if (WDG_VALIDATE_PARAMS == STD_ON)
    else
    {
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)ServiceId, (uint8)ErrorId);
    }
#else
        (void)ServiceId;
        (void)ErrorId;
#endif
    return Valid;
}
#endif

#if (WDG_DIRECT_SERVICE == STD_OFF)
    /* GPT triggering of the Watchdog is only available if the WDG is not serviced directly */
    /**
    * @brief   Triggers the Watchdog.
    * @details The Wdg_Cbk_GptNotification shall trigger the hardware. It is set up
    *          as notification function for the Gpt timer that controls the trigger of
    *          the watchdog
    *
    * @pre    This API has to be set up as notification for the Gpt channels that is set up
    *         for Wdg
    *
    * @param[in]   Instance  Harwdware WDG instance.
    *
    *
    * @implements      Wdg_ChannelTrigger_Activity
    *
    */
    static inline void Wdg_ChannelTrigger(const Wdg_Ipw_InstanceType Instance)
    {
        uint32 TempTimeout;
    #if ((WDG_MULTICORE_ENABLED == STD_ON) || (WDG_VALIDATE_GLOBAL_CALL == STD_ON))
        Std_ReturnType Valid;
    #endif
    #if (WDG_MULTICORE_ENABLED == STD_ON)
        volatile uint32 CoreID;

        CoreID = (uint32) Wdg_GetCoreID();
        Valid = Wdg_ChannelValidateCoreUsed(CoreID, Instance,WDG_TRIGGER_ID,WDG_E_PARAM_CONFIG);
        if ((Std_ReturnType)E_OK == Valid)
        {
    #endif
    #if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
            Valid = Wdg_ChannelValidateGlobalCall(WDG_TRIGGER_ID, Instance);
            if ((Std_ReturnType)E_OK == Valid)
            {
    #endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */
                MCAL_FAULT_INJECTION_POINT(T_WDG_INJ_CHANNEL_TRIGGER_START);

                SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_00();

                if (Wdg_au32Timeout[Instance] < Wdg_au32GptPeriod[Instance])
                {
                    SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();

                    Gpt_StopTimer(Wdg_apConfigPtr[Instance]->Wdg_TimerChannel);
                }
                else
                {
                    TempTimeout = Wdg_au32Timeout[Instance] - Wdg_au32GptPeriod[Instance];
                    Wdg_au32Timeout[Instance] = TempTimeout;
                    SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_00();
                    Wdg_Ipw_Service(Instance);
                }
    #if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
            }
            Wdg_ChannelEndValidateGlobalCall(Valid, Instance);
    #endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */
                MCAL_FAULT_INJECTION_POINT(T_WDG_INJ_CHANNEL_TRIGGER_STOP);
    #if (WDG_MULTICORE_ENABLED == STD_ON)
        }
    #endif
    }

        #ifdef WDG_INSTANCE0
    #if (WDG_INSTANCE0 == STD_ON)
    /**
    * @brief     Callback function Wdg_ChannelTrigger.
    * @implements  Wdg_Cbk_GptNotificationInstanceNo_Activity
    *
    **/
    void Wdg_Cbk_GptNotification0(void)
    {
        Wdg_ChannelTrigger(WDG_IPW_INSTANCE0);
    }
    #endif
    #endif

            #ifdef WDG_INSTANCE1
    #if (WDG_INSTANCE1 == STD_ON)
    /**
     * @brief     Callback function Wdg_ChannelTrigger.
     *   @implements  Wdg_Cbk_GptNotificationInstanceNo_Activity
     *
    **/
    void Wdg_Cbk_GptNotification1(void)
    {
        Wdg_ChannelTrigger(WDG_IPW_INSTANCE1);
    }
    #endif
    #endif

            #ifdef WDG_INSTANCE2
    #if (WDG_INSTANCE2 == STD_ON)
    /**
    * @brief     Callback function Wdg_ChannelTrigger.
    *   @implements  Wdg_Cbk_GptNotificationInstanceNo_Activity
    *
    **/
    void Wdg_Cbk_GptNotification2(void)
    {
        Wdg_ChannelTrigger(WDG_IPW_INSTANCE2);
    }
    #endif
    #endif

            #ifdef WDG_INSTANCE3
    #if (WDG_INSTANCE3 == STD_ON)
    /**
    * @brief     Callback function Wdg_ChannelTrigger.
    *   @implements  Wdg_Cbk_GptNotificationInstanceNo_Activity
    *
    **/
    void Wdg_Cbk_GptNotification3(void)
    {
        Wdg_ChannelTrigger(WDG_IPW_INSTANCE3);
    }
    #endif
    #endif

            #ifdef WDG_INSTANCE4
    #if (WDG_INSTANCE4 == STD_ON)
    /**
    * @brief     Callback function Wdg_ChannelTrigger.
    *   @implements  Wdg_Cbk_GptNotificationInstanceNo_Activity
    *
    **/
    void Wdg_Cbk_GptNotification4(void)
    {
        Wdg_ChannelTrigger(WDG_IPW_INSTANCE4);
    }
    #endif
    #endif

                                
    
#endif /* WDG_DIRECT_SERVICE */

#if (WDG_VALIDATE_PARAMS == STD_ON)
/**
 * @brief       This function validate the initialization pointer.
 *
 * @param[in]   ConfigPtr        Pointer to a selected configuration structure
 * @param[in]   Instance     Harwdware WDG instance
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_ValidatePtrInit_Activity
 *
 * */
static inline Std_ReturnType Wdg_ValidatePtrInit(const Wdg_ConfigType * const ConfigPtr, const Wdg_Ipw_InstanceType Instance)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
    if (NULL_PTR != ConfigPtr)
#else
    if (NULL_PTR == ConfigPtr)
#endif /*#if (WDG_PRECOMPILE_SUPPORT == STD_ON)*/
    {
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)WDG_INIT_ID, (uint8)WDG_E_INIT_FAILED);
        valid = (Std_ReturnType)E_NOT_OK;
    }
#if (WDG_PRECOMPILE_SUPPORT == STD_OFF)
    else
    {
        if (Instance != ConfigPtr->Wdg_Instance)
        {
            (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)WDG_INIT_ID, (uint8)WDG_E_INIT_FAILED);
            valid = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            /* do nothing */
        }
    }
#endif /*WDG_PRECOMPILE_SUPPORT == STD_OFF*/
    return valid;
}
#endif /* (WDG_VALIDATE_PARAMS == STD_ON)*/

#if (WDG_DIRECT_SERVICE == STD_OFF)
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
/**
 * @brief      This function validates the call of Wdg_ChannelSetTriggerCondition function
 * @details    This service is a function used for validating the calls for
               Wdg_ChannelSetTriggerCondition.
 *
 * @param[in]   Instance    Harwdware WDG instance
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 * @implements  Wdg_ChannelValidateTrigerCondition_Activity
 *
 * */
static inline Std_ReturnType Wdg_ChannelValidateTrigerCondition(const Wdg_Ipw_InstanceType Instance)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    if ((WDG_UNINIT == Wdg_aeStatus[Instance]) ||(WDG_INITIALIZING == Wdg_aeStatus[Instance]))
    {
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)WDG_SETTRIGGERCONDITION_ID, (uint8)WDG_E_DRIVER_STATE);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* WDG_VALIDATE_GLOBAL_CALL == STD_ON */
#endif /* WDG_DIRECT_SERVICE == OFF */

#if ((WDG_VALIDATE_PARAMS == STD_ON) && (WDG_VERSION_INFO_API == STD_ON))
/**
 * @brief       This function validate the initialization pointer.
 *
 * @param[in]   VersionInfo        Pointer to a selected configuration structure.
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_ValidatePtrVersion_Activity
 *
 * */
static inline Std_ReturnType Wdg_ValidatePtrVersion(const Std_VersionInfoType * VersionInfo,
                                                    const Wdg_Ipw_InstanceType Instance)
{
    Std_ReturnType valid = (Std_ReturnType)E_OK;

    if (NULL_PTR == VersionInfo)
    {
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance,(uint8)WDG_GETVERSION_ID,(uint8)WDG_E_PARAM_POINTER);
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (WDG_VALIDATE_PARAMS == STD_ON)*/
/**
 * @brief       This function validate the mode that will be set up.
 *
 * @param[in]   Wdg_Mode      The watchdog mode that will be set up.
 * @param[in]   ServiceId    The service id of the caller function
 * @param[in]   ErrorId      The function call was previously validated
 * @param[in]   Instance  Harwdware WDG instance.
 *
 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_ChannelValidateMode_Activity
 *
 * */
static inline Std_ReturnType Wdg_ChannelValidateMode(WdgIf_ModeType Wdg_Mode,
                                                                    Wdg_ServiceIdType ServiceId,
                                                                    Wdg_ErrorIdType ErrorId,
                                                                    const Wdg_Ipw_InstanceType Instance
                                                                   )
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;
    boolean DisableRejectedErrActive = FALSE;
    boolean ModeFailedErrActive = FALSE;

#if (WDG_DISABLE_ALLOWED == STD_OFF)
    if (WDGIF_OFF_MODE == Wdg_Mode)
    {
        DisableRejectedErrActive = TRUE;
        Valid = (Std_ReturnType)E_NOT_OK;
    }
#endif  /* (WDG_DISABLE_ALLOWED == STD_OFF) */
     /* Some peripherals (e.g. EWM) do not support all modes, so this corresponding struct member is generated as NULL */
    if ((!((WDGIF_OFF_MODE  == Wdg_Mode)||(WDGIF_FAST_MODE == Wdg_Mode)||(WDGIF_SLOW_MODE == Wdg_Mode))) || \
         (NULL_PTR == Wdg_apConfigPtr[Instance]->Wdg_ModeSettings[Wdg_Mode]) \
       )
    {
#if (WDG_VALIDATE_PARAMS == STD_ON)

        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)ServiceId, (uint8)ErrorId);
#else
        (void)ServiceId;
        (void)ErrorId;
        (void)Instance;
#endif
         ModeFailedErrActive = TRUE;
         Valid = (Std_ReturnType)E_NOT_OK;
    }

#if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    if ((uint32)STD_ON == Wdg_E_Disable_Rejected.state)
    {
    #if (WDG_DISABLE_ALLOWED == STD_OFF)
            if (TRUE == DisableRejectedErrActive)
            {
                (void) Dem_SetEventStatus((Dem_EventIdType)Wdg_E_Disable_Rejected.id, DEM_EVENT_STATUS_FAILED);
            }
            else
            {
                (void) Dem_SetEventStatus((Dem_EventIdType)Wdg_E_Disable_Rejected.id, DEM_EVENT_STATUS_PASSED);
            }
    #else
        (void)DisableRejectedErrActive;
    #endif     /*WDG_DISABLE_ALLOWED == STD_OFF*/
    }
    if ((uint32)STD_ON == Wdg_E_Mode_Failed.state)
    {
        if (TRUE == ModeFailedErrActive)
        {
            (void) Dem_SetEventStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            (void) Dem_SetEventStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, DEM_EVENT_STATUS_PASSED);
        }
    }
#else
    (void)ModeFailedErrActive;
    (void)DisableRejectedErrActive;
#endif  /* (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

    return Valid;
}

#if (WDG_DIRECT_SERVICE == STD_OFF)
#if (WDG_VALIDATE_PARAMS == STD_ON)
/**
 * @brief       This function validate the initialization pointer.
 *
 * @param[in]   Timeout    timeout window
 * @param[in]   Instance  Harwdware WDG instance.

 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * @implements  Wdg_ValidateTimeout_Activity
 * This function is called in IP HW
 * */
static inline Std_ReturnType Wdg_ValidateTimeout(uint16 Timeout,
                                                const Wdg_Ipw_InstanceType Instance)
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;
    const uint32 Wdg_au32WdgTimeOutPeriod[WDG_NO_OF_INSTANCES][3] = WDG_TIMEOUT_VALUE_ARRAY;
    uint16 CfgMaxTimeout = Wdg_au16CfgMaxTimeout[Instance];

    if ((Timeout > CfgMaxTimeout) || ((Timeout <= (uint16)Wdg_au32WdgTimeOutPeriod[Instance][Wdg_aeCurrentMode[Instance]]) && (Timeout != (uint16)0U)))
    {
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance,(uint8)WDG_SETTRIGGERCONDITION_ID,(uint8)WDG_E_PARAM_TIMEOUT);
        Valid = (Std_ReturnType)E_NOT_OK;
    }
    return Valid;
}
#endif /* WDG_VALIDATE_PARAMS == STD_ON */
#endif /* WDG_DIRECT_SERVICE == STD_OFF */

/**
 * @brief       This function initializes the hardware for Wdg and validates the settings.
 *
 * @param[in]   Status        the status of initial Wdg
 * @param[in]   Instance  Harwdware WDG instance.

 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * This function is called in IP HW
 * */
static inline Std_ReturnType Wdg_InitialHardware(const Wdg_Ipw_InstanceType Instance, const Std_ReturnType Status)
{
    Std_ReturnType Valid = (Std_ReturnType)Status;

    if ((Std_ReturnType)E_OK == Valid)
    {
        if (WDGIF_OFF_MODE == Wdg_apConfigPtr[Instance]->Wdg_DefaultMode)
        {
        #if (WDG_DISABLE_ALLOWED == (STD_ON))
            Valid = Wdg_Ipw_SetMode(Instance, Wdg_apConfigPtr[Instance]->Wdg_ModeSettings[Wdg_apConfigPtr[Instance]->Wdg_DefaultMode]->Wdg_Ipw_pConfig);
        #else
            Valid = (Std_ReturnType)E_NOT_OK;
        #endif
        }
        else
        {
            Valid = Wdg_Ipw_Init(Instance, Wdg_apConfigPtr[Instance]->Wdg_ModeSettings[Wdg_apConfigPtr[Instance]->Wdg_DefaultMode]->Wdg_Ipw_pConfig);
        }
    }
    return Valid;
}

/**
 * @brief       This function validates the hardware setting for wdg.
 *
 * @param[in]   Status        the status of initial Wdg
 * @param[in]   Instance  Harwdware WDG instance.

 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * This function is called in IP HW
 * */
static inline Std_ReturnType Wdg_VadidateHardwareSetting(const Wdg_Ipw_InstanceType Instance, const Std_ReturnType Status)
{
    Std_ReturnType Valid = (Std_ReturnType)Status;

    if ((Std_ReturnType)E_NOT_OK == Valid)
    {
        /* Hardware settings are not valid */
#if (WDG_VALIDATE_PARAMS == STD_ON)
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)WDG_INIT_ID, (uint8)WDG_E_PARAM_MODE);
#endif
    #if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Wdg_E_Mode_Failed.state)
        {
            (void) Dem_SetEventStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, DEM_EVENT_STATUS_FAILED);
        }
    #endif
        Wdg_apConfigPtr[Instance] = NULL_PTR;
    }
    else
    {
        /* Hardware settings are valid */
    #if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Wdg_E_Mode_Failed.state)
        {
            (void) Dem_SetEventStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, DEM_EVENT_STATUS_PASSED);
        }
    #endif
    }
    return Valid;
}

/**
 * @brief       This function initialize hardware for wdg.
 *
 * @param[in] Mode      One of the following statically configured modes:<br>
 *                      -# WDGIF_OFF_MODE,
 *                      -# WDGIF_SLOW_MODE,
 *                      -# WDGIF_FAST_MODE.
 * @param[in]   Instance  Harwdware WDG instance.

 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * This function is called in IP HW
 * */
static inline Std_ReturnType Wdg_DoChannelSetMode(const Wdg_Ipw_InstanceType Instance, const WdgIf_ModeType Mode)
{
    Std_ReturnType Valid = (Std_ReturnType)E_OK;

    if (WDGIF_OFF_MODE == Mode)
    {
    #if (WDG_DISABLE_ALLOWED == (STD_ON))
        if ((Std_ReturnType)E_OK == Wdg_Ipw_StopTimer(Instance))
        {
            Valid = Wdg_Ipw_SetMode(Instance, Wdg_apConfigPtr[Instance]->Wdg_ModeSettings[Mode]->Wdg_Ipw_pConfig);
        }
        else
        {
            Valid = (Std_ReturnType)E_NOT_OK;
        }
    #else
        Valid = (Std_ReturnType)E_NOT_OK;
    #endif
    }
    else
    {
        /* If the Wdg was in OFF Mode, the Wdg needs to be initialized again */
        if (WDGIF_OFF_MODE == Wdg_aePreviousMode[Instance])
        {
            if ((Std_ReturnType)E_OK == Wdg_Ipw_SetMode(Instance, Wdg_apConfigPtr[Instance]->Wdg_ModeSettings[Mode]->Wdg_Ipw_pConfig))
            {
                Valid = Wdg_Ipw_StartTimer(Instance);
            }
            else
            {
                Valid = (Std_ReturnType)E_NOT_OK;
            }
        }
        else
        {
            Valid = Wdg_Ipw_SetMode(Instance, Wdg_apConfigPtr[Instance]->Wdg_ModeSettings[Mode]->Wdg_Ipw_pConfig);
        }
    }
    return Valid;
}

/**
 * @brief       This function validates the channel mode setting for wdg.
 *
 * @param[in]   Status        the status of initial Wdg
 * @param[in] Mode      One of the following statically configured modes:<br>
 *                      -# WDGIF_OFF_MODE,
 *                      -# WDGIF_SLOW_MODE,
 *                      -# WDGIF_FAST_MODE.
 * @param[in]   Instance  Harwdware WDG instance.

 * @return      The validity of the function call
 * @retval      E_OK      The function call is valid
 * @retval      E_NOT_OK The function call is invalid
 *
 * This function is called in IP HW
 * */
static inline Std_ReturnType Wdg_VadidateDoChannelSetMode(const Wdg_Ipw_InstanceType Instance, const WdgIf_ModeType Mode, const Std_ReturnType Status)
{
    Std_ReturnType Valid = (Std_ReturnType)Status;

#if (WDG_DIRECT_SERVICE == STD_OFF)
    Gpt_ValueType ElapsedTime;
    uint32 ValueTempU32;
#endif

    if ((Std_ReturnType)E_NOT_OK == Valid)
    {
        /* Hardware settings are not valid */

#if (WDG_VALIDATE_PARAMS == STD_ON)
        (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)WDG_SETMODE_ID, (uint8)WDG_E_PARAM_MODE);
#endif

    #if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Wdg_E_Mode_Failed.state)
        {
            (void) Dem_SetEventStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, DEM_EVENT_STATUS_FAILED);
        }
    #endif
    }
    else
    {
        /* Hardware settings are valid */
        #if (WDG_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == Wdg_E_Mode_Failed.state)
            {
                (void) Dem_SetEventStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, DEM_EVENT_STATUS_PASSED);
            }
        #endif

#if (WDG_DIRECT_SERVICE == STD_OFF)
        Gpt_StopTimer(Wdg_apConfigPtr[Instance]->Wdg_TimerChannel);
        ElapsedTime =  Gpt_GetTimeElapsed(Wdg_apConfigPtr[Instance]->Wdg_TimerChannel);

        /* update timeout */
        SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_03();
        if (Wdg_au32Timeout[Instance] < ElapsedTime)
        {
            ValueTempU32 = 0;
        }
        else
        {
            ValueTempU32 = Wdg_au32Timeout[Instance] - ElapsedTime;
        }
        Wdg_au32Timeout[Instance] =  ValueTempU32;
        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_03();
        Wdg_au32GptPeriod[Instance] = Wdg_apConfigPtr[Instance]->Wdg_ModeSettings[Mode]->Wdg_u32TimerTriggeringPeriod;

        /* Start the timer only if the mode is not off mode*/
        if (WDGIF_OFF_MODE != Mode)
        {
            Gpt_StartTimer(Wdg_apConfigPtr[Instance]->Wdg_TimerChannel,Wdg_au32GptPeriod[Instance]);
        }
#endif
        Valid = (Std_ReturnType)E_OK;

        /* Remember the last Wdg Mode */
        SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_04();
        Wdg_aePreviousMode[Instance] = Mode;
        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_04();
    }
    return Valid;
}

#if (WDG_DIRECT_SERVICE == STD_OFF)
/**
 * @brief       This function starts the Gpt channel used for servicing the Wdh.
 *
 * @param[in]   Instance  Harwdware WDG instance.
 *
 * */
static inline void Wdg_ChannelStartGpt(const Wdg_Ipw_InstanceType Instance)
{
    Gpt_StopTimer(Wdg_apConfigPtr[Instance]->Wdg_TimerChannel);

    Wdg_au32GptPeriod[Instance] = Wdg_apConfigPtr[Instance]->Wdg_ModeSettings[Wdg_apConfigPtr[Instance]->Wdg_DefaultMode]->Wdg_u32TimerTriggeringPeriod;

    Gpt_EnableNotification(Wdg_apConfigPtr[Instance]->Wdg_TimerChannel);

    /* start the timer channel only if the mode is not off mode */
    if (WDGIF_OFF_MODE != Wdg_apConfigPtr[Instance]->Wdg_DefaultMode)
    {
        Gpt_StartTimer(Wdg_apConfigPtr[Instance]->Wdg_TimerChannel, Wdg_au32GptPeriod[Instance]);
    }
    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_01();
    Wdg_au32Timeout[Instance] = (uint32)(Wdg_au16CfgInitialTimeout[Instance]*(Wdg_apConfigPtr[Instance]->Wdg_u32TriggerSourceClock));
    SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_01();
}
#endif /* (WDG_DIRECT_SERVICE == STD_OFF) */

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief   This function initializes the WDG module.
* @details The @p Wdg_Init function shall initialize the Wdg module and the
*          watchdog hardware, i.e. it shall set the default watchdog mode and
*          timeout period as provided in the configuration set.
*
* @param[in]   ConfigPtr     Pointer to configuration set.
* @param[in]   Instance  Harwdware WDG instance.
*
* @implements      Wdg_ChannelInit_Activity
*/
void Wdg_ChannelInit(const Wdg_Ipw_InstanceType Instance, const Wdg_ConfigType *ConfigPtr)
{
    Std_ReturnType Valid;

#if (WDG_MULTICORE_ENABLED == STD_ON)
    volatile uint32 CoreID;

    CoreID = (uint32) Wdg_GetCoreID();
    Valid = Wdg_ChannelValidateCoreUsed(CoreID, Instance,WDG_INIT_ID,WDG_E_PARAM_CONFIG);
    if ((Std_ReturnType)E_OK == Valid)
    {
#endif
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
        Valid = Wdg_ChannelValidateGlobalCall(WDG_INIT_ID,Instance);
        if ((Std_ReturnType)E_OK == Valid)
        {
#endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */

#if (WDG_VALIDATE_PARAMS == STD_ON)
            Valid = Wdg_ValidatePtrInit(ConfigPtr, Instance);
            if ((Std_ReturnType)E_OK == Valid)
            {
#else
                (void)ConfigPtr;
#endif

#if (WDG_PRECOMPILE_SUPPORT == STD_ON)
                Wdg_apConfigPtr[Instance] = Wdg_Config[Instance];
                (void)ConfigPtr;
#else
                Wdg_apConfigPtr[Instance] = ConfigPtr;
#endif /*(WDG_PRECOMPILE_SUPPORT == STD_ON)*/

#if (WDG_DIRECT_SERVICE == STD_OFF)
#if (WDG_VALIDATE_PARAMS == STD_ON)
                Wdg_aeCurrentMode[Instance] = Wdg_apConfigPtr[Instance]->Wdg_DefaultMode;
#endif /*(WDG_VALIDATE_PARAMS == STD_ON)*/
                /* Wdg needs to have been in OFF Mode in order to be initialized */
                if ((WDGIF_OFF_MODE == Wdg_aePreviousMode[Instance]) && (Wdg_au16CfgInitialTimeout[Instance] != (uint16)0U))
                {
#else
                if (WDGIF_OFF_MODE == Wdg_aePreviousMode[Instance])
                {
#endif
                    Valid = Wdg_ChannelValidateMode(Wdg_apConfigPtr[Instance]->Wdg_DefaultMode, WDG_INIT_ID, WDG_E_PARAM_MODE, Instance);
                }
                else
                {
                    Valid = (Std_ReturnType)E_NOT_OK;
                }

                /* Try to initialize the WDG hardware */
                Valid = Wdg_InitialHardware(Instance, Valid);

                /* Validate harware setting */
                Valid = Wdg_VadidateHardwareSetting(Instance, Valid);

                if ((Std_ReturnType)E_OK == Valid)
                {
                    /* Hardware settings are valid */
#if (WDG_DIRECT_SERVICE == STD_OFF)
                    Wdg_ChannelStartGpt(Instance);
#endif
                    /* Remember the last Wdg Mode */
                    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_02();
                    Wdg_aePreviousMode[Instance] =  Wdg_apConfigPtr[Instance]->Wdg_DefaultMode;
                    SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_02();
                }

#if (WDG_VALIDATE_PARAMS == STD_ON)
            }
#endif
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
        }
        Wdg_ChannelEndValidateGlobalCall(Valid, Instance);
#endif
#if (WDG_MULTICORE_ENABLED == STD_ON)
    }
#endif
}

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
* @param[in]   Instance  Harwdware WDG instance.
*
* @return              Std_ReturnType.
* @retval  E_OK        Mode switch executed completely and successfully.
* @retval  E_NOT_OK    The mode switch encountered errors.
*
* @implements      Wdg_ChannelSetMode_Activity
*/
Std_ReturnType Wdg_ChannelSetMode(const Wdg_Ipw_InstanceType Instance, WdgIf_ModeType Mode)
{
    Std_ReturnType Ret = (Std_ReturnType)E_NOT_OK;
    Std_ReturnType Valid;

#if (WDG_MULTICORE_ENABLED == STD_ON)
    volatile uint32 CoreID;

    CoreID = (uint32) Wdg_GetCoreID();
    Valid = Wdg_ChannelValidateCoreUsed(CoreID, Instance,WDG_SETMODE_ID,WDG_E_PARAM_CONFIG);
    if ((Std_ReturnType)E_OK == Valid)
    {
#endif
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
        Valid = Wdg_ChannelValidateGlobalCall(WDG_SETMODE_ID, Instance);
        if ((Std_ReturnType)E_OK == Valid)
        {
#endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */
            MCAL_FAULT_INJECTION_POINT(T_WDG_INJ_START);
            Valid = Wdg_ChannelValidateMode(Mode, WDG_SETMODE_ID, WDG_E_PARAM_MODE, Instance);
            if ((Std_ReturnType)E_OK == Valid)
            {
#if (WDG_DIRECT_SERVICE == STD_OFF)
#if (WDG_VALIDATE_PARAMS == STD_ON)
                Wdg_aeCurrentMode[Instance] = Mode;
#endif /*(WDG_VALIDATE_PARAMS == STD_ON)*/
#endif /*(WDG_DIRECT_SERVICE == STD_OFF)*/

                Valid = Wdg_DoChannelSetMode(Instance, Mode);
                Ret = Wdg_VadidateDoChannelSetMode(Instance, Mode, Valid);

            }
#if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
        }
        Wdg_ChannelEndValidateGlobalCall(Valid, Instance);
#endif
#if (WDG_MULTICORE_ENABLED == STD_ON)
    }
#endif
    MCAL_FAULT_INJECTION_POINT(T_WDG_INJ_STOP);
    return Ret;
}

#if (WDG_DIRECT_SERVICE == STD_OFF)
    /**
    * @brief   Reset the watchdog timeout counter according to the timeout value passed.
    * @details
    *
    * @param[in]   Timeout value (milliseconds) for setting the trigger counter.
    * @param[in]   Instance  Harwdware WDG instance.
    *
    * @implements      Wdg_ChannelSetTriggerCondition_Activity
    */
    void Wdg_ChannelSetTriggerCondition(const Wdg_Ipw_InstanceType Instance, uint16 Timeout)
    {
        Gpt_ValueType ElapsedTime = (Gpt_ValueType)0;

    #if ((WDG_VALIDATE_GLOBAL_CALL == STD_ON) ||  (WDG_MULTICORE_ENABLED == STD_ON))
        Std_ReturnType Valid;
    #endif

    #if (WDG_MULTICORE_ENABLED == STD_ON)
        volatile uint32 CoreID;

        CoreID = (uint32) Wdg_GetCoreID();
        Valid = Wdg_ChannelValidateCoreUsed(CoreID, Instance,WDG_SETTRIGGERCONDITION_ID,WDG_E_PARAM_CONFIG);
        if ((Std_ReturnType)E_OK == Valid)
        {
    #endif
    #if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
            Valid = Wdg_ChannelValidateTrigerCondition(Instance);
            if ((Std_ReturnType)E_OK == Valid)
            {
    #endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */
    #if (WDG_VALIDATE_PARAMS == STD_ON)
                Valid = Wdg_ValidateTimeout(Timeout, Instance);
                if ((Std_ReturnType)E_OK == Valid)
                {
    #endif

                    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_05();

                    ElapsedTime =  Gpt_GetTimeElapsed(Wdg_apConfigPtr[Instance]->Wdg_TimerChannel);

                    if (((Gpt_ValueType)(ElapsedTime) > Wdg_au32Timeout[Instance]) || ((uint16)0 == Timeout))
                    {
                        Wdg_au32Timeout[Instance] = (uint32)0;
                        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_05();

                        Gpt_StopTimer(Wdg_apConfigPtr[Instance]->Wdg_TimerChannel);
                    }
                    else
                    {
                        Wdg_au32Timeout[Instance] = (uint32)(Timeout * Wdg_apConfigPtr[Instance]->Wdg_u32TriggerSourceClock) + ElapsedTime;
                        SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_05();
                    }
    #if (WDG_VALIDATE_PARAMS == STD_ON)
                }
    #endif
    #if (WDG_VALIDATE_GLOBAL_CALL == STD_ON)
            }
    #endif /* (WDG_VALIDATE_GLOBAL_CALL == STD_ON */
    #if (WDG_MULTICORE_ENABLED == STD_ON)
        }
    #endif /* (WDG_MULTICORE_ENABLED == STD_ON */
    }
#endif /* WDG_DIRECT_SERVICE */


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
* @pre    This ISR is only required if the WDG_VERSION_INFO_API has to be
*         equal STD_ON.
*
* @param[in,out] VersionInfo   Pointer to where to store the version
*                              information of this module.
* @param[in]     Instance  Harwdware instance.
*
*
* @implements      Wdg_ChannelGetVersionInfo_Activity
*/
void Wdg_ChannelGetVersionInfo
                    (const Wdg_Ipw_InstanceType Instance,
                     Std_VersionInfoType *VersionInfo
                    )
{
#if (WDG_VALIDATE_PARAMS == STD_ON)
    Std_ReturnType Valid;
#endif

    (void)Instance;

#if (WDG_VALIDATE_PARAMS == STD_ON)
    Valid = Wdg_ValidatePtrVersion(VersionInfo, Instance);

    if ((Std_ReturnType)E_OK == Valid)
    {
#endif /*(WDG_VALIDATE_PARAMS == STD_ON)*/
        (VersionInfo)->vendorID         = (uint16)WDG_CHANNEL_VENDOR_ID;
        (VersionInfo)->moduleID         = (uint8)WDG_CHANNEL_MODULE_ID;
        (VersionInfo)->sw_major_version = (uint8)WDG_CHANNEL_SW_MAJOR_VERSION;
        (VersionInfo)->sw_minor_version = (uint8)WDG_CHANNEL_SW_MINOR_VERSION;
        (VersionInfo)->sw_patch_version = (uint8)WDG_CHANNEL_SW_PATCH_VERSION;
#if (WDG_VALIDATE_PARAMS == STD_ON)
    }
#endif /*(WDG_VALIDATE_PARAMS == STD_ON)*/

}
#endif /* WDG_VERSION_INFO_API == STD_ON */

#if (WDG_DIRECT_SERVICE == STD_ON)
    /**
    * @brief   Perform a wdg channel service.
    * @details
    *
    * @param
    *
    * @implements      Wdg_ChannelService_Activity
    *
    **/
void Wdg_ChannelService(const Wdg_Ipw_InstanceType Instance)
{
    Wdg_Ipw_Service(Instance);
}
#endif

#if (WDG_DISABLE_ALLOWED == STD_ON)
#if (WDG_CLEAR_RESET_REQUEST == STD_ON)
    /**
    * @brief   Clear a reset request occurring after Watchdog timeout is reached.
    * @details
    *
    * @param
    *
    * @implements      Wdg_ChannelClearResetRequest_Activity
    *
    **/
void  Wdg_ChannelClearResetRequest(const Wdg_Ipw_InstanceType Instance)
{
    Wdg_Ipw_StatusType RetClrReq = WDG_IPW_STATUS_SUCCESS;

    RetClrReq = Wdg_Ipw_ClearResetRequest(Instance);

    /* Disable the Wdg after a reset request is cleared so that internal logic is not affected */
    if (WDG_IPW_STATUS_SUCCESS == RetClrReq)
    {
#if (WDG_VALIDATE_PARAMS == STD_ON)
        if ((Std_ReturnType)E_NOT_OK == Wdg_Ipw_Deinit(Instance))
        {
             /* Wdg is Hard Locked. Avoid calling ClearResetRequest when Hard Lock is on */
            (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)WDG_CLEARRESETREQUEST_ID, (uint8)WDG_E_DRIVER_STATE);
        }
        else
        {
            /*Do nothing */
        }
#else
        (void)Wdg_Ipw_Deinit(Instance);
#endif /* (WDG_VALIDATE_PARAMS == STD_ON) */
    }
    else
    {
        if (WDG_IPW_STATUS_TIMEOUT == RetClrReq)
        {
            /* Raise a runtime det for Osif timeout expired in while the reset request has not been cleared */
            (void)Det_ReportRuntimeError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)WDG_CLEARRESETREQUEST_ID, (uint8)WDG_E_STATUS_TIMEOUT);
        }
#if (WDG_VALIDATE_PARAMS == STD_ON)
        else
        {
            /* Raise a det when clearing reset request failed */
            (void)Det_ReportError((uint16)WDG_CHANNEL_MODULE_ID, (uint8)Instance, (uint8)WDG_CLEARRESETREQUEST_ID, (uint8)WDG_E_DRIVER_STATE);
        }
#endif /* (WDG_VALIDATE_PARAMS == STD_ON) */
    }

    SchM_Enter_Wdg_WDG_EXCLUSIVE_AREA_08();
    Wdg_aePreviousMode[Instance] = WDGIF_OFF_MODE;
    SchM_Exit_Wdg_WDG_EXCLUSIVE_AREA_08();
}
#endif
#endif


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
