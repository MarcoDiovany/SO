#ifndef HEAD_H
    #define HEAD_H


    #define inb read_port
    #define outb write_port
    #define NULL 0

    #define true 1
    #define false 0

    typedef unsigned short uint16;
    typedef unsigned char uint8;
    typedef int s32;
    typedef s32 acpi_native_int;
    typedef char *va_list;

    extern unsigned char keyboard_map[128];
    extern void keyboard_handler(void);
    extern char read_port(unsigned short port);
    extern void write_port(unsigned short port, unsigned char data);
    extern void delay(void);// 0,25 segundo
    extern void load_idt(unsigned long *idt_ptr);
    #include "codes/keyboard.c"

    #include "lib/powermananger.c"
    #include "lib/Math.h"
    #include "lib/string.h"
    #include "lib/gfx_text.h"
    #include "lib/stdio.h"
    #include "lib/grafic_vga.c"
    #include "lib/AlocacaoDinamica.h"


    #include "codes/interrupts.c"
    #include "codes/brain.c"
    #include "codes/console.c"

#endif
