#include <printf.h>

int linearFind(int arr[], int length, int value) {
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void testFindLinear() {
    printf("\n-----find-linear-----begin\n");
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nvalue %d index:%d", arr[3], linearFind(arr, len, arr[3]));
    printf("\n-----find-linear-----end\n");
}