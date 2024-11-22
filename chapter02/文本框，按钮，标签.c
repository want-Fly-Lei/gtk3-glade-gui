#include <stdio.h>
#include <gtk/gtk.h>
// 学习三大部件，按钮文本框和标签

int main() {
    gtk_init(NULL, NULL);
    GtkWindow *window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 800, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);
    gtk_widget_show(GTK_WIDGET(window));

    // 添加文本框
    // 1.创建相对对象指针
    //  GtkEntry * entry1 = (GtkEntry *) gtk_entry_new(); // 一般是gtk_abc_new();abc代表类型
    //  // 2.显示entry
    //  gtk_widget_show(GTK_WIDGET(entry1));
    //  // 3.把文本框添加一个父容器中
    //  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(entry1));

    // 但是由于一个部件只能包含一个字部件，所以我们需要将上面的文本框线注释了
    // 添加按钮，和上面类似
    //  GtkButton * gb = (GtkButton *) gtk_button_new();
    //  // 设置按钮名称
    //  gtk_button_set_label(gb, "点我呀！");
    //  gtk_widget_show(GTK_WIDGET(gb));
    //  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(gb));

    // 添加标签（只读）,同样把上面的给注释掉
    GtkLabel *lab = GTK_LABEL(gtk_label_new("姓名")); // 标签吸血给他取名，所以必有参数
    gtk_widget_show(GTK_WIDGET(lab));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(lab));

    gtk_main();
    return 0;
}
