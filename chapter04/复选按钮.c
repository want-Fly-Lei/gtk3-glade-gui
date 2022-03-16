#include<stdio.h>
#include<gtk/gtk.h>
GtkCheckButton * cb;
GtkButton * bt;

int checkButtonChecked(GtkWidget * widget, int data) {
    gtk_widget_set_sensitive(bt,gtk_toggle_button_get_active(cb));
}

int main() {
    gtk_init(NULL,NULL);
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,800,600);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    //创建box
    GtkBox * box = gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
    //创建复选框
    cb = gtk_check_button_new_with_label("我已同意"); //这里我直接给标题，省的多写一个函数
    //确定默认是否选中
    gtk_toggle_button_set_active(cb,FALSE);
    gtk_box_pack_start(box,cb,FALSE,FALSE,0);
    gtk_widget_show(cb);

    //创建按钮
    bt = gtk_button_new_with_label("登陆");
    gtk_box_pack_start(box,bt,FALSE,FALSE,0);
    gtk_widget_show(bt);
    //设置为禁用状态
    gtk_widget_set_sensitive(bt,FALSE);
    //当点击checkbutton后，登陆按钮可用
    g_signal_connect(cb,"clicked",checkButtonChecked,NULL);

    gtk_widget_show(box);
    gtk_container_add(window,box);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}