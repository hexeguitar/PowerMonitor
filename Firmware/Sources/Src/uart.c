/*
 *  UART1 handling functions
 */
#include <xc.h>
#include <libpic30.h>
#include <stdlib.h>
#include "stdint.h"
#include "uart1.h"
//#include "globalvar.h"

#define RX_BUFFER_SIZE 16
#define TX_BUFFER_SIZE 16
/* size of RX/TX buffers */
#define RX_BUFFER_MASK (RX_BUFFER_SIZE - 1)
#define TX_BUFFER_MASK (TX_BUFFER_SIZE - 1)

#if (RX_BUFFER_SIZE & RX_BUFFER_MASK)
#error RX buffer size is not a power of 2
#endif
#if (TX_BUFFER_SIZE & TX_BUFFER_MASK)
#error TX buffer size is not a power of 2
#endif

#define DELAY_105uS             asm volatile ("REPEAT, #4201"); Nop(); // 105uS delay


static volatile char uart_rx_buffer[RX_BUFFER_SIZE];
static volatile char uart_tx_buffer[TX_BUFFER_SIZE];
static volatile uint8_t rx_tail = 0;
static volatile uint8_t rx_head = 0;
static volatile uint8_t tx_tail = 0;
static volatile uint8_t tx_head = 0;
static volatile uint16_t last_rx_error = 0;
static volatile uint8_t startup = 0;


void UART1_send_char(char data)
{
    uint8_t  tmphead;
    startup = 1;
    tmphead  = (tx_head+1) & TX_BUFFER_MASK;

    while ( tmphead == tx_tail )
    {
        /* wait for free space in buffer */
    }
    uart_tx_buffer[tmphead] = data;
    tx_head = tmphead;

    IEC0bits.U1TXIE = 1;            // Enable UART TX interrupt
}

void UART1_send_string(const char *buffer)
{
    while(*buffer != '\0')
        {
            UART1_send_char(*buffer++);
        }
}
void UART1_send_string_ln(const char *buffer)
{
   while(*buffer != '\0')
    {
        UART1_send_char(*buffer++);
    }
   UART1_send_char('\n');
}

/*
 * ################## UART1 return byte from ringbuffer #######################
 */
uint16_t UART1_get_char(void)
{
    uint8_t tmptail,data;

    if (rx_head == rx_tail)
    {
        return UART_NO_DATA;   /* no data available */
    }

    /* calculate /store buffer index */
    tmptail = (rx_tail+1) & RX_BUFFER_MASK;
    rx_tail = tmptail;

    /* get data from receive buffer */
    data = uart_rx_buffer[tmptail];

    return (last_rx_error<<8)+ data;
}

/*
 * ################## UART1 Receive Interrupt #######################
 */


void __attribute__((interrupt,no_auto_psv)) _U1TXInterrupt( void )
{
    uint8_t tmptail;
    /*
     * once TX int is triggered after enabling the TX transmitter
     * it needs data to shift out and to generate the next TX interrupt
     * according to the UTXISEL
     * we are sending one '+'. Without it the trasmitter will be waiting
     * for one byte to be shifted out, thus not generating any interrupt.  
     */

    if (!startup)
    {
        DELAY_105uS
        U1TXREG = '+';        //send one char to generate int
    }
    if (tx_head != tx_tail)
    {
    
        tmptail = (tx_tail+1) & TX_BUFFER_MASK;
        tx_tail = tmptail;
  
        U1TXREG = uart_tx_buffer[tmptail]; 
    }
    else
    {
        U1TXREG = '\n';                 //send one more char to ensure the
                                        //interrupt will be triggered next time
        IEC0bits.U1TXIE = 0;            // Disable UART TX interrupt
    }
    IFS0bits.U1TXIF = 0; // Clear TX Interrupt flag
}


void __attribute__((interrupt,no_auto_psv)) _U1RXInterrupt( void )
{
    IFS0bits.U1RXIF = 0; // Clear RX Interrupt flag
    uint8_t data,tmphead;
    uint16_t error = 0;

    data = U1RXREG;
    
    /* Check for receive errors */
    if(U1STAbits.FERR == 1)
    {
        error = UART_FRAME_ERROR;
    }
    /* Must clear the overrun error to keep UART receiving */
    if(U1STAbits.OERR == 1)
    {
        U1STAbits.OERR = 0;
        error = UART_OVERRUN_ERROR;
    }
    /* Get the data */
       

        tmphead = (rx_head+1) & RX_BUFFER_MASK;

        if (tmphead == rx_tail)
        {
            /* error: receive buffer overflow */
            error = UART_BUFFER_OVERFLOW;
        }
        else
        {
            /* store new index */
            rx_head = tmphead;
            /* store received data in buffer */
            uart_rx_buffer[tmphead] = data;
        }
   
    last_rx_error = error;
    
}