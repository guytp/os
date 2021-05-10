#include "descriptor-table.h"

#define low_16(address) (ushort)((address) & 0xFFFF)
#define high_16(address) (ushort)(((address) >> 16) & 0xFFFF)

void interrupt_descriptor_table_set_gate(int n, uint  handler) {
    idt[n].low_offset = low_16(handler);
    idt[n].sel = KERNEL_SEGMENT;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E; 
    idt[n].high_offset = high_16(handler);
}

void interrupt_descriptor_table_setup() {
    idt_reg.base = (uint) &idt;
    idt_reg.limit = IDT_LENGTH * sizeof(idt_gate_t) - 1;
    /* Don't make the mistake of loading &idt -- always load &idt_reg */
    asm volatile("lidtl (%0)" : : "r" (&idt_reg));
}