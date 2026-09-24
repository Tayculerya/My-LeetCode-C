//14. 最长公共前缀
//思路：纵向扫描。以第一个字符串为基准，逐个字符检查其余字符串同位置是否相同。
//复杂度:O(n)/O(1)
#include"stdlib.h"
#include"string.h"
char* longestCommonPrefix(char** strs, int strsSize) {
  if(strsSize==0)return "";
  for(int i=0;strs[0][i]!='\0';i++){
    char c=strs[0][i];
    for(int j=1;j<strsSize;j++){
        if(strs[j][i]=='\0'||strs[j][i]!=c){
        char*result=(char*)malloc(sizeof(char)*(i+1));
        strncpy(result,strs[0],i);
        result[i]='\0';
        return result;}
    }
  }
  int len=strlen(strs[0]);
  char*result=(char*)malloc(sizeof(char)*(len+1));
  strcpy(result,strs[0]);
  return result;
}