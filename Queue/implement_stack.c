#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef struct {
    int *arr;
    int front, rear, capacity;
} queue;

queue* queueCreate(int k) {
    queue* mq = (queue*)malloc(sizeof(queue));
    mq->arr = (int*)malloc(sizeof(int) * (k + 1));
    mq->capacity = k + 1;
    mq->front = -1;
    mq->rear = 0;
    return mq;
}

bool queueIsEmpty(queue* obj) {
    return (obj->front == -1);
}

bool queueIsFull(queue* obj) {
    return ((obj->rear + 1) % obj->capacity) == obj->front;
}
int queueDeQueue(queue* obj) {
    if (queueIsEmpty(obj)) {
        return -1;
    }
    int x=queueFront(obj);
    if (obj->front == obj->rear - 1) {
        obj->front = -1;
        obj->rear = 0;
    } else {
        obj->front = (obj->front + 1) % obj->capacity;
    }
    return x;
}
void resize(queue* obj){
    int newCapacity=2*obj->capacity;
    obj->capacity=newCapacity;
    int *narr=(int *)malloc(sizeof(int)*newCapacity);
    int x=0;
    while(!queueIsEmpty(obj)){
        narr[x++]=queueDeQueue(obj);
    }
    obj->front=0;
    obj->rear=x;
    free(obj->arr);
    obj->arr=narr;
}
void queueEnQueue(queue* obj, int value) {
    if (queueIsFull(obj)) {
        resize(obj);
    }
    obj->arr[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    if (obj->front == -1) {
        obj->front = 0;
    }
    return;
}

int queueFront(queue* obj) {
    if (queueIsEmpty(obj)) {
        return -1;
    }
    return obj->arr[obj->front];
}

int queueRear(queue* obj) {
    if (queueIsEmpty(obj)) {
        return -1;
    }
    int rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    return obj->arr[rear];
}

void queueFree(queue* obj) {
    free(obj->arr);
    free(obj); 
}

typedef struct {
    queue* q1;
    queue* q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stk=(MyStack*)malloc(sizeof(MyStack));
    stk->q1=queueCreate(5);
    stk->q2=queueCreate(5);
    return stk;
}

void myStackPush(MyStack* obj, int x) {
    queueEnQueue(obj->q1,x);
}

int myStackPop(MyStack* obj) {
    int x=-1;
    while(!queueIsEmpty(obj->q1)){
        x=queueDeQueue(obj->q1);
        if(queueIsEmpty(obj->q1)){
            break;
        }
        queueEnQueue(obj->q2,x);
    }
    MyStack* q=obj->q1;
    obj->q1=obj->q2;
    obj->q2=q;
    return x;
}

int myStackTop(MyStack* obj) {
    int x=-1;
    while(!queueIsEmpty(obj->q1)){
        x=queueDeQueue(obj->q1);
        queueEnQueue(obj->q2,x);
    }
    MyStack* q=obj->q1;
    obj->q1=obj->q2;
    obj->q2=q;
    return x;
}

bool myStackEmpty(MyStack* obj) {
    return queueIsEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    queueFree(obj->q1);
    queueFree(obj->q2);
    free(obj);
}
int main(){
    MyStack* stk=myStackCreate();
    myStackPush(stk,1);
    myStackPush(stk,2);
    myStackPush(stk,3);
    myStackPush(stk,4);
    myStackPush(stk,5);
    assert(myStackTop(stk)==5);
    assert(myStackTop(stk)==5);
    myStackPop(stk);
    assert(myStackTop(stk)==4);
    myStackPop(stk);
    assert(myStackTop(stk)==3);
    myStackFree(stk);
    return 0;
}
