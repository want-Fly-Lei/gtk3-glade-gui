#include <stdio.h>
#include <gtk/gtk.h>

GtkWindow *window;
GtkBox *box;

int main() {
    gtk_init(NULL, NULL);
    window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 1200, 800);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5));

    // 创建图片
    GtkImage *img = GTK_IMAGE(gtk_image_new());
    // 读取文件位置
    gtk_image_set_from_file(img, "../img/emo.ico");
    // 一步到位使用，gtk_image_new_from_file();

    gtk_box_pack_start(box, GTK_WIDGET(img), FALSE, FALSE, 0);
    gtk_widget_show(GTK_WIDGET(img));

    // gtk为我们内置了一部分图片,第一个是添加到那个控件，第二个是图标名，第三个是大小
    GtkImage *img2 = GTK_IMAGE(gtk_image_new());
    gtk_box_pack_start(box, GTK_WIDGET(img2), FALSE, FALSE, 0);
    // 废弃 api
    // gtk_image_set_from_stock(img2, GTK_STOCK_FILE, GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_image_set_from_icon_name(img2, "text-x-generic", GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_show(GTK_WIDGET(img2));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(box));
    gtk_widget_show(GTK_WIDGET(box));
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
