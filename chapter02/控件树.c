#include <stdio.h>
#include <gtk/gtk.h>
// 控件树，就是进行混合

int main() {
    gtk_init(NULL, NULL);
    GtkWindow *window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_position(window, GTK_WIN_POS_CENTER);
    gtk_window_set_title(window, "super Vscode");
    gtk_widget_set_size_request(GTK_WIDGET(window), 800, 600);
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
