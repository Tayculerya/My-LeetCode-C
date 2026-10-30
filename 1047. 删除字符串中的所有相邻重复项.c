//1047. 删除字符串中的所有相邻重复项
//思路：利用栈保存字符串
//复杂度：O(n)/O(1)
#include"string.h"
char* removeDuplicates(char* s) {
    int len=strlen(s);
    int top=-1;
    int i;
    for(i=0;i<len;i++){
        if(top>=0&&s[i]==s[top]){
            top--;
        }
        else{
            top++;
            s[top]=s[i];
        }
    }
    s[top+1]='\0';
    return s;
}