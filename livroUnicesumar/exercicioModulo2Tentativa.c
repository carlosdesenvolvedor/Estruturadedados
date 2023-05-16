#include <stdio.h>
#include <stdlib.h>
/*a) Crie uma estrutura que tenha dois atributos: cor (cadeia de caracteres) e id
(inteiro).*/

typedef struct {
    char cor;
    int id;
}Semaforo;
//b) Crie três variáveis com o tipo definido no item a.
Semaforo Vermelho;
Semaforo Amarelo;
Semaforo Verde;
//c) Crie um ponteiro do mesmo tipo
Semaforo *ptr_semaforo; 

main() {
    /*d) Inicialize as estruturas da seguinte forma:
• cor vermelha, id 1.
• cor amarela, id 2.
• cor verde, id 3.*/
    Vermelho.id = 1;
    Amarelo.id = 2;
    Verde.id = 3;
//e) Inicialize o ponteiro apontando para a primeira variável criada

    
    
/*Por meio de operações aritméticas com ponteiros, percorra a 
memória e imprima o valor de cada uma das variáveis criadas nesse programa.*/
    ptr_semaforo = &Vermelho.id; 
    printf("\nValor vermelho:%d \n",*ptr_semaforo);
    ptr_semaforo = &Amarelo.id;
    printf("\nValor Amarelo:%d \n",*ptr_semaforo);
    ptr_semaforo = &Verde.id;
    printf("\nValor verde:%d \n",*ptr_semaforo);

    


 return(0);
}