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
#ifndef CRC_IP_HW_ACCESS_H
#define CRC_IP_HW_ACCESS_H

/**
*   @file    Crc_Ip_Hw_Access.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Crc - Crc Ip driver source file.
*   @details
*
*   @addtogroup CRC_IP_DRIVER CRC IP Configure Register
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
#include "Mcal.h"
#include "Crc_Ip_CfgDefines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @brief Parameters that shall be published within the driver header file and also in the
* module's description file
*/
#define CRC_IP_HW_ACCESS_VENDOR_ID                      43
#define CRC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION       4
#define CRC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION       7
#define CRC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION    0
#define CRC_IP_HW_ACCESS_SW_MAJOR_VERSION               3
#define CRC_IP_HW_ACCESS_SW_MINOR_VERSION               0
#define CRC_IP_HW_ACCESS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Crc_Ip_Hw_Access.h file and Mcal.h header file are of the same Autosar version */
#if ((CRC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Crc_Ip_Hw_Access.h and Mcal.h are different"
#endif
#endif


/* Check if source file and Crc_Ip_CfgDefines.h file are of the same vendor */
#if (CRC_IP_HW_ACCESS_VENDOR_ID != CRC_IP_CFG_DEFINES_VENDOR_ID)
    #error "Crc_Ip_Hw_Access.h and Crc_Ip_CfgDefines.h have different vendor ids"
#endif

/* Check if source file and Crc_Ip_CfgDefines.h file are of the same Autosar version */
#if ((CRC_IP_HW_ACCESS_AR_RELEASE_MAJOR_VERSION    != CRC_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (CRC_IP_HW_ACCESS_AR_RELEASE_MINOR_VERSION    != CRC_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (CRC_IP_HW_ACCESS_AR_RELEASE_REVISION_VERSION != CRC_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Crc_Ip_Hw_Access.h and Crc_Ip_CfgDefines.h are different"
#endif

