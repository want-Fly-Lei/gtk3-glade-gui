#include<stdio.h>
#include<gtk/gtk.h>
#include<time.h>
//做一个数字时钟
GtkWindow * window;
GtkEntry * entry;
int hour,min,second;
char nowTime[20];
//存放格林威治时间
time_t sysTime;
//结构体存放了当前时间的各种信息
struct tm * localTime;
gboolean myClock(gpointer data) {
    second++;
    if(second == 60) {
        second = 0;
        min++;
    }
    if(min == 60) {
        min = 0;
        hour++;
    }
    if(hour == 24) {
        hour = 0;
    }
    sprintf(nowTime,"现在时间是:%02d:%02d:%02d",hour,min,second);
    gtk_entry_set_text(entry,nowTime);
    return TRUE;
}

int main() {
    gtk_init(NULL,NULL);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,1600,900);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    entry = gtk_entry_new();
    gtk_widget_show(entry);
    gtk_container_add(window,entry);
    //先进性初始化,获取当前时间
    time(&sysTime);
    localTime = localtime(&sysTime);
    hour = localTime->tm_hour;
    min = localTime->tm_min;
    second = localTime->tm_sec;
    //第一个参数时设置没多少ms执行一次函数，
    g_timeout_add(1000,myClock,NULL);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}