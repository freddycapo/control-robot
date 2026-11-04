#include "mpu6050.h"

/**
 * discovers IMU sensor over I2C bus
*/
HAL_StatusTypeDef IMU_connect(){

}


struct IMU_sample IMU_read(){
    struct IMU_sample imu_sample;
    imu_sample.ax = 1;
    imu_sample.ay = 1;
    imu_sample.az = 1;
    imu_sample.gx = 1;
    imu_sample.gy = 1;
    imu_sample.gz = 1;

    return imu_sample;
}