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
*   @file Dem_stub.c
*
*   @addtogroup DEM_MODULE
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
#include "Mcal.h"
#include "OsIf.h"
#include "Dem_stub.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"

/*================================================================================================*/
/**
* @brief            Tests if an expected event has been reported to DEM
* @details          This function will search the buffer of events, from the last event logged to the first one
*                   (from the newest to the oldest event), for the event ID&Status passed as parameter.
*                   This function will also delete the event found ( (NumberOfEvents--) && (all events
*                   will be shifted with one position in the buffer))
*
* @param[in]        EventId - ID of the event reported
* @param[in]        EventStatus - event status

* @return           boolean - True - if the event is found (the first one found) with the requested status
* @return           boolean - False - if that event is not found in the entire buffer with the requested status
*
*/
boolean Dem_TestLastReportErrorStatus(Dem_EventIdType EventId,
                                      Dem_EventStatusType EventStatus)
{
    boolean result = 0U;
    sint32 counterDown;
    uint32 counterUp;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    /* Search all events, from the last event logged to the first one */
    for(counterDown = (Dem_numEventErrors[u32CoreId] - 1); (sint32)0 <= counterDown; counterDown--)
    {
      /* If the specific event is found */
      if((EventId == Dem_EventId[u32CoreId][counterDown]) && (EventStatus == Dem_EventStatus[u32CoreId][counterDown]))
      {
          /* Mark the result as found */
          result = 1;
          /* shift all the newest events with one position(discard the one that it is found) */
          for(counterUp = (uint32)counterDown; counterUp < (Dem_numEventErrors[u32CoreId] - 1);counterUp++)
          {
              Dem_EventId[u32CoreId][counterUp] = Dem_EventId[u32CoreId][(counterUp+1)];
              Dem_EventStatus[u32CoreId][counterUp] = Dem_EventStatus[u32CoreId][(counterUp+1)];
          }
          /* update the Dem_numEventErrors (the event found is discarded) */
          Dem_numEventErrors[u32CoreId]--;
          /* terminate the search */
          break;
      }
    }

    return result;
}

