/*
 *  float and int to ASCII conversion & formatting
 */
#include <xc.h>
#include <string.h>
#include "stdint.h"
#include "converter.h"

// ### flotat to ascii converter + formatting ###
void f_to_txt(float f_num, char *buf_ptr)
{
    int16_t ix,dp,int_num;
    uint8_t neg = 0;
    uint8_t len;

    if (f_num<0)
    {
        neg = 1;
        f_num = -f_num;
    }
    else
    {
        *buf_ptr++ = ' ';
    }

    f_num += 0.005;         //numbers are rounded to .xx

    int_num = f_num;
    dp=0;
    while (f_num>=10.0)
    {
        f_num=f_num/10.0;
        dp++;
    }
    ix = 3-dp;
    while (ix--)
    {
        *buf_ptr++ = ' ';
    }
    if (neg) *buf_ptr++ = '-'; // add - of negative

    len = dp+4;

    for (ix=1;ix<len;ix++)
    {
        int_num = f_num;
        f_num=f_num-int_num;
        if (int_num>9)	*buf_ptr++='#';
            else      	*buf_ptr++='0'+int_num;
        if (dp==0) 	*buf_ptr++='.';
        f_num=f_num*10.0;
        dp--;
    }
    *buf_ptr++ = '\0';
}
// ### integer to ascii ###
void int_to_txt(int i_num, uint8_t len, char *buf_ptr)
{

    int sign;
    char *ptr;
    uint8_t ix;
    uint8_t digit = 0;

    digit = len-1;
    //add .00 to match the float converter format
     ptr = buf_ptr;
    *ptr++ = '0';
    *ptr++ = '0';
    *ptr++ = '.';
    if ((sign = i_num) < 0)                         // record sign
            i_num = -i_num;                 	    // make n positive
    do 	{
            *ptr++ = i_num % 10 + '0';
            i_num /= 10;
        }  while (digit--);

    if (sign < 0)           *ptr++ = '-';
    else                    *ptr++ = ' ';
    *ptr = '\0';
    reverse(buf_ptr);

    //remove the leading zeroes
    ptr = buf_ptr+1;
    ix = 1;
    while ((*ptr==(16+32)) && (*(ptr+1)!='.'))
    {
        *ptr++ = 32;
    }
}
// ### reverse string ###
void reverse(char *s)
{
   char *j;
   int c;
   j = s + strlen(s) - 1;
   while (s < j)
   {
       c = *s;
       *s++ = *j;
       *j-- = c;
   }
}

