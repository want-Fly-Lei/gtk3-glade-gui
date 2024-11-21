#include <gtk/gtk.h>
// #include<gladeui/glade.h>//这根可以网上没教程，不会用了
// 我们通过GtkBuilder来实现

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWindow *window = NULL;
    // 载入并新建整个界面
    GtkBuilder *bu = gtk_builder_new();
    // 把glade加入到项目中
    gtk_builder_add_from_file(bu, "./第一个项目.glade", NULL);
    window = GTK_WINDOW(gtk_builder_get_object(bu, "window"));

    g_signal_connect(window, "destroy", gtk_main_quit, NULL);
    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
