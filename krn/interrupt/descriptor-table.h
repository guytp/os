#ifndef DESCRIPTOR_TABLE_HEADER
#define DESCRIPTOR_TABLE_HEADER
#include "../types.h"

#define IDT_LENGTH 256
#define KERNEL_SEGMENT 0x08

// Definition of the IDT which is ultimately what is passed through to the CPU in assembly
typedef struct {
    ushort low_offset; /* Lower 16 bits of handler function address */
    ushort sel; /* Kernel segment selector */
    byte always0;
    /* First byte
     * Bit 7: "Interrupt is present"
     * Bits 6-5: Privilege level of caller (0=kernel..3=user)
     * Bit 4: Set to 0 for interrupt gates
     * Bits 3-0: bits 1110 = decimal 14 = "32 bit interrupt gate" */
    byte flags; 
    ushort high_offset; /* Higher 16 bits of handler function address */
} __attribute__((packed)) idt_gate_t;

typedef struct {
    ushort limit;
    uint base;
} __attribute__((packed)) idt_register_t;


// Array of interrupt handlers.  This is read by the lidt instruction in assembly.
idt_gate_t idt[IDT_LENGTH];
idt_register_t idt_reg;

void interrupt_descriptor_table_set_gate(int n, uint handler);
void interrupt_descriptor_table_setup();
#endif