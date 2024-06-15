/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 3.0.0
*   Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
   (c) Copyright 2020 - 2023 NXP Semiconductors
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
*   @file   LinIf.c
*
*   @addtogroup LINIF
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section LinIf_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h,  Precautions shall be 
* taken in order to prevent the contents of a header file being included twice This is not a violation 
* since all header files are protected against multiple inclusions
*
* @section LinIf_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments 
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section LinIf_c_REF_3
* Violates MISRA 2004 Advisory Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. This violation is due to the use of pointer arithematic, to access the channel parameters,
* the indexing of the pointer is taken care and hence the unintended memory location will not
* be accessed
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           LinIf.c
* @requirements   LINIF247, LINIF434, LINIF589, LINIF590, LINIF497, LINIF498, 
*                 LINIF499, LINIF638, LINIF561, LINIF555, LINIF556
*/
#include "modules.h"
#ifdef USE_LIN_MODULE
    #if (USE_LIN_MODULE == STD_ON)
        #include "Lin.h"
    #endif
#endif
#ifdef USE_LIN_43_LINFLEXD_MODULE
    #if (USE_LIN_43_LINFLEXD_MODULE == STD_ON)
        #include "Lin_43_LINFLEXD.h"
    #endif
#endif
#ifdef USE_LIN_43_LPUART_FLEXIO_MODULE
    #if (USE_LIN_43_LPUART_FLEXIO_MODULE == STD_ON)
        #include "Lin_43_LPUART_FLEXIO.h"
    #endif
#endif

#ifdef USE_LIN_43_LLCE_MODULE
    #if (USE_LIN_43_LLCE_MODULE == STD_ON)
        #include "Lin_43_LLCE.h"
    #endif
#endif
#include "LinIf.h"
#if defined(USE_LIN_MODULE) || defined(USE_LIN_43_LINFLEXD_MODULE) || defined(USE_LIN_43_LPUART_FLEXIO_MODULE)
    #if ((USE_LIN_MODULE == STD_ON) || (USE_LIN_43_LINFLEXD_MODULE == STD_ON) || (USE_LIN_43_LPUART_FLEXIO_MODULE == STD_ON))
        #include "Dem.h"
    #endif
#endif

#if defined(LIN_DEV_ERROR_DETECT)
    #if (LIN_DEV_ERROR_DETECT == STD_ON)
        #include "Det.h"
    #endif
#elif defined(LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT)
     #if (LIN_43_LPUART_FLEXIO_DEV_ERROR_DETECT == STD_ON)
        #include "Det.h"
    #endif
#elif defined(LIN_43_LINFLEXD_DEV_ERROR_DETECT)
     #if (LIN_43_LINFLEXD_DEV_ERROR_DETECT == STD_ON)
        #include "Det.h"
    #endif
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           LinIf.c
* @requirements   LINIF383
*/
#define LINIF_VENDOR_ID_C                      43
#define LINIF_AR_RELEASE_MAJOR_VERSION_C       4
#define LINIF_AR_RELEASE_MINOR_VERSION_C       7
#define LINIF_AR_RELEASE_REVISION_VERSION_C    0
#define LINIF_SW_MAJOR_VERSION_C               3
#define LINIF_SW_MINOR_VERSION_C               0
#define LINIF_SW_PATCH_VERSION_C               0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and LinIf header file are of the same vendor */
#if (LINIF_VENDOR_ID_C != LINIF_VENDOR_ID)
    #error "LinIf.c and LinIf.h have different vendor ids"
