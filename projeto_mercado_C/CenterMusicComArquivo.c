#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
    int codigo;
    char nome[100];
    float preco;
} Produto;

typedef struct {
    int codigo;
    char nome[100];
    float preco;
    int quantidade;
} Carrinho;

Carrinho carrinho[100];
static int contador_carrinho = 0;

Produto produto[100];
static int contador_produto = 0;
static int ultimo_codigo = 0;//aquinao
int buscarProduto(int codigo); // Declaração da função para buscar um produto pelo código.
int contarProdutos();
void salvar_produtos(); // Declaração da função para salvar os produtos no arquivo.
void carregar_produtos(); // Declaração da função para carregar os produtos do arquivo.
void menu(); // Declaração da função para exibir o menu principal.
void cadastrarProduto(); // Declaração da função para cadastrar um novo produto.
void listarProdutos(); // Declaração da função para listar os produtos cadastrados.
void comprarProduto(); // Declaração da função para adicionar um produto ao carrinho.
void visualizarCarrinho(); // Declaração da função para exibir o carrinho de compras.
void fecharPedido(); // Declaração da função para fechar o pedido e exibir o total a pagar.
void menu_fila(); // Declaração da função para exibir o menu do carrinho de compras.


int main() {
    carregar_produtos(); // Carrega os produtos do arquivo.
    contador_produto = contarProdutos(); // Obtém a quantidade de produtos existentes.
    menu(); // Exibe o menu principal.
    salvar_produtos(); // Salva os produtos no arquivo.
    return 0;
}


