//145. 二叉树的后序遍历
//思路：先写递归函数，然后左右中顺序递归
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
 void postorder(struct TreeNode* root,int* str,int* returnSize){
    if(root==NULL)return;
    postorder(root->left,str,returnSize);
    postorder(root->right,str,returnSize);
    str[(*returnSize)++]=root->val;
 }
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int *str=(int*)malloc(sizeof(int)*100);
    *returnSize=0;
    postorder(root,str,returnSize);
    return str;
}