#include <stdio.h>
#include <stdlib.h>

   /*REGISTROS
O registro é uma coleção de variáveis e, por ser uma estrutura heterogênea, permite o armazenamento de informações de tipos diferentes. Ele possibilita que o
programador crie tipos de dados específicos e personalizados.
A declaração de um registro se dá pela palavra reservada struct, seguida pelo
conjunto de elementos que o compõem. Veja um exemplo de um registro chamado fraction, que possui três elementos: numerator, denominator e value.*/
    
    struct fraction{
        int numerator;
        int denominator;
        float value;
    };


int main(){
    printf("#####  REVISÃO LINGUAGEM C #######\n");
    /*A declaração de um vetor na linguagem C é muito simples, basta declarar uma
variável e colocar o seu tamanho entre colchetes logo após o nome. Pense no
vetor como uma matriz de uma única linha e quantidade de colunas equivalente ao seu tamanho. O vetor é uma estrutura homogênea, por isso só pode
armazenar um único tipo de dado. Exemplo da declaração em linguagem C de
um vetor chamado dados com capacidade para armazenar 5 valores inteiros:*/
    int dados[5];
    /*Na linguagem C, o índice dos vetores e matrizes começa no valor 0 e vai até
n - 1, em que n é o tamanho do vetor. No exemplo citado, para acessar a primeira
posição da variável dados, usa-se o índice 0, e a última, o índice 4.*/
    dados[0]; //primeira posição do vetor dados
    dados[1]; //segunda posição 
    dados[2];
    dados[3];
    dados[4]; // quinta e última posição

    //Exercicio: atribua os valores respectivamente para o vetor dados: 
    //10, 20, 88, 90, 50 imprima na tela para o usuario usando um for: 
    dados[0] = 10;
    dados[1] = 20;
    dados[2] = 88;
    dados[3] = 90;
    dados[4] = 50;

    printf("******* Exercicio 1 VETOR: **********\n");
    for(int i=0;i<5;i++){
        printf("posição %d: %d /",i,dados[i]);
    }
    printf("\n--------------- FIM VETOR --------------------\n\n\n");

/*As matrizes possuem pelo menos duas dimensões. A declaração é parecida com a de vetores, precisando indicar também a quantidade de linhas além
da quantidade de colunas. A seguir, o exemplo da declaração de uma matriz de
números reais, com duas linhas e três colunas. */
float matriz[2][3];
//Lembre-se que são necessários dois índices para acessar os dados em uma
//matriz bidimensional.

matriz[0][0]; //primeira linha, primeira coluna
matriz[0][1]; //primeira linha, segunda coluna
matriz[1][2]; //Segunda e última linha, terceira e última coluna

/*Preencha os vetores da seguinte madeira 1.2 1.6 1.7
                                          2.4 5.8 1.5
    Depois imprima na tela.
*/
printf("******** Exercicio 2 MATRIZ: **********\n");
matriz[0][0] = 1.2;
matriz[0][1] = 1.6;
matriz[0][2] = 1.7;
matriz[1][0] = 2.4;
matriz[1][1] = 5.8;
matriz[1][2] = 1.5;
//i começa com 0 dai j vai de 0 a 2, no caso 3 colunas
//depois i vai para 1, dai j varia novamente de 0 a 2.
for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
        printf("%.2f ",matriz[i][j]);
    }
    printf("\n");

}
    printf("\n--------------- FIM MATRIZ --------------------\n\n\n");

    printf("****************** STRUCT ****************\n");   
    //STRUCT
    /*Após declarado o registro, o seu uso se dá como tipo de variável, assim como
usado para inteiros, reais, caracteres etc. Cada elemento do registro é acessado
por meio de uma referência composta pelo nome_da_variável.nome_do_elemento.*/
    struct fraction metade; // cria uma variável do tipo fraction
    metade.numerator = 10; //atribui valor ao elemento neumerator
    metade.denominator = 2; //atribui valor ao elemtno denominator
    metade.value = metade.numerator / metade.denominator;
    printf("\nnumerador: %d\ndenumerador: %d\n",metade.numerator,metade.denominator);
    printf("\nmetade.value = %.2f\n",metade.value);
    /*É possível criar vetores e matrizes para acomodar múltiplos registros. Vamos
definir um registro chamado livro para armazenar quatro notas e depois vamos
    criar um vetor para armazenar as notas de 40 alunos.*/
    struct livro{
        float nota1;
        float nota2;
        float nota3;
        float nota4;
    };
    struct livro alunos_notas[40];
    alunos_notas[0].nota1 = 9.8;
    alunos_notas[1].nota1 = 9.8;
    alunos_notas[2].nota1 = 9.8;
    alunos_notas[3].nota1 = 9.9;
    alunos_notas[4].nota1 = 10;

    
    printf("\n----------- Notas 1 dos alunos: -----------\n");
    for(int i=0;i<5;i++){
        printf("aluno %d: nota: %.2f\n",i, alunos_notas[i].nota1);
    }
   
    alunos_notas[0].nota2 = 8.8;
    alunos_notas[1].nota2 = 8.8;
    alunos_notas[2].nota2 = 8.8;
    alunos_notas[3].nota2 = 7.9;
    alunos_notas[4].nota2 = 8;

    
    printf("\n-----------Notas 2 dos alunos: -----------\n");
    for(int i=0;i<5;i++){
        printf("aluno %d: nota: %.2f\n",i, alunos_notas[i].nota2);
    }
    printf("\n----------- FIM STRUCT-----------------\n\n\n");
    
    /*PONTEIROS
Uma variável é um objeto que representa um espaço reservado na memória.
Quando escolhemos o tipo da variável, estamos definindo o tamanho de bytes
que ela terá e as regras de como seus bits serão lidos, conforme foi discutido no
início deste livro.
Um inteiro tem 4 bytes (32 bits), assim como um
número real, só que no número inteiro positivo todos os
bits são significativos, enquanto na variável de ponto
flutuante só os primeiros 24 representam valor,
os últimos 8 determinam a posição da casa
decimal no número.
Por isso, quando encontramos
uma variável de 4 bytes alocada
na memória, precisamos saber qual
o seu tipo para fazer a sua correta leitura.
Ao invés de obter o valor armazenado numa variável, podemos opcionalmente obter o seu endereço na memória. 
Por exemplo, criamos uma variável x
do tipo inteiro; para saber qual o seu endereço, usamos a notação &x.
 Isso significa que &x é um ponteiro que aponta para o endereço da variável x na memória.
Também é possível usar um ponteiro como tipo de dado na declaração de
uma variável, só que nesse caso ele não irá guardar um valor, mas sim uma posição na memória. 
Vejamos agora exemplos de criação de variáveis e ponteiros:
    */
   int xi;
   int *ptr_xi;

   float xf;
   float *ptr_xf;

   char xc;
   char *ptr_xc;
