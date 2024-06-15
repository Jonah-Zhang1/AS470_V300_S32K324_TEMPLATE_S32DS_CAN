/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Siul2 Wkpu LpCmp
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
 *     @file Cmp_Ip.c
 *
 *     @addtogroup cmp_icu_ip CMP IPL
 *     @{
 */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Cmp_Ip.h"

#if (STD_ON == CMP_IP_USED)
    #if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
        #include "Devassert.h"
    #endif /* CMP_IP_DEV_ERROR_DETECT == STD_ON */
#endif /* CMP_IP_USED */

#include "SchM_Icu.h"
#include "Mcal.h"

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/
#define CMP_IP_VENDOR_ID_C                     43
#define CMP_IP_AR_RELEASE_MAJOR_VERSION_C      4
#define CMP_IP_AR_RELEASE_MINOR_VERSION_C      7
#define CMP_IP_AR_RELEASE_REVISION_VERSION_C   0
#define CMP_IP_SW_MAJOR_VERSION_C              3
#define CMP_IP_SW_MINOR_VERSION_C              0
#define CMP_IP_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((CMP_IP_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CMP_IP_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Cmp_Ip.c and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (CMP_IP_VENDOR_ID_C != CMP_IP_VENDOR_ID)
    #error "Cmp_Ip.c and Cmp_Ip.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((CMP_IP_AR_RELEASE_MAJOR_VERSION_C  != CMP_IP_AR_RELEASE_MAJOR_VERSION) || \
     (CMP_IP_AR_RELEASE_MINOR_VERSION_C  != CMP_IP_AR_RELEASE_MINOR_VERSION) || \
     (CMP_IP_AR_RELEASE_REVISION_VERSION_C   != CMP_IP_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Cmp_Ip.c and Cmp_Ip.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((CMP_IP_SW_MAJOR_VERSION_C  != CMP_IP_SW_MAJOR_VERSION) || \
     (CMP_IP_SW_MINOR_VERSION_C  != CMP_IP_SW_MINOR_VERSION) || \
     (CMP_IP_SW_PATCH_VERSION_C  != CMP_IP_SW_PATCH_VERSION))
#error "Software Version Numbers of Cmp_Ip.c and Cmp_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if (STD_ON == CMP_IP_USED)
        #if(CMP_IP_DEV_ERROR_DETECT == STD_ON)
            /* Check if this header file and Devassert.h file are of the same Autosar version */
            #if ((CMP_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
                (CMP_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Cmp_Ip.c and Devassert.h are different"
            #endif
        #endif
    #endif /* CMP_IP_USED */
    
    /* Check if this header file and SchM_Icu.h file are of the same Autosar version */
    #if ((CMP_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_ICU_AR_RELEASE_MAJOR_VERSION) || \
         (CMP_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_ICU_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Cmp_Ip.c and SchM_Icu.h are different"
    #endif
    
    #if ((CMP_IP_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (CMP_IP_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Cmp_Ip.c and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#if (STD_ON == CMP_IP_USED)

#define ICU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

static Cmp_Ip_StateType Cmp_Ip_axState[ICU_CMP_INSTANCE_COUNT];

#define ICU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

#ifdef CMP_IP_SUPPORT_LOWPOWER
LPCMP_Type * const Cmp_Ip_apxBase[ICU_CMP_INSTANCE_COUNT] = IP_LPCMP_BASE_PTRS;
#endif

#ifdef CMP_IP_NOT_SUPPORT_LOWPOWER
CMP_Type * const Cmp_Ip_apxBase[ICU_CMP_INSTANCE_COUNT] = IP_CMP_BASE_PTRS;
#endif

#define ICU_STOP_SEC_CONST_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

#ifdef CMP_IP_SUPPORT_LOWPOWER
static inline void Cmp_Ip_InitCcr0(uint8 instance, const Cmp_Ip_ConfigType* userConfig)
{
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 ccr0 = 0u;

    switch(userConfig->Comparator.FunctionalMode)
    {
        case CMP_IP_FUNCTIONALMODE_DISABLED:
            break;
        case CMP_IP_FUNCTIONALMODE_CONTINUOUS:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_EXT_CLK:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_INT_CLK:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_INT_CLK:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_EXT_CLK:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED_RESAMPLED:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED_FILTERED:
            ccr0 |= LPCMP_CCR0_CMP_EN(1U);
            break;
        default:
            /* Impossible case */
            break;
    }
    ccr0 |= LPCMP_CCR0_CMP_STOP_EN(userConfig->Comparator.EnableInStop?(uint32)1U:(uint32)0U);
    ccr0 |= LPCMP_CCR0_CMP_EN(1u);
    base->CCR0 = ccr0;
}

static inline void Cmp_Ip_InitCcr1(uint8 instance, const Cmp_Ip_ConfigType* userConfig)
{
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 ccr1 = 0u;

    switch(userConfig->Comparator.FunctionalMode)
    {
        case CMP_IP_FUNCTIONALMODE_DISABLED:
            break;
        case CMP_IP_FUNCTIONALMODE_CONTINUOUS:
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_EXT_CLK:
            ccr1 |= LPCMP_CCR1_SAMPLE_EN(1U);
            ccr1 |= LPCMP_CCR1_FILT_CNT(1U);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_INT_CLK:
            ccr1 |= LPCMP_CCR1_FILT_CNT(1U);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_INT_CLK:
            ccr1 |= LPCMP_CCR1_FILT_CNT(userConfig->Comparator.FilterSampleCount);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_EXT_CLK:
            ccr1 |= LPCMP_CCR1_SAMPLE_EN(1U);           
            ccr1 |= LPCMP_CCR1_FILT_CNT(userConfig->Comparator.FilterSampleCount);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED:
            ccr1 |= LPCMP_CCR1_WINDOW_EN(1U);
            ccr1 |= LPCMP_CCR1_FILT_CNT(0U);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED_RESAMPLED:
            ccr1 |= LPCMP_CCR1_WINDOW_EN(1U);
            ccr1 |= LPCMP_CCR1_FILT_CNT(1U);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED_FILTERED:
            ccr1 |= LPCMP_CCR1_WINDOW_EN(1U);
            ccr1 |= LPCMP_CCR1_FILT_CNT(userConfig->Comparator.FilterSampleCount);
            ccr1 |= LPCMP_CCR1_FILT_PER(userConfig->Comparator.FilterSamplePeriod);
            break;
        default:
            /* Impossible case */
            break;
    }

    ccr1 |= LPCMP_CCR1_COUT_PEN((userConfig->Comparator.EnablePinOutput)?1U:0U);
    ccr1 |= LPCMP_CCR1_WINDOW_INV((userConfig->Comparator.EnableInverter)?1U:0U);
    ccr1 |= LPCMP_CCR1_COUT_INV((userConfig->Comparator.EnableComparatorInvert)?1U:0U);
    ccr1 |= LPCMP_CCR1_DMA_EN((userConfig->Comparator.EnableDma)?1U:0U);
    ccr1 |= LPCMP_CCR1_COUT_SEL(userConfig->Comparator.OutputSelect);
    ccr1 |= LPCMP_CCR1_COUTA_OWEN((userConfig->Comparator.WindowCloseOutputOverwrite == CMP_IP_WINDOWCLOSEOUTPUTOVERWRITE_DISABLED)?0U:1U);
    ccr1 |= LPCMP_CCR1_COUTA_OW((userConfig->Comparator.WindowCloseOutputOverwrite == CMP_IP_WINDOWCLOSEOUTPUTOVERWRITE_HIGH)?1U:0U);
    switch (userConfig->Comparator.WindowCloseEvent)
    {
        case CMP_IP_WINDOWCLOSEEVENT_RISING:
            ccr1 &= (~LPCMP_CCR1_EVT_SEL_MASK); 
            ccr1 |= LPCMP_CCR1_WINDOW_CLS(1u); 
            break;
        case CMP_IP_WINDOWCLOSEEVENT_FALLING:
            ccr1 &= (~LPCMP_CCR1_EVT_SEL_MASK);
            ccr1 |= LPCMP_CCR1_WINDOW_CLS(1u) | LPCMP_CCR1_EVT_SEL(1u); 
            break;
        case CMP_IP_WINDOWCLOSEEVENT_BOTH:
            ccr1 |= LPCMP_CCR1_WINDOW_CLS(1u) | LPCMP_CCR1_EVT_SEL(2u); 
            break;
        case CMP_IP_WINDOWCLOSEEVENT_NONE:
            ccr1 &= (~LPCMP_CCR1_WINDOW_CLS_MASK); 
            break;
        default:
            /* Impossible case */
            break;
    }
    base->CCR1 = ccr1;
}

static inline void Cmp_Ip_InitCcr2(uint8 instance, const Cmp_Ip_ConfigType* userConfig)
{
    /*initialise the base address of the given instance*/
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 ccr2 = 0u;

    ccr2 |= LPCMP_CCR2_HYSTCTR(userConfig->Comparator.HysteresisLevel);
    ccr2 |= LPCMP_CCR2_OFFSET(userConfig->Comparator.OffsetLevel);
    ccr2 |= LPCMP_CCR2_CMP_HPMD((userConfig->Comparator.EnableHighPowerMode)?1U:0U);
    ccr2 |= LPCMP_CCR2_INMSEL((userConfig->Comparator.NegativeInputMux == CMP_IP_INPUTMUX_DAC)?0U:1U);
    ccr2 |= LPCMP_CCR2_MSEL((userConfig->Comparator.NegativeInputMux == CMP_IP_INPUTMUX_DAC)?0U:(uint32)(userConfig->Comparator.NegativeInputMux));
    ccr2 |= LPCMP_CCR2_INPSEL((userConfig->Comparator.PositiveInputMux == CMP_IP_INPUTMUX_DAC)?0U:1U);
    ccr2 |= LPCMP_CCR2_PSEL((userConfig->Comparator.PositiveInputMux == CMP_IP_INPUTMUX_DAC)?0U:(uint32)(userConfig->Comparator.PositiveInputMux));
    base->CCR2 = ccr2;
}

static inline void Cmp_Ip_InitDcr(uint8 instance, const Cmp_Ip_ConfigType* userConfig)
{
    /*initialise the base address of the given instance*/
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 dcr = 0u;

    dcr |= LPCMP_DCR_DAC_DATA(userConfig->Dac.VoltageLevel);
    dcr |= LPCMP_DCR_VRSEL(userConfig->Dac.VoltageRefSource);
    dcr |= LPCMP_DCR_DAC_EN((userConfig->Dac.PowerState == CMP_IP_DACPOWERSTATE_ENABLED)?1U:0U);
    dcr |= LPCMP_CCR0_LINKEN((userConfig->Dac.PowerState == CMP_IP_DACPOWERSTATE_LINKED)?1U:0U);
    base->DCR = dcr;
}
#endif

#if (defined(ICU_CMP_0_ISR_USED) || \
     defined(ICU_CMP_1_ISR_USED) || \
     defined(ICU_CMP_2_ISR_USED))

static void Cmp_Ip_IrqHandler(uint8 instance);
#endif

#ifdef CMP_IP_NOT_SUPPORT_LOWPOWER
/**
* @brief      Icu driver function that initializes CMP.
* @details    This function enables CMP instance 0 for signal compare and trigger interrupt
*/
static inline void Cmp_Ip_InitCmpC0(uint8 instance, const Cmp_Ip_ConfigType* const userConfig)
{
    CMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 Cmp_C0 = 0u;

    switch(userConfig->Comparator.FunctionalMode)
    {
        case CMP_IP_FUNCTIONALMODE_DISABLED:
            Cmp_C0 |= CMP_C0_EN(0U);
            break;
        case CMP_IP_FUNCTIONALMODE_CONTINUOUS:
            Cmp_C0 |= CMP_C0_EN(1U);
            Cmp_C0 |= CMP_C0_WE(0U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_EXT_CLK:
            Cmp_C0 |= CMP_C0_EN(1U);
            Cmp_C0 |= CMP_C0_WE(0U);
            Cmp_C0 |= CMP_C0_SE(1U);
            Cmp_C0 |= CMP_C0_FILTER_CNT(1U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_NONFILTERED_INT_CLK:
            Cmp_C0 |= CMP_C0_EN(1U);
            Cmp_C0 |= CMP_C0_WE(0U);
            Cmp_C0 |= CMP_C0_SE(0U);
            Cmp_C0 |= CMP_C0_FILTER_CNT(1U);
            Cmp_C0 |= CMP_C0_FPR(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_INT_CLK:
            Cmp_C0 |= CMP_C0_EN(1U);
            Cmp_C0 |= CMP_C0_WE(0U);
            Cmp_C0 |= CMP_C0_SE(1U);
            Cmp_C0 |= CMP_C0_FILTER_CNT(2U);
            break;
        case CMP_IP_FUNCTIONALMODE_SAMPLED_FILTERED_EXT_CLK:
            Cmp_C0 |= CMP_C0_EN(1U);
            Cmp_C0 |= CMP_C0_WE(0U);
            Cmp_C0 |= CMP_C0_SE(0U);
            Cmp_C0 |= CMP_C0_FILTER_CNT(2U);
            Cmp_C0 |= CMP_C0_FPR(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED:
            Cmp_C0 |= CMP_C0_EN(1U);
            Cmp_C0 |= CMP_C0_WE(1U);
            Cmp_C0 |= CMP_C0_SE(0U);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED_RESAMPLED:
            Cmp_C0 |= CMP_C0_EN(1U);
            Cmp_C0 |= CMP_C0_WE(1U);
            Cmp_C0 |= CMP_C0_SE(0U);
            Cmp_C0 |= CMP_C0_FPR(userConfig->Comparator.FilterSamplePeriod);
            break;
        case CMP_IP_FUNCTIONALMODE_WINDOWED_FILTERED:
            Cmp_C0 |= CMP_C0_EN(1U);
            Cmp_C0 |= CMP_C0_WE(1U);
            Cmp_C0 |= CMP_C0_SE(0U);
            Cmp_C0 |= CMP_C0_FILTER_CNT(2U);
            Cmp_C0 |= CMP_C0_FPR(userConfig->Comparator.FilterSamplePeriod);
            break;
        default:
            /* Impossible case */
            break;
    }

    Cmp_C0 |= CMP_C0_HYSTCTR(userConfig->Comparator.HysteresisLevel);
    Cmp_C0 |= CMP_C0_OFFSET(userConfig->Comparator.OffsetLevel);
    Cmp_C0 |= CMP_C0_OPE(userConfig->Comparator.EnablePinOutput?(uint32)1U:(uint32)0U);
    Cmp_C0 |= CMP_C0_INVT(userConfig->Comparator.EnableInverter?(uint32)1U:(uint32)0U);
    Cmp_C0 |= CMP_C0_PMODE(userConfig->Comparator.EnableHighPowerMode?(uint32)1U:(uint32)0U);
    Cmp_C0 |= CMP_C0_DMAEN(userConfig->Comparator.EnableDma?(uint32)1U:(uint32)0U);
    Cmp_C0 |= CMP_C0_COS(userConfig->Comparator.OutputSelect);

    base->C0 = Cmp_C0;
}

/**
* @brief      Icu driver function that initializes CMP.
* @details    This function enables CMP instance 1 for signal compare and trigger interrupt
*/
static inline void Cmp_Ip_InitCmpC1(uint8 instance, const Cmp_Ip_ConfigType* const userConfig)
{
    CMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 Cmp_C1 = 0u;

    Cmp_C1 |= CMP_C1_INNSEL((userConfig->Comparator.NegativeInputMux == CMP_IP_INPUTMUX_DAC)?0U:1U);
    Cmp_C1 |= CMP_C1_MSEL((userConfig->Comparator.NegativeInputMux == CMP_IP_INPUTMUX_DAC)?0U:(uint32)(userConfig->Comparator.NegativeInputMux));
    Cmp_C1 |= CMP_C1_INPSEL((userConfig->Comparator.PositiveInputMux == CMP_IP_INPUTMUX_DAC)?0U:1U);
    Cmp_C1 |= CMP_C1_PSEL((userConfig->Comparator.PositiveInputMux == CMP_IP_INPUTMUX_DAC)?0U:(uint32)(userConfig->Comparator.PositiveInputMux));
    Cmp_C1 |= CMP_C1_DACEN((userConfig->Dac.PowerState == CMP_IP_DACPOWERSTATE_ENABLED)?1U:0U);
    Cmp_C1 |= CMP_C1_VRSEL(userConfig->Dac.VoltageRefSource);
    Cmp_C1 |= CMP_C1_VOSEL(userConfig->Dac.VoltageLevel);

    base->C1 = Cmp_C1;
}

/**
* @brief      Icu driver function that initializes CMP.
* @details    This function enables CMP instance 2 for signal compare and trigger interrupt
*/
static inline void Cmp_Ip_InitCmpC2(uint8 instance, const Cmp_Ip_ConfigType* const userConfig)
{
    CMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 Cmp_C2 = 0u;

    Cmp_C2 |= CMP_C2_RRIE((userConfig->Trigger.EnableRoundRobinInterrupt)?1U:0U);
    Cmp_C2 |= CMP_C2_RRE((userConfig->Trigger.EnableRoundRobin)?1U:0U);
    Cmp_C2 |= CMP_C2_FXMP(userConfig->Trigger.FixedPort);
    Cmp_C2 |= CMP_C2_FXMXCH(userConfig->Trigger.FixedChannel);
    Cmp_C2 |= CMP_C2_NSAM(userConfig->Trigger.SampleDelay);
    Cmp_C2 |= CMP_C2_INITMOD(userConfig->Trigger.InitDelayValue);
    Cmp_C2 |= CMP_C2_ACOn(userConfig->Trigger.RoundRobinEnChannelMask);

    base->C2 = Cmp_C2;
}
#endif

/**
* @brief      Icu driver function that initializes CMP.
* @details    This function enables CMP instance for signal compare and trigger interrupt
*
* @param[in]  instance      - The instance index
* @param[in]  userConfig    - Pointer to channel configuration structure 
*
* @implements Cmp_Ip_Init_Activity
*/
Cmp_Ip_StatusType Cmp_Ip_Init(uint8 instance, const Cmp_Ip_ConfigType* userConfig)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
    DevAssert(Cmp_Ip_axState[instance].State == ICU_CMP_IP_UNINIT);
#endif
    Cmp_Ip_StatusType   retStatus = CMP_IP_STATUS_SUCCESS;

    if(ICU_CMP_IP_UNINIT == Cmp_Ip_axState[instance].State)
    {
#ifdef CMP_IP_SUPPORT_LOWPOWER
        LPCMP_Type * base = Cmp_Ip_apxBase[instance];

        uint32 ier = 0u;
        uint32 csr = 0u;
        uint32 rrcr0 = 0u;
        uint32 rrcr1 = 0u;
        uint32 rrcsr = 0u;
        uint32 rrsr = 0u;

        Cmp_Ip_InitCcr0(instance, userConfig);
        Cmp_Ip_InitCcr1(instance, userConfig);
        Cmp_Ip_InitCcr2(instance, userConfig);
        Cmp_Ip_InitDcr(instance, userConfig);

        ier |= LPCMP_IER_CFR_IE(((userConfig->Comparator.OutputInterruptTrigger == CMP_IP_INTTRIG_NONE)|| \
                                 (userConfig->Comparator.OutputInterruptTrigger == CMP_IP_INTTRIG_FALLING_EDGE))?0U:1U);
        ier |= LPCMP_IER_CFF_IE(((userConfig->Comparator.OutputInterruptTrigger == CMP_IP_INTTRIG_NONE)|| \
                                 (userConfig->Comparator.OutputInterruptTrigger == CMP_IP_INTTRIG_RISING_EDGE))?0U:1U);
        ier |= LPCMP_IER_RRF_IE((userConfig->Trigger.EnableRoundRobinInterrupt)?1U:0U);
        Cmp_Ip_axState[instance].CmpInterruptEdge =  userConfig->Comparator.OutputInterruptTrigger;


        rrcr1 |= (uint32)userConfig->Trigger.RoundRobinEnChannelMask << (uint32)LPCMP_RRCR1_RR_CH0EN_SHIFT;
        rrcsr |= (uint32)userConfig->Trigger.PrepgmStateChannelMask << (uint32)LPCMP_RRCSR_RR_CH0OUT_SHIFT;
        rrcr0 |= LPCMP_RRCR0_RR_INITMOD(userConfig->Trigger.InitDelayValue);
        rrcr0 |= LPCMP_RRCR0_RR_NSAM(userConfig->Trigger.SampleDelay);
        rrcr1 |= LPCMP_RRCR1_FIXCH(userConfig->Trigger.FixedChannel);
        rrcr1 |= LPCMP_RRCR1_FIXP(userConfig->Trigger.FixedPort);
        Cmp_Ip_axState[instance].EnRoundRobinInterrupt = userConfig->Trigger.EnableRoundRobinInterrupt;
        rrcr0 |= LPCMP_RRCR0_RR_EN((userConfig->Trigger.EnableRoundRobin)?1U:0U);


        base->IER = ier;
        base->CSR = csr;
        base->RRCR0 = rrcr0;
        base->RRCR1 = rrcr1;
        base->RRCSR = rrcsr;
        base->RRSR = rrsr;

        Cmp_Ip_axState[instance].State = ICU_CMP_IP_INIT;
        Cmp_Ip_axState[instance].TriggerNotification = userConfig->TriggerNotification;
        Cmp_Ip_axState[instance].ComparatorNotification = userConfig->ComparatorNotification;
        Cmp_Ip_axState[instance].CallbackParam1 = userConfig->CallbackParam1;
#endif

#ifdef CMP_IP_NOT_SUPPORT_LOWPOWER

        Cmp_Ip_InitCmpC0(instance, userConfig);
        Cmp_Ip_InitCmpC1(instance, userConfig);
        Cmp_Ip_InitCmpC2(instance, userConfig);

        Cmp_Ip_axState[instance].CmpInterruptEdge =  userConfig->Comparator.OutputInterruptTrigger;
        Cmp_Ip_axState[instance].EnRoundRobinInterrupt = userConfig->Trigger.EnableRoundRobinInterrupt;
        Cmp_Ip_axState[instance].State = ICU_CMP_IP_INIT;
        Cmp_Ip_axState[instance].TriggerNotification = userConfig->TriggerNotification;
        Cmp_Ip_axState[instance].ComparatorNotification = userConfig->ComparatorNotification;
        Cmp_Ip_axState[instance].CallbackParam1 = userConfig->CallbackParam1;
#endif
    }
    else
    {
        /* instance already initialized - use deinitialize first */
        retStatus = CMP_IP_STATUS_ERROR;
    }
    return retStatus;
}

/**
* @brief      Icu driver function that reset CMP.
* @details    This function reset CMP instance on reset values
*
* @param[in]  instance      - The instance index
*
* @implements Cmp_Ip_Deinit_Activity
*/
Cmp_Ip_StatusType Cmp_Ip_Deinit(uint8 instance)
{
    /* disable interrupt, stop notifications */
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
    DevAssert(Cmp_Ip_axState[instance].State == ICU_CMP_IP_INIT);
#endif
    Cmp_Ip_StatusType   retStatus = CMP_IP_STATUS_SUCCESS;

    if(ICU_CMP_IP_INIT == Cmp_Ip_axState[instance].State)
    {
        Cmp_Ip_axState[instance].State = ICU_CMP_IP_UNINIT;
    }
    else
    {
        /* instance already de-initialize - use initialize first */
        retStatus = CMP_IP_STATUS_ERROR;
    }
    return retStatus;
}

/**
* @brief      Icu driver function that enable user notification.
* @details    This function enables CMP instance for calling user notification on interrupt
*
* @param[in]  instance      - The instance index
*
* @implements Cmp_Ip_EnableNotification_Activity
*/
void Cmp_Ip_EnableNotification(uint8 instance)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
    if((NULL_PTR == Cmp_Ip_axState[instance].TriggerNotification) && (NULL_PTR == Cmp_Ip_axState[instance].ComparatorNotification))
    {
        DevAssert(FALSE);
    }
#endif

    Cmp_Ip_axState[instance].NotificationEnabled = TRUE;
}

/**
* @brief      Icu driver function that disable user notification.
* @details    This function disable CMP instance for calling user notification on interrupt
*
* @param[in]  instance      - The instance index
*
* @implements Cmp_Ip_DisableNotification_Activity
*/
void Cmp_Ip_DisableNotification(uint8 instance)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif

    Cmp_Ip_axState[instance].NotificationEnabled = FALSE;
}
/* @implements Cmp_Ip_EnableInterrupt_Activity */
void Cmp_Ip_EnableInterrupt(uint8 instance)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif

#ifdef CMP_IP_SUPPORT_LOWPOWER
LPCMP_Type * base = Cmp_Ip_apxBase[instance];

    /* clear w1c bits */
    base->CSR = LPCMP_CSR_CFR_MASK | LPCMP_CSR_CFF_MASK | LPCMP_CSR_RRF_MASK;

    switch (Cmp_Ip_axState[instance].CmpInterruptEdge)
    {
        case CMP_IP_INTTRIG_NONE:
            base->IER  |= LPCMP_IER_CFR_IE(0u) | LPCMP_IER_CFF_IE(0u);
            break;
        case CMP_IP_INTTRIG_FALLING_EDGE:
            base->IER  |= LPCMP_IER_CFR_IE(0u) | LPCMP_IER_CFF_IE(1u);
            break;
        case CMP_IP_INTTRIG_RISING_EDGE:
            base->IER  |= LPCMP_IER_CFR_IE(1u) | LPCMP_IER_CFF_IE(0u);
            break;
        case CMP_IP_INTTRIG_BOTH_EDGES:
            base->IER  |= LPCMP_IER_CFR_IE(1u) | LPCMP_IER_CFF_IE(1u);
            break;
        default:
            /* Impossible case */
            break;
    }

    if (TRUE == Cmp_Ip_axState[instance].EnRoundRobinInterrupt)
    {
        /* clear w1c bits */
        base->RRSR = (0xFFu << LPCMP_RRSR_RR_CH0F_SHIFT);
        base->IER |= LPCMP_IER_RRF_IE(1u);
    }
#endif

#ifdef CMP_IP_NOT_SUPPORT_LOWPOWER
    CMP_Type * base = Cmp_Ip_apxBase[instance];

    /* clear w1c bits */
    base->C0 |= CMP_C0_CFF_MASK | CMP_C0_CFR_MASK;
    switch (Cmp_Ip_axState[instance].CmpInterruptEdge)
    {
        case CMP_IP_INTTRIG_RISING_EDGE:
            base->C0 |= CMP_C0_IER(1U) | CMP_C0_IEF(0U);
            break;
        case CMP_IP_INTTRIG_FALLING_EDGE:
            base->C0 |= CMP_C0_IER(0U) | CMP_C0_IEF(1U);
            break;
        case CMP_IP_INTTRIG_BOTH_EDGES:
            base->C0 |= CMP_C0_IER(1U) | CMP_C0_IEF(1U);
            break;
        case CMP_IP_INTTRIG_NONE:
            base->C0 |= CMP_C0_IER(0U) | CMP_C0_IEF(0U);
            break;
        default:
            /* Impossible case */
            break;
    }

    if (TRUE == Cmp_Ip_axState[instance].EnRoundRobinInterrupt)
    {
        /* clear w1c bits */
        base->C2 |= CMP_C2_CH0F_MASK | CMP_C2_CH1F_MASK | CMP_C2_CH2F_MASK | CMP_C2_CH3F_MASK | CMP_C2_CH4F_MASK | CMP_C2_CH5F_MASK | CMP_C2_CH6F_MASK | CMP_C2_CH7F_MASK;
        base->C2 |= CMP_C2_RRIE(1U);
    }
#endif

}

/**
 * @brief Disable CMP interrupt.
 * @implements Cmp_Ip_DisableInterrupt_Activity
 */
void Cmp_Ip_DisableInterrupt(uint8 instance)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif

#ifdef CMP_IP_SUPPORT_LOWPOWER
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];

    base->IER &= (~(LPCMP_IER_CFR_IE(1u) | LPCMP_IER_CFF_IE(1u)));
    base->IER &= (~LPCMP_IER_RRF_IE(1u));
#endif

#ifdef CMP_IP_NOT_SUPPORT_LOWPOWER
    CMP_Type * base = Cmp_Ip_apxBase[instance];

    base->C0 &= (~(CMP_C0_IER(1U) | CMP_C0_IEF(1U)));
    base->C2 &= (~CMP_C2_RRIE(1U));
#endif
}

/**
 * @brief Set the type of activation for interrupt.
 */
void Cmp_Ip_SetInterruptActivation(uint8 instance, Cmp_Ip_OutputInterruptTriggerType Edge)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif

    Cmp_Ip_axState[instance].CmpInterruptEdge = Edge;

}

