#include <stdio.h>

int main() {
    int i;
    // 创建指针指向i
    int *adder = &i;
    // 查看是否指向地址
    printf("i的地址是：%p\n", &i);
    printf("adder的值是：%p\n", adder);
    
    // 使用指针,因为是指向i，所以可以修改i的值
    *adder = 5;
    printf("i = %d, *adder = %d\n", i, *adder);
    // 同样因为adder是int *类型所以把取地址后把sizeof（int)大小个字节存放的值 加上 3 后赋值给w
    int w = *adder + 3;
    printf("w = %d\n", w);
    return 0;
}
