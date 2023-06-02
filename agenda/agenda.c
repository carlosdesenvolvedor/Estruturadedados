#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;
void imprimir(Contato **c, int quant){  //guarda endereço para contatos 
    printf("\n\t\tLIsta de Contatos:\n");
    printf("\t------------------------------------------\n");
    for(int i = 0;i<quant;i++){
        printf("\t%d = %2d/%2d/%2d \t%s\n",i+1,c[i]->dia,c[i]->mes,c[i]->ano,c[i]->nome);        
        printf("\t------------------------------------------\n");


    }

}
int cadastrar_contato(Contato **c,int quant,int tam){
    if(quant<tam){//se a quantidade de cadastro for menor que a quantidade do meu vetor


    }else{
        printf("Impossivel novo cadastro, vetor cheio;");
        return 0;
    }
}

int main(){
    //vetor de
    Contato *agenda[50];
    int tam = 50, quant = 0; //quantidade estática de dadastrar contatos
    imprimir(agenda,quant);

    return 0;
}

