#include <stdio.h>
#include "ajuda.h"

int main(){

    int n1,n2,res_s,res_m;
    mensagem();
    printf("Informe o primeiro numero: ");
    scanf("%d",&n1);
    printf("Informe o segundo numero: ");
    scanf("%d",&n2);

    res_s = soma(n1,n2);
    printf("A soma de %d com %d eh: %d\n",n1,n2,res_s);
    res_m = multiplicacao(n1,n2);
    printf("A multiplicacao de %d com %d eh: %d\n",n1,n2,res_m);


    return 0;
}