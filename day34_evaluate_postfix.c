/* Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

int evaluatePostfix(char* expr) {
    struct Node* stack = NULL;
    int i = 0;

    while (expr[i] != '\0') {

        if (expr[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(expr[i])) {
            int num = 0;

            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }

            push(&stack, num);
            continue;
        }

        int a = pop(&stack);
        int b = pop(&stack);
        int result;

        switch (expr[i]) {
            case '+': result = b + a; break;
            case '-': result = b - a; break;
            case '*': result = b * a; break;
            case '/': result = b / a; break;
            default:
                printf("Invalid operator\n");
                exit(1);
        }

        push(&stack, result);
        i++;
    }

    return pop(&stack);
}

int main() {
    char expr[] = "2 3 1 * + 9 -";
    int result = evaluatePostfix(expr);
    printf("%d\n", result);
    return 0;
}