/*
 * main.h
 *
 *  Created on: 2024��6��22��
 *      Author: zhang_liu
 */

#ifndef MAIN_H_
#define MAIN_H_

#define IRQ_ENABLE    __asm__("cpsie i")
#define IRQ_DISENABLE __asm__("cpsid i")

#define UART_CONFIG_CHANNEL_0       (0U)  //zm3 Add 20240613  for UART channel0

#endif /* MAIN_H_ */