/* Check if source file and Crc_Ip_CfgDefines.h header file are of the same Software version */
#if ((CRC_IP_HW_ACCESS_SW_MAJOR_VERSION != CRC_IP_CFG_DEFINES_SW_MAJOR_VERSION) || \
     (CRC_IP_HW_ACCESS_SW_MINOR_VERSION != CRC_IP_CFG_DEFINES_SW_MINOR_VERSION) || \
     (CRC_IP_HW_ACCESS_SW_PATCH_VERSION != CRC_IP_CFG_DEFINES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Crc_Ip_Hw_Access.h and Crc_Ip_CfgDefines.h are different"
#endif
/*==================================================================================================
 * CRC CHANNEL CONFIGURATION FUNCTION - REGISTER ACCESSCFG
==================================================================================================*/

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"

#if (STD_ON == CRC_IP_HARDWARE_WIDTH_IS_AVAILABLE)
/**
 * @brief    Switch mode for config start Value or write data CRC
 * @details  This function switch mode for config start Value or write data CRC
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 * @param[in]  CrcWidth     - Crc Width option
 *
 * @return void
 **/
static inline void hwAccCrc_SetCrcWidth(CRC_Type *const pxCrcBase,
                                        const uint8 HwChannel,
                                        Crc_Ip_CrcWidthType CrcWidth
                                       )
{
    boolean SetValue = FALSE;
    uint32  Register = pxCrcBase->CTRL;

    (void)  HwChannel;

    if (CRC_WIDTH_32BIT == CrcWidth)
    {
        SetValue = TRUE;
    }

    Register = ((Register & (~(CRC_CTRL_TCRC_MASK))) | (CRC_CTRL_TCRC(SetValue ? 1UL : 0UL)));
    pxCrcBase->CTRL = Register;
}
#endif /* #if (STD_ON == CRC_IP_HARDWARE_WIDTH_IS_AVAILABLE) */


/**
 * @brief    Switch mode for config start Value or write data CRC
 * @details  This function switch mode for config start Value or write data CRC
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 * @param[in]  enable       - switch data mode is set start value or data value
 *
 * @return void
 **/
static inline void hwAccCrc_SetDataMode(CRC_Type *const pxCrcBase,
                                        const uint8 HwChannel,
                                        const boolean Enable
                                       )
{
    uint32 Reg = pxCrcBase->CTRL;

    Reg = ((Reg & (~(CRC_CTRL_WAS_MASK))) | (CRC_CTRL_WAS(Enable ? 1UL : 0UL)));
    pxCrcBase->CTRL = Reg;
    (void) HwChannel;
}


#if (STD_ON == CRC_IP_HARDWARE_POLYNOM_IS_AVAILABLE)
/**
 * @brief    Sets seed of the CRC data register
 * @details  This function sets seed of the CRC data register
 *
 * @param[in]  pxCrcBase       - The CRC peripheral base address
 * @param[in]  HwChannel       - Hardware Channel
 * @param[in]  polynomialValue - polynomial Value use calculate
 *
 * @return void
 **/
static inline void hwAccCrc_SetPolynom(CRC_Type *const pxCrcBase,
                                       const uint8 HwChannel,
                                       const uint32 PolynomValue
                                      )
{
    (void) HwChannel;
    pxCrcBase->GPOLY = PolynomValue;
}
#endif /* #if (STD_ON == CRC_IP_HARDWARE_POLYNOM_IS_AVAILABLE) */


#if ((STD_ON == CRC_IP_HARDWARE_WRITE_BIT_SWAP_IS_AVAILABLE) || (STD_ON == CRC_IP_HARDWARE_WRITE_BYTE_SWAP_IS_AVAILABLE))
/**
 * @brief    Sets the CRC Swap Data Write is byte-wise
 * @details  This function sets Swap CRC_CFG_SWAP_BYTEWISE byte-wise
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 * @param[in]  SwapOption   - Option set Swap
 *
 * @return void
 **/
static inline void hwAccCrc_SetWriteSwap(CRC_Type *const pxCrcBase,
                                         const uint8 HwChannel,
                                         const boolean WriteBit,
                                         const boolean WriteByte
                                        )
{
    uint32 Reg = pxCrcBase->CTRL;
    uint8 SwapOption = 0U;

    (void) HwChannel;

    if (TRUE == WriteBit)
    {
        if (FALSE == WriteByte)
        {
            /* bit swap */
            SwapOption = 1U;
        }
        else
        {
            /* bit and byte swap */
            SwapOption = 2U;
        }
    }
    else
    {
        if (TRUE == WriteByte)
        {
            /* byte swap */
            SwapOption = 3U;
        }
        else
        {
            /* none swap */
        }
    }

    Reg = ((Reg & (~(CRC_CTRL_TOT_MASK))) | (CRC_CTRL_TOT(SwapOption)));
    pxCrcBase->CTRL = Reg;
}
#endif /* #if ((STD_ON == CRC_IP_HARDWARE_WRITE_BIT_SWAP_IS_AVAILABLE) || (STD_ON == CRC_IP_HARDWARE_WRITE_BYTE_SWAP_IS_AVAILABLE)) */


#if ((STD_ON == CRC_IP_HARDWARE_READ_BIT_SWAP_IS_AVAILABLE) || (STD_ON == CRC_IP_HARDWARE_READ_BYTE_SWAP_IS_AVAILABLE))
/**
 * @brief    Sets the CRC Swap Data Read
 * @details  This function sets transpose CRC_OUTP content
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 * @param[in]  SwapOption   - Option set Swap
 *
 * @return void
 **/
static inline void hwAccCrc_SetReadSwap(CRC_Type *const pxCrcBase,
                                        const uint8 HwChannel,
                                        const boolean ReadBit,
                                        const boolean ReadByte
                                       )
{
    uint32 Reg = pxCrcBase->CTRL;
    uint8 SwapOption = 0U;

    (void) HwChannel;

    if (TRUE == ReadBit)
    {
        if (FALSE == ReadByte)
        {
            /* bit swap */
            SwapOption = 1U;
        }
        else
        {
            /* bit and byte swap */
            SwapOption = 2U;
        }
    }
    else
    {
        if (TRUE == ReadByte)
        {
            /* byte swap */
            SwapOption = 3U;
        }
        else
        {
            /* none swap */
        }
    }

    Reg = ((Reg & (~(CRC_CTRL_TOTR_MASK))) | (CRC_CTRL_TOTR(SwapOption)));
    pxCrcBase->CTRL = Reg;
}
#endif /* #if ((STD_ON == CRC_IP_HARDWARE_READ_BIT_SWAP_IS_AVAILABLE) || (STD_ON == CRC_IP_HARDWARE_READ_BYTE_SWAP_IS_AVAILABLE)) */


#if (STD_ON == CRC_IP_HARDWARE_INVERSE_BIT_IS_AVAILABLE)
/**
 * @brief    Sets the CRC Inversion content (XOR)
 * @details  This function sets Inversion CRC_OUTP content
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 * @param[in]  inverseValue - Inverse Value XOR complement (or negation)
 *
 * @return void
 **/
static inline void hwAccCrc_SetInverseResult(CRC_Type *const pxCrcBase,
                                             const uint8 HwChannel,
                                             const boolean InverseEnable
                                            )
{
    uint32 Reg = pxCrcBase->CTRL;

    (void) HwChannel;

    Reg = ((Reg & (~(CRC_CTRL_FXOR_MASK))) | (CRC_CTRL_FXOR(InverseEnable ? 1UL : 0UL)));
    pxCrcBase->CTRL = Reg;
}
#endif /* #if (STD_ON == CRC_IP_HARDWARE_INVERSE_BIT_IS_AVAILABLE) */


/**
 * @brief    Sets the CRC Data Input
 * @details  This function sets CRC Data Input into CRC_INP Register
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 * @param[in]  value        - New data for CRC computation
 *
 * @return void
 **/
static inline void hwAccCrc_SetInputData(CRC_Type *const pxCrcBase,
                                         const uint8 HwChannel,
                                         const uint8 Value
                                        )
{
    (void) HwChannel;
    *(volatile uint8 *)&pxCrcBase->DATA = Value;
}


/**
 * @brief    Sets seed of the CRC data register
 * @details  This function sets seed of the CRC data register
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 * @param[in]  InitialSeedValue   - new start (seed) Value for CRC computation
 *
 * @return void
 **/
static inline void hwAccCrc_SetInitialSeedValue(CRC_Type *const pxCrcBase,
                                                const uint8 HwChannel,
                                                const uint32 InitialSeedValue
                                               )
{
    hwAccCrc_SetDataMode(pxCrcBase, HwChannel, TRUE);
    pxCrcBase->DATA = InitialSeedValue;
    hwAccCrc_SetDataMode(pxCrcBase, HwChannel, FALSE);
}


/*==================================================================================================
 * CRC GET PARAMETER - REGISTER ACCESS
==================================================================================================*/
#if (STD_ON == CRC_IP_DMA_IS_AVAILABLE)
/**
 * @brief   Returns the address of data input area
 * @details This function returns the address of data input area
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 *
 * @return     Address of data input area
 **/
static inline uint32 hwAccCRC_GetDataInputAddress(const CRC_Type *const pxCrcBase, const uint8 HwChannel)
{
    (void) HwChannel;
    return (uint32)&pxCrcBase->DATA;
}
#endif /* #if (STD_ON == CRC_IP_DMA_IS_AVAILABLE) */

/**
 * @brief   Returns the current result of the CRC calculation
 * @details This function returns the current result of the CRC calculation
 *
 * @param[in]  pxCrcBase    - The CRC peripheral base address
 * @param[in]  HwChannel    - Hardware Channel
 *
 * @return     Result of CRC calculation
 **/
static inline uint32 hwAccCRC_GetResult(const CRC_Type *pxCrcBase, const uint32 HwChannel)
{
    uint32 CrcWidth  = 0U;
    uint8 SwapOption = 0U;
    uint32 Result    = 0U;

    (void) HwChannel;

    /* Get Result from data Register */
    Result = (uint32)pxCrcBase->DATA;

    /* Add label to support fault injection test */
    MCAL_FAULT_INJECTION_POINT(CRC_FAULT_INJECTION);

    /* Get Crc Width */
    CrcWidth = (pxCrcBase->CTRL & CRC_CTRL_TCRC_MASK) >> CRC_CTRL_TCRC_SHIFT;
    /* Get swap option when read data */
    SwapOption = (uint8)((pxCrcBase->CTRL & CRC_CTRL_TOTR_MASK) >> CRC_CTRL_TOTR_SHIFT);

    if (0U == CrcWidth)
    {
        /* Update Valid Data with CRC16 with "swap byte" or "swap bit and byte" */
        if ((SwapOption == 2U) || (SwapOption == 3U))
        {
            Result >>= 16U;
        }
        Result &= 0xFFFFU;
    }

    return Result;
}


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif  /* #ifndef CRC_IP_HW_ACCESS_H */
