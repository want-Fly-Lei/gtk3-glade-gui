#include <gtk/gtk.h>
#include <stdio.h>
/*有一些事件没有一些，但是我们想给他添加事件，我们可以通过事件盒子的方式
事件盒子
1.创建盒子
2.给事件盒子添加事件
3.将其他控件放入事件盒子中
*/

gboolean box_click(GtkEventBox *box, GdkEventButton *event, gpointer user_data) {
    gtk_label_set_text(user_data, "box is clicked");
    return TRUE;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    GtkWindow *window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 400, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    // 创建时间盒子
    GtkEventBox *box = GTK_EVENT_BOX(gtk_event_box_new());
    // 创建子事件，这里我们选用entry
    GtkLabel *label = GTK_LABEL(gtk_label_new("hello"));
    // 把label加入到父盒子中
    gtk_container_add(GTK_CONTAINER(box), GTK_WIDGET(label));
    // 给盒子设置事件，这里是按下按下
    gtk_widget_set_events(GTK_WIDGET(box), GDK_BUTTON_PRESS_MASK);
    // 设置信号
    g_signal_connect(box, "button-press-event", G_CALLBACK(box_click), label);

    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(box));
    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
