
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
    printf("Sistema Carregado!\n%cPrecione Qualquer Tecla\n",0x8a);
    seta_cursor(0,10);
    getch();
    while(console());
}
