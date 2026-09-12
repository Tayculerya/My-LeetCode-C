//001.两数之和
//思路：双重暴力枚举
//时间复杂度：O（n^2）/O(1)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include"stdlib.h"
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   int* result=(int*)malloc(sizeof(int)*2); 
    int i,j;
    for (i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++)
        if(nums[i]+nums[j]==target){
            result[0]=i;
            result[1]=j;
            * returnSize=2;
            return result;
        }
    }
    *returnSize=0;
    return NULL;
}