/*================================================================================================*/
/**
* @brief            Tests if a FAILED or PREFAILED event has been reported to DEM
* @details          Tests if a FAILED or PREFAILED event has been reported to DEM
*                   This function will also reset all the events, after the above check (NumberOfEvents=0)
*
* @return           boolean - true in case of NO event has been reported
*
*/
boolean Dem_TestNoError(void) {
    boolean result = 1U;
    uint32 counter;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    for(counter = 0;counter < Dem_numEventErrors[u32CoreId]; counter++)
    {
        if((DEM_EVENT_STATUS_FAILED == Dem_EventStatus[u32CoreId][counter]) || (DEM_EVENT_STATUS_PREFAILED == Dem_EventStatus[u32CoreId][counter]))
        {
            result = 0U;
          /* terminate the search */
          break;
        }
    }
    Dem_numEventErrors[u32CoreId] = 0;

    return result;
}
/*================================================================================================*/
/**
* @brief            Tests if a DEM extended data has been reported to DEM
* @details          Tests if a DEM extended data has been reported to DEM
*
* @return           boolean - true in case of expected extended data was found
*
*/
boolean Dem_TestLastReportErrorStatusPreExtData(Dem_EventIdType        Dem_EventIdRaw,
                                                Dem_EventStatusType    Dem_EventStatusRaw,
                                                uint8*                 Dem_pui8_PreExtData,
                                                uint8                  Dem_PreExtDataSize)
{
    boolean bRetValue = 1U;
    sint32 counterDown;
    uint32 counterUp;
    uint8  u8Counter;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    /* Search all events, from the last event logged to the first one */
    for(counterDown = (Dem_numEventErrors[u32CoreId] - 1); (sint32)0 <= counterDown; counterDown--)
    {
      /* If the specific event is found */
      if((Dem_EventIdRaw == Dem_EventId[u32CoreId][counterDown]) && (Dem_EventStatusRaw == Dem_EventStatus[u32CoreId][counterDown]))
      {
          /* If EventId and EventStatus match, check if data provided through pointer and length matches */
        for(u8Counter=0; u8Counter < Dem_PreExtDataSize; u8Counter++)
        {
            /* Skip over Dem extended data marked as not used */
            if (DEM_EXT_DATA_NOT_USED_U8 == Dem_pui8_PreExtData[u8Counter])
                continue;
            /* Check for match between expected and existing DEM extended data */
            if (Dem_pui8_PreExtData[u8Counter] != Dem_au8ExtendedData[u32CoreId][u8Counter])
            {
                bRetValue = (boolean)FALSE;
            }
        }
          /* shift all the newest events with one position(discard the one that it is found) */
        for(counterUp = (uint32)counterDown; counterUp < (Dem_numEventErrors[u32CoreId] - 1);counterUp++)
        {
            Dem_EventId[u32CoreId][counterUp] = Dem_EventId[u32CoreId][(counterUp+1)];
            Dem_EventStatus[u32CoreId][counterUp] = Dem_EventStatus[u32CoreId][(counterUp+1)];
        }
        /* update the Dem_numEventErrors (the event found is discarded) */
        Dem_numEventErrors[u32CoreId]--;
        /* terminate the search */
        break;
      }
    }

    /* Clear the stored information */
    for(u8Counter=0; u8Counter < DEM_MAX_EXTENDED_DATA_LENGTH_U8; u8Counter++)
    {
        Dem_au8ExtendedData[u32CoreId][u8Counter] = 0x0U;
    }
    /* Return */
    return bRetValue;
}
/*================================================================================================*/
/**
* @brief            Function that will reset the events.
* @details          This function will reset the counter that holds the number of DEM events.
*
* @return
*
*/
void Dem_ClearEvents(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    Dem_numEventErrors[u32CoreId] = 0U;
}

/*================================================================================================*/
/**
* @brief            It will return the event found on the index passed as parameter(IndexNumber)
* @details          This function will return the event found on the index passed as parameter(IndexNumber)
*                   This function will use the parameters 2 and 3(&EventId, &EventStatus) to return that entry.
*
* @return           boolean - true in case IndexNumber is OutOfRange
*
*/
boolean Dem_GetEvent(uint32 IndexNumber,
                     Dem_EventIdType* EventId,
                     Dem_EventStatusType* EventStatus)
{
    boolean result = 0;
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    if(IndexNumber < Dem_numEventErrors[u32CoreId])
    {
        *EventId = Dem_EventId[u32CoreId][IndexNumber];
        *EventStatus = Dem_EventStatus[u32CoreId][IndexNumber];
    }
    else
    {
        result = 1;
    }
  return result;
}

/*================================================================================================*/
/**
* @brief            Returns the NumberOfEvents that are logged so far.
* @details          This function returns the NumberOfEvents that are logged so far.
*
* @return           uint8 - NumberOfEvents
*
*/
uint32 Dem_GetEventCount(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    return Dem_numEventErrors[u32CoreId];
}

/*================================================================================================*/
/**
* @brief            Return if the maximum number of events was exceeded(256)
* @details          This function returns true if the maximum number of events was exceeded(256).
*                   In case of Overflow: the last position (Dem_EventId[255] )will be overwritten if
*                   the new event is a PREFAILED or FAILED. This way, you will always have the last
*                   error reported. And together with the function Dem_BufferOverflow, you will know
*                   if you have the entire/correct sequence of events reported to DEM.
*
* @return           boolean
*                     True - if the number of events logged so far exceeds the DEM event buffer size elements
*                     False - if there is still room in the buffer
*
*/
boolean Dem_BufferOverflow(void)
{
    uint32 u32CoreId = (uint32)OsIf_GetCoreID();

    return Dem_OverflowEvent[u32CoreId];
}

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
