[BITS 32]

global start

start:
    mov esp, stack_space    ; Seleciona nova area na pilha do sistema
    jmp entrarkernel		  ; Pula para o bloco onde e efetuada a chamada do kernel

ALIGN 4 ; Obrigatoriamente esta parte deve estar alinhada a 4 bytes

;
; O bloco multiboot e responsavel por expor informacoes importantes para o linker
;
multiboot:
    ; Macros para o GRUB
    MULTIBOOT_PAGE_ALIGN	equ 1<<0
    MULTIBOOT_MEMORY_INFO	equ 1<<1
    MULTIBOOT_AOUT_KLUDGE	equ 1<<16
    MULTIBOOT_HEADER_MAGIC	equ 0x1BADB002
    MULTIBOOT_HEADER_FLAGS	equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO | MULTIBOOT_AOUT_KLUDGE
    MULTIBOOT_CHECKSUM	equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
    
    EXTERN code, bss, end

    ; Expondo os cabecalhos Multiboot do GRUB, a assinatura do boot
    ; Caso queira ter mais informacoes vide: http://www.gnu.org/software/grub/manual/multiboot/multiboot.html
    dd MULTIBOOT_HEADER_MAGIC
    dd MULTIBOOT_HEADER_FLAGS
    dd MULTIBOOT_CHECKSUM
    
    ; Expondo enderecos fisicos para o linker (link.ld)
    dd multiboot
    dd code
    dd bss
    dd end
    dd start

global start
global keyboard_handler
global read_port
global write_port
global load_idt
global delay

extern keyboard_handler_main

read_port:
	mov edx, [esp + 4]
			;al is the lower 8 bits of eax
	in al, dx	;dx is the lower 16 bits of edx
	ret

write_port:
	mov   edx, [esp + 4]    
	mov   al, [esp + 4 + 4]  
	out   dx, al  
	ret

load_idt:
	mov edx, [esp + 4]
	lidt [edx]
	sti 				;turn on interrupts
	ret

keyboard_handler:                 
	call    keyboard_handler_main
	iretd
delay:
		mov cx,0x03
	delRep: push cx
		mov cx,0x0D090
	delDec: dec cx
		jnz delDec
		pop cx
		dec cx
		jnz delRep
		ret	

entrarkernel:
	pusha
	cli 				;block interrupts
	extern kmain
	mov esp, stack_space
	call kmain
	jmp $				;halt the CPU

section .bss
resb 16284; 16KB for stack
stack_space:
