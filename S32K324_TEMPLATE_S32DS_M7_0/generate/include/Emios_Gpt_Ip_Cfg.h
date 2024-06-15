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

#ifndef EMIOS_GPT_IP_CFG_H
#define EMIOS_GPT_IP_CFG_H

/**
*   @file           Emios_Gpt_Ip_Cfg.h
*
*   @addtogroup     emios_ip Emios IPL
*
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
#include "Emios_Gpt_Ip_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_GPT_IP_VENDOR_ID_CFG                    43
#define EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG     4
#define EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG     7
#define EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG  0
#define EMIOS_GPT_IP_SW_MAJOR_VERSION_CFG             3
#define EMIOS_GPT_IP_SW_MINOR_VERSION_CFG             0
#define EMIOS_GPT_IP_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_GPT_IP_VENDOR_ID_CFG != EMIOS_GPT_IP_VENDOR_ID_PBCFG_H)
    #error "Emios_Gpt_Ip_Cfg.h and Emios_Gpt_Ip_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG != EMIOS_GPT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG != EMIOS_GPT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG != EMIOS_GPT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of Emios_Gpt_Ip_Cfg.h and Emios_Gpt_Ip_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((EMIOS_GPT_IP_SW_MAJOR_VERSION_CFG != EMIOS_GPT_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (EMIOS_GPT_IP_SW_MINOR_VERSION_CFG != EMIOS_GPT_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (EMIOS_GPT_IP_SW_PATCH_VERSION_CFG != EMIOS_GPT_IP_SW_PATCH_VERSION_PBCFG_H) \
    )
    #error "Software Version Numbers of Emios_Gpt_Ip_Cfg.h and Emios_Gpt_Ip_PBcfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   Dev error detect switch EMIOS_GPT_IP_DEV_ERROR_DETECT
* @details On/Off EMIOS_GPT_IP_DEV_ERROR_DETECT
*/
#define EMIOS_GPT_IP_DEV_ERROR_DETECT (STD_OFF)

/*================================================================================================*/
/**
* @brief    EMIOS_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE switch
* @details  Enable/disable support for changing timeout value during timer running
*/
#define EMIOS_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE     (STD_OFF)
/**
* @brief    EMIOS_GPT_IP_PREDEFTIMER_FUNCTIONALITY_API switch
* @details  Enable/disable GPT_PREDEFTIMER_FUNCTIONALITY_API.
*/
#define EMIOS_GPT_IP_PREDEFTIMER_FUNCTIONALITY_API     (STD_ON)
/*================================================================================================*/
/**
* @brief    EMIOS_GPT_IP_ENABLE_USER_MODE_SUPPORT switch
* @details  Enable/disable support usermode.If this parameter has been configured to 'TRUE' the GPT driver code can be executed from both supervisor and user mode.
*/
#define EMIOS_GPT_IP_ENABLE_USER_MODE_SUPPORT    (STD_OFF)
/*================================================================================================*/
/**
* @brief        EMIOS_GPT_MAX_COUNTER.
* @details      max value of counter register.
*/
#define EMIOS_GPT_MAX_COUNTER         (65535U)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

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
#endif  /* EMIOS_GPT_IP_CFG_H */
