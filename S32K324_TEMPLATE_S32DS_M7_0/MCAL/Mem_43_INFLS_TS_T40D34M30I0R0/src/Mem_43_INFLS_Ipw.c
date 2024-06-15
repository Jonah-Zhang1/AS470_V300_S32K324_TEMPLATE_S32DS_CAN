/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : C40
*   Dependencies         : None
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
 * @file       Mem_43_INFLS_Ipw.c
 *
 * @addtogroup MEM_43_INFLS Driver
 * implement   Mem_43_INFLS_Ipw.c_Artifact
 *
 * @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mem_43_INFLS.h"
#include "Mem_43_INFLS_Ipw.h"
#include "C40_Ip.h"
#include "C40_Ip_Ac.h"

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
#if (STD_ON == MEM_43_INFLS_CLEAN_CACHE_AFTER_LOAD_AC)
#include "Cache_Ip.h"
#endif /* MEM_43_INFLS_CLEAN_CACHE_AFTER_LOAD_AC */
#endif /* MEM_43_INFLS_AC_LOAD_ON_JOB_START */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_IPW_VENDOR_ID_C                           43
#define MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C            4
#define MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C            7
#define MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C         0
#define MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C                    3
#define MEM_43_INFLS_IPW_SW_MINOR_VERSION_C                    0
#define MEM_43_INFLS_IPW_SW_PATCH_VERSION_C                    0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_INFLS.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID_C != MEM_43_INFLS_VENDOR_ID)
    #error "Mem_43_INFLS_Ipw.c and Mem_43_INFLS.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS_Ipw.c and Mem_43_INFLS.h are different"
#endif
/* Check if current file and Mem_43_INFLS.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C != MEM_43_INFLS_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION_C != MEM_43_INFLS_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION_C != MEM_43_INFLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Ipw.c and Mem_43_INFLS.h are different"
#endif

/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID_C != MEM_43_INFLS_IPW_VENDOR_ID)
    #error "Mem_43_INFLS_Ipw.c and Mem_43_INFLS_Ipw.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS_Ipw.c and Mem_43_INFLS_Ipw.h are different"
#endif
/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C != MEM_43_INFLS_IPW_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION_C != MEM_43_INFLS_IPW_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION_C != MEM_43_INFLS_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Ipw.c and Mem_43_INFLS_Ipw.h are different"
#endif

/* Check if current file and C40_Ip.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID_C != C40_IP_VENDOR_ID_H)
    #error "Mem_43_INFLS_Ipw.c and C40_Ip.h have different vendor ids"
#endif
/* Check if current file and C40_Ip.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION_C    != C40_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION_C    != C40_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION_C != C40_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS_Ipw.c and C40_Ip.h are different"
#endif
/* Check if current file and C40_Ip.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION_C != C40_IP_SW_MAJOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION_C != C40_IP_SW_MINOR_VERSION_H) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION_C != C40_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Mem_43_INFLS_Ipw.c and C40_Ip.h are different"
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/
#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)

/**
    @brief fill pattern used to clear write and erase access code in RAM
 */
#define MEM_43_INFLS_AC_UNLOAD_PATTERN 0xffffffffU

#endif

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)

#define MEM_43_INFLS_START_SEC_VAR_CLEARED_8
#include "Mem_43_INFLS_MemMap.h"

/* Block of ACErase function address */
static Mem_43_INFLS_BlockType MemBlockAcErase;
/* Block of ACWrite function address */
static Mem_43_INFLS_BlockType MemBlockAcWrite;

#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_8
#include "Mem_43_INFLS_MemMap.h"


#define MEM_43_INFLS_START_SEC_VAR_CLEARED_BOOLEAN
#include "Mem_43_INFLS_MemMap.h"

/* @brief verify that AC loaded or not */
boolean Mem_AcLoaded;                      /* implicit zero initialization: FALSE */

#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Mem_43_INFLS_MemMap.h"

#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/
#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)

