#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#ifdef __unix__
#include <unistd.h>
#include <stdlib.h>
#elif defined(_WIN32) || defined(WIN32)
#define OS_Windows
#include <locale.h>
#include <windows.h>
#endif

// Configuração de idioma para Windows
void portuguesBrasil() {
#ifdef OS_Windows
    setlocale(LC_ALL, "Portuguese");
#endif
}

// Limpa a tela do console
void limpar() {
#ifdef OS_Windows
    system("cls");
#else
    system("clear");
#endif
}

// Limpa o buffer do teclado
void limpeChar() {
#ifdef OS_Windows
    fflush(stdin);
#else
    getchar();
#endif
}

// Pausa a execução do programa
void pausar() {
#ifdef OS_Windows
    system("pause");
#else
    printf("Aperte qualquer botão para continuar...");
    getchar();
#endif
}

#define TAMFILA 10

// Definição da estrutura do cliente
typedef struct cliente {
    char carro[30];
    int cod;
} cliente;

// Fila / Queue
cliente fila[TAMFILA];
int head = 0; // próximo a ser atendido
int tail = 0; // cauda guarda quantidade de elemento, último da fila

// Lista os elementos da fila
void lista_elementos() {
    printf("\n========  FILA ATUAL ==========\n");
    for (int i = head; i < tail; i++) {
        printf("%s ", fila[i].carro);
    }
    printf("\nhead: %d\n", head);
    printf("\ntail: %d\n", tail);
    printf("\n\n");
}

// Adiciona um cliente à fila
void enqueue() {
    limpeChar();
    if (tail < TAMFILA) {
        // Adiciona
        printf("Informe o modelo do carro: ");
        fgets(fila[tail].carro, 30, stdin);
        tail++;
        lista_elementos();
    } else {
        // Não adiciona
        printf("A garagem está cheia, estacione fora da loja.\n\n");
    }
    limpar();
    menu_compra();
}

// Menu de compra
void menu_compra() {
    int op;
    printf("1 - Desistir da compra.\n");
    printf("2 - Opções de serviços\n");
    printf("3 - Solicitar serviços\n");
    printf("4 - Visualizar carrinho.\n");
    printf("5 - Pagar\n");
    scanf("%d", &op);
    switch (op) {
        case 1:
            limpar();
            menu();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            comprarProduto();
            break;
        case 4:
            visualizarCarrinho();
            break;
        case 5:
            fecharPedido();
            break;
        case 6:
            printf("Volte sempre!!");
            sleep(2); // para Windows
            // sleep(2); para Linux
            exit(0);
        default:
            printf("Opção inválida!!\n");
            sleep(2); // Windows
            limpar();
            menu();
            break;
    }
}
void maisUm() {
    // if (head < tail) {
    //     head++;
    //     lista_elementos();
    // } else {
    //     printf("A loja está vazia!!\n\n");
    // }
}

void dequeue() {
    if (head < tail) {
        for (int i = 0; i < tail - 1; i++) {
            strcpy(fila[i].carro, fila[i + 1].carro);
        }

        tail--;
        limpar();
        lista_elementos();
    } else {
        printf("A loja está vazia!!\n\n");
    }
}

void clear() {
    for (int i = 0; i < TAMFILA; i++) {
        strcpy(fila[i].carro, "");
    }
    head = 0;
    tail = 0;
}

// ========== fim fila ============================

// serviços
typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

// itens do carrinho
typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;

void infoProduto(Produto prod);
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int* temNoCarrinho(int codigo);
void fecharPedido();
void menu_fila();

static int contador_produto = 0; // para saber quantos produtos temos cadastrados
static int contador_carrinho = 0; // para saber quantos produtos tem no carrinho
static Carrinho carrinho[50]; // para adicionar os produtos no carrinho
static Produto produto[50];

int main() {
    menu();
    return 0;
}

void infoProduto(Produto prod) {
    printf("Codigo: %d \nNome: %s\nPreco:%.2f\n", prod.codigo, strtok(prod.nome, "\n"), prod.preco);
}

