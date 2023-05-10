#include <stdio.h>
#include <stdlib.h>

//Constante que define o tamanho máximo da estrutura de dados:
#define tamanho 3
//Decvlaração do tipo_pilha: estrutura de dados
typedef struct tipo_pilha{
    int dados[tamanho]; //um vetor
    int ini;
    int topo; //topo para controlar entradas e saidas.
}tipo_pilha;

//Criando uma variável tipo_pilha
tipo_pilha pilha;

//Função Que empilha um novo elemento no topo:
void empilha(int elemento){
    //Verificando se existe alguma posição disponível para uma inserção
    if(pilha.topo == tamanho){
        //Se a pilha estiver cheia, não é possível empilhar
        printf("Pilha cheia\n");
        system("pause");
    }
    else{
        //Se a pilha não estiver cheia:
        //Adicione o novo elemento no topo
        //Incremente o topo
        pilha.dados[pilha.topo] = elemento;
        pilha.topo++;

    }
}
int main(){

    printf("Empilhando o 10\n");
    empilha(10);
    printf("Empilhando o 20\n");
    empilha(20);
}