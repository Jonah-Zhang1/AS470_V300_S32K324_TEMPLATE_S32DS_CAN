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

#ifndef MEM_43_INFLS_TYPES_H
#define MEM_43_INFLS_TYPES_H

/**
 * @file       Mem_43_INFLSTypes.h
 *
 * @addtogroup MEM_43_INFLS
 * implement   Mem_43_INFLS_Types.h_Artifact
 *
 * @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "C40_Ip_Types.h"
#include "Mem_43_INFLS_CfgDefines.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_TYPES_VENDOR_ID                      43
#define MEM_43_INFLS_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define MEM_43_INFLS_TYPES_AR_RELEASE_MINOR_VERSION       7
#define MEM_43_INFLS_TYPES_AR_RELEASE_REVISION_VERSION    0
#define MEM_43_INFLS_TYPES_SW_MAJOR_VERSION               3
#define MEM_43_INFLS_TYPES_SW_MINOR_VERSION               0
#define MEM_43_INFLS_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
                                    FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and C40_Ip_Types.h header file are of the same vendor */
#if (MEM_43_INFLS_TYPES_VENDOR_ID != C40_IP_TYPES_VENDOR_ID_CFG)
    #error "Mem_43_INFLSTypes.h and C40_Ip_Types.h have different vendor ids"
#endif
/* Check if current file and C40_Ip_Types.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_TYPES_AR_RELEASE_MAJOR_VERSION    != C40_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MEM_43_INFLS_TYPES_AR_RELEASE_MINOR_VERSION    != C40_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MEM_43_INFLS_TYPES_AR_RELEASE_REVISION_VERSION != C40_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLSTypes.h and C40_Ip_Types.h are different"
#endif
/* Check if current file and C40_Ip_Types.h header file are of the same Software version */
#if ((MEM_43_INFLS_TYPES_SW_MAJOR_VERSION != C40_IP_TYPES_SW_MAJOR_VERSION_CFG) || \
     (MEM_43_INFLS_TYPES_SW_MINOR_VERSION != C40_IP_TYPES_SW_MINOR_VERSION_CFG) || \
     (MEM_43_INFLS_TYPES_SW_PATCH_VERSION != C40_IP_TYPES_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Mem_43_INFLSTypes.h and C40_Ip_Types.h are different"
#endif

/* Check if current file and Mem_43_INFLS_CfgDefines.h header file are of the same vendor */
#if (MEM_43_INFLS_TYPES_VENDOR_ID != MEM_43_INFLS_VENDOR_ID_CFG_DEFINES)
    #error "Mem_43_INFLSTypes.h and Mem_43_INFLS_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS_CfgDefines.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_TYPES_AR_RELEASE_MAJOR_VERSION    != MEM_43_INFLS_AR_RELEASE_MAJOR_VERSION_CFG_DEFINES) || \
     (MEM_43_INFLS_TYPES_AR_RELEASE_MINOR_VERSION    != MEM_43_INFLS_AR_RELEASE_MINOR_VERSION_CFG_DEFINES) || \
     (MEM_43_INFLS_TYPES_AR_RELEASE_REVISION_VERSION != MEM_43_INFLS_AR_RELEASE_REVISION_VERSION_CFG_DEFINES) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLSTypes.h and Mem_43_INFLS_CfgDefines.h are different"
#endif
/* Check if current file and Mem_43_INFLS_CfgDefines.h header file are of the same Software version */
#if ((MEM_43_INFLS_TYPES_SW_MAJOR_VERSION != MEM_43_INFLS_SW_MAJOR_VERSION_CFG_DEFINES) || \
     (MEM_43_INFLS_TYPES_SW_MINOR_VERSION != MEM_43_INFLS_SW_MINOR_VERSION_CFG_DEFINES) || \
     (MEM_43_INFLS_TYPES_SW_PATCH_VERSION != MEM_43_INFLS_SW_PATCH_VERSION_CFG_DEFINES) \
    )
    #error "Software Version Numbers of Mem_43_INFLSTypes.h and Mem_43_INFLS_CfgDefines.h are different"
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
*  @brief    AUTOSAR module identification
*/
#define MEM_43_INFLS_MODULE_ID            91U

/**
*  @brief    AUTOSAR module instance identification
*/
#define MEM_43_INFLS_INSTANCE_ID          0U


/**
 *  Development error codes (passed to DET)
 */
/**
 * @brief       API service called without module initialization
 * @implements  MEM_43_INFLS_E_UNINIT_define
 */
#define MEM_43_INFLS_E_UNINIT                0x01U

/**
 * @brief       API service called with NULL pointer
 * @implements  MEM_43_INFLS_E_PARAM_POINTER_define
 */
#define MEM_43_INFLS_E_PARAM_POINTER         0x02U

