/* Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10 */
#include <stdio.h>
#define MAX 1000

void push(int stack[], int *top, int value) {
    if (*top == MAX - 1) {
        return;
    }
    (*top)++;
    stack[*top] = value;
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[*top]);
    (*top)--;
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of operations:");
    scanf("%d", &n);

    int stack[MAX];
    int top = -1;
    printf("operation type and value (if applicable)\n1value: push value\n2:pop\n3:display\n");
    while (n--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int value;
            scanf("%d", &value);
            push(stack, &top, value);
        } else if (op == 2) {
            pop(stack, &top);
        } else if (op == 3) {
            display(stack, top);
        }
    }

    return 0;
}