#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ch[20];
int main() {
    printf("未初始化数组时候\n");
    int i, len;
    //获取数组长度
    len = sizeof(ch) / sizeof(char);
    //如果是字符串可以使用strlen，但是如果作为字符数组就算了吧
    //len = strlen(ch);
    for(i = 0; i < len; i++) {
        printf("%d",ch[i]);
    }
    printf("\n初始化数组后\n");
    memset(ch,0,len);
    for(i = 0; i < len; i++) {
        printf("%d",ch[0]);
    }
    printf("\n");
    return 0;
}