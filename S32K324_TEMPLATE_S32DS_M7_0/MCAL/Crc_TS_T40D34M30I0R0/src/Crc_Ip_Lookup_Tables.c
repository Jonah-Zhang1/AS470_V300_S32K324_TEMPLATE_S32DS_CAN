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

/**
*   @file    Crc_Ip_LookupTables.c
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
#include "Crc_Ip_Lookup_Tables.h"
#include "Crc_Ip_Lib.h"
#include "Crc_Ip_Devassert.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_LOOKUP_TABLES_VENDOR_ID_C                      43
#define CRC_IP_LOOKUP_TABLES_AR_RELEASE_MAJOR_VERSION_C       4
#define CRC_IP_LOOKUP_TABLES_AR_RELEASE_MINOR_VERSION_C       7
#define CRC_IP_LOOKUP_TABLES_AR_RELEASE_REVISION_VERSION_C    0
#define CRC_IP_LOOKUP_TABLES_SW_MAJOR_VERSION_C               3
#define CRC_IP_LOOKUP_TABLES_SW_MINOR_VERSION_C               0
#define CRC_IP_LOOKUP_TABLES_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Crc_Ip_LookupTables.c and Crc_Ip_LookupTables.h are of the same version */
#if (CRC_IP_LOOKUP_TABLES_VENDOR_ID_C != CRC_IP_LOOKUP_TABLES_VENDOR_ID)
    #error "Crc_Ip_LookupTables.c and Crc_Ip_LookupTables.h have different vendor ids"
#endif

/* Check if Crc_Ip_LookupTables.c and Crc_Ip_LookupTables.h are of the same Autosar version */
#if ((CRC_IP_LOOKUP_TABLES_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_LOOKUP_TABLES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_LOOKUP_TABLES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_AR_RELEASE_REVISION_VERSION_C != CRC_IP_LOOKUP_TABLES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_LookupTables.c and Crc_Ip_LookupTables.h are different"
#endif

/* Check if Crc_Ip_LookupTables.c and Crc_Ip_LookupTables.h are of the same Software version */
#if ((CRC_IP_LOOKUP_TABLES_SW_MAJOR_VERSION_C != CRC_IP_LOOKUP_TABLES_SW_MAJOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_SW_MINOR_VERSION_C != CRC_IP_LOOKUP_TABLES_SW_MINOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_SW_PATCH_VERSION_C != CRC_IP_LOOKUP_TABLES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_LookupTables.c and Crc_Ip_LookupTables.h are different"
#endif

/* Check if the files Crc_Ip_Lookup_Tables.c and Crc_Ip_Lib.h are of the same version */
#if (CRC_IP_LOOKUP_TABLES_VENDOR_ID_C != CRC_IP_LIB_VENDOR_ID)
    #error "Crc_Ip_Lookup_Tables.c and Crc_Ip_Lib.h have different vendor ids"
#endif

/* Check if Crc_Ip_Lookup_Tables.c and Crc_Ip_Lib.h are of the same Autosar version */
#if ((CRC_IP_LOOKUP_TABLES_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_LIB_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_LIB_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_AR_RELEASE_REVISION_VERSION_C != CRC_IP_LIB_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Lookup_Tables.c and Crc_Ip_Lib.h are different"
#endif

/* Check if Crc_Ip_Lookup_Tables.c and Crc_Ip_Lib.h are of the same Software version */
#if ((CRC_IP_LOOKUP_TABLES_SW_MAJOR_VERSION_C != CRC_IP_LIB_SW_MAJOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_SW_MINOR_VERSION_C != CRC_IP_LIB_SW_MINOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_SW_PATCH_VERSION_C != CRC_IP_LIB_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Lookup_Tables.c and Crc_Ip_Lib.h are different"
#endif

/* Check if the files Crc_Ip_Lookup_Tables.c and Crc_Ip_Devassert.h are of the same version */
#if (CRC_IP_LOOKUP_TABLES_VENDOR_ID_C != CRC_IP_DEVASSERT_VENDOR_ID)
    #error "Crc_Ip_Lookup_Tables.c and Crc_Ip_Devassert.h have different vendor ids"
#endif

/* Check if Crc_Ip_Lookup_Tables.c and Crc_Ip_Devassert.h are of the same Autosar version */
#if ((CRC_IP_LOOKUP_TABLES_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_AR_RELEASE_REVISION_VERSION_C != CRC_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Lookup_Tables.c and Crc_Ip_Devassert.h are different"
#endif

/* Check if Crc_Ip_Lookup_Tables.c and Crc_Ip_Devassert.h are of the same Software version */
#if ((CRC_IP_LOOKUP_TABLES_SW_MAJOR_VERSION_C != CRC_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_SW_MINOR_VERSION_C != CRC_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (CRC_IP_LOOKUP_TABLES_SW_PATCH_VERSION_C != CRC_IP_DEVASSERT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Lookup_Tables.c and Crc_Ip_Devassert.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/
#if(STD_ON == CRC_IP_LOOK_UP_TABLE_USED)
#if (STD_ON == CRC_IP_8BIT_SAE_J1850_TABLE)

#define CRC_START_SEC_CONST_8
#include "Crc_MemMap.h"
/**
* @brief   CRC 8 SAE J1850 LOOK-UP TABLE
*/
static const uint8 s_TableCrc8[256U] = {
    0x00U, 0x1DU, 0x3AU, 0x27U, 0x74U, 0x69U, 0x4EU, 0x53U, 0xE8U, 0xF5U, 0xD2U, 0xCFU, 0x9CU, 0x81U, 0xA6U, 0xBBU,
    0xCDU, 0xD0U, 0xF7U, 0xEAU, 0xB9U, 0xA4U, 0x83U, 0x9EU, 0x25U, 0x38U, 0x1FU, 0x02U, 0x51U, 0x4CU, 0x6BU, 0x76U,
    0x87U, 0x9AU, 0xBDU, 0xA0U, 0xF3U, 0xEEU, 0xC9U, 0xD4U, 0x6FU, 0x72U, 0x55U, 0x48U, 0x1BU, 0x06U, 0x21U, 0x3CU,
    0x4AU, 0x57U, 0x70U, 0x6DU, 0x3EU, 0x23U, 0x04U, 0x19U, 0xA2U, 0xBFU, 0x98U, 0x85U, 0xD6U, 0xCBU, 0xECU, 0xF1U,
    0x13U, 0x0EU, 0x29U, 0x34U, 0x67U, 0x7AU, 0x5DU, 0x40U, 0xFBU, 0xE6U, 0xC1U, 0xDCU, 0x8FU, 0x92U, 0xB5U, 0xA8U,
    0xDEU, 0xC3U, 0xE4U, 0xF9U, 0xAAU, 0xB7U, 0x90U, 0x8DU, 0x36U, 0x2BU, 0x0CU, 0x11U, 0x42U, 0x5FU, 0x78U, 0x65U,
    0x94U, 0x89U, 0xAEU, 0xB3U, 0xE0U, 0xFDU, 0xDAU, 0xC7U, 0x7CU, 0x61U, 0x46U, 0x5BU, 0x08U, 0x15U, 0x32U, 0x2FU,
    0x59U, 0x44U, 0x63U, 0x7EU, 0x2DU, 0x30U, 0x17U, 0x0AU, 0xB1U, 0xACU, 0x8BU, 0x96U, 0xC5U, 0xD8U, 0xFFU, 0xE2U,
    0x26U, 0x3BU, 0x1CU, 0x01U, 0x52U, 0x4FU, 0x68U, 0x75U, 0xCEU, 0xD3U, 0xF4U, 0xE9U, 0xBAU, 0xA7U, 0x80U, 0x9DU,
    0xEBU, 0xF6U, 0xD1U, 0xCCU, 0x9FU, 0x82U, 0xA5U, 0xB8U, 0x03U, 0x1EU, 0x39U, 0x24U, 0x77U, 0x6AU, 0x4DU, 0x50U,
    0xA1U, 0xBCU, 0x9BU, 0x86U, 0xD5U, 0xC8U, 0xEFU, 0xF2U, 0x49U, 0x54U, 0x73U, 0x6EU, 0x3DU, 0x20U, 0x07U, 0x1AU,
    0x6CU, 0x71U, 0x56U, 0x4BU, 0x18U, 0x05U, 0x22U, 0x3FU, 0x84U, 0x99U, 0xBEU, 0xA3U, 0xF0U, 0xEDU, 0xCAU, 0xD7U,
    0x35U, 0x28U, 0x0FU, 0x12U, 0x41U, 0x5CU, 0x7BU, 0x66U, 0xDDU, 0xC0U, 0xE7U, 0xFAU, 0xA9U, 0xB4U, 0x93U, 0x8EU,
    0xF8U, 0xE5U, 0xC2U, 0xDFU, 0x8CU, 0x91U, 0xB6U, 0xABU, 0x10U, 0x0DU, 0x2AU, 0x37U, 0x64U, 0x79U, 0x5EU, 0x43U,
    0xB2U, 0xAFU, 0x88U, 0x95U, 0xC6U, 0xDBU, 0xFCU, 0xE1U, 0x5AU, 0x47U, 0x60U, 0x7DU, 0x2EU, 0x33U, 0x14U, 0x09U,
    0x7FU, 0x62U, 0x45U, 0x58U, 0x0BU, 0x16U, 0x31U, 0x2CU, 0x97U, 0x8AU, 0xADU, 0xB0U, 0xE3U, 0xFEU, 0xD9U, 0xC4U
};
#define CRC_STOP_SEC_CONST_8
#include "Crc_MemMap.h"

