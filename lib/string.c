
void strcpy(char *str,char *str2){
    while(*str2 != '\0')*str++ = *str2++;
}
void strcpywl(char *str,char *str2,int tam){
    int i=0;
    if(tam){
        for(i=0;(str2[i] != '\0') && (i < tam);i++)
        {
            str[i] = str2[i];
        }
    }else
    {
        strcpy(str,str2);
    }
}
unsigned int strlen(char *str){
    unsigned int i=0;
    while(*str++)
    {
        i++;
    }
    return i;
}
unsigned int findchar(char *str,char c){
    unsigned int i=0;
    while(str[i] != c)
    {
        if(strlen(str) < i){return 0;}
        i++;
    }
    return i;
}
void strclean(char *str){
    while(*str)
    {
        *str = 0;
        str++;
    }
}
int strcmp(const char *cs, const char *ct){
    unsigned char c1, c2;
    int res = 0;

    do {
        c1 = *cs++;
        c2 = *ct++;
        res = c1 - c2;
        if (res)
                    break;
    } while (c1);
    return res;
}

