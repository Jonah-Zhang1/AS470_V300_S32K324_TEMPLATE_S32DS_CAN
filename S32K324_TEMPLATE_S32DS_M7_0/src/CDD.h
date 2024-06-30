/*
 * CDD.h
 *
 *  Created on: 2024Äê6ÔÂ30ÈÕ
 *      Author: zhang_liu
 */

#ifndef CDD_H_
#define CDD_H_

#include "Can_43_FLEXCAN.h"

void CDD_TxConfirmation(PduIdType CanIfTxPduId, Std_ReturnType result);

void CDD_RxIndication(PduIdType RxPduId, const PduInfoType * PduInfoPtr);

#endif /* CDD_H_ */
