/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : none
*   Dependencies         : MemAcc
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
*   @file MemAcc.c
*
*   @addtogroup MEMACC Driver
*   @{
*/

/* implements MemAcc.c_Artifact */

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
 *                                        INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
==================================================================================================*/
#include "MemAcc.h"

#if (MEMACC_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#include "SchM_MemAcc.h"

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEMACC_VENDOR_ID_C                      43
#define MEMACC_AR_RELEASE_MAJOR_VERSION_C       4
#define MEMACC_AR_RELEASE_MINOR_VERSION_C       7
#define MEMACC_AR_RELEASE_REVISION_VERSION_C    0
#define MEMACC_SW_MAJOR_VERSION_C               3
#define MEMACC_SW_MINOR_VERSION_C               0
#define MEMACC_SW_PATCH_VERSION_C               0


/*==================================================================================================
 *                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and MemAcc.h file are of the same vendor */
#if (MEMACC_VENDOR_ID_C != MEMACC_VENDOR_ID)
    #error "MemAcc.c and MemAcc.h have different vendor ids"
#endif
/* Check if current file and MemAcc.h file are of the same Autosar version */
#if ((MEMACC_AR_RELEASE_MAJOR_VERSION_C    != MEMACC_AR_RELEASE_MAJOR_VERSION) || \
     (MEMACC_AR_RELEASE_MINOR_VERSION_C    != MEMACC_AR_RELEASE_MINOR_VERSION) || \
     (MEMACC_AR_RELEASE_REVISION_VERSION_C != MEMACC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of MemAcc.c and MemAcc.h are different"
#endif
/* Check if current file and MemAcc.h file are of the same software version */
#if ((MEMACC_SW_MAJOR_VERSION_C != MEMACC_SW_MAJOR_VERSION) || \
     (MEMACC_SW_MINOR_VERSION_C != MEMACC_SW_MINOR_VERSION) || \
     (MEMACC_SW_PATCH_VERSION_C != MEMACC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of MemAcc.c and MemAcc.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (MEMACC_DEV_ERROR_DETECT == STD_ON)
        /* Checks against Det.h */
        #if ((MEMACC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
             (MEMACC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AUTOSAR Version Numbers of MemAcc.c and Det.h are different"
        #endif
    #endif
    /* Checks against SchM_MemAcc.h */
    #if ((MEMACC_AR_RELEASE_MAJOR_VERSION_C != SCHM_MEMACC_AR_RELEASE_MAJOR_VERSION) || \
         (MEMACC_AR_RELEASE_MINOR_VERSION_C != SCHM_MEMACC_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AUTOSAR Version Numbers of MemAcc.c and SchM_MemAcc.h are different"
    #endif
#endif
/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

#define MEMACC_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemAcc_MemMap.h"

/* Pointer to current memacc module configuration set */
const MemAcc_ConfigType                   *MemAcc_pConfigPtr;

/* Point to the job runtime information list */
static MemAcc_JobRuntimeInfoType          *MemAcc_pJobRuntimeInfo;

#if (MEMACC_COMPARE_API == STD_ON)

static MemAcc_DataType                     MemAcc_Compare_Buffer[MEMACC_COMPARE_BUFFER_SIZE];

#endif

#define MEMACC_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemAcc_MemMap.h"


#define MEMACC_START_SEC_VAR_CLEARED_16
#include "MemAcc_MemMap.h"

/* Runtime status of the Mem hardware resources to indicate they are idle or busy */
static uint16                              MemAcc_au16MemHwResources[MEMACC_MEM_HW_RESOURCE_COUNT];

#define MEMACC_STOP_SEC_VAR_CLEARED_16
#include "MemAcc_MemMap.h"


/*==================================================================================================
 *                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*! The number of address areas in this configuration set */
#define MEMACC_ADDRESS_AREA_COUNT                      (MemAcc_pConfigPtr->AddressAreaCount)

/*! Specifies invalid address area index (valid ones will be in range 0 to MEMACC_ADDRESS_AREA_COUNT-1) */
#define MEMACC_ADDRESS_AREA_INDEX_INVALID              (0xFFFFU)

/*! Specifies an idle hardware resource */
#define MEMACC_MEM_HW_RESOURCE_IDLE                    (0xFFFFU)


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

#define MEMACC_START_SEC_CODE
#include "MemAcc_MemMap.h"

#if (MEMACC_DEV_ERROR_DETECT == STD_ON)
/**
 * @brief    Report a development error
 */
static void MemAcc_ReportDevError
(
    uint32                      ApiId,
    uint32                      ErrorId
)
{
    /* Raise the development error via Det function */
    /* There is no instance in Mem Acc so InstanceId is 0U*/
    (void)Det_ReportError(MEMACC_MODULE_ID, (uint8)0U, (uint8)ApiId, (uint8)ErrorId);
}
#endif

/**
 * @brief    Computes and checks the CRC over configuration set
 */
static Std_ReturnType MemAcc_ValidateConfigCRC(void)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    /* Not implemented yet */
    return RetVal;
}


/**
 * @brief    If MemAccMemInvocation is set to INDIRECT_DYNAMIC or INDIRECT_STATIC,
 *           MemAcc_Init shall also initialize all available Mem drivers
 *           by calling the Mem driver's individual initialization functions.
 */
static void MemAcc_InitMemDrivers(void)
{
    uint32 Index;

    for (Index = 0U; Index < MemAcc_pConfigPtr->MemApiCount; Index++)
    {
        if(MemAcc_pConfigPtr->MemApisInvocation[Index] == MEMACC_MEM_INDIRECT_STATIC)
        {
            /* Perform the initialization of Mem drivers with INDIRECT_STATIC type */
            MemAcc_pConfigPtr->MemApis[Index].InitFunc(NULL_PTR);
        }
    }

    /* MemAcc_ActivateMem is needed for Mem drivers with INDIRECT_DYNAMIC type */
}


/**
 * @brief    If MemAccMemInvocation is set to INDIRECT_DYNAMIC or INDIRECT_STATIC,
 *           MemAcc_Deinit shall also de-initialize all available Mem drivers
 *           by calling the Mem driver's individual de-initialization functions.
 */
static void MemAcc_DeinitMemDrivers(void)
{
    uint32 Index;

    for (Index = 0U; Index < MemAcc_pConfigPtr->MemApiCount; Index++)
    {
        if(MemAcc_pConfigPtr->MemApisInvocation[Index] == MEMACC_MEM_INDIRECT_STATIC)
        {
            /* Perform the de-initialization of Mem drivers with INDIRECT_STATIC type */
            MemAcc_pConfigPtr->MemApis[Index].DeInitFunc();
        }
    }
    /* MemAcc_DeActivateMem is needed for Mem drivers with INDIRECT_DYNAMIC type */
}


/**
* @brief    Search the list of MemAcc address areas and returns index of the one with matching AddressAreaId
*/
static uint16 MemAcc_GetAddressAreaIndex(const MemAcc_AddressAreaIdType AddressAreaId)
{
    const MemAcc_AddressAreaType *AddressArea = MemAcc_pConfigPtr->AddressAreas;  /* Point to the first address area */
    uint32 Index = 0U;

    /* Loop through all configured memory instances */
    do
    {
        if (AddressAreaId == AddressArea->AreaId)
        {
            /* AddressAreaId is matched, exit loop */
            break;
        }

        /* Move to the next area */
        AddressArea++;
        Index++;
    }
    while (Index < MEMACC_ADDRESS_AREA_COUNT);

    if (MEMACC_ADDRESS_AREA_COUNT == Index)
    {
        Index = (uint32)MEMACC_ADDRESS_AREA_INDEX_INVALID;
    }
    /* The returned value will be "AddressAreaCount" if AddressAreaId is not matched with any index */
    return (uint16)Index;
}


/**
* @brief    Search the list of MemAcc address subareas and returns index of the one with matching Logical address
*/
static uint16 MemAcc_GetAddressSubAreaIndex
(
    const MemAcc_AddressAreaType    *AddressArea,
    MemAcc_AddressType               LogicalAddress
)
{
    const MemAcc_SubAddressAreaType  *SubArea = AddressArea->SubAreas;
    MemAcc_AddressType Offset = LogicalAddress;
    uint16 Index = 0U;

    /* Loop through all configured sub areas of this address area */
    do
    {
        if (Offset < SubArea->Length)
        {
            /* The address falls within this sub area */
            break;
        }

        /* Move to the next sub area */
        Offset -= SubArea->Length;
        SubArea++;
        Index++;
    }
    while (Index < AddressArea->SubAreaCount);

    return Index;
}

/**
 * @brief    Search for the sub address area that contains the provided logical address
 *
 */
static const MemAcc_SubAddressAreaType * MemAcc_GetSubAddressArea
(
    const MemAcc_AddressAreaType    *AddressArea,
    MemAcc_AddressType               LogicalAddress
)
{
    const MemAcc_SubAddressAreaType  *SubArea = AddressArea->SubAreas;
    MemAcc_AddressType Offset = LogicalAddress;
    uint32 Index = 0U;

    /* Loop through all configured sub areas of this address area */
    do
    {
        if (Offset < SubArea->Length)
        {
            /* The address falls within this sub area */
            break;
        }
        /*Update offset value*/
        Offset -= SubArea->Length;

        /* Move to the next sub area */
        SubArea++;
        Index++;
    }
    while (Index < AddressArea->SubAreaCount);

    return SubArea;
}


/**
 * @brief    Search for the sub address area that contains the Hw_Id
 *           Use in MemAcc_HwSpecificService API
 */
static const MemAcc_SubAddressAreaType * MemAcc_GetSubAddressAreaByHwId
(
    const MemAcc_AddressAreaType    *AddressArea,
    MemAcc_HwIdType                  HwId
)
{
    const MemAcc_SubAddressAreaType  *SubArea = AddressArea->SubAreas;
    uint32 Index = 0U;

    /* Loop through all configured sub areas of this address area */
    do
    {
        if (HwId == SubArea->Hw_Id)
        {
            /* The HwId falls within this sub area */
            break;
        }

        /* Move to the next sub area */
        SubArea++;
        Index++;
    }
    while (Index < AddressArea->SubAreaCount);

    if (Index >= AddressArea->SubAreaCount)
    {
        SubArea = NULL_PTR;
    }

    return SubArea;
}


/*
 * Description:    Translate the logical address to the according physical one
*/
static void MemAcc_RebasePhysicalAddress
(
    MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    /* Calculate the offset */
    MemAcc_AddressType Offset = JobInfo->LogicAddress - JobInfo->SubArea->LogicalStartAddress;
    /* Translate to physical address */
    JobInfo->PhysicAddress = JobInfo->SubArea->PhysicalStartAddress + Offset;
}


/*
 * Description:    Get the memory access request size for the Mem driver layer.
 *                 And get the number of retries of a failed job.
*/
static void MemAcc_GetMemAccessInfo
(
    MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    /* Initialize with default value */
    MemAcc_LengthType PhysicalSegmentSize = 0U;
    uint8 NumOfRetries = 0U;

    /* Get the according physical segmentation */
    switch (JobInfo->JobType)
    {
        case MEMACC_ERASE_JOB:
            NumOfRetries = JobInfo->SubArea->NumOfEraseRetries;

            PhysicalSegmentSize = JobInfo->SubArea->MemSectorBatchInfo.SectorSize;
            if ((JobInfo->SubArea->BurstSettings & MEMACC_BURST_ERASE) != 0U)
            {
                /* Use burst erase */
                PhysicalSegmentSize = JobInfo->SubArea->MemSectorBatchInfo.EraseBurstSize;
            }
            break;

        case MEMACC_WRITE_JOB:
            NumOfRetries = JobInfo->SubArea->NumOfWriteRetries;

            PhysicalSegmentSize = JobInfo->SubArea->MemSectorBatchInfo.WritePageSize;
            if ((JobInfo->SubArea->BurstSettings & MEMACC_BURST_WRITE) != 0U)
            {
                /* Use burst write */
                PhysicalSegmentSize = JobInfo->SubArea->MemSectorBatchInfo.WriteBurstSize;
            }
            break;

        case MEMACC_READ_JOB:
        case MEMACC_COMPARE_JOB:
        case MEMACC_BLANKCHECK_JOB:
            PhysicalSegmentSize = JobInfo->SubArea->MemSectorBatchInfo.ReadPageSize;
            if ((JobInfo->SubArea->BurstSettings & MEMACC_BURST_READ) != 0U)
            {
                /* Use burst read */
                PhysicalSegmentSize = JobInfo->SubArea->MemSectorBatchInfo.ReadBurstSize;
            }
            break;

        default:
            /* Do nothing */
            break;
    }

    /* Save to runtime information */
    JobInfo->LengthChunk = PhysicalSegmentSize;
    JobInfo->JobRetries  = NumOfRetries;
}


/*
 * Description:    Update job runtime information according to the new sub area
 *                 Obtain the physical characteristics information from the according sector batch
 */
static void MemAcc_JobRenewSubArea
(
    MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    /* Translate logical address to physical address according to the current sub area */
    MemAcc_RebasePhysicalAddress(JobInfo);

    /* Get the memory access size and the number of retries */
    MemAcc_GetMemAccessInfo(JobInfo);
}

#if (MEMACC_DEV_ERROR_DETECT == STD_ON)

/**
 * @brief    Get the according physical segmentation for this job
 */
static MemAcc_LengthType MemAcc_GetPhysicalSegmentSize
(
    const MemAcc_JobRuntimeInfoType *JobRequest
)
{
    MemAcc_LengthType PhysicalSegmentSize;

    /* Get the according physical segmentation */
    switch (JobRequest->JobType)
    {
        case MEMACC_ERASE_JOB:
            PhysicalSegmentSize = JobRequest->SubArea->MemSectorBatchInfo.SectorSize;
            break;

        case MEMACC_WRITE_JOB:
            PhysicalSegmentSize = JobRequest->SubArea->MemSectorBatchInfo.WritePageSize;
            break;

        case MEMACC_READ_JOB:
        case MEMACC_COMPARE_JOB:
        case MEMACC_BLANKCHECK_JOB:
            PhysicalSegmentSize = JobRequest->SubArea->MemSectorBatchInfo.ReadPageSize;
            break;

        case MEMACC_REQUESTLOCK_JOB:
            /*Don't need alignment for locking*/
            PhysicalSegmentSize = 1U;
            break;
        default:
            /* Do nothing */
            PhysicalSegmentSize = 0U;
            break;
    }

    return PhysicalSegmentSize;
}

/**
 * @brief    Checks if the MemAcc module has been initialized.
 */
static inline uint32 MemAcc_ValidateModuleInitialized(void)
{
    uint32 ErrorId = MEMACC_E_OK;

    /* Only check if development error detection is enabled */
    if (NULL_PTR == MemAcc_pConfigPtr)
    {
        /* The MemAcc module has not been initialized */
        ErrorId = MEMACC_E_UNINIT;
    }

    return ErrorId;
}

/**
 * @brief    Checks if the provided address and length are aligned with the physical segmentation size.
 */
static uint32 MemAcc_ValidateAlignment(MemAcc_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId = MEMACC_E_OK;
    MemAcc_LengthType PhysicalSegmentSize;
    const MemAcc_AddressAreaType *AddressArea = &( MemAcc_pConfigPtr->AddressAreas[JobRequest->AreaIndex] );

    /* Check alignment with the subarea include the LogicAddress + LengthOrigin (the last subarea of this job) */

    /* Find the last sub address area of the job (according to the start logical address and LengthOrigin) */
    JobRequest->SubArea = MemAcc_GetSubAddressArea(AddressArea, JobRequest->LogicAddress + JobRequest->LengthOrigin - 1U);
    
    /* Get the according physical segmentation for this job */
    PhysicalSegmentSize = MemAcc_GetPhysicalSegmentSize(JobRequest);

    /* Alignment checking */
    if ( (PhysicalSegmentSize == 0U) || \
        (((JobRequest->LogicAddress + JobRequest->LengthOrigin - JobRequest->SubArea->LogicalStartAddress) % PhysicalSegmentSize) != 0U) \
    )
    {
        /* Not aligned to the physical memory segmentation */
        ErrorId = MEMACC_E_PARAM_ADDRESS_LENGTH;
    }

    if(ErrorId == MEMACC_E_OK)
    {
        /* Check alignment with the subarea include the LogicAddress (the first subarea of this job) */

        /* Find the first sub address area of the job (according to the start logical address) */
        JobRequest->SubArea = MemAcc_GetSubAddressArea(AddressArea, JobRequest->LogicAddress);

        /* Get the according physical segmentation for this job */
        PhysicalSegmentSize = MemAcc_GetPhysicalSegmentSize(JobRequest);

        /* Alignment checking */
        if ( (PhysicalSegmentSize == 0U) || \
            (((JobRequest->LogicAddress - JobRequest->SubArea->LogicalStartAddress) % PhysicalSegmentSize) != 0U) \
        )
        {
            /* Not aligned to the physical memory segmentation */
            ErrorId = MEMACC_E_PARAM_ADDRESS_LENGTH;
        }
    }

    return ErrorId;
}

/**
 * @brief    Checks if the provided address and length are in valid range
 */
static uint32 MemAcc_ValidateRange
(
    const MemAcc_JobRuntimeInfoType    *JobRequest,
    MemAcc_LengthType             AddressAreaLength
)
{
    uint32 ErrorId = MEMACC_E_OK;

    /* Range checking */
    if (
         (JobRequest->LogicAddress >= AddressAreaLength) || \
         (0U == JobRequest->LengthOrigin) || \
         ((JobRequest->LogicAddress + JobRequest->LengthOrigin) > AddressAreaLength) \
       )
    {
        /* Out of range */
        ErrorId = MEMACC_E_PARAM_ADDRESS_LENGTH;
    }

    return ErrorId;
}

/**
 * @brief    Checks if the input argument is a NULL pointer.
 */
static inline uint32 MemAcc_ValidateDataPointer(const MemAcc_DataType *DataPtr)
{
    uint32 ErrorId = MEMACC_E_OK;

    if (NULL_PTR == DataPtr)
    {
        /* The DataPtr argument is a NULL pointer */
        ErrorId = MEMACC_E_PARAM_POINTER;
    }

    return ErrorId;
}

/**
 * @brief    Check availability and consistency of the delimiter field
 */
static uint32 MemAcc_ValidateMemDriverBinaryDelimiterField
(
    const MemAcc_MemDriverHeaderType  *MemDriverHeaderPtr
)
{
    uint32 ErrorId = MEMACC_E_OK;
    const MemAcc_MemDriverUniqueIDType *MemDriverDelimiter;

    if(MemDriverHeaderPtr->Flags.RelocatableBinary != MEMACC_MEMDRIVER_RELOCATABLE_BINARY)
    {
        if(MemDriverHeaderPtr->DelimiterAddress == 0U)
        {
            ErrorId = MEMACC_E_MEM_INIT_FAILED;
        }
        else
        {
            MemDriverDelimiter = (MemAcc_MemDriverUniqueIDType *)((MemAcc_UintPtrType)MemDriverHeaderPtr->DelimiterAddress);
            if(MemDriverDelimiter->ABIVersion != MEMACC_MEMDRIVER_ABI_VERSION)
            {
                ErrorId = MEMACC_E_MEM_INIT_FAILED;
            }
            else if(MemDriverDelimiter->VendorID != MemDriverHeaderPtr->UniqueID.VendorID)
            {
                ErrorId = MEMACC_E_MEM_INIT_FAILED;
            }
            else if(MemDriverDelimiter->DriverID != MemDriverHeaderPtr->UniqueID.DriverID)
            {
                ErrorId = MEMACC_E_MEM_INIT_FAILED;
            }
            else
            {
                /*Empty clause*/
            }
        }
    }
    else
    {
        if(MemDriverHeaderPtr->DelimiterAddress != 0U)
        {
            ErrorId = MEMACC_E_MEM_INIT_FAILED;
        }
    }
    return ErrorId;
}
/**
 * @brief    Check if the Mem driver binary is consistent
 */
static uint32 MemAcc_ValidateMemDriverBinary
(
    MemAcc_AddressType    HeaderAddress,
    MemAcc_HwIdType       HwId
)
{
    uint32 ErrorId = MEMACC_E_OK;
    const MemAcc_MemDriverHeaderType  *MemDriverHeader = (MemAcc_MemDriverHeaderType *)((MemAcc_UintPtrType)HeaderAddress);
    /* Check HwId is valid */
    if(MemAcc_pConfigPtr->MemApiCount <= HwId)
    {
        ErrorId = MEMACC_E_MEM_INIT_FAILED;
    }

    /*Check Header address */
    if(MEMACC_E_OK == ErrorId)
    {
        if(MemDriverHeader->Flags.RelocatableBinary != MEMACC_MEMDRIVER_RELOCATABLE_BINARY)
        {
            if(MemDriverHeader->HeaderAddress != HeaderAddress)
            {
                ErrorId = MEMACC_E_MEM_INIT_FAILED;
            }
        }
    }

    /*Check ABI version of the Mem driver binary, It should be 0001 */
    if(MEMACC_E_OK == ErrorId)
    {
        if(MemDriverHeader->UniqueID.ABIVersion != MEMACC_MEMDRIVER_ABI_VERSION)
        {
            ErrorId = MEMACC_E_MEM_INIT_FAILED;
        }
    }

    /*Check Vendor ID of the Mem driver binary, it should be same with VendorID of the MemAcc driver*/
    if(MEMACC_E_OK == ErrorId)
    {
        if(MemDriverHeader->UniqueID.VendorID != (uint16)MEMACC_VENDOR_ID_C)
        {
            ErrorId = MEMACC_E_MEM_INIT_FAILED;
        }
    }
    /*Check availability and consistency of the delimiter field*/
    if(MEMACC_E_OK == ErrorId)
    {
        ErrorId = MemAcc_ValidateMemDriverBinaryDelimiterField(MemDriverHeader);
    }

    return ErrorId;
}
#endif  /*#if (MEMACC_DEV_ERROR_DETECT == STD_ON)*/

/**
 * @brief    Checks if the provided address and length are valid (both range and alignment)
 */
static uint32 MemAcc_ValidateAddressAndLength(MemAcc_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;
    const MemAcc_AddressAreaType *AddressArea = &( MemAcc_pConfigPtr->AddressAreas[JobRequest->AreaIndex] );

#if (MEMACC_DEV_ERROR_DETECT == STD_ON)
    /* Range checking */
    ErrorId = MemAcc_ValidateRange(JobRequest, AddressArea->Length);

    if (MEMACC_E_OK == ErrorId)
    {
#else
        ErrorId = MEMACC_E_OK;

        /* Find the first sub address area of the job (according to the start logical address) */
        JobRequest->SubArea = MemAcc_GetSubAddressArea(AddressArea, JobRequest->LogicAddress);
#endif

#if (MEMACC_DEV_ERROR_DETECT == STD_ON)
        /* Alignment checking */
        ErrorId = MemAcc_ValidateAlignment(JobRequest);
    }
#endif

    return ErrorId;
}

/**
 * @brief    Common checks of input parameters for driver APIs.
 */
static uint32 MemAcc_SetParamJobCommon(MemAcc_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

#if (MEMACC_DEV_ERROR_DETECT == STD_ON)
    /* Checks if the MemAcc module has been initialized */
    ErrorId = MemAcc_ValidateModuleInitialized();

    if (MEMACC_E_OK == ErrorId)
    {
#endif
        /* Get the index number of this address area */
        JobRequest->AreaIndex = MemAcc_GetAddressAreaIndex(JobRequest->AreaId);
#if (MEMACC_DEV_ERROR_DETECT == STD_ON)
        /* Only check if development error detection is enabled */
        if (MEMACC_ADDRESS_AREA_INDEX_INVALID == JobRequest->AreaIndex)
        {
            /* The provided AddressAreaId is inconsistent with the configuration */
            ErrorId = MEMACC_E_PARAM_ADDRESS_AREA_ID;
        }
    }

    if (MEMACC_E_OK == ErrorId)
    {
#endif
        /* Check if the address and the length are valid */
        ErrorId = MemAcc_ValidateAddressAndLength(JobRequest);

#if (MEMACC_DEV_ERROR_DETECT == STD_ON)
    }
#endif

    return ErrorId;
}

/**
 * @brief    Checks the input parameters for data transfer jobs (read, write, compare)
 */
static uint32 MemAcc_SetParamJobDataTransfer(MemAcc_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;

    /* Set param and perform the common checking */
    ErrorId = MemAcc_SetParamJobCommon(JobRequest);

#if (MEMACC_DEV_ERROR_DETECT == STD_ON)
    /* Perform the specific checking */
    if (MEMACC_E_OK == ErrorId)
    {
        ErrorId = MemAcc_ValidateDataPointer(JobRequest->DataPtr);
    }
#endif
    return ErrorId;
}

/**
 * @brief    Initialize the input parameter for the new job request
 */
static void MemAcc_InitJobRequest(
    MemAcc_JobRuntimeInfoType    *JobRequest,
    MemAcc_AddressAreaIdType      AreaId,
    MemAcc_AddressType            LogicAddress,
    MemAcc_DataType              *DataPtr,
    MemAcc_LengthType             Length
)
{
    /* Input value */
    JobRequest->AreaId           = AreaId;
    JobRequest->LogicAddress     = LogicAddress;
    JobRequest->DataPtr          = DataPtr;
    JobRequest->LengthOrigin     = Length;
    JobRequest->LengthRemain     = Length;
    /* Initial value */
    JobRequest->AreaIndex        = MEMACC_ADDRESS_AREA_INDEX_INVALID;
    JobRequest->SubArea          = NULL_PTR;
    JobRequest->JobResult        = MEMACC_MEM_OK;
    JobRequest->LengthChunk      = 0U;
    JobRequest->JobRetries       = 0U;
    JobRequest->PhysicAddress    = 0U;
    JobRequest->MemHwServiceId   = 0U;
    JobRequest->LengthPtr        = NULL_PTR;
    /*Init lock information*/
    JobRequest->LockStatus       = MEMACC_UNLOCK;
    JobRequest->LockAddress      = 0U;
    JobRequest->LockLength       = 0U;
    JobRequest->LockNotif        = NULL_PTR;
    JobRequest->JobLocked        = (boolean)FALSE;
    /* Prepare for a new job */
    JobRequest->JobStatus        = MEMACC_JOB_PENDING;
    JobRequest->JobState         = MEMACC_JOB_STATE_STARTING;
}

static boolean MemAcc_CheckLockArea(const MemAcc_JobRuntimeInfoType *JobRequest)
{
    const MemAcc_JobRuntimeInfoType *JobCurrent = &MemAcc_pJobRuntimeInfo[JobRequest->AreaIndex];
    MemAcc_AddressType RequestedStart     = JobRequest->LogicAddress;
    MemAcc_AddressType RequestedEnd       = JobRequest->LogicAddress + JobRequest->LengthOrigin;
    MemAcc_AddressType LockedStart        = JobCurrent->LockAddress;
    MemAcc_AddressType LockedEnd          = JobCurrent->LockAddress + JobCurrent->LockLength;
    boolean RetVal = (boolean)FALSE;

    if(JobCurrent->LockStatus == MEMACC_LOCKED)
    {
        /*Check if the requested area is on locked area*/
        /*1. requested start address is on locked area: Requested start address >= Locked start address and < Locked end address */
        /*2. requested end address is on locked area: Requested end address > Locked start address and <= Locked end address */
        /*3. requested area is contained by locked area: Requested start address > Locked start address and Requested end address < Locked end address */
        /*4. requested area contains locked area: Requested start address < Locked start address and Requested end address > Locked end address */
        if(((RequestedStart >= LockedStart) && (RequestedStart <  LockedEnd)) || \
           ((RequestedEnd   >  LockedStart) && (RequestedEnd   <= LockedEnd)) || \
           ((RequestedStart >  LockedStart) && (RequestedEnd   <  LockedEnd)) || \
           ((LockedStart >  RequestedStart) && (LockedEnd   <  RequestedEnd)) \
          )
        {
            RetVal = (boolean)TRUE;
        }
    }
    return RetVal;
}
/**
 * @brief    Check if the address area is idle and configure the new job request
 */
static uint32 MemAcc_ConfigureJobRequest(MemAcc_JobRuntimeInfoType *JobRequest)
{
    uint32 ErrorId;
    const MemAcc_JobRuntimeInfoType *JobCurrent = &MemAcc_pJobRuntimeInfo[JobRequest->AreaIndex];

    if (MEMACC_JOB_PENDING == JobCurrent->JobStatus)
    {
        /* A previous job is still being processed or queued */
        ErrorId = MEMACC_E_BUSY;
    }
    else
    {
        if(JobCurrent->LockStatus == MEMACC_LOCKED)
        {
            /*Restore lock information*/
            JobRequest->LockAddress = JobCurrent->LockAddress;
            JobRequest->LockLength  = JobCurrent->LockLength;
            JobRequest->LockStatus  = JobCurrent->LockStatus;
            JobRequest->LockNotif  = JobCurrent->LockNotif;
            if((boolean)TRUE == MemAcc_CheckLockArea(JobRequest))
            {
                JobRequest->JobLocked = (boolean)TRUE;
            }
            else
            {
                JobRequest->JobLocked = (boolean)FALSE;
            }
        }

        /* Accept the requested job */
        ErrorId = MEMACC_E_OK;
        /* Configure the new job */
        MemAcc_pJobRuntimeInfo[JobRequest->AreaIndex] = *JobRequest;
    }

    return ErrorId;
}


/*==================================================================================================
                                       MEM RELATED FUNCTIONS
==================================================================================================*/

/**
 * @brief   Erase flash data via Mem driver
 **/
static Std_ReturnType MemAcc_CallMemErase
(
    const MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    MemAcc_MemEraseFuncType EraseFunc = JobInfo->SubArea->MemApi->EraseFunc;
    Std_ReturnType RetVal;

    /* Call Mem erase service */
    RetVal = EraseFunc(JobInfo->SubArea->MemInstanceId, JobInfo->PhysicAddress, JobInfo->LengthChunk);
    return RetVal;
}

/**
 * @brief   HW specific service via Mem driver
 **/
static Std_ReturnType MemAcc_CallMemHwSpecificService(
    const MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    MemAcc_MemHwSpecificServiceFuncType MemHwSpecificServiceFunc  = JobInfo->SubArea->MemApi->HwSpecificServiceFunc;
    Std_ReturnType RetVal;

    /* Call Mem Hw Specific Service */
    RetVal = MemHwSpecificServiceFunc(JobInfo->SubArea->MemInstanceId, JobInfo->MemHwServiceId, JobInfo->DataPtr, JobInfo->LengthPtr);
    return RetVal;
}


/**
 * @brief   Read flash data via Mem driver
 **/
static Std_ReturnType MemAcc_CallMemRead(
    const MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    MemAcc_MemReadFuncType ReadFunc  = JobInfo->SubArea->MemApi->ReadFunc;
    Std_ReturnType RetVal;

    /* Call Mem read service */
    RetVal = ReadFunc(JobInfo->SubArea->MemInstanceId, JobInfo->PhysicAddress, JobInfo->DataPtr, JobInfo->LengthChunk);
    return RetVal;
}

#if (MEMACC_COMPARE_API == STD_ON)
/**
 * @brief   Compare flash data via Mem driver
 **/
static Std_ReturnType MemAcc_CallMemCompare
(
    const MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    MemAcc_MemReadFuncType ReadFunc  = JobInfo->SubArea->MemApi->ReadFunc;
    Std_ReturnType RetVal;

    /* Call Mem read service */
    RetVal = ReadFunc(JobInfo->SubArea->MemInstanceId, JobInfo->PhysicAddress, (MemAcc_DataType *)MemAcc_Compare_Buffer, JobInfo->LengthChunk);
    return RetVal;
}
#endif


/**
 * @brief   Blankcheck flash data via Mem driver
 **/
static Std_ReturnType MemAcc_CallMemBlankCheck
(
    const MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    MemAcc_MemBlankCheckFuncType BlankCheckFunc = JobInfo->SubArea->MemApi->BlankCheckFunc;
    Std_ReturnType RetVal;

    /* Call Mem BlankCheck service */
    RetVal = BlankCheckFunc(JobInfo->SubArea->MemInstanceId, JobInfo->PhysicAddress, JobInfo->LengthChunk);
    return RetVal;
}


/**
 * @brief   Write flash data via Mem driver
 **/
static Std_ReturnType MemAcc_CallMemWrite
(
    const MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    MemAcc_MemWriteFuncType WriteFunc = JobInfo->SubArea->MemApi->WriteFunc;
    Std_ReturnType RetVal;

    /* Call Mem BlankCheck service */
    RetVal = (Std_ReturnType)WriteFunc(JobInfo->SubArea->MemInstanceId, JobInfo->PhysicAddress, JobInfo->DataPtr, JobInfo->LengthChunk);
    return RetVal;
}


/**
 * @brief    Get the asynchronous result job being processed by Mem driver
 **/
static MemAcc_MemJobResultType MemAcc_GetMemJobResult
(
    const MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    MemAcc_MemGetJobResultFuncType GetJobResultFunc = JobInfo->SubArea->MemApi->GetJobResultFunc;
    MemAcc_MemJobResultType MemJobResult;

    /* Get the job result from Mem driver */
    MemJobResult = GetJobResultFunc(JobInfo->SubArea->MemInstanceId);
    return MemJobResult;
}


/*==================================================================================================
                                       JOB PROCESSING SUB FUNCTIONS
==================================================================================================*/

/*
 * Description:    Resolve the HW resource conflicting based on address area priority
*/
static void MemAcc_ResolveConflictMemHwResource
(
    const uint16 AreaExecuting,
    const uint16 AreaRequesting
)
{
    MemAcc_JobRuntimeInfoType *JobExecuting = &(MemAcc_pJobRuntimeInfo[AreaExecuting]);

    /* Preemption will only be performed if the requesting job has a
       priority that is higher than the currently executing job
     */
    if (MemAcc_pConfigPtr->AddressAreas[AreaRequesting].Priority > MemAcc_pConfigPtr->AddressAreas[AreaExecuting].Priority)
    {
        /* Suspend the address area with lower priority */
        if (JobExecuting->JobState == MEMACC_JOB_STATE_RETRYING)
        {
            /* Special treatment if the job is in RETRY state */
            if (JobExecuting->JobRetries > 0U)
            {
                JobExecuting->JobRetries--;
                /* Move to RESUME state directly, SUSPEND is not needed */
                JobExecuting->JobState = MEMACC_JOB_STATE_RESUMING;
            }
            else
            {
                /* All attempts have failed, stop the job immediately */
                JobExecuting->JobState = MEMACC_JOB_STATE_STOP;
            }
        }
        else
        {
            /* Suspending the job */
            JobExecuting->JobState = MEMACC_JOB_STATE_SUSPENDING;
        }
    }
}


/*
 * Description:    Request the according Mem hardware resource for the incoming operation
*/
static boolean MemAcc_RequestMemHwResource
(
    const MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    boolean HwResourceGranted   = (boolean)TRUE;
    const uint16 AreaRequesting = JobInfo->AreaIndex;                        /* The address area index number of current job    */
    const uint8  MemHwResource  = JobInfo->SubArea->MemHwResource;           /* The hardware resource is being used current job */
    const uint16 AreaExecuting  = MemAcc_au16MemHwResources[MemHwResource];  /* The address area is using the hardware resource */

    if (AreaExecuting == AreaRequesting)
    {
        /* The resource has already been occupied before */
    }
    else if (AreaExecuting == MEMACC_MEM_HW_RESOURCE_IDLE)
    {
        /* Take the resource resource */
        MemAcc_au16MemHwResources[MemHwResource] = AreaRequesting;
    }
    else
    {
        /* The resource is busy for another address area */
        HwResourceGranted = (boolean)FALSE;
        /* Try to resolve the HW resource conflicting based on address area priority */
        MemAcc_ResolveConflictMemHwResource(AreaExecuting, AreaRequesting);
    }

    return HwResourceGranted;
}

/*
 * Description:    Release the according Mem hardware resource for a completed job
*/
static void MemAcc_ReleaseMemHwResource
(
    const uint8    MemHwResource
)
{
    /* Mark the HW resource as idle */
    MemAcc_au16MemHwResources[MemHwResource] = MEMACC_MEM_HW_RESOURCE_IDLE;
}


/*
 * Description:    Check for changing of HW resources when crossing sub address areas
*/
static boolean MemAcc_RenewMemHwResource
(
    const MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    boolean HwResourceGranted = (boolean)TRUE;
    const uint8 PreviousHwResource = JobInfo->SubArea[-1].MemHwResource;
    const uint8 CurrentHwResource  = JobInfo->SubArea[ 0].MemHwResource;

    /* Check for changing of HW resources */
    if (PreviousHwResource != CurrentHwResource)
    {
        /* Different HW resource, release the previous one and request for the new one */
        MemAcc_ReleaseMemHwResource(PreviousHwResource);
        /* Request the new HW resource */
        HwResourceGranted = MemAcc_RequestMemHwResource(JobInfo);
    }

    return HwResourceGranted;
}


/**
 * @brief    Update the remaining length of the job
 **/
static void MemAcc_UpdateProcessedLength
(
    MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    const MemAcc_LengthType LengthChunk = JobInfo->LengthChunk;

    /* Update job runtime information, move to the next chunk */
    JobInfo->LogicAddress  += LengthChunk;
    JobInfo->PhysicAddress += LengthChunk;
    JobInfo->LengthRemain  -= LengthChunk;

    if (NULL_PTR != JobInfo->DataPtr)
    {
        JobInfo->DataPtr = &(JobInfo->DataPtr[LengthChunk]);
    }
}


/**
 * @brief    Check if the job has crossed the sub address area boundary
 **/
static boolean MemAcc_JobCrossSubAreaBoundary
(
    MemAcc_JobRuntimeInfoType    *JobInfo
)
{
    boolean RetVal = FALSE;

    if (JobInfo->LogicAddress >= (JobInfo->SubArea->LogicalStartAddress + JobInfo->SubArea->Length))
    {
        /* Move on to the next sub area */
        JobInfo->SubArea++;
        MemAcc_JobRenewSubArea(JobInfo);

        /* The current sub area has been processed */
        RetVal = TRUE;
    }

    return RetVal;
}


/**
 * @brief    If a job end notification function is configured by MemAccJobEndNotificationName
 *           MemAcc shall notify the upper layer BSW module by calling the configured notification function.
 **/
static void MemAcc_JobEndNotify( const MemAcc_JobRuntimeInfoType  *JobInfo )
{
    const MemAcc_AddressAreaType         *AddressArea     = &( MemAcc_pConfigPtr->AddressAreas[JobInfo->AreaIndex] );
    MemAcc_AddressAreaJobEndNotification  JobEndNotifFunc = AddressArea->JobEndNotif;

    if (NULL_PTR != JobEndNotifFunc)
    {
        /* Call the notification function */
        JobEndNotifFunc(JobInfo->AreaId, JobInfo->JobResult);
    }
}


/*
 * Description:    Call the according Mem service API to serve the job operation
*/
static void MemAcc_JobRequestMemService( MemAcc_JobRuntimeInfoType *JobInfo )
{
    Std_ReturnType RequestStatus = (Std_ReturnType)E_NOT_OK;

    /* Compute request length */
    if (JobInfo->LengthChunk > JobInfo->LengthRemain)
    {
        JobInfo->LengthChunk = JobInfo->LengthRemain;
    }

    switch (JobInfo->JobType)
    {
        case MEMACC_ERASE_JOB:
            RequestStatus = MemAcc_CallMemErase(JobInfo);
            break;

        case MEMACC_WRITE_JOB:
            RequestStatus = MemAcc_CallMemWrite(JobInfo);
            break;

        case MEMACC_BLANKCHECK_JOB:
            RequestStatus = MemAcc_CallMemBlankCheck(JobInfo);
            break;

        #if (MEMACC_COMPARE_API == STD_ON)
        case MEMACC_COMPARE_JOB:
            RequestStatus = MemAcc_CallMemCompare(JobInfo);
            break;
        #endif

        case MEMACC_READ_JOB:
            RequestStatus = MemAcc_CallMemRead(JobInfo);
            break;

        case MEMACC_MEMHWSPECIFIC_JOB:
            RequestStatus = MemAcc_CallMemHwSpecificService(JobInfo);
            break;

        default:
            /*Empty clause*/
            break;
    };

    if ((Std_ReturnType)E_OK == RequestStatus)
    {
        /* The request was accepted, go to processing state */
        JobInfo->JobState = MEMACC_JOB_STATE_PROCESSING;
    }
    else
    {
        /* The request was not accepted, try again */
        JobInfo->JobState = MEMACC_JOB_STATE_RETRYING;
        JobInfo->JobResult = MEMACC_MEM_FAILED;
    }
}

#if (MEMACC_COMPARE_API == STD_ON)
/*
 * Description:    Compare data.
*/
static boolean MemAcc_CompareCheckData(const MemAcc_DataType *SourcePtr, const MemAcc_DataType *DestPtr, MemAcc_LengthType length)
{
    uint32 counter;
    boolean retValue = (boolean)TRUE;
    for (counter = 0; counter < length; counter++)
    {
        if (SourcePtr[counter] != DestPtr[counter])
        {
            retValue = (boolean)FALSE;
            break;
        }
    }
    return retValue;
}
#endif


/*
 * Description:    Analyze the failure result from Mem driver layer
*/
static void MemAcc_JobAnalyzeFailureMemResult
(
    MemAcc_JobRuntimeInfoType    *JobInfo,
    MemAcc_MemJobResultType       MemJobResult
)
{
    switch (MemJobResult)
    {
        case MEM_JOB_FAILED:
            JobInfo->JobResult = MEMACC_MEM_FAILED;
            break;

        case MEM_INCONSISTENT:
            JobInfo->JobResult = MEMACC_MEM_INCONSISTENT;
            break;

        case MEM_ECC_UNCORRECTED:
            JobInfo->JobResult = MEMACC_MEM_ECC_UNCORRECTED;
            break;

        default:
            /* Do nothing */
            break;
    }
}


/**
 * @brief    Continue to process next chunk of job after the previous chunk has completed successfully.
 *
 **/
static void MemAcc_JobProcessingOnSuccess( MemAcc_JobRuntimeInfoType *JobInfo )
{
    boolean CrossSubArea;
    boolean HwResourceGranted = (boolean)TRUE;

#if (MEMACC_COMPARE_API == STD_ON)
    /* Compare data is implemented here */
    /* JobInfo->DataPtr: Pointer to the already user data, which is compared */
    /* MemAcc_Compare_Buffer: Pointer to the data buffer, which is read from memory */
    if (MEMACC_COMPARE_JOB == JobInfo->JobType)
    {
        if ((boolean)FALSE == MemAcc_CompareCheckData(JobInfo->DataPtr, (MemAcc_DataType *)MemAcc_Compare_Buffer, JobInfo->LengthChunk))
        {
            /* The job has failed, update the result and stop*/
            JobInfo->JobState = MEMACC_JOB_STATE_STOP;
            JobInfo->JobResult = MEMACC_MEM_INCONSISTENT;
        }
    }
#endif

    /* Update remaining length of the job */
    MemAcc_UpdateProcessedLength(JobInfo);

    if (0U == JobInfo->LengthRemain)
    {
        /* The job has been completed successfully */
        JobInfo->JobState = MEMACC_JOB_STATE_STOP;
    }
    else
    {
        /* Check for ending of logical sub area boundary */
        CrossSubArea = MemAcc_JobCrossSubAreaBoundary(JobInfo);
        if ((boolean)TRUE == CrossSubArea)
        {
            HwResourceGranted = MemAcc_RenewMemHwResource(JobInfo);
            if ((boolean)FALSE == HwResourceGranted)
            {
                /* The new HW resource is not ready yet, temporarily stop the job */
                JobInfo->JobState = MEMACC_JOB_STATE_RESUMING;
            }
        }

        if ((boolean)TRUE == HwResourceGranted)
        {
            /* The HW is still available, keep processing the job */
            MemAcc_JobRequestMemService(JobInfo);
        }
    }
}


/*
 * Description:    Suspend the job after a success of a chunk
*/
static void MemAcc_JobSuspendingOnSuccess( MemAcc_JobRuntimeInfoType    *JobInfo )
{
    /* Update remaining length of the job */
    MemAcc_UpdateProcessedLength(JobInfo);

    if (0U == JobInfo->LengthRemain)
    {
        /* The job has been completed successfully */
        JobInfo->JobState = MEMACC_JOB_STATE_STOP;
    }
    else
    {
        /* Release the hardware resource */
        MemAcc_ReleaseMemHwResource(JobInfo->SubArea->MemHwResource);

        /* Check for ending of logical sub area boundary */
        (void)MemAcc_JobCrossSubAreaBoundary(JobInfo);

        /* The job is suspended */
        JobInfo->JobState = MEMACC_JOB_STATE_RESUMING;
    }
}


/*
 * Description:    Suspend the job after a failure of a chunk
*/
static void MemAcc_JobSuspendingOnFailure
(
    MemAcc_JobRuntimeInfoType    *JobInfo,
    MemAcc_MemJobResultType       MemJobResult
)
{
    MemAcc_JobAnalyzeFailureMemResult(JobInfo, MemJobResult);

    /* The chunk has failed */
    if (JobInfo->JobRetries > 0U)
    {
        JobInfo->JobRetries--;

        /* Release the hardware resource */
        MemAcc_ReleaseMemHwResource(JobInfo->SubArea->MemHwResource);

        JobInfo->JobState = MEMACC_JOB_STATE_RESUMING;
    }
    else
    {
        /* All attempts have failed, stop the job */
        JobInfo->JobState = MEMACC_JOB_STATE_STOP;
    }
}


/*==================================================================================================
                                       JOB SCHEDULE FUNCTIONS
==================================================================================================*/

/**
 * @brief    Process the requested job for the address area
 **/
static void MemAcc_JobStarting( MemAcc_JobRuntimeInfoType *JobInfo )
{
    boolean HwResourceGranted;

    HwResourceGranted = MemAcc_RequestMemHwResource(JobInfo);
    if ((boolean)TRUE == HwResourceGranted)
    {
        /* Get information from the first sub area */
        MemAcc_JobRenewSubArea(JobInfo);

        /* Call the according Mem service API for the job */
        MemAcc_JobRequestMemService(JobInfo);
    }
    else
    {
        /* The HW resource is busy */
        /* TODO: check for timeout, if timeout then stop the job */
    }
}


/**
 * @brief    Process the requested job for the address area
 **/
static void MemAcc_JobProcessing( MemAcc_JobRuntimeInfoType *JobInfo )
{
    MemAcc_MemJobResultType MemJobResult;

    /* Check the status of the job is being processed in the Mem driver */
    MemJobResult = MemAcc_GetMemJobResult(JobInfo);
    switch (MemJobResult)
    {
        case MEM_JOB_OK:
            /* The previous chunk job has been processed successfully, launch new operation */
            MemAcc_JobProcessingOnSuccess(JobInfo);
            break;

        case MEM_ECC_CORRECTED:
            /* The previous chunk job has been processed successfully with ECC corrected, launch new operation */
            MemAcc_JobProcessingOnSuccess(JobInfo);
            /* In the last memory operation, the job result shall be set to MEMACC_MEM_ECC_CORRECTED*/
            if (0U == JobInfo->LengthRemain)
            {
                JobInfo->JobResult = MEMACC_MEM_ECC_CORRECTED;
            }
            break;

        case MEM_JOB_PENDING:
            /* The operation is still pending */
            /* TODO: check for operation timeout */
            break;

        default:
            /* The job has failed, update the result and try again */
            MemAcc_JobAnalyzeFailureMemResult(JobInfo, MemJobResult);
            JobInfo->JobState = MEMACC_JOB_STATE_RETRYING;
            break;
    }
}


/**
 * @brief    Process for failure jobs
 **/
static void MemAcc_JobRetrying( MemAcc_JobRuntimeInfoType *JobInfo )
{
    /* Check for retries */
    if (JobInfo->JobRetries > 0U)
    {
        JobInfo->JobRetries--;

        /* Try again with the same previous request */
        MemAcc_JobRequestMemService(JobInfo);
    }
    else
    {
        /* All attempts have failed, stop the job and keep result of the most recent retry*/
        JobInfo->JobState = MEMACC_JOB_STATE_STOP;
    }
}


/**
 * @brief    Suspending a job
 **/
static void MemAcc_JobSuspending( MemAcc_JobRuntimeInfoType *JobInfo )
{
    MemAcc_MemJobResultType MemJobResult;

    /* Check the status of the job is being processed in the Mem driver */
    MemJobResult = MemAcc_GetMemJobResult(JobInfo);
    switch (MemJobResult)
    {
        case MEM_JOB_OK:
            MemAcc_JobSuspendingOnSuccess(JobInfo);
            break;

        case MEM_ECC_CORRECTED:
            MemAcc_JobSuspendingOnSuccess(JobInfo);
            /* In the last memory operation, the job result shall be set to MEMACC_MEM_ECC_CORRECTED*/
            if (0U == JobInfo->LengthRemain)
            {
                JobInfo->JobResult = MEMACC_MEM_ECC_CORRECTED;
            }
            break;

        case MEM_JOB_PENDING:
            /* The operation is still pending */
            break;

        default:  /* failure cases */
            MemAcc_JobSuspendingOnFailure(JobInfo, MemJobResult);
            break;
    }
}


/**
 * @brief    Try to request the Mem hardware resource to continue processing the job
 **/
static void MemAcc_JobResuming( MemAcc_JobRuntimeInfoType *JobInfo )
{
    boolean HwResourceGranted;

    HwResourceGranted = MemAcc_RequestMemHwResource(JobInfo);
    if ((boolean)TRUE == HwResourceGranted)
    {
        /* Continue to process the job */
        MemAcc_JobRequestMemService(JobInfo);
    }
}

/**
 * @brief    Try to request the Mem hardware resource to canceling the job
 **/
static void MemAcc_JobCanceling( MemAcc_JobRuntimeInfoType *JobInfo )
{
    MemAcc_MemJobResultType MemJobResult;

    /* Check the status of the job is being processed in the Mem driver */
    MemJobResult = MemAcc_GetMemJobResult(JobInfo);

    switch (MemJobResult)
    {
        /* There are currently no jobs being processed */
        case MEM_JOB_OK:
        case MEM_ECC_CORRECTED:
            /* Update remaining length of the job */
            MemAcc_UpdateProcessedLength(JobInfo);
            /* Set Hw status to status cancelled*/
            JobInfo->JobState = MEMACC_JOB_STATE_STOP;
            JobInfo->JobStatus = MEMACC_JOB_IDLE;
            JobInfo->JobResult = MEMACC_MEM_CANCELED;
            break;
        case MEM_JOB_FAILED:
        case MEM_INCONSISTENT:
        case MEM_ECC_UNCORRECTED:
            /* Set Hw status to status cancelled*/
            JobInfo->JobState = MEMACC_JOB_STATE_STOP;
            JobInfo->JobStatus = MEMACC_JOB_IDLE;
            JobInfo->JobResult = MEMACC_MEM_CANCELED;
            break;
        /* A job is currently being processed */
        case MEM_JOB_PENDING:
        default:
            /* Do not thing */
            break;
    }
}

/**
 * @brief    Schedule the requested job
 **/
static void MemAcc_ScheduleJob( MemAcc_JobRuntimeInfoType *JobInfo )
{
    MemAcc_ApplicationLockNotification JobLockNotifFunc;

    switch (JobInfo->JobState)
    {
        case MEMACC_JOB_STATE_STARTING:
            MemAcc_JobStarting(JobInfo);
            break;

        case MEMACC_JOB_STATE_PROCESSING:
            MemAcc_JobProcessing(JobInfo);
            break;

        case MEMACC_JOB_STATE_RETRYING:
            MemAcc_JobRetrying(JobInfo);
            break;

        case MEMACC_JOB_STATE_SUSPENDING:
            MemAcc_JobSuspending(JobInfo);
            break;

        case MEMACC_JOB_STATE_RESUMING:
            MemAcc_JobResuming(JobInfo);
            break;

        case MEMACC_JOB_STATE_CANCELING:
            MemAcc_JobCanceling(JobInfo);
            break;

        default:
            /* Do nothing */
            break;
    }

    /* Check if the job has completed (either succeeded or failed) */
    if (MEMACC_JOB_STATE_STOP == JobInfo->JobState)
    {
        /* Release the hardware resource */
        MemAcc_ReleaseMemHwResource(JobInfo->SubArea->MemHwResource);

        /* Mark the job as idle */
        JobInfo->JobStatus = MEMACC_JOB_IDLE;
        /*perform lock Area*/
        if(JobInfo->LockStatus == MEMACC_LOCKING)
        {
            JobInfo->LockStatus = MEMACC_LOCKED;
            JobLockNotifFunc = JobInfo->LockNotif;
            JobLockNotifFunc();
        }
        /* Call the notification if configured */
        MemAcc_JobEndNotify(JobInfo);
    }
}


/**
 * @brief    If MemAccMemInvocation is set to INDIRECT_DYNAMIC or INDIRECT_STATIC,
 *           MemAcc shall call all Mem main functions within MemAcc_MainFunction.
 *           MemAcc_MainFunction shall only call the Mem main function
 *           if there is a job request pending for the corresponding Mem driver.
 **/
static void MemAcc_ScheduleMemDriver( const MemAcc_JobRuntimeInfoType *JobInfo )
{
    if(JobInfo->SubArea->MemInvocation != MEMACC_MEM_DIRECT_STATIC)
    {
        JobInfo->SubArea->MemApi->MainFunc();
    }
}


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Synchronous Functions)
==================================================================================================*/

/**
 * @brief        The function initializes MemAcc module.
 *
 * @details      Initialization function - initializes all variables
 *               and sets the module state to initialized.
 *
 * @param[in]    ConfigPtr    Pointer to selected configuration structure.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       None
 *
 * @pre          ConfigPtr must not be NULL_PTR and the module status must not be BUSY.
 *
 * @api
 *
 * @implements   MemAcc_Init_Activity
 */
void MemAcc_Init(const MemAcc_ConfigType * ConfigPtr)
{
    MemAcc_JobResultType JobResult = MEMACC_MEM_OK;
    Std_ReturnType Status;
    uint32 Index;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
#ifdef MEMACC_PRECOMPILE_SUPPORT
    if (NULL_PTR != ConfigPtr)
#else
    if (NULL_PTR == ConfigPtr)
#endif /* MEMACC_PRECOMPILE_SUPPORT */
    {
        MemAcc_ReportDevError(MEMACC_INIT_ID, MEMACC_E_PARAM_POINTER );
    }
    else
    {
#endif /* MEMACC_DEV_ERROR_DETECT == STD_ON */

#ifdef MEMACC_PRECOMPILE_SUPPORT
        MemAcc_pConfigPtr = &MemAcc_Config;  /* Use pre-compile configuration set structure */
        (void)ConfigPtr;
#else
        MemAcc_pConfigPtr = ConfigPtr;       /* Use post-build configuration set structure */
#endif

        /* Initialization function - initializes all variables and sets the module state to initialized */
        Status = MemAcc_ValidateConfigCRC();

        if ((Std_ReturnType)E_OK == Status)
        {
            /* Point to runtime info list */
            MemAcc_pJobRuntimeInfo = MemAcc_pConfigPtr->JobRuntimeInfo;

            /* Initialize all Mem drivers with INDIRECT invocation type */
            MemAcc_InitMemDrivers();

            /* Update job result and status */
            for (Index = 0U; Index < MEMACC_ADDRESS_AREA_COUNT; Index++)
            {
                MemAcc_pJobRuntimeInfo[Index].JobResult = JobResult;
                MemAcc_pJobRuntimeInfo[Index].JobStatus = MEMACC_JOB_IDLE;
                MemAcc_pJobRuntimeInfo[Index].JobType   = MEMACC_NO_JOB;
                MemAcc_pJobRuntimeInfo[Index].JobLocked = (boolean)FALSE;
            }

            /* Clear hardware resource state */
            for (Index = 0U; Index < MEMACC_MEM_HW_RESOURCE_COUNT; Index++)
            {
                MemAcc_au16MemHwResources[Index] = MEMACC_MEM_HW_RESOURCE_IDLE;
            }
        }
        else
        {
            /* Mark the driver as un-initialized */
            MemAcc_pConfigPtr = NULL_PTR;
        }

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    }
#endif /* MEMACC_DEV_ERROR_DETECT == STD_ON */
}

/**
 * @brief        The function de-initializes the MemAcc module.
 *
 * @details      De-initialize module.
 *               If there is still an access job pending, it is immediately terminated (using hardware cancel operation)
 *               and the Mem driver module state is set to unitialized.
 *               Therefore, Mem must be re-initialized before it will accept any new job requests after this service is processed.
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
 * @pre          The MemAcc module must be re-initialized before it will accept
 *               any new job requests after this service is processed.
 *
 * @implements   MemAcc_DeInit_Activity
 */
void MemAcc_DeInit(void)
{
    /* Deinitialize all Mem drivers with INDIRECT invocation type */
    MemAcc_DeinitMemDrivers();

    /* Deinitialize the MemAcc module */
    MemAcc_pConfigPtr = NULL_PTR;

    /* Reset RuntimeInformation*/
    MemAcc_pJobRuntimeInfo = NULL_PTR;
}


/**
 * @brief        Service to return the version information of the MemAcc module.
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
 * @implements   MemAcc_GetVersionInfo_Activity
 */
void MemAcc_GetVersionInfo(Std_VersionInfoType * VersionInfoPtr)
{
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    if (NULL_PTR == VersionInfoPtr)
    {
        /* The VersionInfoPtr argument is a NULL pointer */
        MemAcc_ReportDevError(MEMACC_GETVERSIONINFO_ID, MEMACC_E_PARAM_POINTER);
    }
    else
#endif
    {
        /* Return version information about MemAcc module */
        VersionInfoPtr->moduleID         = (uint16)MEMACC_MODULE_ID;
        VersionInfoPtr->vendorID         = (uint16)MEMACC_VENDOR_ID;
        VersionInfoPtr->sw_major_version =  (uint8)MEMACC_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version =  (uint8)MEMACC_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version =  (uint8)MEMACC_SW_PATCH_VERSION;
    }
}


/**
 * @brief        Get the most recent job result of the referenced address area.
 *
 * @details      Returns the consolidated job result of the address area referenced by AddressAreaId.
 *               If a MemAcc job is still pending, the API returns the result of the last MemAcc job.
 *
 * @param[in]    AddressAreaId    Numeric identifier of address area
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       MemAcc_JobResultType    Most recent job result.
 *
 * @api
 *
 * @implements   MemAcc_GetJobResult_Activity
 */
MemAcc_JobResultType MemAcc_GetJobResult(MemAcc_AddressAreaIdType AddressAreaId)
{
    MemAcc_JobResultType JobResult = MEMACC_MEM_FAILED;
    uint16 AreaIndex;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    /* Checks if the MemAcc module has been initialized */
    uint32 ErrorId = MemAcc_ValidateModuleInitialized();

    if (MEMACC_E_OK == ErrorId)
    {
#endif
        /* Get the index number of this address area */
        AreaIndex = MemAcc_GetAddressAreaIndex(AddressAreaId);

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        if (AreaIndex != MEMACC_ADDRESS_AREA_INDEX_INVALID)
        {
#endif
            /* Get the most recent job result of the according address area */
            JobResult = MemAcc_pJobRuntimeInfo[AreaIndex].JobResult;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        }
        else
        {
            /* Report the error */
            MemAcc_ReportDevError(MEMACC_GETJOBRESULT_ID, MEMACC_E_PARAM_ADDRESS_AREA_ID);
        }
    }
    else
    {
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_GETJOBRESULT_ID, ErrorId);
    }
#endif

    return JobResult;
}


/**
 * @brief        Get the most recent job status of the referenced address area.
 *
 * @details      Returns the status of the MemAcc job referenced by addressAreaId.
 *
 * @param[in]    AddressAreaId    Numeric identifier of address area
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       MemAcc_JobStatusType    Most recent job status.
 *
 * @api
 *
 * @implements   MemAcc_GetJobStatus_Activity
 */
MemAcc_JobStatusType MemAcc_GetJobStatus(MemAcc_AddressAreaIdType AddressAreaId)
{
    MemAcc_JobStatusType JobStatus = MEMACC_JOB_IDLE;
    uint16 AreaIndex;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    /* Checks if the MemAcc module has been initialized */
    uint32 ErrorId = MemAcc_ValidateModuleInitialized();
    if (MEMACC_E_OK == ErrorId)
    {
#endif
        /* Get the index number of this address area */
        AreaIndex = MemAcc_GetAddressAreaIndex(AddressAreaId);

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        if (AreaIndex != MEMACC_ADDRESS_AREA_INDEX_INVALID)
        {
#endif
            /* Get the most recent job status of the according address area */
            JobStatus = MemAcc_pJobRuntimeInfo[AreaIndex].JobStatus;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        }
    }
    else
    {
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_GETJOBSTATUS_ID, ErrorId);
    }
#endif
    return JobStatus;
}


/**
 * @brief        Get the memory information of the referenced address area.
 *
 * @details      This service function retrieves the physical memory device information of a specific address area.
 *               It can be used by an upper layer to get all necessary information to align the start address
 *               and trim the length for erase/write jobs.
 *
 * @param[in]    AddressAreaId    Numeric identifier of address area
 * @param[in]    Address          Address in logical address space from which corresponding memory device information shall be retrieved.
 *
 * @param[inout] None
 *
 * @param[out]   MemoryInfoPtr    Destination memory pointer to store the memory device information.
 *
 * @return       Std_ReturnType
 *                   - E_OK                   : The requested addressAreaId and address are valid.
 *                   - E_NOT_OK               : The requested addressAreaId and address are invalid.
 *
 * @api
 *
 * @implements   MemAcc_GetMemoryInfo_Activity
 */
Std_ReturnType MemAcc_GetMemoryInfo
(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          Address,
    MemAcc_MemoryInfoType      *MemoryInfoPtr
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    const MemAcc_SubAddressAreaType *SubAreaInfo;
    const MemAcc_AddressAreaType *AddressArea;
    uint16 AreaIndex;
    uint16 SubAreaIndex;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorId;

    /* Checks if the MemAcc module has been initialized */
    ErrorId = MemAcc_ValidateModuleInitialized();

    if (MEMACC_E_OK == ErrorId)
    {
#endif
        /* Get the index number of this address area */
        AreaIndex = MemAcc_GetAddressAreaIndex(AddressAreaId);

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        /* Check if the provided AddressAreaId is consistent with the configuration */
        if (AreaIndex == MEMACC_ADDRESS_AREA_INDEX_INVALID)
        {
            /* The provided AddressAreaId is inconsistent with the configuration */
            ErrorId = MEMACC_E_PARAM_ADDRESS_AREA_ID;
        }

        /* Perform the pointer checking */
        if (MEMACC_E_OK == ErrorId)
        {
            if (NULL_PTR == MemoryInfoPtr)
            {
                /* The NMemoryInfoPtr argument is a NULL pointer */
                ErrorId = MEMACC_E_PARAM_POINTER;
            }
        }
    }

    if (MEMACC_E_OK != ErrorId)
    {
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_GETMEMORYINFO_ID, ErrorId);
        RetVal = E_NOT_OK;
    }
    else
#endif
    {
        /* Get and validate the index number of address sub area */
        AddressArea = &( MemAcc_pConfigPtr->AddressAreas[AreaIndex] );
        SubAreaIndex = MemAcc_GetAddressSubAreaIndex(AddressArea, Address);
        if(SubAreaIndex >= AddressArea->SubAreaCount)
        {
            RetVal = E_NOT_OK;
        }
        else
        {
            /* Update SubAreaInfo information */
            SubAreaInfo = &(MemAcc_pConfigPtr->AddressAreas[AreaIndex].SubAreas[SubAreaIndex]);

            /* Get the most recent memory info of the according address area */
            MemoryInfoPtr->LogicalStartAddress  = SubAreaInfo->LogicalStartAddress;                /* Logical start address of sub address area                                          */
            MemoryInfoPtr->PhysicalStartAddress = SubAreaInfo->PhysicalStartAddress;               /* Physical start address of sub address area                                         */
            MemoryInfoPtr->MaxOffset            = SubAreaInfo->Length;                             /* Size of sub address area in bytes -1                                               */
            MemoryInfoPtr->EraseSectorSize      = SubAreaInfo->MemSectorBatchInfo.SectorSize;      /* Size of a sector in bytes                                                          */
            MemoryInfoPtr->EraseSectorBurstSize = SubAreaInfo->MemSectorBatchInfo.EraseBurstSize;  /* Size of a sector burst in bytes. Equals SectorSize in case burst is disabled       */
            MemoryInfoPtr->ReadPageSize         = SubAreaInfo->MemSectorBatchInfo.ReadPageSize;    /* Read size of a page in bytes                                                       */
            MemoryInfoPtr->WritePageSize        = SubAreaInfo->MemSectorBatchInfo.WritePageSize;   /* Write size of a page in bytes                                                      */
            MemoryInfoPtr->ReadPageBurstSize    = SubAreaInfo->MemSectorBatchInfo.ReadBurstSize;   /* Size of a read page burst in bytes. Equals ReadPageSize in case burst is disabled  */
            MemoryInfoPtr->WritePageBurstSize   = SubAreaInfo->MemSectorBatchInfo.WriteBurstSize;  /* Size of a page burst in bytes. Equals WritePageSize in case burst is disabled      */
            MemoryInfoPtr->HwId                 = SubAreaInfo->Hw_Id;                              /* Referenced memory driver hardware identifier                                       */
        }
    }

    return RetVal;
}


