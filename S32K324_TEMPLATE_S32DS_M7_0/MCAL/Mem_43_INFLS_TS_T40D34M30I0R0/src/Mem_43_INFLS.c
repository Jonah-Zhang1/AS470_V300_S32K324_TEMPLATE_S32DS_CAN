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
 * @file       Mem_43_INFLS.c
 *
 * @addtogroup MEM_43_INFLS
 * @implements Mem_43_INFLS.c_Artifact
 *
 * @{
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
#include "Mem_43_INFLS.h"
#include "Mem_43_INFLS_Ipw.h"

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif
#include "SchM_Mem_43_INFLS.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_VENDOR_ID_C                      43
#define MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C       4
#define MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C       7
#define MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_C    0
#define MEM_43_INFLS_SW_MAJOR_VERSION_C               3
#define MEM_43_INFLS_SW_MINOR_VERSION_C               0
#define MEM_43_INFLS_SW_PATCH_VERSION_C               0

/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

    #if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_INFLS.c and Det.h are different"
    #endif
    #endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */

    /* Check if current file and SchM_Fls header file are of the same Autosar version */
    #if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C != SCHM_MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION) || \
         (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C != SCHM_MEM_43_INFLS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mem_43_INFLS.c and SchM_Mem_43_INFLS.h are different"
    #endif
#endif

/* Check if current file and Mem_43_INFLS.h header file are of the same vendor */
#if (MEM_43_INFLS_VENDOR_ID_C != MEM_43_INFLS_VENDOR_ID)
    #error "Mem_43_INFLS.c and Mem_43_INFLS.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS.c and Mem_43_INFLS.h are different"
#endif
/* Check if current file and Mem_43_INFLS.h header file are of the same Software version */
#if ((MEM_43_INFLS_SW_MAJOR_VERSION_C != MEM_43_INFLS_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_SW_MINOR_VERSION_C != MEM_43_INFLS_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_SW_PATCH_VERSION_C != MEM_43_INFLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS.c and Mem_43_INFLS.h are different"
#endif

/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same vendor */
#if (MEM_43_INFLS_VENDOR_ID_C != MEM_43_INFLS_IPW_VENDOR_ID)
    #error "Mem_43_INFLS.c and Mem_43_INFLS_Ipw.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_C    != MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_C != MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS.c and Mem_43_INFLS_Ipw.h are different"
#endif
/* Check if current file and Mem_43_INFLS_Ipw.h header file are of the same Software version */
#if ((MEM_43_INFLS_SW_MAJOR_VERSION_C != MEM_43_INFLS_IPW_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_SW_MINOR_VERSION_C != MEM_43_INFLS_IPW_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_SW_PATCH_VERSION_C != MEM_43_INFLS_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS.c and Mem_43_INFLS_Ipw.h are different"
#endif

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"


/* Pointer to current mem internal flash module configuration set */
const Mem_43_INFLS_ConfigType           * Mem_43_INFLS_pConfigPtr;

/* Information of the current processing job of each Mem instance */
static Mem_43_INFLS_JobRuntimeInfoType    Mem_43_INFLS_eJobRuntimeInfo[MEM_43_INFLS_MEM_INSTANCE_COUNT];

#define MEM_43_INFLS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mem_43_INFLS_MemMap.h"

/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*! Specifies invalid mem instance index (valid ones will be in range 0 to MEM_43_INFLS_MEM_INSTANCE_COUNT-1) */
#define MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID              MEM_43_INFLS_MEM_INSTANCE_COUNT

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS (internal usage)
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


/**
 * @brief    Report a development error
 */
static void Mem_43_INFLS_ReportDevError(
    Mem_43_INFLS_InstanceIdType    InstanceId,
    uint32                      ApiId,
    uint32                      ErrorId
)
{
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Raise the development error via Det function */
    (void)Det_ReportError(MEM_43_INFLS_MODULE_ID, (uint8)InstanceId, (uint8)ApiId, (uint8)ErrorId);
#endif

    (void)InstanceId;
    (void)ApiId;
    (void)ErrorId;
}


/**
 * @brief    Computes and checks the CRC over configuration set
 */
static Std_ReturnType Mem_43_INFLS_ValidateConfigCRC(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    /* Not implemented yet */
    return RetVal;
}

/**
 * @brief   Avoid CWE violation
 *
 */
static void Mem_43_INFLS_IncreasePtr(const Mem_43_INFLS_SectorBatchType **sectorPtr)
{
    (*sectorPtr)++;
}

/**
 * @brief    Search the list of Mem instances and returns index of instance with matching InstanceId
 */
static uint32 Mem_43_INFLS_GetInstanceIndex(const Mem_43_INFLS_InstanceIdType InstanceId)
{
    uint32 InstanceIndex = 0U;

    /* Loop through all configured memory instances */
    for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
    {
        if (InstanceId == Mem_43_INFLS_pConfigPtr->MemInstances[InstanceIndex].InstanceId)
        {
            /* InstanceId is matched, exit loop */
            break;
        }
    }

    /* The returned value will be INVALID if InstanceId is not matched with any InstanceIndex */
    return InstanceIndex;
}


/**
 * @brief    Search for the sector batch that contains the provided address
 */
static const Mem_43_INFLS_SectorBatchType * Mem_43_INFLS_GetSectorBatch(
    uint32                   InstanceIndex,
    Mem_43_INFLS_AddressType    Address
)
{
    const Mem_43_INFLS_MemInstanceType *MemInstance         = &(Mem_43_INFLS_pConfigPtr->MemInstances[InstanceIndex]);
    const Mem_43_INFLS_SectorBatchType *SectorBatch         = MemInstance->SectorBatches;
    Mem_43_INFLS_AddressType           StartAddressOfSector = 0U;
    Mem_43_INFLS_AddressType           EndAddressOfSector   = 0U;
    uint32 Index = 0U;

    /* Loop through all configured sector batches of this memory instance */
    do
    {
        StartAddressOfSector = (Mem_43_INFLS_AddressType)(SectorBatch->StartAddress);
        EndAddressOfSector   = (Mem_43_INFLS_AddressType)(SectorBatch->EndAddress);
        if ( (StartAddressOfSector <= Address) && (Address <= EndAddressOfSector) )
        {
            /* The address falls within this sector batch */
            break;
        }

        /* Move to the next sector batch */
        Mem_43_INFLS_IncreasePtr(&SectorBatch);
        Index++;
    }
    while (Index < MemInstance->SectorBatchCount);

    /* The returned value will be NULL_PTR if Address does not fall within any sector batch */
    if (Index >= MemInstance->SectorBatchCount)
    {
        SectorBatch = NULL_PTR;
    }

    return SectorBatch;
}


/**
 * @brief    Checks if the provided address and length are in range and aligned to end of the sector.
 */
static uint32 Mem_43_INFLS_CheckSectorAligned(const Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;
    uint32 SectorSize = JobRequest->SectorBatch->SectorSize;
    Mem_43_INFLS_AddressType StartAddress  = JobRequest->SectorBatch->StartAddress;
    Mem_43_INFLS_AddressType EndAddress    = JobRequest->SectorBatch->EndAddress;
    Mem_43_INFLS_AddressType TargetAddress = JobRequest->Address;
    Mem_43_INFLS_LengthType  Length        = JobRequest->Length;

    if ( ( 0U != ((TargetAddress - StartAddress) % SectorSize)))
    {
        /* Address of job is not in range or not aligned to start of the sector */
        ErrorId = MEM_43_INFLS_E_PARAM_ADDRESS;
    }
    else if ( 0U != ( ( EndAddress - ( (TargetAddress + Length) - 1U ) )  % SectorSize ))
    {
        /* Length of job is not aligned to end of the sector */
        ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
    }
    else
    {
        /* Both address and length are valid */
        ErrorId = MEM_43_INFLS_E_OK;
    }

    return ErrorId;
}


/**
 * @brief    Checks if the provided address and length are in range and aligned to end of the page.
 */
static uint32 Mem_43_INFLS_CheckWritePageAligned(const Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;
    uint32 WritePageSize = JobRequest->SectorBatch->WritePageSize;
    Mem_43_INFLS_AddressType StartAddress  = JobRequest->SectorBatch->StartAddress;
    Mem_43_INFLS_AddressType TargetAddress = JobRequest->Address;
    Mem_43_INFLS_LengthType  Length        = JobRequest->Length;
    Mem_43_INFLS_LengthType  SectorOffset  = 0U;

    SectorOffset = (TargetAddress + Length) - StartAddress;

    if ( 0U != ( TargetAddress % WritePageSize ) )
    {
        /* Address of job is not in range or not aligned to start of the page */
        ErrorId = MEM_43_INFLS_E_PARAM_ADDRESS;
    }
    else if ( 0U != (SectorOffset % WritePageSize) )
    {
        /* Length of job is not aligned to end of the page */
        ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
    }
    else
    {
        /* Both address and length are valid */
        ErrorId = MEM_43_INFLS_E_OK;
    }

    return ErrorId;
}


/**
 * @brief    Checks if the provided address and length are valid
 */
static uint32 Mem_43_INFLS_ValidateAddressAndLength(Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    JobRequest->SectorBatch = Mem_43_INFLS_GetSectorBatch(JobRequest->InstanceIndex, JobRequest->Address);
    if (NULL_PTR == JobRequest->SectorBatch)
    {
        /* Could not find the sector batch, the address is invalid */
        ErrorId = MEM_43_INFLS_E_PARAM_ADDRESS;
    }
    else if ( (0U == JobRequest->Length) ||
              ((JobRequest->Address + JobRequest->Length - 1U) > JobRequest->SectorBatch->EndAddress)
            )
    {
        /* The length is invalid */
        ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
    }
    else
    {
        switch (JobRequest->JobType)
        {
        case MEM_43_INFLS_JOB_ERASE:
            ErrorId = Mem_43_INFLS_CheckSectorAligned(JobRequest);
            break;
        case MEM_43_INFLS_JOB_WRITE:
            ErrorId = Mem_43_INFLS_CheckWritePageAligned(JobRequest);
            break;

        default:
            /* Both address and length are valid */
            ErrorId = MEM_43_INFLS_E_OK;
            break;
        }
    }

    return ErrorId;
}


/**
 * @brief    Checks if provided InstanceId is consistent with the configuration
 */
static uint32 Mem_43_INFLS_ValidateInstanceId(Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId = MEM_43_INFLS_E_OK;

    /* Get the mem index number according to the mem instance id */
    JobRequest->InstanceIndex = Mem_43_INFLS_GetInstanceIndex(JobRequest->InstanceId);

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Only check if development error detection is enabled */
    if (MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID == JobRequest->InstanceIndex)
    {
        /* The provided InstanceId is inconsistent with the configuration */
        ErrorId = MEM_43_INFLS_E_PARAM_INSTANCE_ID;
    }
#endif

    return ErrorId;
}


/**
 * @brief    Checks if the Mem module has been initialized.
 */
static inline uint32 Mem_43_INFLS_ValidateModuleInitialized(void)
{
    uint32 ErrorId = MEM_43_INFLS_E_OK;

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Only check if development error detection is enabled */
    if (NULL_PTR == Mem_43_INFLS_pConfigPtr)
    {
        /* The Mem module has not been initialized */
        ErrorId = MEM_43_INFLS_E_UNINIT;
    }
#endif

    return ErrorId;
}


/**
 * @brief    Common checks of input parameters for driver APIs.
 */
static uint32 Mem_43_INFLS_ValidateParamJobCommon(Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Check if the provided InstanceId is consistent with the configuration */
        ErrorId = Mem_43_INFLS_ValidateInstanceId(JobRequest);
    }

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Check if the address and the length are valid */
        ErrorId = Mem_43_INFLS_ValidateAddressAndLength(JobRequest);
    }

    return ErrorId;
}


