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
//Windows X Linux -----------------
void portuguesBrasil(){
    
    #ifdef OS_Windows
    /* Codigo Windows */
        setlocale(LC_ALL,"Portuguese");
    #else
    /* Codigo GNU/Linux */     

    #endif  
}
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
void pausar(){
          #ifdef OS_Windows
    /* Codigo Windows */
        system("pause");
    #else
    /* Codigo GNU/Linux */
        printf("Aperque qualquer botão para continuar...");
        getchar();
    #endif 
}
//fim ---------------------------------------------------
//=========fila=======================================

#define TAMFILA 10 

typedef struct cliente{
    char carro[30];
    int cod;
} cliente;

// Fila / Queue
cliente fila[TAMFILA];
int head = 0; // próximo a ser atendido
int tail = 0;  // cauda guarda quantidade de elemento, último da fila

void lista_elementos() {
    printf("\n========  FILA ATUAL ==========\n");
    for (int i = head; i < tail; i++) {
        printf("%s\n", fila[i].carro);
    }
    printf("\nhead: %d\n", head);
    printf("\ntail: %d\n", tail);
    printf("\n\n");
}

void enqueue() {
    limpeChar();
    if (tail < TAMFILA) {
        //adiciona
        printf("Informe o modelo do carro: ");
        fgets(fila[tail].carro, 30, stdin);
        tail++;
        lista_elementos();
    } else {
        //não adiciona
        printf("A garagem está cheia, estacione fora da loja.\n\n");
    }
}

void maisUm() {
    if (tail > 0 && head < TAMFILA) {
        for (int i = head; i < tail; i++) {
            strcpy(fila[i].carro, fila[i + 1].carro);
        }
        
        tail--;
        head--;
        if (head == -1) {
            head = 0;
        }
        lista_elementos();
    } else {
      printf("A loja está vazia!!\n\n");
    }
}

// remover
void dequeue() {
    if (head < tail) {
        head++;
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
//========== fim fila ============================
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
void menu_fila();

static int contador_produto = 0; //para saber quantos protutos temos cadastrado
static int contador_carrinho = 0; //para saber quantos produtos tem no carrinho
static Carrinho carrinho[50]; //para adicionar os produtos no carrinho
static Produto produto[50];

int main(){
   
    
    menu_fila();
    menu();

    return 0;
}

void infoProduto(Produto prod){
    printf("Codigo: %d \nNome: %s\nPreco:%.2f\n",prod.codigo,strtok(prod.nome,"\n"),prod.preco);

}
void menu(){
    portuguesBrasil();
    printf("============================================\n");
    printf("============= Bem-vindo(a) ==================\n");  
    printf("============== Lava Jato ====================\n");
    printf("===============================================\n\n");

    printf("Selecione uma opcao abaixo: \n");
    printf("1 - Cadastrar servicos\n");
    printf("2 - Listar servicos\n");
    printf("3 - solicitar servicos\n");
    printf("4 - Visualizar Carrinho\n");
    printf("5 - Fechar pedido\n");
    printf("6 - Sair do sistema\n");
    
    int opcao;
    scanf("%d", &opcao);
    limpeChar();
    

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
        
        limpar();
        menu();
        break;
    }

}
void cadastrarProduto(){
    printf("cadastro de produto\n");
    printf("----------------------\n");
    printf("informe o nome do produto: \n");
    
    fgets(produto[contador_produto].nome,30,stdin);
    
    
    printf("Informe o preco do produto:\n");
    scanf("%f",&produto[contador_produto].preco);
 
    printf("O produto [%s] foi cadastrado com sucesso",strtok(produto[contador_produto].nome, "\n"));
    produto[contador_produto].codigo = (contador_produto + 1);
    contador_produto++;
    sleep(2);
    pausar();
    limpar();
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
        pausar();
        menu();

    }else{
        printf("Nao exite serviço cadastrado!!\n");
        sleep(4);
        limpar();
        menu();
    }
    system("pause");
        limpar();
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
        printf("informe o código do produto para adicionar no carrinho: \n");
        int codigo; // se tiver o produto solicito que o usuario digite o codigo do produto
        scanf("%d",&codigo);
        limpeChar();
        
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
                   pausar();
                   menu();
                }else{ //caso o produto não exista no carrinho
                    Produto p = pegarProdutoPorCodigo(codigo);
                    carrinho[contador_carrinho].produto = p; //adicionando o nosso produto no carrinho
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("O produto %s foi add ao carrinho!\n",strtok(p.nome,"\n"));
                    sleep(2);
                    pausar();
                    menu();
                }
            }else{ //caso o carrinho esteja vazio é adicionado o primeiro item
                Produto p = pegarProdutoPorCodigo(codigo);
                carrinho[contador_carrinho].produto = p;
                carrinho[contador_carrinho].quantidade = 1;
                contador_carrinho++;
                printf("O produto %s foi add ao carrinho!\n",strtok(p.nome,"\n"));
                sleep(2);
                pausar();
                menu();
                 }

            }
            
        }
        if(tem_mercado< 1){ //se o tem mercado for menor que 1 significa que não tem o produto cadastrado.
            
            printf("Nao foi encontrado o produto com codigo informado %d!!\n",codigo);
            sleep(2);
            pausar();
            menu();
        }
            else{
                sleep(2);
                menu();
            }

    }else{
        printf("Loja fechada!!Sem produtos para vender!!");
        sleep(2);
        pausar();
        limpar();
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
            sleep(2);
            pausar();
            limpar();
            menu();
            }

    }else{
        printf("ERRO! sem produtos no carrinho\n");
        sleep(2);
        pausar();
        limpar();
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
        pausar();
    }else{
        printf("Voce nao tem nenhum produto no carrinho!!\n");
        sleep(3);//Windows
        //sleep(2);//linux
        
        limpar();
        menu();

        
    }

}
void menu_fila(){
    int op = 0;
    while(op != -1){
        printf("selecione a opcao: \n");
        printf("1 - adicionar veiculo na fila\n");
        printf("2 - atender cliente\n");
        printf("3 - lista de clietes\n");
        printf("4 - mandar todos os clientes embora\n");
        printf("-1 - para sair\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                maisUm();
                lista_elementos();

                break;
            case 3:
                lista_elementos();
                break;
            case 4:
                clear();
                break;
            default:
                printf("opcao invalida!!");
                break;


        }
    }

 
}