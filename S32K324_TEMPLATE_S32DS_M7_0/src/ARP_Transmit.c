/*******************************
 * Discription:
 * This file provides ARP frame Transmition API base on Ethernet
 * Date:
 * 2024/06/23
 * Time:
 * 8锛�18
 * Author锛�
 * Mei Wen
 *******************************/

#include "ARP_Transmit.h"

static uint8 myTxbuffer[5];
static Eth_bufIdxType TmpBufferIdx;
static uint8* TmpBufferPtr[5] = {&myTxbuffer[0], &myTxbuffer[1], &myTxbuffer[2], &myTxbuffer[3],&myTxbuffer[4]};
static volatile BufReq_ReturnType Global_TempUsage1;
static volatile Std_ReturnType EthDemoRetVal;
static uint8 ArpData[28] = 
{
    0x00,0x01,0x08,0x00,0x06,0x04,0x00,0x01,0x66,0x55,0x44,0x33,0x22,0x11,
    0xc0,0xa8,0x01,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0xa8,0x01,0x64
};
static uint8 MacDestBroadAddress[6] = {0xff,0xff,0xff,0xff,0xff,0xff};

FUNC(void, ETH_PUBLIC_CODE) Eth_memcpy
(
    uint8* dst, 
    uint8* src,
    uint16 len
)
{
    for(uint16 i = 0; i < len; i++)
    {
        dst[i] = src[i];
    }
}


void delay(uint32 time)
{
    volatile uint32 loopTimeCnt = 3000u;
    while(time > 0)
    {
        while(loopTimeCnt > 0)
        {
            loopTimeCnt--;
        }
        time--;
    }
}

FUNC(void, ETH_PUBLIC_CODE) TranmitArpFrame
(
    void
)
{
    boolean TxStateus = 0;
    uint16 Tem_Txlength = 28;

    Global_TempUsage1 = Eth_43_GMAC_ProvideTxBuffer(0, 0, &TmpBufferIdx, TmpBufferPtr, &Tem_Txlength);
    Eth_memcpy(TmpBufferPtr[0], ArpData, 28);
    EthDemoRetVal = Eth_43_GMAC_Transmit(0, TmpBufferIdx, ETH_ARP_PROTOCOL, TRUE, 28, &MacDestBroadAddress[0]);
}

FUNC(Std_ReturnType, ETH_PUBLIC_CODE) Ethernet_Init
(
    void
)
{
    Std_ReturnType ret = E_NOT_OK;
    Eth_RxStatusType RxStatus;

    Eth_43_GMAC_Init(NULL_PTR);

    if(Eth_43_GMAC_SetControllerMode(EthConf_EthCtrlConfig_EthCtrlConfig_0, ETH_MODE_ACTIVE) == E_OK)
    {
        for(uint8 i = 0; i < 4; i++)
        {
            TranmitArpFrame();
            delay(1);
            User_UartPrintString("Eth_43_GMAC_SetControllerMode_ETH_MODE_ACTIVE!\r\n");
        }
    	
        ret = E_OK;
    }
    return ret;
}
