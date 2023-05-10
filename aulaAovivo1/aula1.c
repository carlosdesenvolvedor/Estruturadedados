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
        
    }
    else{
        //Se a pilha não estiver cheia:
        //Adicione o novo elemento no topo
        //Incremente o topo
        pilha.dados[pilha.topo] = elemento;
        pilha.topo++;

    }
}
    //--------------------
    //Função que desempilha e tetorna o elemnto do topo
    int desempilha(){ 

        //Variável que guarda um "backup" do elemento desempilhado
        int elemento; 
        //Verificando se existe algum elemento disponível para uma remoção
       if(pilha.topo == pilha.ini){
        //Se a pilha estiver vazia, não será possível desempilhar
        printf("Pilha vazia.\n");
        
       }
       else{
        //Se a pilha não estiver vazia
        //Decremente o topo
        //Retorne o elemento que está no topo
        pilha.topo--;
        elemento = pilha.dados[pilha.topo];
        return elemento;
       }
    }
 
int main(){

    printf("Empilhando o 10\n");
    empilha(10);
    printf("Empilhando o 20\n");
    empilha(20);
    printf("Empilhando o 30\n");
    empilha(30);
    printf("Empilhando o 40\n");
    empilha(40);


    printf("Desempilhou: %d\n", desempilha());
    printf("Desempilhou: %d\n", desempilha());
    printf("Desempilhou: %d\n", desempilha());
    printf("Desempilhou: %d\n", desempilha());
    return 0;

}