
#include "Head.h"

void init(){
    idt_init();
    //disablilita_cursor();
    clear_screen();
    setcor_console(0xa);
    
}

void kmain(void)
{
    init();
    printf("Ola mundo");
    seta_cursor(10,1);
    getch();
    while(console());
}
