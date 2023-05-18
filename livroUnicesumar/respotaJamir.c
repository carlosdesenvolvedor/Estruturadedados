#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char cor[10];
    int id;
} Semaforo;

int main() {
    Semaforo s1 = {"vermelho", 1};
    Semaforo s2 = {"Amarelo", 2};
    Semaforo s3 = {"Verde", 3};

    Semaforo *ptr_s_array[] = {&s1, &s2, &s3};
    int num_variaveis = sizeof(ptr_s_array) / sizeof(ptr_s_array[0]);

    int i;
    for (i = 0; i < num_variaveis; i++) {
        printf("Valor %s: id: %d\n", ptr_s_array[i]->cor, ptr_s_array[i]->id);
    }

    return 0;
}