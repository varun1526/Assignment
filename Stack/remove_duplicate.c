#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef struct {
    int size;
    int capacity;
    char *arr;
}stack;
void inc( stack *stk1){
    int newSize=2*stk1->size;
    char *narr=(char*)malloc(sizeof(char)*newSize);
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
    st1->arr=(char*)malloc(sizeof(char)*(st1->size));
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
void add(stack *stk1,char x){
    if(isfull(stk1)){
        inc(stk1);
    }
    stk1->arr[stk1->capacity++]=x;
}
char remove_func(stack *stk1){
    if(isEmpty(stk1)){
        return -1;
    }
    char x=stk1->arr[--stk1->capacity];
    return x;
}
char peek_func(stack* stk1){
    if(isEmpty(stk1)){
        return -1;
    }
    return stk1->arr[stk1->capacity-1];
}
char* removeDuplicateLetters(char* s) {
    int *arr=(int*)malloc(sizeof(int)*26);
    for(int i=0;i<strlen(s);i++){
        arr[s[i]-'a']=i;
    }
    stack *stk=(stack*)malloc(sizeof(stack));
    init(stk);
    int *vis=(int*)calloc(26,sizeof(int));
    for(int i=0;i<strlen(s);i++){
        while(!isEmpty(stk) && peek_func(stk)>s[i] && arr[peek_func(stk)-'a']>i && vis[s[i]-'a']==0){
            char x=remove_func(stk);
            vis[x-'a']=0;
        }
        if(vis[s[i]-'a']==0){
            add(stk,s[i]);
            vis[s[i]-'a']=1;
        }
    }
    char *ans=(char*)malloc(sizeof(char)*(stk->capacity+1));
    int size=stk->capacity;
    for(int i=stk->capacity-1;i>=0;i--){
        ans[i]=remove_func(stk);
    }
    ans[size]='\0';
    free(stk);
    return ans;
}
int main(){
    assert(strcmp(removeDuplicateLetters("bcabc"),"abc") == 0);
    assert(strcmp(removeDuplicateLetters("cbacdcbc"),"acdb") == 0);
}
