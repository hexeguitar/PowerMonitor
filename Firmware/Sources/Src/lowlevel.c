/*
**
**                           Lowlevel.c
**
**
**********************************************************************/
/*
 * Author:  Piotr Zapart
 *          www.hexeguitar.com
**********************************************************************/
#include <xc.h>
#include <libpic30.h>
#include <stdlib.h>
#include "i2c.h"
#include "stdint.h"

#define IAL_ADC_CH		2	//Ialarm pot adc channel
#define BUZZER_F		2400
#define FCLK			8000000
#define TIM3_FREQ               125     //125Hz - 8ms
#define UART_BAUD               9600

////////////////////////////////////////////////////////////////////////

void hardware_init (void)
{
         ///Clock
	CLKDIVbits.RCDIV = 0b000;	//8MHz

	/// Ports
        AD1PCFG = 0xFFFF;               //all port to digital
        TRISBbits.TRISB1 = 1;           //Calibration mode input

	/// ### PWM/OC ###
	OC1CONbits.OCM = 0b000; 	// Disable Output Compare Module
	OC1R = (FCLK/(BUZZER_F<<2)); 	// Write the duty cycle for the first PWM pulse
	OC1RS = (FCLK/(BUZZER_F<<2));	// Write the duty cycle for the second PWM pulse
	OC1CONbits.OCTSEL = 0; 		// Select Timer 2 as output compare time base
	OC1R = (FCLK/(BUZZER_F<<2)); 	// Load the Compare Register Value
	OC1CONbits.OCM = 0b110; 	// Select the Output Compare mode 
	OC1CONbits.OCSIDL = 1;		//disable in idle

	/// ### Timer2 - PWM base ###
	T2CONbits.TON = 0;      	// Disable Timer
	T2CONbits.TCS = 0;      	// Select internal instruction cycle clock
	T2CONbits.TGATE = 0;  		// Disable Gated Timer mode
	T2CONbits.TSIDL = 1;		// disable in idle mode
	T2CONbits.TCKPS = 0b00; 	// Select 1:256 Prescaler
	TMR2 = 0x00; 			// Clear timer register
	PR2 = (FCLK/(BUZZER_F<<1)); 	// Load the period value 
	
	T2CONbits.TON = 1;      	// Start Timer

	// ### Timer 3 - 8ms delay/debounce CTC ###
	T3CONbits.TON = 0;      	// Disable Timer
	T2CONbits.TCS = 0;      	// Select internal instruction cycle clock
	T3CONbits.TGATE = 0;  		// Disable Gated Timer mode
	T3CONbits.TSIDL = 1;		// disable in idle mode
	T3CONbits.TCKPS = 0b00; 	// Select 1:1 Prescaler
	TMR3 = 0x00; 			// Clear timer register
	PR3 = (FCLK/(TIM3_FREQ<<1));	// 8ms
        IPC2bits.T3IP = 5;              // int priority = 2
	IEC0bits.T3IE = 1;		// enable TIM3 interrupt
	T3CONbits.TON = 1;      	// Start Timer
        
        /// ### ADC ###
	AD1PCFG &=  ~(1<<IAL_ADC_CH);	//set AN2 to analog in

	AD1CON1bits.SSRC = 0b111;
	AD1CON1bits.ASAM = 1;		//Auto conversion ON
	AD1CON1bits.FORM = 0;
	AD1CON3bits.SAMC = 16;		//auto sample time
	AD1CON3bits.ADCS = 3;		//ADC clock=Fcy/4
	AD1CHSbits.CH0SA = 2;    	// MUXA +ve input selection (AIN2) for CH0
	AD1CHSbits.CH0NA = 0;    	// MUXA -ve input selection (Vref-) for CH0
	IFS0bits.AD1IF   = 0;           // Clear the A/D interrupt flag bit
        IPC3bits.AD1IP = 7;             //int priority 5
	IEC0bits.AD1IE   = 1;           // Enable A/D interrupt

	AD1CON1bits.ADON = 1;           // Turn on the A/D converter
        
	/// ### I2C ###
        InitI2C(); //

        // ### SPI ###
        IFS0bits.SPI1IF = 0;            // Clear the Interrupt Flag
        IEC0bits.SPI1IE = 0;            // Disable the Interrupt

        // SPI1CON1 Register Settings
        SPI1CON1bits.DISSCK = 0;        // Internal Serial Clock is Enabled
        SPI1CON1bits.DISSDO = 0;        // SDOx pin is controlled by the module
        SPI1CON1bits.MODE16 = 0;        // Communication is byte-wide (8 bits)
        SPI1CON1bits.SMP = 0;           // Input data is sampled at the middle of data
                                        // output time
        SPI1CON1bits.CKE = 0;           // Serial output data changes on transition
                                        // from Idle clock state to active clock state
        SPI1CON1bits.CKP = 0;           // Idle state for clock is a low level;
                                        // active state is a high level
        SPI1CON1bits.PPRE = 0b10;       // primary prescaler 1:4  8MHz/4 = 2MHz
        SPI1CON1bits.SPRE = 0b110;      // secondary prescaler 1:2 (4MHz/2 = 1MHz)
  
        SPI1CON1bits.MSTEN = 1;         // Master mode Enabled
        SPI1STATbits.SPIEN = 1;         // Enable SPI module

        /// ### USART ###
        /*
         * FOSC = 8MHz, Fp = 4MHz
         */
        TRISBbits.TRISB2 = 1;           //RX
        TRISBbits.TRISB7 = 0;           //TX

        U1MODEbits.STSEL = 0;           // 1-Stop bit
        U1MODEbits.PDSEL = 0;           // No Parity, 8-Data bits
        U1MODEbits.ABAUD = 0;           // Auto-Baud disabled
        U1MODEbits.BRGH = 0;            // Standard-Speed mode
        U1BRG = (((FCLK/2)/(UART_BAUD))/16)-1;  // Baud Rate
        U1STAbits.UTXISEL0 = 1;         // Interrupt if the buffer is empty
        U1STAbits.UTXISEL1 = 0;
        U1STAbits.URXISEL = 0;          // Interrupt after one RX character is received;
        IPC2bits.U1RXIP = 2;            // RX int priority = 3
        IPC3bits.U1TXIP = 1;            // TX prioritry = 4
        IEC0bits.U1TXIE = 1;            // Enable UART TX interrupt
        IEC0bits.U1RXIE = 1;            // Enable UART RX interrupt

        U1MODEbits.UARTEN = 1;          // Enable UART
        U1STAbits.UTXEN = 1;            // Enable UART TX     
}