#endif /* #if (STD_ON == CRC_IP_8BIT_SAE_J1850_TABLE) */


#if (STD_ON == CRC_IP_8BIT_H2F_TABLE)

#define CRC_START_SEC_CONST_8
#include "Crc_MemMap.h"
/**
* @brief   CRC 8 H2F LOOK-UP TABLE
*/
static const uint8 s_TableCrc8H2F[256U] = {
    0x00U, 0x2FU, 0x5EU, 0x71U, 0xBCU, 0x93U, 0xE2U, 0xCDU, 0x57U, 0x78U, 0x09U, 0x26U, 0xEBU, 0xC4U, 0xB5U, 0x9AU,
    0xAEU, 0x81U, 0xF0U, 0xDFU, 0x12U, 0x3DU, 0x4CU, 0x63U, 0xF9U, 0xD6U, 0xA7U, 0x88U, 0x45U, 0x6AU, 0x1BU, 0x34U,
    0x73U, 0x5CU, 0x2DU, 0x02U, 0xCFU, 0xE0U, 0x91U, 0xBEU, 0x24U, 0x0BU, 0x7AU, 0x55U, 0x98U, 0xB7U, 0xC6U, 0xE9U,
    0xDDU, 0xF2U, 0x83U, 0xACU, 0x61U, 0x4EU, 0x3FU, 0x10U, 0x8AU, 0xA5U, 0xD4U, 0xFBU, 0x36U, 0x19U, 0x68U, 0x47U,
    0xE6U, 0xC9U, 0xB8U, 0x97U, 0x5AU, 0x75U, 0x04U, 0x2BU, 0xB1U, 0x9EU, 0xEFU, 0xC0U, 0x0DU, 0x22U, 0x53U, 0x7CU,
    0x48U, 0x67U, 0x16U, 0x39U, 0xF4U, 0xDBU, 0xAAU, 0x85U, 0x1FU, 0x30U, 0x41U, 0x6EU, 0xA3U, 0x8CU, 0xFDU, 0xD2U,
    0x95U, 0xBAU, 0xCBU, 0xE4U, 0x29U, 0x06U, 0x77U, 0x58U, 0xC2U, 0xEDU, 0x9CU, 0xB3U, 0x7EU, 0x51U, 0x20U, 0x0FU,
    0x3BU, 0x14U, 0x65U, 0x4AU, 0x87U, 0xA8U, 0xD9U, 0xF6U, 0x6CU, 0x43U, 0x32U, 0x1DU, 0xD0U, 0xFFU, 0x8EU, 0xA1U,
    0xE3U, 0xCCU, 0xBDU, 0x92U, 0x5FU, 0x70U, 0x01U, 0x2EU, 0xB4U, 0x9BU, 0xEAU, 0xC5U, 0x08U, 0x27U, 0x56U, 0x79U,
    0x4DU, 0x62U, 0x13U, 0x3CU, 0xF1U, 0xDEU, 0xAFU, 0x80U, 0x1AU, 0x35U, 0x44U, 0x6BU, 0xA6U, 0x89U, 0xF8U, 0xD7U,
    0x90U, 0xBFU, 0xCEU, 0xE1U, 0x2CU, 0x03U, 0x72U, 0x5DU, 0xC7U, 0xE8U, 0x99U, 0xB6U, 0x7BU, 0x54U, 0x25U, 0x0AU,
    0x3EU, 0x11U, 0x60U, 0x4FU, 0x82U, 0xADU, 0xDCU, 0xF3U, 0x69U, 0x46U, 0x37U, 0x18U, 0xD5U, 0xFAU, 0x8BU, 0xA4U,
    0x05U, 0x2AU, 0x5BU, 0x74U, 0xB9U, 0x96U, 0xE7U, 0xC8U, 0x52U, 0x7DU, 0x0CU, 0x23U, 0xEEU, 0xC1U, 0xB0U, 0x9FU,
    0xABU, 0x84U, 0xF5U, 0xDAU, 0x17U, 0x38U, 0x49U, 0x66U, 0xFCU, 0xD3U, 0xA2U, 0x8DU, 0x40U, 0x6FU, 0x1EU, 0x31U,
    0x76U, 0x59U, 0x28U, 0x07U, 0xCAU, 0xE5U, 0x94U, 0xBBU, 0x21U, 0x0EU, 0x7FU, 0x50U, 0x9DU, 0xB2U, 0xC3U, 0xECU,
    0xD8U, 0xF7U, 0x86U, 0xA9U, 0x64U, 0x4BU, 0x3AU, 0x15U, 0x8FU, 0xA0U, 0xD1U, 0xFEU, 0x33U, 0x1CU, 0x6DU, 0x42U
};
#define CRC_STOP_SEC_CONST_8
#include "Crc_MemMap.h"

#endif /* #if (STD_ON == CRC_IP_8BIT_H2F_TABLE) */


#if (STD_ON == CRC_IP_16BIT_CCITT_FALSE_TABLE)

