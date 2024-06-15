/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : I2S
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

#ifndef SAI_IP_HWACCESS_H
#define SAI_IP_HWACCESS_H
/**
*   @file
*
*   @addtogroup sai_ip SAI IPL
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
#include "StandardTypes.h"
#include "Sai_Ip_DeviceRegisters.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAI_IP_HWACCESS_VENDOR_ID                      43
#define SAI_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION       4
#define SAI_IP_HWACCESS_AR_RELEASE_MINOR_VERSION       7
#define SAI_IP_HWACCESS_AR_RELEASE_REVISION_VERSION    0
#define SAI_IP_HWACCESS_SW_MAJOR_VERSION               3
#define SAI_IP_HWACCESS_SW_MINOR_VERSION               0
#define SAI_IP_HWACCESS_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sai_Ip_DeviceRegisters header file are of the same vendor */
#if (SAI_IP_HWACCESS_VENDOR_ID != SAI_IP_DEVICEREGISTERS_VENDOR_ID)
#error "Sai_Ip_HwAccess.h and Sai_Ip_DeviceRegisters.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip_DeviceRegisters header file are of the same Autosar version */
#if ((SAI_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION     != SAI_IP_DEVICEREGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_HWACCESS_AR_RELEASE_MINOR_VERSION     != SAI_IP_DEVICEREGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (SAI_IP_HWACCESS_AR_RELEASE_REVISION_VERSION  != SAI_IP_DEVICEREGISTERS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_HwAccess.h and Sai_Ip_DeviceRegisters.h are different"
#endif

/* Check if current file and Sai_Ip_DeviceRegisters header file are of the same software version */
#if ((SAI_IP_HWACCESS_SW_MAJOR_VERSION != SAI_IP_DEVICEREGISTERS_SW_MAJOR_VERSION) || \
     (SAI_IP_HWACCESS_SW_MINOR_VERSION != SAI_IP_DEVICEREGISTERS_SW_MINOR_VERSION) || \
     (SAI_IP_HWACCESS_SW_PATCH_VERSION != SAI_IP_DEVICEREGISTERS_SW_PATCH_VERSION))
#error "Software Version Numbers of Sai_Ip_HwAccess.h and Sai_Ip_DeviceRegisters.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes header file are of the same Autosar version */
#if ((SAI_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION     != STD_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_HWACCESS_AR_RELEASE_MINOR_VERSION     != STD_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Sai_Ip_HwAccess.h and StandardTypes.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

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
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#if (STD_ON == SAI_IP_ENABLE)

#define I2S_START_SEC_CODE
#include "I2s_MemMap.h"

