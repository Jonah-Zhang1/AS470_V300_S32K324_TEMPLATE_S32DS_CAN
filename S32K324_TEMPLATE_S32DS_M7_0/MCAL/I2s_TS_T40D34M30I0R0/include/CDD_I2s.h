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

#ifndef CDD_I2S_H
#define CDD_I2S_H

/**
*   @file
*
*   @addtogroup I2S_DRIVER I2s Driver
*   @{
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

#include "Mcal.h"
#include "CDD_I2s_Types.h"
#include "CDD_I2s_Cfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define I2S_VENDOR_ID                      43
#define I2S_MODULE_ID                      255
#define I2S_AR_RELEASE_MAJOR_VERSION       4
#define I2S_AR_RELEASE_MINOR_VERSION       7
#define I2S_AR_RELEASE_REVISION_VERSION    0
#define I2S_SW_MAJOR_VERSION               3
#define I2S_SW_MINOR_VERSION               0
#define I2S_SW_PATCH_VERSION               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Mcal header file are of the same AutoSar version */
#if ((I2S_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of CDD_I2s.h and Mcal.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if current file and CDD_I2s_Types header file are of the same vendor */
#if (I2S_VENDOR_ID != I2S_TYPES_VENDOR_ID)
#error "CDD_I2s.h and CDD_I2s_Types.h have different vendor ids"
#endif

/* Check if current file and CDD_I2s header file are of the same Autosar version */
#if ((I2S_AR_RELEASE_MAJOR_VERSION     != I2S_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_AR_RELEASE_MINOR_VERSION     != I2S_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (I2S_AR_RELEASE_REVISION_VERSION  != I2S_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_I2s.h and CDD_I2s_Types.h are different"
#endif

