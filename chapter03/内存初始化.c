#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char chs[20];

int main() {
    printf("未初始化数组时候\n");
    int i, len;
    // 获取数组长度
    len = sizeof(chs) / sizeof(char);
    // 如果是字符串可以使用strlen，但是如果作为字符数组就算了吧
    // len = strlen(ch);
    for (i = 0; i < len; ++i) {
        printf("%hhd ", chs[i]);
    }

    puts("\n初始化数组后");
    memset(chs, 0, len);
    for (i = 0; i < len; ++i) {
        printf("%hhd ", chs[i]);
    }
    putchar('\n');
    return 0;
}
