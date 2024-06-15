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

#ifndef CRC_IP_LIB_H
#define CRC_IP_LIB_H

/**
*   @file    Crc_Ip_Lib.h
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
#define CRC_IP_LIB_VENDOR_ID                     43
#define CRC_IP_LIB_AR_RELEASE_MAJOR_VERSION      4
#define CRC_IP_LIB_AR_RELEASE_MINOR_VERSION      7
#define CRC_IP_LIB_AR_RELEASE_REVISION_VERSION   0
#define CRC_IP_LIB_SW_MAJOR_VERSION              3
#define CRC_IP_LIB_SW_MINOR_VERSION              0
#define CRC_IP_LIB_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

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

#define CRC_START_SEC_CONST_8
#include "Crc_MemMap.h"

/* Swap bits for values from 0U to 255U */
static const uint8 Crc_Ip_au8BitSwapArray[256U] =
{
    0x00U, 0x80U, 0x40U, 0xC0U, 0x20U, 0xA0U, 0x60U, 0xE0U, 0x10U, 0x90U, 0x50U, 0xD0U, 0x30U, 0xB0U,
    0x70U, 0xF0U, 0x08U, 0x88U, 0x48U, 0xC8U, 0x28U, 0xA8U, 0x68U, 0xE8U, 0x18U, 0x98U, 0x58U, 0xD8U,
    0x38U, 0xB8U, 0x78U, 0xF8U, 0x04U, 0x84U, 0x44U, 0xC4U, 0x24U, 0xA4U, 0x64U, 0xE4U, 0x14U, 0x94U,
    0x54U, 0xD4U, 0x34U, 0xB4U, 0x74U, 0xF4U, 0x0CU, 0x8CU, 0x4CU, 0xCCU, 0x2CU, 0xACU, 0x6CU, 0xECU,
    0x1CU, 0x9CU, 0x5CU, 0xDCU, 0x3CU, 0xBCU, 0x7CU, 0xFCU, 0x02U, 0x82U, 0x42U, 0xC2U, 0x22U, 0xA2U,
    0x62U, 0xE2U, 0x12U, 0x92U, 0x52U, 0xD2U, 0x32U, 0xB2U, 0x72U, 0xF2U, 0x0AU, 0x8AU, 0x4AU, 0xCAU,
    0x2AU, 0xAAU, 0x6AU, 0xEAU, 0x1AU, 0x9AU, 0x5AU, 0xDAU, 0x3AU, 0xBAU, 0x7AU, 0xFAU, 0x06U, 0x86U,
    0x46U, 0xC6U, 0x26U, 0xA6U, 0x66U, 0xE6U, 0x16U, 0x96U, 0x56U, 0xD6U, 0x36U, 0xB6U, 0x76U, 0xF6U,
    0x0EU, 0x8EU, 0x4EU, 0xCEU, 0x2EU, 0xAEU, 0x6EU, 0xEEU, 0x1EU, 0x9EU, 0x5EU, 0xDEU, 0x3EU, 0xBEU,
    0x7EU, 0xFEU, 0x01U, 0x81U, 0x41U, 0xC1U, 0x21U, 0xA1U, 0x61U, 0xE1U, 0x11U, 0x91U, 0x51U, 0xD1U,
    0x31U, 0xB1U, 0x71U, 0xF1U, 0x09U, 0x89U, 0x49U, 0xC9U, 0x29U, 0xA9U, 0x69U, 0xE9U, 0x19U, 0x99U,
    0x59U, 0xD9U, 0x39U, 0xB9U, 0x79U, 0xF9U, 0x05U, 0x85U, 0x45U, 0xC5U, 0x25U, 0xA5U, 0x65U, 0xE5U,
    0x15U, 0x95U, 0x55U, 0xD5U, 0x35U, 0xB5U, 0x75U, 0xF5U, 0x0DU, 0x8DU, 0x4DU, 0xCDU, 0x2DU, 0xADU,
    0x6DU, 0xEDU, 0x1DU, 0x9DU, 0x5DU, 0xDDU, 0x3DU, 0xBDU, 0x7DU, 0xFDU, 0x03U, 0x83U, 0x43U, 0xC3U,
    0x23U, 0xA3U, 0x63U, 0xE3U, 0x13U, 0x93U, 0x53U, 0xD3U, 0x33U, 0xB3U, 0x73U, 0xF3U, 0x0BU, 0x8BU,
    0x4BU, 0xCBU, 0x2BU, 0xABU, 0x6BU, 0xEBU, 0x1BU, 0x9BU, 0x5BU, 0xDBU, 0x3BU, 0xBBU, 0x7BU, 0xFBU,
    0x07U, 0x87U, 0x47U, 0xC7U, 0x27U, 0xA7U, 0x67U, 0xE7U, 0x17U, 0x97U, 0x57U, 0xD7U, 0x37U, 0xB7U,
    0x77U, 0xF7U, 0x0FU, 0x8FU, 0x4FU, 0xCFU, 0x2FU, 0xAFU, 0x6FU, 0xEFU, 0x1FU, 0x9FU, 0x5FU, 0xDFU,
    0x3FU, 0xBFU, 0x7FU, 0xFFU
};

