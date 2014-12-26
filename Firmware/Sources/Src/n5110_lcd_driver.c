/*
        NOKIA 5110 LCD SPI driver

 */
#include <xc.h>
#include <libpic30.h>
#include <stdlib.h>
#include "stdint.h"
#include "n5110_lcd_driver.h"
#include "font6x8.h"


void LCD5110_init(uint8_t contrast)
{
    //Port configuration
//    !CS =       RB15
//    LDCRST =    RA3
//    LCD D/C =   RA2
//    MOSI =      RB13
//    SCK =       RB12
//    MISO =      RB14

    TRISBbits.TRISB15 = PORT_OUT;       //!CS
    TRISAbits.TRISA3 = PORT_OUT;        //LCDRST
    TRISAbits.TRISA2 = PORT_OUT;        //LCD D/C
    TRISBbits.TRISB13 = PORT_OUT;       //MOSI
    TRISBbits.TRISB12 = PORT_OUT;       //SCK
    TRISBbits.TRISB14 = PORT_IN;        // MISO

    if (contrast>0x7F)      contrast=0x7F;
    uint16_t i = 1500;
    LCD_RST = 0;
    while (i--);
    LCD_RST = 1;

    LCD5110_write_byte(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION, LCD_CMD);
    LCD5110_write_byte(PCD8544_SETVOP | contrast, LCD_CMD);
    LCD5110_write_byte(PCD8544_SETTEMP | LCD_TEMP, LCD_CMD);
    LCD5110_write_byte(PCD8544_SETBIAS | LCD_BIAS, LCD_CMD);
    LCD5110_write_byte(PCD8544_FUNCTIONSET, LCD_CMD);
    LCD5110_clear();
    LCD5110_write_byte(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL, LCD_CMD);
  }

void LCD5110_write_byte(uint8_t dat, uint8_t dat_type)
  {
    uint8_t dummy;

    SPI_CS = 0;

    if (dat_type == LCD_CMD) LCD_DC = LCD_CMD;
    else                     LCD_DC = LCD_DATA;

    SPI1BUF = dat;					//send byte
    while(SPI1STATbits.SPITBF);                         //wait until transmitted
    while(!SPI1STATbits.SPIRBF);                         //wait for receive Buffer
    dummy = SPI1BUF;

    SPI_CS = 1;
  }

void LCD5110_draw_bmp_pixel(uint8_t X,uint8_t Y,uint8_t *map,
                  uint8_t Pix_x,uint8_t Pix_y)
  {
    uint16_t i,n;
    uint8_t row;

    if (Pix_y%8==0) row=Pix_y/8;
      else
        row=Pix_y/8+1;

    for (n=0;n<row;n++)
      {
      	LCD5110_set_XY(X,Y);
        for(i=0; i<Pix_x; i++)
          {
            LCD5110_write_byte(map[i+n*Pix_x], 1);
          }
        Y++;
      }
  }

void LCD5110_write_string(uint8_t X,uint8_t Y,const char *s, uint8_t mode)
  {
    LCD5110_set_XY(X,Y);
      while (*s)
      {
	 LCD5110_write_char6x8(*s, mode);
	 s++;
      }    


  }


void LCD5110_write_char6x8(char c, uint8_t mode)
{
    uint8_t line;
    uint8_t ch, i;

    i = c - 32;
    for (line=0; line<6; line++)
    {
      ch = font6x8[i][line];
      LCD5110_write_byte( (mode==DISP_NORMAL)? ch: (ch^ 0xff) , LCD_DATA);
    }
}

  void LCD5110_set_XY(uint8_t X, uint8_t Y)
  {
    LCD5110_write_byte(0x40 | Y, LCD_CMD);		// column
    LCD5110_write_byte(0x80 | X, LCD_CMD);          	// row
  }

void LCD5110_clear(void)
  {
    uint16_t i;

    LCD5110_write_byte(PCD8544_SETYADDR, LCD_CMD);
    LCD5110_write_byte(PCD8544_SETXADDR, LCD_CMD);

    for (i=0; i<504; i++)
      LCD5110_write_byte(0, LCD_DATA);
  }
void LCD5110_invert(uint8_t mode)
{

    if (mode)
         LCD5110_write_byte(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYINVERTED, LCD_CMD);
    else
         LCD5110_write_byte(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL, LCD_CMD);

}

