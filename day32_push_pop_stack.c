/* Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10 */

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX-1) {
        printf("Stack overflow\n");
    } else {
        top++;
        stack[top] = value;
      
    }
}

void pop () {
    if(top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Deleted: %d\n",stack[top]);
        top--;
    }
}

void display () {
      if(top == -1) {
        printf("Stack underflow\n");
    } else {
       for (int i = top;i >= 0; i--) {
        printf("%d ",stack[i]);
       }
    }
}

int main () {
    int choose,value,m,n;

    while(1) {
    printf("Option\n1:push\n2:pop\n3:exit\nChoose Operation:");
    scanf("%d",&choose);

    switch (choose){
        case 1:
        printf("Enter the no of element to push:");
        scanf("%d",&n);

        printf("Enter %d element:",n);
        for (int i = 0 ;i < n ;i++) {
            scanf("%d",&value);
            push(value);
        }
        break;

        case 2:
        printf("Enter the no of element to pop:");
        scanf("%d",&m);

        for (int i = 0 ;i < m ;i++){
            pop();
        }
        break;

        case 3:
        printf("Exiting Program...\n");
        exit(0);

        default :
        printf("Invalid choice\n");
        
    }

    display();
    printf("\n");
    }

    return 0;

}