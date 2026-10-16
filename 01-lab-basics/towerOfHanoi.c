#include<stdio.h>

void towerOfHanoi(int n, char x, char y, char z) {
    if(n >= 1) {
        towerOfHanoi(n-1, x, z, y);
        printf("Moved disc %d from %c to %c\n", n, x, y);
        towerOfHanoi(n-1, z, y, x);
    }
}

int main() {
    towerOfHanoi(5, 'X', 'Y', 'Z');
    return 0;
}