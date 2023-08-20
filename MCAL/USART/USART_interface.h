/*******************************************************************/
/* Author      : Ibrahim Diab                                      */
/* File Name   : USART_interface.h                                 */
/* Description : Interfacing macros for USART module STM32F103     */
/*******************************************************************/

 // Header guard to prevent multiple inclusions
#ifndef USART_INTERFACE_H 
#define USART_INTERFACE_H

// Function prototypes for initializing USARTX with a given baud rate
void USART1_init(uint32 baudRate);
void USART2_init(uint32 baudRate);

// Function prototypes for sending a single byte over USARTX
void USART1_sendByte(uint8 byteToSend);
void USART2_sendByte(uint8 byteToSend);

/* 
 * Receive a byte through USARTX
 * Check if data exist then save the data and return if data exists or not.
 */
uint8 USART1_receiveByte(uint8* byte);
uint8 USART2_receiveByte(uint8* byte);

// Function prototypes for sending a null-terminated string over USARTX
void USART1_sendString(uint8 *stringToSend);
void USART2_sendString(uint8 *stringToSend);

// Function prototypes for receiving a null-terminated string over USARTX
void USART1_receiveString(uint8 *strToReceive);
void USART2_receiveString(uint8 *strToReceive);

#endif // USART_INTERFACE_H





