//58. 最后一个单词的长度
//思路：倒序遍历，先跳过末尾空格，再计算最后一个单词的长度。
//复杂度：O(n)/O(1)
#include"string.h"
int lengthOfLastWord(char* s) {
    int length=strlen(s);
    int a=length-1;
    int count=0;
    while(a>=0&&s[a]==' '){
        a--;
    }
    while(a>=0&&s[a]!=' '){
        count++;
        a--;
    }
    return count;
}