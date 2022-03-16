#include<stdio.h>
#include<gtk/gtk.h>//引库
int main() {
    //初始化gkt环境  
    gtk_init(NULL,NULL);

    //新建一个窗口（这里是顶级），返回窗口指针
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //设置窗口标题
    gtk_window_set_title(window,"hello,帅逼");

    //设定窗口关闭后程序退出，否则虽然看不到了，但是进程还在导致无法重新编译
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    //显示窗口
    gtk_widget_show(window);

    //启动消息循环，相当于c的system("pause")；就是持续等待
    gtk_main();
    return 0;
}