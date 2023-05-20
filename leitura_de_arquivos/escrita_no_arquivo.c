#include <stdio.h>

int main(){
    FILE *arq;
    char fruta[10];
    
    arq = fopen("frutas.txt","w");
    if(arq){
        //consegui criar o arquivo..
        printf("informe uma fruta ou 0 para sair: ");
        fgets(fruta,10,stdin); 
        while(fruta[0] != '0'){
            fputs(fruta,arq);
            printf("informe uma fruta ou 0 para sair:");
            fgets(fruta,10,stdin);
        }
    }
    else{
        printf("Nao foi criar o arquivo");
    }
    
    fclose(arq);
    return 0;
}