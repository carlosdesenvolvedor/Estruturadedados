#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__         
    #include <unistd.h>
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32) 

   #define OS_Windows

   #include <windows.h>

#endif
void limpar(){
    #ifdef OS_Windows
    /* Codigo Windows */
        system("cls");  
    #else
    /* Codigo GNU/Linux */
        system("clear");
       

    #endif  
}
void limpeChar(){
      #ifdef OS_Windows
    /* Codigo Windows */
        fflush(stdin);
    #else
    /* Codigo GNU/Linux */
        getchar();
    #endif 
}
void pause(){
          #ifdef OS_Windows
    /* Codigo Windows */
        system("pause");
    #else
    /* Codigo GNU/Linux */
        printf("Aperque qualquer botão para continuar...");
        getchar();
    #endif 
}

int main(int argc, char *argv[]) 
{
    printf("ola mundo\n");
    Win_Lin();
    
  
}