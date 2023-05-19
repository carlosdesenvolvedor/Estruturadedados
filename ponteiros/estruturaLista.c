#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
    int tam; //opcional
}Lista;
//inserção no inicio da lista
void inserirInicio(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No)); //precisa ser ponteiro para não perder quando o procedimento terminar.
    novo->valor = valor; //recebe o segundo parâmetro...a região de memória apontada por novo recebe o novo conteudo.
    novo->proximo = lista->inicio; //para adicionar o nó no inicio da lista
    lista->inicio = novo;  //o inicio da lista aponta para o endereço do nó novo que acabei de criar,  lista é um ponteiro para o nó, vai receber o novo que é o nó recem alocado.
    lista->tam++;//opcional


}

//Inserir no final da lista
void inserirFim(Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    No *no = (No*)malloc(sizeof(No));

    novo->valor = valor;
    novo->proximo = NULL;
    if(lista->inicio == NULL){ //se a lista estiver vazia..
        lista->inicio = novo;
        

    }
    else{
        no = lista->inicio;  //para adicionar no fiz precisa chegar no NULL
        while (no->proximo != NULL)
        {
             no = no->proximo;
             
        }
        no->proximo = novo;
        
    }
    lista->tam++;

}


//remover um elemento da lista:
void removerInicio(Lista *lista,int valor){
    No *inicio = lista->inicio; // para percorrer esta lista procurando o elemento a ser removido.
    No *NoARemover = NULL;
    if(lista->inicio != NULL && lista->inicio->valor == valor){
        NoARemover = lista->inicio; //para não perder esse nó, 
        lista->inicio = NoARemover->proximo;
    }else{
        while(inicio!= NULL && inicio->proximo != NULL && inicio->proximo->valor != valor){
           inicio = inicio->proximo;
        }
    if(inicio!= NULL && inicio->proximo != NULL){
            NoARemover = inicio->proximo;
            inicio->proximo = NoARemover->proximo;
        }
    }
    if(NoARemover){
        free(NoARemover);
        lista->tam--;
    }
}

//Imprimir lista
void imprimir(Lista *lista){
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n",lista->tam);
    while(inicio != NULL){ //se minha lista não for vazia...
        printf("%d ",inicio->valor);
        inicio = inicio->proximo;
        
    }
    printf("\n\n");
}


int main(){
    Lista lista;
    lista.inicio = NULL;
    lista.tam = 0;
    int opcao, valor;
    do{
        printf("1 - inserir no inicio\n2 - imprimir\n3- inserir no fim\n4 - Remover\n5 - Sair\n");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                printf("Digite o valor a ser inserido no inicio:\n");
                scanf("%d",&valor);
                inserirInicio(&lista,valor);
                break;
            case 2:
                imprimir(&lista);
                break;
        
            case 3: 
                printf("Digite o valor a ser inserido no fim:");
                scanf("%d",&valor);
                inserirFim(&lista,valor);
                break;
            case 4:
                printf("Digite o valor a ser removido:\n");
                scanf("%d",&valor);
                removerInicio(&lista,valor);
                break;
            case 5:
                printf("Finalizando...\n");
            break;
            default:
                printf("opcao invalida");
        }
    }while (opcao != 5);
   
    

    return 0;
}
