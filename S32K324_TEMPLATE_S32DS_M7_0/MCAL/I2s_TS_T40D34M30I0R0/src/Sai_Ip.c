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
#include "Sai_Ip.h"
#include "Sai_Ip_HwAccess.h"
#include "OsIf.h"
#include "SchM_I2s.h"
#if (STD_ON == SAI_IP_ENABLE)
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
#include "Dma_Ip.h"
#endif /* STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE */
#endif /* (STD_ON == SAI_IP_ENABLE) */

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SAI_IP_VENDOR_ID_C                      43
#define SAI_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define SAI_IP_AR_RELEASE_MINOR_VERSION_C       7
#define SAI_IP_AR_RELEASE_REVISION_VERSION_C    0
#define SAI_IP_SW_MAJOR_VERSION_C               3
#define SAI_IP_SW_MINOR_VERSION_C               0
#define SAI_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Sai_Ip header file are of the same vendor */
#if (SAI_IP_VENDOR_ID_C != SAI_IP_VENDOR_ID)
#error "Sai_Ip.c and Sai_Ip.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip header file are of the same Autosar version */
#if ((SAI_IP_AR_RELEASE_MAJOR_VERSION_C     != SAI_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_AR_RELEASE_MINOR_VERSION_C     != SAI_IP_AR_RELEASE_MINOR_VERSION) || \
     (SAI_IP_AR_RELEASE_REVISION_VERSION_C  != SAI_IP_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Sai_Ip.c and Sai_Ip.h are different"
#endif

/* Check if current file and Sai_Ip header file are of the same software version */
#if ((SAI_IP_SW_MAJOR_VERSION_C != SAI_IP_SW_MAJOR_VERSION) || \
     (SAI_IP_SW_MINOR_VERSION_C != SAI_IP_SW_MINOR_VERSION) || \
     (SAI_IP_SW_PATCH_VERSION_C != SAI_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Sai_Ip.c and Sai_Ip.h are different"
#endif

/* Check if current file and Sai_Ip_HwAccess header file are of the same vendor */
#if (SAI_IP_VENDOR_ID_C != SAI_IP_HWACCESS_VENDOR_ID)
#error "Sai_Ip.c and Sai_Ip_HwAccess.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip_HwAccess header file are of the same Autosar version */
#if ((SAI_IP_AR_RELEASE_MAJOR_VERSION_C     != SAI_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_AR_RELEASE_MINOR_VERSION_C     != SAI_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (SAI_IP_AR_RELEASE_REVISION_VERSION_C  != SAI_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Sai_Ip.c and Sai_Ip_HwAccess.h are different"
#endif

/* Check if current file and Sai_Ip_HwAccess header file are of the same software version */
#if ((SAI_IP_SW_MAJOR_VERSION_C != SAI_IP_HWACCESS_SW_MAJOR_VERSION) || \
     (SAI_IP_SW_MINOR_VERSION_C != SAI_IP_HWACCESS_SW_MINOR_VERSION) || \
     (SAI_IP_SW_PATCH_VERSION_C != SAI_IP_HWACCESS_SW_PATCH_VERSION))
#error "Software Version Numbers of Sai_Ip.c and Sai_Ip_HwAccess.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and Osif header file are of the same Autosar version */
#if ((SAI_IP_AR_RELEASE_MAJOR_VERSION_C     != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Sai_Ip.c and Osif.h are different"
#endif

#if (STD_ON == SAI_IP_ENABLE)
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
/* Check if current file and Dma_Ip header file are of the same Autosar version */
#if ((SAI_IP_AR_RELEASE_MAJOR_VERSION_C     != DMA_IP_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_AR_RELEASE_MINOR_VERSION_C     != DMA_IP_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Sai_Ip.c and Dma_Ip.h are different"
#endif
#endif /* (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE) */
#endif /* (STD_ON == SAI_IP_ENABLE) */

/* Check if current file and SchM_I2s header file are of the same version */
#if ((SAI_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_I2S_AR_RELEASE_MAJOR_VERSION) || \
     (SAI_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_I2S_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Sai_Ip.c and SchM_I2s.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/
#if (STD_ON == SAI_IP_ENABLE)

#define I2S_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2s_MemMap.h"

Sai_Ip_StateStructType * Sai_Ip_apxTxState[SAI_INSTANCE_COUNT]; /* implicit zero initialization: NULL_PTR */
Sai_Ip_StateStructType * Sai_Ip_apxRxState[SAI_INSTANCE_COUNT]; /* implicit zero initialization: NULL_PTR */

#define I2S_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2s_MemMap.h"

#define I2S_START_SEC_CONST_UNSPECIFIED
#include "I2s_MemMap.h"

static SAI_Type * const Sai_Ip_apxSaiBase[SAI_INSTANCE_COUNT] = IP_SAI_BASE_PTRS;

#define I2S_STOP_SEC_CONST_UNSPECIFIED
#include "I2s_MemMap.h"

#define I2S_START_SEC_CONST_8
#include "I2s_MemMap.h"

/* Channel count for each instance */
static const uint8 Sai_Ip_u8ChannelCount[SAI_INSTANCE_COUNT] = SAI_IP_CHANNEL_COUNT_DEFINITION;

#define I2S_STOP_SEC_CONST_8
#include "I2s_MemMap.h"


#define I2S_START_SEC_CODE
#include "I2s_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static void Sai_Ip_Write8Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8Pack,
                                const uint8 u8ChnIdx);
static void Sai_Ip_Write16Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8Pack,
                                const uint8 u8ChnIdx);
static void Sai_Ip_Write32Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8Pack,
                                const uint8 u8ChnIdx);

 static void Sai_Ip_Read8Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8ChnIdx);
static void Sai_Ip_Read16Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8ChnIdx);
static void Sai_Ip_Read32Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8ChnIdx);

static void Sai_Ip_TxIrqCheckFifo(const uint8 u8Instance);

static void Sai_Ip_TxCheckFifoError(SAI_Type * pBase,
                                    const Sai_Ip_StateStructType * pState);
static void Sai_Ip_TxCheckWordStart(SAI_Type * pBase,
                                    const Sai_Ip_StateStructType * pState);
static void Sai_Ip_TxCheckSyncError(SAI_Type * pBase,
                                    const Sai_Ip_StateStructType * pState);

static void Sai_Ip_RxIrqCheckFifo(const uint8 u8Instance);

static Sai_Ip_StatusType Sai_Ip_WaitTimeout(const Sai_Ip_StateStructType * pState,
                            uint32 u32Timeout);
static Sai_Ip_StatusType Sai_Ip_TxWaitFifoComplete(const SAI_Type * pBase,
                            uint32 u32Timeout);
static inline uint32 Sai_Ip_ToBit(boolean bX);
static void Sai_Ip_TxResetVar(const uint8 u8Instance);
static void Sai_Ip_RxResetVar(const uint8 u8Instance);
static void Sai_Ip_SendInt(const uint8 u8Instance,
                        const uint8 * const aData[],
                        uint32 u32Count);
static void Sai_Ip_ReceiveInt(const uint8 u8Instance,
                        uint8 * const aData[],
                        uint32 u32Count);
static boolean Sai_Ip_TxFillFifoInterrupt(const uint8 u8Instance);
static void Sai_Ip_TxMuxLineInterrupt(const uint8 u8Instance,
                                   SAI_Type * pBase,
                                   Sai_Ip_StateStructType * pState,
                                   boolean * pFinish);
static void Sai_Ip_TxMuxMemInterrupt(const uint8 u8Instance,
                                  SAI_Type * pBase,
                                  Sai_Ip_StateStructType * pState,
                                  boolean * pFinish);
static void Sai_Ip_TxMuxDisableInterrupt(const uint8 u8Instance,
                                      SAI_Type * pBase,
                                      Sai_Ip_StateStructType * pState,
                                      boolean * pFinish);
static void Sai_Ip_RxMuxLineInterrupt(const uint8 u8Instance,
                                   SAI_Type * pBase,
                                   Sai_Ip_StateStructType * pState,
                                   boolean * pFinish);
static void Sai_Ip_RxMuxMemInterrupt(const uint8 u8Instance,
                                  SAI_Type * pBase,
                                  Sai_Ip_StateStructType * pState,
                                  boolean * pFinish);
static void Sai_Ip_RxMuxDisableInterrupt(const uint8 u8Instance,
                                      SAI_Type * pBase,
                                      Sai_Ip_StateStructType * pState,
                                      boolean * pFinish);
static void Sai_Ip_InternalClock(uint32 u32MasterClkFreq,
                                 uint32 u32BitClkFreq,
                                 uint32 * pDivisor);
static void Sai_Ip_TxFillMuxLineInt(const uint8 u8Instance,
                                 SAI_Type * pBase,
                                 Sai_Ip_StateStructType * pState,
                                 boolean * pFinish);
static void Sai_Ip_TxFillMuxMemInt(const uint8 u8Instance,
                                SAI_Type * pBase,
                                Sai_Ip_StateStructType * pState,
                                boolean * pFinish);
static void Sai_Ip_TxFillMuxDisableInt(const uint8 u8Instance,
                                    SAI_Type * pBase,
                                    Sai_Ip_StateStructType * pState,
                                    boolean * pFinish);
static void Sai_Ip_GetRxBusyCount(const uint8 u8Instance,
                               uint32 * pCountRemain);
static void Sai_Ip_TxIRQBusy(const uint8 u8Instance);
static void Sai_Ip_RxIRQBusy(const uint8 u8Instance);
static void Sai_Ip_FlushRxFifo(const uint8 u8Instance);

#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
static void Sai_Ip_TxSetupDmaConfig(const uint8 u8Instance);
static void Sai_Ip_SendDma(const uint8 u8Instance,
                           const uint8 * const aData[],
                           uint32 u32Count);
static void Sai_Ip_ReceiveDma(const uint8 u8Instance,
                           uint8 * const aData[],
                           uint32 u32Count);
static void Sai_Ip_TxFillMuxLineDma(const uint8 u8Instance,
                                SAI_Type * pBase,
                                Sai_Ip_StateStructType * pState,
                                boolean * pFinish);
static void Sai_Ip_TxFillMuxMemDma(const uint8 u8Instance,
                                SAI_Type * pBase,
                                Sai_Ip_StateStructType * pState,
                                boolean * pFinish);
static boolean Sai_Ip_TxFillFifoDma(const uint8 u8Instance);
static void Sai_Ip_TxDmaInit(const uint8 u8Instance,
                          const SAI_Type * const pBase,
                          const Sai_Ip_StateStructType * const pState);
static void Sai_Ip_RxDmaInit(const uint8 u8Instance,
                          SAI_Type * pBase,
                          const Sai_Ip_StateStructType * const pState);
static void Sai_Ip_AbortSendingDma(const uint8 u8Instance);
static void Sai_Ip_AbortReceivingDma(const uint8 u8Instance);
static uint8 Sai_Ip_GetFirstEnabledRxChannel(const uint8 u8Instance);
void Sai_Ip_CompleteSendDataUsingDma(const uint8 u8Instance,
                                     boolean error);
void Sai_Ip_CompleteReceiveDataUsingDma(const uint8 u8Instance,
                                        boolean error);
#endif /* SAI_IP_DMA_FEATURE_AVAILABLE */

#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
static void Sai_Ip_RxInitCheck(const uint8 u8Instance,
                            const Sai_Ip_ConfigType * pConfig);
static void Sai_Ip_RxInitCheckSync(const uint8 u8Instance,
                                const Sai_Ip_ConfigType * pConfig);
static void Sai_Ip_TxInitCheck(const uint8 u8Instance,
                            const Sai_Ip_ConfigType * pConfig);
static void Sai_Ip_TxInitCheckSync(const uint8 u8Instance,
                                const Sai_Ip_ConfigType * pConfig);
#endif /* SAI_IP_DEV_ERROR_DETECT */

static void Sai_Ip_AbortSending(const uint8 u8Instance);
static void Sai_Ip_AbortReceiving(const uint8 u8Instance);

static void Sai_Ip_TxIRQHandler(const uint8 u8Instance);
static void Sai_Ip_RxIRQHandler(const uint8 u8Instance);
static void Sai_Ip_StatusBusyHandler(const Sai_Ip_StateStructType * const pState,
                                     uint32 * const pCountRemain);

void Sai_Ip_IRQHandler(const uint8 u8Instance);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
static Sai_Ip_StatusType Sai_Ip_WaitTimeout(const Sai_Ip_StateStructType * pState, uint32 u32Timeout)
{
    Sai_Ip_StatusType eRet = SAI_IP_STATUS_COMPLETED;

    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(u32Timeout, SAI_IP_TIMEOUT_TYPE);
    uint32 u32CurrentTicks = OsIf_GetCounter(SAI_IP_TIMEOUT_TYPE);
    uint32 u32ElapsedTicks = 0U;

    while ((SAI_IP_STATUS_BUSY == pState->eStatus) && (u32ElapsedTicks < u32TimeoutTicks))
    {
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, SAI_IP_TIMEOUT_TYPE);
    }

    if (u32ElapsedTicks >= u32TimeoutTicks)
    {
        eRet = SAI_IP_STATUS_TIMEOUT;
    }

    return eRet;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxWaitFifoComplete
 * Description   : Checks for timeout condition
 *
 *END**************************************************************************/
static Sai_Ip_StatusType Sai_Ip_TxWaitFifoComplete(const SAI_Type * pBase, uint32 u32Timeout)
{
    Sai_Ip_StatusType eRet = SAI_IP_STATUS_COMPLETED;

    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(u32Timeout, SAI_IP_TIMEOUT_TYPE);
    uint32 u32CurrentTicks = OsIf_GetCounter(SAI_IP_TIMEOUT_TYPE);
    uint32 u32ElapsedTicks = 0U;

    while ((!Sai_Ip_TxGetFifoWarnFlag(pBase)) && (u32ElapsedTicks < u32TimeoutTicks))
    {
        u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, SAI_IP_TIMEOUT_TYPE);
    }

    if (u32ElapsedTicks >= u32TimeoutTicks)
    {
        eRet = SAI_IP_STATUS_TIMEOUT;
    }

    return eRet;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_ToBit
 * Description   : Convert boolean to interger
 *
 *END**************************************************************************/
static inline uint32 Sai_Ip_ToBit(boolean bX)
{
    return bX ? 1UL : 0UL;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxResetVar
 * Description   : Reset driver variable
 *
 *END**************************************************************************/
static void Sai_Ip_TxResetVar(const uint8 u8Instance)
{
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];
    uint8 u8Idx = 0U;

    if (NULL_PTR != pState)
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            pState->aChnState[u8Idx].pTxData = NULL_PTR;
            pState->aChnState[u8Idx].pRxData = NULL_PTR;
            pState->aChnState[u8Idx].u32Count = 0U;
        }
        /* unsupported means uninitialized */
        pState->eStatus = SAI_IP_STATUS_UNINITIALIZED;
        pState->bBlocking = FALSE;
        pState->u8ChannelCount = 0U;
        pState->pCallback = NULL_PTR;
        pState->u8NextChn = 0U;
        Sai_Ip_apxTxState[u8Instance] = NULL_PTR;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxResetVar
 * Description   : Reset driver variable
 *
 *END**************************************************************************/
static void Sai_Ip_RxResetVar(const uint8 u8Instance)
{
    Sai_Ip_StateStructType * pState = Sai_Ip_apxRxState[u8Instance];
    uint8 u8Idx = 0U;

    if (NULL_PTR != pState)
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            pState->aChnState[u8Idx].pTxData = NULL_PTR;
            pState->aChnState[u8Idx].pRxData = NULL_PTR;
            pState->aChnState[u8Idx].u32Count = 0U;
        }
        /* unsupported means uninitialized */
        pState->eStatus = SAI_IP_STATUS_UNINITIALIZED;
        pState->u8ChannelCount = 0U;
        pState->bBlocking = FALSE;
        pState->pCallback = NULL_PTR;
        pState->u8NextChn = 0U;
        Sai_Ip_apxRxState[u8Instance] = NULL_PTR;
    }
}

static void Sai_Ip_Write8Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8Pack,
                                const uint8 u8ChnIdx)
{
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxTxState[u8Instance];

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    *u32Data |= ((uint32)*(pState->aChnState[u8ChnIdx].pTxData) << (u8Pack << 3U));
#else
    *u32Data = ((uint32)*(pState->aChnState[u8ChnIdx].pTxData));
    (void)u8Pack;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
}

