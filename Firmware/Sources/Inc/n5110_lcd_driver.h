/* 
 * File:   n5110_lcd_driver.h
 * Author: Pio
 *
 * Created on 5. Juli 2014, 19:46
 */

#ifndef N5110_LCD_DRIVER_H
#define	N5110_LCD_DRIVER_H

#define LCD_DATA        1
#define LCD_CMD         0

#define DISP_NORMAL          0b00
#define DISP_INVERSE         0b01


#define LCD_RST     LATAbits.LATA3
#define SPI_CS      LATBbits.LATB15
#define SPI_MOSI    LATBbits.LATB13
#define SPI_SCK     LATBbits.LATB12
#define LCD_DC      LATAbits.LATA2
#define PORT_IN                 1
#define PORT_OUT                0



#define BLACK 1
#define WHITE 0

#define LCDWIDTH                    84
#define LCDHEIGHT                   48

#define PCD8544_POWERDOWN           0x04
#define PCD8544_ENTRYMODE           0x02
#define PCD8544_EXTENDEDINSTRUCTION 0x01

#define PCD8544_DISPLAYBLANK        0x00
#define PCD8544_DISPLAYNORMAL       0x4
#define PCD8544_DISPLAYALLON        0x1
#define PCD8544_DISPLAYINVERTED     0x5

// H = 0
#define PCD8544_FUNCTIONSET         0x20
#define PCD8544_DISPLAYCONTROL      0x08
#define PCD8544_SETYADDR            0x40
#define PCD8544_SETXADDR            0x80

// H = 1
#define PCD8544_SETTEMP             0x04
#define PCD8544_SETBIAS             0x10
#define PCD8544_SETVOP              0x80

// Display presets
#define LCD_BIAS                    0x03	// Range: 0-7 (0x00-0x07)
#define LCD_TEMP                    0x02	// Range: 0-3 (0x00-0x03)
#define LCD_CONTRAST                0x46	// Range: 0-127 (0x00-0x7F)





void LCD5110_init(uint8_t contrast);
void LCD5110_write_byte(uint8_t dat, uint8_t dat_type);
void LCD5110_draw_bmp_pixel(uint8_t X,uint8_t Y,uint8_t *map,
                  uint8_t Pix_x,uint8_t Pix_y);
void LCD5110_write_string(uint8_t X,uint8_t Y,const char *s, uint8_t mode);
void LCD5110_write_char6x8(char c, uint8_t mode);
void LCD5110_write_char5x8(char c, uint8_t mode);
void LCD5110_set_XY(uint8_t X, uint8_t Y);
void LCD5110_clear(void);

//extern void wait8ms(unsigned int cnt);

#endif	/* N5110_LCD_DRIVER_H */

