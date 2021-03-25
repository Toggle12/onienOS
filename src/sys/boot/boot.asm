; boot asm code

bits 32
section .text
; ----multiboot------
    align 4
    dd 0x1BADB002 
    dd 0x00 ; flags
    dd - (0x1BADB002 + 0x00) ; checksum
global start
extern OSmain ; entery point

start:
    cli
    mov esp, stack_space

    call OSmain

    hlt


stack_space: ; buffer