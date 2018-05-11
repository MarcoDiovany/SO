#ifndef ALOC_H
    #define ALOC_H
    
    #define MEM_MAX 65536 
    // 64kb - map 1kb
    //#define MEM_MAX 1048576
    // 1024kb ou 1mb - map 16kb
    //#define MEM_MAX 67108864
    // 65536 ou 64mb - map 1024kb
    //#define MEM_MAX 1073741824
    // 1024mb ou 1gb - map 16mb
    //#define MEM_MAX 1024

    #define VAR_MAX 64

    //#define PRO_MAX 1024
    // define 1024 espaços máximos de memória
    #define PRO_MAX 256
    // define 256 espaços máximos de memória

    #define BLOCO 2
    
    typedef struct{
	void *pos;
	unsigned long long int tam;
    }mem_Ocup;

    unsigned char mem_public[MEM_MAX+8];
    unsigned char mem_map[MEM_MAX/(8*BLOCO)];
    mem_Ocup programs[PRO_MAX];
    unsigned char vd;
    
    void* aloca(unsigned long int tam);
    void resetMem();
    void libera(void *p);
    void statusMem();
    void* realoca(void *p,int tam);
    void* getEndVoid();
    void* getEndPublic();
    void mostrar();
    void* alocaTemp(unsigned long int tam);
    
    #include "AlocacaoDinamica.c"
#endif