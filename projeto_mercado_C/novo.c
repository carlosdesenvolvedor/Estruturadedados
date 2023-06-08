#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <gtk/gtk.h>

typedef struct {
    char nome[30];
    float preco;
    int codigo;
    int quantidade;
} Produto;

typedef struct {
    char nome[30];
    char telefone[20];
} Cliente;

Produto carrinho[100];
int contador_carrinho = 0;

Produto produto[100];
int contador_produto = 0;

void comprarProduto();
void visualizarCarrinho();
void sair();
void cadastrarProduto();
void cadastrarCliente();

void infoProduto(Produto prod) {
    printf("Código: %d\nNome: %s\nPreço: %.2f\n", prod.codigo, strtok(prod.nome, "\n"), prod.preco);
}

Produto pegarProdutoPorCodigo(int codigo) {
    Produto p;
    for (int i = 0; i < contador_produto; i++) {
        if (produto[i].codigo == codigo) {
            p = produto[i];
            break;
        }
    }
    return p;
}

void pausar() {
#ifdef _WIN32
    system("pause");
#else
    printf("Aperte qualquer botão para continuar...");
    getchar();
#endif
}

void limpar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void limpeChar() {
#ifdef _WIN32
    fflush(stdin);
#else
    getchar();
#endif
}

void cadastrarProduto() {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label_nome;
    GtkWidget *entry_nome;
    GtkWidget *label_preco;
    GtkWidget *entry_preco;
    gint response;

    dialog = gtk_dialog_new_with_buttons("Cadastrar Produto", NULL, GTK_DIALOG_MODAL,
                                         "Cadastrar", GTK_RESPONSE_ACCEPT, "Cancelar", GTK_RESPONSE_CANCEL, NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    label_nome = gtk_label_new("Nome do Produto:");
    entry_nome = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), label_nome);
    gtk_container_add(GTK_CONTAINER(content_area), entry_nome);

    label_preco = gtk_label_new("Preço do Produto:");
    entry_preco = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), label_preco);
    gtk_container_add(GTK_CONTAINER(content_area), entry_preco);

    gtk_widget_show_all(dialog);

    response = gtk_dialog_run(GTK_DIALOG(dialog));

    if (response == GTK_RESPONSE_ACCEPT) {
        const gchar *nome = gtk_entry_get_text(GTK_ENTRY(entry_nome));
        const gchar *preco = gtk_entry_get_text(GTK_ENTRY(entry_preco));

        printf("Cadastro de produto\n");
        printf("----------------------\n");
        printf("Nome do produto: %s\n", nome);
        printf("Preço do produto: %s\n", preco);
        printf("Produto cadastrado com sucesso!\n");
        printf("\n");

        gtk_widget_destroy(dialog);
    } else {
        gtk_widget_destroy(dialog);
    }
}

void cadastrarCliente() {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label_nome;
    GtkWidget *entry_nome;
    GtkWidget *label_telefone;
    GtkWidget *entry_telefone;
    gint response;

    dialog = gtk_dialog_new_with_buttons("Cadastrar Cliente", NULL, GTK_DIALOG_MODAL,
                                         "Cadastrar", GTK_RESPONSE_ACCEPT, "Cancelar", GTK_RESPONSE_CANCEL, NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    label_nome = gtk_label_new("Nome do Cliente:");
    entry_nome = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), label_nome);
    gtk_container_add(GTK_CONTAINER(content_area), entry_nome);

    label_telefone = gtk_label_new("Telefone do Cliente:");
    entry_telefone = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), label_telefone);
    gtk_container_add(GTK_CONTAINER(content_area), entry_telefone);

    gtk_widget_show_all(dialog);

    response = gtk_dialog_run(GTK_DIALOG(dialog));

    if (response == GTK_RESPONSE_ACCEPT) {
        const gchar *nome = gtk_entry_get_text(GTK_ENTRY(entry_nome));
        const gchar *telefone = gtk_entry_get_text(GTK_ENTRY(entry_telefone));

        printf("Cadastro de cliente\n");
        printf("----------------------\n");
        printf("Nome do cliente: %s\n", nome);
        printf("Telefone do cliente: %s\n", telefone);
        printf("Cliente cadastrado com sucesso!\n");
        printf("\n");

        gtk_widget_destroy(dialog);
    } else {
        gtk_widget_destroy(dialog);
    }
}

void comprarProduto() {
    int codigo;
    printf("Digite o código do produto que deseja comprar: ");
    scanf("%d", &codigo);

    Produto p = pegarProdutoPorCodigo(codigo);

    if (p.codigo == 0) {
        printf("Produto não encontrado!\n");
    } else {
        printf("Produto encontrado!\n");
        printf("Nome: %s\n", strtok(p.nome, "\n"));
        printf("Preço: %.2f\n", p.preco);
        printf("Quantidade disponível: %d\n", p.quantidade);

        int quantidade;
        printf("Digite a quantidade que deseja comprar: ");
        scanf("%d", &quantidade);

        if (quantidade <= p.quantidade) {
            Produto novoProduto;
            strcpy(novoProduto.nome, p.nome);
            novoProduto.preco = p.preco;
            novoProduto.codigo = p.codigo;
            novoProduto.quantidade = quantidade;
            carrinho[contador_carrinho++] = novoProduto;

            printf("Produto adicionado ao carrinho com sucesso!\n");
        } else {
            printf("Não há quantidade suficiente em estoque!\n");
        }
    }

    pausar();
}

void visualizarCarrinho() {
    printf("Carrinho de Compras\n");
    printf("----------------------\n");

    if (contador_carrinho == 0) {
        printf("Carrinho vazio!\n");
    } else {
        float total = 0;
        for (int i = 0; i < contador_carrinho; i++) {
            Produto p = carrinho[i];
            printf("Item %d:\n", i + 1);
            printf("Código: %d\n", p.codigo);
            printf("Nome: %s\n", strtok(p.nome, "\n"));
            printf("Preço: %.2f\n", p.preco);
            printf("Quantidade: %d\n", p.quantidade);
            printf("\n");

            total += p.preco * p.quantidade;
        }

        printf("Total: %.2f\n", total);
    }

    pausar();
}

void sair() {
    printf("Saindo do programa...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button_comprar;
    GtkWidget *button_carrinho;
    GtkWidget *button_cadastrar_produto;
    GtkWidget *button_cadastrar_cliente;
    GtkWidget *button_sair;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sistema de Vendas");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    button_comprar = gtk_button_new_with_label("Comprar Produto");
    g_signal_connect(button_comprar, "clicked", G_CALLBACK(comprarProduto), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_comprar, 0, 0, 1, 1);

    button_carrinho = gtk_button_new_with_label("Visualizar Carrinho");
    g_signal_connect(button_carrinho, "clicked", G_CALLBACK(visualizarCarrinho), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_carrinho, 1, 0, 1, 1);

    button_cadastrar_produto = gtk_button_new_with_label("Cadastrar Produto");
    g_signal_connect(button_cadastrar_produto, "clicked", G_CALLBACK(cadastrarProduto), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_cadastrar_produto, 0, 1, 1, 1);

    button_cadastrar_cliente = gtk_button_new_with_label("Cadastrar Cliente");
    g_signal_connect(button_cadastrar_cliente, "clicked", G_CALLBACK(cadastrarCliente), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_cadastrar_cliente, 1, 1, 1, 1);

    button_sair = gtk_button_new_with_label("Sair");
    g_signal_connect(button_sair, "clicked", G_CALLBACK(sair), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_sair, 0, 2, 2, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}