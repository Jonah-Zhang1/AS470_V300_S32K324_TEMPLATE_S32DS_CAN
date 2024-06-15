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
*   @file    Crc_Ip.c
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
#include "Crc_Ip.h"
#include "Crc_Ip_Devassert.h"
#if(STD_ON == CRC_IP_HARDWARE_USED)
#include "Crc_Ip_Hardware.h"
#endif
#if(STD_ON == CRC_IP_LOOK_UP_TABLE_USED)
#include "Crc_Ip_Lookup_Tables.h"
#endif
#if(STD_ON == CRC_IP_SOFTWARE_USED)
#include "Crc_Ip_Software.h"
#endif
#include "Crc_Ip_Lib.h"
#include "Crc_Ip_State.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_VENDOR_ID_C                     43
#define CRC_IP_AR_RELEASE_MAJOR_VERSION_C      4
#define CRC_IP_AR_RELEASE_MINOR_VERSION_C      7
#define CRC_IP_AR_RELEASE_REVISION_VERSION_C   0
#define CRC_IP_SW_MAJOR_VERSION_C              3
#define CRC_IP_SW_MINOR_VERSION_C              0
#define CRC_IP_SW_PATCH_VERSION_C              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Crc_Ip.c and Crc_Ip.h are of the same version */
#if (CRC_IP_VENDOR_ID_C != CRC_IP_VENDOR_ID)
    #error "Crc_Ip.c and Crc_Ip.h have different vendor ids"
#endif

/* Check if Crc_Ip.c and Crc_Ip.h are of the same Autosar version */
#if ((CRC_IP_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_AR_RELEASE_REVISION_VERSION_C != CRC_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip.c and Crc_Ip.h are different"
#endif