static void Sai_Ip_Write16Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8Pack,
                                const uint8 u8ChnIdx)
{
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxTxState[u8Instance];

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    *u32Data |= (uint32)*((uint16 *)((uint32)pState->aChnState[u8ChnIdx].pTxData)) << (u8Pack << 4U);
#else
    *u32Data = (uint32)*((uint16 *)((uint32)pState->aChnState[u8ChnIdx].pTxData));
    (void)u8Pack;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_Write32Handler
 * Description   : Handle write 32 bit
 *
 *END**************************************************************************/
static void Sai_Ip_Write32Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8Pack,
                                const uint8 u8ChnIdx)
{
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxTxState[u8Instance];

    (void)u8Pack;
    *u32Data = *(uint32 *)((uint32)pState->aChnState[u8ChnIdx].pTxData);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxMuxLineInterrupt
 * Description   : Manage interrupt transfer, separated from original txIrq
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_TxMuxLineInterrupt(const uint8 u8Instance,
                                   SAI_Type * pBase,
                                   Sai_Ip_StateStructType * pState,
                                   boolean * pFinish)
{
    uint8 u8Idx = 0U;
    uint32 u32Idx1 = 0U;
    uint32 u32Temp = 0U;
    uint32 u32Data = 0U;

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
    {
        if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
        {
            if (pState->aChnState[0U].u32Count < pState->u32PBuffCnt)
            {
                u32Temp = pState->aChnState[0U].u32Count;
            }
            else
            {
                u32Temp = pState->u32PBuffCnt;
            }
            for (u32Idx1 = 0U; u32Idx1 < u32Temp; u32Idx1++)
            {

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                pState->pWriteHandler(&u32Data, u8Instance, u8Pack, pState->u8NextChn);
                u8Pack++;
                pState->u8AccessNum[u8Idx]++;
                if ((u8Pack == pState->u8PackCnt) || (pState->u8AccessNum[u8Idx] == pState->u8FrameSize))
                {
#else
                pState->pWriteHandler(&u32Data, u8Instance, (uint8)0U, pState->u8NextChn);
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                    Sai_Ip_TxWrite(pBase, u8Idx, u32Data);

                    u32Data = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                    u8Pack = 0U;
                    pState->u8AccessNum[u8Idx] = (pState->u8AccessNum[u8Idx] % pState->u8FrameSize);
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                pState->aChnState[pState->u8NextChn].pTxData = &(pState->aChnState[pState->u8NextChn].pTxData)[pState->u8ElementSize];
                pState->u8NextChn++; /* alternate between data block */
                if (pState->u8NextChn == pState->u8ChannelCount)
                {
                    pState->u8NextChn = 0U;
                }
            }
            if (pState->aChnState[0U].u32Count <= pState->u32PBuffCnt)
            {
                *pFinish = TRUE;
                pState->aChnState[0U].u32Count = 0U;
            }
            else
            {
                pState->aChnState[0U].u32Count -= pState->u32PBuffCnt;
            }
            break; /* only one channle enabled in this mode */
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxMuxMemInterrupt
 * Description   : Manage interrupt transfer, separated from original txIrq
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_TxMuxMemInterrupt(const uint8 u8Instance,
                                  SAI_Type * pBase,
                                  Sai_Ip_StateStructType * pState,
                                  boolean * pFinish)
{
    uint8 u8Idx = 0U;
    uint32 u32Idx1 = 0U;
    uint32 u32Temp = 0U;
    uint32 u32Data[SAI_IP_MAX_CHANNEL_COUNT] = SAI_IP_MAX_CHANNEL_VALUE;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack[SAI_IP_MAX_CHANNEL_COUNT] = SAI_IP_MAX_CHANNEL_VALUE;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    if (pState->aChnState[0U].u32Count < pState->u32PBuffCnt)
    {
        u32Temp = pState->aChnState[0U].u32Count;
    }
    else
    {
        u32Temp = pState->u32PBuffCnt;
    }

    for (u32Idx1 = 0U; u32Idx1 < u32Temp; u32Idx1++)
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
            {

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                pState->pWriteHandler(&u32Data[u8Idx], u8Instance, u8Pack[u8Idx], (uint8)0U);
                u8Pack[u8Idx]++;
                pState->u8AccessNum[u8Idx]++;
                if ((u8Pack[u8Idx] == pState->u8PackCnt) || (pState->u8AccessNum[u8Idx] == pState->u8FrameSize))
                {
#else
                pState->pWriteHandler(&u32Data[u8Idx], u8Instance, (uint8)0U, (uint8)0U);
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                    Sai_Ip_TxWrite(pBase, u8Idx, u32Data[u8Idx]);

                    u32Data[u8Idx] = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                    u8Pack[u8Idx] = 0U;
                    pState->u8AccessNum[u8Idx] = (pState->u8AccessNum[u8Idx] % pState->u8FrameSize);
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                pState->aChnState[0U].pTxData = &(pState->aChnState[0U].pTxData)[pState->u8ElementSize];
            }
        }
    }
    if (pState->aChnState[0U].u32Count <= pState->u32PBuffCnt)
    {
        *pFinish = TRUE;
        pState->aChnState[0U].u32Count = 0U;
    }
    else
    {
        pState->aChnState[0U].u32Count -= pState->u32PBuffCnt;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxMuxDisableInterrupt
 * Description   : Manage interrupt transfer, separated from original txIrq
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_TxMuxDisableInterrupt(const uint8 u8Instance,
                                      SAI_Type * pBase,
                                      Sai_Ip_StateStructType * pState,
                                      boolean * pFinish)
{
    uint8 u8Idx = 0U;
    uint32 u32Idx1 = 0U;
    uint32 u32Temp = 0U;
    uint32 u32Data = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    if (pState->aChnState[0U].u32Count < pState->u32PBuffCnt)
    {
        u32Temp = pState->aChnState[0U].u32Count;
    }
    else
    {
        u32Temp = pState->u32PBuffCnt;
    }

    for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
    {
        if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
        {
            for (u32Idx1 = 0U; u32Idx1 < u32Temp; u32Idx1++)
            {

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                pState->pWriteHandler(&u32Data, u8Instance, u8Pack, u8Idx);
                u8Pack++;
                pState->u8AccessNum[u8Idx]++;
                if ((u8Pack == pState->u8PackCnt) || (pState->u8AccessNum[u8Idx] == pState->u8FrameSize))
                {
#else
                pState->pWriteHandler(&u32Data, u8Instance, (uint8)0U, u8Idx);
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                    Sai_Ip_TxWrite(pBase, u8Idx, u32Data);

                    u32Data = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                    u8Pack = 0U;
                    pState->u8AccessNum[u8Idx] = (pState->u8AccessNum[u8Idx] % pState->u8FrameSize);
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                pState->aChnState[u8Idx].pTxData = &(pState->aChnState[u8Idx].pTxData)[pState->u8ElementSize];
            }
        }
    }
    if (pState->aChnState[0U].u32Count <= pState->u32PBuffCnt)
    {
        *pFinish = TRUE;
        pState->aChnState[0U].u32Count = 0U;
    }
    else
    {
        pState->aChnState[0U].u32Count -= pState->u32PBuffCnt;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxIRQBusy
 * Description   : Manage interrupt transfer when in busy state
 *
 *END**************************************************************************/
static void Sai_Ip_TxIRQBusy(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];
    boolean bFinish = FALSE;

    if (SAI_IP_MUX_LINE == pState->eMux)
    {
        Sai_Ip_TxMuxLineInterrupt(u8Instance, pBase, pState, &bFinish);
    }
    else if (SAI_IP_MUX_MEM == pState->eMux)
    {
        Sai_Ip_TxMuxMemInterrupt(u8Instance, pBase, pState, &bFinish);
    }
    else /* mux disabled */
    {
        Sai_Ip_TxMuxDisableInterrupt(u8Instance, pBase, pState, &bFinish);
    }
    if (bFinish)
    {
        pState->eStatus = SAI_IP_STATUS_COMPLETED;
        /* Enter critical section */
        SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_14();

        /* Disable Tx Fifo request */
        Sai_Ip_TxDisableFifoReqInt(pBase);

        /* Exit critical section */
        SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_14();

        if (NULL_PTR != pState->pCallback)
        {
            pState->pCallback(SAI_IP_TX_COMPLETE);
        }
    }
}

static void Sai_Ip_Read8Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8ChnIdx)
{
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxRxState[u8Instance];

    *(uint8 *)pState->aChnState[u8ChnIdx].pRxData = (uint8)(*u32Data);
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    *u32Data >>= 8U;
#else
    /* To avoid misra violation and compiler warning */
    *u32Data = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

}

static void Sai_Ip_Read16Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8ChnIdx)
{
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxRxState[u8Instance];

    *(uint16*)((uint32)(pState->aChnState[u8ChnIdx].pRxData)) = (uint16)(*u32Data);
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    *u32Data >>= 16U;
#else
    /* To avoid misra violation and compiler warning */
    *u32Data = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

}

static void Sai_Ip_Read32Handler(uint32 * const u32Data,
                                const uint8 u8Instance,
                                const uint8 u8ChnIdx)
{
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxRxState[u8Instance];

    *(uint32*)((uint32)(pState->aChnState[u8ChnIdx].pRxData)) = (uint32)(*u32Data);

    /* To avoid misra violation and compiler warning */
    *u32Data = 0U;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxMuxLineInterrupt
 * Description   : Manage interrupt transfer, separated from original rxIrq
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_RxMuxLineInterrupt(const uint8 u8Instance,
                                   SAI_Type * pBase,
                                   Sai_Ip_StateStructType * pState,
                                   boolean * pFinish)
{
    uint8 u8Idx = 0U;
    uint32 u32Idx1 = 0U;
    uint32 u32Temp = 0U;
    uint32 u32Data = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
    {
        if (Sai_Ip_IsRxChannelEnabled(pBase, u8Idx))
        {
            if (pState->aChnState[0U].u32Count < pState->u32PBuffCnt)
            {
                u32Temp = pState->aChnState[0U].u32Count;
            }
            else
            {
                u32Temp = pState->u32PBuffCnt;
            }
            for (u32Idx1 = 0U; u32Idx1 < u32Temp; u32Idx1++)
            {
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                if (0U == u8Pack)
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                {
                    u32Data = Sai_Ip_RxRead(pBase, u8Idx);
                }

                 pState->pReadHandler(&u32Data, u8Instance, pState->u8NextChn);

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                u8Pack++;
                pState->u8AccessNum[u8Idx]++;
                if ((u8Pack == pState->u8PackCnt) || (pState->u8AccessNum[u8Idx] == pState->u8FrameSize))
                {
                    u8Pack = 0U;
                    pState->u8AccessNum[u8Idx] = (pState->u8AccessNum[u8Idx] % pState->u8FrameSize);
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                pState->aChnState[pState->u8NextChn].pRxData = &(pState->aChnState[pState->u8NextChn].pRxData)[pState->u8ElementSize];
                pState->u8NextChn++; /* alternate between data block */
                if (pState->u8NextChn == pState->u8ChannelCount)
                {
                    pState->u8NextChn = 0U;
                }
            }
            if (pState->aChnState[0U].u32Count <= pState->u32PBuffCnt)
            {
                *pFinish = TRUE;
                pState->aChnState[0U].u32Count = 0U;
            }
            else
            {
                pState->aChnState[0U].u32Count -= pState->u32PBuffCnt;
                if (pState->aChnState[0U].u32Count < pState->u32PBuffCnt) /* set watermark below normal level */
                {
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                    if (pState->u8FrameSize < pState->u8PackCnt)
                    {
                        /* Add this condition to avoid misra violation and compiler warning */
                        if (0U < pState->u8FrameSize)
                        {
                            u32Temp = (pState->aChnState[0U].u32Count / pState->u8FrameSize) +
                                      (((pState->aChnState[0U].u32Count % pState->u8FrameSize) != 0U) ? 1U : 0U);
                        }
                    }
                    else
                    {
                        u32Temp = (pState->aChnState[0U].u32Count / pState->u8PackCnt) +
                                  (((pState->aChnState[0U].u32Count % pState->u8PackCnt) != 0U) ? 1U : 0U);
                    }
#else
                    u32Temp = pState->aChnState[0U].u32Count;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                    Sai_Ip_RxSetWatermark(pBase, (uint8)(u32Temp - 1UL));
                }
            }
            break; /* only one channel is enabled in this mode */
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxMuxMemInterrupt
 * Description   : Manage interrupt transfer, separated from original rxIrq
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_RxMuxMemInterrupt(const uint8 u8Instance,
                                  SAI_Type * pBase,
                                  Sai_Ip_StateStructType * pState,
                                  boolean * pFinish)
{
    uint8 u8Idx = 0U;
    uint32 u32Idx1 = 0U;
    uint32 u32Temp = 0U;
    uint32 u32Data[SAI_IP_MAX_CHANNEL_COUNT] = SAI_IP_MAX_CHANNEL_VALUE;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack[SAI_IP_MAX_CHANNEL_COUNT] = SAI_IP_MAX_CHANNEL_VALUE;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    if (pState->aChnState[0U].u32Count < pState->u32PBuffCnt)
    {
        u32Temp = pState->aChnState[0U].u32Count;
    }
    else
    {
        u32Temp = pState->u32PBuffCnt;
    }

    for (u32Idx1 = 0U; u32Idx1 < u32Temp; u32Idx1++)
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsRxChannelEnabled(pBase, u8Idx))
            {
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                if (0U == u8Pack[u8Idx])
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                {
                    u32Data[u8Idx] = Sai_Ip_RxRead(pBase, u8Idx);
                }
                pState->pReadHandler(&u32Data[u8Idx], u8Instance, (uint8)0U);

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                u8Pack[u8Idx]++;
                pState->u8AccessNum[u8Idx]++;
                if ((u8Pack[u8Idx] == pState->u8PackCnt) || (pState->u8AccessNum[u8Idx] == pState->u8FrameSize))
                {
                    u8Pack[u8Idx] = 0U;
                    pState->u8AccessNum[u8Idx] = (pState->u8AccessNum[u8Idx] % pState->u8FrameSize);
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                pState->aChnState[0U].pRxData = &(pState->aChnState[0U].pRxData)[pState->u8ElementSize];
            }
        }
    }
    if (pState->aChnState[0U].u32Count <= pState->u32PBuffCnt)
    {
        *pFinish = TRUE;
        pState->aChnState[0U].u32Count = 0U;
    }
    else
    {
        pState->aChnState[0U].u32Count -= pState->u32PBuffCnt;
        if (pState->aChnState[0U].u32Count < pState->u32PBuffCnt) /* set watermark below normal level */
        {
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
            if (pState->u8FrameSize < pState->u8PackCnt)
            {
                /* Add this condition to avoid misra violation and compiler warning */
                if (0U < pState->u8FrameSize)
                {
                    u32Temp = (pState->aChnState[0U].u32Count / pState->u8FrameSize) +
                             (((pState->aChnState[0U].u32Count % pState->u8FrameSize) != 0U) ? 1U : 0U);
                }
            }
            else
            {
                u32Temp = (pState->aChnState[0U].u32Count / pState->u8PackCnt) +
                          (((pState->aChnState[0U].u32Count % pState->u8PackCnt) != 0U) ? 1U : 0U);
            }
#else
            u32Temp = pState->aChnState[0U].u32Count;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
            Sai_Ip_RxSetWatermark(pBase, (uint8)(u32Temp - 1UL));
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxMuxDisableInterrupt
 * Description   : Manage interrupt transfer, separated from original rxIrq
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_RxMuxDisableInterrupt(const uint8 u8Instance,
                                      SAI_Type * pBase,
                                      Sai_Ip_StateStructType * pState,
                                      boolean * pFinish)
{
    uint8 u8Idx = 0U;
    uint32 u32Idx1 = 0U;
    uint32 u32Temp = 0U;
    uint32 u32Data = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    if (pState->aChnState[0U].u32Count < pState->u32PBuffCnt)
    {
        u32Temp = pState->aChnState[0U].u32Count;
    }
    else
    {
        u32Temp = pState->u32PBuffCnt;
    }

    for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
    {
        if (Sai_Ip_IsRxChannelEnabled(pBase, u8Idx))
        {
            for (u32Idx1 = 0U; u32Idx1 < u32Temp; u32Idx1++)
            {
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                if (0U == u8Pack)
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                {
                    u32Data = Sai_Ip_RxRead(pBase, u8Idx);
                }
                pState->pReadHandler(&u32Data, u8Instance, u8Idx);

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                u8Pack++;
                pState->u8AccessNum[u8Idx]++;
                if ((u8Pack == pState->u8PackCnt) || (pState->u8AccessNum[u8Idx] == pState->u8FrameSize))
                {
                    u8Pack = 0U;
                    pState->u8AccessNum[u8Idx] = (pState->u8AccessNum[u8Idx] % pState->u8FrameSize);
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                pState->aChnState[u8Idx].pRxData = &(pState->aChnState[u8Idx].pRxData)[pState->u8ElementSize];
            }
        }
    }
    if (pState->aChnState[0U].u32Count <= pState->u32PBuffCnt)
    {
        *pFinish = TRUE;
        pState->aChnState[0U].u32Count = 0U;
    }
    else
    {
        pState->aChnState[0U].u32Count -= pState->u32PBuffCnt;
        if (pState->aChnState[0U].u32Count < pState->u32PBuffCnt) /* set watermark below normal level */
        {
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
            if (pState->u8FrameSize < pState->u8PackCnt)
            {
                /* Add this condition to avoid misra violation and compiler warning */
                if (0U < pState->u8FrameSize)
                {
                    u32Temp = (pState->aChnState[0U].u32Count / pState->u8FrameSize) +
                             (((pState->aChnState[0U].u32Count % pState->u8FrameSize) != 0U) ? 1U : 0U);
                }
            }
            else
            {
                u32Temp = (pState->aChnState[0U].u32Count / pState->u8PackCnt) +
                          (((pState->aChnState[0U].u32Count % pState->u8PackCnt) != 0U) ? 1U : 0U);
            }
#else
            u32Temp = pState->aChnState[0U].u32Count;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
            Sai_Ip_RxSetWatermark(pBase, (uint8)(u32Temp - 1UL));
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxIRQBusy
 * Description   : Manage interrupt transfer when in busy state
 *
 *END**************************************************************************/
static void Sai_Ip_RxIRQBusy(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxRxState[u8Instance];
    boolean bFinish = FALSE;

    if (SAI_IP_MUX_LINE == pState->eMux)
    {
        Sai_Ip_RxMuxLineInterrupt(u8Instance, pBase, pState, &bFinish);
    }
    else if (SAI_IP_MUX_MEM == pState->eMux)
    {
        Sai_Ip_RxMuxMemInterrupt(u8Instance, pBase, pState, &bFinish);
    }
    else /* mux disabled */
    {
        Sai_Ip_RxMuxDisableInterrupt(u8Instance, pBase, pState, &bFinish);
    }
    if (bFinish)
    {
        pState->eStatus = SAI_IP_STATUS_COMPLETED;

        /* Enter critical section */
        SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_11();

        /* Disable Rx to stop receive data and if Receiver is master node */
        Sai_Ip_RxDisable(pBase);
#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
        if (pState->bAutoDisableClock)
        {
            /* Disable Rx Bit clock */
            Sai_Ip_RxDisableBitClock(pBase);
            pState->bAutoDisableClock = FALSE;
        }
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

        /* Exit critical section */
        SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_11();

        if (NULL_PTR != pState->pCallback)
        {
            pState->pCallback(SAI_IP_RX_COMPLETE);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_SendInt
 * Description   : Start sending data using interrupt, return immediately
 *
 *END**************************************************************************/
static void Sai_Ip_SendInt(const uint8 u8Instance,
                        const uint8 * const aData[],
                        uint32 u32Count)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];
    boolean bRet = FALSE;
    uint8 u8Idx = 0U;
    uint8 u8Idx1 = 0U;

    /* Enter critical section */
    SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_03();

    pState->eStatus = SAI_IP_STATUS_BUSY;
    for (u8Idx = 0U; u8Idx < pState->u8ChannelCount; u8Idx++)
    {
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
        pState->u8AccessNum[u8Idx] = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
    }
    if (SAI_IP_MUX_LINE == pState->eMux)
    {
        for (u8Idx = 0U; u8Idx < pState->u8ChannelCount; u8Idx++)
        {
        #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(NULL_PTR != aData[u8Idx]);
        #endif

            pState->aChnState[u8Idx].pTxData = aData[u8Idx];
        }
        pState->aChnState[0U].u32Count = u32Count * pState->u8ChannelCount;
    }
    else if (SAI_IP_MUX_MEM == pState->eMux)
    {
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(NULL_PTR != aData[0U]);
    #endif

        pState->aChnState[0U].pTxData = aData[0U];
        pState->aChnState[0U].u32Count = u32Count;
    }
    else
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
            {
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(NULL_PTR != aData[u8Idx1]);
            #endif

                pState->aChnState[u8Idx].pTxData = aData[u8Idx1];
                u8Idx1++;
            }
        }
        pState->aChnState[0U].u32Count = u32Count;
    }

    /* Exit critical section */
    SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_03();

    /* Fill fifo before enable tx */
    if (!Sai_Ip_TxGetBitEnable(pBase, SAI_TCSR_TE_MASK))
    {
        bRet = Sai_Ip_TxFillFifoInterrupt(u8Instance);

        /* Enter critical section */
        SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_12();

        /* if not finished all data after filling fifo operation */
        if (!bRet)
        {
            /* Enable Tx Fifo request */
            Sai_Ip_TxEnableFifoReqInt(pBase);
        }
#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
        if (pState->bAutoDisableClock)
        {
            /* Enable Fifo warning */
            Sai_Ip_TxEnableFifoWarnInt(pBase);
        }
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

        /* Exit critical section */
        SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_12();
    }
    else
    {
        /* Enter critical section */
        SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_12();

        /* Enable Tx Fifo request */
        Sai_Ip_TxEnableFifoReqInt(pBase);
#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
        if (pState->bAutoDisableClock)
        {
            /* Enable Fifo warning */
            Sai_Ip_TxEnableFifoWarnInt(pBase);
        }
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

        /* Exit critical section */
        SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_12();
    }
}

#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxSetupDmaConfig
 * Description   : Setup the configuration for sending data using Dma mode
 *
 *END**************************************************************************/
static void Sai_Ip_TxSetupDmaConfig(const uint8 u8Instance)
{
    const SAI_Type * const pBase = Sai_Ip_apxSaiBase[u8Instance];
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxTxState[u8Instance];

    uint8 u8Idx = 0U;
    uint8 u8Idx1 = 0U;
    Dma_Ip_LogicChannelTransferListType dmaTransferList[2U];
    Dma_Ip_ReturnType eDmaReturnStatus;

    if ((SAI_IP_MUX_LINE == pState->eMux) || (SAI_IP_MUX_DISABLED == pState->eMux))
    {
        u8Idx1 = 0U;
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
            {
                dmaTransferList[0U].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
                dmaTransferList[0U].Value = (uint32)pState->aChnState[u8Idx].pTxData;
                dmaTransferList[1U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
                dmaTransferList[1U].Value = pState->aChnState[u8Idx].u32Count;

                /* Clear error status before setting up DMA configuration */
                eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[u8Idx1], DMA_IP_CH_CLEAR_ERROR);
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
#endif /* (SAI_IP_DEV_ERROR_DETECT == STD_ON) */
                eDmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(pState->aDmaChannel[u8Idx1], dmaTransferList, 2U);
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
            #endif
                eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[u8Idx1], DMA_IP_CH_SET_HARDWARE_REQUEST);
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
            #endif
            u8Idx1++;
           }
        }
    }
    else if (SAI_IP_MUX_MEM == pState->eMux)
    {
        dmaTransferList[0U].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        dmaTransferList[0U].Value = (uint32)pState->aChnState[0U].pTxData;
        dmaTransferList[1U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        dmaTransferList[1U].Value = pState->aChnState[0U].u32Count * pState->u8ChannelCount;

        eDmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(pState->aDmaChannel[0U], dmaTransferList, 2U);
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
    #endif
        eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[0U], DMA_IP_CH_SET_HARDWARE_REQUEST);
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
    #endif
    }
    else
    {
        /* do nothing */
    }
    (void)eDmaReturnStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_SendDma
 * Description   : Start sending data using dma, return immediately
 *
 *END**************************************************************************/
static void Sai_Ip_SendDma(const uint8 u8Instance,
                        const uint8 * const aData[],
                        uint32 u32Count)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];
    boolean ret = FALSE;
    uint8 u8Idx = 0U;
    uint8 u8Idx1 = 0U;

    /* Enter critical section */
    SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_01();

    pState->eStatus = SAI_IP_STATUS_BUSY;
    /* Setup state variable */
    if ((SAI_IP_MUX_LINE == pState->eMux) || (SAI_IP_MUX_DISABLED == pState->eMux))
    {
        u8Idx1 = 0U;
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
            {
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(NULL_PTR != aData[u8Idx1]);
            #endif
                pState->aChnState[u8Idx].u32Count = u32Count;

                pState->aChnState[u8Idx].pTxData = aData[u8Idx1];
                u8Idx1++;
            }
        }
    }
    else if (SAI_IP_MUX_MEM == pState->eMux)
    {
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(NULL_PTR != aData[0U]);
    #endif
        pState->aChnState[0U].u32Count = u32Count;

        pState->aChnState[0U].pTxData = aData[0U];
    }
    else
    {
        /* do nothing */
    }

    /* Exit critical section */
    SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_01();

    /* Fill fifo before enable tx */
    if (!Sai_Ip_TxGetBitEnable(pBase, SAI_TCSR_TE_MASK))
    {
        ret = Sai_Ip_TxFillFifoDma(u8Instance);
    }
    if (Sai_Ip_TxGetBitEnable(pBase, SAI_TCSR_TE_MASK) || (!ret))
    {

        Sai_Ip_TxSetupDmaConfig(u8Instance);

        /* Enter critical section */
        SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_13();

        /* Enable tx DMA requests for the current instance */
        Sai_Ip_TxEnableFifoReqDma(pBase);

        /* Exit critical section */
        SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_13();
    }

}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


/*******************************************************************************
 * Private functions
 ******************************************************************************/


/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_CompleteSendDataUsingDma
 * Description   : Finish sending data using dma
 *
 *END**************************************************************************/
void Sai_Ip_CompleteSendDataUsingDma(const uint8 u8Instance,
                                     boolean error)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];
    Sai_Ip_ReportType event;
#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
    Sai_Ip_StatusType status = SAI_IP_STATUS_COMPLETED;
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

    if (NULL_PTR != pState)
    {
#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
        if (pState->bAutoDisableClock)
        {
            status = Sai_Ip_TxWaitFifoComplete(pBase, SAI_IP_INTERNAL_TIMEOUT_VALUE);

            /* Enter critical section */
            SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_05();

            Sai_Ip_TxDisable(pBase);
            Sai_Ip_TxDisableBitClock(pBase);
            pState->bAutoDisableClock = FALSE;

            /* Exit critical section */
            SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_05();
        }
        else
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */
        {
            /* Enter critical section */
            SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_05();

            /* Disable tx DMA requests for the current instance */
            Sai_Ip_TxDisableFifoReqDma(pBase);

            /* Exit critical section */
            SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_05();
        }

        /* Release the DMA channel */
        if (error)
        {
            pState->eStatus = SAI_IP_STATUS_ERROR;
            event = SAI_IP_ERROR;
        }
        else
        {
#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
            if (SAI_IP_STATUS_COMPLETED != status)
            {
                pState->eStatus = status;
                event = SAI_IP_ERROR;
            }
            else
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */
            {
                pState->eStatus = SAI_IP_STATUS_COMPLETED;
                event = SAI_IP_TX_COMPLETE;
            }
        }
        if (NULL_PTR != pState->pCallback)
        {
            pState->pCallback(event);
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_CompleteReceiveDataUsingDma
 * Description   : Finish receiving data using dma
 *
 *END**************************************************************************/
void Sai_Ip_CompleteReceiveDataUsingDma(const uint8 u8Instance,
                                        boolean error)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxRxState[u8Instance];
    Sai_Ip_ReportType event;

    if (NULL_PTR != pState)
    {
        /* Disable Rx DMA requests for the current instance */
        /* Enter critical section */
        SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_10();

        /* Disable Rx to stop receive data and if Receiver is master node */
        Sai_Ip_RxDisable(pBase);
#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
        if (pState->bAutoDisableClock)
        {
            /* Disable Rx Bit clock */
            Sai_Ip_RxDisableBitClock(pBase);
            pState->bAutoDisableClock = FALSE;
        }
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

        /* Exot critical section */
        SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_10();

        /* Release the DMA channel */
        if (error)
        {
            pState->eStatus = SAI_IP_STATUS_ERROR;
            event = SAI_IP_ERROR;
        }
        else
        {
            pState->eStatus = SAI_IP_STATUS_COMPLETED;
            event = SAI_IP_RX_COMPLETE;
        }
        if (NULL_PTR != pState->pCallback)
        {
            pState->pCallback(event);
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_ReceiveDma
 * Description   : Start receiving data using dma, return immediately
 * Because using dma with channel linking makes request source has a chance to
 * assert once more after data is read from fifo (fifo level is already equal
 * watermark, which shouldn't assert request source anymore but it did). So
 * value zero shouldn't be used to set watermark for dma. A workaround is done by
 * receive count-1 first with watermark 1, then set watermark to 0 and receive last
 * data.
 *
 *END**************************************************************************/
static void Sai_Ip_ReceiveDma(const uint8 u8Instance,
                              uint8 * const aData[],
                              uint32 u32Count)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxRxState[u8Instance];
    uint8 u8NumChan = pState->u8ChannelCount;
    uint8 u8Idx = 0U;
    uint8 u8Idx1 = 0U;
    Dma_Ip_LogicChannelTransferListType dmaTransferList[2U];
    Dma_Ip_ReturnType eDmaReturnStatus;

    pState->eStatus = SAI_IP_STATUS_BUSY;
    if ((SAI_IP_MUX_DISABLED == pState->eMux) || (SAI_IP_MUX_LINE == pState->eMux))
    {
        u8Idx1 = 0U;
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsRxChannelEnabled(pBase, u8Idx))
            {
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(NULL_PTR != aData[u8Idx1]);
            #endif
                pState->aChnState[u8Idx].u32Count = u32Count;
                pState->aChnState[u8Idx].pRxData = aData[u8Idx1];
                dmaTransferList[0U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                dmaTransferList[0U].Value = (uint32)aData[u8Idx1];
                dmaTransferList[1U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
                dmaTransferList[1U].Value = u32Count;

                /* Clear error status before setting up DMA configuration */
                eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[u8Idx1], DMA_IP_CH_CLEAR_ERROR);
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
#endif /* (SAI_IP_DEV_ERROR_DETECT == STD_ON) */
                eDmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(pState->aDmaChannel[u8Idx1], dmaTransferList, 2U);
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
            #endif
                eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[u8Idx1], DMA_IP_CH_SET_HARDWARE_REQUEST);
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
            #endif
                if (1U == u8NumChan)
                {
                    break;
                }
                u8Idx1++;
            }
        }
    }
    else if (SAI_IP_MUX_MEM == pState->eMux)
    {
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(NULL_PTR != aData[0U]);
    #endif
        pState->aChnState[0U].u32Count = u32Count;
        dmaTransferList[0U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        dmaTransferList[0U].Value = (uint32)aData[0U];
        dmaTransferList[1U].Param = DMA_IP_CH_SET_MAJORLOOP_COUNT;
        dmaTransferList[1U].Value = u32Count * u8NumChan;

        eDmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(pState->aDmaChannel[0U], dmaTransferList, 2U);
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
    #endif
        eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[0U], DMA_IP_CH_SET_HARDWARE_REQUEST);
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
    #endif
    }
    else
    {
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(FALSE);
    #endif
    }
    /* Enter critical section */
    SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_07();

    /* Enable rx DMA requests for the current instance */
    Sai_Ip_RxEnableFifoReqDma(pBase);

    /* Exir critical section */
    SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_07();

    (void)eDmaReturnStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxDmaInit
 * Description   : Setup dma, separated from original init function
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_TxDmaInit(const uint8 u8Instance,
                             const SAI_Type * const pBase,
                             const Sai_Ip_StateStructType * const pState)
{
    uint8 u8NumChan = 0U;
    uint8 u8Idx = 0U;
    uint8 u8Idx1 = 0U;
    uint8 xferSize = 0U;
    Dma_Ip_LogicChannelTransferListType dmaTransferList[21U];
    Dma_Ip_LogicChannelGlobalListType dmaGlobalList[1U];
    Dma_Ip_ReturnType eDmaReturnStatus;

    u8NumChan = pState->u8ChannelCount;
    switch (pState->u8ElementSize)
    {
        case 1U:
            xferSize = DMA_IP_TRANSFER_SIZE_1_BYTE;
            break;
        case 2U:
            xferSize = DMA_IP_TRANSFER_SIZE_2_BYTE;
            break;
        case 4U:
            xferSize = DMA_IP_TRANSFER_SIZE_4_BYTE;
            break;
        default:
        #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
        #endif
            break;
    }

    /* Set up parameters for Dma_Ip_LogicChannelTransferListType */
    dmaTransferList[0U].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
    dmaTransferList[0U].Value = 0U;
    dmaTransferList[1U].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    dmaTransferList[1U].Value = xferSize;
    dmaTransferList[2U].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    dmaTransferList[2U].Value = pState->u8ElementSize;
    dmaTransferList[3U].Param = DMA_IP_CH_SET_SOURCE_SIGNED_LAST_ADDR_ADJ;
    dmaTransferList[3U].Value = 0U;
    dmaTransferList[4U].Param = DMA_IP_CH_SET_SOURCE_MODULO;
    dmaTransferList[4U].Value = 0U;

    dmaTransferList[5U].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    dmaTransferList[5U].Value = xferSize;
    dmaTransferList[6U].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    dmaTransferList[6U].Value = 0U;
    dmaTransferList[7U].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
    dmaTransferList[7U].Value = 0U;
    dmaTransferList[8U].Param = DMA_IP_CH_SET_DESTINATION_MODULO;
    dmaTransferList[8U].Value = 0U;

    dmaTransferList[9U].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    dmaTransferList[9U].Value = pState->u8ElementSize;
    dmaTransferList[10U].Param = DMA_IP_CH_SET_MINORLOOP_EN_SRC_OFFSET;
    dmaTransferList[10U].Value = 0U;
    dmaTransferList[11U].Param = DMA_IP_CH_SET_MINORLOOP_EN_DST_OFFSET;
    dmaTransferList[11U].Value = 0U;
    dmaTransferList[12U].Param = DMA_IP_CH_SET_MINORLOOP_SIGNED_OFFSET;
    dmaTransferList[12U].Value = 0U;

    dmaTransferList[13U].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    dmaTransferList[13U].Value = 1U;
    dmaTransferList[14U].Param = DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT;
    dmaTransferList[14U].Value = 0U;

    /* Set up parameters for Dma_Ip_LogicChannelGlobalListType */
    dmaGlobalList[0U].Param = DMA_IP_CH_SET_EN_ERROR_INTERRUPT;
    dmaGlobalList[0U].Value = 1U;

    if ((SAI_IP_MUX_LINE == pState->eMux) || (SAI_IP_MUX_DISABLED == pState->eMux))
    {
        u8Idx1 = 0U;
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
            {
                if (u8Idx1 != (u8NumChan - 1U))
                {
                    dmaTransferList[15U].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
                    dmaTransferList[15U].Value = 0U;
                    dmaTransferList[16U].Param = DMA_IP_CH_SET_MINORLOOP_EN_LINK;
                    dmaTransferList[16U].Value = 1U;
                    dmaTransferList[17U].Param = DMA_IP_CH_SET_MAJORLOOP_EN_LINK;
                    dmaTransferList[17U].Value = 1U;
                    dmaTransferList[18U].Param = DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH;
                    dmaTransferList[18U].Value = pState->aDmaChannel[u8Idx1+1U];
                    dmaTransferList[19U].Param = DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH;
                    dmaTransferList[19U].Value = pState->aDmaChannel[u8Idx1+1U];
                }
                else
                {
                    dmaTransferList[15U].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
                    dmaTransferList[15U].Value = 1U;
                    dmaTransferList[16U].Param = DMA_IP_CH_SET_MINORLOOP_EN_LINK;
                    dmaTransferList[16U].Value = 0U;
                    dmaTransferList[17U].Param = DMA_IP_CH_SET_MAJORLOOP_EN_LINK;
                    dmaTransferList[17U].Value = 0U;
                    dmaTransferList[18U].Param = DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH;
                    dmaTransferList[18U].Value = 0U;
                    dmaTransferList[19U].Param = DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH;
                    dmaTransferList[19U].Value = 0U;
                }
#ifdef FEATURE_SAI_IP_BIG_ENDIAN
                dmaTransferList[20U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                dmaTransferList[20U].Value = (uint32)(&(pBase->TDR[u8Idx]))+DATA_REG_SIZE-pState->u8ElementSize;
#else
                dmaTransferList[20U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
                dmaTransferList[20U].Value = (uint32)(&(pBase->TDR[u8Idx]));
#endif

                /* Clear error status before setting up DMA configuration */
                eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[u8Idx1], DMA_IP_CH_CLEAR_ERROR);
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
#endif /* (SAI_IP_DEV_ERROR_DETECT == STD_ON) */
                /* Configure the transfer control descriptor for the DMA channel */
                eDmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(pState->aDmaChannel[u8Idx1], dmaTransferList, 21U);
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
            #endif
                eDmaReturnStatus = Dma_Ip_SetLogicChannelGlobalList(pState->aDmaChannel[u8Idx1], dmaGlobalList, 1U);
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
            #endif
                u8Idx1++;
           }
        }
    }
    else /* MUX MEM */
    {
        dmaTransferList[15U].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
        dmaTransferList[15U].Value = 1U;
        dmaTransferList[16U].Param = DMA_IP_CH_SET_MINORLOOP_EN_LINK;
        dmaTransferList[16U].Value = 0U;
        dmaTransferList[17U].Param = DMA_IP_CH_SET_MAJORLOOP_EN_LINK;
        dmaTransferList[17U].Value = 0U;
        dmaTransferList[18U].Param = DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH;
        dmaTransferList[18U].Value = 0;
        dmaTransferList[19U].Param = DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH;
        dmaTransferList[19U].Value = 0;
#ifdef FEATURE_SAI_IP_BIG_ENDIAN
        dmaTransferList[20U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        dmaTransferList[20U].Value = (uint32)(&(pBase->TDR[0U]))+DATA_REG_SIZE-pState->u8ElementSize;
#else
        dmaTransferList[20U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
        dmaTransferList[20U].Value = (uint32)(&(pBase->TDR[0U]));
#endif

        /* Configure the transfer control descriptor for the DMA channel */
        eDmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(pState->aDmaChannel[0U], dmaTransferList, 21U);
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
    #endif
        eDmaReturnStatus = Dma_Ip_SetLogicChannelGlobalList(pState->aDmaChannel[0U], dmaGlobalList, 1U);
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
    #endif
    }

    (void)eDmaReturnStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxDmaInit
 * Description   : Setup dma, separated from original init function
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_RxDmaInit(const uint8 u8Instance,
                             SAI_Type * pBase,
                             const Sai_Ip_StateStructType * const pState)
{
    uint8 u8NumChan = 0U;
    uint8 u8Idx = 0U;
    uint8 u8Idx1 = 0U;
    uint8 xferSize = 0U;
    Dma_Ip_LogicChannelTransferListType dmaTransferList[21U];
    Dma_Ip_LogicChannelGlobalListType dmaGlobalList[1U];
    Dma_Ip_ReturnType eDmaReturnStatus;

    u8NumChan = pState->u8ChannelCount;
    switch (pState->u8ElementSize)
    {
        case 1U:
            xferSize = DMA_IP_TRANSFER_SIZE_1_BYTE;
            break;
        case 2U:
            xferSize = DMA_IP_TRANSFER_SIZE_2_BYTE;
            break;
        case 4U:
            xferSize = DMA_IP_TRANSFER_SIZE_4_BYTE;
            break;
        default:
        #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(FALSE);
        #endif
            break;
    }

    /* Set up parameters for Dma_Ip_LogicChannelTransferListType */
    dmaTransferList[0U].Param = DMA_IP_CH_SET_SOURCE_TRANSFER_SIZE;
    dmaTransferList[0U].Value = xferSize;
    dmaTransferList[1U].Param = DMA_IP_CH_SET_SOURCE_SIGNED_OFFSET;
    dmaTransferList[1U].Value = 0U;
    dmaTransferList[2U].Param = DMA_IP_CH_SET_SOURCE_SIGNED_LAST_ADDR_ADJ;
    dmaTransferList[2U].Value = 0U;
    dmaTransferList[3U].Param = DMA_IP_CH_SET_SOURCE_MODULO;
    dmaTransferList[3U].Value = 0U;

    dmaTransferList[4U].Param = DMA_IP_CH_SET_DESTINATION_ADDRESS;
    dmaTransferList[4U].Value = 0U;
    dmaTransferList[5U].Param = DMA_IP_CH_SET_DESTINATION_TRANSFER_SIZE;
    dmaTransferList[5U].Value = xferSize;
    dmaTransferList[6U].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_OFFSET;
    dmaTransferList[6U].Value = pState->u8ElementSize;
    dmaTransferList[7U].Param = DMA_IP_CH_SET_DESTINATION_SIGNED_LAST_ADDR_ADJ;
    dmaTransferList[7U].Value = 0U;
    dmaTransferList[8U].Param = DMA_IP_CH_SET_DESTINATION_MODULO;
    dmaTransferList[8U].Value = 0U;

    dmaTransferList[9U].Param = DMA_IP_CH_SET_MINORLOOP_SIZE;
    dmaTransferList[9U].Value = pState->u8ElementSize;
    dmaTransferList[10U].Param = DMA_IP_CH_SET_MINORLOOP_EN_SRC_OFFSET;
    dmaTransferList[10U].Value = 0U;
    dmaTransferList[11U].Param = DMA_IP_CH_SET_MINORLOOP_EN_DST_OFFSET;
    dmaTransferList[11U].Value = 0U;
    dmaTransferList[12U].Param = DMA_IP_CH_SET_MINORLOOP_SIGNED_OFFSET;
    dmaTransferList[12U].Value = 0U;

    dmaTransferList[13U].Param = DMA_IP_CH_SET_CONTROL_DIS_AUTO_REQUEST;
    dmaTransferList[13U].Value = 1U;
    dmaTransferList[14U].Param = DMA_IP_CH_SET_CONTROL_EN_HALF_MAJOR_INTERRUPT;
    dmaTransferList[14U].Value = 0U;

    /* Set up parameters for Dma_Ip_LogicChannelGlobalListType */
    dmaGlobalList[0U].Param = DMA_IP_CH_SET_EN_ERROR_INTERRUPT;
    dmaGlobalList[0U].Value = 1U;

    u8Idx1 = 0U;
    if ((SAI_IP_MUX_DISABLED == pState->eMux) || (SAI_IP_MUX_LINE == pState->eMux))
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsRxChannelEnabled(pBase, u8Idx))
            {
                if (u8Idx1 != (u8NumChan - 1U))
                {
                    dmaTransferList[15U].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
                    dmaTransferList[15U].Value = 0U;
                    dmaTransferList[16U].Param = DMA_IP_CH_SET_MINORLOOP_EN_LINK;
                    dmaTransferList[16U].Value = 1U;
                    dmaTransferList[17U].Param = DMA_IP_CH_SET_MAJORLOOP_EN_LINK;
                    dmaTransferList[17U].Value = 1U;
                    dmaTransferList[18U].Param = DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH;
                    dmaTransferList[18U].Value = pState->aDmaChannel[u8Idx1+1U];
                    dmaTransferList[19U].Param = DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH;
                    dmaTransferList[19U].Value = pState->aDmaChannel[u8Idx1+1U];
                }
                else
                {
                    dmaTransferList[15U].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
                    dmaTransferList[15U].Value = 1U;
                    dmaTransferList[16U].Param = DMA_IP_CH_SET_MINORLOOP_EN_LINK;
                    dmaTransferList[16U].Value = 0U;
                    dmaTransferList[17U].Param = DMA_IP_CH_SET_MAJORLOOP_EN_LINK;
                    dmaTransferList[17U].Value = 0U;
                    dmaTransferList[18U].Param = DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH;
                    dmaTransferList[18U].Value = 0U;
                    dmaTransferList[19U].Param = DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH;
                    dmaTransferList[19U].Value = 0U;
                }
            #ifdef FEATURE_SAI_IP_BIG_ENDIAN
                dmaTransferList[20U].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
                dmaTransferList[20U].Value = (uint32)(&(pBase->RDR[u8Idx]))+DATA_REG_SIZE-pState->u8ElementSize;
            #else
                dmaTransferList[20U].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
                dmaTransferList[20U].Value = (uint32)(&(pBase->RDR[u8Idx]));
            #endif

                /* Clear error status before setting up DMA configuration */
                eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[u8Idx1], DMA_IP_CH_CLEAR_ERROR);
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
#endif /* (SAI_IP_DEV_ERROR_DETECT == STD_ON) */
                /* Configure the transfer control descriptor for the DMA channel */
                eDmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(pState->aDmaChannel[u8Idx1], dmaTransferList, 21U);
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
            #endif
                eDmaReturnStatus = Dma_Ip_SetLogicChannelGlobalList(pState->aDmaChannel[u8Idx1], dmaGlobalList, 1U);
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
            #endif

                if (1U == u8NumChan)
                {
                    break;
                }
                u8Idx1++;
            }
        }
    }
    else /* MUX_MEM */
    {
        dmaTransferList[15U].Param = DMA_IP_CH_SET_CONTROL_EN_MAJOR_INTERRUPT;
        dmaTransferList[15U].Value = 1U;
        dmaTransferList[16U].Param = DMA_IP_CH_SET_MINORLOOP_EN_LINK;
        dmaTransferList[16U].Value = 0U;
        dmaTransferList[17U].Param = DMA_IP_CH_SET_MAJORLOOP_EN_LINK;
        dmaTransferList[17U].Value = 0U;
        dmaTransferList[18U].Param = DMA_IP_CH_SET_MINORLOOP_LOGIC_LINK_CH;
        dmaTransferList[18U].Value = 0;
        dmaTransferList[19U].Param = DMA_IP_CH_SET_MAJORLOOP_LOGIC_LINK_CH;
        dmaTransferList[19U].Value = 0;
#ifdef FEATURE_SAI_IP_BIG_ENDIAN
        dmaTransferList[20U].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        dmaTransferList[20U].Value = (uint32)(&(pBase->RDR[0U]))+DATA_REG_SIZE-pState->u8ElementSize;
#else
        dmaTransferList[20U].Param = DMA_IP_CH_SET_SOURCE_ADDRESS;
        dmaTransferList[20U].Value = (uint32)(&(pBase->RDR[0U]));
#endif

        /* Configure the transfer control descriptor for the DMA channel */
        eDmaReturnStatus = Dma_Ip_SetLogicChannelTransferList(pState->aDmaChannel[0U], dmaTransferList, 21U);
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
    #endif
        eDmaReturnStatus = Dma_Ip_SetLogicChannelGlobalList(pState->aDmaChannel[0U], dmaGlobalList, 1U);
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
    #endif
    }
    Sai_Ip_RxSetWatermark(pBase, 0U);

    (void)eDmaReturnStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxFillMuxLineDma
 * Description   : Fill fifo mux line dma, separated from original function
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_TxFillMuxLineDma(const uint8 u8Instance,
                                 SAI_Type * pBase,
                                 Sai_Ip_StateStructType * pState,
                                 boolean * pFinish)
{
    uint8 u8EnabledChannel = 0U;
    uint8 u8Idx = 0U;
    boolean bIsTxFull = FALSE;
    uint32 u32Data = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
    {
        if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
        {
            u8EnabledChannel = u8Idx;
            bIsTxFull = Sai_Ip_IsTxFifoFull(pBase, u8Idx);
            /* all channel fifo should be in the same level */
            while (!((pState->aChnState[u8Idx].u32Count == 0UL) || bIsTxFull))
            {
                switch(pState->u8ElementSize)
                {
                    case 1U:
                        u32Data = ((uint32)*pState->aChnState[u8Idx].pTxData);
                        break;
                    case 2U:
                        u32Data = (uint32)(*(uint16*)((uint32)pState->aChnState[u8Idx].pTxData));
                        break;
                    case 4U:
                        /* FIFO pack offset (4-byte): data */
                        u32Data = *(uint32*)((uint32)pState->aChnState[u8Idx].pTxData);
                        break;
                    default:
                    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                        DevAssert(FALSE);
                    #endif
                        break;
                }
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                u8Pack++;
                if ((u8Pack == pState->u8PackCnt) || (1U == pState->aChnState[u8Idx].u32Count))
                {
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                    Sai_Ip_TxWrite(pBase, u8Idx, u32Data);
                    u32Data = 0U;
                    bIsTxFull = Sai_Ip_IsTxFifoFull(pBase, u8Idx);
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                    u8Pack = 0U;
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                pState->aChnState[u8Idx].pTxData = &(pState->aChnState[u8Idx].pTxData)[pState->u8ElementSize];
                pState->aChnState[u8Idx].u32Count--;
            }
        }
    }
    if (0UL == pState->aChnState[u8EnabledChannel].u32Count)
    {
        *pFinish = TRUE;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxFillMuxMemDma
 * Description   : Fill fifo mux mem dma, separated from original function
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_TxFillMuxMemDma(const uint8 u8Instance,
                                SAI_Type * pBase,
                                Sai_Ip_StateStructType * pState,
                                boolean * pFinish)
{
    uint8 u8Idx = 0U;
    boolean bFull = FALSE;
    uint32 u32Data[SAI_IP_MAX_CHANNEL_COUNT] = SAI_IP_MAX_CHANNEL_VALUE;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack[SAI_IP_MAX_CHANNEL_COUNT] = SAI_IP_MAX_CHANNEL_VALUE;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    while (!((0UL == pState->aChnState[0U].u32Count) || (bFull)))
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            /* check the first enabled channel fifo */
            if (Sai_Ip_IsTxFifoFull(pBase, u8Idx))
            {
                bFull = TRUE;
                break;
            }
            if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
            {
                switch (pState->u8ElementSize)
                {
                    case 1U:
                        u32Data[u8Idx] = ((uint32)*pState->aChnState[0U].pTxData);
                        break;
                    case 2U:
                        u32Data[u8Idx] = (uint32)(*(uint16*)((uint32)pState->aChnState[0U].pTxData));
                        break;
                    case 4U:
                        /* FIFO pack offset (4-byte): data */
                        u32Data[u8Idx] = *(uint32*)((uint32)pState->aChnState[0U].pTxData);
                        break;
                    default:
                    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                        DevAssert(FALSE);
                    #endif
                        break;
                }
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                u8Pack[u8Idx]++;
                if (u8Pack[u8Idx] == pState->u8PackCnt)
                {
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                    Sai_Ip_TxWrite(pBase, u8Idx, u32Data[u8Idx]);
                    u32Data[u8Idx] = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                    u8Pack[u8Idx] = 0U;
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
                pState->aChnState[0U].pTxData = &(pState->aChnState[0U].pTxData)[pState->u8ElementSize];
            }
        }
        if (!bFull)
        {
            pState->aChnState[0U].u32Count--;
        }
    }
    if (0UL == pState->aChnState[0U].u32Count)
    {
        *pFinish = TRUE;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxFillFifoDma
 * Description   : Fill fifo before enable tx to avoid run error
 *
 *END**************************************************************************/
static boolean Sai_Ip_TxFillFifoDma(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];
    boolean bFinish = FALSE;

    if ((SAI_IP_MUX_LINE == pState->eMux) || (SAI_IP_MUX_DISABLED == pState->eMux))
    {
        Sai_Ip_TxFillMuxLineDma(u8Instance, pBase, pState, &bFinish);
    }
    else if (SAI_IP_MUX_MEM == pState->eMux)
    {
        Sai_Ip_TxFillMuxMemDma(u8Instance, pBase, pState, &bFinish);
    }
    else /* should not happen */
    {
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(FALSE);
    #endif
    }
    if (bFinish)
    {
        pState->eStatus = SAI_IP_STATUS_COMPLETED;
        if (NULL_PTR != pState->pCallback)
        {
            pState->pCallback(SAI_IP_TX_COMPLETE);
        }
    }
    return bFinish;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_AbortSendingDma
 * Description   : Abort ongoing sending dma
 *
 *END**************************************************************************/
static void Sai_Ip_AbortSendingDma(const uint8 u8Instance)
{
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    uint8 u8Idx = 0U;
    uint8 u8Idx1 = 0U;
    Dma_Ip_ReturnType eDmaReturnStatus;

    /* Enter critical section */
    SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_15();

    /* Disable tx DMA requests for the current instance */
    Sai_Ip_TxDisableFifoReqDma(pBase);

    /* Exit critical section */
    SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_15();

    (void)Dma_Ip_GetLogicChannelParam(pState->aDmaChannel[0U], DMA_IP_CH_GET_CURRENT_ITER_COUNT, &(pState->aChnState[0U].u32Count));
    /* stop all dma channel*/
    if ((SAI_IP_MUX_DISABLED == pState->eMux) || (SAI_IP_MUX_LINE == pState->eMux))
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
            {
                eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[u8Idx1], DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
            #endif
                u8Idx1++;
            }
        }
    }
    else
    {
        eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[0U], DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
        #endif
    }

    (void)eDmaReturnStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_AbortReceivingDma
 * Description   : Abort ongoing receiving dma
 *
 *END**************************************************************************/
static void Sai_Ip_AbortReceivingDma(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxRxState[u8Instance];
    uint8 u8Idx = 0U;
    uint8 u8Idx1 = 0U;
    uint32 u32Temp = 0U;
    Dma_Ip_ReturnType eDmaReturnStatus;

    /* Enter critical section */
    SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_16();

    /* Disable Rx to stop receive data and if Receiver is master node */
    Sai_Ip_RxDisable(pBase);
#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
    if (pState->bAutoDisableClock)
    {
        /* Disable Rx Bit clock */
        Sai_Ip_RxDisableBitClock(pBase);
        pState->bAutoDisableClock = FALSE;
    }
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

    /* Exot critical section */
    SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_16();

    (void)Sai_Ip_GetReceivingStatus(u8Instance, &u32Temp);
    pState->aChnState[0U].u32Count = u32Temp;
    /* stop all dma channel*/
    if ((SAI_IP_MUX_DISABLED == pState->eMux) || (SAI_IP_MUX_LINE == pState->eMux))
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsRxChannelEnabled(pBase, u8Idx))
            {
                eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[u8Idx1], DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
            #endif
                u8Idx1++;
            }
        }
    }
    else
    {
        eDmaReturnStatus = Dma_Ip_SetLogicChannelCommand(pState->aDmaChannel[0U], DMA_IP_CH_CLEAR_HARDWARE_REQUEST);
        #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(DMA_IP_STATUS_SUCCESS == eDmaReturnStatus);
        #endif
    }

    (void)eDmaReturnStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_GetFirstEnabledRxChannel
 * Description   : Get first enabled rx channel
 *
 *END**************************************************************************/
static uint8 Sai_Ip_GetFirstEnabledRxChannel(const uint8 u8Instance)
{
    const SAI_Type * const pBase = Sai_Ip_apxSaiBase[u8Instance];
    uint8 u8Idx = 0U;

    for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
    {
        if (Sai_Ip_IsRxChannelEnabled(pBase, u8Idx))
        {
            break;
        }
    }
    return u8Idx;
}

#endif /* SAI_IP_DMA_FEATURE_AVAILABLE */

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_ReceiveInt
 * Description   : Start receiving data using interrupt, return immediately
 *
 *END**************************************************************************/
static void Sai_Ip_ReceiveInt(const uint8 u8Instance,
                           uint8 * const aData[],
                           uint32 u32Count)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxRxState[u8Instance];
    uint8 u8Idx = 0U;
    uint8 u8Idx1 = 0U;

    pState->eStatus = SAI_IP_STATUS_BUSY;
    for (u8Idx = 0U; u8Idx < pState->u8ChannelCount; u8Idx++)
    {
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
        pState->u8AccessNum[u8Idx] = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
    }
    if (SAI_IP_MUX_LINE == pState->eMux)
    {
        for (u8Idx = 0U; u8Idx < pState->u8ChannelCount; u8Idx++)
        {
        #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
            DevAssert(NULL_PTR != aData[u8Idx]);
        #endif
            pState->aChnState[u8Idx].pRxData = aData[u8Idx];
        }
        pState->aChnState[0U].u32Count = pState->u8ChannelCount * u32Count;
    }
    else if (SAI_IP_MUX_MEM == pState->eMux)
    {
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(NULL_PTR != aData[0U]);
    #endif
        pState->aChnState[0U].pRxData = aData[0U];
        pState->aChnState[0U].u32Count = u32Count;
    }
    else
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (Sai_Ip_IsRxChannelEnabled(pBase, u8Idx))
            {
            #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
                DevAssert(NULL_PTR != aData[u8Idx1]);
            #endif
                pState->aChnState[u8Idx].pRxData = aData[u8Idx1];
                u8Idx1++;
            }
        }
        pState->aChnState[0U].u32Count = u32Count;
    }

    if (pState->aChnState[0U].u32Count < pState->u32PBuffCnt)
    {
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
        if (pState->u8FrameSize < pState->u8PackCnt)
        {
            /* Add this condition to avoid misra violation and compiler warning */
            if (0U < pState->u8FrameSize)
            {
                u8Idx = (uint8)((pState->aChnState[0U].u32Count / pState->u8FrameSize) +
                               (((pState->aChnState[0U].u32Count % pState->u8FrameSize) != 0U) ? 1U : 0U));
            }
        }
        else
        {
            u8Idx = (uint8)((pState->aChnState[0U].u32Count / pState->u8PackCnt) +
                           (((pState->aChnState[0U].u32Count % pState->u8PackCnt) != 0U) ? 1U : 0U));
        }
#else
        u8Idx = (uint8)(pState->aChnState[0U].u32Count);
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */
        Sai_Ip_RxSetWatermark(pBase, (u8Idx - 1U));
    }
    else
    {
        Sai_Ip_RxSetWatermark(pBase, (pState->u8BufferAccessSize - 1U));
    }

    /* Enter critical section */
    SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_09();

    Sai_Ip_RxEnableFifoReqInt(pBase);

    /* Exit critical section */
    SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_09();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_InternalClock
 * Description   : Setup internal clock, separated from original init function
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_InternalClock(uint32 u32MasterClkFreq,
                                 uint32 u32BitClkFreq,
                                 uint32 * pDivisor)
{
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(0UL < u32MasterClkFreq);
    DevAssert(0U != u32BitClkFreq);
#endif
    *pDivisor = ((u32MasterClkFreq / u32BitClkFreq) / 2UL);
    if (*pDivisor > 0U)
    {
        *pDivisor -= 1UL;
    }
    if (255U < *pDivisor)
    {
        *pDivisor = 255U;
    }
}

#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
/*FUNCTION**********************************************************************
*
* Function Name : Sai_Ip_TxInitCheckSync
* Description   : Check dev assert for syncing
*END*************************************************************************/
static void Sai_Ip_TxInitCheckSync(const uint8 u8Instance,
                                const Sai_Ip_ConfigType * pConfig)
{
    const SAI_Type * const pBase = Sai_Ip_apxSaiBase[u8Instance];
    uint32 u32Rcsr = pBase->RCSR;
    /* check if sync with other and other must be enabled later */
    DevAssert((SAI_IP_SYNC_WITH_OTHER != pConfig->eSyncMode) ||
              ((SAI_IP_SYNC_WITH_OTHER == pConfig->eSyncMode) && (0U == (u32Rcsr & SAI_RCSR_RE_MASK))));
#ifdef FEATURE_SAI_IP_SYNC_WITH_OTHER_INST
    uint32 u32Sai2Tcsr = 0U;
    uint32 u32Sai2Rcsr = 0U;
    /* sai2 cannot sync with sai2 */
    DevAssert(!((2UL == u8Instance) &&
                 ((SAI_IP_SYNC_WITH_SAI2_SAME == pConfig->eSyncMode) || (SAI_IP_SYNC_WITH_SAI2_OTHER == pConfig->eSyncMode))));
    /* sync with sai2 and sai2 same part must be enabled later */
    if (SAI_IP_SYNC_WITH_SAI2_SAME == pConfig->eSyncMode)
    {
        u32Sai2Tcsr = Sai_Ip_apxSaiBase[2U]->TCSR;
        DevAssert(0U == (u32Sai2Tcsr & SAI_TCSR_TE_MASK));
    }
    /* sync with sai2 and sai2 other part must be enabled later */
    if (SAI_IP_SYNC_WITH_SAI2_OTHER == pConfig->eSyncMode)
    {
        u32Sai2Rcsr = Sai_Ip_apxSaiBase[2U]->RCSR;
        DevAssert(0U == (u32Sai2Rcsr & SAI_RCSR_RE_MASK));
    }
#endif /* FEATURE_SAI_IP_SYNC_WITH_OTHER_INST */
}

/*FUNCTION**********************************************************************
*
* Function Name : Sai_Ip_TxInitCheck
* Description   : Check dev assert
*END*************************************************************************/
static void Sai_Ip_TxInitCheck(const uint8 u8Instance,
                            const Sai_Ip_ConfigType * pConfig)
{
    const SAI_Type * const pBase = Sai_Ip_apxSaiBase[u8Instance];

    DevAssert((NULL_PTR != pConfig) && (SAI_INSTANCE_COUNT > u8Instance));
    DevAssert(NULL_PTR != pConfig->pState);
    DevAssert((pConfig->u8FrameSize <= (1U << (Sai_Ip_GetParamFrameSize(pBase)))) && (0U < pConfig->u8FrameSize));
    Sai_Ip_TxInitCheckSync(u8Instance, pConfig);
    DevAssert((0U < pConfig->u8Word0Width) && (0U < pConfig->u8WordNWidth) && (0U < pConfig->u8SyncWidth) && (32U > pConfig->u8FirstBitIndex));
    DevAssert((1U == pConfig->u8ElementSize) || (2U == pConfig->u8ElementSize) || (4U == pConfig->u8ElementSize));
}

/*FUNCTION**********************************************************************
*
* Function Name : Sai_Ip_RxInitCheck
* Description   : Check dev assert
*END*************************************************************************/
static void Sai_Ip_RxInitCheck(const uint8 u8Instance,
                            const Sai_Ip_ConfigType * pConfig)
{
    const SAI_Type * const pBase = Sai_Ip_apxSaiBase[u8Instance];

    DevAssert((NULL_PTR != pConfig) && (SAI_INSTANCE_COUNT > u8Instance));
    DevAssert(NULL_PTR != pConfig->pState);
    DevAssert((pConfig->u8FrameSize <= (1U << (Sai_Ip_GetParamFrameSize(pBase)))) && (0U < pConfig->u8FrameSize));
    Sai_Ip_RxInitCheckSync(u8Instance, pConfig);
    DevAssert((0U < pConfig->u8Word0Width) && (0U < pConfig->u8WordNWidth) && (0U < pConfig->u8SyncWidth) && (32U > pConfig->u8FirstBitIndex));
    DevAssert((1U == pConfig->u8ElementSize) || (2U == pConfig->u8ElementSize) || (4U == pConfig->u8ElementSize));
}

/*FUNCTION**********************************************************************
*
* Function Name : Sai_Ip_RxInitCheckSync
* Description   : Check dev assert for syncing
*END*************************************************************************/
static void Sai_Ip_RxInitCheckSync(const uint8 u8Instance,
                                const Sai_Ip_ConfigType * pConfig)
{
    const SAI_Type * const pBase = Sai_Ip_apxSaiBase[u8Instance];
    /* check if sync with other and other is not enabled */
    DevAssert((SAI_IP_SYNC_WITH_OTHER != pConfig->eSyncMode) ||
              ((SAI_IP_SYNC_WITH_OTHER == pConfig->eSyncMode) && (!Sai_Ip_TxGetBitEnable(pBase, SAI_TCSR_TE_MASK))));
#ifdef FEATURE_SAI_IP_SYNC_WITH_OTHER_INST
    uint32 u32Sai2Tcsr;
    uint32 u32Sai2Rcsr;
    /* sai2 cannot sync with sai2 */
    DevAssert(!((2UL == u8Instance) &&
                 ((SAI_IP_SYNC_WITH_SAI2_SAME == pConfig->eSyncMode) || (SAI_IP_SYNC_WITH_SAI2_OTHER == pConfig->eSyncMode))));
    /* if sync with sai2 then sai2 same part must be enabled later */
    if (SAI_IP_SYNC_WITH_SAI2_OTHER == pConfig->eSyncMode)
    {
        u32Sai2Tcsr = Sai_Ip_apxSaiBase[2U]->TCSR;
        DevAssert((u32Sai2Tcsr & SAI_TCSR_TE_MASK) == 0U);
    }
    /* if sync with sai2 then sai2 other part must be enabled later */
    if (SAI_IP_SYNC_WITH_SAI2_SAME == pConfig->eSyncMode)
    {
        u32Sai2Rcsr = Sai_Ip_apxSaiBase[2U]->RCSR;
        DevAssert((u32Sai2Rcsr & SAI_RCSR_RE_MASK) == 0U);
    }
#endif /* FEATURE_SAI_IP_SYNC_WITH_OTHER_INST */
}
#endif /* SAI_IP_DEV_ERROR_DETECT */

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxFillMuxLineInt
 * Description   : Fill fifo mux line interrupt, separated from original function
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_TxFillMuxLineInt(const uint8 u8Instance,
                                 SAI_Type * pBase,
                                 Sai_Ip_StateStructType * pState,
                                 boolean * pFinish)
{
    uint8 u8Idx = 0U;
    boolean bIsTxFull = FALSE;
    uint32 u32Data = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
    {
        if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
        {
            bIsTxFull = Sai_Ip_IsTxFifoFull(pBase, u8Idx);
            while (!((0UL == pState->aChnState[0U].u32Count) || bIsTxFull))
            {

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                pState->pWriteHandler(&u32Data, u8Instance, u8Pack, pState->u8NextChn);
                u8Pack++;
                pState->u8AccessNum[u8Idx]++;
                if ((u8Pack == pState->u8PackCnt) || (1U == pState->aChnState[0U].u32Count) || (pState->u8AccessNum[u8Idx] == pState->u8FrameSize))
                {
#else
                pState->pWriteHandler(&u32Data, u8Instance, (uint8)0U, pState->u8NextChn);
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                    Sai_Ip_TxWrite(pBase, u8Idx, u32Data);
                    u32Data = 0U;
                    bIsTxFull = Sai_Ip_IsTxFifoFull(pBase, u8Idx);
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                    u8Pack = 0U;
                    pState->u8AccessNum[u8Idx] = (pState->u8AccessNum[u8Idx] % pState->u8FrameSize);
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                pState->aChnState[pState->u8NextChn].pTxData = &(pState->aChnState[pState->u8NextChn].pTxData)[pState->u8ElementSize];
                pState->u8NextChn++; /* alternate between data block */
                if (pState->u8NextChn == pState->u8ChannelCount)
                {
                    pState->u8NextChn = 0U;
                }
                pState->aChnState[0U].u32Count--;
            }
            if (0UL == pState->aChnState[0U].u32Count)
            {
                *pFinish = TRUE;
            }
            break; /* only one channle enabled in this mode */
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxFillMuxMemInt
 * Description   : Fill fifo mux mem interrupt, separated from original function
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_TxFillMuxMemInt(const uint8 u8Instance,
                                SAI_Type * pBase,
                                Sai_Ip_StateStructType * pState,
                                boolean * pFinish)
{
    boolean bFull = FALSE;
    uint8 u8Idx = 0U;
    uint32 u32Data[SAI_IP_MAX_CHANNEL_COUNT] = SAI_IP_MAX_CHANNEL_VALUE;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack[SAI_IP_MAX_CHANNEL_COUNT] = SAI_IP_MAX_CHANNEL_VALUE;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    while (!((0UL == pState->aChnState[0U].u32Count) || (bFull)))
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            /* check the first enabled channel fifo */
            if (Sai_Ip_IsTxFifoFull(pBase, u8Idx))
            {
                bFull = TRUE;
                break;
            }
            if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
            {

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                pState->pWriteHandler(&u32Data[u8Idx], u8Instance, u8Pack[u8Idx], (uint8)0U);
                u8Pack[u8Idx]++;
                pState->u8AccessNum[u8Idx]++;
                if ((u8Pack[u8Idx] == pState->u8PackCnt) || (pState->u8AccessNum[u8Idx] == pState->u8FrameSize))
                {
#else
                pState->pWriteHandler(&u32Data[u8Idx], u8Instance, (uint8)0U, (uint8)0U);
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                    Sai_Ip_TxWrite(pBase, u8Idx, u32Data[u8Idx]);
                    u32Data[u8Idx] = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                    u8Pack[u8Idx] = 0U;
                    pState->u8AccessNum[u8Idx] = (pState->u8AccessNum[u8Idx] % pState->u8FrameSize);
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                pState->aChnState[0U].pTxData = &(pState->aChnState[0U].pTxData)[pState->u8ElementSize];
            }
        }
        if (!bFull)
        {
            pState->aChnState[0U].u32Count--;
        }
    }
    if (0UL == pState->aChnState[0U].u32Count)
    {
        *pFinish = TRUE;
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxFillMuxDisableInt
 * Description   : Fill fifo mux disable, interrupt, separated from original function
 *                 to reduce cyclomatic complexity
 *
 *END**************************************************************************/
static void Sai_Ip_TxFillMuxDisableInt(const uint8 u8Instance,
                                    SAI_Type * pBase,
                                    Sai_Ip_StateStructType * pState,
                                    boolean * pFinish)
{
    uint32 u32Temp = 0UL;
    uint8 u8Idx = 0U;
    boolean isTxFull = FALSE;
    uint32 u32Data = 0U;
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    uint8 u8Pack = 0U;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
    {
        if (Sai_Ip_IsTxChannelEnabled(pBase, u8Idx))
        {
            isTxFull = Sai_Ip_IsTxFifoFull(pBase, u8Idx);
            u32Temp = pState->aChnState[0U].u32Count;
            while (!((u32Temp == 0UL) || isTxFull))
            {

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                pState->pWriteHandler(&u32Data, u8Instance, u8Pack, u8Idx);
                u8Pack++;
                pState->u8AccessNum[u8Idx]++;
                if ((u8Pack == pState->u8PackCnt) || (1U == u32Temp) || (pState->u8AccessNum[u8Idx] == pState->u8FrameSize))
                {
#else
                pState->pWriteHandler(&u32Data, u8Instance, (uint8)0U, u8Idx);
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                    Sai_Ip_TxWrite(pBase, u8Idx, u32Data);
                    u32Data = 0U;
                    isTxFull = Sai_Ip_IsTxFifoFull(pBase, u8Idx);
#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
                    u8Pack = 0U;
                    pState->u8AccessNum[u8Idx] = (pState->u8AccessNum[u8Idx] % pState->u8FrameSize);
                }
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

                pState->aChnState[u8Idx].pTxData = &(pState->aChnState[u8Idx].pTxData)[pState->u8ElementSize];
                u32Temp--;
            }
        }
    }
    pState->aChnState[0U].u32Count = u32Temp;
    if (0UL == pState->aChnState[0U].u32Count)
    {
        *pFinish = TRUE;
    }
}
/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxFillFifoInterrupt
 * Description   : Fill fifo before enable tx to avoid run error flag
 *
 *END**************************************************************************/
static boolean Sai_Ip_TxFillFifoInterrupt(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];
    boolean bFinish  = FALSE;

    if (SAI_IP_MUX_LINE == pState->eMux)
    {
        Sai_Ip_TxFillMuxLineInt(u8Instance, pBase, pState, &bFinish);
    }
    else if (SAI_IP_MUX_MEM == pState->eMux)
    {
        Sai_Ip_TxFillMuxMemInt(u8Instance, pBase, pState, &bFinish);
    }
    else /* mux disabled */
    {
        Sai_Ip_TxFillMuxDisableInt(u8Instance, pBase, pState, &bFinish);
    }
    if (bFinish)
    {
        pState->eStatus = SAI_IP_STATUS_COMPLETED;
        if (NULL_PTR != pState->pCallback)
        {
            pState->pCallback(SAI_IP_TX_COMPLETE);
        }
    }
    return bFinish;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_AbortSending
 * Description   : Abort ongoing sending (dma or interrupt)
 *
 *END**************************************************************************/
static void Sai_Ip_AbortSending(const uint8 u8Instance)
{
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];

    if (NULL_PTR != pState)
    {
        if (SAI_IP_STATUS_BUSY == pState->eStatus)
        {
            pState->eStatus = SAI_IP_STATUS_ABORTED;
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
            if (SAI_IP_DMA == pState->eTransferType)
            {
                Sai_Ip_AbortSendingDma(u8Instance);
            }
            else
#endif /* STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE */
            {
                /* Enter critical section */
                SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_06();

                /* Disable Tx Fifo request */
                Sai_Ip_TxDisableFifoReqInt(pBase);

#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
                /* Disable Tx Fifo warning */
                Sai_Ip_TxDisableFifoWarnInt(pBase);
#endif /* (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK) */

                /* Exit critical section */
                SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_06();
            }

            /* Wait until the remaining data in FIFO is transmitted */
            if (Sai_Ip_TxWaitFifoComplete(pBase, SAI_IP_INTERNAL_TIMEOUT_VALUE) != SAI_IP_STATUS_COMPLETED)
            {
                /* Enter critical section */
                SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_06();

                /* Reset transmitter FIFO */
                Sai_Ip_TxResetFifo(pBase);
            }
            else
            {
                /* Enter critical section */
                SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_06();
            }

            /* Disable transmitter */
            Sai_Ip_TxDisable(pBase);

#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
            if (pState->bAutoDisableClock)
            {
                /* Disable transmitter bit clock */
                Sai_Ip_TxDisableBitClock(pBase);
                pState->bAutoDisableClock = FALSE;
            }
#endif /* (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK) */

            /* Exit critical section */
            SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_06();
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_FlushRxFifo
 * Description   : Flush enabled rx fifo
 *
 *END**************************************************************************/
static void Sai_Ip_FlushRxFifo(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    uint8 u8Idx = 0U;
    uint32 u32TimeoutTicks = OsIf_MicrosToTicks(SAI_IP_INTERNAL_TIMEOUT_VALUE, SAI_IP_TIMEOUT_TYPE);
    uint32 u32CurrentTicks = OsIf_GetCounter(SAI_IP_TIMEOUT_TYPE);
    uint32 u32ElapsedTicks = 0U;

    for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
    {
        if (Sai_Ip_IsRxChannelEnabled(pBase, u8Idx))
        {
            while (!Sai_Ip_IsRxFifoEmpty(pBase, u8Idx) && (u32ElapsedTicks < u32TimeoutTicks))
            {
                (void)Sai_Ip_RxRead(pBase, u8Idx);
                u32ElapsedTicks += OsIf_GetElapsed(&u32CurrentTicks, SAI_IP_TIMEOUT_TYPE);
            }
            if (u32ElapsedTicks >= u32TimeoutTicks)
            {
                /* Enter critical section */
                SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_04();

                /* Reset receiver FIFO */
                Sai_Ip_RxResetFifo(pBase);

                /* Exit critical section */
                SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_04();

                break;
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_GetRxBusyCount
 * Description   : Get count when busy
 *
 *END**************************************************************************/
static void Sai_Ip_GetRxBusyCount(const uint8 u8Instance,
                                 uint32 *pCountRemain)
{
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxRxState[u8Instance];

#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    uint32 u32Temp = 0U;
    uint8 u8Idx = 0U;
    if (SAI_IP_DMA == pState->eTransferType)
    {
        if (NULL_PTR != pCountRemain)
        {
            (void)Dma_Ip_GetLogicChannelParam(pState->aDmaChannel[0U], DMA_IP_CH_GET_CURRENT_ITER_COUNT, &(u32Temp));
            if((1U < pState->u8ChannelCount) && (SAI_IP_MUX_MEM != pState->eMux))
            {
                u8Idx = Sai_Ip_GetFirstEnabledRxChannel(u8Instance);
                if (1UL < pState->aChnState[u8Idx].u32Count)
                {
                    *pCountRemain = u32Temp + 1UL;
                }
                else
                {
                    *pCountRemain = u32Temp;
                }
            }
            else
            {
                if (SAI_IP_MUX_MEM == pState->eMux)
                {
                    *pCountRemain = u32Temp / pState->u8ChannelCount;
                }
                else
                {
                    *pCountRemain = u32Temp;
                }
            }
        }
    }
    else
#endif
    {
        if (NULL_PTR != pCountRemain)
        {
            if (SAI_IP_MUX_LINE == pState->eMux)
            {
                *pCountRemain = pState->aChnState[0U].u32Count / pState->u8ChannelCount;
            }
            else
            {
                *pCountRemain = pState->aChnState[0U].u32Count;
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_AbortReceiving
 * Description   : Abort ongoing receiving (dma or interrupt)
 *
 *END**************************************************************************/
static void Sai_Ip_AbortReceiving(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxRxState[u8Instance];

    if (NULL_PTR != pState)
    {
        if (SAI_IP_STATUS_BUSY == pState->eStatus)
        {
            pState->eStatus = SAI_IP_STATUS_ABORTED;
        #if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
            if (SAI_IP_DMA == pState->eTransferType)
            {
                Sai_Ip_AbortReceivingDma(u8Instance);
            }
            else
        #endif
            {
                /* Enter critical section */
                SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_11();

                /* Disable Rx to stop receive data and if Receiver is master node */
                Sai_Ip_RxDisable(pBase);
#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
                if (pState->bAutoDisableClock)
                {
                    /* Disable Rx Bit clock */
                    Sai_Ip_RxDisableBitClock(pBase);
                    pState->bAutoDisableClock = FALSE;
                }
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

                /* Exit critical section */
                SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_11();
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxIrqCheckFifo
 * Description   : Check Transmit FIFO
 *END**************************************************************************/
static void Sai_Ip_TxIrqCheckFifo(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];

#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
    Sai_Ip_StateStructType * const pState = Sai_Ip_apxTxState[u8Instance];


#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

    /* Check FIFO request */
    if (Sai_Ip_TxGetFifoReqFlag(pBase))
    {
        if (Sai_Ip_TxGetBitEnable(pBase, SAI_TCSR_FRIE_MASK))
        {
            /* Continue the transmission */
            Sai_Ip_TxIRQBusy(u8Instance);
        }
    }

#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
    /* Check FIFO warning */
    if (Sai_Ip_TxGetFifoWarnFlag(pBase))
    {
        if (Sai_Ip_TxGetBitEnable(pBase, SAI_TCSR_FWIE_MASK))
        {
            /* Enter critical section */
            SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_18();

            /* Disable Tx when FIFO is empty */
            Sai_Ip_TxDisable(pBase);
            if (pState->bAutoDisableClock)
            {
                Sai_Ip_TxDisableBitClock(pBase);
                pState->bAutoDisableClock = FALSE;
            }

            /* Exit critical section */
            SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_18();
        }
    }
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxIRQHandler
 * Description   : Manage interrupt transfer using fifo request, execute
 *                 other user interrupt func (fifo error, word start,
 *                 sync error)
 *
 *END**************************************************************************/
static void Sai_Ip_TxIRQHandler(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxTxState[u8Instance];

    if (NULL_PTR != pState)
    {
        Sai_Ip_TxIrqCheckFifo(u8Instance);

        /* Check FIFO error */
        Sai_Ip_TxCheckFifoError(pBase,pState);

        /* Check Word start */
        Sai_Ip_TxCheckWordStart(pBase,pState);

        /* Check Sync error */
        Sai_Ip_TxCheckSyncError(pBase,pState);
    }
    else
    {
        /* Clear all tx flags because module is not init */
        Sai_Ip_TxClearAllFlags(pBase);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxCheckFifoError
 * Description   : Check FIFO Error
 *END**************************************************************************/
static void Sai_Ip_TxCheckFifoError(SAI_Type * pBase,
                                    const Sai_Ip_StateStructType * pState)
{
    if (Sai_Ip_TxGetFifoErrorFlag(pBase))
    {
        if (Sai_Ip_TxGetFifoErrorBitEnable(pBase))
        {           
            Sai_Ip_TxClearFlag(pBase, SAI_TCSR_FEF_SHIFT);
            if ( NULL_PTR != pState->pCallback )
            {
                pState->pCallback(SAI_IP_RUN_ERROR);
            }
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxCheckWordStart
 * Description   : Check Word Start
 *END**************************************************************************/
static void Sai_Ip_TxCheckWordStart(SAI_Type * pBase,
                                    const Sai_Ip_StateStructType * pState)
{
    if (Sai_Ip_TxGetWordStartFlag(pBase))
    {
        if(Sai_Ip_TxGetWordStartBitEnable(pBase))
        {
            Sai_Ip_TxClearFlag(pBase, SAI_TCSR_WSF_SHIFT);
            if( NULL_PTR != pState->pCallback )
            {                
                pState->pCallback(SAI_IP_FRAME_START);
            }     
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxCheckSyncError
 * Description   : Check Sync Error
 *END**************************************************************************/
static void Sai_Ip_TxCheckSyncError(SAI_Type * pBase,
                                    const Sai_Ip_StateStructType * pState)
{
    if (Sai_Ip_TxGetSyncErrorFlag(pBase))
    {
        if (Sai_Ip_TxGetSyncErrorBitEnable(pBase))
        {
            Sai_Ip_TxClearFlag(pBase, SAI_TCSR_SEF_SHIFT);
            if ( NULL_PTR != pState->pCallback )
            {
                pState->pCallback(SAI_IP_SYNC_ERROR);
            }     
        }
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxIrqCheckFifo
 * Description   : Check receive FIFO
 *END**************************************************************************/
static void Sai_Ip_RxIrqCheckFifo(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxRxState[u8Instance];

    /* Check FIFO request */
    if (Sai_Ip_RxGetFifoReqFlag(pBase))
    {
        if ((SAI_IP_INTERRUPT == pState->eTransferType) && (SAI_IP_STATUS_BUSY == pState->eStatus))
        {
            Sai_Ip_RxIRQBusy(u8Instance);
        }
    }

    /* Check FIFO error */
    if (Sai_Ip_RxGetFifoErrorFlag(pBase))
    {
        if (Sai_Ip_RxGetFifoErrorBitEnable(pBase))
        {            
            Sai_Ip_RxClearFlag(pBase, SAI_RCSR_FEF_SHIFT);
            if( NULL_PTR != pState->pCallback )
            {
                pState->pCallback(SAI_IP_RUN_ERROR);
            }
        }
    }
}


/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxIRQHandler
 * Description   : Manage interrupt transfer using fifo request, execute
 *                 other user interrupt func (fifo error, word start,
 *                 sync error)
 *
 *END**************************************************************************/
static void Sai_Ip_RxIRQHandler(const uint8 u8Instance)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxRxState[u8Instance];

    if (NULL_PTR != pState)
    {
        Sai_Ip_RxIrqCheckFifo(u8Instance);

        /* Check Word start */
        if (Sai_Ip_RxGetWordStartFlag(pBase))
        {
            if (Sai_Ip_RxGetWordStartBitEnable(pBase))
            {
                Sai_Ip_RxClearFlag(pBase, SAI_RCSR_WSF_SHIFT);
                if( NULL_PTR != pState->pCallback )
                {
                    pState->pCallback(SAI_IP_FRAME_START);
                }
            }
        }

        /* Check Sync error */
        if (Sai_Ip_RxGetSyncErrorFlag(pBase))
        {
            if (Sai_Ip_RxGetSyncErrorBitEnable(pBase))
            {
                Sai_Ip_RxClearFlag(pBase, SAI_RCSR_SEF_SHIFT);	
                if( NULL_PTR != pState->pCallback )
                {
                    pState->pCallback(SAI_IP_SYNC_ERROR);
                }
            }
        }
    }
    else
    {
        /* Clear all rx flags because module is not init */
        Sai_Ip_RxClearAllFlags(pBase);
    }
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_StatusBusyHandler
 * Description   : Update pCountRemain when status busy
 *END**************************************************************************/
static void Sai_Ip_StatusBusyHandler(const Sai_Ip_StateStructType * const pState,
                                     uint32 * const pCountRemain)
{
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    uint32 u32Temp = 0U;
    if (SAI_IP_DMA == pState->eTransferType)
    {
        if (NULL_PTR != pCountRemain)
        {
            (void)Dma_Ip_GetLogicChannelParam(pState->aDmaChannel[0U], DMA_IP_CH_GET_CURRENT_ITER_COUNT, &(u32Temp));
            if (SAI_IP_MUX_MEM == pState->eMux)
            {
                *pCountRemain = u32Temp / pState->u8ChannelCount;
            }
            else
            {
                *pCountRemain = u32Temp;
            }
        }
    }
    else
#endif
    {
        if (NULL_PTR != pCountRemain)
        {
            if (SAI_IP_MUX_LINE == pState->eMux)
            {
                *pCountRemain = pState->aChnState[0U].u32Count / pState->u8ChannelCount;
            }
            else
            {
                *pCountRemain = pState->aChnState[0U].u32Count;
            }
        }
    }
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_SetMaster
 * Description   : disable tx,rx and save/restore tcr4/rcr4
 * @implements     Sai_Ip_SetMaster_Activity
 *END**************************************************************************/
void Sai_Ip_SetMaster(const uint8 u8Instance,
                      const boolean bTx)
{
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
    DevAssert(NULL_PTR != Sai_Ip_apxTxState[u8Instance]);
    DevAssert(NULL_PTR != Sai_Ip_apxRxState[u8Instance]);
#endif
    Sai_Ip_StateStructType * pTxState = Sai_Ip_apxTxState[u8Instance];
    Sai_Ip_StateStructType * pRxState = Sai_Ip_apxRxState[u8Instance];
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];

    if (pTxState->bMaster && pRxState->bMaster)
    {
        /* Enter critical section */
        SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_00();

        pBase->TCSR &= ~SAI_TCSR_TE_MASK;
        pBase->RCSR &= ~SAI_RCSR_RE_MASK;
        /* in master mode when an instance disable rx and enable tx,
        * rcr4 must be set to zero for tx to work, otherwise sync signal
        * will not be generated. Same for rx.
        */
        if (bTx)
        {
            pBase->TCR4 = pTxState->u32Cr4;
            pRxState->u32Cr4 = pBase->RCR4;
            pBase->RCR4 = 0UL;
            pBase->TCR2 &= ~SAI_TCR2_SYNC_MASK;
            pBase->TCR2 |= SAI_TCR2_SYNC(SAI_IP_ASYNC);
            pBase->RCR2 &= ~SAI_RCR2_SYNC_MASK;
            pBase->RCR2 |= SAI_RCR2_SYNC(SAI_IP_SYNC_WITH_OTHER);
            pBase->TCSR &= ~SAI_TCSR_SR_MASK;  /* clear reset bit */
        }
        else
        {
            pBase->RCR4 = pRxState->u32Cr4;
            pTxState->u32Cr4 = pBase->TCR4;
            pBase->TCR4 = 0UL;
            pBase->TCSR |= SAI_TCSR_FR_MASK; /* reset tx fifo to avoid line is driven by tx even after disabled */
            pBase->TCSR |= SAI_TCSR_SR_MASK;  /* call reset bit to avoid line is driven by tx even after disable */
            pBase->RCSR |= SAI_RCSR_FR_MASK; /* reset rx fifo to clear junk data before receive */
            pBase->TCR2 &= ~SAI_TCR2_SYNC_MASK;
            pBase->TCR2 |= SAI_TCR2_SYNC(SAI_IP_SYNC_WITH_OTHER);
            pBase->RCR2 &= ~SAI_RCR2_SYNC_MASK;
            pBase->RCR2 |= SAI_RCR2_SYNC(SAI_IP_ASYNC);
        }

        /* Exit critical section */
        SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_00();
    }
}

/*FUNCTION**********************************************************************
*
* Function Name : Sai_Ip_TxInit
* Description   : Init tx core
* These params are set by driver:
*      CombineMode = combine line or combine memory, user choice
*                                          < Select fifo combine mode.>
@implements     Sai_Ip_TxInit_Activity
*END*************************************************************************/
void Sai_Ip_TxInit(const uint8 u8Instance,
                   const Sai_Ip_ConfigType * pConfig)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = NULL_PTR;
    uint32 u32Divisor = 0U;
    uint8 u8CombineMode = 0U;
    uint8 u8Channel = 0U;
    uint8 u8FPack = 0U;

#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    Sai_Ip_TxInitCheck(u8Instance, pConfig);
#endif
    Sai_Ip_TxResetVar(u8Instance);
    Sai_Ip_apxTxState[u8Instance] = pConfig->pState;
    pState = pConfig->pState;
    /* calculate divisor parameter */
    if (pConfig->bBitClkInternal)
    {
        Sai_Ip_InternalClock(pConfig->u32MasterClkFreq, pConfig->u32BitClkFreq, &u32Divisor);
    }

    pState->bMaster = pConfig->bBitClkInternal;
    pState->u32PBuffCnt = pConfig->u8BufferAccessSize;
    pState->u8ElementSize = pConfig->u8ElementSize;
    pState->eTransferType = pConfig->eTransferType;
    pState->eMux = pConfig->eMuxMode;
    pState->u8BufferAccessSize = pConfig->u8BufferAccessSize;

    switch (pConfig->u8ElementSize)
    {
        case 1U:
            pState->pWriteHandler =(Sai_Ip_WriteHandlerType)Sai_Ip_Write8Handler;
            break;
        case 2U:
            pState->pWriteHandler =(Sai_Ip_WriteHandlerType)Sai_Ip_Write16Handler;
            break;
        default:
            pState->pWriteHandler =(Sai_Ip_WriteHandlerType)Sai_Ip_Write32Handler;
            break;
    }

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    /* FIFO packing */
    pState->bFPack = pConfig->bFPack;
    if (pConfig->bFPack)
    {
        switch (pConfig->u8ElementSize)
        {
            case 1U:
                u8FPack = SAI_IP_FPACK_8_BIT;
                break;
            case 2U:
                u8FPack = SAI_IP_FPACK_16_BIT;
                break;
            default:
                u8FPack = 0U;
                break;
        }
        pState->u8PackCnt = (uint8)((uint32)SAI_IP_FIFO_SIZE/pConfig->u8ElementSize);
        if (0U != (pConfig->u8FrameSize % pState->u8PackCnt))
        {
            if (pConfig->u8FrameSize <= pState->u8PackCnt)
            {
                pState->u32PBuffCnt *= pConfig->u8FrameSize;
            }
            else
            {
                pState->u32PBuffCnt = ((uint32)pConfig->u8BufferAccessSize * (uint32)pConfig->u8FrameSize) /
                (uint32)(((uint32)pConfig->u8FrameSize / (uint32)pState->u8PackCnt) + (uint32)(((pConfig->u8FrameSize % pState->u8PackCnt) != 0U) ? 1U : 0U));
            }
        }
        else
        {
            pState->u32PBuffCnt *= pState->u8PackCnt;
        }
    }
    else
    {
        u8FPack = 0U;
        pState->u8PackCnt = 1U;
    }
    pState->u8FrameSize = pConfig->u8FrameSize;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    u8Channel = pConfig->u8ChannelEnable;
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    uint8 u8Idx = 0U;
    if (SAI_IP_DMA == pConfig->eTransferType)
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (0U != (u8Channel & (1U << u8Idx)))
            {
                pState->aDmaChannel[pState->u8ChannelCount] = pConfig->aDmaChannel[u8Idx];
                pState->u8ChannelCount++;
            }
        }
        u8CombineMode = (uint8)pConfig->eMuxMode;
    }
    else
#endif
    {
        u8CombineMode = 0U; /* emulate combine mode */
        pState->u8ChannelCount = pConfig->u8ChannelCount;
    }
    pBase->TCSR = SAI_TCSR_SR(1U);  /* call reset bit, reset fifo and logic */
    pBase->TCSR = SAI_TCSR_FEIE(Sai_Ip_ToBit(pConfig->bRunErrorReport)) |
                SAI_TCSR_SEIE(Sai_Ip_ToBit(pConfig->bSyncErrorReport)) |
                SAI_TCSR_DBGE(Sai_Ip_ToBit(pConfig->bDebugEnable)) |
                SAI_TCSR_WSIE(Sai_Ip_ToBit(pConfig->bFrameStartReport));
    pState->pCallback = pConfig->pCallback;
    pBase->TCR1 = SAI_TCR1_TFW(FIFO_SIZE - (uint32)pConfig->u8BufferAccessSize);
    pBase->TCR2 = SAI_TCR2_SYNC(pConfig->eSyncMode) |
#if (STD_ON == SAI_IP_BCS_FEATURE_AVAILABLE)
                SAI_TCR2_BCS(Sai_Ip_ToBit(pConfig->bBitClkSwap)) |
#endif
                SAI_TCR2_BCI(Sai_Ip_ToBit(pConfig->bBitClkInput)) |
                SAI_TCR2_MSEL(pConfig->eMasterClkSrc) |
                SAI_TCR2_BCP(Sai_Ip_ToBit(pConfig->bBitClkNegPolar)) |
                SAI_TCR2_BCD(Sai_Ip_ToBit(pConfig->bBitClkInternal)) |
                SAI_TCR2_DIV((uint8) u32Divisor);
    pBase->TCR3 = SAI_TCR3_TCE(u8Channel) |
                SAI_TCR3_WDFL(pConfig->u8WordFlagIndex);
    pBase->TCR4 = SAI_TCR4_FCONT(Sai_Ip_ToBit(pConfig->bContOnErr)) |
                SAI_TCR4_FCOMB(u8CombineMode) |
                SAI_TCR4_FPACK(u8FPack) |
                SAI_TCR4_FRSZ((uint32)pConfig->u8FrameSize - 1U) |
                SAI_TCR4_SYWD((uint32)pConfig->u8SyncWidth - 1U) |
#ifdef FEATURE_SAI_IP_HAS_CHMOD
                SAI_TCR4_CHMOD(pConfig->eMaskMode) |
#endif /* FEATURE_SAI_IP_HAS_CHMOD */
                SAI_TCR4_MF(Sai_Ip_ToBit(pConfig->bMsbFirst)) |
                SAI_TCR4_FSE(Sai_Ip_ToBit(pConfig->bSyncEarly)) |
                SAI_TCR4_ONDEM(Sai_Ip_ToBit(pConfig->bSyncOnDemand)) |
                SAI_TCR4_FSP(Sai_Ip_ToBit(pConfig->bSyncNegPolar)) |
                SAI_TCR4_FSD(Sai_Ip_ToBit(pConfig->bSyncInternal));
    pBase->TCR5 = SAI_TCR5_WNW((uint32)pConfig->u8WordNWidth - 1U) |
                SAI_TCR5_W0W((uint32)pConfig->u8Word0Width - 1U) |
                SAI_TCR5_FBT(pConfig->bMsbFirst ? ~(31U - (uint32)pConfig->u8FirstBitIndex) : (uint32)pConfig->u8FirstBitIndex);
    pState->u32Cr4 = pBase->TCR4;
    Sai_Ip_TxResetFifo(pBase);
    /* Unset software reset bit */
    pBase->TCSR &= ~SAI_TCSR_SR_MASK;
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    if (SAI_IP_DMA == pConfig->eTransferType)
    {
        Sai_Ip_TxDmaInit(u8Instance, pBase, pState);
    }
#endif
    pState->eStatus = SAI_IP_STATUS_COMPLETED;
}

/*FUNCTION**********************************************************************
*
* Function Name : Sai_Ip_RxInit
* Description   : Init rx core
* These params are set by driver:
*      Others are the same as TxInit
* @implements     Sai_Ip_RxInit_Activity
*END*************************************************************************/
void Sai_Ip_RxInit(const uint8 u8Instance,
                   const Sai_Ip_ConfigType * pConfig)
{
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = NULL_PTR;
    uint32 u32Divisor = 0U;
    uint8 u8CombineMode = 0U;
    uint8 u8Channel = 0U;
    uint8 u8FPack = 0U;

#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    Sai_Ip_RxInitCheck(u8Instance, pConfig);
#endif
    Sai_Ip_RxResetVar(u8Instance);
    Sai_Ip_apxRxState[u8Instance] = pConfig->pState;
    pState = pConfig->pState;
    /* calculate divisor parameter */
    if (pConfig->bBitClkInternal)
    {
        Sai_Ip_InternalClock(pConfig->u32MasterClkFreq, pConfig->u32BitClkFreq, &u32Divisor);
    }

    pState->bMaster = pConfig->bBitClkInternal;
    pState->u32PBuffCnt = pConfig->u8BufferAccessSize;
    pState->u8ElementSize = pConfig->u8ElementSize;
    pState->eTransferType = pConfig->eTransferType;
    pState->eMux = pConfig->eMuxMode;
    pState->u8BufferAccessSize = pConfig->u8BufferAccessSize;

    switch (pConfig->u8ElementSize)
    {
        case 1U:
            pState->pReadHandler =(Sai_Ip_ReadHandlerType)Sai_Ip_Read8Handler;
            break;
        case 2U:
            pState->pReadHandler = (Sai_Ip_ReadHandlerType)Sai_Ip_Read16Handler;
            break;
        default:
            pState->pReadHandler = (Sai_Ip_ReadHandlerType)Sai_Ip_Read32Handler;
            break;
    }

#if (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE)
    /* FIFO packing */
    pState->bFPack = pConfig->bFPack;
    if (pConfig->bFPack)
    {
        switch (pConfig->u8ElementSize)
        {
            case 1U:
                u8FPack = SAI_IP_FPACK_8_BIT;
                break;
            case 2U:
                u8FPack = SAI_IP_FPACK_16_BIT;
                break;
            default:
                u8FPack = 0U;
                break;
        }
        pState->u8PackCnt = (uint8)((uint32)SAI_IP_FIFO_SIZE/pConfig->u8ElementSize);
        if (0U != (pConfig->u8FrameSize % pState->u8PackCnt))
        {
            if (pConfig->u8FrameSize <= pState->u8PackCnt)
            {
                pState->u32PBuffCnt *= pConfig->u8FrameSize;
            }
            else
            {
                pState->u32PBuffCnt = ((uint32)pConfig->u8BufferAccessSize * (uint32)pConfig->u8FrameSize) /
                (uint32)((uint32)(pConfig->u8FrameSize / (uint32)pState->u8PackCnt) + (uint32)(((pConfig->u8FrameSize % pState->u8PackCnt) != 0U) ? 1U : 0U));
            }
        }
        else
        {
            pState->u32PBuffCnt *= pState->u8PackCnt;
        }
    }
    else
    {
        u8FPack = 0U;
        pState->u8PackCnt = 1U;
    }
    pState->u8FrameSize = pConfig->u8FrameSize;
#endif /* (STD_ON == SAI_IP_FPACK_FEATURE_AVAILABLE) */

    u8Channel = pConfig->u8ChannelEnable;
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    uint8 u8Idx = 0U;
    if (SAI_IP_DMA == pConfig->eTransferType)
    {
        for (u8Idx = 0U; u8Idx < Sai_Ip_u8ChannelCount[u8Instance]; u8Idx++)
        {
            if (0U != (u8Channel & (1U << u8Idx)))
            {
                pState->aDmaChannel[pState->u8ChannelCount] = pConfig->aDmaChannel[u8Idx];
                pState->u8ChannelCount++;
            }
        }
        u8CombineMode = (uint8)pConfig->eMuxMode;
    }
    else
#endif
    {
        u8CombineMode = 0U; /* emulate combine mode */
        pState->u8ChannelCount = pConfig->u8ChannelCount;
    }

    pBase->RCSR |= SAI_RCSR_FR_MASK; /* reset rx fifo to clear junk data before receive */
    pBase->RCSR = SAI_RCSR_SR(1UL);  /* call reset bit, reset fifo and logic */
    pBase->RCSR = SAI_RCSR_FEIE(Sai_Ip_ToBit(pConfig->bRunErrorReport)) |
                SAI_RCSR_SEIE(Sai_Ip_ToBit(pConfig->bSyncErrorReport)) |
                SAI_RCSR_DBGE(Sai_Ip_ToBit(pConfig->bDebugEnable)) |
                SAI_RCSR_WSIE(Sai_Ip_ToBit(pConfig->bFrameStartReport));
    pState->pCallback = pConfig->pCallback;
    pBase->RCR1 = SAI_RCR1_RFW(((uint32)(pConfig->u8BufferAccessSize) - 1U));
    pBase->RCR2 = SAI_RCR2_SYNC(pConfig->eSyncMode) |
#if (STD_ON == SAI_IP_BCS_FEATURE_AVAILABLE)
                SAI_RCR2_BCS(Sai_Ip_ToBit(pConfig->bBitClkSwap)) |
#endif
                SAI_RCR2_BCI(Sai_Ip_ToBit(pConfig->bBitClkInput)) |
                SAI_RCR2_MSEL(pConfig->eMasterClkSrc) |
                SAI_RCR2_BCP(Sai_Ip_ToBit(pConfig->bBitClkNegPolar)) |
                SAI_RCR2_BCD(Sai_Ip_ToBit(pConfig->bBitClkInternal)) |
                SAI_RCR2_DIV((uint8) u32Divisor);
    pBase->RCR3 = SAI_RCR3_RCE(u8Channel) |
                SAI_RCR3_WDFL(pConfig->u8WordFlagIndex);
    pBase->RCR4 = SAI_RCR4_FCONT(Sai_Ip_ToBit(pConfig->bContOnErr)) |
                SAI_RCR4_FCOMB(u8CombineMode) |
                SAI_RCR4_FPACK(u8FPack) |
                SAI_RCR4_FRSZ(pConfig->u8FrameSize - 1UL) |
                SAI_RCR4_SYWD(pConfig->u8SyncWidth - 1UL) |
                SAI_RCR4_MF(Sai_Ip_ToBit(pConfig->bMsbFirst)) |
                SAI_RCR4_FSE(Sai_Ip_ToBit(pConfig->bSyncEarly)) |
                SAI_RCR4_ONDEM(Sai_Ip_ToBit(pConfig->bSyncOnDemand)) |
                SAI_RCR4_FSP(Sai_Ip_ToBit(pConfig->bSyncNegPolar)) |
                SAI_RCR4_FSD(Sai_Ip_ToBit(pConfig->bSyncInternal));
    pBase->RCR5 = SAI_RCR5_WNW((uint32)pConfig->u8WordNWidth - 1UL) |
                SAI_RCR5_W0W((uint32)pConfig->u8Word0Width - 1UL) |
                SAI_RCR5_FBT(pConfig->bMsbFirst ? ~(31UL - (uint32)pConfig->u8FirstBitIndex) : (uint32)pConfig->u8FirstBitIndex);
    Sai_Ip_RxResetFifo(pBase);
    pState->u32Cr4 = pBase->RCR4;
    pBase->RCSR &= ~SAI_RCSR_SR_MASK; /* clear software reset bit */
#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    if (SAI_IP_DMA == pConfig->eTransferType)
    {
        Sai_Ip_RxDmaInit(u8Instance, pBase, pState);
    }
#endif
    pState->eStatus = SAI_IP_STATUS_COMPLETED;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxDeInit
 * Description   : DeInit tx core
 * @implements     Sai_Ip_TxDeInit_Activity
 *END**************************************************************************/
void Sai_Ip_TxDeInit(const uint8 u8Instance)
{
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
#endif
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];

    pBase->TCSR = 0U; /* clear all interrupt enable bits */
    pBase->TCSR |= SAI_TCSR_FR_MASK; /* reset tx fifo to avoid line is driven by tx even after disabled */
    pBase->TCSR = SAI_TCSR_SR(1U);  /* call reset bit, reset fifo and logic */
    pBase->TCR1 = 0U;
    pBase->TCR2 = 0U; /* need this for rx/tx init after tx/rx deinit to work */
    pBase->TCR3 = 0U;
    pBase->TCR4 = 0U; /* need this for rx/tx init after tx/rx deinit to work */
    pBase->TCR5 = 0U;
    pBase->TMR = 0U; /* reset mask bits */
    pBase->TCSR = 0U; /* clear software reset bit */
    Sai_Ip_TxResetVar(u8Instance);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxDeInit
 * Description   : DeInit rx core
 * @implements     Sai_Ip_RxDeInit_Activity
 *END**************************************************************************/
void Sai_Ip_RxDeInit(const uint8 u8Instance)
{
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
#endif
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];

    pBase->RCSR = 0U; /* clear all interrupt enable bits */
    pBase->RCSR |= SAI_RCSR_FR_MASK; /* reset rx fifo to avoid line is driven by rx even after disabled */
    pBase->RCSR = SAI_RCSR_SR(1U);  /* call reset bit, reset fifo and logic */
    pBase->RCR1 = 0U;
    pBase->RCR2 = 0U; /* need this for rx/tx init after tx/rx deinit to work */
    pBase->RCR3 = 0U;
    pBase->RCR4 = 0U; /* need this for rx/tx init after tx/rx deinit to work */
    pBase->RCR5 = 0U;
    pBase->RMR = 0U; /* reset mask bits */
    pBase->RCSR = 0U; /* clear software reset bit */
    Sai_Ip_RxResetVar(u8Instance);
}

#if (SAI_IP_ENABLE_DATA_MASKING == STD_ON)
/*FUNCTION**********************************************************************
*
* Function Name : Sai_Ip_SetNextMaskWords
* Description   : Set next frame masked word index
* @implements     Sai_Ip_SetNextMaskWords_Activity
*END**************************************************************************/
void Sai_Ip_SetNextMaskWords(const uint8 u8Instance,
                            const boolean bTx,
                            const uint16 u16Words)
{
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
#endif

    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];

    if (bTx)
    {
        pBase->TMR = u16Words;
    }
    else
    {
        pBase->RMR = u16Words;
    }
}
#endif /* (SAI_IP_ENABLE_DATA_MASKING == STD_ON) */

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_SendBlocking
 * Description   : Send block of data, return when finish sending
 * @implements     Sai_Ip_SendBlocking_Activity
 *END**************************************************************************/
Sai_Ip_StatusType Sai_Ip_SendBlocking(const uint8 u8Instance,
                                      const uint8 * const aData[],
                                      const uint32 u32Count,
                                      const uint32 u32Timeout)
{
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];
    Sai_Ip_StatusType eRes;

#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
    DevAssert(NULL_PTR != pState);
    DevAssert(0UL < u32Count);
    DevAssert(u32Count < SAI_IP_MAX_NO_OF_FRAMES);
    DevAssert(NULL_PTR != aData);
    DevAssert(SAI_IP_STATUS_BUSY != pState->eStatus);
#endif

    pState->bBlocking = TRUE;
    Sai_Ip_Send(u8Instance, aData, u32Count);
    eRes = Sai_Ip_WaitTimeout(pState, u32Timeout);
    pState->bBlocking = FALSE;
    if (SAI_IP_STATUS_TIMEOUT == eRes)
    {
        /* abort current transfer */
        Sai_Ip_AbortSending(u8Instance);
        pState->eStatus = SAI_IP_STATUS_TIMEOUT;
    }
    else
    {
    #if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
        DevAssert(SAI_IP_STATUS_BUSY != pState->eStatus);
    #endif
        /* not time out */
        eRes = pState->eStatus;
    }
    return eRes;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_Send
 * Description   : Send block of data, return immediately
 * @implements     Sai_Ip_Send_Activity
 *END**************************************************************************/
void Sai_Ip_Send(const uint8 u8Instance,
                 const uint8 * const aData[],
                 const uint32 u32Count)
{
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxTxState[u8Instance];
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
    DevAssert(NULL_PTR != pState);
    DevAssert(0UL < u32Count);
    DevAssert(u32Count < SAI_IP_MAX_NO_OF_FRAMES);
    DevAssert(NULL_PTR != aData);
    DevAssert(SAI_IP_STATUS_BUSY != pState->eStatus);
#endif

    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];

    if (!Sai_Ip_TxGetBitEnable(pBase, SAI_TCSR_TE_MASK))
    {
        /* Enter critical section */
        SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_02();

        /* Reset internal receiver logic */
        Sai_Ip_TxActiveReset(pBase);
        Sai_Ip_TxDeactiveReset(pBase);

        /* Exit critical section */
        SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_02();
    }

#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    if (SAI_IP_DMA == pState->eTransferType)
    {
        /* Start sending data using DMA */
        Sai_Ip_SendDma(u8Instance, aData, u32Count);
    }
    else
#endif
    {
        /* Start sending data using Interrupt */
        Sai_Ip_SendInt(u8Instance, aData, u32Count);
    }

    /* Enter critical section */
    SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_02();

    /* Enable tx */
    pBase->TCSR |= SAI_TCSR_TE_MASK;

    /* Exit critical section */
    SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_02();

    (void)pState;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_GetSendingStatus
 * Description   : Get sending status (dma or interrupt)
 * @implements     Sai_Ip_GetSendingStatus_Activity
 *END**************************************************************************/
Sai_Ip_StatusType Sai_Ip_GetSendingStatus(const uint8 u8Instance,
                                          uint32 * pCountRemain)
{
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
    DevAssert(NULL_PTR != Sai_Ip_apxTxState[u8Instance]);
#endif

    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxTxState[u8Instance];
    Sai_Ip_StatusType eCurStatus = pState->eStatus;

    switch (eCurStatus)
    {
        case SAI_IP_STATUS_COMPLETED:
            if (NULL_PTR != pCountRemain)
            {
                *pCountRemain = 0U;
            }
            break;
        case SAI_IP_STATUS_ERROR:
            if (NULL_PTR != pCountRemain)
            {
                *pCountRemain = 0U;
            }
            break;
        case SAI_IP_STATUS_BUSY:
            Sai_Ip_StatusBusyHandler(pState,pCountRemain);
            break;
        case SAI_IP_STATUS_ABORTED:
        case SAI_IP_STATUS_TIMEOUT:
            if (NULL_PTR != pCountRemain)
            {
                *pCountRemain = pState->aChnState[0U].u32Count;
            }
            break;
        default:
            /* undefined value */
            eCurStatus = SAI_IP_STATUS_UNINITIALIZED;
            break;
    }

    return eCurStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_ReceiveBlocking
 * Description   : Receive block of data, return when finish Receiving
 * @implements     Sai_Ip_ReceiveBlocking_Activity
 *END**************************************************************************/
Sai_Ip_StatusType Sai_Ip_ReceiveBlocking(const uint8 u8Instance,
                                         uint8 * const aData[],
                                         const uint32 u32Count,
                                         const uint32 u32Timeout)
{
    Sai_Ip_StateStructType * pState = Sai_Ip_apxRxState[u8Instance];
    Sai_Ip_StatusType eRes;

#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
    DevAssert(NULL_PTR != pState);
    DevAssert(0UL < u32Count);
    DevAssert(NULL_PTR != aData);
    DevAssert(SAI_IP_STATUS_BUSY != pState->eStatus);
#endif

    pState->bBlocking = TRUE;
    Sai_Ip_Receive(u8Instance, aData, u32Count);
    eRes = Sai_Ip_WaitTimeout(pState, u32Timeout);
    pState->bBlocking = FALSE;
    if (SAI_IP_STATUS_TIMEOUT == eRes)
    {
        /* abort current transfer */
        Sai_Ip_AbortReceiving(u8Instance);
        pState->eStatus = SAI_IP_STATUS_TIMEOUT;
    }
    else
    {
        /* not time out */
        eRes = pState->eStatus;
    }
    return eRes;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_Receive
 * Description   : Receive block of data, return immediately
 * @implements     Sai_Ip_Receive_Activity
 *END**************************************************************************/
void Sai_Ip_Receive(const uint8 u8Instance,
                    uint8 * const aData[],
                    const uint32 u32Count)
{
#if ((SAI_IP_DEV_ERROR_DETECT == STD_ON) || (SAI_IP_DMA_FEATURE_AVAILABLE == STD_ON))
    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxRxState[u8Instance];
#endif /* (SAI_IP_DEV_ERROR_DETECT == STD_ON) || (SAI_IP_DMA_FEATURE_AVAILABLE == STD_ON) */
    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];

#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
    DevAssert(NULL_PTR != pState);
    DevAssert(0UL < u32Count);
    DevAssert(NULL_PTR != aData);
    DevAssert(SAI_IP_STATUS_BUSY != pState->eStatus);
#endif

    /* Flush fifo all enabled channel */
    Sai_Ip_FlushRxFifo(u8Instance);

#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
    /* Enter critical section */
    SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_08();

    /* Reset internal receiver logic */
    Sai_Ip_RxActiveReset(pBase);
    Sai_Ip_RxDeactiveReset(pBase);

    /* Exit critical section */
    SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_08();
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

#if (STD_ON == SAI_IP_DMA_FEATURE_AVAILABLE)
    if (SAI_IP_DMA == pState->eTransferType)
    {
        /* Start receiving data using DMA */
        Sai_Ip_ReceiveDma(u8Instance, aData, u32Count);
    }
    else
#endif
    {
        /* Start receiving data using Interrupt */
        Sai_Ip_ReceiveInt(u8Instance, aData, u32Count);
    }

    /* Enter critical section */
    SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_08();

    /* Enable rx */
    pBase->RCSR |= SAI_RCSR_RE_MASK;

    /* Exit critical section */
    SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_08();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_GetReceivingStatus
 * Description   : Get receiving status (dma or interrupt)
 * @implements     Sai_Ip_GetReceivingStatus_Activity
 *END**************************************************************************/
Sai_Ip_StatusType Sai_Ip_GetReceivingStatus(const uint8 u8Instance,
                                            uint32 * pCountRemain)
{
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(u8Instance < SAI_INSTANCE_COUNT);
    DevAssert(Sai_Ip_apxRxState[u8Instance] != NULL_PTR);
#endif

    const Sai_Ip_StateStructType * const pState = Sai_Ip_apxRxState[u8Instance];
    Sai_Ip_StatusType eCurStatus = pState->eStatus;

    switch (eCurStatus)
    {
        case SAI_IP_STATUS_COMPLETED:
            if (NULL_PTR != pCountRemain)
            {
                *pCountRemain = 0U;
            }
            break;
        case SAI_IP_STATUS_ERROR:
            if (NULL_PTR != pCountRemain)
            {
                *pCountRemain = 0U;
            }
            break;
        case SAI_IP_STATUS_BUSY:
            Sai_Ip_GetRxBusyCount(u8Instance, pCountRemain);
            break;
        case SAI_IP_STATUS_ABORTED:
        case SAI_IP_STATUS_TIMEOUT:
            if (NULL_PTR != pCountRemain)
            {
                *pCountRemain = pState->aChnState[0U].u32Count;
            }
            break;
        default:
            /* undefined value */
            eCurStatus = SAI_IP_STATUS_UNINITIALIZED;
            break;
    }

    return eCurStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_AbortTransfer
 * Description   : Abort ongoing sending/receiving (dma or interrupt)
 * @implements     Sai_Ip_AbortTransfer_Activity
 *END**************************************************************************/
void Sai_Ip_AbortTransfer(const uint8 u8Instance)
{
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
#endif

    Sai_Ip_AbortSending(u8Instance);
    Sai_Ip_AbortReceiving(u8Instance);
}

#if (STD_ON == SAI_IP_AUTO_DISABLE_CLOCK)
/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_TxAutoDisableClock
 * Description   : Disable transmitter clock after the transmission completed.
 * This function has effect only for first call to Send function.
 * Without calling this function, the clock will remain active after transmission has ended.
 * @implements     Sai_Ip_TxAutoDisableClock_Activity
 *END**************************************************************************/
void Sai_Ip_TxAutoDisableClock(const uint8 u8Instance)
{
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
#endif

    SAI_Type * pBase = Sai_Ip_apxSaiBase[u8Instance];
    Sai_Ip_StateStructType * pState = Sai_Ip_apxTxState[u8Instance];

    /* Enter critical section */
    SchM_Enter_I2s_I2S_EXCLUSIVE_AREA_17();

    /* Enable Fifo warning */
    Sai_Ip_TxEnableFifoWarnInt(pBase);

    /* Exit critical section */
    SchM_Exit_I2s_I2S_EXCLUSIVE_AREA_17();

    pState->bAutoDisableClock = TRUE;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_RxAutoDisableClock
 * Description   : Disable receiver clock after the transmission completed.
 * This function has effect only for first call to Receive function.
 * Without calling this function, the clock will remain active after transmission has ended.
 * @implements     Sai_Ip_RxAutoDisableClock_Activity
 *END**************************************************************************/
void Sai_Ip_RxAutoDisableClock(const uint8 u8Instance)
{
#if (SAI_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(SAI_INSTANCE_COUNT > u8Instance);
#endif

    Sai_Ip_StateStructType * pState = Sai_Ip_apxRxState[u8Instance];

    pState->bAutoDisableClock = TRUE;
}
#endif /* STD_ON == SAI_IP_AUTO_DISABLE_CLOCK */

/*FUNCTION**********************************************************************
 *
 * Function Name : Sai_Ip_IRQHandler
 * Description   : Manage interrupt transfer using fifo request, execute
 *                 other user interrupt func (fifo error, word start,
 *                 sync error)
 * @implements      Sai_Ip_IRQHandler_Activity
 *END**************************************************************************/
void Sai_Ip_IRQHandler(const uint8 u8Instance)
{
    Sai_Ip_TxIRQHandler(u8Instance);
    Sai_Ip_RxIRQHandler(u8Instance);
}

#define I2S_STOP_SEC_CODE
#include "I2s_MemMap.h"

#endif /* (STD_ON == SAI_IP_ENABLE) */

#ifdef __cplusplus
}
#endif

/** @} */
