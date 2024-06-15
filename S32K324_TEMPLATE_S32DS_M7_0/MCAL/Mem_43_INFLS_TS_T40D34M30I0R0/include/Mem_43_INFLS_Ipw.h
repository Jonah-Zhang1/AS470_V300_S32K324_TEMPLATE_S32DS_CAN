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

#ifndef MEM_43_INFLS_IPW_H
#define MEM_43_INFLS_IPW_H

/**
 * @file       Mem_43_INFLS_IPW.h
 *
 * @addtogroup MEM_43_INFLS Driver
 * implement   Mem_43_INFLS_IPW.h_Artifact
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
#include "Mem_43_INFLS_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MEM_43_INFLS_IPW_VENDOR_ID                       43
#define MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION        4
#define MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION        7
#define MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION     0
#define MEM_43_INFLS_IPW_SW_MAJOR_VERSION                3
#define MEM_43_INFLS_IPW_SW_MINOR_VERSION                0
#define MEM_43_INFLS_IPW_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mem_43_INFLS_Cfg.h header file are of the same vendor */
#if (MEM_43_INFLS_IPW_VENDOR_ID != MEM_43_INFLS_TYPES_VENDOR_ID)
    #error "Mem_43_INFLS.h and Mem_43_INFLS_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mem_43_INFLS_Cfg.h header file are of the same Autosar version */
#if ((MEM_43_INFLS_IPW_AR_RELEASE_MAJOR_VERSION    != MEM_43_INFLS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_MINOR_VERSION    != MEM_43_INFLS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_AR_RELEASE_REVISION_VERSION != MEM_43_INFLS_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mem_43_INFLS.h and Mem_43_INFLS_Cfg.h are different"
#endif
/* Check if current file and Mem_43_INFLS_Cfg.h header file are of the same Software version */
#if ((MEM_43_INFLS_IPW_SW_MAJOR_VERSION != MEM_43_INFLS_TYPES_SW_MAJOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_MINOR_VERSION != MEM_43_INFLS_TYPES_SW_MINOR_VERSION) || \
     (MEM_43_INFLS_IPW_SW_PATCH_VERSION != MEM_43_INFLS_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mem_43_INFLS.h and Mem_43_INFLS_Cfg.h are different"
#endif

/*==================================================================================================
*                                    DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                    VARIABLE DECLARATIONS
==================================================================================================*/



/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MEM_43_INFLS_START_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


/**
 * @brief       Initialize the hardware resources.
 * @details
 *
 * @return      Std_ReturnType
 */
Std_ReturnType Mem_43_INFLS_IPW_Init(void);


/**
 * @brief       IP wrapper read function.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobInfo             Job runtime information
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Read(
    uint32                          InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType   *JobInfo
);


#if (MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON)
/**
 * @brief       IP wrapper Compare function.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobInfo             Job runtime information
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Compare(
    uint32                          InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType   *JobInfo
);
#endif /* MEM_43_INFLS_HW_COMPARE_SERVICE == STD_ON */


/**
 * @brief       IP wrapper blank check function.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobInfo             Job runtime information
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_BlankCheck(
    uint32                          InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType   *JobInfo
);


/**
 * @brief       IP wrapper write function.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobInfo             Job runtime information
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Write(
    uint32                          InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType   *JobInfo
);


/**
 * @brief       IP wrapper erase function.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobInfo             Job runtime information
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Erase(
    uint32                          InstanceIndex,
    Mem_43_INFLS_JobRuntimeInfoType   *JobInfo
);


/**
 * @brief       Returns synchronously the result of the last job.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 * @param[in]   JobType             Job Erase or Write.
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_GetJobResult(
    uint32               InstanceIndex,
    Mem_43_INFLS_JobType JobType
);


/**
 * @brief       Cancel an ongoing flash read, write, erase or compare job.
 * @details
 *
 * @param[in]   InstanceIndex       ID of the related memory driver instance.
 *
 * @return      Mem_43_INFLS_JobResultType
 */
Mem_43_INFLS_JobResultType Mem_43_INFLS_IPW_Cancel(
    uint32 InstanceIndex
);

/**
 * @brief Report Ecc value result.
 */
void Mem_43_INFLS_IPW_ReportEccValueToLayerUnder(void);

#define MEM_43_INFLS_STOP_SEC_CODE
#include "Mem_43_INFLS_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* MEM_43_INFLS_IPW_H */
