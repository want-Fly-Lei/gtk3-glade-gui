#include <stdio.h>
#include <gtk/gtk.h>
GtkWindow *window;
GtkBox *box;
GtkComboBoxText *cbt;
GtkLabel *label;

int cbjOnChanged(GtkWidget *widget, int data) {
    gtk_label_set_text(label, gtk_combo_box_text_get_active_text(cbt));
    // gtk_combo_box_get_active_id()也可以这样获取id
}

int main() {
    gtk_init(NULL, NULL);
    window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 800, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    // 创建盒子
    box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5));
    // 创建下拉选择框
    cbt = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
    // 添加下拉选项，第二个参数相当于id，第三个是显示的内容
    gtk_combo_box_text_append(cbt, "1", "hello");
    gtk_combo_box_text_append(cbt, "2", "thank");
    gtk_combo_box_text_append(cbt, "3", "welcome");
    // 默认选择那个id
    gtk_combo_box_set_active_id(GTK_COMBO_BOX(cbt), "2");
    gtk_box_pack_start(box, GTK_WIDGET(cbt), FALSE, FALSE, 0);
    // 监听是否切换
    g_signal_connect(cbt, "changed", G_CALLBACK(cbjOnChanged), NULL);
    gtk_widget_show(GTK_WIDGET(cbt));

    label = GTK_LABEL(gtk_label_new(""));
    gtk_box_pack_start(box, GTK_WIDGET(label), FALSE, FALSE, 0);
    gtk_widget_show(GTK_WIDGET(label));

    gtk_widget_show(GTK_WIDGET(box));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(box));
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
