#include <stdio.h>
#include <gtk/gtk.h>
GtkWindow *window;
GtkBox *box;
GtkComboBoxText *cbt1, *cbt2;
size_t len, i;
char *chongqing[] = {"巴南", "荣昌", "渝北", "铜梁", "九龙坡", "永川"};
char *beijing[] = {"朝阳", "西城", "丰台", "石景山", "海淀", "顺义"};
char *shanghai[] = {"黄浦", "徐汇", "长宁", "静安", "普陀", "虹口"};
const char *choice; 
char city[3];

static void cbjOnChanged(GtkWidget *widget, gpointer data) {
    // 先删除所有旧元素
    gtk_combo_box_text_remove_all(cbt2);
    choice = gtk_combo_box_get_active_id(GTK_COMBO_BOX(cbt1));
    switch (choice[0]) {
    case '0': {
        len = sizeof(chongqing) / sizeof(chongqing[0]);
        for (i = 0; i < len; ++i) {
            // 把数字(以10进制)转为字符串
            // linux 没有 itoa 函数
            // itoa(i, city, 10);
            sprintf(city, "%zd", i);
            gtk_combo_box_text_append(cbt2, city, chongqing[i]);
        }
        break;
    }

    case '1': {
        len = sizeof(shanghai) / sizeof(shanghai[0]);
        for (i = 0; i < len; ++i) {
            // itoa(i, city, 10);
            sprintf(city, "%zd", i);
            gtk_combo_box_text_append(cbt2, city, shanghai[i]);
        }
        break;
    }

    default: {
        len = sizeof(beijing) / sizeof(beijing[0]);
        for (i = 0; i < len; ++i) {
            // itoa(i, city, 10);
            sprintf(city, "%zd", i);
            gtk_combo_box_text_append(cbt2, city, beijing[i]);
        }
    }
    }
}

int main() {
    gtk_init(NULL, NULL);
    window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 800, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    // 创建盒子
    box = GTK_BOX(gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5));
    // 创建下拉选择框
    cbt1 = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
    // 添加下拉选项，第二个参数相当于id，第三个是显示的内容
    gtk_combo_box_text_append(cbt1, "0", "重庆");
    gtk_combo_box_text_append(cbt1, "1", "上海");
    gtk_combo_box_text_append(cbt1, "2", "北京");
    // 默认选择那个id
    // gtk_combo_box_set_active_id(cbt1, "0");

    gtk_box_pack_start(box, GTK_WIDGET(cbt1), FALSE, FALSE, 0);
    // 监听是否切换, 不加G_Callback函数是void (*)(void), 加了后
    g_signal_connect(cbt1, "changed", G_CALLBACK(cbjOnChanged), NULL);
    gtk_widget_show(GTK_WIDGET(cbt1));

    cbt2 = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
    gtk_box_pack_start(box, GTK_WIDGET(cbt2), FALSE, FALSE, 0);
    gtk_widget_show(GTK_WIDGET(cbt2));

    gtk_widget_show(GTK_WIDGET(box));
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(box));
    gtk_widget_show(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