/**
 * @brief       API service called with an invalid address
 * @implements  MEM_43_INFLS_E_PARAM_ADDRESS_define
 */
#define MEM_43_INFLS_E_PARAM_ADDRESS         0x03U

/**
 * @brief       API service called with an invalid length
 * @implements  MEM_43_INFLS_E_PARAM_LENGTH_define
*/
#define MEM_43_INFLS_E_PARAM_LENGTH          0x04U

/**
 * @brief       API service called with an invalid driver instance ID
 * @implements  MEM_43_INFLS_E_PARAM_INSTANCE_ID_define
*/
#define MEM_43_INFLS_E_PARAM_INSTANCE_ID     0x05U

/**
 * @brief       API service called while a job request is still in progress
 * @implements  MEM_43_INFLS_E_JOB_PENDING_define
*/
#define MEM_43_INFLS_E_JOB_PENDING           0x06U

/**
 * @brief       API service called without errors
 * @implements  MEM_43_INFLS_E_OK_define
*/
#define MEM_43_INFLS_E_OK                    0xFFU
/**
 *  END Development error codes
 */


/**
 *  All service IDs (passed to DET)
 */
/* Synchronous Functions */
/**
 * @brief   Service ID of function Mem_43_INFLS_DeInit
*/
#define MEM_43_INFLS_DEINIT_ID               0x00U

/**
 * @brief   Service ID of function Mem_43_INFLS_Init
*/
#define MEM_43_INFLS_INIT_ID                 0x01U

/**
 * @brief   Service ID of function Mem_43_INFLS_GetVersionInfo
*/
#define MEM_43_INFLS_GET_VERSION_INFO_ID     0x02U

/**
 * @brief   Service ID of function Mem_43_INFLS_GetJobResult
*/
#define MEM_43_INFLS_GET_JOB_RESULT_ID       0x04U

/**
 * @brief   Service ID of function Mem_43_INFLS_PropagateError
*/
#define MEM_43_INFLS_PROPAGATE_ERROR_ID      0x08U

/**
 * @brief   Service ID of function Mem_43_INFLS_Suspend
*/
#define MEM_43_INFLS_SUSPEND_ID              0x0CU

/**
 * @brief   Service ID of function Mem_43_INFLS_Resume
*/
#define MEM_43_INFLS_RESUME_ID               0x0DU


/* Asynchronous Functions */
/**
 * @brief   Service ID of function Mem_43_INFLS_Read
*/
#define MEM_43_INFLS_READ_ID                 0x05U

/**
 * @brief   Service ID of function Mem_43_INFLS_Write
*/
#define MEM_43_INFLS_WRITE_ID                0x06U

/**
 * @brief   Service ID of function Mem_43_INFLS_Erase
*/
#define MEM_43_INFLS_ERASE_ID                0x07U

/**
 * @brief   Service ID of function Mem_43_INFLS_BlankCheck
*/
#define MEM_43_INFLS_BLANK_CHECK_ID          0x09U

/**
 * @brief   Service ID of function Mem_43_INFLS_HwSpecificService
*/
#define MEM_43_INFLS_HW_SPECIFIC_SERVICE_ID  0x0AU


/* Scheduled Functions */
/**
 * @brief   Service ID of function Mem_43_INFLS_MainFunction
*/
#define MEM_43_INFLS_MAINFUNCTION_ID         0x03U
/**
 * END All service IDs
*/


/**
 *   Hardware specific service request identifier
 */

/**
 * @brief    Define ServiceId for Compare feature
*/
#define MEM_43_INFLS_HWSERVICEID_COMPARE     0x11U

/**
 * @brief    Define ServiceId Invalid
*/
#define MEM_43_INFLS_HWSERVICEID_INVALID     0xFFU

/**
 * END All service IDs
*/


/* Job flags */
/**
 * @brief   Initial value
*/
#define MEM_43_INFLS_JOB_FLAG_NONE           0x00U

/**
 * @brief   Indicates that new job has been accepted
*/
#define MEM_43_INFLS_JOB_FLAG_STARTED        0x01U

/*==================================================================================================
                                                TYPEDEFS
==================================================================================================*/


/**
 * @brief          Mem Instance Id Type
 * @details        Mem Instance Id Type
 * @implements     Mem_43_INFLS_InstanceIdType_typedef
 */
typedef uint32 Mem_43_INFLS_InstanceIdType;

/**
 * @brief          Mem Address Type
 * @details        Physical memory device address type
 * @implements     Mem_43_INFLS_AddressType_typedef
 */
typedef MEM_43_INFLS_ADDRESSTYPE Mem_43_INFLS_AddressType;

/**
 * @brief          Mem Length Type
 * @details        Physical memory device length type
 * @implements     Mem_43_INFLS_LengthType_typedef
 */
typedef MEM_43_INFLS_LENGTHTYPE Mem_43_INFLS_LengthType;

