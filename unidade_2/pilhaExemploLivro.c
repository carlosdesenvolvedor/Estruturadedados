#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Constantes:
#define tamanho 5

//Estrutura da pilha
struct tpilha{
	int dados[tamanho]; //vetor com o tamanho do difine;
	int ini; //inicio da pilha
	int fim; //final da pilha

};
//Variáveis globais
struct tpilha pilha;
int op;
//Prototipação, funções serão feitas após a função principal;
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void clientes_na_espera();
//

int main(){
	setlocale(LC_ALL, "Portuguese");
	op = 1;
	pilha.ini = 0;
	pilha.fim = 0;
	while (op != 0){
		system("cls"); //limpa tela
		pilha_mostrar();
		clientes_na_espera();
		scanf("%d",&op);
		switch (op)
		{
		case 1:
			pilha_entrar();
			break;
		case 2:
			pilha_sair();
			break;
		default:
			break;
		}
	}
	


	return 0;
}
//Adicionar um elemtno no final da Pilha: push
//Função pilha_entrar(), que faz checagem do topo da pilha e insere novos valores no vetor dados.
void pilha_entrar(){
	if(pilha.fim == tamanho){
		printf("\nA pilha está cheia, impossível empilhar!\n\n");
		system("pause");
	}
	else{
		printf("\nDigite o valor a ser empilhado: ");
		scanf("%d",&pilha.dados[pilha.fim]);
		pilha.fim++;
	}
}
//Retirar o último elemento da pilha POP
 //Função pilha_sair(), que verifica se existem elementos na pilha e remove o
//último inserido.
void pilha_sair(){
	if(pilha.ini == pilha.fim){
		printf("\nA pilha está vazia, impossível desempilhar!\n\n");
		system("pause");
	}
	else{
		pilha.dados[pilha.fim-1] = 0; //limpa o epaço
		pilha.fim--; //retrocede o fim para posição enterior
	}

}
//Mostrar o conteúdo da Pilha
//Função pilha_mostrar(), que lê o conteúdo e desenha o vetor dados na tela.
void pilha_mostrar(){
	int i;
	printf("[ ");
	for(i = 0; i< tamanho;i++){
		printf("%d ", pilha.dados[i]);
	}
	printf("]\n\n");
}
//Mostrar o menu de opções:
//Função menu_mostrar(), que desenha na tela as opções permitidas para o usuário.
void clientes_na_espera(){
	printf("\nEscolha uma opção: \n");
	printf("1 - Empilhar\n2 - Desempilhar\n0 - Sair\n\n");
}