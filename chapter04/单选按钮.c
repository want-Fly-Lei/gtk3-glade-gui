#include <stdio.h>
#include <gtk/gtk.h>

int main() {
    gtk_init(NULL, NULL);
    GtkWindow * window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 1200, 800);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    // 创建box
    GtkBox *box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5));
    // 先创建一个标签
    GtkLabel *label = GTK_LABEL(gtk_label_new("你最喜欢的运动是："));
    gtk_widget_show(GTK_WIDGET(label));
    gtk_box_pack_start(box, GTK_WIDGET(label), FALSE, FALSE, 0);

    // 创建单选框
    GtkRadioButton *rbt = GTK_RADIO_BUTTON(gtk_radio_button_new_with_label(NULL, "游泳"));
    // 添加新的兄弟是from_widget的方法，保证他们是一组的
    GtkRadioButton *rbt2 = GTK_RADIO_BUTTON(gtk_radio_button_new_with_label_from_widget(rbt, "乒乓"));
    GtkRadioButton *rbt3 = GTK_RADIO_BUTTON(gtk_radio_button_new_with_label_from_widget(rbt, "跑步"));
    gtk_box_pack_start(box, GTK_WIDGET(rbt), FALSE, FALSE, 0); // 添加到盒子中
    gtk_box_pack_start(box, GTK_WIDGET(rbt2), FALSE, FALSE, 0);
    gtk_box_pack_start(box, GTK_WIDGET(rbt3), FALSE, FALSE, 0);
    gtk_widget_show(GTK_WIDGET(rbt)); // 显示出来
    gtk_widget_show(GTK_WIDGET(rbt2));
    gtk_widget_show(GTK_WIDGET(rbt3));

    gtk_widget_show(GTK_WIDGET(box));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(box));
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
