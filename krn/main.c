#include "kernel.h"
#include "drivers/screen.h"

void main() {
  screen_setup();
  screen_print("Kernel loaded");
  screen_print(" and more this is a really long line that I'm going to \nwrite to make it overflow onto the second line\n");
  
  int i = 0;
  while (true)
  {
  for (i = 0; i < 50; i++) {
    char c[4];
    int first = i / 10;
    int second = i % 10;
    c[0] = first + 48;
    c[1] = second + 48;
    c[2] = '\n';
    c[3] = '\0';
    screen_print(c);
    int j = 0;

    for (j = 0; j < 100000000; j++) {
      int a = 1;
      int b = a + 2;
    }
  }
  }
}