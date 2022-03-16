#include<stdio.h>
#include<gtk/gtk.h>
GtkWindow * window;
GtkGrid * grid;
GtkButton * button1, * button2;
GtkImage * img1, * img2;
//我也不知道为什么，按钮不显示图片
int main() {
    gtk_init(NULL,NULL);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(window,TRUE);
    gtk_window_set_position(window,GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(window,1600,900);
    gtk_window_set_title(window,"super Vscode");
    g_signal_connect(window,"destroy",gtk_main_quit,NULL);

    grid = gtk_grid_new();
    
    button1 = gtk_button_new();
    gtk_button_set_label(button1,"保存");
    img1 = gtk_image_new_from_stock(GTK_STOCK_SAVE,GTK_ICON_SIZE_LARGE_TOOLBAR);
    gtk_widget_show(img1);
    //把图片加入到按钮中
    gtk_button_set_image(button1,img1);
    //按钮背景色透明
    gtk_button_set_relief(button1,GTK_RELIEF_NONE);
    
    //设置图片相对按钮的位置（默认左边）
    gtk_button_set_image_position(button1,GTK_POS_RIGHT);
    gtk_widget_show(button1);
    gtk_grid_attach(grid,button1,3,1,8,8);

    button2 = gtk_button_new_with_label("剪切");

    img2 = gtk_image_new_from_stock(GTK_STOCK_CUT,GTK_ICON_SIZE_BUTTON);
    gtk_widget_show(img2);
    gtk_button_set_image(button2,img2);
    gtk_button_set_image_position(button2,GTK_POS_RIGHT);
    gtk_widget_show(button2);
    gtk_grid_attach(grid,button2,3,12,8,8);
    gtk_button_set_relief(button2,GTK_RELIEF_NONE);

    gtk_widget_show(grid);
    gtk_container_add(window,grid);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}