#include <gtk/gtk.h>

void cadastrarProdutoClicked(GtkWidget *widget, gpointer data) {
    printf("Cadastrar Produto\n");

    // Obter os valores dos campos
    GtkWidget *codigoEntry = GTK_WIDGET(gtk_builder_get_object(data, "codigoEntry"));
    GtkWidget *nomeEntry = GTK_WIDGET(gtk_builder_get_object(data, "nomeEntry"));
    GtkWidget *precoEntry = GTK_WIDGET(gtk_builder_get_object(data, "precoEntry"));

    const gchar *codigo = gtk_entry_get_text(GTK_ENTRY(codigoEntry));
    const gchar *nome = gtk_entry_get_text(GTK_ENTRY(nomeEntry));
    const gchar *preco = gtk_entry_get_text(GTK_ENTRY(precoEntry));

    // Imprimir os valores
    printf("Código: %s\n", codigo);
    printf("Nome: %s\n", nome);
    printf("Preço: %s\n", preco);
}

void cadastrarClienteClicked(GtkWidget *widget, gpointer data) {
    printf("Cadastrar Cliente\n");

    // Obter os valores dos campos
    GtkWidget *codigoEntry = GTK_WIDGET(gtk_builder_get_object(data, "codigoClienteEntry"));
    GtkWidget *nomeEntry = GTK_WIDGET(gtk_builder_get_object(data, "nomeClienteEntry"));
    GtkWidget *enderecoEntry = GTK_WIDGET(gtk_builder_get_object(data, "enderecoEntry"));

    const gchar *codigo = gtk_entry_get_text(GTK_ENTRY(codigoEntry));
    const gchar *nome = gtk_entry_get_text(GTK_ENTRY(nomeEntry));
    const gchar *endereco = gtk_entry_get_text(GTK_ENTRY(enderecoEntry));

    // Imprimir os valores
    printf("Código: %s\n", codigo);
    printf("Nome: %s\n", nome);
    printf("Endereço: %s\n", endereco);
}

void fecharPedidoClicked(GtkWidget *widget, gpointer data) {
    printf("Fechar Pedido\n");
}

void verProdutosCadastradosClicked(GtkWidget *widget, gpointer data) {
    printf("Ver Produtos Cadastrados\n");
}

void verCarrinhoClicked(GtkWidget *widget, gpointer data) {
    printf("Ver Carrinho\n");
}

void verPedidoFinalizadoClicked(GtkWidget *widget, gpointer data) {
    printf("Ver Pedido Finalizado\n");
}

void sairClicked(GtkWidget *widget, gpointer data) {
    printf("Sair\n");
    gtk_main_quit();
}

void createGUI(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *btnCadastrarProduto;
    GtkWidget *btnCadastrarCliente;
    GtkWidget *btnFecharPedido;
    GtkWidget *btnVerProdutosCadastrados;
    GtkWidget *btnVerCarrinho;
    GtkWidget *btnVerPedidoFinalizado;
    GtkWidget *btnSair;
    GtkWidget *codigoEntry;
    GtkWidget *nomeEntry;
    GtkWidget *precoEntry;
    GtkWidget *codigoClienteEntry;
    GtkWidget *nomeClienteEntry;
    GtkWidget *enderecoEntry;
    GtkBuilder *builder;

    // Inicializar GTK
    gtk_init(&argc, &argv);

    // Criar janela principal
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Minha Aplicacao");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 200);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Criar grid
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Carregar interface do arquivo Glade
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "interface.glade", NULL);

    // Obter referências para os widgets
    codigoEntry = GTK_WIDGET(gtk_builder_get_object(builder, "codigoEntry"));
    nomeEntry = GTK_WIDGET(gtk_builder_get_object(builder, "nomeEntry"));
    precoEntry = GTK_WIDGET(gtk_builder_get_object(builder, "precoEntry"));
    codigoClienteEntry = GTK_WIDGET(gtk_builder_get_object(builder, "codigoClienteEntry"));
    nomeClienteEntry = GTK_WIDGET(gtk_builder_get_object(builder, "nomeClienteEntry"));
    enderecoEntry = GTK_WIDGET(gtk_builder_get_object(builder, "enderecoEntry"));
    btnCadastrarProduto = GTK_WIDGET(gtk_builder_get_object(builder, "btnCadastrarProduto"));
    btnCadastrarCliente = GTK_WIDGET(gtk_builder_get_object(builder, "btnCadastrarCliente"));

    // Anexar widgets ao grid
    gtk_grid_attach(GTK_GRID(grid), codigoEntry, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), nomeEntry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), precoEntry, 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), codigoClienteEntry, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), nomeClienteEntry, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), enderecoEntry, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btnCadastrarProduto, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btnCadastrarCliente, 1, 2, 1, 1);

    // Conectar os sinais de clique aos manipuladores de eventos
    g_signal_connect(btnCadastrarProduto, "clicked", G_CALLBACK(cadastrarProdutoClicked), builder);
    g_signal_connect(btnCadastrarCliente, "clicked", G_CALLBACK(cadastrarClienteClicked), builder);

    // Adicionar os botões adicionais e seus manipuladores de eventos
    btnFecharPedido = gtk_button_new_with_label("Fechar Pedido");
    g_signal_connect(btnFecharPedido, "clicked", G_CALLBACK(fecharPedidoClicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), btnFecharPedido, 0, 3, 1, 1);

    btnVerProdutosCadastrados = gtk_button_new_with_label("Ver Produtos Cadastrados");
    g_signal_connect(btnVerProdutosCadastrados, "clicked", G_CALLBACK(verProdutosCadastradosClicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), btnVerProdutosCadastrados, 1, 3, 1, 1);

    btnVerCarrinho = gtk_button_new_with_label("Ver Carrinho");
    g_signal_connect(btnVerCarrinho, "clicked", G_CALLBACK(verCarrinhoClicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), btnVerCarrinho, 0, 4, 1, 1);

    btnVerPedidoFinalizado = gtk_button_new_with_label("Ver Pedido Finalizado");
    g_signal_connect(btnVerPedidoFinalizado, "clicked", G_CALLBACK(verPedidoFinalizadoClicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), btnVerPedidoFinalizado, 1, 4, 1, 1);

    btnSair = gtk_button_new_with_label("Sair");
    g_signal_connect(btnSair, "clicked", G_CALLBACK(sairClicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), btnSair, 0, 5, 1, 1);

    // Mostrar todos os widgets
    gtk_widget_show_all(window);

    // Iniciar loop principal do GTK
    gtk_main();
}

int main(int argc, char *argv[]) {
    createGUI(argc, argv);
    return 0;
}