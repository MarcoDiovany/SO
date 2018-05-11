char num_char(int c){
    return  digito_asc[c];
}
int gettam_num(int num){
    int count = 0;
    if(num == 0)return 1;
    while(num > 0){
        count++;
        num = num/10;
    }
    return count;
}
void int_asc(int num, char *numero){
    int Num_Cont = gettam_num(num);
    int index = Num_Cont - 1;
    char x;
    if(num == 0 && Num_Cont == 1){
        numero[0] = '0';
        numero[1] = '\0';
    }else{
        while(num != 0){
            x = num % 10;
            numero[index] = x + '0';
            index--;
            num = num / 10;
        }
        numero[Num_Cont] = '\0';
    }
}
void clear_screen(void){
    unsigned int i = 0;
    while (i < SCREENSIZE)vidtela[i++] = (0) | (corconsole<<8);
    current_loc = 0;
    interrupcaovideo();
}

void setcorfundo(uint8 cor){
    unsigned int i = 0;
    while (i < SCREENSIZE) {
        if(!(vidtela[i] & 0x00ff))
        vidtela[i] = (vidtela[i]&0x00ff)|(cor<<12);
        i++;
    }
    interrupcaovideo();
}

char getCor(unsigned char cor,unsigned char backgroud_color){
    return ((backgroud_color<<4)|cor);
}

void setcor_console(uint8 cor){
    corconsole = cor;
}

void setposicao_video(unsigned int x,unsigned int y){
    current_loc = ((y-1)*80)+x-1;
    return;
}

void interrupcaovideo(){
    int i=0;
    for(i=0;i<SCREENSIZE;i++)vidptr[i] = vidtela[i];
}
