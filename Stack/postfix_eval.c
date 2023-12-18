#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef struct {
    int size;
    int capacity;
    int *arr;
}stack;
void inc(stack *stk1){
    int newSize=2*stk1->size;
    int *narr=(int*)malloc(sizeof(int)*newSize);
    for(int i=0;i<stk1->capacity;i++){
        narr[i]=stk1->arr[i];
    }
    free(stk1->arr);
    stk1->arr=narr;
    stk1->size=newSize;
}
int size_stack(stack* stk){
    return stk->capacity;
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
void free_stack(stack *stk){
    free(stk->arr);
    free(stk);
}
int find(char *str){
    stack *stk=(stack*)malloc(sizeof(stack));
    init(stk);
    int i=0;
    while(str[i]!='?'){
        if(str[i]>='0' && str[i]<='9'){
            int sum=0;
            while(str[i]>='0' && str[i]<='9'){
                sum=sum*10+(str[i]-'0');
                i++;
            }
            // printf("%d\n",sum);
            add(stk,sum);
        }
        else if(str[i]!='?'){
            char x=str[i];
            i++;
            int a=remove_func(stk);
            int b=remove_func(stk);
            // printf("%d %d ",a,b);
            if(x=='+'){
                add(stk,b+a);
            }
            else if(x=='*'){
                add(stk,b*a);
            }
            else if(x=='-'){
                add(stk,b-a);
            }
            else{
                add(stk,b/a);
            }
        }
        i++;
    }
    int ans=remove_func(stk);
    free(stk);
    return ans;
}
int main() {
    assert(find("14 36 * 6 / 3 * ?") == 252);
    assert(find("31 4 50 + * ?") == 1674);
    assert(find("32 34 12 * + 1 2 + * 1 1 + / 23 21 - * ?") == 1320);
    return 0;
}

