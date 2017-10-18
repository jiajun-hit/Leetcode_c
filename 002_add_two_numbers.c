#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p;
    struct ListNode* t;
    struct ListNode* o;
    int carry = 0;

    t = (struct ListNode*)malloc(sizeof(struct ListNode));
    t->val = 0;
    t->next = NULL;

    p = t;
    while (l1 || l2) {
        if (l1 == NULL) {
            o = (struct ListNode*)malloc(sizeof(struct ListNode));
            o->val = (l2->val + carry) % 10;
            o->next = NULL;

            carry = (l2->val + carry) / 10;

            t->next = o;
            t = o;

            l2 = l2->next;
        } else if (l2 == NULL) {
            o = (struct ListNode*)malloc(sizeof(struct ListNode));
            o->val = (l1->val + carry) % 10;
            o->next = NULL;

            carry = (l1->val + carry) / 10;

            t->next = o;
            t = o;

            l1 = l1->next;
        } else {
            o = (struct ListNode*)malloc(sizeof(struct ListNode));
            o->val = (l1->val + l2->val + carry) % 10;
            o->next = NULL;

            carry = (l1->val + l2->val + carry) / 10;

            t->next = o;
            t = o;

            l1 = l1->next;
            l2 = l2->next;
        }
    }

    if (carry) {
            o = (struct ListNode*)malloc(sizeof(struct ListNode));
            o->val = carry;
            o->next = NULL;

            t->next = o;
    }

    p = p->next;

    return p;
}

int main() {
    st

    return 0;
}
