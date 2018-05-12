
#include "Head.h"

void init(){
    idt_init();
    disablilita_cursor();
    // clear_screen();
    //  setcor_console(0xa);

}

void kmain(void)
{
    init();
    //printf("Sistema Carregado!\n%cPrecione Qualquer Tecla\n",0x8a);
    //seta_cursor(0,10);
    int i=0;
    for(i=0;i<200;i++)
    {
        putpixel(i,10,0xff0000);
        putpixel(i,11,0xff0000);
        putpixel(i,12,0xffff00);
        putpixel(i,13,0xffff00);
    }
}
