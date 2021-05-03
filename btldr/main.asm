[bits 16]
[org 0x7c00]
  mov [BootDrive], dl			; Store boot drive location from DL as handed over from BIOS

  mov bp, 0x9000			; Setup our stack
  mov sp, bp

  mov bx, MessageRealModeStart		; Debug print output in real-mode
  call PrintString

  call KernelLoad			; Load our kernel into memory from disk

  call ProtectedModeSwitch		; Switch to protected mode

[bits 32]
MainProtectedMode:
  call KernelStart			; Actually start our kernel

  mov ebx, MessageRebooting		; Notify we've completed and need to reboot
  call PrintStringProtectedMode

  jmp $
  mov al, 0xFE				; Reboot us (source: https://forum.osdev.org/viewtopic.php?t=13113)
  out 0x64, al


%include "global-variables.asm"
%include "gdt.asm"
%include "print-string.asm"
%include "protected-mode.asm"
%include "disk.asm"
%include "kernel.asm"

[bits 16]
  times 510-($-$$) db 0			; Pad us out to 512 bytes so that we can fill the boot sector ending with 0xAA55
  dw 0xAA55
