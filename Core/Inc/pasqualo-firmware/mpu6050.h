#ifndef MPU6050
#define MPU6050

#include <stdint.h>
#include "i2c.h"

/* DEFINES */
#define IMU_ADDR (0x68 << 1)
#define IMU_REG_PWR_MGMT_1 0x6B

#define IMU_REG_ACCEL_XOUT_H 0x3B

struct IMU_sample
{   
    int16_t ax, ay, az, gx, gy, gz;
    // TODO: add timestamp field
};

/**
 * discovers IMU sensor over I2C bus
*/
HAL_StatusTypeDef IMU_connect();


/**
 * creates a IMU_samples                                                                                                                                                                                                                                                                                                                                                                                                                                                
 */
HAL_StatusTypeDef IMU_read(struct IMU_sample* imu);


int16_t to_lacc(int16_t raw);
int16_t to_gacc(int16_t raw);

#endif /* MPU */
