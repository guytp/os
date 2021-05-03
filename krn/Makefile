all: kernel

kernel: main-asm main-c drivers-screen io
	i386-elf-ld -o obj/kernel.bin -Ttext 0x1000 obj/main-asm.o obj/main-c.o obj/screen.o obj/io.o --oformat binary

main-asm:
	nasm main.asm -f elf -o obj/main-asm.o

main-c:
	i386-elf-gcc -ffreestanding -c main.c -o obj/main-c.o

io:
	i386-elf-gcc -ffreestanding -c drivers/io.c -o obj/io.o

drivers-screen:
	i386-elf-gcc -ffreestanding -c drivers/screen.c -o obj/screen.o

clean:
	rm obj/*