#endif
/* Check if current file and LinIf header file are of the same Autosar version */
#if ((LINIF_AR_RELEASE_MAJOR_VERSION_C    != LINIF_AR_RELEASE_MAJOR_VERSION) || \
     (LINIF_AR_RELEASE_MINOR_VERSION_C    != LINIF_AR_RELEASE_MINOR_VERSION) || \
     (LINIF_AR_RELEASE_REVISION_VERSION_C != LINIF_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of LinIf.c and LinIf.h are different"
#endif
/* Check if current file and LinIf header file are of the same Software version */
#if ((LINIF_SW_MAJOR_VERSION_C != LINIF_SW_MAJOR_VERSION) || \
     (LINIF_SW_MINOR_VERSION_C != LINIF_SW_MINOR_VERSION) || \
     (LINIF_SW_PATCH_VERSION_C != LINIF_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of LinIf.c and LinIf.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #ifdef USE_LIN_MODULE
        #if (USE_LIN_MODULE == STD_ON)
            /* Check if current file and Lin header file are of the same Autosar version */
            #if ((LINIF_AR_RELEASE_MAJOR_VERSION_C != LIN_AR_RELEASE_MAJOR_VERSION) || \
                 (LINIF_AR_RELEASE_MINOR_VERSION_C != LIN_AR_RELEASE_MINOR_VERSION) \
                )
            #error "AutoSar Version Numbers of LinIf.c and Lin.h are different"
            #endif
        #endif /* (USE_LIN_MODULE == STD_ON) */
    #endif /* USE_LIN_MODULE */
    #ifdef USE_LIN_43_LPUART_FLEXIO_MODULE
        #if (USE_LIN_43_LPUART_FLEXIO_MODULE == STD_ON)
            /* Check if current file and Lin header file are of the same Autosar version */
            #if ((LINIF_AR_RELEASE_MAJOR_VERSION_C != LIN_43_LPUART_FLEXIO_AR_RELEASE_MAJOR_VERSION) || \
                 (LINIF_AR_RELEASE_MINOR_VERSION_C != LIN_43_LPUART_FLEXIO_AR_RELEASE_MINOR_VERSION) \
                )
            #error "AutoSar Version Numbers of LinIf.c and Lin_43_LPUART_FLEXIO.h are different"
            #endif
        #endif
    #endif /* USE_LIN_43_LPUART_FLEXIO_MODULE */
    #ifdef USE_LIN_43_LINFLEXD_MODULE
        #if (USE_LIN_43_LINFLEXD_MODULE == STD_ON)
            /* Check if current file and Lin header file are of the same Autosar version */
            #if ((LINIF_AR_RELEASE_MAJOR_VERSION_C != LIN_43_LINFLEXD_AR_RELEASE_MAJOR_VERSION) || \
                 (LINIF_AR_RELEASE_MINOR_VERSION_C != LIN_43_LINFLEXD_AR_RELEASE_MINOR_VERSION) \
                )
            #error "AutoSar Version Numbers of LinIf.c and Lin_43_LINFLEXD.h are different"
            #endif
        #endif
    #endif /* USE_LIN_43_LINFLEXD_MODULE */
#if defined(USE_LIN_MODULE) || defined(USE_LIN_43_LINFLEXD_MODULE) || defined(USE_LIN_43_LPUART_FLEXIO_MODULE)
    #if ((USE_LIN_MODULE == STD_ON) || (USE_LIN_43_LINFLEXD_MODULE == STD_ON) || (USE_LIN_43_LPUART_FLEXIO_MODULE == STD_ON))
        /* Check if current file and Dem header file are of the same version */
        #if ((LINIF_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
            (LINIF_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
            )
            #error "AutoSar Version Numbers of LinIf.c and Dem.h are different"
        #endif
    #endif
#endif
    #ifdef LIN_DEV_ERROR_DETECT
        #if (LIN_DEV_ERROR_DETECT == STD_ON)
            /* Check if the source file and Det header file are of the same Autosar version */
            #if ((LINIF_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
                (LINIF_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
                )
                #error "AutoSar Version Numbers of LinIf.c and Det.h are different"
            #endif
        #endif
    #endif /* LIN_DEV_ERROR_DETECT */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (LINIF_WAKEUP_SUPPORT == STD_ON)
