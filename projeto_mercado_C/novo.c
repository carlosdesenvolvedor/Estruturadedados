#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Servico;

Servico servicos[100];
int contador_servicos = 0;

void pausar() {
    printf("Pressione Enter para continuar...");
    while (getchar() != '\n');
    getchar(); 
}
void cadastrarServico(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label_nome;
    GtkWidget *entry_nome;
    GtkWidget *label_preco;
    GtkWidget *entry_preco;
    GtkWidget *label_quantidade;
    GtkWidget *entry_quantidade;
    gint response;

    dialog = gtk_dialog_new_with_buttons("Cadastrar Serviço", NULL, GTK_DIALOG_MODAL,
                                         "Cadastrar", GTK_RESPONSE_ACCEPT, "Cancelar", GTK_RESPONSE_CANCEL, NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    label_nome = gtk_label_new("Nome do Serviço:");
    entry_nome = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), label_nome);
    gtk_container_add(GTK_CONTAINER(content_area), entry_nome);

    label_preco = gtk_label_new("Preço do Serviço:");
    entry_preco = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), label_preco);
    gtk_container_add(GTK_CONTAINER(content_area), entry_preco);

    label_quantidade = gtk_label_new("Quantidade do Serviço:");
    entry_quantidade = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), label_quantidade);
    gtk_container_add(GTK_CONTAINER(content_area), entry_quantidade);

    gtk_widget_show_all(dialog);

    response = gtk_dialog_run(GTK_DIALOG(dialog));

    if (response == GTK_RESPONSE_ACCEPT) {
        const gchar *nome = gtk_entry_get_text(GTK_ENTRY(entry_nome));
        const gchar *preco_str = gtk_entry_get_text(GTK_ENTRY(entry_preco));
        const gchar *quantidade_str = gtk_entry_get_text(GTK_ENTRY(entry_quantidade));

        float preco = atof(preco_str);
        int quantidade = atoi(quantidade_str);

        // Abrir o arquivo "servicos.txt" em modo de leitura
        FILE *arquivo = fopen("servicos.txt", "r");
        if (arquivo != NULL) {
            // Encontrar o maior código existente no arquivo
            int maior_codigo = 0;
            char linha[100];
            while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                int codigo;
                if (sscanf(linha, "Código: %d", &codigo) == 1) {
                    if (codigo > maior_codigo) {
                        maior_codigo = codigo;
                    }
                }
            }

            // Fechar o arquivo
            fclose(arquivo);

            // Atribuir o código do novo serviço como sendo o maior código encontrado mais um
            int novo_codigo = maior_codigo + 1;

            Servico novoServico;
            novoServico.codigo = novo_codigo;
            strcpy(novoServico.nome, nome);
            novoServico.preco = preco;
            novoServico.quantidade = quantidade;

            servicos[contador_servicos++] = novoServico;

            printf("Serviço cadastrado com sucesso!\n");

            // Abrir o arquivo "servicos.txt" no modo de escrita
            arquivo = fopen("servicos.txt", "a");
            if (arquivo != NULL) {
                // Escrever os dados do novo serviço no arquivo
                fprintf(arquivo, "Código: %d\n", novoServico.codigo);
                fprintf(arquivo, "Nome: %s\n", novoServico.nome);
                fprintf(arquivo, "Preço: %.2f\n", novoServico.preco);
                fprintf(arquivo, "Quantidade: %d\n", novoServico.quantidade);
                fprintf(arquivo, "\n");

                // Fechar o arquivo
                fclose(arquivo);

                printf("Dados do serviço armazenados no arquivo 'servicos.txt'\n");
            } else {
                printf("Erro ao abrir o arquivo 'servicos.txt' para escrita\n");
            }
        } else {
            // Caso o arquivo não exista, criar um novo arquivo "servicos.txt"
            arquivo = fopen("servicos.txt", "w");
            if (arquivo != NULL) {
                int novo_codigo = 1;  // Primeiro código para um novo arquivo

                Servico novoServico;
                novoServico.codigo = novo_codigo;
                strcpy(novoServico.nome, nome);
                novoServico.preco = preco;
                novoServico.quantidade = quantidade;

                servicos[contador_servicos++] = novoServico;

                printf("Serviço cadastrado com sucesso!\n");

                // Escrever os dados do novo serviço no arquivo
                fprintf(arquivo, "Código: %d\n", novoServico.codigo);
                fprintf(arquivo, "Nome: %s\n", novoServico.nome);
                fprintf(arquivo, "Preço: %.2f\n", novoServico.preco);
                fprintf(arquivo, "Quantidade: %d\n", novoServico.quantidade);
                fprintf(arquivo, "\n");

                // Fechar o arquivo
                fclose(arquivo);

                printf("Dados do serviço armazenados no arquivo 'servicos.txt'\n");
            } else {
                printf("Erro ao criar o arquivo 'servicos.txt'\n");
            }
        }
    }

    gtk_widget_destroy(dialog);
}




