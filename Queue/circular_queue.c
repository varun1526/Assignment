#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front, rear, capacity;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    mq->arr = (int*)malloc(sizeof(int) * (k + 1));
    mq->capacity = k + 1;
    mq->front = -1;
    mq->rear = 0;
    return mq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->front == -1);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((obj->rear + 1) % obj->capacity) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    obj->arr[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    if (obj->front == -1) {
        obj->front = 0;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    if (obj->front == obj->rear - 1) {
        obj->front = -1;
        obj->rear = 0;
    } else {
        obj->front = (obj->front + 1) % obj->capacity;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    int rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    return obj->arr[rear];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj); 
}
int main(){
    MyCircularQueue* mq=myCircularQueueCreate(5);
    myCircularQueueEnQueue(mq,12);
    printf("%d\n",myCircularQueueFront(mq));
    printf("%d\n",myCircularQueueRear(mq));
}
