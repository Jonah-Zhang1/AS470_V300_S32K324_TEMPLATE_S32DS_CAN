/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Stm_Pit_Rtc_Emios
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
*   @file  Gpt_Ipw_PBcfg.c
*
*   @internal
*   @addtogroup gpt gpt_ipw
*
*   @{
*/
/*==================================================================================================
 *                              GENERATION MACRO DEFINTION
 *================================================================================================*/

 /*Gpt_Ipw_PluginMacros.m*/
/** @} */


#ifdef __cplusplus
extern "C"{
#endif

 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Gpt_Ipw_PBcfg.h"
#include "Pit_Ip_PBcfg.h"
#include "Stm_Ip_PBcfg.h"
#include "Rtc_Ip_PBcfg.h"
#include "Emios_Gpt_Ip_PBcfg.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define GPT_IPW_VENDOR_ID_PBCFG_C                    43
#define GPT_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_C     4
#define GPT_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_C     7
#define GPT_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_C  0
#define GPT_IPW_SW_MAJOR_VERSION_PBCFG_C             3
#define GPT_IPW_SW_MINOR_VERSION_PBCFG_C             0
#define GPT_IPW_SW_PATCH_VERSION_PBCFG_C             0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#if (GPT_IPW_VENDOR_ID_PBCFG_H != GPT_IPW_VENDOR_ID_PBCFG_C)
    #error "Gpt_Ipw_PBcfg.h and Gpt_Ipw_PBcfg.c have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_H != GPT_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_C) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_H != GPT_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_C) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_H != GPT_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_C) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_PBcfg.h and Gpt_Ipw_PBcfg.c are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_PBCFG_H != GPT_IPW_SW_MAJOR_VERSION_PBCFG_C) || \
     (GPT_IPW_SW_MINOR_VERSION_PBCFG_H != GPT_IPW_SW_MINOR_VERSION_PBCFG_C) || \
     (GPT_IPW_SW_PATCH_VERSION_PBCFG_H != GPT_IPW_SW_PATCH_VERSION_PBCFG_C) \
    )
    #error "Software Version Numbers of Gpt_Ipw_PBcfg.h and Gpt_Ipw_PBcfg.c are different"
#endif

#if (GPT_IPW_VENDOR_ID_PBCFG_C != PIT_IP_VENDOR_ID_PBCFG_H)
    #error "Gpt_Ipw_PBcfg.c and Pit_Ip_PBcfg.c have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_C != PIT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_C != PIT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_C != PIT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_PBcfg.c and Pit_Ip_PBcfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_PBCFG_C != PIT_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (GPT_IPW_SW_MINOR_VERSION_PBCFG_C != PIT_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (GPT_IPW_SW_PATCH_VERSION_PBCFG_C != PIT_IP_SW_PATCH_VERSION_PBCFG_H) \
    )
    #error "Software Version Numbers of Gpt_Ipw_PBcfg.c and Pit_Ip_PBcfg.h are different"
#endif

#if (GPT_IPW_VENDOR_ID_PBCFG_C != STM_IP_VENDOR_ID_PBCFG_H)
    #error "Gpt_Ipw_PBcfg.c and Stm_Ip_PBcfg.c have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_C != STM_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_C != STM_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_C != STM_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_PBcfg.c and Stm_Ip_PBcfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_PBCFG_C != STM_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (GPT_IPW_SW_MINOR_VERSION_PBCFG_C != STM_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (GPT_IPW_SW_PATCH_VERSION_PBCFG_C != STM_IP_SW_PATCH_VERSION_PBCFG_H) \
    )
    #error "Software Version Numbers of Gpt_Ipw_PBcfg.c and Stm_Ip_PBcfg.h are different"
#endif

#if (GPT_IPW_VENDOR_ID_PBCFG_C != RTC_IP_VENDOR_ID_PBCFG_H)
    #error "Gpt_Ipw_PBcfg.c and Rtc_Ip_PBcfg.c have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_C != RTC_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_C != RTC_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_C != RTC_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_PBcfg.c and Rtc_Ip_PBcfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_PBCFG_C != RTC_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (GPT_IPW_SW_MINOR_VERSION_PBCFG_C != RTC_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (GPT_IPW_SW_PATCH_VERSION_PBCFG_C != RTC_IP_SW_PATCH_VERSION_PBCFG_H) \
    )
    #error "Software Version Numbers of Gpt_Ipw_PBcfg.c and Rtc_Ip_PBcfg.h are different"
#endif

#if (GPT_IPW_VENDOR_ID_PBCFG_C != EMIOS_GPT_IP_VENDOR_ID_PBCFG_H)
    #error "Gpt_Ipw_PBcfg.c and Emios_Gpt_Ip_PBcfg.c have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_IPW_AR_RELEASE_MAJOR_VERSION_PBCFG_C != EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_MINOR_VERSION_PBCFG_C != EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (GPT_IPW_AR_RELEASE_REVISION_VERSION_PBCFG_C != EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_PBcfg.c and Emios_Gpt_Ip_PBcfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_IPW_SW_MAJOR_VERSION_PBCFG_C != EMIOS_GPT_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (GPT_IPW_SW_MINOR_VERSION_PBCFG_C != EMIOS_GPT_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (GPT_IPW_SW_PATCH_VERSION_PBCFG_C != EMIOS_GPT_IP_SW_PATCH_VERSION_PBCFG_H) \
    )
    #error "Software Version Numbers of Gpt_Ipw_PBcfg.c and Emios_Gpt_Ip_PBcfg.h are different"
#endif
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/

 /*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

Gpt_Ipw_HwInstanceConfigType Gpt_Ipw_HwInstanceConfig_PB[2U]=
{
    {
        /** @brief IP type  */
        GPT_PIT_MODULE,
        /** @brief IP instance */
        0U,
        /** @brief IP instance pointer */
        {
            &PIT_0_InitConfig_PB,
            NULL_PTR
        }
    }
,
    {
        /** @brief IP type  */
        GPT_STM_MODULE,
        /** @brief IP instance */
        0U,
        /** @brief IP instance pointer */
        {
            NULL_PTR,
            &STM_0_InitConfig_PB
        }
    }
};


/*channels*/

/** 
 * @brief   Gpt channels IP related configuration array
 */
Gpt_Ipw_HwChannelConfigType Gpt_Ipw_ChannelConfig_PB[2U] =
{
    /** @brief GptChannelConfiguration_PIT0 */
    {
        /** @brief IP type  */
        GPT_PIT_MODULE,
        /** @brief IP instance */
        0U,
        /** @brief IP channel */
        0U,
        /** @brief IP channel pointer */
        {
            &PIT_0_ChannelConfig_PB[0U],
            NULL_PTR,
            NULL_PTR,
            NULL_PTR
        }
    }
    ,
    /** @brief GptChannelConfiguration_STM0 */
    {
        /** @brief IP type  */
        GPT_STM_MODULE,
        /** @brief IP instance */
        0U,
        /** @brief IP channel */
        0U,
        /** @brief IP instance config pointer */
        {
            NULL_PTR,
            &STM_0_ChannelConfig_PB[0U],
            NULL_PTR,
            NULL_PTR
        }
    }

};

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/


/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/


/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif/*GPT_IPW_PBCFG_C*/

/** @} */
