#include <stdlib.h>
#include <printf.h>

typedef struct TreeNode {
    int value;
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

struct TreeNode *creatTree(char value) {
    TreeNode *treeNode = (TreeNode *) malloc(sizeof(TreeNode));
    treeNode->left = NULL;
    treeNode->right = NULL;
    treeNode->data = value;
    return treeNode;
}

// 先序遍历递归实现
void preTreeOrder1(TreeNode *root) {
    if (!root) {
        return;
    }
    printf("%c ", root->data);
    preTreeOrder1(root->left);
    preTreeOrder1(root->right);
}

// 先序遍历非递归实现
void preTreeOrder2(TreeNode *root) {
    if (!root) {
        return;
    }
    struct TreeNode **stack = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 10);
    int i = 0;
    stack[i++] = root;
    TreeNode *node;
    while (i > 0) {
        // 栈非空
        node = stack[--i];
        printf("%c ", node->data);
        if (node->right) {
            stack[i++] = node->right;
        }
        if (node->left) {
            stack[i++] = node->left;
        }
    }
}

// 中序遍历递归实现
void midTreeOrder1(TreeNode *root) {
    if (!root) {
        return;
    }
    midTreeOrder1(root->left);
    printf("%c ", root->data);
    midTreeOrder1(root->right);
}

// 中序遍历非递归实现
void midTreeOrder2(TreeNode *root) {
    if (!root) {
        return;
    }
    struct TreeNode **stack = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 10);
    int i = 0;
    TreeNode *node = root;
    while (node || i > 0) {
        while (node) {
            // 有左节点就进栈
            stack[i++] = node;
            node = node->left;
        }
        if (i > 0) {
            // 没有左节点就是中间节点、所以访问
            node = stack[--i];
            printf("%c ", node->data);
            // 看是否有右节点
            node = node->right;
        }
    }
}

// 后序遍历递归实现
void lastTreeOrder1(TreeNode *root) {
    if (!root) {
        return;
    }
    midTreeOrder1(root->left);
    midTreeOrder1(root->right);
    printf("%c ", root->data);
}

// 后序遍历非递归实现
void lastTreeOrder2(TreeNode *root) {
    if (!root) {
        return;
    }
    struct TreeNode **stack = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 10);
    int i = 0;
    TreeNode *node = root;
    // 记录上一个访问的节点
    TreeNode *preNode;
    while (node || i > 0) {
        while (node) {
            // 有左节点就进栈
            stack[i++] = node;
            node = node->left;
        }

        if (i > 0) {
            // 取出栈顶，但是不出栈
            node = stack[i - 1];
            if (!node->right || node->right == preNode) {
                // 右节点为空、或者右节点已访问
                preNode = stack[--i];
                printf("%c ", preNode->data);
                node = NULL;
            } else {
                node = node->right;
            }
        }
    }
}

void levelOrder(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    // 动态数组做队列
    struct TreeNode **queue = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 10);
    int rear = 0, front = 0;
    queue[rear++] = root;
    struct TreeNode *temp;
    while (rear > front) {
        temp = queue[front++];
        printf("%c", temp->data);
        if (temp->left) {
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }
}

/**
 *
 * @param root
 * @return
 */
int getTreeWpl(struct TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    // 动态数组做队列
    struct TreeNode **queue = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 10);
    int rear = 0, front = 0;
    queue[rear++] = root;
    struct TreeNode *temp;
    int wpl = 0;
    while (rear > front) {
        temp = queue[front++];
        if (temp->left || temp->right) {
            // 计算非叶结点的权值之和
            wpl += temp->value;
        }
        if (temp->left) {
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }
    return wpl;
}

void testTreeOrder() {
    TreeNode *treeNode1 = creatTree('a');
    TreeNode *treeNode2 = creatTree('b');
    TreeNode *treeNode3 = creatTree('c');
    TreeNode *treeNode4 = creatTree('d');
    TreeNode *treeNode5 = creatTree('e');
    treeNode1->left = treeNode2;
    treeNode1->right = treeNode3;
    treeNode3->left = treeNode4;
    treeNode3->right = treeNode5;

    // 哈夫曼树测试数据 wpl=(4+3)*2+6*1=20 or wpl=7+13=20
    treeNode4->value = 4;
    treeNode5->value = 3;
    treeNode3->value = 7;
    treeNode2->value = 6;
    treeNode1->value = 13;


    printf("\n-----先序遍历递归-----begin\n");
    preTreeOrder1(treeNode1);
    printf("\n-----先序遍历递归-----end\n");
    printf("\n-----先序遍历非递归-----begin\n");
    preTreeOrder2(treeNode1);
    printf("\n-----先序遍历非递归-----end\n");

    printf("\n-----中序遍历递归-----begin\n");
    midTreeOrder1(treeNode1);
    printf("\n-----中序遍历递归-----end\n");
    printf("\n-----中序遍历非递归-----begin\n");
    midTreeOrder2(treeNode1);
    printf("\n-----中序遍历非递归-----end\n");

    printf("\n-----后序遍历递归-----begin\n");
    lastTreeOrder1(treeNode1);
    printf("\n-----后序遍历递归-----end\n");
    printf("\n-----后序遍历非递归-----begin\n");
    lastTreeOrder2(treeNode1);
    printf("\n-----后序遍历非递归-----end\n");

    printf("\n-----层序遍历-----begin\n");
    levelOrder(treeNode1);
    printf("\n-----层序遍历-----end\n");

    printf("wpl=%d\n",getTreeWpl(treeNode1));
}