/*
 * heltec_oled_driver.h
 *
 *  Created on: 30.03.2014
 *      Author: Pio
 */

#ifndef HELTEC_OLED_DRIVER_H_
#define HELTEC_OLED_DRIVER_H_

/*
semi I2C Master driver. The Heltec display controller does not
ACK the received byte. Pins set to push-pull output,
pull up resistors not needed.

RB4 = OLED_SCA
RA4 = OLED_SCL
*/


#define OLED_SCL        LATAbits.LATA4
#define OLED_SDA        LATBbits.LATB4
#define OLED_I2C_DLY    4
static inline void OLED_SCL_HI(void)
{
	OLED_SCL = 1;
}
static inline void OLED_SCL_LO(void)
{
	OLED_SCL = 0;
}
static inline void OLED_SDA_HI(void)
{
	OLED_SDA = 1;
}
static inline void OLED_SDA_LO(void)
{
	OLED_SDA = 0;
}

void OLED_start(void);
void OLED_stop(void);
void OLED_write_byte(uint8_t oled_Byte);
void OLED_write_command(uint8_t oled_Command);
void OLED_begin_data(void);
void OLED_setpos(uint8_t x, uint8_t y);
void OLED_fill_screen(uint8_t fill_Data);
void OLED_char_F8x16(uint8_t x, uint8_t y,const char ch[],uint8_t inv);
void OLED_draw_BMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1,const uint8_t BMP[]);
void OLED_init(void);

void wait_nop(uint8_t count);

#endif /* HELTEC_OLED_DRIVER_H_ */
