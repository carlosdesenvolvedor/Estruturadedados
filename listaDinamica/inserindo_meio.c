#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
    int dado;
    struct NO *prox;
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
    
    if(novoMorador == NULL){
        printf("nao foi possivel alocar memoria!!");
    }else{
        
       
        novoMorador->dado = dado;
        novoMorador->prox = NULL;//para o caso de ser o primeiro elemento, ele vai apontar para lugar nenhum
        
        if(lista.ini == NULL){
           
            lista.fim = novoMorador;
        }else{
           
            //se a lista.ini não estiver vazia ela aponta para algum elemento
            novoMorador->prox = lista.ini; //como já existe um morador que está no inicio da lista
                                        //eu vou entrar antes dele, então preciso receber o endereço
                                        //que o inicio tem, pois esse será o endereço
                                        //do meu proximo.
             
        }
        lista.ini = novoMorador;
        //em seguida, eu faço o inicio da lista receber meu endereço.
        //resumindo, eu vou estar com endereço do que estáva no inicio e o inicio vai ter meu endereço.
        
        
    }
}

void inserirFim(int dado){
    NO *novoMorador = (NO*)malloc(sizeof(NO));
    if(novoMorador == NULL){
        printf("Erro de alocacao");
    }else{
        novoMorador->dado = dado;
        novoMorador->prox = NULL;

        if(lista.ini = NULL){
            lista.ini = novoMorador;
    
        }else{
            lista.fim->prox = novoMorador; //faço o meu fim.prox que 
                            //possui o endereço do proximo elemento que seria NULL
                            // apontar para o novo elemento.
           
        }
         lista.fim = novoMorador;
    }

}
void imprimir(){
    NO *moradores = lista.ini;
    printf("-> ");
    while(moradores != NULL){
        printf("%d ",moradores->dado );
        moradores = moradores->prox;
    }
    printf(" <-");
}

void menu(){
      
    
    printf("\n1 - inserir no inicio"
           " \n2- inserir no final"
            "\n3 - imprimir \n0 - sair\n");
            
   
}


int main(){
    int op,dado;
    lista.ini = NULL;
    lista.fim = NULL;
    do{ 
        menu();
        scanf("%d", &op);
        fflush(stdin);
        system("cls");
        switch (op)
        {
        case 1:
            printf("Digite para inserir no inicio: \n");
            scanf("%d", &dado);
            fflush(stdin);
            inserirInicio(dado);
            system("pause");
            break;
        case 2:
            printf("Digite para inserir no final: \n");
            scanf("%d", &dado);
            fflush(stdin);
            inserirFim(dado);
            system("pause");
            break;
        case 3:
            imprimir();
            break;
        default:
            break;
            }
    }while(op !=0);

   

    return 0;
}