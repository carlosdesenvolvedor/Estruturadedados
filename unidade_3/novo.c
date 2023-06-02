#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*para criar uma lista dinânima é a estrutura do nó
Ela terá dois elemntos:*/
typedef struct{
    int dado;//aqui pode ter varios elementos, mas pelo menos 1
    struct no *proximo; // cria um tipo ponteiro da struct
        //nó que apontara para o proximo nó.
}no;
//Após a criação da struct criaremos um ponteiro do tipo nó;
//que será necessário para fazer a alocação dinâmica na memória para 
//cada novo elemento da lista.
typedef no *ptr_no; //o tipo no agora tem o nome de *ptr_no
//variável que irá apontar para o início da lista.
//A partir dela poderemos navegar do primeiro ao último elemento
//fazer remoções e inserções.
ptr_no lista;// aponta para início
int op;
/*A variável do tipo ponteiro lista foi criada para apontar para 
a nossa lista encadeada. Como ela ainda não existe, vamos criar o
primeiro nó com o atributo dado valendo 0 
e o ponteiro proximo apontando para null:*/
//prototipo
void clientes_na_espera();
void menu_selecinar(int op);
void lista_mostrar(ptr_no lista);
void lista_mostrar_2(ptr_no lista);
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);

int main(){
    
    //Inicializando máquina de números randômicos
    srand(time(NULL));
    op = 1;
    //Criando o primereiro nó da lista
    lista = (ptr_no)malloc(sizeof(no));
    lista->dado = 0;
    lista->proximo = NULL;
    //Laço principal
    while(op != 0){
      
        clientes_na_espera();
        scanf("%d", &op);
        menu_selecinar(op);
        
    }
    system("pause");
    return 0;
}
/*Com a lista definida e devidamente inicializada, podemos criar agora a função lista_mostrar(), que iremos utilizar para desenhar na tela o conteúdo da nossa
lista dinâmica. Ela recebe como parâmetro uma variável do tipo ptr_no, que será
aquela que criamos lá no começo para apontar para o início da lista.*/

void lista_mostrar(ptr_no lista){
     //limpar tela
    while(1){
        printf("%d, ", lista->dado);
        if(lista->proximo == NULL){
            break;
        }
        lista = lista->proximo; 
    }
}
void lista_mostrar_2(ptr_no lista){
    
    while(lista->proximo !=NULL){
        printf("%d, ", lista->dado);
        lista = lista->proximo;
    }
    printf("%d, ", lista->dado); /*A repetição irá parar quando chegar ao último elemento, mas sairá do laço
antes de imprimir o valor de dado do último nó na tela. Para isso se faz necessário um comando printf adicional no final da função.*/
}
void lista_inserir(ptr_no lista){
    while(lista->proximo != NULL){
        lista = lista->proximo;
    }
    lista->proximo = (ptr_no)malloc(sizeof(no));
    lista = lista->proximo;
    lista->dado = rand()%100;//recebe um elemento
    lista->proximo = NULL;
}
void lista_remover(ptr_no lista){
    int dado;
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    printf("Escolha um dos itensd:\n");
    scanf("%d",&dado);
    while((lista->dado != dado)){
        
        if(lista->proximo == NULL){
                break;
            }
        atual = lista;
        lista = lista->proximo;
    }
    if(lista->dado == dado){
        atual->proximo = lista->proximo;
    }
    
}
//mostrar menu de opções:
void clientes_na_espera(){
    printf("\n\nEscolha uma das opções: \n");
    printf("1 - Inserir no final da Lista \n");
    printf("2 - Remover um tem da Lista \n");
    printf("0 - Sair\n\n");
}
//Executa a opção escolhida no menu:
void menu_selecinar(int op){
    switch(op){
        case 1:
            lista_inserir(lista);
            lista_mostrar_2(lista);
            break;
        case 2:
            lista_remover(lista);
            lista_mostrar_2(lista);
            break;
    }
}