#define F_CPU 4000000UL

#include <avr/io.h>

#include "i2c.h"

#include <util/delay.h>

#define READ_BYTE 0x01
#define BMI_ADDRESS 0x68

#define BMI160_REG_CHIP_ID 0x00
#define BMI160_REG_INT_MOTION_3 0x62
#define BMI160_REG_INT_MOTION_1 0x60
#define BMI160_REG_INT_MOTION_0 0x5F
#define BMI160_REG_INT_OUT_CTRL 0x53
#define BMI160_REG_INT_MAP_0 0x55
#define BMI160_REG_INT_EN_0 0x50
#define BMI160_REG_CMD 0x7E
#define BMI160_REG_INT_LATCH 0x54

void i2c_write(int device_address, uint8_t * reg_and_data, uint8_t size) {
  I2C_0_SendData((device_address << 1), reg_and_data, size);
  I2C_0_EndSession();

}

void i2c_read(int device_address, uint8_t * reciev_data, uint8_t size, uint8_t reg_read) {
  i2c_write(device_address, & reg_read, 1);
  I2C_0_GetData((device_address << 1) + 1, reciev_data, size);
  I2C_0_EndSession();

}

void BMI_160_INIT(void) {
  uint8_t REGISTER_AND_DATA[2];
  I2C_0_Init();

  REGISTER_AND_DATA[0] = BMI160_REG_CMD;
  REGISTER_AND_DATA[1] = 0xB6; //soft reset for bmi160
  i2c_write(BMI_ADDRESS, REGISTER_AND_DATA, 2);
  _delay_ms(55); // wait for bmi160 to stabilize

  REGISTER_AND_DATA[0] = BMI160_REG_CMD;
  REGISTER_AND_DATA[1] = 0x12; //set the accelerometer to LPM mode
  i2c_write(BMI_ADDRESS, REGISTER_AND_DATA, 2);
  _delay_ms(5); // wait for bmi160 to stabilize

  REGISTER_AND_DATA[0] = 0x40;
  REGISTER_AND_DATA[1] = 0x88; //set ODR to 100Hz with no average (45uA) 
  i2c_write(BMI_ADDRESS, REGISTER_AND_DATA, 2);

  REGISTER_AND_DATA[0] = BMI160_REG_INT_OUT_CTRL;
  REGISTER_AND_DATA[1] = 0x0A; //set INT1 pin  as output, active-high, push-pull
  i2c_write(BMI_ADDRESS, REGISTER_AND_DATA, 2);

  REGISTER_AND_DATA[0] = BMI160_REG_INT_LATCH;
  REGISTER_AND_DATA[1] = 0x0B; //temporarily latch the interrupt for 160ms   
  i2c_write(BMI_ADDRESS, REGISTER_AND_DATA, 2);

  REGISTER_AND_DATA[0] = BMI160_REG_INT_MAP_0;
  REGISTER_AND_DATA[1] = 0x04; //route anymo_int to int_pin1
  i2c_write(BMI_ADDRESS, REGISTER_AND_DATA, 2);

  REGISTER_AND_DATA[0] = BMI160_REG_INT_MOTION_3;
  REGISTER_AND_DATA[1] = 0x24; //sig_mot_sel=0 => aanymo selected
  i2c_write(BMI_ADDRESS, REGISTER_AND_DATA, 2);

  REGISTER_AND_DATA[0] = BMI160_REG_INT_MOTION_1;
  REGISTER_AND_DATA[1] = 0x50; //anymo_th setat la 0x20
  i2c_write(BMI_ADDRESS, REGISTER_AND_DATA, 2);

  REGISTER_AND_DATA[0] = BMI160_REG_INT_MOTION_0;
  REGISTER_AND_DATA[1] = 0x01; //anymo_dur setat la 0b10 
  i2c_write(BMI_ADDRESS, REGISTER_AND_DATA, 2);

  REGISTER_AND_DATA[0] = BMI160_REG_INT_EN_0;
  REGISTER_AND_DATA[1] = 0x07; //enable la anymo_int pt axa x,z,y
  i2c_write(BMI_ADDRESS, REGISTER_AND_DATA, 2);

  I2C_0_EndSession();
}