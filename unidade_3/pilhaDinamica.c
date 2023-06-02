#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definindo a estrutura da pilha
typedef struct {
 int dado;
 struct no *proximo;
}no;
//Definindo variáveis
typedef no *ptr_no;
ptr_no pilha;
int op;
//Prototipação
void clientes_na_espera();
void menu_selecionar(int op);
void pilha_inserir(ptr_no pilha);
void pilha_remover(ptr_no pilha);
void pilha_mostrar(ptr_no pilha);
//Função Principal
int main() {
 //Inicializando máquina de números randômicos
 srand(time(NULL));
 op = 1;
 //Criando o primeiro nó da pilha
 pilha = (ptr_no) malloc(sizeof(no));
 pilha->dado = 0;
 pilha->proximo = NULL;
 //Laço principal
 while (op !=0){
 system("cls");
 clientes_na_espera();
 scanf("%d", &op);
 menu_selecionar(op);
 }
 system("Pause");
 return(0);
}
//Mostra o menu de opções
void clientes_na_espera(){
 pilha_mostrar(pilha);
 printf("\n\nEscolha uma das opcoes:\n");
 printf("1 - Inserir no final da pilha\n"); 
 printf("2 - Remover no final da pilha\n");
 printf("0 - Sair\n\n");
}
//Executa a opção escolhida no menu
void menu_selecionar(int op){
 switch (op){
 case 1:
 pilha_inserir(pilha);
 break;
 case 2:
 pilha_remover(pilha);
 break;
 }
}
//Insere um elemento no final da Pilha
void pilha_inserir(ptr_no pilha){
 while(pilha->proximo != NULL){
 pilha = pilha->proximo;
 }
 pilha->proximo = (ptr_no) malloc(sizeof(no));
 pilha = pilha->proximo;
 pilha->dado = rand()%100;
 pilha->proximo = NULL;
}
//Remove um elemento da pilha
void pilha_remover(ptr_no pilha){
 ptr_no atual;
 atual = (ptr_no) malloc(sizeof(no));
 while(pilha->proximo != NULL){
 atual = pilha;
 pilha = pilha->proximo;
 }
 atual->proximo = NULL;
}
//Desenha o conteúdo da pilha na tela
void pilha_mostrar(ptr_no pilha){
 system("cls");
 while(pilha->proximo != NULL) {
 printf("%d, ", pilha->dado);
 pilha = pilha->proximo;
 }
 printf("%d, ", pilha->dado);
}