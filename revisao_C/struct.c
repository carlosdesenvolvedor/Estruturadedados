#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pode se colocar varios tipos dentro da minha estrutura.
typedef struct{
    int idade;
    char sexo;
    char nome[100];

}Aluno;

int main(){

Aluno aluno, aluno2;
    aluno.nome[0] = 'C';
    aluno.nome[1] = 'a';
    aluno.nome[2] = 'r';
    aluno.nome[3] = 'l';
    aluno.nome[4] = 'o';
    aluno.nome[5] = 's';

    aluno.idade =10;
    printf("Primeiro aluno\n");
    aluno.sexo = 'M';
    printf("nome: ");
    for(int i = 0; i<6;i++){
        printf("%c",aluno.nome[i]);
    }


    aluno2.idade =45;
    aluno2.sexo = 'F';
    strcpy(aluno2.nome,"Maria josefina de oliveira");
    
    printf("\nidade: %d anos",aluno.idade);
    printf("\nSexo: %c\n",aluno.sexo);
    printf("segundo aluno:\n");
    printf("nome: %s\nSexo: %c\nIdade:%d anos",aluno2.nome,aluno2.sexo,aluno2.idade);
    
    return 0;

}