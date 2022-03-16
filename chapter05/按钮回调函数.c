#include<stdio.h>
#include<gtk/gtk.h>
//关于函数回调的细节
char * str;
void printStr(GtkButton * bu, gpointer user_data) {
    str = user_data;
    printf("str = %s\n",str);
}
int main() {
    gtk_init(NULL,NULL);
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,400,600);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);
    gtk_container_set_border_width(window,5);

    GtkButton * bt = gtk_button_new_with_label("click");
    gtk_container_add(window,bt);
    //第一个参数和第四个参数就是第三个参数（函数名）的传入参数，第二个参数是触发条件
    g_signal_connect(bt,"clicked",printStr,"hello");
    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}