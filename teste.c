#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//define o nó
typedef struct ELEMENTO {
    int data;
    struct ELEMENTO* prox;
} ELEMENTO;
 //estrutura da pilha, é um poneiro para o topo
typedef struct ESTRUTURA {
    ELEMENTO* head;
} ESTRUTURA;
 //ponteiro do tipo topo 
ESTRUTURA* e;

 //função empilha

void insere() {
    ELEMENTO* p = (ELEMENTO*)malloc(sizeof(ELEMENTO));  //cria um novo nó
    p->data = rand() % 100; //preenche o nó com elemento aleatório, corrigido o %100 ###erro1###
    p->prox = e->head; ////proximo do elemento inserido recebe o endereço do topo / segundo explicação está trocado 
    e->head = p; // Update the head to point to the new element
}

int remove_element() {
    ELEMENTO* p = e->head; //faço ponteiro apontar para o topo
    int data; //crio uma variavel para obter o retorno do elemento removido
    if (p != NULL) {  //se p for diferente de null indica que existe alguém na pilha para ser removido.
        e->head = p->prox; //pilha no topo recebe o endereço do proximo elemento que será o topo.
        data = p->data;
        free(p); // Free the memory allocated for the removed element
        return data;
    }
    return -1; /*Retorna um valor sentinela para indicar falha (por exemplo, quando a pilha está vazia)*/
}

void imprimir() {
    ELEMENTO* ptr = e->head;
    printf("\nInicio ->");
    while (ptr != NULL) {
        printf(" %d", ptr->data);
        ptr = ptr->prox;
    }
    printf(" <- Fim\n\n");
}

void menu() {
    printf("1 - Para inserir na pilha\n");
    printf("2 - Para remover da pilha\n");
    printf("3 - Para imprimir a pilha\n");
    printf("0 - Para encerrar\n");
}

int main() {
    e = (ESTRUTURA*)malloc(sizeof(ESTRUTURA)); // Aloca memória para a estrutura da pilha
    e->head = NULL; // Initialize the head to NULL

    int op, dado;
    srand(time(NULL)); // gerar numeros aleatoriós tempo do relógio

    menu(); // meu menu de opções

    do {
        scanf("%d", &op);
        fflush(stdin);

        switch (op) {
            case 1:
                insere();
                break;
            case 2:
                dado = remove_element();
                if (dado != -1)
                    printf("Elemento removido: %d\n", dado);
                else
                    printf("A pilha está vazia!\n");
                break;
            case 3:
                imprimir();
                break;
            case 0:
                break;
            default:
                printf("Digite uma opção válida!\n");
                break;
        }
    } while (op != 0);

    return 0;
}