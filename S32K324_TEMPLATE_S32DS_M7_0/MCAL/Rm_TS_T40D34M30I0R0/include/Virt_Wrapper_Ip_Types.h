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

#ifndef VIRT_WRAPPER_IP_TYPES_H
#define VIRT_WRAPPER_IP_TYPES_H

/**
*   @file Virt_Wrapper_Ip_Types.h
*
*   @addtogroup Virt_Wrapper_Ip Virt Wrapper IPV Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Virt_Wrapper_Ip_Cfg_Defines.h"
#include "Virt_Wrapper_Ip_Device_Registers.h"
/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define RM_VIRT_WRAPPER_IP_TYPES_VENDOR_ID                        43
#define RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_MAJOR_VERSION         4
#define RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_MINOR_VERSION         7
#define RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_REVISION_VERSION      0
#define RM_VIRT_WRAPPER_IP_TYPES_SW_MAJOR_VERSION                 3
#define RM_VIRT_WRAPPER_IP_TYPES_SW_MINOR_VERSION                 0
#define RM_VIRT_WRAPPER_IP_TYPES_SW_PATCH_VERSION                 0

/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
/* Checks against Virt_Wrapper_Ip_Cfg_Defines.h */
#if (RM_VIRT_WRAPPER_IP_TYPES_VENDOR_ID != RM_VIRT_WRAPPER_IP_CFG_DEFINES_VENDOR_ID)
    #error "Virt_Wrapper_Ip_Types.h and Virt_Wrapper_Ip_Cfg_Defines.h have different vendor ids"
#endif
#if ((RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != RM_VIRT_WRAPPER_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_MINOR_VERSION    != RM_VIRT_WRAPPER_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_REVISION_VERSION != RM_VIRT_WRAPPER_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Virt_Wrapper_Ip_Types.h and Virt_Wrapper_Ip_Cfg_Defines.h are different"
#endif
#if ((RM_VIRT_WRAPPER_IP_TYPES_SW_MAJOR_VERSION != RM_VIRT_WRAPPER_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_TYPES_SW_MINOR_VERSION != RM_VIRT_WRAPPER_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_TYPES_SW_PATCH_VERSION != RM_VIRT_WRAPPER_IP_CFG_DEFINES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Virt_Wrapper_Ip_Types.h and Virt_Wrapper_Ip_Cfg_Defines.h are different"
#endif

/* Checks against Virt_Wrapper_Ip_Device_Registers.h */
#if (RM_VIRT_WRAPPER_IP_TYPES_VENDOR_ID != RM_VIRT_WRAPPER_IP_DEVICE_REGISTERS_VENDOR_ID)
    #error "Virt_Wrapper_Ip_Types.h and Virt_Wrapper_Ip_Device_Registers.h have different vendor ids"
#endif
#if ((RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != RM_VIRT_WRAPPER_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_MINOR_VERSION    != RM_VIRT_WRAPPER_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_TYPES_AR_RELEASE_REVISION_VERSION != RM_VIRT_WRAPPER_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
     #error "AUTOSAR Version Numbers of Virt_Wrapper_Ip_Types.h and Virt_Wrapper_Ip_Device_Registers.h are different"
#endif
#if ((RM_VIRT_WRAPPER_IP_TYPES_SW_MAJOR_VERSION != RM_VIRT_WRAPPER_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_TYPES_SW_MINOR_VERSION != RM_VIRT_WRAPPER_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (RM_VIRT_WRAPPER_IP_TYPES_SW_PATCH_VERSION != RM_VIRT_WRAPPER_IP_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Virt_Wrapper_Ip_Types.h and Virt_Wrapper_Ip_Device_Registers.h are different"
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
/**
* @brief          Enumeration listing pad (MSCR or IMCR) slot in a single Virtual Wrapper Parameter_n Register
*/
typedef enum
{
    VIRT_WRAPPER_REG_TYPE_A = 0,
    VIRT_WRAPPER_REG_TYPE_B,
    VIRT_WRAPPER_REG_TYPE_C
    ,
    VIRT_WRAPPER_REG_TYPE_D
} Virt_Wrapper_Ip_SlotType;

/**
* @brief          Enumeration listing which PDAC will be assigned to access by the pad
*/
typedef enum
{
	VIRT_WRAPPER_MAP_PDAC_DEFAULT=0,	
#ifdef VIRT_WRAP_PDAC1
    VIRT_WRAPPER_MAP_PDAC1=VIRT_WRAP_PDAC1,
#endif	/** VIRT_WRAP_PDAC1 */
#ifdef VIRT_WRAP_PDAC2
    VIRT_WRAPPER_MAP_PDAC2=VIRT_WRAP_PDAC2,
#endif	/** VIRT_WRAP_PDAC2 */
#ifdef VIRT_WRAP_PDAC3
    VIRT_WRAPPER_MAP_PDAC3=VIRT_WRAP_PDAC3,
#endif	/** VIRT_WRAP_PDAC3 */
#ifdef VIRT_WRAP_PDAC4
    VIRT_WRAPPER_MAP_PDAC4=VIRT_WRAP_PDAC4,
#endif	/** VIRT_WRAP_PDAC4 */
#ifdef VIRT_WRAP_PDAC0
    VIRT_WRAPPER_MAP_PDAC0=VIRT_WRAP_PDAC0
#endif	/** VIRT_WRAP_PDAC0 */
} Virt_Wrapper_Ip_AccessType;

/**
* @brief          Configuration structure containing the Pin configuration for virtual wrapper
*/
typedef struct
{
    Virt_Wrapper_Ip_AccessType      Virt_Wrapper_Access;
    const uint32                    u32Virt_Wrapper_Instance;
    const uint32                    u32Virt_Wrapper_Pin;
    Virt_Wrapper_Ip_SlotType        Virt_Wrapper_Slot;
} Virt_Wrapper_Ip_RegConfigType;

/**
* @brief          Configuration structure containing the Pin configuration for virtual wrapper
*/
typedef struct
{
    const uint32 u32ConfigCount;
    const Virt_Wrapper_Ip_RegConfigType * aRegConfig;
} Virt_Wrapper_Ip_ConfigType;

/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* VIRT_WRAPPER_IP_TYPES_H */

