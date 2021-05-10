all: kernel-linked

kernel-linked: entry-point exception-handler kernel io drivers-screen interrupt-descriptor-table interrupt-cpu-hookup interrupt-core interrupt-request-line interrupt-service-routine timer
	i386-elf-ld -o obj/kernel.bin -Ttext 0x1000 obj/entry-point.o obj/exception-handler.o obj/kernel.o obj/screen.o obj/io.o obj/interrupt-descriptor-table.o obj/interrupt.o obj/interrupt-request-line.o obj/interrupt-service-routine.o obj/interrupt-cpu-hookup.o obj/timer.o --oformat binary

entry-point:
	nasm entry-point.asm -f elf -o obj/entry-point.o

kernel:
	i386-elf-gcc -ffreestanding -c kernel.c -o obj/kernel.o

timer:
	i386-elf-gcc -ffreestanding -c timer.c -o obj/timer.o

exception-handler:
	i386-elf-gcc -ffreestanding -c exception-handler.c -o obj/exception-handler.o

io:
	i386-elf-gcc -ffreestanding -c drivers/io.c -o obj/io.o

drivers-screen:
	i386-elf-gcc -ffreestanding -c drivers/screen.c -o obj/screen.o

interrupt-descriptor-table:
	i386-elf-gcc -ffreestanding -c interrupt/descriptor-table.c -o obj/interrupt-descriptor-table.o

interrupt-core:
	i386-elf-gcc -ffreestanding -c interrupt/interrupt.c -o obj/interrupt.o

interrupt-request-line:
	i386-elf-gcc -ffreestanding -c interrupt/request-line.c -o obj/interrupt-request-line.o

interrupt-service-routine:
	i386-elf-gcc -ffreestanding -c interrupt/service-routine.c -o obj/interrupt-service-routine.o

interrupt-cpu-hookup:
	nasm interrupt/cpu-hookup.asm -f elf -o obj/interrupt-cpu-hookup.o

clean:
	rm obj/*
