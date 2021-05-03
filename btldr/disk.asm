[bits 16]
DiskLoad:
  push dx				; Store DX on the stack so we can recall number of sectors to read later

  mov ah, 0x02				; Indicates BIOS read sector function
  mov al, dh				; Number of sectors to read = DH
  mov ch, 0x00				; Cylinder 0
  mov dh, 0x00				; Head 0
  mov cl, 0x02				; Start at sector 2

  int 0x13				; BIOS interrupt to read for us

  jc DiskError				; If carry bit is set it indicates an error so jump to that and halt

  pop dx				; Restore dx from the stack indicating how many sectors to read
  cmp dh, al				; Ensure we read sectors we wanted to (al = sectors read, dh = expected).
  jne DiskSectorError			; If not then we jump to the error scenario.

  ret

DiskError:
  mov bx, MessageDiskError		; On error we print message then block forever
  call PrintString
  jmp $

DiskSectorError:
  mov bx, MessageDiskSectorError	; On error we print message then block forever
  call PrintString
  jmp $
