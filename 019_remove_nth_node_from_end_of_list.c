#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int length = 0;
    struct ListNode* p;

    p = head;

    while(p) {
        p = p->next;
        length++;
    }

    if (n == length) {
        return head->next;
    }

    p = head;
    for (int i = 0; i < length-n-1; i++) {
        p = p->next;
    }

    p->next = p->next->next;

    return head;
}

int main() {
    int length;
    int n;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* temp = NULL;
    struct ListNode* p = head;

    head->val = 0;
    printf("please input the length of the linkedlist: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d", &temp->val);
        temp->next = NULL;

        p->next = temp;
        p = p->next;
    }

    printf("please input the location to be removed\n");
    scanf("%d", &n);
    head = removeNthFromEnd(head->next, n);

    p = head;
    while(p) {
        printf("%d-->", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
