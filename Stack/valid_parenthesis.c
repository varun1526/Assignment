#include<stdio.h>
#include<stdbool.h>                // include boolean library in c
#include<string.h>
#include<stdlib.h>
#include<assert.h>
// making the node for stack
struct Node{
    char data;
    struct Node *next;
}*head=NULL,*tail=NULL;
// add to stack
void add(char data){
    struct Node* p=(struct Node*)malloc(sizeof(struct Node));
    p->data=data;
    p->next=head;
    if(head==NULL){
        tail=p;
    }
    head=p;
}
// check if the stack is empty
bool isempty(){
    return head==NULL;
}
// pop from stack
char pop(){
    if(!isempty()){
        char data=head->data;
        struct Node* pre=head;
        head=head->next;
        free(pre);
        return data;
    }
    return '\0';
}
// parenthesis checker
bool isValid(char* s) {
    bool ans=true;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            add(s[i]);
        }
        else{
            if(isempty()){
                ans=false;
                break;
            }
            char pre=pop();
            if((s[i]=='}' && pre!='{') || (s[i]==')' && pre!='(') || (s[i]==']' && pre!='[')){
                ans=false;
                break;
            }
        }
    }
    if(!isempty()){
        ans=false;
    }
    while(head!=NULL){
        pop();
    }
    return ans;
}

// main function
int main(){
	assert(isValid("(()){}{}[][][]")==true);
	assert(isValid("}}{{{}}}{{{")==false);
	return 0;	
}
