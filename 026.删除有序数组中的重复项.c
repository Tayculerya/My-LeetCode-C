//026.删除有序数组中的重复项
//思路：快慢指针，快指针探路，慢指针记录数组下标
//复杂度：O(n)/)(1)
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize==0){
        return 0;
    }
    int slow=0;
    for(int fast=1;fast<numsSize;fast++){
        if(nums[fast]!=nums[slow]){
            slow++;
            nums[slow]=nums[fast];
        }
    }
    return slow+1;
}