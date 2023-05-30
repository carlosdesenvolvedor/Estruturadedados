#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h> //biblioteca para o linux
#include <windows.h> //se estiver no Windows

typedef struct {
    int codigo;
    char nome[30];
    float preco;
}Produto;

//itens do carrinho
typedef struct{
    Produto produto;
    int quantidade;
}Carrinho;

void infoProduto(Produto prod);
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int * temNoCarrinho(int codigo);
void fecharPedido();

static int contador_produto = 0; //para saber quantos protutos temos cadastrado
static int contador_carrinho = 0; //para saber quantos produtos tem no carrinho
static Carrinho carrinho[50]; //para adicionar os produtos no carrinho
static Produto produto[50];

int main(){
    menu();

    return 0;
}

void infoProduto(Produto prod){
    printf("Codigo: %d \nNome: %s\nPreco:%.2f\n",prod.codigo,strtok(prod.nome,"\n"),prod.preco);

}
void menu(){
    printf("============================================\n");
    printf("============= Bem-vindo(a) ==================\n");  
    printf("============= Center Music ====================\n");
    printf("===============================================\n\n");

    printf("Selecione uma opcao abaixo: \n");
    printf("1 - Cadastrar Produto\n");
    printf("2 - Listar Produto\n");
    printf("3 - Comprar Produto\n");
    printf("4 - Visualizar Carrinho\n");
    printf("5 - Fechar pedido\n");
    printf("6 - Sair do sistema\n");
    
    int opcao;
    scanf("%d", &opcao);
    //getchar(); //linux
    //fflush(stdin); //windows

    switch (opcao)
    {
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
    case 5:
        fecharPedido();
        break;
    case 6:
        printf("Volte Sempre!!");
        sleep(2); //para Windows
        //sleep(2); para linux
        exit(0);
    default:
        printf("opcao invalida!!");
        sleep(2); //Windows
        //sleep(2); //linux
        system("cls"); //Windows
        //system("clear"); linux
        menu();
        break;
    }

}
void cadastrarProduto(){
    printf("cadastro de produto\n");
    printf("----------------------\n");
    printf("informe o nome do produto: \n");
    fflush(stdin);
    fgets(produto[contador_produto].nome,30,stdin);
    
    printf("Informe o preco do produto:\n");
    scanf("%f",&produto[contador_produto].preco);
    fflush(stdin);
    printf("O produto [%s] foi cadastrado com sucesso",strtok(produto[contador_produto].nome, "\n"));
    produto[contador_produto].codigo = (contador_produto + 1);
    contador_produto++;
    sleep(2);
    system("cls");
    menu();
}
void listarProdutos(){
    if(contador_produto > 0){
        printf("Listagem de produtos\n");
        printf("---------------------\n");
        for(int i = 0; i< contador_produto; i++){
            infoProduto(produto[i]);
            printf("---------------------\n");
            sleep(1); //Windows
            //sleep(1);//linux
           
        }
        sleep(2);
        menu();

    }else{
        printf("Nao exite produtos cadastrado!!\n");
        sleep(4);
        system("cls");
        menu();
    }
    system("pause");
        system("cls");
        menu();

}
void comprarProduto(){
    if(contador_produto>0){ //verifica se existe produto cadastrado
        printf("Comprando produto\n"); //
       
        printf("---------------------------------------------\n");
        printf("========= Pordutos disponiveis ============= \n");
        for(int i = 0; i<contador_produto;i++){
            infoProduto(produto[i]);
            printf("-------------------\n");

        }
        printf("informe o codigo do produto para adicionar no carrinho: \n");
        int codigo; // se tiver o produto solicito que o usuario digite o codigo do produto
        scanf("%d",&codigo);
        fflush(stdin);
        
        int tem_mercado = 0; //verifica se o codigo recebido é de um produto cadastrado
        for(int i=0;i<contador_produto;i++){ //varre se no arrei de produto para localizar o código
            if(produto[i].codigo == codigo){
                tem_mercado = 1;

            if(contador_carrinho > 0){ //esse produto que foi encontrado já tem no carrinho
                int * retorno = temNoCarrinho(codigo);

                if(retorno[0] == 1){ //produto já tem no carrinho
                    //tem esse porduto com esse código no carrinho
                    carrinho[retorno[1]].quantidade++; //incrementa a quantidade
                    printf("Aumenteir a quantidade do porduto %s ja existente no carrinho\n",
                   strtok(carrinho[retorno[1]].produto.nome, "\n"));
                   sleep(2);
                   menu();
                }else{ //caso o produto não exista no carrinho
                    Produto p = pegarProdutoPorCodigo(codigo);
                    carrinho[contador_carrinho].produto = p; //adicionando o nosso produto no carrinho
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("O produto %s foi add ao carrinho!\n",strtok(p.nome,"\n"));
                    sleep(2);
                    menu();
                }
            }else{ //caso o carrinho esteja vazio é adicionado o primeiro item
                Produto p = pegarProdutoPorCodigo(codigo);
                carrinho[contador_carrinho].produto = p;
                carrinho[contador_carrinho].quantidade = 1;
                contador_carrinho++;
                printf("O produto %s foi add ao carrinho!\n",strtok(p.nome,"\n"));
                sleep(2);
                menu();
                 }

            }
            
        }
        if(tem_mercado< 1){ //se o tem mercado for menor que 1 significa que não tem o produto cadastrado.
            
            printf("Nao foi encontrado o produto com codigo informado %d!!\n",codigo);
            sleep(2);
            menu();
        }
            else{
                sleep(2);
                menu();
            }

    }else{
        printf("Loja fechada!!Sem produtos para vender!!");
        sleep(4);
        system("cls");
        menu();
    }

}




