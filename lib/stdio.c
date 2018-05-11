void kputcl(const uint16 c){
    if(current_loc > SCREENSIZE)current_loc = 0;
    if((c&0x00ff) == 8){
            while(!(vidtela[current_loc]&0x00ff))
            {
                    current_loc--;
            }
            vidtela[current_loc] = (c&0xff00);
    }else if((c&0xff) == '\n') {
            vidtela[current_loc] = (c&0xff00)|' ';
            kprint_newline();
            interrupcaovideo();
            return;
    }else vidtela[current_loc++] = c;
}

void kputc(const char c,uint8 cor){
    if(!cor)cor = corconsole;
    kputcl((c)|(cor<<8));
}
void putchar(const char c){
    kputc(c,0);
    interrupcaovideo();
}

char tryGetch(){
    kb_init();
    delay();
    kb_close_init();
    return buff;
}
char getch(){
    atualiza_cursor();
    kb_init();
    while(!buff)
    {delay();}
    kb_close_init();
    seta_cursor(0,0);
    return buff;
}
char getche(){
    char c;
    c =getch();
    putchar(c);
    return c;
}
char getchar(){
    char c,cb;
    c = getche();
    cb=c;
    while(1){
        c=getch();
        if(c == '\n' && cb != c)break;
        if(cb != c)
        {
            if(!cb){
                cb=c;
                putchar(c);
            }
            if(c==8){
                putchar(8);
                cb=0;
            }
        }
    }
    return cb;
}

char *gets(char *buf){
  char *p = buf;
  int ch;

  while (1) {
    ch = getch();

    if (ch == 8) {
      if (p > buf) {
        putchar('\b');
        putchar(' ');
        putchar('\b');
        p--;
      }
    } else if (ch == '\r' || ch =='\n' || ch >= ' ') {

      if (ch == '\r') putchar('\n');
      if (ch == '\n' || ch == '\r') break;
	putchar(ch);
      *p++ = ch;
    }
  }

  *p = 0;
  return buf;
}
void kprint(const char *str,...){
    uint8 cor = 0;
    va_list args;
    va_start(args, str);
    unsigned int i = 0;
    while (str[i] != '\0') {
        if(str[i] == '%')
        {
            i++;
            if(str[i] == 'd'){
                int n=va_arg(args,int);
                printnum(n,cor);
            }else if(str[i] == 's'){
                char *s =va_arg(args,char *);
                kprint(s,cor);
            }else if(str[i] == 'c')cor =(va_arg(args,uint8));
        }
        else kputc(str[i],cor);
        i++;
    }
    va_end(args);
    interrupcaovideo();
}

void kprint_newline(void){
    unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE;
    current_loc= current_loc+ (line_size - current_loc % (line_size));
}

void printnum(int num,uint8 cor){
    char str_num[gettam_num(num)+1];
    int i=0;
    int_asc(num, str_num);
    while(str_num[i] != '\0')kputc(str_num[i++],cor);
}
