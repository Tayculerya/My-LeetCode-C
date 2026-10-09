//59. 螺旋矩阵 II
//思路：模拟顺时针绕圈填充
//复杂度：O(n*n)/O(n*n)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
  int**mat=(int**)malloc(n*sizeof(int*));
  for(int i=0;i<=n-1;i++){
    mat[i]=(int*)malloc(n*sizeof(int));
  }  
  *returnSize=n;
  *returnColumnSizes=(int*)malloc(n*sizeof(int));
  for(int i=0;i<=n-1;i++){
    (*returnColumnSizes)[i]=n;
    }
  int left=0,top=0;
  int bottom=n-1,right=n-1;
  int num=1,target=n*n;
  while(num<=target){
    for(int i=left;i<=right;i++){
        mat[top][i]=num++;
    }
    top++;
    for(int i=top;i<=bottom;i++){
        mat[i][right]=num++;
    }
    right--;
    if(top<=bottom){
        for(int i=right;i>=left;i--){
        mat[bottom][i]=num++;
    }
    bottom--;
    }
    if(left<=right){
        for(int i=bottom;i>=top;i--){
        mat[i][left]=num++;
        }
    }    
    left++;
  }
  return mat;
}