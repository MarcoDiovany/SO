#ifndef GFX_H
    #define GFX_H
    
    #define  _AUPBND                (sizeof (acpi_native_int) - 1)
    #define  _ADNBND                (sizeof (acpi_native_int) - 1)
    #define _bnd(X, bnd)            (((sizeof (X)) + (bnd)) & (~(bnd)))
    #define va_arg(ap, T)           (*(T *)(((ap) += (_bnd (T, _AUPBND))) - (_bnd (T,_ADNBND))))
    #define va_end(ap)              (ap = (va_list) NULL)
    #define va_start(ap, A)         (void) ((ap) = (((char *) &(A)) + (_bnd (A,_AUPBND))))

    #define PRETO 0x0
    #define AZUL 0x1
    #define VERDE 0x2
    #define VERDE_AGUA 0x3
    #define VERMELHO 0x4
    #define ROXO 0x5
    #define AMARELO 0x6
    #define BRANCO 0x7
    #define endereco_vga 0xb8000;

    #define LINES 25
    #define COLUMNS_IN_LINE 80
    #define BYTES_FOR_EACH_ELEMENT 1
    #define SCREENSIZE BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE * LINES
    
    int digito_asc[10] = {'0','1','2','3','4','5','6','7','8','9'};
    /* current cursor location */
    unsigned int current_loc = {0};
    /* video memory begins at address 0xb8000 */
    uint16 *vidptr = (uint16*)endereco_vga;
    uint16 vidtela[SCREENSIZE] = {0};
    uint8 corconsole=0x07;

    void clear_screen(void);
    void setcorfundo(uint8 cor);
    char getCor(unsigned char cor,unsigned char backgroud_color);
    void setcor_console(uint8 cor);
    void setposicao_video(unsigned int x,unsigned int y);
    void interrupcaovideo();
    char num_char(int C);
    int gettam_num(int num);
    void int_asc(int num, char *numero);
    
    void habilita_cursor(uint8 cursor_start, uint8 cursor_end);
    void atualiza_cursor();
    void seta_cursor(char x,char y);
    void desablilita_cursor();
   
    
    
    #include "grafics_text.c"
    #include "cursor_text.c"
    
#endif
    