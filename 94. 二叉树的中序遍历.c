//94. 二叉树的中序遍历
//思路：递归，左中右顺序
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
void inorder(struct TreeNode* root,int* res,int* returnSize){
    if(root==NULL)return;
    else{
        inorder(root->left,res,returnSize);
        res[(*returnSize)++]=root->val;
        inorder(root->right,res,returnSize);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *res=(int*)malloc(sizeof(int)*100);
    *returnSize=0;
    inorder(root,res,returnSize);
    return res;
}