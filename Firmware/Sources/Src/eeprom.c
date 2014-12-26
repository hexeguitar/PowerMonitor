/*
 *  ### EEPROM HANDLING FUNCTIONS ###
 */

#include <xc.h>
#include "stdint.h"
#include <libpic30.h>
#include "eeprom.h"

uint16_t __attribute__ ((space(eedata))) eep_data0 = 0x0000;    //uart update format
uint16_t __attribute__ ((space(eedata))) eep_data1 = 7695;      //corrected cal vaalue
uint16_t __attribute__ ((space(eedata))) eep_data2 = 8192;      //factory ina219 cal value
uint16_t __attribute__ ((space(eedata))) eep_data3 = 0x0000;

uint16_t eeRead(uint16_t addr)
{
   uint16_t offset=0;
   uint16_t data;
   while(NVMCONbits.WR);                                        // wait for any last write to complete
   switch(addr)
    {
     case 0:
                TBLPAG = __builtin_tblpage(&eep_data0);
                offset = __builtin_tbloffset(&eep_data0);
                break;
     case 1:    TBLPAG = __builtin_tblpage(&eep_data1);
                offset = __builtin_tbloffset(&eep_data1);
                break;
     case 2:    TBLPAG = __builtin_tblpage(&eep_data2);
                offset = __builtin_tbloffset(&eep_data2);
                break;
     case 3:    TBLPAG = __builtin_tblpage(&eep_data3);
                offset = __builtin_tbloffset(&eep_data3);
                break;
    }
   data = __builtin_tblrdl(offset);
 return data;
}

void eeWrite(uint16_t addr, uint16_t data)
{
 uint16_t offset=0;
 while(NVMCONbits.WR);      // wait for last write to complete
 NVMCON = 0x4058;        // Set up NVMCON to erase+write one word of data EEPROM
 switch(addr)
 {
     case 0:
                TBLPAG = __builtin_tblpage(&eep_data0);
                offset = __builtin_tbloffset(&eep_data0);
                break;
     case 1:    TBLPAG = __builtin_tblpage(&eep_data1);
                offset = __builtin_tbloffset(&eep_data1);
                break;
     case 2:    TBLPAG = __builtin_tblpage(&eep_data2);
                offset = __builtin_tbloffset(&eep_data2);
                break;
     case 3:    TBLPAG = __builtin_tblpage(&eep_data3);
                offset = __builtin_tbloffset(&eep_data3);
                break;
 }

 __builtin_tblwtl(offset, 0);
 asm volatile ("disi #5");
 __builtin_write_NVM();       // Issue Unlock Sequence & Start Write Cycle

 while(NVMCONbits.WR);      // wait for erase to complete
 NVMCON = 0x4004;        // Set up NVMCON to write one word of data EEPROM
 __builtin_tblwtl(offset, data);   // Write EEPROM data to write latch
 asm volatile ("disi #5");
 __builtin_write_NVM();
  while(NVMCONbits.WR);      // wait for erase to complete

}
