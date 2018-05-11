#ifndef STDIO_H
    #define STDIO_H
    
    #define printf kprint
    
    void kputcl(const uint16 c);
    void kputc(const char c,uint8 cor);
    void putchar(const char c);
    char tryGetch();
    char getch();
    char getche();
    char getchar();
    char *gets(char *buf);
    void kprint(const char *str,...);
    void kprint_newline(void);
    void printnum(int num,uint8 cor);
    
    #include "stdio.c"
    
#endif