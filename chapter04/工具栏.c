#include <stdio.h>
#include <gtk/gtk.h>
GtkToolbar *bar;
GtkWindow *window;
GtkBox *box;
GtkToolItem *item, *item2;

int main() {
    gtk_init(NULL, NULL);
    window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 1200, 800);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);
    box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5));

    // 创建 toolbar
    bar = GTK_TOOLBAR(gtk_toolbar_new());
    gtk_box_pack_start(box,  GTK_WIDGET(bar), FALSE, FALSE, 0);
    gtk_widget_show(GTK_WIDGET(bar));

    // 创建其中一个item
    item = gtk_tool_button_new(NULL, "保存");
    // 设置图标
    // 废弃的api
    // gtk_tool_button_set_stock_id(GTK_TOOL_BUTTON(item), GTK_STOCK_SAVE);
    // 新 api
    gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(item), "document-save");

    // 加入bar中
    gtk_toolbar_insert(bar, item, 0);
    gtk_widget_show(GTK_WIDGET(item)); // 显示

    // 创建第二个
    item2 = GTK_TOOL_ITEM(gtk_tool_button_new(NULL, "剪切"));
    // 废弃api
    // gtk_tool_button_set_stock_id(item2, GTK_STOCK_CUT);
    gtk_tool_button_set_icon_name(GTK_TOOL_BUTTON(item2), "edit-cut");
    gtk_toolbar_insert(bar, item2, 1); // 应该是下一个位置
    gtk_widget_show(GTK_WIDGET(item2));

    gtk_widget_show(GTK_WIDGET(box));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(box));
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
