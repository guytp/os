#ifndef INTERRUPT_HEADER
#define INTERRUPT_HEADER
#include "../types.h"

void interrupt_setup();

#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47

/* Struct which aggregates many registers.
 * It matches exactly the pushes on interrupt.asm. From the bottom:
 * - Pushed by the processor automatically
 * - `push byte`s on the isr-specific code: error code, then int number
 * - All the registers by pusha
 * - `push eax` whose lower 16-bits contain DS
 */
typedef struct {
   uint ds; /* Data segment selector */
   uint edi, esi, ebp, useless, ebx, edx, ecx, eax; /* Pushed by pusha. */
   uint int_no, err_code; /* Interrupt number and error code (if applicable) */
   uint eip, cs, eflags, esp, ss; /* Pushed by the processor automatically */
} registers_t;

typedef void (*isr_t)(registers_t*);

#endif