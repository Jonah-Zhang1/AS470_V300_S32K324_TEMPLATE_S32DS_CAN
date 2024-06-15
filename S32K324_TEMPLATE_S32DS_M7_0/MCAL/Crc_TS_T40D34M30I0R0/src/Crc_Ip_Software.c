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
*   @file    Crc_Ip_Software.c
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
#include "Crc_Ip_Software.h"
#include "Crc_Ip_Lib.h"
#include "Crc_Ip_Devassert.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_SOFTWARE_VENDOR_ID_C                      43
#define CRC_IP_SOFTWARE_AR_RELEASE_MAJOR_VERSION_C       4
#define CRC_IP_SOFTWARE_AR_RELEASE_MINOR_VERSION_C       7
#define CRC_IP_SOFTWARE_AR_RELEASE_REVISION_VERSION_C    0
#define CRC_IP_SOFTWARE_SW_MAJOR_VERSION_C               3
#define CRC_IP_SOFTWARE_SW_MINOR_VERSION_C               0
#define CRC_IP_SOFTWARE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Crc_Ip_Software.c and Crc_Ip_Software.h are of the same version */
#if (CRC_IP_SOFTWARE_VENDOR_ID_C != CRC_IP_SOFTWARE_VENDOR_ID)
    #error "Crc_Ip_Software.c and Crc_Ip_Software.h have different vendor ids"
#endif

/* Check if Crc_Ip_Software.c and Crc_Ip_Software.h are of the same Autosar version */
#if ((CRC_IP_SOFTWARE_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_SOFTWARE_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_SOFTWARE_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_SOFTWARE_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_SOFTWARE_AR_RELEASE_REVISION_VERSION_C != CRC_IP_SOFTWARE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Software.c and Crc_Ip_Software.h are different"
#endif

