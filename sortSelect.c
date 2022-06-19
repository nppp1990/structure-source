#include <stdio.h>

void selectSort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++) {
        int min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                //记录最小值的位置
                min = j;
            }
        }
        //最小值和i交换
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void testSelectSort() {
    printf("\n-----selectSort-----begin\n");
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    selectSort(arr, len);
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n-----selectSort-----end\n");
}