#define MEM_43_INFLS_START_SEC_CONST_32
#include "Mem_43_INFLS_MemMap.h"

/* Note: Linker scripts symbol declarations must be accessed by the use of the '&' operators */
/* Start Position and Size of erase access code in flash */
extern const uint32 Fls_ACEraseRomStart;
extern const uint32 Fls_ACEraseSize;

/* Start Position and Size of write access code in flash */
extern const uint32 Fls_ACWriteRomStart;
extern const uint32 Fls_ACWriteSize;

#define MEM_43_INFLS_STOP_SEC_CONST_32
#include "Mem_43_INFLS_MemMap.h"

#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"

static void Mem_43_INFLS_IPW_LoadAc(const Mem_43_INFLS_JobType JobType);
static void Mem_43_INFLS_IPW_UnloadAc(const Mem_43_INFLS_JobType JobType);
static inline void Mem_43_INFLS_IPW_CheckLoadAc(
    Mem_43_INFLS_BlockType           BlockAc,
    Mem_43_INFLS_JobRuntimeInfoType *JobInfo
);
static inline void Mem_43_INFLS_IPW_CheckUnLoadAc(const Mem_43_INFLS_JobType JobType);

#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"

#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"

/*
 * Description:    Get the memory unit index of the memory instance
 *
 * Mem_43_INFLS_IPW_GetMemoryUnitIndex - This function maybe will be implemented next feature.
 */

/*
 * Description:    Update the job status after processing a chunk
 */
static void Mem_43_INFLS_IPW_UpdateJobProcessedLength(
    Mem_43_INFLS_JobRuntimeInfoType   *JobInfo,
    Mem_43_INFLS_LengthType            TransferLength
)
{
    /* Move to the next chunk of job */
    JobInfo->Address += TransferLength;
    JobInfo->Length  -= TransferLength;

    /* Update data buffer pointer if required */
    if (NULL_PTR != JobInfo->DataPtr)
    {
        JobInfo->DataPtr = &(JobInfo->DataPtr[TransferLength]);
    }
}


/*
 * Description:    Compute the number of bytes to read for the current job.
 */
static Mem_43_INFLS_LengthType Mem_43_INFLS_IPW_ComputeReadLength(
    const Mem_43_INFLS_JobRuntimeInfoType    *JobInfo
)
{
    Mem_43_INFLS_LengthType ReadLength = JobInfo->Length;

    return ReadLength;
}


/**
 * @brief    Computes the size for an erase job.
 *           Based on physical hardware capability and device sector size boundary.
 */
static Mem_43_INFLS_LengthType Mem_43_INFLS_IPW_ComputeEraseLength(
    const Mem_43_INFLS_JobRuntimeInfoType    *JobInfo
)
{
    Mem_43_INFLS_LengthType EraseLength = JobInfo->SectorBatch->SectorSize;  /* default is normal size */
    const uint32 BurstSize           = JobInfo->SectorBatch->EraseBurstSize;

    /* Check for burst mode */
    if ( (0U == (JobInfo->Address % BurstSize)) &&
         (0U == (JobInfo->Length  % BurstSize))
       )
    {
        /* Both start address and length are aligned with the burst setting */
        EraseLength = BurstSize;
    }

    return EraseLength;
}


/**
 * @brief    Computes the size of the next chunk of a write job.
 *           Based on physical hardware capability and device page size boundary.
 */
static Mem_43_INFLS_LengthType Mem_43_INFLS_IPW_ComputeWriteLength(
    const Mem_43_INFLS_JobRuntimeInfoType    *JobInfo
)
{
    uint32 WriteLength = JobInfo->Length;  /* the remaining length of the job */

    /* Check if chunk does not exceed IP driver capabilities */
    if (WriteLength > JobInfo->SectorBatch->WritePageSize)
    {
        WriteLength = JobInfo->SectorBatch->WritePageSize;
    }

    return WriteLength;
}


/**
 * @brief    Translate the return code from IPV to HLD.
 */
static Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_TranslateReturnCode(C40_Ip_StatusType IpReturnValue)
{
    Mem_43_INFLS_JobResultType JobResult;

    switch (IpReturnValue)
    {
        case STATUS_C40_IP_BUSY:
            /* The job is still being processed */
            JobResult = MEM_43_INFLS_JOB_PENDING;
            break;

        case STATUS_C40_IP_SUCCESS:
            /* The job has completed */
            JobResult = MEM_43_INFLS_JOB_OK;
            break;
        case STATUS_C40_IP_ECC_UNCORRECTED:
            /* The job has completed */
            JobResult = MEM_43_INFLS_JOB_ECC_UNCORRECTED;
            break;
        case STATUS_C40_IP_ECC_CORRECTED:
            /* The job has completed */
            JobResult = MEM_43_INFLS_JOB_ECC_CORRECTED;
            break;
        default:
            /* Timeout or hardware errors */
            JobResult = MEM_43_INFLS_JOB_FAILED;
            break;
    }

    return JobResult;
}

#if ( STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START )
/**
 * @brief        Load access code to RAM
 *
 * @details      Load erase or write access code to statically
 *               pre-configured location in RAM
 *
 * @param[in]    JobType Type of access code to load. Can be either
 *               MEM_43_INFLS_JOB_ERASE or MEM_43_INFLS_JOB_WRITE
 *
 * @pre          The module must be initialized
 *
 */
static void Mem_43_INFLS_IPW_LoadAc(const Mem_43_INFLS_JobType JobType)
{
    uint32        Count;
    uint32        AcSize;  /* Word size */
    uint32       *RamPtr;
    const uint32 *RomPtr;

    if (MEM_43_INFLS_JOB_ERASE == JobType)
    {
        RomPtr = (const uint32 *)( (uint32)(&Fls_ACEraseRomStart) );
        RamPtr = (uint32*)((uint32)(Mem_43_INFLS_pConfigPtr->MemAcErasePtr));
        AcSize = (uint32)(&Fls_ACEraseSize);
    }
    else
    {
        /* MEM_43_INFLS_JOB_WRITE */
        RomPtr = (const uint32 *)( (uint32)(&Fls_ACWriteRomStart) );
        RamPtr = (uint32*)((uint32)(Mem_43_INFLS_pConfigPtr->MemAcWritePtr));
        AcSize = (uint32)(&Fls_ACWriteSize);
    }

    /* Copy erase or write access code to RAM */
    /* AcSize is dynamically calculated and might not be multiple of 4U */
    for (Count = 0U; Count < AcSize; Count++)
    {
        /* Copy 4 bytes at a time*/
        RamPtr[Count] = RomPtr[Count];
    }
}


/**
 * @brief        Unload access code to RAM
 *
 * @details      Erase write or erase access code from statically
 *               pre-configured location in RAM. Fills the RAM location
 *               with MEM_43_INFLS_AC_UNLOAD_PATTERN
 *
 * @param[in]    JobType Type of access code to unload. Can be either
 *               MEM_43_INFLS_JOB_ERASE or MEM_43_INFLS_JOB_WRITE
 *
 * @pre          The module must be initialized
 *
 */
static void Mem_43_INFLS_IPW_UnloadAc(const Mem_43_INFLS_JobType JobType)
{
    uint32  Count;
    uint32  AcSize;  /* Word size */
    uint32 *RamPtr;

    if (MEM_43_INFLS_JOB_ERASE == JobType)
    {
        RamPtr = (uint32*)((uint32)(Mem_43_INFLS_pConfigPtr->MemAcErasePtr));
        AcSize = (uint32)(&Fls_ACEraseSize);
    }
    else
    {
        /* MEM_43_INFLS_JOB_WRITE */
        RamPtr = (uint32*)((uint32)(Mem_43_INFLS_pConfigPtr->MemAcWritePtr));
        AcSize = (uint32)(&Fls_ACWriteSize);
    }

    /* Unload (erase) write or erase access code from RAM */
    for (Count = 0U; Count < AcSize; Count++)
    {
        /* Clear 4 bytes at a time*/
        RamPtr[Count] = MEM_43_INFLS_AC_UNLOAD_PATTERN;
    }
}

