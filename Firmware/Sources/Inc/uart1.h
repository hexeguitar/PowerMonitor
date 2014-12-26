/* 
 * File:   uart.h
 * Author: Pio
 *
 * Created on 7. Juli 2014, 21:07
 */

#ifndef UART_H
#define	UART_H


#define UART_FRAME_ERROR      0x0400              /* Framing Error by UART       */
#define UART_OVERRUN_ERROR    0x0300              /* Overrun condition by UART   */
#define UART_BUFFER_OVERFLOW  0x0200              /* receive ringbuffer overflow */
#define UART_NO_DATA          0x0100              /* no receive data available   */


uint16_t UART1_get_char(void);
void UART1_send_char(char data);
void UART1_send_string(const char *buffer);
void UART1_send_string_ln(const char *buffer);
#endif	/* UART_H */

