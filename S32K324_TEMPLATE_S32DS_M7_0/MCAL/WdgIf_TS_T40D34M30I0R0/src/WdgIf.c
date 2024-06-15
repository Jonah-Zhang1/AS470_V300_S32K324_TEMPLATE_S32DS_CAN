/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : generic
*   Dependencies         : 
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
*   @file WdgIf.c
*
*   @addtogroup WdgIf
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif




/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "WdgIf.h"

#if (USE_WDG_INSTANCE_ANY == STD_ON)

    #ifdef WDG_INSTANCE0
    #if (WDG_INSTANCE0 == STD_ON)
        #include "Wdg_43_Instance0.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE1
    #if (WDG_INSTANCE1 == STD_ON)
        #include "Wdg_43_Instance1.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE2
    #if (WDG_INSTANCE2 == STD_ON)
        #include "Wdg_43_Instance2.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE3
    #if (WDG_INSTANCE3 == STD_ON)
        #include "Wdg_43_Instance3.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE4
    #if (WDG_INSTANCE4 == STD_ON)
        #include "Wdg_43_Instance4.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE5
    #if (WDG_INSTANCE5 == STD_ON)
        #include "Wdg_43_Instance5.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE6
    #if (WDG_INSTANCE6 == STD_ON)
        #include "Wdg_43_Instance6.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE7
    #if (WDG_INSTANCE7 == STD_ON)
        #include "Wdg_43_Instance7.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE8
    #if (WDG_INSTANCE8 == STD_ON)
        #include "Wdg_43_Instance8.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE9
    #if (WDG_INSTANCE9 == STD_ON)
        #include "Wdg_43_Instance9.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE10
    #if (WDG_INSTANCE10 == STD_ON)
        #include "Wdg_43_Instance10.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE11
    #if (WDG_INSTANCE11 == STD_ON)
        #include "Wdg_43_Instance11.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE12
    #if (WDG_INSTANCE12 == STD_ON)
        #include "Wdg_43_Instance12.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE13
    #if (WDG_INSTANCE13 == STD_ON)
        #include "Wdg_43_Instance13.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE14
    #if (WDG_INSTANCE14 == STD_ON)
        #include "Wdg_43_Instance14.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE15
    #if (WDG_INSTANCE15 == STD_ON)
        #include "Wdg_43_Instance15.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE16
    #if (WDG_INSTANCE16 == STD_ON)
        #include "Wdg_43_Instance16.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE17
    #if (WDG_INSTANCE17 == STD_ON)
        #include "Wdg_43_Instance17.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE18
    #if (WDG_INSTANCE18 == STD_ON)
        #include "Wdg_43_Instance18.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE19
    #if (WDG_INSTANCE19 == STD_ON)
        #include "Wdg_43_Instance19.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE20
    #if (WDG_INSTANCE20 == STD_ON)
        #include "Wdg_43_Instance20.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE21
    #if (WDG_INSTANCE21 == STD_ON)
        #include "Wdg_43_Instance21.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE22
    #if (WDG_INSTANCE22 == STD_ON)
        #include "Wdg_43_Instance22.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE23
    #if (WDG_INSTANCE23 == STD_ON)
        #include "Wdg_43_Instance23.h"
    #endif
    #endif

    #ifdef WDG_INSTANCE24
    #if (WDG_INSTANCE24 == STD_ON)
        #include "Wdg_43_Instance24.h"
    #endif
    #endif

#endif

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define WDGIF_VENDOR_ID_C                      43
#define WDGIF_AR_RELEASE_MAJOR_VERSION_C       4
#define WDGIF_AR_RELEASE_MINOR_VERSION_C       7
/** @violates @ref WdgIf_C_REF_1 The compiler/linker shall be checked to ensure that 31
    character significance and case sensitivity are supported for external identifiers. */
#define WDGIF_AR_RELEASE_REVISION_VERSION_C    0
#define WDGIF_SW_MAJOR_VERSION_C               3
#define WDGIF_SW_MINOR_VERSION_C               0
#define WDGIF_SW_PATCH_VERSION_C               0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if current file and WDGIF header file are of the same vendor.*/
#if (WDGIF_VENDOR_ID_C != WDGIF_VENDOR_ID)
    #error "WdgIf.c and WdgIf.h have different vendor ids"
