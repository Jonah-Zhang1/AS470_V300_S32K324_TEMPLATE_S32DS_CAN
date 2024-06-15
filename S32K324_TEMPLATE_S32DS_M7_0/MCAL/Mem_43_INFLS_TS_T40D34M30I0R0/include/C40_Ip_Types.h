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

#ifndef C40_DRIVER_TYPES_H
#define C40_DRIVER_TYPES_H

/**
 * @file       C40_Ip_Types.h
 *
 * @addtogroup C40_IP
 * implement   C40_Ip_Types.h_Artifact
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
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define C40_IP_TYPES_VENDOR_ID_CFG                    43
#define C40_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG     4
#define C40_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG     7
#define C40_IP_TYPES_AR_RELEASE_REVISION_VERSION_CFG  0
#define C40_IP_TYPES_SW_MAJOR_VERSION_CFG             3
#define C40_IP_TYPES_SW_MINOR_VERSION_CFG             0
#define C40_IP_TYPES_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if C40_Ip_Types header file and StandardTypes.h header file are of the same Autosar version */
    #if ((C40_IP_TYPES_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (C40_IP_TYPES_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Autosar Version Numbers of C40_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief  Each sector has a size of 8k
 */
#define C40_SECTOR_SIZE           8192U
/**
 * @brief  Code sectors base address
 */
#define C40_CODE_BASE_ADDRESS     0x00400000U
/**
 * @brief  Data sectors base address
 */
#define C40_DATA_BASE_ADDRESS     0x10000000U
/**
 * @brief  Data sectors end address
 */
#define C40_DATA_END_ADDRESS      0x1003FFFFU
/**
 * @brief  UTest sector base address
 */
#define C40_UTEST_BASE_ADDRESS    0x1B000000U
/**
 * @brief  Program alignment
 */
#define C40_WRITE_DOUBLE_WORD     8U
/**
 * @brief  Main interface program data registers (DATA0 - DATA31)
 */
#define C40_DATA_SIZE_BYTES_U32   128U


/**
 * @brief  For UTE bit, the password 0xF9F9_9999 must be written to the UT0 register, and this must be a 32bit write
 */
#define C40_USER_TEST_PASSWORD   (0xF9F99999U)
/**
 * @brief  Time out for wait done
 */
#define FLASH_USER_TEST_WAIT     (450U)

/**
 * @brief the number of bytes uses to compare (1 byte).
 */
#define FLS_SIZE_1BYTE      1U

/**
 * @brief the number of bytes uses to compare (2 bytes).
 */
#define FLS_SIZE_2BYTE      2U

/**
 * @brief the number of bytes uses to compare (4 bytes).
 */
#define FLS_SIZE_4BYTE      4U


/*==================================================================================================
                                 ENUM TYPEDEFS
==================================================================================================*/

/*!
 * @brief C40 hardware instance
 */
typedef enum
{
    C40_IP_INSTANCE_0 = 0x00U,  /*!< C40 hardware instance 0 */
} C40_Ip_InstanceType;

/*!
 * @brief Enumeration of checking status errors or not.
 */
typedef enum
{
    STATUS_C40_IP_SUCCESS                   = 0x00U,    /*!< Successful job */
    STATUS_C40_IP_BUSY                      = 0x01U,    /*!< IP is performing an operation */
    STATUS_C40_IP_ERROR                     = 0x02U,    /*!< Error - general code */
    STATUS_C40_IP_ERROR_TIMEOUT             = 0x03U,    /*!< Error - exceeded timeout */
    STATUS_C40_IP_ERROR_INPUT_PARAM         = 0x04U,    /*!< Error - wrong input parameter */
    STATUS_C40_IP_ERROR_BLANK_CHECK         = 0x05U,    /*!< Error - selected memory area is not erased */
    STATUS_C40_IP_ERROR_PROGRAM_VERIFY      = 0x06U,    /*!< Error - selected memory area doesn't contain desired value */
    STATUS_C40_IP_ERROR_USER_TEST_BREAK_SBC = 0x07U,    /*!< Error - single bit correction */
    STATUS_C40_IP_ERROR_USER_TEST_BREAK_DBD = 0x08U,    /*!< Error - double bit detection */
    STATUS_C40_IP_SECTOR_UNPROTECTED        = 0x09U,    /*!< Checked sector is unlocked */
    STATUS_C40_IP_SECTOR_PROTECTED          = 0x0AU,    /*!< Checked sector is locked */
    STATUS_C40_IP_ECC_UNCORRECTED           = 0x0BU,    /*!< Ecc uncorrected error */
    STATUS_C40_IP_ECC_CORRECTED             = 0x0CU     /*!< Ecc corrected error */
} C40_Ip_StatusType;

/*!
 * @brief Enumeration of Blocks of memory flash .
 */
