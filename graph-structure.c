#include "graph-structure.h"

struct ArcNode *creatArcNode(char value, int index, const int adjArr[], int adjSize) {
    ArcNode *node = (ArcNode *) malloc(sizeof(ArcNode));
    node->value = value;
    node->index = index;
    ArcNode *temp = node, *p;
    for (int i = 0; i < adjSize; ++i) {
        p = (ArcNode *) malloc(sizeof(ArcNode));
        p->index = adjArr[i];
        temp->next = p;
        temp = p;
    }
    temp->next = NULL;
    return node;
}

AdjGraph *createAdjGraph() {
    struct ArcNode **array = (struct ArcNode **) malloc(sizeof(struct ArcNode *) * 7);
    int adj0[] = {1, 2};
    int adj1[] = {0, 3, 4};
    int adj2[] = {0};
    int adj3[] = {1};
    int adj4[] = {1};
    int adj5[] = {6};
    int adj6[] = {5};
    ArcNode *node0 = creatArcNode('A', 0, adj0, 2);
    ArcNode *node1 = creatArcNode('B', 1, adj1, 3);
    ArcNode *node2 = creatArcNode('C', 2, adj2, 1);
    ArcNode *node3 = creatArcNode('D', 3, adj3, 1);
    ArcNode *node4 = creatArcNode('E', 4, adj4, 1);
    ArcNode *node5 = creatArcNode('F', 5, adj5, 1);
    ArcNode *node6 = creatArcNode('G', 6, adj6, 1);
    array[0] = node0;
    array[1] = node1;
    array[2] = node2;
    array[3] = node3;
    array[4] = node4;
    array[5] = node5;
    array[6] = node6;
    AdjGraph *graph = (AdjGraph *) malloc(sizeof(AdjGraph));
    graph->n = 7;
    graph->e = (2 + 3 + 1 + 1 + 1 + 1 + 1) / 2;
    graph->adjList = array;
    return graph;
}

// 随机获取一个未访问顶点
int getRandomRestPoint(AdjGraph *graph, const int *visited) {
    for (int i = 0; i < graph->n; i++) {
        if (visited[i] == 0) {
            return i;
        }
    }
    return -1;
}

struct GraphVertex *creatVertex(char value, int index) {
    GraphVertex *vertex = (GraphVertex *) malloc(sizeof(GraphVertex));
    vertex->index = index;
    vertex->value = value;
    return vertex;
}

MatrixGraph *createMatrixGraph() {
    MatrixGraph *graph = (MatrixGraph *) malloc(sizeof(MatrixGraph));
    char a = 'A';
    for (int i = 0; i < VERTEX_SIZE; i++) {
        graph->vertex[i] = creatVertex(a++, i);
    }
    int matrix[VERTEX_SIZE][VERTEX_SIZE] = {
            {0, 5, 4, 0, 0},
            {5, 0, 0, 2, 7},
            {4, 0, 0, 0, 0},
            {0, 2, 0, 0, 1},
            {0, 6, 0, 1, 0},
    };

    int arcSize = 0;
    for (int i = 0; i < VERTEX_SIZE; i++) {
        for (int j = i; j < VERTEX_SIZE; j++) {
            if (i == j) {
                graph->matrix[i][j] = 0;
            } else {
                if (matrix[i][j] > 0) {
                    arcSize++;
                }
                graph->matrix[i][j] = matrix[i][j];
                graph->matrix[j][i] = matrix[i][j];
            }
        }
    }
    graph->arcNum = arcSize;
    graph->vertexNum = VERTEX_SIZE;
    return graph;
}

MatrixGraph *createSpanningGraph() {
    MatrixGraph *graph = (MatrixGraph *) malloc(sizeof(MatrixGraph));
    char a = 'A';
    for (int i = 0; i < VERTEX_SIZE; i++) {
        graph->vertex[i] = creatVertex(a++, i);
    }
    int matrix[VERTEX_SIZE][VERTEX_SIZE] = {
            {0,  7,  14, 9, 0},
            {7,  0,  17, 0, 5},
            {14, 17, 0,  4, 15},
            {9,  0,  4,  0, 0},
            {0,  5,  15, 0, 0},
    };

    int arcSize = 0;
    for (int i = 0; i < VERTEX_SIZE; i++) {
        for (int j = i; j < VERTEX_SIZE; j++) {
            if (i == j) {
                graph->matrix[i][j] = 0;
            } else {
                if (matrix[i][j] > 0) {
                    arcSize++;
                }
                graph->matrix[i][j] = matrix[i][j];
                graph->matrix[j][i] = matrix[i][j];
            }
        }
    }
    graph->arcNum = arcSize;
    graph->vertexNum = VERTEX_SIZE;
    return graph;
}