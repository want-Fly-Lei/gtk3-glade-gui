#include <stdio.h>
#include <gtk/gtk.h>
// 除了使用盒子，还可以使用网格来进行布局

int main() {
    gtk_init(NULL, NULL);
    GtkWindow *window = (GtkWindow *) gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 400, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    // 创建网格指针
    GtkGrid *grid = GTK_GRID(gtk_grid_new());
    // 创建两个文本框，按钮和标签
    GtkLabel *label1, *label2;
    label1 = (GtkLabel *) gtk_label_new("账号:");
    label2 = (GtkLabel *) gtk_label_new("密码:");
    // 3,4个参数是距离左边和上边的距离，第5,6的占多少列和行
    gtk_grid_attach(grid, GTK_WIDGET(label1), 0, 0, 1, 1);
    gtk_grid_attach(grid, GTK_WIDGET(label2), 0, 1, 1, 1);
    gtk_widget_show(GTK_WIDGET(label1));
    gtk_widget_show(GTK_WIDGET(label2));

    GtkEntry *entry1 = GTK_ENTRY(gtk_entry_new()), *entry2 = GTK_ENTRY(gtk_entry_new());
    gtk_grid_attach(grid, GTK_WIDGET(entry1), 1, 0, 3, 1);
    gtk_grid_attach(grid, GTK_WIDGET(entry2), 1, 1, 3, 1);
    gtk_widget_show(GTK_WIDGET(entry1));
    gtk_widget_show(GTK_WIDGET(entry2));

    GtkButton *bt1, *bt2;
    bt1 = GTK_BUTTON(gtk_button_new());
    bt2 = GTK_BUTTON(gtk_button_new());
    gtk_button_set_label(bt1, "登陆");
    gtk_button_set_label(bt2, "注册");
    gtk_grid_attach(grid, GTK_WIDGET(bt1), 0, 2, 1, 1);
    gtk_grid_attach(grid, GTK_WIDGET(bt2), 2, 2, 1, 1);
    gtk_widget_show(GTK_WIDGET(bt1));
    gtk_widget_show(GTK_WIDGET(bt2));

    gtk_widget_show(GTK_WIDGET(grid));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(grid));
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
