#include <printf.h>
#include "graph-structure.h"

/**
 * 邻接矩阵的dfs
 * @param graph 邻接矩阵
 * @param i 开始顶点
 */
void bfs(AdjGraph *graph, int i) {
    // 记录已访问顶点：0表示未访问，1表示已访问
    int *visited = (int *) malloc(sizeof(int) * graph->n);
    for (int j = 0; j < graph->n; j++) {
        visited[j] = 0;
    }

    // 待访问顶点队列
    int *queue = (int *) malloc(sizeof(int) * graph->n);
    int rear = 0, front = 0;
    queue[rear++] = i;

    int size = 0;
    ArcNode *node;
    while (size < graph->n) {
        while (front < rear) {
            int currentIndex = queue[front++];
            node = graph->adjList[currentIndex];
            printf("%c ", node->value);
            // 访问结点后：更新visited、size
            visited[currentIndex] = 1;
            size++;
            node = node->next;
            while (node) {
                // 遍历node相邻顶点，找到未访问的加入栈
                if (visited[node->index] == 0) {
                    queue[rear++] = node->index;
                }
                node = node->next;
            }
        }
        if (size < graph->n) {
            // 如果队列为空，但是size<n；说明图G不是连通图，需要在未遍历顶点中随机再找一个顶点进行bfs
            queue[rear++] = getRandomRestPoint(graph, visited);
        }
    }
}

void testBfs() {
    printf("\n-----bfs-----begin\n");
    AdjGraph *graph = createAdjGraph();
    printf("起点：%c bfs结果为：", graph->adjList[3]->value);
    bfs(graph, 3);
    printf("\n起点：%c bfs结果为：", graph->adjList[5]->value);
    bfs(graph, 5);
    printf("\n-----dfs-----end\n");
}