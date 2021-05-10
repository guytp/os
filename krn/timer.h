#ifndef TIMER_HEADER
#define TIMER_HEADER
#include "interrupt/interrupt.h"

void timer_setup();
ulong timer_get();
static void timer_callback(registers_t *regs);

#endif