static inline void Mem_43_INFLS_IPW_CheckLoadAc(
    Mem_43_INFLS_BlockType           BlockAc,
    Mem_43_INFLS_JobRuntimeInfoType *JobInfo
)
{
    Mem_43_INFLS_AddressType JobAddrStart;
    Mem_43_INFLS_BlockType   JobBlockSector;

    /* Get the base address of the sector. */
    JobAddrStart = JobInfo->Address;
    /* Add the offset of the sector inside sector group */
    JobAddrStart += JobInfo->Length;
    /* Get block number of the sector to be erased or written */
    JobBlockSector = (Mem_43_INFLS_BlockType)C40_Ip_GetBlockNumberFromAddress((uint32)JobAddrStart);

    /* Only load if erase/write to the same block */
    if (JobBlockSector == BlockAc)
    {
        /* Load position independent access code to RAM */
        Mem_43_INFLS_IPW_LoadAc(JobInfo->JobType);

        /* Mask the status as loaded */
        Mem_AcLoaded = (boolean)TRUE;

#if (STD_ON == MEM_43_INFLS_CLEAN_CACHE_AFTER_LOAD_AC)
        if (MEM_43_INFLS_JOB_ERASE == JobInfo->JobType)
        {
            /* Clean cache after loading to sync with RAM for Erase job */
            (void)Cache_Ip_CleanByAddr(CACHE_IP_CORE, CACHE_IP_DATA, TRUE, (uint32)Mem_43_INFLS_pConfigPtr->MemAcErasePtr, ((uint32)(&Fls_ACEraseSize) * 4U));
        }
        else
        {
            /* Clean cache after loading to sync with RAM for Write job */
            (void)Cache_Ip_CleanByAddr(CACHE_IP_CORE, CACHE_IP_DATA, TRUE, (uint32)Mem_43_INFLS_pConfigPtr->MemAcWritePtr, ((uint32)(&Fls_ACWriteSize) * 4U));
        }
#endif /* MEM_43_INFLS_SUPPORT_CACHE_FEATURE */
    }
}

static inline void Mem_43_INFLS_IPW_CheckUnLoadAc(const Mem_43_INFLS_JobType JobType)
{
    /* If the access code was loaded */
    if (TRUE == Mem_AcLoaded)
    {
        /* Unload from RAM */
        Mem_43_INFLS_IPW_UnloadAc(JobType);

        /* Mask the status as unloaded */
        Mem_AcLoaded = (boolean)FALSE;
    }
}
#endif /* MEM_43_INFLS_AC_LOAD_ON_JOB_START */


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
 * @brief        Mem_43_INFLS_IPW_Init
 * @details      Initialize memory flash devices.
 */
