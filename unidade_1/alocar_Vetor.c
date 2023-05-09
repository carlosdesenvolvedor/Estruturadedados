#include <stdio.h>
#include <stdlib.h>

int main(){

    int *vetor;
    vetor = (int *)malloc(sizeof(int)*10);
    
    if(vetor == NULL){
        printf("Erro!\n");
    }    
    else{
        *vetor = 10;
        printf("vetor: %d\n", *vetor);
        free(vetor);
    }

    return 0;
}
