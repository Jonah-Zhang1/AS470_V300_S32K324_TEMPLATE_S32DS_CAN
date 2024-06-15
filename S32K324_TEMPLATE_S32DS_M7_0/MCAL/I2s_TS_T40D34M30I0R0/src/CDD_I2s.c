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
*   (u8Idx1) Copyright 2020 - 2023 NXP Semiconductors
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
*   @addtogroup I2S_DRIVER I2s Driver
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_I2s.h"
#include "I2s_Ipw.h"
#include "OsIf.h"
#include "Det.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2S_VENDOR_ID_C                      43
#define I2S_AR_RELEASE_MAJOR_VERSION_C       4
#define I2S_AR_RELEASE_MINOR_VERSION_C       7
#define I2S_AR_RELEASE_REVISION_VERSION_C    0
#define I2S_SW_MAJOR_VERSION_C               3
#define I2S_SW_MINOR_VERSION_C               0
#define I2S_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_I2s header file are of the same vendor */
#if (I2S_VENDOR_ID_C != I2S_VENDOR_ID)
#error "CDD_I2s.c and CDD_I2s.h have different vendor ids"
#endif

/* Check if current file and CDD_I2s header file are of the same Autosar version */
#if ((I2S_AR_RELEASE_MAJOR_VERSION_C     != I2S_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_AR_RELEASE_MINOR_VERSION_C     != I2S_AR_RELEASE_MINOR_VERSION) || \
     (I2S_AR_RELEASE_REVISION_VERSION_C  != I2S_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_I2s.c and CDD_I2s.h are different"
#endif

/* Check if current file and CDD_I2s header file are of the same software version */
#if ((I2S_SW_MAJOR_VERSION_C != I2S_SW_MAJOR_VERSION) || \
     (I2S_SW_MINOR_VERSION_C != I2S_SW_MINOR_VERSION) || \
     (I2S_SW_PATCH_VERSION_C != I2S_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_I2s.c and CDD_I2s.h are different"
#endif

/* Check if current file and I2s_Ipw header file are of the same vendor */
#if (I2S_VENDOR_ID_C != I2S_IPW_VENDOR_ID)
#error "CDD_I2s.c and I2s_Ipw.h have different vendor ids"
#endif

/* Check if current file and CDD_I2s header file are of the same Autosar version */
#if ((I2S_AR_RELEASE_MAJOR_VERSION_C     != I2S_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_AR_RELEASE_MINOR_VERSION_C     != I2S_IPW_AR_RELEASE_MINOR_VERSION) || \
     (I2S_AR_RELEASE_REVISION_VERSION_C  != I2S_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_I2s.c and I2s_Ipw.h are different"
#endif

/* Check if current file and CDD_I2s header file are of the same software version */
#if ((I2S_SW_MAJOR_VERSION_C != I2S_IPW_SW_MAJOR_VERSION) || \
     (I2S_SW_MINOR_VERSION_C != I2S_IPW_SW_MINOR_VERSION) || \
     (I2S_SW_PATCH_VERSION_C != I2S_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_I2s.c and I2s_Ipw.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

/* Check if current file and Osif header file are of the same Autosar version */
#if ((I2S_AR_RELEASE_MAJOR_VERSION_C     != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of CDD_I2s.c and Osif.h are different"
#endif

/* Check if current file and Det header file are of the same Autosar version */
#if ((I2S_AR_RELEASE_MAJOR_VERSION_C     != DET_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_AR_RELEASE_MINOR_VERSION_C     != DET_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of CDD_I2s.c and Det.h are different"
#endif

/* Check if current file and Osif header file are of the same Autosar version */
#if ((I2S_AR_RELEASE_MAJOR_VERSION_C     != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of CDD_I2s.c and OsIf.h are different"
#endif

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */


/*******************************************************************************
 * Defines
 ******************************************************************************/

#if (I2S_MULTICORE_ENABLED == STD_ON)
    #define I2s_GetCoreID()            (uint32)OsIf_GetCoreID()
#else
    #define I2s_GetCoreID()            ((uint32)0UL)
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if(I2S_DEV_ERROR_DETECT == STD_ON)
#if (I2S_MULTICORE_ENABLED == STD_ON)
/* Local Functions */
/**
 * @brief           This function validates the call for a specific channel
 * @details         This service is a non re entrant function on channel used for validating the calls
 *                  for functions that use one channel
 *
 * @param[in]       Channel          Numeric identifier of the GPT channel
 * @param[in]       u8ServiceId      The service id of the caller function
 * @return          The validity of the function call
 * @returnValue     E_OK             The function call is valid
 * @returnValue     E_NOT_OK         The function call is invalid
 *
 * @pre             I2s_Init must be called before.
 * @implement      I2s_ValidateCore_Activity
 *
 * */
static inline Std_ReturnType I2s_ValidateCore(I2s_LogicalChannel LogicChn, uint32 u32CoreId, uint8 ServiceId)
{
    Std_ReturnType returnValue = (Std_ReturnType)E_NOT_OK;

    /* Check if the channel is used on the current core */
    if (u32CoreId == u8I2sChannelIdToCoreMap[LogicChn])
    {
        returnValue = (Std_ReturnType)E_OK;
    }
    else
    {
        (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)ServiceId, (uint8) I2S_E_PARAM_CONFIG);
    }

    return returnValue;
}
#endif /* I2S_MULTICORE_ENABLED == STD_ON */
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */

/* Global Functions */

#define I2S_START_SEC_CODE
#include "I2s_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_Init
 * Description   : This function performs software initialization of I2S driver.
 *
 * @implements     I2s_Init_Activity
 *END*************************************************************************/
void I2s_Init(const I2s_ConfigType * const pConfigPtr)
{
    uint32 u32CoreId;
    u32CoreId = (uint32)I2s_GetCoreID();

    /* Variable (pointer) used for storing the I2S driver configuration data */
#if (I2S_MULTICORE_ENABLED == STD_ON)
    static const I2s_ConfigType *I2s_pConfig[I2S_MAX_PARTITIONS]; /* implicit zero initialization: NULL_PTR */
#else
    static const I2s_ConfigType *I2s_pConfig[1U]; /* implicit zero initialization: NULL_PTR */
#endif

#if (I2S_DEV_ERROR_DETECT == STD_ON)
#if (I2S_PRECOMPILE_SUPPORT == STD_ON)
    if (NULL_PTR != pConfigPtr)
#else
    if (NULL_PTR == pConfigPtr)
#endif
    {
        (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_INIT_ID, (uint8) I2S_E_INIT_FAILED);
    }
    else
    {
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */

#if (I2S_PRECOMPILE_SUPPORT == STD_ON)
#if(I2S_MULTICORE_ENABLED == STD_ON)
        I2s_pConfig[u32CoreId] = I2s_apxConfigVariantPredefined[u32CoreId];
#else
        I2s_pConfig[u32CoreId] = I2s_pxConfigVariantPredefined;
#endif
        (void)pConfigPtr;
#else
        I2s_pConfig[u32CoreId] = pConfigPtr;
#endif

        I2s_Ipw_Init(I2s_pConfig[u32CoreId]);
#if(I2S_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_DeInit
 * Description   : This function performs software de initialization of I2S modules to reset values.
 *
 * @implements     I2s_DeInit_Activity
 *END*************************************************************************/
void I2s_DeInit(void)
{
#if (I2S_MULTICORE_ENABLED == STD_ON)
    uint32 u32CoreId;
    u32CoreId = (uint32)I2s_GetCoreID();
    uint8 u8LogicChnCount = 0;

    for (u8LogicChnCount = 0; u8LogicChnCount < I2S_NUM_CONFIG; u8LogicChnCount++)
    {
        if (u32CoreId == u8I2sChannelIdToCoreMap[u8LogicChnCount])
        {
            I2s_Ipw_DeInitLogicalChannel(u8LogicChnCount);
        }
    }
#else
    I2s_Ipw_DeInit();
#endif /* (I2S_MULTICORE_ENABLED == STD_ON) */
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_SyncTransmit
 * Description   : Sends or receives an I2S message blocking.
 *
 * @implements     I2s_SyncTransmit_Activity
 *END*************************************************************************/
Std_ReturnType I2s_SyncTransmit(I2s_LogicalChannel LogicChn,
                                const I2s_RequestType * const pRequest)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
#if (I2S_DEV_ERROR_DETECT == STD_ON)
#if (I2S_MULTICORE_ENABLED == STD_ON)
    uint32 u32CoreId;
    u32CoreId = (uint32)I2s_GetCoreID();
#endif
#endif

#if (I2S_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pRequest)
    {
        (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_SYNCTRANSMIT_ID, (uint8) I2S_E_PARAM_POINTER);
        status = (Std_ReturnType)E_NOT_OK;
    }
    else if (I2S_LOGICAL_CHANNEL_COUNT <= LogicChn)
    {
        (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_SYNCTRANSMIT_ID, (uint8) I2S_E_PARAM_CHANNEL);
        status = (Std_ReturnType)E_NOT_OK;
    }
    else
#if (I2S_MULTICORE_ENABLED == STD_ON)
    if ((Std_ReturnType) E_NOT_OK == I2s_ValidateCore(LogicChn, u32CoreId, (uint8)I2S_SYNCTRANSMIT_ID))
    {
        status = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */
        status = I2s_Ipw_Transmit(LogicChn, pRequest, TRUE);

        switch (status)
        {
        case (Std_ReturnType)I2S_E_TIMEOUT:
            (void)Det_ReportRuntimeError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_SYNCTRANSMIT_ID, (uint8)status);
            break;
#if(I2S_DEV_ERROR_DETECT == STD_ON)
        case (Std_ReturnType)I2S_E_BUSY:
        case (Std_ReturnType)I2S_E_INIT_FAILED:
        case (Std_ReturnType)E_NOT_OK:
        case (Std_ReturnType)I2S_E_INCORRECT_DIRECTION:
            (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_SYNCTRANSMIT_ID, (uint8)status);
            break;
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */
        default:
            ;/* Do nothing */
            break;
        }
#if(I2S_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */

    return ((status == (Std_ReturnType)E_OK) ? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_AsyncTransmit
 * Description   : Starts an asynchronous transmission on the I2S bus.
 *
 * @implements     I2s_AsyncTransmit_Activity
 *END*************************************************************************/
Std_ReturnType I2s_AsyncTransmit(I2s_LogicalChannel LogicChn,
                                   const I2s_RequestType * const pRequest)
{
    Std_ReturnType status = (Std_ReturnType)E_OK;
#if (I2S_DEV_ERROR_DETECT == STD_ON)
#if (I2S_MULTICORE_ENABLED == STD_ON)
    uint32 u32CoreId;
    u32CoreId = (uint32)I2s_GetCoreID();
#endif
#endif

#if (I2S_DEV_ERROR_DETECT == STD_ON)
   if (NULL_PTR == pRequest)
    {
        (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_ASYNCTRANSMIT_ID, (uint8) I2S_E_PARAM_POINTER);
        status = (Std_ReturnType)E_NOT_OK;
    }
    else if (I2S_LOGICAL_CHANNEL_COUNT <= LogicChn)
    {
        (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_ASYNCTRANSMIT_ID, (uint8) I2S_E_PARAM_CHANNEL);
        status = (Std_ReturnType)E_NOT_OK;
    }
    else
#if (I2S_MULTICORE_ENABLED == STD_ON)
    if ((Std_ReturnType) E_NOT_OK == I2s_ValidateCore(LogicChn, u32CoreId, (uint8)I2S_ASYNCTRANSMIT_ID))
    {
        status = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif
    {
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */
        status = I2s_Ipw_Transmit(LogicChn, pRequest, FALSE);
#if(I2S_DEV_ERROR_DETECT == STD_ON)
        switch (status)
        {
        case (Std_ReturnType)I2S_E_BUSY:
        case (Std_ReturnType)I2S_E_INIT_FAILED:
        case (Std_ReturnType)E_NOT_OK:
        case (Std_ReturnType)I2S_E_INCORRECT_DIRECTION:
            (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_ASYNCTRANSMIT_ID, (uint8)status);
            break;
        default:
            ;/* Do nothing */
            break;
        }
    }
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */

    return ((status == (Std_ReturnType)E_OK) ? (Std_ReturnType)E_OK : (Std_ReturnType)E_NOT_OK);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_GetStatus
 * Description   : Gets the status of an I2s channel.
 *
 * @implements     I2s_GetStatus_Activity
 *END*************************************************************************/
Std_ReturnType I2s_GetStatus(I2s_LogicalChannel LogicChn,
                             I2s_StatusStructType * const pStatus)
{
    Std_ReturnType status;
#if (I2S_DEV_ERROR_DETECT == STD_ON)
#if (I2S_MULTICORE_ENABLED == STD_ON)
    uint32 u32CoreId;
    u32CoreId = (uint32)I2s_GetCoreID();
#endif
#endif

#if (I2S_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pStatus)
    {
        (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_GETSTATUS_ID, (uint8)I2S_E_PARAM_POINTER);
        status = (Std_ReturnType)E_NOT_OK;
    }
    else
    { 
#endif
        status = I2s_Ipw_GetStatus(LogicChn, pStatus);
#if (I2S_DEV_ERROR_DETECT == STD_ON)
        if (I2S_E_INIT_FAILED == status)
        {
            (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_GETSTATUS_ID, (uint8)I2S_E_INIT_FAILED);
        }
        else if (I2S_LOGICAL_CHANNEL_COUNT <= LogicChn)
        {
            (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_GETSTATUS_ID, (uint8)I2S_E_PARAM_CHANNEL);
            status = (Std_ReturnType)E_NOT_OK;
        }
        else
#if (I2S_MULTICORE_ENABLED == STD_ON)
        if ((Std_ReturnType) E_NOT_OK == I2s_ValidateCore(LogicChn, u32CoreId, (uint8)I2S_GETSTATUS_ID))
        {
            status = (Std_ReturnType)E_NOT_OK;
        }
        else
#endif
        {
        switch (status)
            {
            case (Std_ReturnType)I2S_E_BUSY:
            case (Std_ReturnType)E_NOT_OK:
            (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_GETSTATUS_ID, (uint8)status);
                break;
            default:
                ;/* Do nothing */
                break;
            }
        }
    }
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */
    return status;
}


/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_AbortTransmit
 * Description   : Aborts the I2s ongoing transmission.
 *
 * @implements     I2s_AbortTransmit_Activity
 *END*************************************************************************/
void I2s_AbortTransmit(I2s_LogicalChannel LogicChn)
{
#if (I2S_DEV_ERROR_DETECT == STD_ON)
#if (I2S_MULTICORE_ENABLED == STD_ON)
    uint32 u32CoreId;
    u32CoreId = (uint32)I2s_GetCoreID();
#endif
    Std_ReturnType status = (Std_ReturnType)E_OK;
    I2s_StatusStructType i2sStatus;
    status = I2s_GetStatus(LogicChn, &i2sStatus);
    /* Check that the driver has been initialized. */
    if(I2S_E_INIT_FAILED == status)
    {
    /* Raise Det error. */
    (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_ABORTTRANSMIT_ID, (uint8)I2S_E_INIT_FAILED);
    }
    /*If the driver was initialized check the channel and abort transmission. */
    else
    {
        if (I2S_LOGICAL_CHANNEL_COUNT <= LogicChn)
        {
            (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_ABORTTRANSMIT_ID, (uint8) I2S_E_PARAM_CHANNEL);
        }
        else
#if (I2S_MULTICORE_ENABLED == STD_ON)
        if (I2s_ValidateCore(LogicChn, u32CoreId, (uint8)I2S_ABORTTRANSMIT_ID) == (Std_ReturnType) E_NOT_OK)
        {
            /* Do nothing */
        }
        else
#endif
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */
        {
            I2s_Ipw_AbortTrasmit(LogicChn);
        }
#if (I2S_DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

#if (I2S_VERSION_INFO_API == STD_ON)
/*FUNCTION**********************************************************************
 *
 * Function Name : I2s_GetVersionInfo
 * Description   : Aborts the I2s ongoing transmission.
 *
 * @implements     I2s_GetVersionInfo_Activity
 *END*************************************************************************/
void I2s_GetVersionInfo(Std_VersionInfoType * pVersionInfo)
{
#if (I2S_DEV_ERROR_DETECT == STD_ON)
    if (NULL_PTR == pVersionInfo)
    {
        (void)Det_ReportError((uint16)I2S_MODULE_ID, (uint8)0, (uint8)I2S_GETVERSIONINFO_ID, (uint8) I2S_E_PARAM_POINTER);
    }
    else
    {
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */
        (pVersionInfo)->vendorID = (uint16) I2S_VENDOR_ID;
        (pVersionInfo)->moduleID = (uint16) I2S_MODULE_ID;
        (pVersionInfo)->sw_major_version = (uint8) I2S_SW_MAJOR_VERSION;
        (pVersionInfo)->sw_minor_version = (uint8) I2S_SW_MINOR_VERSION;
        (pVersionInfo)->sw_patch_version = (uint8) I2S_SW_PATCH_VERSION;
#if(I2S_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* I2S_DEV_ERROR_DETECT == STD_ON */
}
#endif  /* #if I2S_VERSION_INFO_API == STD_ON */

#define I2S_STOP_SEC_CODE
#include "I2s_MemMap.h"

/*******************************************************************************
 * EOF
 ******************************************************************************/