#endif

/* Check if current file and WDGIF header file are of the same Autosar version.*/
#if ((WDGIF_AR_RELEASE_MAJOR_VERSION_C    != WDGIF_AR_RELEASE_MAJOR_VERSION) || \
     (WDGIF_AR_RELEASE_MINOR_VERSION_C    != WDGIF_AR_RELEASE_MINOR_VERSION) || \
     (WDGIF_AR_RELEASE_REVISION_VERSION_C != WDGIF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of WdgIf.c and WdgIf.h are different"
#endif

/* Check if current file and WDGIF header file are of the same Software version.*/
#if ((WDGIF_SW_MAJOR_VERSION_C != WDGIF_SW_MAJOR_VERSION) || \
     (WDGIF_SW_MINOR_VERSION_C != WDGIF_SW_MINOR_VERSION) || \
     (WDGIF_SW_PATCH_VERSION_C != WDGIF_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of WdgIf.c and WdgIf.h are different"
#endif

#if (USE_WDG_INSTANCE_ANY == STD_ON)
#ifdef WDG_INSTANCE0
#if (WDG_INSTANCE0 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance0 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE0_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE0_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance0.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE1
#if (WDG_INSTANCE1 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance1 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE1_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE1_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance1.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE2
#if (WDG_INSTANCE2 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance2 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE2_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE2_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance2.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE3
#if (WDG_INSTANCE3 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance3 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE3_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE3_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance3.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE4
#if (WDG_INSTANCE4 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance4 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE4_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE4_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance4.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE5
#if (WDG_INSTANCE5 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance5 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE5_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE5_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance5.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE6
#if (WDG_INSTANCE6 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance6 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE6_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE6_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance6.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE7
#if (WDG_INSTANCE7 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance7 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE7_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE7_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance7.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE8
#if (WDG_INSTANCE8 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance8 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE8_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE8_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance8.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE9
#if (WDG_INSTANCE9 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance9 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE9_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE9_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance9.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE10
#if (WDG_INSTANCE10 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance10 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE10_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE10_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance10.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE11
#if (WDG_INSTANCE11 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance11 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE11_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE11_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance11.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE12
#if (WDG_INSTANCE12 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance12 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE12_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE12_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance12.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE13
#if (WDG_INSTANCE13 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance13 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE13_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE13_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance13.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE14
#if (WDG_INSTANCE14 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance14 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE14_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE14_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance14.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE15
#if (WDG_INSTANCE15 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance15 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE15_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE15_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance15.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE16
#if (WDG_INSTANCE16 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance16 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE16_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE16_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance16.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE17
#if (WDG_INSTANCE17 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance17 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE17_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE17_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance17.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE18
#if (WDG_INSTANCE18 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance18 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE18_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE18_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance18.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE19
#if (WDG_INSTANCE19 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance19 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE19_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE19_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance19.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE20
#if (WDG_INSTANCE20 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance20 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE20_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE20_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance20.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE21
#if (WDG_INSTANCE21 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance21 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE21_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE21_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance21.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE22
#if (WDG_INSTANCE22 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance22 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE22_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE22_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance22.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE23
#if (WDG_INSTANCE23 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance23 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE23_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE23_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance23.h are different"
     #endif
#endif
#endif
#endif

#ifdef WDG_INSTANCE24
#if (WDG_INSTANCE24 == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if source file and Wdg instance24 header file are of the same Autosar version */
     #if (( WDGIF_AR_RELEASE_MAJOR_VERSION_C != WDG_43_INSTANCE24_AR_RELEASE_MAJOR_VERSION) || \
          ( WDGIF_AR_RELEASE_MINOR_VERSION_C != WDG_43_INSTANCE24_AR_RELEASE_MINOR_VERSION))
         #error "AutoSar Version Numbers of Wdg_Channel.c and Wdg_43_Instance24.h are different"
     #endif
#endif
#endif
#endif

#endif
/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/

#if (USE_WDG_INSTANCE_ANY == STD_ON)
const WdgIf_SetModeFctPtrType WdgIf_SetModeFctPtr[WDGIF_NUMBER_OF_DEVICES] =
    {
    #if(WDG_INSTANCE0 == STD_ON)
            Wdg_43_Instance0_SetMode
            #else
            NULL_PTR
        #endif
    #if (WDGIF_NUMBER_OF_DEVICES>1)
        #ifdef WDG_INSTANCE1
            #if(WDG_INSTANCE1 == STD_ON)
            ,Wdg_43_Instance1_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>2)
        #ifdef WDG_INSTANCE2
            #if(WDG_INSTANCE2 == STD_ON)
            ,Wdg_43_Instance2_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>3)
        #ifdef WDG_INSTANCE3
            #if(WDG_INSTANCE3 == STD_ON)
            ,Wdg_43_Instance3_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>4)
        #ifdef WDG_INSTANCE4
            #if(WDG_INSTANCE4 == STD_ON)
            ,Wdg_43_Instance4_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>5)
        #ifdef WDG_INSTANCE5
            #if(WDG_INSTANCE5 == STD_ON)
            ,Wdg_43_Instance5_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>6)
        #ifdef WDG_INSTANCE6
            #if(WDG_INSTANCE6 == STD_ON)
            ,Wdg_43_Instance6_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>7)
        #ifdef WDG_INSTANCE7
            #if(WDG_INSTANCE7 == STD_ON)
            ,Wdg_43_Instance7_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>8)
        #ifdef WDG_INSTANCE8
            #if(WDG_INSTANCE8 == STD_ON)
            ,Wdg_43_Instance8_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>9)
        #ifdef WDG_INSTANCE9
            #if(WDG_INSTANCE9 == STD_ON)
            ,Wdg_43_Instance9_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>10)
        #ifdef WDG_INSTANCE10
            #if(WDG_INSTANCE10 == STD_ON)
            ,Wdg_43_Instance10_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>11)
        #ifdef WDG_INSTANCE11
            #if(WDG_INSTANCE11 == STD_ON)
            ,Wdg_43_Instance11_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>12)
        #ifdef WDG_INSTANCE12
            #if(WDG_INSTANCE12 == STD_ON)
            ,Wdg_43_Instance12_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>13)
        #ifdef WDG_INSTANCE13
            #if(WDG_INSTANCE13 == STD_ON)
            ,Wdg_43_Instance13_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>14)
        #ifdef WDG_INSTANCE14
            #if(WDG_INSTANCE14 == STD_ON)
            ,Wdg_43_Instance14_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>15)
        #ifdef WDG_INSTANCE15
            #if(WDG_INSTANCE15 == STD_ON)
            ,Wdg_43_Instance15_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>16)
        #ifdef WDG_INSTANCE16
            #if(WDG_INSTANCE16 == STD_ON)
            ,Wdg_43_Instance16_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>17)
        #ifdef WDG_INSTANCE17
            #if(WDG_INSTANCE17 == STD_ON)
            ,Wdg_43_Instance17_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>18)
        #ifdef WDG_INSTANCE18
            #if(WDG_INSTANCE18 == STD_ON)
            ,Wdg_43_Instance18_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>19)
        #ifdef WDG_INSTANCE19
            #if(WDG_INSTANCE19 == STD_ON)
            ,Wdg_43_Instance19_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>20)
        #ifdef WDG_INSTANCE20
            #if(WDG_INSTANCE20 == STD_ON)
            ,Wdg_43_Instance20_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>21)
        #ifdef WDG_INSTANCE21
            #if(WDG_INSTANCE21 == STD_ON)
            ,Wdg_43_Instance21_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>22)
        #ifdef WDG_INSTANCE22
            #if(WDG_INSTANCE22 == STD_ON)
            ,Wdg_43_Instance22_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>23)
        #ifdef WDG_INSTANCE23
            #if(WDG_INSTANCE23 == STD_ON)
            ,Wdg_43_Instance23_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>24)
        #ifdef WDG_INSTANCE24
            #if(WDG_INSTANCE24 == STD_ON)
            ,Wdg_43_Instance24_SetMode
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif

    };

