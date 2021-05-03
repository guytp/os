void main() {
  char* videoMemory = (char*) 0xb8000;
  int i =0;
  for (i;i < (80*50); i+=2) {
    *(videoMemory + i) = ' ';
    *(videoMemory + i + 1) = 0x3F;
  }

  char* toPrint = "Kernel Booted";
  i = 0;
  int j = 162;
  char c = toPrint[0];
  while (c != '\0') {
      *(videoMemory + j) = c;
      i++;
      j+=2;
      c = toPrint[i];
  }
}
