#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Constantes:
#define tamanho 5

//Estrutura da pilha
/*a) Crie uma estrutura para a pilha de livros. Lembre-se de que ela tem que ter
um vetor para armazenar os dados (código, nome do livro e autor) e dois
números inteiros, um para controlar o início e outro o final da pilha.*/
struct tlivros{
	int codigo[tamanho]; //vetor com o tamanho do difine;
	char nomeLivro[tamanho];
	char altor[tamanho];
	int ini; //inicio da pilha
	int fim; //final da pilha
	char *ptr_nomeLivro;
	char *ptr_altor;

};
//Variáveis globais
/*b) Defina a variável que será um vetor do tipo pilha de livros*/
struct tlivros livro;
int op;
//Prototipação, funções serão feitas após a função principal;
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();
//

int main(){
	setlocale(LC_ALL, "Portuguese");

	
	op = 1;
	livro.ini = 0;
	livro.fim = 0;
	while (op != 0){
		system("cls"); //limpa tela
		pilha_mostrar();
		menu_mostrar();
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
/*c) Faça uma função de empilhamento, lembrando-se de verificar se a pilha
atingiu o tamanho máximo de livros (a mesa não aguenta muito peso)*/
void pilha_entrar(){
	if(livro.fim == tamanho){
		printf("\nA pilha está cheia, impossível empilhar!\n\n");
		system("pause");
	}
	else{
		printf("\nDigite o código do livro: ");
		scanf("%d",&livro.codigo[livro.fim]);
		printf("\nDigite o nome do livro: \n");
		fgets(livro.nomeLivro,50,stdin);
		printf("\nDigite o Altor do livro: ");
		fgets(livro.altor,50,stdin);
		livro.fim++;
	}
}
//Retirar o último elemento da pilha POP
 //Função pilha_sair(), que verifica se existem elementos na pilha e remove o
//último inserido.
/*C) Crie uma função para desempilhamento de livros. Não se esqueça de que é
necessário verificar se ainda existem livros para ser guardados.*/
void pilha_sair(){
	if(livro.ini == livro.fim){
		printf("\nA pilha está vazia, impossível desempilhar!\n\n");
		system("pause");
	}
	else{
		livro.codigo[livro.fim-1] = 0; //limpa o epaço
		livro.altor[50] = NULL;
		livro.nomeLivro[50] = NULL;
		livro.fim--; //retrocede o fim para posição enterior
	}

}
//Mostrar o conteúdo da Pilha
//Função pilha_mostrar(), que lê o conteúdo e desenha o vetor dados na tela.
/*Elabore uma função que apresente na tela a lista de todos os livros que se
encontram empilhados ao lado da recepção.*/
void pilha_mostrar(){
	int i;
	
	printf("[ ");
	for(i = 0; i< tamanho;i++){
		printf("\nCódigo: %d \n", livro.codigo[i]);
		printf("\nNome do livro: %s \n",livro.nomeLivro[i]);
		printf("\nAltor: %s\n ",livro.altor[i]);
	}
	printf("]\n\n");
}
//Mostrar o menu de opções:
//Função menu_mostrar(), que desenha na tela as opções permitidas para o usuário.
void menu_mostrar(){
	printf("\nEscolha uma opção: \n");
	printf("1 - Empilhar\n2 - Desempilhar\n0 - Sair\n\n");
}