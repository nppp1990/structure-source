#include <stdlib.h>
#include <printf.h>

void testListQueue() {
    printf("\n-----队列-----begin\n");
    // 动态数组做队列：无头结点的队列
    char *queue = (char *) malloc(sizeof(char) * 10);
    int rear = 0, front = 0;
    char c = 'a';
    while (c < 'e') {
        queue[rear++] = c++;
    }

    printf("出队：");
    while (front < rear) {
        printf("%c ", queue[front++]);
    }

    printf("\n-----队列-----end\n");
}
