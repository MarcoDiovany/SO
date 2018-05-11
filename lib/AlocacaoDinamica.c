
int quad(int vezes){
    /*int aux=1,x;
    for(x=0;x<vezes;x++)
        aux*=2;
    return aux;*/
    return pow(2,vezes);
}

void* getEndPublic(){
    return mem_public;
}
void* getEndVoid(){
    return &vd;
}
int getBit(unsigned char alvo,int pos){
    if(pos>7||pos<0){
        return -1;
    }
    pos++;
    alvo=(alvo<<8)-pos;
    alvo=alvo>>7;
    return alvo;
}
void statusMem(){
    unsigned int p=0,x,y=0,aux=MEM_MAX/((MEM_MAX<256)?MEM_MAX:256),aux2=0;
    printf("\nUso de memoria: [");
    for(x=0;x<MEM_MAX/(8*BLOCO);x+=aux/BLOCO+1){
        for(y=aux2;y<8;y+=aux){
            if(getBit(mem_map[x],y)==1){
                printf("|");	
            }else printf("_");
        }
        aux2=y%8;
    }
    for(x=0;x<MEM_MAX/(8*BLOCO);x++){
        for(y=0;y<8;y++){
            if(getBit(mem_map[x],y)==1){
                p++;	
            }
        }
    }
    printf("] %.4f%% - %d bytes",100*p/((float)MEM_MAX/BLOCO),p*BLOCO);
    for(p=0,x=0;x<PRO_MAX;x++){
       if(programs[x].pos!=0)p++;
    }
    printf("\nVariaveis alocadas:  %.4f%% - %d \n\n",100*p/((float)PRO_MAX),p);
}
void resetMem(){
    int x;
    for(x=0;x<MEM_MAX/(8*BLOCO);x++){
        mem_map[x]=0x00;
    }
    for(x=0;x<PRO_MAX;x++){
        programs[x].pos=0;
    }
}
void mostrarMem(){
    int x,y;
    for(x=0;x<MEM_MAX/(8*BLOCO);x++){
        for(y=0;y<8;y++){
                printf("%d-",getBit(mem_map[x],y));
        }
        printf("\n");
    }
    for(x=0;x<MEM_MAX;x++){
        if(x%8==0)printf("|");
        printf(" %c ",mem_public[x]);
        
    }
    printf("\n");
}
void libera(void *p){
    int w=0;
    if(p==0)return;
    if(p==&vd)return;
    while(programs[w].pos!= p){
        w++;
        if(w>=PRO_MAX)return;
    }
    int y;
    int tam=programs[w].tam,aux;
    {
        long int p1=(long int)programs[w].pos, p2=(long int)&mem_public[0];
        aux = (p1-p2)/BLOCO;
    }
    for(y=0;y<tam;y++){
        int z=aux+y;
        int a=z%8,b=z/8;
        if(getBit(mem_map[b],a)!=0){
            mem_map[b]-=quad(a);
        }
    }
    programs[w].pos=0;
    programs[w].tam=0;
}
void* alocaTemp(unsigned long int tam){
    unsigned int x=0,bol=true,y;
    if(tam<=0)return &vd; 
    if(tam%BLOCO>0)tam=tam/BLOCO+1;
    else tam/=BLOCO;
    do{
        if(!getBit(mem_map[x/8],x%8)){
            bol=false;
            y=1;
            do{
                int z=x+y;
                if(getBit(mem_map[z/8],z%8))bol=true;
                y++;
            }while(y<tam && !bol);
        }
        if(bol)x++;
        if(x>MEM_MAX/BLOCO-tam){
            x=0;
        }
    }while(bol);
    return &mem_public[x*BLOCO];
}
void* aloca(unsigned long int tam){
    unsigned int x=0,bol=true,y,w=0;
    if(tam<=0)return &vd; 
    if(tam%BLOCO>0)tam=tam/BLOCO+1;
    else tam/=BLOCO;
    do{
        if(!getBit(mem_map[x/8],x%8)){
            int bol2=true;
            y=1;
            do{
                int z=x+y;
                if(getBit(mem_map[z/8],z%8))bol2=false;
                y++;
            }while(y<tam && bol2);
            if(bol2){
                for(y=0;y<tam;y++){
                    int z=x+y;
                    int a=z%8,b=z/8;
                    if(getBit(mem_map[b],a)!=1){
                        mem_map[b]+=quad(a);
                    }
                }
                bol=false;
            }else x++;
        }else x++;
        if(x>MEM_MAX/BLOCO-tam){
            x=0;
        }
    }while(bol);
    while(programs[w].pos!=0){
        w++;
        if(w>=PRO_MAX)w=0;
    }
    
    programs[w].pos=&mem_public[x*BLOCO];
    programs[w].tam=tam;
    return &mem_public[x*BLOCO];
}
void* realoca(void *p,int tam){
    int w=0;
    while(programs[w].pos!= p){
        w++;
        if(w>=PRO_MAX){
                return aloca(tam);
        }
    }
    if(tam<=0){
        libera(p);
        return &vd;
    }
    int aux=programs[w].tam*BLOCO,x;
    char *lp,*c=(char*)p;
    libera(p);
    lp=(char*)aloca(tam);
    for(x=0;x<tam && x<aux;x++)lp[x]=c[x];
    return (void*)lp;
}