/**
 * @brief    Checks if the input argument is a NULL pointer.
 */
static inline uint32 Mem_43_INFLS_ValidateDataPointer(const Mem_43_INFLS_DataType *DataPtr)
{
    uint32 ErrorId = MEM_43_INFLS_E_OK;

    if (NULL_PTR == DataPtr)
    {
        /* The DataPtr argument is a NULL pointer */
        ErrorId = MEM_43_INFLS_E_PARAM_POINTER;
    }

    return ErrorId;
}


/**
 * @brief    Checks the input parameters for data transfer jobs (read, write)
 */
static uint32 Mem_43_INFLS_ValidateParamJobDataTransfer(Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Perform the common checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobCommon(JobRequest);

    /* Perform the specific checking */
    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        ErrorId = Mem_43_INFLS_ValidateDataPointer(JobRequest->DataPtr);
    }

    return ErrorId;
}


/**
 * @brief    Initialize the input parameter for the new job request
 */
static void Mem_43_INFLS_InitJobRequest(
    Mem_43_INFLS_JobRuntimeInfoType    *JobRequest,
    Mem_43_INFLS_InstanceIdType         InstanceId,
    Mem_43_INFLS_AddressType            Address,
    Mem_43_INFLS_DataType              *DataPtr,
    Mem_43_INFLS_LengthType             Length
)
{
    /* Input value */
    JobRequest->InstanceId       = InstanceId;
    JobRequest->HwServiceIdJob   = MEM_43_INFLS_HWSERVICEID_INVALID;
    JobRequest->Address          = Address;
    JobRequest->DataPtr          = DataPtr;
    JobRequest->Length           = Length;
    /* Default value */
    JobRequest->InstanceIndex    = MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID;
    JobRequest->SectorBatch      = NULL_PTR;
    /* Prepare for a new job */
    JobRequest->JobFlags         = MEM_43_INFLS_JOB_FLAG_STARTED;
    JobRequest->JobResult        = MEM_43_INFLS_JOB_PENDING;
#if (MEM_43_INFLS_SUSPEND_RESUME_SUPPORT == STD_ON)
    JobRequest->SuspendState     = FALSE;
#endif
}


