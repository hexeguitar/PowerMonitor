/*
 * heltec_oled_driver.c
 *
 *  Created on: 30.03.2014
 *      Author: Pio
 *
 * Based on the heltec OLED Arduino library
 */
#include <xc.h>
//#include <p24F16KA101.h>
#include <libpic30.h>
#include <stdlib.h>
#include <string.h>  
#include "stdint.h"
#include "heltec_oled_driver.h"
#include "fonts.h"


void OLED_start(void)
{
  OLED_SCL_HI();
  OLED_SDA_HI();
  wait_nop(OLED_I2C_DLY);
  OLED_SDA_LO();
  wait_nop(OLED_I2C_DLY);

  OLED_SCL_LO();
  wait_nop(OLED_I2C_DLY);
}

void OLED_stop(void)
{
  OLED_SDA_LO();
  wait_nop(OLED_I2C_DLY);
  OLED_SCL_HI();
  wait_nop(OLED_I2C_DLY);
  OLED_SDA_HI();
  wait_nop(OLED_I2C_DLY);
}

void OLED_write_byte(uint8_t oled_Byte)
{
  uint8_t i;
  for(i=0;i<8;i++)
  {
    if((oled_Byte << i) & 0x80)
    	{
            OLED_SDA_HI();
    	}
    else
    	{
            OLED_SDA_LO();
    	}
    wait_nop(OLED_I2C_DLY);
    OLED_SCL_HI();
    wait_nop(OLED_I2C_DLY);
    OLED_SCL_LO();
    wait_nop(OLED_I2C_DLY);
   }
   OLED_SDA_HI();
   wait_nop(OLED_I2C_DLY);
   OLED_SCL_HI();
   wait_nop(OLED_I2C_DLY);
   OLED_SCL_LO();
   wait_nop(OLED_I2C_DLY);
}

void OLED_write_command(uint8_t oled_Command)
{
   OLED_start();
   OLED_write_byte(0x78);         //Slave address,SA0=0
   OLED_write_byte(0x00);	  //write command
   OLED_write_byte(oled_Command);
   OLED_stop();
}

void OLED_begin_data(void)
{
   OLED_start();
   OLED_write_byte(0x78);
   OLED_write_byte(0x40);	//write data
}

//Set the starting point coordinates
void OLED_SetPos(uint8_t x, uint8_t y)
{
  OLED_start();
  OLED_write_byte(0x78);  //Slave address,SA0=0
  OLED_write_byte(0x00);	//write command

  OLED_write_byte(0xB0 + y);
  OLED_write_byte(((x & 0xF0)>>4)|0x10);
  OLED_write_byte((x & 0x0F)|0x01);

  OLED_stop();
}

void OLED_fill_screen(uint8_t fill_Data)
{
  uint8_t m,n;
  for(m=0;m<8;m++)
  {
    OLED_write_command(0xB0 + m);	//page0-page1
    OLED_write_command(0x00);		//low column start address
    OLED_write_command(0x10);		//high column start address
    OLED_begin_data();
    for(n=0;n<128;n++)
    {
      OLED_write_byte(fill_Data);
    }
    OLED_stop();
  }
}


//ASCII character display 8x8
/*
void Char_H8x8(uint8_t x, uint8_t y, const uint8_t ch[])
{
  uint8_t c,i,j=0;
  while(ch[j] != '\0')
  {
    c = ch[j] - 32;
    if(x>120)
    {
      x=0;
      y++;
    }
    oled_SetPos(x,y);
    OLED_begin_data();
    for(i=0;i<8;i++)
    {
    	OLED_write_byte(fontH8x8[c][i]);
	}
    oled_Stop();
    x += 8;
    j++;
  }
}

*/

