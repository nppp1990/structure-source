#include <printf.h>
#include "graph-structure.h"

// 创建一个有向无环图
MatrixGraph *createDagGraph() {
    MatrixGraph *graph = (MatrixGraph *) malloc(sizeof(MatrixGraph));
    char a = 'A';
    for (int i = 0; i < VERTEX_SIZE; i++) {
        graph->vertex[i] = creatVertex(a++, i);
    }
    int matrix[VERTEX_SIZE][VERTEX_SIZE] = {
            {0, 1, 1, 1, 0},
            {0, 0, 0, 0, 0},
            {0, 1, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0},
    };

    for (int i = 0; i < VERTEX_SIZE; i++) {
        for (int j = 0; j < VERTEX_SIZE; j++) {
            graph->matrix[i][j] = matrix[i][j];
        }
    }
    graph->vertexNum = VERTEX_SIZE;
    return graph;
}

// 剩余顶点中找到入度为0的点；-1表示没有入度为0的点
int getIn0(MatrixGraph *graph, const int *visited) {
    for (int i = 0; i < graph->vertexNum; i++) {
        if (visited[i] == 1) {
            continue;
        }
        int degree = 0;
        for (int j = 0; j < graph->vertexNum; j++) {
            if (visited[j] == 1) {
                continue;
            }
            degree += graph->matrix[j][i];
            if (degree > 0) {
                break;
            }
        }
        if (degree == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * 拓扑排序：输出排序列表
 * @param graph
 * @return 1表示是有向无环图，支持拓扑排序，0表示不是有向无环图
 */
int dagSort(MatrixGraph *graph) {
    int n = graph->vertexNum;

    // 记录已访问顶点：0表示未访问，1表示已访问
    int *visited = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int size = 0;
    printf("拓扑排序：");
    while (size < graph->vertexNum) {
        int i = getIn0(graph, visited);
        if (i == -1) {
            return -1;
        }
        printf("%c ", graph->vertex[i]->value);
        visited[i] = 1;
        size++;
    }
    return 1;
}

void testDagSort() {
    printf("\n-----拓扑排序-----begin\n");
    MatrixGraph *graph = createDagGraph();
    int res = dagSort(graph);
    printf("   有向无环图：%d", res);
    printf("\n-----拓扑排序-----end\n");
}
