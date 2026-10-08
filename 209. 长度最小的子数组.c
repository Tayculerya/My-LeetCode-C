//209. 长度最小的子数组
//思路：滑动窗口。right扩张，left收缩，记录最短窗口长度。
//复杂度：O(n)/O(1)
int minSubArrayLen(int target, int* nums, int numsSize) {
 int left=0;
 int sum=0;
 int minlen=INT_MAX;
 for(int right =0;right<numsSize;right++){
    sum+=nums[right];
    while(sum>=target){
        int n=right-left+1;
        if(n<minlen){
            minlen=n;
        }
        sum-=nums[left];
        left++;
    }
 }
 return minlen==INT_MAX?0:minlen;
}
