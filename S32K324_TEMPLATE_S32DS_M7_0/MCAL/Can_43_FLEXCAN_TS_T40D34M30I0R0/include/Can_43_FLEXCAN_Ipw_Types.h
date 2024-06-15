/**
*   @file    Can_IPW_Types.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Can_43_FLEXCAN - module interface
*   @details Main header file - can include different IPV models.
*
*   @addtogroup CAN_43_FLEXCAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
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
/*==================================================================================================
==================================================================================================*/

#ifndef CAN_43_FLEXCAN_IPW_TYPES_H
#define CAN_43_FLEXCAN_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
* @section Can_43_FLEXCAN_IPW_Types_h_REF_1
* Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused macro declarations.
* Declaration is reserved for future feature.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can_43_FLEXCAN_Ipw_Cfg.h"

#if (CAN_43_FLEXCAN_USE_FLEXCAN_IP  == STD_ON)
#include "FlexCAN_Ip.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Can_IPW_Types.h
*/
#define CAN_43_FLEXCAN_IPW_TYPES_VENDOR_ID_H                    43
/* @violates @ref Can_43_FLEXCAN_IPW_Types_h_REF_1 2012 Advisory Rule 2.5. */
#define CAN_43_FLEXCAN_IPW_TYPES_MODULE_ID_H                    80
#define CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H     7
#define CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H  0
#define CAN_43_FLEXCAN_IPW_TYPES_SW_MAJOR_VERSION_H             3
#define CAN_43_FLEXCAN_IPW_TYPES_SW_MINOR_VERSION_H             0
#define CAN_43_FLEXCAN_IPW_TYPES_SW_PATCH_VERSION_H             0
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (CAN_43_FLEXCAN_USE_FLEXCAN_IP  == STD_ON)
/* Check if current file and FlexCAN_Ip.h are of the same vendor */
#if (CAN_43_FLEXCAN_IPW_TYPES_VENDOR_ID_H != FLEXCAN_IP_VENDOR_ID_H)
#error "Can_43_FLEXCAN_IPW_Types.h and FlexCAN_Ip.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip.h are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H != FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H != FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_43_FLEXCAN_IPW_Types.h and FlexCAN_Ip.h are different"
#endif

/* Check if current file and FlexCAN_Ip.h are of the same software version */
#if ((CAN_43_FLEXCAN_IPW_TYPES_SW_MAJOR_VERSION_H != FLEXCAN_IP_SW_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_TYPES_SW_MINOR_VERSION_H != FLEXCAN_IP_SW_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_TYPES_SW_PATCH_VERSION_H != FLEXCAN_IP_SW_PATCH_VERSION_H))
  #error "Software Version Numbers of Can_43_FLEXCAN_IPW_Types.h and FlexCAN_Ip.h are different"
#endif
#endif /* (CAN_43_FLEXCAN_USE_FLEXCAN_IP  == STD_ON) */

/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg.h are of the same vendor */
#if (CAN_43_FLEXCAN_IPW_TYPES_VENDOR_ID_H != CAN_43_FLEXCAN_IPW_CFG_VENDOR_ID)
#error "Can_43_FLEXCAN_IPW_Types.h and Can_43_FLEXCAN_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg.h are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H !=    CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H !=    CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H != CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_43_FLEXCAN_IPW_Types.h and Can_43_FLEXCAN_Ipw_Cfg.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg.h are of the same software version */
#if ((CAN_43_FLEXCAN_IPW_TYPES_SW_MAJOR_VERSION_H != CAN_43_FLEXCAN_IPW_CFG_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_TYPES_SW_MINOR_VERSION_H != CAN_43_FLEXCAN_IPW_CFG_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_TYPES_SW_PATCH_VERSION_H != CAN_43_FLEXCAN_IPW_CFG_SW_PATCH_VERSION))
  #error "Software Version Numbers of Can_43_FLEXCAN_IPW_Types.h and Can_43_FLEXCAN_Ipw_Cfg.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct {
const Flexcan_Ip_ConfigType * pFlexcanIpHwConfig;
} Can_43_FLEXCAN_Ipw_HwChannelConfigType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*CAN_43_FLEXCAN_IPW_TYPES_H */

/** @} */