#if (WDG_DIRECT_SERVICE == STD_OFF)
const WdgIf_SetTriggerFctPtrType WdgIf_SetTriggerConditionFctPtr[WDGIF_NUMBER_OF_DEVICES] =
    {
    #if(WDG_INSTANCE0 == STD_ON)
            Wdg_43_Instance0_SetTriggerCondition
            #else
            NULL_PTR
        #endif
    #if (WDGIF_NUMBER_OF_DEVICES>1)
        #ifdef WDG_INSTANCE1
            #if(WDG_INSTANCE1 == STD_ON)
            ,Wdg_43_Instance1_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>2)
        #ifdef WDG_INSTANCE2
            #if(WDG_INSTANCE2 == STD_ON)
            ,Wdg_43_Instance2_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>3)
        #ifdef WDG_INSTANCE3
            #if(WDG_INSTANCE3 == STD_ON)
            ,Wdg_43_Instance3_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>4)
        #ifdef WDG_INSTANCE4
            #if(WDG_INSTANCE4 == STD_ON)
            ,Wdg_43_Instance4_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>5)
        #ifdef WDG_INSTANCE5
            #if(WDG_INSTANCE5 == STD_ON)
            ,Wdg_43_Instance5_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>6)
        #ifdef WDG_INSTANCE6
            #if(WDG_INSTANCE6 == STD_ON)
            ,Wdg_43_Instance6_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>7)
        #ifdef WDG_INSTANCE7
            #if(WDG_INSTANCE7 == STD_ON)
            ,Wdg_43_Instance7_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>8)
        #ifdef WDG_INSTANCE8
            #if(WDG_INSTANCE8 == STD_ON)
            ,Wdg_43_Instance8_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>9)
        #ifdef WDG_INSTANCE9
            #if(WDG_INSTANCE9 == STD_ON)
            ,Wdg_43_Instance9_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>10)
        #ifdef WDG_INSTANCE10
            #if(WDG_INSTANCE10 == STD_ON)
            ,Wdg_43_Instance10_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>11)
        #ifdef WDG_INSTANCE11
            #if(WDG_INSTANCE11 == STD_ON)
            ,Wdg_43_Instance11_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>12)
        #ifdef WDG_INSTANCE12
            #if(WDG_INSTANCE12 == STD_ON)
            ,Wdg_43_Instance12_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>13)
        #ifdef WDG_INSTANCE13
            #if(WDG_INSTANCE13 == STD_ON)
            ,Wdg_43_Instance13_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>14)
        #ifdef WDG_INSTANCE14
            #if(WDG_INSTANCE14 == STD_ON)
            ,Wdg_43_Instance14_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>15)
        #ifdef WDG_INSTANCE15
            #if(WDG_INSTANCE15 == STD_ON)
            ,Wdg_43_Instance15_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>16)
        #ifdef WDG_INSTANCE16
            #if(WDG_INSTANCE16 == STD_ON)
            ,Wdg_43_Instance16_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>17)
        #ifdef WDG_INSTANCE17
            #if(WDG_INSTANCE17 == STD_ON)
            ,Wdg_43_Instance17_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>18)
        #ifdef WDG_INSTANCE18
            #if(WDG_INSTANCE18 == STD_ON)
            ,Wdg_43_Instance18_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>19)
        #ifdef WDG_INSTANCE19
            #if(WDG_INSTANCE19 == STD_ON)
            ,Wdg_43_Instance19_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>20)
        #ifdef WDG_INSTANCE20
            #if(WDG_INSTANCE20 == STD_ON)
            ,Wdg_43_Instance20_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>21)
        #ifdef WDG_INSTANCE21
            #if(WDG_INSTANCE21 == STD_ON)
            ,Wdg_43_Instance21_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>22)
        #ifdef WDG_INSTANCE22
            #if(WDG_INSTANCE22 == STD_ON)
            ,Wdg_43_Instance22_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>23)
        #ifdef WDG_INSTANCE23
            #if(WDG_INSTANCE23 == STD_ON)
            ,Wdg_43_Instance23_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif
    #if (WDGIF_NUMBER_OF_DEVICES>24)
        #ifdef WDG_INSTANCE24
            #if(WDG_INSTANCE24 == STD_ON)
            ,Wdg_43_Instance24_SetTriggerCondition
            #else
            ,NULL_PTR
            #endif
        #endif
    #endif

    };
#endif
#endif

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
