#ifndef __I2C_H__
#define __I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
 *               F U N C T I O N    D E C L A R A T I O N S               *
 **************************************************************************/
void i2c_init(void);
unsigned int i2c_read8(int addr);
void i2c_write8(int addr, unsigned int value);

#ifdef __cplusplus
}
#endif

#endif
