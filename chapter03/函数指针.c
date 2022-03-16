#include<stdio.h>
//个人感觉函数指针，最大的作用就是可以作为参数进行传递，对泛型编程有着很大意义
typedef void (* func) (int i);//真的感觉没有c++的using好用

void test(int num) {
    printf("num = %d\n",num);
}

void forEach(int * arr,int len,func f) { 
    for(int i = 0; i < len; i++) {
        f(arr[i]);
    }
}

typedef int (*compare)(void * num1, void * num2 );
//int类型的比较函数，反正根据你需要判断的类型来，结果提这些也行，还是c++舒服呀，有auto，decltype这些
int comperInt(void * a, void * b) {
    return *(int *) a - *(int *)b;
}

//数组首地址，一个占多少字节，长度，比较函数
void * getMaxArrValue(void * arr, int unint, int len, compare co) {
    void * max = arr;
    for(int i = 1; i < len; i++) {
        //因为void指针无法实现++这种操作，所以需要自己计算下一次的位移偏量
        if(co(arr + i * unint,max) > 0) {
            max = arr + i * unint;
        }
    }
    return max;
}

int main() {
    func f1 = test;//func类型的函数指针指向test
    f1(10);//执行f1函数指针指向的代码
    f1(33);
    int num[] = {33,14,45,1021,88,-10086};
    forEach(num,sizeof(num) / 4, test);
    
    //但是这些都弱爆了,我们来比较任意类型的比较
    printf("max = %d\n",*(int *)getMaxArrValue(num,sizeof(int),sizeof(num) / sizeof(int),comperInt));
    return 0;
}