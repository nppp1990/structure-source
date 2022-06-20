#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int length, int max) {
    int * bucket = (int *) malloc(sizeof(int) * max);
    int i, j;
    for (i = 0; i < max; i++) {
        // 一开始都是0
        bucket[i] = 0;
    }
    for (i = 0; i < length; i++) {
        int index = arr[i];
        // 用value作为bucket的index
        bucket[index] = bucket[index] + 1;
    }

    for (i = 0, j = 0; i < max; i++) {
        int size = bucket[i];
        while (size > 0) {
            arr[j++] = i;
            size--;
        }
    }
}


void testCountingSort() {
    printf("\n-----countingSort-----begin\n");
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    countingSort(arr, len, 100);
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n-----countingSort-----end\n");
}
