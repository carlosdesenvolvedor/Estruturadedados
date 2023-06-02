#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

 
int main() {
    char nome[10] ="primeiro";
    char nome2[10] ="segundo";
    strcpy(nome,nome2);

    printf("primeiro %s\nSegundo %s\n",nome,nome2);
    system("pause");
            
    return(0);
}