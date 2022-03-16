#include<stdio.h>
#include<gtk/gtk.h>
//进度条的使用
GtkButton * bt1, * bt2, * bt3;
char str[20];
int fraction;
//按钮1事件
void bt1Click(GtkButton * bt,gpointer user_data) {
    fraction = gtk_progress_bar_get_fraction(user_data) * 10;
    fraction++;
    if(fraction > 10) {
        fraction = 10;
    } else{
        gtk_progress_bar_set_fraction(user_data,fraction * 0.1);
        sprintf(str,"当前进度是%d%%",fraction * 10);
        gtk_progress_bar_set_text(user_data,str);
    }
}

//按钮2事件
void bt2Click(GtkButton * bt,gpointer user_data) {
    fraction = gtk_progress_bar_get_fraction(user_data) * 10;
    fraction--;
    if(fraction < 0) {
        fraction = 0;
    } else {
        gtk_progress_bar_set_fraction(user_data,fraction * 0.1);
        sprintf(str,"当前进度是%d%%",fraction * 10);
        gtk_progress_bar_set_text(user_data,str);
    }
}

//按钮3事件
void bt3Click(GtkButton * bt,gpointer user_data) {
    //位置进度条反转,第二个参数，true表示从后到前，所以每一次需要取前一次的相反值，我都是看官方文档看的
    gtk_progress_bar_set_inverted(user_data,!gtk_progress_bar_get_inverted(user_data));
}

int main() {
    gtk_init(NULL,NULL);
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,400,600);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);
    gtk_container_set_border_width(window,5);

    GtkVBox * vbox = gtk_vbox_new(TRUE,5);

    bt1 = gtk_button_new_with_label("快进");
    bt2 = gtk_button_new_with_label("倒退");
    bt3 = gtk_button_new_with_label("切换方向");

    //创建进度条
    GtkProgressBar * bar = gtk_progress_bar_new();
    //设置进度0-1.0
    gtk_progress_bar_set_fraction(bar,0.0);

    //进度条文本设置
    //首先需要设置可以显示
    gtk_progress_bar_set_show_text(bar,TRUE);
    //如果不设置就是n%，其实我觉得挺好的，改了还要写其他函数
    gtk_progress_bar_set_text(bar,"当前进度是0%");
    //设置进度条移动方向(默认左到右)，垃圾函数好像被删除了，不过看我第三个函数也可以解决
    //gtk_progress_bar_set_orientation(bar,GTK_PROGRESS_LEFT_TO_RIGHT);
    gtk_container_add(vbox,bar);
    gtk_container_add(vbox,bt1);
    g_signal_connect(bt1,"clicked",bt1Click,bar);
    gtk_container_add(vbox,bt2);
    g_signal_connect(bt2,"clicked",bt2Click,bar);
    gtk_container_add(vbox,bt3);
    g_signal_connect(bt3,"clicked",bt3Click,bar);

    gtk_container_add(window,vbox);

    gtk_widget_show_all(window);

    gtk_main();
    return 0;
}