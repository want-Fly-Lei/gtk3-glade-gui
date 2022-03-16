#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>
GtkWindow * window;
GtkGrid * grid;
GtkEntry * entry1;
GtkButton * button;
GtkImage * img;
char * news;
int age;

int buttonChecked(GtkWidget * widget, int data) {
    news = gtk_entry_get_text(entry1);
    age = atoi(news);//把字符转化为数字
    if(age >= 0 && age < 12) {
        gtk_image_set_from_file(img,"../img/kid.jpg");
    } else if(age >= 12 && age < 18) {
        gtk_image_set_from_file(img,"../img/youth.jpg");
    } else if(age >= 18 && age < 44) {
        gtk_image_set_from_file(img,"../img/middleAge.jpg");
    } else {
        gtk_image_set_from_file(img,"../img/agedness.jpg");
    }
}

int main() {
    gtk_init(NULL,NULL);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,1600,900);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    grid = gtk_grid_new();
    gtk_container_add(window,grid);
    gtk_widget_show(grid);

    entry1 = gtk_entry_new();
    gtk_widget_show(entry1);
    gtk_grid_attach(grid,entry1,0,0,1,1);

    button = gtk_button_new_with_label("点击生成对应岁数的图片");
    gtk_widget_show(button);
    gtk_grid_attach(grid,button,1,0,1,1);
    g_signal_connect(button,"clicked",buttonChecked,NULL);

    img = gtk_image_new();
    gtk_grid_attach(grid,img,0,1,1,1);
    gtk_widget_show(img);

    gtk_widget_show(window);
    gtk_main();
    return 0;
}