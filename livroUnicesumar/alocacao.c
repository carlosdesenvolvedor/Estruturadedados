#include <stdio.h>
#include <stdlib.h>
main() {
    int *ptr;  //Declarou
    printf ("Endereco: %p\n\n", ptr); //imprime o endereço aleatório
    ptr = (int *) malloc(sizeof (int)); //aloca o espaço de um inteiro e imprimi
    printf ("Endereco: %p \nValor: %d\n\n", ptr, *ptr); //mostra o endereço e valor 
    *ptr = 10; //atribui um valor para o ponteiro
    printf ("Endereco: %p \nValor: %d\n\n", ptr, *ptr);//imprime o msm endereço que já tinha sido alocado, agora foi atribuido outro valor
    int x;
    x = 20;
    ptr = &x; //aponta o ptr para o endereço de x
    printf ("Endereco: %p \nValor: %d\n\n", ptr, *ptr); // imprimi endereço do valor e seu conteudo que agora é 10 em outro local.
    ptr = (int *) malloc(sizeof (int)); //aloca outro espaço para o ptr
    printf ("Endereco: %p \nValor: %d\n\n", ptr, *ptr); //O rerultado é que será alocado outra parte de memória, com conteudo diferente. 
    printf("---------------- Teste -----------------");
    int tam;
    int *vetor;
    printf ("\nEscolha o tamanho do vetor: ");
    scanf("%d", &tam);
    vetor = (int *) malloc(sizeof (int)*tam);
    for (int i = 0; i < tam; i++) {
    vetor[i] = pow(2,i);
    printf ("Posicao %d: %d\n", i, vetor[i]);
    }
    system("Pause");

 return(0);
 
}