void menu() {
    portuguesBrasil();
    printf("============================================\n");
    printf("============= Bem-vindo(a) ==================\n");
    printf("============== Lava Jato ====================\n");
    printf("===============================================\n\n");

    printf("Selecione uma opcao abaixo: \n");
    printf("0 - Chegou cliente!!\n");
    printf("1 - Cadastrar servicos\n");
    printf("2 - Listar servicos\n");
    printf("3 - solicitar servicos\n");
    printf("4 - Visualizar Carrinho\n");
    printf("5 - Fechar pedido\n");
    printf("6 - Sair do sistema\n");

    int opcao;
    scanf("%d", &opcao);
    limpeChar();

    switch (opcao) {
        case 0:
            limpar();
            menu_fila();
            break;
        case 1:
            cadastrarProduto();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            comprarProduto();
            break;
        case 4:
            visualizarCarrinho();
            break;
        case 5:
            fecharPedido();
            break;
        case 6:
            printf("Volte Sempre!!");
            sleep(2); // para Windows
            // sleep(2); para linux
            exit(0);
        default:
            printf("opcao invalida!!");
            sleep(2); // Windows
            limpar();
            menu();
            break;
    }
}

void cadastrarProduto() {
    printf("cadastro de produto\n");
    printf("----------------------\n");
    printf("informe o nome do produto: \n");
    fgets(produto[contador_produto].nome, 30, stdin);

    printf("Informe o preco do produto:\n");
    scanf("%f", &produto[contador_produto].preco);

    printf("O produto [%s] foi cadastrado com sucesso", strtok(produto[contador_produto].nome, "\n"));
    produto[contador_produto].codigo = (contador_produto + 1);
    contador_produto++;
    sleep(2);
    pausar();
    limpar();
    menu();
}

void listarProdutos() {
    if (contador_produto > 0) {
        printf("Listagem de produtos\n");
        printf("---------------------\n");
        for (int i = 0; i < contador_produto; i++) {
            infoProduto(produto[i]);
            printf("---------------------\n");
            sleep(1); // Windows
            // sleep(1);//linux
        }
        sleep(2);
        pausar();
        menu();
    } else {
        printf("Nao existe serviço cadastrado!!\n");
        sleep(4);
        limpar();
        menu_compra();
    }
    system("pause");
    limpar();
    menu_compra();
}

void comprarProduto() {
    if (contador_produto > 0) { // verifica se existe produto cadastrado
        printf("Comprando produto\n");

        printf("---------------------------------------------\n");
        printf("========= Produtos disponiveis ============= \n");
        for (int i = 0; i < contador_produto; i++) {
            infoProduto(produto[i]);
            printf("-------------------\n");
        }
        printf("informe o código do produto para adicionar no carrinho: \n");
        int codigo; // se tiver o produto, solicito que o usuário digite o código do produto
        scanf("%d", &codigo);
        limpeChar();

        int tem_mercado = 0; // verifica se o código recebido é de um produto cadastrado
        for (int i = 0; i < contador_produto; i++) { // varre o array de produtos para localizar o código
            if (produto[i].codigo == codigo) {
                tem_mercado = 1;

                if (contador_carrinho > 0) { // esse produto que foi encontrado já tem no carrinho
                    int* retorno = (int *)temNoCarrinho(codigo);

                    if (retorno[0] == 1) { // produto já tem no carrinho
                        // tem esse produto com esse código no carrinho
                        carrinho[retorno[1]].quantidade++; // incrementa a quantidade
                        printf("produto %s já existente no carrinho, acrescentado mais um no carrinho\n",
                            strtok(carrinho[retorno[1]].produto.nome, "\n"));
                        sleep(2);
                        pausar();
                        menu_compra();
                    } else { // caso o produto não exista no carrinho
                        Produto p = pegarProdutoPorCodigo(codigo);
                        carrinho[contador_carrinho].produto = p; // adicionando o nosso produto no carrinho
                        carrinho[contador_carrinho].quantidade = 1;
                        contador_carrinho++;
                        printf("O produto %s foi adicionado ao carrinho!\n", strtok(p.nome, "\n"));
                        sleep(2);
                        pausar();
                        menu_compra();
                    }
                } else { // caso o carrinho esteja vazio, adiciona o primeiro item
                    Produto p = pegarProdutoPorCodigo(codigo);
                    carrinho[contador_carrinho].produto = p;
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("O produto %s foi adicionado ao carrinho!\n", strtok(p.nome, "\n"));
                    sleep(2);
                    pausar();
                    menu_compra();
                }
            }
        }
        if (tem_mercado < 1) { // se tem_mercado for menor que 1, significa que não há o produto cadastrado.
            printf("Nao foi encontrado o produto com o código informado %d!!\n", codigo);
            sleep(2);
            pausar();
            menu();
        } else {
            sleep(2);
            menu();
        }
    } else {
        printf("Loja fechada!! Sem produtos para vender!!");
        sleep(2);
        pausar();
        limpar();
        menu();
    }
}
void visualizarCarrinho(){
    if(contador_carrinho>0){ // verifica se existem produtos no carrinho
        printf("Produtos no Carrinho\n");
        printf("-----------------------\n");
        for(int i= 0;i<contador_carrinho;i++){ // percorre todos os produtos no carrinho
            infoProduto(carrinho[i].produto); // exibe informações do produto
            printf("Quantidade: %d\n",carrinho[i].quantidade); // exibe a quantidade do produto no carrinho
            printf("---------------------------\n");
            sleep(2);
            pausar();
            limpar();
            menu();
        }
    }else{
        printf("ERRO! sem produtos no carrinho\n"); // exibe mensagem de erro se não houver produtos no carrinho
        sleep(2);
        pausar();
        limpar();
        menu();
    }
}