/**
 * @brief        Get the processed length of data of the referenced address area.
 *
 * @details      Returns the accumulated number of bytes that have already been processed in the current job.
 *
 * @param[in]    AddressAreaId    Numeric identifier of address area
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       MemAcc_LengthType    Processed length of current job (in bytes).
 *
 * @api
 *
 * @implements   MemAcc_GetProcessedLength_Activity
 */
MemAcc_LengthType MemAcc_GetProcessedLength(MemAcc_AddressAreaIdType AddressAreaId)
{
    MemAcc_LengthType Length = 0U;
    const MemAcc_JobRuntimeInfoType *JobInfo;
    uint16 AreaIndex;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    /* Checks if the MemAcc module has been initialized */
    uint32 ErrorId = MemAcc_ValidateModuleInitialized();

    if (MEMACC_E_OK == ErrorId)
    {
#endif
        /* Get the index number of this address area */
        AreaIndex = MemAcc_GetAddressAreaIndex(AddressAreaId);

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        if (MEMACC_ADDRESS_AREA_INDEX_INVALID == AreaIndex)
        {
            /* The provided AddressAreaId is inconsistent with the configuration */
            ErrorId = MEMACC_E_PARAM_ADDRESS_AREA_ID;
        }
    }

    if (MEMACC_E_OK != ErrorId)
    {
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_GETPROCESSEDLENGTH_ID, ErrorId);
    }
    else
