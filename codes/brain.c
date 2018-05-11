#define BRAIN_MEM_MAX 300

typedef struct{
    int tamCod;
    char *cod;
    unsigned char mem [BRAIN_MEM_MAX];
    int pontMem,pontCod;
    int pontLoopMem[64];
    char loops;
}brain;

int brainCod (brain *b){
    if(b->pontCod>=b->tamCod)return 0;
    switch(b->cod [b->pontCod]){
    case '>':
        b->pontMem++;
        break;
    case '<':
        b->pontMem--;
        break;
    case '+':
        b->mem [b->pontMem]++;
        break;
    case '-':
        b->mem [b->pontMem]--;
        break;
    case '[':
        {
            int pos=b->pontCod+1;
            int aux=b->pontMem;
            b->pontCod=pos;
            if(b->mem[aux]==0){
                while(b->cod[b->pontCod]!=']')b->pontCod++;
            }else while (b->mem[aux]){
                while(brainCod(b))b->pontCod++;
            }
        }
        break;
    case ']':
        return 0;
        break;
    case '(':
        if(!b->mem[b->pontMem]){
            b->pontCod++;
            while(b->cod[b->pontCod]!=')' && b->cod[b->pontCod]!='|')b->pontCod++;
        }
        break;
    case '|':
        b->pontCod++;
        while(b->cod[b->pontCod])b->pontCod++;
        break;
    case ',':
        b->mem[b->pontMem] = getche();
        break;
    case '.':
        kprint("%d",b->mem[b->pontMem]);
        break;
    case '*':
        putchar(b->mem[b->pontMem]);
        break;
    default:
        return 2;
    }
    return 1;
}

void brainDeco(char *cod){
    brain b;
    {
        int x;
        for(x=0;x<512;x++)b.mem[x]=0;
    }
    b.tamCod=strlen(cod);
    b.cod =cod;
    b.pontMem=0;
    b.pontCod=0;
    /*int p;		EXEMPLO DE MULT-THREAD IN BRAIN CODE
    while(true) for(p=0;p<3;p++){
            brainCod(&b[p]);
            b[p].pontCod++;
    }*/
    
    while(b.pontCod<b.tamCod){
        brainCod(&b);
        b.pontCod++;
    }
}