/*A variável xi é do tipo inteiro e ptr_xi é um ponteiro que aponta para uma variável do tipo inteiro. A mesma relação existe para xf e ptr_xf, só que no caso deles
é para armazenar um valor de ponto flutuante e um ponteiro para uma variável
do tipo ponto flutuante. Por último, xc é uma variável do tipo caractere e ptr_xc,
um ponteiro para um caractere.
Segundo Tenenbaum (1995, p. 29), “[...] um ponteiro é como qualquer outro
tipo de dado em C. O valor de um ponteiro é uma posição na memória da mesma
forma que o valor de um inteiro é um número. Os valores dos ponteiros podem
ser atribuídos como quaisquer outros valores”.
A imagem a seguir simula um espaço na memória. Na parte de cima estão os
endereços e, na de baixo, os valores contidos naquelas posições. Essa ilustração
ajuda a entender melhor o conceito de ponteiro e a sua relação com uma variável.
Como ptr_xi é um ponteiro, não posso simplesmente atribuir a ele o valor de xi,
preciso, sim, atribuir o endereço que xi ocupa na memória. Para isso, usamos a
anotação &xi, que significa “o ponteiro que aponta para o endereço na memória da variável xi”. */
   

/*Eu sei que ptr_xi contém o endereço de uma variável, mas como saber o
valor daquele objeto? Para isso, é usada a notação *ptr_xi, que significa: “o valor
da variável para qual aponta o ponteiro ptr_xi”. */

    //Exercicio: Imprima os ponteiros declarado acima:
 
         ptr_xi = &xi;
         xi = *ptr_xi;
    printf("\n---- Ponteiro -------\n");
    printf("Valor de xi: %d",xi); //contudo da variavel xi
    printf("\nValor de &xi: %p",&xi); //endereço da variavel xi
    printf("\nValor de ptr_xi: %p",ptr_xi); //conteudo do ponteiro ptr_xi é o endereço da variavel xi
    printf("\nValor de *ptr_xi: %d\n",*ptr_xi);//mostra uma copia do conteudo que tem na variavel do endereço guardado.

    ptr_xi = &xi;
    xi = *ptr_xi;

    /*Lembrando que xi é uma variável do tipo inteiro e &xi é o ponteiro que
aponta para o endereço onde xi está armazenada na memória. A variável ptr_xi
é um ponteiro para um inteiro e *ptr_xi é o valor para o qual o ponteiro ptr_xi
está apontando.
Dentro da função main(), vamos atribuir o valor 10 para xi e o valor de &xi
para ptr_xi. Em seguida, vamos chamar a função imprimir() e observar o resultado.*/
    xi = 10;
    ptr_xi = &xi;
    printf("\n---- Ponteiro depois da atribuição -------\n");
    printf("Valor de xi: %d",xi); //contudo da variavel xi
    printf("\nValor de &xi: %p",&xi); //endereço da variavel xi
    printf("\nValor de ptr_xi: %p",ptr_xi); //conteudo do ponteiro ptr_xi é o endereço da variavel xi
    printf("\nValor de *ptr_xi: %d\n",*ptr_xi);//mostra uma copia do conteudo que tem na variavel do endereço guardado.


    return 0;
}
