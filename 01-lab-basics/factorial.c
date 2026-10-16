#include<stdio.h>

int factorial(int number){
    int fatcoricalResult = 1;
    while(number > 1) {
        fatcoricalResult *= number;
        number--;
    }
    return fatcoricalResult;
}

int factorialRecursion(int number) {
    if(number == 1 || number == 0) return 1;
    return number * factorialRecursion(number - 1);
}

int main(void) {
    int number;
    printf("Enter the number to calcualte the factorial: ");
    scanf("%d", &number);

    // printf("Factrial of %d is %d\n", number, factorial(number));
    printf("Factrial of %d is %d\n", number, factorialRecursion(number));
    return 0;
}