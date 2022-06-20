#include <stdlib.h>

#ifndef STRUCTURE_SOURCE_GRAPH_STRUCTURE
#define STRUCTURE_SOURCE_GRAPH_STRUCTURE
/**
 * 邻接表表结点，不带头结点链表
 */
typedef struct ArcNode {
    int index; // 顶点序号，从0开始
    char value; // 顶点值
    int val;
    struct ArcNode *next; //邻接链表
} ArcNode;

//邻接表
typedef struct {
    ArcNode **adjList; // 邻接表数组
    int n, e;//顶点总数 边数
} AdjGraph;


#define VERTEX_SIZE 5
typedef struct GraphVertex {
    int index; // 顶点序号，从0开始
    char value; // 顶点值
} GraphVertex;

typedef struct {
    GraphVertex *vertex[VERTEX_SIZE];
    int matrix[VERTEX_SIZE][VERTEX_SIZE];
    int vertexNum;
    int arcNum;
} MatrixGraph;

struct ArcNode *creatArcNode(char value, int index, const int adjArr[], int adjSize);

AdjGraph *createAdjGraph();

int getRandomRestPoint(AdjGraph *graph, const int *visited);


struct GraphVertex *creatVertex(char value, int index);

// 无向图
MatrixGraph *createMatrixGraph();

// 生成树
MatrixGraph *createSpanningGraph();

#endif
