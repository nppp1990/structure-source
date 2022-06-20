#include <printf.h>

int binaryFind(int arr[], int length, int value) {
    int low = 0, high = length - 1, mid;
    if (arr[low] > value || arr[high] < value) {
        // 直接返回-1
        return -1;
    }

    while (low <= high && value >= arr[low] && value <= arr[high]) {
        mid = low + (high - low) / 2;
        if (value == arr[mid]) {
            return mid;
        }
        if (arr[mid] > value) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

void _bubbleSort(int arr[], int len) {
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

void testFindBinary() {
    printf("\n-----find-binary-----begin\n");
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    // 二分查找 要求已排序
    _bubbleSort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nvalue %d index:%d", arr[3], binaryFind(arr, len, arr[3]));
    printf("\nvalue %d index:%d", 21, binaryFind(arr, len, 21));
    printf("\n-----find-binary-----end\n");
}