#endif
    {
        /* Update runtime information */
        JobInfo = &MemAcc_pJobRuntimeInfo[AreaIndex];

        /* Returns the accumulated number of bytes that have already been processed in the current job */
        Length = JobInfo->LengthOrigin -JobInfo->LengthRemain;
    }

    return Length;
}


/**
 * @brief        Get the job information of the referenced address area.
 *
 * @details      Returns detailed information of the current memory job
 *               like memory device ID, job type, job processing state or job result, address area as well as address and length.
 *
 * @param[in]    AddressAreaId    Numeric identifier of address area
 *
 * @param[inout] None
 *
 * @param[out]   JobInfoPtr       Structure pointer to return the detailed processing information of the current job.
 *
 * @return       None
 *
 * @api
 *
 * @implements   MemAcc_GetJobInfo_Activity
 */
void MemAcc_GetJobInfo
(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_JobInfoType         *JobInfoPtr
)
{
    uint16 AreaIndex;
    const MemAcc_JobRuntimeInfoType *JobInfo;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    /* Checks if the MemAcc module has been initialized */
    uint32 ErrorId = MemAcc_ValidateModuleInitialized();

    if (MEMACC_E_OK == ErrorId)
    {
#endif
        /* Get the index number of this address area */
        AreaIndex = MemAcc_GetAddressAreaIndex(AddressAreaId);

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        if (MEMACC_ADDRESS_AREA_INDEX_INVALID == AreaIndex)
        {
            /* The provided AddressAreaId is inconsistent with the configuration */
            ErrorId = MEMACC_E_PARAM_ADDRESS_AREA_ID;
        }
    }

    /* Perform checking memoryInfoPtr argument is a NULL pointer */
    if (MEMACC_E_OK == ErrorId)
    {
        if (NULL_PTR == JobInfoPtr)
        {
            /* The DataPtr argument is a NULL pointer */
            ErrorId = MEMACC_E_PARAM_POINTER;
        }
    }

    if (MEMACC_E_OK != ErrorId)
    {
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_GETJOBINFO_ID, ErrorId);
    }
    else