#define CRC_START_SEC_CONST_16
#include "Crc_MemMap.h"
/**
* @brief   CRC 16 CCITT_FALSE LOOK-UP TABLE
*/
static const uint16 s_TableCrc16[256U] = {
    0x0000U, 0x1021U, 0x2042U, 0x3063U, 0x4084U, 0x50A5U, 0x60C6U, 0x70E7U, 0x8108U, 0x9129U, 0xA14AU, 0xB16BU,
    0xC18CU, 0xD1ADU, 0xE1CEU, 0xF1EFU, 0x1231U, 0x0210U, 0x3273U, 0x2252U, 0x52B5U, 0x4294U, 0x72F7U, 0x62D6U,
    0x9339U, 0x8318U, 0xB37BU, 0xA35AU, 0xD3BDU, 0xC39CU, 0xF3FFU, 0xE3DEU, 0x2462U, 0x3443U, 0x0420U, 0x1401U,
    0x64E6U, 0x74C7U, 0x44A4U, 0x5485U, 0xA56AU, 0xB54BU, 0x8528U, 0x9509U, 0xE5EEU, 0xF5CFU, 0xC5ACU, 0xD58DU,
    0x3653U, 0x2672U, 0x1611U, 0x0630U, 0x76D7U, 0x66F6U, 0x5695U, 0x46B4U, 0xB75BU, 0xA77AU, 0x9719U, 0x8738U,
    0xF7DFU, 0xE7FEU, 0xD79DU, 0xC7BCU, 0x48C4U, 0x58E5U, 0x6886U, 0x78A7U, 0x0840U, 0x1861U, 0x2802U, 0x3823U,
    0xC9CCU, 0xD9EDU, 0xE98EU, 0xF9AFU, 0x8948U, 0x9969U, 0xA90AU, 0xB92BU, 0x5AF5U, 0x4AD4U, 0x7AB7U, 0x6A96U,
    0x1A71U, 0x0A50U, 0x3A33U, 0x2A12U, 0xDBFDU, 0xCBDCU, 0xFBBFU, 0xEB9EU, 0x9B79U, 0x8B58U, 0xBB3BU, 0xAB1AU,
    0x6CA6U, 0x7C87U, 0x4CE4U, 0x5CC5U, 0x2C22U, 0x3C03U, 0x0C60U, 0x1C41U, 0xEDAEU, 0xFD8FU, 0xCDECU, 0xDDCDU,
    0xAD2AU, 0xBD0BU, 0x8D68U, 0x9D49U, 0x7E97U, 0x6EB6U, 0x5ED5U, 0x4EF4U, 0x3E13U, 0x2E32U, 0x1E51U, 0x0E70U,
    0xFF9FU, 0xEFBEU, 0xDFDDU, 0xCFFCU, 0xBF1BU, 0xAF3AU, 0x9F59U, 0x8F78U, 0x9188U, 0x81A9U, 0xB1CAU, 0xA1EBU,
    0xD10CU, 0xC12DU, 0xF14EU, 0xE16FU, 0x1080U, 0x00A1U, 0x30C2U, 0x20E3U, 0x5004U, 0x4025U, 0x7046U, 0x6067U,
    0x83B9U, 0x9398U, 0xA3FBU, 0xB3DAU, 0xC33DU, 0xD31CU, 0xE37FU, 0xF35EU, 0x02B1U, 0x1290U, 0x22F3U, 0x32D2U,
    0x4235U, 0x5214U, 0x6277U, 0x7256U, 0xB5EAU, 0xA5CBU, 0x95A8U, 0x8589U, 0xF56EU, 0xE54FU, 0xD52CU, 0xC50DU,
    0x34E2U, 0x24C3U, 0x14A0U, 0x0481U, 0x7466U, 0x6447U, 0x5424U, 0x4405U, 0xA7DBU, 0xB7FAU, 0x8799U, 0x97B8U,
    0xE75FU, 0xF77EU, 0xC71DU, 0xD73CU, 0x26D3U, 0x36F2U, 0x0691U, 0x16B0U, 0x6657U, 0x7676U, 0x4615U, 0x5634U,
    0xD94CU, 0xC96DU, 0xF90EU, 0xE92FU, 0x99C8U, 0x89E9U, 0xB98AU, 0xA9ABU, 0x5844U, 0x4865U, 0x7806U, 0x6827U,
    0x18C0U, 0x08E1U, 0x3882U, 0x28A3U, 0xCB7DU, 0xDB5CU, 0xEB3FU, 0xFB1EU, 0x8BF9U, 0x9BD8U, 0xABBBU, 0xBB9AU,
    0x4A75U, 0x5A54U, 0x6A37U, 0x7A16U, 0x0AF1U, 0x1AD0U, 0x2AB3U, 0x3A92U, 0xFD2EU, 0xED0FU, 0xDD6CU, 0xCD4DU,
    0xBDAAU, 0xAD8BU, 0x9DE8U, 0x8DC9U, 0x7C26U, 0x6C07U, 0x5C64U, 0x4C45U, 0x3CA2U, 0x2C83U, 0x1CE0U, 0x0CC1U,
    0xEF1FU, 0xFF3EU, 0xCF5DU, 0xDF7CU, 0xAF9BU, 0xBFBAU, 0x8FD9U, 0x9FF8U, 0x6E17U, 0x7E36U, 0x4E55U, 0x5E74U,
    0x2E93U, 0x3EB2U, 0x0ED1U, 0x1EF0U
};
#define CRC_STOP_SEC_CONST_16
#include "Crc_MemMap.h"

#endif /* #if (STD_ON == CRC_IP_16BIT_CCITT_FALSE_TABLE) */


#if (STD_ON == CRC_IP_16BIT_ARC_TABLE)

#define CRC_START_SEC_CONST_16
#include "Crc_MemMap.h"
/**
* @brief   CRC 16 ARC TABLE
*/
static const uint16 s_TableCrc16ARC[256U] = {
    0x0000U, 0x8005U, 0x800FU, 0x000AU, 0x801BU, 0x001EU, 0x0014U, 0x8011U, 0x8033U, 0x0036U, 0x003CU, 0x8039U,
    0x0028U, 0x802DU, 0x8027U, 0x0022U, 0x8063U, 0x0066U, 0x006CU, 0x8069U, 0x0078U, 0x807DU, 0x8077U, 0x0072U,
    0x0050U, 0x8055U, 0x805FU, 0x005AU, 0x804BU, 0x004EU, 0x0044U, 0x8041U, 0x80C3U, 0x00C6U, 0x00CCU, 0x80C9U,
    0x00D8U, 0x80DDU, 0x80D7U, 0x00D2U, 0x00F0U, 0x80F5U, 0x80FFU, 0x00FAU, 0x80EBU, 0x00EEU, 0x00E4U, 0x80E1U,
    0x00A0U, 0x80A5U, 0x80AFU, 0x00AAU, 0x80BBU, 0x00BEU, 0x00B4U, 0x80B1U, 0x8093U, 0x0096U, 0x009CU, 0x8099U,
    0x0088U, 0x808DU, 0x8087U, 0x0082U, 0x8183U, 0x0186U, 0x018CU, 0x8189U, 0x0198U, 0x819DU, 0x8197U, 0x0192U,
    0x01B0U, 0x81B5U, 0x81BFU, 0x01BAU, 0x81ABU, 0x01AEU, 0x01A4U, 0x81A1U, 0x01E0U, 0x81E5U, 0x81EFU, 0x01EAU,
    0x81FBU, 0x01FEU, 0x01F4U, 0x81F1U, 0x81D3U, 0x01D6U, 0x01DCU, 0x81D9U, 0x01C8U, 0x81CDU, 0x81C7U, 0x01C2U,
    0x0140U, 0x8145U, 0x814FU, 0x014AU, 0x815BU, 0x015EU, 0x0154U, 0x8151U, 0x8173U, 0x0176U, 0x017CU, 0x8179U,
    0x0168U, 0x816DU, 0x8167U, 0x0162U, 0x8123U, 0x0126U, 0x012CU, 0x8129U, 0x0138U, 0x813DU, 0x8137U, 0x0132U,
    0x0110U, 0x8115U, 0x811FU, 0x011AU, 0x810BU, 0x010EU, 0x0104U, 0x8101U, 0x8303U, 0x0306U, 0x030CU, 0x8309U,
    0x0318U, 0x831DU, 0x8317U, 0x0312U, 0x0330U, 0x8335U, 0x833FU, 0x033AU, 0x832BU, 0x032EU, 0x0324U, 0x8321U,
    0x0360U, 0x8365U, 0x836FU, 0x036AU, 0x837BU, 0x037EU, 0x0374U, 0x8371U, 0x8353U, 0x0356U, 0x035CU, 0x8359U,
    0x0348U, 0x834DU, 0x8347U, 0x0342U, 0x03C0U, 0x83C5U, 0x83CFU, 0x03CAU, 0x83DBU, 0x03DEU, 0x03D4U, 0x83D1U,
    0x83F3U, 0x03F6U, 0x03FCU, 0x83F9U, 0x03E8U, 0x83EDU, 0x83E7U, 0x03E2U, 0x83A3U, 0x03A6U, 0x03ACU, 0x83A9U,
    0x03B8U, 0x83BDU, 0x83B7U, 0x03B2U, 0x0390U, 0x8395U, 0x839FU, 0x039AU, 0x838BU, 0x038EU, 0x0384U, 0x8381U,
    0x0280U, 0x8285U, 0x828FU, 0x028AU, 0x829BU, 0x029EU, 0x0294U, 0x8291U, 0x82B3U, 0x02B6U, 0x02BCU, 0x82B9U,
    0x02A8U, 0x82ADU, 0x82A7U, 0x02A2U, 0x82E3U, 0x02E6U, 0x02ECU, 0x82E9U, 0x02F8U, 0x82FDU, 0x82F7U, 0x02F2U,
    0x02D0U, 0x82D5U, 0x82DFU, 0x02DAU, 0x82CBU, 0x02CEU, 0x02C4U, 0x82C1U, 0x8243U, 0x0246U, 0x024CU, 0x8249U,
    0x0258U, 0x825DU, 0x8257U, 0x0252U, 0x0270U, 0x8275U, 0x827FU, 0x027AU, 0x826BU, 0x026EU, 0x0264U, 0x8261U,
    0x0220U, 0x8225U, 0x822FU, 0x022AU, 0x823BU, 0x023EU, 0x0234U, 0x8231U, 0x8213U, 0x0216U, 0x021CU, 0x8219U,
    0x0208U, 0x820DU, 0x8207U, 0x0202U
};
#define CRC_STOP_SEC_CONST_16
#include "Crc_MemMap.h"

