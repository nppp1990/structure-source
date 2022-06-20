#include <printf.h>
#include "graph-structure.h"

#define INF 100

int prim(MatrixGraph *graph) {
    int n = graph->vertexNum;

    // 记录已访问顶点：0表示未访问，1表示已访问(已固定的顶点)
    int *visited = (int *) malloc(sizeof(int) * n);
    // 记录每个顶点加入生成树T时在树中的父顶点：用于记录增加的边，如果只是计算最小值 可以不要parent
    int *parents = (int *) malloc(sizeof(int) * n);
    // 记录每个顶点已查询相邻边的最小值，初始为INF
    int *weights = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parents[i] = -1;
        weights[i] = INF;
    }

    // 加入第一个顶点
    int current = 0;
    parents[current] = -1;
    weights[current] = 0;
    visited[current] = 1;

    int ast = 0;
    int size = 1;
    int dis, minDis, minIndex;
    while (size < n) {
        for (int i = 0; i < n; i++) {
            dis = graph->matrix[current][i];
            if (visited[i] == 1 || dis == 0) {
                // 找相邻且没被访问的
                continue;
            }
            if (dis < weights[i]) {
                // 如果dis较小 更新weights和parent
                weights[i] = dis;
                parents[i] = current;
            }
        }

        // weights中最小的一个顶点固定
        minDis = INF;
        minIndex = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1 || weights[i] == INF) {
                continue;
            }
            if (weights[i] < minDis) {
                minDis = weights[i];
                minIndex = i;
            }
        }
        if (minIndex != -1) {
            // 更新current，接下来看current相邻顶点
            current = minIndex;
            visited[minIndex] = 1;
            ast += minDis;
            size++;
        } else {
            return -1;
        }
    }
    for (int i = 1; i < n; i++) {
        int parent = parents[i];
        printf("%c%c ", graph->vertex[parent]->value, graph->vertex[i]->value);
    }
    return ast;
}

void testPrim() {
    printf("\n-----prim-----begin\n");
    MatrixGraph *graph = createSpanningGraph();
    int ast = prim(graph);
    printf("\nprim算法最小生成树大小为：%d", ast);
    printf("\n-----prim-----end\n");
}