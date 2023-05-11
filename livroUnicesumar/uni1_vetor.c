#include <stdio.h>
#include <stdlib.h>


int main(){
    /*A declaração de um vetor na linguagem C é muito simples, basta declarar uma
variável e colocar o seu tamanho entre colchetes logo após o nome. Pense no
vetor como uma matriz de uma única linha e quantidade de colunas equivalente ao seu tamanho. O vetor é uma estrutura homogênea, por isso só pode
armazenar um único tipo de dado. Exemplo da declaração em linguagem C de
um vetor chamado dados com capacidade para armazenar 5 valores inteiros:*/
    int dados[5];
    /*Na linguagem C, o índice dos vetores e matrizes começa no valor 0 e vai até
n - 1, em que n é o tamanho do vetor. No exemplo citado, para acessar a primeira
posição da variável dados, usa-se o índice 0, e a última, o índice 4.*/
    dados[0]; //primeira posição do vetor dados
    dados[1]; //segunda posição 
    dados[2];
    dados[3];
    dados[4]; // quinta e última posição

    //Exercicio: atribua os valores respectivamente para o vetor dados: 
    //10, 20, 88, 90, 50 imprima na tela para o usuario usando um for: 
    dados[0] = 10;
    dados[1] = 20;
    dados[2] = 88;
    dados[3] = 90;
    dados[4] = 50;
    printf("Exercicio 1: \n");
    for(int i=0;i<5;i++){
        printf("posição %d: %d /",i,dados[i]);
    }
    printf("\n--------------- FIM --------------------\n");

/*As matrizes possuem pelo menos duas dimensões. A declaração é parecida com a de vetores, precisando indicar também a quantidade de linhas além
da quantidade de colunas. A seguir, o exemplo da declaração de uma matriz de
números reais, com duas linhas e três colunas. */
float matriz[2][3];
//Lembre-se que são necessários dois índices para acessar os dados em uma
//matriz bidimensional.

matriz[0][0]; //primeira linha, primeira coluna
matriz[0][1]; //primeira linha, segunda coluna
matriz[1][2]; //Segunda e última linha, terceira e última coluna

/*Preencha os vetores da seguinte madeira 1.2 1.6 1.7
                                          2.4 5.8 1.5
    Depois imprima na tela.
*/
printf("Exercicio 2: \n");
matriz[0][0] = 1.2;
matriz[0][1] = 1.6;
matriz[0][2] = 1.7;
matriz[1][0] = 2.4;
matriz[1][1] = 5.8;
matriz[1][2] = 1.5;

for(int c=0;c<3;c++){
    
    printf("%.2f ",matriz[0][c]);
    
}
printf("\n");
for(int l=0;l<3;l++){
    
    printf("%.2f ",matriz[1][l]);
    
}
printf("\n");

    return 0;
}