Produto pegarProdutoPorCodigo(int codigo){
    Produto p;
    for(int i = 0; i< contador_produto;i++){ // percorre todos os produtos cadastrados
        if(produto[i].codigo == codigo){ // verifica se o código do produto coincide com o código fornecido
            p = produto[i]; // atribui o produto encontrado à variável 'p'
        }
    }
    return p; // retorna o produto encontrado
}

int * temNoCarrinho(int codigo){
    int static retorno[] = {0,0}; // array estático para armazenar o resultado da busca
    for(int i = 0;i<contador_carrinho;i++){ // percorre todos os produtos no carrinho
        if(carrinho[i].produto.codigo == codigo){ // verifica se o código do produto coincide com o código fornecido
            retorno[0] = 1; // indica que o produto foi encontrado no carrinho
            retorno[1] = i; // armazena o índice do produto no carrinho
        }
    }
    return retorno; // retorna o array com o resultado da busca
}

void fecharPedido(){
    if(contador_carrinho>0){ // verifica se há produtos no carrinho
        float valorTotal = 0.0; // variável para armazenar o valor total do pedido
        printf("produtos do carrinho: \n");
        printf("----------------------\n");
        for(int i =0; i<contador_carrinho;i++){ // percorre todos os produtos no carrinho
            Produto p = carrinho[i].produto; // obtém o produto
            int quantidade = carrinho[i].quantidade; // obtém a quantidade do produto
            valorTotal += p.preco * quantidade; // calcula o valor total do pedido
            infoProduto(p); // exibe informações do produto
            printf("Quantidade: %d\n",quantidade); // exibe a quantidade do produto
            printf("-----------------------------\n");
            sleep(1);
        }
        printf("Sua fatura e R$ %.2f\n",valorTotal); // exibe o valor total do pedido
        contador_carrinho = 0; // limpa o carrinho
        printf("Obrigado pela preferencia\n");
        sleep(1);
        pausar();
    }else{
        printf("Voce nao tem nenhum produto no carrinho!!\n"); // exibe mensagem de erro se não houver produtos no carrinho
        sleep(3); // pausa a execução por 3 segundos (Windows)
        //sleep(2); // pausa a execução por 2 segundos (Linux)
        limpar();
        menu();
    }
}

void menu_fila(){
    int op = 0;
    while(op != -1){
        printf("selecione a opcao: \n");
        printf("0 - Menu inicial!!\n");
        printf("1 - adicionar veiculo na fila\n");
        printf("2 - lavar veiculo da vez\n");
        printf("3 - lista de clietes\n");
        printf("4 - mandar todos os clientes embora\n");
        printf("-1 - para sair\n");
        scanf("%d",&op); // lê a opção selecionada pelo usuário
        switch(op){
            case 0:
                menu(); // exibe o menu inicial
                break;
            case 1:
                enqueue(); // adiciona um veículo à fila
                break;
            case 2:
                dequeue(); // remove o veículo da vez na fila
                maisUm();
                lista_elementos();
                break;
            case 3:
                limpar();
                lista_elementos(); // exibe a lista de clientes
                break;
            case 4:
                clear(); // remove todos os clientes da fila
                break;
            default:
                printf("opcao invalida!!"); // exibe mensagem de opção inválida
                break;
        }
    }
}
