#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct NO{
    int dado;
    struct NO *prox;

}NO;

typedef struct LISTA{
    NO *ini;
    NO *fim;
}LISTA;

LISTA l;
//função para inserir no inicio
void insereNoinicio(int elemento){
    NO *ptr = (NO*)malloc(sizeof(NO)); //local alocado dinamicamente
    ptr->dado = elemento; //este local recebe o meu dado inserido 
    ptr->prox = NULL; //o último elemento sempre aponta para null
    if(l.ini == NULL){ //se o inicio da lista for nulo,ou seja a lista estiver vazia
        l.ini = ptr; //
    }
    else{//nesse caso vai ter um elemento que l.ini aponta, o novo elemento precisa entrar antes
        ptr->prox = l.ini; //pindurei esse elemento no inicio
    }
     l.fim = ptr; //agora o inicio está apontando para o novo primeiro elemento
}

void insersaoNofim(int elemento){
    NO *ptr = (NO*)malloc(sizeof(NO)); //eu posso checar se o dado foi alocado corretamente, fica pra proxima kkk
    ptr->dado = elemento;
    ptr->prox = NULL;

    if(l.ini == NULL){//se minha listaestiver vazia. 
        l.ini = ptr;
    }
    else{
        l.fim->prox = ptr; //aponta para novo ptr
    }
        l.fim = ptr; //o fim estava apontando para o penultimo, aqui ele atualiza e aponta para o último.
}
void imprimir(){
    NO* ptr = l.ini;
    printf("\ninicio ->");
    while(ptr != NULL){
        printf("%d ",ptr->dado);
        ptr = ptr->prox;
    }
    printf("<- Fim\n\n");
}

void menu(){
    printf("1 - Para inserir no inicio da lista\n");
    printf("2 - Para inserir no fim da lista\n");
    printf("3 - para imprimir o conteudo da lista\n");
    printf("0 - para encerrar\n");

    }






int main(){

    int op,dado;
    l.ini = NULL;
    l.fim = NULL;
    do{
        system("cls");
        menu();
        scanf("%d",&op);
        fflush(stdin);
        system("cls");
        switch (op)
        {
        case 1:
            printf("\nDigite o dado a ser inserido no inicio: ");
            scanf("%d",&dado);
            fflush(stdin);
            insereNoinicio(dado);
            system("pause");
            break;
        case 2:
        printf("\nDigite o dado a ser inserido no fim: ");
            scanf("%d",&dado);
            fflush(stdin);
            insersaoNofim(dado);
            system("pause");
            break;
        case 3:
            printf("dados coletados");
            imprimir();
            system("pause");
            break;      
        default:
            break;
        }

    }while(op != 0); 


    return 0;
}