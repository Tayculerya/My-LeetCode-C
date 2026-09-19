//977. 有序数组的平方
//思路：对撞双指针
//复杂度：O(n)/O(n)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
  int* result=(int*)malloc(sizeof(int)*numsSize);
  *returnSize=numsSize;
  int left=0;
  int right=numsSize-1;
  int k=numsSize-1;
  while(left<=right){
    int leftSqure=nums[left]*nums[left];
    int rightSqure=nums[right]*nums[right];
    if(leftSqure>rightSqure){
    result[k]=leftSqure;
    left++;}
    else{
        result[k]=rightSqure;
        right--;
    } 
    k--;
  } 
  return result;
}