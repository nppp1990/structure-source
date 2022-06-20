
#include <stdlib.h>
#include <printf.h>

#define HASH_SIZE 8
typedef struct HashNode {
    // 数组下标，当然也可以再存储value
    int index;
    int value;
    struct HashNode *next;
} HashNode;

struct HashNode *creatHashNode(int index) {
    HashNode *node = (HashNode *) malloc(sizeof(HashNode));
    node->next = NULL;
    node->index = index;
    return node;
}

struct HashNode *creatHashNode2(int index, int value) {
    HashNode *node = (HashNode *) malloc(sizeof(HashNode));
    node->index = index;
    node->value = value;
    return node;
}

int hashCode(int v) {
    return v % 8;
}

HashNode **createHashLinkHead(int arr[], int length) {
    HashNode **head = (HashNode **) malloc(sizeof(HashNode *) * HASH_SIZE);
    for (int i = 0; i < HASH_SIZE; i++) {
        // 带头结点的哈希表
//        head[i] = (HashNode *) malloc(sizeof(HashNode));
        head[i] = creatHashNode(-1);
    }
    int hashKey;
    HashNode *node;
    // 链地址法建表
    for (int i = 0; i < length; i++) {
        hashKey = hashCode(arr[i]);
        node = head[hashKey];
        while (node->next) {
            // 找到最后一个结点
            node = node->next;
        }
        // 插入到链表最后一个结点
        node->next = creatHashNode(i);
    }
    return head;
}

int findHashLink(HashNode **head, int arr[], int value) {
    HashNode *node = head[hashCode(value)]->next;
    while (node) {
        if (arr[node->index] == value) {
            return node->index;
        }
        node = node->next;
    }
    return -1;
}

HashNode **createLinearHashTable(int arr[], int length) {
    // 这里设置size为16：保证能放下待查找数组每个数
    HashNode **table = (HashNode **) malloc(sizeof(HashNode *) * HASH_SIZE * 2);
    for (int i = 0; i < HASH_SIZE * 2; i++) {
        // 暂定-1为空
        table[i] = creatHashNode2(-1, -1);
    }

    int index;
    for (int i = 0; i < length; i++) {
        index = hashCode(arr[i]);
        while (table[index]->value != -1) {
            // 不空，则找到下一个非空位置index
            index = (index + 1) % (HASH_SIZE * 2);
        }
        // 插入到哈希表中
        table[index] = creatHashNode2(i, arr[i]);
    }
    return table;
}

int findHashLinear(HashNode **table, int value) {
    int index = hashCode(value);
    int i = 0;
    while (table[index]->index != -1 && i < HASH_SIZE * 2) {
        if (table[index]->value == value) {
            return table[index]->index;
        }
        // 找不到value看下一个位置
        index = (index + 1) % (HASH_SIZE * 2);
        // i=16时：说明整个哈希表都找了一遍，没发现value
        i++;
    }
    // index对应哈希表为空
    return -1;
}

void testFindHash() {
    int arr[] = {22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = (int) sizeof(arr) / sizeof(*arr);
    printf("\n-----链地址法-----begin\n");
    HashNode **linkHead = createHashLinkHead(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nvalue %d index:%d", arr[3], findHashLink(linkHead, arr, arr[3]));
    printf("\nvalue %d index:%d", 21, findHashLink(linkHead, arr, 21));
    printf("\n-----链地址法-----end\n");
    printf("\n-----线性在探测法-----begin\n");
    HashNode **linearTable = createLinearHashTable(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nvalue %d index:%d", arr[3], findHashLinear(linearTable, arr[3]));
    printf("\nvalue %d index:%d", 21, findHashLinear(linearTable, 21));

    printf("\n-----线性在探测法-----end\n");
}