#define CRC_STOP_SEC_CONST_8
#include "Crc_MemMap.h"

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
 * @brief   This function Swap bit in byte uint8.
 *
 * @param[in] InputData     Input data to swap bit in byte.
 *
 * @return uint8
 **/
static inline uint8 Crc_Ip_LibBitSwap8U(const uint8 InputData)
{
    return Crc_Ip_au8BitSwapArray[InputData];
}

/**
 * @brief   This function Swap bit in bytes uint16.
 *
 * @param[in] InputData     Input data to swap bit in bytes.
 *
 * @return uint32
 **/
static inline uint16 Crc_Ip_LibBitSwap16U(const uint16 InputData)
{
    uint16 Tmp1 = (uint16)((uint16)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 8U) & 0xFFU) << 8U);
    uint16 Tmp2 = (uint16)Crc_Ip_LibBitSwap8U((uint8)(InputData & 0xFFU));
    uint16 ReturnValue = Tmp1 | Tmp2;
    return ReturnValue;
}

/**
 * @brief   This function Swap bit in bytes uint32.
 *
 * @param[in] InputData     Input data to swap bit in bytes.
 *
 * @return uint32
 **/
static inline uint32 Crc_Ip_LibBitSwap32U(const uint32 InputData)
{
    uint32 Tmp1 = (uint32)((uint32)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 24U) & 0xFFU) << 24U);
    uint32 Tmp2 = (uint32)((uint32)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 16U) & 0xFFU) << 16U);
    uint32 Tmp3 = (uint32)((uint32)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 8U) & 0xFFU) << 8U);
    uint32 Tmp4 = (uint32)Crc_Ip_LibBitSwap8U((uint8)((uint8)InputData & 0xFFU));
    uint32 ReturnValue1 = Tmp1 | Tmp2;
    uint32 ReturnValue2 = Tmp3 | Tmp4;
    uint32 ReturnValue = ReturnValue1 | ReturnValue2;
    return ReturnValue;
}

/**
 * @brief   This function Swap bit in bytes uint64.
 *
 * @param[in] InputData     Input data to swap bit in bytes.
 *
 * @return uint64
 **/
static inline uint64 Crc_Ip_LibBitSwap64U(const uint64 InputData)
{
    uint64 Tmp1 = (uint64)((uint64)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 56U) & 0xFFU) << 56U);
    uint64 Tmp2 = (uint64)((uint64)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 48U) & 0xFFU) << 48U);
    uint64 Tmp3 = (uint64)((uint64)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 40U) & 0xFFU) << 40U);
    uint64 Tmp4 = (uint64)((uint64)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 32U) & 0xFFU) << 32U);
    uint64 Tmp5 = (uint64)((uint64)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 24U) & 0xFFU) << 24U);
    uint64 Tmp6 = (uint64)((uint64)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 16U) & 0xFFU) << 16U);
    uint64 Tmp7 = (uint64)((uint64)Crc_Ip_LibBitSwap8U((uint8)(InputData >> 8U) & 0xFFU) << 8U);
    uint64 Tmp8 = (uint64)Crc_Ip_LibBitSwap8U((uint8)((uint8)InputData & 0xFFU));
    uint64 ReturnValue1 = Tmp1 | Tmp2;
    uint64 ReturnValue2 = Tmp3 | Tmp4;
    uint64 ReturnValue3 = Tmp5 | Tmp6;
    uint64 ReturnValue4 = Tmp7 | Tmp8;
    uint64 ReturnValue12 = ReturnValue1 | ReturnValue2;
    uint64 ReturnValue34 = ReturnValue3 | ReturnValue4;
    uint64 ReturnValue = ReturnValue12 | ReturnValue34;
    return ReturnValue;
}

