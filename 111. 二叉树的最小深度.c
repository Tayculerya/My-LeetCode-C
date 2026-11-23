//111. 二叉树的最小深度
//思路：后序遍历
//复杂度：O(n)/O(logn)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)return 1;
    int leftDepth=minDepth(root->left);
    int rightDepth=minDepth(root->right);
    if(root->left==NULL)return rightDepth+1;
    if(root->right==NULL)return leftDepth+1;
    return(leftDepth<rightDepth?leftDepth:rightDepth)+1;
}