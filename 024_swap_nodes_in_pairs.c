#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p;
    struct ListNode *q;

    if (head && head->next) {
        p = head;
        head = head->next;
        p->next = head->next;
        head->next = p;
    } else {
        return head;
    }

    while (p->next && p->next->next) {
        q = p->next;
        p->next = q->next;
        q->next = q->next->next;
        p->next->next = q;
        p = q;
    }

    return head;
}

int main() {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p = head, *q;
    int num;

    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        q = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &(q->val));
        q->next = NULL;

        p->next = q;
        p = p->next;
    }

    head->next = swapPairs(head->next);

    p = head->next;

    while (p) {
        printf("%d\n", p->val);
        p=p->next;
    }

    return 0;
}
