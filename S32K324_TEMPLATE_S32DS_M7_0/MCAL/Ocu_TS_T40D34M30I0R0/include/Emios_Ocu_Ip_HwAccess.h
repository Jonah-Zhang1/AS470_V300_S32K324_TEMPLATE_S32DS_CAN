/*==================================================================================================
* Project              : RTD AUTOSAR 4.7
* Platform             : CORTEXM
* Peripheral           : eMios
* Dependencies         : none
*
* Autosar Version      : 4.7.0
* Autosar Revision     : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version           : 3.0.0
* Build Version        : S32K3_RTD_3_0_0_P10_D2307_ASR_REL_4_7_REV_0000_20230726
*
* Copyright 2020 - 2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef EMIOS_OCU_IP_HWACCESS_H
#define EMIOS_OCU_IP_HWACCESS_H

/**
*   @file       Emios_Ocu_Ip_HwAccess.h
*
*   @internal
*   @addtogroup     ocu_ip Ocu IPL
*   @brief
*
*   @{
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Emios_Ocu_Ip_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_OCU_IP_HWACCESS_VENDOR_ID                    43
#define EMIOS_OCU_IP_HWACCESS_MODULE_ID                    125
#define EMIOS_OCU_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION     4
#define EMIOS_OCU_IP_HWACCESS_AR_RELEASE_MINOR_VERSION     7
#define EMIOS_OCU_IP_HWACCESS_AR_RELEASE_REVISION_VERSION  0
#define EMIOS_OCU_IP_HWACCESS_SW_MAJOR_VERSION             3
#define EMIOS_OCU_IP_HWACCESS_SW_MINOR_VERSION             0
#define EMIOS_OCU_IP_HWACCESS_SW_PATCH_VERSION             0


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#if (EMIOS_OCU_IP_HWACCESS_VENDOR_ID != EMIOS_OCU_IP_TYPES_VENDOR_ID)
    #error "Emios_Ocu_Ip_HwAccess.h and Emios_Ocu_Ip_Types.h have different vendor ids"
#endif

/* Check if  header file and Emios_Ocu_Ip_Types.h file are of the same Autosar version */
#if ((EMIOS_OCU_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_OCU_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != EMIOS_OCU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Emios_Ocu_Ip_HwAccess.h and Emios_Ocu_Ip_Types.h are different"
#endif

/* Check if header file and Emios_Ocu_Ip_Types.h file are of the same Software version */
#if ((EMIOS_OCU_IP_HWACCESS_SW_MAJOR_VERSION != EMIOS_OCU_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_OCU_IP_HWACCESS_SW_MINOR_VERSION != EMIOS_OCU_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_OCU_IP_HWACCESS_SW_PATCH_VERSION != EMIOS_OCU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Emios_Ocu_Ip_HwAccess.h and Emios_Ocu_Ip_Types.h are different"
#endif

#if (STD_ON == OCU_EMIOS_USED)

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define OCU_START_SEC_CONST_UNSPECIFIED
#include "Ocu_MemMap.h"

/** @brief  Array of eMIOS peripheral base pointers */
extern Emios_Ocu_Ip_xRegLayoutType * const Emios_Ocu_Ip_gapcxBase[OCU_EMIOS_INSTANCE_COUNT];

#define OCU_STOP_SEC_CONST_UNSPECIFIED
#include "Ocu_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*================================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================================*/

#define OCU_START_SEC_CODE
#include "Ocu_MemMap.h"

/**
 * @brief Set the logic level on the output pin (Edge Polarity bit - EDPOL).
 * @details For output modes, the EDPOL bit is used to select the logic level on the output pin.
 *              0 - A match on comparator A clears the output flip-flop, while a match on comparator B sets it
 *              1 - A match on comparator A sets the output flip-flop, while a match on comparator B clears it
 *
 * @param[in] pcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @param[in] aboEdPol The value to set
 */
static inline void Emios_Ocu_Ip_SetEdgePolarityBit( Emios_Ocu_Ip_xRegLayoutType * const pcxBase,
                                                    uint8 Channel,
                                                    boolean aboEdPol )
{
    uint32 TmpMask = (pcxBase->CH.UC[Channel].C & ~(eMIOS_C_EDPOL_MASK)) | eMIOS_C_EDPOL(aboEdPol ? 1UL : 0UL);
    pcxBase->CH.UC[Channel].C = TmpMask;
}