/* Check if current file and CDD_I2s header file are of the same software version */
#if ((I2S_SW_MAJOR_VERSION != I2S_TYPES_SW_MAJOR_VERSION) || \
     (I2S_SW_MINOR_VERSION != I2S_TYPES_SW_MINOR_VERSION) || \
     (I2S_SW_PATCH_VERSION != I2S_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_I2s.h and CDD_I2s_Types.h are different"
#endif

/* Check if current file and CDD_I2s_Cfg header file are of the same vendor */
#if (I2S_VENDOR_ID != I2S_CFG_VENDOR_ID)
#error "CDD_I2s.h and CDD_I2s_Cfg.h have different vendor ids"
#endif

/* Check if current file and CDD_I2s_Cfg header file are of the same Autosar version */
#if ((I2S_AR_RELEASE_MAJOR_VERSION     != I2S_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_AR_RELEASE_MINOR_VERSION     != I2S_CFG_AR_RELEASE_MINOR_VERSION) || \
     (I2S_AR_RELEASE_REVISION_VERSION  != I2S_CFG_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of CDD_I2s.h and CDD_I2s_Cfg.h are different"
#endif

/* Check if current file and CDD_I2s_Cfg header file are of the same software version */
#if ((I2S_SW_MAJOR_VERSION != I2S_CFG_SW_MAJOR_VERSION) || \
     (I2S_SW_MINOR_VERSION != I2S_CFG_SW_MINOR_VERSION) || \
     (I2S_SW_PATCH_VERSION != I2S_CFG_SW_PATCH_VERSION))
#error "Software Version Numbers of CDD_I2s.h and CDD_I2s_Cfg.h are different"
#endif

/* Check if current file and Mcal header file are of the same Autosar version */
#if ((I2S_AR_RELEASE_MAJOR_VERSION     != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (I2S_AR_RELEASE_MINOR_VERSION     != MCAL_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of CDD_I2s.h and Mcal.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/**
*       Development errors.
*       The following errors shall be detectable by the I2S module depending on its
*       configuration (development / production mode).
*
*       All error codes
*
*/

/**
* @brief   API service used without I2s module initialization
* */
#define I2S_E_UNINIT                                 ((uint8)0x0AU)

/**
* @brief   I2s module is busy with a running operation
* */
#define I2S_E_BUSY                                   ((uint8)0x0BU)

/**
* @brief   I2s module is timeout with a running operation
* */
#define I2S_E_TIMEOUT                                ((uint8)0x0CU)

/**
* @brief   I2s module is not properly initialized
* */
#define I2S_E_INIT_FAILED                            ((uint8)0x0DU)

/**
* @brief   API service is called using an invalid pointer (e.g. the pointer should not be NULL).
* */
#define I2S_E_PARAM_POINTER                          ((uint8)0x14U)

/**
* @brief   API service is called using an invalid logical channel.
* */
#define I2S_E_PARAM_CHANNEL                          ((uint8)0x15U)

/**
* @brief   API service is called using an invalid core.
* */
#define I2S_E_PARAM_CONFIG                           ((uint8)0x16U)

/**
* @brief   I2s module is not properly direction initialized.
* */
#define I2S_E_INCORRECT_DIRECTION                    ((uint8)0x17U)

/**
          All AUTOSAR API's service IDs
*/

/**
* @brief API service ID for I2s_Init function
* */
#define I2S_INIT_ID                                  0x00U

/**
* @brief API service ID for I2s_DeInit function
* */
#define I2S_DEINIT_ID                                0x01U

/**
* @brief API service ID for I2s_SyncTransmit function
* */
#define I2S_SYNCTRANSMIT_ID                          0x02U

/**
* @brief API service ID for I2s_AsyncTransmit function
* */
#define I2S_ASYNCTRANSMIT_ID                         0x03U

/**
* @brief API service ID for I2s_GetStatus function
* */
#define I2S_GETSTATUS_ID                             0x04U

/**
* @brief API service ID for I2s_AbortTransmit function
* */
#define I2S_ABORTTRANSMIT_ID                         0x05U

/**
* @brief API service ID for I2s_GetVersionInfo function
* */
#define I2S_GETVERSIONINFO_ID                        0x06U



/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#if (I2S_PRECOMPILE_SUPPORT == STD_ON)
    #define I2S_START_SEC_CONFIG_DATA_UNSPECIFIED
    #include "I2s_MemMap.h"

#if (I2S_MULTICORE_ENABLED == STD_ON)
    extern const I2s_ConfigType * const I2s_apxConfigVariantPredefined[I2S_MAX_PARTITIONS];
#else
    extern const I2s_ConfigType * const I2s_pxConfigVariantPredefined;
#endif
    #define I2S_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #include "I2s_MemMap.h"
#else
    #define I2S_START_SEC_CONST_UNSPECIFIED
    #include "I2s_MemMap.h"

    I2S_CONFIG_EXT

    #define I2S_STOP_SEC_CONST_UNSPECIFIED
    #include "I2s_MemMap.h"
#endif
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define I2S_START_SEC_CODE

#include "I2s_MemMap.h"

/**
* @brief   Initializes the I2S module.
* @details This function performs software initialization of I2S driver.
*
* @param[in] pConfig        Pointer to I2S driver configuration set.
*
* @return  void
*
* @api
*
* @implements I2s_Init_Activity
*
* @note    Service ID: 0x00.
* @note    Synchronous, non re-entrant function.
*
*/
void I2s_Init(const I2s_ConfigType * const pConfigPtr);

/**
* @brief   DeInitializes the I2S module.
* @details This function performs software de initialization of I2S modules to reset values.
*          The service influences only the peripherals, which are allocated by static
*          configuration and the runtime configuration set passed by the previous call of I2s_Init()
*          The driver needs to be initialized before calling I2s_DeInit(). Otherwise, the
*          function I2s_DeInit shall raise the development error I2S_E_UNINIT and leave the desired
*          de initialization functionality without any action.
*
* @param[in] void
*
* @return  void
*
* @api
*
* @implements I2s_DeInit_Activity
*
* @note    Service ID: 0x01.
* @note    Synchronous, non re-entrant function.
*
*/
void I2s_DeInit(void);

/**
* @brief   Sends or receives an I2S message blocking.
* @details Sends the slave address and based on the direction of the message it sends
*          or receives data by using a blocking mechanism.
*
* @param[in] LogicChn      I2S logical channel to be addressed.
* @param[in] pRequest   Pointer to data information to be used
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2S Instance is not valid or
*                          I2S driver is not initialized or
*                          pRequest is NULL or
*                          I2S Instance is in busy state.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements I2s_SyncTransmit_Activity
*
* @note    Service ID: 0x02.
* @note    Synchronous, non reentrant function.
*
*/
Std_ReturnType I2s_SyncTransmit(I2s_LogicalChannel LogicChn,
                                  const I2s_RequestType * const pRequest);

/**
* @brief   Starts an asynchronous transmission on the I2S bus.
* @details Sends the slave address and enables the interrupts that will send
*          or receive data depending on the direction of the message.
*
* @param[in] LogicChn      I2S logical channel to be addressed.
* @param[in] pRequest   Pointer to data information to be used
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2S Instance is not valid or
*                          I2S driver is not initialized or
*                          pRequest is NULL or
*                          I2S Instance is in busy state.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements I2s_AsyncTransmit_Activity
*
* @note    Service ID: 0x03.
* @note    Synchronous, non reentrant function.
*
*/
Std_ReturnType I2s_AsyncTransmit(I2s_LogicalChannel LogicChn,
                                   const I2s_RequestType * const pRequest);

/**
* @brief   Gets the status of an I2S instance.
* @details Gets the status of an I2S instance and checks for errors.
*
* @param[in] LogicChn      I2S logical channel to be addressed.
* @param[out] pStatus      Pointer for storing the current transfer status
*
* @return                  Std_ReturnType.
* @retval E_NOT_OK         If the I2S Instance is not valid or
*                          I2S driver is not initialized or
*                          pStatus is NULL.
* @retval E_OK             Otherwise.
*
* @api
*
* @implements I2s_GetStatus_Activity
*
* @note    Service ID: 0x04.
* @note    Synchronous, non re-entrant function.
*
*/
Std_ReturnType I2s_GetStatus(I2s_LogicalChannel LogicChn,
                               I2s_StatusStructType * const pStatus);

/**
* @brief   Aborts the I2s ongoing transmission.
* @details Aborts the I2s ongoing transmission.
*
* @param[in] LogicChn          I2S logical channel to be addressed.
*
* @return                  void.
*
* @api
*
* @note    Service ID: 0x05.
* @note    Synchronous, non reentrant function.
*
*/
void I2s_AbortTransmit(I2s_LogicalChannel LogicChn);

#if (I2S_VERSION_INFO_API == STD_ON)
/**
* @brief   Returns the version information of this module.
* @details The version information includes:
*
*          - Two bytes for the Vendor ID
*          - Two bytes for the Module ID
*          - One byte  for the Instance ID
*          - Three bytes version number. The numbering shall be vendor
*            specific: it consists of:
*
*             - The major, the minor and the patch version number of
*               the module;
*             - The AUTOSAR specification version number shall not
*               be included. The AUTOSAR specification version number is
*               checked during compile time and therefore not required
*               in this API.
*
* @param[out] pVersionInfo   Pointer for storing the version information
*                            of this module.
*
* @return                  void.
*
* @api
*
* @implements I2s_GetVersionInfo_Activity
*
* @pre            Preconditions as text description. Optional tag.
*
* @note    Service ID: 0x0A.
* @note    Synchronous, non re-entrant function.
*
*/
void I2s_GetVersionInfo(Std_VersionInfoType * pVersionInfo);
#endif /* #if I2S_VERSION_INFO_API == STD_ON */

#define I2S_STOP_SEC_CODE

#include "I2s_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* CDD_I2S_H */

/** @} */
