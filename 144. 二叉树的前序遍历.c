//144. 二叉树的前序遍历
//思路：递归，先向左边，再向右边。
//复杂度：O(n)/O(logn)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preorder(struct TreeNode* root,int* res,int* returnSize){
    if(root==NULL)return;
    res[(*returnSize)++]=root->val;
    preorder(root->left,res,returnSize);
    preorder(root->right,res,returnSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int*res=(int*)malloc(sizeof(int)*100);
    *returnSize=0;
    preorder(root,res,returnSize);
    return res;
}