#if (CMP_IP_GET_INPUT_STATE_API == STD_ON)
/**
 * @brief Get instance status.
 */
boolean Cmp_Ip_GetStatus(uint8 instance)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif
    boolean status;

#ifdef CMP_IP_SUPPORT_LOWPOWER
    status = (Cmp_Ip_apxBase[instance]->CSR == 0x0U)?FALSE:TRUE;
#endif

#ifdef CMP_IP_NOT_SUPPORT_LOWPOWER
    uint32 flag_Cmp;
    uint32 flag_RR;

    flag_Cmp = Cmp_Ip_apxBase[instance]->C0 & (CMP_C0_CFF_MASK | CMP_C0_CFR_MASK);
    flag_RR  = CMP_C2_CH0F_MASK | CMP_C2_CH1F_MASK | CMP_C2_CH2F_MASK | CMP_C2_CH3F_MASK | CMP_C2_CH4F_MASK | CMP_C2_CH5F_MASK | CMP_C2_CH6F_MASK | CMP_C2_CH7F_MASK;
    flag_RR  = Cmp_Ip_apxBase[instance]->C2 & flag_RR;

    status   = ((flag_Cmp != 0U) || (flag_RR != 0U)) ? TRUE:FALSE;

#endif

    return status;
}
#endif