void comprarServico(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *label_codigo;
    GtkWidget *entry_codigo;
    gint response;

    dialog = gtk_dialog_new_with_buttons("Comprar Serviço", NULL, GTK_DIALOG_MODAL,
                                         "Comprar", GTK_RESPONSE_ACCEPT, "Cancelar", GTK_RESPONSE_CANCEL, NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    label_codigo = gtk_label_new("Código do Serviço:");
    entry_codigo = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), label_codigo);
    gtk_container_add(GTK_CONTAINER(content_area), entry_codigo);

    gtk_widget_show_all(dialog);

    response = gtk_dialog_run(GTK_DIALOG(dialog));

    if (response == GTK_RESPONSE_ACCEPT) {
        const gchar *codigo_str = gtk_entry_get_text(GTK_ENTRY(entry_codigo));
        int codigo = atoi(codigo_str);

        Servico *servico = NULL;

        for (int i = 0; i < contador_servicos; i++) {
            if (servicos[i].codigo == codigo) {
                servico = &servicos[i];
                break;
            }
        }

        if (servico == NULL) {
            printf("Serviço não encontrado!\n");
        } else {
            int quantidade;
            printf("Informe a quantidade desejada: ");
            scanf("%d", &quantidade);

            if (quantidade > servico->quantidade) {
                printf("Quantidade indisponível!\n");
            } else {
                servico->quantidade -= quantidade;
                printf("Serviço comprado com sucesso!\n");
            }
        }
    }

    gtk_widget_destroy(dialog);
}

void visualizarCarrinho(GtkWidget *widget, gpointer data) {
    if (contador_servicos == 0) {
        printf("Nenhum serviço cadastrado!\n");
    } else {
        float total = 0;
        for (int i = 0; i < contador_servicos; i++) {
            Servico s = servicos[i];
            printf("Item %d:\n", i + 1);
            printf("Código: %d\n", s.codigo);
            printf("Nome: %s\n", strtok(s.nome, "\n"));
            printf("Preço: %.2f\n", s.preco);
            printf("Quantidade: %d\n", s.quantidade);
            printf("\n");

            total += s.preco * s.quantidade;
        }

        printf("Total: %.2f\n", total);
    }

    pausar();
}

void sair(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button_comprar;
    GtkWidget *button_carrinho;
    GtkWidget *button_cadastrar_servico;
    GtkWidget *button_sair;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sistema de Vendas");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    button_comprar = gtk_button_new_with_label("Comprar Serviço");
    g_signal_connect(button_comprar, "clicked", G_CALLBACK(comprarServico), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_comprar, 0, 0, 1, 1);

    button_carrinho = gtk_button_new_with_label("Visualizar Carrinho");
    g_signal_connect(button_carrinho, "clicked", G_CALLBACK(visualizarCarrinho), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_carrinho, 1, 0, 1, 1);

    button_cadastrar_servico = gtk_button_new_with_label("Cadastrar Serviço");
    g_signal_connect(button_cadastrar_servico, "clicked", G_CALLBACK(cadastrarServico), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_cadastrar_servico, 0, 1, 1, 1);

    button_sair = gtk_button_new_with_label("Sair");
    g_signal_connect(button_sair, "clicked", G_CALLBACK(sair), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_sair, 1, 1, 1, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
