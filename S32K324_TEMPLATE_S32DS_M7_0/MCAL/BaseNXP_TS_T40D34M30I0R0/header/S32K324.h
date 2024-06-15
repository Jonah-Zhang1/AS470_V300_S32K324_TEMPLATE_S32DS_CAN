/*
** ###################################################################
**     Processor:           S32K324_M7
**     Reference manual:    S32K3xx RM Rev.3
**     Version:             rev. 1.1, 2021-10-21
**     Build:               b211021
**
**     Abstract:
**         Peripheral Access Layer for S32K324_M7
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2021 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may only be
**     used strictly in accordance with the applicable license terms. By expressly
**     accepting such terms or by downloading, installing, activating and/or otherwise
**     using the software, you are agreeing that you have read, and that you agree to
**     comply with and are bound by, such license terms. If you do not agree to be
**     bound by the applicable license terms, then you may not retain, install,
**     activate or otherwise use the software. The production use license in
**     Section 2.3 is expressly granted for this software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 Taru Shree 01-Sep-21  Initial release based on 
**                                      RM Rev.3.
**
**     - rev. 1.1 Taru Shree 21-Oct-21  1)Initial release based on 
**                                      RM Rev.3.
**                                      2)EMAC-                               	
**                       	            MAC_VLAN_INCL register array          
**                                      with MAC_VLAN_INCL, MAC_VLAN_INCL0,   
**                                      MAC_VLAN_INCL1, MAC_VLAN_INCL2,       
**                                      MAC_VLAN_INCL3, MAC_VLAN_INCL4,       
**                                      MAC_VLAN_INCL5, MAC_VLAN_INCL6 and    
**                                      MAC_VLAN_INCL7 registers is added.     
**
** ###################################################################
*/

/*!
 * @file S32K324.h
 * @version 1.1
 * @date 2021-10-21
 * @brief Peripheral Access Layer for S32K324
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K324_H_)  /* Check if memory map has not been already included */
#define S32K324_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K324_ADC.h"
#include "S32K324_AXBS_LITE.h"
#include "S32K324_BCTU.h"
#include "S32K324_CMU_FC.h"
#include "S32K324_CMU_FM.h"
#include "S32K324_CONFIGURATION_GPR.h"
#include "S32K324_CRC.h"
#include "S32K324_DCM.h"
#include "S32K324_DCM_GPR.h"
#include "S32K324_DMA.h"
#include "S32K324_DMAMUX.h"
#include "S32K324_DMA_TCD.h"
#include "S32K324_EIM.h"
#include "S32K324_EMAC.h"
#include "S32K324_EMIOS.h"
#include "S32K324_ERM.h"
#include "S32K324_FCCU.h"
#include "S32K324_FIRC.h"
#include "S32K324_FLASH.h"
#include "S32K324_FLEXCAN.h"
#include "S32K324_FLEXIO.h"
#include "S32K324_FXOSC.h"
#include "S32K324_INTM.h"
#include "S32K324_JDC.h"
#include "S32K324_LCU.h"
#include "S32K324_LPCMP.h"
#include "S32K324_LPI2C.h"
#include "S32K324_LPSPI.h"
#include "S32K324_LPUART.h"
#include "S32K324_MCM_CM7.h"
#include "S32K324_MC_CGM.h"
#include "S32K324_MC_ME.h"
#include "S32K324_MC_RGM.h"
#include "S32K324_MDM_AP.h"
#include "S32K324_MSCM.h"
#include "S32K324_MU.h"
#include "S32K324_PFLASH.h"
#include "S32K324_PIT.h"
#include "S32K324_PLL.h"
#include "S32K324_PMC.h"
#include "S32K324_PRAMC.h"
#include "S32K324_QUADSPI.h"
#include "S32K324_QUADSPI_ARDB.h"
#include "S32K324_RTC.h"
#include "S32K324_SAI.h"
#include "S32K324_SDA_AP.h"
#include "S32K324_SELFTEST_GPR.h"
#include "S32K324_SEMA42.h"
#include "S32K324_SIRC.h"
#include "S32K324_SIUL2.h"
#include "S32K324_STCU.h"
#include "S32K324_STM.h"
#include "S32K324_SWT.h"
#include "S32K324_SXOSC.h"
#include "S32K324_TEMPSENSE.h"
#include "S32K324_TRGMUX.h"
#include "S32K324_TSPC.h"
#include "S32K324_VIRT_WRAPPER.h"
#include "S32K324_WKPU.h"
#include "S32K324_XBIC.h"
#include "S32K324_XRDC.h"
#include "S32K324_NVIC.h"
#include "S32K324_SCB.h"
#include "S32K324_SYSTICK.h"
#include "S32K324_MPU.h"

#endif  /* #if !defined(S32K324_H_) */
