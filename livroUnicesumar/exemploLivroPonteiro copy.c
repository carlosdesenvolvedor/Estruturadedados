#include <stdio.h>
#include <stdlib.h>
int xi;
int *ptr_xi;


void imprimir() {
 printf("Valor de xi = %d \n", xi);
 printf("Valor de &xi = %p \n", &xi);
 printf("Valor de ptr_xi = %p \n", ptr_xi);
 printf("Valor de *ptr_xi = %d \n\n", *ptr_xi);
}
int main(){
    ptr_xi = &xi;
    xi = *ptr_xi;
    imprimir();
    return 0;
}