/*
 * INA219.h
 *
 *  Created on: 10.04.2014
 *      Author:
 */

#ifndef INA219_H_
#define INA219_H_

#define TRUE 		1
#define FALSE 		0


#define INA219_ADDRESS              (0x80)

#define INA219_CMD_READ             (0x01)

#define INA219_REG_CONFIG           (0x00)
#define INA219_REG_SHUNTVOLTAGE     (0x01)
#define INA219_REG_BUSVOLTAGE       (0x02)
#define INA219_REG_POWER            (0x03)
#define INA219_REG_CURRENT          (0x04)
#define INA219_REG_CALIBRATION      (0x05)

#define INA219_RANGE_16V             0x00
#define INA219_RANGE_32V             0x01

#define INA219_GAIN_40MV             0x00
#define INA219_GAIN_80MV             0x01
#define INA219_GAIN_160MV            0x02
#define INA219_GAIN_320MV            0x03

#define INA219_BUS_RES_9BIT          0x00
#define INA219_BUS_RES_10BIT         0x01
#define INA219_BUS_RES_11BIT         0x02
#define INA219_BUS_RES_12BIT         0x03

#define INA219_SHUNT_RES_9BIT_1S     0x00
#define INA219_SHUNT_RES_10BIT_1S    0x01
#define INA219_SHUNT_RES_11BIT_1S    0x02
#define INA219_SHUNT_RES_12BIT_1S    0x03
#define INA219_SHUNT_RES_12BIT_2S    0x09
#define INA219_SHUNT_RES_12BIT_4S    0x0A
#define INA219_SHUNT_RES_12BIT_8S    0x0B
#define INA219_SHUNT_RES_12BIT_16S   0x0C
#define INA219_SHUNT_RES_12BIT_32S   0x0D
#define INA219_SHUNT_RES_12BIT_64S   0x0E
#define INA219_SHUNT_RES_12BIT_128S  0x0F

#define INA219_MODE_POWER_DOWN       0x00
#define INA219_MODE_SHUNT_TRIG       0x01
#define INA219_MODE_BUS_TRIG         0x02
#define INA219_MODE_SHUNT_BUS_TRIG   0x03
#define INA219_MODE_ADC_OFF          0x04
#define INA219_MODE_SHUNT_CONT       0x05
#define INA219_MODE_BUS_CONT         0x06
#define INA219_MODE_SHUNT_BUS_CONT   0x07


uint16_t INA219_configure(uint8_t range, uint8_t gain, uint8_t busRes, uint8_t shuntRes, uint8_t mode);

void INA219_calibrate(uint16_t cal);

int16_t INA219_getBusVoltage_raw(void);
int16_t INA219_getShuntVoltage_raw(void);
int16_t INA219_getCurrent_raw(void);
int16_t INA219_getPower_raw(void);

float INA219_getShuntVoltage_mV(void);
float INA219_getBusVoltage_V(void);
float INA219_getCurrent_mA(void);
float INA219_getPower_mW(void);


void INA219_writeRegister16(uint8_t reg, uint16_t val);
int16_t INA219_readRegister16(uint8_t reg);


#endif /* INA219_H_ */
