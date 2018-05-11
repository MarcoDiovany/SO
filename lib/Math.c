int pow(int ex,int el){
    if(el==0)return 0;
    int aux=ex,x;
    for(x=0;x<el;x++)aux*=ex;
    return aux;
}
    