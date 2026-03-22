/* Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity */

#include<stdio.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push (char x){
    stack[++top] = x;
}

char pop () {
    if(top == -1)
        return -1;
    return stack[top--];
}

int precedence (char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main () {
    char exp[100],result[100];
    int i = 0, j = 0;
    
    printf("Enter infix Expression:");
    scanf("%s",exp);

    while (exp[i] != '\0') {

        if (isalnum(exp[i])) {
            result[j++] = exp[i];
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(' ) {
                result[j++] = pop ();
            }
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                result[j++] =pop();
            }
            push(exp[i]);
        }
        i++;
    }

    while (top != -1) {
        result[j++] = pop();
    }

    result[j] = '\0';

    printf("postfix expression:%s\n",result);

    return 0;
}
