#ifndef I2C_H_
#define I2C_H_

#define PAGESIZE 4
#define FCY     4000000l        //FOSC/2 = 8/2 = 4MHz
#define FSCL    100000l


//Low Level Functions
unsigned int IdleI2C(void);
unsigned int StartI2C(void);
unsigned int WriteI2C(unsigned char);
unsigned int StopI2C(void);
unsigned int RestartI2C(void);
unsigned int getsI2C(unsigned char*, unsigned char);
unsigned int NotAckI2C(void);
unsigned int InitI2C(void);
unsigned int ACKStatus(void);
unsigned int getI2C(void);
unsigned int AckI2C(void);
unsigned int EEAckPolling(unsigned char);
unsigned int putstringI2C(unsigned char*);

//High Level Functions for Low Density Devices
unsigned int LDByteReadI2C(unsigned char, unsigned char, unsigned char*, unsigned char);
unsigned int LDByteWriteI2C(unsigned char, unsigned char, unsigned char);
unsigned int LDPageWriteI2C(unsigned char, unsigned char, unsigned char*);
unsigned int LDSequentialReadI2C(unsigned char, unsigned char, unsigned char*, unsigned char);

//High Level Functions for High Density Devices
unsigned int HDByteReadI2C(unsigned char, unsigned char, unsigned char, unsigned char*, unsigned char);
unsigned int HDByteWriteI2C(unsigned char, unsigned char, unsigned char, unsigned char);
unsigned int HDPageWriteI2C(unsigned char, unsigned char, unsigned char, unsigned char*);
unsigned int HDSequentialReadI2C(unsigned char, unsigned char, unsigned char, unsigned char*, unsigned char);

#endif
