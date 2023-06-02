#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Constantes:
#define tamanho 5
void flush_in(){
	int ch;
	do{
		ch = fgetc(stdin);
	}while(ch !=EOF && ch != '\n');
}

//Estrutura da pilha
/*a) Crie uma estrutura para a pilha de livros. Lembre-se de que ela tem que ter
um vetor para armazenar os dados (código, nome do livro e autor) e dois
números inteiros, um para controlar o início e outro o final da pilha.*/
struct tlivros{
	int codigo; //vetor com o tamanho do difine;
	char nomeLivro[50];
	char autor[50];
 
};
struct tpilha{
	struct tlivros dados[tamanho];
	int ini;
	int fim;
};
//Variáveis globais
/*b) Defina a variável que será um vetor do tipo pilha de livros*/
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
		system("clear"); //limpa tela
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
/*c) Faça uma função de empilhamento, lembrando-se de verificar se a pilha
atingiu o tamanho máximo de livros (a mesa não aguenta muito peso)*/
void pilha_entrar(){
	if(pilha.fim == tamanho){
		printf("\nA pilha está cheia, impossível empilhar!\n\n");
		system("pause");
	}
	else{
		printf("\nDigite o código do livro: ");
		scanf("%d",&pilha.dados[pilha.fim].codigo);
		flush_in();
		printf("\nDigite o nome do livro: ");
		fgets(pilha.dados[pilha.fim].nomeLivro,50,stdin);
		printf("\nDigite o Autor do livro: ");
		fgets(pilha.dados[pilha.fim].autor,50,stdin);
		pilha.fim++;
	}
}
//Retirar o último elemento da pilha POP
 //Função pilha_sair(), que verifica se existem elementos na pilha e remove o
//último inserido.
/*C) Crie uma função para desempilhamento de livros. Não se esqueça de que é
necessário verificar se ainda existem livros para ser guardados.*/
void pilha_sair(){
	if(pilha.ini == pilha.fim){
		printf("\nA pilha está vazia, impossível desempilhar!\n\n");
		system("pause");
	}
	else{
		pilha.dados[pilha.fim-1].codigo = 0; //limpa o epaço
		strcpy(pilha.dados[pilha.fim-1].nomeLivro,"");
		strcpy(pilha.dados[pilha.fim-1].autor,""); //revisar cópia de strings
		pilha.fim--; //retrocede o fim para posição enterior
	}

}
//Mostrar o conteúdo da Pilha
//Função pilha_mostrar(), que lê o conteúdo e desenha o vetor dados na tela.
/*Elabore uma função que apresente na tela a lista de todos os livros que se
encontram empilhados ao lado da recepção.*/
void pilha_mostrar(){
	int i;
	
	
	for(i = 0; i< tamanho;i++){
		printf("------------- livro %d --------\n",i+1);
		printf("código: %d\nlivro: %sautor: %s\n", pilha.dados[i].codigo,pilha.dados[i].nomeLivro,pilha.dados[i].autor);
		printf("-------------- FIM ------------\n");
	}
	printf("\n\n");
}
//Mostrar o menu de opções:
//Função menu_mostrar(), que desenha na tela as opções permitidas para o usuário.
void clientes_na_espera(){
	printf("\nEscolha uma opção: \n");
	printf("1 - Empilhar\n2 - Desempilhar\n0 - Sair\n\n");
}