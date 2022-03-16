#include<stdio.h>
#include<gtk/gtk.h>
//和水平布局类似
GtkButton * bt1, * bt2, * bt3;
int main() {
    gtk_init(NULL,NULL);
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,400,600);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    //创建垂直布局，感觉和水平的一样的
    //第一个参数时容器内空间是否均匀排放（大小一致），第二个就是间距
    GtkVBox * vb = gtk_vbox_new(TRUE,5);
    bt1 = gtk_button_new_with_label("hello");
    gtk_container_add(vb,bt1);
    bt2 = gtk_button_new_with_label("super");
    gtk_container_add(vb,bt2);
    bt3 = gtk_button_new_with_label("handsome");
    gtk_container_add(vb,bt3);

    gtk_container_add(window,vb);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}