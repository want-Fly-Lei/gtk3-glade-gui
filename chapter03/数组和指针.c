#include<stdio.h>
int main() {
    int num[] = {1,2,4,7,10};
    int len = sizeof(num) / sizeof(int);
    int i;
    //从结果可以看出数组是连续分布的地址
    for(i = 0; i < len; i++) {
        printf("%p ",&num[i]);
    }
    printf("\n");
    //我们使用的字符串char数组也是同样的道理
    char ch[] = "hello, handsome boy";
    char * cptr = ch;
    //进行遍历输出
    while(*cptr != '\0') {
        //通过指针移动来进行获取内容
        printf("%c",*cptr);
        //指针的±n，是 ± n * sizeof(该类型去掉一个星号)
        ++cptr;
    }
    printf("\n");

    cptr = ch;
    //使用*(指针 + n)可以获取到数组第n个值
    printf("%c",*(cptr + 3));
    return 0;
}