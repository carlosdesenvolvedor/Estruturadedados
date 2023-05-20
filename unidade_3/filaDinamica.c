#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definindo a estrutura da fila
typedef struct no {
 int dado;
 struct no *proximo;
}no;
//Definindo variáveis
typedef no *ptr_no;
ptr_no fila;
int op;
//Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void fila_inserir(ptr_no fila);
void fila_remover(ptr_no fila);
void fila_mostrar(ptr_no fila);
//Função Principal
int main() {
 //Inicializando máquina de números randômicos
 srand(time(NULL));
 op = 1;
 //Criando o primeiro nó da fila
 fila = (ptr_no) malloc(sizeof(no));
 fila->dado = 0;
 fila->proximo = NULL;
 //Laço principal
 while (op !=0){
 system("cls");
 menu_mostrar();
 scanf("%d", &op);
 menu_selecionar(op);
 }
 system("Pause");
 return(0);
}
//Mostra o menu de opções
void menu_mostrar(){
 fila_mostrar(fila);
 printf("\n\nEscolha uma das opcoes:\n");
 printf("1 - Inserir no final da fila\n");
 printf("2 - Remover no inicio da fila\n");
 printf("0 - Sair\n\n");
}
//Executa a opção escolhida no menu
void menu_selecionar(int op){
 switch (op){
 case 1:
 fila_inserir(fila);
 break;
 case 2:
 fila_remover(fila);
 break;
 }
}
//Insere um elemento no final da fila
void fila_inserir(ptr_no fila){
 while(fila->proximo != NULL){
 fila = fila->proximo;
 }
 fila->proximo = (ptr_no) malloc(sizeof(no));
 fila = fila->proximo;
 fila->dado = rand()%100;
 fila->proximo = NULL;
}
//Remove um elemento do início da fila
void fila_remover(ptr_no fila){
 ptr_no atual;
 atual = (ptr_no) malloc(sizeof(no));
 atual = fila;
 if (fila->proximo != NULL){
 fila = fila->proximo;
 atual->proximo = fila->proximo;
 }
}
//Desenha o conteúdo da fila na tela
void fila_mostrar(ptr_no fila){
 system("cls");
 while(fila->proximo != NULL) {
 printf("%d, ", fila->dado);
 fila = fila->proximo;
 }
 printf("%d, ", fila->dado);
}