#include<stdio.h>
#include<gtk/gtk.h>
GtkToolbar * bar;
GtkWindow * window;
GtkBox * box;
GtkToolItem * item, * item2;

int main() {
    gtk_init(NULL,NULL);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,1600,900);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);
    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);

    //创建toolbar
    bar = gtk_toolbar_new();
    gtk_box_pack_start(box,bar,FALSE,FALSE,0);
    gtk_widget_show(bar);

    //创建其中一个item
    item = gtk_tool_button_new(NULL,"保存");
    //设置图标
    gtk_tool_button_set_stock_id(item,GTK_STOCK_SAVE);
    //加入bar中
    gtk_toolbar_insert(bar,item,0);
    gtk_widget_show(item);//显示

    //创建第二个
    item2 = gtk_tool_button_new(NULL,"剪切");
    gtk_tool_button_set_stock_id(item2,GTK_STOCK_CUT);
    gtk_toolbar_insert(bar,item2,1);//应该是下一个位置
    gtk_widget_show(item2);

    gtk_widget_show(box);
    gtk_container_add(window,box);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}