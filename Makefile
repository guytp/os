all: osimage

osimage: bootloader kernel
	cat btldr/obj/boot_sec.bin krn/obj/kernel.bin > os-image.img

run: osimage
	qemu-system-i386 -fda os-image.img

bootloader:
	$(MAKE) -C btldr btldr

kernel:
	$(MAKE) -C krn all

clean:
	$(MAKE) -C btldr clean
	$(MAKE) -C krn clean
