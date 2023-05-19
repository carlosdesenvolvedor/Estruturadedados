#include <stdio.h>

int main(){
    FILE *arq;
    char c;
    arq = fopen("arquivo.txt","r");//r somente leitura

    if(arq){
        while((c = getc(arq)) != EOF){ //EOF é uma constante e significa fim do arquivo
        printf("%c", c);
        }
    }else{
        printf("arquivo nao encontrado");
    }


    return 0;
}