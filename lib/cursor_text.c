void desablilita_cursor(){
    write_port(0x3D4, 0x0A);
    write_port(0x3D5, 0x20);
}

void habilita_cursor(uint8 cursor_start, uint8 cursor_end){
    outb(0x3D4, 0x0A);
    outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);

    outb(0x3D4, 0x0B);
    outb(0x3D5, (inb(0x3E0) & 0xE0) | cursor_end);
}

void atualiza_cursor(){
    write_port(0x3D4, 0x0F);
    write_port(0x3D5, (uint8)(current_loc & 0xff));
    write_port(0x3D4, 0x0E);
    write_port(0x3D5, (uint8)((current_loc >> 8) & 0xff));
}

void seta_cursor(char x,char y){
    unsigned int pos = ((y-1)*80)+x-1;
    write_port(0x3D4, 0x0F);
    write_port(0x3D5, (uint8)(pos & 0xff));
    write_port(0x3D4, 0x0E);
    write_port(0x3D5, (uint8)((pos >> 8) & 0xff));
}