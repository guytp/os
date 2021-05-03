[bits 16]
KernelLoad:
  mov bx, MessageKernelLoading		; Print debug message for kernel loading
  call PrintString

  mov bx, KernelOffset			; Call disk load - we're setting up the kernel offset
  mov dh, 15				; 15 sectors of data to load and the boot drive
  mov dl, [BootDrive]			; reference that we stored as soon as boot sector starter
  call DiskLoad				; up to be used as parameters here

  ret


[bits 32]
KernelStart:
  mov ebx, MessageKernelStarting	; Debug print that we're in protected mode
  call PrintStringProtectedMode

  call KernelOffset			; This is where we loaded Kernel to from disk

  mov ebx, MessageKernelExited		; Debug print that kernel exited
  call PrintStringProtectedMode

  ret					; Jump back to the main loop which will ultimately reboot us
