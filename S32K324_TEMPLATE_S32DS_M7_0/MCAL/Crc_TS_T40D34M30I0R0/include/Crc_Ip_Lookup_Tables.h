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

/* Prevention from multiple including the same header */
#ifndef CRC_IP_LOOKUP_TABLES_H
#define CRC_IP_LOOKUP_TABLES_H

/**
*   @file    Crc_Ip_LookupTables.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Crc - Crc Ip driver source file.
*   @details
*
*   @addtogroup CRC_IP_DRIVER
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
#include "Crc_Ip_Types.h"
#include "Crc_Ip_State.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_LOOKUP_TABLES_VENDOR_ID                      43
#define CRC_IP_LOOKUP_TABLES_AR_RELEASE_MAJOR_VERSION       4
#define CRC_IP_LOOKUP_TABLES_AR_RELEASE_MINOR_VERSION       7
#define CRC_IP_LOOKUP_TABLES_AR_RELEASE_REVISION_VERSION    0
#define CRC_IP_LOOKUP_TABLES_SW_MAJOR_VERSION               3
#define CRC_IP_LOOKUP_TABLES_SW_MINOR_VERSION               0
#define CRC_IP_LOOKUP_TABLES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Crc_Ip_State.h file are of the same vendor */
#if (CRC_IP_LOOKUP_TABLES_VENDOR_ID != CRC_IP_STATE_VENDOR_ID)
    #error "Crc_Ip_Lookup_Tables.h and Crc_Ip_State.h have different vendor ids"
#endif

/* Check if source file and Crc_Ip_State.h file are of the same Autosar version */
#if ((CRC_IP_LOOKUP_TABLES_AR_RELEASE_MAJOR_VERSION    != CRC_IP_STATE_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_AR_RELEASE_MINOR_VERSION    != CRC_IP_STATE_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_AR_RELEASE_REVISION_VERSION != CRC_IP_STATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Lookup_Tables.h and Crc_Ip_State.h are different"
#endif

/* Check if source file and Crc_Ip_State.h header file are of the same Software version */
#if ((CRC_IP_LOOKUP_TABLES_SW_MAJOR_VERSION != CRC_IP_STATE_SW_MAJOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_SW_MINOR_VERSION != CRC_IP_STATE_SW_MINOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_SW_PATCH_VERSION != CRC_IP_STATE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Lookup_Tables.h and Crc_Ip_State.h are different"
#endif

/* Check if source file and Crc_Ip_Types.h file are of the same vendor */
#if (CRC_IP_LOOKUP_TABLES_VENDOR_ID != CRC_IP_TYPES_VENDOR_ID)
    #error "Crc_Ip_Lookup_Tables.h and Crc_Ip_Types.h have different vendor ids"
#endif

/* Check if source file and Crc_Ip_Types.h file are of the same Autosar version */
#if ((CRC_IP_LOOKUP_TABLES_AR_RELEASE_MAJOR_VERSION    != CRC_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_AR_RELEASE_MINOR_VERSION    != CRC_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_AR_RELEASE_REVISION_VERSION != CRC_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Lookup_Tables.h and Crc_Ip_Types.h are different"
#endif

/* Check if source file and Crc_Ip_Types.h header file are of the same Software version */
#if ((CRC_IP_LOOKUP_TABLES_SW_MAJOR_VERSION != CRC_IP_TYPES_SW_MAJOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_SW_MINOR_VERSION != CRC_IP_TYPES_SW_MINOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_SW_PATCH_VERSION != CRC_IP_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Lookup_Tables.h and Crc_Ip_Types.h are different"
#endif
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

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

/**
 * @brief   This function shall start algorithm Lookup Table calculation CRC.
 * @details This service is a reentrant function that shall calculate the CRC Lookup Table Channel.
 *
 * @param[in]  pxLogicChannelState      - Pointer Logic Channel Config contains parameter for Calculate CRC
 * @param[in]  *DataPtr                 - Pointer to start address of data block to be calculated.
 * @param[in]  Length                   - Length of data block to be calculated in bytes.
 * @param[in]  InitialSeedStartValue         - Start value (seed Value) when the algorithm starts.
 *
 * @return 32 bit result of CRC calculation
 **/
uint64 Crc_Ip_LookupTablesCalculate(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
                                    const uint8  *LookUpTableAddress,
                                    const uint8  *DataPtr,
                                    const uint32  Length,
                                    const uint64  InitialSeedStartValue
                                   );

#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_IP_LOOKUP_TABLES_H */
