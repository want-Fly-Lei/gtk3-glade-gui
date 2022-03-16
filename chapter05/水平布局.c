#include<stdio.h>
#include<gtk/gtk.h>
//相对于box布局，我们还有hbox（水平布局），vbox（垂直布局），table（表格布局），fixed（固定布局）
//他们比起box更容易理解
GtkButton * bt1, * bt2, * bt3;
int main() {
    gtk_init(NULL,NULL);
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,400,600);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    //创建水平布局
    //第一个参数时容器内空间是否均匀排放（大小一致），第二个就是间距
    GtkHBox * hb = gtk_hbox_new(TRUE,5);
    //添加按钮
    bt1 = gtk_button_new_with_label("hello");
    //添加就是要容器添加即可
    gtk_container_add(hb,bt1);
    bt2 = gtk_button_new_with_label("super");
    gtk_container_add(hb,bt2);
    bt3 = gtk_button_new_with_label("handsome");
    gtk_container_add(hb,bt3);

    gtk_container_add(window,hb);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}