#include "io.h"

void io_out_byte(ushort port, byte data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}