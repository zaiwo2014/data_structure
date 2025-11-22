//
// Created by leung on 2025/11/22.
//


# include <stdio.h>

void sort(int arr[],int size) {
    //冒泡排序法 从小到大排序

    for (int i = 0; i < size ; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    return;
}

int binary_search(int arr[], int size,void (*sort)(int[],int) ,int target) {
    sort(arr, size);  // 直接调用排序函数

    int left = 0;
    int right = size - 1;

    while (left <= right) {  // 修正条件
        int mid = left + ((right - left) >> 1);  // 防止溢出

        if (arr[mid] == target) {
            return mid;  // 找到目标值，返回索引
        } else if (arr[mid] < target) {
            left = mid + 1;  // 在右半部分查找
        } else {
            right = mid - 1;  // 在左半部分查找
        }
    }

    return -1;  // 未找到目标值
}


int main(int argc, char *argv[]) {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 22;

    int result = binary_search(arr, size, sort ,target);

    if (result != -1) {
        printf("元素 %d 在数组中的索引为: %d\n", target, result);
    } else {
        printf("元素 %d 不在数组中\n", target);
    }

    return 0;

}