/**
 * @brief    Check if the mem instance is idle and configure the new job request
 */
static uint32 Mem_43_INFLS_ConfigureJobRequest(const Mem_43_INFLS_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    if (MEM_43_INFLS_JOB_PENDING == Mem_43_INFLS_eJobRuntimeInfo[JobRequest->InstanceIndex].JobResult)
    {
        /* A previous job is still being processed */
        ErrorId = MEM_43_INFLS_E_JOB_PENDING;
    }
    else
    {
        /* Accept the requested job */
        ErrorId = MEM_43_INFLS_E_OK;
        /* Configure the new job */
        Mem_43_INFLS_eJobRuntimeInfo[JobRequest->InstanceIndex] = *JobRequest;
    }

    return ErrorId;
}

/**
* @brief        Process the HwSpecificService job
*
* @details      Process the HwSpecificService job with the corresponding serviceID stored in the variable JobInfo.HwServiceIdJob
*
*/
static Mem_43_INFLS_JobResultType Mem_43_INFLS_ProcessHwSpecificServiceJob(uint32 InstanceIndex, Mem_43_INFLS_JobRuntimeInfoType* JobInfo)
{
    Mem_43_INFLS_JobResultType JobResult    = MEM_43_INFLS_JOB_FAILED;

#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
    if(MEM_43_INFLS_HWSERVICEID_COMPARE == JobInfo->HwServiceIdJob)
    {
        JobResult = Mem_43_INFLS_IPW_Compare(InstanceIndex, JobInfo);
    }
#endif

    (void)InstanceIndex;
    (void)JobInfo;

    return JobResult;
}

/**
 * @brief   Decides which sub-function to call based on the job type:
 *          Modify (Write, Erase) or Read (Read, BlankCheck).
 */
