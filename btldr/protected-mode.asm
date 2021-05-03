[bits 16]
ProtectedModeSwitch:
  cli 					; Disable interrupts before we go to 32-bit

  lgdt [GdtDescriptor]			; Load the GDT descriptor


  mov eax, cr0				; To move to 32-bit mode we need to set the first bit of the control register
  or eax, 0x1				; to 1.  We do that by reading it, oring it with 1 and then moving it back
  mov cr0, eax				; to the control register.  We're now in 32-bit mode but have to far-jump to
					; allow any 16-bit parallelised 16-bit pipelines to complete.

  jmp CodeSegment:ProtectedModeInit	; Here's the far jump and when it's called we're fully in PM


[bits 32]
ProtectedModeInit:
  mov ax, DataSegment			; Update all segments registers to be the data segment as defined in the GDT
  mov ds, ax
  mov ss, ax
  mov es, ax
  mov fs, ax
  mov gs, ax

  mov ebp, 0x90000			; Update stack position so we're at the top off free space
  mov esp, ebp

  mov ebx, MessageProtectedModeStart   ; Debug print that we're in protected mode
  call PrintStringProtectedMode

  call MainProtectedMode
