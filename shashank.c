#include <stdio.h>

int stack[100];
int top = -1;
int tenCount = 0;

void push() {
    if (top == 99) {
        printf("Stack Overflow\n");
        return;
    }

    int x;
    printf("Enter value to push: ");
    scanf("%d", &x);

    stack[++top] = x;

    if (x == 10) {
        tenCount++;

        int i = top;
        while (i > 0 && stack[i - 1] != 10) {
            int temp = stack[i];
            stack[i] = stack[i - 1];
            stack[i - 1] = temp;
            i--;
        }
    }

    printf("%d pushed\n", x);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    if (stack[top] == 10 && tenCount < 5) {
        printf("Cannot pop 10 until five 10s are in the stack\n");
        return;
    }

    if (stack[top] == 10) {
        tenCount--;
    }

    printf("%d popped\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int ch;

    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}