Std_ReturnType Mem_43_INFLS_IPW_Init(void)
{
    const Mem_43_INFLS_InternalUnitType *InternalUnits = Mem_43_INFLS_pConfigPtr->MemDevices->InternalUnits;
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    C40_Ip_StatusType Status;
    uint32 Unit;

    for (Unit = 0U; Unit < MEM_43_INFLS_INTERNAL_UNIT_COUNT; Unit++)
    {
        if (NULL_PTR != InternalUnits[Unit].InternalConfig)
        {
            /* Use configuration "InternalConfig" to initialize C40 */
            Status = C40_Ip_Init(InternalUnits[Unit].InternalConfig);

            if (STATUS_C40_IP_SUCCESS != Status)
            {
                RetVal = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
    /* Get block number of ACWrite/Erase function address */
    MemBlockAcErase = (Mem_43_INFLS_BlockType)C40_Ip_GetBlockNumberFromAddress((uint32)(&Fls_ACWriteRomStart));
    MemBlockAcWrite = (Mem_43_INFLS_BlockType)C40_Ip_GetBlockNumberFromAddress((uint32)(&Fls_ACEraseRomStart));
#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */

    return RetVal;
}


/**
 * @brief          IP wrapper read function.
 * @details        Route the read job to appropriate low level IP function.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Read(
    uint32                          InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType   *JobInfo
)
{
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_INFLS_LengthType TransferLength;
    C40_Ip_StatusType Status;

    if (JobInfo->Length == 0U)
    {
        /* No more data to read */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else
    {
        /* Calculate length of data transfer */
        TransferLength = Mem_43_INFLS_IPW_ComputeReadLength(JobInfo);

        /* Read data from flash memory device */
        Status = C40_Ip_Read(JobInfo->Address, TransferLength, JobInfo->DataPtr);

        if (STATUS_C40_IP_SUCCESS == Status)
        {
            /* Update length */
            Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
            JobResult = MEM_43_INFLS_JOB_PENDING;
        }
        else if (STATUS_C40_IP_ECC_CORRECTED == Status)
        {
            /* Update length */
            Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
            if (JobInfo->Length == 0U)
            {
                JobResult = MEM_43_INFLS_JOB_ECC_CORRECTED;;
            }
            else
            {
                JobResult = MEM_43_INFLS_JOB_PENDING;
            }
        }
        else if (STATUS_C40_IP_ECC_UNCORRECTED == Status)
        {
            /* the job result is ecc uncorrected */
            JobResult = MEM_43_INFLS_JOB_ECC_UNCORRECTED;
        }
        else
        {
            /* Do nothing */
        }
    }

    (void)InstanceIndex;

    return JobResult;
}


#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
/**
 * @brief          IP wrapper comparison check function.
 * @details        Route the comparison check job to appropriate low level IP function.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Compare(
    uint32                             InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType  * JobInfo
)
{
    Mem_43_INFLS_JobResultType JobResult;
    Mem_43_INFLS_LengthType TransferLength;
    C40_Ip_StatusType Status;

    if (JobInfo->Length == 0U)
    {
        /* No more data to check comparison */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else
    {
        /* Calculate length of data transfer */
        TransferLength = Mem_43_INFLS_IPW_ComputeReadLength(JobInfo);

        /* check comparison */
        Status = C40_Ip_Compare(JobInfo->Address, TransferLength, JobInfo->DataPtr);
        if (STATUS_C40_IP_SUCCESS == Status)
        {
            JobResult = MEM_43_INFLS_JOB_PENDING;

            /* Update job state */
            Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        }
        else if (STATUS_C40_IP_ECC_CORRECTED == Status)
        {
            /* Update length */
            Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
            if (JobInfo->Length == 0U)
            {
                JobResult = MEM_43_INFLS_JOB_ECC_CORRECTED;;
            }
            else
            {
                JobResult = MEM_43_INFLS_JOB_PENDING;
            }
        }
        else if (STATUS_C40_IP_ECC_UNCORRECTED == Status)
        {
            /* the job result is ecc uncorrected */
            JobResult = MEM_43_INFLS_JOB_ECC_UNCORRECTED;
        }
        else
        {
            /* the job result is inconsistent */
            JobResult = MEM_43_INFLS_JOB_INCONSISTENT;
        }
    }

    (void)InstanceIndex;

    return JobResult;
}
#endif /* MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON */


/**
 * @brief          IP wrapper blank check function.
 * @details        Route the blank check job to appropriate low level IP function.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_BlankCheck(
    uint32                          InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType   *JobInfo
)
{
    Mem_43_INFLS_JobResultType JobResult;
    Mem_43_INFLS_LengthType TransferLength;
    C40_Ip_StatusType Status;

    if (JobInfo->Length == 0U)
    {
        /* No more data to check blank */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else
    {
        /* Calculate length of data transfer */
        TransferLength = Mem_43_INFLS_IPW_ComputeReadLength(JobInfo);

        /* Read data from flash memory device and verify that it is in erased state */
        Status = C40_Ip_Compare(JobInfo->Address, TransferLength, NULL_PTR);
        if (STATUS_C40_IP_SUCCESS == Status)
        {
            JobResult = MEM_43_INFLS_JOB_PENDING;

            /* Update job state */
            Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        }
        else if (STATUS_C40_IP_ECC_CORRECTED == Status)
        {
            /* Update length */
            Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
            if (JobInfo->Length == 0U)
            {
                JobResult = MEM_43_INFLS_JOB_ECC_CORRECTED;;
            }
            else
            {
                JobResult = MEM_43_INFLS_JOB_PENDING;
            }
        }
        else if (STATUS_C40_IP_ECC_UNCORRECTED == Status)
        {
            /* the job result is ecc uncorrected */
            JobResult = MEM_43_INFLS_JOB_ECC_UNCORRECTED;
        }
        else
        {
            /* the job result is inconsistent */
            JobResult = MEM_43_INFLS_JOB_INCONSISTENT;
        }
    }

    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief          IP wrapper sector function.
 * @details        Route the erase job to appropriate low level IP function.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Erase(
    uint32                             InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType   *JobInfo
)
{
    Mem_43_INFLS_JobResultType     JobResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_INFLS_LengthType        TransferLength;
    C40_Ip_StatusType              Status;
    C40_Ip_VirtualSectorsType      VirtualSector;

    if (JobInfo->Length == 0U)
    {
        /* No more sector to erase */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else
    {
        /* Calculate length of data transfer */
        TransferLength = Mem_43_INFLS_IPW_ComputeEraseLength(JobInfo);

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
        Mem_43_INFLS_IPW_CheckLoadAc(MemBlockAcErase, JobInfo);
#endif

        /* Get the physical sector number */
        VirtualSector = C40_Ip_GetSectorNumberFromAddress(JobInfo->Address);

        /* Unlocks the Virtual Sector */
        Status = C40_Ip_ClearLock(VirtualSector, (uint8)MEM_43_INFLS_DOMAIN_ID);

        if (Status == STATUS_C40_IP_SUCCESS)
        {
            /* Call IP routine to erase internal flash memory sector */
            Status = C40_Ip_MainInterfaceSectorErase(VirtualSector, (uint8)MEM_43_INFLS_DOMAIN_ID);
        }

#if ( STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START )
        if (TRUE == Mem_AcLoaded)
        {
            /* Wait for IP to finish */
            FLASH_AC_CALL(Mem_43_INFLS_pConfigPtr->MemAcErasePtr, Mem_43_INFLS_AcErasePtrType)(Mem_43_INFLS_pConfigPtr->MemAcCallBackPtr);
        }
        else
#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */
        {
            C40_Ip_AccessCode(Mem_43_INFLS_pConfigPtr->MemAcCallBackPtr);
        }

        if ((STATUS_C40_IP_SUCCESS == Status) || (STATUS_C40_IP_ECC_CORRECTED == Status))
        {
            /* Command is sent, the actual job is being processed in the memory device */
            JobResult = MEM_43_INFLS_JOB_PENDING;
            /* Update job state */
            Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        }
        else if (STATUS_C40_IP_ECC_UNCORRECTED == Status)
        {
            /* the job result is ecc uncorrected */
            JobResult = MEM_43_INFLS_JOB_ECC_UNCORRECTED;
        }
        else
        {
            /* Operation failed. Command is sent */
            JobResult = MEM_43_INFLS_JOB_FAILED;
        }

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
        Mem_43_INFLS_IPW_CheckUnLoadAc(JobInfo->JobType);
#endif
    }

    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief          IP wrapper sector write function.
 * @details        Route the write job to appropriate low level IP function.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Write(
    uint32                             InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType   *JobInfo
)
{
    Mem_43_INFLS_JobResultType     JobResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_INFLS_LengthType        TransferLength;
    C40_Ip_StatusType              Status;
    C40_Ip_VirtualSectorsType      VirtualSector;

    if (JobInfo->Length == 0U)
    {
        /* No more data to write */
        JobResult = MEM_43_INFLS_JOB_OK;
    }
    else
    {
        /* Calculate length of data transfer */
        TransferLength = Mem_43_INFLS_IPW_ComputeWriteLength(JobInfo);

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
        Mem_43_INFLS_IPW_CheckLoadAc(MemBlockAcWrite, JobInfo);
#endif

        /* Get the physical sector number */
        VirtualSector = C40_Ip_GetSectorNumberFromAddress(JobInfo->Address);

        /* Unlocks the Virtual Sector */
        Status = C40_Ip_ClearLock(VirtualSector, (uint8)MEM_43_INFLS_DOMAIN_ID);

        if (STATUS_C40_IP_SUCCESS == Status)
        {
            /* Call IP routine to write data to internal flash memory */
            Status = C40_Ip_MainInterfaceWrite(JobInfo->Address, TransferLength, JobInfo->DataPtr, (uint8)MEM_43_INFLS_DOMAIN_ID);
        }

#if ( STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START )
        if (TRUE == Mem_AcLoaded)
        {
            /* Wait for IP to finish */
            FLASH_AC_CALL(Mem_43_INFLS_pConfigPtr->MemAcWritePtr, Mem_43_INFLS_AcWritePtrType)(Mem_43_INFLS_pConfigPtr->MemAcCallBackPtr);
        }
        else
#endif /* STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START */
        {
            C40_Ip_AccessCode(Mem_43_INFLS_pConfigPtr->MemAcCallBackPtr);
        }

        if ((STATUS_C40_IP_SUCCESS == Status) || (STATUS_C40_IP_ECC_CORRECTED == Status))
        {
            /* Command is sent, the actual job is being processed in the memory device */
            JobResult = MEM_43_INFLS_JOB_PENDING;
            /* Update job state */
            Mem_43_INFLS_IPW_UpdateJobProcessedLength(JobInfo, TransferLength);
        }
        else if (STATUS_C40_IP_ECC_UNCORRECTED == Status)
        {
            /* the job result is ecc uncorrected */
            JobResult = MEM_43_INFLS_JOB_ECC_UNCORRECTED;
        }
        else
        {
            /* Operation failed. Command is sent */
            JobResult = MEM_43_INFLS_JOB_FAILED;
        }

#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
        Mem_43_INFLS_IPW_CheckUnLoadAc(JobInfo->JobType);
#endif
    }

    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief    Returns the result of the last job.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_GetJobResult(
    uint32               InstanceIndex,
    Mem_43_INFLS_JobType JobType
)
{
    C40_Ip_StatusType          Status;
    Mem_43_INFLS_JobResultType JobResult;

    switch (JobType)
    {
        case MEM_43_INFLS_JOB_ERASE:
            /* Process ongoing erase asynchronous hardware job. */
            Status = C40_Ip_MainInterfaceSectorEraseStatus();
            break;

        case MEM_43_INFLS_JOB_WRITE:
            /* Process ongoing write asynchronous hardware job. */
            Status = C40_Ip_MainInterfaceWriteStatus();
            break;

        default:
            Status = STATUS_C40_IP_SUCCESS;
            break;
    };

    JobResult = Mem_43_INFLS_IPW_TranslateReturnCode(Status);
    (void)InstanceIndex;

    return JobResult;
}


/**
 * @brief       Cancel an ongoing flash read, write, erase or compare job.
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Cancel(
    uint32 InstanceIndex
)
{
    C40_Ip_StatusType          Status = STATUS_C40_IP_SUCCESS;
    Mem_43_INFLS_JobResultType JobResult;

    /* Check that job is being processed */
    if (STATUS_C40_IP_BUSY == C40_Ip_MainInterfaceHVJobStatus())
    {
        /* Abort a program or erase operation */
        Status = C40_Ip_Abort();
    }

    JobResult = Mem_43_INFLS_IPW_TranslateReturnCode(Status);
    (void)InstanceIndex;

    return JobResult;
}

/**
 * @brief Report Ecc value result.
 */
void Mem_43_INFLS_IPW_ReportEccValueToLayerUnder(void)
{
    C40_Ip_ReportEccUnCorrectedError();
}
#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
