all: kernel

kernel: main-asm main-c
	i386-elf-ld -o obj/kernel.bin -Ttext 0x1000 obj/main-asm.o obj/main-c.o --oformat binary

main-asm:
	nasm main.asm -f elf -o obj/main-asm.o

main-c:
	i386-elf-gcc -ffreestanding -c main.c -o obj/main-c.o

clean:
	rm obj/*
