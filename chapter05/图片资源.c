#include<stdio.h>
#include<gtk/gtk.h>
GtkButton * bt1, * bt2, * bt3;
int main() {
    gtk_init(NULL,NULL);
    GtkWindow * window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,400,600);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    //创建图片资源,第一个是图片位置，第二个参数是错误内容指针
    //图片来源
    GdkPixbuf * src_pbuf = gdk_pixbuf_new_from_file("../img/kid.jpg",NULL);
    //图片资源目的地，顺便设置图片大小，最后一个参数标志着图片加载的速度和质量
    GdkPixbuf * dest_pbuf = gdk_pixbuf_scale_simple(src_pbuf,571,342,GDK_INTERP_BILINEAR);
    //释放资源
    g_object_unref(src_pbuf);

    //gtkimage通过图片文件
    GtkImage * img = gtk_image_new_from_pixbuf(dest_pbuf);

    //图片控件重新设置一张图片
    gtk_image_set_from_pixbuf(img,dest_pbuf);

    //清除图像数据
    //gtk_image_clear(img);

    //创建表格布局容器
    GtkTable * table = gtk_table_new(7,7,TRUE);
    bt1 = gtk_button_new_with_label("hello");
    gtk_table_attach_defaults(table,bt1,1,2,6,7);

    bt2 = gtk_button_new_with_label("thank");
    gtk_table_attach_defaults(table,bt2,5,6,6,7);

    bt3 = gtk_button_new_with_label("you");
    gtk_table_attach_defaults(table,bt3,0,2,1,2);
    //把图片添加进去
    gtk_table_attach_defaults(table,img,1,6,1,6);

    gtk_container_add(window,table);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}