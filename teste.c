#include <stdio.h>
#include <stdlib.h>

typedef struct ELEMENTO{
        int data;
        struct ELEMENTO *prox;
}ELEMENTO;
 
typedef struct ESTRUTURA{
        ELEMENTO* head;
}ESTRUTURA;
 
ESTRUTURA *e;
 
void insere(){
        ELEMENTO* p = (ELEMENTO *) malloc(sizeof(ELEMENTO));
        p->data = rand() % 100;
        p->next = e->head;
        e->head = p;
}
 
int remove(){
        ELEMENTO* p = e->head;
        int data;
        if(p != NULL){
                        e->head = p->next;
                        p->next = NULL;
                        data = p->data;
                        return data;
        }else{
                return -1;
        }
}
void imprimir(){
    ELEMENTO* ptr = e->head ;
    printf("\ninicio ->");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("<- Fim\n\n");
}
    void menu(){
    printf("1 - Para inserir na pilha\n");
    printf("2 - Para remover da pilha\n");
    printf("3 - para imprimir \n");
    printf("0 - para encerrar\n");

    }
int main(){
        
    int op,dado;
    e->head = NULL;
    
    do{
        system("cls");
        menu();
        scanf("%d",&op);
        fflush(stdin);
        system("cls");
        switch (op)
        {
        case 1:
            printf("\nDigite o dado para ser empilhado: ");
            scanf("%d",&dado);
            fflush(stdin);
            insere(dado);
            system("pause");
            break;
        case 2:
        printf("\nremovendo da pilha: ");
            dado = remove(); 
            if(dado == -1){
                printf("Erro\n");
                system("pause");
            }else{
                printf("Removendo o elemento %d do inicio da lista.\n",dado);
                system("pause");
            }
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