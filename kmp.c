#include <stdlib.h>
#include <printf.h>
#include <string.h>

/**
 * 
 * @param pattern 模式串
 * @param len 
 * @return next数组
 */
int *getNext(const char pattern[], int len) {
    int *next = (int *) malloc(sizeof(int) * len);
    next[0] = -1;
    next[1] = 0;
    for (int i = 2; i < len; i++) {
        int last = next[i - 1];
        if (pattern[i - 1] == pattern[last]) {
            next[i] = last + 1;
        } else {
            next[i] = 0;
        }
    }
    return next;
}

/**
 *
 * @param str 主串
 * @param pattern 模式串
 * @return {number} 匹配成功时，返回模式串在主串的位置；失败返回-1
 */
int kmp(char str[], char pattern[]) {
    int len1 = strlen(str);
    int len2 = strlen(pattern);
    int *next = getNext(pattern, len2);

    int j = 0;
    for (int i = 0; i < len1; i++) {
        while (j > 0 && str[i] != pattern[j]) {
            j = next[j];
        }
        if (str[i] == pattern[j]) {
            j++;
        }
        if (j == len2) {
            return i - len2 + 1;
        }
    }
    return -1;
}

void testKmp() {
    printf("\n-----kmp-----begin\n");
    char str[] = "abcabcabacba";
    char pattern1[] = "abcabb";
    char pattern2[] = "bcaba";

    printf("主串：%s, 模式串：%s, 匹配结果：%d\n", str, pattern1, kmp(str, pattern1));
    printf("主串：%s, 模式串：%s, 匹配结果：%d\n", str, pattern2, kmp(str, pattern2));

    printf("\n-----kmp-----begin\n");
}
