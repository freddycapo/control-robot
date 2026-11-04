#ifndef MPU
#define MPU

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
void IMU_connect();


/**
 * creates a IMU_samples                                                                                                                                                                                                                                                                                                                                                                                                                                                
 */
struct IMU_sample IMU_read();



#endif /* MPU */
