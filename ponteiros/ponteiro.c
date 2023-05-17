#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;  
}No;
//incerção no inicio
No* inserir(No *inicio,int x){//No *inicio érecebe como parâmetro o inicio da lista. O int x é o valor
                         //que vamos receber para fazer a inserção;
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = x;
        novo->proximo = inicio;
    }
    return novo;

}
void imprimir(No *inicio){
    if(inicio){
        printf("%d ",inicio->valor);
        imprimir(inicio->proximo); //função recurciva.
    }
}

int main(){

    No *lista = NULL;

    lista = inserir(lista, 10);
    lista = inserir(lista, 50);
    lista = inserir(lista, 100);
    imprimir(lista);
    

    return 0;
}