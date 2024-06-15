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


#ifndef WDG_IPW_TYPES_H
#define WDG_IPW_TYPES_H

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
#include "Wdg_Ipw_Cfg_Defines.h"

#if (SWT_IP_USED == STD_ON)
     #include "Swt_Ip_Types.h"
#endif /*(SWT_IP_USED == STD_ON)*/

#if (AEWDOG_IP_USED == STD_ON)
     #include "AeWdog_Ip_Types.h"
#endif /*(AEWDOG_IP_USED == STD_ON)*/
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define WDG_IPW_TYPES_VENDOR_ID                    43
#define WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION     7
#define WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION  0
#define WDG_IPW_TYPES_SW_MAJOR_VERSION             3
#define WDG_IPW_TYPES_SW_MINOR_VERSION             0
#define WDG_IPW_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_Ipw_Cfg_Defines header file are of the same vendor */
#if (WDG_IPW_TYPES_VENDOR_ID != WDG_IPW_CFG_DEFINES_VENDOR_ID)
#error "Wdg_Ipw_Types.h and Wdg_Ipw_Cfg_Defines.h have different vendor ids"
#endif

/* Check if current file and Wdg_Ipw_Cfg_Defines header file are of the same Autosar version */
#if ((WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     != WDG_IPW_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION     != WDG_IPW_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != WDG_IPW_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Wdg_Ipw_Types.h and Wdg_Ipw_Cfg_Defines.h are different"
#endif

/* Check if current file and Wdg_Ipw_Cfg_Defines header file are of the same software version */
#if ((WDG_IPW_TYPES_SW_MAJOR_VERSION != WDG_IPW_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (WDG_IPW_TYPES_SW_MINOR_VERSION != WDG_IPW_CFG_DEFINES_SW_MINOR_VERSION) || \
     (WDG_IPW_TYPES_SW_PATCH_VERSION != WDG_IPW_CFG_DEFINES_SW_PATCH_VERSION))
#error "Software Version Numbers of Wdg_Ipw_Types.h and Wdg_Ipw_Cfg_Defines.h are different"
#endif

#if (SWT_IP_USED == STD_ON)
     /* Check if current file and Swt_Ip_Types header file are of the same vendor */
     #if (WDG_IPW_TYPES_VENDOR_ID != SWT_IP_TYPES_VENDOR_ID)
     #error "Wdg_Ipw_Types.h and Swt_Ip_Types.h have different vendor ids"
     #endif

     /* Check if current file and Swt_Ip_Types header file are of the same Autosar version */
     #if ((WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     != SWT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
          (WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION     != SWT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
          (WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != SWT_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Wdg_Ipw_Types.h and Swt_Ip_Types.h are different"
     #endif

     /* Check if current file and Swt_Ip_Types header file are of the same software version */
     #if ((WDG_IPW_TYPES_SW_MAJOR_VERSION != SWT_IP_TYPES_SW_MAJOR_VERSION) || \
          (WDG_IPW_TYPES_SW_MINOR_VERSION != SWT_IP_TYPES_SW_MINOR_VERSION) || \
          (WDG_IPW_TYPES_SW_PATCH_VERSION != SWT_IP_TYPES_SW_PATCH_VERSION))
     #error "Software Version Numbers of Wdg_Ipw_Types.h and Swt_Ip_Types.h are different"
     #endif
#endif /*(SWT_IP_USED == STD_ON)*/

#if (AEWDOG_IP_USED == STD_ON)
     /* Check if current file and AeWdog_Ip_Types header file are of the same vendor */
     #if (WDG_IPW_TYPES_VENDOR_ID != AEWDOG_IP_TYPES_VENDOR_ID)
     #error "Wdg_Ipw_Types.h and AeWdog_Ip_Types.h have different vendor ids"
     #endif

     /* Check if current file and AeWdog_Ip_Types header file are of the same Autosar version */
     #if ((WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION     != AEWDOG_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
          (WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION     != AEWDOG_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
          (WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION  != AEWDOG_IP_TYPES_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of Wdg_Ipw_Types.h and AeWdog_Ip_Types.h are different"
     #endif

     /* Check if current file and AeWdog_Ip_Types header file are of the same software version */
     #if ((WDG_IPW_TYPES_SW_MAJOR_VERSION != AEWDOG_IP_TYPES_SW_MAJOR_VERSION) || \
          (WDG_IPW_TYPES_SW_MINOR_VERSION != AEWDOG_IP_TYPES_SW_MINOR_VERSION) || \
          (WDG_IPW_TYPES_SW_PATCH_VERSION != AEWDOG_IP_TYPES_SW_PATCH_VERSION))
     #error "Software Version Numbers of Wdg_Ipw_Types.h and AeWdog_Ip_Types.h are different"
     #endif
#endif /*(AEWDOG_IP_USED == STD_ON)*/
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
* @brief          Wdg_IPW_ConfigType.
* @details        Contains the information related to the hardware setup for SWT
*/
typedef enum
{
    WDG_IPW_INSTANCE0 = 0x0U,
    WDG_IPW_INSTANCE1 = 0x1U,
    WDG_IPW_INSTANCE2 = 0x2U,
    WDG_IPW_INSTANCE3 = 0x3U,
    WDG_IPW_INSTANCE4 = 0x4U,
    WDG_IPW_INSTANCE5 = 0x5U,
    WDG_IPW_INSTANCE6 = 0x6U,
    WDG_IPW_INSTANCE7 = 0x7U,
    WDG_IPW_INSTANCE8 = 0x8U,
    WDG_IPW_INSTANCE9 = 0x9U,
    WDG_IPW_INSTANCE10 = 0xAU
} Wdg_Ipw_InstanceType;

/**
* @brief          Wdg_Ipw_IpType.
* @details        Contains the Ip types available for Wdg.
*/
typedef enum
{
    WDG_IPW_SWT_IP     = 0x00,
    WDG_IPW_AEWDOG_IP  = 0x01,
    WDG_IPW_UNINIT_IP  = 0x02
} Wdg_Ipw_IpType;

#if (WDG_IPW_DEINIT == STD_ON)
#if (WDG_IPW_CLEAR_RESET_REQUEST == STD_ON)
/** @brief       Enum defining the possible type values for WDG_IPW API
*/
typedef enum
{
    WDG_IPW_STATUS_SUCCESS   = 0x00,
    WDG_IPW_STATUS_ERROR     = 0x01,
    WDG_IPW_STATUS_TIMEOUT   = 0x02
} Wdg_Ipw_StatusType;

#endif
#endif

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef struct 
{
    const Wdg_Ipw_IpType eWdgIp;
#if (SWT_IP_USED == STD_ON)
    const Swt_Ip_ConfigType *aSwtConfig;
#endif /*(SWT_IP_USED == STD_ON)*/
#if (AEWDOG_IP_USED == STD_ON)
    const AeWdog_Ip_ConfigType *pAeWdogConfig;
#endif /*(AEWDOG_IP_USED == STD_ON)*/
} Wdg_Ipw_ConfigType;

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

#endif /*WDG_IPW_TYPES_H*/