void salvar_produtos() {
    FILE *arquivo = fopen("produtos.txt", "w"); // Abre o arquivo "produtos.txt" para escrita.
    if (arquivo == NULL) { // Verifica se houve erro ao abrir o arquivo.
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    for (int i = 0; i < contador_produto; i++) {
        fprintf(arquivo, "%d\n", produto[i].codigo); // Escreve o código do produto no arquivo.
        fprintf(arquivo, "%s\n", produto[i].nome); // Escreve o nome do produto no arquivo.
        fprintf(arquivo, "%.2f\n", produto[i].preco); // Escreve o preço do produto no arquivo.
    }
    fclose(arquivo); // Fecha o arquivo.
}


void carregar_produtos() {
    contador_produto = contarProdutos(); // Obtém a quantidade de produtos existentes.
    FILE *arquivo = fopen("produtos.txt", "r"); // Abre o arquivo "produtos.txt" para leitura.
    if (arquivo == NULL) { // Verifica se houve erro ao abrir o arquivo.
        return;
    }
    contador_produto = 0;
    int codigo;
    char nome[100];
    float preco;
    while (fscanf(arquivo, "%d\n", &codigo) != EOF) { // Lê o código do produto do arquivo até o final.
        fgets(nome, 100, arquivo); // Lê o nome do produto do arquivo.
        nome[strcspn(nome, "\n")] = '\0'; // Remove o caractere de nova linha do nome.
        fscanf(arquivo, "%f\n", &preco); // Lê o preço do produto do arquivo.
        produto[contador_produto].codigo = codigo; // Armazena o código do produto na estrutura de produtos.
        strcpy(produto[contador_produto].nome, nome); // Copia o nome do produto para a estrutura de produtos.
        produto[contador_produto].preco = preco; // Armazena o preço do produto na estrutura de produtos.
        contador_produto++; // Incrementa o contador de produtos.
        ultimo_codigo = codigo; // Atualiza o último código
    }
    fclose(arquivo); // Fecha o arquivo.
}

   
void cadastrarProduto() {
    printf("==== Cadastro de Produto ====\n");
    if (contador_produto >= 100) {
        printf("Limite de produtos atingido.\n");
        return;
    }
    Produto novo_produto;
    printf("Nome: ");
    scanf("%*c"); // Consumir o caractere de nova linha pendente.
    fgets(novo_produto.nome, 100, stdin);
    novo_produto.nome[strcspn(novo_produto.nome, "\n")] = '\0';
    printf("Preco: ");
    scanf("%f", &novo_produto.preco);

    // Verificar se o código já existe
    int codigo_existe = buscarProduto(novo_produto.codigo);
    if (codigo_existe != -1) {
        printf("O codigo %d ja esta em uso.\n", novo_produto.codigo);
        return;
    }

    novo_produto.codigo = ultimo_codigo + 1; // Atribui o novo código ao produto cadastrado.
    ultimo_codigo++; // Incrementa o último código.

    int posicao_insercao = 0;
    while (posicao_insercao < contador_produto && produto[posicao_insercao].codigo < novo_produto.codigo) {
        posicao_insercao++;
    }

    // Move os elementos subsequentes para a direita
    for (int i = contador_produto; i > posicao_insercao; i--) {
        produto[i] = produto[i - 1];
    }

    // Insere o novo produto na posição correta
    produto[posicao_insercao] = novo_produto;

    contador_produto++;

    printf("Produto cadastrado com sucesso.\n");
}



    



void listarProdutos(){
    printf("==== Produtos Cadastrados ====\n");
    for(int i=0; i<contador_produto; i++){
        printf("-----------------------------\n");
        printf("Codigo: %d\n", produto[i].codigo); // Exibe o código do produto.
        printf("Nome: %s\n", produto[i].nome); // Exibe o nome do produto.
        printf("Preco: %.2f\n", produto[i].preco); // Exibe o preço do produto.
    }
}

void comprarProduto() {
    printf("Informe o código do produto: ");
    int codigo;
    scanf("%d", &codigo); // Lê o código do produto a ser comprado.

    int indice_produto = -1;
    int indice_carrinho = -1;

    // Verifica se o produto já está no carrinho
    for (int i = 0; i < contador_carrinho; i++) {
        if (codigo == carrinho[i].codigo) {
            indice_carrinho = i;
            break;
        }
    }

    if (indice_carrinho != -1) {
        printf("Produto já está no carrinho. Preço atualizado!\n");
        return;
    }

    // Verifica se o produto existe
    for (int i = 0; i < contador_produto; i++) {
        if (codigo == produto[i].codigo) {
            indice_produto = i;
            break;
        }
    }

    if (indice_produto == -1) {
        printf("Produto não encontrado.\n");
        return;
    }

    Carrinho novo_produto_carrinho;
    novo_produto_carrinho.codigo = produto[indice_produto].codigo; // Armazena o código do produto no carrinho.
    strcpy(novo_produto_carrinho.nome, produto[indice_produto].nome); // Copia o nome do produto para o carrinho.
    novo_produto_carrinho.preco = produto[indice_produto].preco; // Armazena o preço do produto no carrinho.

    printf("Quantidade: ");
    scanf("%d", &novo_produto_carrinho.quantidade); // Lê a quantidade do produto a ser comprada.

    carrinho[contador_carrinho] = novo_produto_carrinho; // Adiciona o produto ao carrinho.
    contador_carrinho++; // Incrementa o contador de produtos no carrinho.
    printf("Produto [%s] adicionado ao carrinho!\n", novo_produto_carrinho.nome); // Exibe a confirmação de que o produto foi adicionado ao carrinho.

    salvar_produtos(); // Salva os produtos no arquivo.
}


void visualizarCarrinho(){
    printf("==== Carrinho de Compras ====\n");
    printf("Quantidade de produtos: %d\n", contador_carrinho); // Exibe a quantidade de produtos no carrinho.
    for(int i=0; i<contador_carrinho; i++){
        printf("-----------------------------\n");
        printf("Codigo: %d\n", carrinho[i].codigo); // Exibe o código do produto.
        printf("Nome: %s\n", carrinho[i].nome); // Exibe o nome do produto.
        printf("Preco: %.2f\n", carrinho[i].preco); // Exibe o preço do produto.
        printf("Quantidade: %d\n", carrinho[i].quantidade); // Exibe a quantidade do produto.
    }
}

void fecharPedido(){
    float total = 0;
    for(int i=0; i<contador_carrinho; i++){
        total += carrinho[i].preco * carrinho[i].quantidade; // Calcula o total a pagar multiplicando o preço pela quantidade de produtos.
    }
    printf("Total a pagar: R$ %.2f\n", total); // Exibe o total a pagar.
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
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1: comprarProduto(); break;
            case 2: visualizarCarrinho(); break;
            case 3: fecharPedido(); break;
            case 0: break;
            default: printf("Opção inválida.\n");
        }
    } while(opcao != 0);
}

void menu(){
    int opcao;
    do{
        printf("==== MENU ====\n");
        printf("1- Cadastrar produto\n");
        printf("2- Listar produtos\n");
        printf("3- Atender um cliente\n");
        printf("0- Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: menu_fila(); break;
            case 0: break;
            default: printf("Opção inválida.\n");
        }
    } while(opcao != 0);
}
int contarProdutos() {
    FILE *arquivo = fopen("produtos.txt", "r"); // Abre o arquivo "produtos.txt" para leitura.
    if (arquivo == NULL) { // Verifica se houve erro ao abrir o arquivo.
        return 0;
    }
    int contador = 0;
    int codigo;
    char nome[100];
    float preco;
    while (fscanf(arquivo, "%d\n", &codigo) != EOF) { // Lê o código do produto do arquivo até o final.
        fgets(nome, 100, arquivo); // Lê o nome do produto do arquivo.
        fscanf(arquivo, "%f\n", &preco); // Lê o preço do produto do arquivo.
        contador++; // Incrementa o contador de produtos.
    }
    fclose(arquivo); // Fecha o arquivo.
    return contador;
}
int buscarProduto(int codigo) {
    for (int i = 0; i < contador_produto; i++) {
        if (produto[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}
