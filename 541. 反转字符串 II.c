//541. 反转字符串 II
//思路：利用循环每次跳2k步，内部用双指针交换。
//复杂度：O(n)/O(1)
char* reverseStr(char* s, int k) {
    int sSize=strlen(s);
    for(int i=0;i<sSize;i+=2*k){
        int left=i;
        int right=(i+k-1<sSize)?(i+k-1):(sSize-1);
        int t;
        while(left<right){
            char t=s[left];
            s[left]=s[right];
            s[right]=t;
            left++;
            right--;
        }
    }
    return s;
}