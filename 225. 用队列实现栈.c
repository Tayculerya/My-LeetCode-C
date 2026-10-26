//225. 用队列实现栈
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// 1. 封装一个标准队列
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;
} Queue;

// 队列的四个标准操作（只要不直接碰data数组，LeetCode就不报错）
void push(Queue* q, int x) {
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->count++;
}

int pop(Queue* q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    return val;
}

int peek(Queue* q) { return q->data[q->front]; }
bool empty(Queue* q) { return q->count == 0; }


// ================= 以上是队列，以下是栈 =================

// 2. 用队列实现栈
typedef struct {
    Queue* q;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q = (Queue*)malloc(sizeof(Queue));
    obj->q->front = 0;
    obj->q->rear = 0;
    obj->q->count = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    int size = obj->q->count; // 记住进来之前有几个老元素
    push(obj->q, x);          // 新元素正常入队
    
    // 把前面的老元素全部弹出来，重新塞到队尾
    for (int i = 0; i < size; i++) {
        push(obj->q, pop(obj->q));
    }
}

int myStackPop(MyStack* obj) {
    return pop(obj->q);
}

int myStackTop(MyStack* obj) {
    return peek(obj->q);
}

bool myStackEmpty(MyStack* obj) {
    return empty(obj->q);
}

void myStackFree(MyStack* obj) {
    free(obj->q);
    free(obj);
}