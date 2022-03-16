#include<stdio.h>
#include<malloc.h>
//这里案例是其次，主要是直到可以函数返回指针类型，从而实现，函数返回多个值
int * revsal(int num) {
    if(num >= 100 && num <= 999) {
        //开辟空间
        int * arr = (int *)malloc(sizeof(int) * 3);
        for(int i = 0; i < 3; i++) {
            arr[i] = num % 10;
            num /= 10;
        }
        return arr;
    }
    return NULL;
}

int main() {
    int num;
    printf("请输入一个三位数的数字\n");
    scanf("%d",&num);
    int *re = revsal(num);
    if(re != NULL) {
        printf("%d %d %d\n",*re,*(re + 1), *(re + 2));
        //释放空间
        free(re);
    } else {
        printf("你的输入不合法\n");
    }
    return 0;
}