/**
* @brief   The LIN Driver or LIN Transceiver Driver will call this function to report the wake up 
*          source after the successful wakeup detection during CheckWakeup or after power on by bus. 
* @details This is a function stub only. 
*     
* @param[in]  WakeupSource - Source device which initiated the wakeup event: LIN controller
*                            or LIN transceiver.
*
* @Requirements
*/
void LinIf_WakeupConfirmation(EcuM_WakeupSourceType WakeupSource)
{
    /* Cast to avoid CW */
    (void)WakeupSource;
    return;
}

/** 
* @brief   Will be called when the EcuM has been notified about a wakeup on a specific LIN channel. 
*
* @details This is a function stub only. 
*     
* @param[in]  WakeupSource - Source device which initiated the wakeup event: LIN controller
*                            or LIN transceiver.
*
* @Requirements
*/
Std_ReturnType LinIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
    /* Cast to avoid CW */
    (void)WakeupSource;

    return E_OK;
}

/**
* @brief   The LIN Driver will call this function to report a received LIN header. This function is 
*          only applicable for LIN slave nodes (available only if the ECU has any LIN slave channel).
*
* @details This is a function stub only.
*
* @param[in]    Channel  Identification of the LIN channel.
*
* @param[inout] PduPtr   Pointer to PDU providing the received PID and pointer to the SDU data buffer
*                        as in parameter. Upon return, the length, checksum type and frame response 
*                        type are received as out parameter. If the frame response type is 
*                        LIN_FRAMERESPONSE_TX, then the SDU data buffer contains the transmission data.
*
* @return                Lin_StatusType.
* @retval E_OK           Request has been accepted.
* @retval E_NOT_OK       Request has not been accepted, development or production error occurred.
*
* @Requirements
*/
Std_ReturnType LinIf_HeaderIndication(NetworkHandleType Channel, Lin_PduType * PduPtr)
{
    /* Cast to avoid CW */
    (void)Channel;
    (void)PduPtr;
    return E_OK;
}

/**
* @brief   The LIN Driver will call this function to report a successfully received response and
*          provides the reception data to the LIN Interface. This function is only applicable for
*          LIN slave nodes (available only if the ECU has any LIN slave channel).
*
* @details This is a function stub only.
*
* @param[in]  Channel    Identification of the LIN channel.
* @param[in]  Lin_SduPtr Pointer to pointer to a shadow buffer or memory mapped LIN Hardware receive
*                        buffer where the current SDU is stored. This pointer is only valid if the 
*                        response is received.
*
* @Requirements
*/
void LinIf_RxIndication(NetworkHandleType Channel, uint8* Lin_SduPtr)
{
    /* Cast to avoid CW */
    (void)Channel;
    (void)Lin_SduPtr;
}

/** 
* @brief   The LIN Driver will call this function to report a successfully transmitted response.
*          This function is only applicable for LIN slave nodes (available only if the ECU has
*          any LIN slave channel).
*
* @details This is a function stub only.
*
* @param[in]  Channel    Identification of the LIN channel.
*
* @Requirements
*/
void LinIf_TxConfirmation(NetworkHandleType Channel)
{
    /* Cast to avoid CW */
    (void)Channel;
}

/**
* @brief   The LIN Driver will call this function to report a detected error event during header
*          or response processing. This function is only applicable for LIN slave nodes (available 
*          only if the ECU has any LIN slave channel).
*
* @details This is a function stub only.
*
* @param[in]  Channel    Identification of the LIN channel.
* @param[in]  ErrorStatus Type of detected error
*
* @Requirements
*/
void LinIf_LinErrorIndication(NetworkHandleType Channel, Lin_SlaveErrorType ErrorStatus)
{
    /* Cast to avoid CW */
    (void)Channel;
    (void)ErrorStatus;
}
#endif

#ifdef __cplusplus
}
#endif

/* End of File */

/** @}*/
