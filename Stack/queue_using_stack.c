#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
typedef struct {
    int size;
    int capacity;
    int *arr;
}stack;
void inc( stack *stk1){
    int newSize=2*stk1->size;
    int *narr=(int*)malloc(sizeof(int)*newSize);
    for(int i=0;i<stk1->capacity;i++){
        narr[i]=stk1->arr[i];
    }
    free(stk1->arr);
    stk1->arr=narr;
    stk1->size=newSize;
}
void init(stack *st1){
    st1->capacity=0;
    st1->size=5;
    st1->arr=(int*)malloc(sizeof(int)*(st1->size));
}
bool isfull(stack *stk1){
    if(stk1->size==stk1->capacity){
        return true;
    }
    return false;
}
bool isEmpty(stack *stk1){
    if(stk1->capacity==0){
        return true;
    }
    return false;
}
void add(stack *stk1,int x){
    if(isfull(stk1)){
        inc(stk1);
    }
    stk1->arr[stk1->capacity++]=x;
}
int remove_func(stack *stk1){
    if(isEmpty(stk1)){
        return -1;
    }
    int x=stk1->arr[--stk1->capacity];
    return x;
}
int peek_func(stack* stk1){
    if(isEmpty(stk1)){
        return -1;
    }
    return stk1->arr[stk1->capacity-1];
}
typedef struct {
    stack *stk1;
    stack *stk2;
}MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *mq=(MyQueue*)malloc(sizeof(MyQueue));
    mq->stk1=(stack*)malloc(sizeof(stack));
    mq->stk2=(stack*)malloc(sizeof(stack));
    init(mq->stk1);
    init(mq->stk2);
    return mq;
}

void myQueuePush(MyQueue* obj, int x) {
    while(!isEmpty(obj->stk2)){
        add(obj->stk1,remove_func(obj->stk2));
    }
    add(obj->stk1,x);
    while(!isEmpty(obj->stk1)){
        add(obj->stk2,remove_func(obj->stk1));
    }
}

int myQueuePop(MyQueue* obj) {
    if(isEmpty(obj->stk2)){
        return -1;
    }
    return remove_func(obj->stk2);
}

int myQueuePeek(MyQueue* obj) {
    return peek_func(obj->stk2);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj->stk2);
}

void myQueueFree(MyQueue* obj) {
    free(obj->stk1->arr);
    free(obj->stk1);
    free(obj->stk2->arr);
    free(obj->stk2);
    free(obj);
}

int main(){
    MyQueue* mq=myQueueCreate();
    myQueuePush(mq,1);
    myQueuePush(mq,2);
    myQueuePush(mq,3);
    myQueuePush(mq,4);
    assert(myQueuePop(mq)==1);
    assert(myQueuePop(mq)==2);
    assert(myQueuePop(mq)==3);
    assert(myQueuePop(mq)==4);
    return 0;
}
