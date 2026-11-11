//102. 二叉树的层序遍历
//思路：广度优先搜索，利用队列，每次记录当前层的节点数。
//复杂度：O(n)/O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int**res=(int**)malloc(sizeof(int*)*10000);
    *returnSize=0;
    *returnColumnSizes=(int*)malloc(sizeof(int)*10000);
    if(root==NULL)return res;
    struct TreeNode*queue[10000];
    int rear=0;
    int front=0;
    queue[rear++]=root;
    while(front<rear){
        int size=rear-front;
        res[*returnSize]=(int*)malloc(sizeof(int)*size);
        (*returnColumnSizes)[*returnSize]=size;
        for(int i=0;i<size;i++){
            struct TreeNode*node=queue[front++];
            res[*returnSize][i]=node->val;
            if(node->left)queue[rear++]=node->left;
            if(node->right)queue[rear++]=node->right;
        }
        (*returnSize)++;
    }
    return res;
}