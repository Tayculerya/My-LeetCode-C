// 20. 有效的括号
// 思路：用数组模拟栈。左括号入栈，右括号匹配出栈。
// 复杂度：时间 O(n)，空间 O(n)
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) return false; 
    char stack[10000];
    int top = -1; 
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } 
        else {
            if (top == -1) return false;
            
            char topChar = stack[top];
            
            if ((c == ')' && topChar == '(') ||
                (c == ']' && topChar == '[') ||
                (c == '}' && topChar == '{')) {
                top--; 
            } else {
                return false; 
            }
        }
    }
    return top == -1;
}