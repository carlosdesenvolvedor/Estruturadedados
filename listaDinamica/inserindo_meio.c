#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
    int dado;
    struct endereco *prox;
}NO;

typedef struct Lista{
    //aqui vai ter o endereço do fim e do começo da lista
    NO *ini;
    NO *fim;
}Lista;
Lista lista;

//para inserir no inicio da lista...
void inserirInicio(int dado){
    //alocação para receber os dados;
    NO *novoMorador = (NO*)malloc(sizeof(NO));
    int dado;
    if(novoMorador == NULL){
        printf("nao foi possivel alocar memoria!!");
    }else{
        
       
        novoMorador->dado = dado;
        novoMorador->prox = NULL;//para o caso de ser o primeiro elemento, ele vai apontar para lugar nenhum
        
        if(lista.ini == NULL){
            lista.ini = novoMorador;
            lista.fim = novoMorador;
        }else{
           
            //se a lista.ini não estiver vazia ela aponta para algum elemento
            novoMorador->prox = lista.ini; //como já existe um morador que está no inicio da lista
                                        //eu vou entrar antes dele, então preciso receber o endereço
                                        //que o inicio tem, pois esse será o endereço
                                        //do meu proximo.
            lista.ini = novoMorador; //em seguida, eu faço o inicio da lista receber meu endereço.
        //resumindo, eu vou estar com endereço do que estáva no inicio e o inicio vai ter meu endereço.
        
        }
        
    }
}

void inserirFim(int dado){
    NO *novoMorador = (NO *)malloc(sizeof(NO));
    if(novoMorador == NULL){
        printf("Erro de alocacao");
    }else{
        novoMorador->dado = dado;
        novoMorador->prox = NULL;

        if(lista.ini = NULL){
            lista.ini = novoMorador;
            lista.fim = novoMorador;
        }else{
            lista.fim->prox = novoMorador; //faço o meu fim.prox que 
                            //possui o endereço do proximo elemento que seria NULL
                            // apontar para o novo elemento.
            lista.fim = novoMorador;
        }
        
    }

}
void imprimir(){
    NO* moradores = lista.ini;
    printf("-> ");
    while(moradores != NULL){
        printf("%d ",moradores->dado );
        moradores = moradores->prox;
    }
    printf(" <-");
}

void menu(){
    int op;
    NO presente;
    
    
    printf("1 - inserir no inicio"
           " \n2- inserir no final"
            "\n3 - sair \n");
            
            scanf("%d ",&op);
            switch (op)
            {
            case 1:
                printf("digite o valor: ");
                scanf("%d ", &presente.dado);
                inserirInicio(presente.dado);
                break;
            case 2:
                inserirFim(presente.dado);
            default:
                break;
            }
            
}


int main(){

    menu();
  
    
    
    return 0;
}