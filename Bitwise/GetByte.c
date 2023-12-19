#include<stdio.h>
#include<assert.h>
int GetByte(int x,int n){
    return (x>>(n*8)&(255));
}
int main(){
    assert(GetByte(305419896,1)==86);
    return 0;
}