/**
 * @brief          Mem Data Type
 * @details        Read data user buffer type
 * @implements     Mem_43_INFLS_DataType_typedef
 */
typedef uint8 Mem_43_INFLS_DataType;

/**
 * @brief          Mem CRC Type
 * @details        CRC computed over config set
 *                 (will be implement in next feature)
 *                 Mem_43_INFLS_CrcType_typedef
 *  typedef uint16 Mem_43_INFLS_CrcType;
 */

/**
 * @brief          Mem Hardware Service Id Type
 * @details        Hardware specific service request identifier type
 * @implements     Mem_43_INFLS_HwServiceIdType_typedef
 */
typedef uint32 Mem_43_INFLS_HwServiceIdType;

/**
 * @brief          Mem Access Code Callback
 * @details        Pointer type of Access Code Callback function.
 */
typedef void (*Mem_43_INFLS_ACCallbackPtrType)  ( void );

#if ( STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START )

/**
 * @brief          Mem Hardware Service Id Type
 * @details        Hardware specific service request identifier type
 */
typedef uint8 Mem_43_INFLS_BlockType;

/**
 * @brief          Mem Access Code Pointer Erase Type
 * @details        Define pointer type of erase access code function.
 */
typedef void (*Mem_43_INFLS_AcErasePtrType)  ( void (*CallBack)( void ));

/**
 * @brief          Mem Access Code Write Pointer Type
 * @details        Define pointer type of write access code function.
 */
typedef void (*Mem_43_INFLS_AcWritePtrType)  ( void (*CallBack)( void ));

#endif

/*==================================================================================================
                                                ENUMS
==================================================================================================*/

/**
 * @brief          Mem job result type
 * @implements     Mem_43_INFLS_JobResultType_enum
 */
typedef enum
{
    MEM_43_INFLS_JOB_OK                 = 0x00,    /* The last job has been finished successfully                                    */
    MEM_43_INFLS_JOB_PENDING            = 0x01,    /* A job is currently being processed                                             */
    MEM_43_INFLS_JOB_FAILED             = 0x02,    /* Job failed for some unspecific reason                                          */
    MEM_43_INFLS_JOB_INCONSISTENT       = 0x03,    /* The checked page is not blank                                                  */
    MEM_43_INFLS_JOB_ECC_UNCORRECTED    = 0x04,    /* Uncorrectable ECC errors occurred during memory access                         */
    MEM_43_INFLS_JOB_ECC_CORRECTED      = 0x05     /* Correctable ECC errors occurred during memory access                           */
} Mem_43_INFLS_JobResultType;

/**
 * @brief          Type of job currently executed by Mem_43_INFLS_MainFunction.
 */
typedef enum
{
    MEM_43_INFLS_JOB_NONE               = 0x00,    /* no job executed                                                                */
    MEM_43_INFLS_JOB_ERASE              = 0x01,    /* erase one or more complete flash sectors                                       */
    MEM_43_INFLS_JOB_WRITE              = 0x02,    /* write one or more complete flash pages                                         */
    MEM_43_INFLS_JOB_READ               = 0x03,    /* read one or more bytes from flash memory                                       */
    MEM_43_INFLS_JOB_BLANK_CHECK        = 0x04,    /* check content of erased flash memory area                                      */
    MEM_43_INFLS_JOB_HWSPECIFICSERVICE  = 0x05     /* hardware specific service                                                      */
} Mem_43_INFLS_JobType;


/*==================================================================================================
                                        CONFIGURATION STRUCTURES
==================================================================================================*/

/**
 * @brief          Mem Internal Flash Type
 * @details        Configuration structure of internal flash.
 */
typedef C40_ConfigType Mem_43_INFLS_InternalConfigType;

/**
 * @brief          Mem internal unit type
 * @details        Mem internal unit config data structure
 *                 Mem_43_INFLS_InternalUnitType_struct
 */
typedef struct
{
    const Mem_43_INFLS_InternalConfigType *InternalConfig;      /* Pointer to configuration structure internal flash */
} Mem_43_INFLS_InternalUnitType;

/**
 * @brief          Mem device config type
 * @details        Mem device config data structure
 *                 Mem_43_INFLS_MemDeviceType_struct
 */
typedef struct
{
    const Mem_43_INFLS_InternalUnitType    *InternalUnits;      /* Point to first element in array of internal flash unit configurations */
} Mem_43_INFLS_MemDeviceType;


/**
 * @brief          Sector Batch Type
 * @details        Sector Batch data structure for group of identical sectors
 *                 Note: burst sizes equal to normal sizes in case burst disabled
 *                 Mem_43_INFLS_SectorBatchType_struct
 */
