/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,LCU,EMIOS,FLEXIO
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
*   @file    Dma_Ip_Multicore.c
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Mcl - Dma Ip driver source file.
*   @details 
*
*   @addtogroup DMA_IP_DRIVER DMA IP Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Dma_Ip_Multicore.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define DMA_IP_MULTICORE_VENDOR_ID_C                       43
#define DMA_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION_C        4
#define DMA_IP_MULTICORE_AR_RELEASE_MINOR_VERSION_C        7
#define DMA_IP_MULTICORE_AR_RELEASE_REVISION_VERSION_C     0
#define DMA_IP_MULTICORE_SW_MAJOR_VERSION_C                3
#define DMA_IP_MULTICORE_SW_MINOR_VERSION_C                0
#define DMA_IP_MULTICORE_SW_PATCH_VERSION_C                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if Dma_Ip_Multicore.c file and Dma_Ip_Multicore.h file are of the same vendor */
#if (DMA_IP_MULTICORE_VENDOR_ID_C != DMA_IP_MULTICORE_VENDOR_ID)
    #error "Dma_Ip_Multicore.c and Dma_Ip_Multicore.h have different vendor ids"
#endif

/* Check if Dma_Ip_Multicore.c file and Dma_Ip_Multicore.h file are of the same Autosar version */
#if ((DMA_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION_C != DMA_IP_MULTICORE_AR_RELEASE_MAJOR_VERSION) || \
     (DMA_IP_MULTICORE_AR_RELEASE_MINOR_VERSION_C != DMA_IP_MULTICORE_AR_RELEASE_MINOR_VERSION) || \
     (DMA_IP_MULTICORE_AR_RELEASE_REVISION_VERSION_C != DMA_IP_MULTICORE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Dma_Ip_Multicore.c and Dma_Ip_Multicore.h are different"
#endif

/* Check if Dma_Ip_Multicore.c file and Dma_Ip_Multicore.h file are of the same Software version */
#if ((DMA_IP_MULTICORE_SW_MAJOR_VERSION_C != DMA_IP_MULTICORE_SW_MAJOR_VERSION) || \
     (DMA_IP_MULTICORE_SW_MINOR_VERSION_C != DMA_IP_MULTICORE_SW_MINOR_VERSION) || \
     (DMA_IP_MULTICORE_SW_PATCH_VERSION_C != DMA_IP_MULTICORE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Dma_Ip_Multicore.c and Dma_Ip_Multicore.h are different"
#endif

#if (STD_ON == DMA_IP_IS_AVAILABLE)

#if (STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE)
#define MCL_START_SEC_CODE
#include "Mcl_MemMap.h"
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

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static inline uint8 Static_Dma_Ip_GetMultiCoreChannelStatus(uint32 ChannelNumber, const Dma_Ip_InitType * const ConfigPtr);
static inline uint8 Static_Dma_Ip_GetMultiCoreInstanceStatus(uint32 InstanceNumber, const Dma_Ip_InitType * const ConfigPtr);

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
static inline uint8 Static_Dma_Ip_GetMultiCoreChannelStatus(uint32 ChannelNumber, const Dma_Ip_InitType * const ConfigPtr)
{
    uint8 Status;
    uint8 StatusChannel = (uint8)(ConfigPtr->pxMultiCoreConfig->pMultiCoreDmaChannelConfig)[ChannelNumber];

    if (StatusChannel == 0U)
    {
        Status = (uint8)0xFFU;
    }
    else
    {
        Status = (uint8)(StatusChannel - 1U);
    }
    return Status;
}

static inline uint8 Static_Dma_Ip_GetMultiCoreInstanceStatus(uint32 InstanceNumber, const Dma_Ip_InitType * const ConfigPtr)
{
    uint8 Status;
    uint8 StatusInstance = (uint8)(ConfigPtr->pxMultiCoreConfig->pMultiCoreDmaInstanceConfig)[InstanceNumber];

    if (StatusInstance == 0U)
    {
        Status = (uint8)0xFFU;
    }
    else
    {
        Status = (uint8)(StatusInstance - 1U);
    }
    return Status;
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief          This function validate the initialization pointer.
*
* @param[in]      ConfigPtr        Pointer to a selected configuration structure.
*
* @return         The validity of the function call
* @retval         DMA_IP_STATUS_SUCCESS     The function call is valid
* @retval         DMA_IP_STATUS_WRONG_CORE  The function call is invalid
*
* @post           none
*/
Dma_Ip_ReturnType Dma_Ip_ValidateMultiCoreInit(void)
{
    Dma_Ip_ReturnType Valid;
    const Dma_Ip_InitType * ConfigPtr = NULL_PTR;
    uint8 CoreId;

    ConfigPtr = Dma_Ip_GetInitPtr();
    CoreId = (uint8)OsIf_GetCoreID();

    if (CoreId == (uint8)((ConfigPtr->pxMultiCoreConfig->pMultiCoreConfig) - (uint8)1))
    {
        Valid = DMA_IP_STATUS_SUCCESS;
    }
    else
    {
        Valid = DMA_IP_STATUS_WRONG_CORE;
    }

    return Valid;
}

/**
* @brief          Validate the call of a Dma API regarding the channelNumber parameter
* @details        Before execution, this function is called to check that the core can access Channel Dma

* @param[in]      ChannelNumber       Id of the channel the caller tries to update
*
* @return         Dma_Ip_ReturnType  Call is valid or not
* @retval         DMA_IP_STATUS_SUCCESS     The function call is valid
* @retval         DMA_IP_STATUS_WRONG_CORE  The function call is invalid
*
* @api
*
* @note
*/
Dma_Ip_ReturnType Dma_Ip_ValidateMultiCoreChannelCall(uint32 ChannelNumber)
{
    Dma_Ip_ReturnType Valid = DMA_IP_STATUS_WRONG_CORE;
    const Dma_Ip_InitType * ConfigPtr = NULL_PTR;
    uint8 StatusCore;
    uint8 CoreId;

    ConfigPtr = Dma_Ip_GetInitPtr();
    StatusCore = Static_Dma_Ip_GetMultiCoreChannelStatus(ChannelNumber, ConfigPtr);
    CoreId = (uint8)OsIf_GetCoreID();
    /* Check that the core can access Channel Dma */
    if (StatusCore == CoreId)
    {
        Valid = DMA_IP_STATUS_SUCCESS;
    }
    else
    {
        Valid = DMA_IP_STATUS_WRONG_CORE;
    }
    return Valid;
}

/**
* @brief          Validate the call of a Dma API regarding the InstanceNumber parameter
* @details        Before execution, this function is called to check that the core can access Instance Dma

* @param[in]      InstanceNumber       Id of the instance the caller tries to update
*
* @return         Dma_Ip_ReturnType  Call is valid or not
* @retval         DMA_IP_STATUS_SUCCESS     The function call is valid
* @retval         DMA_IP_STATUS_WRONG_CORE  The function call is invalid
*
* @api
*
* @note
*/
Dma_Ip_ReturnType Dma_Ip_ValidateMultiCoreInstanceCall(uint32 InstanceNumber)
{
    Dma_Ip_ReturnType Valid = DMA_IP_STATUS_WRONG_CORE;
    const Dma_Ip_InitType * ConfigPtr = NULL_PTR;
    uint8 StatusCore;
    uint8 CoreId;

    ConfigPtr = Dma_Ip_GetInitPtr();
    StatusCore = Static_Dma_Ip_GetMultiCoreInstanceStatus(InstanceNumber, ConfigPtr);
    CoreId = (uint8)OsIf_GetCoreID();
    /* Check that the core can access Channel Dma */
    if (StatusCore == CoreId)
    {
        Valid = DMA_IP_STATUS_SUCCESS;
    }
    else
    {
        Valid = DMA_IP_STATUS_WRONG_CORE;
    }
    return Valid;
}

#define MCL_STOP_SEC_CODE
#include "Mcl_MemMap.h"

#endif /* STD_ON == DMA_IP_MULTICORE_IS_AVAILABLE */

#endif /* #if (STD_ON == DMA_IP_IS_AVAILABLE) */

#ifdef __cplusplus
}
#endif

/** @} */
