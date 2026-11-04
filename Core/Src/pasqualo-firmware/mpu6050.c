#include "mpu6050.h"

int16_t to_lacc(int16_t raw){
    return (raw * 2) / INT16_MAX;
}

int16_t to_gacc(int16_t raw){
    return (raw * 250) / INT16_MAX;
}

/**
 * discovers IMU sensor over I2C bus
*/
HAL_StatusTypeDef IMU_connect(){
    if (HAL_I2C_IsDeviceReady(&hi2c2, IMU_ADDR, 3, 100) != HAL_OK){return HAL_ERROR;}
    uint8_t wake_up_value = 0x00;
    if(HAL_I2C_Mem_Write(
        &hi2c2,
        IMU_ADDR,
        IMU_REG_PWR_MGMT_1,
        I2C_MEMADD_SIZE_8BIT,
        &wake_up_value,
        1, // how many bytes are you writing
        100 // Timeout
        ) != HAL_OK){return HAL_ERROR;}

    return HAL_OK;
}


HAL_StatusTypeDef IMU_read(struct IMU_sample* imu){
    
    uint8_t raw[14] = {0}; // 14 8-bit registers = 7 16-bit values
    if (HAL_I2C_Mem_Read(
        &hi2c2,
        IMU_ADDR,
        IMU_REG_ACCEL_XOUT_H,
        I2C_MEMADD_SIZE_8BIT,
        &raw[0],
        14,
        100
    ) != HAL_OK) {return HAL_ERROR;}

    imu->ax = to_lacc((int16_t) (raw[0] << 8 | raw[1]));
    imu->ay = to_lacc((int16_t) (raw[2] << 8 | raw[3]));
    imu->az = to_lacc((int16_t) (raw[4] << 8 | raw[5]));
    imu->gx = to_gacc((int16_t) (raw[8] << 8 | raw[9]));
    imu->gy = to_gacc((int16_t) (raw[10] << 8 | raw[11]));
    imu->gz = to_gacc((int16_t) (raw[12] << 8 | raw[13]));



    return HAL_OK;
}