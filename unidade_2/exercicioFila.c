#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h> //necessário para usar localtime() e struct tm
//Constantes:
 
#define tamanho 5
void flush_in(){
	int ch;
	do{
		ch = fgetc(stdin);
	}while(ch !=EOF && ch != '\n');
}

//Estrutura da pilha
/*a) Faça uma estrutura para o controle da fila. Você precisa guardar o nome e
a hora que o cliente chegou. Use um vetor para armazenar os dados e dois
números inteiros, um para controlar o início e outro o final da fila.*/
struct tclientes{
	struct tm *data_hora_atual;
	char nome[50];
	char hora[50];
 
};
struct tfila{
	struct tclientes dados[tamanho];
	int ini;
	int fim;
};
//Variáveis globais
/*b) Defina a variável que será um vetor do tipo fila de clientes.*/
struct tfila fila;
int op;
  
//Prototipação, funções serão feitas após a função principal;
void fila_entrar();
void fila_sair();
void fila_mostrar();
void menu_mostrar();
//

int main(){
	setlocale(LC_ALL, "Portuguese");

	
	op = 1;
	pilha.ini = 0;
	pilha.fim = 0;
	while (op != 0){
		system("clear"); //limpa tela
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
/*c) Crie uma função enfileirar, lembrando que é preciso verificar se há espaço
na fila (o número de cadeiras na recepção é limitado).*/
void fila_entrar(){
	if(fila.fim == tamanho){
		printf("\nA Fila está cheia, Aguarde fora do estabelecimento!\n\n");
		system("pause");
	}
	else{
		printf("\nDigite o nome do Cliente: ");
		fgets(fila.dados[fila.fim].nome,50,data);
		fila.dados[fila.fim].hora = {data_hora_atual};
		fgets(fila.dados[fila.fim].hora,50,stdin);
		printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora   
		printf("%d:",data_hora_atual->tm_min);//minuto
		printf("%d\n",data_hora_atual->tm_sec);//segundo
		fila.fim++;
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
void menu_mostrar(){
	printf("\nEscolha uma opção: \n");
	printf("1 - Empilhar\n2 - Desempilhar\n0 - Sair\n\n");
}