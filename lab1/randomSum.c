#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));
    int randomNumber1 = rand();
    int randomNumber2 = rand();

    printf("%d + %d = %d\n", randomNumber1, randomNumber2, randomNumber1 + randomNumber2);
}