#include <stdio.h>
int main(){
        float c = 3.14;
        float *pc = &c;
        printf("Endereco de c: %x.\n", &c);
        pc++;
        printf("Endereco para o qual pr aponta: %x.\n", pc);
}
