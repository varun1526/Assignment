#include<stdio.h>
#include<assert.h>
int bang(int x){
    x|=(x>>2);
    x|=(x>>4);
    x|=(x>>8);
    x|=(x>>16);
    x|=(x>>31);
    return (x&1)^1;
}
int main(){
    assert(bang(-1)==0);
    assert(bang(2)==1);
    assert(bang(-100)==0);
    assert(bang(101)==0);
}
