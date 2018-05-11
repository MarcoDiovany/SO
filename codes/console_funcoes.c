void toup(char *c)
{
    while(*c)
    {*c&=0xdf;c++;}
}
void todown(char *c)
{
    while(*c)
    {*c|=0x40;c++;}
}
void dialogocor()
{
    uint16 telabackup[SCREENSIZE];
    unsigned int cursorbackup=current_loc;
    char c=0,back,letra;
    int i=0;
    for(i=0;i<SCREENSIZE;i++)
    {
            telabackup[i] = vidtela[i];
    }
    clear_screen();
    kprint("Qual cor voce deseja para background? ");
    c = getchar();
    if(c>57){toup(&c);c-=55;}else{c&=0xf;}
    back =c;
    kprint("\nQual cor voce deseja para as letras? ");
    c = getchar();
    if(c>57){toup(&c);c-=55;}else{c&=0xf;}
    letra =c;
    corconsole = getCor(letra,back);
    for(i=0;i<SCREENSIZE;i++)
    {
        vidtela[i] = telabackup[i];
    }
    current_loc = cursorbackup;
    setcorfundo(back);
    putchar('\n');
}
void brainf(char *arg){
    clear_screen();
    char comando[1024] = {0},c=0;
    keyboard_map[72] = '+';
    keyboard_map[80] = '-';
    keyboard_map[0x4b] = '<'; //33
    keyboard_map[77] = '>';
    strcpy(comando,arg);
    while(1)
    {
        kprint("Digite os comandos em brainfuck abaixo:\n");
        if(c!='\n')
        {
            if(strlen(arg)){
                kprint("%s\n%cExecutando:",comando,0xe4);putchar('\n');
            }else{
                gets(comando);kprint("\n%cExecutando:",0xe4);putchar('\n');
            }
        }else{
            kprint("%s\n%cExecutando Novamente:",comando,0xe4);putchar('\n');
        }
        brainDeco(comando);
        kprint("\nPrograma Finalizado:\n");
        c =getch();
        if(c == 27)
        {
                break;
        }
        clear_screen();
    }
    kprint("\nbrainf_coder finalizado...\n");
    keyboard_map[72] = 0;
    keyboard_map[80] = 0;
    keyboard_map[0x4b] = 0;
    keyboard_map[77] = 0;
}

