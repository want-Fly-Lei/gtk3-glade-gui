#include <gtk/gtk.h>
#include <stdio.h>
#include <gdk/gdkkeysyms.h> //键盘头文件
// 介绍键盘事件

// 打印键盘值
gboolean keyboardPrint(GtkWidget *widget, GdkEventKey *event, gpointer user_data) {
    switch (event->keyval) {
    case GDK_KEY_Up: {
        puts("up"); // 上键
        break;
    }

    case GDK_KEY_Down: {
        puts("down"); // 下键
        break;
    }

    case GDK_KEY_Q: {
        puts("Q"); // 大写字母Q
        break;
    }

    case GDK_KEY_q: {
        puts("q"); // 小写字母q
        break;
    }

    default: {
        printf("other letter %u\n", event->keyval);
    }
    }
    return TRUE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWindow *window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 400, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    // 键盘监控默认是开启的，所以只需要信号监听即可
    g_signal_connect(window, "key-press-event", G_CALLBACK(keyboardPrint), NULL);

    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
