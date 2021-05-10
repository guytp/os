#include "request-line.h"

isr_t interrupt_handlers[256];

void interrupt_request_line_setup() {
    asm volatile("sti");
}

void interrupt_request_line_handler(registers_t *r) {
    /* After every interrupt we need to send an EOI to the PICs
     * or they will not send another interrupt again */
    if (r->int_no >= 40) io_out_byte(0xA0, 0x20); /* slave */
    io_out_byte(0x20, 0x20); /* master */

    /* Handle the interrupt in a more modular way */
    if (interrupt_handlers[r->int_no] != 0) {
        isr_t handler = interrupt_handlers[r->int_no];
        handler(r);
    }
}

void interrupt_request_line_handler_register(byte n, isr_t handler) {
    interrupt_handlers[n] = handler;
}