//101. 对称二叉树
//思路：引入双参数的辅助函数。
//复杂度：O(n)/O(logn)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool check(struct TreeNode* left, struct TreeNode* right) { 
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL || left->val != right->val) return false;   
    return check(left->left, right->right) && check(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true; 
    return check(root->left, root->right);
}