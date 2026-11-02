//150. 逆波兰表达式求值
//思路 ：数字就入栈，运算符就返回两数计算，返回计算值入栈。
//复杂度：O(n)/O(1)
#include"stdlib.h"
#include"string.h"
int evalRPN(char** tokens, int tokensSize) {
    int stack[10000];
    int top=-1;
    for(int i=0;i<tokensSize;i++){
        char*token=tokens[i];
        if(strcmp(token,"+") == 0 || strcmp(token,"-") == 0 || strcmp(token,"*") == 0 || strcmp(token,"/") == 0){
            int right = stack[top--];
            int left = stack[top--];
            if(strcmp(token,"+") == 0)stack[++top] = left+right;
            if(strcmp(token,"-") == 0)stack[++top] = left-right;
            if(strcmp(token,"*") == 0)stack[++top] = left*right;
            if(strcmp(token,"/") == 0)stack[++top] = left/right;
        }
        else{
            stack[++top] = atoi(token);
        }
    }
    return stack[top];
}