#endif /* #if (STD_ON == CRC_IP_16BIT_ARC_TABLE) */


#if (STD_ON == CRC_IP_32BIT_ETHERNET_TABLE)

#define CRC_START_SEC_CONST_32
#include "Crc_MemMap.h"
/**
* @brief   CRC 32 TABLE
*/
static const uint32 s_TableCrc32[256U] = {
    0x00000000U, 0x04C11DB7U, 0x09823B6EU, 0x0D4326D9U, 0x130476DCU, 0x17C56B6BU, 0x1A864DB2U, 0x1E475005U,
    0x2608EDB8U, 0x22C9F00FU, 0x2F8AD6D6U, 0x2B4BCB61U, 0x350C9B64U, 0x31CD86D3U, 0x3C8EA00AU, 0x384FBDBDU,
    0x4C11DB70U, 0x48D0C6C7U, 0x4593E01EU, 0x4152FDA9U, 0x5F15ADACU, 0x5BD4B01BU, 0x569796C2U, 0x52568B75U,
    0x6A1936C8U, 0x6ED82B7FU, 0x639B0DA6U, 0x675A1011U, 0x791D4014U, 0x7DDC5DA3U, 0x709F7B7AU, 0x745E66CDU,
    0x9823B6E0U, 0x9CE2AB57U, 0x91A18D8EU, 0x95609039U, 0x8B27C03CU, 0x8FE6DD8BU, 0x82A5FB52U, 0x8664E6E5U,
    0xBE2B5B58U, 0xBAEA46EFU, 0xB7A96036U, 0xB3687D81U, 0xAD2F2D84U, 0xA9EE3033U, 0xA4AD16EAU, 0xA06C0B5DU,
    0xD4326D90U, 0xD0F37027U, 0xDDB056FEU, 0xD9714B49U, 0xC7361B4CU, 0xC3F706FBU, 0xCEB42022U, 0xCA753D95U,
    0xF23A8028U, 0xF6FB9D9FU, 0xFBB8BB46U, 0xFF79A6F1U, 0xE13EF6F4U, 0xE5FFEB43U, 0xE8BCCD9AU, 0xEC7DD02DU,
    0x34867077U, 0x30476DC0U, 0x3D044B19U, 0x39C556AEU, 0x278206ABU, 0x23431B1CU, 0x2E003DC5U, 0x2AC12072U,
    0x128E9DCFU, 0x164F8078U, 0x1B0CA6A1U, 0x1FCDBB16U, 0x018AEB13U, 0x054BF6A4U, 0x0808D07DU, 0x0CC9CDCAU,
    0x7897AB07U, 0x7C56B6B0U, 0x71159069U, 0x75D48DDEU, 0x6B93DDDBU, 0x6F52C06CU, 0x6211E6B5U, 0x66D0FB02U,
    0x5E9F46BFU, 0x5A5E5B08U, 0x571D7DD1U, 0x53DC6066U, 0x4D9B3063U, 0x495A2DD4U, 0x44190B0DU, 0x40D816BAU,
    0xACA5C697U, 0xA864DB20U, 0xA527FDF9U, 0xA1E6E04EU, 0xBFA1B04BU, 0xBB60ADFCU, 0xB6238B25U, 0xB2E29692U,
    0x8AAD2B2FU, 0x8E6C3698U, 0x832F1041U, 0x87EE0DF6U, 0x99A95DF3U, 0x9D684044U, 0x902B669DU, 0x94EA7B2AU,
    0xE0B41DE7U, 0xE4750050U, 0xE9362689U, 0xEDF73B3EU, 0xF3B06B3BU, 0xF771768CU, 0xFA325055U, 0xFEF34DE2U,
    0xC6BCF05FU, 0xC27DEDE8U, 0xCF3ECB31U, 0xCBFFD686U, 0xD5B88683U, 0xD1799B34U, 0xDC3ABDEDU, 0xD8FBA05AU,
    0x690CE0EEU, 0x6DCDFD59U, 0x608EDB80U, 0x644FC637U, 0x7A089632U, 0x7EC98B85U, 0x738AAD5CU, 0x774BB0EBU,
    0x4F040D56U, 0x4BC510E1U, 0x46863638U, 0x42472B8FU, 0x5C007B8AU, 0x58C1663DU, 0x558240E4U, 0x51435D53U,
    0x251D3B9EU, 0x21DC2629U, 0x2C9F00F0U, 0x285E1D47U, 0x36194D42U, 0x32D850F5U, 0x3F9B762CU, 0x3B5A6B9BU,
    0x0315D626U, 0x07D4CB91U, 0x0A97ED48U, 0x0E56F0FFU, 0x1011A0FAU, 0x14D0BD4DU, 0x19939B94U, 0x1D528623U,
    0xF12F560EU, 0xF5EE4BB9U, 0xF8AD6D60U, 0xFC6C70D7U, 0xE22B20D2U, 0xE6EA3D65U, 0xEBA91BBCU, 0xEF68060BU,
    0xD727BBB6U, 0xD3E6A601U, 0xDEA580D8U, 0xDA649D6FU, 0xC423CD6AU, 0xC0E2D0DDU, 0xCDA1F604U, 0xC960EBB3U,
    0xBD3E8D7EU, 0xB9FF90C9U, 0xB4BCB610U, 0xB07DABA7U, 0xAE3AFBA2U, 0xAAFBE615U, 0xA7B8C0CCU, 0xA379DD7BU,
    0x9B3660C6U, 0x9FF77D71U, 0x92B45BA8U, 0x9675461FU, 0x8832161AU, 0x8CF30BADU, 0x81B02D74U, 0x857130C3U,
    0x5D8A9099U, 0x594B8D2EU, 0x5408ABF7U, 0x50C9B640U, 0x4E8EE645U, 0x4A4FFBF2U, 0x470CDD2BU, 0x43CDC09CU,
    0x7B827D21U, 0x7F436096U, 0x7200464FU, 0x76C15BF8U, 0x68860BFDU, 0x6C47164AU, 0x61043093U, 0x65C52D24U,
    0x119B4BE9U, 0x155A565EU, 0x18197087U, 0x1CD86D30U, 0x029F3D35U, 0x065E2082U, 0x0B1D065BU, 0x0FDC1BECU,
    0x3793A651U, 0x3352BBE6U, 0x3E119D3FU, 0x3AD08088U, 0x2497D08DU, 0x2056CD3AU, 0x2D15EBE3U, 0x29D4F654U,
    0xC5A92679U, 0xC1683BCEU, 0xCC2B1D17U, 0xC8EA00A0U, 0xD6AD50A5U, 0xD26C4D12U, 0xDF2F6BCBU, 0xDBEE767CU,
    0xE3A1CBC1U, 0xE760D676U, 0xEA23F0AFU, 0xEEE2ED18U, 0xF0A5BD1DU, 0xF464A0AAU, 0xF9278673U, 0xFDE69BC4U,
    0x89B8FD09U, 0x8D79E0BEU, 0x803AC667U, 0x84FBDBD0U, 0x9ABC8BD5U, 0x9E7D9662U, 0x933EB0BBU, 0x97FFAD0CU,
    0xAFB010B1U, 0xAB710D06U, 0xA6322BDFU, 0xA2F33668U, 0xBCB4666DU, 0xB8757BDAU, 0xB5365D03U, 0xB1F740B4U
};
#define CRC_STOP_SEC_CONST_32
#include "Crc_MemMap.h"

#endif /* #if (STD_ON == CRC_IP_32BIT_ETHERNET_TABLE) */


#if (STD_ON == CRC_IP_32BIT_E2E_P4_TABLE)

