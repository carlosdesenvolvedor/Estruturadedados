#include <stdio.h>
#include <stdlib.h>
#define TAMFILA 10 

//Fila / Queue
int fila[TAMFILA] =  {0,0,0,0,0,0,0,0,0,0}; //inicializado a lista com valor 0
int head = 0; //proximo a ser atendido
int tail = 0;  //cauda guarda quantidade de elmento, último da fila

void lista_elementos(){
    printf("\n========  FILA ATUAL ==========\n");
    for(int i=0; i<TAMFILA;i++){
        printf("->");
        printf("|%d|",fila[i]);
        printf("<-");

    }
    printf("\nhead: %d\n",head);
    printf("\ntail: %d\n",tail);
    printf("\n\n");

}
void enqueue(){
    int val;
    if(tail < TAMFILA){
        //adiciona
        printf("informe o elemento para adicionar na fila: ");
        scanf("%d",&val);
        fila[tail] = val;
        tail++;
        lista_elementos();
    }else{
        //não adiciona
        printf("A fila está cheia");

    }
}
void maisUm(){
    for(int i = 0; i<tail;i++){
        
         fila[i] = fila[i+1];
                   
    }
    tail--;
    head--;
    
}

//remover
void dequeue(){
    if(head < tail){
        fila[head] = 0;
        head++;
        
        lista_elementos();
    }else{
        printf("A fila está vazia");
    }
}
void clear(){
    for(int i = 0;i < TAMFILA;i++){
        fila[i] = 0;

    }
    head = 0;
    tail = 0;

}


int main(){
    int op = 0;
    while(op != -1){
        printf("selecione a opcao: \n");
        printf("1 - para inserir\n");
        printf("2 - remover\n");
        printf("3 - listar elementos\n");
        printf("4 - limpara a fila\n");
        printf("-1 - para sair\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                maisUm();
                lista_elementos();

                break;
            case 3:
                lista_elementos();
                break;
            case 4:
                clear();
                break;
            default:
                printf("opcao invalida!!");
                break;


        }
    }

    return 0;
}