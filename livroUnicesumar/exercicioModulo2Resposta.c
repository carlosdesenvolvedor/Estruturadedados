#include <stdio.h>
#include <stdlib.h>
/*a) Crie uma estrutura que tenha dois atributos: cor (cadeia de caracteres) e id
(inteiro).*/

typedef struct {
    char cor[10];
    int id;
}Semaforo;
//b) Crie três variáveis com o tipo definido no item a.
 /*d) Inicialize as estruturas da seguinte forma:
• cor vermelha, id 1.
• cor amarela, id 2.
• cor verde, id 3.*/

//e) Inicialize o ponteiro apontando para a primeira variável criada
Semaforo s1 = {"vermelho", 1};
Semaforo s2 = {"Amarelo", 2};
Semaforo s3 = {"Verde",3};

//c) Crie um ponteiro do mesmo tipo
Semaforo *ptr_s; 

main() {
   ptr_s = &s1; 
/*Por meio de operações aritméticas com ponteiros, percorra a 
memória e imprima o valor de cada uma das variáveis criadas nesse programa.*/
   printf("Valor %s: id: %d",(ptr_s)->cor,(ptr_s)->id); 
   ptr_s++;
   printf("\nValor %s: id %d",(ptr_s)->cor,(ptr_s)->id);
   ptr_s++;
   printf("\nValor %s: id %d",(*ptr_s).cor,(*ptr_s).id);





    


 return(0);
}