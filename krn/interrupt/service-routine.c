#include "service-routine.h"

/* Can't do this with a loop because we need the address
 * of the function names */
void interrupt_service_routine_setup() {
    interrupt_descriptor_table_set_gate(0, (uint)isr0);
    interrupt_descriptor_table_set_gate(1, (uint)isr1);
    interrupt_descriptor_table_set_gate(2, (uint)isr2);
    interrupt_descriptor_table_set_gate(3, (uint)isr3);
    interrupt_descriptor_table_set_gate(4, (uint)isr4);
    interrupt_descriptor_table_set_gate(5, (uint)isr5);
    interrupt_descriptor_table_set_gate(6, (uint)isr6);
    interrupt_descriptor_table_set_gate(7, (uint)isr7);
    interrupt_descriptor_table_set_gate(8, (uint)isr8);
    interrupt_descriptor_table_set_gate(9, (uint)isr9);
    interrupt_descriptor_table_set_gate(10, (uint)isr10);
    interrupt_descriptor_table_set_gate(11, (uint)isr11);
    interrupt_descriptor_table_set_gate(12, (uint)isr12);
    interrupt_descriptor_table_set_gate(13, (uint)isr13);
    interrupt_descriptor_table_set_gate(14, (uint)isr14);
    interrupt_descriptor_table_set_gate(15, (uint)isr15);
    interrupt_descriptor_table_set_gate(16, (uint)isr16);
    interrupt_descriptor_table_set_gate(17, (uint)isr17);
    interrupt_descriptor_table_set_gate(18, (uint)isr18);
    interrupt_descriptor_table_set_gate(19, (uint)isr19);
    interrupt_descriptor_table_set_gate(20, (uint)isr20);
    interrupt_descriptor_table_set_gate(21, (uint)isr21);
    interrupt_descriptor_table_set_gate(22, (uint)isr22);
    interrupt_descriptor_table_set_gate(23, (uint)isr23);
    interrupt_descriptor_table_set_gate(24, (uint)isr24);
    interrupt_descriptor_table_set_gate(25, (uint)isr25);
    interrupt_descriptor_table_set_gate(26, (uint)isr26);
    interrupt_descriptor_table_set_gate(27, (uint)isr27);
    interrupt_descriptor_table_set_gate(28, (uint)isr28);
    interrupt_descriptor_table_set_gate(29, (uint)isr29);
    interrupt_descriptor_table_set_gate(30, (uint)isr30);
    interrupt_descriptor_table_set_gate(31, (uint)isr31);

    // Remap the PIC
    io_out_byte(0x20, 0x11);
    io_out_byte(0xA0, 0x11);
    io_out_byte(0x21, 0x20);
    io_out_byte(0xA1, 0x28);
    io_out_byte(0x21, 0x04);
    io_out_byte(0xA1, 0x02);
    io_out_byte(0x21, 0x01);
    io_out_byte(0xA1, 0x01);
    io_out_byte(0x21, 0x0);
    io_out_byte(0xA1, 0x0); 

    // Install the IRQs
    interrupt_descriptor_table_set_gate(32, (uint)irq0);
    interrupt_descriptor_table_set_gate(33, (uint)irq1);
    interrupt_descriptor_table_set_gate(34, (uint)irq2);
    interrupt_descriptor_table_set_gate(35, (uint)irq3);
    interrupt_descriptor_table_set_gate(36, (uint)irq4);
    interrupt_descriptor_table_set_gate(37, (uint)irq5);
    interrupt_descriptor_table_set_gate(38, (uint)irq6);
    interrupt_descriptor_table_set_gate(39, (uint)irq7);
    interrupt_descriptor_table_set_gate(40, (uint)irq8);
    interrupt_descriptor_table_set_gate(41, (uint)irq9);
    interrupt_descriptor_table_set_gate(42, (uint)irq10);
    interrupt_descriptor_table_set_gate(43, (uint)irq11);
    interrupt_descriptor_table_set_gate(44, (uint)irq12);
    interrupt_descriptor_table_set_gate(45, (uint)irq13);
    interrupt_descriptor_table_set_gate(46, (uint)irq14);
    interrupt_descriptor_table_set_gate(47, (uint)irq15);
}

void interrupt_service_routine_handler(registers_t *r) {
    exception_handler(r->int_no);
}