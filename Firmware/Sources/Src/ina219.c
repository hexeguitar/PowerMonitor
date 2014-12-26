/*
 * ina219.c
 *
 *  Created on: 10.04.2014
 *      Author: Piotr Zapart
 *      based on Adafruit INA219 library
 */
#include <xc.h>
#include <stdlib.h>
#include <math.h>
#include "stdint.h"
#include "i2c.h"
#include "ina219.h"

uint8_t inaAddress;
uint16_t ina219_calValue;
// The following multipliers are used to convert raw current and power
// values to mA and mW, taking into account the current config settings
float ina219_currentDivider_mA;
float ina219_powerDivider_mW;

uint16_t INA219_configure(uint8_t range, uint8_t gain, uint8_t busRes, uint8_t shuntRes, uint8_t mode)
{
    uint16_t config = 0;

    config |= (range << 13) + (gain << 11) + (busRes << 7) + (shuntRes << 3) + mode;
    INA219_writeRegister16(INA219_REG_CONFIG, config);
    return config;
}

void INA219_calibrate(uint16_t cal)
{
  // ###  ported from Adafruit INA219 Arduino löibrary ### 


// By default we use a pretty huge range for the input voltage,
  // which probably isn't the most appropriate choice for system
  // that don't use a lot of power.  But all of the calculations
  // are shown below if you want to change the settings.  You will
  // also need to change any relevant register settings, such as
  // setting the VBUS_MAX to 16V instead of 32V, etc.

  // VBUS_MAX = 32V		(Assumes 32V, can also be set to 16V)
  // VSHUNT_MAX = 0.32	(Assumes Gain 8, 320mV, can also be 0.16, 0.08, 0.04)
  // RSHUNT = 0.1			(Resistor value in ohms)

  // 1. Determine max possible current
  // MaxPossible_I = VSHUNT_MAX / RSHUNT
  // MaxPossible_I = 3.2A

  // 2. Determine max expected current
  // MaxExpected_I = 1.0A

  // 3. Calculate possible range of LSBs (Min = 15-bit, Max = 12-bit)
  // MinimumLSB = MaxExpected_I/32767
  // MinimumLSB = 0.0000305             (30.5uA per bit)
  // MaximumLSB = MaxExpected_I/4096
  // MaximumLSB = 0.000244              (244uA per bit)

  // 4. Choose an LSB between the min and max values
  //    (Preferrably a roundish number close to MinLSB)
  // CurrentLSB = 0.0000500 (50uA per bit)

  // 5. Compute the calibration register
  // Cal = trunc (0.04096 / (Current_LSB * RSHUNT))
  // Cal = 10240 (0x2800)

  //ina219_calValue = 8192;

  //second calibration step:
//    measure the current with a good quality multimeter :
//    Ims = ...
//    Current measured with INA219 :
//    Iina219 = ...
//
//    Corrected_calcValue = trunc(INA219_calValue * Ims / Iina219)
//    example : Ims = 19.183mA Iina219 = 19.79mA
//
//    Corrected_calValue = trunc(8192 * 19.183 / 19.79) = 7940

    //ina219_calValue = 7855;

    // calibration constant is stored in EEPROM

    ina219_calValue = cal;

  // 6. Calculate the power LSB
  // PowerLSB = 20 * CurrentLSB
  // PowerLSB = 0.001 (1mW per bit)

  // 7. Compute the maximum current and shunt voltage values before overflow
  //
  // Max_Current = Current_LSB * 32767
  // Max_Current = 1.63855A before overflow
  //
  // If Max_Current > Max_Possible_I then
  //    Max_Current_Before_Overflow = MaxPossible_I
  // Else
  //    Max_Current_Before_Overflow = Max_Current
  // End If
  //
  // ... In this case, we're good though since Max_Current is less than MaxPossible_I
  //
  // Max_ShuntVoltage = Max_Current_Before_Overflow * RSHUNT
  // Max_ShuntVoltage = 0.163835V
  //
  // If Max_ShuntVoltage >= VSHUNT_MAX
  //    Max_ShuntVoltage_Before_Overflow = VSHUNT_MAX
  // Else
  //    Max_ShuntVoltage_Before_Overflow = Max_ShuntVoltage
  // End If

  // 8. Compute the Maximum Power
  // MaximumPower = Max_Current_Before_Overflow * VBUS_MAX
  // MaximumPower = 1.63835 * 32V
  // MaximumPower = 52.4272W

  // Set multipliers to convert raw current/power values
  ina219_currentDivider_mA = 20.0;      // Current LSB = 50uA per bit (1000/50 = 20)
  ina219_powerDivider_mW = 1.0;         // Power LSB = 1mW per bit

  // Set Calibration register to 'Cal' calculated above	
  INA219_writeRegister16(INA219_REG_CALIBRATION, ina219_calValue);
	
}

