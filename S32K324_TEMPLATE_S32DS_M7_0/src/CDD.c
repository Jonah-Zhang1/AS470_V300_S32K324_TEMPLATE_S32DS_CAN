/*
 * CDD.c
 *
 *  Created on: 2024Äê6ÔÂ30ÈÕ
 *      Author: zhang_liu
 */
#include "CDD.h"
#include "Queue.h"

void CDD_TxConfirmation(PduIdType CanIfTxPduId, Std_ReturnType result)
{
	if(result == E_OK)
	{
		print("\r\nCDD_TxConfirmation, result: OK, CanIfTxPduId = %d\r\n", CanIfTxPduId);
	}
}

void CDD_RxIndication(PduIdType RxPduId, const PduInfoType * PduInfoPtr)
{
	print("\r\nCDD_RxIndication, RxPduId = 0x%x\r\n", RxPduId);
	PduLengthType len = PduInfoPtr->SduLength;
	print("Length: %d\r\n",len);
	uint8 *pData = PduInfoPtr->SduDataPtr;
	for(uint8 i =0;i < len;i ++)
	{
		print("%x ",pData[i]);
	}
}