#if (defined(ICU_CMP_0_ISR_USED) || \
     defined(ICU_CMP_1_ISR_USED) || \
     defined(ICU_CMP_2_ISR_USED))

static void Cmp_Ip_IrqHandler(uint8 instance)
{
#if (CMP_IP_DEV_ERROR_DETECT == STD_ON)
    DevAssert(instance < ICU_CMP_INSTANCE_COUNT);
#endif
#ifdef CMP_IP_SUPPORT_LOWPOWER
    LPCMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 ier = base->IER & (LPCMP_IER_CFR_IE_MASK | LPCMP_IER_CFF_IE_MASK | LPCMP_IER_RRF_IE_MASK);
    uint32 csr = base->CSR & (LPCMP_CSR_CFR_MASK | LPCMP_CSR_CFF_MASK | LPCMP_CSR_RRF_MASK);
    uint32 flags = ier & csr; /* mask out interrupt sources that are not enabled - spurious interrupts */
    
    if ((uint32)0U != flags)
    {
        /* clear w1c bits */
        base->CSR = LPCMP_CSR_CFR_MASK | LPCMP_CSR_CFF_MASK | LPCMP_CSR_RRF_MASK;
        base->RRSR = (0xFFu << LPCMP_RRSR_RR_CH0F_SHIFT);
        if (Cmp_Ip_axState[instance].NotificationEnabled)
        {
            if (NULL_PTR != Cmp_Ip_axState[instance].ComparatorNotification)
            {
                if (0U != (flags & (LPCMP_CSR_CFR_MASK | LPCMP_CSR_CFF_MASK)))
                {
                    Cmp_Ip_axState[instance].ComparatorNotification(Cmp_Ip_axState[instance].CallbackParam1, FALSE);
                }
            }
            if (NULL_PTR != Cmp_Ip_axState[instance].TriggerNotification)
            {
                if (0U != (flags & LPCMP_CSR_RRF_MASK))
                {
                    Cmp_Ip_axState[instance].TriggerNotification(Cmp_Ip_axState[instance].CallbackParam1, FALSE);
                }
            }
        }
    }
#endif
#ifdef CMP_IP_NOT_SUPPORT_LOWPOWER
    CMP_Type * base = Cmp_Ip_apxBase[instance];
    uint32 flag_Cmp;
    uint32 flag_RR;
    uint32 intterEnable;

    flag_RR  = CMP_C2_CH0F_MASK | CMP_C2_CH1F_MASK | CMP_C2_CH2F_MASK | CMP_C2_CH3F_MASK | CMP_C2_CH4F_MASK | CMP_C2_CH5F_MASK | CMP_C2_CH6F_MASK | CMP_C2_CH7F_MASK;
    flag_RR  = base->C2 & flag_RR;
    flag_Cmp = base->C0 & (CMP_C0_CFF_MASK | CMP_C0_CFR_MASK);
    intterEnable = base->C0 & (CMP_C0_IER_MASK | CMP_C0_IEF_MASK);
    
    if (flag_Cmp && (flag_Cmp || flag_RR))
    {
    /* clear w1c bits */
    base->C0 |= CMP_C0_CFF_MASK | CMP_C0_CFR_MASK;
    base->C2 |= CMP_C2_CH0F_MASK | CMP_C2_CH1F_MASK | CMP_C2_CH2F_MASK | CMP_C2_CH3F_MASK | CMP_C2_CH4F_MASK | CMP_C2_CH5F_MASK | CMP_C2_CH6F_MASK | CMP_C2_CH7F_MASK;
        if (Cmp_Ip_axState[instance].NotificationEnabled)
        {
            if (NULL_PTR != Cmp_Ip_axState[instance].ComparatorNotification)
            {
                if (0U != flag_Cmp)
                {
                    Cmp_Ip_axState[instance].ComparatorNotification(Cmp_Ip_axState[instance].CallbackParam1, FALSE);
                }
            }
            if (NULL_PTR != Cmp_Ip_axState[instance].TriggerNotification)
            {
                if (0U != flag_RR)
                {
                    Cmp_Ip_axState[instance].TriggerNotification(Cmp_Ip_axState[instance].CallbackParam1, FALSE);
                }
            }
        }
    }
#endif
} 
#endif

#if (defined(ICU_CMP_0_ISR_USED))
ISR(CMP_0_ISR)
{
    /*enable IRQs*/
    Cmp_Ip_IrqHandler(0U);
    EXIT_INTERRUPT();
}
#endif

#if (defined(ICU_CMP_1_ISR_USED))
ISR(CMP_1_ISR)
{
    /*enable IRQ*/
    Cmp_Ip_IrqHandler(1U);
    EXIT_INTERRUPT();
}
#endif

#if (defined(ICU_CMP_2_ISR_USED))
ISR(CMP_2_ISR)
{
    /*enable IRQ*/
    Cmp_Ip_IrqHandler(2U);
    EXIT_INTERRUPT();
}
#endif


#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#endif /* CMP_IP_USED */

#ifdef __cplusplus
}
#endif

/** @} */