typedef enum
{
    FLS_CODE_BLOCK_0  = 0x00U,  /*!< code block number 0 */
    FLS_CODE_BLOCK_1  = 0x01U,  /*!< code block number 1 */
    FLS_CODE_BLOCK_2  = 0x02U,  /*!< code block number 2 */
    FLS_CODE_BLOCK_3  = 0x03U,  /*!< code block number 3 */
    FLS_DATA_BLOCK    = 0x04U,  /*!< data block          */
    FLS_BLOCK_UTEST   = 0x05U,  /*!< block Utest         */
    FLS_BLOCK_INVALID = 0xFFU   /*!< invalid block       */
} C40_Ip_FlashBlocksNumberType;

/*!
 * @brief Enumeration breakpoints .
 */
typedef enum
{
    FLS_BREAKPOINTS_ON_DBD = 0U, /*!< Break on Double bit detection */
    FLS_BREAKPOINTS_ON_DBD_SBC,  /*!< Break on both Double bit detection and Single bit correction */
    FLS_NO_BREAKPOINTS           /*!< No break at all */
} C40_Ip_FlashBreakPointsType;

/*!
 * @brief Enumeration of Array Integrity Sequence(proprietary sequence or sequential) .
 */
typedef enum
{
    FLS_PROPRIETARY_SEQENCE = 0U, /*!< Array integrity sequence is proprietary sequence */
    FLS_SEQUENTIAL                /*!< Array integrity sequence is sequential */
} C40_Ip_ArrayIntegritySequenceType;

/*!
 * @brief Declarations of margin levels.
 *
 * This is used to selects the margin level that is being checked.
 * implement  : C40_Ip_MarginOptionType_Class
 */
typedef enum
{
    C40_MARGIN_LEVEL_PROGRAM    = 0x00U,   /*!< a programmed level */
    C40_MARGIN_LEVEL_ERASE      = 0x01U    /*!< a erased level */
} C40_Ip_MarginOptionType;

/*!
 * @brief Declarations for flash suspend operation and resume operation and user test check state.
 *
 * This is used to indicators for suspending state, resuming state and operation is broken by
 * single bit correction or double bit detection.
 * implement  : C40_Ip_UtestStateType
 */
typedef enum
{
    C40_IP_OK                           = 0x00U,   /*!< Successful operation */
    C40_IP_SUS_NOTHING                  = 0x10U,   /*!< No program/erase operation */
    C40_IP_PGM_WRITE                    = 0x11U,   /*!< A program sequence in interlock write stage. */
    C40_IP_ERS_WRITE                    = 0x12U,   /*!< An erase sequence in interlock write stage. */
    C40_IP_ERS_SUS_PGM_WRITE            = 0x13U,   /*!< An erase-suspend program sequence in interlock write stage. */
    C40_IP_PGM_SUS                      = 0x14U,   /*!< The program operation is in suspend state */
    C40_IP_ERS_SUS                      = 0x15U,   /*!< The erase operation is in suspend state */
    C40_IP_ERS_SUS_PGM_SUS              = 0x16U,   /*!< The erase-suspended program operation is in suspend state */
    C40_IP_USER_TEST_SUS                = 0x17U,   /*!< The UTest check operation is in suspend state C40_IP */
    C40_IP_RES_NOTHING                  = 0x20U,   /*!< No suspended program/erase operation */
    C40_IP_RES_PGM                      = 0x21U,   /*!< The program operation is resumed */
    C40_IP_RES_ERS                      = 0x22U,   /*!< The erase operation is resumed */
    C40_IP_RES_ERS_PGM                  = 0x23U,   /*!< The erase-suspended program operation is resumed */
    C40_IP_RES_USER_TEST                = 0x24U,   /*!< The UTest check operation is resumed C40_IP */
    C40_IP_USER_TEST_BREAK_SBC          = 0x30U,   /*!< The UTest check operation is broken by Single bit correction */
    C40_IP_USER_TEST_BREAK_DBD          = 0x31U    /*!< The UTest check operation is broken by Double bit detection */
} C40_Ip_UtestStateType;


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*!
 * @brief MISR structure.
 * implement  : C40_Ip_MisrType_Class
 */
typedef struct
{
    uint32 arrMISRValue[10U];    /*!< The value of MISR, size of arrMISRValue is (FLASH_UM_COUNT +1) */
} C40_Ip_MisrType;
/**
 * @brief       Fls Start Flash Access Notification Pointer Type
 * @details     Pointer type of Fls_StartFlashAccessNotif function
 */
typedef void (*C40_StartFlashAccessNotifPtrType)(void);

/**
 * @brief       Fls Finished Flash Access Notification Pointer Type
 * @details     Pointer type of Fls_FinishedFlashAccessNotif function
 */
typedef void (*C40_FinishedFlashAccessNotifPtrType)(void);

/*!
 * @brief       C40 Configuration Structure
 *
 * implement  : C40_ConfigType_Class
 */
typedef struct
{
    C40_StartFlashAccessNotifPtrType       startFlashAccessNotifPtr;            /*!< Pointer to start flash access callout  */
    C40_FinishedFlashAccessNotifPtrType    finishedFlashAccessNotifPtr;         /*!< Pointer to finish flash access callout */
} C40_ConfigType;


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* C40_DRIVER_TYPES_H */
