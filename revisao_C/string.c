#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){ 
    char palavras[50]= {"Eu estou treinando a programação em C"};
    char nome2[40];
    printf("Digite seu nome:");
    fgets(palavras,50,stdin);
    //A ultima posição é usado para o caracter de final da string \0
    printf("nome com fgets: %s\n",palavras);
    printf("Digite outro nome: ");
    scanf("%20[^\n]",palavras[50]);
    printf("nome com scanf: %s",nome2);   
    system("pause");

}