/**
 * @brief   This function Swap bytes uint64.
 *
 * @param[in] InputData     Input data to swap bytes.
 *
 * @return uint64
 **/
static inline uint64 Crc_Ip_LibByteSwap64U(const uint64 InputData)
{
    return ((InputData >> 56U) & 0xFFU) | (((InputData >> 48U) & 0xFFU) << 8U) | \
           (((InputData >> 40U) & 0xFFU) << 16U) | (((InputData >> 32U) & 0xFFU) << 24U) | \
           (((InputData >> 24U) & 0xFFU) << 32U) | (((InputData >> 16U) & 0xFFU) << 40U) | \
           (((InputData >> 8U) & 0xFFU) << 48U) | ((InputData & 0xFFU) << 56U);
}

/**
 * @brief   This function Swap bytes uint32.
 *
 * @param[in] InputData     Input data to swap bytes.
 *
 * @return uint32
 **/
static inline uint32 Crc_Ip_LibByteSwap32U(const uint32 InputData)
{
    return ((InputData >> 24U) & 0xFFU) | (((InputData >> 16U) & 0xFFU) << 8U) | \
           (((InputData >> 8U) & 0xFFU) << 16U) | ((InputData & 0xFFU) << 24U);
}

/**
 * @brief   This function Swap bytes uint16.
 *
 * @param[in] InputData     Input data to swap bytes.
 *
 * @return uint16
 **/
static inline uint16 Crc_Ip_LibByteSwap16U(const uint16 InputData)
{
    return ((uint16)(Crc_Ip_LibByteSwap32U((uint32)InputData) >> 16U));
}

/**
 * @brief   This function sets the CRC transpose type for writes
 *
 * @param[in] InputData     Input data to transpose type for writes.
 * @param[in] mode          mode to transpose type for writes.
 *
 * @return uint64
 **/
static inline uint64 Crc_Ip_LibTranspose(const uint64 InputData,
                                          const uint8  CrcWidth,
                                          const boolean BitSwap,
                                          const boolean ByteSwap)
{
    uint64 Result = InputData;

    if (TRUE == BitSwap)
    {
        if ((uint8)CRC_WIDTH_64BIT == CrcWidth)
        {
            Result = Crc_Ip_LibBitSwap64U(Result);
        }
        else if ((uint8)CRC_WIDTH_32BIT == CrcWidth)
        {
            Result = Crc_Ip_LibBitSwap32U((uint32)Result);
        }
        else if ((uint8)CRC_WIDTH_16BIT == CrcWidth)
        {
            Result = Crc_Ip_LibBitSwap16U((uint16)Result);
        }
        else if ((uint8)CRC_WIDTH_8BIT == CrcWidth)
        {
            Result = Crc_Ip_LibBitSwap8U((uint8)Result);
        }
        else
        {
            /* Do nothing */
        }
    }
    if (TRUE == ByteSwap)
    {
        if ((uint8)CRC_WIDTH_64BIT == CrcWidth)
        {
            Result = Crc_Ip_LibByteSwap64U((uint64)Result);
        }
        else if ((uint8)CRC_WIDTH_32BIT == CrcWidth)
        {
            Result = Crc_Ip_LibByteSwap32U((uint32)Result);
        }
        else if ((uint8)CRC_WIDTH_16BIT == CrcWidth)
        {
            Result = Crc_Ip_LibByteSwap16U((uint16)Result);
        }
        else
        {
            /* Do nothing */
        }
    }

    return Result;
}


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CRC_IP_LIB_H */