#endif
    {
        /* Update runtime information */
        JobInfo = &MemAcc_pJobRuntimeInfo[AreaIndex];
        JobInfoPtr->CurrentJob      = JobInfo->JobType;                 /* Currently active MemAcc job                          */
        JobInfoPtr->Length          = JobInfo->LengthOrigin;            /* Length of the currently active address area request  */
        JobInfoPtr->LogicalAddress  = JobInfo->LogicAddress;            /* Address of currently active address area request     */
        JobInfoPtr->MemAddress      = JobInfo->PhysicAddress;           /* Physical address of the current memory driver request*/
        JobInfoPtr->MemResult       = JobInfo->JobResult;               /* Current or last Mem driver result                    */
        if(NULL_PTR != JobInfo->SubArea)
        {
            JobInfoPtr->MemInstanceId   = JobInfo->SubArea->MemInstanceId;  /* Instance ID of the current memory request         */
            JobInfoPtr->HwId            = JobInfo->SubArea->Hw_Id;          /* Referenced memory driver hardware identifier      */
            JobInfoPtr->MemLength       = JobInfo->SubArea->Length;         /* Length of memory driver request                   */
        }
        else
        {
            JobInfoPtr->MemInstanceId   = 0U;  /* Instance ID of the current memory request         */
            JobInfoPtr->HwId            = 0U;  /* Referenced memory driver hardware identifier      */
            JobInfoPtr->MemLength       = 0U;  /* Length of memory driver request                   */
        }
    }
}


