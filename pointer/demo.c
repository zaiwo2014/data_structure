

/**
 *  明晰几个概念:
 *          1. 指针函数 : 就是个普通函数,不过其返回值是个指针 -> 不可以返回局部变量的地址, 因为超出作用域会被操作系统回收,成为野指针
 *          2. 函数指针: 是一个指向函数的指针
 */


#include <stdio.h>


//函数指针
int pointerFunc() {
    return 1;
}

int main(int argc, char *argv[]) {
    int (*pfun)() = pointerFunc;
    int result = pfun();
    printf("%d\n", result);

    return 0;
}


