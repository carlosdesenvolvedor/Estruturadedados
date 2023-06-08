#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20
#define GRID_WIDTH 30
#define GRID_HEIGHT 20
#define WINDOW_WIDTH (GRID_WIDTH * GRID_SIZE)
#define WINDOW_HEIGHT (GRID_HEIGHT * GRID_SIZE)

GtkWidget *window;
GtkWidget *drawing_area;

int snakeX = 0;
int snakeY = 0;
int directionX = 1;
int directionY = 0;

int foodX = 0;
int foodY = 0;

int tailX[GRID_WIDTH * GRID_HEIGHT];
int tailY[GRID_WIDTH * GRID_HEIGHT];
int tailLength = 0;

int wallX[GRID_WIDTH * GRID_HEIGHT];
int wallY[GRID_WIDTH * GRID_HEIGHT];
int wallCount = 0;

gboolean foodEaten = FALSE;

gboolean is_snake_or_wall(int x, int y) {
    // Verifica se a posição está ocupada pela cobrinha ou pelas paredes
    for (int i = 0; i < tailLength; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            return TRUE;
        }
    }

    for (int i = 0; i < wallCount; i++) {
        if (wallX[i] == x && wallY[i] == y) {
            return TRUE;
        }
    }

    return FALSE;
}

void generate_food_position() {
    srand(time(NULL));

    // Gera uma posição aleatória para a comida dentro do grid
    do {
        foodX = (rand() % GRID_WIDTH) * GRID_SIZE;
        foodY = (rand() % GRID_HEIGHT) * GRID_SIZE;
    } while (is_snake_or_wall(foodX, foodY));

    foodEaten = FALSE;
}

gboolean update_snake(gpointer data) {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = snakeX;
    tailY[0] = snakeY;

    for (int i = 1; i < tailLength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    snakeX += directionX * GRID_SIZE;
    snakeY += directionY * GRID_SIZE;

    if (snakeX >= WINDOW_WIDTH) {
        snakeX = 0;
    }
    else if (snakeX < 0) {
        snakeX = WINDOW_WIDTH - GRID_SIZE;
    }

    if (snakeY >= WINDOW_HEIGHT) {
        snakeY = 0;
    }
    else if (snakeY < 0) {
        snakeY = WINDOW_HEIGHT - GRID_SIZE;
    }

    // Verifica se a cobrinha encontrou a comida
    if (snakeX == foodX && snakeY == foodY) {
        foodEaten = TRUE;
        generate_food_position();
        tailLength++;
    }

    // Verifica se a cobrinha colidiu com a parede
    if (is_snake_or_wall(snakeX, snakeY)) {
        g_print("Game Over\n");
        gtk_main_quit();
        return G_SOURCE_REMOVE;
    }

    gtk_widget_queue_draw(drawing_area);

    return G_SOURCE_CONTINUE;
}

gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    switch (event->keyval) {
        case GDK_KEY_Up:
            if (directionY != 1) {
                directionX = 0;
                directionY = -1;
            }
            break;
        case GDK_KEY_Down:
            if (directionY != -1) {
                directionX = 0;
                directionY = 1;
            }
            break;
        case GDK_KEY_Left:
            if (directionX != 1) {
                directionX = -1;
                directionY = 0;
            }
            break;
        case GDK_KEY_Right:
            if (directionX != -1) {
                directionX = 1;
                directionY = 0;
            }
            break;
    }

    return TRUE;
}

gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data) {
    // Preenche o fundo do desenho com a cor preta
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_paint(cr);

    // Desenha a cobrinha como retângulos brancos
    cairo_set_source_rgb(cr, 1, 1, 1);
    for (int i = 0; i < tailLength; i++) {
        cairo_rectangle(cr, tailX[i], tailY[i], GRID_SIZE, GRID_SIZE);
        cairo_fill(cr);
    }

    // Desenha a comida como um caractere "*"
    cairo_set_source_rgb(cr, 1, 0, 0);
    cairo_select_font_face(cr, "Monospace", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, GRID_SIZE);
    cairo_move_to(cr, foodX, foodY + GRID_SIZE);
    cairo_show_text(cr, "*");

    // Desenha as paredes como retângulos azuis
    cairo_set_source_rgb(cr, 0, 0, 1);
    for (int i = 0; i < wallCount; i++) {
        cairo_rectangle(cr, wallX[i], wallY[i], GRID_SIZE, GRID_SIZE);
        cairo_fill(cr);
    }

    return FALSE;
}

void on_window_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);
    gtk_window_set_default_size(GTK_WINDOW(window), WINDOW_WIDTH, WINDOW_HEIGHT);

    drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw), NULL);
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), NULL);

    gtk_widget_set_app_paintable(drawing_area, TRUE);

    gtk_widget_show_all(window);

    generate_food_position();

    g_timeout_add(100, update_snake, NULL);

    gtk_main();

    return 0;
}
