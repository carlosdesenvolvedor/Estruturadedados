#include <stdio.h>


int main(){

    FILE *arq;

    arq = fopen("arquivo.txt","w");//recebe dois parametros, nome do arquivo e forma de abertura do arquivo
    //w = abrir para escrita. Se arquivo não existir ele será criado
    //caso ele já exista, ele será sobrescrito.
    //r = abrir o arquivo para leitura, nesse caso não podemos escrever no arquivo.
    //wa = abrir o arquivo para adição de conteudo. Se arquivo já existir o conteudo será adicionado nas linhas abaixo.

    //Sempre que a gente finalizar a manipulação de um arquivo devemos fecha-lo
    fclose(arq);
    
        printf("Ola mundo!");


    return 0;
}