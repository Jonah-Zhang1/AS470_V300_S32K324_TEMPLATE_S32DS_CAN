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
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef AEWDOG_IP_H
#define AEWDOG_IP_H

/**
*   @file
*
*   @addtogroup AeWdog_Ip
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

#include "AeWdog_Ip_Types.h"
#include "AeWdog_Ip_DeviceRegisters.h"
#if (AEWDOG_IP_ENABLE == STD_ON)
#include "Aec_Ip.h"
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEWDOG_IP_VENDOR_ID                    43
#define AEWDOG_IP_MODULE_ID                    102
#define AEWDOG_IP_AR_RELEASE_MAJOR_VERSION     4
#define AEWDOG_IP_AR_RELEASE_MINOR_VERSION     7
#define AEWDOG_IP_AR_RELEASE_REVISION_VERSION  0
#define AEWDOG_IP_SW_MAJOR_VERSION             3
#define AEWDOG_IP_SW_MINOR_VERSION             0
#define AEWDOG_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and AeWdog_Ip_Types header file are of the same vendor */
#if (AEWDOG_IP_VENDOR_ID != AEWDOG_IP_TYPES_VENDOR_ID)
#error "AeWdog_Ip.h and AeWdog_Ip_Types.h have different vendor ids"
#endif

#if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION    != AEWDOG_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_MINOR_VERSION    != AEWDOG_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_REVISION_VERSION != AEWDOG_IP_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of AeWdog_Ip.h and AeWdog_Ip_Types.h are different"
#endif

#if ((AEWDOG_IP_SW_MAJOR_VERSION != AEWDOG_IP_TYPES_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_SW_MINOR_VERSION != AEWDOG_IP_TYPES_SW_MINOR_VERSION) || \
     (AEWDOG_IP_SW_PATCH_VERSION != AEWDOG_IP_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of AeWdog_Ip.h and AeWdog_Ip_Types.h are different"
#endif

/* Check if current file and AeWdog_Ip_DeviceRegisters header file are of the same vendor */
#if (AEWDOG_IP_VENDOR_ID != AEWDOG_IP_DEVICE_REGISTERS_VENDOR_ID)
#error "AeWdog_Ip.h and AeWdog_Ip_DeviceRegisters.h have different vendor ids"
#endif

#if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION    != AEWDOG_IP_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_MINOR_VERSION    != AEWDOG_IP_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_REVISION_VERSION != AEWDOG_IP_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of AeWdog_Ip.h and AeWdog_Ip_DeviceRegisters.h are different"
#endif

#if ((AEWDOG_IP_SW_MAJOR_VERSION != AEWDOG_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_SW_MINOR_VERSION != AEWDOG_IP_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (AEWDOG_IP_SW_PATCH_VERSION != AEWDOG_IP_DEVICE_REGISTERS_SW_PATCH_VERSION))
#error "Software Version Numbers of AeWdog_Ip.h and AeWdog_Ip_DeviceRegisters.h are different"
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

#if (AEWDOG_IP_ENABLE == STD_ON)

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

/*!
 * @brief Init AEWDOG. This method initializes AEWDOG instance to the configuration
 * from the passed structure. The user must make sure that the clock is
 * enabled. This is the only method needed to be called to start the module.
 *
 *  Example configuration structure:
 *  @code
 *      AeWdog_Ip_ConfigType ewmUserCfg = {
 *          .AssertLogic        = AEWDOG_IN_ASSERT_ON_LOGIC_ZERO,
 *          .InterruptEnable    = true,
 *          .Prescaler          = 128,
 *          .CompareLow         = 0,
 *          .CompareHigh        = 254
 *      };
 *  @endcode
 *      This configuration will enable the peripheral, with input pin configured
 *      to assert on logic low, interrupt enabled, prescaler 128 and maximum
 *      refresh window.
 *
 *      The AEWDOG can be initialized only once per CPU reset as the registers
 *      are write once.
 *
 * @param[in] u8Instance AEWDOG instance number
 * @param[in] config  Pointer to the module configuration structure.
 *
 * @return AeWdog_Ip_StatusType Will return the status of the operation:
 *          - STATUS_SUCCESS            if the operation is successful
 *          - STATUS_ERROR              if the windows values are not
 *                                        correct or if the instance is
 *                                        already enabled
 *
 */
AeWdog_Ip_StatusType AeWdog_Ip_Init(const uint8 Instance, const AeWdog_Ip_ConfigType * const ConfigPtr);

/*!
 * @brief Refresh AEWDOG. This method needs to be called within the window period
 * specified by the Compare Low and Compare High registers.
 *
 * @param[in] u8Instance AEWDOG instance number
 *
 * @return None
 *
 */
void AeWdog_Ip_Service(const uint8 Instance);

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

#endif /* (AEWDOG_IP_ENABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* AEWDOG_IP_H */
