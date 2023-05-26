#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//define o nó

typedef struct ELEMENTO{
        int data;
        struct ELEMENTO *prox;
}ELEMENTO;
 //estrutura da pilha, é um poneiro para o topo
typedef struct ESTRUTURA{
        ELEMENTO* head;
}ESTRUTURA;
 //ponteiro do tipo topo 
ESTRUTURA *e;
  
 //função empilha
 
void insere(){
    ELEMENTO* p = (ELEMENTO *) malloc(sizeof(ELEMENTO)); //cria um novo nó
    p->data = rand()%100; //preenche o nó com elemento aleatório, corrigido o %100
    p->prox = e->head;   //e->head = p; //proximo do elemento inserido recebe o endereço do topo / segundo explicação está trocado 
    e->head = p; //p.prox = e.head; //atualizar o topo, agora ele passa a apontar para o novo elemento
                
}
 
int remover_elemento(){
    ELEMENTO* p = e->head; //faço ponteiro apontar para o topo
    int data;//crio uma variavel para obter o retorno do elemento removido
    if(p != NULL){ //se p for diferente de null indica que existe alguém na pilha para ser removido.
       e->head = p->prox;  //e->head = p->next; //pilha no topo recebe o endereço do proximo elemento que será o topo.
       p->prox = NULL;  //elemento que será excluido apontara para o vazio.
       data = p->data; //data que é uma variavel colal recebe o conteúdo do elemento excluido
       free(p);//free(ptr); //corrigido, falto esse free para desalocar a memório do elemento que foi desligado da pilha. 
       return data;  //recupera o valor do dado para a função que o envocar. 
    }else{
        return -1;
    }
}


void imprimir(){
    ELEMENTO* ptr = e->head;
    printf("\ninicio ->");
    while(ptr != NULL){
        printf(" %d ",ptr->data);
        ptr = ptr->prox;
    }
    printf("<- Fim\n\n");
}   
    void menu(){
    imprimir();
    printf("1 - Para inserir na pilha\n");
    printf("2 - Para remover da pilha\n");
    printf("3 - para imprimir \n");
    printf("0 - para encerrar\n");

    }
int main() {
    e = (ESTRUTURA*)malloc(sizeof(ESTRUTURA)); // Aloca memória para a estrutura da pilha
    e->head = NULL; // Initialize the head to NULL

    int op, dado;
    srand(time(NULL)); // gerar numeros aleatoriós tempo do relógio
    printf("Este é um programa C que implementa uma pilha básica usando uma lista encadeada individualmente. Aqui está um detalhamento de como funciona:");
    printf("\n\n Aperte enter para comecar a usar sua pilha!!");
    getchar();
    menu(); // meu menu de opções

    do {
        scanf("%d", &op);
        fflush(stdin);
       
        switch (op) {
            case 1:
                insere();
                
                printf("precione enter para atualizar o topo!");
                getchar();
                system("cls");
                menu();
                break;
            case 2:
                dado = remover_elemento();
                if (dado != -1){ 
                    printf("Elemento %d removido da pilha!!\n", dado);
                    printf("precione enter para remover item do topo!");
                    getchar();
                    system("cls");
                    menu();
                    }
                else{
                    printf("A pilha está vazia!\n");
                }
                break;
            case 3:
                imprimir();
                system("pause");
                system("cls");
                menu();

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