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
	
	
	char nome[50];
	int hora;
	int min;
	int seg;
 
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
void enfileirar();
void desenfileirar();
void fila_mostrar();
void menu_mostrar();
//

int main(){
	setlocale(LC_ALL, "Portuguese");

	
	op = 1;
	fila.ini = 0;
	fila.fim = 0;
	while (op != 0){
		system("cls"); //limpa tela
		fila_mostrar();
		menu_mostrar();
		scanf("%d",&op);
		fflush(stdin);
		switch (op)
		{
		case 1:
			enfileirar();
			break;
		case 2:
			desenfileirar();
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
void enfileirar(){
	if(fila.fim == tamanho){
		printf("\nA Fila está cheia, Aguarde fora do estabelecimento!\n\n");
		system("pause");
	}
	else{

		printf("\nDigite o nome do Cliente: ");
		fgets(fila.dados[fila.fim].nome,50,stdin); //pega o nome do cliente atraves do teclado

		struct tm *data_hora_atual;
		time_t segundos;
 		time(&segundos);  
		data_hora_atual = localtime(&segundos);
		// printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora   
		// system("pause");
		fila.dados[fila.fim].hora = data_hora_atual->tm_hour; //pega a hora
		fila.dados[fila.fim].min = data_hora_atual->tm_min; //pega o minito atual
		fila.dados[fila.fim].seg = data_hora_atual->tm_sec; //pega o segundo atual
		
		
		// fgets(fila.dados[fila.fim].hora,50,stdin);
		// printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora   
		// printf("%d:",data_hora_atual->tm_min);//minuto
		// printf("%d\n",data_hora_atual->tm_sec);//segundo
		fila.fim++;
	}
}
//Retirar o último elemento da pilha POP
 //Função pilha_sair(), que verifica se existem elementos na pilha e remove o
//último inserido.
/*d) Elabore a função desenfileirar cliente, não se esqueça de que é necessário
verificar se ainda existem clientes para serem atendidos.*/
void desenfileirar(){
	if(fila.ini == fila.fim){
		printf("\nA fila está vazia, mas logo aparece alguém para voce trabalhar!\n\n");
		system("pause");
	}
	else{
		for(int i = 0; i<tamanho;i++){
			fila.dados[i].hora = fila.dados[i+1].hora;
			fila.dados[i].min = fila.dados[i+1].min;
			fila.dados[i].seg = fila.dados[i+1].seg;
			strcpy(fila.dados[i].nome,fila.dados[i+1].nome);

		}
		fila.dados[fila.fim].hora = 0;
		fila.dados[fila.fim].min = 0;
		fila.dados[fila.fim].seg = 0;
		strcpy(fila.dados[fila.fim].nome,"");

		fila.fim--; //retrocede o fim para posição enterior
	}

}
//Mostrar o conteúdo da Pilha
//Função pilha_mostrar(), que lê o conteúdo e desenha o vetor dados na tela.
/*e) Faça uma função que apresente na tela a lista de todos os clientes que estão
aguardando atendimento na recepção..*/
void fila_mostrar(){
	int i;
	
	
	for(i = 0; i< tamanho;i++){
		printf("-------------  %d° da fila --------\n",i+1);
		printf("nome:%s\nhorario de chegada: %d:%d:%d\n", fila.dados[i].nome,fila.dados[i].hora,fila.dados[i].min,fila.dados[i].seg);
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