// 无限大：表示没有连接路径
#include <printf.h>
#include "graph-structure.h"

#define INF 100

/**
 * 邻接矩阵的floyd算法 复杂度O(n³)
 * @param graph
 * @return
 */
int **floyd(MatrixGraph *graph) {
    int n = graph->vertexNum;
    int **matrix = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph->matrix[i][j] == 0) {
                matrix[i][j] = INF;
            } else {
                matrix[i][j] = graph->matrix[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (matrix[i][k] == INF || matrix[k][j] == INF) {
                    continue;
                }
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    return matrix;
}

void testFloyd() {
    printf("\n-----floyd-----begin\n");
    MatrixGraph *graph = createMatrixGraph();
    int i = 0;
    int j = 4;
    int **matrix = floyd(graph);
    printf("顶点%c到顶点%c最短距离：%d\n", graph->vertex[i]->value, graph->vertex[j]->value,
           matrix[i][j]);
    printf("顶点%c到顶点%c最短距离：%d", graph->vertex[1]->value, graph->vertex[4]->value,
           matrix[1][4]);
    printf("\n-----floyd-----end\n");
}
