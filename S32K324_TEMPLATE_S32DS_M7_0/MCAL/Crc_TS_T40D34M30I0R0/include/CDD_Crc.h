/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
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
/* Prevention from multiple including the same header */
#ifndef CDD_CRC_H
#define CDD_CRC_H

/**
*   @file    CDD_Crc.h
*
*   @version 3.0.0
*
*   @brief   AUTOSAR Crc - Crc Ip driver source file.
*   @details
*
*   @addtogroup CRC_HLD_DRIVER
*   @{
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
#include "StandardTypes.h"
#include "Crc_Types.h"
#include "Crc_Cfg.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Crc driver header file and also in the
*        module's description file
*/
#define CDD_CRC_MODULE_ID                      201
#define CDD_CRC_VENDOR_ID                      43
#define CDD_CRC_AR_RELEASE_MAJOR_VERSION       4
#define CDD_CRC_AR_RELEASE_MINOR_VERSION       7
#define CDD_CRC_AR_RELEASE_REVISION_VERSION    0
#define CDD_CRC_SW_MAJOR_VERSION               3
#define CDD_CRC_SW_MINOR_VERSION               0
#define CDD_CRC_SW_PATCH_VERSION               0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files CDD_Crc.h and Crc_Types.h are of the same vendor */
#if (CDD_CRC_VENDOR_ID != CRC_TYPES_VENDOR_ID)
    #error "CDD_Crc.h and Crc_Types.h have different vendor ids"
