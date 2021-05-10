#include "kernel.h"
#include "exception-handler.h"
#include "interrupt/interrupt.h"
#include "drivers/screen.h"
#include "timer.h"

int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0') ++i;
    return i;
}
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void ulong_to_ascii(ulong n, char str[]) {
    ulong i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    reverse(str);
}

void kernel_main() {
  screen_setup();
  screen_print("Display starting... (done)\n");

  screen_print("Interrupts starting... ");
  interrupt_setup();
  screen_print("(done)\n");

  
  screen_print("Timer starting... ");
  timer_setup();
  screen_print("(done)\n");
  
  screen_print("Kernel loaded\n");
  
  ulong i = 0;
  while (true)
  {
    char str[30];
    ulong v = 0;
    while ((v = timer_get() / 100) == i)
    {
      asm volatile("HLT");
    }
    i = v;
    ulong_to_ascii(v, str);
    screen_print("Time ");
    screen_print(str);
    screen_print("\n");
  }
}