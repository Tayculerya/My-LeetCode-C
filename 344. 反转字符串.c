//344.反转字符串
//思路：双指针
//复杂度：O(n)/O(1)
void reverseString(char* s, int sSize) {
    int t;
    for(int i=0;i<sSize/2;i++){
        t=s[i];
        s[i]=s[sSize-1-i];
        s[sSize-1-i]=t;
    }
    
}