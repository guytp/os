BootDrive db 0
KernelOffset equ 0x1000 ; Where we will load the kernel
MessageRealModeStart db		"Starting in 16-bit real mode ", 0
MessageProtectedModeStart db	"Entered 32-bit protected mode", 0
MessageKernelLoading db		"Loading kernel into memory.  ", 0
MessageKernelStarting db	"Starting kernel              ", 0
MessageKernelExited db		"Kernel has exited            ", 0
MessageRebooting db		"All code complete, rebooting ", 0
MessageDiskError db             "Problem reading from disk    ", 0
MessageDiskSectorError db	"Disk read sector mismatch    ", 0
