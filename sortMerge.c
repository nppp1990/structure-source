#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int length = high - low + 1;
    int temp[length];
    int i = low;
    int j = mid + 1;
    int k = 0;
    // 把较小的数先移到新数组中
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    // 把左边剩余的数移入数组
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    // 把右边边剩余的数移入数组
    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high) {
    int mid = (low + high) / 2;
    if (low < high) {
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        //左右归并
        merge(arr, low, mid, high);
    }
}

void testMergeSort() {
    printf("\n-----mergeSort-----begin\n");
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    mergeSort(arr, 0, len - 1);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n-----mergeSort-----end\n");
}