/* Check if Crc_Ip_Software.c and Crc_Ip_Software.h are of the same Software version */
#if ((CRC_IP_SOFTWARE_SW_MAJOR_VERSION_C != CRC_IP_SOFTWARE_SW_MAJOR_VERSION) || \
     (CRC_IP_SOFTWARE_SW_MINOR_VERSION_C != CRC_IP_SOFTWARE_SW_MINOR_VERSION) || \
     (CRC_IP_SOFTWARE_SW_PATCH_VERSION_C != CRC_IP_SOFTWARE_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Software.c and Crc_Ip_Software.h are different"
#endif

/* Check if the files Crc_Ip_Software.c and Crc_Ip_Lib.h are of the same version */
#if (CRC_IP_SOFTWARE_VENDOR_ID_C != CRC_IP_LIB_VENDOR_ID)
    #error "Crc_Ip_Software.c and Crc_Ip_Lib.h have different vendor ids"
#endif

/* Check if Crc_Ip_Software.c and Crc_Ip_Lib.h are of the same Autosar version */
#if ((CRC_IP_SOFTWARE_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_LIB_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_SOFTWARE_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_LIB_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_SOFTWARE_AR_RELEASE_REVISION_VERSION_C != CRC_IP_LIB_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Software.c and Crc_Ip_Lib.h are different"
#endif

/* Check if Crc_Ip_Software.c and Crc_Ip_Lib.h are of the same Software version */
#if ((CRC_IP_SOFTWARE_SW_MAJOR_VERSION_C != CRC_IP_LIB_SW_MAJOR_VERSION) || \
     (CRC_IP_SOFTWARE_SW_MINOR_VERSION_C != CRC_IP_LIB_SW_MINOR_VERSION) || \
     (CRC_IP_SOFTWARE_SW_PATCH_VERSION_C != CRC_IP_LIB_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Software.c and Crc_Ip_Lib.h are different"
#endif

/* Check if the files Crc_Ip_Software.c and Crc_Ip_Devassert.h are of the same version */
#if (CRC_IP_SOFTWARE_VENDOR_ID_C != CRC_IP_DEVASSERT_VENDOR_ID)
    #error "Crc_Ip_Software.c and Crc_Ip_Devassert.h have different vendor ids"
#endif

/* Check if Crc_Ip_Software.c and Crc_Ip_Devassert.h are of the same Autosar version */
#if ((CRC_IP_SOFTWARE_AR_RELEASE_MAJOR_VERSION_C    != CRC_IP_DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_SOFTWARE_AR_RELEASE_MINOR_VERSION_C    != CRC_IP_DEVASSERT_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_SOFTWARE_AR_RELEASE_REVISION_VERSION_C != CRC_IP_DEVASSERT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Software.c and Crc_Ip_Devassert.h are different"
#endif

/* Check if Crc_Ip_Software.c and Crc_Ip_Devassert.h are of the same Software version */
#if ((CRC_IP_SOFTWARE_SW_MAJOR_VERSION_C != CRC_IP_DEVASSERT_SW_MAJOR_VERSION) || \
     (CRC_IP_SOFTWARE_SW_MINOR_VERSION_C != CRC_IP_DEVASSERT_SW_MINOR_VERSION) || \
     (CRC_IP_SOFTWARE_SW_PATCH_VERSION_C != CRC_IP_DEVASSERT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Software.c and Crc_Ip_Devassert.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if(STD_ON == CRC_IP_SOFTWARE_USED)
/*! @brief CRC software mask, width and shift for calculate */
#define CRC8_IP_SW_MASK_VALUE      (0x80U)
#define CRC16_IP_SW_MASK_VALUE     (0x8000U)
#define CRC32_IP_SW_MASK_VALUE     (0x80000000U)
#define CRC64_IP_SW_MASK_VALUE     (0x8000000000000000U)

#define CRC_IP_BIT_COUNTER         (8U)
#define CRC_IP_SW_SHIFT_VALUE      (1U)


/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

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

static uint8 Crc_Ip_SwCalculateCRC8(const Crc_Ip_CrcProtocolInfoType *pxCrcProtocolInfo,
                                    const uint8  *DataPtr,
                                    const uint32  Length,
                                    const uint8   StartValue8
                                   );

static uint16 Crc_Ip_SwCalculateCRC16(const Crc_Ip_CrcProtocolInfoType *pxCrcProtocolInfo,
                                      const uint8  *DataPtr,
                                      const uint32  Length,
                                      const uint16  StartValue16
                                     );

static uint32 Crc_Ip_SwCalculateCRC32(const Crc_Ip_CrcProtocolInfoType *pxCrcProtocolInfo,
                                      const uint8  *DataPtr,
                                      const uint32  Length,
                                      const uint32  StartValue32
                                     );

static uint64 Crc_Ip_SwCalculateCRC64(const Crc_Ip_CrcProtocolInfoType *pxCrcProtocolInfo,
                                      const uint8  *DataPtr,
                                      const uint32  Length,
                                      const uint64  StartValue64
                                     );

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

/**
 * @brief This function Calculate CRC8 Software with Channel Input: CRC8 and CRC8H2F
 * @details This service is a reentrant function that shall calculate the CRC Channel.
 *
 * */
static uint8 Crc_Ip_SwCalculateCRC8(const Crc_Ip_CrcProtocolInfoType *pxCrcProtocolInfo,
                                    const uint8  *DataPtr,
                                    const uint32  Length,
                                    const uint8   StartValue8
                                   )
{
    uint32 BitsIdx    = 0U;
    uint32 LengthIdx  = 0U;
    uint32 u32CrcData = 0U;
    uint8  u8CrcValue = StartValue8;

    /* Start for CRC calculator */
    for (LengthIdx = 0UL; LengthIdx < Length; LengthIdx++)
    {
        /* Set write transpose for CRC data */
        u32CrcData = (uint32)Crc_Ip_LibTranspose((uint32)DataPtr[LengthIdx],
                                                 (uint8)pxCrcProtocolInfo->Width,
                                                 pxCrcProtocolInfo->WriteBitSwap,
                                                 pxCrcProtocolInfo->WriteByteSwap
                                                );
        /* Xor input data after transpose */
        u8CrcValue ^= (uint8)u32CrcData;

        for (BitsIdx = 0U; BitsIdx < CRC_IP_BIT_COUNTER; BitsIdx++)
        {
            if (0U != (u8CrcValue & CRC8_IP_SW_MASK_VALUE))
            {
                u8CrcValue = (uint8)(((uint8)(u8CrcValue << CRC_IP_SW_SHIFT_VALUE)) ^ pxCrcProtocolInfo->PolynomValue);
            }
            else
            {
                u8CrcValue <<= CRC_IP_SW_SHIFT_VALUE;
            }
        }
    }
    /* Set red transpose for CRC data */
    u8CrcValue = (uint8)Crc_Ip_LibTranspose((uint64)u8CrcValue,
                                            (uint8)pxCrcProtocolInfo->Width,
                                            pxCrcProtocolInfo->ReadBitSwap,
                                            pxCrcProtocolInfo->ReadByteSwap
                                           );
    /* Xor the CRC value with specified final XOR value before returning */
    if (pxCrcProtocolInfo->InverseEnable)
    {
        u8CrcValue = ~u8CrcValue;
    }
    return u8CrcValue;
}


/**
 * @brief This function Calculate CRC16 Software with Channel Input: CRC16 and CRC16ARC
 * @details This service is a reentrant function that shall calculate the CRC Channel.
 *
 * @return CRC final result: 16 bits
 * */
static uint16 Crc_Ip_SwCalculateCRC16(const Crc_Ip_CrcProtocolInfoType *pxCrcProtocolInfo,
                                      const uint8  *DataPtr,
                                      const uint32  Length,
                                      const uint16  StartValue16
                                     )
{
    uint32 BitsIdx     = 0U;
    uint32 LengthIdx   = 0U;
    uint32 u32CrcData  = 0U;
    uint16 u16CrcValue = StartValue16;

    /* Start for CRC calculator */
    for (LengthIdx = 0UL; LengthIdx < Length; LengthIdx++)
    {
        /* Set write transpose for CRC input data */
        u32CrcData = (uint32)Crc_Ip_LibTranspose((uint32)DataPtr[LengthIdx],
                                                 (uint8)pxCrcProtocolInfo->Width,
                                                 pxCrcProtocolInfo->WriteBitSwap,
                                                 pxCrcProtocolInfo->WriteByteSwap
                                                );
        /* Xor input data after transpose */
        u16CrcValue ^= (uint16)((uint16)u32CrcData << 8U);

        for (BitsIdx = 0U; BitsIdx < CRC_IP_BIT_COUNTER; BitsIdx++)
        {
            if (0U != (u16CrcValue & CRC16_IP_SW_MASK_VALUE))
            {
                u16CrcValue = (uint16)(((uint16)(u16CrcValue << CRC_IP_SW_SHIFT_VALUE)) ^ pxCrcProtocolInfo->PolynomValue);
            }
            else
            {
                u16CrcValue <<= CRC_IP_SW_SHIFT_VALUE;
            }
        }
    }
    /* Set red transpose for CRC data */
    u16CrcValue = (uint16)Crc_Ip_LibTranspose((uint64)u16CrcValue,
                                              (uint8)pxCrcProtocolInfo->Width,
                                              pxCrcProtocolInfo->ReadBitSwap,
                                              pxCrcProtocolInfo->ReadByteSwap
                                             );

    /* Xor the CRC value with specified final XOR value before returning */
    if (pxCrcProtocolInfo->InverseEnable)
    {
        u16CrcValue = ~u16CrcValue;
    }
    return u16CrcValue;
}


/**
 * @brief This function Calculate CRC32 Software with Channel Input.
 * @details This service is a reentrant function that shall calculate the CRC Channel Standard.
 *
 * @return CRC final result: 32 bits
 * */
static uint32 Crc_Ip_SwCalculateCRC32(const Crc_Ip_CrcProtocolInfoType *pxCrcProtocolInfo,
                                      const uint8  *DataPtr,
                                      const uint32  Length,
                                      const uint32  StartValue32
                                     )
{
    uint32 BitsIdx     = 0U;
    uint32 LengthIdx   = 0U;
    uint32 u32CrcData  = 0U;
    uint32 u32CrcValue = StartValue32;

    /* Start for CRC calculator */
    for (LengthIdx = 0UL; LengthIdx < Length; LengthIdx++)
    {
        /* Set write transpose for CRC data */
        u32CrcData = (uint32)Crc_Ip_LibTranspose((uint32)DataPtr[LengthIdx],
                                                 (uint8)pxCrcProtocolInfo->Width,
                                                 pxCrcProtocolInfo->WriteBitSwap,
                                                 pxCrcProtocolInfo->WriteByteSwap
                                                );
        /* Xor input data after transpose */
        u32CrcValue ^= (u32CrcData << 24U);
        for (BitsIdx = 0U; BitsIdx < CRC_IP_BIT_COUNTER; BitsIdx++)
        {
            if (0U != (u32CrcValue & CRC32_IP_SW_MASK_VALUE))
            {
                u32CrcValue = (uint32)(u32CrcValue << CRC_IP_SW_SHIFT_VALUE);
                u32CrcValue = (uint32)(u32CrcValue ^ (uint32)(pxCrcProtocolInfo->PolynomValue));
            }
            else
            {
                u32CrcValue <<= CRC_IP_SW_SHIFT_VALUE;
            }
        }
    }
    /* Set red transpose for CRC data */
    u32CrcValue = (uint32)Crc_Ip_LibTranspose((uint64)u32CrcValue,
                                              (uint8)pxCrcProtocolInfo->Width,
                                              pxCrcProtocolInfo->ReadBitSwap,
                                              pxCrcProtocolInfo->ReadByteSwap
                                             );
    /* Xor the CRC value with specified final XOR value before returning */
    if (pxCrcProtocolInfo->InverseEnable)
    {
        u32CrcValue = ~u32CrcValue;
    }

    return u32CrcValue;
}

/**
 * @brief This function Calculate CRC64 Software with Channel Input.
 * @details This service is a reentrant function that shall calculate the CRC Channel Standard.
 *
 * @return CRC final result: 64 bits
 * */
static uint64 Crc_Ip_SwCalculateCRC64(const Crc_Ip_CrcProtocolInfoType *pxCrcProtocolInfo,
                                      const uint8  *DataPtr,
                                      const uint32  Length,
                                      const uint64  StartValue64
                                     )
{
    uint32 BitsIdx     = 0U;
    uint32 LengthIdx   = 0U;
    uint64 CrcData  = 0U;
    uint64 CrcValue = StartValue64;

    /* Start for CRC calculator */
    for (LengthIdx = 0UL; LengthIdx < Length; LengthIdx++)
    {
        /* Set write transpose for CRC data */
        CrcData = Crc_Ip_LibTranspose((uint32)DataPtr[LengthIdx],
                                      (uint8)pxCrcProtocolInfo->Width,
                                      pxCrcProtocolInfo->WriteBitSwap,
                                      pxCrcProtocolInfo->WriteByteSwap
                                     );
        /* Xor input data after transpose */
        CrcValue ^= (CrcData << 56U);
        for (BitsIdx = 0U; BitsIdx < CRC_IP_BIT_COUNTER; BitsIdx++)
        {
            if (0U != (CrcValue & CRC64_IP_SW_MASK_VALUE))
            {
                CrcValue = (CrcValue << CRC_IP_SW_SHIFT_VALUE) ^ pxCrcProtocolInfo->PolynomValue;
            }
            else
            {
                CrcValue <<= CRC_IP_SW_SHIFT_VALUE;
            }
        }
    }
    /* Set red transpose for CRC data */
    CrcValue = Crc_Ip_LibTranspose(CrcValue,
                                   (uint8)pxCrcProtocolInfo->Width,
                                   pxCrcProtocolInfo->ReadBitSwap,
                                   pxCrcProtocolInfo->ReadByteSwap
                                  );
    /* Xor the CRC value with specified final XOR value before returning */
    if (pxCrcProtocolInfo->InverseEnable)
    {
        CrcValue = ~CrcValue;
    }

    return CrcValue;
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief This function shall start algorithm calculation CRC.
 *
 * @return CRC final result: 32 bits
 */
uint64 Crc_Ip_SwCalculate(const Crc_Ip_LogicChannelStateType * pxLogicChannelState,
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
            LocResult = Crc_Ip_SwCalculateCRC8(pxLogicChannelState->CrcProtocolInfo, DataPtr, Length, (uint8)InitialSeedStartValue);
            break;
        case CRC_WIDTH_16BIT:
            LocResult = Crc_Ip_SwCalculateCRC16(pxLogicChannelState->CrcProtocolInfo, DataPtr, Length, (uint16)InitialSeedStartValue);
            break;
        case CRC_WIDTH_32BIT:
            LocResult = Crc_Ip_SwCalculateCRC32(pxLogicChannelState->CrcProtocolInfo, DataPtr, Length, (uint32)InitialSeedStartValue);
            break;
        case CRC_WIDTH_64BIT:
            LocResult = Crc_Ip_SwCalculateCRC64(pxLogicChannelState->CrcProtocolInfo, DataPtr, Length, InitialSeedStartValue);
            break;
        default:
            /* CRC Width not support */
            CRC_IP_DEV_ASSERT(FALSE);
            break;
    }

    return LocResult;
}


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"

#endif /* #if(STD_ON == CRC_IP_SOFTWARE_USED) */

#ifdef __cplusplus
}
#endif

/** @} */
