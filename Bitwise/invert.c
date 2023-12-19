#include<stdio.h>
#include<assert.h>
int invert(int x,int p,int n){
    int mask=(((1<<n) -1)<<(p-1));
    int get=x&(mask);
    int clear=x&(~mask);
    return clear|((~get)&(mask));
}
int main(){
    assert(invert(20,2,3)==26);
    assert(invert(10,2,3)==4);
    return 0;
}
