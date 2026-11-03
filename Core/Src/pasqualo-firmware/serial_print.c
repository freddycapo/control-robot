#include "serial_print.h"

#include <string.h>
#include "usbd_cdc_if.h"

void serialPrint(const char* str){
    uint16_t len = strlen(str);
    for(int i = 0; i<10; ++i){
        if (CDC_Transmit_FS( (uint8_t*) str , len) != USBD_BUSY) return;
        HAL_Delay(1);
    }
}