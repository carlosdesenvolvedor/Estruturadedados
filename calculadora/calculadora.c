#include <gtk/gtk.h>
#include <stdlib.h>



GtkEntry *display;

void on_botao_clicked(GtkButton *button, gpointer data){

    if(strcmp(gtk_entry_get_text(display), "0") == 0)
        gtk_entry_set_text(display,gtk_button_get_label(button));
    else{
        char texto[100];
        g_snprintf(texto, 100, "%s%s",gtk_entry_get_text(display),gtk_button_get_label(button) );
        gtk_entry_set_text(display, texto);
    }
}


void on_botao_reset_clicked(GtkWidget *widget, gpointer data){


    gtk_main_quit();

}
void on_botao_raiz_quadrada_clicked(GtkWidget *widget, gpointer data){


    gtk_main_quit();

}
void on_botao_porcentagem_clicked(GtkWidget *widget, gpointer data){


    gtk_main_quit();

}
void on_botao_divisao_clicked(GtkWidget *widget, gpointer data){


    gtk_main_quit();

}
void on_botao_multiplicacao_clicked(GtkWidget *widget, gpointer data){


    gtk_main_quit();

}
void on_botao_subtracao_clicked(GtkWidget *widget, gpointer data){


    gtk_main_quit();

}
void on_botao_soma_clicked(GtkWidget *widget, gpointer data){


    gtk_main_quit();

}
void on_botao_igual_clicked(GtkWidget *widget, gpointer data){


    gtk_main_quit();

}
void on_botao_ponto_clicked(GtkWidget *widget, gpointer data){


    gtk_main_quit();

}
void on_main_window_destroy(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);

    GtkBuilder *builder = gtk_builder_new_from_file("projeto3.glade");

    gtk_builder_add_callback_symbols(builder,
        "on_botao_clicked",                  G_CALLBACK(on_botao_clicked),
        "on_main_window_destroy",            G_CALLBACK(on_main_window_destroy),
        "on_botao_reset_clicked",             G_CALLBACK(on_botao_reset_clicked),
         "on_botao_raiz_quadrada_clicked",    G_CALLBACK(on_botao_raiz_quadrada_clicked),
         "on_botao_porcentagem_clicked"   ,   G_CALLBACK(on_botao_porcentagem_clicked),
         "on_botao_divisao_clicked"        ,  G_CALLBACK(on_botao_divisao_clicked),
         "on_botao_multiplicacao_clicked"   , G_CALLBACK(on_botao_multiplicacao_clicked),
         "on_botao_subtracao_clicked"        ,G_CALLBACK(on_botao_subtracao_clicked),
         "on_botao_soma_clicked"             ,G_CALLBACK(on_botao_soma_clicked),
         "on_botao_igual_clicked."           ,G_CALLBACK(on_botao_igual_clicked),
         "on_botao_ponto_clicked"           , G_CALLBACK(on_botao_ponto_clicked),


        NULL);

    gtk_builder_connect_signals(builder,NULL);

    display = GTK_ENTRY(gtk_builder_get_object(builder,"display"));

    gtk_entry_set_text(display, "0");

    GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    
    gtk_widget_show_all(window);
    gtk_main();


    return 0;
}