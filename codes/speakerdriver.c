typedef unsigned int uint32;
static void play_sound(uint32 nFrequence) {
    uint32 Div;
    uint8 tmp;

    //Set the PIT to the desired frequency
    Div = 1193180 / nFrequence;
    write_port(0x43, 0xb6);
    write_port(0x42, (uint8) (Div) );
    write_port(0x42, (uint8) (Div >> 8));

    //And play the sound using the PC speaker
    tmp = read_port(0x61);
    if (tmp != (tmp | 3)) {
        write_port(0x61, tmp | 3);
    }
}

//make it shutup
static void nosound() {
    uint8 tmp = inb(0x61) & 0xFC;
    write_port(0x61, tmp);
}

//Make a beep
void beep() {
        play_sound(1000);
        getch();
        nosound();
        //set_PIT_2(old_frequency);
}
