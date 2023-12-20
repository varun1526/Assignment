#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int longestValidParentheses(char* s) {
    int len=strlen(s);
    int *arr=(int *)malloc(sizeof(int)*(len));
    for(int i=0;i<len;i++){
        arr[i]=i-1;
    }
    int *stk=(int *)malloc(sizeof(int)*len);
    int j=0;
    for(int i=0;i<len;i++){
        if(s[i]=='('){
            stk[j++]=i;
        }
        else{
            if(j>0 && s[stk[j-1]]=='('){
                arr[stk[j-1]]=i;
                j--;
            }
        }
    }
    int i=0,maxi=0;
    while(i<len){
        if(arr[i]!=i-1){
            int count=0;
            while(i<len && arr[i]!=i-1){
                count+=(arr[i]-i+1);
                i=arr[i]+1;
            }
            if(maxi<count){
                maxi=count;
            }
        }
        i++;
    }
    free(arr);
    free(stk);
    return maxi;
}
int main(){
    assert(longestValidParentheses("(()")==2);
    assert(longestValidParentheses(")()())")==4);
    assert(longestValidParentheses("")==0);
}
