/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : I2S
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 3.0.0
* Build Version : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @internal
*   @addtogroup i2s_ipw I2s Ipw
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
#include "I2s_Ipw.h"
#include "CDD_I2s.h"
#if (I2S_IPW_USING_SAI == STD_ON)
#include "Sai_Ip.h"
#endif /* (I2S_IPW_USING_SAI == STD_ON) */
#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
#include "FlexIO_I2s_Ip.h"
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2S_IPW_VENDOR_ID_C                    43
#define I2S_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define I2S_IPW_AR_RELEASE_MINOR_VERSION_C     7
#define I2S_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define I2S_IPW_SW_MAJOR_VERSION_C             3
#define I2S_IPW_SW_MINOR_VERSION_C             0
#define I2S_IPW_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and I2s_Ipw header file are of the same vendor */
#if (I2S_IPW_VENDOR_ID_C != I2S_IPW_VENDOR_ID)
#error "I2s_Ipw.c and I2s_Ipw.h have different vendor ids"
#endif

/* Check if current file and I2s_Ipw header file are of the same Autosar version */
#if ((I2S_IPW_AR_RELEASE_MAJOR_VERSION_C     != I2S_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_MINOR_VERSION_C     != I2S_IPW_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_REVISION_VERSION_C  != I2S_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw.c and I2s_Ipw.h are different"
#endif

