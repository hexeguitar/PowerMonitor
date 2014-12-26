/* 
 * File:   globalvar.h
 * Author:  Piotr Zapart
 *          www.hexeguitar.com
 *
 * Created on 8. Juli 2014, 12:53
 */

#ifndef GLOBALVAR_H
#define	GLOBALVAR_H

#define RB1INPUT               (!PORTBbits.RB1)
#define BUZZER                  OC1RS
#define BUZZER_ON		0x80
#define BUZZER_OFF		0x00
#define NORMAL			0
#define INVERSE			1
#define MAX_I_ALARM             1000
#define PORT_IN                 1
#define PORT_OUT                0

//eeprom data
#define U1_DISP_MODE            0
#define MODE_LCD                0
#define MODE_RAW                1

#define UART_SETUP_EEP_ADDR     0
#define INA219_CALC_EEP_ADDR    1
#define INA219_RST_CALC_EEP_ADDR    2


#define UART_UPDATE_RATE_MS    (1000/8) //uart update rate in [ms]


// ################ VARIABLES ##################

static volatile uint16_t Ialarm_adc;        //pot value read in ADC ISR
static volatile uint16_t delay8ms;          //8ms utility delay
static volatile uint16_t beeper;

//measured parameteres:
static volatile float current_mA;
float bus_voltage_V;
float power_mW;
float ref_current_mA = 0.0;                 //reference current used in calibration

uint16_t Ialarm;                            //scaled value + ~log response

//text buffers
char I_txt[9],
     V_txt[9],
     P_txt[9],
     Ial_txt[9],
     cmd_buffer[9];
static volatile uint8_t cmdbuf_index = 0;

//errors used while debugging
typedef enum {
    NO_ERROR,
    UART_RX_OVERRUN,
    UART_PARITY_ERROR,
    UART_FRAMING_ERROR,
    I2C_MASTER_BUS_COLLISION,
    I2C_WRITE_COLLISION,
    I2C_OVERFLOW
}errors;

//INA219 recalibration modes
typedef enum{
    CL_OFF,
    CL_RST,
    RCL_ON,
    CL_RST_CONFIRM,
    RCL_CONFIRM
}cal_modes;



static volatile struct
{
	unsigned alarm:		1;  //alarm flag
        unsigned alarm_sdown:   1;  //alarm on/off
	unsigned pwr_rev: 	1;  //power jacks reversed warning
        cal_modes cal_mode:     3;  //ina219 calibration mode
        uint8_t   error;        
} status;

typedef enum{
    OFF,
    LCD,
    RAW
}uart_data_format;

static volatile struct
{
    uint16_t update_clock;          //uart update counter
    uint16_t counter;               //uart update counter
    uint16_t setup_eep;
    uart_data_format format;        //format: raw od ldc type
    unsigned updater:        1;     //uart update on/off flag
}uart1;

extern uint16_t ina219_calValue;    //used in calibration mode
uint16_t ina219_calValue_new;

#endif	/* GLOBALVAR_H */

