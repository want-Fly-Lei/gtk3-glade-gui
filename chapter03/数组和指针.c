#include<stdio.h>
int main() {
    int num[] = {1,2,4,7,10};
    int len = sizeof(num) / sizeof(int);
    int i;
    //�ӽ�����Կ��������������ֲ��ĵ�ַ
    for(i = 0; i < len; i++) {
        printf("%p ",&num[i]);
    }
    printf("\n");
    //����ʹ�õ��ַ���char����Ҳ��ͬ���ĵ���
    char ch[] = "hello, handsome boy";
    char * cptr = ch;
    //���б������
    while(*cptr != '\0') {
        //ͨ��ָ���ƶ������л�ȡ����
        printf("%c",*cptr);
        //ָ��ġ�n���� �� n * sizeof(������ȥ��һ���Ǻ�)
        ++cptr;
    }
    printf("\n");

    cptr = ch;
    //ʹ��*(ָ�� + n)���Ի�ȡ�������n��ֵ
    printf("%c",*(cptr + 3));
    return 0;
}