#define CRC_START_SEC_CONST_32
#include "Crc_MemMap.h"
/**
* @brief   CRC 32P4 TABLE
*/
static const uint32 s_TableCrc32P4[256U] = {
    0x00000000U, 0xF4ACFB13U, 0x1DF50D35U, 0xE959F626U, 0x3BEA1A6AU, 0xCF46E179U, 0x261F175FU, 0xD2B3EC4CU,
    0x77D434D4U, 0x8378CFC7U, 0x6A2139E1U, 0x9E8DC2F2U, 0x4C3E2EBEU, 0xB892D5ADU, 0x51CB238BU, 0xA567D898U,
    0xEFA869A8U, 0x1B0492BBU, 0xF25D649DU, 0x06F19F8EU, 0xD44273C2U, 0x20EE88D1U, 0xC9B77EF7U, 0x3D1B85E4U,
    0x987C5D7CU, 0x6CD0A66FU, 0x85895049U, 0x7125AB5AU, 0xA3964716U, 0x573ABC05U, 0xBE634A23U, 0x4ACFB130U,
    0x2BFC2843U, 0xDF50D350U, 0x36092576U, 0xC2A5DE65U, 0x10163229U, 0xE4BAC93AU, 0x0DE33F1CU, 0xF94FC40FU,
    0x5C281C97U, 0xA884E784U, 0x41DD11A2U, 0xB571EAB1U, 0x67C206FDU, 0x936EFDEEU, 0x7A370BC8U, 0x8E9BF0DBU,
    0xC45441EBU, 0x30F8BAF8U, 0xD9A14CDEU, 0x2D0DB7CDU, 0xFFBE5B81U, 0x0B12A092U, 0xE24B56B4U, 0x16E7ADA7U,
    0xB380753FU, 0x472C8E2CU, 0xAE75780AU, 0x5AD98319U, 0x886A6F55U, 0x7CC69446U, 0x959F6260U, 0x61339973U,
    0x57F85086U, 0xA354AB95U, 0x4A0D5DB3U, 0xBEA1A6A0U, 0x6C124AECU, 0x98BEB1FFU, 0x71E747D9U, 0x854BBCCAU,
    0x202C6452U, 0xD4809F41U, 0x3DD96967U, 0xC9759274U, 0x1BC67E38U, 0xEF6A852BU, 0x0633730DU, 0xF29F881EU,
    0xB850392EU, 0x4CFCC23DU, 0xA5A5341BU, 0x5109CF08U, 0x83BA2344U, 0x7716D857U, 0x9E4F2E71U, 0x6AE3D562U,
    0xCF840DFAU, 0x3B28F6E9U, 0xD27100CFU, 0x26DDFBDCU, 0xF46E1790U, 0x00C2EC83U, 0xE99B1AA5U, 0x1D37E1B6U,
    0x7C0478C5U, 0x88A883D6U, 0x61F175F0U, 0x955D8EE3U, 0x47EE62AFU, 0xB34299BCU, 0x5A1B6F9AU, 0xAEB79489U,
    0x0BD04C11U, 0xFF7CB702U, 0x16254124U, 0xE289BA37U, 0x303A567BU, 0xC496AD68U, 0x2DCF5B4EU, 0xD963A05DU,
    0x93AC116DU, 0x6700EA7EU, 0x8E591C58U, 0x7AF5E74BU, 0xA8460B07U, 0x5CEAF014U, 0xB5B30632U, 0x411FFD21U,
    0xE47825B9U, 0x10D4DEAAU, 0xF98D288CU, 0x0D21D39FU, 0xDF923FD3U, 0x2B3EC4C0U, 0xC26732E6U, 0x36CBC9F5U,
    0xAFF0A10CU, 0x5B5C5A1FU, 0xB205AC39U, 0x46A9572AU, 0x941ABB66U, 0x60B64075U, 0x89EFB653U, 0x7D434D40U,
    0xD82495D8U, 0x2C886ECBU, 0xC5D198EDU, 0x317D63FEU, 0xE3CE8FB2U, 0x176274A1U, 0xFE3B8287U, 0x0A977994U,
    0x4058C8A4U, 0xB4F433B7U, 0x5DADC591U, 0xA9013E82U, 0x7BB2D2CEU, 0x8F1E29DDU, 0x6647DFFBU, 0x92EB24E8U,
    0x378CFC70U, 0xC3200763U, 0x2A79F145U, 0xDED50A56U, 0x0C66E61AU, 0xF8CA1D09U, 0x1193EB2FU, 0xE53F103CU,
    0x840C894FU, 0x70A0725CU, 0x99F9847AU, 0x6D557F69U, 0xBFE69325U, 0x4B4A6836U, 0xA2139E10U, 0x56BF6503U,
    0xF3D8BD9BU, 0x07744688U, 0xEE2DB0AEU, 0x1A814BBDU, 0xC832A7F1U, 0x3C9E5CE2U, 0xD5C7AAC4U, 0x216B51D7U,
    0x6BA4E0E7U, 0x9F081BF4U, 0x7651EDD2U, 0x82FD16C1U, 0x504EFA8DU, 0xA4E2019EU, 0x4DBBF7B8U, 0xB9170CABU,
    0x1C70D433U, 0xE8DC2F20U, 0x0185D906U, 0xF5292215U, 0x279ACE59U, 0xD336354AU, 0x3A6FC36CU, 0xCEC3387FU,
    0xF808F18AU, 0x0CA40A99U, 0xE5FDFCBFU, 0x115107ACU, 0xC3E2EBE0U, 0x374E10F3U, 0xDE17E6D5U, 0x2ABB1DC6U,
    0x8FDCC55EU, 0x7B703E4DU, 0x9229C86BU, 0x66853378U, 0xB436DF34U, 0x409A2427U, 0xA9C3D201U, 0x5D6F2912U,
    0x17A09822U, 0xE30C6331U, 0x0A559517U, 0xFEF96E04U, 0x2C4A8248U, 0xD8E6795BU, 0x31BF8F7DU, 0xC513746EU,
    0x6074ACF6U, 0x94D857E5U, 0x7D81A1C3U, 0x892D5AD0U, 0x5B9EB69CU, 0xAF324D8FU, 0x466BBBA9U, 0xB2C740BAU,
    0xD3F4D9C9U, 0x275822DAU, 0xCE01D4FCU, 0x3AAD2FEFU, 0xE81EC3A3U, 0x1CB238B0U, 0xF5EBCE96U, 0x01473585U,
    0xA420ED1DU, 0x508C160EU, 0xB9D5E028U, 0x4D791B3BU, 0x9FCAF777U, 0x6B660C64U, 0x823FFA42U, 0x76930151U,
    0x3C5CB061U, 0xC8F04B72U, 0x21A9BD54U, 0xD5054647U, 0x07B6AA0BU, 0xF31A5118U, 0x1A43A73EU, 0xEEEF5C2DU,
    0x4B8884B5U, 0xBF247FA6U, 0x567D8980U, 0xA2D17293U, 0x70629EDFU, 0x84CE65CCU, 0x6D9793EAU, 0x993B68F9U
};
#define CRC_STOP_SEC_CONST_32
#include "Crc_MemMap.h"

#endif /* #if (STD_ON == CRC_IP_32BIT_E2E_P4_TABLE) */


#if (STD_ON == CRC_IP_64BIT_ECMA_TABLE)

