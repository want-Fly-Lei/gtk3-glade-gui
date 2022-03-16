#include<stdio.h>
#include<gtk/gtk.h>
#include<string.h>
//本代码接受输入数据，经过转换输出和设置出密码*的效果
GtkLabel * label1, * label2;
GtkEntry * entry;
GtkButton * bt1, * bt2;
char * buffer, newBuffer[20];
const char * str = "经过科学的计算你的身高是";

int btClick(GtkWidget * widget, int data){//监听点击事件
    buffer = gtk_entry_get_text(entry);//获取文本框内容
    // strcpy(newBuffer,str);
    // strcat(newBuffer,buffer);
    // strcat(newBuffer,"cm");
    //显示使用sprintf函数要少使用很多其他函数
    sprintf(newBuffer,"%s%scm",str,buffer);
    gtk_label_set_text(label2,newBuffer);
}

int hideOrShow(GtkWidget * widget, int data) {
    //获取和设置是否隐藏文本框内容
    gtk_entry_set_visibility(entry,!gtk_entry_get_visibility(entry));
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
    GtkBox * box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,5);

    label1 = gtk_label_new("请输入你的身高（cm）");
    gtk_box_pack_start(box,label1,FALSE,FALSE,0);
    gtk_widget_show(label1);

    entry = gtk_entry_new();
    gtk_widget_show(entry);
    //设置最大输入长度为5
    gtk_entry_set_max_length(entry,5);
    //设置是否可以进行编辑
    gtk_editable_set_editable(entry,TRUE);
    gtk_box_pack_start(box,entry,FALSE,FALSE,0);
    //如果想要限定输入的是数字，那么就必须使用g_signal_connect函数，在自己编写函数即可
    //信号是"insert-text";自己的函数把非数字的给过滤了就行

    bt1 = gtk_button_new_with_label("计算");
    gtk_box_pack_start(box,bt1,FALSE,FALSE,0);
    gtk_widget_show(bt1);
    //进行计算
    g_signal_connect(bt1,"clicked",btClick,NULL);

    bt2 = gtk_button_new_with_label("显示");
    gtk_box_pack_start(box,bt2,FALSE,FALSE,0);
    gtk_widget_show(bt2);
    //是否隐藏
    g_signal_connect(bt2,"clicked",hideOrShow,NULL);

    label2 = gtk_label_new("0cm");
    gtk_box_pack_start(box,label2,FALSE,FALSE,0);
    gtk_widget_show(label2);

    gtk_widget_show(box);
    gtk_container_add(window,box);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}