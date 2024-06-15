/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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

#ifndef AXBS_IP_H
#define AXBS_IP_H

/**
*   @file Axbs_Ip.h
*
*   @addtogroup AXBS_IP AXBS IPV Driver
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
#include "Axbs_Ip_Types.h"
#include "Axbs_Ip_Cfg.h"
#include "Axbs_Ip_Device_Registers.h"

#ifdef AXBS_IP_ENABLE_USER_MODE_SUPPORT
    #include "OsIf.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RM_AXBS_IP_VENDOR_ID                      43
#define RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION       4
#define RM_AXBS_IP_AR_RELEASE_MINOR_VERSION       7
#define RM_AXBS_IP_AR_RELEASE_REVISION_VERSION    0
#define RM_AXBS_IP_SW_MAJOR_VERSION               3
#define RM_AXBS_IP_SW_MINOR_VERSION               0
#define RM_AXBS_IP_SW_PATCH_VERSION               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Checks against Axbs_Ip_Types.h */
#if (RM_AXBS_IP_VENDOR_ID != RM_AXBS_IP_TYPES_VENDOR_ID)
    #error "Axbs_Ip.h and Axbs_Ip_Types.h have different vendor ids"
#endif
#if ((RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION    != RM_AXBS_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AXBS_IP_AR_RELEASE_MINOR_VERSION    != RM_AXBS_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (RM_AXBS_IP_AR_RELEASE_REVISION_VERSION != RM_AXBS_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Axbs_Ip.h and Axbs_Ip_Types.h are different"
#endif
#if ((RM_AXBS_IP_SW_MAJOR_VERSION != RM_AXBS_IP_TYPES_SW_MAJOR_VERSION) || \
     (RM_AXBS_IP_SW_MINOR_VERSION != RM_AXBS_IP_TYPES_SW_MINOR_VERSION) || \
     (RM_AXBS_IP_SW_PATCH_VERSION != RM_AXBS_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Axbs_Ip.h and Axbs_Ip_Types.h are different"
#endif

/* Checks against Axbs_Ip_Cfg.h */
#if (RM_AXBS_IP_VENDOR_ID != RM_AXBS_IP_CFG_VENDOR_ID)
    #error "Axbs_Ip.h and Axbs_Ip_Cfg.h have different vendor ids"
#endif
#if ((RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION    != RM_AXBS_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AXBS_IP_AR_RELEASE_MINOR_VERSION    != RM_AXBS_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (RM_AXBS_IP_AR_RELEASE_REVISION_VERSION != RM_AXBS_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Axbs_Ip.h and Axbs_Ip_Cfg.h are different"
#endif
#if ((RM_AXBS_IP_SW_MAJOR_VERSION != RM_AXBS_IP_CFG_SW_MAJOR_VERSION) || \
     (RM_AXBS_IP_SW_MINOR_VERSION != RM_AXBS_IP_CFG_SW_MINOR_VERSION) || \
     (RM_AXBS_IP_SW_PATCH_VERSION != RM_AXBS_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Axbs_Ip.h and Axbs_Ip_Cfg.h are different"
#endif

/* Checks against Axbs_Ip_Device_Registers.h */
#if (RM_AXBS_IP_VENDOR_ID != RM_AXBS_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Axbs_Ip.h and Axbs_Ip_Device_Registers.h have different vendor ids"
#endif
#if ((RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION    != RM_AXBS_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_AXBS_IP_AR_RELEASE_MINOR_VERSION    != RM_AXBS_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (RM_AXBS_IP_AR_RELEASE_REVISION_VERSION != RM_AXBS_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION) \
    )
     #error "AUTOSAR Version Numbers of Axbs_Ip.h and Axbs_Ip_Device_Registers.h are different"
#endif
#if ((RM_AXBS_IP_SW_MAJOR_VERSION != RM_AXBS_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (RM_AXBS_IP_SW_MINOR_VERSION != RM_AXBS_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (RM_AXBS_IP_SW_PATCH_VERSION != RM_AXBS_IP_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Axbs_Ip.h and Axbs_Ip_Device_Registers.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef AXBS_IP_ENABLE_USER_MODE_SUPPORT
        /* Checks against OsIf.h */
        #if ((RM_AXBS_IP_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
             (RM_AXBS_IP_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AUTOSAR Version Numbers of Axbs_Ip.h and OsIf.h are different"
        #endif
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef RM_IP_ENABLE_AXBS
#if (RM_IP_ENABLE_AXBS == STD_ON)

#define RM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"
/**
* @brief   Export AXBS configurations.
*/
AXBS_CONFIG_EXT

#define RM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Rm_MemMap.h"

#define RM_START_SEC_CODE
#include "Rm_MemMap.h"

/**
 * @brief        The function initializes AXBS module.
 * @details      The function sets the internal module variables according to given
 *               configuration set.
 *
 * @param[in]     pAxbsConfig    Pointer of Configuration Axbs
 *
 * @return
 *
 * @api
 *
 * @pre
 *
 */
void Axbs_Ip_Init(const Axbs_Ip_ConfigType * pAxbsConfig);

/**
* @brief        This function de-initializes the AXBS module.
* @details
*
* @param[in]    pAxbsConfig   Pointer to Axbs configuration structure
*/
void Axbs_Ip_DeInit(const Axbs_Ip_ConfigType * pAxbsConfig);

#define RM_STOP_SEC_CODE
#include "Rm_MemMap.h"

#endif /* (RM_IP_ENABLE_AXBS == STD_ON) */
#endif /* RM_IP_ENABLE_AXBS */

#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* AXBS_IP_H */