#define CRC_START_SEC_CONST_UNSPECIFIED
#include "Crc_MemMap.h"
/**
* @brief   CRC 64 ECMA-182 LOOK-UP TABLE
*/
static const uint64 s_TableCrc64ECMA[256U] = {
0x0000000000000000U, 0x42F0E1EBA9EA3693U, 0x85E1C3D753D46D26U, 0xC711223CFA3E5BB5U, 0x493366450E42ECDFU, 0x0BC387AEA7A8DA4CU, 0xCCD2A5925D9681F9U, 0x8E224479F47CB76AU,
0x9266CC8A1C85D9BEU, 0xD0962D61B56FEF2DU, 0x17870F5D4F51B498U, 0x5577EEB6E6BB820BU, 0xDB55AACF12C73561U, 0x99A54B24BB2D03F2U, 0x5EB4691841135847U, 0x1C4488F3E8F96ED4U,
0x663D78FF90E185EFU, 0x24CD9914390BB37CU, 0xE3DCBB28C335E8C9U, 0xA12C5AC36ADFDE5AU, 0x2F0E1EBA9EA36930U, 0x6DFEFF5137495FA3U, 0xAAEFDD6DCD770416U, 0xE81F3C86649D3285U,
0xF45BB4758C645C51U, 0xB6AB559E258E6AC2U, 0x71BA77A2DFB03177U, 0x334A9649765A07E4U, 0xBD68D2308226B08EU, 0xFF9833DB2BCC861DU, 0x388911E7D1F2DDA8U, 0x7A79F00C7818EB3BU,
0xCC7AF1FF21C30BDEU, 0x8E8A101488293D4DU, 0x499B3228721766F8U, 0x0B6BD3C3DBFD506BU, 0x854997BA2F81E701U, 0xC7B97651866BD192U, 0x00A8546D7C558A27U, 0x4258B586D5BFBCB4U,
0x5E1C3D753D46D260U, 0x1CECDC9E94ACE4F3U, 0xDBFDFEA26E92BF46U, 0x990D1F49C77889D5U, 0x172F5B3033043EBFU, 0x55DFBADB9AEE082CU, 0x92CE98E760D05399U, 0xD03E790CC93A650AU,
0xAA478900B1228E31U, 0xE8B768EB18C8B8A2U, 0x2FA64AD7E2F6E317U, 0x6D56AB3C4B1CD584U, 0xE374EF45BF6062EEU, 0xA1840EAE168A547DU, 0x66952C92ECB40FC8U, 0x2465CD79455E395BU,
0x3821458AADA7578FU, 0x7AD1A461044D611CU, 0xBDC0865DFE733AA9U, 0xFF3067B657990C3AU, 0x711223CFA3E5BB50U, 0x33E2C2240A0F8DC3U, 0xF4F3E018F031D676U, 0xB60301F359DBE0E5U,
0xDA050215EA6C212FU, 0x98F5E3FE438617BCU, 0x5FE4C1C2B9B84C09U, 0x1D14202910527A9AU, 0x93366450E42ECDF0U, 0xD1C685BB4DC4FB63U, 0x16D7A787B7FAA0D6U, 0x5427466C1E109645U,
0x4863CE9FF6E9F891U, 0x0A932F745F03CE02U, 0xCD820D48A53D95B7U, 0x8F72ECA30CD7A324U, 0x0150A8DAF8AB144EU, 0x43A04931514122DDU, 0x84B16B0DAB7F7968U, 0xC6418AE602954FFBU,
0xBC387AEA7A8DA4C0U, 0xFEC89B01D3679253U, 0x39D9B93D2959C9E6U, 0x7B2958D680B3FF75U, 0xF50B1CAF74CF481FU, 0xB7FBFD44DD257E8CU, 0x70EADF78271B2539U, 0x321A3E938EF113AAU,
0x2E5EB66066087D7EU, 0x6CAE578BCFE24BEDU, 0xABBF75B735DC1058U, 0xE94F945C9C3626CBU, 0x676DD025684A91A1U, 0x259D31CEC1A0A732U, 0xE28C13F23B9EFC87U, 0xA07CF2199274CA14U,
0x167FF3EACBAF2AF1U, 0x548F120162451C62U, 0x939E303D987B47D7U, 0xD16ED1D631917144U, 0x5F4C95AFC5EDC62EU, 0x1DBC74446C07F0BDU, 0xDAAD56789639AB08U, 0x985DB7933FD39D9BU,
0x84193F60D72AF34FU, 0xC6E9DE8B7EC0C5DCU, 0x01F8FCB784FE9E69U, 0x43081D5C2D14A8FAU, 0xCD2A5925D9681F90U, 0x8FDAB8CE70822903U, 0x48CB9AF28ABC72B6U, 0x0A3B7B1923564425U,
0x70428B155B4EAF1EU, 0x32B26AFEF2A4998DU, 0xF5A348C2089AC238U, 0xB753A929A170F4ABU, 0x3971ED50550C43C1U, 0x7B810CBBFCE67552U, 0xBC902E8706D82EE7U, 0xFE60CF6CAF321874U,
0xE224479F47CB76A0U, 0xA0D4A674EE214033U, 0x67C58448141F1B86U, 0x253565A3BDF52D15U, 0xAB1721DA49899A7FU, 0xE9E7C031E063ACECU, 0x2EF6E20D1A5DF759U, 0x6C0603E6B3B7C1CAU,
0xF6FAE5C07D3274CDU, 0xB40A042BD4D8425EU, 0x731B26172EE619EBU, 0x31EBC7FC870C2F78U, 0xBFC9838573709812U, 0xFD39626EDA9AAE81U, 0x3A28405220A4F534U, 0x78D8A1B9894EC3A7U,
0x649C294A61B7AD73U, 0x266CC8A1C85D9BE0U, 0xE17DEA9D3263C055U, 0xA38D0B769B89F6C6U, 0x2DAF4F0F6FF541ACU, 0x6F5FAEE4C61F773FU, 0xA84E8CD83C212C8AU, 0xEABE6D3395CB1A19U,
0x90C79D3FEDD3F122U, 0xD2377CD44439C7B1U, 0x15265EE8BE079C04U, 0x57D6BF0317EDAA97U, 0xD9F4FB7AE3911DFDU, 0x9B041A914A7B2B6EU, 0x5C1538ADB04570DBU, 0x1EE5D94619AF4648U,
0x02A151B5F156289CU, 0x4051B05E58BC1E0FU, 0x87409262A28245BAU, 0xC5B073890B687329U, 0x4B9237F0FF14C443U, 0x0962D61B56FEF2D0U, 0xCE73F427ACC0A965U, 0x8C8315CC052A9FF6U,
0x3A80143F5CF17F13U, 0x7870F5D4F51B4980U, 0xBF61D7E80F251235U, 0xFD913603A6CF24A6U, 0x73B3727A52B393CCU, 0x31439391FB59A55FU, 0xF652B1AD0167FEEAU, 0xB4A25046A88DC879U,
0xA8E6D8B54074A6ADU, 0xEA16395EE99E903EU, 0x2D071B6213A0CB8BU, 0x6FF7FA89BA4AFD18U, 0xE1D5BEF04E364A72U, 0xA3255F1BE7DC7CE1U, 0x64347D271DE22754U, 0x26C49CCCB40811C7U,
0x5CBD6CC0CC10FAFCU, 0x1E4D8D2B65FACC6FU, 0xD95CAF179FC497DAU, 0x9BAC4EFC362EA149U, 0x158E0A85C2521623U, 0x577EEB6E6BB820B0U, 0x906FC95291867B05U, 0xD29F28B9386C4D96U,
0xCEDBA04AD0952342U, 0x8C2B41A1797F15D1U, 0x4B3A639D83414E64U, 0x09CA82762AAB78F7U, 0x87E8C60FDED7CF9DU, 0xC51827E4773DF90EU, 0x020905D88D03A2BBU, 0x40F9E43324E99428U,
0x2CFFE7D5975E55E2U, 0x6E0F063E3EB46371U, 0xA91E2402C48A38C4U, 0xEBEEC5E96D600E57U, 0x65CC8190991CB93DU, 0x273C607B30F68FAEU, 0xE02D4247CAC8D41BU, 0xA2DDA3AC6322E288U,
0xBE992B5F8BDB8C5CU, 0xFC69CAB42231BACFU, 0x3B78E888D80FE17AU, 0x7988096371E5D7E9U, 0xF7AA4D1A85996083U, 0xB55AACF12C735610U, 0x724B8ECDD64D0DA5U, 0x30BB6F267FA73B36U,
0x4AC29F2A07BFD00DU, 0x08327EC1AE55E69EU, 0xCF235CFD546BBD2BU, 0x8DD3BD16FD818BB8U, 0x03F1F96F09FD3CD2U, 0x41011884A0170A41U, 0x86103AB85A2951F4U, 0xC4E0DB53F3C36767U,
0xD8A453A01B3A09B3U, 0x9A54B24BB2D03F20U, 0x5D45907748EE6495U, 0x1FB5719CE1045206U, 0x919735E51578E56CU, 0xD367D40EBC92D3FFU, 0x1476F63246AC884AU, 0x568617D9EF46BED9U,
0xE085162AB69D5E3CU, 0xA275F7C11F7768AFU, 0x6564D5FDE549331AU, 0x279434164CA30589U, 0xA9B6706FB8DFB2E3U, 0xEB46918411358470U, 0x2C57B3B8EB0BDFC5U, 0x6EA7525342E1E956U,
0x72E3DAA0AA188782U, 0x30133B4B03F2B111U, 0xF7021977F9CCEAA4U, 0xB5F2F89C5026DC37U, 0x3BD0BCE5A45A6B5DU, 0x79205D0E0DB05DCEU, 0xBE317F32F78E067BU, 0xFCC19ED95E6430E8U,
0x86B86ED5267CDBD3U, 0xC4488F3E8F96ED40U, 0x0359AD0275A8B6F5U, 0x41A94CE9DC428066U, 0xCF8B0890283E370CU, 0x8D7BE97B81D4019FU, 0x4A6ACB477BEA5A2AU, 0x089A2AACD2006CB9U,
0x14DEA25F3AF9026DU, 0x562E43B4931334FEU, 0x913F6188692D6F4BU, 0xD3CF8063C0C759D8U, 0x5DEDC41A34BBEEB2U, 0x1F1D25F19D51D821U, 0xD80C07CD676F8394U, 0x9AFCE626CE85B507U
};
#define CRC_STOP_SEC_CONST_UNSPECIFIED
#include "Crc_MemMap.h"

