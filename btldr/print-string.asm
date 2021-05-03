[bits 32]
VideoMemory equ 0xb8000
TextDefault equ 0x3F			; White on blue

PrintStringProtectedMode:
  pusha					; Push all registers to stack and set edx to be location
  mov edx, VideoMemory			; of video memory

PrintStringProtectedModeLoop:
  mov al, [ebx]				; Store character at EBX into AL
  mov ah, TextDefault			; Set the background attributes for text

  cmp al, 0				; When we reach a null character we need to jump to being done
  je PrintStringProtectedModeLoopDone

  mov [edx], ax				; Take the character stored in ax and push it to current location of
  add ebx, 1				; video memory.  We then increase video memory location (edx) by 2 (since it's
  add edx, 2				; 2 bytes per string for text + formatting) and the string index by 1

  jmp PrintStringProtectedModeLoop	; Back to start of loop

PrintStringProtectedModeLoopDone:
  popa					; Pop everything from the stack

  ret


[bits 16]
PrintString:
  pusha					; Push all reigsters to stack

PrintStringLoop:
  mov al, [bx]				; String is in bx, so move it into al

  cmp al, 0				; Once we reach null break out of the loop
  je PrintStringLoopDone

  mov ah, 0x0e				; Call out to BIOS to print, with character already in al
  int 0x10

  add bx, 1				; Increment loop count and location in string and try again
  jmp PrintStringLoop

PrintStringLoopDone:
  popa					; Pop everything from the stack

  ret
