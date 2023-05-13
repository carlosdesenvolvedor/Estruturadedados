#include <stdio.h>
#include <stdlib.h>
main() {
/*1. Faça um pequeno programa para testar seus conhecimentos sobre ponteiros e
alocação dinâmica na memória. */
/*a) Defina um ponteiro do tipo inteiro*/
    int *ponteiro;
//b) Faça alocação dinâmica para o ponteiro recém-criado.
    ponteiro = (int *)malloc(sizeof(int)); 
//c) Preencha a memória com o valor 42.
    *ponteiro = 42;
//d) Imprima o endereço do ponteiro na memória e o valor contido nele.*/
    printf("\nEndereco: %p/nValor:%d",ponteiro,*ponteiro);
 return(0);
}