/**
 * @brief Set the Edge Selection bit (EDSEL).
 * @details When a match occurs in Single Action Output Compare (SAOC) mode, the EDSEL bit selects whether the output flip-flop is toggled or
 *          the value in EDPOL is transferred to it:
 *            0 – The EDPOL value is transferred to the output flip-flop
 *            1 – The output flip-flop is toggled
 *
 * @param[in] pcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @param[in] aboEnEdsel The value to set
 */
static inline void Emios_Ocu_Ip_SetOutputFlipFlop(Emios_Ocu_Ip_xRegLayoutType * const pcxBase, uint8 Channel, boolean aboEnEdsel)
{
    uint32 TmpMask = (pcxBase->CH.UC[Channel].C & ~(eMIOS_C_EDSEL_MASK)) | eMIOS_C_EDSEL(aboEnEdsel ? 1UL : 0UL);
    pcxBase->CH.UC[Channel].C = TmpMask;
}

/**
 * @brief Set the Prescaler Enable bit (UCPREN).
 * @details Enables and disables the prescaler counter.
 *              0b - Disabled (no clock)
 *              1b - Enabled
 *
 * @param[in] pcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @param[in] aboVal The value to set
 */
static inline void Emios_Ocu_Ip_SetPrescalerEnableBit(  Emios_Ocu_Ip_xRegLayoutType * const pcxBase,
                                                        uint8 Channel,
                                                        boolean aboVal )
{
    uint32 TmpMask = (pcxBase->CH.UC[Channel].C & ~(eMIOS_C_UCPREN_MASK)) | eMIOS_C_UCPREN(aboVal ? 1UL : 0UL);
    pcxBase->CH.UC[Channel].C = TmpMask;
}

/**
 * @brief Set the Prescaler (UCPRE).
 * @details Selects the clock divider value for the UC internal prescaler.
 *              00b - 1
 *              01b - 2
 *              10b - 3
 *              11b - 4
 * @note    The two least-significant bits of C2_n[UCEXTPRE] mirror the contents of UCPRE.
 *          Any write operations to UCPRE affect these bits in C2_n[UCEXTPRE].
 *
 * @param[in] pcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @param[in] aVal The value to set
 */
static inline void Emios_Ocu_Ip_SetPrescalerBits(   Emios_Ocu_Ip_xRegLayoutType * const pcxBase,
                                                    uint8 Channel,
                                                    uint8 aVal )
{
    uint32 TmpMask = (pcxBase->CH.UC[Channel].C2 & ~(eMIOS_C2_UCEXTPRE_MASK)) | eMIOS_C2_UCEXTPRE(aVal);
    pcxBase->CH.UC[Channel].C2 = TmpMask;
}

/**
 * @brief Set the Freeze Enable bit (FREN).
 * @details Works with MCR[FRZ] to allows the UC to enter Freeze state, freezing all register values when in Debug
 *          mode and allowing the chip to perform debug functions.
 8              0b - Do not freeze; normal operation
 8              1b - Freeze
 *
 * @param[in] pcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @param[in] aboVal The value to set
 */
static inline void Emios_Ocu_Ip_SetFreezeEnableBit( Emios_Ocu_Ip_xRegLayoutType * const pcxBase,
                                                    uint8 Channel,
                                                    boolean aboVal )
{
    uint32 TmpMask = (pcxBase->CH.UC[Channel].C & ~(eMIOS_C_FREN_MASK)) | eMIOS_C_FREN(aboVal ? 1UL : 0UL);
    pcxBase->CH.UC[Channel].C = TmpMask;
}

/**
 * @brief Set the Bus Select bits (BSL).
 * @details Selects one of the counter buses or the internal counter for the UC to use.
 *          Not all chips support all counter buses. See the chip-specific eMIOS information for details.
 *              00b - Select counter bus A for all channels
 *              01b - Select counter bus B, C, D, or E for channels 0–7, 8–15, 16–23, or 24–31, respectively
 *              10b - Reserved
 *              11b - Select the internal counter for all channels
 *
 * @param[in] pcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @param[in] aVal The value to set
 */
static inline void Emios_Ocu_Ip_SetBusSelectBits(   Emios_Ocu_Ip_xRegLayoutType * const pcxBase,
                                                    uint8 Channel,
                                                    uint8 aVal )
{
    uint32 TmpMask = (pcxBase->CH.UC[Channel].C & ~(eMIOS_C_BSL_MASK)) | eMIOS_C_BSL(aVal);
    pcxBase->CH.UC[Channel].C = TmpMask;
}

