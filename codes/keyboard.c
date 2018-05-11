#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

#include "keyboard_map.h"

char buff;
uint8 CAPSON=0,SHIFT=0;
void kb_init(void){
    /* 0xFD is 11111101 - enables only IRQ1 (keyboard)*/
    buff = 0;
    write_port(0x21 , 0xFD);
}
void kb_close_init(void){
    write_port(0x21,0xff);
}

void keyboard_handler_main(void)
{
    unsigned char status;
    char keycode,c;

    /* write EOI */
    write_port(0x20, 0x20);

    status = read_port(KEYBOARD_STATUS_PORT);
    /* Lowest bit of status will be set if buffer is not empty */
    if (status & 0x01) {
        keycode = read_port(KEYBOARD_DATA_PORT);
        if(keycode < 0){
            return ;
        }else if(keycode == 58){
            if(CAPSON){
                CAPSON =0;
            }else{
                CAPSON =0xff;
            }
        }else if((keycode == 0x36)||(keycode == 0x2A))
        {
            SHIFT = 0xff;
            while((keycode == 0x36)||(keycode == 0x2A))
            {
                write_port(0x20, 0x20);

                status = read_port(KEYBOARD_STATUS_PORT);
                /* Lowest bit of status will be set if buffer is not empty */
                if (status & 0x01) {keycode = read_port(KEYBOARD_DATA_PORT);}
            }
        }
        c = keyboard_map[(unsigned char) keycode];
        if((CAPSON != SHIFT)){
            c= ASC_CAP[c];
        }
        buff = c;
        SHIFT = 0;
    }
}
