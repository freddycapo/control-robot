#include "serial_print.h"

#include "usbd_cdc_if.h"

// Overrides the weak _write in syscalls.c so printf() goes out over USB CDC.
int _write(int fd, char *ptr, int len){
    (void) fd;
    for(int i = 0; i<10; ++i){
        if (CDC_Transmit_FS( (uint8_t*) ptr , (uint16_t) len) != USBD_BUSY) return len;
        HAL_Delay(1);
    }
    return 0;
}
