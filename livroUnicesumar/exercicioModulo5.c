#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Crie um programa que leia uma variável e crie dois vetores dinâmicos, um com
o tamanho lido e outro com o dobro desse tamanho. Preencha esses vetores
respectivamente com potências de 2 e potências de 3.*/

int main() {
   int tam;
   int *vetor;
   int *tres;
   printf("Escolha o tamanho do vetor: ");
   scanf("%d",&tam);
   vetor = (int *)malloc(sizeof(int));
   tres = (int *)malloc(sizeof(int));
   printf("\nElevado a dois\n");
   for (int i = 0; i < tam; i++) {
      vetor[i] = pow(2 ,i);
      tres[i] = pow(3,i);
      printf ("Posicao %d ^2: %d\n", i, vetor[i]);
      printf ("Posicao %d ^3: %d\n", i, tres[i]);
   }
      

   return 0;
}