/* Check if current file and I2s_Ipw header file are of the same software version */
#if ((I2S_IPW_SW_MAJOR_VERSION_C != I2S_IPW_SW_MAJOR_VERSION) || \
     (I2S_IPW_SW_MINOR_VERSION_C != I2S_IPW_SW_MINOR_VERSION) || \
     (I2S_IPW_SW_PATCH_VERSION_C != I2S_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw.c and I2s_Ipw.h are different"
#endif

/* Check if current file and CDD_I2s header file are of the same vendor */
#if (I2S_IPW_VENDOR_ID_C != I2S_VENDOR_ID)
#error "I2s_Ipw.c and CDD_I2s.h have different vendor ids"
#endif

/* Check if current file and CDD_I2s header file are of the same Autosar version */
#if ((I2S_IPW_AR_RELEASE_MAJOR_VERSION_C     != I2S_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_MINOR_VERSION_C     != I2S_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_REVISION_VERSION_C  != I2S_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw.c and CDD_I2s.h are different"
#endif

/* Check if current file and CDD_I2s header file are of the same software version */
#if ((I2S_IPW_SW_MAJOR_VERSION_C != I2S_SW_MAJOR_VERSION) || \
     (I2S_IPW_SW_MINOR_VERSION_C != I2S_SW_MINOR_VERSION) || \
     (I2S_IPW_SW_PATCH_VERSION_C != I2S_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw.c and CDD_I2s.h are different"
#endif

#if (I2S_IPW_USING_SAI == STD_ON)
/* Check if current file and I2s_Ipw_Types header file are of the same vendor */
#if (I2S_IPW_VENDOR_ID_C != SAI_IP_VENDOR_ID)
#error "I2s_Ipw_Types.h and Sai_Ip.h have different vendor ids"
#endif

/* Check if current file and Sai_Ip header file are of the same Autosar version */
#if ((I2S_IPW_AR_RELEASE_MAJOR_VERSION_C     != SAI_IP_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_MINOR_VERSION_C     != SAI_IP_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_REVISION_VERSION_C  != SAI_IP_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw_Types.h and Sai_Ip.h are different"
#endif

/* Check if current file and Sai_Ip header file are of the same software version */
#if ((I2S_IPW_SW_MAJOR_VERSION_C != SAI_IP_SW_MAJOR_VERSION) || \
     (I2S_IPW_SW_MINOR_VERSION_C != SAI_IP_SW_MINOR_VERSION) || \
     (I2S_IPW_SW_PATCH_VERSION_C != SAI_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw_Types.h and Sai_Ip.h are different"
#endif
#endif /* (I2S_IPW_USING_SAI == STD_ON) */

#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
/* Check if current file and I2s_Ipw_Types header file are of the same vendor */
#if (I2S_IPW_VENDOR_ID_C != FLEXIO_I2S_IP_VENDOR_ID)
#error "I2s_Ipw_Types.h and Flexio_I2s_Ip.h have different vendor ids"
#endif

/* Check if current file and Flexio_I2s_Ip header file are of the same Autosar version */
#if ((I2S_IPW_AR_RELEASE_MAJOR_VERSION_C     != FLEXIO_I2S_IP_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_MINOR_VERSION_C     != FLEXIO_I2S_IP_AR_RELEASE_MINOR_VERSION) || \
     (I2S_IPW_AR_RELEASE_REVISION_VERSION_C  != FLEXIO_I2S_IP_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of I2s_Ipw_Types.h and Flexio_I2s_Ip.h are different"
#endif

/* Check if current file and Flexio_I2s_Ip header file are of the same software version */
#if ((I2S_IPW_SW_MAJOR_VERSION_C != FLEXIO_I2S_IP_SW_MAJOR_VERSION) || \
     (I2S_IPW_SW_MINOR_VERSION_C != FLEXIO_I2S_IP_SW_MINOR_VERSION) || \
     (I2S_IPW_SW_PATCH_VERSION_C != FLEXIO_I2S_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of I2s_Ipw_Types.h and Flexio_I2s_Ip.h are different"
#endif
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */

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

#define I2S_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2s_MemMap.h"

static I2s_LogicalConfigState I2s_Ipw_xLogicalState[I2S_LOGICAL_CHANNEL_COUNT];

#define I2S_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "I2s_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define I2S_START_SEC_CODE
#include "I2s_MemMap.h"

#if (I2S_IPW_USING_SAI == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_ConvertSaiIpToDetStatus
 * Description   : Convert status from IPL to STD
 *END**************************************************************************/
static Std_ReturnType I2s_Ipw_ConvertSaiIpToDetStatus(Sai_Ip_StatusType eIpStatus)
{
    Std_ReturnType status;

    /* Check IP status */
    switch (eIpStatus)
    {
        /* Return E_OK in case SAI_IP_STATUS_COMPLETED or SAI_IP_STATUS_ABORTED */
        case SAI_IP_STATUS_COMPLETED:
        case SAI_IP_STATUS_ABORTED:
            status = (Std_ReturnType)E_OK;
            break;
        /* Return E_NOT_OK in case SAI_IP_STATUS_ERROR */
        case SAI_IP_STATUS_ERROR:
            status = (Std_ReturnType)E_NOT_OK;
            break;
        /* Return I2S_E_TIMEOUT in case SAI_IP_STATUS_TIMEOUT */
        case SAI_IP_STATUS_TIMEOUT:
            status = (Std_ReturnType)I2S_E_TIMEOUT;
            break;
        /* Return I2S_E_BUSY in case SAI_IP_STATUS_BUSY */
        case SAI_IP_STATUS_BUSY:
            status = (Std_ReturnType)I2S_E_BUSY;
            break;
        /* Return I2S_E_INIT_FAILED in remaining cases */
        default:
            status = (Std_ReturnType)I2S_E_INIT_FAILED;
            break;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_ConvertSaiIpToHldStatus
 * Description   : Convert status from Sai IPL to HLD
 *END**************************************************************************/
static I2s_StatusType I2s_Ipw_ConvertSaiIpToHldStatus(Sai_Ip_StatusType eIpStatus)
{
    I2s_StatusType status;

    /* Check IP status */
    switch (eIpStatus)
    {
        /* Return I2S_STATUS_COMPLETED in case SAI_IP_STATUS_COMPLETED */
        case SAI_IP_STATUS_COMPLETED:
            status = I2S_STATUS_COMPLETED;
            break;
        /* Return I2S_STATUS_ABORTED in case SAI_IP_STATUS_ABORTED */
        case SAI_IP_STATUS_ABORTED:
            status = I2S_STATUS_ABORTED;
            break;
        /* Return I2S_STATUS_ERROR in case SAI_IP_STATUS_ERROR */
        case SAI_IP_STATUS_ERROR:
            status = I2S_STATUS_ERROR;
            break;
        /* Return I2S_STATUS_TIMEOUT in case SAI_IP_STATUS_TIMEOUT */
        case SAI_IP_STATUS_TIMEOUT:
            status = I2S_STATUS_TIMEOUT;
            break;
        /* Return I2S_STATUS_BUSY in case SAI_IP_STATUS_BUSY */
        case SAI_IP_STATUS_BUSY:
            status = I2S_STATUS_BUSY;
            break;
        /* Return I2S_STATUS_UNINITIALIZED in remaining cases */
        default:
            status = I2S_STATUS_UNINITIALIZED;
            break;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_GetTxStatus
 * Description   : Get sending status
 *END**************************************************************************/
static Sai_Ip_StatusType I2s_Ipw_GetTxStatus(uint8 u8Instance, uint32 * pByteRemainCount, boolean * bMaster)
{
    Sai_Ip_StatusType ipStatus = SAI_IP_STATUS_UNINITIALIZED;

    /* Check if I2s channel is initialized already else return SAI_IP_STATUS_UNINITIALIZED */
    if (NULL_PTR != Sai_Ip_apxTxState[u8Instance])
    {
        /* Get sending status */
        ipStatus = Sai_Ip_GetSendingStatus(u8Instance, pByteRemainCount);

        if (NULL_PTR != bMaster)
        {
            *bMaster = Sai_Ip_apxTxState[u8Instance]->bMaster;
        }
    }

    return ipStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_GetRxStatus
 * Description   : Get receiving status
 *END**************************************************************************/
static Sai_Ip_StatusType I2s_Ipw_GetRxStatus(uint8 u8Instance, uint32 * pByteRemainCount, boolean * bMaster)
{
    Sai_Ip_StatusType ipStatus = SAI_IP_STATUS_UNINITIALIZED;

    /* Check if I2s channel is initialized already else return SAI_IP_STATUS_UNINITIALIZED */
    if (NULL_PTR != Sai_Ip_apxRxState[u8Instance])
    {
        /* Get receiving status */
        ipStatus = Sai_Ip_GetReceivingStatus(u8Instance, pByteRemainCount);

        if (NULL_PTR != bMaster)
        {
            *bMaster = Sai_Ip_apxRxState[u8Instance]->bMaster;
        }
    }

    return ipStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_SaiSendData
 * Description   : Request to send data in synchronous or asynchronous mode
 *END**************************************************************************/
static Std_ReturnType I2s_Ipw_SaiSendData(const uint8 HwInstance,
                                          const I2s_RequestType * const pRequest,
                                          boolean bSync)
{
    Sai_Ip_StatusType ipStatus;
    boolean bTxMaster = FALSE;
    boolean bRxMaster = FALSE;

#if (I2S_IPW_ENABLE_DATA_MASKING == STD_ON)
    Sai_Ip_SetNextMaskWords(HwInstance, TRUE, pRequest->wordMask);
#endif

    /* Check the transmitter of the given I2s logical channel is initialized already and not busy */
    ipStatus = I2s_Ipw_GetTxStatus(HwInstance, NULL_PTR, &bTxMaster);
    if ((SAI_IP_STATUS_UNINITIALIZED != ipStatus) && (SAI_IP_STATUS_BUSY != ipStatus))
    {
        /* Check the receiver of the given I2s logical channel is not busy */
        ipStatus = I2s_Ipw_GetRxStatus(HwInstance, NULL_PTR, &bRxMaster);
        if ((SAI_IP_STATUS_BUSY != ipStatus) || !(bTxMaster && bRxMaster))
        {
            /* Set master mode for transmitter if the receiver has the same master and async mode */
            if (SAI_IP_STATUS_UNINITIALIZED != ipStatus)
            {
                Sai_Ip_SetMaster(HwInstance, TRUE);
            }

#if (STD_ON == I2S_IPW_AUTO_DISABLE_CLOCK)
            if (pRequest->autoDisableClock)
            {
                Sai_Ip_TxAutoDisableClock(HwInstance);
            }
#endif /* STD_ON == I2S_IPW_AUTO_DISABLE_CLOCK */

            /* Check synchronous request */
            if (bSync)
            {
                /* Send data blocking */
                ipStatus = Sai_Ip_SendBlocking(HwInstance, (const uint8 **)((uint32)pRequest->pDataBuffer), pRequest->bufferSize, I2S_IPW_TIMEOUT);
            }
            else
            {
                /* Send data non-blocking */
                Sai_Ip_Send(HwInstance, (const uint8 **)((uint32)pRequest->pDataBuffer), pRequest->bufferSize);
                ipStatus = SAI_IP_STATUS_COMPLETED;
            }
        }
    }

    /* Convert status from IPL to DET */
    return I2s_Ipw_ConvertSaiIpToDetStatus(ipStatus);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_SaiReceiveData
 * Description   : Request to receive data in synchronous or asynchronous mode
 *END**************************************************************************/
static Std_ReturnType I2s_Ipw_SaiReceiveData(const uint8 HwInstance,
                                             const I2s_RequestType * const pRequest,
                                             boolean bSync)
{
    Sai_Ip_StatusType ipStatus;
    boolean bTxMaster = FALSE;
    boolean bRxMaster = FALSE;

#if (I2S_IPW_ENABLE_DATA_MASKING == STD_ON)
    Sai_Ip_SetNextMaskWords(HwInstance, FALSE, pRequest->wordMask);
#endif
    /* Check the receiver of the given I2s logical channel is initialized already and not busy */
    ipStatus = I2s_Ipw_GetRxStatus(HwInstance, NULL_PTR, &bRxMaster);
    if ((SAI_IP_STATUS_UNINITIALIZED != ipStatus) && (SAI_IP_STATUS_BUSY != ipStatus))
    {
        /* Check the transmitter of the given I2s logical channel is not busy */
        ipStatus = I2s_Ipw_GetTxStatus(HwInstance, NULL_PTR, &bTxMaster);
        if ((SAI_IP_STATUS_BUSY != ipStatus) || !(bTxMaster && bRxMaster))
        {
            /* Set master mode for receiver if the receiver has the same master and async mode */
            if (SAI_IP_STATUS_UNINITIALIZED != ipStatus)
            {
                Sai_Ip_SetMaster(HwInstance, FALSE);
            }

#if (STD_ON == I2S_IPW_AUTO_DISABLE_CLOCK)
           if (pRequest->autoDisableClock)
           {
               Sai_Ip_RxAutoDisableClock(HwInstance);
           }
#endif /* STD_ON == I2S_IPW_AUTO_DISABLE_CLOCK */
            /* Check sync request */
            if (bSync)
            {
                /* Receive data blocking */
                ipStatus = Sai_Ip_ReceiveBlocking(HwInstance, (uint8 **)((uint32)pRequest->pDataBuffer), pRequest->bufferSize, I2S_IPW_TIMEOUT);
            }
            else
            {
                /* Receive data non-blocking */
                Sai_Ip_Receive(HwInstance, (uint8 **)pRequest->pDataBuffer, pRequest->bufferSize);
                ipStatus = SAI_IP_STATUS_COMPLETED;
            }
        }
    }

    /* Convert status from IPL to DET */
    return I2s_Ipw_ConvertSaiIpToDetStatus(ipStatus);
}
#endif /* (I2S_IPW_USING_SAI == STD_ON) */

#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_ConvertFlexioI2sIpToDetStatus
 * Description   : Convert status from IPL to STD
 *END**************************************************************************/
static Std_ReturnType I2s_Ipw_ConvertFlexioI2sIpToDetStatus(Flexio_I2s_Ip_StatusType eIpStatus)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;

    /* Check IP status */
    switch (eIpStatus)
    {
        /* Return E_OK in case FLEXIO_I2S_IP_STATUS_COMPLETED or FLEXIO_I2S_IP_STATUS_ABORTED */
        case FLEXIO_I2S_IP_STATUS_SUCCESS:
        case FLEXIO_I2S_IP_STATUS_ABORTED:
            status = (Std_ReturnType)E_OK;
            break;
        /* Return E_NOT_OK in case FLEXIO_I2S_IP_STATUS_ERROR */
        case FLEXIO_I2S_IP_STATUS_ERROR:
            status = (Std_ReturnType)E_NOT_OK;
            break;
        /* Return I2S_E_TIMEOUT in case FLEXIO_I2S_IP_STATUS_TIMEOUT */
        case FLEXIO_I2S_IP_STATUS_TIMEOUT:
            status = (Std_ReturnType)I2S_E_TIMEOUT;
            break;
        /* Return I2S_E_BUSY in case FLEXIO_I2S_IP_STATUS_BUSY */
        case FLEXIO_I2S_IP_STATUS_BUSY:
            status = (Std_ReturnType)I2S_E_BUSY;
            break;
        /* Return I2S_E_INIT_FAILED in remaining cases */
        default:
            status = (Std_ReturnType)I2S_E_INIT_FAILED;
            break;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_ConvertFlexioI2sIpToHldStatus
 * Description   : Convert status from FlexIO I2S IPL to HLD
 *END**************************************************************************/
static I2s_StatusType I2s_Ipw_ConvertFlexioI2sIpToHldStatus(Flexio_I2s_Ip_StatusType eIpStatus)
{
    I2s_StatusType status;

    /* Check IP status */
    switch (eIpStatus)
    {
        /* Return I2S_STATUS_UNINITIALIZED in case FLEXIO_I2S_IP_STATUS_UNINIT */
        case FLEXIO_I2S_IP_STATUS_UNINIT:
            status = I2S_STATUS_UNINITIALIZED;
            break;
        /* Return I2S_STATUS_COMPLETED in case FLEXIO_I2S_IP_STATUS_SUCCESS */
        case FLEXIO_I2S_IP_STATUS_SUCCESS:
            status = I2S_STATUS_COMPLETED;
            break;
        /* Return I2S_STATUS_ABORTED in case FLEXIO_I2S_IP_STATUS_ABORTED */
        case FLEXIO_I2S_IP_STATUS_ABORTED:
            status = I2S_STATUS_ABORTED;
            break;
        /* Return I2S_STATUS_TIMEOUT in case FLEXIO_I2S_IP_STATUS_TIMEOUT */
        case FLEXIO_I2S_IP_STATUS_TIMEOUT:
            status = I2S_STATUS_TIMEOUT;
            break;
        /* Return I2S_STATUS_BUSY in case FLEXIO_I2S_IP_STATUS_BUSY */
        case FLEXIO_I2S_IP_STATUS_BUSY:
            status = I2S_STATUS_BUSY;
            break;
        /* Return I2S_STATUS_ERROR in case FLEXIO_I2S_IP_STATUS_ERROR and other cases */
        default:
            status = I2S_STATUS_ERROR;
            break;
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_FlexioI2sSendData
 * Description   : Request to send data in synchronous or asynchronous mode
 *END**************************************************************************/
static Std_ReturnType I2s_Ipw_FlexioI2sSendData(const uint8 HwInstance,
                                                const I2s_RequestType * const pRequest,
                                                boolean bSync)
{
    Flexio_I2s_Ip_StatusType ipStatus;

    ipStatus = Flexio_I2s_Ip_MasterGetStatus(0U, HwInstance, NULL_PTR);
    if ((FLEXIO_I2S_IP_STATUS_BUSY != ipStatus) && (FLEXIO_I2S_IP_STATUS_UNINIT != ipStatus))
    {
        /* Check synchronous request */
        if (bSync)
        {
            /* Send data blocking */
            ipStatus = Flexio_I2s_Ip_MasterSendDataBlocking(0U, HwInstance, (const uint8 *)((uint32)pRequest->pDataBuffer[0U]), pRequest->bufferSize, I2S_IPW_TIMEOUT);
        }
        else
        {
            /* Send data non-blocking */
            ipStatus = Flexio_I2s_Ip_MasterSendData(0U, HwInstance, (const uint8 *)((uint32)pRequest->pDataBuffer[0U]), pRequest->bufferSize);
        }
    }

    /* Convert status from IPL to DET */
    return I2s_Ipw_ConvertFlexioI2sIpToDetStatus(ipStatus);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_FlexioI2sReceiveData
 * Description   : Request to receive data in synchronous or asynchronous mode
 *END**************************************************************************/
static Std_ReturnType I2s_Ipw_FlexioI2sReceiveData(const uint8 HwInstance,
                                                   const I2s_RequestType * const pRequest,
                                                   boolean bSync)
{
    Flexio_I2s_Ip_StatusType ipStatus;

    ipStatus = Flexio_I2s_Ip_MasterGetStatus(0U, HwInstance, NULL_PTR);
    if ((FLEXIO_I2S_IP_STATUS_BUSY != ipStatus) && (FLEXIO_I2S_IP_STATUS_UNINIT != ipStatus))
    {
        /* Check synchronous request */
        if (bSync)
        {
            /* Send data blocking */
            ipStatus = Flexio_I2s_Ip_MasterReceiveDataBlocking(0U, HwInstance, (uint8 *)((uint32)pRequest->pDataBuffer[0U]), pRequest->bufferSize, I2S_IPW_TIMEOUT);
        }
        else
        {
            /* Send data non-blocking */
            ipStatus = Flexio_I2s_Ip_MasterReceiveData(0U, HwInstance, (uint8 *)((uint32)pRequest->pDataBuffer[0U]), pRequest->bufferSize);
        }
    }

    /* Convert status from IPL to DET */
    return I2s_Ipw_ConvertFlexioI2sIpToDetStatus(ipStatus);
}
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_Init
 * Description   : Initialize I2s module
 *END**************************************************************************/
void I2s_Ipw_Init(const I2s_ConfigType * const pConfigPtr)
{
    uint8 u8CfgCnt = 0U;
    const I2s_HwConfigType * pHwCfg = NULL_PTR;
    I2s_LogicalConfigState * pState = NULL_PTR;

    /* Initialize all configurations */
    for (u8CfgCnt = 0U; u8CfgCnt < pConfigPtr->cfgCount; u8CfgCnt++)
    {
        /* Allocate hardware configuration and runtime state */
        pHwCfg = pConfigPtr->pHwConfig[u8CfgCnt];
        pState = &I2s_Ipw_xLogicalState[pHwCfg->LogicChn];

        /* Update logical state */
        pState->IpType = pHwCfg->IpType;
        pState->Mode = pHwCfg->IpMode;
        pState->HwInstance = pHwCfg->HwInstance;

#if (I2S_IPW_USING_SAI == STD_ON)
        /* Select IP configuration */
        if (I2S_OVER_SAI == pHwCfg->IpType)
        {
            pState->TransmitDirection = pHwCfg->IpTransmitReceiveMode;
            /* Initialize SAI configuration */
            if (I2S_TRANSMITTER == pHwCfg->IpTransmitReceiveMode)
            {
                Sai_Ip_TxInit(pState->HwInstance, pHwCfg->IpConfig.SaiIpConfig);
            }
            else
            {
                Sai_Ip_RxInit(pState->HwInstance, pHwCfg->IpConfig.SaiIpConfig);
            }
        }
        else
#endif /* (I2S_IPW_USING_SAI == STD_ON) */
#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
        if (I2S_OVER_FLEXIO_I2S == pHwCfg->IpType)
        {
            /* Initialize FLEXIO_I2S configuration */
            if (I2S_MASTER == pHwCfg->IpMode)
            {
                Flexio_I2s_Ip_MasterInit(0U, pState->HwInstance, pHwCfg->IpConfig.FlexioMasterIpConfig);
            }
            else
            {
                Flexio_I2s_Ip_SlaveInit(0U, pState->HwInstance, pHwCfg->IpConfig.FlexioSlaveIpConfig);
            }
        }
        else
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */
        {
            ; /* Avoid MISRA */
        }
    }
}

#if (I2S_IPW_MULTICORE_ENABLED == STD_OFF)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_DeInit
 * Description   : De-initialize I2s module
 *END**************************************************************************/
void I2s_Ipw_DeInit(void)
{
    uint8 u8CfgCnt;
#if (I2S_IPW_USING_SAI == STD_ON)
    /* De-initialize all configurations */
    for (u8CfgCnt = 0U; u8CfgCnt < SAI_INSTANCE_COUNT; u8CfgCnt++)
    {
        /* De-initialize Transmitter if it is initialized already */
        if (I2s_Ipw_GetTxStatus(u8CfgCnt, NULL_PTR, NULL_PTR) != SAI_IP_STATUS_UNINITIALIZED)
        {
            Sai_Ip_TxDeInit(u8CfgCnt);
        }

        /* De-initialize Receiver if it is initialized already */
        if (SAI_IP_STATUS_UNINITIALIZED != I2s_Ipw_GetRxStatus(u8CfgCnt, NULL_PTR, NULL_PTR))
        {
            Sai_Ip_RxDeInit(u8CfgCnt);
        }
    }
#endif /* (I2S_IPW_USING_SAI == STD_ON) */

#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
    for (u8CfgCnt = 0U; u8CfgCnt < FLEXIO_I2S_IP_NUMBER_OF_CHANNEL; u8CfgCnt++)
    {
        /* De-initialize Master/Slave channel if it is initialized already */
        if (NULL_PTR != Flexio_I2s_Ip_pxState[0u][u8CfgCnt])
        {
            Flexio_I2s_Ip_MasterDeinit(0U, u8CfgCnt);
            Flexio_I2s_Ip_pxState[0u][u8CfgCnt]->status = FLEXIO_I2S_IP_STATUS_UNINIT;
        }
    }
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */
}

#else
/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_DeInitLogicalChannel
 * Description   : De-initialize I2s logical channel
 *END**************************************************************************/
void I2s_Ipw_DeInitLogicalChannel(I2s_LogicalChannel LogicChn)
{
    const I2s_LogicalConfigState * const pState = &I2s_Ipw_xLogicalState[LogicChn];

#if (I2S_IPW_USING_SAI == STD_ON)
    if (pState->IpType == I2S_OVER_SAI)
    {
        /* Check transmit direction of the given Sai logical channel */
        if (I2S_TRANSMITTER == pState->TransmitDirection)
        {
            /* De-initialize Transmitter if it is initialized already */
            if (SAI_IP_STATUS_UNINITIALIZED != I2s_Ipw_GetTxStatus(pState->HwInstance, NULL_PTR, NULL_PTR))
            {
                Sai_Ip_TxDeInit(pState->HwInstance);
            }
        }
        else
        {
            /* De-initialize Receiver if it is initialized already */
            if (SAI_IP_STATUS_UNINITIALIZED != I2s_Ipw_GetRxStatus(pState->HwInstance, NULL_PTR, NULL_PTR))
            {
                Sai_Ip_RxDeInit(pState->HwInstance);
            }
        }
    }
    else
#endif /* (I2S_IPW_USING_SAI == STD_ON) */
#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
    if (pState->IpType == I2S_OVER_FLEXIO_I2S)
    {
        /* De-initialize Master/Slave channel if it is initialized already */
        if (NULL_PTR != Flexio_I2s_Ip_pxState[0u][pState->HwInstance])
        {
            Flexio_I2s_Ip_MasterDeinit(0U, pState->HwInstance);
            Flexio_I2s_Ip_pxState[0u][pState->HwInstance]->status = FLEXIO_I2S_IP_STATUS_UNINIT;
        }
    }
    else
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */
    {
        ; /* Avoid MISRA */
    }
}
#endif /* (I2S_IPW_MULTICORE_ENABLED == STD_OFF) */


/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_Transmit
 * Description   : Request to send or receive data in synchronous or asynchronous mode
 *END**************************************************************************/
Std_ReturnType I2s_Ipw_Transmit(I2s_LogicalChannel LogicChn,
                                const I2s_RequestType * const pRequest,
                                boolean bSync)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
    const I2s_LogicalConfigState * const pState = &I2s_Ipw_xLogicalState[LogicChn];
    const uint8 HwInstance = pState->HwInstance;

#if (I2S_IPW_USING_SAI == STD_ON)
    if (pState->IpType == I2S_OVER_SAI)
    {
        /* Check transfer direction of the given request */
        if (I2S_SEND_DATA == pRequest->dataDirection)
        {
            if (I2S_TRANSMITTER == pState->TransmitDirection)
            {
                status = I2s_Ipw_SaiSendData(HwInstance, pRequest, bSync);
            }
            else
            {
                status = I2S_E_INCORRECT_DIRECTION;
            }
        }
        else
        {
            if (I2S_RECEIVER == pState->TransmitDirection)
            {
                status = I2s_Ipw_SaiReceiveData(HwInstance, pRequest, bSync);
            }
            else
            {
                status = I2S_E_INCORRECT_DIRECTION;
            }
        }
    }
    else
#endif /* (I2S_IPW_USING_SAI == STD_ON) */
#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
    if (pState->IpType == I2S_OVER_FLEXIO_I2S)
    {
        /* Check transfer direction of the given request */
        /* Master and Slave share the same API in IPL */
        if(I2S_SEND_DATA == pRequest->dataDirection)
        {
            status = I2s_Ipw_FlexioI2sSendData(HwInstance, pRequest, bSync);
        }
        else
        {
            status = I2s_Ipw_FlexioI2sReceiveData(HwInstance, pRequest, bSync);
        }
    }
    else
    {
        /* Driver uninitialized. */
        status = (Std_ReturnType)I2S_E_INIT_FAILED;
    }
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */
    {
        ; /* Avoid MISRA */
    }
    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_GetStatus
 * Description   : Get status of the given logical channel and data line direction
 *END**************************************************************************/
Std_ReturnType I2s_Ipw_GetStatus(I2s_LogicalChannel LogicChn,
                                 I2s_StatusStructType * const pStatus)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
#if (I2S_IPW_USING_SAI == STD_ON)
    Sai_Ip_StatusType saiStatus;
#endif /* (I2S_IPW_USING_SAI == STD_ON) */
#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
    Flexio_I2s_Ip_StatusType i2sStatus;
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */
    const I2s_LogicalConfigState * const pState = &I2s_Ipw_xLogicalState[LogicChn];

#if (I2S_IPW_USING_SAI == STD_ON)
    if (pState->IpType == I2S_OVER_SAI)
    {
        /* Check data line direction */
        if (pState->TransmitDirection == I2S_TRANSMITTER)
        {
            /* Get sending status */
            saiStatus = I2s_Ipw_GetTxStatus(pState->HwInstance, &pStatus->byteRemainCount, NULL_PTR);
        }
        else
        {
            /* Get receiving status */
            saiStatus = I2s_Ipw_GetRxStatus(pState->HwInstance, &pStatus->byteRemainCount, NULL_PTR);
        }

        /* Convert status from IPL to HLD */
        pStatus->status = I2s_Ipw_ConvertSaiIpToHldStatus(saiStatus);
        /* Convert status to Std_ReturnType */
        status = I2s_Ipw_ConvertSaiIpToDetStatus(saiStatus);
    }
    else
#endif /* (I2S_IPW_USING_SAI == STD_ON) */
#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
    if (pState->IpType == I2S_OVER_FLEXIO_I2S)
    {
        /* Get flexio i2s master/slave status */
        i2sStatus = Flexio_I2s_Ip_MasterGetStatus(0U, pState->HwInstance, &pStatus->byteRemainCount);
        /* Convert status from IPL to HLD */
        pStatus->status = I2s_Ipw_ConvertFlexioI2sIpToHldStatus(i2sStatus);
        /* Convert status to Std_ReturnType */
        status = I2s_Ipw_ConvertFlexioI2sIpToDetStatus(i2sStatus);
    }
    else
    {
        /* Driver uninitialized. */
        status = (Std_ReturnType)I2S_E_INIT_FAILED;
    }
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */
    {
        ; /* Avoid MISRA */
    }

    return status;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Ipw_AbortTrasmit
 * Description   : Abort all ongoing transferring data in the logical channel
 *END**************************************************************************/
void I2s_Ipw_AbortTrasmit(I2s_LogicalChannel LogicChn)
{
    const I2s_LogicalConfigState * const pState = &I2s_Ipw_xLogicalState[LogicChn];

#if (I2S_IPW_USING_SAI == STD_ON)
    if (pState->IpType == I2S_OVER_SAI)
    {
        /* TODO: Does it require to abort both transfer and reciever by Sai_Ip_AbortTransfer */
        /* Abort all ongoing transferring data in the logical channel */
        Sai_Ip_AbortTransfer(pState->HwInstance);
    }
    else
#endif /* (I2S_IPW_USING_SAI == STD_ON) */
#if (I2S_IPW_USING_FLEXIO_I2S == STD_ON)
    if (pState->IpType == I2S_OVER_FLEXIO_I2S)
    {
        (void)Flexio_I2s_Ip_MasterTransferAbort(0U, pState->HwInstance);
    }
    else
#endif /* (I2S_IPW_USING_FLEXIO_I2S == STD_ON) */
    {
        ; /* Avoid MISRA */
    }
}

#define I2S_STOP_SEC_CODE
#include "I2s_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
