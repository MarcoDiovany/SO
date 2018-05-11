#ifndef STRING_H
    #define STRING_H
    
    void strcpy(char *str,char *str2);
    void strcpywl(char *str,char *str2,int tam);
    unsigned int strlen(char *str);
    unsigned int findchar(char *str,char c);
    void strclean(char *str);
    int strcmp(const char *cs, const char *ct);
    
    #include "string.c"
    
#endif