/**
 * @brief        Dynamic activation and initialization of a Mem driver referenced by HwId and HeaderAddress.
 *
 * @details      Dynamic activation and initialization of a Mem driver referenced by HwId and HeaderAddress.
 *
 * @param[in]    HeaderAddress    Physical start address of Mem driver header structure.
 * @param[in]    HwId             Unique numeric memory driver identifier.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       Std_ReturnType
 *               - E_OK         Mem driver activation successful.
 *               - E_NOT_OK     Mem driver activation failed.
 *
 * @api
 *
 * @implements   MemAcc_ActivateMem_Activity
 */
Std_ReturnType MemAcc_ActivateMem
(
    MemAcc_AddressType    HeaderAddress,
    MemAcc_HwIdType       HwId
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    const MemAcc_MemApiType *pMemApis = NULL_PTR;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorId = MemAcc_ValidateModuleInitialized();

    if (MEMACC_E_OK == ErrorId)
    {
        ErrorId = MemAcc_ValidateMemDriverBinary(HeaderAddress,HwId);
    }

    if (MEMACC_E_OK != ErrorId)
    {
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_ACTIVATEMEM_ID, ErrorId);
    }
    else
#endif
    {
        /* Check HwId is correct for the Mem driver which is INDIRECT_DYNAMIC */
        if(MemAcc_pConfigPtr->MemApisInvocation[HwId] == MEMACC_MEM_INDIRECT_DYNAMIC)
        {
            pMemApis = (MemAcc_MemApiType *)((MemAcc_UintPtrType)HeaderAddress);

            MemAcc_pConfigPtr->MemApis[HwId].InitFunc                = pMemApis->InitFunc;
            MemAcc_pConfigPtr->MemApis[HwId].DeInitFunc              = pMemApis->DeInitFunc;
            MemAcc_pConfigPtr->MemApis[HwId].MainFunc                = pMemApis->MainFunc;
            MemAcc_pConfigPtr->MemApis[HwId].GetJobResultFunc        = pMemApis->GetJobResultFunc;
            MemAcc_pConfigPtr->MemApis[HwId].ReadFunc                = pMemApis->ReadFunc;
            MemAcc_pConfigPtr->MemApis[HwId].WriteFunc               = pMemApis->WriteFunc;
            MemAcc_pConfigPtr->MemApis[HwId].EraseFunc               = pMemApis->EraseFunc;
            MemAcc_pConfigPtr->MemApis[HwId].BlankCheckFunc          = pMemApis->BlankCheckFunc;
            MemAcc_pConfigPtr->MemApis[HwId].PropagateErrorFunc      = pMemApis->PropagateErrorFunc;
            MemAcc_pConfigPtr->MemApis[HwId].SuspendFunc             = pMemApis->SuspendFunc;
            MemAcc_pConfigPtr->MemApis[HwId].ResumeFunc              = pMemApis->ResumeFunc;
            MemAcc_pConfigPtr->MemApis[HwId].HwSpecificServiceFunc   = pMemApis->HwSpecificServiceFunc;

            /* Init the Mem driver */
            MemAcc_pConfigPtr->MemApis[HwId].InitFunc(NULL_PTR);
            RetVal = (Std_ReturnType)E_OK;
        }
    }
    return RetVal;
}


