#include <stdio.h>

void bubbleSort(int arr[], int len) {
    int i, j, temp;
    int flag;
    for (i = 0; i < len - 1; i++) {
        flag = 0;
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            // 说明没有需要交换的数，说明所有的数已排序
            return;
        }
    }
}

void testBubbleSort() {
    printf("\n-----bubbleSort-----begin\n");
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    bubbleSort(arr, len);
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n-----bubbleSort-----end\n");
}
