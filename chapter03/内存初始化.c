#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ch[20];
int main() {
    printf("δ��ʼ������ʱ��\n");
    int i, len;
    //��ȡ���鳤��
    len = sizeof(ch) / sizeof(char);
    //������ַ�������ʹ��strlen�����������Ϊ�ַ���������˰�
    //len = strlen(ch);
    for(i = 0; i < len; i++) {
        printf("%d",ch[i]);
    }
    printf("\n��ʼ�������\n");
    memset(ch,0,len);
    for(i = 0; i < len; i++) {
        printf("%d",ch[0]);
    }
    printf("\n");
    return 0;
}