#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    int a, b;
    
    if (root == NULL) {
        return 0;
    }
    
    a = maxDepth(root->left) + 1;
    b = maxDepth(root->right) + 1;
    return a > b ? a: b;
}

int main() {

    return 0;
}
