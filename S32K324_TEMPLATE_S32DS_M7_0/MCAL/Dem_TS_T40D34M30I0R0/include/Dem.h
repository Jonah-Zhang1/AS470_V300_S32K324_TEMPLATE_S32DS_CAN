/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : 
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

#ifndef DEM_H
#define DEM_H

/**
*   @file Dem.h
*
*   @addtogroup DEM_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section Dem_h_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once.
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Dem_h_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Dem_IntErrId.h"
#include "Dem_Types.h"
#include "Rte_Dem_Type.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DEM_VENDOR_ID                       43
#define DEM_MODULE_ID                       54
#define DEM_AR_RELEASE_MAJOR_VERSION        4
#define DEM_AR_RELEASE_MINOR_VERSION        7
#define DEM_AR_RELEASE_REVISION_VERSION     0
#define DEM_SW_MAJOR_VERSION                3
#define DEM_SW_MINOR_VERSION                0
#define DEM_SW_PATCH_VERSION                0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#if (DEM_VENDOR_ID != DEM_INTERRID_VENDOR_ID)
#error "Dem.h and Dem_IntErrId.h have different vendor ids"
#endif


#if ((DEM_AR_RELEASE_MAJOR_VERSION != DEM_INTERRID_AR_RELEASE_MAJOR_VERSION) || \
     (DEM_AR_RELEASE_MINOR_VERSION != DEM_INTERRID_AR_RELEASE_MINOR_VERSION) || \
     (DEM_AR_RELEASE_REVISION_VERSION != DEM_INTERRID_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dem.h and Dem_IntErrId.h are different"
#endif


#if ((DEM_SW_MAJOR_VERSION != DEM_INTERRID_SW_MAJOR_VERSION) || \
     (DEM_SW_MINOR_VERSION != DEM_INTERRID_SW_MINOR_VERSION) || \
     (DEM_SW_PATCH_VERSION != DEM_INTERRID_SW_PATCH_VERSION))
#error "Software Version Numbers of Dem.h and Dem_IntErrId.h are different"
#endif

#if (DEM_VENDOR_ID != DEM_TYPES_VENDOR_ID)
#error "Dem.h and Dem_Types.h have different vendor ids"
#endif

#if ((DEM_AR_RELEASE_MAJOR_VERSION != DEM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (DEM_AR_RELEASE_MINOR_VERSION != DEM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (DEM_AR_RELEASE_REVISION_VERSION != DEM_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Dem.h and Dem_Types.h are different"
#endif

#if ((DEM_SW_MAJOR_VERSION != DEM_TYPES_SW_MAJOR_VERSION) || \
     (DEM_SW_MINOR_VERSION != DEM_TYPES_SW_MINOR_VERSION) || \
     (DEM_SW_PATCH_VERSION != DEM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Dem.h and Dem_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Max length value of extended data kept by Dem when Dem_ReportErrorStatusPreExtData() API is called */
#define DEM_MAX_EXTENDED_DATA_LENGTH_U8         (uint8)(100U)
/* Max numbers of ECU cores supported */
#define DEM_NO_ECU_CORES                        (uint8)(4U)

/* Length value of DEM event ID */
#define DEM_EVENT_ID                            (uint8)(127U)

/* Length value of DEM enven status */
#define DEM_EVENT_STATUS                        (uint8)(127U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define DEM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
/*
 * @violates @ref Dem_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"
extern Dem_EventIdType Dem_EventId[DEM_NO_ECU_CORES][DEM_EVENT_ID];                 /**< @brief DEM event ID*/
extern Dem_EventStatusType Dem_EventStatus[DEM_NO_ECU_CORES][DEM_EVENT_STATUS];             /**< @brief DEM event status*/
#define DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
/*
 * @violates @ref Dem_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Dem_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"
extern uint8               Dem_OverflowEvent[DEM_NO_ECU_CORES];                /**< @brief DEM Overflow Event*/
/**< @brief DEM byte array storing reported extended data */
extern uint8 Dem_au8ExtendedData[DEM_NO_ECU_CORES][DEM_MAX_EXTENDED_DATA_LENGTH_U8];
#define DEM_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Dem_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
/*
 * @violates @ref Dem_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"
extern uint32              Dem_numEventErrors[DEM_NO_ECU_CORES];               /**< @brief DEM event number of errors*/
#define DEM_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
/*
 * @violates @ref Dem_h_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_h_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId,
                                  Dem_EventStatusType EventStatus);
Std_ReturnType Dem_ReportErrorStatusPreExtData(Dem_EventIdType Dem_EventIdRaw,
                                               Dem_EventStatusType Dem_EventStatusRaw,
                                               const uint8 * const Dem_pui8_PreExtData,
                                               uint8 Dem_PreExtDataSize);

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DEM_H */
