#include<stdio.h>
#include<malloc.h>
//���ﰸ������Σ���Ҫ��ֱ�����Ժ�������ָ�����ͣ��Ӷ�ʵ�֣��������ض��ֵ
int * revsal(int num) {
    if(num >= 100 && num <= 999) {
        //���ٿռ�
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
    printf("������һ����λ��������\n");
    scanf("%d",&num);
    int *re = revsal(num);
    if(re != NULL) {
        printf("%d %d %d\n",*re,*(re + 1), *(re + 2));
        //�ͷſռ�
        free(re);
    } else {
        printf("������벻�Ϸ�\n");
    }
    return 0;
}