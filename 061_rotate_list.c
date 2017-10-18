#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* p = head;
    int length = 1;

    if (p == NULL || k == 0) {
        return head;
    }

    while (p->next) {
        p = p->next;
        length++;
    }
    p->next = head;

    k = length - (k % length);

    for (int i = 0; i < k; i++) {
        p = p->next;
    }

    head = p->next;
    p->next = NULL;

    return head;
}

int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* new_node = NULL;
    struct ListNode* float_node = head;
    int len, move;

    scanf("%d %d", &len, &move);


    head->val = 0;
    head->next = NULL;

    for (int i = 1; i <= len; i++) {
        new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->val = i;
        new_node->next = NULL;
        float_node->next = new_node;
        float_node = float_node->next;
    }

    head->next = rotateRight(head->next, move);

    while(head->next) {
        head = head->next;
        printf("%d\n", head->val);
    }

    return 0;
}
