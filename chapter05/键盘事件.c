#include <gtk/gtk.h>
#include <stdio.h>
#include<gdk/gdkkeysyms.h>//键盘头文件
//介绍键盘事件

gboolean keyboardPrint(GtkWidget * widget, GdkEventKey * event,gpointer user_data) {
    if(event->keyval == GDK_KEY_Up) {
        printf("up ");//上键
    } else if(event->keyval == GDK_KEY_Down) {
        printf("down ");//下键
    } else if(event->keyval == GDK_KEY_Q) {
        printf("Q ");//大写字母Q
    } else if(event->keyval == GDK_KEY_q) {
        printf("q ");//小写字母q
    } else {
        printf("other letter ");
    }
    return TRUE;
}

int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    GtkWindow *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window, 400, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);
    gtk_container_set_border_width(window, 5);

    //键盘监控默认是开启的，所以只需要信号监听即可
    g_signal_connect(window, "key-press-event", keyboardPrint, NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}