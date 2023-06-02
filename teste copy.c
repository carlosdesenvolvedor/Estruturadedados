#include <stdio.h>
#include <stdlib.h>
 
struct notas {
            float bim1;
            float bim2;
            float bim3;
            float bim4;
};

 
struct notas alunos_notas[40];

 
int main() {
            
            alunos_notas[0].bim1 = 9.9;
            alunos_notas[1].bim1 = 8.9;
            alunos_notas[2].bim1 = 7.9;
            alunos_notas[3].bim1 = 6.9;
            
            for(int i =0;i<4;i++){
                printf("nota %d: %.2f\n",i,alunos_notas[i].bim1);
            }

            system("pause");
            
            return(0);
}