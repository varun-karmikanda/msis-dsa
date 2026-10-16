#include<stdio.h>

int twoPowerN(int n){
    if(n < 1) return 1;
    return 1 << n;
}

int main() {
    int n;
    printf("What power of 2 do you want to calculate: ");
    scanf("%d", &n);

    printf("2^%d = %d\n", n, twoPowerN(n));
    return 0;
}