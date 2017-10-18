#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *new_list = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *temp_node;
    struct ListNode *move_node = new_list;

    while (1) {
        int min = 65535;
        int index;

        temp_node = NULL;

        for (int i = 0; i < listsSize; i++) {
            if (lists[i] && lists[i]->val < min) {
                min = lists[i]->val;
                temp_node = lists[i];
                index = i;
            }
        }

        if (temp_node == NULL) {
            break;
        } else {
            move_node->next = lists[index];
            lists[index] = lists[index]->next;
            move_node = move_node->next;
            move_node->next = NULL;
        }
    }

    return new_list->next;
}

int main() {

    return 0;
}
