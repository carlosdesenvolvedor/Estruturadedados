#include <stdio.h>
#include <stdlib.h>

//MEU NÓ
typedef struct ELEMENTO{
        int data;
        struct ELEMENTO *next;
}ELEMENTO;

//UMA LISTA PARA REFERENCIAR O TOPO
typedef struct ESTRUTURA{
        ELEMENTO* head;
}ESTRUTURA;

//NOVO DA VARIAVEL DA LISTA
ESTRUTURA *e;

//para enserir na pilha.
void menu_mostrar(){
 pilha_mostrar(e);
 printf("\n\nEscolha uma das opcoes:\n");
 printf("1 - Inserir no final da pilha\n"); 
 printf("2 - Remover no final da pilha\n");
 printf("0 - Sair\n\n");
}
int op;
void menu_selecionar(int op){
 switch (op){
    case 1:
        insere(e);
        break;
    case 2:
        remover(e);
        break;
 }
}

void insere(ELEMENTO *head){
        while(head->next != NULL){
            head = head->next;
        }
    head->next = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    head = head->next;
    head->data = rand()%100;
    head->next = NULL;
}

//para remover da pilha
int remover(ELEMENTO* head){
    ELEMENTO atual;
    atual.data = (ELEMENTO *)malloc(sizeof(ELEMENTO));
    while(head->next != NULL){
    atual.data = head;
    head = head->next;
    }
    atual.next = NULL;
}

void pilha_mostrar(ELEMENTO* head){
 system("cls");
 while(head->next != NULL) {
 printf("%d, ", head->next);
 head = head->next;
 }
 printf("%d, ", head->data);
}



int main(){
    srand(time(NULL));
    op = 1;
    //Criando o primeiro nó da pilha
    ELEMENTO* lista = (ELEMENTO *) malloc(sizeof(ELEMENTO));
    lista->data = 0;
    lista->next = NULL;
    //Laço principal
    while (op !=0){
    system("cls");
    menu_mostrar();
    scanf("%d", &op);
    menu_selecionar(op);
    }
    system("Pause");
    return(0);
    

    return 0;
}