/*
**
**                           Platform.h
**
**
**********************************************************************/
/*
 *             Author: Piotr Zapart
 *                     www.hexeguitar.com
 * 
**********************************************************************/

#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <xc.h>
#include <uart.h>
#include <libpic30.h>
#include "stdint.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "uart1.h"
#include "ina219.h"
#include "heltec_oled_driver.h"
#include "n5110_lcd_driver.h"
#include "bmp.h"
#include "txt.h"
#include "eeprom.h"
#include "converter.h"
#include "globalvar.h"

uint16_t calc_Ialarm(uint16_t input, uint16_t max);

void hardware_init (void);
void startup(void);
void wait8ms(unsigned int cnt);
void display_data(cal_modes cal_mode);
void display_warning(void);

void update_uart(uart_data_format mode);
void uart_warning(void);
uint8_t decode_char(uint16_t err_data);
void flush_cmd_buff(void);

uint16_t calc_new_cal(float ref_current,float m_current, uint16_t old_cal);

uart_data_format get_udata_format(void);

#endif

