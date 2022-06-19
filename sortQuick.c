#include <stdio.h>

int quickSort(int arr[], int left, int right) {
    if (left >= right) {
        // 递归结束的条件
        return 0;
    }

    // 指针p指向left
    int p = arr[left];
    int i = left;
    int j = right;
    while (i < j) {
        while (i < j && arr[j] >= p) {
            // 从最右往左找到第一个小于p的位置j
            j--;
        }
        while (i < j && arr[i] <= p) {
            // 从左往右找到第一个大于p的位置i
            i++;
        }
        if (i < j) {
            // 交换i和j
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // i和j相遇，说明temp的左边的数都小于等于temp；右边都大于等于temp
    int temp = arr[i];
    arr[i] = arr[left];
    arr[left] = temp;

    // temp位置已确定，递归快排剩余的数
    quickSort(arr, left, i - 1);
    quickSort(arr, j + 1, right);
}


void testQuickSort() {
    printf("\n-----quickSort-----begin\n");
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    quickSort(arr, 0, len - 1);
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n-----quickSort-----end\n");
}
