#include <stdio.h>
#include <string.h>

int main(){

    char s[6] = {'c','a','r','l','o'};
    char sobre[6] = "souza";
    
    printf("Sexo:%c\nsobrenome: %s...",remove(s),sobre);
    printf("\nnome: %s",s);

    return 0;
}