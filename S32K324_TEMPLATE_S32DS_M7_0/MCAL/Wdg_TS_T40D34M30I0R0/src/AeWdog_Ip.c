/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Swt
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
*   (c) Copyright 2020 - 2023 NXP Semiconductors
*   All Rights Reserved.
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
*   @addtogroup AeWdog_Ip
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

#include "AeWdog_Ip.h"
#include "Devassert.h"
#include "OsIf.h"
#include "Mcal.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define AEWDOG_IP_VENDOR_ID_C                      43
#define AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define AEWDOG_IP_AR_RELEASE_MINOR_VERSION_C       7
#define AEWDOG_IP_AR_RELEASE_REVISION_VERSION_C    0
#define AEWDOG_IP_SW_MAJOR_VERSION_C               3
#define AEWDOG_IP_SW_MINOR_VERSION_C               0
#define AEWDOG_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and AeWdog_Ip header file are of the same vendor */
#if (AEWDOG_IP_VENDOR_ID_C != AEWDOG_IP_VENDOR_ID)
#error "AeWdog_Ip.c and AeWdog_Ip.h have different vendor ids"
#endif

/* Check if current file and AeWdog_Ip header file are of the same Autosar version */
#if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_C     != AEWDOG_IP_AR_RELEASE_MAJOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_C     != AEWDOG_IP_AR_RELEASE_MINOR_VERSION) || \
     (AEWDOG_IP_AR_RELEASE_REVISION_VERSION_C  != AEWDOG_IP_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of AeWdog_Ip.c and AeWdog_Ip.h are different"
#endif

/* Check if current file and AeWdog_Ip header file are of the same software version */
#if ((AEWDOG_IP_SW_MAJOR_VERSION_C != AEWDOG_IP_SW_MAJOR_VERSION) || \
     (AEWDOG_IP_SW_MINOR_VERSION_C != AEWDOG_IP_SW_MINOR_VERSION) || \
     (AEWDOG_IP_SW_PATCH_VERSION_C != AEWDOG_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of AeWdog_Ip.c and AeWdog_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Devassert header file are of the same Autosar version */
    #if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_C    != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
        (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_C     != DEVASSERT_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of AeWdog_Ip.c and Devassert.h are different"
    #endif
        /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_C    != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_C     != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of AeWdog_Ip.c and Mcal.h are different"
    #endif

    /* Check if current file and Osif header file are of the same Autosar version */
    #if ((AEWDOG_IP_AR_RELEASE_MAJOR_VERSION_C    != OSIF_AR_RELEASE_MAJOR_VERSION) || \
        (AEWDOG_IP_AR_RELEASE_MINOR_VERSION_C     != OSIF_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of AeWdog_Ip.c and Osif.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

#if (AEWDOG_IP_ENABLE == STD_ON)

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#ifdef AEWDOG_IP_CHALLENGER_WATCHDOG_USED
    #define AEWDOG_IP_LFSR_POLYNOMIAL               ((uint16)0x1021)
#else
    #define AEWDOG_IP_DEFAULT_TOKEN_VALUE           ((uint16)0x5AB2)
#endif

#define AEWDOG_IP_DATA_WIDTH_16                 ((uint8)16UL)
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

#define WDG_START_SEC_CONST_UNSPECIFIED

#include "Wdg_MemMap.h"

/*! @brief Table of base addresses for AEWDOG instances. */
static AEC_AE_Type * const AeWdog_Ip_sBase[] = IP_AEC_AE_BASE_PTRS;

#define WDG_STOP_SEC_CONST_UNSPECIFIED

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_START_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_START_SEC_RAMCODE
    #endif
#endif

#include "Wdg_MemMap.h"

#ifdef AEWDOG_IP_CHALLENGER_WATCHDOG_USED
/*!
 * @brief Compute answer expected by alive watchdog in challenger mode.
 *
 * @param[in] N/A 
 * @return 16 bit word which is the new LFSR value
 */
static uint16 AeWdog_Ip_ComputeAnswer(void)
{
    static uint16 AeWdog_LFSR_Val = AEWDOG_IP_TOKEN_INIT_VALUE;
    uint16 Ret= (uint16) AeWdog_LFSR_Val;

    if ((uint16)0 != (AeWdog_LFSR_Val & (((uint16)1)<<15)))
    {
        AeWdog_LFSR_Val = ((AeWdog_LFSR_Val<<1) & ((uint16)0xffff)) ^ AEWDOG_IP_LFSR_POLYNOMIAL;
    }
    else
    {
        AeWdog_LFSR_Val = ((AeWdog_LFSR_Val<<1) & ((uint16)0xffff));
    }
    return ((uint16) Ret);
}
#endif

/*!
 * @brief Refresh AEWDOG
 *
 * This method needs to be called within the window period
 * specified by the Compare Low and Compare High registers
 *
 * @param[in] Base AEWDOG base pointer
 */
static inline void AeWdog_Ip_Refresh(AEC_AE_Type * const Base)
{
    uint32 TempRegAnswer;

    /* Check watchdog mode */
    #ifdef AEWDOG_IP_CHALLENGER_WATCHDOG_USED
    TempRegAnswer = (uint32)AeWdog_Ip_ComputeAnswer();
    #else
    TempRegAnswer = AEWDOG_IP_DEFAULT_TOKEN_VALUE;
    #endif
    (void)Aec_Ip_SpiWrite((uint32)(&(Base->ALIVE_WD_ANSWER)), AEWDOG_IP_DATA_WIDTH_16, TempRegAnswer);
}

/*!
 * @brief Get the AEWDOG enable bit.
 *
 * @param[in] Base AEWDOG base pointer
 * @return The state of the device enable bit:
 *      -   FALSE - AEWDOG disabled
 *      -   TRUE  - AEWDOG enabled
 */
static inline boolean AeWdog_Ip_IsEnabled(const AEC_AE_Type * const Base)
{
    uint32 TempRegVal;
    boolean Ret = TRUE;
    Aec_Ip_StatusType ReturnStatus;
    uint16 CurrentPeriod;

    ReturnStatus = Aec_Ip_SpiRead((uint32)(&(Base->ALIVE_WD_CFG)),AEWDOG_IP_DATA_WIDTH_16,&TempRegVal);
    if(AEC_STATUS_SUCCESS != ReturnStatus)
    {
        Ret = FALSE;
    }
    else
    {
        CurrentPeriod = (uint16)TempRegVal & (AEC_AE_ALIVE_WD_CFG_WDW_PERIOD_MASK);
        /* Check if CurrentPeriod is disabled or has time value */
        if ((uint16)AEWDOG_IP_WD_PERIOD_DISABLED == CurrentPeriod)
        {
            Ret = FALSE;
        }
    }    

    return Ret;
}

/*!
 * @brief Check if access to AEWDOG is locked by lock control register.
 *
 * @param[in] Base AEWDOG base pointer
 * @return The state of the device enable bit:
 *      -   FALSE - access to AEWDOG locked
 *      -   TRUE  - access to AEWDOG unlocked
 */
static inline boolean AeWdog_Ip_IsAccessEnabled(const AEC_AE_Type * const Base)
{
    uint32 TempRegVal;
    boolean Ret;
    Aec_Ip_StatusType ReturnStatus;

    ReturnStatus = Aec_Ip_SpiRead((uint32)(&(Base->LOCK_CONTROL)),AEWDOG_IP_DATA_WIDTH_16,&TempRegVal);

    if(AEC_STATUS_SUCCESS != ReturnStatus)
    {
        Ret = FALSE;
    }
    else
    {
        if ((uint16)0 != (((uint16)TempRegVal) & (AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_MASK)) )
        {
            Ret = FALSE;
        }
        else
        {
            Ret = TRUE;
        }
    }
    return Ret;
}

/*!
 * @brief Lock Write Access to Registers of the Alive Watchdog.
 *
 * @param[in] Base AEWDOG base pointer
 * @return The status of the process:
 *      -   AEWDOG_IP_STATUS_SUCCESS - successfully
 *      -   AEWDOG_IP_STATUS_ERROR  - error
 *      -   AEWDOG_IP_STATUS_TIMEOUT - timeout
 */
static AeWdog_Ip_StatusType AeWdog_Ip_Lock(AEC_AE_Type * const Base)
{
    Aec_Ip_StatusType ReturnStatus;
    uint32 TempCr;
    uint32 TempRegVal;

    ReturnStatus = Aec_Ip_SpiRead((uint32)(&(Base->LOCK_CONTROL)),AEWDOG_IP_DATA_WIDTH_16,&TempRegVal);
    if(AEC_STATUS_SUCCESS == ReturnStatus)
    {
        TempCr = (TempRegVal | AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_MASK);
        ReturnStatus = Aec_Ip_SpiWrite((uint32)(&(Base->LOCK_CONTROL)),AEWDOG_IP_DATA_WIDTH_16,TempCr);
    }
    return (AeWdog_Ip_StatusType)ReturnStatus;
}

/*!
 * @brief Unlock Write Access to Registers of the Alive Watchdog.
 *
 * @param[in] Base AEWDOG base pointer
 * @return The status of the process:
 *      -   AEWDOG_IP_STATUS_SUCCESS - successfully
 *      -   AEWDOG_IP_STATUS_ERROR  - error
 *      -   AEWDOG_IP_STATUS_TIMEOUT - timeout
 */
static AeWdog_Ip_StatusType AeWdog_Ip_Unlock(AEC_AE_Type * const Base)
{
    Aec_Ip_StatusType ReturnStatus;
    uint32 TempCr;
    uint32 TempRegVal;

    ReturnStatus = Aec_Ip_SpiRead((uint32)(&(Base->LOCK_CONTROL)),AEWDOG_IP_DATA_WIDTH_16,&TempRegVal);
    if(AEC_STATUS_SUCCESS == ReturnStatus)
    {
        TempCr = (TempRegVal & (~AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_MASK));
        ReturnStatus = Aec_Ip_SpiWrite((uint32)(&(Base->LOCK_CONTROL)),AEWDOG_IP_DATA_WIDTH_16,TempCr);
    }
    return (AeWdog_Ip_StatusType)ReturnStatus;
}
/*==================================================================================================
*                                 GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*FUNCTION**********************************************************************
 *
 * Function Name : AeWdog_Ip_Init
 * Description   : This function initializes the AEWDOG instance to a specified
 * state
 *
 * @implements     
 *END**************************************************************************/
AeWdog_Ip_StatusType AeWdog_Ip_Init(const uint8 Instance, const AeWdog_Ip_ConfigType * const ConfigPtr)
{
    /* Base pointer */
    AEC_AE_Type * const Base = AeWdog_Ip_sBase[Instance];
    /* Return status variable */
    Aec_Ip_StatusType ReturnStatus = AEC_STATUS_SUCCESS;
    /* Flag to store if the module is enabled */
    boolean IsModuleEnabled;
    /* Temporary storage for configuration register value */
    uint16 TempCr;

#if (AEWDOG_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < AEC_AE_INSTANCE_COUNT);
    DevAssert(ConfigPtr != NULL_PTR);
#endif
    /* Get the enablement status of the module */
    IsModuleEnabled = AeWdog_Ip_IsEnabled(Base);
    /* Check if the AeWdog instance is already enabled */
    if (TRUE == IsModuleEnabled)
    {
        /* If conditions are met change the status code to error */
        ReturnStatus = AEC_STATUS_ERROR;
    }
    else
    {
        if(FALSE == AeWdog_Ip_IsAccessEnabled(Base))
        {
            ReturnStatus = (Aec_Ip_StatusType)AeWdog_Ip_Unlock(Base);
        }

        if (AEC_STATUS_SUCCESS == ReturnStatus)
        {
            /* Sets alive watchdog configuration */
            TempCr = (  AEC_AE_ALIVE_WD_CFG_WDW_FAULTREC(ConfigPtr->eFaultRespType)
                        | AEC_AE_ALIVE_WD_CFG_WDW_MODE(ConfigPtr->eAeWdogMode)
                        | AEC_AE_ALIVE_WD_CFG_WDW_BADRESP(ConfigPtr->eMaxBadResp)
                        | AEC_AE_ALIVE_WD_CFG_WDW_PERIOD(ConfigPtr->eWindowPeriod)
                        | AEC_AE_ALIVE_WD_CFG_WDW_DC(ConfigPtr->eWindowDutyCycle));
            #ifdef AEWDOG_IP_CHALLENGER_WATCHDOG_USED
            ReturnStatus = Aec_Ip_SpiWrite((uint32)(&(Base->ALIVE_WD_TOKEN)), \
                                            AEWDOG_IP_DATA_WIDTH_16, \
                                            (uint32)AEWDOG_IP_TOKEN_INIT_VALUE);
            #endif
            ReturnStatus = Aec_Ip_SpiWrite((uint32)(&(Base->ALIVE_WD_CFG)), AEWDOG_IP_DATA_WIDTH_16, (uint32)TempCr);
            ReturnStatus = (Aec_Ip_StatusType)AeWdog_Ip_Lock(Base);
        }
        
    }
    return (AeWdog_Ip_StatusType)ReturnStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : AeWdog_Ip_Service
 * Description   : This function services the AEWDOG instance counter
 *
 * @implements     
 *END**************************************************************************/
void AeWdog_Ip_Service(const uint8 Instance)
{
#if (AEWDOG_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(Instance < AEC_AE_INSTANCE_COUNT);
#endif

    /* Base pointer */
    AEC_AE_Type * Base = AeWdog_Ip_sBase[Instance];
    if(FALSE == AeWdog_Ip_IsAccessEnabled(Base))
    {
        (void)AeWdog_Ip_Unlock(Base);
    }
    AeWdog_Ip_Refresh(Base);

    (void)AeWdog_Ip_Lock(Base);
}

#ifdef WDG_ROM
    #if (WDG_ROM == 1U)
        #define WDG_STOP_SEC_CODE
    #endif
#else
    #if (WDG_RAM == 0U)
        #define WDG_STOP_SEC_RAMCODE
    #endif
#endif


#include "Wdg_MemMap.h"

#endif /* (AEWDOG_IP_ENABLE == STD_ON) */

#ifdef __cplusplus
}
#endif

/** @} */
