#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l = l1;
    struct ListNode* node;

    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    } else if (l2->val < l1->val) {
        node = l1;
        l1 = l2;
        l2 = l2->next;
        l1->next = node;
        l = l1;
    }

    while (l2) {
        if (l->next && l2->val <= l->next->val) {
            node = l->next;
            l->next = l2;
            l2 = l2->next;
            l->next->next = node;
            l = l->next;
        } else if (l->next && l2->val > l->next->val) {
            l = l->next;
        } else {
            l->next = l2;
            break;
        }
    }

    return l1;
}

int main () {

    return 0;
}
