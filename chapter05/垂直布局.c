#include <stdio.h>
#include <gtk/gtk.h>

// GtkVBox deprecated: 3.2 使用 GtkBox即可
// 和水平布局类似
GtkButton *bt1, *bt2, *bt3;

int main() {
    gtk_init(NULL, NULL);
    GtkWindow *window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 400, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    // 创建垂直布局，感觉和水平的一样的
    // 第一个参数时容器内空间是否均匀排放（大小一致），第二个就是间距
    // GtkVBox *vb = GTK_VBOX(gtk_vbox_new(TRUE, 5));
    // 废弃 api， 使用 box 创建即可初始化
    GtkBox * vb = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 5));
    bt1 = GTK_BUTTON(gtk_button_new_with_label("hello"));
    gtk_container_add(GTK_CONTAINER(vb), GTK_WIDGET(bt1));
    bt2 = GTK_BUTTON(gtk_button_new_with_label("super"));
    gtk_container_add(GTK_CONTAINER(vb), GTK_WIDGET(bt2));
    bt3 = GTK_BUTTON(gtk_button_new_with_label("handsome"));
    gtk_container_add(GTK_CONTAINER(vb), GTK_WIDGET(bt3));

    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(vb));
    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
