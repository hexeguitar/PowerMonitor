/* 
 * File:   eeprom.h
 * Author:  Piotr Zapart
 *          www.hexeguitar.com
 * Created on 8. Juli 2014, 17:49
 */

#ifndef EEP_H
#define	EEP_H

uint16_t eeRead(uint16_t addr);
void eeWrite(uint16_t addr, uint16_t data);
#endif	/* EEPROM_H */

