#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DYN_ARR {
    int *arr;
    int capacity;
    int size;
};

//定义一个结构体类型
typedef struct DYN_ARR dyn;

//初始化函数
dyn init_dyn_arr(int arr[], int size) {
    //申请一块内存 容量为原始数组的两倍大小 -> 为后续插入数据预留空间
    int *tmp = malloc(sizeof(int) * size * 2);
    memcpy(tmp,arr,sizeof(int) * size * 2);
    dyn dyn_arr;
    dyn_arr.arr = tmp;
    dyn_arr.size = size;
    dyn_arr.capacity = size * 2;
    return dyn_arr;
}


//打印动态数组中的元素
void print_dyn_arr(dyn dyn_arr) {
    for (int i = 0; i < dyn_arr.size; ++i) {
        printf("%d\n", dyn_arr.arr[i]);
    }
}

//动态扩容
dyn dyn_expansion(dyn dyn_arr) {
    int *tmp = malloc(sizeof(int) * dyn_arr.capacity * 1.5);
    memcpy(tmp,dyn_arr.arr,sizeof(int) * dyn_arr.size);
    free(dyn_arr.arr);
    dyn new_dyn_arr;
    new_dyn_arr.arr = tmp;
    new_dyn_arr.size = dyn_arr.size;
    new_dyn_arr.capacity = dyn_arr.capacity * 1.5;
    return new_dyn_arr;
}

void insert_into_dyn(dyn* dyn_arr,int element) {
    if (dyn_arr->size == dyn_arr->capacity) {
        *dyn_arr = dyn_expansion(*dyn_arr);
    }

    dyn_arr->arr[dyn_arr->size] = element;
    dyn_arr->size++;
}



int main(void) {
    //定义一个数组
    dyn dyn_arr = init_dyn_arr((int[]){1,2,3,4,5}, 5);
    for (int i = 10; i < 50; i++) {
        insert_into_dyn(&dyn_arr, i);
    }
    print_dyn_arr(dyn_arr);
    free(dyn_arr.arr);
    return 0;
    //动态扩容算法
}

