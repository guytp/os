#ifndef REQUEST_LINE_HEADER
#define REQUEST_LINE_HEADER
#include "interrupt.h"

void interrupt_request_line_setup();
void interrupt_request_line_handler(registers_t *r);
void interrupt_request_line_handler_register(byte n, isr_t handler);

#endif