#endif
/* Check if the files CDD_Crc.h and Crc_Types.h are of the same Autosar version */
#if ((CDD_CRC_AR_RELEASE_MAJOR_VERSION    != CRC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_CRC_AR_RELEASE_MINOR_VERSION    != CRC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CDD_CRC_AR_RELEASE_REVISION_VERSION != CRC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Crc.h and Crc_Types.h are different"
#endif
/* Check if the files CDD_Crc.h and Crc_Types.h are of the same software version */
#if ((CDD_CRC_SW_MAJOR_VERSION != CRC_TYPES_SW_MAJOR_VERSION) || \
     (CDD_CRC_SW_MINOR_VERSION != CRC_TYPES_SW_MINOR_VERSION) || \
     (CDD_CRC_SW_PATCH_VERSION != CRC_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Crc.h and Crc_Types.h are different"
#endif

/* Check if the files CDD_Crc.h and Crc_Cfg.h are of the same vendor */
#if (CDD_CRC_VENDOR_ID != CRC_CFG_VENDOR_ID)
    #error "CDD_Crc.h and Crc_Cfg.h have different vendor ids"
#endif
/* Check if the files CDD_Crc.h and Crc_Cfg.h are of the same Autosar version */
#if ((CDD_CRC_AR_RELEASE_MAJOR_VERSION    != CRC_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CDD_CRC_AR_RELEASE_MINOR_VERSION    != CRC_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CDD_CRC_AR_RELEASE_REVISION_VERSION != CRC_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of CDD_Crc.h and Crc_Cfg.h are different"
#endif
/* Check if the files CDD_Crc.h and Crc_Cfg.h are of the same software version */
#if ((CDD_CRC_SW_MAJOR_VERSION != CRC_CFG_SW_MAJOR_VERSION) || \
     (CDD_CRC_SW_MINOR_VERSION != CRC_CFG_SW_MINOR_VERSION) || \
     (CDD_CRC_SW_PATCH_VERSION != CRC_CFG_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of CDD_Crc.h and Crc_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files CDD_Crc.h and StandardTypes.h are of the same version */
    #if ((CDD_CRC_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (CDD_CRC_AR_RELEASE_MINOR_VERSION  != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CDD_Crc.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief    ID of CRC Instance
* @details  Parameters used when raising an error/exception
*/
#define CRC_INSTANCE_ID                             (0U)


/*-------------------------------------------------------------------------------------------------
 * THE SERVICE ID OF THE CALLER STANDARD FUNCTION
 * ----------------------------------------------------------------------------------------------*/

/**
* @brief    API service ID for Crc_CalculateCRC8 function
* @details  Parameters used when raising an error/exception
*/
#define CRC_CALCULATECRC8_ID                        (1U)

/**
* @brief    API service ID for Crc_CalculateCRC16 function
* @details  Parameters used when raising an error/exception
*/
#define CRC_CALCULATECRC16_ID                       (2U)

/**
* @brief    API service ID for Crc_CalculateCRC32 function
* @details  Parameters used when raising an error/exception
*/
#define CRC_CALCULATECRC32_ID                       (3U)

/**
* @brief    API service ID for Crc_GetVersionInfo function
* @details  Parameters used when raising an error/exception
*/
#define CRC_GETVERSIONINFO_ID                       (4U)

/**
* @brief    API service ID for Crc_CalculateCRC8H2F function
* @details  Parameters used when raising an error/exception
*/
#define CRC_CALCULATECRC8H2F_ID                     (5U)

/**
* @brief    API service ID for Crc_CalculateCRC32P4 function
* @details  Parameters used when raising an error/exception
*/
#define CRC_CALCULATECRC32P4_ID                     (6U)

/**
* @brief    API service ID for Crc_CalculateCRC64 function
* @details  Parameters used when raising an error/exception
*/
#define CRC_CALCULATECRC64_ID                       (7U)

/**
* @brief    API service ID for Crc_CalculateCRC16ARC function
* @details  Parameters used when raising an error/exception
*/
#define CRC_CALCULATECRC16ARC_ID                    (8U)


/*-------------------------------------------------------------------------------------------------
 * THE SERVICE ID OF THE CALLER CDD FUNCTION
 * ----------------------------------------------------------------------------------------------*/

/**
* @brief    API service ID for Crc_Init function
* @details  Parameters used when raising an error/exception
*/
#define CRC_INIT_ID                                 (9U)

/**
* @brief    API service ID for Crc_SetChannelConfig function
* @details  Parameters used when raising an error/exception
*/
#define CRC_SETCHANNELCONFIG_ID                     (10U)

/**
* @brief    API service ID for Crc_SetChannelCalculate function
* @details  Parameters used when raising an error/exception
*/
#define CRC_SETCHANNELCALCULATE_ID                  (11U)

/**
* @brief    API service ID for Crc_GetChannelResult function
* @details  Parameters used when raising an error/exception
*/
#define CRC_GETCHANNELRESULT_ID                     (12U)

/*-------------------------------------------------------------------------------------------------
 * THE ERROR ID TO BE REPORTED
 * -----------------------------------------------------------------------------------------------*/

/**
* @brief        API service is called with wrong channel identifier
* @details      Parameter is used when raising a Det error
* @implements   Crc_ErrorIds_define
*/
#define CRC_E_INVALID_CHANNEL                       (1U)

/**
* @brief        API service is called with NULL pointer parameter
* @details      Parameter is used when raising a Det error
* @implements   Crc_ErrorIds_define
*/
#define CRC_E_INVALID_POINTER                       (2U)

/**
* @brief        The CRC module is not properly configured
* @details      Parameter is used when raising a Det error
* @implements   Crc_ErrorIds_define
* */
#define CRC_E_PARAM_CONFIG                          (3U)

/**
* @brief        The CRC module is not properly initialized
* @details      Parameter is used when raising a Det error
* @implements   Crc_ErrorIds_define
* */
#define CRC_E_INIT_FAILED                           (4U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief         This type contains the CRC Channel Configuration.
* @details       The Channel is identified by the following structure configure parameter for each CRC Channel
* @implements    Crc_ChannelConfigType_structure
*/
typedef Crc_Ip_LogicChannelConfigType Crc_ChannelConfigType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#define CRC_START_SEC_CODE
#include "Crc_MemMap.h"


/**
 * @brief   This service will store the Crc driver installation configuration based on user configuration.
 * @details This service is a non-reentrant function that shall store user configuration.
 *          The initialization is applied for the enabled IPs, configured statically.
 *
 * @param[in] pxCrcInit  - Pointer to the Crc specific configuration structure that contains static configuration.
 *
 * @return void
 *
 * @api
 *
 **/
void Crc_Init(const Crc_InitType * ConfigPtr);


/**
 * @brief   This function initializes the CRC Channel configuration by logicChannel's info
 * @details This service is a reentrant function that shall initialize parameters list for the CRC Channel.
 *          The list is composed of an array of Crc Channel parameters settings.
 *
 * @param[in]  Channel:          - Logic Channel Tag defined by the user.
 * @param[in]  pxChannelConfig:  - Pointer to the Logic Channel Config
 *
 *
 * @return void
 *
 * @api
 *
 **/
void Crc_SetChannelConfig(const uint32 Channel, const Crc_ChannelConfigType * pxChannelConfig);


/**
 * @brief   This function shall start algorithm calculate CRC
 * @details This service is a reentrant function that shall start the Channel to calculate the CRC using the configured algorithm.
 *
 * @param[in]  Channel          - Logic Channel Tag defined by the user.
 * @param[in]  *pCrcData        - Pointer to the Crc Data Input.
 * @param[in]  CrcLength        - Length of crcDataPtr block to be calculated in bytes
 * @param[in]  CrcStartValue    - Start value (seed Value) when the algorithm starts.
 * @param[in]  IsFirstCall      - TRUE: ignore CrcStartValue the initialization value is known by the chosen algorithm.
 *                              - FALSE: initialization CrcStartValue is interpreted to be the return value of the previous function
 *
 * @return - 32 bit result of CRC calculation
 *
 * @api
 *
 **/
uint64 Crc_SetChannelCalculate(const uint32 Channel, const uint8 * pCrcData, const uint32 CrcLength, const uint64 CrcStartValue, const boolean IsFirstCall);


/**
 * @brief   This function get result CRC after finish calculated.
 * @details This service is a function that shall get result CRC calculated by CRC Channel Allocated
 *
 * @param[in]  Channel      - Logic Channel Tag defined by the user.
 *
 * @return  Result of CRC calculation.
 *
 * @api
 *
 **/
uint64 Crc_GetChannelResult(const uint32 Channel);


#if (STD_ON  == CRC_AUTOSAR_LIBRARY_IS_AVAILABLE)
/**
 * @brief   This function calculates CRC8 and returns the result
 * @details This service is a reentrant function that shall perform a CRC8 calculation
 *          on Crc_Length data bytes, pointed to by Crc_DataPtr, with the starting value of Crc_StartValue8
 *
 * @param[in]  *Crc_DataPtr         - Pointer to start address of data block to be calculated.
 * @param[in]  Crc_Length           - Length of data block to be calculated in bytes.
 * @param[in]  Crc_StartValue8      - Length value of the DataPtr.
 * @param[in]  Crc_IsFirstCall      - TRUE: First call in a sequence or individual CRC calculation.
 *                                          Start from initial value, ignore Crc_StartValue8.
 *                                  - FALSE: Subsequent call in a call sequence.
 *                                           Crc_StartValue8 is interpreted to be the return value of the previous function call.
 *
 * @return 8 bit result of CRC calculation.
 *
 * @api
 *
 * */
uint8 Crc_CalculateCRC8(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall);

/**
 * @brief   This function calculates CRC8H2F and returns the result
 * @details This service is a reentrant function that shall perform a CRC8H2F calculation
 *          on Crc_Length data bytes, pointed to by Crc_DataPtr, with the starting value of Crc_StartValue8H2F
 *
 * @param[in]  *Crc_DataPtr         - Pointer to start address of data block to be calculated.
 * @param[in]  Crc_Length           - Length of data block to be calculated in bytes.
 * @param[in]  Crc_StartValue8H2F   - Length value of the DataPtr.
 * @param[in]  Crc_IsFirstCall      - TRUE: First call in a sequence or individual CRC calculation.
 *                                          Start from initial value, ignore Crc_StartValue8H2F.
 *                                  - FALSE: Subsequent call in a call sequence.
 *                                           Crc_StartValue8H2F is interpreted to be the return value of the previous function call.
 *
 * @return 8 bit result of CRC calculation.
 *
 * @api
 *
 * */
uint8 Crc_CalculateCRC8H2F(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8H2F, boolean Crc_IsFirstCall);

/**
 * @brief   This function calculates CRC16 and returns the result
 * @details This service is a reentrant function that shall perform a CRC16 calculation
 *          on Crc_Length data bytes, pointed to by Crc_DataPtr, with the starting value of Crc_StartValue16
 *
 * @param[in]  *Crc_DataPtr         - Pointer to start address of data block to be calculated.
 * @param[in]  Crc_Length           - Length of data block to be calculated in bytes.
 * @param[in]  Crc_StartValue16     - Length value of the DataPtr.
 * @param[in]  Crc_IsFirstCall      - TRUE: First call in a sequence or individual CRC calculation.
 *                                          Start from initial value, ignore Crc_StartValue16.
 *                                  - FALSE: Subsequent call in a call sequence.
 *                                           Crc_StartValue16 is interpreted to be the return value of the previous function call.
 *
 * @return 16 bit result of CRC calculation.
 *
 * @api
 *
 * */
uint16 Crc_CalculateCRC16(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall);

/**
 * @brief   This function calculates CRC16 and returns the result
 * @details This service is a reentrant function that shall perform a CRC16 calculation
 *          on Crc_Length data bytes, pointed to by Crc_DataPtr, with the starting value of Crc_StartValue16
 *
 * @param[in]  *Crc_DataPtr         - Pointer to start address of data block to be calculated.
 * @param[in]  Crc_Length           - Length of data block to be calculated in bytes.
 * @param[in]  Crc_StartValue16     - Length value of the DataPtr.
 * @param[in]  Crc_IsFirstCall      - TRUE: First call in a sequence or individual CRC calculation.
 *                                          Start from initial value, ignore Crc_StartValue16.
 *                                  - FALSE: Subsequent call in a call sequence.
 *                                           Crc_StartValue16 is interpreted to be the return value of the previous function call.
 *
 * @return 16 bit result of CRC calculation.
 *
 * @api
 *
 * */
uint16 Crc_CalculateCRC16ARC(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall);

/**
 * @brief   This function calculates CRC32 and returns the result
 * @details This service is a reentrant function that shall perform a CRC32 calculation
 *          on Crc_Length data bytes, pointed to by Crc_DataPtr, with the starting value of Crc_StartValue32
 *
 * @param[in]  *Crc_DataPtr         - Pointer to start address of data block to be calculated.
 * @param[in]  Crc_Length           - Length of data block to be calculated in bytes.
 * @param[in]  Crc_StartValue32     - Length value of the DataPtr.
 * @param[in]  Crc_IsFirstCall      - TRUE: First call in a sequence or individual CRC calculation.
 *                                          Start from initial value, ignore Crc_StartValue32.
 *                                  - FALSE: Subsequent call in a call sequence.
 *                                           Crc_StartValue32 is interpreted to be the return value of the previous function call.
 *
 * @return 32 bit result of CRC calculation.
 *
 * @api
 *
 * */
uint32 Crc_CalculateCRC32(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall);

/**
 * @brief   This function calculates CRC32P4 and returns the result
 * @details This service is a reentrant function that shall perform a CRC32P4 calculation
 *          on Crc_Length data bytes, pointed to by Crc_DataPtr, with the starting value of Crc_StartValue32
 *
 * @param[in]  *Crc_DataPtr         - Pointer to start address of data block to be calculated.
 * @param[in]  Crc_Length           - Length of data block to be calculated in bytes.
 * @param[in]  Crc_StartValue32     - Length value of the DataPtr.
 * @param[in]  Crc_IsFirstCall      - TRUE: First call in a sequence or individual CRC calculation.
 *                                          Start from initial value, ignore Crc_StartValue32.
 *                                  - FALSE: Subsequent call in a call sequence.
 *                                           Crc_StartValue32 is interpreted to be the return value of the previous function call.
 *
 * @return 32 bit result of CRC calculation.
 *
 * @api
 *
 * */
uint32 Crc_CalculateCRC32P4(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall);

/**
 * @brief   This function calculates CRC64 and returns the result
 * @details This service is a reentrant function that shall perform a CRC64 calculation
 *          on Crc_Length data bytes, pointed to by Crc_DataPtr, with the starting value of Crc_StartValue64
 *
 * @param[in]  *Crc_DataPtr         - Pointer to start address of data block to be calculated.
 * @param[in]  Crc_Length           - Length of data block to be calculated in bytes.
 * @param[in]  u64Crc_StartValue    - Length value of the DataPtr.
 * @param[in]  Crc_IsFirstCall      - TRUE: First call in a sequence or individual CRC calculation.
 *                                          Start from initial value, ignore Crc_StartValue64.
 *                                  - FALSE: Subsequent call in a call sequence.
 *                                           Crc_StartValue64 is interpreted to be the return value of the previous function call.
 *
 * @return 64 bit result of CRC calculation.
 *
 * @api
 *
 * */
uint64 Crc_CalculateCRC64(const uint8 *Crc_DataPtr, uint32 Crc_Length, uint64 Crc_StartValue64, boolean Crc_IsFirstCall);

#endif /* #if (CRC_AUTOSAR_LIBRARY_IS_AVAILABLE  == STD_ON) */

#if (STD_ON == CRC_VERSION_INFO_API_ENABLE)
/**
 * @brief   Software module version query.
 * @details Returns the version information of this module
 *
 * @param[in]  pVersionInfo    - Pointer to get Version Information
 *
 * @return void
 *
 * @api
 *
 **/
void Crc_GetVersionInfo(Std_VersionInfoType *pVersionInfo);
#endif /* CRC_VERSION_INFO_API_ENABLE == STD_ON */


#define CRC_STOP_SEC_CODE
#include "Crc_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CDD_CRC_H */
