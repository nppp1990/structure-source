#include <printf.h>
#include "graph-structure.h"

// 无限大
#define INF 100

/**
 *
 * @param graph 邻接矩阵
 * @param i 起始点
 * @param j 终点
 * @return i到j的最短距离
 */
int dijkstra(MatrixGraph *graph, const int i, const int j) {
    int n = graph->vertexNum;
    // 记录最短距离
    int *minDistance = (int *) malloc(sizeof(int) * n);
    for (int k = 0; k < n; k++) {
        // 一开始除了i都是无穷大
        minDistance[k] = k == i ? 0 : INF;
    }

    // 记录已访问顶点：0表示未访问，1表示已访问
    int *visited = (int *) malloc(sizeof(int) * n);
    for (int k = 0; k < n; k++) {
        visited[k] = 0;
    }
    visited[i] = 1;

    int size = 1;
    int current = i;
    int minIndex, minDis;
    while (size < n) {
        for (int k = 0; k < n; k++) {
            if (visited[k] == 0 && graph->matrix[current][k] > 0) {
                // 获取当前current顶点未访问顶点
                int dis = minDistance[current] + graph->matrix[current][k];
                if (dis < minDistance[k]) {
                    // 如果（i到current+current到k）小于minDis：更新minDis
                    minDistance[k] = dis;
                }
            }
        }

        minIndex = -1;
        minDis = INF;
        for (int k = 0; k < n; k++) {
            // 获取当前current顶点未访问顶点, 距离最小的点
            if (visited[k] == 0 && minDistance[k] < minDis) {
                minDis = minDistance[k];
                minIndex = k;
            }
        }
        if (minIndex == j) {
            // 如果是目标顶点，直接返回dis
            return minDis;
        }
        if (minIndex == -1) {
            // 说明没有相邻顶点了，直接返回无穷大
            return INF;
        }
        visited[minIndex] = 1;
        current = minIndex;
        size++;
    }
}

void testDijkstra() {
    printf("\n-----dijkstra-----begin\n");
    MatrixGraph *graph = createMatrixGraph();
    int i = 0;
    int j = 4;
    printf("顶点%c到顶点%c最短距离：%d", graph->vertex[i]->value, graph->vertex[j]->value,
           dijkstra(graph, i, j));
    printf("\n-----dijkstra-----end\n");
}