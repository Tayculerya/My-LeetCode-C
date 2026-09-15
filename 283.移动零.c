//283.移动零
//思路：快慢指针，先前移，再补零
//复杂度：O(n)/O(1)
void moveZeroes(int* nums, int numsSize) {
    int slow=0;
    for(int fast=0;fast<numsSize;fast++){
        if(nums[fast]!=0){
            nums[slow]=nums[fast];
            slow++;}
        }
            for(int n=slow;n<numsSize;n++){
                    nums[n]=0;}  
}