/* Check if Crc_Ip.c and Crc_Ip.h are of the same Software version */
#if ((CRC_IP_SW_MAJOR_VERSION_C != CRC_IP_SW_MAJOR_VERSION) || \
     (CRC_IP_SW_MINOR_VERSION_C != CRC_IP_SW_MINOR_VERSION) || \
     (CRC_IP_SW_PATCH_VERSION_C != CRC_IP_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip.c and Crc_Ip.h are different"
#endif

#if(STD_ON == CRC_IP_LOOK_UP_TABLE_USED)
/* Check if the files Crc_Ip.c and Crc_Ip_LookupTables.h are of the same version */
#if (CRC_IP_VENDOR_ID_C != CRC_IP_LOOKUP_TABLES_VENDOR_ID)
    #error "Crc_Ip.c and Crc_Ip_Lookup_Tables.h have different vendor ids"
#endif

/* Check if Crc_Ip.c and Crc_Ip_LookupTables.h are of the same Autosar version */
#if ((CRC_IP_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_LOOKUP_TABLES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_LOOKUP_TABLES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_AR_RELEASE_REVISION_VERSION_C != CRC_IP_LOOKUP_TABLES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip.c and Crc_Ip_Lookup_Tables.h are different"
#endif

/* Check if Crc_Ip.c and Crc_Ip_LookupTables.h are of the same Software version */
#if ((CRC_IP_SW_MAJOR_VERSION_C != CRC_IP_LOOKUP_TABLES_SW_MAJOR_VERSION) || \
     (CRC_IP_SW_MINOR_VERSION_C != CRC_IP_LOOKUP_TABLES_SW_MINOR_VERSION) || \
     (CRC_IP_SW_PATCH_VERSION_C != CRC_IP_LOOKUP_TABLES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip.c and Crc_Ip_Lookup_Tables.h are different"
#endif
#endif /* #if(STD_ON == CRC_IP_LOOK_UP_TABLE_USED) */

#if(STD_ON == CRC_IP_SOFTWARE_USED)
/* Check if the files Crc_Ip.c and Crc_Ip_Software.h are of the same version */
#if (CRC_IP_VENDOR_ID_C != CRC_IP_SOFTWARE_VENDOR_ID)
    #error "Crc_Ip.c and Crc_Ip_Software.h have different vendor ids"
#endif

/* Check if Crc_Ip.c and Crc_Ip_Software.h are of the same Autosar version */
#if ((CRC_IP_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_SOFTWARE_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_SOFTWARE_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_AR_RELEASE_REVISION_VERSION_C != CRC_IP_SOFTWARE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip.c and Crc_Ip_Software.h are different"
#endif

/* Check if Crc_Ip.c and Crc_Ip_Software.h are of the same Software version */
#if ((CRC_IP_SW_MAJOR_VERSION_C != CRC_IP_SOFTWARE_SW_MAJOR_VERSION) || \
     (CRC_IP_SW_MINOR_VERSION_C != CRC_IP_SOFTWARE_SW_MINOR_VERSION) || \
     (CRC_IP_SW_PATCH_VERSION_C != CRC_IP_SOFTWARE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip.c and Crc_Ip_Software.h are different"
#endif
#endif /* #if(STD_ON == CRC_IP_LOOK_UP_TABLE_USED) */

#if(STD_ON == CRC_IP_HARDWARE_USED)
/* Check if the files Crc_Ip.c and Crc_Ip_Hardware.h are of the same version */
#if (CRC_IP_VENDOR_ID_C != CRC_IP_HARDWARE_VENDOR_ID)
    #error "Crc_Ip.c and Crc_Ip_Hardware.h have different vendor ids"
#endif

/* Check if Crc_Ip.c and Crc_Ip_Hardware.h are of the same Autosar version */
#if ((CRC_IP_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_HARDWARE_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_HARDWARE_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_AR_RELEASE_REVISION_VERSION_C != CRC_IP_HARDWARE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip.c and Crc_Ip_Hardware.h are different"
#endif

/* Check if Crc_Ip.c and Crc_Ip_Hardware.h are of the same Software version */
#if ((CRC_IP_SW_MAJOR_VERSION_C != CRC_IP_HARDWARE_SW_MAJOR_VERSION) || \
     (CRC_IP_SW_MINOR_VERSION_C != CRC_IP_HARDWARE_SW_MINOR_VERSION) || \
     (CRC_IP_SW_PATCH_VERSION_C != CRC_IP_HARDWARE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip.c and Crc_Ip_Hardware.h are different"
#endif

/* Check if the files Crc_Ip.c and Crc_Ip_Lib.h are of the same version */
#if (CRC_IP_VENDOR_ID_C != CRC_IP_LIB_VENDOR_ID)
    #error "Crc_Ip.c and Crc_Ip_Lib.h have different vendor ids"
#endif
#endif /* #if(STD_ON == CRC_IP_HARDWARE_USED) */

/* Check if Crc_Ip.c and Crc_Ip_Lib.h are of the same Autosar version */
#if ((CRC_IP_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_LIB_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_LIB_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_AR_RELEASE_REVISION_VERSION_C != CRC_IP_LIB_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip.c and Crc_Ip_Lib.h are different"
#endif

/* Check if Crc_Ip.c and Crc_Ip_Lib.h are of the same Software version */
#if ((CRC_IP_SW_MAJOR_VERSION_C != CRC_IP_LIB_SW_MAJOR_VERSION) || \
     (CRC_IP_SW_MINOR_VERSION_C != CRC_IP_LIB_SW_MINOR_VERSION) || \
     (CRC_IP_SW_PATCH_VERSION_C != CRC_IP_LIB_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip.c and Crc_Ip_Lib.h are different"
#endif

/* Check if the files Crc_Ip.c and Crc_Ip_State.h are of the same version */
#if (CRC_IP_VENDOR_ID_C != CRC_IP_STATE_VENDOR_ID)
    #error "Crc_Ip.c and Crc_Ip_State.h have different vendor ids"
#endif

/* Check if Crc_Ip.c and Crc_Ip_State.h are of the same Autosar version */
#if ((CRC_IP_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_STATE_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_STATE_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_AR_RELEASE_REVISION_VERSION_C != CRC_IP_STATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip.c and Crc_Ip_State.h are different"
#endif

/* Check if Crc_Ip.c and Crc_Ip_State.h are of the same Software version */
#if ((CRC_IP_SW_MAJOR_VERSION_C != CRC_IP_STATE_SW_MAJOR_VERSION) || \
     (CRC_IP_SW_MINOR_VERSION_C != CRC_IP_STATE_SW_MINOR_VERSION) || \
     (CRC_IP_SW_PATCH_VERSION_C != CRC_IP_STATE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip.c and Crc_Ip_State.h are different"
#endif

/* Check if the files Crc_Ip.c and Crc_Ip_Devassert.h are of the same version */
#if (CRC_IP_VENDOR_ID_C != CRC_IP_DEVASSERT_VENDOR_ID)
    #error "Crc_Ip.c and Crc_Ip_Devassert.h have different vendor ids"
#endif

/* Check if Crc_Ip.c and Crc_Ip_Devassert.h are of the same Autosar version */
#if ((CRC_IP_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_AR_RELEASE_REVISION_VERSION_C != CRC_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip.c and Crc_Ip_Devassert.h are different"
#endif

/* Check if Crc_Ip.c and Crc_Ip_Devassert.h are of the same Software version */
#if ((CRC_IP_SW_MAJOR_VERSION_C != CRC_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (CRC_IP_SW_MINOR_VERSION_C != CRC_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (CRC_IP_SW_PATCH_VERSION_C != CRC_IP_DEVASSERT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip.c and Crc_Ip_Devassert.h are different"
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
#define CRC_START_SEC_VAR_CLEARED_BOOLEAN
#include "Crc_MemMap.h"

#if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE)
#if (STD_ON == CRC_IP_HARDWARE_USED)
/* Table of pxCrcBase addresses  for CRC instances. */
static uint8 Crc_Hardware_Lock[CRC_IP_INSTANCE_COUNT_U8][CRC_IP_CHANNEL_COUNT_U8];
#endif /* #if(STD_ON == CRC_IP_HARDWARE_USED) */
#endif /* #if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE) */

#define CRC_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Crc_MemMap.h"

#define CRC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crc_MemMap.h"
/* Pointer to the CRC Initialization Configuration. Based on this configuration pointer,
   the CRC Driver obtains all information for the Logic Channels and corresponding
   Channel Configurations.
   The Pointer is loaded when Crc_Ip_Init() is called. */
static const Crc_Ip_LogicChannelType * const *s_ppaxLogicChannelInit;
static Crc_Ip_LogicChannelStateType s_axLogicChannelState[CRC_IP_NUM_LOGIC_CHANNEL_MAX];
static Crc_Ip_CrcProtocolInfoType   s_axLogicChannelCustomProtocol[CRC_IP_NUM_LOGIC_CHANNEL_MAX];

#define CRC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Crc_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define CRC_START_SEC_CONST_UNSPECIFIED
#include "Crc_MemMap.h"

#define CRC_STOP_SEC_CONST_UNSPECIFIED
#include "Crc_MemMap.h"

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Static_Crc_Ip_SetChannelCustomProtocol(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig, Crc_Ip_CrcWidthType LocWidth);
static void Static_Crc_Ip_SetChannelState(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig);
#if (STD_ON == CRC_IP_DEV_ERROR_DETECT)
static void Static_Crc_Ip_ValidateProtocol(const Crc_Ip_CalculationType CalculationType, const Crc_Ip_ProtocolType Protocol);
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/**
 * @brief   Local function used to update the Logic Channel Custom Protocol.
 */
static void Static_Crc_Ip_SetChannelCustomProtocol(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig, Crc_Ip_CrcWidthType LocWidth)
{
    s_axLogicChannelCustomProtocol[LogicChannel].Width            = LocWidth;
    s_axLogicChannelCustomProtocol[LogicChannel].PolynomValue     = pxLocLogicChannelConfig->PolynomValue;
    s_axLogicChannelCustomProtocol[LogicChannel].WriteBitSwap     = pxLocLogicChannelConfig->WriteBitSwap;
    s_axLogicChannelCustomProtocol[LogicChannel].WriteByteSwap    = pxLocLogicChannelConfig->WriteByteSwap;
    s_axLogicChannelCustomProtocol[LogicChannel].ReadBitSwap      = pxLocLogicChannelConfig->ReadBitSwap;
    s_axLogicChannelCustomProtocol[LogicChannel].ReadByteSwap     = pxLocLogicChannelConfig->ReadByteSwap;
    s_axLogicChannelCustomProtocol[LogicChannel].InverseEnable    = pxLocLogicChannelConfig->InverseEnable;
    s_axLogicChannelState[LogicChannel].CrcProtocolInfo           = &s_axLogicChannelCustomProtocol[LogicChannel];
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_8BIT_CUSTOM
 */
static void Static_Crc_Ip_SetChannelProtocol_8BitCustom(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    Static_Crc_Ip_SetChannelCustomProtocol(LogicChannel, pxLocLogicChannelConfig, CRC_WIDTH_8BIT);
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_16BIT_CUSTOM
 */
static void Static_Crc_Ip_SetChannelProtocol_16BitCustom(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    Static_Crc_Ip_SetChannelCustomProtocol(LogicChannel, pxLocLogicChannelConfig, CRC_WIDTH_16BIT);
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_32BIT_CUSTOM
 */
static void Static_Crc_Ip_SetChannelProtocol_32BitCustom(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    Static_Crc_Ip_SetChannelCustomProtocol(LogicChannel, pxLocLogicChannelConfig, CRC_WIDTH_32BIT);
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_32BIT_CUSTOM
 */
static void Static_Crc_Ip_SetChannelProtocol_64BitCustom(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    Static_Crc_Ip_SetChannelCustomProtocol(LogicChannel, pxLocLogicChannelConfig, CRC_WIDTH_64BIT);
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_8BIT_SAE_J1850
 */
static void Static_Crc_Ip_SetChannelProtocol_8BitSaeJ1850Autosar(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    /* Define Protocol Autosar Info */
    static const Crc_Ip_CrcProtocolInfoType s_Protocol8Bit_SAE_J1850_AUTOSAR = {
        .Width=CRC_WIDTH_8BIT, .PolynomValue=0x1DU, .InitialSeedValue=0xFFU, .WriteBitSwap=FALSE,
        .WriteByteSwap=FALSE, .ReadBitSwap=FALSE, .ReadByteSwap=FALSE, .InverseEnable=TRUE};

    /* Define Protocol Info specific for hardware calculate */
#if (STD_ON == CRC_IP_8BIT_SAE_J1850_HARDWARE_SUPPORTED)
    static const Crc_Ip_CrcProtocolInfoType s_Protocol8Bit_SAE_J1850_HARDWARE = {
        .Width=CRC_WIDTH_8BIT, .PolynomValue=0x1DU, .InitialSeedValue=0xFFU, .WriteBitSwap=TRUE,
        .WriteByteSwap=FALSE, .ReadBitSwap=FALSE, .ReadByteSwap=FALSE, .InverseEnable=TRUE};
#endif

#if (STD_ON == CRC_IP_8BIT_SAE_J1850_HARDWARE_SUPPORTED)
    if (CRC_IP_HARDWARE_CALCULATION == s_ppaxLogicChannelInit[LogicChannel]->CalculationType)
    {
        s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol8Bit_SAE_J1850_HARDWARE;
    }
    else
    {
#endif
        s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol8Bit_SAE_J1850_AUTOSAR;
#if (STD_ON == CRC_IP_8BIT_SAE_J1850_HARDWARE_SUPPORTED)
    }
#endif

    (void)pxLocLogicChannelConfig;
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_8BIT_H2F
 */
static void Static_Crc_Ip_SetChannelProtocol_8BitH2fAutosar(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    /* Define Protocol Autosar Info */
    static const Crc_Ip_CrcProtocolInfoType s_Protocol8Bit_H2F_AUTOSAR = {
        .Width=CRC_WIDTH_8BIT, .PolynomValue=0x2FU, .InitialSeedValue=0xFFU, .WriteBitSwap=FALSE,
        .WriteByteSwap=FALSE, .ReadBitSwap=FALSE, .ReadByteSwap=FALSE, .InverseEnable=TRUE};

    /* Define Protocol Info specific for hardware calculate */
#if (STD_ON == CRC_IP_8BIT_H2F_HARDWARE_SUPPORTED)
    static const Crc_Ip_CrcProtocolInfoType s_Protocol8Bit_H2F_HARDWARE = {
        .Width=CRC_WIDTH_8BIT, .PolynomValue=0x2FU, .InitialSeedValue=0xFFU, .WriteBitSwap=TRUE,
        .WriteByteSwap=FALSE, .ReadBitSwap=FALSE, .ReadByteSwap=FALSE, .InverseEnable=TRUE};
#endif

#if (STD_ON == CRC_IP_8BIT_H2F_HARDWARE_SUPPORTED)
    if (CRC_IP_HARDWARE_CALCULATION == s_ppaxLogicChannelInit[LogicChannel]->CalculationType)
    {
        s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol8Bit_H2F_HARDWARE;
    }
    else
    {
#endif
        s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol8Bit_H2F_AUTOSAR;
#if (STD_ON == CRC_IP_8BIT_H2F_HARDWARE_SUPPORTED)
    }
#endif

    (void)pxLocLogicChannelConfig;
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_16BIT_CCITT_FALSE
 */
static void Static_Crc_Ip_SetChannelProtocol_16BitCcittFalseAutosar(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    /* Define Protocol Autosar Info */
    static const Crc_Ip_CrcProtocolInfoType s_Protocol16Bit_CCITT_FALSE_AUTOSAR = {
        .Width=CRC_WIDTH_16BIT, .PolynomValue=0x1021U, .InitialSeedValue=0xFFFFU, .WriteBitSwap=FALSE,
        .WriteByteSwap=FALSE, .ReadBitSwap=FALSE, .ReadByteSwap=FALSE, .InverseEnable=FALSE};

    /* Define Protocol Info specific for hardware calculate */
#if (STD_ON == CRC_IP_16BIT_CCITT_FALSE_HARDWARE_SUPPORTED)
#if (STD_ON == CRC_IP_WRITE_BIT_SWAP_INVERETED)
    static const Crc_Ip_CrcProtocolInfoType s_Protocol16Bit_CCITT_FALSE_HARDWARE = {
        .Width=CRC_WIDTH_16BIT, .PolynomValue=0x1021U, .InitialSeedValue=0xFFFFU, .WriteBitSwap=TRUE,
        .WriteByteSwap=FALSE, .ReadBitSwap=FALSE, .ReadByteSwap=FALSE, .InverseEnable=FALSE};
#elif (STD_OFF == CRC_IP_WRITE_BIT_SWAP_INVERETED)
    static const Crc_Ip_CrcProtocolInfoType s_Protocol16Bit_CCITT_FALSE_HARDWARE = {
        .Width=CRC_WIDTH_16BIT, .PolynomValue=0x1021U, .InitialSeedValue=0xFFFFU, .WriteBitSwap=FALSE,
        .WriteByteSwap=FALSE, .ReadBitSwap=FALSE, .ReadByteSwap=FALSE, .InverseEnable=FALSE};
#endif
#endif

#if (STD_ON == CRC_IP_16BIT_CCITT_FALSE_HARDWARE_SUPPORTED)
    if (CRC_IP_HARDWARE_CALCULATION == s_ppaxLogicChannelInit[LogicChannel]->CalculationType)
    {
        s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol16Bit_CCITT_FALSE_HARDWARE;
    }
    else
    {
#endif
        s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol16Bit_CCITT_FALSE_AUTOSAR;
#if (STD_ON == CRC_IP_16BIT_CCITT_FALSE_HARDWARE_SUPPORTED)
    }
#endif

    (void)pxLocLogicChannelConfig;
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_16BIT_ARC
 */
static void Static_Crc_Ip_SetChannelProtocol_16BitArcAutosar(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    static const Crc_Ip_CrcProtocolInfoType s_Protocol16Bit_ARC_AUTOSAR = {
        .Width=CRC_WIDTH_16BIT, .PolynomValue=0x8005U, .InitialSeedValue=0U, .WriteBitSwap=TRUE,
        .WriteByteSwap=FALSE, .ReadBitSwap=TRUE, .ReadByteSwap=TRUE, .InverseEnable=FALSE};

    s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol16Bit_ARC_AUTOSAR;

    (void)pxLocLogicChannelConfig;
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_32BIT_ETHERNET
 */
static void Static_Crc_Ip_SetChannelProtocol_32BitEthernetAutosar(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    /* Define Protocol Autosar Info */
    static const Crc_Ip_CrcProtocolInfoType s_Protocol32Bit_ETHERNET_AUTOSAR = {
        .Width=CRC_WIDTH_32BIT, .PolynomValue=0x04C11DB7U, .InitialSeedValue=0xFFFFFFFFU, .WriteBitSwap=TRUE,
        .WriteByteSwap=FALSE, .ReadBitSwap=TRUE, .ReadByteSwap=TRUE, .InverseEnable=TRUE};

    /* Define Protocol Info specific for hardware calculate */
#if (STD_ON == CRC_IP_32BIT_ETHERNET_HARDWARE_SUPPORTED)
#if (STD_ON == CRC_IP_WRITE_BIT_SWAP_INVERETED)
    static const Crc_Ip_CrcProtocolInfoType s_Protocol32Bit_ETHERNET_HARDWARE = {
        .Width=CRC_WIDTH_32BIT, .PolynomValue=0x04C11DB7U, .InitialSeedValue=0xFFFFFFFFU, .WriteBitSwap=FALSE,
        .WriteByteSwap=TRUE, .ReadBitSwap=TRUE, .ReadByteSwap=TRUE, .InverseEnable=TRUE};
#elif (STD_OFF == CRC_IP_WRITE_BIT_SWAP_INVERETED)
    static const Crc_Ip_CrcProtocolInfoType s_Protocol32Bit_ETHERNET_HARDWARE = {
        .Width=CRC_WIDTH_32BIT, .PolynomValue=0x04C11DB7U, .InitialSeedValue=0xFFFFFFFFU, .WriteBitSwap=TRUE,
        .WriteByteSwap=FALSE, .ReadBitSwap=TRUE, .ReadByteSwap=TRUE, .InverseEnable=TRUE};
#endif
#endif

#if (STD_ON == CRC_IP_32BIT_ETHERNET_HARDWARE_SUPPORTED)
    if (CRC_IP_HARDWARE_CALCULATION == s_ppaxLogicChannelInit[LogicChannel]->CalculationType)
    {
        s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol32Bit_ETHERNET_HARDWARE;
    }
    else
    {
#endif
        s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol32Bit_ETHERNET_AUTOSAR;
#if (STD_ON == CRC_IP_32BIT_ETHERNET_HARDWARE_SUPPORTED)
    }
#endif

    (void)pxLocLogicChannelConfig;
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_32BIT_E2E_P4
 */
static void Static_Crc_Ip_SetChannelProtocol_32BitE2eP4Autosar(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    static const Crc_Ip_CrcProtocolInfoType s_Protocol32Bit_E2E_P4_AUTOSAR = {
        .Width=CRC_WIDTH_32BIT, .PolynomValue=0xF4ACFB13U, .InitialSeedValue=0xFFFFFFFFU, .WriteBitSwap=TRUE,
        .WriteByteSwap=FALSE, .ReadBitSwap=TRUE, .ReadByteSwap=TRUE, .InverseEnable=TRUE};

    s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol32Bit_E2E_P4_AUTOSAR;

    (void)pxLocLogicChannelConfig;
}

/**
 * @brief   Set config parameter for Channel Protocol is CRC_PROTOCOL_64BIT_ECMA
 */
static void Static_Crc_Ip_SetChannelProtocol_64BitAutosar(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    static const Crc_Ip_CrcProtocolInfoType s_Protocol64Bit_AUTOSAR = {
        .Width=CRC_WIDTH_64BIT, .PolynomValue=0x42F0E1EBA9EA3693U, .InitialSeedValue=0xFFFFFFFFFFFFFFFFU, .WriteBitSwap=TRUE,
        .WriteByteSwap=FALSE, .ReadBitSwap=TRUE, .ReadByteSwap=TRUE, .InverseEnable=TRUE};

    s_axLogicChannelState[LogicChannel].CrcProtocolInfo = &s_Protocol64Bit_AUTOSAR;

    (void)pxLocLogicChannelConfig;
}


/**
 * @brief   Checks if the protocol is correct based on channel calculation type.
 */
static void Static_Crc_Ip_SetChannelProtocol_Invalid(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    (void)LogicChannel;
    (void)pxLocLogicChannelConfig;
    CRC_IP_DEV_ASSERT(FALSE);
}

/**
 * @brief   Local function used to update the Logic Channel Configuration State.
 */
static void Static_Crc_Ip_SetChannelState(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig)
{
    static void (*const fpCrc_Ip_SetChannelProtocol[])(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType * pxLocLogicChannelConfig) =
    {
        Static_Crc_Ip_SetChannelProtocol_8BitCustom,
        Static_Crc_Ip_SetChannelProtocol_16BitCustom,
        Static_Crc_Ip_SetChannelProtocol_32BitCustom,
        Static_Crc_Ip_SetChannelProtocol_64BitCustom,
        Static_Crc_Ip_SetChannelProtocol_8BitH2fAutosar,
        Static_Crc_Ip_SetChannelProtocol_8BitSaeJ1850Autosar,
        Static_Crc_Ip_SetChannelProtocol_16BitArcAutosar,
        Static_Crc_Ip_SetChannelProtocol_16BitCcittFalseAutosar,
        Static_Crc_Ip_SetChannelProtocol_32BitE2eP4Autosar,
        Static_Crc_Ip_SetChannelProtocol_32BitEthernetAutosar,
        Static_Crc_Ip_SetChannelProtocol_64BitAutosar,
        Static_Crc_Ip_SetChannelProtocol_Invalid
    };
    fpCrc_Ip_SetChannelProtocol[pxLocLogicChannelConfig->Protocol](LogicChannel, pxLocLogicChannelConfig);
    CRC_IP_DEV_ASSERT(CRC_PROTOCOL_INVALID > pxLocLogicChannelConfig->Protocol);
    s_axLogicChannelState[LogicChannel].Protocol = pxLocLogicChannelConfig->Protocol;

#if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE)
#if(STD_ON == CRC_IP_HARDWARE_USED)
    if (CRC_IP_HARDWARE_CALCULATION == s_ppaxLogicChannelInit[LogicChannel]->CalculationType)
    {
        Crc_Hardware_Lock[s_ppaxLogicChannelInit[LogicChannel]->HwInst][s_ppaxLogicChannelInit[LogicChannel]->HwChannel] = 0x01U;
        Crc_Ip_HwSetConfig(s_ppaxLogicChannelInit[LogicChannel]->HwInst,
                           s_ppaxLogicChannelInit[LogicChannel]->HwChannel,
                           &s_axLogicChannelState[LogicChannel]
                          );
    }
#endif /* #if(STD_ON == CRC_IP_HARDWARE_USED) */
#endif /* #if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE) */
}

#if (STD_ON == CRC_IP_DEV_ERROR_DETECT)
/**
 * @brief         Local function used to validate the Logic Channel Configuration Protocol.
 * @implements    Static_Crc_Ip_ValidateProtocol
 */
static void Static_Crc_Ip_ValidateProtocol(const Crc_Ip_CalculationType CalculationType, const Crc_Ip_ProtocolType Protocol)
{
    uint8 Tmp = 1U;

    if (CRC_IP_TABLE_CALCULATION == CalculationType)
    {
        #if (STD_ON == CRC_IP_8BIT_SAE_J1850_TABLE)
            Tmp &= (CRC_PROTOCOL_8BIT_SAE_J1850 != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_8BIT_H2F_TABLE)
            Tmp &= (CRC_PROTOCOL_8BIT_H2F != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_16BIT_CCITT_FALSE_TABLE)
            Tmp &= (CRC_PROTOCOL_16BIT_CCITT_FALSE != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_16BIT_ARC_TABLE)
            Tmp &= (CRC_PROTOCOL_16BIT_ARC != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_32BIT_ETHERNET_TABLE)
            Tmp &= (CRC_PROTOCOL_32BIT_ETHERNET != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_32BIT_E2E_P4_TABLE)
            Tmp &= (CRC_PROTOCOL_32BIT_E2E_P4 != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_64BIT_ECMA_TABLE)
            Tmp &= (CRC_PROTOCOL_64BIT_ECMA != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_8BIT_CUSTOM_TABLE)
            Tmp &= (CRC_PROTOCOL_8BIT_CUSTOM != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_16BIT_CUSTOM_TABLE)
            Tmp &= (CRC_PROTOCOL_16BIT_CUSTOM != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_32BIT_CUSTOM_TABLE)
            Tmp &= (CRC_PROTOCOL_32BIT_CUSTOM != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_64BIT_CUSTOM_TABLE)
            Tmp &= (CRC_PROTOCOL_64BIT_CUSTOM != Protocol) ? 1U : 0U;
        #endif

        if (Tmp == 1U)
        {
            CRC_IP_DEV_ASSERT(FALSE);
        }
    }
    else if (CRC_IP_HARDWARE_CALCULATION == CalculationType)
    {
        #if (STD_ON == CRC_IP_8BIT_SAE_J1850_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_8BIT_SAE_J1850 != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_8BIT_H2F_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_8BIT_H2F != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_16BIT_CCITT_FALSE_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_16BIT_CCITT_FALSE != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_16BIT_ARC_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_16BIT_ARC != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_32BIT_ETHERNET_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_32BIT_ETHERNET != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_32BIT_E2E_P4_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_32BIT_E2E_P4 != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_64BIT_ECMA_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_64BIT_ECMA != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_8BIT_CUSTOM_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_8BIT_CUSTOM != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_16BIT_CUSTOM_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_16BIT_CUSTOM != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_32BIT_CUSTOM_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_32BIT_CUSTOM != Protocol) ? 1U : 0U;
        #endif
        #if (STD_ON == CRC_IP_64BIT_CUSTOM_HARDWARE_SUPPORTED)
            Tmp &= (CRC_PROTOCOL_64BIT_CUSTOM != Protocol) ? 1U : 0U;
        #endif

        if (Tmp == 1U)
        {
            CRC_IP_DEV_ASSERT(FALSE);
        }
    }
    else
    {
        /* Do nothing. */
    }
    (void)Tmp;
    (void)Protocol;
}
#endif /* #if (STD_ON == CRC_IP_DEV_ERROR_DETECT) */

/*==================================================================================================
*                                       INTERNAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

/**
 * @brief         Initializes the CRC Driver settings based on user configuration.
 * @implements    Crc_Ip_Init_Activity
 */
void Crc_Ip_Init(const Crc_Ip_InitType *const pxCrcIpInit)
{
    uint32 LocChannelIndex = 0U;

    CRC_IP_DEV_ASSERT(NULL_PTR != pxCrcIpInit);
    CRC_IP_DEV_ASSERT(NULL_PTR != pxCrcIpInit->LogicChannelConfigList);

    /* Save pointer to initialization structure for LogicChannelConfig */
    s_ppaxLogicChannelInit = pxCrcIpInit->LogicChannelConfigList;

    for (LocChannelIndex = 0U; LocChannelIndex < CRC_IP_NUM_LOGIC_CHANNEL_MAX; LocChannelIndex++)
    {
        if (NULL_PTR != s_ppaxLogicChannelInit[LocChannelIndex]->LogicChannelConfig)
        {
            Static_Crc_Ip_SetChannelState(LocChannelIndex, s_ppaxLogicChannelInit[LocChannelIndex]->LogicChannelConfig);
        }
        else
        {
            CRC_IP_DEV_ASSERT(FALSE);
        }
    }
}


/**
 * @brief         The function configures the Logic Channel during runtime.
 * @implements    Crc_Ip_SetChannelConfig_Activity
 */
void Crc_Ip_SetChannelConfig(const uint32 LogicChannel, const Crc_Ip_LogicChannelConfigType *pxLocLogicChannelConfig)
{
    const Crc_Ip_LogicChannelConfigType *LogicChannelConfig;

    CRC_IP_DEV_ASSERT(LogicChannel < CRC_IP_NUM_LOGIC_CHANNEL_MAX);

    if (NULL_PTR != pxLocLogicChannelConfig)
    {
        LogicChannelConfig = pxLocLogicChannelConfig;
    }
    else
    {
        LogicChannelConfig = (Crc_Ip_LogicChannelConfigType *)s_ppaxLogicChannelInit[LogicChannel]->LogicChannelConfig;
    }

#if (STD_ON == CRC_IP_DEV_ERROR_DETECT)
    Static_Crc_Ip_ValidateProtocol(s_ppaxLogicChannelInit[LogicChannel]->CalculationType, LogicChannelConfig->Protocol);
#endif

    Static_Crc_Ip_SetChannelState(LogicChannel, LogicChannelConfig);
}


/**
 * @brief         This function shall start algorithm calculate CRC
 * @implements    Crc_Ip_SetChannelCalculate_Activity
 */
uint64 Crc_Ip_SetChannelCalculate(const uint32 LogicChannel, const uint8  *DataPtr, const uint32  Length, const uint64 StartValue, const boolean IsFirstCall)
{
    uint64 LocResult = 0U;
    uint64 LocInitialSeedStartValue = StartValue;

    const Crc_Ip_CrcProtocolInfoType * pxLocProtocolInfo = s_axLogicChannelState[LogicChannel].CrcProtocolInfo;

    CRC_IP_DEV_ASSERT(LogicChannel < CRC_IP_NUM_LOGIC_CHANNEL_MAX);
    CRC_IP_DEV_ASSERT(NULL_PTR != DataPtr);
#if (STD_ON == CRC_IP_DEV_ERROR_DETECT)
    Static_Crc_Ip_ValidateProtocol(s_ppaxLogicChannelInit[LogicChannel]->CalculationType, s_axLogicChannelState[LogicChannel].Protocol);
#endif

    if (TRUE == IsFirstCall)
    {
        switch (s_axLogicChannelState[LogicChannel].Protocol)
        {
            case CRC_PROTOCOL_8BIT_CUSTOM:
            case CRC_PROTOCOL_16BIT_CUSTOM:
            case CRC_PROTOCOL_32BIT_CUSTOM:
            case CRC_PROTOCOL_64BIT_CUSTOM:
                LocInitialSeedStartValue = StartValue;
                break;
            default:
                LocInitialSeedStartValue = pxLocProtocolInfo->InitialSeedValue;
                break;
        }
    }
    else
    {
        if (TRUE == pxLocProtocolInfo->InverseEnable)
        {
            LocInitialSeedStartValue = ~StartValue;
        }
        LocInitialSeedStartValue = Crc_Ip_LibTranspose(LocInitialSeedStartValue,
                                                       (uint8)pxLocProtocolInfo->Width,
                                                       pxLocProtocolInfo->ReadBitSwap,
                                                       pxLocProtocolInfo->ReadByteSwap
                                                      );
    }

    switch (s_ppaxLogicChannelInit[LogicChannel]->CalculationType)
    {
        case CRC_IP_TABLE_CALCULATION:
#if (STD_ON == CRC_IP_LOOK_UP_TABLE_USED)
            LocResult = Crc_Ip_LookupTablesCalculate(&s_axLogicChannelState[LogicChannel],
                                                     s_ppaxLogicChannelInit[LogicChannel]->LogicChannelConfig->LookUpTable,
                                                     DataPtr,
                                                     Length,
                                                     LocInitialSeedStartValue
                                                    );
#endif
            break;
        case CRC_IP_RUNTIME_CALCULATION:
#if (STD_ON == CRC_IP_SOFTWARE_USED)
            LocResult = Crc_Ip_SwCalculate(&s_axLogicChannelState[LogicChannel],
                                           DataPtr,
                                           Length,
                                           LocInitialSeedStartValue
                                          );
#endif
            break;
        case CRC_IP_HARDWARE_CALCULATION:
#if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE)
#if (STD_ON == CRC_IP_HARDWARE_USED)
            if(Crc_Hardware_Lock[s_ppaxLogicChannelInit[LogicChannel]->HwInst][s_ppaxLogicChannelInit[LogicChannel]->HwChannel] == 0x01U)
            {
                Crc_Hardware_Lock[s_ppaxLogicChannelInit[LogicChannel]->HwInst][s_ppaxLogicChannelInit[LogicChannel]->HwChannel] = 0x00U;
                
                LocResult = Crc_Ip_HwCalculate(s_ppaxLogicChannelInit[LogicChannel],
                                           DataPtr,
                                           Length,
                                           LocInitialSeedStartValue
                                          );

                Crc_Hardware_Lock[s_ppaxLogicChannelInit[LogicChannel]->HwInst][s_ppaxLogicChannelInit[LogicChannel]->HwChannel] = 0x01U;
            }
#endif /* #if(STD_ON == CRC_IP_HARDWARE_USED) */
#endif /* #if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE) */
            break;
        default:
            /* Do nothing */
            break;
    }
    s_axLogicChannelState[LogicChannel].CrcResult = LocResult;

    return LocResult;
}

/**
 * @brief       Initializes the CRC Driver settings based on user configuration.
 * @implements  Crc_Ip_GetChannelResult_Activity
 */
uint64 Crc_Ip_GetChannelResult(const uint32 LogicChannel)
{
    uint64 LocResult = 0U;

    CRC_IP_DEV_ASSERT(LogicChannel < CRC_IP_NUM_LOGIC_CHANNEL_MAX);

    switch (s_ppaxLogicChannelInit[LogicChannel]->CalculationType)
    {
        case CRC_IP_TABLE_CALCULATION:
        case CRC_IP_RUNTIME_CALCULATION:
            LocResult = s_axLogicChannelState[LogicChannel].CrcResult;
            break;
#if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE)
#if(STD_ON == CRC_IP_HARDWARE_USED)
        case CRC_IP_HARDWARE_CALCULATION:
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
            LocResult = Crc_Ip_HwGetLocResultDmaSupported(s_ppaxLogicChannelInit[LogicChannel]->HwInst,
                                              s_ppaxLogicChannelInit[LogicChannel]->HwChannel,
                                              s_ppaxLogicChannelInit[LogicChannel]->DmaLogicChannelEnable,
                                              s_ppaxLogicChannelInit[LogicChannel]->DmaLogicChannelName
                                             );
#else
            LocResult = Crc_Ip_HwGetLocResult(s_ppaxLogicChannelInit[LogicChannel]->HwInst,
                                              s_ppaxLogicChannelInit[LogicChannel]->HwChannel
                                             );
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */
            break;
#endif /* #if(STD_ON == CRC_IP_HARDWARE_USED) */
#endif /* #if (STD_ON == CRC_IP_HARDWARE_IS_AVAILABLE) */
        default:
            /* Do nothing */
            break;
    }
    return LocResult;
}


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
