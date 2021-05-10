#include "exception-handler.h"
#include "drivers/screen.h"

char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

// Later on we want a _setup method here and pass a pointer to this method, for now we'll just implement here and extern it in the ISR part
void exception_handler(uint exceptionNumber) {
    screen_text_style(White, LightRed);
    screen_clear();
    screen_print("Kernel Panic: ");
    screen_print(exception_messages[exceptionNumber]);
    screen_print("\nSystem halted...");
    while (1 == 1) {
        // TODO: Actual halt, disable interrupts, etc.
    }
}