static Mem_43_INFLS_JobResultType Mem_43_INFLS_DoRequestedJobs(
    uint32                           InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType    *JobInfo
)
{
    /* Assume no more data to process, previous asynchronous job completed successfully */
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_OK;

    if (0U != JobInfo->Length)
    {
        /* Call Low-level driver to work with physical flash device
         * Process the maximum length depending on the hardware capabilities, or until a sector boundary
         */
        switch (JobInfo->JobType)
        {
            case MEM_43_INFLS_JOB_ERASE:
                JobResult = Mem_43_INFLS_IPW_Erase(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_WRITE:
                JobResult = Mem_43_INFLS_IPW_Write(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_READ:
                JobResult = Mem_43_INFLS_IPW_Read(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_HWSPECIFICSERVICE:
                /* Process hw specific service job */
                JobResult = Mem_43_INFLS_ProcessHwSpecificServiceJob(InstanceIndex, JobInfo);
                break;

            case MEM_43_INFLS_JOB_BLANK_CHECK:
                JobResult = Mem_43_INFLS_IPW_BlankCheck(InstanceIndex, JobInfo);
                break;

            default:  /* MEM_43_INFLS_JOB_NONE */
                JobResult = MEM_43_INFLS_JOB_FAILED;
                break;
        };
        if ( ((MEM_43_INFLS_JOB_OK == JobResult) || (MEM_43_INFLS_JOB_ECC_CORRECTED == JobResult))  && (0U != JobInfo->Length) )
        {
            /* The current chunk has completed but there is still data to process, need more MainFunction calls */
            JobResult = MEM_43_INFLS_JOB_PENDING;
        }
    }
    return JobResult;
}


/**
 * @brief    Process the pending job for the mem instance
 */
static void Mem_43_INFLS_ProcessRequestedJobs(uint32 InstanceIndex)
{
    Mem_43_INFLS_JobRuntimeInfoType *JobInfo = &(Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex]);
    Mem_43_INFLS_JobResultType     JobResult = MEM_43_INFLS_JOB_OK;

    if ((JobInfo->JobFlags & MEM_43_INFLS_JOB_FLAG_STARTED) != 0U)
    {
        /* Clear flag */
        JobInfo->JobFlags &=  ~((uint8)MEM_43_INFLS_JOB_FLAG_STARTED);
    }
    else
    {
        /* Check the status of the job is being processed in the low-level driver */
        JobResult = Mem_43_INFLS_IPW_GetJobResult(InstanceIndex, JobInfo->JobType);
    }

    if (MEM_43_INFLS_JOB_OK == JobResult)
    {
        /* The previous pending job has been done, launch new operation */
        JobResult = Mem_43_INFLS_DoRequestedJobs(InstanceIndex, JobInfo);
    }

    if (MEM_43_INFLS_JOB_ECC_UNCORRECTED == JobResult)
    {
        /* abort pending job */
        JobInfo->JobType = MEM_43_INFLS_JOB_NONE;
    }
    /* Update the latest job result */
    JobInfo->JobResult = JobResult;
}


#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
static Std_ReturnType Mem_43_INFLS_Compare(
    Mem_43_INFLS_InstanceIdType    InstanceId,
    Mem_43_INFLS_AddressType       SourceAddress,
    Mem_43_INFLS_DataType        * DestinationDataPtr,
    Mem_43_INFLS_LengthType        Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, SourceAddress, DestinationDataPtr, Length);

    /* Config Hardware Service job for Compare Function  */
    JobRequest.JobType        = MEM_43_INFLS_JOB_HWSPECIFICSERVICE;
    JobRequest.HwServiceIdJob = MEM_43_INFLS_HWSERVICEID_COMPARE;

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransfer(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_05();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_05();
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_READ_ID, ErrorId);
    }

    return RetVal;
}
#endif /* MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON */

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief            Check dev error common for Mem_HwSpecificService API()
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        HwServiceId           Hardware specific service request identifier for dispatching the request.
 * @param[in]        DataPtr               Request specific data pointer.
 * @param[in]        LengthPtr             Size pointer of the data passed by dataPtr.
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : has dev error detect.
 *                   - E_NOT_OK               : hasn't dev error detect.
 */
static Std_ReturnType Mem_43_INFLS_CheckDevErrorCommon_HwSpecificService(
                                            Mem_43_INFLS_InstanceIdType     instanceId,
                                            Mem_43_INFLS_HwServiceIdType    hwServiceId,
                                            Mem_43_INFLS_DataType         * dataPtr,
                                            Mem_43_INFLS_LengthType       * lengthPtr)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint32 ErrorId;

    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if (ErrorId == MEM_43_INFLS_E_OK)
    {
        /* Get the mem index number according to the mem instance id */
        uint32 InstanceIndex = Mem_43_INFLS_GetInstanceIndex(instanceId);

        if (MEM_43_INFLS_MEM_INSTANCE_COUNT <= InstanceIndex)
        {
            /* The provided instanceId is inconsistent with the configuration */
            ErrorId = MEM_43_INFLS_E_PARAM_INSTANCE_ID;
        }
        else if ((NULL_PTR == dataPtr) || (NULL_PTR == lengthPtr))
        {
            ErrorId = MEM_43_INFLS_E_PARAM_POINTER;
        }
#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
        else if ((MEM_43_INFLS_HWSERVICEID_COMPARE == hwServiceId) && (sizeof(Mem_43_INFLS_CompareConfigType) != *lengthPtr))
        {
            ErrorId = MEM_43_INFLS_E_PARAM_LENGTH;
        }
#endif
        else
        {
            RetVal = (Std_ReturnType)E_OK;
        }
    }

    if(MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Report the error */
        (void)Det_ReportError(MEM_43_INFLS_MODULE_ID, (uint8)instanceId, (uint8)MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID, (uint8)ErrorId);
    }

