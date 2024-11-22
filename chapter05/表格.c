#include <stdio.h>
#include <gtk/gtk.h>
// 感觉之前学的表格grid和table差不多
// 在deprecated: 3.4， 使用 GtkGrid 就行
GtkButton *bt1, *bt2, *bt3;

int main() {
    gtk_init(NULL, NULL);
    GtkWindow *window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 400, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    // 创建表格布局容器
    // 行数，列数，容器内大小是否一致
    GtkTable *table = GTK_TABLE(gtk_table_new(2, 2, TRUE));
    bt1 = GTK_BUTTON(gtk_button_new_with_label("hello"));
    // 这个参数好多，感觉还不如grid,如果不加defaults参数更加离谱的多，
    // 分别是左，右，上，下的位置
    gtk_table_attach_defaults(table, GTK_WIDGET(bt1), 0, 1, 0, 1);

    bt2 = GTK_BUTTON(gtk_button_new_with_label("thank"));
    gtk_table_attach_defaults(table, GTK_WIDGET(bt2), 1, 2, 0, 1);

    bt3 = GTK_BUTTON(gtk_button_new_with_label("you"));
    gtk_table_attach_defaults(table, GTK_WIDGET(bt3), 0, 2, 1, 2);

    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(table));
    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
