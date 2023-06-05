#include <gtk/gtk.h>

// Função callback para o botão "Cadastrar Produto"
void cadastrar_produto(GtkWidget *widget, gpointer data) {
    // Chame a função cadastrarProduto() aqui
    cadastrarProduto();
}

// Função callback para o botão "Listar Produtos"
void listar_produtos(GtkWidget *widget, gpointer data) {
    // Chame a função listarProdutos() aqui
    listarProdutos();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Cria a janela principal
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sistema de Gerenciamento de Produtos");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Cria um layout vertical para os widgets
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Cria um botão "Cadastrar Produto"
    GtkWidget *button_cadastrar = gtk_button_new_with_label("Cadastrar Produto");
    g_signal_connect(button_cadastrar, "clicked", G_CALLBACK(cadastrar_produto), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), button_cadastrar, FALSE, FALSE, 0);

    // Cria um botão "Listar Produtos"
    GtkWidget *button_listar = gtk_button_new_with_label("Listar Produtos");
    g_signal_connect(button_listar, "clicked", G_CALLBACK(listar_produtos), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), button_listar, FALSE, FALSE, 0);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}