/**
 * @brief        Dynamic deactivation of a Mem driver referenced by HwId and HeaderAddress.
 *
 * @details      Dynamic deactivation of a Mem driver referenced by HwId and HeaderAddress.
 *
 * @param[in]    HwId             Unique numeric memory driver identifier.
 * @param[in]    HeaderAddress    Physical start address of Mem driver header structure.
 *
 * @param[inout] None
 *
 * @param[out]   None
 *
 * @return       Std_ReturnType
 *               - E_OK         Mem driver deactivation successful.
 *               - E_NOT_OK     Mem driver deactivation failed.
 *
 * @api
 *
 * @implements   MemAcc_DeactivateMem_Activity
 */
Std_ReturnType MemAcc_DeactivateMem
(
    MemAcc_HwIdType       HwId,
    MemAcc_AddressType    HeaderAddress
)
{
    Std_ReturnType RetVal         = (Std_ReturnType)E_NOT_OK;
    boolean        PendingJob     = (boolean)FALSE;
    uint32         AreaIndex      = 0U;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorId = MemAcc_ValidateModuleInitialized();

    if (MEMACC_E_OK != ErrorId)
    {
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_DEACTIVATEMEM_ID, ErrorId);
    }
    else
#endif
    {
        /* Check HwId is valid */
        if(MemAcc_pConfigPtr->MemApiCount > HwId)
        {
            /* Check HwId is correct for the Mem driver which is INDIRECT_DYNAMIC */
            if(MemAcc_pConfigPtr->MemApisInvocation[HwId] == MEMACC_MEM_INDIRECT_DYNAMIC)
            {
                /* Loop through the sorted list to check if any job is pending */
                for (AreaIndex = 0U; AreaIndex < MEMACC_ADDRESS_AREA_COUNT; AreaIndex++)
                {
                    /* Check if there was a pending or queued job */
                    if (MEMACC_JOB_IDLE != MemAcc_pJobRuntimeInfo[AreaIndex].JobStatus)
                    {
                        PendingJob = (boolean)TRUE;
                        break;
                    }
                }
                if(PendingJob == (boolean)FALSE)
                {
                    /* De-initial the Mem driver */
                    MemAcc_pConfigPtr->MemApis[HwId].DeInitFunc();
                    RetVal = (Std_ReturnType)E_OK;
                }
            }
        }
    }
    /*Not used*/
    (void)HeaderAddress;

    return RetVal;
}


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Asynchronous Functions)
==================================================================================================*/

