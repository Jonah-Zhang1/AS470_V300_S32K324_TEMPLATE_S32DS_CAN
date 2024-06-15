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

#ifndef DEM_STUB_H
#define DEM_STUB_H

/**
*   @file Dem_stub.h
*
*   @addtogroup DEM_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif



/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Dem.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/


/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/
/* Dem extended data (provided through pointer and length) can contain bytes of information
that are not used, due to padding. Need to instruct the Dem_TestLastReportErrorStatusPreExtData()
function to ignore those bytes from checking */
#define DEM_EXT_DATA_NOT_USED_U8       ((uint8)0xA5)
#define DEM_EXT_DATA_NOT_USED_U32      ((uint32)0xA5A5A5A5)

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                            STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/


/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

extern boolean Dem_TestLastReportErrorStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
extern boolean Dem_TestNoError(void);
extern boolean Dem_TestLastReportErrorStatusPreExtData
(
    Dem_EventIdType        Dem_EventIdRaw,
    Dem_EventStatusType    Dem_EventStatusRaw,
    uint8*                 Dem_pui8_PreExtData,
    uint8                  Dem_PreExtDataSize
);
extern void Dem_ClearEvents(void);
extern boolean Dem_GetEvent(uint32 IndexNumber, Dem_EventIdType* EventId, Dem_EventStatusType* EventStatus);
extern uint32 Dem_GetEventCount(void);
extern boolean Dem_BufferOverflow(void);

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* DEM_STUB_H */
