//232. 用栈实现队列
//思路：双栈变队列，一个进，一个出。
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* stackIn;
    int topIn;
    int* stackOut;
    int topOut;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->capacity = 100;
    obj->stackIn = (int*)malloc(sizeof(int) * obj->capacity);
    obj->topIn = -1;
    obj->stackOut = (int*)malloc(sizeof(int) * obj->capacity);
    obj->topOut = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->topIn++;
    obj->stackIn[obj->topIn] = x;
}

void inToOut(MyQueue* obj) {
    if (obj->topOut == -1) {
        while (obj->topIn != -1) {
            int temp = obj->stackIn[obj->topIn];
            obj->topIn--;
            obj->topOut++;
            obj->stackOut[obj->topOut] = temp;
        }
    }
}

int myQueuePop(MyQueue* obj) {
    inToOut(obj);
    int val = obj->stackOut[obj->topOut];
    obj->topOut--;
    return val;
}

int myQueuePeek(MyQueue* obj) {
    inToOut(obj);
    return obj->stackOut[obj->topOut];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->topIn == -1 && obj->topOut == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stackIn);
    free(obj->stackOut);
    free(obj);
}
/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/