/**
 * @brief            Cancel an ongoing job.
 *
 * @details          Triggers a cancel operation of the pending job for the address area referenced by the AddressAreaId.
 *                   Cancelling affects only jobs in pending state. For any other states, the request will be ignored.
 *                   Abort a running job synchronously so that directly after returning from this function a new job can be started.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 *
 * @param[out]       None
 *
 * @return           None
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       MemAcc_Cancel_Activity
 */
void MemAcc_Cancel(MemAcc_AddressAreaIdType AddressAreaId)
{
    MemAcc_JobRuntimeInfoType *JobInfo;
    uint16 AreaIndex;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    /* Checks if the MemAcc module has been initialized */
    uint32 ErrorId = MemAcc_ValidateModuleInitialized();

    if (MEMACC_E_OK == ErrorId)
    {
#endif
        /* Get the index number of this address area */
        AreaIndex = MemAcc_GetAddressAreaIndex(AddressAreaId);

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        if (MEMACC_ADDRESS_AREA_INDEX_INVALID == AreaIndex)
        {
            /* The provided AddressAreaId is inconsistent with the configuration */
            ErrorId = MEMACC_E_PARAM_ADDRESS_AREA_ID;
        }
    }
    if (MEMACC_E_OK != ErrorId)
    {
        /* Only raise the development error if development error detection is enabled */
        MemAcc_ReportDevError(MEMACC_CANCEL_ID, ErrorId);
    }
    else
#endif
    {
        /* Update runtime information */
        JobInfo = &MemAcc_pJobRuntimeInfo[AreaIndex];

        /* Cancelling affects only jobs in pending state */
        /* Check the status of the job is being processed in the Mem driver */
        if (MEMACC_JOB_PENDING == JobInfo->JobStatus)
        {
            /* Check the status of the job is being processed in the Mem driver */
            switch (JobInfo->JobState)
            {
            case MEMACC_JOB_STATE_STARTING:
            case MEMACC_JOB_STATE_SUSPENDING:
                /* Set Hw status to status cancelled*/
                JobInfo->JobState = MEMACC_JOB_STATE_STOP;
                JobInfo->JobStatus = MEMACC_JOB_IDLE;
                JobInfo->JobResult = MEMACC_MEM_CANCELED;
                break;
            case MEMACC_JOB_STATE_STOP:
                /* Do not thing*/
                break;
            default:
                /* Triggers a cancel operation for the address area */
                JobInfo->JobState = MEMACC_JOB_STATE_CANCELING;
                break;
            }
        }
    }
}



/**
 * @brief            Reads from an address area.
 *
 * @details          Triggers a read job to copy data from the source address into the referenced destination data buffer.
 *                   The result of this service can be retrieved using the MemAcc_GetJobResult API.
 *                   If the read operation was successful, the result of the job is MEMACC_MEM_OK.
 *                   If the read operation failed, the result of the job is either MEMACC_MEM_FAILED in case of a general error
 *                   or MEMACC_MEM_ECC_CORRECTED/MEMACC_MEM_ECC_UNCORRECTED in case of a correctable/uncorrectable ECC error.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        SourceAddress         Read address in logical address space.
 * @param[in]        Length                Read length in bytes (aligned to read page size).
 *
 * @param[out]       DestinationDataPtr    Destination memory pointer to store the read data
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       MemAcc_Read_Activity
 */
Std_ReturnType MemAcc_Read
(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          SourceAddress,
    MemAcc_DataType            *DestinationDataPtr,
    MemAcc_LengthType           Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;
    MemAcc_JobRuntimeInfoType JobRequest;

    /* Prepare for input parameter checking before update runtime information */
    JobRequest.JobType = MEMACC_READ_JOB;
    MemAcc_InitJobRequest(&JobRequest, AddressAreaId, SourceAddress, DestinationDataPtr, Length);

    /* Set the parameters and validate if enabling Dev error detect*/
    ErrorId = MemAcc_SetParamJobDataTransfer(&JobRequest);

    if (MEMACC_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_MemAcc_MEMACC_EXCLUSIVE_AREA_12();

        /* Configure the new job request to global runtime variable */
        ErrorId = MemAcc_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_MemAcc_MEMACC_EXCLUSIVE_AREA_12();
    }

    if (MEMACC_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_READ_ID, ErrorId);
#endif
    }

    return RetVal;
}


/**
 * @brief            Writes to flash memory.
 *
 * @details          Triggers a write job to store the passed data to the provided address area with given address and length.
 *                   The result of this service can be retrieved using the MemAcc_GetJobResult API.
 *                   If the write operation was successful, the job result is MEMACC_MEM_OK.
 *                   If there was an issue writing the data, the result is MEMACC_MEM_FAILED.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        TargetAddress         Write address in logical address space.
 * @param[out]       SourceDataPtr         Source data pointer (aligned to MemAccBufferAlignmentValue).
 * @param[in]        Length                Write length in bytes (aligned to page size).
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       MemAcc_Write_Activity
 */
Std_ReturnType MemAcc_Write
(
    MemAcc_AddressAreaIdType     AddressAreaId,
    MemAcc_AddressType           TargetAddress,
    const MemAcc_DataType       *SourceDataPtr,
    MemAcc_LengthType            Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;
    MemAcc_JobRuntimeInfoType JobRequest;

    /* Prepare for input parameter checking before update runtime information */
    JobRequest.JobType = MEMACC_WRITE_JOB;
    MemAcc_InitJobRequest(&JobRequest, AddressAreaId, TargetAddress, (MemAcc_DataType *) ((MemAcc_UintPtrType)SourceDataPtr), Length);

    /* Set the parameters and validate if enabling Dev error detect*/
    ErrorId = MemAcc_SetParamJobDataTransfer(&JobRequest);

    if (MEMACC_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_MemAcc_MEMACC_EXCLUSIVE_AREA_11();

        /* Configure the new job request to global runtime variable */
        ErrorId = MemAcc_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_MemAcc_MEMACC_EXCLUSIVE_AREA_11();
    }

    if (MEMACC_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_WRITE_ID, ErrorId);
#endif
    }
    return RetVal;
}


/**
 * @brief            Erase one or more complete flash sectors.
 *
 * @details          Triggers an erase job of the given area.
 *                   Triggers an erase job of the given area defined by targetAddress and length.
 *                   The result of this service can be retrieved using the Mem_GetJobResult API.
 *                   If the erase operation was successful, the result of the job is MEM_JOB_OK.
 *                   If the erase operation failed, e.g. due to a hardware issue, the result of the job is MEM_JOB_FAILED.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        TargetAddress         Erase address in logical address space (aligned to sector size).
 * @param[in]        Length                Erase length in bytes (aligned to sector size).
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       MemAcc_Erase_Activity
 */
Std_ReturnType MemAcc_Erase
(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          TargetAddress,
    MemAcc_LengthType           Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;
    MemAcc_JobRuntimeInfoType JobRequest;

    /* Prepare for input parameter checking before update runtime information */
    JobRequest.JobType = MEMACC_ERASE_JOB;
    MemAcc_InitJobRequest(&JobRequest, AddressAreaId, TargetAddress, NULL_PTR, Length);

    /* Set the parameters and validate if enabling Dev error detect*/
    ErrorId = MemAcc_SetParamJobCommon(&JobRequest);

    if (MEMACC_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_MemAcc_MEMACC_EXCLUSIVE_AREA_10();

        /* Configure the new job request to global runtime variable */
        ErrorId = MemAcc_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_MemAcc_MEMACC_EXCLUSIVE_AREA_10();
    }

    if (MEMACC_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_ERASE_ID, ErrorId);
#endif
    }
    return RetVal;
}


#if (MEMACC_COMPARE_API == STD_ON)

/**
 * @brief            Compares a flash memory area with an application data buffer.
 *
 * @details          Triggers a job to compare the passed data to the memory content of the provided address area.
 *                   The job terminates, if all bytes matched or a difference was detected.
 *                   The result of this service can be retrieved using the MemAcc_GetJobResult() API.
 *                   If the compare operation determined a mismatch, the result code is MEMACC_MEM_INCONSISTENT.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        SourceAddress         Compare address in logical address space.
 * @param[in]        DataPtr               Pointer to user data which shall be compared to data in memory.
 * @param[in]        Length                Compare length in bytes.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       MemAcc_Compare_Activity
 */
Std_ReturnType MemAcc_Compare
(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          SourceAddress,
    const MemAcc_DataType      *DataPtr,
    MemAcc_LengthType           Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;
    MemAcc_JobRuntimeInfoType JobRequest;

    /* Prepare for input parameter checking before update runtime information */
    JobRequest.JobType = MEMACC_COMPARE_JOB;
    MemAcc_InitJobRequest(&JobRequest, AddressAreaId, SourceAddress, (MemAcc_DataType *)((MemAcc_UintPtrType)DataPtr), Length);

    /* Set the parameters and validate if enabling Dev error detect*/
    ErrorId = MemAcc_SetParamJobDataTransfer(&JobRequest);

    if (MEMACC_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_MemAcc_MEMACC_EXCLUSIVE_AREA_13();

        /* Configure the new job request to global runtime variable */
        ErrorId = MemAcc_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_MemAcc_MEMACC_EXCLUSIVE_AREA_13();
    }

    if (MEMACC_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_COMPARE_ID, ErrorId);
#endif
    }

    return RetVal;
}

#endif


/**
 * @brief            Verify whether a given memory area has been erased but not (yet) programmed.
 *
 * @details          Checks if the passed address space is blank, i.e. erased and writeable.
 *                   The result of this service can be retrieved using the MemAcc_GetJobResult API.
 *                   If the address area defined by targetAddress and length is blank, the result is MEMACC_MEM_OK,
 *                   otherwise the result is MEMACC_MEM_INCONSISTENT.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        TargetAddress         Blank check address in logical address space.
 * @param[in]        Length                Blank check length in bytes.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       MemAcc_BlankCheck_Activity
 */
Std_ReturnType MemAcc_BlankCheck
(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          TargetAddress,
    MemAcc_LengthType           Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;
    MemAcc_JobRuntimeInfoType JobRequest;

    /* Prepare for input parameter checking before update runtime information */
    JobRequest.JobType    = MEMACC_BLANKCHECK_JOB;
    MemAcc_InitJobRequest(&JobRequest, AddressAreaId, TargetAddress, NULL_PTR, Length);

    /* Perform the input parameters checking */
    ErrorId = MemAcc_SetParamJobCommon(&JobRequest);

    if (MEMACC_E_OK == ErrorId)
    {
        /* Start of exclusive area */
        SchM_Enter_MemAcc_MEMACC_EXCLUSIVE_AREA_14();

        /* Configure the new job request to global runtime variable */
        ErrorId = MemAcc_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_MemAcc_MEMACC_EXCLUSIVE_AREA_14();
    }

    if (MEMACC_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_BLANKCHECK_ID, ErrorId);
#endif
    }

    return RetVal;
}