typedef struct
{
    const Mem_43_INFLS_AddressType    StartAddress;       /* Physical start address of the sector batch                              */
    const Mem_43_INFLS_AddressType    EndAddress;         /* Physical end address of the sector batch                                */
    const uint32                      SectorSize;         /* Size of a sector in bytes in this sector batch (smallest erasable unit) */
    const uint32                      ReadPageSize;       /* Size of a read page of this sector in bytes (smallest readable unit)    */
    const uint32                      WritePageSize;      /* Size of a write page of this sector in bytes (smallest writeable unit)  */
    const uint32                      EraseBurstSize;     /* Size of sector erase burst in bytes (for improved performance)          */
    const uint32                      ReadBurstSize;      /* Size of page read burst in bytes (for improved performance)             */
    const uint32                      WriteBurstSize;     /* Size of page write/program burst in bytes (for improved performance)    */
} Mem_43_INFLS_SectorBatchType;

/**
 * @brief          Mem Instance Type
 * @details        Mem Instance data structure
 *                 Mem_43_INFLS_MemInstanceType_struct
 */
typedef struct
{
    const Mem_43_INFLS_InstanceIdType     InstanceId;          /* Unique numeric identifier for each a Mem driver instance           */
    const uint32                          SectorBatchCount;    /* Number of sector batches in this Mem instance                      */
    const Mem_43_INFLS_SectorBatchType   *SectorBatches;       /* Point to first element in array of sector batches configurations   */
    const uint8                           MemUnitIndex;        /* Index of flash memory unit used for this Mem instance              */
} Mem_43_INFLS_MemInstanceType;

/**
 * @brief          Mem Configuration Type
 * @details        Mem module initialization data structure
 * @implements     Mem_43_INFLS_ConfigType_struct
 */
typedef struct
{
#if (STD_ON == MEM_43_INFLS_AC_LOAD_ON_JOB_START)
    Mem_43_INFLS_AcErasePtrType           MemAcErasePtr;           /* Pointer to erase access code function in RAM or ROM                */
    Mem_43_INFLS_AcWritePtrType           MemAcWritePtr;           /* Pointer to write access code function in RAM or ROM                */
#endif
    Mem_43_INFLS_ACCallbackPtrType        MemAcCallBackPtr;        /* Pointer to Access Code Callback function                           */

    const Mem_43_INFLS_MemInstanceType   *MemInstances;            /* Point to first element in array of mem instances configurations    */
    const Mem_43_INFLS_MemDeviceType     *MemDevices;              /* Mem devices configurations used by the mem instance                */
} Mem_43_INFLS_ConfigType;

/**
* @brief          Mem_43_INFLS Compare Configuration Type
* @details        Mem_43_INFLS Compare data structure for dataPtr of HwSpecificService
*
*                 Mem_43_INFLS_CompareConfigType
*/
typedef struct
{
Mem_43_INFLS_AddressType    CompareAddr;
Mem_43_INFLS_DataType      *DataSourcePtr;
Mem_43_INFLS_LengthType     Length;
} Mem_43_INFLS_CompareConfigType;

/*==================================================================================================
                                        INTERNAL TYPES
==================================================================================================*/

/**
 * @brief          Mem job runtime information Type
 * @details        This structure contains runtime information the current processing job of each Mem instance.
 *                 Mem_43_INFLS_JobRuntimeInfoType_struct
 */
typedef struct
{
    /* Input information */
    Mem_43_INFLS_InstanceIdType            InstanceId;         /* Unique numeric identifier for each a Mem driver instance           */
    Mem_43_INFLS_JobType                   JobType;            /* Type of currently executed job (Erase, Write, or Read)             */
    Mem_43_INFLS_HwServiceIdType           HwServiceIdJob;     /* Type of currently executed job HwServiceId (Compare)       ..      */
    Mem_43_INFLS_AddressType               Address;            /* Last physical address to be processed                              */
    Mem_43_INFLS_DataType                 *DataPtr;            /* Pointer to user data buffer (used in Read and Write)               */
    Mem_43_INFLS_LengthType                Length;             /* Remaining bytes of data to be processed                            */

    /* Output result of the parameter checking stage */
    uint32                                 InstanceIndex;      /* The mem index number according to the mem instance id              */
    const Mem_43_INFLS_SectorBatchType    *SectorBatch;        /* The sector batch to be worked with the request job                 */

    /* Runtime information */
    Mem_43_INFLS_JobResultType             JobResult;          /* The result of the most recent job                                  */
    uint8                                  JobFlags;           /* Job information (Started state, burst mode)                        */
#if (MEM_43_INFLS_SUSPEND_RESUME_SUPPORT == STD_ON)
    boolean                                SuspendState;         /* Job information (Started state, burst mode)                        */
#endif
} Mem_43_INFLS_JobRuntimeInfoType;

#ifdef __cplusplus
}
#endif

/** @}*/

#endif /* MEM_43_INFLS_TYPES_H */
