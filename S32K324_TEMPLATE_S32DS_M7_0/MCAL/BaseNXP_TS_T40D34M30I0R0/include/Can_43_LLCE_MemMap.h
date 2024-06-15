/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : S32K3XX
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

/**
*   @file Can_43_llce_MemMap.h
*   @implements     MemMap.h_Artifact
*   @brief   Memory mapping specification.
*   @details This document specifies mechanisms for the mapping of code and data to specific
*            memory sections via memory mapping file. For many ECUs and microcontroller platforms
*            it is of utmost necessity to be able to map code, variables and constants module
*            wise to specific memory sections.
*            This file contains sample code only. It is not part of the production code deliverables.
*   @addtogroup BASENXP_COMPONENT
*   @{
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
#include "CompilerDefinition.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @brief Parameters that shall be published within the memory map header file and also in the
*       module's description file
*/
#define CAN_43_LLCE_MEMMAP_VENDOR_ID                    43
#define CAN_43_LLCE_MEMMAP_AR_RELEASE_MAJOR_VERSION     4
#define CAN_43_LLCE_MEMMAP_AR_RELEASE_MINOR_VERSION     7
#define CAN_43_LLCE_MEMMAP_AR_RELEASE_REVISION_VERSION  0
#define CAN_43_LLCE_MEMMAP_SW_MAJOR_VERSION             3
#define CAN_43_LLCE_MEMMAP_SW_MINOR_VERSION             0
#define CAN_43_LLCE_MEMMAP_SW_PATCH_VERSION             0
/**@}*/
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/**
* @brief Symbol used for checking correctness of the includes
*/
#define MEMMAP_ERROR

/**************************************************************************************************/
/********************************************* GREENHILLS *****************************************/
/**************************************************************************************************/
#ifdef _GREENHILLS_C_S32K3XX_
/**************************************** CAN_43_LLCE *******************************/
#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section rodata=".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".mcal_text"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_RAMCODE
    #define ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_RAMCODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".ramcode"
    #pragma ghs inlineprologue
    #pragma ghs callmode=far
#endif

#ifdef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
    #pragma ghs callmode=default
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE_AC
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE_AC
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section text=".accan_43_llce_code_rom"
    #pragma ghs inlineprologue
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
    #pragma ghs noinlineprologue
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data" bss=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data" bss=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data" bss=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data" bss=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data" bss=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data_no_cacheable" bss=".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data_no_cacheable"  bss=".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data_no_cacheable"  bss=".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data_no_cacheable"  bss=".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_data_no_cacheable"  bss=".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".dma_dest_buffer_bss" data=".dma_dest_buffer"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".dma_dest_buffer_bss" data=".dma_dest_buffer"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section data=".mcal_shared_data" bss=".mcal_shared_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".mcal_shared_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif
#ifdef CAN_43_LLCE_START_SEC_ENDBOOT
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_ENDBOOT
    #define ENTERED_CAN_43_LLCE_START_SEC_ENDBOOT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_ENDBOOT
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".llce_boot_end"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_ENDBOOT
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_ENDBOOT
        #undef ENTERED_CAN_43_LLCE_START_SEC_ENDBOOT
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_ENDBOOT
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif

