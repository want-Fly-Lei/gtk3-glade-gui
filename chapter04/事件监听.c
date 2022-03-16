#include<stdio.h>
#include<gtk/gtk.h>
GtkWindow * window;//需要声明到全局中不然现在阶段其他函数无法访问

int btClick(GtkWidget * widget, int data){
    gtk_window_set_title(window,"super 大帅比");
}

int main() {
    gtk_init(NULL,NULL);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,800,600);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);
    
    GtkButton * bt = gtk_button_new_with_label("点击");
    gtk_widget_show(bt);
    gtk_container_add(window,bt);
    //点击按钮后切换标题
    g_signal_connect(bt,"clicked",btClick,NULL);

    gtk_widget_show(window);
    gtk_main();
    return 0;
}