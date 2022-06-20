#include <printf.h>
#include "graph-structure.h"

/**
 * 获取链表尾部结点
 * @param nextArray
 * @param start
 * @return {*}
 */
int findEndNode(const int *nextArray, int start) {
    while (nextArray[start] != -1) {
        start = nextArray[start];
    }
    return start;
}

typedef struct {
    int i;
    int j;
    int value;
} Edge;

// 对所有边排序
void bubbleEdgeSort(Edge **edgeList, int len) {
    int i, j;
    Edge *temp;
    int flag;
    for (i = 0; i < len - 1; i++) {
        flag = 0;
        for (j = 0; j < len - 1 - i; j++) {
            if (edgeList[j]->value > edgeList[j + 1]->value) {
                temp = edgeList[j];
                edgeList[j] = edgeList[j + 1];
                edgeList[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            // 说明没有需要交换的数，说明所有的数已排序
            return;
        }
    }
}

/**
 * kruskal算法
 * @param matrix
 * @return {*[{i,j,weight}]}
 */
int kruskal(MatrixGraph *graph) {
    int n = graph->vertexNum;
    Edge **edgeList = (struct Edge **) malloc(sizeof(Edge *) * graph->arcNum);
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph->matrix[i][j] == 0) {
                continue;
            }
            Edge *edge = (Edge *) malloc(sizeof(Edge));
            edge->i = i;
            edge->j = j;
            edge->value = graph->matrix[i][j];
            edgeList[index++] = edge;
        }
    }

    // 1. 对所有边排序
    bubbleEdgeSort(edgeList, graph->arcNum);
    // 2. 初始化next数组：用于判断是否有环
    int *nextArray = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        nextArray[i] = -1;
    }


    int nextIndex = 0;
    int size = 0;
    Edge *edge;
    int ast = 0;
    while (size < n - 1) {
        // 生成树为n-1条边
        edge = edgeList[nextIndex++];
        int u = findEndNode(nextArray, edge->i);
        int v = findEndNode(nextArray, edge->j);
        if (u != v) {
            // 表示无环
            printf("%c%c ", graph->vertex[edge->i]->value, graph->vertex[edge->j]->value);
            nextArray[u] = v;
            ast += edge->value;
            size++;
        }
    }
    return ast;
}

void testKruskal() {
    printf("\n-----kruskal-----begin\n");
    MatrixGraph *graph = createSpanningGraph();
    int res = kruskal(graph);
    printf("\nkruskal算法最小生成树大小为：%d", res);
    printf("\n-----kruskal-----end\n");

}
