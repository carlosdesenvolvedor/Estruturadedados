#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

Produto produto[100]; //array de produtos

//protótipos das funções
void salvar_produtos();
void carregar_produtos();
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
void fecharPedido();
void menu_fila();

static int contador_produto = 0; //para saber quantos protutos temos cadastrado
static int contador_carrinho = 0; //para saber quantos produtos tem no carrinho

int main(){
    carregar_produtos();
    menu();
    salvar_produtos();
    return 0;
}

//Funções relacionadas a produtos

void salvar_produtos() {
    FILE *arquivo = fopen("produtos.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!");
        return;
    }
    for (int i = 0; i < contador_produto; i++) {
        fprintf(arquivo, "%d\n", produto[i].codigo);
        fprintf(arquivo, "%s\n", produto[i].nome);
        fprintf(arquivo, "%.2f\n", produto[i].preco);
    }
    fclose(arquivo);
}

void carregar_produtos() {
    FILE *arquivo = fopen("produtos.txt", "r");
    if (arquivo == NULL) {
        return; // caso o arquivo não exista, retorna
    }
    contador_produto = 0; // zera o contador para popular o array do início
    int codigo;
    char nome[30];
    float preco;
    while (fscanf(arquivo, "%d\n", &codigo) != EOF) {
        fgets(nome, 30, arquivo);
        fscanf(arquivo, "%f\n", &preco);
        produto[contador_produto].codigo = codigo;
        strcpy(produto[contador_produto].nome, nome);
        produto[contador_produto].preco = preco;
        contador_produto++;
    }
    fclose(arquivo);
}

void cadastrarProduto(){
    printf("==== Cadastro de Produto ====\n");
    if(contador_produto >= 100){
        printf("Limite de produtos atingido.\n");
        return;
    }
    Produto novo_produto;
    printf("Código: ");
    scanf("%d", &novo_produto.codigo);
    for(int i=0; i<contador_produto; i++){
        if(novo_produto.codigo == produto[i].codigo){
            printf("Já existe um produto com esse código.\n");
            return;
        }
    }
    printf("Nome: ");
    scanf("%s", novo_produto.nome);
    printf("Preço: ");
    scanf("%f", &novo_produto.preco);
    produto[contador_produto] = novo_produto;
    contador_produto++;
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos(){
    printf("==== Produtos Cadastrados ====\n");
    for(int i=0; i<contador_produto; i++){
        printf("-----------------------------\n");
        printf("Código: %d\n", produto[i].codigo);
        printf("Nome: %s\n", produto[i].nome);
        printf("Preço: %.2f\n", produto[i].preco);
    }
}

void comprarProduto(){
    printf("Informe o código do produto: ");
    int codigo;
    scanf("%d", &codigo);
    int indice_produto = -1;
    for(int i=0; i<contador_produto; i++){
        if(codigo == produto[i].codigo){
            indice_produto = i;
            break;
        }
    }
    if(indice_produto == -1){
        printf("Produto não encontrado.\n");
        return;
    }
    produto[indice_produto].preco += produto[indice_produto].preco*0.10; //aumenta 10% do preço
    printf("Produto adicionado ao carrinho!\n");
    contador_carrinho++;
}

void visualizarCarrinho(){
    printf("==== Carrinho de Compras ====\n");
    printf("Quantidade de produtos: %d\n", contador_carrinho);
}

//Funções relacionadas ao fechamento do pedido

void fecharPedido(){
    float total = 0;
    for(int i=0; i<contador_produto; i++){
        total += produto[i].preco;
    }
    printf("Total a pagar: R$ %.2f\n", total);
    contador_produto = 0;
    contador_carrinho = 0;
    printf("Pedido finalizado com sucesso!\n");
}

void menu_fila(){
    int opcao;
    do{
        printf("==== MENU ====\n");
        printf("1- Comprar produto\n");
        printf("2- Visualizar carrinho\n");
        printf("3- Fechar pedido\n");
        printf("0- Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1: comprarProduto(); break;
            case 2: visualizarCarrinho(); break;
            case 3: fecharPedido(); break;
            case 0: break;
            default: printf("Opção inválida.\n");
        }
    }while(opcao != 0);
}

//Função que exibe o menu principal

void menu(){
    int opcao;
    do{
        printf("==== MENU ====\n");
        printf("1- Cadastrar produto\n");
        printf("2- Listar produtos\n");
        printf("3- Acessar fila\n");
        printf("0- Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: menu_fila(); break;
            case 0: break;
            default: printf("Opção inválida.\n");
        }
    }while(opcao != 0);
}