#ifdef CAN_43_LLCE_START_SEC_SHAREDMEMORY
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_SHAREDMEMORY
    #define ENTERED_CAN_43_LLCE_START_SEC_SHAREDMEMORY
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_SHAREDMEMORY
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section bss=".can_43_llce_sharedmemory"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_SHAREDMEMORY
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_SHAREDMEMORY
        #undef ENTERED_CAN_43_LLCE_START_SEC_SHAREDMEMORY
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_SHAREDMEMORY
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma ghs section
#endif
/**************************************************************************************************/
/********************************************* DIAB ***********************************************/
/**************************************************************************************************/
#elif defined(_DIABDATA_C_S32K3XX_)
/**************************************** CAN_43_LLCE *******************************/
#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=".mcal_const_cfg"
    #else
        #pragma section CONST ".mcal_const_cfg"
    #endif    
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section CONST
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=".mcal_const_cfg"
    #else
        #pragma section CONST ".mcal_const_cfg"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section CONST
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=".mcal_const_cfg"
    #else
        #pragma section CONST ".mcal_const_cfg"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section CONST
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=".mcal_const_cfg"
    #else
        #pragma section CONST ".mcal_const_cfg"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section CONST
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=".mcal_const_no_cacheable"
    #else
        #pragma section CONST ".mcal_const_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=".mcal_const_no_cacheable"
    #else
        #pragma section CONST ".mcal_const_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=".mcal_const_no_cacheable"
    #else
        #pragma section CONST ".mcal_const_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=".mcal_const_no_cacheable"
    #else
        #pragma section CONST ".mcal_const_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=".mcal_const"
    #else
        #pragma section CONST ".mcal_const"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section CONST
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=".mcal_const"
    #else
        #pragma section CONST ".mcal_const"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section CONST
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=".mcal_const"
    #else
        #pragma section CONST ".mcal_const"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section CONST
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=".mcal_const"
    #else
        #pragma section CONST ".mcal_const"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section CONST
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=".mcal_const"
    #else
        #pragma section CONST ".mcal_const"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section CONST
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata="" text=".mcal_text"
    #else
    /* no definition -> default compiler settings are used */
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata="" text=""
    #else
    /* no definition -> default compiler settings are used */
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_RAMCODE
    #define ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_RAMCODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata="" text=".ramcode"
    #else
        #pragma section CODE ".ramcode" far-absolute
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata="" text=""
    #else
        #pragma section CODE
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE_AC
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE_AC
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* use code relative addressing mode to ensure Position-independent Code (PIC) */
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata="" text=".accan_43_llce_code_rom"
    #else
        #pragma section CODE ".accan_43_llce_code_rom" far-code 
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* default section for CODE */
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata="" text=""
    #else
        #pragma section CODE
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
    #else
        #pragma section DATA ".mcal_data" ".mcal_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
    #else
        #pragma section DATA ".mcal_data" ".mcal_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
    #else
        #pragma section DATA ".mcal_data" ".mcal_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
    #else
        #pragma section DATA ".mcal_data" ".mcal_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
    #else
        #pragma section DATA ".mcal_data" ".mcal_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
    #else
        #pragma section DATA ".mcal_data" ".mcal_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata="" 
    #else
        #pragma section DATA 
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
    #else
        #pragma section DATA ".mcal_data" ".mcal_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata="" 
    #else
        #pragma section DATA 
    #endif
#endif


#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
    #else
        #pragma section DATA ".mcal_data" ".mcal_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata="" 
    #else
        #pragma section DATA 
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
    #else
        #pragma section DATA ".mcal_data" ".mcal_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata="" 
    #else
        #pragma section DATA 
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss" data=".mcal_data" rodata=""
    #else
        #pragma section DATA ".mcal_data" ".mcal_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata="" 
    #else
        #pragma section DATA 
    #endif
#endif


#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
    #else
        #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata="" 
    #else
        #pragma section DATA 
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
    #else
        #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
    #else
        #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
    #else
        #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
    #else
        #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
    #else
        #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
    #else
        #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif


#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
    #else
        #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
    #else
        #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".mcal_bss_no_cacheable" data=".mcal_data_no_cacheable" rodata=""
    #else
        #pragma section DATA ".mcal_data_no_cacheable" ".mcal_bss_no_cacheable"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss=".dma_dest_buffer_bss" data=".dma_dest_buffer" rodata=""
    #else
        #pragma section DATA ".dma_dest_buffer" ".dma_dest_buffer_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss=".dma_dest_buffer_bss" data=".dma_dest_buffer" rodata=""
    #else
        #pragma section DATA ".dma_dest_buffer" ".dma_dest_buffer_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss=".mcal_shared_bss" data=".mcal_shared_data" rodata=""
    #else
        #pragma section DATA ".mcal_shared_data" ".mcal_shared_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__
        #pragma clang section bss=".mcal_shared_bss" data=".mcal_shared_data" rodata=""
    #else
        #pragma section DATA ".mcal_shared_data" ".mcal_shared_bss"
    #endif
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #ifdef __clang__        
        #pragma clang section bss="" data="" rodata=""
    #else
        #pragma section DATA
    #endif
