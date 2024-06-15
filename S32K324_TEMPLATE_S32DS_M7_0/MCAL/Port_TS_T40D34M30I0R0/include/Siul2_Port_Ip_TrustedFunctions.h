/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : SIUL2
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

#ifndef SIUL2_PORT_IP_TRUSTEDFUNCTIONS_H
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_H

/**
*   @file Siul2_Port_Ip_TrustedFunctions.h
*
*   @addtogroup Port_IPL Port IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

#include "Std_Types.h"
#include "Siul2_Port_Ip_Defines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H                       43
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H        4
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H        7
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H     0
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H                3
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H                0
#define SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Siul2_Port_Ip_TrustedFunctions.h and StandardTypes.h file are of the same Autosar version */
    #if ((SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Siul2_Port_Ip_TrustedFunctions.h and StandardTypes.h are different"
    #endif
#endif

/* Check if the files Siul2_Port_Ip_TrustedFunctions.h and Siul2_Port_Ip_Defines.h are of the same version */
#if (SIUL2_PORT_IP_TRUSTEDFUNCTIONS_VENDOR_ID_H != SIUL2_PORT_IP_DEFINES_VENDOR_ID_H)
    #error "Siul2_Port_Ip_TrustedFunctions.h and Siul2_Port_Ip_Defines.h have different vendor ids"
#endif
/* Check if Siul2_Port_Ip_TrustedFunctions.h and Siul2_Port_Ip_Defines.h are of the same Autosar version */
#if ((SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION_H    != SIUL2_PORT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION_H    != SIUL2_PORT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION_H != SIUL2_PORT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Siul2_Port_Ip_TrustedFunctions.h and Siul2_Port_Ip_Defines.h are different"
#endif
/* Check if Siul2_Port_Ip_TrustedFunctions.h and Siul2_Port_Ip_Defines.h are of the same Software version */
#if ((SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION_H != SIUL2_PORT_IP_DEFINES_SW_MAJOR_VERSION_H) || \
     (SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION_H != SIUL2_PORT_IP_DEFINES_SW_MINOR_VERSION_H) || \
     (SIUL2_PORT_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION_H != SIUL2_PORT_IP_DEFINES_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Siul2_Port_Ip_TrustedFunctions.h and Siul2_Port_Ip_Defines.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define PORT_START_SEC_CODE
#include "Port_MemMap.h"


#if (defined(MCAL_ENABLE_USER_MODE_SUPPORT) && defined(PORT_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT))
#if (defined(MCAL_SIUL2_REG_PROT_AVAILABLE) && (STD_ON == MCAL_SIUL2_REG_PROT_AVAILABLE))
/**
* @brief        Enables SIUL2 registers writing in User Mode by configuring REG_PROT
*
* @details      Sets the UAA (User Access Allowed) bit of the SIUL2 IP allowing SIUL2 registers writing in User Mode
*
* @param        none
* @retval       none
*
* @pre          The user mode is enabled
*
*/
extern void Siul2_Port_Ip_SetUserAccessAllowed(void);
#endif /* (defined(MCAL_SIUL2_REG_PROT_AVAILABLE) && (STD_ON == MCAL_SIUL2_REG_PROT_AVAILABLE)) */
#endif /* (defined(MCAL_ENABLE_USER_MODE_SUPPORT) && defined(PORT_ENABLE_USER_MODE_SUPPORT) && (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT)) */

#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SIUL2_PORT_IP_TRUSTEDFUNCTIONS_H */
