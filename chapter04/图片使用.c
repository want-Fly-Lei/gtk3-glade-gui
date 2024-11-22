#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
GtkWindow *window;
GtkGrid *grid;
GtkEntry *entry1;
GtkButton *button;
GtkImage *img;
const char *news;
int age;

int buttonChecked(GtkWidget *widget, int data) {
    news = (const char *) gtk_entry_get_text(entry1);
    age = atoi(news); // 把字符转化为数字
    if (age >= 0 && age < 12) {
        gtk_image_set_from_file(img, "../img/kid.jpg");
    } else if (age >= 12 && age < 18) {
        gtk_image_set_from_file(img, "../img/youth.jpg");
    } else if (age >= 18 && age < 44) {
        gtk_image_set_from_file(img, "../img/middleAge.jpg");
    } else {
        gtk_image_set_from_file(img, "../img/agedness.jpg");
    }
}

int main() {
    gtk_init(NULL, NULL);
    window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 800, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    grid = GTK_GRID(gtk_grid_new());
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(grid));
    gtk_widget_show(GTK_WIDGET(grid));

    entry1 = GTK_ENTRY(gtk_entry_new());
    gtk_widget_show(GTK_WIDGET(entry1));
    gtk_grid_attach(grid, GTK_WIDGET(entry1), 0, 0, 1, 1);

    button = GTK_BUTTON(gtk_button_new_with_label("点击生成对应岁数的图片"));
    gtk_widget_show(GTK_WIDGET(button));
    gtk_grid_attach(grid, GTK_WIDGET(button), 1, 0, 1, 1);
    g_signal_connect(button, "clicked", G_CALLBACK(buttonChecked), NULL);

    img = GTK_IMAGE(gtk_image_new());
    gtk_grid_attach(grid, GTK_WIDGET(img), 0, 1, 1, 1);
    gtk_widget_show(GTK_WIDGET(img));

    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
