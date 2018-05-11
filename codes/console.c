#define comandn 5
#include "console_funcoes.c"

uint8 console_search(char *comando)
{
    char comandos[comandn][256]={0};
    int i=0;
    if(!strlen(comandos[0]))
    {
        strcpy(comandos[0],"brain");
        strcpy(comandos[1],"cls");
        strcpy(comandos[2],"setarcor");
        strcpy(comandos[3],"help");
        strcpy(comandos[4],"shutdown");
    }
    
    while(1)
    {
        if(i == comandn){return 0;}
        if(!strcmp(comando,comandos[i++]))
        {
                return i;
        }
    }
}
void help_console(char *arg)
{
    switch((arg)?console_search(arg):0)
    {
        case 1:
            kprint("\n         %cHelp Instructions for brainf%c\n %cinstrucao%c  - Descricao\n",0x64,corconsole,0x71,0x7);
            kprint(" %cseta esquerda%c    : para escrever < \n",0x71,0x7);	
            kprint(" %cseta direita%c    : para escrever > \n",0x71,0x7);	
            kprint(" %csetas cima e baixo%c    : para escrever + e - \n",0x71,0x7);	
            kprint(" %c,(virgula) e *%c    : entrada e saida em ASC II \n",0x71,0x7);	
            kprint(" %c.(ponto)%c    : para saida em numerica \n",0x71,0x7);
            kprint(" %c[ e ]%c    : para loop enquanto diferente de ZERO \n",0x71,0x7);
            kprint(" %cBreve Descricao%c : na linguagem voce trabalha com um vetor(vet[n_posicoes])\n onde usa < e > para movimentar a posicao, + e - para incrementar ou \n decrementar o valor e ,(virgula) .(ponto) e * para I/O  \n",0x71,0x7);			
            break;
        case 3:
            kprint("\n         %cHelp Instructions for setarcor%c\n %cinstrucao%c  - Descricao\n",0x64,corconsole,0x71,0x7);
            kprint(" %cbackground%c   : e a cor de fundo do console| 0-7 normal e 8-f piscante\n",0x71,0x7);	
            kprint(" %ccor letra%c    : e a cor da letra do console| 0-f normal\n",0x71,0x7);	
            break;
        default:
            kprint("\n         %cHelp Instructions%c\n %cComando%c  - Descricao\n",0x64,corconsole,0x71,0x7);
            kprint(" %cbrain%c    : E uma funcao que lhe permite programar em Brainfuck\n",0x71,0x7);	
            kprint(" %ccls%c      : E o comando para limpar a tela\n",0x71,0x7);
            kprint(" %csetarcor%c : E uma funcao que lhe permite trocar as cores do console\n",0x71,0x7);
            kprint(" %chelp%c     : E uma funcao que lhe ajuda com algumas informacoes\n",0x71,0x7);
            kprint(" %cshutdown%c : Desliga a maquina\n",0x71,0x7);

    }
    
}
int console()
{
    char comando[256]={0},instrucao[64]={0},args[256];
    kprint("Console >");
    gets(comando);
    strcpywl(instrucao,comando,findchar(comando,' '));
    if(findchar(comando,' '))
    {
        strcpy(args,(char*)(&comando)+(findchar(comando,' ')+1));
    }
    switch(console_search(instrucao))
    {
        case 1:
            brainf(args);
            break;
        case 2:
            clear_screen();
            break;
        case 3:
            dialogocor();
            break;
        case 4:
            help_console(args);
            break;
        case 5:
            clear_screen();
            kprint("%cFinalizado%c -pode desligar!\n",0xd4,corconsole);
            return 0;
            break;
        default:
            kprint("\nComando nao existe ou nao implementado\n");

    }
    strclean(args);
    return 1;
}

