#include<stdio.h>
#include<stdbool.h>

#define INTEGER 0
#define CHARACTER 1

bool isCharacterOrInteger(char ch) {
    if(ch >= 48 && ch <= 57) return INTEGER;
    return CHARACTER;
}

int main(){
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if(isCharacterOrInteger(ch) == 0) {
        printf("%c is an INTEGER\n", ch);
    } else {
        printf("%c is a CHARACTER\n", ch);
    }
    return 0;
}