#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxEnableFifoWarnInt
 * Description   : Enable fifo warning interrupt
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxEnableFifoWarnInt(SAI_Type * pBase)
{
    uint32 u32Val = pBase->TCSR;

    /* careful not to clear flags */
    u32Val &= ~(SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
    /* enable fifo warning int */
    u32Val |= SAI_TCSR_FWIE_MASK;
    pBase->TCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxDisableFifoWarnInt
 * Description   : Disable fifo warning interrupt
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxDisableFifoWarnInt(SAI_Type * pBase)
{
    uint32 u32Val = pBase->TCSR;

    /* careful not to clear flags */
    u32Val &= ~(SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
    /* disable fifo warning int */
    u32Val &= ~SAI_TCSR_FWIE_MASK;
    pBase->TCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxDisableBitClock
 * Description   : Disable transmmitter bit clock
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxDisableBitClock(SAI_Type * pBase)
{
    /* Disable tx clock, do not clear flags */
    pBase->TCSR &= ~(SAI_TCSR_BCE_MASK | SAI_TCSR_TE_MASK |
                     SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxDisableBitClock
 * Description   : Disable receiver bit clock
 *
 *END**************************************************************************/
static inline void Sai_Ip_RxDisableBitClock(SAI_Type * pBase)
{
    /* Disable rx clock, do not clear flags */
    pBase->RCSR &= ~(SAI_RCSR_BCE_MASK | SAI_RCSR_RE_MASK |
                     SAI_RCSR_WSF_MASK | SAI_RCSR_SEF_MASK | SAI_RCSR_FEF_MASK);
}
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxActiveReset
 * Description   : Enable software reset bit
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxActiveReset(SAI_Type * pBase)
{
    /* Reset the internal transmitter logic */
    pBase->TCSR = (pBase->TCSR & ~(SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK)) | SAI_TCSR_SR_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxDeactiveReset
 * Description   : Disable software reset bit
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxDeactiveReset(SAI_Type * pBase)
{
    /* Enable internal transmitter logic */
    pBase->TCSR = pBase->TCSR & ~(SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK | SAI_TCSR_SR_MASK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxActiveReset
 * Description   : Enable software reset bit
 *
 *END**************************************************************************/
static inline void Sai_Ip_RxActiveReset(SAI_Type * pBase)
{
    /* Reset the internal receiver logic */
    pBase->RCSR = (pBase->RCSR & ~(SAI_RCSR_WSF_MASK | SAI_RCSR_SEF_MASK | SAI_RCSR_FEF_MASK)) | SAI_RCSR_SR_MASK;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxDeactiveReset
 * Description   : Disable software reset bit
 *
 *END**************************************************************************/
static inline void Sai_Ip_RxDeactiveReset(SAI_Type * pBase)
{
    /* Enable internal receiver logic */
    pBase->RCSR = pBase->RCSR & ~(SAI_RCSR_WSF_MASK | SAI_RCSR_SEF_MASK | SAI_RCSR_FEF_MASK | SAI_RCSR_SR_MASK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxSetWatermark
 * Description   : Set fifo watermark
 *
 *END**************************************************************************/
static inline void Sai_Ip_RxSetWatermark(SAI_Type * pBase, uint8 u8Level)
{
    pBase->RCR1 = SAI_RCR1_RFW((uint32) u8Level);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_IsTxChannelEnabled
 * Description   : check if channel is enabled
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_IsTxChannelEnabled(const SAI_Type * pBase, uint8 u8Channel)
{
    boolean bRet;

    if ((pBase->TCR3 & (SAI_TCR3_TCE(1UL << u8Channel))) != 0UL)
    {
        bRet = TRUE;
    }
    else
    {
        bRet = FALSE;
    }
    return bRet;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_IsRxChannelEnabled
 * Description   : check if channel is enabled
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_IsRxChannelEnabled(const SAI_Type * pBase, uint8 u8Channel)
{
    boolean bRet;

    if ((pBase->RCR3 & (SAI_RCR3_RCE(1UL << u8Channel))) != 0UL)
    {
        bRet = TRUE;
    }
    else
    {
        bRet =FALSE;
    }
    return bRet;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxResetFifo
 * Description   : Reset fifo
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxResetFifo(SAI_Type * pBase)
{
    uint32 u32Val = pBase->TCSR;
    /* careful not to clear flags */
    u32Val &= ~(SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
    /* enable fifo request int */
    u32Val |= SAI_TCSR_FR_MASK;
    pBase->TCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxResetFifo
 * Description   : Reset fifo
 *
 *END**************************************************************************/
static inline void Sai_Ip_RxResetFifo(SAI_Type * pBase)
{
    uint32 u32Val = pBase->RCSR;
    /* careful not to clear flags */
    u32Val &= ~(SAI_RCSR_WSF_MASK | SAI_RCSR_SEF_MASK | SAI_RCSR_FEF_MASK);
    /* enable fifo request int */
    u32Val |= SAI_RCSR_FR_MASK;
    pBase->RCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxDisableFifoReqInt
 * Description   : Disable fifo request interrupt
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxDisableFifoReqInt(SAI_Type * pBase)
{
    uint32 u32Val = pBase->TCSR;
    /* careful not to clear flags */
    u32Val &= ~(SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
    /* enable fifo request int */
    u32Val &= ~SAI_TCSR_FRIE_MASK;
    pBase->TCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxClearAllFlags
 * Description   : Clear all tx flags
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxClearAllFlags(SAI_Type * pBase)
{
     uint32 u32Val = pBase->TCSR;
     /* Clear flags */
     u32Val |= (SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
     /* Clear tx fifo */
     u32Val |= SAI_TCSR_FR_MASK;

     pBase->TCSR = u32Val;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxClearFlag
 * Description   : Clear one of folowing flags: word start, fifo erro,
 *                 sync error
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxClearFlag(SAI_Type * pBase, uint32 u32Shift)
{
    uint32 u32Val = pBase->TCSR;
    /* careful not to clear flags */
    u32Val &= ~(SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
    /* clear fifo error flag */
    u32Val |= 1UL << u32Shift;
    pBase->TCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxClearAllFlags
 * Description   : Clear all rx flags
 *
 *END**************************************************************************/
static inline void Sai_Ip_RxClearAllFlags(SAI_Type * pBase)
{
     uint32 u32Val = pBase->RCSR;
    /* Clear flags */
     u32Val |= (SAI_RCSR_WSF_MASK | SAI_RCSR_SEF_MASK | SAI_RCSR_FEF_MASK);
     /* Clear rx fifo */
     u32Val |= SAI_RCSR_FR_MASK;

     pBase->RCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxClearFlag
 * Description   : Clear one of folowing flags: word start, fifo erro,
 *                 sync error
 *
 *END**************************************************************************/
static inline void Sai_Ip_RxClearFlag(SAI_Type * pBase, uint32 u32Shift)
{
    uint32 u32Val = pBase->RCSR;
    /* careful not to clear flags */
    u32Val &= ~(SAI_RCSR_WSF_MASK | SAI_RCSR_SEF_MASK | SAI_RCSR_FEF_MASK);
    /* clear fifo error flag */
    u32Val |= 1UL << u32Shift;
    pBase->RCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxEnableFifoReqInt
 * Description   : Enable fifo request interrupt
 *
 *END**************************************************************************/
static inline void Sai_Ip_RxEnableFifoReqInt(SAI_Type * pBase)
{
    uint32 u32Val = pBase->RCSR;

    /* careful not to clear flags */
    u32Val &= ~(SAI_RCSR_WSF_MASK | SAI_RCSR_SEF_MASK | SAI_RCSR_FEF_MASK);
    /* enable fifo request int */
    u32Val |= SAI_RCSR_FRIE_MASK;
    pBase->RCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxEnableFifoReqDma
 * Description   : Enable fifo request dma
 *
 *END**************************************************************************/
static inline void Sai_Ip_RxEnableFifoReqDma(SAI_Type * pBase)
{
    uint32 u32Val = pBase->RCSR;

    /* careful not to clear flags */
    u32Val &= ~(SAI_RCSR_WSF_MASK | SAI_RCSR_SEF_MASK | SAI_RCSR_FEF_MASK);
    /* enable fifo request int */
    u32Val |= SAI_RCSR_FRDE_MASK;
    pBase->RCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxDisable
 * Description   : Disable receiver (Interrupt and DMA requests)
 *
 *END**************************************************************************/
static inline void Sai_Ip_RxDisable(SAI_Type * pBase)
{
    /* Reset the internal receiver logic */
    Sai_Ip_RxActiveReset(pBase);

    /* Disable rx, do not clear flags */
    pBase->RCSR &= ~(SAI_RCSR_RE_MASK | SAI_RCSR_FRIE_MASK | SAI_RCSR_FRDE_MASK |
                     SAI_RCSR_WSF_MASK | SAI_RCSR_SEF_MASK | SAI_RCSR_FEF_MASK);

    /* Enable internal receiver logic */
    Sai_Ip_RxDeactiveReset(pBase);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxEnableFifoReqInt
 * Description   : Enable fifo request interrupt
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxEnableFifoReqInt(SAI_Type * pBase)
{
    uint32 u32Val = pBase->TCSR;

    /* careful not to clear flags */
    u32Val &= ~(SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
    /* enable fifo request int */
    u32Val |= SAI_TCSR_FRIE_MASK;
    pBase->TCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxEnableFifoReqDma
 * Description   : Enable fifo request dma
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxEnableFifoReqDma(SAI_Type * pBase)
{
    uint32 u32Val = pBase->TCSR;

    /* careful not to clear flags */
    u32Val &= ~(SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
    /* enable fifo request int */
    u32Val |= SAI_TCSR_FRDE_MASK;
    pBase->TCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxDisableFifoReqDma
 * Description   : Disable fifo request dma
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxDisableFifoReqDma(SAI_Type * pBase)
{
    uint32 u32Val = pBase->TCSR;

    /* careful not to clear flags */
    u32Val &= ~(SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
    /* enable fifo request int */
    u32Val &= ~SAI_TCSR_FRDE_MASK;
    pBase->TCSR = u32Val;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxDisable
 * Description   : Disable transmitter (and Bit clock, Warning, Interrupt and DMA requests)
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxDisable(SAI_Type * pBase)
{
    /* Disable tx, do not clear flags */
    pBase->TCSR &= ~(SAI_TCSR_TE_MASK | SAI_TCSR_FRIE_MASK | SAI_TCSR_FRDE_MASK | SAI_TCSR_FWIE_MASK |
                     SAI_TCSR_WSF_MASK | SAI_TCSR_SEF_MASK | SAI_TCSR_FEF_MASK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_IsTxFifoFull
 * Description   : Check if Tx fifo is full
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_IsTxFifoFull(const SAI_Type * pBase,
                                        uint8 u8Channel)
{
    uint32 u32Wfp = 0U;
    uint32 u32Rfp = 0U;
    boolean bRet;

    u32Wfp = (pBase->TFR[u8Channel] & SAI_TFR_WFP_MASK) >> SAI_TFR_WFP_SHIFT;
    u32Rfp = (pBase->TFR[u8Channel] & SAI_TFR_RFP_MASK) >> SAI_TFR_RFP_SHIFT;

    /* if WFP and RFP is identical except msb then fifo is full */
    if ((u32Wfp ^ u32Rfp) == (1UL << (SAI_TFR_WFP_WIDTH - 1UL)))
    {
        bRet = TRUE;
    }
    else
    {
        bRet = FALSE;
    }
    return bRet;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_IsRxFifoEmpty
 * Description   : Check if Rx fifo is empty
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_IsRxFifoEmpty(const SAI_Type * pBase,
                          uint8 u8Channel)
{
    uint32 u32Wfp;
    uint32 u32Rfp;
    boolean bRet;

    u32Wfp = (pBase->RFR[u8Channel] & SAI_RFR_WFP_MASK) >> SAI_RFR_WFP_SHIFT;
    u32Rfp = (pBase->RFR[u8Channel] & SAI_RFR_RFP_MASK) >> SAI_RFR_RFP_SHIFT;

    /* if WFP and RFP is identical then fifo is empty */
    if (u32Wfp == u32Rfp)
    {
        bRet = TRUE;
    }
    else
    {
        bRet = FALSE;
    }
    return bRet;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxWrite
 * Description   : Write data register once
 *
 *END**************************************************************************/
static inline void Sai_Ip_TxWrite(SAI_Type * pBase,
                                   uint8 u8Channel,
                                   uint32 u32Data)
{
    pBase->TDR[u8Channel] = u32Data;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxRead
 * Description   : Read data register once
 *
 *END**************************************************************************/
static inline uint32 Sai_Ip_RxRead(const SAI_Type * pBase,
                                    uint8 u8Channel)
{
    return pBase->RDR[u8Channel];
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxGetFifoErrorFlag
 * Description   : Return tx fifo error flag
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_TxGetFifoErrorFlag(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->TCSR;
    return ((u32Temp & SAI_TCSR_FEF_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxGetFifoErrorBitEnable
 * Description   : Return tx fifo error bit enable
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_TxGetFifoErrorBitEnable(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->TCSR;
    return ((u32Temp & SAI_TCSR_FEIE_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxGetFifoErrorFlag
 * Description   : Return tx sync error flag
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_TxGetSyncErrorFlag(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->TCSR;
    return ((u32Temp & SAI_TCSR_SEF_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxGetSyncErrorBitEnable
 * Description   : Return tx sync error bit enable
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_TxGetSyncErrorBitEnable(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->TCSR;
    return ((u32Temp & SAI_TCSR_SEIE_MASK) != 0UL);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxGetWordStartFlag
 * Description   : Return tx word start flag
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_TxGetWordStartFlag(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->TCSR;
    return ((u32Temp & SAI_TCSR_WSF_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxGetWordStartBitEnable
 * Description   : Return tx word start bit enable
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_TxGetWordStartBitEnable(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->TCSR;
    return ((u32Temp & SAI_TCSR_WSIE_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxGetFifoReqFlag
 * Description   : Return fifo request flag
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_TxGetFifoReqFlag(const SAI_Type * pBase)
{
    return ((pBase->TCSR & SAI_TCSR_FRF_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxGetFifoWarnFlag
 * Description   : Return fifo warning flag
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_TxGetFifoWarnFlag(const SAI_Type * pBase)
{
    return ((pBase->TCSR & SAI_TCSR_FWF_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxGetFifoErrorFlag
 * Description   : Return rx fifo error flag
 *
 *END**************************************************************************/

static inline boolean Sai_Ip_RxGetFifoErrorFlag(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->RCSR;
    return ((u32Temp & SAI_RCSR_FEF_MASK) != 0UL);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxGetFifoErrorBitEnable
 * Description   : Return rx fifo error bit enable
 *
 *END**************************************************************************/

static inline boolean Sai_Ip_RxGetFifoErrorBitEnable(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->RCSR;
    return ((u32Temp & SAI_RCSR_FEIE_MASK) != 0UL);
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxGetFifoErrorFlag
 * Description   : Return rx sync error flag
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_RxGetSyncErrorFlag(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->RCSR;
    return ((u32Temp & SAI_RCSR_SEF_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxGetSyncErrorBitEnable
 * Description   : Return rx sync error bit enable
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_RxGetSyncErrorBitEnable(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->RCSR;
    return ((u32Temp & SAI_RCSR_SEIE_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxGetFifoReqFlag
 * Description   : Return fifo request flag
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_RxGetFifoReqFlag(const SAI_Type * pBase)
{
    return ((pBase->RCSR & SAI_RCSR_FRF_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxGetWordStartFlag
 * Description   : Return rx word start flag
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_RxGetWordStartFlag(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->RCSR;
    return ((u32Temp & SAI_RCSR_WSF_MASK) != 0UL);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxGetWordStartBitEnable
 * Description   : Return rx word start bit enable
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_RxGetWordStartBitEnable(const SAI_Type * pBase)
{
    uint32 u32Temp = pBase->RCSR;
    return ((u32Temp & SAI_RCSR_WSIE_MASK) != 0UL);
}

#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_GetParamFrameSize
 * Description   : Return frame size in param register
 *
 *END**************************************************************************/
static inline uint8 Sai_Ip_GetParamFrameSize(const SAI_Type * pBase)
{
#ifdef FEATURE_SAI_IP_HAS_PARAM
    return (uint8)((pBase->PARAM & SAI_PARAM_FRAME_MASK) >> SAI_PARAM_FRAME_SHIFT);
#else
    return SAI_IP_FIFO_SIZE;
#endif
}
#endif /* SAI_IP_DEV_ERROR_DETECT */

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxGetIntEnable
 * Description   : Get one of folowing interrupt enable: word start, fifo erro,
 *                 sync error
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_TxGetBitEnable(const SAI_Type * const pBase, uint32 u32Mask)
{
    return (((pBase->TCSR & u32Mask) != 0U) ? TRUE : FALSE);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxGetIntEnable
 * Description   : Get one of folowing interrupt enable: word start, fifo erro,
 *                 sync error
 *
 *END**************************************************************************/
static inline boolean Sai_Ip_RxGetBitEnable(const SAI_Type * const pBase, uint32 u32Mask)
{
    return (((pBase->RCSR & u32Mask) != 0U) ? TRUE : FALSE);
}

#define I2S_STOP_SEC_CODE
#include "I2s_MemMap.h"

#endif /* (STD_ON == SAI_IP_ENABLE) */

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* SAI_IP_HWACCESS_H */
