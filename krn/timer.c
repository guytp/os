#include "timer.h"
#include "interrupt/request-line.h"
#include "drivers/io.h"
#include "common.h"
#include "drivers/screen.h"
ulong tick = 0;

static void timer_callback(registers_t *regs) {
    tick++;
    UNUSED(regs);
}

void timer_setup() {
    uint divisor = 1193180 / 100;       // Calculate our divisor -> Once every 100Hz (10ms)
    io_out_byte(0x43, 0x36);             // Set our command byte 0x36 
    io_out_byte(0x40, divisor & 0xFF);   // Set low byte of divisor 
    io_out_byte(0x40, divisor >> 8);     // Set high byte of divisor
    interrupt_request_line_handler_register(IRQ0, timer_callback);
}

ulong timer_get() {
    return tick;
}