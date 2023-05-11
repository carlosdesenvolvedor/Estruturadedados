#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){ 
    char  palavras[50]= {"Eu estou treinando a programação em C"};
    printf("Digite seu nome:");
    fgets(palavras,50,stdin);
    //A ultima posição é usado para o caracter de final da string \0
    printf("nome: %s",palavras);
    
    
    return 0;

}