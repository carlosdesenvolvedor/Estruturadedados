#include <stdio.h>
#include <stdlib.h>
#define tam 3
struct tipo_pilha
{
	int dados[tam];
	int ini;
	int topo;
};

int main(){
	printf("teste");
	struct tipo_pilha pilha;
	int elemento;
	void push(int elemento);
	{
		if(pilha.topo == tam){
			printf("fila cheia. \n");
			system("pause");
		}
		else{
			pilha.dados[pilha.topo] = elemento;
			pilha.topo++;
			printf("tudo ok");
		}
	}


	return 0;
}
