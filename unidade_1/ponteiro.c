#include <stdio.h>
//para compilar no terminal, usar gcc <nomedoarquivo.c> -o <novoNome>
// revisão sobre ponteiros: quarda o endereço de momória.
int main(){

  int *p;
  int x =10;

  p = &x;
  x = *p;
  printf("p : %d \nconteudo em x: %d \nponteir:o %d \nendereço de x: %d \nMuitos acentos: ~ * , # $ não é tão índice",p,x,*p,&x);
  printf("Renovado...\n");  
  printf("Depois de compilado.\n ");
    return 0;
}