void visualizarCarrinho(){
    if(contador_carrinho>0){
        printf("Produtos no Carrinho\n");
        printf("-----------------------\n");
        for(int i= 0;i<contador_carrinho;i++){
            infoProduto(carrinho[i].produto);
            printf("Quantidade: %d\n",carrinho[i].quantidade);
            printf("---------------------------\n");
            sleep(3);
            system("cls");
            menu();
            }

    }else{
        printf("ERRO! sem produtos no carrinho\n");
        sleep(3);
        system("cls");
        menu();
    }

}
Produto pegarProdutoPorCodigo(int codigo){
    Produto p;
    for(int i = 0; i< contador_produto;i++){
        if(produto[i].codigo == codigo){
            p = produto[i];
        }
    }
    return p;
}
int * temNoCarrinho(int codigo){
    int static retorno[] = {0,0};
    for(int i = 0;i<contador_carrinho;i++){
        if(carrinho[i].produto.codigo == codigo){
            retorno[0] = 1 ;//tem oproduto com este coódio no ocarrinho
            retorno[1] = i; //o indice do produto no carrinho
        }

    }
    return retorno;
}
void fecharPedido(){
    if(contador_carrinho>0){
        float valorTotal = 0.0;
        printf("produtos do carrinho: \n");
        printf("----------------------\n");
        for(int i =0; i<contador_carrinho;i++){
            Produto p = carrinho[i].produto;
            int quantidade = carrinho[i].quantidade;
            valorTotal += p.preco * quantidade;
            infoProduto(p);
            printf("Quantidade: %d\n",quantidade);
            printf("-----------------------------\n");
            sleep(1);
        }
        printf("Sua fatura e R$ %.2f\n",valorTotal);
        //limpar carrinho
        contador_carrinho = 0;
        printf("Obrigado pela preferencia\n");
        sleep(1);
    }else{
        printf("Voce nao tem nenhum produto no carrinho!!\n");
        sleep(3);//Windows
        //sleep(2);//linux
        system("cls");
        menu();

        
    }

}