/**
 * @brief Set the Output Disable bit (ODIS).
 * @details Allows you to disable the output pin when running any of the output modes except for GPIO mode.
 *          When ODIS = 1:
 *              • If the selected Output Disable Input signal is asserted, the output pin goes to EDPOL for OPWFMB
 *                  and OPWMB modes and to the complement of EDPOL for other output modes, but the UC
 *                  continues to operate normally - it continues to produce FLAG and matches.
 *              • If the selected Output Disable Input signal is negated, the output pin operates normally.
 *                  0b - Enable; the output pin operates normally
 *                  1b - Disable
 *
 * @param[in] pcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @param[in] aboVal The value to set
 */
static inline void Emios_Ocu_Ip_SetOutputDisableBit(Emios_Ocu_Ip_xRegLayoutType * const pcxBase, uint8 Channel, boolean aboVal)
{
    uint32 TmpMask = (pcxBase->CH.UC[Channel].C & ~(eMIOS_C_ODIS_MASK)) | eMIOS_C_ODIS(aboVal ? 1UL : 0UL);
    pcxBase->CH.UC[Channel].C = TmpMask;
}

/**
 * @brief Write 1 to FLAG bit to clear it
 * @param[in] pcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 */
static inline void Emios_Ocu_Ip_ClearInterruptFlags(Emios_Ocu_Ip_xRegLayoutType * const pcxBase, uint8 Channel)
{
    /* Clear pending interrupt serviced
     * OVR bit, OVFL bit & FLAG bit can be cleared when write 1 to them */
     pcxBase->CH.UC[Channel].S = (uint32)(eMIOS_S_OVR_MASK | eMIOS_S_OVFL_MASK | eMIOS_S_FLAG_MASK);
}

/*!
 * brief Set FLAG Enable bit
 * @details Enables and disables Sn[FLAG] to generate an interrupt signal or a DMA request signal
 *          (the DMA field defines the type of signal to be generated)
 *              0b - Disable
 *              1b - Enable
 * param[in] pcxBase - eMIOS peripheral base pointer
 * param[in] Channel channel
 * @param[in] aboEn The value to set
 *            - 0 Disable (FLAG does not generate an interrupt request)
 *            - 1 Enable (FLAG generates an interrupt request)
 */
static inline void Emios_Ocu_Ip_SetFlagEnableBit(   Emios_Ocu_Ip_xRegLayoutType * const pcxBase,
                                                    uint8 Channel,
                                                    boolean aboEn )
{
    /* Enable or disable interrupts */
    uint32 TmpMask = (pcxBase->CH.UC[Channel].C & ~(eMIOS_C_FEN_MASK)) | eMIOS_C_FEN(aboEn ? 1UL : 0UL);
    pcxBase->CH.UC[Channel].C = TmpMask;
}

/**
 * @brief Set the operation mode of the Unified Channel (Mode selection bits - MODE[6:0])
 * @details The MODE[6:0] bits select the operation mode of the Unified Channel
 *              0000011b - Single Action Output Compare
 *              0000110b - Double Action Output compare (with FLAG set on B match)
 *              0000111b - Double Action Output compare (with FLAG set on both match)
 *
 * @param[in] pcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @param[in] aMode The value to set
 */
static inline void Emios_Ocu_Ip_SetOperationMode(   Emios_Ocu_Ip_xRegLayoutType * const pcxBase,
                                                    uint8 Channel,
                                                    Emios_Ocu_Ip_OperationModeType aMode )
{
    uint32 TmpMask = (pcxBase->CH.UC[Channel].C & ~(eMIOS_C_MODE_MASK)) | eMIOS_C_MODE((uint32)aMode);
    pcxBase->CH.UC[Channel].C = TmpMask;
}

#if ((OCU_SET_RELATIVE_THRESHOLD_API == STD_ON) || (OCU_SET_ABSOLUTE_THRESHOLD_API == STD_ON) || (OCU_GET_COUNTER_API == STD_ON))
/**
 * @brief   Get CNT register's value
 *
 * @param[in]   cpcxBase - eMIOS peripheral base pointer
 * @param[in]   Channel - channel number in the current instance
 * @return      Value of Unified Channels CNT register
 */
