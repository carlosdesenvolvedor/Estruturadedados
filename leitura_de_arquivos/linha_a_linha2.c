#include <stdio.h>

int main(){
    FILE *arq;
    int num, resultado, soma =0;
    arq = fopen("arquivo2.txt","r");
    if(arq){
        while(!feof(arq)){
            
            resultado = fscanf(arq, "%d", &num); //para fazer leitura do arquivo

            if(resultado == 1){ //Para não somar a linha que está vazia, ele pegaria o último número da lista.
                printf("Resultado: %d",resultado);
                soma = soma + num; 

            }
        }   

    }else{
        printf("Arquivo nao encontrado!!");
    }
    printf("A soma dos numeros do arquivo eh: %d", soma);
    fclose(arq);


    return 0;
}