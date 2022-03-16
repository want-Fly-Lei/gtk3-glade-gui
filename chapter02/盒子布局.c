#include<stdio.h>
#include<gtk/gtk.h> 
//之前我们学习了三大控件，但是因为一个容器只能包含一个控件，所以我们来学习盒子布局，来显示多个控件
int main() {
    gtk_init(NULL,NULL);
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,800,600);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    //创建盒子，在这些东西显示之前
    GtkBox * box = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);//布局方式和间距

    //添加按钮进入
    GtkButton * bu = gtk_button_new();
    gtk_button_set_label(bu,"welcome");

    //把按钮添加到盒子中，start是前往后加而end是从后向前加
    gtk_box_pack_start(box,bu,FALSE,FALSE,0);
    gtk_widget_show(bu);

    //添加标签
    GtkLabel * label = gtk_label_new("hello,帅逼");
    gtk_box_pack_start(box,label,FALSE,FALSE,0);
    gtk_widget_show(label);

    //添加文本框
    GtkEntry * entry = gtk_entry_new();
    gtk_box_pack_start(box,entry,FALSE,FALSE,0);
    gtk_widget_show(entry);

    gtk_widget_show(box);//显示盒子（虽然不可见，但是你不显示，他无法显示子控件

    //最后一步把盒子添加到window中来显示出来
    gtk_container_add(window,box);
    gtk_widget_show(window);

    

    gtk_main();
    return 0;
}