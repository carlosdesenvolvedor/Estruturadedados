#include <stdio.h>
#include <stdlib.h>

//pode se colocar varios tipos dentro da minha estrutura.
typedef struct{
    int idade;
    char sexo;
    char nome[100];

}Aluno;

int main(){

Aluno aluno;
    aluno.nome[0] = 'C';
    aluno.nome[1] = 'a';
    aluno.nome[2] = 'r';
    aluno.nome[3] = 'l';
    aluno.nome[4] = 'o';
    aluno.nome[5] = 's';

    aluno.idade =10;
    aluno.sexo = 'M';
    printf("nome: ");
    for(int i = 0; i<6;i++){
        printf("%c",aluno.nome[i]);
    }
    printf("\nidade: %d",aluno.idade);
    printf("\nSexo: %c\n",aluno.sexo);


    
    
    
    
    return 0;

}