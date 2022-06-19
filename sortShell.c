#include <stdio.h>

void shellSort(int arr[], int length) {
    int gap;
    for (gap = length / 2; gap > 0; gap /= 2) {
        // 分组插入排序
        for (int i = 0; i < gap; i++) {
            for (int j = i + gap; j < length; j += gap) {
                int key = arr[j];
                int k = j - gap;
                while (k >= i && arr[k] > key) {
                    arr[k + gap] = arr[k];
                    k -= gap;
                }
                arr[k + gap] = key;
            }
        }
    }
}


void testShellSort() {
    printf("\n-----shellSort-----begin\n");

    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    shellSort(arr, len);
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n-----shellSort-----begin\n");
}
