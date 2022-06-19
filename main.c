#include <sys/timeb.h>
#include <string.h>
#include <stdlib.h>
#include <printf.h>

#define MAX 100
#define N 5

testBubbleSort();
testInsertSort();
testSelectSort();
testQuickSort();
testHeapSort();
testMergeSort();
testBucketSort();
testRadixSort();
testCountingSort();
testShellSort();

testListArray();
testListLink();
testListStack();
testListQueue();

testTreeOrder();

int main() {
    testBubbleSort();
    testInsertSort();
    testSelectSort();
    testQuickSort();
    testHeapSort();
    testMergeSort();
    testBucketSort();
    testRadixSort();
    testCountingSort();
    testShellSort();

    testListArray();
    testListLink();
    testListStack();
    testListQueue();

    testTreeOrder();
//    printf("------xxxx2222\n");
//    TreeNode *treeNode1 = creatTree(11);
//    TreeNode *treeNode2 = creatTree(5);
//    TreeNode *treeNode3 = creatTree(6);
//    TreeNode *treeNode4 = creatTree(2);
//    TreeNode *treeNode5 = creatTree(4);
//    treeNode1->left = treeNode2;
//    treeNode1->right = treeNode3;
//    treeNode3->left = treeNode4;
//    treeNode3->right = treeNode5;
//
//    printf("wpl:%d\n", getTreeWpl(treeNode1, 100));
//
////    levelOrder(treeNode1, 4);
//    int a[] = {-1, 0, 9};
//    int b[] = {-25, -10, 10, 11};
//    int c[] = {2, 9, 7, 30, 41};
//    printf("-----minD:%d\n", getMinD(a, b, c, 3, 4, 5));
//    int x[] = {-5, 1, 5, 3};
//    printf("---func:%d\n", func(x, 4));

//    char a = 'a';
//    while (a != 'z') {
//        // 插入链表'a'
//        printf("%c", a);
//        a++;
//    }


//    int arr[] = {1, 2, 3, 4, 5, 6, 1, 3, 5, 2, 1};
//    int length = (int) sizeof(arr) / sizeof(*arr);
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", arr[i]);
//    }
//    removeArrayItem(arr, length, 1);
//    printf("\n删除1以后、数组的长度为：%d，内容为：", length);
//    for (int i = 0; i < length; ++i) {
//        printf("%d ", arr[i]);
//    }
//    int arr1[] = {1, 2, 3, 4, 5, 6, 1, 5};
//    divideArray(arr1, 8);
//
//    int s1[] = {11};
//    int s2[] = {2};
//    printf("sm:%d\n", searchM(s1, s2, 1));



//    testArc();
//    testLink();
//    testSort();
//    testArray();

//    int n = 10;
//    struct LinkNode **map = (struct LinkNode **) malloc(sizeof(struct LinkNode *) * n);
//    for (int i = 0; i < n; i++) {
//        map[i] = NULL;
//    }
//    map[3] = creatLinkNode(10);
//    if (map[2] == NULL) {
//        printf("----xxxx");
//    }
//
//    if (map[3] != NULL) {
//        printf("----xxxx3333");
//    }
//
//    struct Sqlist *sqlist = (Sqlist *) malloc(sizeof(Sqlist));
//    sqlist->num = 7;
//    int array[] = {2, 1, 5, -1, -1, 6, 7};
//    printf("----xxxx---===%d", midOrder(sqlist, 0, array));


    return 0;
}