#endif
/**************************************************************************************************/
/********************************************* CODEWARRIOR ****************************************/
/**************************************************************************************************/
#elif defined(_CODEWARRIOR_C_S32K3XX_)
/**************************************** CAN_43_LLCE *******************************/
#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const_cfg
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG .mcal_const_no_cacheable
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG .mcal_const_no_cacheable
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG .mcal_const_no_cacheable
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG .mcal_const_no_cacheable
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG mcal_const
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CONST_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG mcal_text
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_RAMCODE
    #define ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_RAMCODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG ramcode
#endif

#ifdef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE_AC
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE_AC
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG accan_43_llce_code_rom
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma CODE_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG mcal_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG dma_dest_buffer_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG dma_dest_buffer
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG .mcal_shared_data
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif


#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG .mcal_shared_bss
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma DATA_SEG DEFAULT
#endif

/**************************************************************************************************/
/********************************************* HighTec *********************************************/
/**************************************************************************************************/
#elif defined(_HITECH_C_S32K3XX_)
/**************************************** CAN_43_LLCE *******************************/
#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const_cfg" a
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const_cfg" a
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const_cfg" a
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const_cfg" a
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const" a
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const" a
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const" a
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const" a
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_const" a
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_text" avx
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_RAMCODE
    #define ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_RAMCODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".ramcode" avx
#endif

#ifdef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma  section
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE_AC
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE_AC
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".accan_43_llce_code_rom" avx
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma  section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss" awsB
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss" awsB
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss" awsB
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss" awsB
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss" awsB
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_bss_no_cacheable" awsB
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_data" aws
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_data" aws
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_data" aws
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_data" aws
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_data" aws
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".dma_dest_buffer_bss" aws
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".dma_dest_buffer" aws
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_shared_data" aws
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section ".mcal_shared_bss" aws
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma section
#endif
/**************************************************************************************************/
/********************************************* Linaro *********************************************/
/**************************************************************************************************/
#elif defined(_LINARO_C_S32K3XX_)
/**************************************** CAN_43_LLCE *******************************/
#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata 
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata 
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata ".mcal_const" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section rodata
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".mcal_text" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text
#endif

#ifdef CAN_43_LLCE_START_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_RAMCODE
    #define ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_RAMCODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".ramcode" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE_AC
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE_AC
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text ".acfls_code_rom" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section text
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data" 
    #pragma GCC section bss ".mcal_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss 
    #pragma GCC section data 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data" 
    #pragma GCC section bss ".mcal_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss 
    #pragma GCC section data 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data" 
    #pragma GCC section bss ".mcal_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss 
    #pragma GCC section data 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data" 
    #pragma GCC section bss ".mcal_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss 
    #pragma GCC section data 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data" 
    #pragma GCC section bss ".mcal_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss 
    #pragma GCC section data 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data_no_cacheable" 
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
    #pragma GCC section data
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data_no_cacheable" 
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
    #pragma GCC section data
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data_no_cacheable" 
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
    #pragma GCC section data
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data_no_cacheable" 
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
    #pragma GCC section data
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data_no_cacheable" 
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
    #pragma GCC section data
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_bss_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_data_no_cacheable" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data ".mcal_shared_data" 
    #pragma GCC section bss ".mcal_shared_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section data
    #pragma GCC section bss
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".mcal_shared_bss" 
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
#endif
#ifdef CAN_43_LLCE_START_SEC_ENDBOOT
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_ENDBOOT
    #define ENTERED_CAN_43_LLCE_START_SEC_ENDBOOT
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_ENDBOOT
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".llce_boot_end"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_ENDBOOT
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_ENDBOOT
        #undef ENTERED_CAN_43_LLCE_START_SEC_ENDBOOT
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_ENDBOOT
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
#endif