static inline Emios_Ocu_Ip_ValueType Emios_Ocu_Ip_GetCntVal(const Emios_Ocu_Ip_xRegLayoutType * const cpcxBase, uint8 Channel)
{
    /* Read the elapsed time */
    return (Emios_Ocu_Ip_ValueType)((cpcxBase->CH.UC[Channel].CNT & eMIOS_CNT_C_MASK) >> eMIOS_CNT_C_SHIFT);
}
#endif

/**
 * @brief Set the eMIOS UC A register n (eMIOS_An), maximum value is 0xFFFFFFUL
 * @details Depending on the mode of operation, internal registers A1[0:23] or A2[0:23], used for matches and
 *          captures, can be assigned to address EMIOS_An. Both A1 and A2 are cleared by reset.
 *
 * @param[in] pcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @param[in] au32MatchEdgeVal The value to set
 */
static inline void Emios_Ocu_Ip_SetMatchLeadingEdge(    Emios_Ocu_Ip_xRegLayoutType * const pcxBase,
                                                        uint8 Channel,
                                                        uint32 au32MatchEdgeVal )
{
    uint32 TmpMask = (pcxBase->CH.UC[Channel].A & ~(eMIOS_A_A_MASK)) | eMIOS_A_A(au32MatchEdgeVal);
    pcxBase->CH.UC[Channel].A = TmpMask;
}

/**
 * @brief Get the state of UC Output Pin (UCOUT)
 * @details Reflects the output pin state.
 *
 * @param[in] cpcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @return True if a match event in the comparators occurred, False otherwise
 */
static inline boolean Emios_Ocu_Ip_GetOutputPinState(const Emios_Ocu_Ip_xRegLayoutType * const cpcxBase, uint8 Channel)
{
    return (0U != (cpcxBase->CH.UC[Channel].S & eMIOS_S_UCOUT_MASK)) ? TRUE : FALSE;
}

#if (STD_ON == OCU_SET_PIN_STATE_API)
/**
 * brief Force Match A bit (FORCMA)
 * @details For output modes, the FORCMA bit is equivalent to a successful comparison on comparator A (except that the FLAG bit is not set).
 *          This bit is cleared by reset and is always read as zero. This bit is valid for every output operation mode which uses comparator A,
 *          otherwise it has no effect. For input modes, the FORCMA bit is not used and writing to it has no effect.
 *              0b - Has no effect.
 *              1b - Force a match at comparator A
 *
 * param[in] pcxBase - eMIOS peripheral base pointer
 * param[in] Channel - channel number in the current instance
 * @param[in] aboEn The value to set
 *              - True : Force a match at comparator A
 *              - False: Has no effect
 */
static inline void Emios_Ocu_Ip_SetForceMatchA( Emios_Ocu_Ip_xRegLayoutType * const pcxBase,
                                                uint8 Channel,
                                                boolean aboEn )
{
    uint32 TmpMask = (pcxBase->CH.UC[Channel].C & ~(eMIOS_C_FORCMA_MASK)) | eMIOS_C_FORCMA(aboEn ? 1UL : 0UL);
    pcxBase->CH.UC[Channel].C = TmpMask;
}
#endif

#if (OCU_NOTIFICATION_SUPPORTED == STD_ON)

/**
 * @brief Get the state of FLAG bit
 * @param[in] cpcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @return True if a match event in the comparators occurred, False otherwise
 */
static inline boolean Emios_Ocu_Ip_HasMatchEventOccurred(const Emios_Ocu_Ip_xRegLayoutType * const cpcxBase, uint8 Channel)
{
    return (0U != (cpcxBase->CH.UC[Channel].S & eMIOS_S_FLAG_MASK)) ? TRUE : FALSE;
}

/**
 * @brief Get the state of FLAG Enable bit
 * @param[in] cpcxBase - eMIOS peripheral base pointer
 * @param[in] Channel - channel number in the current instance
 * @return True if Sn[FLAG] is enabled to generate an interrupt signal or a DMA request signal, False otherwise
 */
static inline boolean Emios_Ocu_Ip_IsMatchEventEnabled(const Emios_Ocu_Ip_xRegLayoutType * const cpcxBase, uint8 Channel)
{
    return (0U != (cpcxBase->CH.UC[Channel].C & eMIOS_C_FEN_MASK)) ? TRUE : FALSE;
}

#endif

#define OCU_STOP_SEC_CODE
#include "Ocu_MemMap.h"

#endif /* OCU_EMIOS_USED */


#ifdef __cplusplus
}
#endif

/*! @}*/

#endif /* EMIOS_OCU_IP_HWACCESS_H */
