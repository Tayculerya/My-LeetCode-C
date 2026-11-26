//110. 平衡二叉树
//思路：自顶向下递归
//复杂度：O(n^2)/O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getHeight(struct TreeNode* root) {
    if (root == NULL) return 0;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);
    if (abs(leftH - rightH) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}