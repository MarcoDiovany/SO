
extern void global vga_interrupt(void);
unsigned char * memvga = 0xA0000;

static void putpixel(int x,int y, int color) {
    unsigned where = x*3 + y*600;
    memvga[where] = color & 255;              // BLUE
    memvga[where + 1] = (color >> 8) & 255;   // GREEN
    memvga[where + 2] = (color >> 16) & 255;  // RED
}