#if (MEM_43_INFLS_HW_COMPARE_SERVICE != STD_ON)
    /* fix compiler warning */
    (void)hwServiceId;
#endif

    return RetVal;
}
#endif

/*==================================================================================================
                                       GLOBAL FUNCTIONS (Synchronous Functions)
==================================================================================================*/

/**
 * @brief        The function initializes Mem_43_INFLS module.
 *
 * @details      Initialization function - initializes all variables
 *               and sets the module state to initialized.
 *
 * @param[in]    ConfigPtr        Pointer to the configuration data structure - since Mem_43_INFLS driver
 *                                is a precompile module this parameter is typically not used.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @pre          None
 *
 * @api
 *
 * @implements   Mem_43_INFLS_Init_Activity
 */
void Mem_43_INFLS_Init(const Mem_43_INFLS_ConfigType * ConfigPtr)
{
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_OK;
    Std_ReturnType Status;
    uint32 InstanceIndex;

    if (NULL_PTR != ConfigPtr)
    {
        /* The ConfigPtr argument is not a NULL pointer */
        Mem_43_INFLS_ReportDevError(0U, MEM_43_INFLS_INIT_ID, MEM_43_INFLS_E_PARAM_POINTER);
    }
    else
    {
        /* Initialize the Mem driver internal states and set the Mem driver job processing state to MEM_43_INFLS_JOB_OK */
        Mem_43_INFLS_pConfigPtr = &Mem_43_INFLS_Config;

        Status = Mem_43_INFLS_ValidateConfigCRC();
        if ((Std_ReturnType)E_OK == Status)
        {
            /* Initialize low-level hardware */
            Status = Mem_43_INFLS_IPW_Init();
        }

        if ((Std_ReturnType)E_OK != Status)
        {
            /* Mark the driver as un-initialized */
            Mem_43_INFLS_pConfigPtr = NULL_PTR;
            JobResult = MEM_43_INFLS_JOB_FAILED;
        }

        /* Update job result */
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult = JobResult;
        }
    }
}


/**
 * @brief        The function de-initializes the Mem_43_INFLS module.
 *
 * @details      De-initialize module. If there is still an access job pending,
 *               it is immediately terminated (using hardware cancel operation)
 *               and the Mem driver module state is set to uninitialized.
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @pre          The Mem_43_INFLS module must be re-initialized before it will accept
 *               any new job requests after this service is processed.
 *
 * @implements   Mem_43_INFLS_DeInit_Activity
 */
void Mem_43_INFLS_DeInit(void)
{
    uint32 InstanceIndex;
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_OK;

    /* Check if the driver has been initialized before */
    if (NULL_PTR != Mem_43_INFLS_pConfigPtr)
    {
        /* Cancel any ongoing flash operations in the hardware */
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            /* Check if there was a pending job in each instance */
            if (MEM_43_INFLS_JOB_PENDING == Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult)
            {
                /* Cancel the on-going job for this mem instance (using hardware) */
                JobResult = Mem_43_INFLS_IPW_Cancel(InstanceIndex);
            }

            /* Update job result */
            Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult = JobResult;
            /* Update job JobType to MEM_43_INFLS_JOB_NONE */
            Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobType   = MEM_43_INFLS_JOB_NONE;
        }

        /* De-initialize the Mem driver internal states */
        Mem_43_INFLS_pConfigPtr = NULL_PTR;
    }
}


/**
 * @brief        Return the version information of the Mem module.
 *
 * @details      Version information includes:
 *               - Module Id
 *               - Vendor Id
 *               - Vendor specific version numbers
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   VersionInfoPtr    Pointer to where to store the version information of this module.
 *
 * @return       None
 *
 * @api
 *
 * @implements    Mem_43_INFLS_GetVersionInfo_Activity
 */
void Mem_43_INFLS_GetVersionInfo(Std_VersionInfoType * VersionInfoPtr)
{
    if (NULL_PTR != VersionInfoPtr)
    {
        /* Return version information about Mem module */
        VersionInfoPtr->moduleID         = (uint16)MEM_43_INFLS_MODULE_ID;
        VersionInfoPtr->vendorID         = (uint16)MEM_43_INFLS_VENDOR_ID;
        VersionInfoPtr->sw_major_version =  (uint8)MEM_43_INFLS_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version =  (uint8)MEM_43_INFLS_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version =  (uint8)MEM_43_INFLS_SW_PATCH_VERSION;
    }
    else
    {
        /* The VersionInfoPtr argument is a NULL pointer */
        Mem_43_INFLS_ReportDevError(0U, MEM_43_INFLS_GET_VERSION_INFO_ID, MEM_43_INFLS_E_PARAM_POINTER);
    }
}


