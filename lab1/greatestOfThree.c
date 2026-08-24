#include<stdio.h>

int gratestOfThree(int a, int b, int c) {
    if(a >= b && a >=c) return a;
    else if(b >= c) return b;
    else return c;
}

int main() {
    int a, b, c;
    printf("Enter the first number : ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Enter the third number : ");
    scanf("%d", &c);

    printf("The gratest from %d, %d and %d is %d\n", a, b, c, gratestOfThree(a, b, c));
    return 0;
}