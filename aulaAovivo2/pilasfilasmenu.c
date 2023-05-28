#include <stdio.h>
#include <stdlib.h>


typedef struct NO{
    int dado;
    NO* prox;
}NO;

typedef struct PILHA{
    NO* topo;
}PILHA;

typedef struct FILA{
    NO* inicio;
    NO* fim;
}FILA;
//declarei uma variavel do dipo fila e uma do tipo pilha
FILA *f;
PILHA *p;


void empilha(int dado){
    NO* ptr = (NO *) malloc(sizeof(NO));
    ptr->dado = dado; //recebe o dado
    ptr->prox = p->topo; //proximo recebe o edereço do topo da lista
    p->topo = ptr; //topo recebe o endereço do último elemento
}

int desempilha(){
    NO* ptr = p->topo; //recupera o que tem no topo
    int dado; //vai retornar o elemento desempilhado
    if(ptr !=NULL){
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
    else{
        printf("Fila vazia!!");
        getchar();
        return -1;
    }
}

void imprimePilha(){
    NO *ptr = p->topo;
    if(ptr == NULL){
        printf("PILHA VAZIA.\n");
        return;
    }else{
        printf("=== Conteudo da Pilha ===\n\n");
        printf(" TOPO-> ");
        while(ptr != NULL){
            printf("%d ",ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    }

}

int enfileira(int dado){
    NO* ptr = (NO *) malloc(sizeof(NO)); //aloca na memória
    ptr->dado = dado; //preenche o dado por parâmentro
    ptr->prox = NULL; //fazendo esse o novo apontar para null, no fim da fila
    if(f->inicio == NULL){ //a fila está vazia? se sim o novo vai estár no inicio e no final da fila...
        f->inicio = ptr; //meu fim recebe o endereço do elemento
    }else{
        f->fim->prox = ptr; //se não é o primeiro, o elemento vai para o fim da fila.
    }
    f->fim = ptr; 
}
int desenvileira(){
    NO* ptr = f->inicio;
    int dado;
    if(ptr != NULL){
        f->inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
         free(ptr);
         return dado;
    }else{
        printf("Erro!\n");
        getchar();
        return -1;
    }
}
void imprimeFila(){
    NO *ptr = f->inicio;
    if(ptr == NULL){
        printf("FILA VAZIA. \n");
    }else{
        printf("=== condeudo da fila == \n\n");
        printf(" inicio ->");
        while(ptr != NULL){
            printf("%d ",ptr->dado);
            ptr = ptr->prox;
        }
        printf(" <-Fim");
    }
}
void menu(){
    printf("1 - Para empilhar\n");
    printf("2 - Para desempilhar\n");
    printf("3 - Para mostrar pilha\n");
    printf("4 - Para enfileirar\n");
    printf("5 - Para desefileirar\n");
    printf("6 - Para mostrar a fila\n");
    printf("0 - para encerrar \n");
}

int main(){

    return 0;
}
