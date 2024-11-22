#include <stdio.h>
#include <gtk/gtk.h>
GtkCheckButton *cb;
GtkButton *bt;

static void checkButtonChecked() {
    gtk_widget_set_sensitive(GTK_WIDGET(bt), gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cb)));
}

int main() {
    gtk_init(NULL, NULL);
    GtkWindow *window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 800, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    // 创建box
    GtkBox *box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_VERTICAL, 5));
    // 创建复选框
    cb = GTK_CHECK_BUTTON(gtk_check_button_new_with_label("我已同意")); // 这里我直接给标题，省的多写一个函数
    // 确定默认是否选中
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cb), FALSE);
    gtk_box_pack_start(box, GTK_WIDGET(cb), FALSE, FALSE, 0);
    gtk_widget_show(GTK_WIDGET(cb));

    // 创建按钮
    bt = GTK_BUTTON(gtk_button_new_with_label("登陆"));
    gtk_box_pack_start(box, GTK_WIDGET(bt), FALSE, FALSE, 0);
    gtk_widget_show(GTK_WIDGET(bt));
    // 设置为禁用状态
    gtk_widget_set_sensitive(GTK_WIDGET(bt), FALSE);
    // 当点击 check button 后，登陆按钮可用
    g_signal_connect(cb, "clicked", checkButtonChecked, NULL);

    gtk_widget_show(GTK_WIDGET(box));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(box));
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
