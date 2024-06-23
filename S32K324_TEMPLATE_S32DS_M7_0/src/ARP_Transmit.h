/*******************************
 * Discription:
 * This file provides ARP frame Transmition API base on Ethernet
 * Date:
 * 2024/06/23
 * Time:
 * 8：18
 * Author：
 * Mei Wen
 *******************************/


#ifndef ARP_TRANSMIT_H
#define ARP_TRANSMIT_H

#include "Eth_43_GMAC.h"
#include "SchM_Eth_43_GMAC.h"
#include "Queue.h"

#define ETH_PUBLIC_CODE
#define ETH_ARP_PROTOCOL (0x0806U)

typedef uint32 Eth_bufIdxType;

FUNC(Std_ReturnType, ETH_PUBLIC_CODE) Ethernet_Init
(
    void
);


#endif/*ARP_TRANSMIT_H*/