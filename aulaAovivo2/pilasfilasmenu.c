#include <stdio.h>
#include <stdlib.h>


typedef struct NO{
    int dado;
    NO* prox;
}NO;

typedef struct PILHA{
    NO* topo;
}PILHA;

typedef struct FILA{
    NO* inicio;
    NO* fim;
}FILA;
//declarei uma variavel do dipo fila e uma do tipo pilha
FILA *f;
PILHA *p;
void menuPrimeiro();
void menuPilha();
void menuSegundo();
void empilhar(int dado);
int desempilhar();
void imprimePilha();
void enfileira(int dado);
int desenfileira();
void imprimeFila();
void menuSegundo();
void menuFila();




//função principal
int main(){
    
   
    menuPrimeiro();
  return 0;

}
void empilha(int dado){
    NO* ptr = (NO *) malloc(sizeof(NO));
    ptr->dado = dado; //recebe o dado
    ptr->prox = p->topo; //proximo recebe o edereço do topo da lista
    p->topo = ptr; //topo recebe o endereço do último elemento
}

int desempilha(){
    NO* ptr = p->topo; //recupera o que tem no topo
    int dado; //vai retornar o elemento desempilhado
    if(ptr !=NULL){
        p->topo = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        return dado;
    }
    else{
        printf("Fila vazia!!");
        getchar();
        return -1;
    }
}
void imprimePilha(){
    NO *ptr = p->topo;
    if(ptr == NULL){
        printf("PILHA VAZIA.\n");
        return;
    }else{
        printf("=== Conteudo da Pilha ===\n\n");
        printf(" TOPO-> ");
        while(ptr != NULL){
            printf("%d ",ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    }

}

void enfileira(int dado){
    NO* ptr = (NO *) malloc(sizeof(NO)); //aloca na memória
    ptr->dado = dado; //preenche o dado por parâmentro
    ptr->prox = NULL; //fazendo esse o novo apontar para null, no fim da fila
    if(f->inicio == NULL){ //a fila está vazia? se sim o novo vai estár no inicio e no final da fila...
        f->inicio = ptr; //meu fim recebe o endereço do elemento
    }else{
        f->fim->prox = ptr; //se não é o primeiro, o elemento vai para o fim da fila.
    }
    f->fim = ptr; 
}
int desenfileira(){
    NO* ptr = f->inicio;
    int dado;
    if(ptr != NULL){
        f->inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
         free(ptr);
         return dado;
    }else{
        printf("Erro!\n");
        getchar();
        return -1;
    }
}
void imprimeFila(){
    NO *ptr = f->inicio;
    if(ptr == NULL){
        printf("FILA VAZIA. \n");
    }else{
        printf("=== condeudo da fila == \n\n");
        printf(" inicio ->");
        while(ptr != NULL){
            printf("%d ",ptr->dado);
            ptr = ptr->prox;
        }
        printf(" <-Fim\n");
    }
}

void menuSegundo(){
	printf("==== PILHA ====\n");
    printf("1 - Para empilhar\n");
    printf("2 - Para desempilhar\n");
    printf("3 - Para mostrar pilha\n");
    printf("0 - para encerrar \n");
    printf("-1 - para voltar ao menu inicial\n");
    
}
void menuFila(){
	int op,dado;
	
	f = (FILA *) malloc(sizeof(FILA));
	f->inicio = NULL;
    f->fim = NULL;
	do{ 
		
    	printf("===== Fila =====\n\n");
	    printf("1 - Para enfileirar\n");
	    printf("2 - Para desefileirar\n");
	    printf("3 - Para mostrar a fila\n");
	    printf("0 - para encerrar \n");
	    printf("-1 - voltar ao menu inicial\n");
	    scanf("%d",&op);
	    switch(op){
	    	case 1:
                printf("Insira o dado da fila\n");
                scanf("%d",&dado);
                fflush(stdin);
                enfileira(dado);
                system("pause");
                system("cls");
                
                break;
            case 2:
                dado = desenfileira();
                printf("dado %d sai da fila!\n",dado);
                system("pause");
                system("cls");
                break;
            case 3:
                imprimeFila();
                system("pause");
                system("cls");
                break;
            case -1:
            	system("cls");
                menuPrimeiro();
              
                break;
            case 0:
            	printf("programa encerrado!!");
            	exit(0);
            	break;
	    	default:
                printf("opcao invalida!!");
                break;
		}
	}while(op !=0);
	
}

void menuPilha(){
	int op,dado;
	p = (PILHA *) malloc(sizeof(PILHA));
    p->topo = NULL;
	do{
       	
        menuSegundo();
        scanf("%d",&op);
        fflush(stdin);
        system("cls");
        switch(op){
             case 1:
             	printf("\ninsira o dado da pilha: ");
             	scanf("%d",&dado);
             	fflush(stdin);
                empilha(dado);
                printf("dado %d inserido no topo!\n", dado);
                system("pause");
                system("cls");
                break;
            case 2:
            	if(dado = -1){
            		printf("voce ja esta vazia");
				}else{
					
				}
                dado = desempilha();
                printf("\ndado %d desempilhado!\n",dado);
				system("pause");
				system("cls");             
                break;
            case 3:
                imprimePilha();
                system("pause");
                system("cls");
                break;
                case -1:
                	system("cls");
            		menuPrimeiro();
                	break;
             case 0:
            	printf("programa encerrado!!");
            	break;
            
            default:
                printf("opcao invalida!!");
                exit(0);
                break;

        }

        }while(op != 0);
        menuSegundo();

	
}
void menuPrimeiro(){
	int op;
	printf("==== Estrutura de dados =========");
	printf("\n1 - fila\n2 - pilha\n0 - para encerrar!\n");
	scanf("%d",&op);

	system("cls");
	if(op == 0 ){
		exit(0);
	}
	if(op > 3){
		printf("\nopcao invalida\n");
		printf("cls");
		menuPrimeiro();
		
	}
	do{ 
    switch(op){
            case 1:
                menuFila();
                break;
            case 2:
                menuPilha();
                break;
                
        }
        
        }while(op != 0);
    
	
	
}