#include<stdio.h>
#include<gtk/gtk.h>//引库
int main() {
    gtk_init(NULL,NULL);
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //设置窗口可以拉伸，FALSE则是不可拉伸,默认是可以拉伸的
    gtk_window_set_resizable(window,TRUE);

    //设置窗口起始位置（中间），未设置则随机
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);

    //设置建议大小
    gtk_widget_set_size_request(window,400,600);

    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}