
#include <printf.h>
#include <stdlib.h>

void testListArray() {
    printf("\n-----数组-----begin\n");
    int array1[] = {1, 2, 3, 4, 5};

    // 动态数组创建
    int *array2 = (int *) malloc(sizeof(int) * 10);
    array2[1] = 10;

    // 二维数组动态创建
    int **array3 = (int **) malloc(sizeof(int *) * 10);
    for (int i = 0; i < 10; ++i) {
        array3[i] = (int *) malloc(sizeof(int) * 5);
    }
    array3[1][4] = 1;
    printf("array[1]=%d  array3[1][4]=%d", array1[1], array3[1][4]);
    printf("\n-----数组-----end\n");
}