#ifdef CAN_43_LLCE_START_SEC_SHAREDMEMORY
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_SHAREDMEMORY
    #define ENTERED_CAN_43_LLCE_START_SEC_SHAREDMEMORY
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_SHAREDMEMORY
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss ".can_43_llce_sharedmemory"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_SHAREDMEMORY
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_SHAREDMEMORY
        #undef ENTERED_CAN_43_LLCE_START_SEC_SHAREDMEMORY
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_SHAREDMEMORY
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma GCC section bss
#endif
/**************************************************************************************************/
/********************************************* DS5 ************************************************/
/**************************************************************************************************/
#elif defined(_ARM_DS5_C_S32K3XX_)
/**************************************** CAN_43_LLCE *******************************/
#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rodata=".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section code=".mcal_text"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_RAMCODE
    #define ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_RAMCODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section code=".ramcode"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE_AC
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE_AC
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section code=".accan_43_llce_code_rom"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".dma_dest_buffer_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".dma_dest_buffer"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section rwdata=".mcal_shared_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma arm section zidata=".mcal_shared_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    /* no definition -> default compiler settings are used */
#endif
/**************************************************************************************************/
/********************************************* IAR ************************************************/
/**************************************************************************************************/
#elif defined(_IAR_C_S32K3XX_)
/**************************************** CAN_43_LLCE *******************************/
#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_cfg"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONFIG_DATA_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_8
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_16
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_32
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_const"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_CONST_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CONST_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".mcal_text"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_RAMCODE
    #define ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_RAMCODE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".ramcode"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
        #undef ENTERED_CAN_43_LLCE_START_SEC_RAMCODE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_RAMCODE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_CODE_AC
    #define ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_CODE_AC
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = @ ".accan_43_llce_code_rom"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
        #undef ENTERED_CAN_43_LLCE_START_SEC_CODE_AC
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_CODE_AC
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_function_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_bss_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_BOOLEAN_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_8_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_8_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_16_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_16_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_32_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_32_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes =
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
   #pragma default_variable_attributes = @ ".mcal_data_no_cacheable"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".dma_dest_buffer_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_CLEARED_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".dma_dest_buffer"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_INIT_UNSPECIFIED_AE_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_shared_data"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_INIT_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif

#ifdef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #define ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #ifndef MEMMAP_MATCH_ERROR
        #define MEMMAP_MATCH_ERROR
    #else
        #ifndef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #error "MemMap.h, no valid matching start-stop section defined."
        #endif
    #endif
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = @ ".mcal_shared_bss"
#endif

#ifdef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #ifdef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
        #undef ENTERED_CAN_43_LLCE_START_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    #else
        #error "MemMap.h, no valid matching start-stop section defined."
    #endif
    #ifdef MEMMAP_MATCH_ERROR
        #undef MEMMAP_MATCH_ERROR
    #endif
    #undef CAN_43_LLCE_STOP_SEC_VAR_SHARED_CLEARED_UNSPECIFIED_NO_CACHEABLE
    /**
    * @file Can_43_llce_MemMap.h
    */
    #undef MEMMAP_ERROR
    #pragma default_variable_attributes = 
#endif
#endif 
/**************************************************************************************************/
/****************************************** Report error ******************************************/
/**************************************************************************************************/
#ifdef MEMMAP_ERROR
    #error "MemMap.h, no valid memory mapping symbol defined."
#endif
                                                                                                     
/*================================================================================================== 
*                                            ENUMS                                                   
==================================================================================================*/ 
                                                                                                     
/*================================================================================================== 
*                                 STRUCTURES AND OTHER TYPEDEFS                                      
==================================================================================================*/ 
                                                                                                     
/*================================================================================================== 
*                                 GLOBAL VARIABLE DECLARATIONS                                       
==================================================================================================*/ 
                                                                                                     
/*================================================================================================== 
*                                     FUNCTION PROTOTYPES                                            
==================================================================================================*/ 
                                                                                                     
#ifdef __cplusplus                                                                                   
}                                                                                                    
#endif                                                                                               
                                                                                                     
/** @} */                                                                                            
