#include<stdio.h>
#include<gtk/gtk.h>
//这种布局无法自适应大小，所以使用的较少
int main() {
    gtk_init(NULL,NULL);
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,400,600);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    //还是老几样，先创建
    GtkFixed * fix = gtk_fixed_new();
    //随便添加一个
    GtkButton * bt = gtk_button_new();
    gtk_button_set_label(bt,"变有钱");
    gtk_fixed_put(fix,bt,40,30);//相当于位置在第40列30行
    gtk_widget_show(bt);

    //这种函数一步到位，按钮直接有名称
    GtkButton * bt2 = gtk_button_new_with_label("all of new button");
    gtk_fixed_put(fix,bt2,10,100);
    gtk_widget_show(bt2);

    //添加到window上
    gtk_container_add(window,fix);
    gtk_widget_show(fix);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}