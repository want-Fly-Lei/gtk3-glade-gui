#include<stdio.h>
//因为在同样位数的机器中指针的大小都一致（32位4个字节，64位八个字节）
//个人觉得void最好的好处就是任何类型的指针都可以直接赋值给 void 指针，而无需进行其他相关的强制类型转换
//例子比如我们常用很多函数比如void * memset(void * dest, int ch, int n);
//因为void*表示不知道类型的指针，所以你必须转黄才能使用（赋值，++，--等等），除了在泛型编程中有用，其他就这样吧
int main() {
    int num = 12;
    void * ptr = &num;
    printf("void指针长度为%d\n",sizeof(ptr));
    //*ptr = 14;//错误，void指针，必须先转换才能使用
    int * pp = ptr;
    *pp = 20;
    printf("pp = %d\n",*pp);
    return 0;
}