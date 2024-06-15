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
#ifndef CRC_IP_H
#define CRC_IP_H

/**
*   @file    Crc_Ip.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Crc - Crc Ip driver source file.
*   @details
*
*   @defgroup CRC_IP_DRIVER CRC IPL Driver
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
#include "Crc_Ip_Cfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_VENDOR_ID                     43
#define CRC_IP_AR_RELEASE_MAJOR_VERSION      4
#define CRC_IP_AR_RELEASE_MINOR_VERSION      7
#define CRC_IP_AR_RELEASE_REVISION_VERSION   0
#define CRC_IP_SW_MAJOR_VERSION              3
#define CRC_IP_SW_MINOR_VERSION              0
#define CRC_IP_SW_PATCH_VERSION              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Crc_Ip.h and Crc_Ip_Cfg.h are of the same version */
#if (CRC_IP_VENDOR_ID != CRC_IP_CFG_VENDOR_ID)
    #error "Crc_Ip.h and Crc_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Crc_Ip.h and Crc_Ip_Cfg.h are of the same Autosar version */
#if ((CRC_IP_AR_RELEASE_MAJOR_VERSION    != CRC_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_AR_RELEASE_MINOR_VERSION    != CRC_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_AR_RELEASE_REVISION_VERSION != CRC_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip.h and Crc_Ip_Cfg.h are different"
#endif

/* Check if Crc_Ip.h and Crc_Ip_Cfg.h are of the same Software version */
#if ((CRC_IP_SW_MAJOR_VERSION != CRC_IP_CFG_SW_MAJOR_VERSION) || \
     (CRC_IP_SW_MINOR_VERSION != CRC_IP_CFG_SW_MINOR_VERSION) || \
     (CRC_IP_SW_PATCH_VERSION != CRC_IP_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip.h and Crc_Ip_Cfg.h are different"
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
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

/**
 * @brief   This function initializes the CRC Driver in IP Layer.
 * @details This service is a non-reentrant function that shall initialize the Crc driver.
 *          The user must make sure that the clock is enabled.
 *
 * @param[in] paxLogicChannelConfig     - Pointer to the configuration structure.
 *
 * @return void
 *
 * @api
 *
 **/
void Crc_Ip_Init(const Crc_Ip_InitType *const pxCrcIpInit);


/**
 * @brief   This function initializes the CRC Channel configuration by LogicChannel's info
 * @details This service is a reentrant function that shall initializes parameters list for the CRC Channel.
 *          The list is composed of an array of Crc Channel parameters settings.
 *
 * @param[in]  LogicChannel                - Specifies the Logic Channel Tag defined by the user
 * @param[in]  pxLocLogicChannelConfig     - Specifies the Logic Channel Config defined by the user
 *
 * @return  void
 *
 * @api
 *
 **/
void Crc_Ip_SetChannelConfig(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType *pxLocLogicChannelConfig);


/**
 * @brief   This function shall start algorithm calculate CRC in IP layer.
 * @details This service is a reentrant function that shall start algorithm calculate in CRC Channel
 *          with LogicChannelConfig info
 *
 * @param[in]  LogicChannel     - Specifies the Logic Channel Tag defined by the user.
 * @param[in]  *DataPtr         - Pointer to start address of data block to be calculated..
 * @param[in]  Length           - Length of DataPtr block to be calculated in bytes. *
 * @param[in]  StartValue       - Start value (seed Value) when the algorithm starts.
 * @param[in]  IsFirstCall      - TRUE: ignore StartValue the initialization value is known by the chosen algorithm.
 *                              - FALSE: initialization StartValue is interpreted to be the return value of the previous function
 *
 * @return  Result of CRC calculated.
 *
 * @api
 *
 **/
uint64 Crc_Ip_SetChannelCalculate(const uint32  LogicChannel, const uint8 *DataPtr, const uint32 Length, const uint64 StartValue, const boolean IsFirstCall);


/**
 * @brief   This function get result CRC after finish calculated in IP Layer.
 * @details This service is a function that shall get result from CRC Channel after finish calculated
 *
 * @param[in]  LogicChannel     - Specifies the Logic Channel Tag defined by the user
 *
 * @return  result of CRC calculated.
 *
 * @api
 *
 **/
uint64 Crc_Ip_GetChannelResult(const uint32 LogicChannel);


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_IP_H */
