//222. 完全二叉树的节点个数
//思路：算树高，利用公式分情况算树的结点。
//复杂度：O(n)/O(logn)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <math.h>
int getHeight(struct TreeNode* root) {
    int h = 0;
    while (root != NULL) {
        h++;
        root = root->left;
    }
    return h;
}

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    
    if (leftH == rightH) {
        return (1 << leftH) + countNodes(root->right);
    } else {
        return (1 << rightH) + countNodes(root->left);
    }
}