#include<stdio.h>
int main() {
    int i;
    //����ָ��ָ��i
    int * adder = &i;
    //�鿴�Ƿ�ָ���ַ
    printf("i�ĵ�ַ�ǣ�%p\n",&i);
    printf("adder��ֵ�ǣ�%p\n",adder);
    //ʹ��ָ��,��Ϊ��ָ��i�����Կ����޸�i��ֵ
    *adder = 5;
    printf("i = %d, *adder = %d\n",i, *adder);
    //ͬ����Ϊadder��int *�������԰�ȡ��ַ���sizeof��int)��С���ֽڴ�ŵ�ֵ ���� 3 ��ֵ��w
    int w = *adder + 3;
    printf("w = %d\n",w);
    return 0;
}