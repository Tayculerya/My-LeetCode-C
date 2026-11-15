//104. 二叉树的最大深度
//思路：递归
//复杂度：O(n)/O(logn)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int i=0;
    if(root==NULL)return 0;
    int leftdepth=maxDepth (root->left);
    int rightdepth=maxDepth (root->right);
    return (leftdepth>rightdepth?leftdepth:rightdepth)+1;
}