/**
 * @brief        Returns the result of the most recent job.
 *
 * @details      Returns synchronously the result of the last job.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       Mem_43_INFLS_JobResultType    Most recent job result.
 *
 * @api
 *
 * @implements   Mem_43_INFLS_GetJobResult_Activity
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_GetJobResult(Mem_43_INFLS_InstanceIdType InstanceId)
{
    Mem_43_INFLS_JobResultType JobResult = MEM_43_INFLS_JOB_FAILED;
    uint32 InstanceIndex;

    InstanceIndex = Mem_43_INFLS_GetInstanceIndex(InstanceId);
    if (InstanceIndex != MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID)
    {
        /* Get the most recent job result of the according driver instance */
        JobResult = Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult;
    }

    return JobResult;
}


/**
 * @brief        Suspends active memory operation using hardware mechanism.
 *
 * @details      If the suspend mechanism is not supported by hardware,
 *               implementation based on physical segmentation.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_INFLS_Suspend_Activity
 */
Std_ReturnType Mem_43_INFLS_Suspend(Mem_43_INFLS_InstanceIdType InstanceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

#if (MEM_43_INFLS_SUSPEND_RESUME_SUPPORT == STD_ON)
    uint32                           InstanceIndex = 0U;
    Mem_43_INFLS_JobResultType       JobCurrentResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_INFLS_JobRuntimeInfoType *JobCurrentInfo;

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    uint32 ErrorId;

    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if(MEM_43_INFLS_E_OK != ErrorId)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_SUSPEND_ID, ErrorId);
    }
    else
#endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */
    {
        InstanceIndex  = Mem_43_INFLS_GetInstanceIndex(InstanceId);
        if (InstanceIndex != MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID)
        {
            /* Get Information of Job Current */
            JobCurrentInfo = &(Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex]);

            /* Check if Job current: in case not suspend operation is already in pending */
            if ((JobCurrentInfo->SuspendState == FALSE) &&
                (JobCurrentInfo->JobResult    == MEM_43_INFLS_JOB_PENDING))
            {
                switch (JobCurrentInfo->JobType)
                {
                    case MEM_43_INFLS_JOB_ERASE:
                        JobCurrentResult = Mem_43_INFLS_IPW_EraseSuspend(InstanceId);
                        break;
                    case MEM_43_INFLS_JOB_WRITE:
                    default: /* Read, compare or blank check*/
                        RetVal = E_MEM_SERVICE_NOT_AVAIL;
                        break;
                }

                if (JobCurrentResult == MEM_43_INFLS_JOB_OK)
                {
                    JobCurrentInfo->SuspendState = TRUE;
                    RetVal = E_OK;
                }
            }
        }
    }

#else /* Hardware not support Resume feature */
    (void)InstanceId;
    RetVal = E_MEM_SERVICE_NOT_AVAIL;
#endif /* MEM_43_INFLS_SUSPEND_RESUME_SUPPORT == STD_ON */

    return RetVal;
}


/**
 * @brief        Resumes suspended memory operation using hardware mechanism.
 *
 * @details      Resumes suspended memory operation using hardware mechanism.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_INFLS_Resume_Activity
 */
Std_ReturnType Mem_43_INFLS_Resume(Mem_43_INFLS_InstanceIdType InstanceId)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;

#if (MEM_43_INFLS_SUSPEND_RESUME_SUPPORT == STD_ON)
    uint32                           InstanceIndex = 0U;
    Mem_43_INFLS_JobResultType       JobCurrentResult = MEM_43_INFLS_JOB_FAILED;
    Mem_43_INFLS_JobRuntimeInfoType *JobCurrentInfo;

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    uint32 ErrorId;

    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if(MEM_43_INFLS_E_OK != ErrorId)
    {
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_RESUME_ID, ErrorId);
    }
    else
#endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */
    {
        InstanceIndex  = Mem_43_INFLS_GetInstanceIndex(InstanceId);
        if (InstanceIndex != MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID)
        {
            /* Get Information of Job Current */
            JobCurrentInfo = &(Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex]);

            /* Check if Job current: in case not suspend operation is already in pending */
            if ((JobCurrentInfo->SuspendState == TRUE) &&
                (JobCurrentInfo->JobResult    == MEM_43_INFLS_JOB_PENDING))
            {
                switch (JobCurrentInfo->JobType)
                {
                    case MEM_43_INFLS_JOB_ERASE:
                        JobCurrentResult = Mem_43_INFLS_IPW_EraseResume(InstanceId);
                        break;
                    case MEM_43_INFLS_JOB_WRITE:
                    default: /* Read, compare or blank check*/
                        RetVal = E_MEM_SERVICE_NOT_AVAIL;
                        break;
                }

                if (JobCurrentResult == MEM_43_INFLS_JOB_OK)
                {
                    JobCurrentInfo->SuspendState = FALSE;
                    JobCurrentInfo->JobResult    = JobCurrentResult;
                    RetVal = E_OK;
                }
            }
        }
    }

#else /* Hardware not support Resume feature */
    (void)InstanceId;
    RetVal = E_MEM_SERVICE_NOT_AVAIL;
#endif /* MEM_43_INFLS_SUSPEND_RESUME_SUPPORT == STD_ON */

    return RetVal;
}
/*==================================================================================================
                                       GLOBAL FUNCTIONS (Asynchronous Functions)
==================================================================================================*/

