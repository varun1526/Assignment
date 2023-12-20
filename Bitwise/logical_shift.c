#include<stdio.h>
#include<limits.h>

int main() {
    int x = -2023406815, n = 4;
    int result = ((((!!(x & INT_MIN)) << (31 - n)) | ((x & INT_MAX)) >> n));
    printf("%d\n", result);

}

