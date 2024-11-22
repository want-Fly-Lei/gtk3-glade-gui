#include <stdio.h>
#include <gtk/gtk.h>
// GTK3 我也不知道为什么，按钮不显示图片
// gtk_image_new_from_stock()来创建图像，但这个方法在GTK3中已经被废弃了。
// GTK3引入了新的图标主题系统，使用 GtkIconTheme 和 GtkIconInfo 来加载图标。这就是为什么您的按钮不显示图片的原因。
// 我们先使用 gtk_image_new_from_icon_name 函数

// 创建一个水平的盒子，里面是图标和带标签的盒子， 在把盒子放入按钮中
static GtkButton* my_new_hbox_button_with_label_and_icon(const char * label_name, const char * icon_name);

// 没内容显示
int main() {
    gtk_init(NULL, NULL);
    GtkWindow * window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 1200, 800);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    GtkGrid * grid = GTK_GRID(gtk_grid_new());

    // 创建并添加按钮
    // button1 = GTK_BUTTON(gtk_button_new());
    // gtk_button_set_label(button1, "保存");

    // gtk2 的方法
    // img1 = GTK_IMAGE(gtk_image_new_from_stock(GTK_STOCK_SAVE, GTK_ICON_SIZE_LARGE_TOOLBAR));

    // 新的方法
    // GTK_STOCK_SAVE
    GtkButton * button1 = my_new_hbox_button_with_label_and_icon("保存", "document-save");

    // 设置图片相对按钮的位置（默认左边）
    // gtk_button_set_image_position(button1, GTK_POS_RIGHT);
    // gtk_widget_show((GtkWidget *)button1);
    gtk_grid_attach(grid, GTK_WIDGET(button1), 3, 1, 8, 8);


    // 我是真不知道为什么无法打开第二个图标
    GtkButton * button2 = my_new_hbox_button_with_label_and_icon("剪切", "edit-cut");

    // gtk_widget_show((GtkWidget *)button2);
    gtk_grid_attach(grid, GTK_WIDGET(button2), 3, 13, 8, 8);


    gtk_widget_show(GTK_WIDGET(grid));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(grid));
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}

static GtkButton* my_new_hbox_button_with_label_and_icon(const char *label_name, const char *icon_name) {  
    GtkBox *hbox = GTK_BOX(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5));
    // 创建空按钮
    GtkButton * btn = GTK_BUTTON(gtk_button_new());
    // 貌似文字和图标都有容易出问题， 所以选择在水平盒子中
    // gtk_button_set_image(btn, GTK_IMAGE(gtk_image_new_from_icon_name(icon_name, GTK_ICON_SIZE_BUTTON)));

    // 创建标签
    GtkLabel * label = GTK_LABEL(gtk_label_new(label_name));
    // 创建图标
    GtkImage * img = GTK_IMAGE(gtk_image_new_from_icon_name(icon_name, GTK_ICON_SIZE_BUTTON));

    // 加入水平盒子, 先加的在前
    gtk_box_pack_start(hbox, GTK_WIDGET(img), FALSE, FALSE, 0);
    gtk_box_pack_start(hbox, GTK_WIDGET(label), TRUE, FALSE, 0);

    // 把盒子添加到按钮上
    gtk_container_add(GTK_CONTAINER(btn), GTK_WIDGET(hbox));
    // 逐一 show 太麻烦了
    gtk_widget_show_all(GTK_WIDGET(btn));
    return btn;
}  
