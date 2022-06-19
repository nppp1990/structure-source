#include <stdlib.h>
#include <printf.h>

typedef struct RadixNode {
    int data;
    struct RadixNode *next;
} RadixNode;

struct RadixNode *creatRadixNode(int value) {
    RadixNode *node = (RadixNode *) malloc(sizeof(RadixNode));
    node->next = NULL;
    node->data = value;
    return node;
}

#define MOD 10

void radixSort(int arr[], int len, int maxDigit) {
    RadixNode **buckets = (RadixNode **) malloc(sizeof(RadixNode *) * MOD);
    // 存储链表尾部，用来模拟队列
    RadixNode **tailBuckets = (RadixNode **) malloc(sizeof(RadixNode *) * MOD);
    for (int i = 0; i < MOD; i++) {
        // 创建头结点
        struct RadixNode *node = creatRadixNode(-1);
        buckets[i] = node;
        tailBuckets[i] = node;
    }

    int index;
    RadixNode *head, *next, *temp;
    for (int i = 0, radix = 1; i < maxDigit; i++, radix *= MOD) {
        for (int j = 0; j < len; j++) {
            index = arr[j] / radix % MOD;
            // 尾部插入arr[j]
            temp = creatRadixNode(arr[j]);
            tailBuckets[index]->next = temp;
            tailBuckets[index] = temp;
        }

        int k = 0;
        for (int j = 0; j < 10; ++j) {
            // 遍历buckets数据，按照先进先出的方式取出链表数据，所以这里应该用队列来实现
            RadixNode *p = buckets[j]->next;
            while (p) {
                arr[k++] = p->data;
                temp = p->next;
                free(p);
                p = temp;
            }
            // 重置buckets和tailBuckets
            buckets[j]->next = NULL;
            tailBuckets[j] = buckets[j];
        }
    }
}

void testRadixSort() {
    printf("\n-----radixSort-----begin\n");
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    radixSort(arr, len, 2);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n-----radixSort-----end\n");
}