#endif /* #if (STD_ON == CRC_IP_64BIT_ECMA_TABLE) */

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == CRC_IP_8BIT_USED)
static uint8 Crc_TableCalculateCRC8(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
                                    const uint8 *LookUpTable,
                                    const uint8 *DataPtr,
                                    const uint32 Length,
                                    const uint8 StartValue8
                                   );
#endif

#if (STD_ON == CRC_IP_16BIT_USED)
static uint16 Crc_TableCalculateCRC16(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
                                      const uint8 *LookUpTable,
                                      const uint8 *DataPtr,
                                      const uint32 Length,
                                      const uint16 StartValue16
                                     );
#endif

#if (STD_ON == CRC_IP_32BIT_USED)
static uint32 Crc_TableCalculateCRC32(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
                                      const uint8 *LookUpTable,
                                      const uint8 *DataPtr,
                                      const uint32 Length,
                                      const uint32 StartValue32
                                     );
#endif

#if (STD_ON == CRC_IP_64BIT_USED)
static uint64 Crc_TableCalculateCRC64(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
                                      const uint8 *LookUpTable,
                                      const uint8 *DataPtr,
                                      const uint32 Length,
                                      const uint64 StartValue64
                                     );
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

#if (STD_ON == CRC_IP_8BIT_USED)
/**
 * @brief   This function Calculate CRC8 Lookup Table with Channel Input: CRC8 and CRC8H2F
 * @details This service is a reentrant function that shall calculate the CRC Channel.
 *
 * @return CRC final result: 8 bits
 * */
static uint8 Crc_TableCalculateCRC8(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
                                    const uint8 *LookUpTable,
                                    const uint8 *DataPtr,
                                    const uint32 Length,
                                    const uint8 StartValue8
                                   )
{
    uint32 LengthIdx  = 0U;
    uint32 CrcDataU32 = 0U;
    uint8  CrcDataU8  = 0U;
    uint8  CrcValue = StartValue8;

    /* Start calculate CRC value by using a table */
    for (LengthIdx = 0UL; LengthIdx < Length; LengthIdx++)
    {
        /* Set write transpose for CRC data */
        CrcDataU32 = (uint32)Crc_Ip_LibTranspose((uint32)DataPtr[LengthIdx],
                                                  (uint8)pxLogicChannelState->CrcProtocolInfo->Width,
                                                  pxLogicChannelState->CrcProtocolInfo->WriteBitSwap,
                                                  pxLogicChannelState->CrcProtocolInfo->WriteByteSwap
                                                );

        /* Copy 16 bit data after swap write input data */
        CrcDataU8 = (uint8)CrcDataU32;
        /* Check CRC Table types */
        /* XOR-in remainder from lookup table using the calculated index */

        switch (pxLogicChannelState->Protocol)
        {
            case CRC_PROTOCOL_8BIT_SAE_J1850:
            #if (STD_ON == CRC_IP_8BIT_SAE_J1850_TABLE)
                CrcValue = s_TableCrc8[CrcValue ^ CrcDataU8];
            #endif
            break;
            case CRC_PROTOCOL_8BIT_H2F:
            #if (STD_ON == CRC_IP_8BIT_H2F_TABLE)
                CrcValue = s_TableCrc8H2F[CrcValue ^ CrcDataU8];
            #endif
            break;
            case CRC_PROTOCOL_8BIT_CUSTOM:
            #if (STD_ON == CRC_IP_8BIT_CUSTOM_TABLE)
                CrcValue = LookUpTable[CrcValue ^ CrcDataU8];
            #endif
            break;
            default:
                CRC_IP_DEV_ASSERT(FALSE);
                /* Avoid compiler warning */
                (void)CrcDataU8;
                (void)LookUpTable;
            break;
        }
    }
    /* Set read transpose for CRC data */
    CrcValue = (uint8)Crc_Ip_LibTranspose((uint32)CrcValue,
                                             (uint8)pxLogicChannelState->CrcProtocolInfo->Width,
                                             pxLogicChannelState->CrcProtocolInfo->ReadBitSwap,
                                             pxLogicChannelState->CrcProtocolInfo->ReadByteSwap
                                         );
    /* Xor the CRC value with specified final XOR value before returning */
    if (pxLogicChannelState->CrcProtocolInfo->InverseEnable)
    {
        CrcValue = ~CrcValue;
    }

    return CrcValue;
}
#endif

#if (STD_ON == CRC_IP_16BIT_USED)
/**
 * @brief This function Calculate CRC16 Lookup Table with Channel Input: CRC16 and CRC16ARC
 * @details This service is a reentrant function that shall calculate the CRC Channel.
 *
 * @return CRC final result: 16 bits
 * */
static uint16 Crc_TableCalculateCRC16(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
                                      const uint8 *LookUpTable,
                                      const uint8 *DataPtr,
                                      const uint32 Length,
                                      const uint16 StartValue16
                                     )
{
    uint8  TableIndex  = 0U;
    uint32 LengthIdx   = 0U;
    uint32 CrcData  = 0U;
    uint16 CrcValue = StartValue16;

    /* Start calculate CRC value by using a table */
    for (LengthIdx = (uint32)0UL; LengthIdx < Length; LengthIdx++)
    {
        /* Set write transpose for CRC data */
        CrcData = (uint32)Crc_Ip_LibTranspose((uint32)DataPtr[LengthIdx],
                                              (uint8)pxLogicChannelState->CrcProtocolInfo->Width,
                                              pxLogicChannelState->CrcProtocolInfo->WriteBitSwap,
                                              pxLogicChannelState->CrcProtocolInfo->WriteByteSwap
                                             );
        /* update the MSB of crc value with next input byte */
        CrcValue ^= (uint16)((uint16)CrcData << 8U);
        /* this MSB byte value is the index into the lookup table */
        TableIndex = (uint8)(CrcValue >> 8U);
        /* shift out this index */
        CrcValue <<= 8U;

        /* XOR-in remainder from lookup table using the calculated index */
        /* Check CRC Table types */

        switch (pxLogicChannelState->Protocol)
        {
            case CRC_PROTOCOL_16BIT_CCITT_FALSE:
            #if (STD_ON == CRC_IP_16BIT_CCITT_FALSE_TABLE)
                CrcValue ^= s_TableCrc16[TableIndex];
            #endif
            break;

            case CRC_PROTOCOL_16BIT_ARC:
            #if (STD_ON == CRC_IP_16BIT_ARC_TABLE)
                CrcValue ^= s_TableCrc16ARC[TableIndex];
            #endif
            break;
            case CRC_PROTOCOL_16BIT_CUSTOM:
            {
            #if (STD_ON == CRC_IP_16BIT_CUSTOM_TABLE)
                const uint16 * LookUpTable16 = (const uint16 *)LookUpTable;
                CrcValue ^= LookUpTable16[TableIndex];
            #endif
            }
            break;
            default:
                CRC_IP_DEV_ASSERT(FALSE);
                /* Avoid compiler warning */
                (void)TableIndex;
                (void)LookUpTable;
            break;
        }
    }

    /* Set red transpose for CRC data */
    CrcValue = (uint16)Crc_Ip_LibTranspose((uint32)CrcValue,
                                           (uint8)pxLogicChannelState->CrcProtocolInfo->Width,
                                           pxLogicChannelState->CrcProtocolInfo->ReadBitSwap,
                                           pxLogicChannelState->CrcProtocolInfo->ReadByteSwap
                                          );
    /* Xor the CRC value with specified final XOR value before returning */
    if (pxLogicChannelState->CrcProtocolInfo->InverseEnable)
    {
        CrcValue = ~CrcValue;
    }

    return CrcValue;
}
#endif

