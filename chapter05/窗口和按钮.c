#include <stdio.h>
#include <gtk/gtk.h>

// 之前我们每加一个部件，就要show一下，show_all更加方便
int main() {
    gtk_init(NULL, NULL);
    GtkWindow *window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 400, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    // 设置边框
    gtk_container_set_border_width(GTK_CONTAINER(window), 5); // 这里设置的是5

    GtkButton *bt = GTK_BUTTON(gtk_button_new_with_label("click"));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(bt));
    // 因为使用的是show_all函数，所以只需要show一下父组件即可
    gtk_widget_show_all(GTK_WIDGET(window));
    // 同样对饮的也有隐藏
    // gtk_widget_hide(window);_all

    // 获取button中的内容
    const char * str = (const char *) gtk_button_get_label(bt);
    // 不知道为什么中文读取不出来
    printf("str = %s\n", str);
    gtk_main();
    return 0;
}
