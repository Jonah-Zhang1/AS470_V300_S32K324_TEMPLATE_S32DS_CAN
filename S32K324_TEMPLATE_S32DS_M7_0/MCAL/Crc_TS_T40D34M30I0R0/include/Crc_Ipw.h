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
#ifndef CRC_IPW_H
#define CRC_IPW_H

/**
*   @file    Crc_Ipw.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Crc - Crc Ipw driver source file.
*   @details
*
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
#include "Crc_Ip.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the Crc driver header file and also in the
*        module's description file.
*
*/
#define CRC_IPW_VENDOR_ID                    43
#define CRC_IPW_AR_RELEASE_MAJOR_VERSION     4
#define CRC_IPW_AR_RELEASE_MINOR_VERSION     7
#define CRC_IPW_AR_RELEASE_REVISION_VERSION  0
#define CRC_IPW_SW_MAJOR_VERSION             3
#define CRC_IPW_SW_MINOR_VERSION             0
#define CRC_IPW_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

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
 * @brief   This function initializes the CRC Driver in IPW Layer.
 * @details This service is a non-reentrant function that shall initialize the Crc driver.
 *          The user must make sure that the clock is enabled.
 *
 * @param[in] pxCrcIpInit     - Pointer to the Crc specific configuration structure that contains static configuration.
 *
 * @return void
 *
 * @api
 *
 **/
#define Crc_Ipw_Init(pxCrcIpInit) Crc_Ip_Init(pxCrcIpInit)


/**
 * @brief   This function initializes the CRC Channel configuration by logicChannel's info
 * @details This service is a reentrant function that shall initialize parameters list for the CRC Channel.
 *          The list is composed of an array of Crc Channel parameters settings.
 *
 * @param[in]  Channel             - Logic Channel Tag defined by the user.
 * @param[in]  pxChannelConfig     - Specifies the Logic Channel Config defined by the user
 *
 * @return void
 *
 * @api
 *
 **/
#define Crc_Ipw_SetChannelConfig(Channel, pxChannelConfig) Crc_Ip_SetChannelConfig(Channel, pxChannelConfig)


/**
 * @brief   This function shall start algorithm calculate CRC in IPW layer.
 * @details This service is a reentrant function that shall start the Channel to calculate the CRC using the configured algorithm.
 *
 * @param[in]  Channel          - Logic Channel Tag defined by the user..
 * @param[in]  *pCrcData        - Pointer to the Crc Data Input.
 * @param[in]  CrcLength        - Length of pCrcData block to be calculated in bytes.
 * @param[in]  CrcStartValue    - Start value (seed Value) when the algorithm starts.
 * @param[in]  IsFirstCall      - TRUE: ignore CrcStartValue the initialization value is known by the chosen algorithm.
 *                              - FALSE: initialization CrcStartValue is interpreted to be the return value of the previous function
 *
 * @return  Result of CRC calculated.
 *
 * @api
 *
 **/
#define Crc_Ipw_SetChannelCalculate(Channel, pCrcData, CrcLength, CrcStartValue, IsFirstCall) Crc_Ip_SetChannelCalculate(Channel, pCrcData, CrcLength, CrcStartValue, IsFirstCall)


/**
 * @brief   This function get result CRC after finish calculated in IPW Layer.
 * @details This service is a function that shall get result CRC Channel parameters list
 *
 * @param[in]  Channel      - Logic Channel Tag defined by the user.
 *
 * @return void
 *
 * @api
 *
 **/
#define Crc_Ipw_GetChannelResult(Channel) Crc_Ip_GetChannelResult(Channel)


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_IPW_H */
