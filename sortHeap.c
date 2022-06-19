#include <stdio.h>

//交换
void heapSwap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 自下而上的建堆方法
void maxHeapify(int arr[], int length) {
    int i = length / 2 - 1;
    while (i >= 0) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int max; // 左右孩子中最大的数
        if (right < length && arr[left] < arr[right]) {
            max = right;
        } else {
            max = left;
        }
        if (arr[i] < arr[max]) {
            // 如果左右孩子中最大的数大于i，则把大的数和i交换
            heapSwap(arr, i, max);
        }
        i--;
    }
}

void insertHeap(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int currentIndex = i;
        int fatherIndex = (i - 1) / 2;
        while (currentIndex >= 1 && arr[fatherIndex] < arr[currentIndex]) {
            heapSwap(arr, fatherIndex, currentIndex);
            currentIndex = fatherIndex;
            fatherIndex = (currentIndex - 1) / 2;
        }
    }
}

void correctHeap(int arr[], int size) {
    int index = 0;
    while (index * 2 + 1 < size) {
        // 至少有一个左孩子
        int left = index * 2 + 1; // 左子孩子
        int right = index * 2 + 2; // 右子孩子
        int max;
        if (right < size && arr[left] < arr[right]) {
            max = right;
        } else {
            max = left;
        }

        if (arr[index] >= arr[max]) {
            return;
        }
        heapSwap(arr, index, max);
        index = max;
    }
}

/**
 * 自下而上的堆排序 建堆复杂度O(n)
 * @param arr
 * @param length
 */
void heapSort1(int arr[], int length) {
    maxHeapify(arr, length);
    int size = length;
    while (size > 1) {
        // 交换堆顶和数组尾部的数、固定最大值
        heapSwap(arr, 0, size - 1);
        size--;
        // 纠正大顶堆
        maxHeapify(arr, size);
    }

}

/**
 * 自上而下、插入法的堆排序 建堆复杂度O(nlogn)
 * @param arr
 * @param length
 */
void heapSort2(int arr[], int length) {
    // 用从上往下遍历插入的方式构造大顶堆
    insertHeap(arr, length);
    int size = length;
    while (size > 1) {
        // 交换堆顶和数组尾部的数、固定最大值
        heapSwap(arr, 0, size - 1);
        size--;
        // 纠正大顶堆
        correctHeap(arr, size);
    }
}

void testHeapSort() {
    int arr1[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int arr2[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr1) / sizeof(*arr1);
    printf("\n-----heapSort：自下而上-----begin\n");
    heapSort1(arr1, len);
    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n-----heapSort：自下而上-----end\n");

    printf("\n-----heapSort：自上而下-----begin\n");
    heapSort2(arr2, len);
    for (i = 0; i < len; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n-----heapSort：自上而下-----end\n");
}
