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
#ifndef CRC_IP_STATE_H
#define CRC_IP_STATE_H

/**
*   @file    Crc_Ip_State.h
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

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_STATE_VENDOR_ID                      43
#define CRC_IP_STATE_AR_RELEASE_MAJOR_VERSION       4
#define CRC_IP_STATE_AR_RELEASE_MINOR_VERSION       7
#define CRC_IP_STATE_AR_RELEASE_REVISION_VERSION    0
#define CRC_IP_STATE_SW_MAJOR_VERSION               3
#define CRC_IP_STATE_SW_MINOR_VERSION               0
#define CRC_IP_STATE_SW_PATCH_VERSION               0

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

/**
 * @brief   This type contains the CRC Width Type.
 * @details Select Width for each Channel to calculate CRC.
 * */
typedef enum
{
    CRC_WIDTH_8BIT  = 0U,
    CRC_WIDTH_16BIT = 1U,
    CRC_WIDTH_32BIT = 2U,
    CRC_WIDTH_64BIT = 3U
} Crc_Ip_CrcWidthType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
 * @brief   This type contains the CRC Protocol Information.
 * @details
 * */
typedef struct
{
    Crc_Ip_CrcWidthType Width;
    uint64  PolynomValue;
    uint64  InitialSeedValue;
    boolean WriteBitSwap;
    boolean WriteByteSwap;
    boolean ReadBitSwap;
    boolean ReadByteSwap;
    boolean InverseEnable;
} Crc_Ip_CrcProtocolInfoType;


/**
 * @brief   Internal State for the Logic CHannel
 * @details It shall contain the last loaded configuration by the user for the specified Logic Channel
 * */
typedef struct
{
    Crc_Ip_ProtocolType Protocol;                        /**< Protocol Type: CRC-CCITT, CRC-32, CRC-8, CRC-8-H2F */
    const Crc_Ip_CrcProtocolInfoType * CrcProtocolInfo; /**< Crc Protocol Information */
    uint64 CrcResult;                                     /**< Stores the last CRC Result. */


} Crc_Ip_LogicChannelStateType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* #ifndef CRC_IP_STATE_H */
