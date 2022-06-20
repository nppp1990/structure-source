#include <printf.h>
#include "graph-structure.h"

/**
 * 邻接矩阵的dfs
 * @param graph 邻接矩阵
 * @param i 开始顶点
 */
void dfs(AdjGraph *graph, int i) {
    // 记录已访问顶点：0表示未访问，1表示已访问
    int *visited = (int *) malloc(sizeof(int) * graph->n);
    for (int j = 0; j < graph->n; j++) {
        visited[j] = 0;
    }

    // 待访问顶点栈
    int *stack = (int *) malloc(sizeof(int) * graph->n);
    int index = 0;
    stack[index++] = i;

    // 已访问顶点个数
    int size = 0;
    ArcNode *node;
    while (size < graph->n) {
        while (index > 0) {
            int currentIndex = stack[--index];
            node = graph->adjList[currentIndex];
            printf("%c ", node->value);
            // 访问结点后：更新visited、size
            visited[currentIndex] = 1;
            size++;
            if (size == graph->n) {
                return;
            }
            node = node->next;
            while (node) {
                // 遍历node相邻顶点，找到未访问的加入栈
                if (visited[node->index] == 0) {
                    stack[index++] = node->index;
                }
                node = node->next;
            }
        }
        if (size < graph->n) {
            // 如果栈为空，但是size<n；说明图G不是连通图，需要在未遍历顶点中随机再找一个顶点进行dfs
            stack[index++] = getRandomRestPoint(graph, visited);
        }
    }
}

void testDfs() {
    printf("\n-----dfs-----begin\n");
    AdjGraph *graph = createAdjGraph();
    printf("起点：%c dfs结果为：", graph->adjList[3]->value);
    dfs(graph, 3);
    printf("\n起点：%c dfs结果为：", graph->adjList[5]->value);
    dfs(graph, 5);
    printf("\n-----dfs-----end\n");
}