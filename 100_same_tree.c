#include <stdio.h>
#include <stdlib.h>

typedef _Bool bool;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL) {
        if (q == NULL) {
            return 1;
        } else {
            return 0;
        }
    }

    if (q == NULL) {
        if(p != NULL) {
            return 0;
        }
    }

    if (p->val != q->val) {
        return 0;
    } else {
        return 1 * isSameTree(p->left, q->left) * isSameTree(p->right, q->right);
    }
}


int main() {
    struct TreeNode *p, *q;
    bool a;

    p = NULL;
    q = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    q->val = 0;
    q->left = NULL;
    q->right = NULL;

    a = isSameTree(p, q);

    printf("%d\n", a);

    return 0;
}
