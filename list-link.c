#include <printf.h>
#include <stdlib.h>

// 单链表
typedef struct ListLink {
    char data;
    struct ListLink *next;
} ListLink;

// 双向链表
typedef struct ListDoubleLink {
    char data;
    struct ListDoubleLink *next;
    struct ListDoubleLink *pre;
} ListDoubleLink;

struct ListLink *creatListLinkNode(char value) {
    ListLink *node = (ListLink *) malloc(sizeof(ListLink));
    node->next = NULL;
    node->data = value;
    return node;
}

void testListLink() {
    printf("\n-----链表-----begin\n");
    ListLink *head = creatListLinkNode('h');
    char c = 'a';
    // 带头结点的单链表：头结点head的next指向a
    // 不带头结点单链表：第一个结点就是a，而不是head
    // 带头结点的循环单链表：尾部rear，rear->next=head rear->next->next=a
    // 不带头结点循环单链表：尾部rear，rear->next=a
    ListLink *p = head;
    while (c < 'e') {
        p->next = creatListLinkNode(c);
        p = p->next;
        c++;
    }

    p = head->next;
    // 遍历单链表
    while (p) {
        printf("%c ", p->data);
        p = p->next;
    }

    // 删除c
    p = head;
    while (p->next) {
        if (p->next->data == 'c') {
            break;
        }
        p = p->next;
    }
    if (p->next) {
        p->next = p->next->next;
    }

    p = head->next;
    printf("\n删除c后的单链表：");
    while (p) {
        printf("%c ", p->data);
        p = p->next;
    }

    printf("\n-----链表-----begin\n");
}