/* Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order. */
#include<stdio.h>
#include<stdlib.h>
struct node {
    int coef;
    int expo;
    struct node* next;
};
struct node* head = NULL;

struct node* createnode(int coef,int expo) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    newnode->coef = coef;
    newnode->expo = expo;
    newnode->next = NULL;

    return newnode;
}

void  insertterm(int coef,int expo) {
    struct node* newnode = createnode(coef,expo);

    if (head == NULL || head->expo < expo){
        newnode->next = head;
        head = newnode;
        return;
    }

    struct node* temp = head;

    while(temp->next != NULL && temp->next->expo > expo)
        temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;

}

void printlist(){

    struct node* temp = head;

    while(temp != NULL){
        printf("%dX^%d ",temp->coef,temp->expo);

        if(temp->next != NULL)
            printf(" + ");
        
        temp = temp->next;
    }

}

int main () {
    int n,coef,expo;
    printf("Enter the number of node for polynomial linked list:");
    scanf("%d",&n);

    printf("Enter the polynomial term one by one:");
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent respectively for %d term of polynomial:",i+1);
        scanf("%d %d",&coef,&expo);
        insertterm(coef,expo);
    }

    printlist();

}