/**
 * @brief            Trigger a hardware specific service.
 *
 * @details          Triggers a hardware specific job request referenced by hwServiceId.
 *                   Service specific data can be passed/retrieved by dataPtr.
 *                   The result of this service can be retrieved using the MemAcc_GetJobResult API.
 *                   If the hardware specific operation was successful, the result of the job is MEMACC_MEM_OK.
 *                   If the hardware specific operation failed, the result of the job is MEMACC_MEM_FAILED.
 *
 * @param[in]        AddressAreaId         Numeric identifier of address area.
 * @param[in]        HwId                  Unique numeric memory driver identifier.
 * @param[in]        HwServiceId           Array index pointing to the hardware specific service function pointer.
 *
 * @param[inout]     DataPtr               Data pointer pointing to the job buffer. Value can be NULL_PTR, if not needed.
 *                                         If dataPtr is used by the hardware specific service, the pointer must be valid until the job completed.
 * @param[inout]     LengthPtr             Size pointer of the data passed by dataPtr. Can be NULL_PTR if dataPtr is also NULL_PTR.
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *                   - E_MEM_SERVICE_NOT_AVAIL: The underlying Mem driver service function is not available.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       MemAcc_HwSpecificService_Activity
 */
Std_ReturnType MemAcc_HwSpecificService
(
    MemAcc_AddressAreaIdType     AddressAreaId,
    MemAcc_HwIdType              HwId,
    MemAcc_MemHwServiceIdType    HwServiceId,
    MemAcc_DataType             *DataPtr,
    MemAcc_LengthType           *LengthPtr
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_OK;
    uint32 ErrorId;
    MemAcc_JobRuntimeInfoType JobRequest;
    const MemAcc_AddressAreaType *AddressArea;

    /* Prepare for input parameter checking before update runtime information */
    JobRequest.JobType = MEMACC_MEMHWSPECIFIC_JOB;
    MemAcc_InitJobRequest(&JobRequest, AddressAreaId, 0x0U, DataPtr, 0x0U);
    /*Initial specific information*/
    JobRequest.LengthPtr = LengthPtr;
    JobRequest.MemHwServiceId = HwServiceId;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    /* Checks if the MemAcc module has been initialized */
    ErrorId = MemAcc_ValidateModuleInitialized();

    if (MEMACC_E_OK == ErrorId)
    {
#endif
        /* Get the index number of this address area */
        JobRequest.AreaIndex = MemAcc_GetAddressAreaIndex(AddressAreaId);

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        if (MEMACC_ADDRESS_AREA_INDEX_INVALID == JobRequest.AreaIndex)
        {
            /* The provided AddressAreaId is inconsistent with the configuration */
            ErrorId = MEMACC_E_PARAM_ADDRESS_AREA_ID;
        }
    }

    if (MEMACC_E_OK == ErrorId)
    {
#endif
        /* Find the first sub address area of the job (according to the HwId) */
        AddressArea = &(MemAcc_pConfigPtr->AddressAreas[JobRequest.AreaIndex]);
        JobRequest.SubArea = MemAcc_GetSubAddressAreaByHwId(AddressArea, HwId);

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        /* Check if the Mem driver hardware identification given by hwId is invalid or not assigned to the passed addressAreaId */
        if(NULL_PTR == JobRequest.SubArea)
        {
            ErrorId = MEMACC_E_PARAM_HW_ID;
        }
    }

    if (MEMACC_E_OK == ErrorId)
#endif
    {
        /* Start of exclusive area */
        SchM_Enter_MemAcc_MEMACC_EXCLUSIVE_AREA_15();

        /* Configure the new job request to global runtime variable */
        ErrorId = MemAcc_ConfigureJobRequest(&JobRequest);

        /* End of exclusive area */
        SchM_Exit_MemAcc_MEMACC_EXCLUSIVE_AREA_15();
    }

    if (MEMACC_E_OK != ErrorId)
    {
        /* Reject the requested job */
        RetVal = (Std_ReturnType)E_NOT_OK;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_HWSPECIFICSERVICE_ID, ErrorId);
#endif
    }

    return RetVal;
}


/**
 * @brief            Request lock of an address area for exclusive access.
 *
 * @details          Request lock of an address area for exclusive access.
 *                   Once the lock is granted, the referenced lock notification function is called by MemAcc.
 *
 * @param[in]        AddressAreaId           Numeric identifier of address area.
 * @param[in]        Address                 Logical start address of the address area to identify the Mem driver to be locked.
 * @param[in]        Length                  Length of the address area to identify the Mem driver to be locked.
 * @param[in]        LockNotificationFctPtr  Pointer to address area lock notification callback function.
 *
 * @param[inout]     None
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module. The address area is locked/locking or validation fail.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       MemAcc_RequestLock_Activity
 */
Std_ReturnType MemAcc_RequestLock
(
    MemAcc_AddressAreaIdType            AddressAreaId,
    MemAcc_AddressType                  Address,
    MemAcc_LengthType                   Length,
    MemAcc_ApplicationLockNotification  LockNotificationFctPtr
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint32 ErrorId;
    MemAcc_ApplicationLockNotification JobLockNotifFunc;
    MemAcc_JobRuntimeInfoType JobRequest;
    MemAcc_JobRuntimeInfoType *JobInfo;

    /* Prepare for input parameter checking before update runtime information */
    JobRequest.JobType = MEMACC_REQUESTLOCK_JOB;
    MemAcc_InitJobRequest(&JobRequest, AddressAreaId, Address, NULL_PTR, Length);

    /* Perform the input parameters checking */
    ErrorId = MemAcc_SetParamJobCommon(&JobRequest);

    if (MEMACC_E_OK == ErrorId)
    {
        JobInfo = &MemAcc_pJobRuntimeInfo[JobRequest.AreaIndex];
        if(JobInfo->LockStatus == MEMACC_UNLOCK)
        {
            /*Store lock information*/
            JobInfo->LockAddress = Address;
            JobInfo->LockLength  = Length;
            JobInfo->JobLocked   = FALSE;
            if(LockNotificationFctPtr != NULL_PTR)
            {
                JobInfo->LockNotif   = LockNotificationFctPtr;
                /*If a job is pending, change lock status to MEMACC_LOCKING*/
                if(MEMACC_JOB_IDLE != JobInfo->JobStatus)
                {
                    JobInfo->LockStatus  = MEMACC_LOCKING;
                }
                else
                {
                    /*No job is pending, change lock status to MEMACC_LOCKED and call Lock callback function*/
                    JobInfo->LockStatus  = MEMACC_LOCKED;
                    JobLockNotifFunc = JobInfo->LockNotif;
                    JobLockNotifFunc();
                }
                RetVal = (Std_ReturnType)E_OK;
            }
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
            else
            {
                /* Report the error */
                MemAcc_ReportDevError(MEMACC_REQUESTLOCK_ID, MEMACC_E_PARAM_POINTER);
            }
#endif
        }
        /*If the Area is locked/locking. Return E_NOT_OK*/
    }
#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    else
    {
        /*Validation fail, return E_NOT_OK*/
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_REQUESTLOCK_ID, ErrorId);
    }
#endif
    return RetVal;
}

/**
 * @brief            Release access lock of provided address area.
 *
 * @details          Release access lock of provided address area.
 *
 * @param[in]        AddressAreaId           Numeric identifier of address area.
 * @param[in]        Address                 Logical start address to identify lock area.
 * @param[in]        Length                  Length to identify lock area.
 *
 * @param[inout]     None
 *
 * @param[out]       None
 *
 * @return           Std_ReturnType
 *                   - E_OK                   : The requested job has been accepted by the module.
 *                   - E_NOT_OK               : The requested job has not been accepted by the module.
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @implements       MemAcc_ReleaseLock_Activity
 */
Std_ReturnType MemAcc_ReleaseLock
(
    MemAcc_AddressAreaIdType    AddressAreaId,
    MemAcc_AddressType          Address,
    MemAcc_LengthType           Length
)
{
    Std_ReturnType RetVal = (Std_ReturnType)E_NOT_OK;
    uint16 AreaIndex;

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
    uint32 ErrorId;

    /* Checks if the MemAcc module has been initialized */
    ErrorId = MemAcc_ValidateModuleInitialized();

    if (MEMACC_E_OK != ErrorId)
    {
        /* Report the error */
        MemAcc_ReportDevError(MEMACC_RELEASELOCK_ID, MEMACC_E_UNINIT);
    }
    else
#else
    (void)Address;
    (void)Length;
#endif
    {
        AreaIndex = MemAcc_GetAddressAreaIndex(AddressAreaId);

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
        if (AreaIndex == MEMACC_ADDRESS_AREA_INDEX_INVALID)
        {
            /* Report the error */
            MemAcc_ReportDevError(MEMACC_RELEASELOCK_ID, MEMACC_E_PARAM_ADDRESS_AREA_ID);
        }
        else
#endif
        {
            if(MemAcc_pJobRuntimeInfo[AreaIndex].LockStatus != MEMACC_UNLOCK)
            {

#if ( MEMACC_DEV_ERROR_DETECT == STD_ON )
                if(Address != MemAcc_pJobRuntimeInfo[AreaIndex].LockAddress)
                {
                    /* Report the error */
                    MemAcc_ReportDevError(MEMACC_RELEASELOCK_ID, MEMACC_E_PARAM_ADDRESS_LENGTH);
                }
                else if (Length != MemAcc_pJobRuntimeInfo[AreaIndex].LockLength)
                {
                    /* Report the error */
                    MemAcc_ReportDevError(MEMACC_RELEASELOCK_ID, MEMACC_E_PARAM_ADDRESS_LENGTH);
                }
                else
#endif
                {
                    /*Clear lock information of the address area*/
                    MemAcc_pJobRuntimeInfo[AreaIndex].LockStatus = MEMACC_UNLOCK;
                    MemAcc_pJobRuntimeInfo[AreaIndex].LockAddress = 0U;
                    MemAcc_pJobRuntimeInfo[AreaIndex].LockLength  = 0U;
                    MemAcc_pJobRuntimeInfo[AreaIndex].JobLocked   = FALSE;
                    MemAcc_pJobRuntimeInfo[AreaIndex].LockNotif   = NULL_PTR;

                    RetVal = (Std_ReturnType)E_OK;
                }
            }
            else
            {
                /*The address area is not locked. return E_NOT_OK*/
            }
        }
    }

    return RetVal;
}


/*==================================================================================================
                                       GLOBAL FUNCTIONS (Scheduled Functions)
==================================================================================================*/

/**
 * @brief            Service to handle the requested jobs and the internal management operations.
 *
 * @details          Service to handle the requested jobs and the internal management operations.
 *                   Depending on the configuration MemAcc will call the Mem driver main functions.
 *
 * @param[in]        None
 *
 * @param[inout]     None
 *
 * @param[out]       None
 *
 * @return           None
 *
 * @api
 *
 * @pre              The module has to be initialized.
 *
 * @note             This function have to be called cyclically by the Basic Software Module;
 *                   it will do nothing if there aren't pending job.
 *
 * @implements       MemAcc_MainFunction_Activity
 */
void MemAcc_MainFunction(void)
{
    uint32 AreaIndex;
    MemAcc_JobRuntimeInfoType *JobInfo;

    /* SWS_BSW_00037 - If the module is not initialized and the main function is executed
       then no error shall be reported and the main function shall return immediately.
    */
    if (NULL_PTR != MemAcc_pConfigPtr)
    {
        /* Loop through the sorted list to serve the address area with highest priority first */
        for (AreaIndex = 0U; AreaIndex < MEMACC_ADDRESS_AREA_COUNT; AreaIndex++)
        {
            JobInfo = &(MemAcc_pJobRuntimeInfo[AreaIndex]);

            /* Check if there was a pending or queued job */
            if ((MEMACC_JOB_IDLE != MemAcc_pJobRuntimeInfo[AreaIndex].JobStatus) && \
                ((boolean)TRUE != MemAcc_pJobRuntimeInfo[AreaIndex].JobLocked) \
               )
            {
                /* Process the requested job for this address area */
                MemAcc_ScheduleJob(JobInfo);

                /*If the job is in MEMACC_JOB_STATE_RETRYING that mean there is no Mem's job pending -> don't not need to call Mem's MainFunction.*/
                if (JobInfo->JobState != MEMACC_JOB_STATE_RETRYING)
                {
                    /* Call the corresponding Mem's MainFunction (only for INDIRECT invocation type) */
                    MemAcc_ScheduleMemDriver(JobInfo);
                }
            }
        }
    }
}

#define MEMACC_STOP_SEC_CODE
#include "MemAcc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
