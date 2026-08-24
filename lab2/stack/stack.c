  #include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 7

typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

void initialize(Stack *stack) {
  stack -> top = -1;
}

bool isEmpty(Stack *stack) {
  if(stack -> top == -1) return true;
  return false;
}

bool isFull(Stack *stack) {
  if(stack -> top >= MAX_SIZE - 1) return true;
  return false;
}

void push(Stack *stack, int element) {
  if(isFull(stack)) {
    printf("\nStack overflow!!");
    return;
  }
  // stack -> top++;
  stack -> arr[++stack -> top] = element;
  printf("\nElement %d inserted successfully!!", element);
}

int pop(Stack *stack) {
  if(isEmpty(stack)) {
    printf("\nEmpty stack!!");
    return -1;
  }
  int popped = stack -> arr[stack -> top--];
  // stack -> top--;
  printf("\nElement %d popped successfully!!", popped);
  return popped;

}

int peek(Stack *stack) {
  if(isEmpty(stack)) {
    printf("\nEmpty stack!!");
    return -1;
  }
  return stack -> arr[stack -> top];
}

void displayStack(Stack *stack) {
  printf("\n\nSTACK {");

  for(int i = 0; i <= stack -> top; i++) {
    printf("\n\tstack[%d] = %d", i, stack -> arr[i]);
  }

  printf("\n}");
}

int main() {
  Stack stack;

  initialize(&stack);

  pop(&stack);

  push(&stack, 67);
  push(&stack,51);
  push(&stack, 63);
  push(&stack, 737);
  push(&stack, 911);
  push(&stack, 83);
  push(&stack, 420);
  push(&stack, 666);

  pop(&stack);
  pop(&stack);
  
  int peekedValue = peek(&stack);
  printf("\nPEAK VALUE = %d", peekedValue);
  
  displayStack(&stack);
  
  pop(&stack);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  pop(&stack);
  pop(&stack);
}