/**
 * @brief            Reads from flash memory.
 *
 * @details          Triggers a read job to copy the from the source address into the referenced destination data
 *                   buffer. The result of this service can be retrieved using the Mem_GetJobResult API. If the read
 *                   operation was successful, the result of the job is MEM_43_INFLS_JOB_OK. If the read operation failed,
 *                   the result of the job is either MEM_43_INFLS_JOB_FAILED in case of a general error or MEM_ECC_
 *                   CORRECTED/MEM_ECC_UNCORRECTED in case of a correctable/uncorrectable ECC error.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        SourceAddress         Physical address to read data from.
 * @param[in]        Length                Read length in bytes.
 *
 * @param[out]       DestinationDataPtr    Destination memory pointer to store the read data
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_INFLS_Read_Activity
 */
Std_ReturnType Mem_43_INFLS_Read(
    Mem_43_INFLS_InstanceIdType    InstanceId,
    Mem_43_INFLS_AddressType       SourceAddress,
    Mem_43_INFLS_DataType        * DestinationDataPtr,
    Mem_43_INFLS_LengthType        Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_READ;
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, SourceAddress, DestinationDataPtr, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransfer(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_03();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_03();
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_READ_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Writes to flash memory.
 *
 * @details          Triggers a write job to store the passed data to the provided address area with given address
 *                   and length. The result of this service can be retrieved using the Mem_GetJobResult API. If the
 *                   write operation was successful, the job result is MEM_43_INFLS_JOB_OK. If there was an issue writing
 *                   the data, the result is MEM_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical write address (aligned to page size).
 * @param[out]       SourceDataPtr         Source data pointer (aligned to page size).
 * @param[in]        Length                Write length in bytes (aligned to page size).
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_INFLS_Write_Activity
 */
Std_ReturnType Mem_43_INFLS_Write(
    Mem_43_INFLS_InstanceIdType     InstanceId,
    Mem_43_INFLS_AddressType        TargetAddress,
    const Mem_43_INFLS_DataType   * SourceDataPtr,
    Mem_43_INFLS_LengthType         Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_WRITE;

    /* Clause added to fulfil MISRA Rule 11.8 */
    const uint32 SourceDataAddr = (uint32)&(SourceDataPtr[0]);

    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, TargetAddress, (Mem_43_INFLS_DataType *)(SourceDataAddr), Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobDataTransfer(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_02();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_02();
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_WRITE_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Erase one or more complete flash sectors.
 *
 * @details          Triggers an erase job of the given sector/sector batch defined by targetAddress and length.
 *                   The result of this service can be retrieved using the Mem_GetJobResult API. If the erase operation
 *                   was successful, the result of the job is MEM_43_INFLS_JOB_OK. If the erase operation failed, e.g. due to
 *                   a hardware issue, the result of the job is MEM_43_INFLS_JOB_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical erase address (aligned to sector size).
 * @param[in]        Length                Erase length in bytes (aligned to sector size).
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_INFLS_Erase_Activity
 */
Std_ReturnType Mem_43_INFLS_Erase(
    Mem_43_INFLS_InstanceIdType    InstanceId,
    Mem_43_INFLS_AddressType       TargetAddress,
    Mem_43_INFLS_LengthType        Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_ERASE;
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, TargetAddress, NULL_PTR, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobCommon(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_01();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_01();
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_ERASE_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Verify whether a given memory area has been erased but not (yet) programmed.
 *
 * @details          Triggers a job to check the erased state of the page which is referenced by targetAddress.
 *                   The result of this service can be retrieved using the Mem_GetJobResult API. If the checked page is
 *                   blank, the result of the job is MEM_43_INFLS_JOB_OK. Otherwise, if the page is not blank, the result is
 *                   MEM_INCONSISTENT.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        TargetAddress         Physical blank check address.
 * @param[in]        Length                Blank check length.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_INFLS_BlankCheck_Activity
 */
Std_ReturnType Mem_43_INFLS_BlankCheck(
    Mem_43_INFLS_InstanceIdType    InstanceId,
    Mem_43_INFLS_AddressType       TargetAddress,
    Mem_43_INFLS_LengthType        Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;

    /* Prepare for input parameter checking before update runtime information */
    Mem_43_INFLS_JobRuntimeInfoType JobRequest;
    JobRequest.JobType = MEM_43_INFLS_JOB_BLANK_CHECK;
    Mem_43_INFLS_InitJobRequest(&JobRequest, InstanceId, TargetAddress, NULL_PTR, Length);

    /* Perform the input parameters checking */
    ErrorId = Mem_43_INFLS_ValidateParamJobCommon(&JobRequest);

    if (MEM_43_INFLS_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_04();

        /* Configure the new job request to global runtime variable */
        ErrorId = Mem_43_INFLS_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_Mem_43_INFLS_MEM_EXCLUSIVE_AREA_04();
    }

    if (MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_BLANK_CHECK_ID, ErrorId);
    }

    return RetVal;
}


/**
 * @brief            Trigger a hardware specific service.
 *
 * @details          Triggers a hardware specific memory driver job. DataPtr can be used to pass and return data to/
 *                   from this service. This service is just a dispatcher to the hardware specific service
 *                   implementation referenced by HwServiceId. The result of this service can be retrieved using the
 *                   Mem_GetJobResult API. If the hardware specific operation was successful, the result of the job
 *                   is MEM_43_INFLS_JOB_OK. If the hardware specific operation failed, the result of the job is MEM_43_INFLS_JOB_FAILED.
 *
 * @param[in]        InstanceId            ID of the related memory driver instance
 * @param[in]        HwServiceId           Hardware specific service request identifier for dispatching the request.
 * @param[in]        DataPtr               Request specific data pointer.
 * @param[in]        LengthPtr             Size pointer of the data passed by dataPtr.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The service function is not implemented.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       Mem_43_INFLS_HwSpecificService_Activity
 */
Std_ReturnType Mem_43_INFLS_HwSpecificService(
    Mem_43_INFLS_InstanceIdType     instanceId,
    Mem_43_INFLS_HwServiceIdType    hwServiceId,
    Mem_43_INFLS_DataType         * dataPtr,
    Mem_43_INFLS_LengthType       * lengthPtr
)
{
    Std_ReturnType RetVal;

#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
    const Mem_43_INFLS_CompareConfigType*  pCompareConfig;
#endif

#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    /* Perform the input parameters checking */
    RetVal = Mem_43_INFLS_CheckDevErrorCommon_HwSpecificService(instanceId, hwServiceId, dataPtr, lengthPtr);

    if ((Std_ReturnType)E_OK == RetVal)
    {
#endif
        switch (hwServiceId)
        {
            #if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
            case MEM_43_INFLS_HWSERVICEID_COMPARE:
                pCompareConfig = (Mem_43_INFLS_CompareConfigType *)((uint32)dataPtr);
                RetVal = Mem_43_INFLS_Compare(instanceId, pCompareConfig->CompareAddr, pCompareConfig->DataSourcePtr, pCompareConfig->Length);
                break;
            #endif

            default:
                RetVal = E_MEM_SERVICE_NOT_AVAIL;
                break;
        }
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    }
#else
    (void)instanceId;
    (void)dataPtr;
    (void)lengthPtr;
#endif

    return RetVal;
}

/**
 * @brief        Propagates an ECC error to the memory upper layers
 *
 * @details      This service can be used to report an access error in case
 *               the Mem driver cannot provide the access error information - typically for ECC faults.
 *               It is called by the system ECC handler to propagate an ECC error to the memory upper layers.
 *
 * @param[in]    InstanceId    ID of the related memory driver instance.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @implements   Mem_43_INFLS_PropagateError_Activity
 */
void Mem_43_INFLS_PropagateError(Mem_43_INFLS_InstanceIdType InstanceId)
{
    uint32 Index;
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    uint32 ErrorId;
    /* Checks if the Mem module has been initialized */
    ErrorId = Mem_43_INFLS_ValidateModuleInitialized();

    if(MEM_43_INFLS_E_OK == ErrorId)
    {
#endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */
        /* Check if InstanceId is consistent with configuration */
        /* Get the mem index number according to the mem instance id */
        Index = Mem_43_INFLS_GetInstanceIndex(InstanceId);
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
        if(MEM_43_INFLS_MEM_INSTANCE_INDEX_INVALID == Index)
        {
            /* The provided InstanceId is inconsistent with the configuration */
            ErrorId = MEM_43_INFLS_E_PARAM_INSTANCE_ID;
        }
    }

    if(MEM_43_INFLS_E_OK != ErrorId)
    {
        /* Report the error */
        Mem_43_INFLS_ReportDevError(InstanceId, MEM_43_INFLS_PROPAGATE_ERROR_ID, ErrorId);
    }
    else
    {
#endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */
        Mem_43_INFLS_eJobRuntimeInfo[Index].JobType=MEM_43_INFLS_JOB_NONE;
        /* Set the job result code to MEM_ECC_UNCORRECTED */
        Mem_43_INFLS_eJobRuntimeInfo[Index].JobResult=MEM_43_INFLS_JOB_ECC_UNCORRECTED;
        Mem_43_INFLS_IPW_ReportEccValueToLayerUnder();
#if (MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* MEM_43_INFLS_DEV_ERROR_DETECT == STD_ON */
}
/*==================================================================================================
                                       GLOBAL FUNCTIONS (Scheduled Functions)
==================================================================================================*/

/**
 * @brief            Service to handle the requested jobs and the internal management operations.
 *
 * @details          Service to handle the requested jobs and the internal management operations.
 *
 * @param[in]    None
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @note             This function have to be called cyclically by the Basic Software Module;
 *                   it will do nothing if there aren't pending job.
 *
 * @implements       Mem_43_INFLS_MainFunction_Activity
 */
void Mem_43_INFLS_MainFunction(void)
{
    uint32 InstanceIndex;

    /* SWS_BSW_00037 - If the module is not initialized and the main function is executed
       then no error shall be reported and the main function shall return immediately.
    */
    if (NULL_PTR != Mem_43_INFLS_pConfigPtr)
    {
        for (InstanceIndex = 0U; InstanceIndex < MEM_43_INFLS_MEM_INSTANCE_COUNT; InstanceIndex++)
        {
            /* Check if there was a pending job in each instance */
            if (MEM_43_INFLS_JOB_PENDING == Mem_43_INFLS_eJobRuntimeInfo[InstanceIndex].JobResult)
            {
                /* Process the requested job for this mem instance */
                Mem_43_INFLS_ProcessRequestedJobs(InstanceIndex);
            }
        }
    }
}


#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
