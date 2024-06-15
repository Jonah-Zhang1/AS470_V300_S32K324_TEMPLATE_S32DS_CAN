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

/**
*   @file Dem.c
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
* @section Dem_c_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents of a header file being included more than once.
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Dem_c_REF_2
* Violates MISRA 2012 Advisory Rule 20.1, #Include directives should only be preceded by preprocessor directives or comments.
* <MA>_MemMap.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "OsIf.h"
#include "Dem.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
#define DEM_VENDOR_ID_C         43
#define DEM_AR_RELEASE_MAJOR_VERSION_C  4
#define DEM_AR_RELEASE_MINOR_VERSION_C  7
#define DEM_AR_RELEASE_REVISION_VERSION_C  0
#define DEM_SW_MAJOR_VERSION_C  3
#define DEM_SW_MINOR_VERSION_C  0
#define DEM_SW_PATCH_VERSION_C  0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and DEM header file are of the same vendor */
#if (DEM_VENDOR_ID_C != DEM_VENDOR_ID)
    #error "Dem.c and Dem.h have different vendor ids"
#endif

/* Check if source file and DEM header file are of the same Autosar version */
#if ((DEM_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (DEM_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) || \
     (DEM_AR_RELEASE_REVISION_VERSION_C != DEM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Dem.c and Dem.h are different"
#endif

/* Check if source file and DEM header file are of the same Software version */
#if ((DEM_SW_MAJOR_VERSION_C != DEM_SW_MAJOR_VERSION) || \
     (DEM_SW_MINOR_VERSION_C != DEM_SW_MINOR_VERSION) || \
     (DEM_SW_PATCH_VERSION_C != DEM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Dem.c and Dem.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if DEM source file and STD_TYPES header file are of the same Software version */
    #if ((DEM_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
        (DEM_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Dem.C and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#define DEM_MAX_NUMBER_OF_EVENTS (uint32)127

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define DEM_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
/*
 * @violates @ref Dem_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"
Dem_EventIdType Dem_EventId[DEM_NO_ECU_CORES][DEM_EVENT_ID];                 /**< @brief DEM event ID*/
Dem_EventStatusType Dem_EventStatus[DEM_NO_ECU_CORES][DEM_EVENT_STATUS];             /**< @brief DEM event status*/
#define DEM_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
/*
 * @violates @ref Dem_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Dem_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"
uint8               Dem_OverflowEvent[DEM_NO_ECU_CORES];                /**< @brief DEM Overflow Event*/
/**< @brief DEM byte array storing reported extended data */
uint8 Dem_au8ExtendedData[DEM_NO_ECU_CORES][DEM_MAX_EXTENDED_DATA_LENGTH_U8];
#define DEM_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
/*
 * @violates @ref Dem_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
/*
 * @violates @ref Dem_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"
uint32              Dem_numEventErrors[DEM_NO_ECU_CORES];               /**< @brief DEM event number of errors*/
#define DEM_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
/*
 * @violates @ref Dem_c_REF_1 Precautions shall be taken in order to prevent the contents of a header file being included more than once
 * @violates @ref Dem_c_REF_2 #Include directives should only be preceded by preprocessor directives or comments
 */
#include "Dem_MemMap.h"


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

/*================================================================================================*/
/**
* @brief   This function sets the error status.
* @details This is a function stub only. It loads Dem_EventId2 = EventId and
*          Dem_EventStatus2 = EventStatus and returns success.
*
* @param[in]     EventId        ID of the event
* @param[in]     EventStatus    status of the event
* @return        Std_ReturnType This function is always successful
*
*/
Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(DEM_MAX_NUMBER_OF_EVENTS > Dem_numEventErrors[u32CoreId])
    {
        Dem_EventId[u32CoreId][Dem_numEventErrors[u32CoreId]] = EventId;
        Dem_EventStatus[u32CoreId][Dem_numEventErrors[u32CoreId]] = EventStatus;
        Dem_numEventErrors[u32CoreId]++;
        Dem_OverflowEvent[u32CoreId] = 0U;
    }
    else
    {
        Dem_EventId[u32CoreId][(Dem_numEventErrors[u32CoreId]-1)] = EventId;
        Dem_EventStatus[u32CoreId][(Dem_numEventErrors[u32CoreId]-1)] = EventStatus;
        Dem_OverflowEvent[u32CoreId] = 1U;
    }

    return(E_OK);
}

/**
* Description:    NON-AUTOSAR DEM function:
*                 This function shall be used to report the Event Status from a monitoring function as soon as a new test result is available.
*                 This function has to be used if pre-extended data shall be logged at the time the event has been reported as "Failed".
*                 In case the EvTestResult is "Passed" the parameters pPreExtData and PreExtDataSize will be ignored.
*
* Return value:   Std_ReturnType: E_OK (0x00) Operation was successful ; E_NOT_OK (0x01) Operation failed
*
* Preconditions:  None: function can be called at any time during startup-phase. Functions "Dem_PreInit()" and "Dem_Init()" do not have to be called before.
* Postconditions: -
*
* **************************************************************************
* PARAMETERS:
*    Dem_EventIdRaw      [In] Identification of the event
*    Dem_EventStatus     [In] DEM_EVENT_STATUS_PASSED or DEM_EVENT_STATUS_FAILED
*    Dem_pui8_PreExtData [In] Pointer to pre-extended data
*    Dem_PreExtDataSize  [In] Size of pre-extended data
*
* **************************************************************************/
Std_ReturnType Dem_ReportErrorStatusPreExtData
(
    Dem_EventIdType Dem_EventIdRaw,
    Dem_EventStatusType Dem_EventStatusRaw,
    const uint8 * const Dem_pui8_PreExtData,
    uint8 Dem_PreExtDataSize
)
{
    uint8 u8Counter;
    Std_ReturnType retVal = (Std_ReturnType)E_OK;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(DEM_MAX_NUMBER_OF_EVENTS > Dem_numEventErrors[u32CoreId])
    {
        Dem_EventId[u32CoreId][Dem_numEventErrors[u32CoreId]] = Dem_EventIdRaw;
        Dem_EventStatus[u32CoreId][Dem_numEventErrors[u32CoreId]] = Dem_EventStatusRaw;
        Dem_numEventErrors[u32CoreId]++;
        Dem_OverflowEvent[u32CoreId] = 0U;
    }
    else
    {
        Dem_EventId[u32CoreId][(Dem_numEventErrors[u32CoreId]-1)] = Dem_EventIdRaw;
        Dem_EventStatus[u32CoreId][(Dem_numEventErrors[u32CoreId]-1)] = Dem_EventStatusRaw;
        Dem_OverflowEvent[u32CoreId] = 1U;
    }

    /* Store extended data only if Dem_EventStatus is set to DEM_EVENT_STATUS_FAILED */
    if ((Dem_EventStatusType)DEM_EVENT_STATUS_FAILED == Dem_EventStatusRaw)
    {
        /* Check if the extended data fits in the DEM statically allocated buffer */
        if (Dem_PreExtDataSize <= DEM_MAX_EXTENDED_DATA_LENGTH_U8)
        {
            for(u8Counter=0; u8Counter<Dem_PreExtDataSize; u8Counter++)
            {
                Dem_au8ExtendedData[u32CoreId][u8Counter] = Dem_pui8_PreExtData[u8Counter];
            }
        }
        else
        {
            retVal = (Std_ReturnType)E_NOT_OK;
        }
    }

    return retVal;
}

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
