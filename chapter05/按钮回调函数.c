#include <stdio.h>
#include <gtk/gtk.h>

// 关于函数回调的细节
char *str;

// 一般的回调函数是这种类型， 加 static 是为了避免装库
// 还有这种回调函数
// void my_callback(GtkWidget * widget, GdkEvent * event, gpointer user_data);
static void printStr(GtkButton *bu, gpointer user_data) {
    str = (char *) user_data;
    printf("str = %s\n", str);
}

int main() {
    gtk_init(NULL, NULL);
    GtkWindow *window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 400, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    GtkButton *bt = GTK_BUTTON(gtk_button_new_with_label("click"));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(bt));
    // 第一个参数和第四个参数就是第三个参数（函数名）的传入参数，第二个参数是触发条件
    // G_CALLBACK 避免编译时候回调函数错误
    g_signal_connect(bt, "clicked", G_CALLBACK(printStr), "hello");
    gtk_widget_show_all(GTK_WIDGET(window));

    gtk_main();
    return 0;
}