#if (STD_ON == CRC_IP_32BIT_USED)
/**
 * @brief This function Calculate CRC32 Lookup Table with Channel Input: CRC32 and CRC32P4
 * @details This service is a reentrant function that shall calculate the CRC Channel.
 *
 * @return CRC final result: 32 bits
 * */
static uint32 Crc_TableCalculateCRC32(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
                                      const uint8 *LookUpTable,
                                      const uint8 *DataPtr,
                                      const uint32 Length,
                                      const uint32 StartValue32
                                     )
{
    uint8  TableIndex  = 0U;
    uint32 LengthIdx   = 0U;
    uint32 CrcData  = 0U;
    uint32 CrcValue = StartValue32;

    /* Start calculate CRC value by using a table */
    for (LengthIdx = (uint32)0UL; LengthIdx < Length; LengthIdx++)
    {
        /* Set write transpose for CRC data */
        CrcData = (uint32)Crc_Ip_LibTranspose((uint32)DataPtr[LengthIdx],
                                              (uint8)pxLogicChannelState->CrcProtocolInfo->Width,
                                              pxLogicChannelState->CrcProtocolInfo->WriteBitSwap,
                                              pxLogicChannelState->CrcProtocolInfo->WriteByteSwap
                                             );
        /* update the MSB of crc value with next input byte */
        CrcValue ^= (CrcData << 24U);
        /* this MSB byte value is the index into the lookup table */
        TableIndex = (uint8)(CrcValue >> 24U);
        /* shift out this index */
        CrcValue = (CrcValue << 8U);
        /* XOR-in remainder from lookup table using the calculated index */
        /* Check CRC Table types */

        switch (pxLogicChannelState->Protocol)
        {
            case CRC_PROTOCOL_32BIT_ETHERNET:
            #if (STD_ON == CRC_IP_32BIT_ETHERNET_TABLE)
                CrcValue ^= s_TableCrc32[TableIndex];
            #endif
            break;
            case CRC_PROTOCOL_32BIT_E2E_P4:
            #if (STD_ON == CRC_IP_32BIT_E2E_P4_TABLE)
                CrcValue ^= s_TableCrc32P4[TableIndex];
            #endif
            break;
            case CRC_PROTOCOL_32BIT_CUSTOM:
            {
            #if (STD_ON == CRC_IP_32BIT_CUSTOM_TABLE)
                const uint32 * LookUpTable32 = (const uint32 *)LookUpTable;
                CrcValue ^= LookUpTable32[TableIndex];
            #endif
            }
            break;
            default:
                CRC_IP_DEV_ASSERT(FALSE);
                /* Avoid compiler warning */
                (void)TableIndex;
                (void)LookUpTable;
            break;
        }
    }
    /* Set red transpose for CRC data */
    CrcValue = (uint32)Crc_Ip_LibTranspose(CrcValue,
                                           (uint8)pxLogicChannelState->CrcProtocolInfo->Width,
                                           pxLogicChannelState->CrcProtocolInfo->ReadBitSwap,
                                           pxLogicChannelState->CrcProtocolInfo->ReadByteSwap
                                          );
    /* Xor the CRC value with specified final XOR value before returning */
    if (pxLogicChannelState->CrcProtocolInfo->InverseEnable)
    {
        CrcValue = ~CrcValue;
    }

    return CrcValue;
}
#endif

#if (STD_ON == CRC_IP_64BIT_USED)
/**
 * @brief This function Calculate CRC64 Lookup Table with Channel Input: CRC64
 * @details This service is a reentrant function that shall calculate the CRC Channel.
 *
 * @return CRC final result: 64 bits
 * */
static uint64 Crc_TableCalculateCRC64(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
                                      const uint8 *LookUpTable,
                                      const uint8 *DataPtr,
                                      const uint32 Length,
                                      const uint64 StartValue64
                                     )
{
    uint8  TableIndex  = 0U;
    uint32 LengthIdx   = 0U;
    uint64 CrcData  = 0U;
    uint64 CrcValue = StartValue64;

    /* Start calculate CRC value by using a table */
    for (LengthIdx = (uint32)0UL; LengthIdx < Length; LengthIdx++)
    {
        /* Set write transpose for CRC data */
        CrcData = Crc_Ip_LibTranspose((uint32)DataPtr[LengthIdx],
                                      (uint8)pxLogicChannelState->CrcProtocolInfo->Width,
                                      pxLogicChannelState->CrcProtocolInfo->WriteBitSwap,
                                      pxLogicChannelState->CrcProtocolInfo->WriteByteSwap
                                     );
        /* update the MSB of crc value with next input byte */
        CrcValue ^= (CrcData << 56U);
        /* this MSB byte value is the index into the lookup table */
        TableIndex = (uint8)(CrcValue >> 56U);
        /* shift out this index */
        CrcValue = (CrcValue << 8U);
        /* XOR-in remainder from lookup table using the calculated index */
        /* Check CRC Table types */

        switch (pxLogicChannelState->Protocol)
        {
            case CRC_PROTOCOL_64BIT_ECMA:
            #if (STD_ON == CRC_IP_64BIT_ECMA_TABLE)
                CrcValue ^= s_TableCrc64ECMA[TableIndex];
            #endif
                break;
            case CRC_PROTOCOL_64BIT_CUSTOM:
            {
            #if (STD_ON == CRC_IP_64BIT_CUSTOM_TABLE)
                const uint64 * LookUpTable64 = (const uint64 *)LookUpTable;
                CrcValue ^= LookUpTable64[TableIndex];
            #endif
            }
            break;
            default:
                CRC_IP_DEV_ASSERT(FALSE);
                /* Avoid compiler warning */
                (void)TableIndex;
                (void)LookUpTable;
            break;
        }
    }
    /* Set red transpose for CRC data */
    CrcValue = Crc_Ip_LibTranspose(CrcValue,
                                   (uint8)pxLogicChannelState->CrcProtocolInfo->Width,
                                   pxLogicChannelState->CrcProtocolInfo->ReadBitSwap,
                                   pxLogicChannelState->CrcProtocolInfo->ReadByteSwap
                                  );
    /* Xor the CRC value with specified final XOR value before returning */
    if (pxLogicChannelState->CrcProtocolInfo->InverseEnable)
    {
        CrcValue = ~CrcValue;
    }

    return CrcValue;
}
#endif
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief This function shall start algorithm calculation CRC.
 */
uint64 Crc_Ip_LookupTablesCalculate(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
                                    const uint8  *LookUpTableAddress,
                                    const uint8  *DataPtr,
                                    const uint32  Length,
                                    const uint64  InitialSeedStartValue
                                   )
{
    uint64 LocResult = 0U;

    CRC_IP_DEV_ASSERT(NULL_PTR != pxLogicChannelState);
    CRC_IP_DEV_ASSERT(NULL_PTR != DataPtr);

    switch (pxLogicChannelState->CrcProtocolInfo->Width)
    {
        case CRC_WIDTH_8BIT:
        #if (STD_ON == CRC_IP_8BIT_USED)
            LocResult = Crc_TableCalculateCRC8(pxLogicChannelState, LookUpTableAddress, DataPtr, Length, (uint8)InitialSeedStartValue);
        #endif
            break;

        case CRC_WIDTH_16BIT:
        #if (STD_ON == CRC_IP_16BIT_USED)
            LocResult = Crc_TableCalculateCRC16(pxLogicChannelState, LookUpTableAddress, DataPtr, Length, (uint16)InitialSeedStartValue);
        #endif
            break;

        case CRC_WIDTH_32BIT:
        #if (STD_ON == CRC_IP_32BIT_USED)
            LocResult = Crc_TableCalculateCRC32(pxLogicChannelState, LookUpTableAddress, DataPtr, Length, (uint32)InitialSeedStartValue);
        #endif
            break;

        case CRC_WIDTH_64BIT:
        #if (STD_ON == CRC_IP_64BIT_USED)
            LocResult = Crc_TableCalculateCRC64(pxLogicChannelState, LookUpTableAddress, DataPtr, Length, InitialSeedStartValue);
        #endif
            break;

        default:
            /* Do nothing */
            break;
    }

    return LocResult;
}


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#endif  /* #if(STD_ON == CRC_IP_LOOK_UP_TABLE_USED) */

#ifdef __cplusplus
}
#endif

/** @} */
