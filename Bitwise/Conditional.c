#include<stdio.h>
#include<assert.h>
int conditional(int x,int y,int z){
    int mask=(~(!x))+1;
    return (mask&z)|((~mask)&y);
}
int main(){
    assert(conditional(1,2,3)==2);
    assert(conditional(0,2,3)==3);
    assert(conditional(1012,100,34)==100);
    return 0;
}
