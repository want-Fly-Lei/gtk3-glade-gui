#include<stdio.h>
#include<gtk/gtk.h>

int main() {
    gtk_init(NULL,NULL);
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,800,600);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    //创建box
    GtkBox * box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);
    //先创建一个标签
    GtkLabel * label = gtk_label_new("你最喜欢的运动是：");
    gtk_widget_show(label);
    gtk_box_pack_start(box,label,FALSE,FALSE,0);

    //创建单选框
    GtkRadioButton * rbt = gtk_radio_button_new_with_label(NULL,"游泳");
    //添加新的兄弟是from_widget的方法，保证他们是一组的
    GtkRadioButton * rbt2 = gtk_radio_button_new_with_label_from_widget(rbt,"乒乓");
    GtkRadioButton * rbt3 = gtk_radio_button_new_with_label_from_widget(rbt,"跑步");
    gtk_box_pack_start(box,rbt,FALSE,FALSE,0);//添加到盒子中
    gtk_box_pack_start(box,rbt2,FALSE,FALSE,0);
    gtk_box_pack_start(box,rbt3,FALSE,FALSE,0);
    gtk_widget_show(rbt);//显示出来
    gtk_widget_show(rbt2);
    gtk_widget_show(rbt3);

    gtk_widget_show(box);
    gtk_container_add(window,box);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}