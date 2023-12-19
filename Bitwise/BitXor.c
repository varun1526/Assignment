#include<stdio.h>
#include<assert.h>
int xor(int a,int b){
    return ((~(a&b))&(a|b));
}
int main(){
    assert(xor(2,3)==1);
    assert(xor(100,45)==73);
}