/**************************************************************************/
/*! 
    @brief  Gets the raw bus voltage (16-bit signed integer, so +-32767)
*/
/**************************************************************************/
int16_t INA219_getBusVoltage_raw(void) {
  uint16_t value;
  value = INA219_readRegister16(INA219_REG_BUSVOLTAGE);

  // Shift to the right 3 to drop CNVR and OVF and multiply by LSB
  return (int16_t)((value >> 3) * 4);
}

/**************************************************************************/
/*! 
    @brief  Gets the raw shunt voltage (16-bit signed integer, so +-32767)
*/
/**************************************************************************/
int16_t INA219_getShuntVoltage_raw(void) {
  uint16_t value;
  value = INA219_readRegister16(INA219_REG_SHUNTVOLTAGE);
  return (int16_t)value;
}

/**************************************************************************/
/*! 
    @brief  Gets the raw current value (16-bit signed integer, so +-32767)
*/
/**************************************************************************/
int16_t INA219_getCurrent_raw(void) {
  uint16_t value;

  // Sometimes a sharp load will reset the INA219, which will
  // reset the cal register, meaning CURRENT and POWER will
  // not be available ... avoid this by always setting a cal
  // value even if it's an unfortunate extra step
  INA219_writeRegister16(INA219_REG_CALIBRATION, ina219_calValue);

  // Now we can safely read the CURRENT register!
  value = INA219_readRegister16(INA219_REG_CURRENT);
  
  return (int16_t)value;
}

int16_t INA219_getPower_raw(void)
{
	uint16_t value;
  // Sometimes a sharp load will reset the INA219, which will
  // reset the cal register, meaning CURRENT and POWER will
  // not be available ... avoid this by always setting a cal
  // value even if it's an unfortunate extra step
  INA219_writeRegister16(INA219_REG_CALIBRATION, ina219_calValue);
  value = INA219_readRegister16(INA219_REG_POWER);

  return (int16_t) value;

} 

float INA219_getPower_mW(void)
{
	int16_t value;
	value = INA219_getPower_raw();
	return (float)(value/ina219_powerDivider_mW);		//LSB =1mW
}



/**************************************************************************/
/*! 
    @brief  Gets the shunt voltage in mV (so +-327mV)
*/
/**************************************************************************/
float INA219_getShuntVoltage_mV(void) {
  int16_t value;
  value = INA219_getShuntVoltage_raw();
  return value * 0.01;
}

/**************************************************************************/
/*! 
    @brief  Gets the shunt voltage in volts
*/
/**************************************************************************/
float INA219_getBusVoltage_V(void) {
  int16_t value = INA219_getBusVoltage_raw();
  return value * 0.001;
}

/**************************************************************************/
/*! 
    @brief  Gets the current value in mA, taking into account the
            config settings and current LSB
*/
/**************************************************************************/
float INA219_getCurrent_mA(void) {
  float valueDec = INA219_getCurrent_raw();
  valueDec /= ina219_currentDivider_mA;
  return valueDec;
}

int16_t INA219_readRegister16(uint8_t reg)
{
    int16_t value;
	uint8_t low_byte, hi_byte;

	IdleI2C();						//Ensure Module is Idle
	StartI2C();						//Generate Start COndition
	WriteI2C(INA219_ADDRESS);			//Write Address/Control byte
	IdleI2C();	
	WriteI2C(reg);
	IdleI2C();
	StopI2C();						//Initiate Stop Condition

	IdleI2C();						//Ensure Module is Idle
	StartI2C();						//Generate Start COndition
	WriteI2C(INA219_ADDRESS | INA219_CMD_READ);	//Write control byte for read
	IdleI2C();					//wait for bus Idle
	
	hi_byte = getI2C();
	AckI2C();
	low_byte = getI2C();
	NotAckI2C();				//Send Not Ack
	StopI2C();					//Generate Stop

    value = (hi_byte << 8) + low_byte;

    return value;
}

void INA219_writeRegister16(uint8_t reg, uint16_t val)
{
    uint8_t low_byte, hi_byte;
    low_byte = val&0x00FF;
    hi_byte = val>>8;

	IdleI2C();						//Ensure Module is Idle
	StartI2C();						//Generate Start COndition
	WriteI2C(INA219_ADDRESS);			//Write Address/Control byte
	IdleI2C();	
	WriteI2C(reg);
	IdleI2C();							//Write High Address
	WriteI2C(hi_byte);				//Write Low Address
	IdleI2C();
	WriteI2C(low_byte);					//Write Data
	IdleI2C();
	StopI2C();							//Initiate Stop Condition

}
