//027.移除元素
//思路：快慢指针,快指针探路，慢指针收集元素
//复杂度：O(n)/O(1)
int removeElement(int* nums, int numsSize, int val) {
    int slow = 0;
    for(int fast=0;fast<numsSize;fast++){
        if(nums[fast]!=val){
            nums[slow]=nums[fast];
            slow++;
        }
    }
    return slow;
}