/*
void Char_H6x8(uint8_t x, uint8_t y, const uint8_t ch[])
{
  uint8_t c,i,j=0;
  while(ch[j] != '\0')
  {
    c = ch[j];// - 32;
    if(x>126)
    	{
     	 	x=0;
      		y++;
    	}
    oled_SetPos(x,y);
    OLED_begin_data();
    for(i=0;i<6;i++)
    	{
	    OLED_write_byte(fontH6x8[c][i]);
    	}
    oled_Stop();
    x += 6;
    j++;
  }
}
*/

void OLED_char_F8x16(uint8_t x, uint8_t y,const char ch[],uint8_t inv)
{
	uint8_t c=0,i=0,j=0;
	uint8_t out_byte;
	while (ch[j]!='\0')
	{
		c =ch[j]-32;
		if(x>120)
			{
      			x=0;
      			y++;
    		}
		OLED_SetPos(x,y);
		OLED_begin_data();
		for(i=0;i<8;i++)
			{
			if (inv)	out_byte = (font8X16[(c<<4)+i])^0xFF;
	     		else		out_byte = font8X16[(c<<4)+i];
				OLED_write_byte(out_byte);
	   	 	}
	    OLED_stop();
		OLED_SetPos(x,y+1);
		OLED_begin_data();
		for(i=0;i<8;i++)
			{
			if (inv)	out_byte = (font8X16[(c<<4)+i+8])^0xFF;
	     		else		out_byte = font8X16[(c<<4)+i+8];
	    	 	OLED_write_byte(out_byte);
	    	}
	    OLED_stop();
		x+=8;
		j++;
	}
}

void OLED_draw_BMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1,const uint8_t BMP[])
{
  uint16_t j=0;
  uint8_t x,y;

  if((y1%8)==0)
  {
	  y = y1>>3; //y=y1/8;
  }

  else
  {
	  y = (y1>>3) + 1; //y=y1/8+1;
  }

  for(y=y0;y<y1;y++)
  {
    OLED_SetPos(x0,y);
    OLED_begin_data();
    for(x=x0;x<x1;x++)
    {
      OLED_write_byte(BMP[j++]);
    }
    OLED_stop();
  }
}


//SSD1306 initialization
void OLED_init(void)
{
    // config output pins
    TRISAbits.TRISA4 = 0;           //OLED software I2C SCL
    TRISBbits.TRISB4 = 0;           //OLED software I2C SDA

  OLED_write_command(0xAE);//display off
  OLED_write_command(0x00);//Set Memory Addressing Mode
  OLED_write_command(0x10);//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
  OLED_write_command(0x40);//Set Page Start Address for Page Addressing Mode,0-7
  OLED_write_command(0x81);//Set COM Output Scan Direction
  OLED_write_command(0xCF);//---set low column address
  OLED_write_command(0xA1);//---set high column address
  OLED_write_command(0xC8);//--set start line address
  OLED_write_command(0xA6);//--set contrast control register
  OLED_write_command(0xA8);
  OLED_write_command(0x3F);//--set segment re-map 0 to 127
  OLED_write_command(0xD3);//--set normal display
  OLED_write_command(0x00);//--set multiplex ratio(1 to 64)
  OLED_write_command(0xD5);//
  OLED_write_command(0x80);//0xa4,Output follows RAM content;0xa5,Output ignores RAM content
  OLED_write_command(0xD9);//-set display offset
  OLED_write_command(0xF1);//-not offset
  OLED_write_command(0xDA);//--set display clock divide ratio/oscillator frequency
  OLED_write_command(0x12);//--set divide ratio
  OLED_write_command(0xDB);//--set pre-charge period
  OLED_write_command(0x40);//
  OLED_write_command(0x20);//--set com pins hardware configuration
  OLED_write_command(0x02);
  OLED_write_command(0x8D);//--set vcomh
  OLED_write_command(0x14);//0x20,0.77xVcc
  OLED_write_command(0xA4);//--set DC-DC enable
  OLED_write_command(0xA6);//
  OLED_write_command(0xAF);//--turn on oled panel
}

void wait_nop (uint8_t count)
{
    while (count--)
    {
        asm("nop");
    }
}


