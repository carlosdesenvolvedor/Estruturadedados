// Alocação estática:
// Reserva espaço de memória em tempo de compilação
// pode ser mais rápida, durante a execução;
// pode desperdiçar memória.

// alocação dinâmica:
// Reserva espaços de memória em tempo de execução;
// pode ser mais lenta, durante a execução.
// Otimiza o uso de memória.

#include <stdlib.h>
#include <stdio.h>

int main(){
    /*<ponteiro> = (cast: tipo de dados)*  malloc(<tam. em bytes>); */
    /*Free(libera o esaço de memória alocado a um ponteiro) free<pontiro>*/
    /*Malloc() vai vasculhar a memória e encontrar um espaço da memório*/
    
    int *p;
    p = (int *) malloc(4); /*4 pq um inteiro precisa de 4 bits*/
    
    if(p == NULL){
        printf("Erro!\n");
    }
    else{
        *p = 10;
        printf("p: %d\n", *p);
        free(p);
    } 
    

    /*Tamanhos dos tipos primitivos:
    int 4 bytes
    char 1 byte
    float 4 bytes
    Double: 8 bytes
    Bool 1 bytes
    Função sizeof(<nome_do_tipo>);
    */

    return 0;
}