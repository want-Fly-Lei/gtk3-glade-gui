#include <gtk/gtk.h>
#include <stdio.h>
//介绍鼠标单击和鼠标移动事件

//鼠标点击事件,gtkevent的事件貌似要传三个参数
gboolean windowClick(GtkWidget * widget, GdkEventButton * event ,gpointer user_data) {
    //获取鼠标事件
    int choice = event->button;
    switch(choice) {
        case 1: {
            printf("left button ");
            break;
        }
        case 2: {
            printf("middle button ");
            break;
        }
        case 3: {
            printf("right button ");
            break;
        }
        default:
        printf("other ");
    }
    //判断点击数
    choice = event->type;
    if(choice == GDK_BUTTON_PRESS) {
        printf("one click ");//单击 
    } else if(choice == GDK_2BUTTON_PRESS) {
        printf("double clicks ");//双击 
    } else if(choice == GDK_3BUTTON_PRESS) {
        printf("tree clicks ");//三击 
    }
    //获取鼠标位置
    printf("x = %.2lf, y = %.2lf\n",event->x,event->y);
    return TRUE;
}

//鼠标移到事件
gboolean windowMove(GtkWidget * widget, GdkEventMotion * event ,gpointer user_data) {
    //这里的移动时拖拉这window才算
    printf("mouses location: x = %.2lf, y = %.2lf",event->x,event->y);
}

int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    GtkWindow *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window, 400, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);
    gtk_container_set_border_width(window, 5);

    //有一些控件没有对应的相应事件，这里给给控件（这里是窗口）添加相应事件
    /*一些常用的如下
        GDK_BUTTON_PRESS_MASK 鼠标点击
        GDK_BUTTON_RELEASE_MASK 鼠标释放
        GDK_BUTTON_MOTION_MASK 鼠标移动
        GDK_KEY_PRESS_MASK 键盘按下
        GDK_ENTER_NOTIFY_MASK 进入控件区域*/
    //不同的事件可以通过|操作来实现多级，这里添加窗口点击和移动
    gtk_widget_add_events(window,GDK_BUTTON_PRESS_MASK | GDK_BUTTON_MOTION_MASK);

    //设置信号,鼠标点击事件，gtkevent需要回调函数传入三个参数才行
    g_signal_connect(window,"button-press-event",windowClick,NULL);
    //鼠标移动事件
    g_signal_connect(window,"motion-notify-event",windowMove,NULL);

    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}