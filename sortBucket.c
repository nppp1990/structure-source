#include <stdlib.h>
#include <printf.h>

typedef struct BucketNode {
    int data;
    struct BucketNode *next;
} BucketNode;

struct BucketNode *creatBucketNode(int value) {
    BucketNode *node = (BucketNode *) malloc(sizeof(BucketNode));
    node->next = NULL;
    node->data = value;
    return node;
}

/**
 * 数组+链表的方式：存放桶数据
 * @param arr
 * @param length
 * @param bucketCounts 桶的数量
 */
void bucketSort(int arr[], int length, int bucketCounts) {
    if (length == 0) {
        return;
    }
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    // 桶的容量
    int bucketSize = (max - min) / bucketCounts + 1;
    BucketNode **buckets = (BucketNode **) malloc(sizeof(BucketNode *) * bucketCounts);

    for (int i = 0; i < bucketCounts; i++) {
        // 创建头结点
        buckets[i] = creatBucketNode(-1);
    }

    for (int i = 0; i < length; i++) {
        int index = (arr[i] - min) / bucketSize;
        BucketNode *node = buckets[index];
        BucketNode *p = node;
        while (p->next) {
            // 遍历链表，找到要插入的位置
            if (p->next->data >= arr[i]) {
                break;
            }
            p = p->next;
        }
        // 对应桶中插入arr[i]的结点
        BucketNode *insertNode = creatBucketNode(arr[i]);
        BucketNode *temp = p->next;
        p->next = insertNode;
        insertNode->next = temp;
    }

    int i = 0;
    for (int j = 0; j < bucketCounts; ++j) {
        BucketNode *p = buckets[j];
        while (p->next) {
            arr[i++] = p->next->data;
            p = p->next;
        }
    }
}

void testBucketSort() {
    printf("\n-----bucketSort-----begin\n");
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    bucketSort(arr, len, 4);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n-----bucketSort-----end\n");
}
