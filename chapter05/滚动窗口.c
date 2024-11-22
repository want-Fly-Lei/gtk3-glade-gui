#include <stdio.h>
#include <gtk/gtk.h>

// 滚动窗口，这样我们查看文本就可以移动了

int main() {
    gtk_init(NULL, NULL);
    GtkWindow *window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_window_set_resizable(window, TRUE);
    gtk_window_set_position(window, GTK_WIN_POS_CENTER_ALWAYS);
    gtk_widget_set_size_request(GTK_WIDGET(window), 800, 600);
    gtk_window_set_title(window, "super Vscode");
    g_signal_connect(window, "destroy", gtk_main_quit, NULL);

    // 创建滚动条,第一个参数水平调节的对象，第二个是垂直的，一般传入null
    GtkScrolledWindow *srcWind = GTK_SCROLLED_WINDOW(gtk_scrolled_window_new(NULL, NULL));
    gtk_container_set_border_width(GTK_CONTAINER(srcWind), 10); // 设置滑动条宽度
    // 添加滚动条到窗口
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(srcWind));
    // 设置滚动条出现的方式
    /*第一是设置水平滚动条，第二个是垂直滚动条
    GTK_POLICY_AUTOMATIC 自动决定是否出现滚动条
    GTK_POLICY_ALWAYS 滚动条始终存在
    GTK_POLICY_NEVER，滚动条永远不存在*/
    gtk_scrolled_window_set_policy(srcWind, GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    // 添加一个label； \的换行用的，就是可以把字符串连接起来
    GtkLabel *label = GTK_LABEL(gtk_label_new("this is sample,hahahhahahaha sjdndkncklcsdmcksdmcvslcjdklclmcc"
                                              "fsfm lsfjsf ;safks;f ;lasfkls;fksl;fksd'fofjskjfjdkjfsljlsdk"
                                              "fjdsklfjdklfjsklfjslfjslkdfjdslf"
                                              ";asfja;fjsa;fjs;fjsd;fjso;fdsl;f;poiffjvjnldcnslooewiueuifhjfhjfhsfj"
                                              "  msfmnkn ksmfls lkdfmfmn"
                                              "oj ; sfsamf s ; sd f s;dlcks;  ;f ks;ksldvkdlv  s;lkfsdlfksl"
                                              "vcsldvkslfk ldsfmv;sl slflflvcvmdl"
                                              "soafdkjsaofjksdaofoj ksdjsadka  c;sf kls fsl dfs fcs;dlkcsdkvsdl;"
                                              ";kvcs'c ;fksdfkcs'';vks"
                                              "sahfdhsa ca ae sai dsf jf  kfnslfnkdsl"
                                              "sfijsfijsf awo rjw jfwsfjs jmm"));

    // 设置自动换行
    gtk_label_set_line_wrap(label, TRUE);
    // 组件添加到滚动窗口中,这个貌似和其他添加不太一样
    // 废弃 api
    // gtk_scrolled_window_add_with_viewport(srcWind, GTK_WIDGET(label));
    gtk_container_add(GTK_CONTAINER(srcWind), GTK_WIDGET(label));
    gtk_widget_show_all(GTK_WIDGET(window));
    gtk_main();
    return 0;
}
