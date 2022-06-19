#include <stdlib.h>
#include <printf.h>

void testListStack() {
    printf("\n-----栈-----begin\n");
    // 动态数组做栈
    char *stack = (char *) malloc(sizeof(char) * 10);
    int i = 0;
    char c = 'a';
    while (c < 'e') {
        stack[i++] = c;
        c++;
    }

    printf("出栈：");
    while (i > 0) {
        // i=0表示栈为空
        printf("%c ", stack[--i]);
    }

    printf("\n-----栈-----end\n");
}
