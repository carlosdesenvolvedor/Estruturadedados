#include <stdio.h>

int main(){
    FILE *arq;
    char nome[10], *resultado;
    arq = fopen("arquivo.txt","r");//r somente leitura

    if(arq){
        while(!feof(arq)){ //feof para fazer o loop enquanto não chegar no final do arquivo.
            
            resultado =  fgets(nome,10,arq);
            printf("Resuldado: %d\n",resultado);
            if(resultado){
                printf("%s\n",nome);

            }

        }
    }else{
        printf("arquivo nao encontrado");
    }

    fclose(arq);
    return 0;
}