#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){ 
    char  palavras[5];
    printf("Digite seu nome:");
    fgets(palavras,5,stdin);
    //A ultima posição é usado para o caracter de final da string \0
    printf("nome: %s",palavras);
    
    
    return 0;

}